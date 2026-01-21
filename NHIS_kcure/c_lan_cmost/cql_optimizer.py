import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
import random
import os
from collections import deque
from torch.utils.tensorboard import SummaryWriter

# [1] 실제 시뮬레이터 모듈 Import
from parameters import SimulationParameters
from output import Output
from entities import Person

# ==============================================================================
# [Helper] PPO Actor 모델 구조 (불러오기용)
# PPOOptimizer에서 쓰던 Actor 네트워크 구조와 같아야 합니다.
# ==============================================================================
class PPOActor(nn.Module):
    def __init__(self, state_dim, action_dim):
        super(PPOActor, self).__init__()
        self.fc = nn.Sequential(
            nn.Linear(state_dim, 256),
            nn.ReLU(),
            nn.Linear(256, 256),
            nn.ReLU(),
            nn.Linear(256, action_dim),
            nn.Softmax(dim=-1) # 확률 반환
        )

    def forward(self, x):
        return self.fc(x)

# ==============================================================================
# [2] 데이터셋 수집기 (Data Collector) - PPO 모델 연동 기능 추가
# ==============================================================================
class OfflineDataCollector:
    def __init__(self, settings_file):
        self.params = SimulationParameters(settings_file)
        self.min_age = self.params.opt_min_age
        self.max_age = self.params.opt_max_age
        self.max_history = 10
        self.state_dim = 16
        
        # PPO 모델 로드 준비
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        self.behavior_policy = None
        self.load_behavior_policy() # 파일이 있으면 로드 시도

# [기존의 load_behavior_policy 함수를 지우고 이걸로 덮어씌우세요]
    def load_behavior_policy(self, path="ppo_actor_medium.pth"):
        """학습된 PPO 모델(Actor)을 불러옵니다."""
        if os.path.exists(path):
            try:
                # [수정] PPOActor 클래스 대신 nn.Sequential을 직접 사용
                # 이유: drl_optimizer에서 저장할 때 nn.Sequential 객체를 저장했기 때문
                self.behavior_policy = nn.Sequential(
                    nn.Linear(self.state_dim, 256),
                    nn.ReLU(),
                    nn.Linear(256, 256),
                    nn.ReLU(),
                    nn.Linear(256, 2), # Action Dim
                    nn.Softmax(dim=-1)
                ).to(self.device)
                
                self.behavior_policy.load_state_dict(torch.load(path, map_location=self.device))
                self.behavior_policy.eval()
                print(f">>> [System] Loaded Behavior Policy from '{path}' (Medium-Expert Mode)")
            except Exception as e:
                print(f">>> [Warning] Failed to load PPO model: {e}")
                print("    (Check if state_dim matches or file is corrupted)")
                self.behavior_policy = None
        else:
            print(f">>> [System] No '{path}' found. Using Random Policy.")
            self.behavior_policy = None

    def _get_state_vector(self, person, age, history):
        # (기존과 동일)
        age_norm = age / 100.0
        hist_norm = history / 10.0
        gender = float(person.gender)
        zones = np.zeros(13)
        
        adv_threshold = getattr(self.params, 'adv_polyp_transition', 5)
        for p in person.polyps:
            if p.age_developed <= age < p.age_end:
                loc = min(p.location, 12)
                if p.stage >= adv_threshold: zones[loc] = 2 
                else: zones[loc] = 1

        for c in person.cancers:
            if c.age_developed <= age:
                loc = min(c.location, 12)
                if c.detected: zones[loc] = 4
                else: zones[loc] = 3
        
        return np.array([age_norm, hist_norm, gender] + list(zones), dtype=np.float32)

    def select_action(self, state_vec):
        """
        PPO 모델이 있으면 그것을 쓰고, 없으면 랜덤을 씁니다.
        """
        # 1. PPO 모델이 있는 경우 (Medium Policy)
        if self.behavior_policy is not None:
            state_t = torch.tensor(state_vec, dtype=torch.float32).unsqueeze(0).to(self.device)
            with torch.no_grad():
                probs = self.behavior_policy(state_t) # [0.8, 0.2]
                
                # 완전히 결정적(Argmax)으로 하지 않고 확률 분포대로 뽑음
                # 이유: 다양한 데이터를 모으기 위해 (Exploration 유지)
                dist = torch.distributions.Categorical(probs)
                action = dist.sample().item()
                return action
        
        # 2. 모델이 없는 경우 (Random Policy)
        else:
            # 50% 확률 랜덤 (기존 방식)
            return 1 if random.random() < 0.5 else 0

    def collect_data(self, n_samples=50000):
        print(f">>> [DataCollection] Collecting {n_samples} transitions...")
        if self.behavior_policy:
            print("    -> Strategy: Using Pre-trained PPO Model (Smart-ish)")
        else:
            print("    -> Strategy: Using Random 50:50 (Reckless)")

        buffer = []
        rng = np.random.default_rng()
        
        while len(buffer) < n_samples:
            person = Person(self.params, rng)
            if person.death_age <= self.min_age: continue
            
            curr_age = self.min_age
            hist = self.max_history
            output = Output(self.params)
            
            while curr_age < min(person.death_age, self.max_age):
                state = self._get_state_vector(person, curr_age, hist)
                
                # ★ 수정된 행동 선택 (PPO or Random)
                action = self.select_action(state)
                
                # --- Step 진행 (기존과 동일) ---
                reward = 0
                next_hist = min(hist + 1, self.max_history)
                done = False
                
                if action == 1: # Screen
                    had_adv_polyp = False
                    had_cancer = False
                    adv_threshold = getattr(self.params, 'adv_polyp_transition', 5)

                    for p in person.polyps:
                        if p.age_developed <= curr_age < p.age_end and p.stage >= adv_threshold:
                            had_adv_polyp = True; break
                    for c in person.cancers:
                        if c.age_developed <= curr_age and not c.detected:
                            had_cancer = True; break

                    prev_cost = output.total_discounted_cost
                    person._perform_colonoscopy(curr_age, output, is_screening=True)
                    step_cost = output.total_discounted_cost - prev_cost
                    
                    reward -= (step_cost * 0.0001 + 0.05)
                    if had_cancer: reward += 50.0
                    elif had_adv_polyp: reward += 10.0
                    next_hist = 0

                else: # Wait
                    pass

                if curr_age + 1 >= person.death_age:
                    reward -= 100.0
                    done = True
                else:
                    reward += 0.1
                
                next_state = self._get_state_vector(person, curr_age + 1, next_hist)
                buffer.append((state, action, reward, next_state, done))
                
                curr_age += 1
                hist = next_hist
                if done: break
                
        print(f" -> Collection Complete. Buffer: {len(buffer)}")
        return buffer

