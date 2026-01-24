"""
PPO Reward 파라미터 조정 방안
"""

# 현재 설정 (검진 1.1%)
conservative_current = {
    'cost_penalty': 0.10,      # 검진 시 큰 penalty
    'survival_reward': 0.1,    # 작은 생존 보상
    'cancer_bonus': 0.0        # 암 발견 보상 없음
}

# 제안1: 검진을 더 장려하는 방향
conservative_new = {
    'cost_penalty': 0.03,      # penalty 감소 (0.10 → 0.03)
    'survival_reward': 0.05,   # 약간 감소
    'cancer_bonus': 15.0,      # 암 발견 시 큰 보상 추가
    'polyp_bonus': 5.0         # 용종 발견 시 보상 추가
}

balanced_new = {
    'cost_penalty': 0.02,
    'survival_reward': 0.05,
    'cancer_bonus': 20.0,
    'polyp_bonus': 8.0
}

aggressive_new = {
    'cost_penalty': 0.01,      # penalty 최소화
    'survival_reward': 0.05,
    'cancer_bonus': 30.0,      # 매우 큰 보상
    'polyp_bonus': 12.0
}

# 제안2: Exploration 강화
# - Epsilon-greedy 추가 (탐험 확률 20%)
# - 또는 training 초반에 강제로 screen action 비율 높이기
