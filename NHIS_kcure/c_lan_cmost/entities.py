import numpy as np

# Polyp 클래스는 그대로 사용 (Fast Cancer 로직 포함된 버전)
class Polyp:
    def __init__(self, age, gender, params, rng):
        self.age_developed = age
        self.stage = params.initial_polyp_stage
        self.location = self._determine_location(params, rng)
        self.age_end = params.years_to_simulate
        self.cancer_ref = None
        self.history = [] 
        
        idx = int(rng.random() * len(params.early_polyp_progression))
        self.indiv_early_risk = params.early_polyp_progression[idx]
        idx2 = int(rng.random() * len(params.adv_polyp_progression))
        self.indiv_adv_risk = params.adv_polyp_progression[idx2]

        if self.location < len(params.loc_early_prog):
            self.indiv_early_risk *= params.loc_early_prog[self.location]
            self.indiv_adv_risk *= params.loc_adv_prog[self.location]
            
        if gender == 1: 
            self.indiv_early_risk *= params.female_early_prog
            self.indiv_adv_risk *= params.female_adv_prog

    def _determine_location(self, params, rng):
        u = rng.random()
        loc = 0
        while loc < len(params.new_polyp_location) and u > params.new_polyp_location[loc]:
            loc += 1
        return loc

    def simulate(self, params, rng, cancers_list, gender):
        t = self.age_developed
        max_age_idx = len(params.polyp_progression_rates[0]) - 1
        
        while t < params.years_to_simulate:
            current_stage = self.stage
            age_idx = min(int(t), max_age_idx)
            
            base_prob = params.polyp_progression_rates[self.stage - 1][age_idx]
            multiplier = self.indiv_adv_risk if self.stage >= params.adv_polyp_transition else self.indiv_early_risk
            progression_prob = base_prob * multiplier

            if rng.random() < progression_prob:
                self.stage += 1
                if self.stage > params.num_polyp_stages:
                    new_cancer = Cancer(t, gender, params, rng, origin_polyp=self)
                    cancers_list.append(new_cancer)
                    self.cancer_ref = new_cancer
                    self.age_end = t
                    cancer_code = 10 + new_cancer.symptoms_stage
                    self.history.append((t, current_stage, cancer_code))
                    return 
                
                self.history.append((t, current_stage, self.stage))
                t += params.dt 
                continue 

            fast_cancer_prob = 0.0
            if (self.stage - 1) < len(params.fast_cancer_rates):
                 fast_cancer_prob = params.fast_cancer_rates[self.stage - 1]
            
            if rng.random() < fast_cancer_prob:
                new_cancer = Cancer(t, gender, params, rng, origin_polyp=self)
                cancers_list.append(new_cancer)
                self.cancer_ref = new_cancer
                self.age_end = t
                cancer_code = 10 + new_cancer.symptoms_stage
                self.history.append((t, current_stage, cancer_code))
                return 
            
            if self.stage > 0 and (self.stage-1 < len(params.healing_rates)):
                if rng.random() < params.healing_rates[self.stage-1]:
                    self.stage -= 1
                    self.history.append((t, current_stage, self.stage))
                    if self.stage == 0: 
                        self.age_end = t
                        return 
            t += params.dt
        self.age_end = t

class Cancer:
    def __init__(self, age, gender, params, rng, origin_polyp=None):
        self.age_developed = age
        self.detected = False
        self.prevented = False
        self.origin_polyp = origin_polyp
        if origin_polyp: self.location = origin_polyp.location
        else: self.location = int(rng.random() * 13) 

        self.symptoms_stage = self._determine_symptoms_stage(age, gender, params, rng)
        self.symptoms_age = self._calc_symptoms_age(age, self.symptoms_stage, params, rng)
        self.mortality_time = self._generate_mortality_time(gender, age, self.symptoms_stage, params, rng)

    def _determine_symptoms_stage(self, age, gender, params, rng):
        age_idx = min(int(age / 5), len(params.frac_stage1)-1)
        p1 = params.frac_stage1[age_idx]
        p2 = params.frac_stage2[age_idx]
        p3 = params.frac_stage3[age_idx]
        p4 = params.frac_stage4[age_idx]
        total = p1 + p2 + p3 + p4
        if total == 0: return 1
        r = rng.random() * total
        if r < p1: return 1
        elif r < p1 + p2: return 2
        elif r < p1 + p2 + p3: return 3
        else: return 4

    def _calc_symptoms_age(self, start_age, sym_stage, params, rng):
        cdf = params.sojourn_cdf[sym_stage - 1]
        u = rng.random()
        idx = np.searchsorted(cdf, u)
        return start_age + (idx + 1) * params.dt

    def _generate_mortality_time(self, gender, age, stage, params, rng):
        age_group = 0
        for i in range(len(params.os_age_ranges)):
            if age >= params.os_age_ranges[i]: age_group += 1
            else: break
        age_group = min(age_group, params.n_age_groups - 1)
        idx_start = int(gender) * params.num_data_points_per_surv_curve * params.n_age_groups * 4
        idx_start += (int(stage) - 1) * params.num_data_points_per_surv_curve * params.n_age_groups
        idx_start += age_group * params.num_data_points_per_surv_curve
        end_idx = min(idx_start + params.survival_cutoff, len(params.os_by_gender_age_stage))
        os_curve = params.os_by_gender_age_stage[idx_start : end_idx]
        
        r = rng.random()
        mort_years = 0
        for prob in os_curve:
            if r > prob: mort_years += 1
            else: break
        if mort_years >= len(os_curve): return 999.0 
        return age + float(mort_years) + rng.random()

