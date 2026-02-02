"""
DRL Optimizer with GAE (Generalized Advantage Estimation)
==========================================================
- Uses GPU or CPU cores as many as system allows
- Sparse reward system support
- Reward options: 
    i) CRC incidence, 
    ii) CRC mortality, 
    iii) life years lost to CRC, 
    iv) overall costs, 
    v) status quo
- Implements GAE for stable policy gradient estimation
"""

import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.distributions import Categorical
import multiprocessing
import os
from enum import Enum
from typing import List, Tuple, Optional
from dataclasses import dataclass

# Module imports
from parameters import SimulationParameters
from output import Output
from entities import Person

# ============================================================
# [1] Device Configuration - Force CPU usage for this simulation
# ============================================================
def get_device():
    """Force CPU device (faster for this small network + Python simulation)"""
    device = torch.device("cpu")
    n_cpus = multiprocessing.cpu_count()
    torch.set_num_threads(n_cpus)
    print(f">>> Using CPU with {n_cpus} cores (forced)")
    return device

# ============================================================
# [2] Reward Type Enumeration
# ============================================================
class RewardType(Enum):
    CRC_INCIDENCE = 1       # Minimize CRC incidence
    CRC_MORTALITY = 2       # Minimize CRC mortality
    LIFE_YEARS_LOST = 3     # Minimize life years lost to CRC
    OVERALL_COSTS = 4       # Minimize overall costs
    STATUS_QUO = 5          # Maintain status quo (no screening baseline)

# ============================================================
# [3] Configuration Dataclass
# ============================================================
@dataclass
class GAEConfig:
    """Configuration for GAE-based DRL optimizer"""
    # Reward configuration
    reward_type: RewardType = RewardType.CRC_INCIDENCE
    sparse_reward: bool = True  # If True, reward only at episode end
    
    # GAE parameters
    gamma: float = 0.99         # Discount factor
    gae_lambda: float = 0.95    # GAE lambda for bias-variance tradeoff
    
    # PPO parameters
    eps_clip: float = 0.2       # PPO clipping parameter
    K_epochs: int = 10          # Number of epochs per update
    lr_actor: float = 0.0003    # Actor learning rate
    lr_critic: float = 0.001    # Critic learning rate
    
    # Training parameters
    update_timestep: int = 40000 # Steps before policy update
    max_episodes: int = 400000    # Maximum training episodes
    
    # Entropy bonus coefficient
    entropy_coef: float = 0.01

