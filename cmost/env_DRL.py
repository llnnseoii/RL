# %%
import numpy as np
import scipy.io
import gymnasium as gym
from gymnasium import spaces
from stable_baselines3 import PPO
from stable_baselines3.common.vec_env import DummyVecEnv
import pandas as pd
import os

# %%
#config

class CMOSTConfig:
    def __init__(self, mat_file_path='/Users/llnnseoii/Desktop/cmost/Settings/CMOST13.mat'):
        print(f"🔧 Config 로딩 및 캘리브레이션 적용 중...")
        
        try:
            mat_data = scipy.io.loadmat(mat_file_path)
            if 'temp' in mat_data:
                self.data = mat_data['temp'][0, 0]
        except:
            self.data = None

        if self.data is not None:
            # =========================================================
            # 🎛️ [핵심 수정] 캘리브레이션 팩터 (Calibration Factor)
            # =========================================================
            # 목표: 발병률 40% -> 5% (약 1/8로 감소 필요)
            # 0.15 (15%)로 설정하여 발병 확률을 확 낮춥니다.
            CALIB_FACTOR = 0.15 
            
            self.frac_female = self._get_scalar('fraction_female')
            
            # 남성 데이터 (보정 적용)
            self.male_onset = self._interpolate(self.data['NewPolypRate']) * CALIB_FACTOR
            self.male_early = self._interpolate(self.data['EarlyProgressionRate'])
            self.male_adv   = self._interpolate(self.data['AdvancedProgressionRate'])
            self.male_life  = self.data['LifeTable'][:, 0]
            
            # 여성 데이터 (보정 적용)
            if 'new_polyp_female' in self.data.dtype.names:
                self.female_onset = self._interpolate(self.data['new_polyp_female']) * CALIB_FACTOR
                self.female_early = self._interpolate(self.data['early_progression_female'])
                self.female_adv   = self._interpolate(self.data['advanced_progression_female'])
                self.female_life  = self.data['LifeTable'][:, 1]
            else:
                self.female_onset = self.male_onset
                self.female_early = self.male_early
                self.female_adv   = self.male_adv
                self.female_life  = self.male_life

            self.prob_healing = self.data['Healing'].flatten()
            
            # 급속 암도 너무 자주 생기면 안 되므로 동일하게 보정
            self.prob_fast_cancer = self.data['FastCancer'].flatten() * CALIB_FACTOR
            self.prob_symptoms = self.data['Symptoms'].flatten()
            
            # Risk 정규화
            raw_risk = self.data['IndividualRisk'].flatten()
            mean_risk = np.mean(raw_risk) if len(raw_risk) > 0 else 1.0
            self.risk_dist = raw_risk / mean_risk 
            self.risk_dist = np.clip(self.risk_dist, 0.1, 5.0) 

            self.sens_colo = self.data['Colo_Detection'].flatten()
            self.risk_perf  = self._get_scalar('Colonoscopy_RiscPerforation')
            self.death_perf = self._get_scalar('DeathPerforation')
        else:
            self._set_dummy_values()

        self.sens_fobt = np.array([0.02, 0.02, 0.05, 0.05, 0.12, 0.12, 0.4, 0.4, 0.4, 0.4])

        # 보상 체계 (한국형 비용 반영 버전 유지)
        self.rewards = {
            'cost_wait': 0.0,
            'cost_fobt': 0.1,  
            'cost_colo': 2.0,  
            'cost_sigmo': 1.2,
            'reward_alive': 1.0,       
            'reward_polyp': 5.0,       
            'reward_cancer': 200.0,     
            'penalty_death': -8000.0,  
            'penalty_complication': -100.0 
        }

    # ... (나머지 헬퍼 함수는 동일) ...
    def _get_scalar(self, key):
        if key in self.data.dtype.names:
            val = self.data[key]
            return val.item() if val.size == 1 else val.flatten()[0]
        return 0.0

    def _interpolate(self, raw_data, target_len=100):
        if raw_data is None or raw_data.size == 0: return np.zeros(target_len)
        y = raw_data.flatten()
        x = np.linspace(0, target_len, len(y))
        return np.interp(np.arange(target_len), x, y)
    
    def _set_dummy_values(self):
        self.risk_dist = np.ones(100)
    
    def get_rates(self, is_female):
        if is_female: return self.female_onset, self.female_early, self.female_adv, self.female_life
        return self.male_onset, self.male_early, self.male_adv, self.male_life
    
    def get_sensitivity(self, test_type, state_idx):
        if state_idx < 0: return 0
        idx = min(state_idx, 9)
        if test_type == 'colonoscopy': return self.sens_colo[idx]
        elif test_type == 'fobt': return self.sens_fobt[idx]
        return 0


