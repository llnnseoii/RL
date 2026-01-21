import numpy as np
from parameters import SimulationParameters
from extract_probabilities import ProbabilityExtractor # ★ 방금 만든 모듈 임포트

class DPOptimizer:
    def __init__(self, settings_file):
        self.params = SimulationParameters(settings_file)
        
        # DP 범위 설정
        self.min_age = self.params.opt_min_age
        self.max_age = self.params.opt_max_age
        self.max_history = 10 
        
        # 6-State Model
        # 0:Healthy, 1:Early, 2:Adv, 3:Undetected, 4:Detected, 5:Dead
        self.n_states = 6
        
        # DP Tables
        self.V = np.zeros((102, self.max_history + 1, self.n_states))
        self.Policy = np.zeros((102, self.max_history + 1), dtype=int)
        
        # ★ 확률 추출기 초기화
        self.extractor = ProbabilityExtractor(settings_file)

    def solve(self):
        # 1. 먼저 시뮬레이션을 돌려 확률을 학습합니다.
        self.extractor.run_extraction(n_people=100000)

        #debugging(for checking transition probability matrix)
        print("\n[Debug] Transition Matrix at Age 60:")
        T_60 = self.extractor.get_prob_matrix(60)
        np.set_printoptions(precision=4, suppress=True)
        print(T_60)
        print("Row 0 (Healthy -> ?):", T_60[0])
        print("Row 1 (Early -> ?):", T_60[1])
        print("Row 2 (Adv -> ?):", T_60[2])
        print("-" * 30)       
    
        print(">>> Starting Dynamic Programming (Backward Induction)...")
        
        # 비용 및 파라미터
        val_life_year = 50000.0 # QALY 가치 ($)
        cost_screen = self.params.cost_colo
        
        # 검사 민감도 (Sensitivity) - Settings.ini 값을 평균내거나 대표값 사용
        # (여기서는 용종/암 발견 평균 확률 가정)
        sens_early = 0.70  # Early Polyp 발견율
        sens_adv = 0.90    # Advanced Polyp 발견율
        sens_cancer = 0.95 # Cancer 발견율
        
        # 100세 -> min_age 역순 계산
        for t in range(99, self.min_age - 1, -1):
            
            # ★ 학습된 전이 확률 가져오기
            T = self.extractor.get_prob_matrix(t)
            
            for h in range(self.max_history + 1):
                next_h_wait = min(h + 1, self.max_history)
                next_h_screen = 0
                
                # --- [1] Future Value 계산 (검사 안 했을 때 다음 해의 가치) ---
                future_val = np.zeros(self.n_states)
                for s in range(self.n_states):
                    # 다음 상태들의 가치 가중평균
                    expected_next_v = sum(T[s, next_s] * self.V[t+1, next_h_wait, next_s] for next_s in range(self.n_states))
                    
                    # 보상 체계
                    if s == 5: # Dead
                        future_val[s] = 0
                    elif s == 4: # Detected Cancer (치료중)
                        # 치료비 발생 & 삶의 질 감소
                        future_val[s] = expected_next_v + (val_life_year * 0.7) - 5000 
                    else: # Healthy / Polyp / Undetected
                        future_val[s] = expected_next_v + val_life_year

                # DP Table 저장 (Wait 했을 때의 가치)
                # s=0,1,2,3일 때만 선택권이 있음
                
                # --- [2] Action 0: Wait ---
                ev_wait = future_val.copy() # 위에서 계산한 값 그대로
                
                # --- [3] Action 1: Screen ---
                ev_screen = np.zeros(self.n_states)
                
                # S=0 (Healthy): 비용만 발생, 상태 유지
                ev_screen[0] = -cost_screen + sum(T[0, ns] * self.V[t+1, next_h_screen, ns] for ns in range(self.n_states)) + val_life_year
                
                # S=1 (Early): 발견 시 제거(Healthy로 회귀), 미발견 시 유지
                # 발견하면 T[0] 확률(건강해짐), 놓치면 T[1] 확률(그대로)
                v_cured = sum(T[0, ns] * self.V[t+1, next_h_screen, ns] for ns in range(self.n_states)) + val_life_year
                v_missed = sum(T[1, ns] * self.V[t+1, next_h_screen, ns] for ns in range(self.n_states)) + val_life_year
                ev_screen[1] = -cost_screen - self.params.cost_colo_polyp + (sens_early * v_cured + (1-sens_early) * v_missed)
                
                # S=2 (Advanced): 발견 시 제거(Healthy), 미발견 시 위험
                v_missed_adv = sum(T[2, ns] * self.V[t+1, next_h_screen, ns] for ns in range(self.n_states)) + val_life_year
                ev_screen[2] = -cost_screen - self.params.cost_colo_polyp + (sens_adv * v_cured + (1-sens_adv) * v_missed_adv)
                
                # S=3 (Undetected): 발견 시 Detected(State 4)로 전환
                # 발견하면 T[4](Detected)의 경로를 따름 (치료 시작)
                v_detected = sum(T[4, ns] * self.V[t+1, next_h_screen, ns] for ns in range(self.n_states)) + (val_life_year * 0.8)
                v_missed_ca = sum(T[3, ns] * self.V[t+1, next_h_screen, ns] for ns in range(self.n_states)) + val_life_year
                ev_screen[3] = -cost_screen - self.params.cost_initial_cancer[1] + (sens_cancer * v_detected + (1-sens_cancer) * v_missed_ca)
                
                # S=4, 5: 이미 늦음 (검사 안함)
                ev_screen[4] = ev_wait[4]
                ev_screen[5] = ev_wait[5]

                # --- [4] 최적 선택 (Optimization) ---
                # 현재 내 상태를 모름 -> 위험도(Prevalence) 기반 결정
                # 나이 t일 때 각 상태에 있을 확률 (Extractor에서 얻은 state_population 사용)
                total_pop = self.extractor.state_population[t].sum()
                if total_pop > 0:
                    probs = self.extractor.state_population[t] / total_pop
                else:
                    probs = np.array([1, 0, 0, 0, 0, 0]) # 데이터 없으면 Healthy 가정

                # 가중 평균 기대값 (Weighted Expected Value)
                # s=0~3 (검진 대상)에 대해서만 계산
                E_wait_weighted = 0
                E_screen_weighted = 0
                
                denom = probs[0] + probs[1] + probs[2] + probs[3]
                if denom > 0:
                    for s in [0, 1, 2, 3]:
                        weight = probs[s] / denom
                        E_wait_weighted += weight * ev_wait[s]
                        E_screen_weighted += weight * ev_screen[s]
                
                # DP Table 업데이트 (가중 평균값이 아닌, 각 상태별 최적값으로 저장해야 정확함)
                # 하지만 Policy는 하나여야 하므로 가중 평균으로 결정
                if E_screen_weighted > E_wait_weighted:
                    self.Policy[t, h] = 1
                    # 결정된 정책에 따라 Value Function 업데이트
                    for s in range(self.n_states):
                        self.V[t, h, s] = ev_screen[s]
                else:
                    self.Policy[t, h] = 0
                    for s in range(self.n_states):
                        self.V[t, h, s] = ev_wait[s]
                # ★ [디버깅] 10년 이상 검사 안 한 50세, 60세, 70세의 속마음 출력
                if h == 10 and t in [50, 60, 70]:
                    diff = E_screen_weighted - E_wait_weighted
                    print(f"[Age {t}] Wait Val: {E_wait_weighted:,.0f} vs Screen Val: {E_screen_weighted:,.0f} | Diff: {diff:,.0f}")
                

        print(">>> DP Optimization Complete.")

    def print_optimal_policy(self):
        print("\n" + "="*50)
        print("   OPTIMAL SCREENING POLICY (Simulation-based DP)")
        print("="*50)
        print(" Age | Rec. Since Last | Recommendation")
        print("-----|-----------------|----------------")
        
        # 보기 좋게 출력 (검사 안 한 지 오래된 사람 기준)
        for t in range(40, 81):
            action = self.Policy[t, 10]
            action_str = "★ SCREEN" if action == 1 else "Wait"
            print(f" {t:3d} |      10+ years   | {action_str}")