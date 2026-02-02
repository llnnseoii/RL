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

# 모듈 임포트
from parameters import SimulationParameters
from output import Output
from entities import Person

# --------------------------------------------------------
# [1] 최적화용 강화학습 환경 (Gym 스타일)
# --------------------------------------------------------
class ColonoscopyOptimalEnv:
    """
    대장암 검진 최적화를 위한 강화학습 환경
    - 목표: 최적의 검진 정책 학습 (Medium이 아닌 Best Policy)
    - 상태: 16차원 (Age, History, Gender, 13 Zones)
    - 행동: 2개 (Wait, Screen)
    """
    def __init__(self, settings_file):
        self.params = SimulationParameters(settings_file)
        self.min_age = self.params.opt_min_age
        self.max_age = min(self.params.opt_max_age, 85)  # 최대 85세까지
        self.max_history = 10
        
        # 상태 공간: CQL과 동일하게 16차원
        # Age(1) + History(1) + Gender(1) + 13 Zones(13) = 16
        self.state_dim = 16
        self.action_dim = 2  # 0:Wait, 1:Screen
        
        self.person = None
        self.current_age = 0
        self.years_since_last = 0
        self.output = None
        
        # 통계 추적용
        self.total_screenings = 0
        self.cancers_detected = 0
        self.cancers_prevented = 0
        
    def reset(self):
        """환경 초기화 및 첫 관찰 반환"""
        rng = np.random.default_rng()
        self.person = Person(self.params, rng)
        self.current_age = self.min_age
        self.years_since_last = self.max_history
        self.output = Output(self.params)
        
        # 통계 초기화
        self.total_screenings = 0
        self.cancers_detected = 0
        self.cancers_prevented = 0
        
        # 시작부터 사망자인 경우 다시 생성
        max_attempts = 100
        attempts = 0
        while self.person.death_age <= self.current_age and attempts < max_attempts:
            self.person = Person(self.params, rng)
            attempts += 1
        
        if attempts >= max_attempts:
            # 최악의 경우 death_age를 강제로 연장
            self.person.death_age = self.max_age + 10
        
        return self._get_observation()
    
    def _get_observation(self):
        """현재 상태를 16차원 벡터로 반환"""
        # 1. 기본 정보 (정규화)
        age_norm = self.current_age / 100.0
        hist_norm = min(self.years_since_last, 10) / 10.0
        gender = float(self.person.gender)
        
        # 2. 구역별 상태 (13개 구역)
        # 0:Healthy, 1:Early Polyp, 2:Adv Polyp, 3:Undetected Cancer, 4:Detected Cancer
        zones = np.zeros(13, dtype=np.float32)
        
        adv_threshold = getattr(self.params, 'adv_polyp_transition', 5)
        
        # 용종 상태 반영
        for p in self.person.polyps:
            if p.age_developed <= self.current_age < p.age_end:
                loc = min(p.location, 12)
                if p.stage >= adv_threshold:
                    zones[loc] = max(zones[loc], 2.0)  # Advanced
                else:
                    zones[loc] = max(zones[loc], 1.0)  # Early
        
        # 암 상태 반영 (더 높은 우선순위)
        for c in self.person.cancers:
            if c.age_developed <= self.current_age:
                loc = min(c.location, 12)
                if c.detected:
                    zones[loc] = 4.0  # Detected Cancer
                else:
                    zones[loc] = 3.0  # Undetected Cancer
        
        # 16차원 벡터 구성
        obs = np.array([age_norm, hist_norm, gender] + list(zones), dtype=np.float32)
        return obs
    
    def step(self, action):
        """
        행동 수행 및 다음 상태, 보상, 종료 여부 반환
        
        향상된 보상 설계:
        - 생존 보상 (기본)
        - 검진 페널티 (비용 + 불편함)
        - 암 조기 발견 보너스
        - 암 예방 보상
        - 사망 페널티
        """
        reward = 0.0
        done = False
        info = {}
        
        # 이전 암 상태 기록 (조기 발견 보너스용)
        undetected_cancers_before = [c for c in self.person.cancers 
                                     if not c.detected and not c.prevented 
                                     and c.age_developed <= self.current_age]
        
        # Action 수행
        if action == 1:  # Screen
            self.total_screenings += 1
            prev_cost = self.output.total_discounted_cost
            
            # 용종/암 카운트 (예방 보상용)
            polyps_before = len([p for p in self.person.polyps 
                                if p.age_developed <= self.current_age < p.age_end])
            
            # 검진 수행
            self.person._perform_colonoscopy(self.current_age, self.output, is_screening=True)
            
            step_cost = self.output.total_discounted_cost - prev_cost
            
            # --- 보상 설계 ---
            # 1. 검진 비용 페널티 (정규화)
            cost_penalty = step_cost * 0.0001
            
            # 2. 불편함 페널티
            discomfort_penalty = 0.02
            
            reward -= (cost_penalty + discomfort_penalty)
            
            # 3. 암 조기 발견 보너스 (큰 양수 보상)
            newly_detected_cancers = [c for c in self.person.cancers 
                                     if c.detected and c in undetected_cancers_before]
            if newly_detected_cancers:
                # 조기 단계 암일수록 더 큰 보상
                for c in newly_detected_cancers:
                    stage_bonus = (5 - c.symptoms_stage) * 0.5  # Stage 1: +2.0, Stage 4: +0.5
                    reward += (3.0 + stage_bonus)
                    self.cancers_detected += 1  # 발견한 암마다 1씩 증가
            
            # 4. 용종 제거 보상 (암 예방)
            polyps_after = len([p for p in self.person.polyps 
                               if p.age_developed <= self.current_age < p.age_end])
            removed_polyps = polyps_before - polyps_after
            if removed_polyps > 0:
                reward += removed_polyps * 0.5
                self.cancers_prevented += removed_polyps  # 제거한 용종 개수만큼 증가
            
            self.years_since_last = 0
            
        else:  # Wait
            self.years_since_last = min(self.years_since_last + 1, self.max_history)
            
            # 대기에 대한 작은 페널티 (너무 소극적 방지)
            # 단, 최근 검진 후라면 페널티 없음
            if self.years_since_last > 5:
                reward -= 0.005
        
        # 나이 증가
        self.current_age += 1
        
        # --- 종료 조건 및 최종 보상 ---
        if self.current_age >= self.person.death_age:
            done = True
            
            # 암으로 인한 조기 사망인지 확인
            if self.person.death_age < self.person.natural_death_age:
                # 큰 페널티
                years_lost = self.person.natural_death_age - self.person.death_age
                reward -= (10.0 + years_lost * 0.5)
                info['death_reason'] = 'cancer'
            else:
                # 자연사: 작은 보너스
                reward += 2.0
                info['death_reason'] = 'natural'
                
        elif self.current_age >= self.max_age:
            done = True
            # 시뮬레이션 완주 보상
            reward += 5.0
            info['death_reason'] = 'completed'
        else:
            # 1년 생존 보상
            reward += 0.15
        
        # 통계 정보
        info['total_screenings'] = self.total_screenings
        info['cancers_detected'] = self.cancers_detected
        info['cancers_prevented'] = self.cancers_prevented
        
        return self._get_observation(), reward, done, info


