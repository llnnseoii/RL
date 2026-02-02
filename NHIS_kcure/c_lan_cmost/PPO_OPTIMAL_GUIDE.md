# PPO Optimal Training Guide

## 개요

`ppo_optimal.py`는 대장암 검진 최적화를 위한 강화학습 에이전트입니다. GAE(Generalized Advantage Estimation)를 사용하여 안정적이고 효율적인 학습을 제공합니다.

## 주요 기능

### 1. 향상된 환경 (`ColonoscopyOptimalEnv`)
- **상태 공간**: 16차원 (나이, 검진 이력, 성별, 13개 구역 상태)
- **행동 공간**: 2개 (대기, 검진)
- **보상 설계**:
  - 생존 보상 (연간 +0.15, 완주 +5.0)
  - 검진 페널티 (비용 + 불편함)
  - 암 조기 발견 보너스 (Stage I: +5.0, Stage IV: +3.5)
  - 용종 제거 보상 (개당 +0.5)
  - 암 사망 페널티 (-10.0 - 손실년수×0.5)

### 2. GAE (Generalized Advantage Estimation)
```python
δ_t = r_t + γV(s_{t+1}) - V(s_t)
A_t = δ_t + (γλ)δ_{t+1} + (γλ)²δ_{t+2} + ...
```
- λ = 0.95: 편향-분산 트레이드오프
- γ = 0.99: 할인 계수

### 3. Actor-Critic 네트워크
- **구조**: 16 → 512 → 512 → 256 → {2|1}
- **정규화**: LayerNorm, Dropout(0.1)
- **초기화**: Xavier Uniform

### 4. 고급 학습 기법
- **Learning Rate Scheduling**: Cosine annealing (3e-4 → 1e-5)
- **Entropy Decay**: 0.01 → 0.001 (탐색 → 활용)
- **Gradient Clipping**: Max norm 0.5
- **Mini-batch Update**: Batch 256, Mini-batch 64, Epochs 10

## 사용 방법

### 기본 학습
```bash
python ppo_optimal.py
```

### 파라미터 설정
```bash
# 짧은 학습 (테스트용)
python ppo_optimal.py --max_episodes 1000 --test_mode

# 긴 학습 (최적 정책용)
python ppo_optimal.py --max_episodes 20000

# GPU 사용
python ppo_optimal.py --device cuda

# 커스텀 디렉토리
python ppo_optimal.py --save_dir my_models --log_dir my_logs
```

### 전체 옵션
```bash
--settings          # Settings INI 파일 경로 (기본: settings.ini)
--max_episodes      # 최대 에피소드 수 (기본: 10000)
--update_interval   # 정책 업데이트 주기 (기본: 2000)
--eval_interval     # 평가 주기 (기본: 500)
--save_dir          # 모델 저장 디렉토리 (기본: models)
--log_dir           # TensorBoard 로그 디렉토리 (기본: logs)
--device            # 디바이스 (cuda/cpu, 기본: auto)
--test_mode         # 테스트 모드 (100 에피소드만 학습)
```

## TensorBoard 모니터링

```bash
tensorboard --logdir=logs
```

**주요 메트릭**:
- `Episode/Reward`: 에피소드별 총 보상
- `Episode/Length`: 에피소드 길이 (생존 년수)
- `Episode/Screenings`: 검진 횟수
- `Episode/CancersDetected`: 검진으로 발견한 암
- `Episode/CancersPrevented`: 용종 제거로 예방한 암
- `Loss/Actor`, `Loss/Critic`, `Loss/Entropy`: 손실 함수
- `Hyperparams/LearningRate`: 현재 학습률
- `Hyperparams/EntropyCoef`: 현재 엔트로피 계수

## 저장된 모델

### Best Model
- **파일**: `models/ppo_optimal_best.pth`
- **기준**: 최근 100 에피소드 평균 보상이 최고일 때
- **포함**: 모델 가중치, 옵티마이저 상태, 에피소드 번호, 보상

### Final Model
- **파일**: `models/ppo_optimal_final.pth`
- **저장**: 학습 완료 시점
- **용도**: 최종 정책 평가

## 모델 불러오기

```python
import torch
from ppo_optimal import ActorCritic

# 모델 생성
policy = ActorCritic(state_dim=16, action_dim=2)

# 체크포인트 로드
checkpoint = torch.load('models/ppo_optimal_best.pth')
policy.load_state_dict(checkpoint['model_state_dict'])
policy.eval()

# 추론
state = env.reset()
with torch.no_grad():
    action, _ = policy.act(state)
```

## 기대 결과

### 학습 곡선
- **초기 (0-1000 에피소드)**: 탐색 단계, 보상 변동 큼
- **중기 (1000-5000)**: 안정화, 점진적 개선
- **후기 (5000-10000)**: 수렴, 최적 정책 도달

### 최적 정책 특성
- **검진 빈도**: 생애 2-4회 (50-80세)
- **검진 타이밍**: 
  - 첫 검진: 50-55세
  - 후속 검진: 10년 간격 (용종 없을 시)
  - 용종 발견 시: 3-5년 간격
- **암 발견율**: 60% 이상 (조기 단계)
- **평균 보상**: 50+ (vs 자연사 기준선)

## 문제 해결

### CUDA Out of Memory
```bash
# 배치 크기 줄이기
self.batch_size = 128
self.mini_batch_size = 32
```

### 학습 불안정
- Learning rate 낮추기: `lr_start = 1e-4`
- Entropy coefficient 높이기: `entropy_coef_start = 0.02`
- Gradient clipping 강화: `max_grad_norm = 0.3`

### 느린 학습
- Update interval 줄이기: `update_interval = 1000`
- K epochs 증가: `K_epochs = 15`
- Network 크기 증가: `hidden_size = 768`

## drl_optimizer.py와의 비교

| 기능 | drl_optimizer.py | ppo_optimal.py |
|-----|------------------|----------------|
| Advantage 계산 | Simple returns | GAE (λ=0.95) |
| 학습 목표 | Medium policy | Optimal policy |
| 에피소드 수 | 3,000 | 10,000-20,000 |
| 네트워크 크기 | 256 units | 512 units |
| 정규화 | 없음 | LayerNorm + Dropout |
| LR 스케줄링 | 없음 | Cosine annealing |
| 엔트로피 | 고정 | Decay (0.01→0.001) |
| 로깅 | 없음 | TensorBoard |
| 체크포인트 | 마지막만 | Best + Final |
| 보상 설계 | 기본 | 향상됨 (조기발견 보너스) |

## 다음 단계

1. **학습 실행**: `python ppo_optimal.py --max_episodes 10000`
2. **모니터링**: TensorBoard로 학습 진행 상황 확인
3. **평가**: Best model로 시뮬레이션 실행
4. **비교**: Baseline, drl_optimizer와 성능 비교
5. **하이퍼파라미터 튜닝**: 필요 시 파라미터 조정
