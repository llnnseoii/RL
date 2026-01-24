"""
Quality-based Dataset Labeling and Mixing for CQL

이 모듈은 PPO로 수집한 데이터를 quality에 따라 라벨링하고,
지정된 비율로 섞어서 CQL 학습용 데이터셋을 생성합니다.
"""

import numpy as np
import torch
import pickle
from typing import List, Dict, Tuple
from collections import defaultdict


class QualityLabeler:
    """Episode 데이터를 quality (GOOD/MEDIUM/BAD)로 라벨링"""
    
    def __init__(self, good_threshold=0.7, medium_threshold=0.4):
        self.good_threshold = good_threshold
        self.medium_threshold = medium_threshold
    
    def calculate_quality_score(self, episode_data: Dict) -> float:
        """
        Episode의 quality score 계산
        
        Args:
            episode_data: {
                'total_reward': float,
                'life_years_gained': float,
                'total_cost': float,
                'cancer_detected': bool,
                'num_screenings': int
            }
        
        Returns:
            0.0 ~ 1.0 사이의 quality score
        """
        # 정규화 (대략적인 범위 기반)
        reward_norm = self._normalize(episode_data['total_reward'], -5.0, 5.0)
        lyg_norm = self._normalize(episode_data['life_years_gained'], 0, 50)
        cost_norm = 1.0 - self._normalize(episode_data['total_cost'], 0, 50000)  # 비용 낮을수록 좋음
        
        # 암 발견 보너스
        cancer_bonus = 0.1 if episode_data.get('cancer_detected', False) else 0.0
        
        # 검진 횟수 페널티 (너무 많으면 감점)
        screening_penalty = 0.0
        if episode_data['num_screenings'] > 10:
            screening_penalty = -0.1
        
        # 가중 평균
        score = (
            0.4 * reward_norm +
            0.3 * lyg_norm +
            0.2 * cost_norm +
            cancer_bonus +
            screening_penalty
        )
        
        return np.clip(score, 0.0, 1.0)
    
    def _normalize(self, value, min_val, max_val):
        """값을 0~1 범위로 정규화"""
        return np.clip((value - min_val) / (max_val - min_val), 0.0, 1.0)
    
    def label_quality(self, episode_data: Dict) -> str:
        """
        Episode를 GOOD/MEDIUM/BAD로 분류
        
        Returns:
            'GOOD', 'MEDIUM', or 'BAD'
        """
        score = self.calculate_quality_score(episode_data)
        
        if score >= self.good_threshold:
            return 'GOOD'
        elif score >= self.medium_threshold:
            return 'MEDIUM'
        else:
            return 'BAD'