# ============================================================
# [4] DRL Environment with Configurable Reward
# ============================================================
class ColonoscopyGAEEnv:
    """
    RL Environment for colonoscopy screening optimization
    Supports multiple reward types with sparse reward option
    """
    def __init__(self, settings_file: str, config: GAEConfig):
        self.params = SimulationParameters(settings_file)
        self.config = config
        
        self.min_age = self.params.opt_min_age
        self.max_age = self.params.opt_max_age
        self.max_history = 10
        
        # State dimensions: Age(1) + History(1) + Gender(1) + 13 Zones(13) = 16
        self.state_dim = 16
        self.action_dim = 2  # 0: Wait, 1: Screen
        
        # Baseline statistics for relative rewards
        self.baseline_output = None
        
        # Episode tracking for sparse rewards
        self.episode_events = {
            'cancers': 0,
            'deaths': 0,
            'life_years': 0.0,
            'costs': 0.0,
            'screenings': 0
        }
        
        self.person = None
        self.current_age = 0
        self.years_since_last = 0
        self.output = None
        
    def reset(self) -> np.ndarray:
        """Reset environment for new episode"""
        rng = np.random.default_rng()
        self.person = Person(self.params, rng)
        
        # ★ CRITICAL: Must call simulate() to generate polyps and cancers!
        # This simulates the natural disease progression over the person's lifetime
        self.person.simulate()  # No output passed - we track manually
        
        self.current_age = self.min_age
        self.years_since_last = self.max_history
        self.output = Output(self.params)
        
        # Reset episode events tracking
        self.episode_events = {
            'cancers': 0,
            'deaths': 0,
            'life_years': 0.0,
            'costs': 0.0,
            'screenings': 0
        }
        
        # Regenerate if person died before min_age
        while self.person.death_age <= self.current_age:
            rng = np.random.default_rng()
            self.person = Person(self.params, rng)
            self.person.simulate()  # Must simulate each new person
            
        return self._get_observation()
    
    def _get_observation(self) -> np.ndarray:
        """Get current state observation"""
        age_norm = self.current_age / 100.0
        hist_norm = self.years_since_last / 10.0
        gender = float(self.person.gender)
        
        # 13 zones for colon locations (0-12)
        zones = np.zeros(13)
        adv_threshold = getattr(self.params, 'adv_polyp_transition', 5)
        
        # Polyp status
        for p in self.person.polyps:
            if p.age_developed <= self.current_age < p.age_end:
                loc = min(p.location, 12)
                if p.stage >= adv_threshold:
                    zones[loc] = 2  # Advanced polyp
                else:
                    zones[loc] = 1  # Early polyp
        
        # Cancer status
        for c in self.person.cancers:
            if c.age_developed <= self.current_age:
                loc = min(c.location, 12)
                if c.detected:
                    zones[loc] = 4  # Detected cancer
                else:
                    zones[loc] = 3  # Undetected cancer
        
        obs = np.array([age_norm, hist_norm, gender] + list(zones), dtype=np.float32)
        return obs
    
    def _calculate_reward(self, action: int, done: bool) -> float:
        """
        Calculate reward based on reward type and sparse setting
        """
        reward = 0.0
        
        # Dense reward components (applied each step if sparse=False)
        if not self.config.sparse_reward or done:
            reward = self._get_reward_by_type()
        
        # Small step rewards/penalties for training stability
        if action == 1:  # Screening action
            self.episode_events['screenings'] += 1
            if not self.config.sparse_reward:
                # Small cost penalty for screening
                reward -= 0.01
        
        # Terminal rewards
        if done:
            if self.current_age >= self.max_age:
                reward += 1.0  # Survival bonus
            else:
                reward -= 0.5  # Premature death penalty
        
        return reward
    
    def _get_reward_by_type(self) -> float:
        """Get reward based on configured reward type"""
        reward = 0.0
        
        if self.config.reward_type == RewardType.CRC_INCIDENCE:
            # Negative reward for each cancer
            current_cancers = self.output.cancers_count
            reward = -0.5 * current_cancers
            
        elif self.config.reward_type == RewardType.CRC_MORTALITY:
            # Negative reward for cancer deaths
            reward = -1.0 * self.output.cancer_deaths
            
        elif self.config.reward_type == RewardType.LIFE_YEARS_LOST:
            # Reward for person years gained
            expected_years = self.person.natural_death_age - self.min_age
            actual_years = min(self.person.death_age, self.max_age) - self.min_age
            years_lost = max(0, expected_years - actual_years)
            reward = -0.1 * years_lost
            
        elif self.config.reward_type == RewardType.OVERALL_COSTS:
            # Negative reward for costs (normalized)
            cost_normalized = self.output.total_discounted_cost / 10000.0
            reward = -cost_normalized
            
        elif self.config.reward_type == RewardType.STATUS_QUO:
            # Status quo: NO SCREENING baseline
            # Survival time without any intervention
            reward = 0.1 * (self.current_age - self.min_age) / (self.max_age - self.min_age)
            # Heavy penalty for any screening to enforce NO screening policy
            if self.episode_events['screenings'] > 0:
                reward -= 10.0 * self.episode_events['screenings']
        
        return reward
    
    def step(self, action: int) -> Tuple[np.ndarray, float, bool]:
        """Execute action and return next state, reward, done"""
        done = False
        
        # Perform action
        if action == 1:  # Screen
            prev_cost = self.output.total_discounted_cost
            self.person._perform_colonoscopy(self.current_age, self.output, is_screening=True)
            self.episode_events['costs'] += self.output.total_discounted_cost - prev_cost
            self.years_since_last = 0
        else:
            self.years_since_last = min(self.years_since_last + 1, self.max_history)
        
        # Advance time
        self.current_age += 1
        
        # Check terminal conditions
        if self.current_age >= self.person.death_age:
            done = True
            if self.output.cancer_deaths > 0:
                self.episode_events['deaths'] += 1
        elif self.current_age >= self.max_age:
            done = True
        
        # Track life years
        self.episode_events['life_years'] = min(self.person.death_age, self.max_age) - self.min_age
        
        # ★ Count cancers that have developed by current age (from person's cancer list)
        cancers_developed = sum(1 for c in self.person.cancers if c.age_developed <= self.current_age)
        self.episode_events['cancers'] = cancers_developed
        
        reward = self._calculate_reward(action, done)
        
        return self._get_observation(), reward, done

