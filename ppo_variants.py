"""
PPO Variants with Actual Training - Conservative, Balanced, Aggressive

각 variant별로 PPO를 실제로 학습시킨 후 episode 데이터를 수집합니다.
"""

import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
from typing import List, Dict
import pickle

from parameters import SimulationParameters
from output import Output
from entities import Person


# ==================== PPO Network (drl_optimizer와 동일) ====================
class ActorCritic(nn.Module):
    def __init__(self, state_dim, action_dim):
        super(ActorCritic, self).__init__()
        
        # Actor
        self.actor = nn.Sequential(
            nn.Linear(state_dim, 256),
            nn.ReLU(),
            nn.Linear(256, 256),
            nn.ReLU(),
            nn.Linear(256, action_dim),
            nn.Softmax(dim=-1)
        )
        
        # Critic
        self.critic = nn.Sequential(
            nn.Linear(state_dim, 256),
            nn.ReLU(),
            nn.Linear(256, 256),
            nn.ReLU(),
            nn.Linear(256, 1)
        )
    
    def forward(self):
        raise NotImplementedError
    
    def act(self, state):
        state = torch.from_numpy(state).float()
        action_probs = self.actor(state)
        dist = torch.distributions.Categorical(action_probs)
        action = dist.sample()
        return action.item(), dist.log_prob(action)
    
    def evaluate(self, state, action):
        action_probs = self.actor(state)
        dist = torch.distributions.Categorical(action_probs)
        action_logprobs = dist.log_prob(action)
        dist_entropy = dist.entropy()
        state_value = self.critic(state)
        return action_logprobs, torch.squeeze(state_value), dist_entropy


# ==================== Simplified Environment ====================
class ScreeningEnv:
    """간소화된 검진 환경 (PPO 학습용)"""
    
    def __init__(self, params, variant='balanced'):
        self.params = params
        self.variant = variant
        self.min_age = params.opt_min_age
        self.max_age = params.opt_max_age
        self.state_dim = 16
        self.max_history = 10
        
        # Variant별 reward 파라미터
        if variant == 'conservative':
            self.cost_penalty = 0.10
            self.survival_reward = 0.1
            self.cancer_bonus = 0.0
        elif variant == 'balanced':
            self.cost_penalty = 0.05
            self.survival_reward = 0.1
            self.cancer_bonus = 0.0
        else:  # aggressive
            self.cost_penalty = 0.02
            self.survival_reward = 0.15
            self.cancer_bonus = 2.0
        
        self.reset()
    
    def reset(self):
        """새로운 person으로 리셋"""
        self.rng = np.random.default_rng()
        self.person = Person(self.params, self.rng)
        self.person.simulate()
        
        self.output = Output(self.params)
        self.current_age = self.min_age
        self.years_since_last = self.max_history
        
        return self._get_state()
    
    def _get_state(self):
        """State vector 생성"""
        age_norm = self.current_age / 100.0
        hist_norm = self.years_since_last / 10.0
        gender = float(self.person.gender)
        zones = np.zeros(13)
        
        adv_threshold = getattr(self.params, 'adv_polyp_transition', 5)
        for p in self.person.polyps:
            if p.age_developed <= self.current_age < p.age_end:
                loc = min(p.location, 12)
                if p.stage >= adv_threshold:
                    zones[loc] = 2
                else:
                    zones[loc] = 1
        
        for c in self.person.cancers:
            if c.age_developed <= self.current_age:
                loc = min(c.location, 12)
                if c.detected:
                    zones[loc] = 4
                else:
                    zones[loc] = 3
        
        return np.array([age_norm, hist_norm, gender] + list(zones), dtype=np.float32)
    
    def step(self, action):
        """Action 수행"""
        reward = 0.0
        
        if action == 1:  # Screen
            prev_cost = self.output.total_discounted_cost
            self.person._perform_colonoscopy(self.current_age, self.output, is_screening=True)
            step_cost = self.output.total_discounted_cost - prev_cost
            
            reward -= (step_cost * 0.0001 + self.cost_penalty)
            
            # Aggressive: 암 발견 보너스
            if self.variant == 'aggressive' and self.output.screen_detections > 0:
                reward += self.cancer_bonus
            
            self.years_since_last = 0
        else:
            self.years_since_last = min(self.years_since_last + 1, self.max_history)
        
        # 나이 증가
        self.current_age += 1
        done = False
        
        if self.current_age >= self.person.death_age:
            reward -= 1.0
            done = True
        elif self.current_age >= self.max_age:
            reward += 1.0
            done = True
        else:
            reward += self.survival_reward
        
        return self._get_state(), reward, done