class Person:
    def __init__(self, params, rng):
        self.params = params
        self.rng = rng
        self.gender = 1 if rng.random() < params.fraction_female else 0
        self.polyps = []
        self.cancers = []
        
        lt = self.params.life_table_females_cum if self.gender == 1 else self.params.life_table_males_cum
        death_idx = np.searchsorted(lt, self.rng.random())
        self.natural_death_age = death_idx + self.rng.random()
        self.death_age = self.natural_death_age
        
        idx = int(rng.random() * len(params.individual_polyp_risk))
        self.risk_factor = params.individual_polyp_risk[idx]
        if self.gender == 1: self.risk_factor *= params.female_new_polyp_risk

    def simulate(self, output=None):
        max_age = min(int(self.natural_death_age), int(self.params.years_to_simulate))
        steps_per_year = int(1.0 / self.params.dt)
        
        for age in range(max_age):
            risk_polyp = self.params.general_new_polyps_risk[age] if age < len(self.params.general_new_polyps_risk) else 0
            risk_cancer_list = self.params.direct_cancer_risk_female if self.gender == 1 else self.params.direct_cancer_risk_male
            risk_cancer = risk_cancer_list[age] if age < len(risk_cancer_list) else 0
            risk_cancer *= self.params.direct_cancer_speed 

            for _ in range(steps_per_year):
                if self.rng.random() < (self.risk_factor * risk_polyp):
                    t = age + self.rng.random() * self.params.dt
                    self.polyps.append(Polyp(t, self.gender, self.params, self.rng))
                if self.rng.random() < risk_cancer:
                    t = age + self.rng.random() * self.params.dt
                    self.cancers.append(Cancer(t, self.gender, self.params, self.rng))

        earliest_cancer_death = 999.0
        for p in self.polyps:
            p.simulate(self.params, self.rng, self.cancers, self.gender)
            if output: output.polyps_count += 1
            
        for c in self.cancers:
            if c.mortality_time > c.age_developed and c.mortality_time < earliest_cancer_death:
                earliest_cancer_death = c.mortality_time

        if earliest_cancer_death < self.natural_death_age:
            self.death_age = earliest_cancer_death
            if output: output.cancer_deaths += 1

        if output:
            output.total_person_years += min(self.death_age, self.params.years_to_simulate)
            for c in self.cancers:
                if c.age_developed < self.death_age:
                    output.cancers_count += 1
                    # ★ [Cost] 암 초기 치료비
                    output.record_event_cost(c.age_developed, 'CANCER_INIT', c.symptoms_stage)
                    
                    if c.mortality_time < self.natural_death_age:
                        # ★ [Cost] 암 말기(사망 전) 치료비
                        output.record_event_cost(c.mortality_time, 'CANCER_FINAL', c.symptoms_stage)

    def evaluate_strategy(self, screening_moments, output, compliance=1.0):
        schedule = sorted(screening_moments)
        self.cancers.sort(key=lambda x: x.symptoms_age)
        current_age = 0.0
        
        while current_age < self.death_age:
            next_screening = schedule[0] if schedule else 999.0
            next_symptom = 999.0
            symptom_cancer = None
            
            for c in self.cancers:
                if not c.prevented and not c.detected and c.symptoms_age > current_age:
                    next_symptom = c.symptoms_age
                    symptom_cancer = c
                    break
            
            event_time = min(next_screening, next_symptom)
            if event_time >= self.death_age: break
            current_age = event_time
            
            if next_screening <= next_symptom:
                schedule.pop(0)
                # ★ [Compliance] 순응도에 따른 검사 여부 결정
                if self.rng.random() < compliance:
                    self._perform_colonoscopy(current_age, output, is_screening=True)
            else:
                if symptom_cancer:
                    output.symptom_detections += 1
                    symptom_cancer.detected = True
                    # 증상 발견 진단 비용
                    output.record_event_cost(current_age, 'COLONOSCOPY')

    def _perform_colonoscopy(self, age, output, is_screening=False):
        if is_screening: output.screening_counts += 1
        
        # ★ [Cost] 기본 내시경 비용
        output.record_event_cost(age, 'COLONOSCOPY')

        # [Risks] 합병증
        if self.rng.random() < self.params.risk_perforation:
            output.record_event_cost(age, 'PERFORATION')
            output.compl_perforations += 1
            if self.rng.random() < self.params.death_perforation:
                self.death_age = age
                return
        
        if self.rng.random() < self.params.risk_bleeding:
            output.record_event_cost(age, 'BLEEDING')
            output.compl_bleedings += 1

        reach_prob = 1.0
        if len(self.params.colo_reach) > 0: reach_prob = self.params.colo_reach[-1]
        if self.rng.random() > reach_prob: return 

        has_polyp_found = False
        has_cancer_found = False
        
        for p in self.polyps:
            if p.age_developed <= age < p.age_end and p.cancer_ref is None:
                det_idx = min(p.stage-1, len(self.params.colo_det_polyp)-1)
                sens = self.params.colo_det_polyp[det_idx]
                if self.rng.random() < sens:
                    p.age_end = age
                    if p.cancer_ref: p.cancer_ref.prevented = True
                    has_polyp_found = True
        
        for c in self.cancers:
            if not c.prevented and not c.detected and c.age_developed <= age:
                if self.rng.random() < 0.95: 
                    c.detected = True
                    if is_screening: output.screen_detections += 1
                    has_cancer_found = True
                    
        # ★ [Cost] 발견 시 추가 비용 (차액)
        if has_cancer_found:
            output.record_event_cost(age, 'COLO_CANCER')
        elif has_polyp_found:
            output.record_event_cost(age, 'COLO_POLYP')