# ============================================================
# [5] Actor-Critic Network
# ============================================================
class ActorCriticGAE(nn.Module):
    """
    Actor-Critic network for PPO with GAE
    Separate networks for actor and critic
    """
    def __init__(self, state_dim: int, action_dim: int, device: torch.device):
        super(ActorCriticGAE, self).__init__()
        self.device = device
        
        # Actor network (policy)
        self.actor = nn.Sequential(
            nn.Linear(state_dim, 256),
            nn.ReLU(),
            nn.Linear(256, 256),
            nn.ReLU(),
            nn.Linear(256, 128),
            nn.ReLU(),
            nn.Linear(128, action_dim),
            nn.Softmax(dim=-1)
        ).to(device)
        
        # Critic network (value function)
        self.critic = nn.Sequential(
            nn.Linear(state_dim, 256),
            nn.ReLU(),
            nn.Linear(256, 256),
            nn.ReLU(),
            nn.Linear(256, 128),
            nn.ReLU(),
            nn.Linear(128, 1)
        ).to(device)
        
    def act(self, state: np.ndarray) -> Tuple[int, torch.Tensor, torch.Tensor]:
        """Select action based on policy"""
        state_t = torch.FloatTensor(state).unsqueeze(0).to(self.device)
        probs = self.actor(state_t)
        dist = Categorical(probs)
        action = dist.sample()
        
        return (
            action.item(),
            dist.log_prob(action),
            self.critic(state_t)
        )
    
    def evaluate(self, states: torch.Tensor, actions: torch.Tensor) -> Tuple[torch.Tensor, torch.Tensor, torch.Tensor]:
        """Evaluate actions for PPO update"""
        probs = self.actor(states)
        dist = Categorical(probs)
        
        action_logprobs = dist.log_prob(actions)
        dist_entropy = dist.entropy()
        state_values = self.critic(states)
        
        return action_logprobs, state_values.squeeze(), dist_entropy

# ============================================================
# [6] GAE Calculator
# ============================================================
def compute_gae(
    rewards: List[float],
    values: List[float],
    dones: List[bool],
    gamma: float,
    gae_lambda: float
) -> Tuple[torch.Tensor, torch.Tensor]:
    """
    Compute Generalized Advantage Estimation (GAE)
    
    GAE-Lambda: A_t = sum_{l=0}^{inf} (gamma * lambda)^l * delta_{t+l}
    where delta_t = r_t + gamma * V(s_{t+1}) - V(s_t)
    
    Args:
        rewards: List of rewards
        values: List of value estimates
        dones: List of done flags
        gamma: Discount factor
        gae_lambda: GAE lambda parameter
        
    Returns:
        advantages: GAE advantages
        returns: Discounted returns
    """
    gae = 0
    advantages = []
    
    # Append last value for bootstrapping
    values = values + [0]
    
    for step in reversed(range(len(rewards))):
        if dones[step]:
            next_value = 0
            gae = 0
        else:
            next_value = values[step + 1]
        
        delta = rewards[step] + gamma * next_value - values[step]
        gae = delta + gamma * gae_lambda * gae * (1 - int(dones[step]))
        advantages.insert(0, gae)
    
    advantages = torch.tensor(advantages, dtype=torch.float32)
    returns = advantages + torch.tensor(values[:-1], dtype=torch.float32)
    
    # Normalize advantages
    if len(advantages) > 1:
        advantages = (advantages - advantages.mean()) / (advantages.std() + 1e-8)
    
    return advantages, returns

