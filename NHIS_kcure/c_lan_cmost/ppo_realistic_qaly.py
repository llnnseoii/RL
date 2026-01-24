"""
Realistic Health Economics-based Reward Function for PPO

Based on actual Korean cost data and QALY values:
R = -C_test - C_followup + QALY_gain - mortality_cost

Data from evaluation.ini:
- Colonoscopy: $917
- Colonoscopy with Polyp: $1,205
- Cancer treatment (Initial I-IV): $45K-$95K
- QALY value: $50,000 per year (Korean standard)
"""

import numpy as np
from parameters import SimulationParameters
from output import Output
from entities import Person
import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
import pickle


# ==================== UK EQ-5D-5L QALY Calculator ====================
class QALYCalculator:
    """UK EQ-5D-5L Population Norms (Gender-specific)"""
    
    def __init__(self):
        # UK EQ-5D-5L Population Norms (Szende et al., 2014)
        # 17 age groups with gender-specific scores
        
        # Age group midpoints (17 groups)
        self.age_points = [
            16.5,  # 16-17
            18.5,  # 18-19
            22.0,  # 20-24
            27.0,  # 25-29
            32.0,  # 30-34
            37.0,  # 35-39
            42.0,  # 40-44
            47.0,  # 45-49
            52.0,  # 50-54
            57.0,  # 55-59
            62.0,  # 60-64
            67.0,  # 65-69
            72.0,  # 70-74
            77.0,  # 75-79
            82.0,  # 80-84
            87.0,  # 85-89
            90.0   # 90+
        ]
        
        # Female EQ-5D-5L scores (17 values)
        self.female_scores = [
            0.878,  # 16-17
            0.856,  # 18-19
            0.859,  # 20-24
            0.869,  # 25-29
            0.869,  # 30-34
            0.854,  # 35-39
            0.846,  # 40-44
            0.806,  # 45-49
            0.798,  # 50-54
            0.791,  # 55-59
            0.776,  # 60-64
            0.775,  # 65-69
            0.784,  # 70-74
            0.730,  # 75-79
            0.710,  # 80-84
            0.666,  # 85-89
            0.666   # 90+
        ]
        
        # Male EQ-5D-5L scores (17 values)
        self.male_scores = [
            0.918,  # 16-17
            0.930,  # 18-19
            0.894,  # 20-24
            0.895,  # 25-29
            0.915,  # 30-34
            0.863,  # 35-39
            0.872,  # 40-44
            0.822,  # 45-49
            0.836,  # 50-54
            0.809,  # 55-59
            0.803,  # 60-64
            0.797,  # 65-69
            0.801,  # 70-74
            0.788,  # 75-79
            0.767,  # 80-84
            0.727,  # 85-89
            0.656   # 90+
        ]
        
        # QALY monetary value (UK NICE threshold)
        self.qaly_value_per_year = 50000.0  # $50K/QALY
        
        # Cancer stage별 utility decrement (Teckle et al., 2015)
        self.cancer_utility_loss = {
            0: 0.0,      # Healthy
            1: 0.074,    # Stage I
            2: 0.084,    # Stage II
            3: 0.170,    # Stage III
            4: 0.290,    # Stage IV
        }

    
    def get_qaly_weight(self, age, is_female=True):
        """
        연령과 성별에 따른 EQ-5D weight (선형 보간)
        
        Args:
            age: 나이
            is_female: 여성 여부 (True=Female, False=Male)
        
        Returns:
            EQ-5D utility score
        """
        scores = self.female_scores if is_female else self.male_scores
        
        if age <= self.age_points[0]:
            return scores[0]
        elif age >= self.age_points[-1]:
            return scores[-1]
        else:
            # Linear interpolation
            for i in range(len(self.age_points) - 1):
                if self.age_points[i] <= age < self.age_points[i+1]:
                    age_diff = self.age_points[i+1] - self.age_points[i]
                    score_diff = scores[i+1] - scores[i]
                    weight = (age - self.age_points[i]) / age_diff
                    return scores[i] + score_diff * weight
            return scores[-1]
    
    def get_annual_qaly_value(self, age, is_female=True, has_cancer=False, cancer_stage=0):
        """
        1년 생존의 QALY 가치 계산
        
        Returns:
            Dollar value of living one more year
        """
        base_weight = self.get_qaly_weight(age, is_female)
        
        if has_cancer:
            utility_loss = self.cancer_utility_loss.get(cancer_stage, 0.0)
            adjusted_weight = max(0.0, base_weight - utility_loss)
        else:
            adjusted_weight = base_weight
        
        return adjusted_weight * self.qaly_value_per_year



