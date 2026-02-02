"""
True Dynamic Programming Optimizer
====================================
This module implements Dynamic Programming using analytical transition probabilities
calculated directly from the parameters in settings.ini, without relying on
simulation-based probability extraction.

The transition matrix is computed from known model parameters:
- Polyp incidence rates (GeneralNewPolypsRisk)
- Polyp progression rates (PolypStage{1-6}AgeProgressionRate)
- Fast cancer rates (FastCancerRates)
- Healing rates (HealingRates)
- Background mortality (LifeTableMales/Females)
- Cancer survival (osByGenderAgeStage)
- Sojourn time (sojournTimeStage{1-4}AtDiagnosisCDF)

States:
    0: Healthy - No polyps or cancer
    1: Early Polyp - Stages 1-4 (before advanced transition)
    2: Advanced Polyp - Stages 5-6 (after advanced transition)
    3: Undetected Cancer - Cancer present but not yet symptomatic/detected
    4: Detected Cancer - Symptomatic or screen-detected cancer
    5: Dead

Actions:
    0: Wait (no screening)
    1: Screen (perform colonoscopy)
"""

import numpy as np
from parameters import SimulationParameters


class TransitionMatrixCalculator:
    """
    Calculates the 6x6 transition matrix for each age from settings.ini parameters.
    
    The transition matrix T[age][s1][s2] represents P(next_state = s2 | current_state = s1, age)
    """
    
    def __init__(self, params: SimulationParameters):
        self.params = params
        self.n_states = 6
        self.max_age = 100
        
        # Pre-compute transition matrices for all ages
        self.transition_matrices = np.zeros((self.max_age + 1, self.n_states, self.n_states))
        self._compute_all_matrices()
    
    def _compute_all_matrices(self):
        """Pre-compute transition matrices for all ages."""
        for age in range(self.max_age + 1):
            self.transition_matrices[age] = self._compute_matrix_for_age(age)
    
    def _get_background_mortality(self, age: int) -> float:
        """Get background (non-cancer) mortality probability at given age."""
        # Weighted average of male and female life tables
        p_female = self.params.fraction_female
        
        age_idx = min(age, len(self.params.life_table_males) - 1)
        if age_idx < 0:
            return 0.0
        
        p_death_male = self.params.life_table_males[age_idx] if age_idx < len(self.params.life_table_males) else 0.3
        p_death_female = self.params.life_table_females[age_idx] if age_idx < len(self.params.life_table_females) else 0.3
        
        return (1 - p_female) * p_death_male + p_female * p_death_female
    
    def _get_polyp_incidence(self, age: int) -> float:
        """Get probability of developing a new polyp at given age."""
        if age < 0 or age >= len(self.params.general_new_polyps_risk):
            return 0.0
        
        # Base risk from settings
        base_risk = self.params.general_new_polyps_risk[age]
        
        # Average individual risk multiplier
        avg_indiv_risk = np.mean(self.params.individual_polyp_risk) if len(self.params.individual_polyp_risk) > 0 else 1.0
        
        # Adjust for dt (simulation time step) - annualize if needed
        # The base risk is per dt, so multiply by steps_per_year to get annual rate
        steps_per_year = int(1.0 / self.params.dt)
        
        # Convert per-step risk to annual risk: P_annual = 1 - (1 - p_step)^steps
        p_step = base_risk * avg_indiv_risk
        p_annual = 1 - (1 - p_step) ** steps_per_year
        
        return min(p_annual, 1.0)
    
    def _get_polyp_progression(self, age: int) -> tuple:
        """
        Get polyp progression probabilities.
        
        Returns:
            (p_early_to_advanced, p_advanced_to_cancer)
        """
        # Early polyp stages: 1-4
        # Advanced polyp stages: 5-6 (adv_polyp_transition = 5)
        
        if age < 0:
            return 0.0, 0.0
        
        # Get age index for progression rates
        age_idx = min(age, 99)
        
        # Early polyp progression (Stages 1-4 -> 5)
        # We use average of stages 1-4 progression rates
        early_probs = []
        for stage in range(1, 5):  # Stages 1-4
            if stage - 1 < len(self.params.polyp_progression_rates):
                rates = self.params.polyp_progression_rates[stage - 1]
                if age_idx < len(rates):
                    early_probs.append(rates[age_idx])
        
        # Combine progression through multiple stages (approximate)
        # Use average rate as representative
        p_early_prog = np.mean(early_probs) if early_probs else 0.0
        
        # Advanced polyp progression (Stages 5-6 -> Cancer)
        adv_probs = []
        for stage in range(5, 7):  # Stages 5-6
            if stage - 1 < len(self.params.polyp_progression_rates):
                rates = self.params.polyp_progression_rates[stage - 1]
                if age_idx < len(rates):
                    adv_probs.append(rates[age_idx])
        
        p_adv_prog = np.mean(adv_probs) if adv_probs else 0.0
        
        return p_early_prog, p_adv_prog
    
    def _get_fast_cancer_rate(self) -> tuple:
        """
        Get fast cancer rates (cancer development without full polyp progression).
        
        Returns:
            (p_fast_early, p_fast_advanced) - probability of jumping to cancer
        """
        # FastCancerRates correspond to each polyp stage
        # Early stages (1-4) 
        early_fast = []
        for i in range(4):
            if i < len(self.params.fast_cancer_rates):
                early_fast.append(self.params.fast_cancer_rates[i])
        
        # Advanced stages (5-6)
        adv_fast = []
        for i in range(4, 6):
            if i < len(self.params.fast_cancer_rates):
                adv_fast.append(self.params.fast_cancer_rates[i])
        
        p_fast_early = np.mean(early_fast) if early_fast else 0.0
        p_fast_adv = np.mean(adv_fast) if adv_fast else 0.0
        
        return p_fast_early, p_fast_adv
    
    def _get_healing_rate(self) -> tuple:
        """
        Get polyp healing (regression) rates.
        
        Returns:
            (p_heal_early, p_heal_advanced)
        """
        # Healing rates by stage
        early_heal = []
        for i in range(4):
            if i < len(self.params.healing_rates):
                early_heal.append(self.params.healing_rates[i])
        
        adv_heal = []
        for i in range(4, 6):
            if i < len(self.params.healing_rates):
                adv_heal.append(self.params.healing_rates[i])
        
        p_heal_early = np.mean(early_heal) if early_heal else 0.0
        p_heal_adv = np.mean(adv_heal) if adv_heal else 0.0
        
        return p_heal_early, p_heal_adv
    
    def _get_direct_cancer_rate(self, age: int) -> float:
        """Get direct cancer development rate (no polyp precursor)."""
        if age < 0:
            return 0.0
        
        age_idx = min(age, len(self.params.direct_cancer_risk_male) - 1)
        
        p_female = self.params.fraction_female
        
        p_male = self.params.direct_cancer_risk_male[age_idx] if age_idx >= 0 else 0.0
        p_female_risk = self.params.direct_cancer_risk_female[age_idx] if age_idx >= 0 else 0.0
        
        # Scale by DirectCancerSpeed
        base_rate = (1 - p_female) * p_male + p_female * p_female_risk
        
        return base_rate * self.params.direct_cancer_speed
    
    def _get_cancer_symptom_rate(self) -> float:
        """
        Get rate of cancer becoming symptomatic (undetected -> detected).
        Based on sojourn time CDFs.
        """
        # Average sojourn time across stages
        # Use 1-year transition probability
        avg_symptom_prob = 0.0
        count = 0
        
        for stage_cdf in self.params.sojourn_cdf:
            if len(stage_cdf) > 0:
                # CDF gives P(symptoms by year t)
                # P(symptoms in year 1) = CDF[0] (first entry is for 1 year)
                avg_symptom_prob += stage_cdf[0] if len(stage_cdf) > 0 else 0.0
                count += 1
        
        return avg_symptom_prob / count if count > 0 else 0.1
    
    def _get_cancer_mortality(self, age: int) -> float:
        """
        Get cancer-specific mortality rate.
        Based on overall survival curves in osByGenderAgeStage.
        """
        # Average across stages 1-4
        # This is the 1-year survival probability
        # Mortality = 1 - survival
        
        # Using age groups from settings
        age_group = 0
        for i, threshold in enumerate(self.params.os_age_ranges):
            if age >= threshold:
                age_group = i + 1
        age_group = min(age_group, self.params.n_age_groups - 1)
        
        # Get average mortality across all stages
        mortality_rates = []
        
        # os_by_gender_age_stage is a flat array organized by:
        # [gender][stage][age_group][time_point]
        # We want 1-year survival (index 1) for each stage
        
        for stage in range(4):  # Stages 1-4
            idx = stage * self.params.n_age_groups * self.params.num_data_points_per_surv_curve
            idx += age_group * self.params.num_data_points_per_surv_curve
            idx += 1  # 1-year survival
            
            if idx < len(self.params.os_by_gender_age_stage):
                survival = self.params.os_by_gender_age_stage[idx]
                mortality_rates.append(1 - survival)
        
        return np.mean(mortality_rates) if mortality_rates else 0.05
    
    def _compute_matrix_for_age(self, age: int) -> np.ndarray:
        """
        Compute the 6x6 transition matrix for a given age.
        """
        T = np.zeros((self.n_states, self.n_states))
        
        # Get all probabilities for this age
        p_death_bg = self._get_background_mortality(age)
        p_polyp = self._get_polyp_incidence(age)
        p_early_prog, p_adv_prog = self._get_polyp_progression(age)
        p_fast_early, p_fast_adv = self._get_fast_cancer_rate()
        p_heal_early, p_heal_adv = self._get_healing_rate()
        p_direct_cancer = self._get_direct_cancer_rate(age)
        p_symptom = self._get_cancer_symptom_rate()
        p_cancer_death = self._get_cancer_mortality(age)
        
        # Ensure valid probabilities (0-1 range)
        def clip(p): return max(0.0, min(1.0, p))
        
        p_death_bg = clip(p_death_bg)
        p_polyp = clip(p_polyp)
        p_direct_cancer = clip(p_direct_cancer)
        
        # === State 0: Healthy ===
        # Can: stay healthy, develop polyp, develop direct cancer, die
        p_stay_healthy = 1 - p_polyp - p_direct_cancer - p_death_bg
        p_stay_healthy = max(0.0, p_stay_healthy)
        
        T[0, 0] = p_stay_healthy  # Stay healthy
        T[0, 1] = p_polyp         # Develop early polyp
        T[0, 3] = p_direct_cancer # Direct cancer (skip polyp)
        T[0, 5] = p_death_bg      # Background death
        
        # Normalize row 0
        total = T[0].sum()
        if total > 1:
            T[0] /= total
        elif total < 1:
            T[0, 0] += 1 - total  # Add remainder to stay healthy
        
        # === State 1: Early Polyp ===
        # Can: regress to healthy, stay early, progress to advanced, fast cancer, die
        p_stay_early = 1 - p_heal_early - p_early_prog - p_fast_early - p_death_bg
        p_stay_early = max(0.0, p_stay_early)
        
        T[1, 0] = p_heal_early    # Regress to healthy
        T[1, 1] = p_stay_early    # Stay early
        T[1, 2] = p_early_prog    # Progress to advanced
        T[1, 3] = p_fast_early    # Fast cancer
        T[1, 5] = p_death_bg      # Background death
        
        total = T[1].sum()
        if total > 1:
            T[1] /= total
        elif total < 1:
            T[1, 1] += 1 - total
        
        # === State 2: Advanced Polyp ===
        # Can: regress to early, stay advanced, progress to cancer, die
        p_stay_adv = 1 - p_heal_adv - p_adv_prog - p_fast_adv - p_death_bg
        p_stay_adv = max(0.0, p_stay_adv)
        
        T[2, 1] = p_heal_adv      # Regress to early polyp
        T[2, 2] = p_stay_adv      # Stay advanced
        T[2, 3] = p_adv_prog + p_fast_adv  # Progress to cancer
        T[2, 5] = p_death_bg      # Background death
        
        total = T[2].sum()
        if total > 1:
            T[2] /= total
        elif total < 1:
            T[2, 2] += 1 - total
        
        # === State 3: Undetected Cancer ===
        # Can: stay undetected, become symptomatic, die from cancer
        p_cancer_death_total = min(p_cancer_death + p_death_bg, 1.0)
        p_stay_undetected = 1 - p_symptom - p_cancer_death_total
        p_stay_undetected = max(0.0, p_stay_undetected)
        
        T[3, 3] = p_stay_undetected     # Stay undetected
        T[3, 4] = p_symptom             # Become symptomatic
        T[3, 5] = p_cancer_death_total  # Die
        
        total = T[3].sum()
        if total > 1:
            T[3] /= total
        elif total < 1:
            T[3, 3] += 1 - total
        
        # === State 4: Detected Cancer ===
        # Can: stay detected (in treatment), die
        p_stay_detected = 1 - p_cancer_death_total
        p_stay_detected = max(0.0, p_stay_detected)
        
        T[4, 4] = p_stay_detected       # Stay in treatment
        T[4, 5] = p_cancer_death_total  # Die
        
        total = T[4].sum()
        if total > 1:
            T[4] /= total
        elif total < 1:
            T[4, 4] += 1 - total
        
        # === State 5: Dead ===
        # Absorbing state
        T[5, 5] = 1.0
        
        return T
    
    def get_matrix(self, age: int) -> np.ndarray:
        """Get pre-computed transition matrix for given age."""
        age = max(0, min(age, self.max_age))
        return self.transition_matrices[age]
    
    def print_matrix(self, age: int):
        """Print transition matrix for debugging."""
        T = self.get_matrix(age)
        states = ['Healthy', 'Early', 'Advanced', 'Undetected', 'Detected', 'Dead']
        
        print(f"\n=== Transition Matrix at Age {age} ===")
        print("       " + "  ".join(f"{s:>10}" for s in states))
        for i, row_name in enumerate(states):
            row_str = "  ".join(f"{T[i,j]:10.4f}" for j in range(6))
            print(f"{row_name:>8} {row_str}")
        print(f"Row sums: {[f'{T[i].sum():.4f}' for i in range(6)]}")


