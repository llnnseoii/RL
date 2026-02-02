import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.distributions import Categorical
from torch.utils.tensorboard import SummaryWriter
import os
import argparse
from datetime import datetime
from collections import deque

# --------------------------------------------------------
# [0] 외부 모듈 임포트 (가정)
# 실제 실행 시 parameters.py, output.py, entities.py가 같은 폴더에 있어야 합니다.
# --------------------------------------------------------
try:
    from parameters import SimulationParameters
    from output import Output
    from entities import Person
except ImportError:
    print("오류: 'parameters.py', 'output.py', 'entities.py' 파일이 필요합니다.")
    print("이 파일들이 같은 디렉토리에 있는지 확인해주세요.")
    exit(1)

# --------------------------------------------------------
# [1] 목적 지표별 보상을 적용한 강화학습 환경
# --------------------------------------------------------
class ColonoscopyOptimalEnv:
    """
    대장암 검진 최적화 환경 (Target-Specific Rewards)
    
    [Available Reward Modes]
    1. 'incidence': 암 발생 최소화
    2. 'mortality': 암 사망 최소화
    3. 'lyl': 암으로 인한 기대수명 손실 최소화
    4. 'cost': 총 비용 최소화
    5. 'icer': 비용-효과성 최적화 (NMB Approach)
    """
    def __init__(self, settings_file, reward_mode='icer', wtp_threshold=30000):
        self.params = SimulationParameters(settings_file)
        self.min_age = self.params.opt_min_age
        self.max_age = min(self.params.opt_max_age, 85)
        self.max_history = 10
        
        self.state_dim = 16
        self.action_dim = 2 # 0:Wait, 1:Screen
        
        self.reward_mode = reward_mode
        self.wtp_threshold = wtp_threshold 

        # 통계 추적
        self.stats = {
            'screenings': 0,
            'cancers_detected': 0,
            'cancers_prevented': 0,
            'cancer_incidence': 0,
            'cancer_death': 0,
            'life_years_lost': 0,
            'total_cost': 0.0
        }
        
        self.person = None
        self.current_age = 0
        self.years_since_last = 0
        self.output = None

    def reset(self):
        rng = np.random.default_rng()
        self.person = Person(self.params, rng)
        self.current_age = self.min_age
        self.years_since_last = self.max_history
        self.output = Output(self.params)
        
        # 통계 초기화
        for k in self.stats:
            self.stats[k] = 0
        
        # 시작 시점 사망자 제외
        max_attempts = 100
        attempts = 0
        while self.person.death_age <= self.current_age and attempts < max_attempts:
            self.person = Person(self.params, rng)
            attempts += 1
        if attempts >= max_attempts:
            self.person.death_age = self.max_age + 10
        
        return self._get_observation()
    
    def _get_observation(self):
        age_norm = self.current_age / 100.0
        hist_norm = min(self.years_since_last, 10) / 10.0
        gender = float(self.person.gender)
        
        zones = np.zeros(13, dtype=np.float32)
        adv_threshold = getattr(self.params, 'adv_polyp_transition', 5)
        
        for p in self.person.polyps:
            if p.age_developed <= self.current_age < p.age_end:
                loc = min(p.location, 12)
                zones[loc] = max(zones[loc], 2.0 if p.stage >= adv_threshold else 1.0)
        
        for c in self.person.cancers:
            if c.age_developed <= self.current_age:
                loc = min(c.location, 12)
                zones[loc] = 4.0 if c.detected else 3.0
        
        obs = np.array([age_norm, hist_norm, gender] + list(zones), dtype=np.float32)
        return obs
    
    def step(self, action):
        reward = 0.0
        done = False
        info = {}
        
        cancers_count_before = len([c for c in self.person.cancers if c.age_developed <= self.current_age])
        prev_cost = self.output.total_discounted_cost
        
        # Action 수행
        if action == 1: # Screen
            self.stats['screenings'] += 1
            self.person._perform_colonoscopy(self.current_age, self.output, is_screening=True)
            self.years_since_last = 0
        else: # Wait
            self.years_since_last = min(self.years_since_last + 1, self.max_history)
        
        # 비용 및 암 발생 변화 계산
        current_cost = self.output.total_discounted_cost
        step_cost = current_cost - prev_cost
        self.stats['total_cost'] += step_cost
        
        cancers_count_after = len([c for c in self.person.cancers if c.age_developed <= self.current_age])
        new_cancers = max(0, cancers_count_after - cancers_count_before)
        if new_cancers > 0:
            self.stats['cancer_incidence'] += new_cancers

        self.current_age += 1
        
        # 종료 조건
        death_by_cancer = False
        life_years_lost = 0.0
        
        if self.current_age >= self.person.death_age:
            done = True
            if self.person.death_age < self.person.natural_death_age:
                death_by_cancer = True
                life_years_lost = self.person.natural_death_age - self.person.death_age
                self.stats['cancer_death'] = 1
                self.stats['life_years_lost'] = life_years_lost
                info['death_reason'] = 'cancer'
            else:
                info['death_reason'] = 'natural'
        elif self.current_age >= self.max_age:
            done = True
            info['death_reason'] = 'completed'

        # --- 보상 계산 (Reward Modes) ---
        if self.reward_mode == 'incidence':
            if new_cancers > 0:
                reward -= 100.0
            reward -= step_cost * 0.0001 

        elif self.reward_mode == 'mortality':
            reward += 0.1 # 생존 보상
            if done and death_by_cancer:
                reward -= 1000.0
            reward -= step_cost * 0.0001

        elif self.reward_mode == 'lyl':
            if done and death_by_cancer:
                reward -= life_years_lost
            elif not done:
                reward += 0.1

        elif self.reward_mode == 'cost':
            reward -= step_cost
            if done and death_by_cancer:
                 reward -= 100.0 # 최소한의 사망 페널티 (안 그러면 그냥 죽게 둠)

        elif self.reward_mode == 'icer':
            # NMB = (WTP * Effectiveness) - Cost
            effectiveness_gain = 1.0 
            if done and (self.current_age >= self.person.death_age):
                effectiveness_gain = 0.0
            
            monetary_benefit = (self.wtp_threshold * effectiveness_gain) - step_cost
            reward = monetary_benefit * 1e-4

        return self._get_observation(), reward, done, self.stats

