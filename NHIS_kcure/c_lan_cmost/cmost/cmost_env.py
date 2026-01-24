#based on NumberCrunching_1000.m
import gymnasium as gym
import numpy as np
from gymnasium import spaces
from cmost_config import CMOSTConfig

class CmostEnv(gym.Env):
    """
    CMOST 기반 대장암 스크리닝 강화학습 환경
    Reference: NumberCrunching_10000.m
    """
    def __init__(self):
        super(CmostEnv, self).__init__()
        self.cfg = CMOSTConfig()
        
        # --- Action Space ---
        # 0: 대기 (Wait)
        # 1: 분변잠혈검사 (FOBT)
        # 2: 대장내시경 (Colonoscopy)
        self.action_space = spaces.Discrete(3)
        
        # --- Observation Space ---
        # [0]: 현재 나이 (normalized 0~1)
        # [1]: 증상 유무 (0 or 1) - Symptom develops logic
        # [2]: 마지막 검사 종류 (0:없음, 1:FOBT, 2:Colo)
        # [3]: 마지막 검사 결과 (0:정상, 1:용종, 2:암)
        # [4]: 마지막 검사로부터 경과 시간 (normalized)
        self.observation_space = spaces.Box(low=0, high=1, shape=(5,), dtype=np.float32)
        
        self.reset()

    def reset(self, seed=None, options=None):
        super().reset(seed=seed)
        
        # 1. 환자 초기화 (NumberCrunching.m: INITIALIZE 부분)
        self.age = 50 # 시작 나이
        self.max_age = 90
        
        # 환자 고유 위험도 할당 (Risk_Settings.m: IndividualRisk 적용)
        self.individual_risk = np.random.choice(self.cfg.individual_risk_dist)
        
        # Hidden States (Preclinical - Agent는 볼 수 없음)
        # 용종 리스트: 각 요소는 용종의 크기 단계 (1~6)
        self.hidden_polyps = [] 
        # 암 상태: None 또는 병기 (1~4)
        self.hidden_cancer = None 
        # 증상 타이머 (암 발생 시 설정됨)
        self.symptom_timer = -1 
        
        # Observation History
        self.last_test_type = 0
        self.last_test_result = 0
        self.time_since_last_test = 0
        
        return self._get_obs(), {}

    def step(self, action):
        reward = 0
        done = False
        info = {}
        
        # ====================================================
        # 1. Action 수행 (Screening_Settings.m & Colonoscopy 함수)
        # ====================================================
        test_performed = False
        
        if action == 1: # FOBT
            reward -= self.cfg.cost['fobt']
            test_performed = True
            detected, finding_type = self._perform_screening('fobt')
            
            if detected:
                self.last_test_result = finding_type # 1:용종, 2:암
                # FOBT 양성이면 보통 내시경을 하러 가므로(치료 기회) 약간의 보상
                reward += 0.5 
            else:
                self.last_test_result = 0

        elif action == 2: # Colonoscopy
            reward -= self.cfg.cost['colonoscopy']
            test_performed = True
            detected, finding_type = self._perform_screening('colonoscopy', remove_polyp=True)
            
            if detected:
                self.last_test_result = finding_type
                if finding_type == 1: # 용종 발견 및 제거
                    reward += self.cfg.reward['polyp_removed']
                elif finding_type == 2: # 암 발견
                    reward += self.cfg.reward['cancer_detected']
                    # 암 발견 시 시뮬레이션 종료 (치료 모드로 전환 가정)
                    done = True 
            else:
                self.last_test_result = 0

        if test_performed:
            self.last_test_type = action
            self.time_since_last_test = 0
        else:
            self.time_since_last_test += 1

        # ====================================================
        # 2. 자연사 진행 (NumberCrunching.m: Natural History)
        # ====================================================
        self._update_natural_history()

        # ====================================================
        # 3. 종료 조건 (Death / Max Age)
        # ====================================================
        self.age += 1
        reward += self.cfg.reward['alive'] # 1년 생존 보상
        
        # (1) 암으로 인한 사망 체크 (증상 발현 후 방치된 경우)
        if self.hidden_cancer and self.symptom_timer == 0:
            # 증상이 발현되었는데(Symptom develops), 치료되지 않음 -> 사망 위험
            if np.random.rand() < 0.5: # 간단화된 사망 확률
                done = True
                reward += self.cfg.reward['death_penalty']
                info['cause_of_death'] = 'cancer'

        # (2) 자연사 (LifeTable 적용 가능하나 여기선 90세로 단순화)
        if self.age >= self.max_age:
            done = True
            info['cause_of_death'] = 'natural'

        return self._get_obs(), reward, done, False, info

    def _update_natural_history(self):
        """ NumberCrunching.m 의 핵심 확률 로직 이식 """
        
        # A. 용종 발생 (New Polyp)
        # MATLAB: if rand < PolypRate(z) ...
        current_onset_prob = self.cfg.prob_onset_base * self.individual_risk
        if np.random.rand() < current_onset_prob:
            # 크기 1단계 용종 생성
            self.hidden_polyps.append(1) 

        # B. 용종 성장 (Progression)
        # MATLAB: AgeProgression * LocationProgression ...
        for i in range(len(self.hidden_polyps)):
            # 간단화: 일정 확률로 크기 +1
            if np.random.rand() < self.cfg.prob_growth:
                self.hidden_polyps[i] += 1
        
        # C. 암화 (Malignancy)
        # MATLAB: if Polyp.Polyps(z, f) > 6 ... Ca.Cancer(z, l2) = 7
        # 용종이 6단계를 넘어가면 암으로 변함
        for i in reversed(range(len(self.hidden_polyps))):
            if self.hidden_polyps[i] > 6:
                if self.hidden_cancer is None:
                    self.hidden_cancer = 1 # 1기 암 발생
                    self.symptom_timer = 5 # 5년 뒤 증상 발현 (Sojourn time)
                self.hidden_polyps.pop(i) # 용종은 암이 되었으므로 리스트에서 제거

        # D. 암 진행 (Cancer Progression)
        if self.hidden_cancer is not None:
            if self.hidden_cancer < 4: # 4기까지 진행
                if np.random.rand() < self.cfg.prob_cancer_progress:
                    self.hidden_cancer += 1
            
            # 증상 타이머 감소
            if self.symptom_timer > 0:
                self.symptom_timer -= 1

    def _perform_screening(self, test_type, remove_polyp=False):
        """ Screening_Settings.m 의 민감도 적용 """
        sens_table = self.cfg.sensitivities[test_type]
        detected = False
        finding_type = 0 # 0:없음, 1:용종, 2:암
        
        # 1. 암 탐지 시도
        if self.hidden_cancer is not None:
            # 암 병기(1~4)에 따른 민감도 인덱스: 6~9 (Python index 6,7,8,9)
            sens_idx = 5 + self.hidden_cancer 
            sensitivity = sens_table[sens_idx]
            if np.random.rand() < sensitivity:
                detected = True
                finding_type = 2
                return detected, finding_type # 암 찾으면 즉시 리턴

        # 2. 용종 탐지 시도
        # 발견된 용종들을 저장할 임시 리스트
        detected_polyps_indices = []
        
        for i, size in enumerate(self.hidden_polyps):
            # 용종 크기(1~6)에 따른 민감도 인덱스: 0~5
            sens_idx = min(size - 1, 5)
            sensitivity = sens_table[sens_idx]
            
            if np.random.rand() < sensitivity:
                detected = True
                finding_type = 1
                detected_polyps_indices.append(i)
        
        # 대장내시경인 경우 발견된 용종 제거 (Polypectomy)
        if remove_polyp and detected_polyps_indices:
            # 인덱스가 꼬이지 않게 뒤에서부터 제거
            for i in sorted(detected_polyps_indices, reverse=True):
                self.hidden_polyps.pop(i)
                
        return detected, finding_type

    def _get_obs(self):
        # Normalize age
        norm_age = (self.age - 50) / (90 - 50)
        
        # 증상 유무 (암이 있고 타이머가 0이면 증상 있음)
        has_symptom = 1.0 if (self.hidden_cancer and self.symptom_timer <= 0) else 0.0
        
        # 경과 시간 Normalize (최대 10년으로 가정)
        norm_time = min(self.time_since_last_test, 10) / 10.0
        
        return np.array([
            norm_age,
            has_symptom,
            self.last_test_type / 2.0,    # 0, 0.5, 1.0
            self.last_test_result / 2.0,  # 0, 0.5, 1.0
            norm_time
        ], dtype=np.float32)