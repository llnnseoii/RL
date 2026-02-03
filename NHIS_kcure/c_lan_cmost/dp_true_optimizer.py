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
import argparse
from enum import Enum
from parameters import SimulationParameters


# ============================================================
# 목적 함수 유형 열거형
# ============================================================
class ObjectiveType(Enum):
    """
    DP 최적화를 위한 목적 함수 유형
    
    각 목적 함수는 다른 최적 정책을 생성합니다:
    - CRC_INCIDENCE: 대장암 발생률 최소화
    - CRC_MORTALITY: 대장암 사망률 최소화
    - LIFE_YEARS_LOST: 대장암으로 인한 손실 생존연수 최소화
    - OVERALL_COSTS: 전체 비용 최소화
    - QALY: Quality-Adjusted Life Years 최대화
    - PARETO: 다중 목적 Pareto 최적해
    """
    CRC_INCIDENCE = 1
    CRC_MORTALITY = 2
    LIFE_YEARS_LOST = 3
    OVERALL_COSTS = 4
    QALY = 5
    PARETO = 6


# ============================================================
# QALY 계산기
# ============================================================
class QALYCalculator:
    """
    QALY (Quality-Adjusted Life Years) 계산기
    UK EQ-5D-5L 기반 나이/성별별 유틸리티 값 사용
    """
    
    # 나이별 기본 유틸리티 값 (EQ-5D-5L population norms)
    UTILITY_BY_AGE = {
        20: 0.94, 25: 0.93, 30: 0.92, 35: 0.91,
        40: 0.90, 45: 0.89, 50: 0.88, 55: 0.87,
        60: 0.86, 65: 0.85, 70: 0.82, 75: 0.79,
        80: 0.75, 85: 0.70, 90: 0.65, 95: 0.60, 100: 0.55
    }
    
    # 암 병기별 유틸리티 감소량
    CANCER_DECREMENTS = {
        0: 0.00,   # 건강
        1: 0.05,   # 조기 용종
        2: 0.08,   # 진행성 용종
        3: 0.25,   # 미발견 암
        4: 0.35,   # 발견된 암 (치료 중)
        5: 0.00    # 사망 (QALY=0)
    }
    
    # 암 병기별 치료 비용 가중치
    CANCER_STAGE_COSTS = {
        1: 1.0,  # Stage I
        2: 1.3,  # Stage II
        3: 1.6,  # Stage III
        4: 2.0   # Stage IV
    }
    
    # WTP threshold
    WTP_THRESHOLD = 90000.0
    
    @classmethod
    def get_utility(cls, age: int, state: int = 0, gender: int = 0) -> float:
        """
        특정 나이, 상태, 성별에 대한 유틸리티 값 반환
        
        Args:
            age: 나이
            state: 건강 상태 (0=건강, 1=조기용종, 2=진행용종, 3=미발견암, 4=발견암, 5=사망)
            gender: 성별 (0=남성, 1=여성)
        
        Returns:
            유틸리티 값 (0.0 ~ 1.0)
        """
        if state == 5:  # 사망
            return 0.0
        
        # 나이별 기본 유틸리티 (선형 보간)
        ages = sorted(cls.UTILITY_BY_AGE.keys())
        if age <= ages[0]:
            base_utility = cls.UTILITY_BY_AGE[ages[0]]
        elif age >= ages[-1]:
            base_utility = cls.UTILITY_BY_AGE[ages[-1]]
        else:
            for i in range(len(ages) - 1):
                if ages[i] <= age < ages[i + 1]:
                    t = (age - ages[i]) / (ages[i + 1] - ages[i])
                    base_utility = (1 - t) * cls.UTILITY_BY_AGE[ages[i]] + t * cls.UTILITY_BY_AGE[ages[i + 1]]
                    break
        
        # 성별 보정 (여성이 약간 높은 유틸리티)
        if gender == 1:
            base_utility *= 1.02
        
        # 상태별 감소량 적용
        decrement = cls.CANCER_DECREMENTS.get(state, 0.0)
        utility = max(0.0, base_utility - decrement)
        
        return utility
    
    @classmethod
    def calculate_qaly(cls, age: int, state: int, years: float = 1.0, 
                       discount_rate: float = 0.03) -> float:
        """
        특정 기간의 QALY 계산
        
        Args:
            age: 시작 나이
            state: 건강 상태
            years: 기간 (년)
            discount_rate: 할인율
        
        Returns:
            QALY 값
        """
        utility = cls.get_utility(age, state)
        
        # 할인 적용
        if discount_rate > 0:
            # 연간 할인
            discount_factor = 1 / (1 + discount_rate)
            qaly = utility * years * discount_factor
        else:
            qaly = utility * years
        
        return qaly
    
    @classmethod
    def qaly_value_monetized(cls, qaly: float) -> float:
        """QALY를 금전적 가치로 변환"""
        return qaly * cls.WTP_THRESHOLD


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
    
    Supports multiple objective functions:
    - CRC_INCIDENCE: 대장암 발생률 최소화
    - CRC_MORTALITY: 대장암 사망률 최소화
    - LIFE_YEARS_LOST: 손실 생존연수 최소화
    - OVERALL_COSTS: 전체 비용 최소화
    - QALY: Quality-Adjusted Life Years 최대화
    - PARETO: 다중 목적 Pareto 최적해
    """
    
    def __init__(self, settings_file: str, objective_type: ObjectiveType = ObjectiveType.QALY):
        self.params = SimulationParameters(settings_file)
        self.trans_calc = TransitionMatrixCalculator(self.params)
        self.objective_type = objective_type
        
        # DP parameters
        self.min_age = self.params.opt_min_age
        self.max_age = self.params.opt_max_age
        self.terminal_age = 100
        self.max_history = 10  # Max years since last screening
        self.min_screen_interval = 3  # 최소 검진 간격 (년) - history < 이 값이면 검진 불가
        
        # Value & Policy tables
        # V[age, history, state] = expected future value
        # Policy[age, history] = optimal action (0=wait, 1=screen)
        self.V = np.zeros((self.terminal_age + 2, self.max_history + 1, 6))
        self.Policy = np.zeros((self.terminal_age + 2, self.max_history + 1), dtype=int)
        
        # For Pareto optimization: multiple value tables
        self.V_pareto = {}  # {objective_type: V_table}
        self.pareto_weights = {
            ObjectiveType.CRC_INCIDENCE: 0.25,
            ObjectiveType.CRC_MORTALITY: 0.25,
            ObjectiveType.LIFE_YEARS_LOST: 0.25,
            ObjectiveType.OVERALL_COSTS: 0.25
        }
        
        # Cost parameters
        self.val_life_year = 50000.0       # QALY value ($) - Korean WTP threshold
        self.cost_colo = self.params.cost_colo
        self.cost_colo_polyp = self.params.cost_colo_polyp
        self.cost_cancer_init = self.params.cost_initial_cancer[1]  # Stage I average
        self.cost_cancer_final = self.params.cost_final_cancer[1]
        
        # Objective-specific reward weights
        self._setup_objective_rewards()
        
        # Screening sensitivity
        self.sens_early = 0.70   # Early polyp detection
        self.sens_adv = 0.90    # Advanced polyp detection
        self.sens_cancer = 0.95 # Cancer detection
        
        # Discount rate
        self.discount_rate = 0.0
    
    def _setup_objective_rewards(self):
        """
        목적 함수별 보상 가중치 설정
        """
        # 각 목적 함수별 상태별 즉시 보상/비용
        # state: 0=Healthy, 1=Early, 2=Advanced, 3=Undetected, 4=Detected, 5=Dead
        
        if self.objective_type == ObjectiveType.CRC_INCIDENCE:
            # 암 발생 시 큰 페널티, 용종 발견 시 작은 보상
            self.state_rewards = {
                0: 0.0,      # Healthy
                1: -0.1,     # Early polyp (암 전구 병변)
                2: -0.3,     # Advanced polyp (암 위험 증가)
                3: -10.0,    # Undetected cancer (발생!)
                4: -8.0,     # Detected cancer (이미 발생)
                5: 0.0       # Dead
            }
            self.screen_benefit = 5.0   # 용종 제거로 암 예방 보상
            
        elif self.objective_type == ObjectiveType.CRC_MORTALITY:
            # 암 사망 시 큰 페널티
            self.state_rewards = {
                0: 0.0,
                1: 0.0,
                2: -0.1,
                3: -5.0,     # Undetected cancer (사망 위험)
                4: -3.0,     # Detected cancer (치료 중, 사망 위험 감소)
                5: -50.0     # Death from cancer
            }
            self.screen_benefit = 10.0  # 조기 발견으로 사망 예방
            
        elif self.objective_type == ObjectiveType.LIFE_YEARS_LOST:
            # 생존연수 기반 보상 (나이 고려)
            self.state_rewards = {
                0: 1.0,      # Healthy - 1 life year
                1: 0.98,     # Early polyp - 약간 감소
                2: 0.95,     # Advanced polyp
                3: 0.7,      # Undetected cancer - 기대수명 감소
                4: 0.6,      # Detected cancer - 치료 중
                5: 0.0       # Dead - no life years
            }
            self.screen_benefit = 2.0
            
        elif self.objective_type == ObjectiveType.OVERALL_COSTS:
            # 비용 최소화 (음수로 표현)
            self.state_rewards = {
                0: 0.0,                           # Healthy - no cost
                1: 0.0,                           # Early polyp
                2: 0.0,                           # Advanced polyp
                3: -self.cost_cancer_init / 1000, # Cancer treatment cost
                4: -self.cost_cancer_final / 1000,# Ongoing cancer cost
                5: 0.0
            }
            self.screen_benefit = 0.0  # 비용 절감은 암 예방에서 발생
            
        elif self.objective_type == ObjectiveType.QALY:
            # QALY 기반 (상태별 유틸리티 × 생존연수)
            # age-specific 유틸리티는 solve() 에서 적용
            self.state_rewards = None  # Use QALYCalculator dynamically
            self.screen_benefit = 0.5
            
        elif self.objective_type == ObjectiveType.PARETO:
            # Pareto: 여러 목적 함수의 가중합
            self.state_rewards = None  # Will be calculated dynamically
            self.screen_benefit = 1.0
    
    def solve(self):
        """Run backward induction to find optimal policy."""
        print("\n" + "=" * 60)
        print("  TRUE DYNAMIC PROGRAMMING OPTIMIZER")
        print(f"  Objective: {self.objective_type.name}")
        print("  Method: Backward Induction with Analytical Transition Matrix")
        print("=" * 60)
        
        # Skip transition matrix printing for cleaner output
        # for age in [40, 50, 60, 70]:
        #     self.trans_calc.print_matrix(age)
        
        print(f"\n>>> Starting Backward Induction ({self.objective_type.name})...")
        
        if self.objective_type == ObjectiveType.PARETO:
            self._solve_pareto()
        else:
            self._solve_single_objective()
        
        print("\n>>> Dynamic Programming Complete!")
    
    def _get_immediate_reward(self, state: int, age: int, action: int = 0) -> float:
        """
        목적 함수 유형에 따른 즉시 보상 계산
        
        Args:
            state: 현재 상태 (0-5)
            age: 현재 나이
            action: 행동 (0=wait, 1=screen)
        
        Returns:
            즉시 보상 값
        """
        if self.objective_type == ObjectiveType.QALY:
            # QALY: 나이/상태별 유틸리티 기반
            qaly = QALYCalculator.calculate_qaly(age, state, years=1.0, 
                                                  discount_rate=self.discount_rate)
            # 금전적 가치로 환산
            return QALYCalculator.qaly_value_monetized(qaly)
        
        elif self.objective_type == ObjectiveType.OVERALL_COSTS:
            # 비용 목적: 검진 비용 포함
            reward = self.state_rewards.get(state, 0.0) * 1000  # Scale back
            if action == 1:  # Screening
                reward -= self.cost_colo
            return reward
        
        else:
            # CRC_INCIDENCE, CRC_MORTALITY, LIFE_YEARS_LOST
            base_reward = self.state_rewards.get(state, 0.0)
            
            # Life years lost는 나이에 따른 기대수명 반영
            if self.objective_type == ObjectiveType.LIFE_YEARS_LOST:
                expected_remaining = max(0, 85 - age)  # 기대수명 85세 가정
                base_reward *= expected_remaining / 45  # 정규화
            
            return base_reward * self.val_life_year
    
    def _solve_single_objective(self):
        """단일 목적 함수에 대한 DP 해결"""
        gamma = 1.0 / (1 + self.discount_rate) if self.discount_rate > 0 else 1.0
        
        # QALY 모드에서는 WTP_THRESHOLD 사용
        if self.objective_type == ObjectiveType.QALY:
            value_scale = QALYCalculator.WTP_THRESHOLD
        else:
            value_scale = self.val_life_year
        
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
                    # Expected future value from next states
                    expected_future = sum(T[s, ns] * self.V[t+1, next_h_wait, ns] for ns in range(6))
                    
                    # Immediate reward (objective-specific)
                    immediate = self._get_immediate_reward(s, t, action=0)
                    
                    ev_wait[s] = immediate + gamma * expected_future
                
                # --- Action 1: SCREEN ---
                ev_screen = np.zeros(6)
                
                # 건강 상태(0)에서의 미래 가치 (모든 상태에서 참조)
                future_healthy = sum(T[0, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6))
                
                # S=0 (Healthy): 검진 비용만 발생, 직접적인 이득 없음
                immediate_0 = self._get_immediate_reward(0, t, action=1)
                ev_screen[0] = immediate_0 - self.cost_colo + gamma * future_healthy
                
                # S=1 (Early Polyp): 발견하면 제거 → 건강 상태로 전환
                # 용종 제거의 핵심 가치: 건강 상태 미래 - 용종 상태 미래
                future_polyp = sum(T[1, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6))
                
                # 용종 제거로 얻는 미래 QALY 이득 (핵심!)
                cure_benefit = gamma * (future_healthy - future_polyp)
                
                # 발견 시 가치 = 건강 상태 보상 + 미래 건강 가치
                v_cured = self._get_immediate_reward(0, t, action=1) + gamma * future_healthy
                # 미발견 시 가치 = 용종 상태 보상 + 미래 용종 가치 (자연 경과)
                v_missed = self._get_immediate_reward(1, t, action=1) + gamma * future_polyp
                
                ev_screen[1] = -self.cost_colo - self.cost_colo_polyp + (
                    self.sens_early * v_cured + (1 - self.sens_early) * v_missed
                )
                
                # S=2 (Advanced Polyp): 발견 → 제거 → 건강 상태
                future_adv = sum(T[2, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6))
                v_cured_adv = self._get_immediate_reward(0, t, action=1) + gamma * future_healthy
                v_missed_adv = self._get_immediate_reward(2, t, action=1) + gamma * future_adv
                
                ev_screen[2] = -self.cost_colo - self.cost_colo_polyp + (
                    self.sens_adv * v_cured_adv + (1 - self.sens_adv) * v_missed_adv
                )
                
                # S=3 (Undetected Cancer): 조기 발견 → 치료 상태로 전환
                future_undetected = sum(T[3, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6))
                future_detected = sum(T[4, ns] * self.V[t+1, next_h_screen, ns] for ns in range(6))
                
                # 조기 발견의 이점: 발견된 암은 미발견 암보다 더 나은 예후
                # 발견된 암 상태(4)의 전이 확률이 더 좋음 (사망률 낮음)
                v_detected = self._get_immediate_reward(4, t, action=1) + gamma * future_detected
                v_missed_ca = self._get_immediate_reward(3, t, action=1) + gamma * future_undetected
                
                ev_screen[3] = -self.cost_colo - self.cost_cancer_init + (
                    self.sens_cancer * v_detected + (1 - self.sens_cancer) * v_missed_ca
                )
                
                # S=4, 5: 이미 발견/사망 상태, 검진 의미 없음
                ev_screen[4] = ev_wait[4]
                ev_screen[5] = ev_wait[5]
                
                # --- Optimal Action Selection ---
                prior = self._get_state_prior(t)
                
                # Weighted expected value for states 0-3 (actionable states)
                denom = sum(prior[s] for s in range(4))
                if denom > 0:
                    E_wait = sum(prior[s] / denom * ev_wait[s] for s in range(4))
                    E_screen = sum(prior[s] / denom * ev_screen[s] for s in range(4))
                else:
                    E_wait = ev_wait[0]
                    E_screen = ev_screen[0]
                
                # 최소 검진 간격 제약: history < min_screen_interval 이면 검진 불가
                if h < self.min_screen_interval:
                    # 최근에 검진했으므로 반드시 Wait
                    self.Policy[t, h] = 0
                    for s in range(6):
                        self.V[t, h, s] = ev_wait[s]
                elif E_screen > E_wait:
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
    
    def _solve_pareto(self):
        """
        Pareto 최적화: 여러 목적 함수의 가중합
        
        각 하위 목적 함수에 대해 개별적으로 풀고,
        가중합을 사용하여 최종 정책 결정
        """
        print(">>> Pareto Optimization: Solving for each sub-objective...")
        
        sub_objectives = [
            ObjectiveType.CRC_INCIDENCE,
            ObjectiveType.CRC_MORTALITY,
            ObjectiveType.LIFE_YEARS_LOST,
            ObjectiveType.OVERALL_COSTS
        ]
        
        # 각 하위 목적 함수에 대해 풀기
        sub_values = {}
        sub_policies = {}
        
        for obj_type in sub_objectives:
            print(f"    - Solving for {obj_type.name}...")
            
            # 임시로 목적 함수 변경
            original_type = self.objective_type
            self.objective_type = obj_type
            self._setup_objective_rewards()
            
            # 풀기
            self._solve_single_objective()
            
            # 결과 저장
            sub_values[obj_type] = self.V.copy()
            sub_policies[obj_type] = self.Policy.copy()
            
            # 초기화
            self.V = np.zeros((self.terminal_age + 2, self.max_history + 1, 6))
            
            # 원래 목적 함수 복원
            self.objective_type = original_type
        
        # 가중합을 사용한 최종 정책 결정
        print(">>> Combining sub-objectives with weights...")
        
        for t in range(self.min_age, self.terminal_age):
            for h in range(self.max_history + 1):
                # 각 목적 함수의 정책 투표
                votes_screen = 0.0
                votes_wait = 0.0
                
                for obj_type in sub_objectives:
                    weight = self.pareto_weights[obj_type]
                    if sub_policies[obj_type][t, h] == 1:
                        votes_screen += weight
                    else:
                        votes_wait += weight
                
                # 다수결 (가중)
                if votes_screen > votes_wait:
                    self.Policy[t, h] = 1
                else:
                    self.Policy[t, h] = 0
                
                # 가중 평균 가치 함수
                for s in range(6):
                    weighted_value = sum(
                        self.pareto_weights[obj_type] * sub_values[obj_type][t, h, s]
                        for obj_type in sub_objectives
                    )
                    self.V[t, h, s] = weighted_value
        
        print(">>> Pareto Optimization Complete!")
        
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
        print(f"   OPTIMAL SCREENING POLICY")
        print(f"   Objective: {self.objective_type.name}")
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
        print("    " + "".join(f"{h:2d}" for h in range(11)))
        for t in range(40, 81, 5):
            row = "".join("S " if self.Policy[t, h] == 1 else ". " for h in range(11))
            print(f"{t:2d}  {row}")
        print(" (S=Screen, .=Wait)")
        
        # 검진 권고 요약 출력
        screen_ages = [t for t in range(40, 81) if self.Policy[t, 10] == 1]
        if screen_ages:
            print(f"\n Summary: Screen recommended at ages {min(screen_ages)}-{max(screen_ages)} (when 10+ yrs since last)")
        else:
            print("\n Summary: No screening recommended")


def main():
    """Main entry point for true DP optimization."""
    parser = argparse.ArgumentParser(
        description='Colorectal Cancer Screening Optimization using Dynamic Programming',
        formatter_class=argparse.RawTextHelpFormatter
    )
    
    parser.add_argument(
        '--objective', '-o', 
        type=int, 
        default=5,
        choices=[1, 2, 3, 4, 5, 6],
        help='''Objective function type:
  1 = CRC_INCIDENCE   - Minimize CRC incidence (대장암 발생률 최소화)
  2 = CRC_MORTALITY   - Minimize CRC mortality (대장암 사망률 최소화)
  3 = LIFE_YEARS_LOST - Minimize life years lost (손실 생존연수 최소화)
  4 = OVERALL_COSTS   - Minimize overall costs (전체 비용 최소화)
  5 = QALY            - Maximize QALY (Quality-Adjusted Life Years 최대화) [default]
  6 = PARETO          - Pareto optimal solution (다중 목적 최적해)'''
    )
    
    parser.add_argument(
        '--settings', '-s',
        type=str,
        default='settings.ini',
        help='Path to settings.ini file (default: settings.ini)'
    )
    
    args = parser.parse_args()
    
    # Map integer to ObjectiveType enum
    objective_map = {
        1: ObjectiveType.CRC_INCIDENCE,
        2: ObjectiveType.CRC_MORTALITY,
        3: ObjectiveType.LIFE_YEARS_LOST,
        4: ObjectiveType.OVERALL_COSTS,
        5: ObjectiveType.QALY,
        6: ObjectiveType.PARETO
    }
    
    objective_type = objective_map[args.objective]
    
    print("\n" + "=" * 60)
    print("  COLORECTAL CANCER SCREENING OPTIMIZATION")
    print("  True Dynamic Programming with Known Transition Probabilities")
    print(f"  Objective: {objective_type.name}")
    print("=" * 60)
    
    dp = TrueDPOptimizer(args.settings, objective_type=objective_type)
    dp.solve()
    dp.print_optimal_policy()
    
    return dp


if __name__ == '__main__':
    main()