# ==============================================================================
# [3] Q-Network (CQL 학습용)
# ==============================================================================
class QNetwork(nn.Module):
    def __init__(self, state_dim, action_dim):
        super(QNetwork, self).__init__()
        self.fc = nn.Sequential(
            nn.Linear(state_dim, 256),
            nn.ReLU(),
            nn.Linear(256, 256),
            nn.ReLU(),
            nn.Linear(256, action_dim)
        )

    def forward(self, x):
        return self.fc(x)

# ==============================================================================
# [4] CQL Optimizer
# ==============================================================================
class CQLOptimizer:
    def __init__(self, settings_file):
        self.collector = OfflineDataCollector(settings_file)
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        
        self.state_dim = 16 
        self.action_dim = 2
        
        log_dir = 'runs/cql_experiment'
        if not os.path.exists(log_dir): os.makedirs(log_dir)
        self.writer = SummaryWriter(log_dir)
        
        self.q_net = QNetwork(self.state_dim, self.action_dim).to(self.device)
        self.target_q_net = QNetwork(self.state_dim, self.action_dim).to(self.device)
        self.target_q_net.load_state_dict(self.q_net.state_dict())
        
        self.optimizer = optim.Adam(self.q_net.parameters(), lr=1e-4)
        self.gamma = 0.99
        self.batch_size = 2048
        self.cql_alpha = 1.0 
        
    def train(self, iterations=10000):
        # 데이터 수집 (PPO 모델이 있으면 그것을 사용)
        dataset = self.collector.collect_data(n_samples=100000)
        
        print(f">>> Starting CQL Training on {self.device}...")
        self.q_net.train()
        
        for it in range(iterations):
            batch = random.sample(dataset, self.batch_size)
            states, actions, rewards, next_states, dones = zip(*batch)
            
            states = torch.tensor(np.array(states), dtype=torch.float32).to(self.device)
            actions = torch.tensor(actions, dtype=torch.int64).unsqueeze(1).to(self.device)
            rewards = torch.tensor(rewards, dtype=torch.float32).unsqueeze(1).to(self.device)
            next_states = torch.tensor(np.array(next_states), dtype=torch.float32).to(self.device)
            dones = torch.tensor(dones, dtype=torch.float32).unsqueeze(1).to(self.device)

            curr_q = self.q_net(states).gather(1, actions)
            
            with torch.no_grad():
                next_q = self.target_q_net(next_states).max(1)[0].unsqueeze(1)
                target_q = rewards + self.gamma * next_q * (1 - dones)
            
            bellman_loss = nn.MSELoss()(curr_q, target_q)
            
            # CQL Loss
            q_all = self.q_net(states)
            logsumexp_q = torch.logsumexp(q_all, dim=1, keepdim=True)
            cql_loss = (logsumexp_q - curr_q).mean()

            total_loss = bellman_loss + self.cql_alpha * cql_loss
            
            self.optimizer.zero_grad()
            total_loss.backward()
            self.optimizer.step()
            
            if it % 100 == 0:
                self.update_target()
                if it % 1000 == 0:
                    print(f" [Iter {it}] Loss: {total_loss.item():.4f}")
                    self.writer.add_scalar('Loss/Total', total_loss.item(), it)

        print(">>> CQL Training Complete.")
        self.writer.close()

    def update_target(self, tau=0.005):
        for param, target_param in zip(self.q_net.parameters(), self.target_q_net.parameters()):
            target_param.data.copy_(tau * param.data + (1 - tau) * target_param.data)

    def print_sample_decisions(self):
        print("\n" + "="*60)
        print("      CQL Learned Policy Evaluation")
        print("="*60)
        self.q_net.eval()
        
        def predict_and_report(case_name, age=50, hist=10, gender=1.0, zones=None):
            s = np.zeros(16, dtype=np.float32)
            s[0] = age / 100.0; s[1] = hist / 10.0; s[2] = gender
            if zones:
                for idx, val in zones.items(): s[3+idx] = val 
            
            s_tensor = torch.tensor(s).unsqueeze(0).to(self.device)
            with torch.no_grad():
                q = self.q_net(s_tensor)
                act = q.argmax().item()
            
            decision = "★ SCREEN" if act == 1 else "  Wait"
            print(f"[{case_name}] Age:{age} -> {decision} (Q_Wait={q[0,0]:.2f}, Q_Screen={q[0,1]:.2f})")

        predict_and_report("Normal", age=50, hist=10)
        predict_and_report("Adv Polyp", age=50, hist=10, zones={5: 2})
        predict_and_report("Cancer", age=60, hist=10, zones={10: 3})