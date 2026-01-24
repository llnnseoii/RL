import numpy as np

class CMOSTConfig:
    def __init__(self):
        # ==========================================
        # 1. Risk Settings (from Risk_Settings.m)
        # ==========================================
        # 환자 개인별 위험도 분포를 만들기 위한 백분위수 (예시값)
        # MATLAB의 handles.Variables.Ind_Risk_Percentiles 에 해당
        self.risk_percentiles = [0.1, 0.2, 0.3, 0.5, 1.0, 1.5, 2.0, 3.0, 5.0, 8.0, 10.0, 15.0]
        
        # 보간법을 통해 500개 구간의 위험도 분포 생성 (AdjustRiskGraph 함수 이식)
        self.individual_risk_dist = self._interpolate_risk(self.risk_percentiles)

        # 자연사 파라미터 (NumberCrunching.m의 AgeProgression 등 추상화)
        self.prob_onset_base = 0.04      # 기본 용종 발생률
        self.prob_growth = 0.15          # 용종 성장 확률 (Small -> Large)
        self.prob_malignancy = 0.05      # 암화 확률 (Large -> Cancer)
        self.prob_cancer_progress = 0.4  # 암 기수 진행 확률

        # ==========================================
        # 2. Screening Settings (from Screening_Settings.m)
        # ==========================================
        # 민감도(Sensitivity): [P1, P2, P3, P4, P5, P6, Ca1, Ca2, Ca3, Ca4]
        # P1~P6: 용종 크기별 (1mm ~ >10mm), Ca1~Ca4: 암 병기별
        
        self.sensitivities = {
            # 대장내시경 (Colonoscopy): 용종 발견율이 높음 + 치료 가능
            'colonoscopy': np.array([0.70, 0.80, 0.90, 0.95, 0.98, 0.99, 0.95, 0.98, 0.99, 0.99]),
            
            # 분변잠혈검사 (FOBT): 용종 발견율 낮음, 암 발견율은 중간
            'fobt':        np.array([0.05, 0.05, 0.10, 0.15, 0.20, 0.25, 0.50, 0.60, 0.70, 0.80]),
            
            # Septin9 등 다른 검사 추가 가능
            'sept9':       np.array([0.01, 0.02, 0.05, 0.10, 0.15, 0.20, 0.60, 0.75, 0.85, 0.90])
        }

        # 비용 및 보상 설정 (RL 학습용)
        self.cost = {
            'wait': 0,
            'fobt': 0.1,        # 저렴
            'colonoscopy': 1.0  # 비쌈 (기준점)
        }
        self.reward = {
            'alive': 0.1,       # 생존 보상
            'polyp_removed': 1.0, # 예방 보상
            'cancer_detected': 5.0, # 조기 발견 보상
            'death_penalty': -100.0 # 사망 페널티
        }

    def _interpolate_risk(self, percentiles):
        """
        Risk_Settings.m 의 'AdjustRiskGraph' 함수 로직 구현
        주어진 백분위수 점들을 선형 보간하여 전체 인구의 위험도 분포를 생성
        """
        # x축 기준점 (MATLAB 코드의 Values 배열)
        x_points = np.array([10, 20, 30, 40, 50, 60, 70, 80, 90, 95, 97, 100]) * 5
        
        # 0~500 범위의 분포 생성
        risk_dist = np.zeros(501)
        risk_dist[:x_points[0]] = percentiles[0]
        
        prev_x = x_points[0]
        prev_y = percentiles[0]
        
        for i in range(1, len(x_points)):
            curr_x = x_points[i]
            curr_y = percentiles[i]
            
            # 선형 보간
            for x in range(prev_x, curr_x):
                risk_dist[x] = prev_y + (curr_y - prev_y) * (x - prev_x) / (curr_x - prev_x)
            
            prev_x = curr_x
            prev_y = curr_y
            
        return risk_dist