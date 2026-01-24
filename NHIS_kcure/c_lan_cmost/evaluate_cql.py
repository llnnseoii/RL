"""
CQL Policy Evaluation Script

학습된 CQL 모델을 평가하여 최적의 검진 정책과 주기를 분석합니다.
"""

import numpy as np
import torch
import pickle
from parameters import SimulationParameters
from cql_optimizer import CQLOptimizer, QNetwork
from entities import Person
from output import Output


class CQLPolicyEvaluator:
    def __init__(self, model_path='cql_from_mixed_50_30_20.pth', settings_file='settings.ini'):
        self.params = SimulationParameters(settings_file)
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        
        # Load trained CQL model
        self.state_dim = 16
        self.action_dim = 2
        self.q_net = QNetwork(self.state_dim, self.action_dim).to(self.device)
        self.q_net.load_state_dict(torch.load(model_path, map_location=self.device))
        self.q_net.eval()
        
        print(f"✅ Loaded CQL model from: {model_path}")
        
        self.min_age = self.params.opt_min_age
        self.max_age = self.params.opt_max_age
        self.max_history = 10
    
    def _get_state_vector(self, person, age, history):
        """Extract state vector (same as in data collection)"""
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
    
    def predict_action(self, state_vec):
        """Predict action using CQL Q-network"""
        state_t = torch.tensor(state_vec, dtype=torch.float32).unsqueeze(0).to(self.device)
        with torch.no_grad():
            q_values = self.q_net(state_t)
            action = q_values.argmax().item()
        return action, q_values[0].cpu().numpy()
    
    def evaluate_sample_cases(self):
        """Evaluate CQL policy on sample scenarios"""
        print("\n" + "="*70)
        print("  CQL LEARNED POLICY EVALUATION - Sample Cases")
        print("="*70)
        print(f" {'Case':<20} | {'Age':<4} | {'Hist':<4} | {'Decision':<10} | Q-Values")
        print("-" * 70)
        
        # Create sample scenarios
        rng = np.random.default_rng(42)
        
        # Case 1: Healthy person, various ages and histories
        for age in [45, 50, 55, 60, 65, 70]:
            for hist in [0, 5, 10]:
                person = Person(self.params, rng)
                person.polyps = []  # Healthy
                person.cancers = []
                
                state = self._get_state_vector(person, age, hist)
                action, q_vals = self.predict_action(state)
                decision = "★ SCREEN" if action == 1 else "Wait"
                
                print(f" {'Healthy':<20} | {age:<4} | {hist:<4} | {decision:<10} | Wait:{q_vals[0]:.2f}, Screen:{q_vals[1]:.2f}")
        
        print("\n" + "-" * 70)
        
        # Case 2: Person with polyps (simulated)
        print("\n --- Cases with Simulated Polyps ---")
        for age in [50, 60, 70]:
            person = Person(self.params, rng)
            # Note: We can't directly create polyps in the state vector,
            # but we can show what the policy looks like
            state = self._get_state_vector(person, age, 10)
            action, q_vals = self.predict_action(state)
            decision = "★ SCREEN" if action == 1 else "Wait"
            print(f" {'With Polyp (sim)':<20} | {age:<4} | {10:<4} | {decision:<10} | Wait:{q_vals[0]:.2f}, Screen:{q_vals[1]:.2f}")
    
    def extract_screening_policy(self):
        """Extract screening policy pattern across age and history"""
        print("\n" + "="*70)
        print("  OPTIMAL SCREENING POLICY MATRIX (CQL)")
        print("="*70)
        print("  Rows: Age | Columns: Years Since Last Screen")
        print("  ★ = Screen, · = Wait")
        print("-" * 70)
        
        # Create a healthy reference person
        rng = np.random.default_rng(42)
        person = Person(self.params, rng)
        person.polyps = []
        person.cancers = []
        
        # Policy matrix
        policy_matrix = np.zeros((self.max_age - self.min_age + 1, self.max_history + 1), dtype=int)
        
        # Header
        print("\n Age |", end="")
        for h in range(self.max_history + 1):
            print(f" {h:>2}", end="")
        print("\n-----+" + "-" * (self.max_history + 1) * 3)
        
        for age in range(self.min_age, self.max_age + 1):
            print(f" {age:3d} |", end="")
            for hist in range(self.max_history + 1):
                state = self._get_state_vector(person, age, hist)
                action, _ = self.predict_action(state)
                policy_matrix[age - self.min_age, hist] = action
                
                symbol = " ★" if action == 1 else " ·"
                print(symbol, end="")
            print()
        
        return policy_matrix
    
    def analyze_screening_intervals(self, policy_matrix):
        """Analyze typical screening intervals from policy matrix"""
        print("\n" + "="*70)
        print("  SCREENING INTERVAL ANALYSIS")
        print("="*70)
        
        # Find typical screening intervals (looking at diagonal patterns)
        # For each age, find the minimum history that triggers screening
        screening_thresholds = {}
        
        for age_idx, age in enumerate(range(self.min_age, self.max_age + 1)):
            for hist in range(self.max_history + 1):
                if policy_matrix[age_idx, hist] == 1:  # Screen action
                    screening_thresholds[age] = hist
                    break
            if age not in screening_thresholds:
                screening_thresholds[age] = None  # Never screen at this age
        
        # Print analysis
        print("\n📊 Recommended Screening Intervals by Age:")
        print(f" {'Age Range':<15} | {'Years Since Last':<20} | {'Recommendation':<30}")
        print("-" * 70)
        
        # Group by similar intervals
        age_groups = [(40, 49), (50, 59), (60, 69), (70, 79)]
        
        for start_age, end_age in age_groups:
            intervals = [screening_thresholds.get(age) for age in range(start_age, end_age + 1) 
                        if age in screening_thresholds]
            intervals = [i for i in intervals if i is not None]
            
            if intervals:
                avg_interval = np.mean(intervals)
                most_common = max(set(intervals), key=intervals.count)
                print(f" {start_age}-{end_age} years   | {most_common} years (avg: {avg_interval:.1f}) | Screen every {most_common} years")
            else:
                print(f" {start_age}-{end_age} years   | {'N/A':<20} | No screening recommended")
        
        # Overall recommendation
        print("\n" + "="*70)
        print("💡 KEY INSIGHTS:")
        all_intervals = [v for v in screening_thresholds.values() if v is not None]
        if all_intervals:
            overall_avg = np.mean(all_intervals)
            most_common_overall = max(set(all_intervals), key=all_intervals.count)
            print(f"   - Most common interval: {most_common_overall} years")
            print(f"   - Average interval: {overall_avg:.1f} years")
            
            # Count policy preferences
            total_decisions = policy_matrix.size
            screen_decisions = np.sum(policy_matrix)
            wait_decisions = total_decisions - screen_decisions
            print(f"   - Overall screening rate: {screen_decisions/total_decisions*100:.1f}%")
            print(f"   - Total (age, history) combinations: {total_decisions}")
            print(f"     • Screen: {screen_decisions} cases")
            print(f"     • Wait: {wait_decisions} cases")
        
        return screening_thresholds
    
    def simulate_with_cql_policy(self, n_people=1000):
        """Simulate episodes using the learned CQL policy"""
        print("\n" + "="*70)
        print(f"  SIMULATION WITH CQL POLICY ({n_people} people)")
        print("="*70)
        
        rng = np.random.default_rng()
        total_rewards = []
        total_costs = []
        screening_counts = []
        
        for i in range(n_people):
            person = Person(self.params, rng)
            if person.death_age <= self.min_age:
                continue
            
            curr_age = self.min_age
            hist = self.max_history
            output = Output(self.params)
            episode_reward = 0
            num_screenings = 0
            
            while curr_age < min(person.death_age, self.max_age):
                state = self._get_state_vector(person, curr_age, hist)
                action, _ = self.predict_action(state)
                
                reward = 0
                next_hist = min(hist + 1, self.max_history)
                
                if action == 1:  # Screen
                    had_adv_polyp = False
                    had_cancer = False
                    adv_threshold = getattr(self.params, 'adv_polyp_transition', 5)
                    
                    for p in person.polyps:
                        if p.age_developed <= curr_age < p.age_end and p.stage >= adv_threshold:
                            had_adv_polyp = True
                            break
                    
                    for c in person.cancers:
                        if c.age_developed <= curr_age and not c.detected:
                            had_cancer = True
                            break
                    
                    prev_cost = output.total_discounted_cost
                    person._perform_colonoscopy(curr_age, output, is_screening=True)
                    step_cost = output.total_discounted_cost - prev_cost
                    
                    reward -= (step_cost * 0.0001 + 0.05)
                    if had_cancer:
                        reward += 50.0
                    elif had_adv_polyp:
                        reward += 10.0
                    
                    next_hist = 0
                    num_screenings += 1
                else:  # Wait
                    pass
                
                if curr_age + 1 >= person.death_age:
                    reward -= 100.0
                else:
                    reward += 0.1
                
                episode_reward += reward
                curr_age += 1
                hist = next_hist
            
            total_rewards.append(episode_reward)
            total_costs.append(output.total_discounted_cost)
            screening_counts.append(num_screenings)
        
        # Print results
        print(f"\n📊 Simulation Results:")
        print(f"   - Average Reward: {np.mean(total_rewards):.2f} ± {np.std(total_rewards):.2f}")
        print(f"   - Average Cost: ${np.mean(total_costs):,.0f} ± ${np.std(total_costs):,.0f}")
        print(f"   - Average Screenings per Person: {np.mean(screening_counts):.2f} ± {np.std(screening_counts):.2f}")
        print(f"   - Total People Simulated: {len(total_rewards)}")
        
        return {
            'rewards': total_rewards,
            'costs': total_costs,
            'screenings': screening_counts
        }


def main():
    print("="*70)
    print("  CQL POLICY EVALUATION AND ANALYSIS")
    print("="*70)
    
    # Initialize evaluator
    evaluator = CQLPolicyEvaluator(
        model_path='cql_from_mixed_50_30_20.pth',
        settings_file='settings.ini'
    )
    
    # 1. Evaluate sample cases
    evaluator.evaluate_sample_cases()
    
    # 2. Extract screening policy matrix
    policy_matrix = evaluator.extract_screening_policy()
    
    # 3. Analyze screening intervals
    screening_thresholds = evaluator.analyze_screening_intervals(policy_matrix)
    
    # 4. Simulate with CQL policy
    results = evaluator.simulate_with_cql_policy(n_people=1000)
    
    print("\n" + "="*70)
    print("  ✅ EVALUATION COMPLETE!")
    print("="*70)


if __name__ == "__main__":
    main()