# ==================== Realistic Reward Environment ====================
class RealisticScreeningEnv:
    """보건경제학 기반 Reward 구조"""
    
    def __init__(self, params, variant='balanced'):
        self.params = params
        self.variant = variant
        self.qaly_calc = QALYCalculator()
        
        self.min_age = params.opt_min_age
        self.max_age = params.opt_max_age
        self.state_dim = 16
        self.max_history = 10
        
        # Discount rate (연 3%)
        self.annual_discount = 0.97
        
        # Variant별 조정 (cost scaling만)
        if variant == 'conservative':
            self.cost_weight = 1.5     # 비용 1.5배 민감
            self.qaly_weight = 1.0
        elif variant == 'balanced':
            self.cost_weight = 1.0
            self.qaly_weight = 1.0
        else:  # aggressive
            self.cost_weight = 0.7     # 비용 덜 민감
            self.qaly_weight = 1.2     # QALY 더 중시
        
        print(f"  Reward: Realistic QALY-based (variant={variant})")
        print(f"    - Cost weight: {self.cost_weight}, QALY weight: {self.qaly_weight}")
        
        self.reset()
    
    def reset(self):
        self.rng = np.random.default_rng()
        self.person = Person(self.params, self.rng)
        self.person.simulate()
        
        self.output = Output(self.params)
        self.current_age = self.min_age
        self.years_since_last = self.max_history
        self.cumulative_cost = 0.0
        
        return self._get_state()
    
    def _get_state(self):
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
        """
        Reward 계산:
        R = -C_test - C_followup + QALY_gain - mortality_cost
        """
        
        # === 1. Cost 계산 ===
        step_cost = 0.0
        
        if action == 1:  # Screen
            prev_cost = self.output.total_discounted_cost
            
            # 검진 수행
            self.person._perform_colonoscopy(self.current_age, self.output, is_screening=True)
            
            # 검진 비용 (실제 값)
            step_cost = self.output.total_discounted_cost - prev_cost
            self.cumulative_cost += step_cost
            
            self.years_since_last = 0
        else:
            self.years_since_last = min(self.years_since_last + 1, self.max_history)
        
        # === 2. QALY Gain 계산 ===
        # 현재 건강 상태 확인
        has_cancer = False
        cancer_stage = 0
        
        for c in self.person.cancers:
            if c.age_developed <= self.current_age:
                has_cancer = True
                if c.detected:
                    cancer_stage = c.stage
                else:
                    cancer_stage = c.stage  # 미발견 암도 QOL 영향
                break
        
        # ★ 성별 정보 사용 (person.gender: 0=Male, 1=Female)
        is_female = (self.person.gender == 1)
        
        # 1년 생존 시 QALY 가치
        annual_qaly_value = self.qaly_calc.get_annual_qaly_value(
            self.current_age,
            is_female=is_female,  # ← 성별 반영!
            has_cancer=has_cancer,
            cancer_stage=cancer_stage
        )
        
        # === 3. Mortality Cost ===
        self.current_age += 1
        mortality_cost = 0.0
        done = False
        
        if self.current_age >= self.person.death_age:
            # 조기 사망 시 잃은 기대여명의 QALY 가치
            # 한국 기대여명 (간소화)
            if is_female:
                life_exp_table = {20: 86.5, 40: 86.7, 60: 87.8, 80: 91.8}
            else:
                life_exp_table = {20: 80.6, 40: 80.9, 60: 82.5, 80: 88.2}
            
            remaining_life_exp = 85 if is_female else 80  # 기본값
            for key_age in sorted(life_exp_table.keys()):
                if self.current_age <= key_age:
                    remaining_life_exp = life_exp_table[key_age]
                    break
            
            years_lost = max(0, remaining_life_exp - self.current_age)
            
            # 할인된 미래 QALY 손실
            mortality_cost = 0.0
            discount_factor = 1.0
            for year in range(int(years_lost)):
                future_age = self.current_age + year
                future_qaly = self.qaly_calc.get_annual_qaly_value(
                    future_age,
                    is_female=is_female  # ← 성별 반영!
                )
                mortality_cost += future_qaly * discount_factor
                discount_factor *= self.annual_discount
            
            done = True
        elif self.current_age >= self.max_age:
            done = True
        
        # === 4. Final Reward 계산 ===
        # R = -Cost + QALY_gain - Mortality_cost
        # 스케일 조정: cost는 달러 단위, QALY도 달러로 환산됨
        reward = (
            -step_cost * self.cost_weight * 0.01 +           # Cost (1/100 스케일)
            annual_qaly_value * self.qaly_weight * 0.01 -    # QALY gain
            mortality_cost * 0.01                             # Mortality cost
        )
        
        return self._get_state(), reward, done


