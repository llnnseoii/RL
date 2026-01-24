import numpy as np

# ============================================================================
# 수정 1: Polyp 클래스 - Correlation 플래그 적용 + stage_at_colonoscopy 추가
# ============================================================================
class Polyp:
    def __init__(self, age, gender, params, rng):
        self.age_developed = age
        self.stage = params.initial_polyp_stage
        self.location = self._determine_location(params, rng)
        self.age_end = params.years_to_simulate
        self.cancer_ref = None
        self.history = [] 
        
        # ★★★ 수정: Correlation 플래그 적용 (기존 36-37줄)
        # 변경 전: idx2 = int(rng.random() * len(params.adv_polyp_progression))
        # 변경 후: params.correlation 체크하여 같은 idx 사용
        idx = int(rng.random() * len(params.early_polyp_progression))
        self.indiv_early_risk = params.early_polyp_progression[idx]
        
        if params.correlation:
            idx2 = idx  # ← 추가: 같은 인덱스 사용 (상관관계)
        else:
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

    # ★★★ 추가: stage_at_colonoscopy 메서드 (C++ Polyp.cpp:74-84)
    def stage_at_colonoscopy(self, age):
        """
        특정 나이에 대장내시경 했을 때의 용종 Stage 반환
        C++ 원본: Polyp.cpp 74-84줄
        """
        stage_loc = 1  # 기본값: Stage 1
        
        for t_event, prev_stage, new_stage in self.history:
            if t_event >= age:
                break
            
            if new_stage >= 10:  # Fast cancer로 전환됨
                return 0
            elif new_stage == 0:  # Healing
                stage_loc -= 1
            else:  # Progression
                stage_loc = new_stage
        
        return stage_loc


# ============================================================================
# 수정 2: Cancer 클래스 - age_progression 배열 + stage_at_colonoscopy 추가
# ============================================================================
class Cancer:
    def __init__(self, age, gender, params, rng, origin_polyp=None):
        self.age_developed = age
        self.detected = False
        self.prevented = False
        self.origin_polyp = origin_polyp
        if origin_polyp: 
            self.location = origin_polyp.location
        else: 
            self.location = int(rng.random() * 13)

        self.symptoms_stage = self._determine_symptoms_stage(age, gender, params, rng)
        self.symptoms_age = self._calc_symptoms_age(age, self.symptoms_stage, params, rng)
        self.mortality_time = self._generate_mortality_time(gender, age, self.symptoms_stage, params, rng)
        
        # ★★★ 추가: 검진 시 기록용 속성 (Issue 2 수정)
        self.stage_at_detection = 0
        self.age_detected = 0.0
        
        # ★★★ 추가: Stage Progression 배열 (C++ Cancer.h:16)
        self.age_progression = [0.0, 0.0, 0.0]
        self._calculate_stage_progression(age, params)

    # ★★★ 추가: _calculate_stage_progression 메서드 (C++ Cancer.cpp:49-66)
    def _calculate_stage_progression(self, age, params):
        """
        증상 발현 시점과 stage에 따라 각 stage 도달 나이 계산
        C++ 원본: Cancer.cpp 49-66줄
        
        ★ 수정 (Issue 1): 인덱스 수정
        - age_progression[0] = Stage I 도달 시점
        - age_progression[1] = Stage II 도달 시점
        - age_progression[2] = Stage III 도달 시점
        """
        st = self.symptoms_age - age  # Sojourn Time
        
        if self.symptoms_stage == 2:
            if hasattr(params, 'stage_duration_stage_ii'):
                self.age_progression[0] = age + st * params.stage_duration_stage_ii  # ← 0으로 수정
        
        elif self.symptoms_stage == 3:
            if hasattr(params, 'stage_duration_stage_iii'):
                durations = params.stage_duration_stage_iii
                if len(durations) >= 2:
                    self.age_progression[0] = age + st * durations[0]  # ← 0으로 수정
                    self.age_progression[1] = age + st * durations[1]  # ← 1 유지
        
        elif self.symptoms_stage == 4:
            if hasattr(params, 'stage_duration_stage_iv'):
                durations = params.stage_duration_stage_iv
                if len(durations) >= 3:
                    self.age_progression[0] = age + st * durations[0]  # ← 0 유지
                    self.age_progression[1] = age + st * durations[1]  # ← 1 유지
                    self.age_progression[2] = age + st * durations[2]  # ← 2 유지

    # ★★★ 추가: stage_at_colonoscopy 메서드 (C++ Cancer.cpp:68-91)
    def stage_at_colonoscopy(self, age):
        """
        특정 나이에 대장내시경 했을 때의 암 Stage 반환
        C++ 원본: Cancer.cpp 68-91줄
        
        ★ 수정 (Issue 5): 인덱스 수정 (Issue 1과 연관)
        """
        stage_c = 1  # 기본값: Stage I
        
        if self.symptoms_stage == 2:
            if age >= self.age_progression[0]:  # ← 0으로 수정
                stage_c = 2
        
        elif self.symptoms_stage == 3:
            if age >= self.age_progression[1]:  # ← 1로 수정
                stage_c = 3
            elif age >= self.age_progression[0]:  # ← 0으로 수정
                stage_c = 2
        
        elif self.symptoms_stage == 4:
            if age >= self.age_progression[2]:  # ← 2 유지
                stage_c = 4
            elif age >= self.age_progression[1]:  # ← 1 유지
                stage_c = 3
            elif age >= self.age_progression[0]:  # ← 0 유지
                stage_c = 2
        
        return stage_c

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


