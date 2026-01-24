import time
import multiprocessing
import numpy as np
import sys

# -----------------------------------------------------------
# [1] 모든 모듈 임포트
# -----------------------------------------------------------
from parameters import SimulationParameters
from output import Output
from entities import Person

# 각 최적화 모듈 (파일이 모두 존재해야 함)
from optimizer import GeneticOptimizer      # Mode 1
from dp_optimizer import DPOptimizer        # Mode 4
from drl_optimizer import PPOOptimizer      # Mode 5 (New)
from cql_optimizer import CQLOptimizer      # Mode 6 (New)

def worker_simulation(args):
    """개별 프로세스가 수행하는 시뮬레이션 작업 (Mode 2, 3용)"""
    seed, num_people, params_file, moments, compliance = args
    params = SimulationParameters(params_file)
    rng = np.random.default_rng(seed)
    local_output = Output(params)
    
    for _ in range(num_people):
        p = Person(params, rng)
        p.simulate(local_output)
        if moments is not None:
            p.evaluate_strategy(moments, local_output, compliance)
    return local_output

def run_simulation(name, moments, compliance, params, pop_size):
    """멀티프로세싱 관리 및 결과 취합 함수"""
    print(f"\n>>> Running: {name}")
    if len(moments) > 0:
        print(f"    Schedule: {moments}, Compliance: {compliance:.2f}")
    else:
        print("    Schedule: None (Natural History)")

    start = time.time()
    n_cpus = params.n_cpus
    people_per = pop_size // n_cpus
    tasks = []
    
    for i in range(n_cpus):
        cnt = people_per + (1 if i < pop_size % n_cpus else 0)
        tasks.append((params.rng_seed + i, cnt, 'settings.ini', moments, compliance))

    with multiprocessing.Pool(processes=n_cpus) as pool:
        results = pool.map(worker_simulation, tasks)

    total_out = Output(params)
    for res in results:
        total_out.add_results(res)
        
    print(f"    Done. (Time: {time.time()-start:.2f}s)")
    return total_out

def main():
    settings_file = 'settings.ini'
    try:
        params = SimulationParameters(settings_file)
    except Exception as e:
        print(f"Error loading settings: {e}")
        print("Make sure 'settings.ini' and the 'InputFiles' folder exist.")
        return

    print("="*60)
    print("          CMOST Python Simulator (Integrated Mode)")
    print(f"          Population Size: {params.population_size}")
    print("="*60)
    
    # -----------------------------------------------------------
    # [2] 통합 메뉴 출력
    # -----------------------------------------------------------
    print("\nSelect Mode:")
    print("  [1] Genetic Algorithm Optimization (Classic)")
    print("  [2] Evaluate Screening Scenarios (From INI)")
    print("  [3] Run Baseline (No Screening)")
    print("  [4] Dynamic Programming (Simulation-based DP)")
    print("  [5] ★ Deep RL (PPO) - Online Learning")
    print("  [6] ★ Offline RL (CQL) - Data-Driven")
    print("  [0] Exit")
    
    choice = input("\nEnter choice (1-6, 0): ").strip()

    # --- [Mode 1] Genetic Optimization ---
    if choice == '1':
        print("\n" + "-"*60)
        print(" [MODE 1] Genetic Algorithm Optimization Selected")
        print("-" * 60)
        opt_pop_size = 10000 
        print(f"Optimization Population: {opt_pop_size}")
        
        opt = GeneticOptimizer(settings_file, params.n_cpus, pop_size_sim=opt_pop_size)
        opt.run_optimization()

    # --- [Mode 2] Screening Scenarios ---
    elif choice == '2':
        print("\n" + "-"*60)
        print(" [MODE 2] Screening Scenarios Evaluation Selected")
        print("-" * 60)
        
        if not params.screening_scenarios:
            print("Error: No scenarios found in 'screeningVarAdherence.ini'.")
            return

        print("Running Baseline for comparison...")
        base = run_simulation("Baseline", [], 0.0, params, params.population_size)
        base_inc = base.cancers_count
        base_ly = base.total_person_years
        base_cost = base.total_discounted_cost
        
        print("-" * 85)
        print(f"{'Scenario':<10} | {'Incidence':<10} | {'Red(%)':<8} | {'LYG':<10} | {'Cost($)':<12} | {'ICER':<10}")
        print("-" * 85)

        for sc in params.screening_scenarios:
            res = run_simulation(sc['name'], sc['moments'], sc['compliance'], params, params.population_size)
            
            inc_red = (1 - res.cancers_count/base_inc)*100 if base_inc > 0 else 0
            lyg = res.total_person_years - base_ly
            cost_diff = res.total_discounted_cost - base_cost
            icer = cost_diff / lyg if lyg > 0 else 0.0
            
            print(f"{sc['name']:<10} | {res.cancers_count:<10} | {inc_red:8.2f} | {lyg:<10.1f} | {res.total_discounted_cost:,.0f} | {icer:,.0f}")

    # --- [Mode 3] Baseline Only ---
    elif choice == '3':
        print("\n" + "-"*60)
        print(" [MODE 3] Baseline Simulation Selected")
        print("-" * 60)
        base = run_simulation("Baseline", [], 0.0, params, params.population_size)
        print(f"\n[Result] Total Cancers: {base.cancers_count}")
        print(f"[Result] Total Discounted Cost: ${base.total_discounted_cost:,.0f}")

    # --- [Mode 4] Dynamic Programming ---
    elif choice == '4':
        print("\n" + "-"*60)
        print(" [MODE 4] Dynamic Programming (DP) Selected")
        print("          Method: Backward Induction with Simulation Probabilities")
        print("-" * 60)
        
        dp = DPOptimizer(settings_file)
        dp.solve()
        dp.print_optimal_policy()

    # --- [Mode 5] Deep RL (PPO) ---
    elif choice == '5':
        print("\n" + "-"*60)
        print(" [MODE 5] Deep RL (PPO) Selected")
        print("          Algorithm: Proximal Policy Optimization")
        print("          State Dim: 17 (Including 13 Zones Info)")
        print("-" * 60)
        
        # 학습 횟수 설정 (시간 관계상 3000회 설정, 필요시 증가)
        drl = PPOOptimizer(settings_file)
        drl.train(max_episodes=3000)
        drl.print_sample_decisions()

    # --- [Mode 6] Offline RL (CQL) ---
    elif choice == '6':
        print("\n" + "-"*60)
        print(" [MODE 6] Offline RL (CQL) Selected")
        print("          Algorithm: Conservative Q-Learning")
        print("          Step 1: Generate Offline Dataset (Replay Buffer)")
        print("          Step 2: Train Q-Network without interaction")
        print("-" * 60)
        
        cql = CQLOptimizer(settings_file)
        cql.train(iterations=100000)
        cql.print_sample_decisions()

    # --- Exit ---
    elif choice == '0':
        print("Exiting...")
        sys.exit()
    
    else:
        print("Invalid choice. Please run again.")

if __name__ == '__main__':
    multiprocessing.freeze_support()
    main()