# %%
# ==============================================================================
# 2. CMOST Environment (시뮬레이션 환경)
# ==============================================================================
class CmostEnv(gym.Env):
    def __init__(self):
        super(CmostEnv, self).__init__()
        self.cfg = CMOSTConfig() 
        
        # Action Space: 0=Wait, 1=I-FOBT, 2=Colonoscopy, 3=Sigmoidoscopy
        self.action_space = spaces.Discrete(4)
        
        # Observation Space
        # [나이, 성별, 증상, 마지막검사, 결과, 경과시간]
        self.observation_space = spaces.Box(low=0, high=1, shape=(6,), dtype=np.float32)

    def reset(self, seed=None, options=None):
        super().reset(seed=seed)
        
        max_retries = 100 
        attempt = 0
        
        while attempt < max_retries:
            attempt += 1
            
            # 1. 초기화
            self.max_age = 100
            self.is_female = np.random.rand() < self.cfg.frac_female
            self.risk_factor = np.random.choice(self.cfg.risk_dist)
            
            self.rates = self.cfg.get_rates(self.is_female) 
            self.r_onset, self.r_early, self.r_adv, self.r_life = self.rates

            self.hidden_polyps = []   
            self.hidden_cancer = None 
            
            # 2. Warm-up (0세 -> 50세)
            self.age = 0
            target_start_age = 50
            is_dead_during_warmup = False
            
            for _ in range(target_start_age):
                for q in range(4):
                    current_time = self.age + q/4.0
                    self._update_biology_quarterly(current_time)
                    if self._check_death(current_time): 
                        is_dead_during_warmup = True
                        break
                if is_dead_during_warmup: break
                self.age += 1
                
            # 3. 조건 확인 (살아있고, 말기암 아니면 통과)
            if not is_dead_during_warmup:
                if not (self.hidden_cancer and self.hidden_cancer >= 4):
                    break 
        
        # 실패 시 강제 초기화 (안전장치)
        if attempt >= max_retries:
            self.age = 50
            self.hidden_polyps = []
            self.hidden_cancer = None 
        
        # 관측값 초기화
        self.last_test_type = 0
        self.last_test_result = 0
        self.time_since_test = 10.0 
        self.has_symptom = 0
        
        if self.hidden_cancer:
             symp_prob = self.cfg.prob_symptoms[min(5+self.hidden_cancer, 9)]
             if np.random.rand() < symp_prob:
                 self.has_symptom = 1

        # ★★★ [수정] return 구문 위치 및 들여쓰기 확인 ★★★
        return self._get_obs(), {}

    def step(self, action):
        reward = 0
        done = False
        info = {'cause': 'alive', 'action': action}
        
        # 1. Action
        if not done:
            reward_act, done_act, info_act = self._perform_action(action)
            reward += reward_act
            if done_act: 
                done = True
                info.update(info_act)

        # 2. Biology (Quarterly)
        if not done:
            for q in range(4):
                current_time = self.age + q/4.0
                self._update_biology_quarterly(current_time)
                
                if self.hidden_cancer:
                    symp_prob = self.cfg.prob_symptoms[min(5+self.hidden_cancer, 9)] / 4.0
                    if np.random.rand() < symp_prob:
                        self.has_symptom = 1
                
                if self._check_death(current_time):
                    done = True
                    # 암 사망 vs 자연사 구분
                    if self.hidden_cancer and self.has_symptom:
                        info['cause'] = 'cancer_death'
                        reward += self.cfg.rewards['penalty_death']
                    else:
                        info['cause'] = 'natural_death'
                    break

        # 3. Year End
        if not done:
            self.age += 1
            reward += self.cfg.rewards['reward_alive']
            self.time_since_test += 1
            if self.age >= self.max_age:
                done = True
                info['cause'] = 'max_age_reached'

        return self._get_obs(), reward, done, False, info

    def _perform_action(self, action):
        r, d = 0, False
        i = {}
        
        if action == 0: # Wait
            return r, d, i
            
        elif action == 1: # I-FOBT (FIT)
            r -= 0.5 
            self.time_since_test = 0
            self.last_test_type = 0.3
            detected, f_type = self._run_test('fobt', remove=False, sens_factor=1.5)
            if detected:
                self.last_test_result = f_type
                r += 0.5 
            else:
                self.last_test_result = 0
                
        elif action == 2: # Colonoscopy
            r -= 5.0 
            self.time_since_test = 0
            self.last_test_type = 1.0
            
            if np.random.rand() < self.cfg.risk_perf:
                r += self.cfg.rewards['penalty_complication']
                if np.random.rand() < self.cfg.death_perf:
                    return r + self.cfg.rewards['penalty_death'], True, {'cause': 'perforation_death'}

            detected, f_type = self._run_test('colonoscopy', remove=True)
            if detected:
                self.last_test_result = f_type
                if f_type == 1: r += self.cfg.rewards['reward_polyp']
                elif f_type == 2:
                    r += self.cfg.rewards['reward_cancer']
                    d = True
                    i['cause'] = 'cancer_detected'
            else:
                self.last_test_result = 0

        elif action == 3: # Sigmoidoscopy
            r -= 2.0 
            self.time_since_test = 0
            self.last_test_type = 0.6
            
            detected, f_type = self._run_test('colonoscopy', remove=True, reach_factor=0.6)
            if detected:
                self.last_test_result = f_type
                if f_type == 1: r += self.cfg.rewards['reward_polyp']
                elif f_type == 2:
                    r += self.cfg.rewards['reward_cancer']
                    d = True
                    i['cause'] = 'cancer_detected'
            else:
                self.last_test_result = 0
                
        return r, d, i

    def _run_test(self, t_type, remove, sens_factor=1.0, reach_factor=1.0):
        det, f_type = False, 0
        
        # 암 탐지
        if self.hidden_cancer:
            if np.random.rand() < reach_factor: 
                sens = self.cfg.get_sensitivity(t_type, 5 + self.hidden_cancer) * sens_factor
                if np.random.rand() < sens: return True, 2
            
        # 용종 탐지
        rem_idx = []
        for idx, size in enumerate(self.hidden_polyps):
            if np.random.rand() < reach_factor: 
                sens = self.cfg.get_sensitivity(t_type, min(size-1, 5)) * sens_factor
                if np.random.rand() < sens:
                    det = True
                    f_type = 1
                    rem_idx.append(idx)
        
        if remove and rem_idx:
            for idx in sorted(rem_idx, reverse=True):
                self.hidden_polyps.pop(idx)
                
        return det, f_type

    def _update_biology_quarterly(self, current_time):
        age_idx = min(int(self.age), 99)
        dt = 0.25 
        
        prob_onset = (self.r_onset[age_idx] * self.risk_factor) * dt
        if np.random.rand() < prob_onset:
            self.hidden_polyps.append(1) 

        prob_fast = self.cfg.prob_fast_cancer[age_idx] if age_idx < len(self.cfg.prob_fast_cancer) else 0
        if np.random.rand() < prob_fast * dt:
            self.hidden_cancer = 1 
            
        for i in range(len(self.hidden_polyps)):
            size = self.hidden_polyps[i]
            rate = self.r_early[age_idx] if size <= 3 else self.r_adv[age_idx]
            if np.random.rand() < rate * dt: 
                self.hidden_polyps[i] += 1

        for i in reversed(range(len(self.hidden_polyps))):
            size = self.hidden_polyps[i]
            heal_prob = self.cfg.prob_healing[min(size-1, 9)] if size > 0 else 0
            if np.random.rand() < heal_prob * dt:
                self.hidden_polyps[i] -= 1 
                if self.hidden_polyps[i] <= 0:
                    self.hidden_polyps.pop(i) 

        for i in reversed(range(len(self.hidden_polyps))):
            if self.hidden_polyps[i] > 6: 
                if self.hidden_cancer is None: self.hidden_cancer = 1
                self.hidden_polyps.pop(i)

        if self.hidden_cancer and self.hidden_cancer < 4:
            if np.random.rand() < 0.4 * dt: 
                self.hidden_cancer += 1

    def _check_death(self, current_time):
        age_idx = min(int(self.age), 99)
        nat_death_prob = self.r_life[age_idx] / 4.0
        if np.random.rand() < nat_death_prob: return True
            
        if self.hidden_cancer:
            cancer_death_base = [0, 0.01, 0.05, 0.2, 0.8] 
            c_death = cancer_death_base[self.hidden_cancer] / 4.0
            if np.random.rand() < c_death: return True
        return False

    def _get_obs(self):
        return np.array([
            (self.age - 50) / 50.0,      
            1.0 if self.is_female else 0.0,
            self.has_symptom,
            self.last_test_type,
            self.last_test_result,
            min(self.time_since_test, 10) / 10.0
        ], dtype=np.float32)