# ==================== PPO Trainer ====================
class PPOTrainer:
    """PPO 학습기"""
    
    def __init__(self, params, variant='balanced'):
        self.params = params
        self.variant = variant
        self.env = ScreeningEnv(params, variant)
        
        self.state_dim = 16
        self.action_dim = 2
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        
        # Networks
        self.policy = ActorCritic(self.state_dim, self.action_dim).to(self.device)
        self.policy_old = ActorCritic(self.state_dim, self.action_dim).to(self.device)
        self.policy_old.load_state_dict(self.policy.state_dict())
        
        self.optimizer = optim.Adam(self.policy.parameters(), lr=3e-4)
        
        # Hyperparameters
        self.gamma = 0.99
        self.K_epochs = 4
        self.eps_clip = 0.2
        self.update_timestep = 2000
    
    def train(self, max_episodes=1000):
        """PPO 학습"""
        print(f"\n🎓 Training {self.variant.upper()} PPO for {max_episodes} episodes...")
        
        timestep = 0
        memory_states = []
        memory_actions = []
        memory_logprobs = []
        memory_rewards = []
        memory_is_terminals = []
        
        for ep in range(1, max_episodes + 1):
            state = self.env.reset()
            ep_reward = 0
            
            while True:
                timestep += 1
                
                # Action 선택
                action, log_prob = self.policy_old.act(state)
                
                # 환경 진행
                next_state, reward, done = self.env.step(action)
                
                # 메모리 저장
                memory_states.append(torch.from_numpy(state).float())
                memory_actions.append(torch.tensor(action))
                memory_logprobs.append(log_prob)
                memory_rewards.append(reward)
                memory_is_terminals.append(done)
                
                state = next_state
                ep_reward += reward
                
                # 업데이트
                if timestep % self.update_timestep == 0:
                    self.update(memory_states, memory_actions, memory_logprobs, 
                               memory_rewards, memory_is_terminals)
                    memory_states, memory_actions, memory_logprobs = [], [], []
                    memory_rewards, memory_is_terminals = [], []
                
                if done:
                    break
            
            if ep % 100 == 0:
                print(f"  Episode {ep}/{max_episodes}: Reward = {ep_reward:.2f}")
        
        print(f"✅ {self.variant.upper()} PPO Training Complete!")
        return self.policy
    
    def update(self, states, actions, logprobs, rewards, is_terminals):
        """PPO 업데이트"""
        # Discount rewards
        discounted_rewards = []
        discounted_reward = 0
        for reward, is_terminal in zip(reversed(rewards), reversed(is_terminals)):
            if is_terminal:
                discounted_reward = 0
            discounted_reward = reward + (self.gamma * discounted_reward)
            discounted_rewards.insert(0, discounted_reward)
        
        discounted_rewards = torch.tensor(discounted_rewards, dtype=torch.float32)
        if len(discounted_rewards) > 1:
            discounted_rewards = (discounted_rewards - discounted_rewards.mean()) / (discounted_rewards.std() + 1e-5)
        
        old_states = torch.stack(states)
        old_actions = torch.stack(actions)
        old_logprobs = torch.stack(logprobs).detach()
        
        # 여러 epoch 업데이트
        for _ in range(self.K_epochs):
            logprobs, state_values, dist_entropy = self.policy.evaluate(old_states, old_actions)
            
            ratios = torch.exp(logprobs - old_logprobs)
            advantages = discounted_rewards - state_values.detach()
            
            surr1 = ratios * advantages
            surr2 = torch.clamp(ratios, 1 - self.eps_clip, 1 + self.eps_clip) * advantages
            
            loss = -torch.min(surr1, surr2) + 0.5 * F.mse_loss(state_values, discounted_rewards) - 0.01 * dist_entropy
            
            self.optimizer.zero_grad()
            loss.mean().backward()
            self.optimizer.step()
        
        self.policy_old.load_state_dict(self.policy.state_dict())
    
    def collect_episodes(self, n_episodes=1000):
        """학습된 policy로 episode 수집"""
        print(f"\n📊 Collecting {n_episodes} episodes with trained {self.variant.upper()} policy...")
        
        episodes = []
        
        for ep_idx in range(n_episodes):
            episode_data = self._run_episode()
            episodes.append(episode_data)
            
            if (ep_idx + 1) % 100 == 0:
                avg_reward = np.mean([e['total_reward'] for e in episodes[-100:]])
                print(f"  [{ep_idx+1}/{n_episodes}] Avg Reward: {avg_reward:.2f}")
        
        print(f"✅ {len(episodes)} episodes collected!")
        return episodes
    
    def _run_episode(self):
        """단일 episode 실행 및 데이터 수집"""
        state = self.env.reset()
        
        transitions = []
        total_reward = 0.0
        num_screenings = 0
        cancer_detected = False
        
        while True:
            # Trained policy로 action 선택
            action, _ = self.policy_old.act(state)
            
            # Step
            next_state, reward, done = self.env.step(action)
            
            if action == 1:
                num_screenings += 1
                if self.env.output.screen_detections > 0:
                    cancer_detected = True
            
            # Transition 저장
            transitions.append({
                'state': state,
                'action': action,
                'reward': reward,
                'next_state': next_state,
                'done': done
            })
            
            total_reward += reward
            state = next_state
            
            if done:
                break
        
        # Episode summary
        life_years_gained = min(
            self.env.current_age - self.env.min_age,
            self.env.person.death_age - self.env.min_age
        )
        
        return {
            'total_reward': total_reward,
            'life_years_gained': life_years_gained,
            'total_cost': self.env.output.total_discounted_cost,
            'cancer_detected': cancer_detected,
            'num_screenings': num_screenings,
            'transitions': transitions,
            'variant': self.variant
        }