# ============================================================
# [7] PPO with GAE Optimizer
# ============================================================
class PPOGAEOptimizer:
    """
    PPO optimizer with Generalized Advantage Estimation
    Supports multiple reward types and sparse rewards
    """
    def __init__(self, settings_file: str, config: Optional[GAEConfig] = None):
        self.device = get_device()
        self.config = config if config else GAEConfig()
        self.settings_file = settings_file
        
        # Initialize environment
        self.env = ColonoscopyGAEEnv(settings_file, self.config)
        
        # Initialize networks
        self.policy = ActorCriticGAE(
            self.env.state_dim, 
            self.env.action_dim,
            self.device
        )
        self.policy_old = ActorCriticGAE(
            self.env.state_dim,
            self.env.action_dim,
            self.device
        )
        self.policy_old.load_state_dict(self.policy.state_dict())
        
        # Separate optimizers for actor and critic
        self.optimizer_actor = optim.Adam(
            self.policy.actor.parameters(), 
            lr=self.config.lr_actor
        )
        self.optimizer_critic = optim.Adam(
            self.policy.critic.parameters(), 
            lr=self.config.lr_critic
        )
        
        # Experience buffer
        self.buffer = {
            'states': [],
            'actions': [],
            'logprobs': [],
            'rewards': [],
            'values': [],
            'dones': []
        }
        
        # Training statistics
        self.training_stats = {
            'episode_rewards': [],
            'actor_losses': [],
            'critic_losses': [],
            'avg_advantages': []
        }
        
    def _clear_buffer(self):
        """Clear experience buffer"""
        for key in self.buffer:
            self.buffer[key] = []
    
    def train(self, max_episodes: Optional[int] = None):
        """Train the agent using PPO with GAE"""
        if max_episodes is None:
            max_episodes = self.config.max_episodes
            
        print("=" * 60)
        print("  PPO with GAE Training")
        print("=" * 60)
        print(f"  Reward Type: {self.config.reward_type.name}")
        print(f"  Sparse Reward: {self.config.sparse_reward}")
        print(f"  GAE Lambda: {self.config.gae_lambda}")
        print(f"  Gamma: {self.config.gamma}")
        print(f"  Device: {self.device}")
        print("=" * 60)
        
        timestep = 0
        
        for episode in range(1, max_episodes + 1):
            state = self.env.reset()
            episode_reward = 0
            
            while True:
                timestep += 1
                
                # Select action
                with torch.no_grad():
                    action, logprob, value = self.policy_old.act(state)
                
                # Step environment
                next_state, reward, done = self.env.step(action)
                
                # Store experience
                self.buffer['states'].append(state)
                self.buffer['actions'].append(action)
                self.buffer['logprobs'].append(logprob.item())
                self.buffer['rewards'].append(reward)
                self.buffer['values'].append(value.item())
                self.buffer['dones'].append(done)
                
                state = next_state
                episode_reward += reward
                
                # Update policy
                if timestep % self.config.update_timestep == 0:
                    self._update()
                    self._clear_buffer()
                
                if done:
                    break
            
            self.training_stats['episode_rewards'].append(episode_reward)
            
            # Logging
            if episode % 100 == 0:
                avg_reward = np.mean(self.training_stats['episode_rewards'][-100:])
                print(f"Episode {episode:5d} | Avg Reward: {avg_reward:8.3f} | "
                      f"Events - Cancers: {self.env.episode_events['cancers']}, "
                      f"Screenings: {self.env.episode_events['screenings']}")
        
        print("\n>>> Training Complete!")
        self._save_model()
        
    def _update(self):
        """Update policy using PPO with GAE"""
        if len(self.buffer['states']) == 0:
            return
        
        # Compute GAE advantages
        advantages, returns = compute_gae(
            self.buffer['rewards'],
            self.buffer['values'],
            self.buffer['dones'],
            self.config.gamma,
            self.config.gae_lambda
        )
        
        # Convert to tensors
        old_states = torch.FloatTensor(np.array(self.buffer['states'])).to(self.device)
        old_actions = torch.LongTensor(self.buffer['actions']).to(self.device)
        old_logprobs = torch.FloatTensor(self.buffer['logprobs']).to(self.device)
        advantages = advantages.to(self.device)
        returns = returns.to(self.device)
        
        # PPO update epochs
        for _ in range(self.config.K_epochs):
            # Evaluate current policy
            logprobs, state_values, dist_entropy = self.policy.evaluate(old_states, old_actions)
            
            # Importance ratio
            ratios = torch.exp(logprobs - old_logprobs)
            
            # Surrogate losses
            surr1 = ratios * advantages
            surr2 = torch.clamp(ratios, 1 - self.config.eps_clip, 1 + self.config.eps_clip) * advantages
            
            # Actor loss (with entropy bonus)
            actor_loss = -torch.min(surr1, surr2).mean() - self.config.entropy_coef * dist_entropy.mean()
            
            # Critic loss
            critic_loss = nn.MSELoss()(state_values, returns)
            
            # Update actor
            self.optimizer_actor.zero_grad()
            actor_loss.backward()
            torch.nn.utils.clip_grad_norm_(self.policy.actor.parameters(), 0.5)
            self.optimizer_actor.step()
            
            # Update critic
            self.optimizer_critic.zero_grad()
            critic_loss.backward()
            torch.nn.utils.clip_grad_norm_(self.policy.critic.parameters(), 0.5)
            self.optimizer_critic.step()
        
        # Sync old policy
        self.policy_old.load_state_dict(self.policy.state_dict())
        
        # Store stats
        self.training_stats['actor_losses'].append(actor_loss.item())
        self.training_stats['critic_losses'].append(critic_loss.item())
        self.training_stats['avg_advantages'].append(advantages.mean().item())

    def _save_model(self):
        """Save trained model"""
        reward_name = self.config.reward_type.name.lower()
        sparse_str = "sparse" if self.config.sparse_reward else "dense"
        filename = f"ppo_gae_{reward_name}_{sparse_str}.pth"
        
        save_dict = {
            'actor_state_dict': self.policy.actor.state_dict(),
            'critic_state_dict': self.policy.critic.state_dict(),
            'config': {
                'reward_type': self.config.reward_type.value,
                'sparse_reward': self.config.sparse_reward,
                'gamma': self.config.gamma,
                'gae_lambda': self.config.gae_lambda
            }
        }
        
        torch.save(save_dict, filename)
        print(f">>> Model saved to '{filename}'")
        
    def print_sample_decisions(self):
        """Print sample decisions for different states"""
        print("\n" + "=" * 50)
        print("  Sample Policy Decisions")
        print("=" * 50)
        
        test_cases = [
            ("Healthy 50yo Male, Long History", 
             [0.5, 1.0, 0.0] + [0] * 13),
            ("Healthy 50yo Female, Recent Screen",
             [0.5, 0.1, 1.0] + [0] * 13),
            ("Advanced Polyp (Zone 5)",
             [0.5, 0.5, 0.0] + [0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0]),
            ("Undetected Cancer (Zone 8)",
             [0.5, 0.5, 0.0] + [0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0]),
            ("Elderly 75yo, Healthy",
             [0.75, 0.5, 0.0] + [0] * 13)
        ]
        
        for name, state_values in test_cases:
            state = np.array(state_values, dtype=np.float32)
            with torch.no_grad():
                action, _, _ = self.policy.act(state)
            decision = "Screen" if action == 1 else "Wait"
            print(f"  {name}: {decision}")
        
        print("=" * 50)