# %%
# ==============================================================================
# 3. 학습 및 평가 코드
# ==============================================================================
def evaluate_agent(agent_model, num_episodes=50, name="Agent"):
    test_env = CmostEnv()
    rewards = []
    
    print(f"\n--- [{name}] 평가 시작 ({num_episodes}명) ---")
    for ep in range(num_episodes):
        obs, _ = test_env.reset()
        done = False
        ep_reward = 0
        while not done:
            if agent_model: action, _ = agent_model.predict(obs, deterministic=True)
            else: action = test_env.action_space.sample()
            obs, reward, done, _, info = test_env.step(action)
            ep_reward += reward
        rewards.append(ep_reward)
    
    print(f"평균 보상: {np.mean(rewards):.2f}")
    return np.mean(rewards)

# 학습 시작
env = DummyVecEnv([lambda: CmostEnv()])
print("🤖 PPO 모델 생성 및 학습 시작...")
model = PPO("MlpPolicy", env, verbose=1, learning_rate=0.0003, gamma=0.999)
evaluate_agent(None, num_episodes=20, name="Random Agent")
model.learn(total_timesteps=100000) 
print("✅ 학습 완료!")
evaluate_agent(model, num_episodes=20, name="Trained AI")


# %%
import pandas as pd
import numpy as np
import os