# --------------------------------------------------------
# [2] 향상된 Actor-Critic 네트워크 (더 큰 용량)
# --------------------------------------------------------
class ActorCritic(nn.Module):
    """
    PPO용 Actor-Critic 네트워크
    - 더 큰 용량 (512 hidden units)
    - LayerNorm으로 안정성 향상
    - Dropout으로 과적합 방지
    """
    def __init__(self, state_dim, action_dim, hidden_size=512):
        super(ActorCritic, self).__init__()
        
        # Actor: 상태 -> 행동 확률
        self.actor = nn.Sequential(
            nn.Linear(state_dim, hidden_size),
            nn.LayerNorm(hidden_size),
            nn.Tanh(),
            nn.Dropout(0.1),
            
            nn.Linear(hidden_size, hidden_size),
            nn.LayerNorm(hidden_size),
            nn.Tanh(),
            nn.Dropout(0.1),
            
            nn.Linear(hidden_size, 256),
            nn.Tanh(),
            
            nn.Linear(256, action_dim),
            nn.Softmax(dim=-1)
        )
        
        # Critic: 상태 -> 가치 함수
        self.critic = nn.Sequential(
            nn.Linear(state_dim, hidden_size),
            nn.LayerNorm(hidden_size),
            nn.Tanh(),
            nn.Dropout(0.1),
            
            nn.Linear(hidden_size, hidden_size),
            nn.LayerNorm(hidden_size),
            nn.Tanh(),
            nn.Dropout(0.1),
            
            nn.Linear(hidden_size, 256),
            nn.Tanh(),
            
            nn.Linear(256, 1)
        )
        
        # 가중치 초기화
        self.apply(self._init_weights)
    
    def _init_weights(self, module):
        """Xavier uniform 초기화"""
        if isinstance(module, nn.Linear):
            nn.init.xavier_uniform_(module.weight)
            if module.bias is not None:
                nn.init.constant_(module.bias, 0)
    
    def forward(self):
        raise NotImplementedError
    
    def act(self, state):
        """주어진 상태에서 행동 선택"""
        if isinstance(state, np.ndarray):
            state = torch.from_numpy(state).float().unsqueeze(0)
        
        probs = self.actor(state)
        dist = Categorical(probs)
        action = dist.sample()
        
        return action.item(), dist.log_prob(action)
    
    def evaluate(self, state, action):
        """정책 평가 (학습용)"""
        probs = self.actor(state)
        dist = Categorical(probs)
        
        action_logprobs = dist.log_prob(action)
        dist_entropy = dist.entropy()
        state_values = self.critic(state)
        
        return action_logprobs, state_values, dist_entropy