# ============================================================================
# 수정 3: Person 클래스 - Surveillance 로직 완전 재구현
# ============================================================================
class Person:
    def __init__(self, params, rng):
        self.params = params
        self.rng = rng
        self.gender = 1 if rng.random() < params.fraction_female else 0
        self.polyps = []
        self.cancers = []
        
        # ★★★ 추가: Surveillance 추적 변수 (C++ Person.h:37-38)
        self.last_early_polyp = -1.0
        self.last_adv_polyp = -1.0
        self.last_cancer = -1.0
        self.last_colonoscopy = -1.0
        
        lt = self.params.life_table_females_cum if self.gender == 1 else self.params.life_table_males_cum
        death_idx = np.searchsorted(lt, self.rng.random())
        self.natural_death_age = death_idx + self.rng.random()
        self.death_age = self.natural_death_age
        
        idx = int(rng.random() * len(params.individual_polyp_risk))
        self.risk_factor = params.individual_polyp_risk[idx]
        if self.gender == 1: 
            self.risk_factor *= params.female_new_polyp_risk

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
                    output.record_event_cost(c.age_developed, 'CANCER_INIT', c.symptoms_stage)
                    
                    if c.mortality_time < self.natural_death_age:
                        output.record_event_cost(c.mortality_time, 'CANCER_FINAL', c.symptoms_stage)

    # ★★★ 수정: evaluate_strategy 완전 재작성 (C++ Person.cpp:237-283)
    def evaluate_strategy(self, screening_moments, output, compliance=1.0):
        """
        C++ 원본: Person.cpp 237-283줄
        변경사항:
        1. Surveillance 로직 추가 (_find_next_surveillance)
        2. Event type 분류 (증상/Surveillance/스크리닝)
        3. 5년 최소 간격 체크
        """
        schedule = sorted(screening_moments.copy())
        self.cancers.sort(key=lambda x: x.symptoms_age)
        current_age = 0.0
        
        # Surveillance 플래그 확인
        polyp_surveillance = getattr(self.params, 'polyp_surveillance', True)
        cancer_surveillance = getattr(self.params, 'cancer_surveillance', True)
        
        while current_age < self.death_age:
            # [1] 다음 스크리닝 시점
            next_screening = schedule[0] if schedule else 999.0
            
            # [2] 다음 증상 발현 시점
            next_symptom = 999.0
            symptom_cancer = None
            for c in self.cancers:
                if not c.prevented and not c.detected and c.symptoms_age > current_age:
                    next_symptom = c.symptoms_age
                    symptom_cancer = c
                    break
            
            # ★ [3] 다음 Surveillance 시점 계산 (새로 추가)
            next_surveillance = self._find_next_surveillance(current_age, polyp_surveillance, cancer_surveillance)
            
            # 세 가지 중 가장 빠른 것 선택
            event_time = min(next_screening, next_symptom, next_surveillance)
            if event_time >= self.death_age: 
                break
            
            current_age = event_time
            
            # 이벤트 처리
            if event_time == next_symptom:
                # 증상 발현
                if symptom_cancer:
                    output.symptom_detections += 1
                    symptom_cancer.detected = True
                    output.record_event_cost(current_age, 'COLONOSCOPY')
            
            elif event_time == next_surveillance:
                # ★ Surveillance 검사 (새로 추가)
                if self.rng.random() < compliance:
                    self._perform_colonoscopy(current_age, output, is_screening=False, is_surveillance=True)
            
            elif event_time == next_screening:
                # 스크리닝 검사
                schedule.pop(0)
                if self.rng.random() < compliance:
                    # ★ 5년 최소 간격 체크 (추가)
                    if self.last_colonoscopy < 0 or (current_age - self.last_colonoscopy) >= 5.0:
                        self._perform_colonoscopy(current_age, output, is_screening=True, is_surveillance=False)

    # ★★★ 추가: _find_next_surveillance 메서드 (C++ Person.cpp:145-217)
    def _find_next_surveillance(self, current_age, polyp_surveillance, cancer_surveillance):
        """
        용종/암 발견 후 추적검사 스케줄 계산
        C++ 원본: Person.cpp 145-217줄
        
        규칙:
        - Early Polyp: 5년 후
        - Advanced Polyp: 3년 후
        - Cancer: 1년 후, 그 다음 3년 후
        """
        if self.last_colonoscopy < 0:
            return 999.0
        
        candidates = []
        
        # [1] 용종 Surveillance
        if polyp_surveillance:
            # Early Polyp 발견 후 5년
            if self.last_early_polyp > 0:
                if self.last_early_polyp == self.last_colonoscopy:
                    candidates.append(self.last_early_polyp + 5.0)
                else:
                    next_time = max(self.last_colonoscopy, self.last_early_polyp + 1.0) + 5.0
                    if next_time <= self.last_early_polyp + 9.0:
                        candidates.append(next_time)
            
            # Advanced Polyp 발견 후 3년
            if self.last_adv_polyp > 0:
                if self.last_adv_polyp == self.last_colonoscopy:
                    candidates.append(self.last_adv_polyp + 3.0)
                else:
                    next_time = max(self.last_colonoscopy, self.last_adv_polyp) + 5.0
                    candidates.append(next_time)
        
        # [2] 암 Surveillance
        if cancer_surveillance:
            if self.last_cancer > 0:
                if self.last_cancer == self.last_colonoscopy:
                    candidates.append(self.last_cancer + 1.0)
                elif self.last_cancer == self.last_colonoscopy - 1.0:
                    candidates.append(self.last_cancer + 4.0)
                else:
                    next_time = max(self.last_colonoscopy, self.last_cancer) + 5.0
                    candidates.append(next_time)
        
        # 가장 빠른 시점 선택
        valid_candidates = [c for c in candidates if c > current_age and c > self.last_colonoscopy]
        if valid_candidates:
            return min(valid_candidates)
        return 999.0

    # ★★★ 수정: _perform_colonoscopy - Location-based Detection 추가 (C++ Person.cpp:341-453)
    def _perform_colonoscopy(self, age, output, is_screening=False, is_surveillance=False):
        """
        C++ 원본: Person.cpp 341-453줄
        
        변경사항:
        1. Location 도달 체크 추가 (reach_loc)
        2. Location-based sensitivity 곱셈
        3. Stage at colonoscopy 사용
        4. Surveillance 변수 업데이트
        5. ★ Issue 3 수정: Reach location 로직을 C++ while 패턴으로 수정
        6. ★ Issue 4 수정: output.add_colonoscopy() 호출 추가
        """
        if is_screening: 
            output.screening_counts += 1
        
        output.record_event_cost(age, 'COLONOSCOPY')

        # 합병증 플래그 (Issue 4용)
        perforation = False
        serosa = False
        bleeding = False
        bleeding_transf = False

        # 합병증 체크
        if self.rng.random() < self.params.risk_perforation:
            output.record_event_cost(age, 'PERFORATION')
            output.compl_perforations += 1
            perforation = True  # ← 추가
            if self.rng.random() < self.params.death_perforation:
                self.death_age = age
                # 사망 전 output 기록 (Issue 4)
                colo_type = 3 if is_screening else (2 if is_surveillance else 1)
                output.add_colonoscopy(age, self.gender, 0, 0, 0, 
                                      perforation, serosa, bleeding, bleeding_transf, colo_type)
                return
        
        if self.rng.random() < self.params.risk_bleeding:
            output.record_event_cost(age, 'BLEEDING')
            output.compl_bleedings += 1
            bleeding = True  # ← 추가

        # ★ 수정 (Issue 3): Reach 위치 계산 - C++ while 패턴 사용
        u = self.rng.random()
        reach_loc = 0
        while reach_loc < len(self.params.colo_reach) and u > self.params.colo_reach[reach_loc]:
            reach_loc += 1

        has_polyp_found = False
        has_cancer_found = False
        adv_polyp_found = False
        early_polyp_count = 0
        advanced_polyp_count = 0
        cancer_count = 0
        
        # ★ 수정: 용종 발견 로직 (C++ Person.cpp:384-408)
        for p in self.polyps:
            if p.age_developed <= age < p.age_end and p.cancer_ref is None:
                # ★ 추가: Location 체크
                if p.location < reach_loc:
                    continue
                
                # ★ 수정: Stage at colonoscopy 사용
                stage_at_colo = p.stage_at_colonoscopy(age)
                if stage_at_colo == 0:
                    continue
                
                det_idx = min(stage_at_colo - 1, len(self.params.colo_det_polyp) - 1)
                sens = self.params.colo_det_polyp[det_idx]
                
                # ★ 추가: Location-based sensitivity (C++ Person.cpp:397)
                if p.location < len(self.params.colo_det_location):
                    sens *= self.params.colo_det_location[p.location]
                
                if self.rng.random() < sens:
                    p.age_end = age
                    if p.cancer_ref: 
                        p.cancer_ref.prevented = True
                    has_polyp_found = True
                    
                    # ★ 추가: Advanced 여부 기록 (Issue 4용)
                    if stage_at_colo >= self.params.adv_polyp_transition:
                        adv_polyp_found = True
                        advanced_polyp_count += 1
                    else:
                        early_polyp_count += 1
        
        # ★ 수정: 암 발견 로직 (C++ Person.cpp:412-427)
        for c in self.cancers:
            if not c.prevented and not c.detected and c.age_developed <= age:
                # ★ 추가: Location 체크
                if c.location < reach_loc:
                    continue
                
                # ★ 수정: Stage at colonoscopy 기반 감지 (C++ Person.cpp:416-417)
                stage_at_colo = c.stage_at_colonoscopy(age)
                sens_idx = min(stage_at_colo - 1, len(self.params.colo_det_cancer) - 1)
                sens = self.params.colo_det_cancer[sens_idx]
                
                if self.rng.random() < sens:
                    c.detected = True
                    c.stage_at_detection = stage_at_colo  # 추가
                    c.age_detected = age  # 추가
                    if is_screening: 
                        output.screen_detections += 1
                    has_cancer_found = True
                    cancer_count += 1
        
        # ★ 추가: Surveillance 변수 업데이트 (C++ Person.cpp:429-432)
        if has_cancer_found:
            self.last_cancer = age
            output.record_event_cost(age, 'COLO_CANCER')
        elif adv_polyp_found:
            self.last_adv_polyp = age
            output.record_event_cost(age, 'COLO_POLYP')
        elif has_polyp_found:
            self.last_early_polyp = age
            output.record_event_cost(age, 'COLO_POLYP')
        
        self.last_colonoscopy = age
        
        # ★★★ 추가 (Issue 4): output.add_colonoscopy 호출
        # Colonoscopy type: 1=증상, 2=surveillance, 3=screening
        colo_type = 3 if is_screening else (2 if is_surveillance else 1)
        
        output.add_colonoscopy(
            age, 
            self.gender, 
            cancer_count,
            early_polyp_count, 
            advanced_polyp_count,
            perforation, 
            serosa, 
            bleeding, 
            bleeding_transf, 
            colo_type
        )