# ============================================================
# [8] Main Entry Point
# ============================================================
def main():
    """Main function to run the DRL optimizer with GAE"""
    settings_file = 'settings.ini'
    
    print("=" * 60)
    print("  DRL Optimizer with GAE")
    print("=" * 60)
    print("\nSelect Reward Type:")
    print("  [1] CRC Incidence - Minimize cancer incidence")
    print("  [2] CRC Mortality - Minimize cancer deaths")
    print("  [3] Life Years Lost - Minimize life years lost to CRC")
    print("  [4] Overall Costs - Minimize total costs")
    print("  [5] Status Quo - No screening baseline")
    
    choice = input("\nEnter choice (1-5): ").strip()
    
    reward_map = {
        '1': RewardType.CRC_INCIDENCE,
        '2': RewardType.CRC_MORTALITY,
        '3': RewardType.LIFE_YEARS_LOST,
        '4': RewardType.OVERALL_COSTS,
        '5': RewardType.STATUS_QUO
    }
    
    if choice not in reward_map:
        print("Invalid choice. Using default (CRC Incidence).")
        reward_type = RewardType.CRC_INCIDENCE
    else:
        reward_type = reward_map[choice]
    
    sparse_input = input("Use sparse rewards? (y/n, default=y): ").strip().lower()
    sparse_reward = sparse_input != 'n'
    
    episodes_input = input("Number of training episodes (default=5000): ").strip()
    try:
        max_episodes = int(episodes_input) if episodes_input else 5000
    except ValueError:
        max_episodes = 5000
    
    # Create configuration
    config = GAEConfig(
        reward_type=reward_type,
        sparse_reward=sparse_reward,
        max_episodes=max_episodes
    )
    
    # Initialize and train optimizer
    optimizer = PPOGAEOptimizer(settings_file, config)
    optimizer.train()
    optimizer.print_sample_decisions()

if __name__ == '__main__':
    multiprocessing.freeze_support()
    main()
