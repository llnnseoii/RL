"""
Updated QALY Calculator with UK EQ-5D-5L Data (Gender-specific)

영국 EQ-5D-5L 인구 규준 데이터를 사용한 QALY 계산기
"""

import numpy as np


class UpdatedQALYCalculator:
    """영국 EQ-5D-5L 데이터 기반 (성별 구분)"""
    
    def __init__(self):
        # UK EQ-5D-5L Population Norms
        # Source: Szende et al., 2014 (UK population norms)
        
        # 연령 그룹 중심값
        self.age_points = [16.5, 18.5, 22, 27, 32, 37, 42, 47, 52, 57, 62, 67, 72, 77, 82, 87, 90]
        
        # Female EQ-5D-5L 점수
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
        
        # Male EQ-5D-5L 점수
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
        
        # QALY monetary value
        self.qaly_value_per_year = 50000.0  # $50K/QALY (UK NICE threshold)
        
        # Cancer stage별 utility decrement (문헌 기반)
        self.cancer_utility_loss = {
            0: 0.0,      # Healthy
            1: 0.074,    # Stage I (Teckle et al., 2015)
            2: 0.084,    # Stage II
            3: 0.170,    # Stage III
            4: 0.290,    # Stage IV
        }
    
    def get_qaly_weight(self, age, is_female=True):
        """
        연령과 성별에 따른 EQ-5D weight 반환 (선형 보간)
        
        Args:
            age: 나이
            is_female: 여성 여부 (True/False)
        
        Returns:
            EQ-5D utility score
        """
        scores = self.female_scores if is_female else self.male_scores
        
        # 선형 보간
        if age <= self.age_points[0]:
            return scores[0]
        elif age >= self.age_points[-1]:
            return scores[-1]
        else:
            # 두 점 사이 보간
            for i in range(len(self.age_points) - 1):
                if self.age_points[i] <= age < self.age_points[i+1]:
                    # 선형 보간
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
    
    def get_life_expectancy(self, age, is_female=False):
        """한국 기대여명 (2023년 통계청)"""
        if is_female:
            life_exp_table = {
                20: 86.5, 30: 86.6, 40: 86.7, 50: 87.0, 
                60: 87.8, 70: 89.5, 80: 91.8, 90: 95.0
            }
        else:
            life_exp_table = {
                20: 80.6, 30: 80.7, 40: 80.9, 50: 81.3,
                60: 82.5, 70: 84.8, 80: 88.2, 90: 92.5
            }
        
        for key_age in sorted(life_exp_table.keys()):
            if age <= key_age:
                return life_exp_table[key_age]
        return life_exp_table[max(life_exp_table.keys())]


# ==================== 사용 예시 ====================
if __name__ == "__main__":
    calc = UpdatedQALYCalculator()
    
    print("="*60)
    print("  UK EQ-5D-5L Population Norms (Gender-specific)")
    print("="*60)
    
    # 테스트: 다양한 나이와 성별
    test_cases = [
        (30, False, "30세 남성"),
        (30, True, "30세 여성"),
        (50, False, "50세 남성"),
        (50, True, "50세 여성"),
        (70, False, "70세 남성"),
        (70, True, "70세 여성"),
    ]
    
    print("\n📊 기본 EQ-5D Scores:")
    for age, is_female, desc in test_cases:
        score = calc.get_qaly_weight(age, is_female)
        qaly_value = calc.get_annual_qaly_value(age, is_female)
        print(f"  {desc}: EQ-5D = {score:.3f}, Annual QALY Value = ${qaly_value:,.0f}")
    
    print("\n🏥 암 환자 (50세 여성):")
    for stage in [0, 1, 2, 3, 4]:
        qaly_value = calc.get_annual_qaly_value(50, True, has_cancer=(stage>0), cancer_stage=stage)
        stage_name = "Healthy" if stage == 0 else f"Stage {stage}"
        print(f"  {stage_name}: Annual QALY Value = ${qaly_value:,.0f}")
    
    print("\n📈 성별 차이 (검진 대상 연령):")
    for age in [40, 45, 50, 55, 60, 65, 70]:
        male_score = calc.get_qaly_weight(age, is_female=False)
        female_score = calc.get_qaly_weight(age, is_female=True)
        diff = male_score - female_score
        print(f"  {age}세: Male={male_score:.3f}, Female={female_score:.3f}, Diff={diff:+.3f}")