def run_full_evaluation(agent_model, env_class, episodes=100, agent_name="Agent"):
    """
    에이전트의 성능을 상세 평가하고, 개별 환자 기록을 반환하는 함수
    """
    env = env_class()
    records = []
    
    # 통계용 변수
    total_lifespan = 0
    cancer_deaths = 0
    perf_deaths = 0
    total_rewards = 0
    
    print(f"🏥 [{agent_name}] {episodes}명 환자 시뮬레이션 진행 중...", end="")
    
    for i in range(episodes):
        obs, _ = env.reset()
        done = False
        ep_reward = 0
        
        # 환자별 기록
        history = {
            'id': i + 1,
            'agent_type': agent_name,
            'risk': env.risk_factor,
            'gender': "Female" if env.is_female else "Male",
            'events': [], # (나이, 검사명)
            'cause': None
        }
        
        # 행동 이름 매핑
        action_map = {0: 'Wait', 1: 'I-FOBT', 2: 'Colo', 3: 'Sigmo'}
        
        while not done:
            if agent_model:
                action, _ = agent_model.predict(obs, deterministic=True)
                action = int(action)
            else:
                action = env.action_space.sample()
            
            # 검사 기록 (대기(0) 제외)
            if action > 0:
                history['events'].append((env.age, action_map[action]))
            
            obs, reward, done, _, info = env.step(action)
            ep_reward += reward
            
            if done:
                history['cause'] = info.get('cause')
                total_lifespan += env.age
                if info.get('cause') == 'cancer_death': cancer_deaths += 1
                if info.get('cause') == 'perforation_death': perf_deaths += 1
        
        total_rewards += ep_reward
        
        # --- 데이터 가공 (Interval 계산) ---
        ages = [e[0] for e in history['events']]
        methods = [e[1] for e in history['events']]
        
        if len(ages) > 1:
            intervals = np.diff(ages).tolist()
            intervals = [int(x) for x in intervals] # 소수점 제거
            avg_int = round(np.mean(intervals), 1)
        else:
            intervals = []
            avg_int = 0

        # 레코드 추가
        records.append({
            "Agent": agent_name,
            "ID": history['id'],
            "Gender": history['gender'],
            "Risk": round(history['risk'], 2),
            "Lifespan": int(env.age),
            "Death Cause": history['cause'],
            "Total Tests": len(ages),
            "Methods": str(methods).replace("'", "").replace("[", "").replace("]", ""),
            "Intervals": str(intervals).replace("[", "").replace("]", ""),
            "Avg Interval": avg_int if avg_int > 0 else "-"
        })
        
        if i % 20 == 0: print(".", end="")

    print(" 완료!")
    
    # 요약 통계 반환
    summary = {
        "Agent": agent_name,
        "Avg Reward": total_rewards / episodes,
        "Avg Lifespan": total_lifespan / episodes,
        "Cancer Mortality (%)": (cancer_deaths / episodes) * 100,
        "Perforation Death (%)": (perf_deaths / episodes) * 100,
        "Avg Tests per Patient": sum(r['Total Tests'] for r in records) / episodes
    }
    
    return pd.DataFrame(records), summary