# ==================== Main Function ====================
def train_and_collect_all_variants(params, episodes_per_variant=1000, 
                                   training_episodes=1000, save_path='diverse_ppo_data.pkl'):
    """
    3가지 PPO variant 학습 후 episode 수집
    
    Args:
        params: SimulationParameters
        episodes_per_variant: 수집할 episode 수
        training_episodes: PPO 학습 episode 수
        save_path: 저장 경로
    
    Returns:
        전체 episode 리스트
    """
    all_episodes = []
    
    for variant in ['conservative', 'balanced', 'aggressive']:
        print(f"\n{'='*60}")
        print(f"  Variant: {variant.upper()}")
        print(f"{'='*60}")
        
        # PPO 학습
        trainer = PPOTrainer(params, variant=variant)
        trainer.train(max_episodes=training_episodes)
        
        # Episode 수집
        episodes = trainer.collect_episodes(n_episodes=episodes_per_variant)
        all_episodes.extend(episodes)
        
        # 모델 저장 (선택사항)
        torch.save(trainer.policy.state_dict(), f'ppo_{variant}.pth')
        print(f"💾 Model saved: ppo_{variant}.pth")
    
    # 전체 데이터 저장
    with open(save_path, 'wb') as f:
        pickle.dump(all_episodes, f)
    
    print(f"\n{'='*60}")
    print(f"✅ 전체 {len(all_episodes)} episodes 저장: {save_path}")
    print(f"{'='*60}")
    print(f"  Conservative: {sum(1 for e in all_episodes if e['variant'] == 'conservative')}")
    print(f"  Balanced: {sum(1 for e in all_episodes if e['variant'] == 'balanced')}")
    print(f"  Aggressive: {sum(1 for e in all_episodes if e['variant'] == 'aggressive')}")
    print(f"{'='*60}")
    
    return all_episodes