class TrueDPOptimizer:
    """
    Dynamic Programming optimizer using analytical transition probabilities.
    
    Uses backward induction (Value Iteration) to find optimal screening policy.
    """
    
    def __init__(self, settings_file: str):
        self.params = SimulationParameters(settings_file)
        self.trans_calc = TransitionMatrixCalculator(self.params)
        
        # DP parameters
        self.min_age = self.params.opt_min_age
        self.max_age = self.params.opt_max_age
        self.terminal_age = 100
        self.max_history = 10  # Max years since last screening
        
        # Value & Policy tables
        # V[age, history, state] = expected future value
        # Policy[age, history] = optimal action (0=wait, 1=screen)
        self.V = np.zeros((self.terminal_age + 2, self.max_history + 1, 6))
        self.Policy = np.zeros((self.terminal_age + 2, self.max_history + 1), dtype=int)
        
        # Cost parameters
        self.val_life_year = 50000.0       # QALY value ($)
        self.cost_colo = self.params.cost_colo
        self.cost_colo_polyp = self.params.cost_colo_polyp
        self.cost_cancer_init = self.params.cost_initial_cancer[1]  # Stage I average
        
        # Screening sensitivity
        self.sens_early = 0.70   # Early polyp detection
        self.sens_adv = 0.90    # Advanced polyp detection
        self.sens_cancer = 0.95 # Cancer detection
    
    def solve(self):
        """Run backward induction to find optimal policy."""
        print("\n" + "=" * 60)
        print("  TRUE DYNAMIC PROGRAMMING OPTIMIZER")
        print("  Method: Backward Induction with Analytical Transition Matrix")
        print("=" * 60)
        
        # Print sample transition matrices for debugging
        for age in [40, 50, 60, 70]:
            self.trans_calc.print_matrix(age)
        
        print("\n>>> Starting Backward Induction...")
        
        # Backward induction: from terminal age to min age
        for t in range(self.terminal_age - 1, self.min_age - 1, -1):
            T = self.trans_calc.get_matrix(t)
            
            for h in range(self.max_history + 1):
                next_h_wait = min(h + 1, self.max_history)
                next_h_screen = 0
                
                # === Compute V(t, h, s) for each state ===
                
                # --- Action 0: WAIT ---
                ev_wait = np.zeros(6)
                for s in range(6):
                    # Expected future value from next states (without screening)
                    expected_future = sum(T[s, ns] * self.V[t+1, next_h_wait, ns] for ns in range(6))
                    
                    # Immediate reward
                    if s == 5:  # Dead
                        ev_wait[s] = 0
                    elif s == 4:  # Detected cancer (in treatment)
                        # Reduced quality of life + treatment costs
                        ev_wait[s] = expected_future + (self.val_life_year * 0.7) - 5000
                    elif s == 3:  # Undetected cancer
                        ev_wait[s] = expected_future + self.val_life_year
                    else:  # Healthy, Early, Advanced
                        ev_wait[s] = expected_future + self.val_life_year
                
                # --- Action 1: SCREEN ---
                ev_screen = np.zeros(6)
                
                # S=0 (Healthy): Cost only, no benefit
                expected_future_0 = sum(T[0, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6))
                ev_screen[0] = -self.cost_colo + expected_future_0 + self.val_life_year
                
                # S=1 (Early Polyp): Detect and remove → return to Healthy
                v_cured = sum(T[0, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6)) + self.val_life_year
                v_missed = sum(T[1, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6)) + self.val_life_year
                ev_screen[1] = -self.cost_colo - self.cost_colo_polyp + (self.sens_early * v_cured + (1-self.sens_early) * v_missed)
                
                # S=2 (Advanced Polyp): Detect and remove → return to Healthy
                v_missed_adv = sum(T[2, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6)) + self.val_life_year
                ev_screen[2] = -self.cost_colo - self.cost_colo_polyp + (self.sens_adv * v_cured + (1-self.sens_adv) * v_missed_adv)
                
                # S=3 (Undetected Cancer): Early detection → better treatment
                v_detected = sum(T[4, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6)) + (self.val_life_year * 0.8)
                v_missed_ca = sum(T[3, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6)) + self.val_life_year
                ev_screen[3] = -self.cost_colo - self.cost_cancer_init + (self.sens_cancer * v_detected + (1-self.sens_cancer) * v_missed_ca)
                
                # S=4, 5: Already detected/dead, no action needed
                ev_screen[4] = ev_wait[4]
                ev_screen[5] = ev_wait[5]
                
                # --- Optimal Action Selection ---
                # Use prior probability of each state for weighted decision
                # (Approximate prior based on age)
                prior = self._get_state_prior(t)
                
                # Weighted expected value for states 0-3 (actionable states)
                denom = sum(prior[s] for s in range(4))
                if denom > 0:
                    E_wait = sum(prior[s] / denom * ev_wait[s] for s in range(4))
                    E_screen = sum(prior[s] / denom * ev_screen[s] for s in range(4))
                else:
                    E_wait = ev_wait[0]
                    E_screen = ev_screen[0]
                
                # Choose optimal action
                if E_screen > E_wait:
                    self.Policy[t, h] = 1
                    for s in range(6):
                        self.V[t, h, s] = ev_screen[s]
                else:
                    self.Policy[t, h] = 0
                    for s in range(6):
                        self.V[t, h, s] = ev_wait[s]
                
                # Debug output for key ages
                if h == 10 and t in [50, 60, 70]:
                    diff = E_screen - E_wait
                    print(f"[Age {t}] Wait: {E_wait:,.0f} vs Screen: {E_screen:,.0f} | Diff: {diff:,.0f}")
        
        print("\n>>> Dynamic Programming Complete!")
    
    def _get_state_prior(self, age: int) -> np.ndarray:
        """
        Get approximate prior probability of being in each state at given age.
        This is based on typical disease progression rates.
        """
        # Rough approximation based on epidemiological data
        # P(Healthy) decreases, P(Polyp) increases with age
        
        base_polyp_rate = 0.01 + 0.005 * (age - 40) / 40  # 1% at 40, ~2.5% at 80
        base_cancer_rate = 0.001 + 0.002 * (age - 40) / 40  # 0.1% at 40, ~0.3% at 80
        
        prior = np.zeros(6)
        prior[0] = 1 - base_polyp_rate - base_cancer_rate  # Healthy
        prior[1] = base_polyp_rate * 0.7   # Early polyp
        prior[2] = base_polyp_rate * 0.3   # Advanced polyp
        prior[3] = base_cancer_rate * 0.5  # Undetected cancer
        prior[4] = base_cancer_rate * 0.5  # Detected cancer
        prior[5] = 0.0  # Dead (not in decision making)
        
        return prior / prior.sum()
    
    def print_optimal_policy(self):
        """Print the optimal screening policy."""
        print("\n" + "=" * 60)
        print("   OPTIMAL SCREENING POLICY (True DP with Analytical Matrix)")
        print("=" * 60)
        print(" Age | Years Since Last Screen | Recommendation")
        print("-----|-------------------------|----------------")
        
        # Print policy for 10+ years since last screening (most conservative)
        for t in range(40, 81):
            action = self.Policy[t, 10]
            action_str = "★ SCREEN" if action == 1 else "Wait"
            print(f" {t:3d} |        10+ years        | {action_str}")
        
        print("\n" + "-" * 60)
        print(" Full Policy Matrix (rows=ages 40-80, cols=history 0-10):")
        print(" " + "".join(f"{h:2d}" for h in range(11)))
        for t in range(40, 81, 5):
            row = "".join("S " if self.Policy[t, h] == 1 else ". " for h in range(11))
            print(f"{t:2d} {row}")
        print(" (S=Screen, .=Wait)")


def main():
    """Main entry point for true DP optimization."""
    settings_file = 'settings.ini'
    
    print("\n" + "=" * 60)
    print("  COLORECTAL CANCER SCREENING OPTIMIZATION")
    print("  True Dynamic Programming with Known Transition Probabilities")
    print("=" * 60)
    
    dp = TrueDPOptimizer(settings_file)
    dp.solve()
    dp.print_optimal_policy()
    
    return dp


if __name__ == '__main__':
    main()
