import numpy as np

class Output:
    def __init__(self, params):
        self.params = params
        
        self.polyps_count = 0
        self.cancers_count = 0
        self.cancer_deaths = 0 
        
        self.screening_counts = 0      
        self.screen_detections = 0     
        self.symptom_detections = 0
        self.compl_perforations = 0
        self.compl_bleedings = 0
        
        self.total_person_years = 0.0
        
        # 상세 통계
        self.cancers_by_stage_init = {1:0, 2:0, 3:0, 4:0}
        self.cancers_by_stage_final = {1:0, 2:0, 3:0, 4:0}
        
        self.total_discounted_cost = 0.0

    def add_results(self, other):
        self.polyps_count += other.polyps_count
        self.cancers_count += other.cancers_count
        self.cancer_deaths += other.cancer_deaths
        
        self.screening_counts += other.screening_counts
        self.screen_detections += other.screen_detections
        self.symptom_detections += other.symptom_detections
        self.compl_perforations += other.compl_perforations
        self.compl_bleedings += other.compl_bleedings
        
        self.total_person_years += other.total_person_years
        
        for s in range(1, 5):
            self.cancers_by_stage_init[s] += other.cancers_by_stage_init[s]
            self.cancers_by_stage_final[s] += other.cancers_by_stage_final[s]
            
        self.total_discounted_cost += other.total_discounted_cost

    def record_event_cost(self, age, cost_type, stage=0):
        """
        비용 발생 이벤트를 기록하고 할인율을 적용하여 총 비용에 합산
        """
        base_cost = 0.0
        
        if cost_type == 'COLONOSCOPY':
            base_cost = self.params.cost_colo
        elif cost_type == 'COLO_POLYP':
            # 발견 시 추가비용 (단순 차액 처리 예시)
            base_cost = self.params.cost_colo_polyp - self.params.cost_colo
        elif cost_type == 'COLO_CANCER':
            base_cost = self.params.cost_colo_cancer - self.params.cost_colo
        elif cost_type == 'PERFORATION':
            base_cost = self.params.cost_perf
        elif cost_type == 'BLEEDING':
            base_cost = self.params.cost_bleed
        elif cost_type == 'CANCER_INIT':
            # 1~4기 초기 치료비
            if stage in self.params.cost_initial_cancer:
                base_cost = self.params.cost_initial_cancer[stage]
            self.cancers_by_stage_init[stage] += 1
        elif cost_type == 'CANCER_FINAL':
            # 1~4기 말기 치료비
            if stage in self.params.cost_final_cancer:
                base_cost = self.params.cost_final_cancer[stage]
            self.cancers_by_stage_final[stage] += 1
            
        # Discounting: Cost * (Coeff ^ max(0, age - start_year))
        # 나이(age)가 할인 시작 연도(discount_after_year)보다 클 때만 할인 적용
        if age > self.params.discount_after_year:
            years = age - self.params.discount_after_year
            discount_factor = self.params.discount_coeff ** years
        else:
            discount_factor = 1.0
        
        self.total_discounted_cost += base_cost * discount_factor