# --------------------------------------------------------
# [3] GAE를 사용하는 PPO Trainer
# --------------------------------------------------------
class PPOTrainer:
    """
    Proximal Policy Optimization with Generalized Advantage Estimation
    
    주요 기능:
    - GAE (λ=0.95) for advantage estimation
    - Learning rate scheduling (cosine annealing)
    - Entropy coefficient decay
    - Gradient clipping
    - TensorBoard logging
    - Model checkpointing
    """
    def __init__(self, settings_file, save_dir='models', log_dir='logs', device=None):
        self.env = ColonoscopyOptimalEnv(settings_file)
        self.save_dir = save_dir
        self.log_dir = log_dir
        
        # Device 설정
        if device is None:
            self.device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
        else:
            self.device = torch.device(device)
        
        print(f"Using device: {self.device}")
        
        # 네트워크 생성
        self.policy = ActorCritic(self.env.state_dim, self.env.action_dim).to(self.device)
        self.policy_old = ActorCritic(self.env.state_dim, self.env.action_dim).to(self.device)
        self.policy_old.load_state_dict(self.policy.state_dict())
        self.policy_old.eval()
        
        # Hyperparameters
        self.gamma = 0.99  # Discount factor
        self.gae_lambda = 0.95  # GAE lambda
        self.eps_clip = 0.2  # PPO clip parameter
        self.K_epochs = 10  # Update epochs
        self.batch_size = 256  # Batch size
        self.mini_batch_size = 64  # Mini-batch size
        self.max_grad_norm = 0.5  # Gradient clipping
        
        # Learning rate scheduling
        self.lr_start = 3e-4
        self.lr_end = 1e-5
        self.optimizer = optim.Adam(self.policy.parameters(), lr=self.lr_start)
        
        # Entropy coefficient (decay over time)
        self.entropy_coef_start = 0.01
        self.entropy_coef_end = 0.001
        self.entropy_coef = self.entropy_coef_start
        
        # 디렉토리 생성
        os.makedirs(self.save_dir, exist_ok=True)
        os.makedirs(self.log_dir, exist_ok=True)
        
        # TensorBoard writer
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        self.writer = SummaryWriter(os.path.join(self.log_dir, f'ppo_optimal_{timestamp}'))
        
        # 통계
        self.best_reward = float('-inf')
        self.total_timesteps = 0
    
    def compute_gae(self, rewards, values, dones, next_value):
        """
        Generalized Advantage Estimation (GAE) 계산
        
        δ_t = r_t + γV(s_{t+1}) - V(s_t)
        A_t = δ_t + (γλ)δ_{t+1} + (γλ)²δ_{t+2} + ...
        """
        advantages = []
        gae = 0
        
        # 역순으로 계산
        for t in reversed(range(len(rewards))):
            if t == len(rewards) - 1:
                next_val = next_value
            else:
                next_val = values[t + 1]
            
            # TD error: δ_t = r_t + γV(s_{t+1})(1 - done) - V(s_t)
            delta = rewards[t] + self.gamma * next_val * (1 - dones[t]) - values[t]
            
            # GAE: A_t = δ_t + (γλ)A_{t+1}(1 - done)
            gae = delta + self.gamma * self.gae_lambda * (1 - dones[t]) * gae
            advantages.insert(0, gae)
        
        return advantages
    
    def update_learning_rate(self, episode, max_episodes):
        """Cosine annealing learning rate schedule"""
        progress = episode / max_episodes
        lr = self.lr_end + 0.5 * (self.lr_start - self.lr_end) * (1 + np.cos(np.pi * progress))
        
        for param_group in self.optimizer.param_groups:
            param_group['lr'] = lr
        
        return lr
    
    def update_entropy_coef(self, episode, max_episodes):
        """Entropy coefficient linear decay"""
        progress = episode / max_episodes
        self.entropy_coef = self.entropy_coef_start - progress * (self.entropy_coef_start - self.entropy_coef_end)
        return self.entropy_coef
    
    def update(self, memory):
        """
        PPO update using collected memory
        
        Args:
            memory: dict with keys ['states', 'actions', 'logprobs', 'rewards', 'dones', 'values']
        """
        # 메모리에서 데이터 추출
        old_states = torch.stack(memory['states']).to(self.device).detach()
        old_actions = torch.stack(memory['actions']).to(self.device).detach()
        old_logprobs = torch.stack(memory['logprobs']).to(self.device).detach()
        
        # Value 계산 (numpy -> tensor)
        with torch.no_grad():
            values = self.policy_old.critic(old_states).squeeze().cpu().numpy()
            last_state = memory['states'][-1].unsqueeze(0).to(self.device)
            next_value = self.policy_old.critic(last_state).squeeze().cpu().item()
        
        # GAE 계산
        advantages = self.compute_gae(
            memory['rewards'],
            values,
            memory['dones'],
            next_value
        )
        
        advantages = torch.tensor(advantages, dtype=torch.float32).to(self.device)
        
        # Returns 계산: R_t = A_t + V(s_t)
        returns = advantages + torch.tensor(values, dtype=torch.float32).to(self.device)
        
        # Normalize advantages
        advantages = (advantages - advantages.mean()) / (advantages.std() + 1e-8)
        
        # Mini-batch update
        dataset_size = old_states.size(0)
        
        for _ in range(self.K_epochs):
            # 데이터 셔플
            indices = torch.randperm(dataset_size)
            
            for start_idx in range(0, dataset_size, self.mini_batch_size):
                end_idx = min(start_idx + self.mini_batch_size, dataset_size)
                batch_indices = indices[start_idx:end_idx]
                
                # Mini-batch 추출
                batch_states = old_states[batch_indices]
                batch_actions = old_actions[batch_indices]
                batch_old_logprobs = old_logprobs[batch_indices]
                batch_advantages = advantages[batch_indices]
                batch_returns = returns[batch_indices]
                
                # 정책 평가
                logprobs, state_values, dist_entropy = self.policy.evaluate(batch_states, batch_actions)
                state_values = state_values.squeeze()
                
                # Ratio: π(a|s) / π_old(a|s)
                ratios = torch.exp(logprobs - batch_old_logprobs)
                
                # Surrogate loss
                surr1 = ratios * batch_advantages
                surr2 = torch.clamp(ratios, 1 - self.eps_clip, 1 + self.eps_clip) * batch_advantages
                
                # Actor loss (negative because we want to maximize)
                actor_loss = -torch.min(surr1, surr2).mean()
                
                # Critic loss (MSE)
                critic_loss = 0.5 * nn.MSELoss()(state_values, batch_returns)
                
                # Entropy bonus (encourage exploration)
                entropy_loss = -dist_entropy.mean()
                
                # Total loss
                loss = actor_loss + critic_loss + self.entropy_coef * entropy_loss
                
                # Gradient update
                self.optimizer.zero_grad()
                loss.backward()
                nn.utils.clip_grad_norm_(self.policy.parameters(), self.max_grad_norm)
                self.optimizer.step()
        
        # Old policy 업데이트
        self.policy_old.load_state_dict(self.policy.state_dict())
        
        # Return losses for logging
        return {
            'actor_loss': actor_loss.item(),
            'critic_loss': critic_loss.item(),
            'entropy_loss': entropy_loss.item(),
            'total_loss': loss.item()
        }
    
    def train(self, max_episodes=10000, update_interval=2000, eval_interval=500, test_mode=False):
        """
        PPO 학습 루프
        
        Args:
            max_episodes: 최대 에피소드 수
            update_interval: 업데이트 주기 (타임스텝)
            eval_interval: 평가 주기 (에피소드)
            test_mode: 테스트 모드 (짧은 학습)
        """
        if test_mode:
            max_episodes = min(max_episodes, 100)
            print(">>> Test Mode: Training only 100 episodes")
        
        print(f">>> Starting PPO Training (Target: Optimal Policy)")
        print(f"    State Dim: {self.env.state_dim}")
        print(f"    Max Episodes: {max_episodes}")
        print(f"    Device: {self.device}")
        print(f"    Save Dir: {self.save_dir}")
        print("-" * 60)
        
        # 메모리 버퍼
        memory = {
            'states': [],
            'actions': [],
            'logprobs': [],
            'rewards': [],
            'dones': [],
        }
        
        # 통계
        episode_rewards = deque(maxlen=100)
        episode_lengths = deque(maxlen=100)
        
        timestep = 0
        
        for ep in range(1, max_episodes + 1):
            state = self.env.reset()
            ep_reward = 0
            ep_length = 0
            
            while True:
                timestep += 1
                ep_length += 1
                
                # 행동 선택
                action, log_prob = self.policy_old.act(state)
                
                # 환경 진행
                next_state, reward, done, info = self.env.step(action)
                
                # 메모리 저장
                memory['states'].append(torch.from_numpy(state).float())
                memory['actions'].append(torch.tensor(action))
                memory['logprobs'].append(log_prob)
                memory['rewards'].append(reward)
                memory['dones'].append(float(done))
                
                state = next_state
                ep_reward += reward
                
                # 업데이트
                if timestep % update_interval == 0:
                    losses = self.update(memory)
                    
                    # TensorBoard logging
                    self.writer.add_scalar('Loss/Actor', losses['actor_loss'], timestep)
                    self.writer.add_scalar('Loss/Critic', losses['critic_loss'], timestep)
                    self.writer.add_scalar('Loss/Entropy', losses['entropy_loss'], timestep)
                    self.writer.add_scalar('Loss/Total', losses['total_loss'], timestep)
                    
                    # 메모리 초기화
                    memory = {
                        'states': [],
                        'actions': [],
                        'logprobs': [],
                        'rewards': [],
                        'dones': [],
                    }
                
                if done:
                    break
            
            # 에피소드 통계
            episode_rewards.append(ep_reward)
            episode_lengths.append(ep_length)
            
            # Learning rate & entropy coefficient update
            current_lr = self.update_learning_rate(ep, max_episodes)
            current_entropy = self.update_entropy_coef(ep, max_episodes)
            
            # TensorBoard logging
            self.writer.add_scalar('Episode/Reward', ep_reward, ep)
            self.writer.add_scalar('Episode/Length', ep_length, ep)
            self.writer.add_scalar('Episode/Screenings', info.get('total_screenings', 0), ep)
            self.writer.add_scalar('Episode/CancersDetected', info.get('cancers_detected', 0), ep)
            self.writer.add_scalar('Episode/CancersPrevented', info.get('cancers_prevented', 0), ep)
            self.writer.add_scalar('Hyperparams/LearningRate', current_lr, ep)
            self.writer.add_scalar('Hyperparams/EntropyCoef', current_entropy, ep)
            
            # 평가 및 체크포인트
            if ep % eval_interval == 0:
                avg_reward = np.mean(episode_rewards)
                avg_length = np.mean(episode_lengths)
                
                print(f"[Episode {ep}/{max_episodes}]")
                print(f"  Avg Reward (last 100): {avg_reward:.2f}")
                print(f"  Avg Length: {avg_length:.1f}")
                print(f"  LR: {current_lr:.6f}, Entropy Coef: {current_entropy:.4f}")
                print(f"  Screenings: {info.get('total_screenings', 0)}, "
                      f"Detected: {info.get('cancers_detected', 0)}, "
                      f"Prevented: {info.get('cancers_prevented', 0)}")
                
                # Best model 저장
                if avg_reward > self.best_reward:
                    self.best_reward = avg_reward
                    save_path = os.path.join(self.save_dir, 'ppo_optimal_best.pth')
                    torch.save({
                        'episode': ep,
                        'model_state_dict': self.policy.state_dict(),
                        'optimizer_state_dict': self.optimizer.state_dict(),
                        'best_reward': self.best_reward,
                    }, save_path)
                    print(f"  ✓ Best model saved! (Reward: {avg_reward:.2f})")
                
                print("-" * 60)
        
        print("\n>>> PPO Training Complete!")
        print(f"    Best Average Reward: {self.best_reward:.2f}")
        
        # Final model 저장
        final_path = os.path.join(self.save_dir, 'ppo_optimal_final.pth')
        torch.save({
            'episode': max_episodes,
            'model_state_dict': self.policy.state_dict(),
            'optimizer_state_dict': self.optimizer.state_dict(),
            'final_reward': np.mean(episode_rewards),
        }, final_path)
        print(f"    Final model saved to: {final_path}")
        
        self.writer.close()
    
    def print_sample_decisions(self):
        """샘플 상황에서의 의사결정 출력"""
        print("\n=== PPO Sample Decisions ===")
        
        self.policy_old.eval()
        
        # 50세 건강한 남성
        s1 = np.zeros(16, dtype=np.float32)
        s1[0] = 0.5  # Age 50
        s1[1] = 1.0  # History 10 (no recent screening)
        s1[2] = 0.0  # Male
        with torch.no_grad():
            act1, _ = self.policy_old.act(s1)
        print(f" -> 50세 건강한 남성: {'검사' if act1 == 1 else '대기'}")
        
        # 60세, 진행성 용종 보유
        s2 = s1.copy()
        s2[0] = 0.6  # Age 60
        s2[3 + 5] = 2.0  # Zone 5 = Advanced Polyp
        with torch.no_grad():
            act2, _ = self.policy_old.act(s2)
        print(f" -> 60세 진행성 용종 보유: {'검사' if act2 == 1 else '대기'}")
        
        # 70세, 암 의심
        s3 = s1.copy()
        s3[0] = 0.7  # Age 70
        s3[3 + 8] = 3.0  # Zone 8 = Undetected Cancer
        with torch.no_grad():
            act3, _ = self.policy_old.act(s3)
        print(f" -> 70세 암 의심: {'검사' if act3 == 1 else '대기'}")
        
        # 45세, 최근 검진 받음
        s4 = s1.copy()
        s4[0] = 0.45  # Age 45
        s4[1] = 0.1  # History 1 (recent screening)
        with torch.no_grad():
            act4, _ = self.policy_old.act(s4)
        print(f" -> 45세 최근 검진 받음: {'검사' if act4 == 1 else '대기'}")


