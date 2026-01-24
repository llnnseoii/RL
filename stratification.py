"""
Stratification 모듈: 인구 계층화 (고위험군/저위험군 분할)
C++ Stratification.cpp와 동일한 기능 제공
"""
import numpy as np
from scipy import optimize
import configparser

class Stratification:
    """
    개인별 리스크 팩터를 기반으로 인구를 고위험군/저위험군으로 분할
    """
    
    def __init__(self, ini_file=None):
        """
        Args:
            ini_file: stratification.ini 파일 경로 (선택사항)
        """
        self.target_fraction = 0.3  # 고위험군 목표 비율
        self.target_fold_change = 2.0  # 발생률 차이 목표 배수
        self.tolerance_fraction = 0.05  # 비율 허용 오차
        self.tolerance_fold = 0.3  # 배수 허용 오차
        
        if ini_file:
            self._load_ini(ini_file)
    
    def _load_ini(self, ini_file):
        """stratification.ini 파일 로드"""
        config = configparser.ConfigParser()
        config.read(ini_file)
        
        if 'goal' in config:
            self.target_fraction = float(config['goal'].get('populationFraction', 0.3))
            self.target_fold_change = float(config['goal'].get('foldChange', 2.0))
            self.tolerance_fraction = float(config['goal'].get('tolerancePopulationFraction', 0.05))
            self.tolerance_fold = float(config['goal'].get('toleranceFoldChange', 0.3))
    
    def stratify(self, population, rng=None):
        """
        인구를 리스크 기반으로 계층화
        
        Args:
            population: Person 객체 리스트
            rng: Random number generator (선택사항)
        
        Returns:
            tuple: (strata, success, actual_fraction, actual_fold_change)
                - strata: 각 개인의 그룹 번호 (0=저위험, 1=고위험)
                - success: 목표 달성 여부
                - actual_fraction: 실제 고위험군 비율
                - actual_fold_change: 실제 발생률 차이 배수
        """
        if not population:
            return [], False, 0.0, 0.0
        
        if rng is None:
            rng = np.random.default_rng()
        
        N = len(population)
        
        # 1. 개인별 리스크 팩터 및 암 발생 여부 수집
        individual_risks = []
        detected_cancers = []
        random_vals = []
        
        for p in population:
            individual_risks.append(p.risk_factor)
            # 발견된 암 개수 (실제 발생 여부)
            num_cancers = len([c for c in p.cancers if c.age_developed < p.death_age])
            detected_cancers.append(num_cancers)
            random_vals.append(rng.random())
        
        individual_risks = np.array(individual_risks)
        detected_cancers = np.array(detected_cancers)
        random_vals = np.array(random_vals)
        
        max_IR = np.max(individual_risks) if len(individual_risks) > 0 else 1.0
        
        # 2. 최적화로 분할선 찾기
        # 목표: (a, b) 값을 찾아 분할선 = a + (b-a) * IR / max_IR
        # 목표 함수: (fraction - target)^2 + (fold_change - target)^2 최소화
        
        def objective(x):
            a, b = x
            threshold = a + (b - a) * individual_risks / max_IR
            
            # 분할: random_val < threshold이면 고위험군
            high_risk_mask = random_vals < threshold
            
            pos = np.sum(high_risk_mask)
            if pos == 0 or pos == N:
                return 1000.0  # 불가능한 분할
            
            detected_canc_pos = np.sum(detected_cancers[high_risk_mask])
            detected_canc_neg = np.sum(detected_cancers[~high_risk_mask])
            
            incidence_low = detected_canc_neg / (N - pos) if (N - pos) > 0 else 0
            incidence_high = detected_canc_pos / pos if pos > 0 else 0
            
            fraction = pos / N
            
            if incidence_low == 0:
                fold_change = 100  # 매우 큰 값
            else:
                if self.target_fold_change > 1.0:
                    fold_change = incidence_low / incidence_high if incidence_high > 0 else 100
                else:
                    fold_change = incidence_high / incidence_low if incidence_low > 0 else 100
            
            # 목표 함수
            error = (fraction - self.target_fraction)**2 + \
                    (fold_change - (1.0 / self.target_fold_change if self.target_fold_change > 1 else self.target_fold_change))**2
            
            return error
        
        # 최적화 실행
        result = optimize.minimize(
            objective,
            x0=[0.3, 0.7],  # 초기값
            bounds=[(0, 1), (0, 1)],
            method='L-BFGS-B'
        )
        
        a_opt, b_opt = result.x
        
        # 3. 최적 값으로 분할
        threshold = a_opt + (b_opt - a_opt) * individual_risks / max_IR
        high_risk_mask = random_vals < threshold
        
        strata = np.zeros(N, dtype=int)
        strata[high_risk_mask] = 1
        
        # 4. 결과 검증
        pos = np.sum(high_risk_mask)
        detected_canc_pos = np.sum(detected_cancers[high_risk_mask])
        detected_canc_neg = np.sum(detected_cancers[~high_risk_mask])
        
        incidence_low = detected_canc_neg / (N - pos) if (N - pos) > 0 else 0
        incidence_high = detected_canc_pos / pos if pos > 0 else 0
        
        actual_fraction = pos / N
        
        if incidence_low > 0:
            if self.target_fold_change > 1.0:
                actual_fold_change = incidence_high / incidence_low
            else:
                actual_fold_change = incidence_low / incidence_high
        else:
            actual_fold_change = 100.0
        
        # 성공 여부 판정
        success = (abs(actual_fraction - self.target_fraction) < self.tolerance_fraction and
                  abs(actual_fold_change - self.target_fold_change) < self.tolerance_fold)
        
        return strata.tolist(), success, actual_fraction, actual_fold_change
    
    def print_stratification_result(self, strata, success, actual_fraction, actual_fold_change):
        """계층화 결과 출력"""
        print(f"\n{'='*60}")
        print(f"  Stratification Result")
        print(f"{'='*60}")
        print(f"Status:              {'SUCCESS' if success else 'FAILED'}")
        print(f"")
        print(f"Target Fraction:     {self.target_fraction:.2%}")
        print(f"Actual Fraction:     {actual_fraction:.2%}")
        print(f"Difference:          {abs(actual_fraction - self.target_fraction):.2%}")
        print(f"")
        print(f"Target Fold Change:  {self.target_fold_change:.2f}x")
        print(f"Actual Fold Change:  {actual_fold_change:.2f}x")
        print(f"Difference:          {abs(actual_fold_change - self.target_fold_change):.2f}x")
        print(f"")
        print(f"High-risk group:     {sum(strata)} people")
        print(f"Low-risk group:      {len(strata) - sum(strata)} people")
        print(f"{'='*60}\n")


def stratify_population_by_strata(population, strata):
    """
    계층화된 인구를 그룹별로 분리
    
    Args:
        population: Person 객체 리스트
        strata: 각 개인의 그룹 번호 리스트
    
    Returns:
        list: [저위험군 리스트, 고위험군 리스트]
    """
    n_strata = max(strata) + 1 if strata else 1
    populations = [[] for _ in range(n_strata)]
    
    for i, stratum in enumerate(strata):
        populations[stratum].append(population[i])
    
    return populations