if __name__ == "__main__":
    from parameters import SimulationParameters
    
    params = SimulationParameters('settings.ini')
    
    # 3가지 variant 학습 및 수집
    dataset = train_and_collect_all_variants(
        params,
        episodes_per_variant=1000,    # 수집할 episodes
        training_episodes=1000,        # 학습 episodes
        save_path='diverse_ppo_data.pkl'
    )

    """다양한 PPO 정책으로 데이터 수집"""
    
    def __init__(self, params, variant='balanced'):
        """
        Args:
            variant: 'conservative', 'balanced', 'aggressive'
        """
        self.params = params
        self.variant = variant
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        
        # Variant별 reward 설정
        if variant == 'conservative':
            self.cost_penalty = 0.10  # 높은 비용 페널티
            self.survival_reward = 0.1
            self.cancer_detection_bonus = 0.0
            print("🟦 Conservative Policy: 비용 중시, 검진 최소화")
            
        elif variant == 'balanced':
            self.cost_penalty = 0.05  # 표준
            self.survival_reward = 0.1
            self.cancer_detection_bonus = 0.0
            print("🟩 Balanced Policy: 표준 가이드라인")
            
        elif variant == 'aggressive':
            self.cost_penalty = 0.02  # 낮은 비용 페널티
            self.survival_reward = 0.15  # 높은 생존 보상
            self.cancer_detection_bonus = 2.0  # 암 발견 보상
            print("🟥 Aggressive Policy: 생존 중시, 조기 발견")
        
        self.min_age = params.opt_min_age
        self.max_age = params.opt_max_age
        self.state_dim = 16
        self.max_history = 10
    
    def collect_episodes(self, n_episodes=1000, rng_seed=42) -> List[Dict]:
        """
        지정된 수의 episode 데이터 수집
        
        Returns:
            List of episode data with quality metrics
        """
        episodes = []
        rng = np.random.default_rng(rng_seed)
        
        print(f"\n📊 {self.variant.upper()} Policy로 {n_episodes} episodes 수집 중...")
        
        for ep_idx in range(n_episodes):
            episode_data = self._run_episode(rng)
            episodes.append(episode_data)
            
            if (ep_idx + 1) % 100 == 0:
                avg_reward = np.mean([e['total_reward'] for e in episodes[-100:]])
                print(f"  [{ep_idx+1}/{n_episodes}] Avg Reward: {avg_reward:.2f}")
        
        print(f"✅ {len(episodes)} episodes 수집 완료!")
        return episodes
    
    def _run_episode(self, rng) -> Dict:
        """단일 episode 실행 및 데이터 수집"""
        # Person 생성 및 시뮬레이션
        person = Person(self.params, rng)
        person.simulate()
        
        output = Output(self.params)
        
        # Episode 실행
        transitions = []
        total_reward = 0.0
        num_screenings = 0
        cancer_detected = False
        
        current_age = self.min_age
        years_since_last = self.max_history
        
        while current_age < min(person.death_age, self.max_age):
            # State 생성
            state = self._get_state_vector(person, current_age, years_since_last)
            
            # Action 선택 (Random policy - PPO 학습 전이므로)
            action = self._select_action_random()
            
            # Action 수행
            if action == 1:  # Screen
                prev_cost = output.total_discounted_cost
                person._perform_colonoscopy(current_age, output, is_screening=True)
                step_cost = output.total_discounted_cost - prev_cost
                
                # Variant별 reward 계산
                reward = -(step_cost * 0.0001 + self.cost_penalty)
                
                # Aggressive: 암 발견 보너스
                if self.variant == 'aggressive' and output.screen_detections > 0:
                    reward += self.cancer_detection_bonus
                    cancer_detected = True
                
                num_screenings += 1
                years_since_last = 0
            else:
                reward = 0
                years_since_last = min(years_since_last + 1, self.max_history)
            
            # 생존 보상
            current_age += 1
            done = False
            
            if current_age >= person.death_age:
                reward -= 1.0  # 사망 페널티
                done = True
            elif current_age >= self.max_age:
                reward += 1.0  # 완주 보상
                done = True
            else:
                reward += self.survival_reward
            
            # Next state
            next_state = self._get_state_vector(person, current_age, years_since_last)
            
            # Transition 저장
            transitions.append({
                'state': state,
                'action': action,
                'reward': reward,
                'next_state': next_state,
                'done': done
            })
            
            total_reward += reward
            
            if done:
                break
        
        # Episode summary
        life_years_gained = min(current_age - self.min_age, person.death_age - self.min_age)
        
        return {
            'total_reward': total_reward,
            'life_years_gained': life_years_gained,
            'total_cost': output.total_discounted_cost,
            'cancer_detected': cancer_detected,
            'num_screenings': num_screenings,
            'transitions': transitions,
            'variant': self.variant
        }
    
    def _get_state_vector(self, person, age, history):
        """State vector 생성"""
        age_norm = age / 100.0
        hist_norm = history / 10.0
        gender = float(person.gender)
        zones = np.zeros(13)
        
        adv_threshold = getattr(self.params, 'adv_polyp_transition', 5)
        for p in person.polyps:
            if p.age_developed <= age < p.age_end:
                loc = min(p.location, 12)
                if p.stage >= adv_threshold:
                    zones[loc] = 2
                else:
                    zones[loc] = 1
        
        for c in person.cancers:
            if c.age_developed <= age:
                loc = min(c.location, 12)
                if c.detected:
                    zones[loc] = 4
                else:
                    zones[loc] = 3
        
        return np.array([age_norm, hist_norm, gender] + list(zones), dtype=np.float32)
    
    def _select_action_random(self):
        """Random action (PPO 학습 전 baseline)"""
        return np.random.choice([0, 1])