# --------------------------------------------------------
# [4] Main 실행
# --------------------------------------------------------
def main():
    parser = argparse.ArgumentParser(description='PPO Optimal Training for Colonoscopy Screening')
    parser.add_argument('--settings', type=str, default='settings.ini', help='Settings file path')
    parser.add_argument('--max_episodes', type=int, default=10000, help='Maximum training episodes')
    parser.add_argument('--update_interval', type=int, default=2000, help='Policy update interval')
    parser.add_argument('--eval_interval', type=int, default=500, help='Evaluation interval')
    parser.add_argument('--save_dir', type=str, default='models', help='Model save directory')
    parser.add_argument('--log_dir', type=str, default='logs', help='TensorBoard log directory')
    parser.add_argument('--device', type=str, default=None, help='Device (cuda/cpu)')
    parser.add_argument('--test_mode', action='store_true', help='Test mode (short training)')
    
    args = parser.parse_args()
    
    # Trainer 생성
    trainer = PPOTrainer(
        settings_file=args.settings,
        save_dir=args.save_dir,
        log_dir=args.log_dir,
        device=args.device
    )
    
    # 학습 시작
    trainer.train(
        max_episodes=args.max_episodes,
        update_interval=args.update_interval,
        eval_interval=args.eval_interval,
        test_mode=args.test_mode
    )
    
    # 샘플 의사결정 출력
    trainer.print_sample_decisions()


if __name__ == '__main__':
    main()
