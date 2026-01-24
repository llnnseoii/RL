import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.distributions import Categorical
import os

# 모듈 임포트
from parameters import SimulationParameters
from output import Output
from entities import Person

# --------------------------------------------------------
# [1] DRL 환경 정의 (Gym 스타일) - [수정] 차원 및 상태 정의 통일
# --------------------------------------------------------
class ColonoscopyDeepEnv:
    def __init__(self, settings_file):
        self.params = SimulationParameters(settings_file)
        self.min_age = self.params.opt_min_age
        self.max_age = self.params.opt_max_age
        self.max_history = 10
        
        # [수정] CQL 코드와 동일하게 16차원으로 통일 (Risk Factor 제거)
        # Age(1) + History(1) + Gender(1) + 13 Zones(13) = 16
        self.state_dim = 16
        self.action_dim = 2 # 0:Wait, 1:Screen

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
        
        # 시작부터 사망자인 경우 다시 생성
        while self.person.death_age <= self.current_age:
            self.person = Person(self.params, rng)
        
        return self._get_observation()

    def _get_observation(self):
        # 1. 기본 정보 (정규화)
        age_norm = self.current_age / 100.0
        hist_norm = self.years_since_last / 10.0
        gender = float(self.person.gender)
        
        # [수정] Risk Factor 제거 (CQL과 입력 크기 맞춤)
        
        # 2. 구역별 상태 (13개 구역) - [수정] CQL의 상태 정의와 일치시킴
        # 0:Healthy, 1:Early, 2:Adv, 3:Undetected, 4:Detected
        zones = np.zeros(13)
        
        # (1) 용종 상태 반영
        # (CQL의 OfflineDataCollector 로직과 동일해야 PPO 뇌가 헷갈리지 않음)
        adv_threshold = getattr(self.params, 'adv_polyp_transition', 5)
        
        for p in self.person.polyps:
            if p.age_developed <= self.current_age < p.age_end:
                loc = min(p.location, 12)
                if p.stage >= adv_threshold:
                    zones[loc] = 2 # Adv
                else:
                    zones[loc] = 1 # Early
        
        # (2) 암 상태 반영
        for c in self.person.cancers:
            if c.age_developed <= self.current_age:
                loc = min(c.location, 12)
                if c.detected:
                    zones[loc] = 4 # Det Cancer
                else:
                    zones[loc] = 3 # Undet Cancer

        # 16차원 벡터
        obs = np.array([age_norm, hist_norm, gender] + list(zones), dtype=np.float32)
        return obs

    def step(self, action):
        reward = 0.0
        done = False
        
        # Action 수행
        if action == 1: # Screen
            prev_cost = self.output.total_discounted_cost
            self.person._perform_colonoscopy(self.current_age, self.output, is_screening=True)
            step_cost = self.output.total_discounted_cost - prev_cost
            
            # 보상 설계 (비용 + 고통)
            reward -= (step_cost * 0.0001 + 0.05) 
            
            # [옵션] PPO도 암 발견시 추가 보상을 주면 학습이 더 빠름 (Shaping)
            # 여기서는 CQL 수집용 'Medium' 정책을 만드는 게 목적이므로,
            # 너무 완벽하지 않게 기본 페널티 위주로만 설정해도 됨.
            
            self.years_since_last = 0
        else:
            self.years_since_last = min(self.years_since_last + 1, self.max_history)

        # 생존 보상
        self.current_age += 1
        
        if self.current_age >= self.person.death_age:
            done = True
            reward -= 1.0 # 사망 페널티
        elif self.current_age >= self.max_age:
            done = True
            reward += 1.0 # 완주 보상
        else:
            reward += 0.1 # 1년 생존 보상

        return self._get_observation(), reward, done