# ==================== Main Collection Function ====================
def collect_diverse_dataset(params, episodes_per_variant=1000, save_path='diverse_ppo_data.pkl'):
    """
    3가지 PPO variant로 diverse dataset 수집
    
    Args:
        params: SimulationParameters
        episodes_per_variant: 각 variant당 episode 수
        save_path: 저장 경로
    
    Returns:
        전체 episode 리스트
    """
    all_episodes = []
    
    for variant in ['conservative', 'balanced', 'aggressive']:
        collector = PPOVariantCollector(params, variant=variant)
        episodes = collector.collect_episodes(n_episodes=episodes_per_variant)
        all_episodes.extend(episodes)
    
    # 저장
    with open(save_path, 'wb') as f:
        pickle.dump(all_episodes, f)
    
    print(f"\n💾 총 {len(all_episodes)} episodes 저장: {save_path}")
    
    return all_episodes


if __name__ == "__main__":
    from parameters import SimulationParameters
    
    params = SimulationParameters('settings.ini')
    
    # Diverse dataset 수집 (각 1000 episodes)
    dataset = collect_diverse_dataset(
        params,
        episodes_per_variant=1000,
        save_path='diverse_ppo_data.pkl'
    )
    
    print("\n📊 Dataset 통계:")
    print(f"  Conservative: {sum(1 for e in dataset if e['variant'] == 'conservative')}")
    print(f"  Balanced: {sum(1 for e in dataset if e['variant'] == 'balanced')}")
    print(f"  Aggressive: {sum(1 for e in dataset if e['variant'] == 'aggressive')}")
