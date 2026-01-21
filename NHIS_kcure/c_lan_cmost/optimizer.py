import numpy as np
from scipy.optimize import differential_evolution
import multiprocessing
from parameters import SimulationParameters
from output import Output
from entities import Person

def worker_simulation_opt(args):
    seed, num_people, params_file, moments, compliance = args
    params = SimulationParameters(params_file)
    rng = np.random.default_rng(seed)
    local_output = Output(params)
    for _ in range(num_people):
        p = Person(params, rng)
        p.simulate(local_output)
        if moments:
            p.evaluate_strategy(moments, local_output, compliance)
    return local_output

class GeneticOptimizer:
    def __init__(self, settings_file, n_cpus, pop_size_sim):
        self.params = SimulationParameters(settings_file)
        self.settings_file = settings_file
        self.n_cpus = n_cpus
        self.pop_size_sim = pop_size_sim
        self.iteration = 0
        self.ndim = self.params.opt_num_colo

    def run_scenario_internal(self, moments):
        people_per = self.pop_size_sim // self.n_cpus
        tasks = []
        base_seed = 12345
        for i in range(self.n_cpus):
            cnt = people_per + (1 if i < self.pop_size_sim % self.n_cpus else 0)
            # 최적화 중에는 Compliance 1.0 (완벽한 이행 가정)
            tasks.append((base_seed + i, cnt, self.settings_file, moments, 1.0))

        with multiprocessing.Pool(processes=self.n_cpus) as pool:
            results = pool.map(worker_simulation_opt, tasks)
        total_out = Output(self.params)
        for res in results: total_out.add_results(res)
        return total_out

    def objective_function(self, x):
        self.iteration += 1
        schedule = sorted([int(round(val)) for val in x])
        if len(set(schedule)) < len(schedule): return 9e9

        res = self.run_scenario_internal(schedule)
        
        # Goals: 1=Mortality, 2=Incidence, 3=LYG, 4=Cost
        goal = self.params.opt_goals[0]
        score = 0.0
        
        if goal == 1: score = float(res.cancer_deaths)
        elif goal == 2: score = float(res.cancers_count)
        elif goal == 3: score = -float(res.total_person_years) # Maximize LYG
        elif goal == 4: score = float(res.total_discounted_cost)
        
        disp_score = -score if goal == 3 else score
        # 너무 잦은 출력 방지 (5번마다)
        if self.iteration % 5 == 0:
            print(f" [Iter {self.iteration}] Sched: {schedule} -> Score: {disp_score:,.1f}")
        return score

    def run_optimization(self):
        print(f"\n>>> Starting Optimization (Goals={self.params.opt_goals})")
        
        bounds = [(self.params.opt_min_age, self.params.opt_max_age)] * self.ndim
        
        res = differential_evolution(
            self.objective_function, bounds, strategy='best1bin',
            maxiter=15, popsize=10, tol=0.01, workers=1
        )
        
        best_sched = sorted([int(round(x)) for x in res.x])
        final_val = -res.fun if self.params.opt_goals[0] == 3 else res.fun
        print(f"\n✅ Optimization Done! Best Schedule: {best_sched}, Score: {final_val:,.1f}")