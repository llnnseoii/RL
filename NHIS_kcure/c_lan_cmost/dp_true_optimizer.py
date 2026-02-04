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
    
    # 상태별 유틸리티 감소량 (12개 상태)
    # 0=Healthy, 1-6=Polyp stages, 7-10=Cancer I-IV, 11=Dead
    CANCER_DECREMENTS = {
        0: 0.00,   # Healthy
        1: 0.01,   # Polyp Stage 1
        2: 0.02,   # Polyp Stage 2
        3: 0.03,   # Polyp Stage 3
        4: 0.04,   # Polyp Stage 4
        5: 0.05,   # Polyp Stage 5 (Advanced)
        6: 0.07,   # Polyp Stage 6 (Advanced)
        7: 0.15,   # Cancer Stage I
        8: 0.22,   # Cancer Stage II
        9: 0.32,   # Cancer Stage III
        10: 0.45,  # Cancer Stage IV
        11: 0.00   # Dead (QALY=0)
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
            state: 건강 상태 (0=Healthy, 1-6=Polyp, 7-10=Cancer, 11=Dead)
            gender: 성별 (0=남성, 1=여성)
        
        Returns:
            유틸리티 값 (0.0 ~ 1.0)
        """
        if state == 11:  # 사망
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
    
    The transition matrix T[age][risk_class][s1][s2] represents 
    P(next_state = s2 | current_state = s1, age, risk_class)
    
    Risk classes represent individual variation in polyp incidence risk,
    similar to how entities.py uses individual_polyp_risk.
    """
    
    # State indices for 12-state model
    # Polyp stages 1-6, Cancer stages I-IV (undetected)
    STATE_HEALTHY = 0
    STATE_POLYP_1 = 1
    STATE_POLYP_2 = 2
    STATE_POLYP_3 = 3
    STATE_POLYP_4 = 4
    STATE_POLYP_5 = 5  # Advanced
    STATE_POLYP_6 = 6  # Advanced
    STATE_CANCER_I = 7
    STATE_CANCER_II = 8
    STATE_CANCER_III = 9
    STATE_CANCER_IV = 10
    STATE_DEAD = 11
    
    def __init__(self, params: SimulationParameters, n_risk_classes: int = 5, min_age: int = 40, max_age: int = 80):
        self.params = params
        self.n_states = 12  # Healthy + Polyp(1-6) + Cancer(I-IV) + Dead
        self.min_age = min_age  # 계산 범위 시작 나이
        self.max_age = max_age
        self.n_risk_classes = n_risk_classes
        
        # Compute risk multipliers from individual_polyp_risk distribution
        self.risk_multipliers = self._compute_risk_multipliers()
        self.risk_class_probs = np.ones(n_risk_classes) / n_risk_classes  # Equal probability
        
        # Pre-compute transition matrices for all ages and risk classes
        # Shape: (max_age+1, n_risk_classes, n_states, n_states)
        self.transition_matrices = np.zeros((self.max_age + 1, self.n_risk_classes, 
                                              self.n_states, self.n_states))
        self._compute_all_matrices()
    
    def _compute_risk_multipliers(self) -> np.ndarray:
        """
        Compute risk multipliers for each risk class using log-scale spacing.
        
        The multipliers are evenly spaced on a log scale such that:
        - Class 0 (lowest risk): 1/sqrt(10) ≈ 0.316
        - Class n-1 (highest risk): sqrt(10) ≈ 3.162
        - Ratio between highest and lowest: exactly 10x
        - Middle class: 1.0 (baseline)
        
        Formula: multiplier[i] = 10^(-0.5 + i/(n-1))
        
        For n=5 classes:
          Class 0: 10^(-0.5) = 0.316 (1/sqrt(10))
          Class 1: 10^(-0.25) = 0.562
          Class 2: 10^(0) = 1.0 (baseline)
          Class 3: 10^(0.25) = 1.778
          Class 4: 10^(0.5) = 3.162 (sqrt(10))
        """
        multipliers = np.zeros(self.n_risk_classes)
        
        if self.n_risk_classes == 1:
            multipliers[0] = 1.0
        else:
            for i in range(self.n_risk_classes):
                # Exponent ranges from -0.5 to 0.5 (log10 scale)
                exponent = -0.5 + i / (self.n_risk_classes - 1)
                multipliers[i] = 10 ** exponent
        
        return multipliers
    
    def _compute_all_matrices(self):
        """Pre-compute transition matrices for all ages and risk classes."""
        for age in range(self.min_age, self.max_age + 1):
            for risk_class in range(self.n_risk_classes):
                self.transition_matrices[age, risk_class] = self._compute_matrix_for_age(
                    age, risk_class)
    
    def _get_background_mortality(self, age: int) -> float:
        """Get background (non-cancer) mortality probability at given age."""
        # Weighted average of male and female life tables
        p_female = self.params.fraction_female
        
        age_idx = min(age, len(self.params.life_table_males) - 1)
        if age_idx < 0:
            return 0.0
        
        p_death_male = self.params.life_table_males[age_idx] if age_idx < len(self.params.life_table_males) else 0.0
        p_death_female = self.params.life_table_females[age_idx] if age_idx < len(self.params.life_table_females) else 0.0
        
        return (1 - p_female) * p_death_male + p_female * p_death_female
    
    def _get_polyp_incidence(self, age: int, risk_class: int = -1) -> float:
        """
        Get probability of developing a new polyp at given age.
        
        Args:
            age: Current age
            risk_class: Risk class index (0 to n_risk_classes-1).
                        If -1, uses average risk (for backward compatibility).
        """
        if age < 0 or age >= len(self.params.general_new_polyps_risk):
            return 0.0
        
        # Base risk from settings
        base_risk = self.params.general_new_polyps_risk[age]
        
        # Individual risk multiplier based on risk class
        if risk_class >= 0 and risk_class < self.n_risk_classes:
            indiv_risk = self.risk_multipliers[risk_class]
        else:
            # Use average (backward compatibility)
            indiv_risk = np.mean(self.params.individual_polyp_risk) if len(self.params.individual_polyp_risk) > 0 else 1.0
        
        # Adjust for dt (simulation time step) - annualize if needed
        steps_per_year = int(1.0 / self.params.dt)
        
        # Convert per-step risk to annual risk: P_annual = 1 - (1 - p_step)^steps
        p_step = base_risk * indiv_risk
        p_annual = 1 - (1 - p_step) ** steps_per_year
        
        return min(p_annual, 1.0)
    
    def _get_polyp_progression_by_stage(self, age: int, stage: int) -> float:
        """
        Get polyp progression probability for a specific stage.
        
        Args:
            age: Current age
            stage: Polyp stage (1-6)
        
        Returns:
            Probability of progressing to next stage (or cancer for stage 6)
        """
        if age < 0 or stage < 1 or stage > 6:
            return 0.0
        
        age_idx = min(age, 99)
        stage_idx = stage - 1  # 0-indexed
        
        if stage_idx < len(self.params.polyp_progression_rates):
            rates = self.params.polyp_progression_rates[stage_idx]
            if age_idx < len(rates):
                return rates[age_idx]
        
        return 0.0
    
    def _get_fast_cancer_rate_by_stage(self, stage: int) -> float:
        """
        Get fast cancer rate for a specific polyp stage.
        
        Args:
            stage: Polyp stage (1-6)
        
        Returns:
            Probability of fast cancer development
        """
        if stage < 1 or stage > 6:
            return 0.0
        
        stage_idx = stage - 1
        if stage_idx < len(self.params.fast_cancer_rates):
            return self.params.fast_cancer_rates[stage_idx]
        return 0.0
    
    def _get_healing_rate_by_stage(self, stage: int) -> float:
        """
        Get healing (regression) rate for a specific polyp stage.
        
        Args:
            stage: Polyp stage (1-6)
        
        Returns:
            Probability of regressing to previous stage
        """
        if stage < 1 or stage > 6:
            return 0.0
        
        stage_idx = stage - 1
        if stage_idx < len(self.params.healing_rates):
            return self.params.healing_rates[stage_idx]
        return 0.0
    
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
    
    def _get_cancer_symptom_rate(self, age: int = 60) -> float:
        """
        Get rate of cancer becoming symptomatic (undetected -> detected).
        Uses stage-weighted sojourn time CDFs based on age-specific stage distribution.
        
        Args:
            age: Current age (for stage distribution lookup)
        
        Returns:
            Probability of symptoms appearing in 1 year
        """
        # Get age-specific stage distribution (like entities.py _determine_symptoms_stage)
        age_idx = min(int(age / 5), len(self.params.frac_stage1) - 1) if hasattr(self.params, 'frac_stage1') else 0
        
        if age_idx >= 0 and hasattr(self.params, 'frac_stage1'):
            p1 = self.params.frac_stage1[age_idx] if age_idx < len(self.params.frac_stage1) else 0.25
            p2 = self.params.frac_stage2[age_idx] if age_idx < len(self.params.frac_stage2) else 0.25
            p3 = self.params.frac_stage3[age_idx] if age_idx < len(self.params.frac_stage3) else 0.25
            p4 = self.params.frac_stage4[age_idx] if age_idx < len(self.params.frac_stage4) else 0.25
        else:
            p1, p2, p3, p4 = 0.25, 0.25, 0.25, 0.25
        
        total = p1 + p2 + p3 + p4
        if total == 0:
            return 0.1  # Default fallback
        
        # Normalize probabilities
        weights = [p1 / total, p2 / total, p3 / total, p4 / total]
        
        # Weighted average of 1-year symptom probability from sojourn CDFs
        weighted_symptom_prob = 0.0
        
        for stage_idx, weight in enumerate(weights):
            if stage_idx < len(self.params.sojourn_cdf):
                stage_cdf = self.params.sojourn_cdf[stage_idx]
                if len(stage_cdf) > 0:
                    # CDF[0] = P(symptoms by year 1)
                    weighted_symptom_prob += weight * stage_cdf[0]
        
        return weighted_symptom_prob if weighted_symptom_prob > 0 else 0.1
    
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
    
    def _compute_matrix_for_age(self, age: int, risk_class: int = -1) -> np.ndarray:
        """
        Compute the 12x12 transition matrix for a given age and risk class.
        
        States:
            0: Healthy
            1-6: Polyp stages 1-6
            7-10: Cancer stages I-IV (undetected)
            11: Dead
        
        Args:
            age: Current age
            risk_class: Risk class index (0 to n_risk_classes-1). -1 for average.
        """
        T = np.zeros((self.n_states, self.n_states))
        
        # Get common probabilities
        p_death_bg = self._get_background_mortality(age)
        p_polyp = self._get_polyp_incidence(age, risk_class)
        p_direct_cancer = self._get_direct_cancer_rate(age)
        
        # Clip probabilities to valid range
        def clip(p): 
            return max(0.0, min(1.0, p))
        
        p_death_bg = clip(p_death_bg)
        p_polyp = clip(p_polyp)
        p_direct_cancer = clip(p_direct_cancer)
        
        # Cancer stage distribution for direct cancer (based on frac_stage params)
        cancer_stage_dist = self._get_cancer_stage_distribution(age)
        
        # === State 0: Healthy ===
        # Can: stay healthy, develop polyp (stage 1), develop direct cancer, die
        p_stay_healthy = max(0.0, 1 - p_polyp - p_direct_cancer - p_death_bg)
        
        T[0, 0] = p_stay_healthy          # Stay healthy
        T[0, 1] = p_polyp                  # Develop polyp stage 1
        # Direct cancer - distribute across cancer stages I-IV
        for cs in range(4):
            T[0, 7 + cs] = p_direct_cancer * cancer_stage_dist[cs]
        T[0, 11] = p_death_bg              # Background death
        
        self._normalize_row(T, 0)
        
        # === States 1-6: Polyp stages ===
        for polyp_stage in range(1, 7):  # Polyp stages 1-6
            state_idx = polyp_stage  # State index equals polyp stage
            
            p_prog = self._get_polyp_progression_by_stage(age, polyp_stage)
            p_fast = self._get_fast_cancer_rate_by_stage(polyp_stage)
            p_heal = self._get_healing_rate_by_stage(polyp_stage)
            
            p_prog = clip(p_prog)
            p_fast = clip(p_fast)
            p_heal = clip(p_heal)
            
            # Calculate stay probability
            p_stay = max(0.0, 1 - p_prog - p_fast - p_heal - p_death_bg)
            
            T[state_idx, state_idx] = p_stay  # Stay in same stage
            
            # Healing: regress to previous stage (or healthy if stage 1)
            if polyp_stage == 1:
                T[state_idx, 0] = p_heal  # Regress to healthy
            else:
                T[state_idx, polyp_stage - 1] = p_heal  # Regress to previous stage
            
            # Progression
            if polyp_stage < 6:
                T[state_idx, polyp_stage + 1] = p_prog  # Progress to next polyp stage
            else:
                # Stage 6 progresses to cancer - distribute across stages
                for cs in range(4):
                    T[state_idx, 7 + cs] = p_prog * cancer_stage_dist[cs]
            
            # Fast cancer - distribute across cancer stages
            for cs in range(4):
                T[state_idx, 7 + cs] += p_fast * cancer_stage_dist[cs]
            
            T[state_idx, 11] = p_death_bg  # Background death
            
            self._normalize_row(T, state_idx)
        
        # === States 7-10: Cancer stages I-IV (undetected) ===
        for cancer_stage in range(1, 5):  # Cancer stages I-IV
            state_idx = 6 + cancer_stage  # States 7, 8, 9, 10
            
            p_cancer_death = self._get_cancer_mortality_by_stage(age, cancer_stage)
            p_cancer_death = clip(p_cancer_death)
            
            p_death_total = min(p_cancer_death + p_death_bg, 1.0)
            p_stay = max(0.0, 1 - p_death_total)
            
            T[state_idx, state_idx] = p_stay  # Stay in cancer state
            T[state_idx, 11] = p_death_total  # Die (cancer + background)
            
            self._normalize_row(T, state_idx)
        
        # === State 11: Dead ===
        # Absorbing state
        T[11, 11] = 1.0
        
        return T
    
    def _get_cancer_stage_distribution(self, age: int) -> list:
        """Get probability distribution across cancer stages I-IV at given age."""
        age_idx = min(int(age / 5), len(self.params.frac_stage1) - 1) if hasattr(self.params, 'frac_stage1') else 0
        
        if age_idx >= 0:
            p1 = self.params.frac_stage1[age_idx] if hasattr(self.params, 'frac_stage1') and age_idx < len(self.params.frac_stage1) else 0.25
            p2 = self.params.frac_stage2[age_idx] if hasattr(self.params, 'frac_stage2') and age_idx < len(self.params.frac_stage2) else 0.25
            p3 = self.params.frac_stage3[age_idx] if hasattr(self.params, 'frac_stage3') and age_idx < len(self.params.frac_stage3) else 0.25
            p4 = self.params.frac_stage4[age_idx] if hasattr(self.params, 'frac_stage4') and age_idx < len(self.params.frac_stage4) else 0.25
        else:
            p1, p2, p3, p4 = 0.25, 0.25, 0.25, 0.25
        
        total = p1 + p2 + p3 + p4
        if total > 0:
            return [p1/total, p2/total, p3/total, p4/total]
        return [0.25, 0.25, 0.25, 0.25]
    
    def _get_cancer_mortality_by_stage(self, age: int, cancer_stage: int) -> float:
        """Get cancer mortality rate for specific cancer stage (1-4)."""
        if cancer_stage < 1 or cancer_stage > 4:
            return 0.05
        
        age_group = 0
        for i, threshold in enumerate(self.params.os_age_ranges):
            if age >= threshold:
                age_group = i + 1
        age_group = min(age_group, self.params.n_age_groups - 1)
        
        stage_idx = cancer_stage - 1
        idx = stage_idx * self.params.n_age_groups * self.params.num_data_points_per_surv_curve
        idx += age_group * self.params.num_data_points_per_surv_curve
        idx += 1  # 1-year survival
        
        if idx < len(self.params.os_by_gender_age_stage):
            survival = self.params.os_by_gender_age_stage[idx]
            return 1 - survival
        
        # Default mortality rates by stage if data not available
        default_rates = {1: 0.05, 2: 0.10, 3: 0.20, 4: 0.40}
        return default_rates.get(cancer_stage, 0.05)
    
    def _normalize_row(self, T: np.ndarray, row_idx: int):
        """Normalize a row of transition matrix to sum to 1."""
        total = T[row_idx].sum()
        if total > 1:
            T[row_idx] /= total
        elif total < 1:
            T[row_idx, row_idx] += 1 - total  # Add remainder to stay probability
    
    def get_matrix(self, age: int, risk_class: int = 0) -> np.ndarray:
        """
        Get pre-computed transition matrix for given age and risk class.
        
        Args:
            age: Current age
            risk_class: Risk class index (0 to n_risk_classes-1)
        """
        age = max(0, min(age, self.max_age))
        risk_class = max(0, min(risk_class, self.n_risk_classes - 1))
        return self.transition_matrices[age, risk_class]
    
    def print_matrix(self, age: int, risk_class: int = 0):
        """Print transition matrix for debugging."""
        T = self.get_matrix(age, risk_class)
        states = ['H', 'P1', 'P2', 'P3', 'P4', 'P5', 'P6', 'CI', 'CII', 'CIII', 'CIV', 'D']
        
        print(f"\n=== Transition Matrix at Age {age}, Risk Class {risk_class} ===")
        print(f"    (Risk Multiplier: {self.risk_multipliers[risk_class]:.4f})")
        print(f"States: H=Healthy, P1-P6=Polyp stages, CI-CIV=Cancer stages, D=Dead")
        print("      " + " ".join(f"{s:>6}" for s in states))
        for i, row_name in enumerate(states):
            row_str = " ".join(f"{T[i,j]:6.3f}" for j in range(12))
            print(f"{row_name:>5} {row_str}")
        print(f"Row sums: {[f'{T[i].sum():.3f}' for i in range(12)]}")
    
    def print_risk_class_summary(self):
        """Print summary of risk classes."""
        print(f"\n=== Risk Class Summary (n={self.n_risk_classes}) ===")
        for i in range(self.n_risk_classes):
            print(f"  Class {i}: Multiplier = {self.risk_multipliers[i]:.4f}, "
                  f"Prob = {self.risk_class_probs[i]:.4f}")


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
    
    State Space includes:
    - age: Current age
    - history: Years since last screening (0 = just screened, max_history = never or 10+ years)
    - state: Health state (0-5)
    - risk_class: Individual polyp risk class (0 to n_risk_classes-1)
    - screens_used: Number of screenings used (optional, if max_screens > 0)
    """
    
    def __init__(self, settings_file: str, objective_type: ObjectiveType = ObjectiveType.QALY, 
                 min_interval: int = 1, max_screens: int = 0, n_risk_classes: int = 5):
        self.params = SimulationParameters(settings_file)
        self.n_risk_classes = n_risk_classes
        
        # DP parameters (먼저 설정 - TransitionMatrixCalculator에 필요)
        self.min_age = self.params.opt_min_age
        self.max_age = self.params.opt_max_age
        
        # min_age를 전달하여 계산 범위 제한
        self.trans_calc = TransitionMatrixCalculator(self.params, n_risk_classes=n_risk_classes, min_age=self.min_age)
        self.objective_type = objective_type
        self.terminal_age = 100
        self.max_history = 10  # Max years since last screening
        self.min_screen_interval = min_interval  # 최소 검진 간격 (년)
        self.max_screens = max_screens  # 총 검진 횟수 제한 (0 = 무제한)
        
        # Risk class information from transition calculator
        self.risk_multipliers = self.trans_calc.risk_multipliers
        self.risk_class_probs = self.trans_calc.risk_class_probs
        
        # Value & Policy tables with risk_class dimension
        if self.max_screens > 0:
            # 5D: V[age, history, state, risk_class, screens_used]
            # Policy[age, history, risk_class, screens_used] = optimal action
            self.V = np.zeros((self.terminal_age + 2, self.max_history + 1, 12, 
                               self.n_risk_classes, self.max_screens + 1))
            self.Policy = np.zeros((self.terminal_age + 2, self.max_history + 1, 
                                    self.n_risk_classes, self.max_screens + 1), dtype=int)
        else:
            # 4D: V[age, history, state, risk_class]
            # Policy[age, history, risk_class] = optimal action
            self.V = np.zeros((self.terminal_age + 2, self.max_history + 1, 12, self.n_risk_classes))
            self.Policy = np.zeros((self.terminal_age + 2, self.max_history + 1, self.n_risk_classes), dtype=int)
        
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
        목적 함수별 보상 가중치 설정 (12개 상태)
        """
        # 각 목적 함수별 상태별 즉시 보상/비용
        # States: 0=Healthy, 1-6=Polyp stages, 7-10=Cancer I-IV, 11=Dead
        
        if self.objective_type == ObjectiveType.CRC_INCIDENCE:
            # 암 발생 시 큰 페널티, 용종 발견 시 작은 보상
            self.state_rewards = {
                0: 0.0,       # Healthy
                1: -0.05,     # Polyp Stage 1
                2: -0.1,      # Polyp Stage 2
                3: -0.15,     # Polyp Stage 3
                4: -0.2,      # Polyp Stage 4
                5: -0.3,      # Polyp Stage 5 (Advanced)
                6: -0.5,      # Polyp Stage 6 (Advanced)
                7: -10.0,     # Cancer Stage I
                8: -10.0,     # Cancer Stage II
                9: -10.0,     # Cancer Stage III
                10: -10.0,    # Cancer Stage IV
                11: 0.0       # Dead
            }
            self.screen_benefit = 5.0   # 용종 제거로 암 예방 보상
            
        elif self.objective_type == ObjectiveType.CRC_MORTALITY:
            # 암 사망 시 큰 페널티 (병기별 차등)
            self.state_rewards = {
                0: 0.0,
                1: 0.0, 2: 0.0, 3: 0.0, 4: -0.1, 5: -0.2, 6: -0.3,
                7: -2.0,      # Cancer I (낮은 사망률)
                8: -4.0,      # Cancer II
                9: -8.0,      # Cancer III
                10: -15.0,    # Cancer IV (높은 사망률)
                11: -50.0     # Death
            }
            self.screen_benefit = 10.0
            
        elif self.objective_type == ObjectiveType.LIFE_YEARS_LOST:
            # 생존연수 기반 보상
            self.state_rewards = {
                0: 1.0,       # Healthy - 1 life year
                1: 0.99, 2: 0.98, 3: 0.97, 4: 0.96, 5: 0.94, 6: 0.92,
                7: 0.85,      # Cancer I
                8: 0.75,      # Cancer II
                9: 0.55,      # Cancer III
                10: 0.30,     # Cancer IV
                11: 0.0       # Dead
            }
            self.screen_benefit = 2.0
            
        elif self.objective_type == ObjectiveType.OVERALL_COSTS:
            # 비용 최소화 (병기별 치료비 반영)
            self.state_rewards = {
                0: 0.0,
                1: 0.0, 2: 0.0, 3: 0.0, 4: 0.0, 5: 0.0, 6: 0.0,
                7: -self.cost_cancer_init * 1.0 / 1000,   # Stage I
                8: -self.cost_cancer_init * 1.3 / 1000,   # Stage II
                9: -self.cost_cancer_init * 1.6 / 1000,   # Stage III
                10: -self.cost_cancer_init * 2.0 / 1000,  # Stage IV
                11: 0.0
            }
            self.screen_benefit = 0.0
            
        elif self.objective_type == ObjectiveType.QALY:
            # QALY 기반 (상태별 유틸리티 × 생존연수)
            self.state_rewards = None  # Use QALYCalculator dynamically
            self.screen_benefit = 0.5
            
        elif self.objective_type == ObjectiveType.PARETO:
            # Pareto: 여러 목적 함수의 가중합
            self.state_rewards = None
            self.screen_benefit = 1.0
    
    def solve(self):
        """Run backward induction to find optimal policy."""
        print("\n" + "=" * 60)
        print("  TRUE DYNAMIC PROGRAMMING OPTIMIZER")
        print(f"  Objective: {self.objective_type.name}")
        print(f"  Risk Classes: {self.n_risk_classes}")
        if self.max_screens > 0:
            print(f"  Max Screenings: {self.max_screens}")
        print(f"  Min Interval: {self.min_screen_interval} years")
        print("  Method: Backward Induction with Analytical Transition Matrix")
        print("=" * 60)
        
        # Print risk class summary
        self.trans_calc.print_risk_class_summary()
        
        print(f"\n>>> Starting Backward Induction ({self.objective_type.name})...")
        
        if self.objective_type == ObjectiveType.PARETO:
            self._solve_pareto()
        elif self.max_screens > 0:
            self._solve_with_screen_limit()
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
    
    def _get_state_prior(self, age: int) -> dict:
        """
        나이별 상태 사전 확률 분포 반환 (12개 상태)
        
        Args:
            age: 현재 나이
        
        Returns:
            각 상태의 확률 딕셔너리
        """
        # 기본적으로 대부분 Healthy, 나이가 들수록 Polyp/Cancer 확률 증가
        base_polyp_rate = min(0.001 * (age - 30), 0.05) if age > 30 else 0.0
        base_cancer_rate = min(0.0001 * (age - 40), 0.005) if age > 40 else 0.0
        
        prior = {
            0: 1.0,  # Will be normalized
            1: base_polyp_rate * 0.3,
            2: base_polyp_rate * 0.25,
            3: base_polyp_rate * 0.2,
            4: base_polyp_rate * 0.1,
            5: base_polyp_rate * 0.1,
            6: base_polyp_rate * 0.05,
            7: base_cancer_rate * 0.4,
            8: base_cancer_rate * 0.3,
            9: base_cancer_rate * 0.2,
            10: base_cancer_rate * 0.1,
            11: 0.0  # Dead
        }
        
        # Normalize
        total = sum(prior.values())
        if total > 0:
            for s in prior:
                prior[s] /= total
        
        return prior
    
    def _solve_single_objective(self):
        """단일 목적 함수에 대한 DP 해결 (12개 상태, risk class 차원 포함)"""
        gamma = 1.0 / (1 + self.discount_rate) if self.discount_rate > 0 else 1.0
        n_states = 12  # Healthy + Polyp(1-6) + Cancer(I-IV) + Dead
        
        # QALY 모드에서는 WTP_THRESHOLD 사용
        if self.objective_type == ObjectiveType.QALY:
            value_scale = QALYCalculator.WTP_THRESHOLD
        else:
            value_scale = self.val_life_year
        
        # Polyp stage별 검출률 (stages 1-6)
        polyp_sens = [0.50, 0.60, 0.70, 0.80, 0.90, 0.95]
        cancer_sens = 0.95  # 암 검출률
        
        # Backward induction
        for t in range(self.terminal_age - 1, self.min_age - 1, -1):
            for r in range(self.n_risk_classes):
                T = self.trans_calc.get_matrix(t, risk_class=r)
                
                for h in range(self.max_history + 1):
                    next_h_wait = min(h + 1, self.max_history)
                    next_h_screen = 0
                    
                    # === Action 0: WAIT ===
                    ev_wait = np.zeros(n_states)
                    for s in range(n_states):
                        expected_future = sum(T[s, ns] * self.V[t+1, next_h_wait, ns, r] for ns in range(n_states))
                        immediate = self._get_immediate_reward(s, t, action=0)
                        ev_wait[s] = immediate + gamma * expected_future
                    
                    # === Action 1: SCREEN ===
                    ev_screen = np.zeros(n_states)
                    
                    # 건강 상태(0)에서의 미래 가치
                    future_healthy = sum(T[0, ns] * self.V[t+1, next_h_screen, ns, r] for ns in range(n_states))
                    
                    # S=0 (Healthy): 검진 비용만 발생
                    immediate_0 = self._get_immediate_reward(0, t, action=1)
                    ev_screen[0] = immediate_0 - self.cost_colo + gamma * future_healthy
                    
                    # S=1-6 (Polyp Stages): 발견 시 제거 → Healthy로 전환
                    for polyp_stage in range(1, 7):
                        state_idx = polyp_stage
                        sens = polyp_sens[polyp_stage - 1]
                        
                        future_polyp = sum(T[state_idx, ns] * self.V[t+1, next_h_screen, ns, r] for ns in range(n_states))
                        
                        # 발견 시: Healthy로 전환
                        v_cured = self._get_immediate_reward(0, t, action=1) + gamma * future_healthy
                        # 미발견 시: 현재 stage 유지
                        v_missed = self._get_immediate_reward(state_idx, t, action=1) + gamma * future_polyp
                        
                        ev_screen[state_idx] = -self.cost_colo - self.cost_colo_polyp + (
                            sens * v_cured + (1 - sens) * v_missed
                        )
                    
                    # S=7-10 (Cancer I-IV): 발견 시 조기 치료 효과
                    for cancer_stage in range(1, 5):
                        state_idx = 6 + cancer_stage  # States 7, 8, 9, 10
                        
                        future_cancer = sum(T[state_idx, ns] * self.V[t+1, next_h_screen, ns, r] for ns in range(n_states))
                        
                        # 발견 시: 조기 치료로 사망률 감소 (same state but with treatment benefit)
                        # 발견된 암의 미래 가치는 미발견 암보다 약간 나음
                        treatment_bonus = value_scale * 0.1 * (5 - cancer_stage)  # 병기가 낮을수록 이득
                        
                        v_detected = self._get_immediate_reward(state_idx, t, action=1) + gamma * future_cancer + treatment_bonus
                        v_missed = self._get_immediate_reward(state_idx, t, action=1) + gamma * future_cancer
                        
                        ev_screen[state_idx] = -self.cost_colo - self.cost_cancer_init + (
                            cancer_sens * v_detected + (1 - cancer_sens) * v_missed
                        )
                    
                    # S=11 (Dead): 검진 의미 없음
                    ev_screen[11] = ev_wait[11]
                    
                    # --- Optimal Action Selection ---
                    prior = self._get_state_prior(t)
                    
                    # Polyp/Cancer 상태들에 대한 가중 기대값 (Dead 제외)
                    actionable_states = list(range(11))  # 0-10
                    denom = sum(prior.get(s, 0) for s in actionable_states)
                    if denom > 0:
                        E_wait = sum(prior.get(s, 0) / denom * ev_wait[s] for s in actionable_states)
                        E_screen = sum(prior.get(s, 0) / denom * ev_screen[s] for s in actionable_states)
                    else:
                        E_wait = ev_wait[0]
                        E_screen = ev_screen[0]
                    
                    # 최소 검진 간격 제약
                    if h < self.min_screen_interval:
                        self.Policy[t, h, r] = 0
                        for s in range(n_states):
                            self.V[t, h, s, r] = ev_wait[s]
                    elif E_screen > E_wait:
                        self.Policy[t, h, r] = 1
                        for s in range(n_states):
                            self.V[t, h, s, r] = ev_screen[s]
                    else:
                        self.Policy[t, h, r] = 0
                        for s in range(n_states):
                            self.V[t, h, s, r] = ev_wait[s]
                    
                    # Debug output
                    if h == 10 and t in [50, 60, 70] and r in [0, self.n_risk_classes // 2, self.n_risk_classes - 1]:
                        diff = E_screen - E_wait
                        print(f"[Age {t}, Risk={r}] Wait: {E_wait:,.0f} vs Screen: {E_screen:,.0f} | Diff: {diff:,.0f}")
    
    def _solve_with_screen_limit(self):
        """총 검진 횟수 제한이 있는 경우의 DP 해결 (12개 상태, risk class 포함)"""
        gamma = 1.0 / (1 + self.discount_rate) if self.discount_rate > 0 else 1.0
        n_states = 12
        
        print(f"  (Screen limit: {self.max_screens}, Risk classes: {self.n_risk_classes})")
        
        # Polyp stage별 검출률
        polyp_sens = [0.50, 0.60, 0.70, 0.80, 0.90, 0.95]
        cancer_sens = 0.95
        
        if self.objective_type == ObjectiveType.QALY:
            value_scale = QALYCalculator.WTP_THRESHOLD
        else:
            value_scale = self.val_life_year
        
        for t in range(self.terminal_age - 1, self.min_age - 1, -1):
            for r in range(self.n_risk_classes):
                T = self.trans_calc.get_matrix(t, risk_class=r)
                
                for n in range(self.max_screens + 1):
                    screens_remaining = self.max_screens - n
                    
                    for h in range(self.max_history + 1):
                        next_h_wait = min(h + 1, self.max_history)
                        next_h_screen = 0
                        
                        # --- Action 0: WAIT ---
                        ev_wait = np.zeros(n_states)
                        for s in range(n_states):
                            expected_future = sum(T[s, ns] * self.V[t+1, next_h_wait, ns, r, n] for ns in range(n_states))
                            immediate = self._get_immediate_reward(s, t, action=0)
                            ev_wait[s] = immediate + gamma * expected_future
                        
                        # --- Action 1: SCREEN ---
                        ev_screen = np.zeros(n_states)
                        can_screen = (screens_remaining > 0) and (h >= self.min_screen_interval)
                        
                        if can_screen:
                            n_after_screen = n + 1
                            future_healthy = sum(T[0, ns] * self.V[t+1, next_h_screen, ns, r, n_after_screen] for ns in range(n_states))
                            
                            # S=0 (Healthy)
                            immediate_0 = self._get_immediate_reward(0, t, action=1)
                            ev_screen[0] = immediate_0 - self.cost_colo + gamma * future_healthy
                            
                            # S=1-6 (Polyp Stages)
                            for polyp_stage in range(1, 7):
                                sens = polyp_sens[polyp_stage - 1]
                                future_polyp = sum(T[polyp_stage, ns] * self.V[t+1, next_h_screen, ns, r, n_after_screen] for ns in range(n_states))
                                v_cured = self._get_immediate_reward(0, t, action=1) + gamma * future_healthy
                                v_missed = self._get_immediate_reward(polyp_stage, t, action=1) + gamma * future_polyp
                                ev_screen[polyp_stage] = -self.cost_colo - self.cost_colo_polyp + (
                                    sens * v_cured + (1 - sens) * v_missed
                                )
                            
                            # S=7-10 (Cancer I-IV)
                            for cancer_stage in range(1, 5):
                                state_idx = 6 + cancer_stage
                                future_cancer = sum(T[state_idx, ns] * self.V[t+1, next_h_screen, ns, r, n_after_screen] for ns in range(n_states))
                                treatment_bonus = value_scale * 0.1 * (5 - cancer_stage)
                                v_detected = self._get_immediate_reward(state_idx, t, action=1) + gamma * future_cancer + treatment_bonus
                                v_missed = self._get_immediate_reward(state_idx, t, action=1) + gamma * future_cancer
                                ev_screen[state_idx] = -self.cost_colo - self.cost_cancer_init + (
                                    cancer_sens * v_detected + (1 - cancer_sens) * v_missed
                                )
                            
                            ev_screen[11] = ev_wait[11]
                        else:
                            ev_screen = ev_wait.copy()
                        
                        # --- Optimal Action Selection ---
                        prior = self._get_state_prior(t)
                        actionable_states = list(range(11))
                        denom = sum(prior.get(s, 0) for s in actionable_states)
                        if denom > 0:
                            E_wait = sum(prior.get(s, 0) / denom * ev_wait[s] for s in actionable_states)
                            E_screen = sum(prior.get(s, 0) / denom * ev_screen[s] for s in actionable_states)
                        else:
                            E_wait = ev_wait[0]
                            E_screen = ev_screen[0]
                        
                        if can_screen and E_screen > E_wait:
                            self.Policy[t, h, r, n] = 1
                            for s in range(n_states):
                                self.V[t, h, s, r, n] = ev_screen[s]
                        else:
                            self.Policy[t, h, r, n] = 0
                            for s in range(n_states):
                                self.V[t, h, s, r, n] = ev_wait[s]
                        
                        if h == 10 and n == 0 and t in [50, 60, 70] and r in [0, self.n_risk_classes - 1]:
                            diff = E_screen - E_wait if can_screen else 0
                            print(f"[Age {t}, Risk={r}, screens=0] Wait: {E_wait:,.0f} vs Screen: {E_screen:,.0f} | Diff: {diff:,.0f}")
    
    def _solve_pareto(self):
        """
        Pareto 최적화: 여러 목적 함수의 가중합 (risk class 포함)
        
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
            
            # 초기화 (with risk class dimension)
            self.V = np.zeros((self.terminal_age + 2, self.max_history + 1, 12, self.n_risk_classes))
            
            # 원래 목적 함수 복원
            self.objective_type = original_type
        
        # 가중합을 사용한 최종 정책 결정
        print(">>> Combining sub-objectives with weights...")
        
        for t in range(self.min_age, self.terminal_age):
            for r in range(self.n_risk_classes):
                for h in range(self.max_history + 1):
                    # 각 목적 함수의 정책 투표
                    votes_screen = 0.0
                    votes_wait = 0.0
                    
                    for obj_type in sub_objectives:
                        weight = self.pareto_weights[obj_type]
                        if sub_policies[obj_type][t, h, r] == 1:
                            votes_screen += weight
                        else:
                            votes_wait += weight
                    
                    # 다수결 (가중)
                    if votes_screen > votes_wait:
                        self.Policy[t, h, r] = 1
                    else:
                        self.Policy[t, h, r] = 0
                    
                    # 가중 평균 가치 함수
                    for s in range(12):
                        weighted_value = sum(
                            self.pareto_weights[obj_type] * sub_values[obj_type][t, h, s, r]
                            for obj_type in sub_objectives
                        )
                        self.V[t, h, s, r] = weighted_value
        
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
        """Print the optimal screening policy (with risk class support)."""
        print("\n" + "=" * 70)
        print(f"   OPTIMAL SCREENING POLICY")
        print(f"   Objective: {self.objective_type.name}")
        print(f"   Risk Classes: {self.n_risk_classes}")
        if self.max_screens > 0:
            print(f"   Max Screenings: {self.max_screens}")
        print("=" * 70)
        
        # Print risk class summary
        print("\n Risk Multipliers by Class:")
        for r in range(self.n_risk_classes):
            print(f"   Class {r}: {self.risk_multipliers[r]:.4f}")
        
        if self.max_screens > 0:
            # 5D policy: show policy for each risk class starting with 0 screens used
            print("\n" + "-" * 70)
            print(" Policy by Risk Class (h=10+, screens_used=0):")
            print(" Age |" + "".join(f" R{r} " for r in range(self.n_risk_classes)))
            print("-----|" + "----" * self.n_risk_classes)
            for t in range(40, 81, 5):
                row = "|".join(" S " if self.Policy[t, 10, r, 0] == 1 else " . " 
                               for r in range(self.n_risk_classes))
                print(f" {t:3d} |{row}")
        else:
            # 4D policy: show policy for each risk class
            print("\n" + "-" * 70)
            print(" Policy by Risk Class (h=10+ years since last screening):")
            print(" Age |" + "".join(f" R{r} " for r in range(self.n_risk_classes)))
            print("-----|" + "----" * self.n_risk_classes)
            for t in range(40, 81, 5):
                row = "|".join(" S " if self.Policy[t, 10, r] == 1 else " . " 
                               for r in range(self.n_risk_classes))
                print(f" {t:3d} |{row}")
            
            # Detailed matrix for middle risk class
            mid_r = self.n_risk_classes // 2
            print(f"\n Policy Matrix (Risk Class {mid_r}, rows=ages, cols=history):")
            print("    " + "".join(f"{h:2d}" for h in range(11)))
            for t in range(40, 81, 5):
                row = "".join("S " if self.Policy[t, h, mid_r] == 1 else ". " for h in range(11))
                print(f"{t:2d}  {row}")
        
        print(" (S=Screen, .=Wait, R0=Low risk, R{high}=High risk)".format(high=self.n_risk_classes-1))
        
        # 검진 권고 요약 출력 (각 risk class별)
        print("\n Summary by Risk Class:")
        for r in range(self.n_risk_classes):
            if self.max_screens > 0:
                screen_ages = [t for t in range(40, 81) if self.Policy[t, 10, r, 0] == 1]
            else:
                screen_ages = [t for t in range(40, 81) if self.Policy[t, 10, r] == 1]
            
            if screen_ages:
                print(f"   Risk {r} (mult={self.risk_multipliers[r]:.2f}): Screen at ages {min(screen_ages)}-{max(screen_ages)}")
            else:
                print(f"   Risk {r} (mult={self.risk_multipliers[r]:.2f}): No screening recommended")
    
    def save_policy(self, output_dir: str = "policy"):
        """
        정책을 파일로 저장 (with risk class support)
        
        Args:
            output_dir: 출력 디렉토리 (기본값: 'policy')
        """
        import os
        from datetime import datetime
        
        # 디렉토리 생성
        os.makedirs(output_dir, exist_ok=True)
        
        # 타임스탬프
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        
        # 파일명 생성
        base_name = f"{self.objective_type.name}"
        if self.max_screens > 0:
            base_name += f"_max{self.max_screens}"
        base_name += f"_int{self.min_screen_interval}"
        base_name += f"_risk{self.n_risk_classes}"
        
        # NPY 파일로 저장 (전체 배열)
        npy_path = os.path.join(output_dir, f"{base_name}_{timestamp}.npy")
        np.save(npy_path, self.Policy)
        print(f"\n>>> Policy saved: {npy_path}")
        
        # CSV 파일로 저장 (읽기 쉬운 형식)
        csv_path = os.path.join(output_dir, f"{base_name}_{timestamp}.csv")
        with open(csv_path, 'w') as f:
            if self.max_screens > 0:
                # 5D: 모든 risk_class와 screens_used 값 포함
                f.write("age,history,risk_class,screens_used,action\n")
                for t in range(40, 81):  # 40-80세
                    for h in range(self.max_history + 1):
                        for r in range(self.n_risk_classes):
                            for n in range(self.max_screens + 1):
                                action = self.Policy[t, h, r, n]
                                f.write(f"{t},{h},{r},{n},{action}\n")
            else:
                # 4D: risk_class 포함
                f.write("age,history,risk_class,action\n")
                for t in range(40, 81):  # 40-80세
                    for h in range(self.max_history + 1):
                        for r in range(self.n_risk_classes):
                            action = self.Policy[t, h, r]
                            f.write(f"{t},{h},{r},{action}\n")
        
        print(f">>> Policy CSV saved: {csv_path}")
        
        # Risk multipliers 저장
        risk_path = os.path.join(output_dir, f"{base_name}_{timestamp}_risk_classes.csv")
        with open(risk_path, 'w') as f:
            f.write("risk_class,multiplier,probability\n")
            for r in range(self.n_risk_classes):
                f.write(f"{r},{self.risk_multipliers[r]:.6f},{self.risk_class_probs[r]:.6f}\n")
        print(f">>> Risk classes saved: {risk_path}")
        
        # 요약 정보 저장
        info_path = os.path.join(output_dir, f"{base_name}_{timestamp}_info.txt")
        with open(info_path, 'w', encoding='utf-8') as f:
            f.write(f"Objective: {self.objective_type.name}\n")
            f.write(f"Min Interval: {self.min_screen_interval} years\n")
            f.write(f"Max Screens: {self.max_screens if self.max_screens > 0 else 'Unlimited'}\n")
            f.write(f"Risk Classes: {self.n_risk_classes}\n")
            f.write(f"Age Range: {self.min_age}-{self.max_age}\n")
            f.write(f"Max History: {self.max_history}\n")
            f.write(f"Generated: {datetime.now().isoformat()}\n")
            
            # 요약 (각 risk class별)
            f.write("\nScreen ages by risk class (h=10, n=0):\n")
            for r in range(self.n_risk_classes):
                if self.max_screens > 0:
                    screen_ages = [t for t in range(40, 81) if self.Policy[t, 10, r, 0] == 1]
                else:
                    screen_ages = [t for t in range(40, 81) if self.Policy[t, 10, r] == 1]
                f.write(f"  Risk {r} (mult={self.risk_multipliers[r]:.4f}): {screen_ages}\n")
        
        print(f">>> Policy info saved: {info_path}")
        
        return npy_path, csv_path, info_path


def main():
    """Main entry point for true DP optimization with interactive input."""
    print("\n" + "=" * 70)
    print("  COLORECTAL CANCER SCREENING OPTIMIZATION")
    print("  True Dynamic Programming with Known Transition Probabilities")
    print("=" * 70)
    
    # 목적 함수 선택
    print("\n[목적 함수 선택]")
    print("  1 = CRC_INCIDENCE   - 대장암 발생률 최소화")
    print("  2 = CRC_MORTALITY   - 대장암 사망률 최소화")
    print("  3 = LIFE_YEARS_LOST - 손실 생존연수 최소화")
    print("  4 = OVERALL_COSTS   - 전체 비용 최소화")
    print("  5 = QALY            - Quality-Adjusted Life Years 최대화 [기본값]")
    print("  6 = PARETO          - 다중 목적 최적해")
    
    objective_input = input("목적 함수 번호 입력 (기본값=5): ").strip()
    objective_num = int(objective_input) if objective_input else 5
    if objective_num not in [1, 2, 3, 4, 5, 6]:
        print(f"잘못된 입력. 기본값 5(QALY) 사용")
        objective_num = 5
    
    # Settings 파일 경로
    settings_input = input("\nSettings 파일 경로 (기본값=settings.ini): ").strip()
    settings_file = settings_input if settings_input else "settings.ini"
    
    # 최소 검진 간격
    interval_input = input("\n최소 검진 간격 (년, 기본값=3): ").strip()
    min_interval = int(interval_input) if interval_input else 3
    
    # 총 검진 횟수 제한
    max_screens_input = input("\n총 검진 횟수 제한 (0=무제한, 기본값=0): ").strip()
    max_screens = int(max_screens_input) if max_screens_input else 0
    
    # 위험도 클래스 수
    risk_classes_input = input("\n위험도 클래스 수 (기본값=2): ").strip()
    n_risk_classes = int(risk_classes_input) if risk_classes_input else 2
    
    # Map integer to ObjectiveType enum
    objective_map = {
        1: ObjectiveType.CRC_INCIDENCE,
        2: ObjectiveType.CRC_MORTALITY,
        3: ObjectiveType.LIFE_YEARS_LOST,
        4: ObjectiveType.OVERALL_COSTS,
        5: ObjectiveType.QALY,
        6: ObjectiveType.PARETO
    }
    
    objective_type = objective_map[objective_num]
    
    print("\n" + "=" * 70)
    print(f"  Objective: {objective_type.name}")
    print(f"  Settings: {settings_file}")
    print(f"  Min Interval: {min_interval} years")
    print(f"  Risk Classes: {n_risk_classes}")
    if max_screens > 0:
        print(f"  Max Screenings: {max_screens}")
    print("=" * 70)
    
    dp = TrueDPOptimizer(settings_file, objective_type=objective_type, 
                         min_interval=min_interval, max_screens=max_screens,
                         n_risk_classes=n_risk_classes)
    dp.solve()
    dp.print_optimal_policy()
    dp.save_policy()
    
    return dp


if __name__ == '__main__':
    main()
