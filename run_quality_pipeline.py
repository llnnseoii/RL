"""
Complete Pipeline: PPO Training → Quality Labeling → Mixed Dataset → CQL Training

전체 workflow를 실행하는 통합 스크립트입니다.
"""

import numpy as np
from parameters import SimulationParameters

# 새로 생성한 모듈들
from ppo_variants import train_and_collect_all_variants
from quality_dataset import MixedDatasetGenerator, extract_transitions_from_episodes
from cql_optimizer import CQLOptimizer


def run_complete_pipeline():
    """
    Complete Pipeline 실행
    
    단계:
    1. PPO 학습 + Episode 수집 (각 variant별 1000 training, 1000 collection)
    2. Quality 라벨링 (GOOD/MEDIUM/BAD)
    3. Mixed Dataset 생성 (50% good, 30% medium, 20% bad)
    4. CQL 학습
    """
    print("="*70)
    print("  Complete PPO→CQL Pipeline with Actual Training")
    print("  Step 1: Train 3 PPO Variants + Collect Episodes")
    print("  Step 2: Label Quality (GOOD/MEDIUM/BAD)")
    print("  Step 3: Create Mixed Dataset (50/30/20)")
    print("  Step 4: Train CQL with Mixed Data")
    print("="*70)
    
    # Parameters
    params = SimulationParameters('settings.ini')
    
    # ========== Step 1: Train PPO & Collect Episodes ==========
    print("\n" + "="*70)
    print("STEP 1: Training PPO Variants & Collecting Episodes")
    print("="*70)
    print("  - Conservative PPO: 1000 train → 1000 collect")
    print("  - Balanced PPO: 1000 train → 1000 collect")
    print("  - Aggressive PPO: 1000 train → 1000 collect")
    print("  ⏱️  예상 시간: ~60분")
    print("="*70)
    
    all_episodes = train_and_collect_all_variants(
        params,
        episodes_per_variant=1000,    # 수집할 episodes
        training_episodes=1000,        # PPO 학습 episodes
        save_path='diverse_ppo_data.pkl'
    )
    
    print(f"\n✅ 총 {len(all_episodes)} episodes 수집 완료")
    
    # ========== Step 2: Quality Labeling ==========
    print("\n" + "="*70)
    print("STEP 2: Quality Labeling")
    print("="*70)
    
    generator = MixedDatasetGenerator(
        good_ratio=0.5,
        medium_ratio=0.3,
        bad_ratio=0.2
    )
    
    categorized = generator.collect_and_label_episodes(all_episodes)
    
    # ========== Step 3: Create Mixed Dataset ==========
    print("\n" + "="*70)
    print("STEP 3: Creating Mixed Dataset")
    print("="*70)
    
    total_dataset_size = 3000
    mixed_episodes = generator.create_mixed_dataset(
        categorized,
        total_size=total_dataset_size
    )
    
    # Save mixed dataset
    generator.save_dataset(mixed_episodes, 'mixed_dataset_50_30_20.pkl')
    
    # Extract transitions for CQL
    print("\n🔄 Extracting transitions from episodes...")
    all_transitions = extract_transitions_from_episodes(mixed_episodes)
    print(f"✅ {len(all_transitions)} transitions 추출 완료")
    
    # ========== Step 4: Train CQL ==========
    print("\n" + "="*70)
    print("STEP 4: Training CQL with Mixed Dataset")
    print("="*70)
    
    cql = CQLOptimizer('settings.ini')
    cql.train_from_transitions(
        transitions=all_transitions,
        epochs=100,
        batch_size=256,
        alpha=1.0  # CQL penalty weight
    )
    
    # Save CQL model
    cql.save_model('cql_from_mixed_50_30_20.pth')
    
    print("\n" + "="*70)
    print("  ✅ Complete Pipeline 완료!")
    print("="*70)
    print(f"  📂 Diverse Episodes: diverse_ppo_data.pkl")
    print(f"  📂 PPO Models: ppo_conservative.pth, ppo_balanced.pth, ppo_aggressive.pth")
    print(f"  📂 Mixed Dataset: mixed_dataset_50_30_20.pkl")
    print(f"  📂 CQL Model: cql_from_mixed_50_30_20.pth")
    print("="*70)


def run_step_by_step():
    """단계별로 실행 (디버깅용)"""
    import sys
    
    print("\n단계별 실행 모드")
    print("1. PPO 학습 + 데이터 수집 (Conservative, Balanced, Aggressive)")
    print("2. Quality Labeling만 (기존 diverse_ppo_data.pkl 사용)")
    print("3. Mixed Dataset 생성만")
    print("4. CQL 학습만")
    print("5. 전체 실행")
    
    choice = input("\n선택 (1-5): ")
    
    params = SimulationParameters('settings.ini')
    
    if choice == '1':
        print("\n🎓 PPO 학습 + 데이터 수집...")
        all_episodes = train_and_collect_all_variants(
            params, 
            episodes_per_variant=1000,
            training_episodes=1000
        )
        
    elif choice == '2':
        print("\n🏷️  Quality Labeling...")
        import pickle
        with open('diverse_ppo_data.pkl', 'rb') as f:
            all_episodes = pickle.load(f)
        
        generator = MixedDatasetGenerator(0.5, 0.3, 0.2)
        categorized = generator.collect_and_label_episodes(all_episodes)
        
        # Stats
        for quality in ['GOOD', 'MEDIUM', 'BAD']:
            if quality in categorized:
                rewards = [e['total_reward'] for e in categorized[quality]]
                costs = [e['total_cost'] for e in categorized[quality]]
                print(f"  {quality}: Avg Reward = {np.mean(rewards):.2f}, Avg Cost = ${np.mean(costs):.0f}")
        
    elif choice == '3':
        print("\n🎲 Mixed Dataset 생성...")
        import pickle
        with open('diverse_ppo_data.pkl', 'rb') as f:
            all_episodes = pickle.load(f)
        
        generator = MixedDatasetGenerator(0.5, 0.3, 0.2)
        categorized = generator.collect_and_label_episodes(all_episodes)
        mixed = generator.create_mixed_dataset(categorized, 3000)
        generator.save_dataset(mixed, 'mixed_dataset_50_30_20.pkl')
        
    elif choice == '4':
        print("\n🤖 CQL 학습...")
        import pickle
        with open('mixed_dataset_50_30_20.pkl', 'rb') as f:
            mixed_episodes = pickle.load(f)
        
        transitions = extract_transitions_from_episodes(mixed_episodes)
        cql = CQLOptimizer('settings.ini')
        cql.train_from_transitions(transitions, epochs=100)
        cql.save_model('cql_from_mixed_50_30_20.pth')
        
    elif choice == '5':
        run_complete_pipeline()
    
    else:
        print("잘못된 선택입니다.")


if __name__ == "__main__":
    import sys
    
    if len(sys.argv) > 1 and sys.argv[1] == '--step':
        run_step_by_step()
    else:
        run_complete_pipeline()