# =========================================================
# 1. 실행: Random vs PPO 비교
# =========================================================
print("\n🔄 비교 분석 시작...")
df_random, sum_random = run_full_evaluation(None, CmostEnv, episodes=10000, agent_name="Random")
df_ppo, sum_ppo = run_full_evaluation(model, CmostEnv, episodes=10000, agent_name="PPO_AI")

# =========================================================
# 2. 결과 비교표 출력
# =========================================================
print("\n📊 [최종 성적표: Random vs AI]")
print("="*60)
print(f"{'Metric':<25} | {'Random Agent':<15} | {'PPO AI Doctor':<15}")
print("-" * 60)
print(f"{'Avg Lifespan (Age)':<25} | {sum_random['Avg Lifespan']:<15.1f} | {sum_ppo['Avg Lifespan']:<15.1f}")
print(f"{'Cancer Mortality (%)':<25} | {sum_random['Cancer Mortality (%)']:<15.1f} | {sum_ppo['Cancer Mortality (%)']:<15.1f}")
print(f"{'Medical Accident (%)':<25} | {sum_random['Perforation Death (%)']:<15.1f} | {sum_ppo['Perforation Death (%)']:<15.1f}")
print(f"{'Avg Tests (Count)':<25} | {sum_random['Avg Tests per Patient']:<15.1f} | {sum_ppo['Avg Tests per Patient']:<15.1f}")
print(f"{'Total Reward':<25} | {sum_random['Avg Reward']:<15.1f} | {sum_ppo['Avg Reward']:<15.1f}")
print("="*60)

# =========================================================
# 3. CSV 저장 (VS Code 시각화용)
# =========================================================
# 두 데이터 합치기
df_final = pd.concat([df_random, df_ppo])

# 한글 매핑 (보기 좋게 변환)
cause_map = {
    'natural_death': 'Natural', 
    'cancer_death': 'Cancer', 
    'perforation_death': 'Accident', 
    'cancer_detected': 'Cured',
    'max_age_reached': 'MaxAge'
}
df_final['Death Cause'] = df_final['Death Cause'].map(cause_map).fillna(df_final['Death Cause'])

# 파일 저장
file_name = "comparison_results.csv"
# df_final.to_csv(file_name, index=False)

# print(f"\n✅ 데이터 저장 완료: {file_name}")
# print("👉 VS Code에서 이 CSV 파일을 열고 'Data Wrangler' 또는 'Excel Viewer' 확장 프로그램을 사용하면 표/그래프로 볼 수 있습니다.")

# %%
# 행(Row) 제한을 없애는 설정 (None = 제한 없음)
pd.set_option('display.max_rows', None)

# 출력
df_final['Death Cause'].value_counts()

# %%
#application 1. env test
#action=wait일 때, 즉 no screening일 때의 통계가 나옴. 
import numpy as np
import pandas as pd
import time

