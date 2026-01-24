import numpy as np

class Output:
    """
    C++ Output.cpp와 동일하게 연령별 세부 추적을 지원하는 출력 클래스
    """
    def __init__(self, params):
        self.params = params
        N = int(params.years_to_simulate)
        
        # ===== 연령별 인구 추적 (C++ 동일) =====
        self.cancer_females = [0] * N
        self.cancer_males = [0] * N
        self.population_females = [0] * N
        self.population_males = [0] * N
        
        # ===== 연령별 용종 유병률 =====
        num_polyp_stages = int(params.num_polyp_stages)
        self.polyps_summ_female = [0] * (N * num_polyp_stages)
        self.polyps_summ_male = [0] * (N * num_polyp_stages)
        self.number_any_polyp_females = [0] * N
        self.number_any_polyp_males = [0] * N
        self.number_advanced_polyp_females = [0] * N
        self.number_advanced_polyp_males = [0] * N
        
        # ===== 연령별 검진 횟수 =====
        self.number_colonoscopies_female = [0] * N
        self.number_colonoscopies_male = [0] * N
        
        # ===== 검진 종류별 분류 (Screening) =====
        self.colo_notumor_nopolyps_screen = [0] * N
        self.colo_tumor_nopolyps_screen = [0] * N
        self.colo_notumor_polyps_screen = [0] * N
        
        self.num_perforations_screen = [0] * N
        self.num_serosa_screen = [0] * N
        self.num_bleeding_screen = [0] * N
        self.num_bleeding_transf_screen = [0] * N
        
        # ===== 검진 종류별 분류 (Treatment - 증상 발현) =====
        self.colo_notumor_nopolyps_treat = [0] * N
        self.colo_tumor_nopolyps_treat = [0] * N
        self.colo_notumor_polyps_treat = [0] * N
        
        self.num_perforations_treat = [0] * N
        self.num_serosa_treat = [0] * N
        self.num_bleeding_treat = [0] * N
        self.num_bleeding_transf_treat = [0] * N
        
        # ===== 검진 종류별 분류 (Followup - 추적 검사) =====
        self.colo_notumor_nopolyps_followup = [0] * N
        self.colo_tumor_nopolyps_followup = [0] * N
        self.colo_notumor_polyps_followup = [0] * N
        
        self.num_perforations_followup = [0] * N
        self.num_serosa_followup = [0] * N
        self.num_bleeding_followup = [0] * N
        self.num_bleeding_transf_followup = [0] * N
        
        # ===== 생존 연수 손실 (연령별) =====
        self.life_years_lost_ca = [0.0] * N
        self.life_years_lost_colo = [0.0] * N
        
        # ===== 암 단계별 비용 (연령별) =====
        self.stage1_cost_continuous = [0.0] * N
        self.stage1_cost_initial = [0.0] * N
        self.stage1_cost_final = [0.0] * N
        self.stage1_cost_final_oc = [0.0] * N
        
        self.stage2_cost_continuous = [0.0] * N
        self.stage2_cost_initial = [0.0] * N
        self.stage2_cost_final = [0.0] * N
        self.stage2_cost_final_oc = [0.0] * N
        
        self.stage3_cost_continuous = [0.0] * N
        self.stage3_cost_initial = [0.0] * N
        self.stage3_cost_final = [0.0] * N
        self.stage3_cost_final_oc = [0.0] * N
        
        self.stage4_cost_continuous = [0.0] * N
        self.stage4_cost_initial = [0.0] * N
        self.stage4_cost_final = [0.0] * N
        self.stage4_cost_final_oc = [0.0] * N
        
        # ===== 전체 집계 =====
        self.death_cancer = 0
        self.number_screening_colonoscopies = 0
        self.number_detected_cancers = [0] * N
        
        self.init_pop_size = params.population_size
        
        # ===== 하위 호환성을 위한 추가 속성 (DRL/CQL/기존 코드용) =====
        self.total_discounted_cost = 0.0  # 단순 비용 누적 (간소화)
        self.cancers_count = 0  # 전체 암 발생 수
        self.cancer_deaths = 0  # 전체 암 사망 수
        self.total_person_years = 0.0  # 전체 생존 연수
        self.polyps_count = 0  # 전체 용종 수
        
        # entities.py가 사용하는 속성들
        self.screening_counts = 0  # 검진 횟수
        self.symptom_detections = 0  # 증상으로 발견된 암
        self.screen_detections = 0  # 검진으로 발견된 암
        self.compl_perforations = 0  # 천공 합병증
        self.compl_bleedings = 0  # 출혈 합병증

    def add_results(self, other):
        """다른 Output 객체의 결과를 현재 객체에 합산"""
        N = len(self.cancer_females)
        
        for i in range(N):
            self.cancer_females[i] += other.cancer_females[i]
            self.cancer_males[i] += other.cancer_males[i]
            self.population_females[i] += other.population_females[i]
            self.population_males[i] += other.population_males[i]
            
            self.number_any_polyp_females[i] += other.number_any_polyp_females[i]
            self.number_any_polyp_males[i] += other.number_any_polyp_males[i]
            self.number_advanced_polyp_females[i] += other.number_advanced_polyp_females[i]
            self.number_advanced_polyp_males[i] += other.number_advanced_polyp_males[i]
            
            self.number_colonoscopies_female[i] += other.number_colonoscopies_female[i]
            self.number_colonoscopies_male[i] += other.number_colonoscopies_male[i]
            
            # Screening
            self.colo_notumor_nopolyps_screen[i] += other.colo_notumor_nopolyps_screen[i]
            self.colo_tumor_nopolyps_screen[i] += other.colo_tumor_nopolyps_screen[i]
            self.colo_notumor_polyps_screen[i] += other.colo_notumor_polyps_screen[i]
            self.num_perforations_screen[i] += other.num_perforations_screen[i]
            self.num_serosa_screen[i] += other.num_serosa_screen[i]
            self.num_bleeding_screen[i] += other.num_bleeding_screen[i]
            self.num_bleeding_transf_screen[i] += other.num_bleeding_transf_screen[i]
            
            # Treatment
            self.colo_notumor_nopolyps_treat[i] += other.colo_notumor_nopolyps_treat[i]
            self.colo_tumor_nopolyps_treat[i] += other.colo_tumor_nopolyps_treat[i]
            self.colo_notumor_polyps_treat[i] += other.colo_notumor_polyps_treat[i]
            self.num_perforations_treat[i] += other.num_perforations_treat[i]
            self.num_serosa_treat[i] += other.num_serosa_treat[i]
            self.num_bleeding_treat[i] += other.num_bleeding_treat[i]
            self.num_bleeding_transf_treat[i] += other.num_bleeding_transf_treat[i]
            
            # Followup
            self.colo_notumor_nopolyps_followup[i] += other.colo_notumor_nopolyps_followup[i]
            self.colo_tumor_nopolyps_followup[i] += other.colo_tumor_nopolyps_followup[i]
            self.colo_notumor_polyps_followup[i] += other.colo_notumor_polyps_followup[i]
            self.num_perforations_followup[i] += other.num_perforations_followup[i]
            self.num_serosa_followup[i] += other.num_serosa_followup[i]
            self.num_bleeding_followup[i] += other.num_bleeding_followup[i]
            self.num_bleeding_transf_followup[i] += other.num_bleeding_transf_followup[i]
            
            # Life years lost
            self.life_years_lost_ca[i] += other.life_years_lost_ca[i]
            self.life_years_lost_colo[i] += other.life_years_lost_colo[i]
            
            # Cancer costs by stage
            self.stage1_cost_continuous[i] += other.stage1_cost_continuous[i]
            self.stage1_cost_initial[i] += other.stage1_cost_initial[i]
            self.stage1_cost_final[i] += other.stage1_cost_final[i]
            self.stage1_cost_final_oc[i] += other.stage1_cost_final_oc[i]
            
            self.stage2_cost_continuous[i] += other.stage2_cost_continuous[i]
            self.stage2_cost_initial[i] += other.stage2_cost_initial[i]
            self.stage2_cost_final[i] += other.stage2_cost_final[i]
            self.stage2_cost_final_oc[i] += other.stage2_cost_final_oc[i]
            
            self.stage3_cost_continuous[i] += other.stage3_cost_continuous[i]
            self.stage3_cost_initial[i] += other.stage3_cost_initial[i]
            self.stage3_cost_final[i] += other.stage3_cost_final[i]
            self.stage3_cost_final_oc[i] += other.stage3_cost_final_oc[i]
            
            self.stage4_cost_continuous[i] += other.stage4_cost_continuous[i]
            self.stage4_cost_initial[i] += other.stage4_cost_initial[i]
            self.stage4_cost_final[i] += other.stage4_cost_final[i]
            self.stage4_cost_final_oc[i] += other.stage4_cost_final_oc[i]
            
            self.number_detected_cancers[i] += other.number_detected_cancers[i]
        
        for i in range(len(self.polyps_summ_male)):
            self.polyps_summ_male[i] += other.polyps_summ_male[i]
            self.polyps_summ_female[i] += other.polyps_summ_female[i]
        
        self.death_cancer += other.death_cancer
        self.number_screening_colonoscopies += other.number_screening_colonoscopies
        
        # 하위 호환성 속성도 합산
        self.total_discounted_cost += other.total_discounted_cost
        self.cancers_count += other.cancers_count
        self.cancer_deaths += other.cancer_deaths
        self.total_person_years += other.total_person_years
        self.polyps_count += other.polyps_count
        self.screening_counts += other.screening_counts
        self.symptom_detections += other.symptom_detections
        self.screen_detections += other.screen_detections
        self.compl_perforations += other.compl_perforations
        self.compl_bleedings += other.compl_bleedings

    def add_colonoscopy(self, age, gender, cancer_counter, early_counter, advanced_counter,
                        perforation, serosa, bleeding, bleeding_transf, colo_type):
        """
        검진 이벤트 기록 (C++ addColonoscopy() 동일)
        
        colo_type: 1=증상(Treatment), 2=추적(Followup), 3=검진(Screening)
        """
        indx = int(age)
        if indx >= len(self.cancer_females):
            return
            
        # 성별 검진 횟수
        if gender:
            self.number_colonoscopies_female[indx] += 1
        else:
            self.number_colonoscopies_male[indx] += 1
        
        # 종류별 분류
        if colo_type == 1:  # Treatment (증상)
            if cancer_counter == 0 and early_counter == 0 and advanced_counter == 0:
                self.colo_notumor_nopolyps_treat[indx] += 1
            if cancer_counter > 0 and early_counter == 0 and advanced_counter == 0:
                self.colo_tumor_nopolyps_treat[indx] += 1
            if cancer_counter == 0 and (early_counter > 0 or advanced_counter > 0):
                self.colo_notumor_polyps_treat[indx] += 1
            
            if perforation: self.num_perforations_treat[indx] += 1
            if serosa: self.num_serosa_treat[indx] += 1
            if bleeding: self.num_bleeding_treat[indx] += 1
            if bleeding_transf: self.num_bleeding_transf_treat[indx] += 1
                
        elif colo_type == 2:  # Followup (추적)
            if cancer_counter == 0 and early_counter == 0 and advanced_counter == 0:
                self.colo_notumor_nopolyps_followup[indx] += 1
            if cancer_counter > 0 and early_counter == 0 and advanced_counter == 0:
                self.colo_tumor_nopolyps_followup[indx] += 1
            if cancer_counter == 0 and (early_counter > 0 or advanced_counter > 0):
                self.colo_notumor_polyps_followup[indx] += 1
            
            if perforation: self.num_perforations_followup[indx] += 1
            if serosa: self.num_serosa_followup[indx] += 1
            if bleeding: self.num_bleeding_followup[indx] += 1
            if bleeding_transf: self.num_bleeding_transf_followup[indx] += 1
                
        elif colo_type == 3:  # Screening (검진)
            if cancer_counter == 0 and early_counter == 0 and advanced_counter == 0:
                self.colo_notumor_nopolyps_screen[indx] += 1
            if cancer_counter > 0 and early_counter == 0 and advanced_counter == 0:
                self.colo_tumor_nopolyps_screen[indx] += 1
            if cancer_counter == 0 and (early_counter > 0 or advanced_counter > 0):
                self.colo_notumor_polyps_screen[indx] += 1
            
            if perforation: self.num_perforations_screen[indx] += 1
            if serosa: self.num_serosa_screen[indx] += 1
            if bleeding: self.num_bleeding_screen[indx] += 1
            if bleeding_transf: self.num_bleeding_transf_screen[indx] += 1
            
            self.number_screening_colonoscopies += 1
        
        # 암 발견 시 incidence 기록
        if cancer_counter > 0:
            if gender:
                self.cancer_females[indx] += 1
            else:
                self.cancer_males[indx] += 1
            self.number_detected_cancers[indx] += cancer_counter
            self.cancers_count += cancer_counter  # ← 추가 (DRL/CQL용)
        
        # ★ 추가: 간소화된 비용 누적 (DRL/CQL 호환성)
        # 기본 검진 비용 + 합병증 비용 누적
        base_cost = getattr(self.params, 'cost_colo', 100.0)
        if cancer_counter > 0:
            base_cost = getattr(self.params, 'cost_colo_cancer', 300.0)
        elif early_counter > 0 or advanced_counter > 0:
            base_cost = getattr(self.params, 'cost_colo_polyp', 200.0)
        
        if perforation: base_cost += getattr(self.params, 'cost_perf', 5000.0)
        if bleeding: base_cost += getattr(self.params, 'cost_bleed', 1000.0)
        
        self.total_discounted_cost += base_cost

    def record_death(self, death_cancer_related, death_year_life_tables, cause_of_death, gender):
        """사망 기록 (C++ recordDeath() 동일)"""
        age = min(death_cancer_related, death_year_life_tables) if death_cancer_related > 0 else death_year_life_tables
        t_age = int(np.ceil(age)) - 1
        
        if t_age >= 0 and t_age < len(self.population_females):
            if gender:
                for i in range(t_age + 1):
                    self.population_females[i] += 1
            else:
                for i in range(t_age + 1):
                    self.population_males[i] += 1
        
        # 생존 연수 손실 기록
        if death_cancer_related > 0:
            ly = max(death_year_life_tables - death_cancer_related, 0.0)
            if ly > 0:
                start_idx = int(death_cancer_related)
                end_idx = int(death_cancer_related + ly)
                
                if cause_of_death == 1:  # Cancer
                    for i in range(start_idx, min(end_idx, len(self.life_years_lost_ca))):
                        self.life_years_lost_ca[i] += 1
                    # 소수점 부분
                    remainder = ly - int(ly)
                    if remainder > 0 and end_idx < len(self.life_years_lost_ca):
                        self.life_years_lost_ca[end_idx] += remainder
                        
                elif cause_of_death == 2:  # Colonoscopy complication
                    for i in range(start_idx, min(end_idx, len(self.life_years_lost_colo))):
                        self.life_years_lost_colo[i] += 1
                    remainder = ly - int(ly)
                    if remainder > 0 and end_idx < len(self.life_years_lost_colo):
                        self.life_years_lost_colo[end_idx] += remainder

    def save_summary(self, cancers, gender, cause_of_death, death_cancer_related, death_year_life_tables, dt):
        """암 치료 비용 기록 (C++ saveSummary() 동일)"""
        death_moment = min(death_year_life_tables, death_cancer_related) if death_cancer_related > 0 else death_year_life_tables
        
        if cause_of_death == 1:
            self.death_cancer += 1
        
        # 각 암에 대한 치료 비용 계산
        for cancer in cancers:
            if not cancer.detected:
                continue
                
            start = cancer.age_detected
            difference = min(death_moment - start, 5.0)
            survived_5years = (difference == 5.0)
            stage = cancer.stage_at_detection
            
            # 치료 기간 동안 비용 누적
            t = start
            while t < start + difference:
                indx = int(t)
                if indx >= len(self.stage1_cost_initial):
                    break
                    
                if stage == 1:
                    if survived_5years:
                        if t - start < 1.0:
                            self.stage1_cost_initial[indx] += dt
                        else:
                            self.stage1_cost_continuous[indx] += dt
                    else:
                        if t >= start + difference - 1.0:
                            if cause_of_death == 1:
                                self.stage1_cost_final[indx] += dt
                            else:
                                self.stage1_cost_final_oc[indx] += dt
                        elif t - start < 1.0:
                            self.stage1_cost_initial[indx] += dt
                        else:
                            self.stage1_cost_continuous[indx] += dt
                            
                elif stage == 2:
                    if survived_5years:
                        if t - start < 1.0:
                            self.stage2_cost_initial[indx] += dt
                        else:
                            self.stage2_cost_continuous[indx] += dt
                    else:
                        if t >= start + difference - 1.0:
                            if cause_of_death == 1:
                                self.stage2_cost_final[indx] += dt
                            else:
                                self.stage2_cost_final_oc[indx] += dt
                        elif t - start < 1.0:
                            self.stage2_cost_initial[indx] += dt
                        else:
                            self.stage2_cost_continuous[indx] += dt
                            
                elif stage == 3:
                    if survived_5years:
                        if t - start < 1.0:
                            self.stage3_cost_initial[indx] += dt
                        else:
                            self.stage3_cost_continuous[indx] += dt
                    else:
                        if t >= start + difference - 1.0:
                            if cause_of_death == 1:
                                self.stage3_cost_final[indx] += dt
                            else:
                                self.stage3_cost_final_oc[indx] += dt
                        elif t - start < 1.0:
                            self.stage3_cost_initial[indx] += dt
                        else:
                            self.stage3_cost_continuous[indx] += dt
                            
                elif stage == 4:
                    if survived_5years:
                        if t - start < 1.0:
                            self.stage4_cost_initial[indx] += dt
                        else:
                            self.stage4_cost_continuous[indx] += dt
                    else:
                        if t >= start + difference - 1.0:
                            if cause_of_death == 1:
                                self.stage4_cost_final[indx] += dt
                            else:
                                self.stage4_cost_final_oc[indx] += dt
                        elif t - start < 1.0:
                            self.stage4_cost_initial[indx] += dt
                        else:
                            self.stage4_cost_continuous[indx] += dt
                
                t += dt

    # ===== 집계 메서드 (C++ 동일) =====
    
    def total_number_of_cancers(self):
        return sum(self.cancer_females) + sum(self.cancer_males)
    
    def total_life_years_lost(self):
        return sum(self.life_years_lost_ca) + sum(self.life_years_lost_colo)
    
    def total_disc_life_years_lost(self, disc_val, disc_after):
        """할인된 생존 연수 손실 (C++ 동일)"""
        result = 0.0
        disc_val_current = 1.0
        
        for i in range(len(self.life_years_lost_ca)):
            result += disc_val_current * self.life_years_lost_ca[i]
            result += disc_val_current * self.life_years_lost_colo[i]
            if i > int(disc_after):
                disc_val_current *= disc_val
        
        return result
    
    def initial_population_size(self):
        return self.init_pop_size
    
    def record_event_cost(self, age, cost_type, stage=0):
        """
        비용 발생 이벤트를 기록 (간소화 버전 - 하위 호환성용)
        실제 상세 비용 계산은 evaluate.py의 total_discounted_costs()에서 수행
        """
        # 간소화: 기본 비용만 누적
        base_cost = 0.0
        
        if cost_type == 'COLONOSCOPY':
            base_cost = getattr(self.params, 'cost_colo', 100.0)
        elif cost_type == 'COLO_POLYP':
            base_cost = getattr(self.params, 'cost_colo_polyp', 200.0) - getattr(self.params, 'cost_colo', 100.0)
        elif cost_type == 'COLO_CANCER':
            base_cost = getattr(self.params, 'cost_colo_cancer', 300.0) - getattr(self.params, 'cost_colo', 100.0)
        elif cost_type == 'PERFORATION':
            base_cost = getattr(self.params, 'cost_perf', 5000.0)
        elif cost_type == 'BLEEDING':
            base_cost = getattr(self.params, 'cost_bleed', 1000.0)
        elif cost_type == 'CANCER_INIT':
            # 암 초기 치료 비용 (간소화)
            cost_map = {1: 10000.0, 2: 15000.0, 3: 20000.0, 4: 30000.0}
            base_cost = cost_map.get(stage, 15000.0)
        elif cost_type == 'CANCER_FINAL':
            # 암 말기 치료 비용 (간소화)
            cost_map = {1: 5000.0, 2: 8000.0, 3: 12000.0, 4: 20000.0}
            base_cost = cost_map.get(stage, 10000.0)
        
        # 간단한 할인 적용
        discount_factor = 1.0
        if hasattr(self.params, 'discount_after_year') and age > self.params.discount_after_year:
            years = age - self.params.discount_after_year
            discount_coeff = getattr(self.params, 'discount_coeff', 0.97)
            discount_factor = discount_coeff ** years
        
        self.total_discounted_cost += base_cost * discount_factor