class MixedDatasetGenerator:
    """Quality 기반으로 데이터셋을 섞어서 생성"""
    
    def __init__(self, good_ratio=0.5, medium_ratio=0.3, bad_ratio=0.2):
        """
        Args:
            good_ratio: 좋은 데이터 비율 (default: 0.5)
            medium_ratio: 중간 데이터 비율 (default: 0.3)
            bad_ratio: 나쁜 데이터 비율 (default: 0.2)
        """
        assert abs(good_ratio + medium_ratio + bad_ratio - 1.0) < 1e-6, "비율 합이 1.0이 아닙니다!"
        
        self.good_ratio = good_ratio
        self.medium_ratio = medium_ratio
        self.bad_ratio = bad_ratio
        self.labeler = QualityLabeler()
    
    def collect_and_label_episodes(self, episodes: List[Dict]) -> Dict[str, List]:
        """
        Episode들을 quality별로 분류
        
        Args:
            episodes: PPO로 수집한 episode 데이터 리스트
        
        Returns:
            {
                'GOOD': [...],
                'MEDIUM': [...],
                'BAD': [...]
            }
        """
        categorized = defaultdict(list)
        
        for episode in episodes:
            quality = self.labeler.label_quality(episode)
            categorized[quality].append(episode)
        
        print(f"📊 Quality 분포:")
        print(f"  GOOD: {len(categorized['GOOD'])} episodes")
        print(f"  MEDIUM: {len(categorized['MEDIUM'])} episodes")
        print(f"  BAD: {len(categorized['BAD'])} episodes")
        
        return dict(categorized)
    
    def create_mixed_dataset(self, categorized_data: Dict[str, List], 
                            total_size: int = 3000) -> List[Dict]:
        """
        지정된 비율로 데이터셋 생성
        
        Args:
            categorized_data: Quality별로 분류된 데이터
            total_size: 최종 데이터셋 크기
        
        Returns:
            섞인 데이터셋 리스트
        """
        good_size = int(total_size * self.good_ratio)
        medium_size = int(total_size * self.medium_ratio)
        bad_size = total_size - good_size - medium_size
        
        print(f"🎯 Mixed Dataset 구성 (총 {total_size}):")
        print(f"  GOOD: {good_size} ({self.good_ratio*100:.0f}%)")
        print(f"  MEDIUM: {medium_size} ({self.medium_ratio*100:.0f}%)")
        print(f"  BAD: {bad_size} ({self.bad_ratio*100:.0f}%)")
        
        mixed = []
        
        # GOOD 데이터 샘플링
        good_data = categorized_data.get('GOOD', [])
        if len(good_data) >= good_size:
            sampled = np.random.choice(good_data, good_size, replace=False).tolist()
        else:
            print(f"⚠️  GOOD 데이터 부족: {len(good_data)} < {good_size}, 중복 허용")
            sampled = np.random.choice(good_data, good_size, replace=True).tolist()
        
        # Quality label 추가
        for ep in sampled:
            ep['quality'] = 'GOOD'
        mixed.extend(sampled)
        
        # MEDIUM 데이터 샘플링
        medium_data = categorized_data.get('MEDIUM', [])
        if len(medium_data) >= medium_size:
            sampled = np.random.choice(medium_data, medium_size, replace=False).tolist()
        else:
            print(f"⚠️  MEDIUM 데이터 부족: {len(medium_data)} < {medium_size}, 중복 허용")
            sampled = np.random.choice(medium_data, medium_size, replace=True).tolist()
        
        # Quality label 추가
        for ep in sampled:
            ep['quality'] = 'MEDIUM'
        mixed.extend(sampled)
        
        # BAD 데이터 샘플링
        bad_data = categorized_data.get('BAD', [])
        if len(bad_data) >= bad_size:
            sampled = np.random.choice(bad_data, bad_size, replace=False).tolist()
        else:
            print(f"⚠️  BAD 데이터 부족: {len(bad_data)} < {bad_size}, 중복 허용")
            sampled = np.random.choice(bad_data, bad_size, replace=True).tolist()
        
        # Quality label 추가
        for ep in sampled:
            ep['quality'] = 'BAD'
        mixed.extend(sampled)
        
        # 섞기
        np.random.shuffle(mixed)
        
        print(f"✅ Mixed Dataset 생성 완료: {len(mixed)} episodes")
        
        return mixed
    
    def save_dataset(self, dataset: List[Dict], filepath: str):
        """데이터셋 저장"""
        with open(filepath, 'wb') as f:
            pickle.dump(dataset, f)
        print(f"💾 Dataset saved to: {filepath}")
    
    def load_dataset(self, filepath: str) -> List[Dict]:
        """데이터셋 로드"""
        with open(filepath, 'rb') as f:
            dataset = pickle.load(f)
        print(f"📂 Dataset loaded from: {filepath}")
        return dataset


def extract_transitions_from_episodes(episodes: List[Dict]) -> List[Dict]:
    """
    Episode 데이터를 transition 형태로 변환
    
    Args:
        episodes: Episode 데이터 리스트
    
    Returns:
        CQL 학습용 transition 리스트
        각 transition: {
            'state': np.array,
            'action': int,
            'reward': float,
            'next_state': np.array,
            'done': bool,
            'quality': str
        }
    """
    all_transitions = []
    
    for episode in episodes:
        quality = episode['quality']
        transitions = episode['transitions']
        
        for trans in transitions:
            trans['quality'] = quality
            all_transitions.append(trans)
    
    return all_transitions


# ==================== 사용 예시 ====================
if __name__ == "__main__":
    # 예시 데이터
    example_episodes = [
        {
            'total_reward': 3.5,
            'life_years_gained': 35,
            'total_cost': 5000,
            'cancer_detected': True,
            'num_screenings': 3,
            'transitions': [...]  # 실제 state, action, reward 데이터
        },
        # ... more episodes
    ]
    
    # Generator 생성 (50% good, 30% medium, 20% bad)
    generator = MixedDatasetGenerator(
        good_ratio=0.5,
        medium_ratio=0.3,
        bad_ratio=0.2
    )
    
    # Quality 분류
    categorized = generator.collect_and_label_episodes(example_episodes)
    
    # Mixed dataset 생성
    mixed_dataset = generator.create_mixed_dataset(categorized, total_size=3000)
    
    # 저장
    generator.save_dataset(mixed_dataset, 'mixed_dataset_50_30_20.pkl')