def validate_natural_history(env_class, num_patients=100000):
    """
    10만 명의 환자를 대상으로 '검사 없이(Wait)' 시뮬레이션을 돌려서
    환경의 자연사(Natural History) 통계가 정상적인지 검증함.
    """
    env = env_class()
    print(f"🧪 [환경 검증] 자연사 시뮬레이션 시작 (대상: {num_patients:,}명)")
    print("   👉 검사를 전혀 하지 않을 때의 암 발생률과 사망률을 측정합니다.")
    
    start_time = time.time()
    
    # 통계 변수
    stats = {
        'total_cancer_cases': 0,   # 암이 발병한 사람 수 (완치 포함)
        'cancer_deaths': 0,        # 암으로 사망한 사람 수
        'natural_deaths': 0,       # 자연사한 사람 수
        'total_polyps': 0,         # 평생 발생한 총 용종 수
        'lifespans': []            # 수명 데이터
    }
    
    # 10만 명 루프 (시간이 좀 걸리므로 1만 명 단위로 로그 출력)
    for i in range(num_patients):
        if (i+1) % 10000 == 0:
            print(f"   ... {i+1:,}명 진행 중 ({time.time()-start_time:.1f}초 경과)")
            
        obs, _ = env.reset()
        done = False
        
        has_cancer_history = False # 이 환자가 평생 암에 걸린 적이 있는가?
        polyps_count = len(env.hidden_polyps) # 초기 용종 수
        
        while not done:
            # 무조건 대기 (검사 안 함)
            action = 0 
            
            # Step 진행
            obs, reward, done, _, info = env.step(action)
            
            # 통계 수집
            if env.hidden_cancer: 
                has_cancer_history = True
            
            # 새로 생긴 용종 카운트 (근사치: 현재 용종 수가 늘어나면 체크)
            # 정확히 하려면 env 내부에서 카운트해야 하지만, 여기선 경향성만 봅니다.
            if len(env.hidden_polyps) > polyps_count:
                polyps_count = len(env.hidden_polyps)

        # 환자 1명 종료 후 집계
        stats['lifespans'].append(env.age)
        stats['total_polyps'] += polyps_count
        if has_cancer_history: stats['total_cancer_cases'] += 1
        
        if info.get('cause') == 'cancer_death':
            stats['cancer_deaths'] += 1
        else:
            stats['natural_deaths'] += 1

    # --- 최종 검증 리포트 ---
    duration = time.time() - start_time
    print(f"\n✅ 시뮬레이션 완료! (소요 시간: {duration:.2f}초)")
    
    cancer_incidence = (stats['total_cancer_cases'] / num_patients) * 100
    cancer_mortality = (stats['cancer_deaths'] / num_patients) * 100
    avg_lifespan = np.mean(stats['lifespans'])
    
    print("\n📊 [Natural History Benchmark Result]")
    print("=" * 60)
    print(f"1. 시뮬레이션 인원 : {num_patients:,} 명")
    print(f"2. 평균 수명       : {avg_lifespan:.1f} 세")
    print("-" * 60)
    print(f"3. 대장암 발병률   : {cancer_incidence:.2f}% (평생 암에 한 번이라도 걸릴 확률)")
    print(f"   - 참고(현실)    : 약 4% ~ 6% (선진국 기준)")
    print("-" * 60)
    print(f"4. 대장암 사망률   : {cancer_mortality:.2f}% (검사 안 했을 때 암으로 죽을 확률)")
    print(f"   - 참고(현실)    : 약 2% ~ 3% (검진 없을 시)")
    print("=" * 60)
    
    # 검증 로직
    if 3.0 <= cancer_incidence <= 10.0:
        print("🟢 [판정: 적합] 암 발병률이 현실적인 범위(3~10%) 내에 있습니다.")
    elif cancer_incidence > 10.0:
        print("🔴 [판정: 과다] 암 발병률이 너무 높습니다. (Risk 정규화 또는 발병률 파라미터 확인 필요)")
    else:
        print("🟡 [판정: 과소] 암 발병률이 너무 낮습니다.")

# --- 실행 ---
validate_natural_history(CmostEnv, num_patients=100000)