# --------------------------------------------------------
# [2] Actor-Critic Network
# --------------------------------------------------------
class ActorCritic(nn.Module):
    def __init__(self, state_dim, action_dim, hidden_size=256):
        super(ActorCritic, self).__init__()
        
        self.actor = nn.Sequential(
            nn.Linear(state_dim, hidden_size),
            nn.LayerNorm(hidden_size),
            nn.Tanh(),
            nn.Linear(hidden_size, hidden_size),
            nn.LayerNorm(hidden_size),
            nn.Tanh(),
            nn.Linear(hidden_size, action_dim),
            nn.Softmax(dim=-1)
        )
        
        self.critic = nn.Sequential(
            nn.Linear(state_dim, hidden_size),
            nn.LayerNorm(hidden_size),
            nn.Tanh(),
            nn.Linear(hidden_size, hidden_size),
            nn.LayerNorm(hidden_size),
            nn.Tanh(),
            nn.Linear(hidden_size, 1)
        )
        
    def act(self, state):
        if isinstance(state, np.ndarray):
            state = torch.from_numpy(state).float().unsqueeze(0)
        probs = self.actor(state)
        dist = Categorical(probs)
        action = dist.sample()
        return action.item(), dist.log_prob(action)
    
    def evaluate(self, state, action):
        probs = self.actor(state)
        dist = Categorical(probs)
        action_logprobs = dist.log_prob(action)
        dist_entropy = dist.entropy()
        state_values = self.critic(state)
        return action_logprobs, state_values, dist_entropy

