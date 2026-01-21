import numpy as np
import time
from parameters import SimulationParameters
from entities import Person

class ProbabilityExtractor:
    def __init__(self, settings_file):
        self.params = SimulationParameters(settings_file)
        
        # 6-State Model 정의
        # 0: Healthy
        # 1: Early Polyp (Stage 1 ~ 4)
        # 2: Advanced Polyp (Stage 5 ~ 6)
        # 3: Undetected Cancer
        # 4: Detected Cancer (증상 발현 or 검진 발견)
        # 5: Dead
        self.n_states = 6
        
        # Transition Matrix 저장소: [나이(0~100)][현재상태][다음상태]
        # 예: transitions[50][0][1] -> 50세에 Healthy였다가 51세에 EarlyPolyp이 된 사람 수
        self.transition_counts = np.zeros((101, self.n_states, self.n_states))
        
        # 나이별 상태별 총 인구수 (정규화용)
        self.state_population = np.zeros((101, self.n_states))

    def _determine_state(self, person, age):
        """
        한 사람(Person)의 특정 나이(age) 시점 상태를 판별하는 함수
        (우선순위: 사망 > 암 > 진행성용종 > 초기용종 > 건강)
        """
        # 1. 사망 여부
        if person.death_age <= age:
            return 5 # Dead

        # 2. 암 여부
        # (주의: Person 객체에는 여러 암이 있을 수 있으나 가장 심각한 것 기준)
        for c in person.cancers:
            if c.age_developed <= age:
                if c.detected: return 4 # Detected Cancer (이미 치료 모드)
                return 3 # Undetected Cancer (아직 모름)

        # 3. 용종 여부
        max_stage = 0
        has_polyp = False
        for p in person.polyps:
            # 이 나이 때 존재했던 용종만 체크
            if p.age_developed <= age < p.age_end:
                has_polyp = True
                if p.stage > max_stage:
                    max_stage = p.stage
        
        if has_polyp:
            # 설정파일의 'advancedPolypStageTransition' 값(보통 5) 기준 분류
            if max_stage >= self.params.adv_polyp_transition:
                return 2 # Advanced Polyp
            else:
                return 1 # Early Polyp

        # 4. 아무것도 없음
        return 0 # Healthy

    def run_extraction(self, n_people=50000):
        print(f"\n[Extraction] Running microsimulation with {n_people} people to learn probabilities...")
        start_time = time.time()
        
        rng = np.random.default_rng(12345) # 고정 시드 (결과 재현성)
        
        # 시뮬레이션 실행 루프
        for i in range(n_people):
            # 1. 한 사람의 인생을 끝까지 시뮬레이션 (검진 없이 자연사)
            p = Person(self.params, rng)
            p.simulate(output=None) # 기록용 Output 객체 필요 없음
            
            # 2. 매년 상태 변화 추적 (20세 ~ 99세)
            # 너무 어린 나이는 불필요하므로 최적화 범위 근처부터 시작 가능하지만
            # 전체 데이터를 위해 20세부터 스캔
            for age in range(20, 100):
                curr_state = self._determine_state(p, age)
                next_state = self._determine_state(p, age + 1)
                
                self.transition_counts[age, curr_state, next_state] += 1
                self.state_population[age, curr_state] += 1
                
                # 이미 죽었으면 그 이후 나이는 루프 불필요 (Dead -> Dead 100%)
                if curr_state == 5:
                    # 남은 나이 구간은 전부 Dead->Dead로 채워질 것이므로 스킵해도 되지만
                    # 통계적 정확성을 위해 데이터가 적은 고령층은 카운팅 유지
                    pass

        print(f" -> Extraction Complete. (Time: {time.time()-start_time:.2f}s)")

    def get_prob_matrix(self, age):
        """
        특정 나이(age)의 전이 확률 행렬(6x6)을 반환
        """
        mat = np.zeros((self.n_states, self.n_states))
        
        for s in range(self.n_states):
            total = self.state_population[age, s]
            
            if total > 0:
                # 관측된 데이터 기반 확률 계산
                mat[s] = self.transition_counts[age, s] / total
            else:
                # 데이터가 없는 경우 (예: 20세에 암 환자가 0명일 때)
                # 논리적인 기본값 설정
                mat[s, s] = 1.0 # 상태 유지
                if s == 5: mat[s, s] = 1.0 # Dead -> Dead
        
        return mat