# ==================== PPO Networks (동일) ====================
class ActorCritic(nn.Module):
    def __init__(self, state_dim, action_dim):
        super(ActorCritic, self).__init__()
        
        self.actor = nn.Sequential(
            nn.Linear(state_dim, 256),
            nn.ReLU(),
            nn.Linear(256, 256),
            nn.ReLU(),
            nn.Linear(256, action_dim),
            nn.Softmax(dim=-1)
        )
        
        self.critic = nn.Sequential(
            nn.Linear(state_dim, 256),
            nn.ReLU(),
            nn.Linear(256, 256),
            nn.ReLU(),
            nn.Linear(256, 1)
        )
    
    def act(self, state, epsilon=0.0):
        if np.random.random() < epsilon:
            return np.random.choice([0, 1]), torch.tensor(0.0)
        
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


# ==================== Realistic PPO Trainer ====================
class RealisticPPOTrainer:
    def __init__(self, params, variant='balanced'):
        self.params = params
        self.variant = variant
        self.env = RealisticScreeningEnv(params, variant)
        
        self.state_dim = 16
        self.action_dim = 2
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        
        self.policy = ActorCritic(self.state_dim, self.action_dim).to(self.device)
        self.policy_old = ActorCritic(self.state_dim, self.action_dim).to(self.device)
        self.policy_old.load_state_dict(self.policy.state_dict())
        
        self.optimizer = optim.Adam(self.policy.parameters(), lr=3e-4)
        
        self.gamma = 0.99
        self.K_epochs = 4
        self.eps_clip = 0.2
        self.update_timestep = 2000
    
    def train(self, max_episodes=1000):
        print(f"\n🎓 Training {self.variant.upper()} PPO (Realistic QALY-based) for {max_episodes} episodes...")
        
        timestep = 0
        memory_states, memory_actions, memory_logprobs = [], [], []
        memory_rewards, memory_is_terminals = [], []
        
        for ep in range(1, max_episodes + 1):
            state = self.env.reset()
            ep_reward = 0
            
            # Exploration (초반에만)
            epsilon = max(0.0, 0.2 - (ep / max_episodes) * 0.2)
            
            while True:
                timestep += 1
                
                action, log_prob = self.policy_old.act(state, epsilon=epsilon)
                next_state, reward, done = self.env.step(action)
                
                memory_states.append(torch.from_numpy(state).float())
                memory_actions.append(torch.tensor(action))
                memory_logprobs.append(log_prob)
                memory_rewards.append(reward)
                memory_is_terminals.append(done)
                
                state = next_state
                ep_reward += reward
                
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
        print(f"\n📊 Collecting {n_episodes} episodes with {self.variant.upper()} policy...")
        
        episodes = []
        
        for ep_idx in range(n_episodes):
            episode_data = self._run_episode()
            episodes.append(episode_data)
            
            if (ep_idx + 1) % 100 == 0:
                avg_reward = np.mean([e['total_reward'] for e in episodes[-100:]])
                avg_screen = np.mean([e['num_screenings'] for e in episodes[-100:]])
                avg_cost = np.mean([e['total_cost'] for e in episodes[-100:]])
                print(f"  [{ep_idx+1}/{n_episodes}] Avg Reward: {avg_reward:.2f}, Screens: {avg_screen:.1f}, Cost: ${avg_cost:,.0f}")
        
        print(f"✅ {len(episodes)} episodes collected!")
        return episodes
    
    def _run_episode(self):
        state = self.env.reset()
        
        transitions = []
        total_reward = 0.0
        num_screenings = 0
        cancer_detected = False
        
        while True:
            action, _ = self.policy_old.act(state, epsilon=0.0)
            next_state, reward, done = self.env.step(action)
            
            if action == 1:
                num_screenings += 1
                if self.env.output.screen_detections > 0:
                    cancer_detected = True
            
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