# --------------------------------------------------------
# [3] PPO Trainer
# --------------------------------------------------------
class PPOTrainer:
    def __init__(self, settings_file, reward_mode='icer', wtp=30000, save_dir='models', log_dir='logs', device=None):
        # 환경 초기화 시 reward_mode와 wtp 전달
        self.env = ColonoscopyOptimalEnv(settings_file, reward_mode=reward_mode, wtp_threshold=wtp)
        
        self.save_dir = save_dir
        self.log_dir = log_dir
        self.device = torch.device('cuda' if torch.cuda.is_available() else 'cpu') if device is None else torch.device(device)
        
        print(f"Using device: {self.device}")
        print(f"Reward Mode: {reward_mode}, WTP: {wtp}")

        self.policy = ActorCritic(self.env.state_dim, self.env.action_dim).to(self.device)
        self.policy_old = ActorCritic(self.env.state_dim, self.env.action_dim).to(self.device)
        self.policy_old.load_state_dict(self.policy.state_dict())
        self.policy_old.eval()
        
        self.optimizer = optim.Adam(self.policy.parameters(), lr=3e-4)
        
        # PPO Hyperparameters
        self.gamma = 0.99
        self.eps_clip = 0.2
        self.K_epochs = 10
        
        os.makedirs(self.save_dir, exist_ok=True)
        os.makedirs(self.log_dir, exist_ok=True)
        self.writer = SummaryWriter(self.log_dir)
        
    def update(self, memory):
        old_states = torch.stack(memory['states']).to(self.device).detach()
        old_actions = torch.stack(memory['actions']).to(self.device).detach()
        old_logprobs = torch.stack(memory['logprobs']).to(self.device).detach()
        
        # Compute Rewards (Simple Monte Carlo for brevity, usually GAE is better)
        rewards = []
        discounted_reward = 0
        for reward, is_terminal in zip(reversed(memory['rewards']), reversed(memory['is_terminals'])):
            if is_terminal:
                discounted_reward = 0
            discounted_reward = reward + (self.gamma * discounted_reward)
            rewards.insert(0, discounted_reward)
            
        rewards = torch.tensor(rewards, dtype=torch.float32).to(self.device)
        rewards = (rewards - rewards.mean()) / (rewards.std() + 1e-7)
        
        # Optimize policy for K epochs
        for _ in range(self.K_epochs):
            logprobs, state_values, dist_entropy = self.policy.evaluate(old_states, old_actions)
            state_values = state_values.squeeze()
            
            ratios = torch.exp(logprobs - old_logprobs)
            advantages = rewards - state_values.detach()
            
            surr1 = ratios * advantages
            surr2 = torch.clamp(ratios, 1-self.eps_clip, 1+self.eps_clip) * advantages
            
            loss = -torch.min(surr1, surr2) + 0.5*nn.MSELoss()(state_values, rewards) - 0.01*dist_entropy
            
            self.optimizer.zero_grad()
            loss.mean().backward()
            self.optimizer.step()
            
        self.policy_old.load_state_dict(self.policy.state_dict())

    def train(self, max_episodes):
        memory = {'states': [], 'actions': [], 'logprobs': [], 'rewards': [], 'is_terminals': []}
        timestep = 0
        update_timestep = 2000
        
        for ep in range(1, max_episodes+1):
            state = self.env.reset()
            ep_reward = 0
            
            while True:
                timestep += 1
                action, log_prob = self.policy_old.act(state)
                next_state, reward, done, info = self.env.step(action)
                
                memory['states'].append(torch.from_numpy(state).float())
                memory['actions'].append(torch.tensor(action))
                memory['logprobs'].append(log_prob)
                memory['rewards'].append(reward)
                memory['is_terminals'].append(done)
                
                state = next_state
                ep_reward += reward
                
                if timestep % update_timestep == 0:
                    self.update(memory)
                    memory = {'states': [], 'actions': [], 'logprobs': [], 'rewards': [], 'is_terminals': []}
                    timestep = 0
                
                if done:
                    break
            
            self.writer.add_scalar('Reward', ep_reward, ep)
            self.writer.add_scalar('Cost', info['total_cost'], ep)
            self.writer.add_scalar('Incidence', info['cancer_incidence'], ep)
            
            if ep % 100 == 0:
                print(f"Episode {ep} | Reward: {ep_reward:.2f} | Cost: {info['total_cost']:.0f} | Incidence: {info['cancer_incidence']}")

        torch.save(self.policy.state_dict(), os.path.join(self.save_dir, f'ppo_{self.env.reward_mode}.pth'))
        print("Training Completed.")

# --------------------------------------------------------
# [4] Main Execution
# --------------------------------------------------------
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--settings', type=str, default='settings.ini')
    parser.add_argument('--max_episodes', type=int, default=10000)
    parser.add_argument('--reward_mode', type=str, default='icer', 
                        choices=['incidence', 'mortality', 'lyl', 'cost', 'icer'])
    parser.add_argument('--wtp', type=float, default=30000)
    
    args = parser.parse_args()
    
    # args.reward_mode와 args.wtp를 Trainer에게 전달
    trainer = PPOTrainer(
        settings_file=args.settings,
        reward_mode=args.reward_mode,
        wtp=args.wtp,
        log_dir=os.path.join('logs', f"ppo_{args.reward_mode}")
    )
    
    trainer.train(args.max_episodes)

if __name__ == '__main__':
    main()