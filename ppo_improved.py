"""
Improved PPO Training with Balanced Reward Structure

주요 개선사항:
1. 검진 penalty 감소
2. 암/용종 발견 시 큰 보상
3. Exploration 강화 (epsilon-greedy)
"""

import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
import pickle
from typing import List, Dict

from parameters import SimulationParameters
from output import Output
from entities import Person


# ==================== PPO Network ====================
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
        """Epsilon-greedy exploration 추가"""
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


# ==================== Improved Environment ====================
class ImprovedScreeningEnv:
    """개선된 Reward 구조"""
    
    def __init__(self, params, variant='balanced'):
        self.params = params
        self.variant = variant
        self.min_age = params.opt_min_age
        self.max_age = params.opt_max_age
        self.state_dim = 16
        self.max_history = 10
        
        # ★ 개선된 Reward 파라미터
        if variant == 'conservative':
            self.cost_penalty = 0.03      # 감소 (0.10 → 0.03)
            self.survival_reward = 0.05
            self.cancer_bonus = 15.0      # 신규 추가
            self.polyp_bonus = 5.0        # 신규 추가
        elif variant == 'balanced':
            self.cost_penalty = 0.02
            self.survival_reward = 0.05
            self.cancer_bonus = 20.0
            self.polyp_bonus = 8.0
        else:  # aggressive
            self.cost_penalty = 0.01
            self.survival_reward = 0.05
            self.cancer_bonus = 30.0
            self.polyp_bonus = 12.0
        
        print(f"  Reward: cancer_bonus={self.cancer_bonus}, polyp_bonus={self.polyp_bonus}, cost_penalty={self.cost_penalty}")
        
        self.reset()
    
    def reset(self):
        self.rng = np.random.default_rng()
        self.person = Person(self.params, self.rng)
        self.person.simulate()
        
        self.output = Output(self.params)
        self.current_age = self.min_age
        self.years_since_last = self.max_history
        
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
        reward = 0.0
        
        if action == 1:  # Screen
            # 발견 여부 확인
            had_cancer = False
            had_polyp = False
            
            adv_threshold = getattr(self.params, 'adv_polyp_transition', 5)
            for p in self.person.polyps:
                if p.age_developed <= self.current_age < p.age_end:
                    had_polyp = True
                    break
            
            for c in self.person.cancers:
                if c.age_developed <= self.current_age and not c.detected:
                    had_cancer = True
                    break
            
            # 검진 수행
            prev_cost = self.output.total_discounted_cost
            self.person._perform_colonoscopy(self.current_age, self.output, is_screening=True)
            step_cost = self.output.total_discounted_cost - prev_cost
            
            # ★ Reward 계산
            reward -= (step_cost * 0.0001 + self.cost_penalty)
            
            # ★ 발견 보너스 (핵심!)
            if had_cancer:
                reward += self.cancer_bonus
            elif had_polyp:
                reward += self.polyp_bonus
            
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


# ==================== PPO Trainer (with Exploration) ====================
class ImprovedPPOTrainer:
    def __init__(self, params, variant='balanced'):
        self.params = params
        self.variant = variant
        self.env = ImprovedScreeningEnv(params, variant)
        
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
        print(f"\n🎓 Training {self.variant.upper()} PPO (Improved) for {max_episodes} episodes...")
        
        timestep = 0
        memory_states, memory_actions, memory_logprobs = [], [], []
        memory_rewards, memory_is_terminals = [], []
        
        for ep in range(1, max_episodes + 1):
            state = self.env.reset()
            ep_reward = 0
            
            # ★ Exploration: 초반에 epsilon-greedy
            epsilon = max(0.0, 0.3 - (ep / max_episodes) * 0.3)  # 0.3 → 0
            
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
                print(f"  Episode {ep}/{max_episodes}: Reward = {ep_reward:.2f}, Epsilon = {epsilon:.3f}")
        
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
        print(f"\n📊 Collecting {n_episodes} episodes with IMPROVED {self.variant.upper()} policy...")
        
        episodes = []
        
        for ep_idx in range(n_episodes):
            episode_data = self._run_episode()
            episodes.append(episode_data)
            
            if (ep_idx + 1) % 100 == 0:
                avg_reward = np.mean([e['total_reward'] for e in episodes[-100:]])
                avg_screen = np.mean([e['num_screenings'] for e in episodes[-100:]])
                print(f"  [{ep_idx+1}/{n_episodes}] Avg Reward: {avg_reward:.2f}, Avg Screenings: {avg_screen:.2f}")
        
        print(f"✅ {len(episodes)} episodes collected!")
        return episodes
    
    def _run_episode(self):
        state = self.env.reset()
        
        transitions = []
        total_reward = 0.0
        num_screenings = 0
        cancer_detected = False
        
        while True:
            action, _ = self.policy_old.act(state, epsilon=0.0)  # 수집 시엔 greedy
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
def retrain_ppo_improved(params, episodes_per_variant=1000, training_episodes=1000):
    """개선된 Reward로 PPO 재학습"""
    
    print("\n" + "="*70)
    print("  IMPROVED PPO TRAINING - Balanced Reward Structure")
    print("="*70)
    print("  Changes:")
    print("    - Reduced screening penalty: 0.10 → 0.03 (conservative)")
    print("    - Added cancer detection bonus: +15~30")
    print("    - Added polyp detection bonus: +5~12")
    print("    - Epsilon-greedy exploration: 0.3 → 0 (decay)")
    print("="*70)
    
    all_episodes = []
    
    for variant in ['conservative', 'balanced', 'aggressive']:
        print(f"\n{'='*60}")
        print(f"  Variant: {variant.upper()}")
        print(f"{'='*60}")
        
        trainer = ImprovedPPOTrainer(params, variant=variant)
        trainer.train(max_episodes=training_episodes)
        
        episodes = trainer.collect_episodes(n_episodes=episodes_per_variant)
        all_episodes.extend(episodes)
        
        torch.save(trainer.policy.state_dict(), f'ppo_{variant}_improved.pth')
        print(f"💾 Model saved: ppo_{variant}_improved.pth")
    
    # 저장
    with open('diverse_ppo_data_improved.pkl', 'wb') as f:
        pickle.dump(all_episodes, f)
    
    print(f"\n{'='*60}")
    print(f"✅ 전체 {len(all_episodes)} episodes 저장: diverse_ppo_data_improved.pkl")
    print(f"{'='*60}")
    
    # 통계 출력
    total_transitions = sum(len(ep['transitions']) for ep in all_episodes)
    screen_count = sum(1 for ep in all_episodes for t in ep['transitions'] if t['action'] == 1)
    
    print(f"\n📊 Data Statistics:")
    print(f"  Total transitions: {total_transitions}")
    print(f"  Screen actions: {screen_count} ({screen_count/total_transitions*100:.1f}%)")
    print(f"  Wait actions: {total_transitions-screen_count} ({(total_transitions-screen_count)/total_transitions*100:.1f}%)")
    
    return all_episodes


if __name__ == "__main__":
    params = SimulationParameters('settings.ini')
    
    retrain_ppo_improved(
        params,
        episodes_per_variant=1000,
        training_episodes=1000
    )