# --------------------------------------------------------
# [2] PPO Actor-Critic Network
# --------------------------------------------------------
class ActorCritic(nn.Module):
    def __init__(self, state_dim, action_dim):
        super(ActorCritic, self).__init__()
        
        # Actor: 상태 -> 행동 확률
        self.actor = nn.Sequential(
            nn.Linear(state_dim, 256), # [수정] 노드 수 256으로 증강 (CQL과 유사하게)
            nn.ReLU(),
            nn.Linear(256, 256),
            nn.ReLU(),
            nn.Linear(256, action_dim),
            nn.Softmax(dim=-1)
        )
        
        # Critic: 상태 -> 가치
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
# [3] PPO 알고리즘 (학습기)
# --------------------------------------------------------
class PPOOptimizer:
    def __init__(self, settings_file):
        self.env = ColonoscopyDeepEnv(settings_file)
        self.policy = ActorCritic(self.env.state_dim, self.env.action_dim)
        self.optimizer = optim.Adam(self.policy.parameters(), lr=0.0003) # LR 조정
        self.policy_old = ActorCritic(self.env.state_dim, self.env.action_dim)
        self.policy_old.load_state_dict(self.policy.state_dict())
        
        # Hyperparameters
        self.gamma = 0.99
        self.eps_clip = 0.2
        self.K_epochs = 4
        self.update_timestep = 2000

    def train(self, max_episodes=1000):
        """
        max_episodes: CQL을 위한 'Medium' 수준 모델을 만들 것이므로
                      너무 오래(예: 10000번) 학습시킬 필요 없음. 
                      1000~2000 정도면 적당한 '어설픈 전문가'가 됨.
        """
        print(f">>> Starting PPO Training (Target: Medium Policy)...")
        print(f"    State Dim: {self.env.state_dim} (Synced with CQL)")
        
        memory_states, memory_actions, memory_logprobs, memory_rewards, memory_is_terminals = [], [], [], [], []
        timestep = 0
        
        for ep in range(1, max_episodes+1):
            state = self.env.reset()
            ep_reward = 0
            
            while True:
                timestep += 1
                
                # 1. 행동 결정
                action, log_prob = self.policy_old.act(state)
                
                # 2. 환경 진행
                next_state, reward, done = self.env.step(action)
                
                # 3. 메모리 저장
                memory_states.append(torch.from_numpy(state).float())
                memory_actions.append(torch.tensor(action))
                memory_logprobs.append(log_prob)
                memory_rewards.append(reward)
                memory_is_terminals.append(done)
                
                state = next_state
                ep_reward += reward
                
                # 4. 업데이트
                if timestep % self.update_timestep == 0:
                    self.update(memory_states, memory_actions, memory_logprobs, memory_rewards, memory_is_terminals)
                    memory_states, memory_actions, memory_logprobs, memory_rewards, memory_is_terminals = [], [], [], [], []
                
                if done:
                    break
            
            if ep % 100 == 0:
                print(f" [Episode {ep}] Reward: {ep_reward:.2f}")

        print(">>> PPO Training Complete.")
        
        # [중요] 모델 저장 (Actor만 저장)
        # CQL DataCollector가 이 파일을 불러와서 시뮬레이션을 돌립니다.
        save_path = "ppo_actor_medium.pth"
        torch.save(self.policy.actor.state_dict(), save_path)
        print(f">>> Model Saved to '{save_path}' (Ready for CQL)")

    def update(self, states, actions, logprobs, rewards, is_terminals):
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
        
        for _ in range(self.K_epochs):
            logprobs, state_values, dist_entropy = self.policy.evaluate(old_states, old_actions)
            state_values = torch.squeeze(state_values)
            
            ratios = torch.exp(logprobs - old_logprobs)
            advantages = discounted_rewards - state_values.detach()
            
            surr1 = ratios * advantages
            surr2 = torch.clamp(ratios, 1-self.eps_clip, 1+self.eps_clip) * advantages
            
            loss = -torch.min(surr1, surr2) + 0.5 * nn.MSELoss()(state_values, discounted_rewards) - 0.01 * dist_entropy
            
            self.optimizer.zero_grad()
            loss.mean().backward()
            self.optimizer.step()
            
        self.policy_old.load_state_dict(self.policy.state_dict())

    def print_sample_decisions(self):
        print("\n=== PPO Sample Decisions ===")
        # 차원이 16으로 바뀌었으므로 테스트 벡터도 수정
        s1 = np.zeros(16, dtype=np.float32)
        s1[0] = 0.5; s1[1] = 1.0; s1[2] = 1.0 # Age50, Hist10, Male
        act1, _ = self.policy_old.act(s1)
        print(f" -> 건강함: {'검사' if act1==1 else '대기'}")
        
        s2 = s1.copy()
        s2[3+5] = 2 # Zone 5 = Adv Polyp (Index 3부터 Zone 시작)
        act2, _ = self.policy_old.act(s2)
        print(f" -> 진행성 용종: {'검사' if act2==1 else '대기'}")