# ==================== Main ====================
def train_realistic_ppo(params, episodes_per_variant=1000, training_episodes=1000):
    """현실적인 QALY 기반 Reward로 PPO 학습"""
    
    print("\n" + "="*70)
    print("  REALISTIC QALY-BASED PPO TRAINING")
    print("="*70)
    print("  Reward Structure:")
    print("    R = -C_test - C_followup + QALY_gain - mortality_cost")
    print("  ")
    print("  Based on:")
    print("    - Korean colonoscopy costs: $917-$1,205")
    print("    - Cancer treatment costs: $45K-$95K")
    print("    - Korean age-specific QALY weights (EQ-5D)")
    print("    - Life expectancy (2023 Korean statistics)")
    print("    - QALY value: $50,000 per year")
    print("="*70)
    
    all_episodes = []
    
    for variant in ['conservative', 'balanced', 'aggressive']:
        print(f"\n{'='*60}")
        print(f"  Variant: {variant.upper()}")
        print(f"{'='*60}")
        
        trainer = RealisticPPOTrainer(params, variant=variant)
        trainer.train(max_episodes=training_episodes)
        
        episodes = trainer.collect_episodes(n_episodes=episodes_per_variant)
        all_episodes.extend(episodes)
        
        torch.save(trainer.policy.state_dict(), f'ppo_{variant}_realistic.pth')
        print(f"💾 Model saved: ppo_{variant}_realistic.pth")
    
    # 저장
    with open('diverse_ppo_data_realistic.pkl', 'wb') as f:
        pickle.dump(all_episodes, f)
    
    print(f"\n{'='*60}")
    print(f"✅ 전체 {len(all_episodes)} episodes 저장: diverse_ppo_data_realistic.pkl")
    print(f"{'='*60}")
    
    # 통계
    total_transitions = sum(len(ep['transitions']) for ep in all_episodes)
    screen_count = sum(1 for ep in all_episodes for t in ep['transitions'] if t['action'] == 1)
    
    print(f"\n📊 Data Statistics:")
    print(f"  Total transitions: {total_transitions}")
    print(f"  Screen actions: {screen_count} ({screen_count/total_transitions*100:.1f}%)")
    print(f"  Wait actions: {total_transitions-screen_count} ({(total_transitions-screen_count)/total_transitions*100:.1f}%)")
    
    print(f"\n💰 Cost Statistics:")
    avg_cost = np.mean([ep['total_cost'] for ep in all_episodes])
    avg_screens = np.mean([ep['num_screenings'] for ep in all_episodes])
    print(f"  Average cost per person: ${avg_cost:,.0f}")
    print(f"  Average screenings per person: {avg_screens:.2f}")
    
    return all_episodes


if __name__ == "__main__":
    params = SimulationParameters('settings.ini')
    
    train_realistic_ppo(
        params,
        episodes_per_variant=1000,
        training_episodes=1000
    )
