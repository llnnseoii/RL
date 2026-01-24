"""
Evaluate 모듈: 비용-효과 분석 및 ICER 계산
C++ Evaluate.cpp와 동일한 기능 제공
"""
import configparser

class Evaluator:
    """
    검진 전략 평가를 위한 클래스
    - ICER (Incremental Cost-Effectiveness Ratio) 계산
    - 발생률/사망률 감소율 계산
    - 비용 세부 분류
    """
    
    def __init__(self, ini_file):
        """evaluation.ini 파일 로드"""
        config = configparser.ConfigParser()
        config.read(ini_file)
        
        # Discounting parameters
        self.discounting_coeff = float(config['costs']['DiscountingCoeff'])
        self.discounting_after_year = float(config['costs']['DiscountingAfterYear'])
        
        # Colonoscopy costs
        self.colonoscopy = float(config['costs']['Colonoscopy'])
        self.colonoscopy_polyp = float(config['costs']['Colonoscopy_Polyp'])
        self.colonoscopy_cancer = float(config['costs']['Colonoscopy_Cancer'])
        
        # Complication costs
        self.colonoscopy_perforation = float(config['costs']['Colonoscopy_Perforation'])
        self.colonoscopy_serosal_burn = float(config['costs']['Colonoscopy_Serosal_burn'])
        self.colonoscopy_bleed = float(config['costs']['Colonoscopy_bleed'])
        self.colonoscopy_bleed_transfusion = float(config['costs']['Colonoscopy_bleed_transfusion'])
        
        # Cancer treatment costs - Initial
        self.initial_I = float(config['costs']['Initial_I'])
        self.initial_II = float(config['costs']['Initial_II'])
        self.initial_III = float(config['costs']['Initial_III'])
        self.initial_IV = float(config['costs']['Initial_IV'])
        
        # Cancer treatment costs - Continuous
        self.cont_I = float(config['costs']['Cont_I'])
        self.cont_II = float(config['costs']['Cont_II'])
        self.cont_III = float(config['costs']['Cont_III'])
        self.cont_IV = float(config['costs']['Cont_IV'])
        
        # Cancer treatment costs - Final
        self.final_I = float(config['costs']['Final_I'])
        self.final_II = float(config['costs']['Final_II'])
        self.final_III = float(config['costs']['Final_III'])
        self.final_IV = float(config['costs']['Final_IV'])
        
        # Cancer treatment costs - Final (Other Cause)
        self.final_oc_I = float(config['costs']['Final_oc_I'])
        self.final_oc_II = float(config['costs']['Final_oc_II'])
        self.final_oc_III = float(config['costs']['Final_oc_III'])
        self.final_oc_IV = float(config['costs']['Final_oc_IV'])
    
    def incidence_reduction(self, baseline, strategy):
        """
        발생률 감소율 계산 (%)
        
        Args:
            baseline: Output 객체 (검진 없음)
            strategy: Output 객체 (검진 전략 적용)
        
        Returns:
            float: 감소율 (%)
        """
        c1 = baseline.total_number_of_cancers()
        c2 = strategy.total_number_of_cancers()
        
        if c1 == 0:
            return 0.0
        
        return ((c1 - c2) / c1) * 100.0
    
    def mortality_reduction(self, baseline, strategy):
        """
        사망률 감소율 계산 (%)
        
        Args:
            baseline: Output 객체 (검진 없음)
            strategy: Output 객체 (검진 전략 적용)
        
        Returns:
            float: 감소율 (%)
        """
        c1 = baseline.death_cancer
        c2 = strategy.death_cancer
        
        if c1 == 0:
            return 0.0
        
        return ((c1 - c2) / c1) * 100.0
    
    def discounted_ly_gained(self, baseline, strategy):
        """
        할인된 생존 연수 증가 (per 1000 people)
        
        Args:
            baseline: Output 객체
            strategy: Output 객체
        
        Returns:
            float: Life years gained per 1000
        """
        c1 = baseline.total_disc_life_years_lost(self.discounting_coeff, self.discounting_after_year)
        c2 = strategy.total_disc_life_years_lost(self.discounting_coeff, self.discounting_after_year)
        c3 = baseline.initial_population_size()
        
        if c3 == 0:
            return 0.0
        
        return ((c1 - c2) / c3) * 1000.0
    
    def usd_per_lyg(self, baseline, strategy):
        """
        ICER 계산: USD per Life Year Gained
        
        Args:
            baseline: Output 객체
            strategy: Output 객체
        
        Returns:
            float: ICER (USD/LYG)
        """
        c1 = self.total_discounted_costs(baseline)
        c2 = self.total_discounted_costs(strategy)
        c3 = baseline.total_disc_life_years_lost(self.discounting_coeff, self.discounting_after_year)
        c4 = strategy.total_disc_life_years_lost(self.discounting_coeff, self.discounting_after_year)
        
        lyg = c3 - c4
        
        if lyg == 0:
            return float('inf')
        
        return (c2 - c1) / lyg
    
    def total_discounted_costs(self, output):
        """
        총 할인 비용 계산 (C++ totalDiscCosts()와 동일)
        
        Args:
            output: Output 객체
        
        Returns:
            float: 총 할인 비용
        """
        result = 0.0
        disc_val_current = 1.0
        
        N = len(output.life_years_lost_ca)
        
        for i in range(N):
            # Colonoscopy costs - Treatment
            result += disc_val_current * (self.colonoscopy * output.colo_notumor_nopolyps_treat[i])
            result += disc_val_current * (self.colonoscopy_polyp * output.colo_notumor_polyps_treat[i])
            result += disc_val_current * (self.colonoscopy_cancer * output.colo_tumor_nopolyps_treat[i])
            result += disc_val_current * (self.colonoscopy_perforation * output.num_perforations_treat[i])
            result += disc_val_current * (self.colonoscopy_serosal_burn * output.num_serosa_treat[i])
            result += disc_val_current * (self.colonoscopy_bleed * output.num_bleeding_treat[i])
            result += disc_val_current * (self.colonoscopy_bleed_transfusion * output.num_bleeding_transf_treat[i])
            
            # Colonoscopy costs - Followup
            result += disc_val_current * (self.colonoscopy * output.colo_notumor_nopolyps_followup[i])
            result += disc_val_current * (self.colonoscopy_polyp * output.colo_notumor_polyps_followup[i])
            result += disc_val_current * (self.colonoscopy_cancer * output.colo_tumor_nopolyps_followup[i])
            result += disc_val_current * (self.colonoscopy_perforation * output.num_perforations_followup[i])
            result += disc_val_current * (self.colonoscopy_serosal_burn * output.num_serosa_followup[i])
            result += disc_val_current * (self.colonoscopy_bleed * output.num_bleeding_followup[i])
            result += disc_val_current * (self.colonoscopy_bleed_transfusion * output.num_bleeding_transf_followup[i])
            
            # Colonoscopy costs - Screening
            result += disc_val_current * (self.colonoscopy * output.colo_notumor_nopolyps_screen[i])
            result += disc_val_current * (self.colonoscopy_polyp * output.colo_notumor_polyps_screen[i])
            result += disc_val_current * (self.colonoscopy_cancer * output.colo_tumor_nopolyps_screen[i])
            result += disc_val_current * (self.colonoscopy_perforation * output.num_perforations_screen[i])
            result += disc_val_current * (self.colonoscopy_serosal_burn * output.num_serosa_screen[i])
            result += disc_val_current * (self.colonoscopy_bleed * output.num_bleeding_screen[i])
            result += disc_val_current * (self.colonoscopy_bleed_transfusion * output.num_bleeding_transf_screen[i])
            
            # Cancer treatment costs - Stage I
            result += disc_val_current * (self.initial_I * output.stage1_cost_initial[i])
            result += disc_val_current * (self.cont_I * output.stage1_cost_continuous[i])
            result += disc_val_current * (self.final_I * output.stage1_cost_final[i])
            result += disc_val_current * (self.final_oc_I * output.stage1_cost_final_oc[i])
            
            # Cancer treatment costs - Stage II
            result += disc_val_current * (self.initial_II * output.stage2_cost_initial[i])
            result += disc_val_current * (self.cont_II * output.stage2_cost_continuous[i])
            result += disc_val_current * (self.final_II * output.stage2_cost_final[i])
            result += disc_val_current * (self.final_oc_II * output.stage2_cost_final_oc[i])
            
            # Cancer treatment costs - Stage III
            result += disc_val_current * (self.initial_III * output.stage3_cost_initial[i])
            result += disc_val_current * (self.cont_III * output.stage3_cost_continuous[i])
            result += disc_val_current * (self.final_III * output.stage3_cost_final[i])
            result += disc_val_current * (self.final_oc_III * output.stage3_cost_final_oc[i])
            
            # Cancer treatment costs - Stage IV
            result += disc_val_current * (self.initial_IV * output.stage4_cost_initial[i])
            result += disc_val_current * (self.cont_IV * output.stage4_cost_continuous[i])
            result += disc_val_current * (self.final_IV * output.stage4_cost_final[i])
            result += disc_val_current * (self.final_oc_IV * output.stage4_cost_final_oc[i])
            
            # Update discount factor
            if i > int(self.discounting_after_year):
                disc_val_current *= self.discounting_coeff
        
        return result
    
    def total_screening_costs(self, output):
        """검진 비용만 분리 계산"""
        result = 0.0
        for i in range(len(output.colo_notumor_nopolyps_screen)):
            result += self.colonoscopy * output.colo_notumor_nopolyps_screen[i]
            result += self.colonoscopy_polyp * output.colo_notumor_polyps_screen[i]
            result += self.colonoscopy_cancer * output.colo_tumor_nopolyps_screen[i]
            result += self.colonoscopy_perforation * output.num_perforations_screen[i]
            result += self.colonoscopy_serosal_burn * output.num_serosa_screen[i]
            result += self.colonoscopy_bleed * output.num_bleeding_screen[i]
            result += self.colonoscopy_bleed_transfusion * output.num_bleeding_transf_screen[i]
        return result
    
    def total_followup_costs(self, output):
        """추적 검사 비용만 분리 계산"""
        result = 0.0
        for i in range(len(output.colo_notumor_nopolyps_followup)):
            result += self.colonoscopy * output.colo_notumor_nopolyps_followup[i]
            result += self.colonoscopy_polyp * output.colo_notumor_polyps_followup[i]
            result += self.colonoscopy_cancer * output.colo_tumor_nopolyps_followup[i]
            result += self.colonoscopy_perforation * output.num_perforations_followup[i]
            result += self.colonoscopy_serosal_burn * output.num_serosa_followup[i]
            result += self.colonoscopy_bleed * output.num_bleeding_followup[i]
            result += self.colonoscopy_bleed_transfusion * output.num_bleeding_transf_followup[i]
        return result
    
    def print_evaluation_summary(self, baseline, strategy, strategy_name="Strategy"):
        """평가 결과 요약 출력"""
        print(f"\n{'='*60}")
        print(f"  Evaluation Summary: {strategy_name}")
        print(f"{'='*60}")
        
        print(f"\n[Effectiveness]")
        print(f"  Incidence Reduction:    {self.incidence_reduction(baseline, strategy):.2f}%")
        print(f"  Mortality Reduction:    {self.mortality_reduction(baseline, strategy):.2f}%")
        print(f"  LYG per 1000:          {self.discounted_ly_gained(baseline, strategy):.2f}")
        
        print(f"\n[Costs]")
        baseline_cost = self.total_discounted_costs(baseline)
        strategy_cost = self.total_discounted_costs(strategy)
        print(f"  Baseline Total:        ${baseline_cost:,.0f}")
        print(f"  Strategy Total:        ${strategy_cost:,.0f}")
        print(f"  Incremental:           ${(strategy_cost - baseline_cost):,.0f}")
        
        print(f"\n[Cost Breakdown - Strategy]")
        print(f"  Screening Costs:       ${self.total_screening_costs(strategy):,.0f}")
        print(f"  Followup Costs:        ${self.total_followup_costs(strategy):,.0f}")
        
        print(f"\n[ICER]")
        icer = self.usd_per_lyg(baseline, strategy)
        if icer == float('inf'):
            print(f"  USD per LYG:           N/A (no LYG)")
        else:
            print(f"  USD per LYG:           ${icer:,.0f}")
        
        print(f"{'='*60}\n")
