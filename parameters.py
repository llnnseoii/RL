import configparser
import numpy as np
import os

# ============================================================================
# 수정: parameters.py - Surveillance 플래그 + Stage Duration 파라미터 추가
# ============================================================================
class SimulationParameters:
    def __init__(self, settings_file='settings.ini'):
        self.main_config = configparser.ConfigParser()
        # 대소문자 구분을 위해 옵션 설정 (ini 파일 키값 보존)
        self.main_config.optionxform = str
        
        if not os.path.exists(settings_file):
            raise FileNotFoundError(f"Main configuration file not found: {settings_file}")
        
        self.main_config.read(settings_file)
        
        # --- 리스트 파싱 헬퍼 함수 ---
        def get_list(config, section, key, dtype=float):
            if not config.has_option(section, key):
                return np.array([], dtype=dtype)
            val = config.get(section, key)
            return np.array([dtype(x) for x in val.replace('\n', ',').split(',') if x.strip()], dtype=dtype)

        # =========================================================
        # [1] Settings.ini 로드
        # =========================================================
        # [General]
        self.population_size = self.main_config.getint('general', 'PopulationSize')
        self.years_to_simulate = self.main_config.getfloat('general', 'YearsToSimulate')
        self.dt = self.main_config.getfloat('general', 'dt')
        self.rng_seed = self.main_config.getint('general', 'RandomNumberSeed')
        self.n_cpus = self.main_config.getint('general', 'nCPUs')

        # [Flags] & [Evaluation switches]
        self.calculate_incidence = self.main_config.getint('evaluation', 'CalculateIncidence')
        self.perform_optimization = self.main_config.getint('optimization', 'performOptimization')
        self.evaluate_screening = self.main_config.getint('screening', 'evaluateScreeningScenarios')
        self.correlation = self.main_config.getboolean('flags', 'correlation')
        
        # ★★★ 추가: Surveillance 플래그들 (C++에는 Settings.h에 있음)
        # settings.ini에 [flags] 섹션에 추가 필요:
        #   PolypSurveillance=1
        #   CancerSurveillance=1
        if self.main_config.has_option('flags', 'PolypSurveillance'):
            self.polyp_surveillance = self.main_config.getboolean('flags', 'PolypSurveillance')
        else:
            self.polyp_surveillance = True  # 기본값: 활성화
        
        if self.main_config.has_option('flags', 'CancerSurveillance'):
            self.cancer_surveillance = self.main_config.getboolean('flags', 'CancerSurveillance')
        else:
            self.cancer_surveillance = True  # 기본값: 활성화

        # [Population]
        self.fraction_female = self.main_config.getfloat('population_parameters', 'fractionFemale')
        self.life_table_males = get_list(self.main_config, 'population_parameters', 'LifeTableMales')
        self.life_table_females = get_list(self.main_config, 'population_parameters', 'LifeTableFemales')
        self.life_table_males_cum = self._calc_cumulative(self.life_table_males)
        self.life_table_females_cum = self._calc_cumulative(self.life_table_females)

        # [Polyp]
        self.initial_polyp_stage = self.main_config.getint('polyp_related_parameters', 'initialPolypStage')
        self.num_polyp_stages = self.main_config.getint('polyp_related_parameters', 'NumPolypStages')
        self.adv_polyp_transition = self.main_config.getint('polyp_related_parameters', 'advancedPolypStageTransition')
        self.general_new_polyps_risk = get_list(self.main_config, 'polyp_related_parameters', 'GeneralNewPolypsRisk')
        self.individual_polyp_risk = get_list(self.main_config, 'polyp_related_parameters', 'IndividualPolypRisk')
        self.female_new_polyp_risk = self.main_config.getfloat('polyp_related_parameters', 'femaleNewPolypRisk')
        self.healing_rates = get_list(self.main_config, 'polyp_related_parameters', 'HealingRates')
        self.fast_cancer_rates = get_list(self.main_config, 'polyp_related_parameters', 'FastCancerRates')
        
        self.polyp_progression_rates = []
        for i in range(1, self.num_polyp_stages + 1):
            key = f'PolypStage{i}AgeProgressionRate'
            self.polyp_progression_rates.append(get_list(self.main_config, 'polyp_related_parameters', key))

        # [Cancer]
        self.direct_cancer_risk_male = get_list(self.main_config, 'cancer_related_parameters', 'GeneralDirectCancerRiskMale')
        self.direct_cancer_risk_female = get_list(self.main_config, 'cancer_related_parameters', 'GeneralDirectCancerRiskFemale')
        self.direct_cancer_speed = self.main_config.getfloat('cancer_related_parameters', 'DirectCancerSpeed')
        
        self.frac_stage1 = get_list(self.main_config, 'cancer_related_parameters', 'fractionBySexAndAgeAtDiagnosis_Stage1')
        self.frac_stage2 = get_list(self.main_config, 'cancer_related_parameters', 'fractionBySexAndAgeAtDiagnosis_Stage2')
        self.frac_stage3 = get_list(self.main_config, 'cancer_related_parameters', 'fractionBySexAndAgeAtDiagnosis_Stage3')
        self.frac_stage4 = get_list(self.main_config, 'cancer_related_parameters', 'fractionBySexAndAgeAtDiagnosis_Stage4')
        
        self.sojourn_cdf = []
        for i in range(1, 5):
            self.sojourn_cdf.append(get_list(self.main_config, 'cancer_related_parameters', f'sojournTimeStage{i}AtDiagnosisCDF'))

        self.survival_cutoff = self.main_config.getint('cancer_related_parameters', 'survivalCutoff')
        self.os_by_gender_age_stage = get_list(self.main_config, 'cancer_related_parameters', 'osByGenderAgeStage')
        self.n_age_groups = self.main_config.getint('cancer_related_parameters', 'nAgeGroups')
        self.os_age_ranges = get_list(self.main_config, 'cancer_related_parameters', 'osAgeRanges', dtype=int)
        self.num_data_points_per_surv_curve = self.main_config.getint('cancer_related_parameters', 'numDataPointsPerSurvCurve')

        # ★★★ 추가: Cancer Stage Duration 파라미터 (C++ SimulationParameters.h:52-54)
        # settings.ini에 [cancer_related_parameters] 섹션에 추가 필요:
        #   StageDurationStageIIDiagnosis=0.5
        #   StageDurationStageIIIDiagnosis=0.33,0.66
        #   StageDurationStageIVDiagnosis=0.25,0.50,0.75
        if self.main_config.has_option('cancer_related_parameters', 'StageDurationStageIIDiagnosis'):
            self.stage_duration_stage_ii = self.main_config.getfloat('cancer_related_parameters', 'StageDurationStageIIDiagnosis')
        else:
            self.stage_duration_stage_ii = 0.5  # 기본값
        
        self.stage_duration_stage_iii = get_list(self.main_config, 'cancer_related_parameters', 'StageDurationStageIIIDiagnosis')
        if len(self.stage_duration_stage_iii) == 0:
            self.stage_duration_stage_iii = np.array([0.33, 0.66])  # 기본값
        
        self.stage_duration_stage_iv = get_list(self.main_config, 'cancer_related_parameters', 'StageDurationStageIVDiagnosis')
        if len(self.stage_duration_stage_iv) == 0:
            self.stage_duration_stage_iv = np.array([0.25, 0.5, 0.75])  # 기본값

        # [Progression Risk]
        self.early_polyp_progression = get_list(self.main_config, 'progression_risk_parameters', 'EarlyPolypProgression')
        self.adv_polyp_progression = get_list(self.main_config, 'progression_risk_parameters', 'AdvancedPolypProgression')
        self.female_early_prog = self.main_config.getfloat('progression_risk_parameters', 'femaleEarlyProgression')
        self.female_adv_prog = self.main_config.getfloat('progression_risk_parameters', 'femaleAdvancedProgression')

        # [Location]
        self.new_polyp_location = get_list(self.main_config, 'location_related_parameters', 'NewPolypLocation')
        self.new_cancer_location = get_list(self.main_config, 'location_related_parameters', 'NewCancerLocation')
        self.loc_early_prog = get_list(self.main_config, 'location_related_parameters', 'LocationEarlyPolypProgression')
        self.loc_adv_prog = get_list(self.main_config, 'location_related_parameters', 'LocationAdvancedPolypProgression')

        # [Colonoscopy & Risks]
        self.colo_reach = get_list(self.main_config, 'colonoscopy_related_parameters', 'ColoReach')
        self.colo_det_polyp = get_list(self.main_config, 'colonoscopy_related_parameters', 'ColoDetectionPolyp')
        self.colo_det_cancer = get_list(self.main_config, 'colonoscopy_related_parameters', 'ColoDetectionCancer')
        self.colo_det_location = get_list(self.main_config, 'colonoscopy_related_parameters', 'ColoDetectionLocation')

        self.risk_perforation = self.main_config.getfloat('risks', 'ColonoscopyRiscPerforation')
        self.risk_serosa_burn = self.main_config.getfloat('risks', 'ColonoscopyRiscSerosaBurn')
        self.risk_bleeding = self.main_config.getfloat('risks', 'ColonoscopyRiscBleeding')
        self.risk_bleeding_transfusion = self.main_config.getfloat('risks', 'ColonoscopyRiscBleedingTransfusion')
        self.death_perforation = self.main_config.getfloat('risks', 'DeathPerforation')
        self.death_bleeding_transfusion = self.main_config.getfloat('risks', 'DeathBleedingTransfusion')

        # =========================================================
        # [2] Evaluation.ini 로드 (비용) - 수정 없음
        # =========================================================
        self.cost_colo = 0.0
        self.cost_colo_polyp = 0.0
        self.cost_colo_cancer = 0.0
        self.cost_perf = 0.0
        self.cost_bleed = 0.0
        self.cost_initial_cancer = [0.0]*5
        self.cost_final_cancer = [0.0]*5
        self.discount_coeff = 1.0
        self.discount_after_year = 0

        if self.main_config.has_option('evaluation', 'EvalIniFile'):
            raw_path = self.main_config.get('evaluation', 'EvalIniFile')
            eval_path = self._resolve_path(raw_path)
            
            if eval_path:
                eval_config = configparser.ConfigParser()
                eval_config.optionxform = str
                eval_config.read(eval_path)
                
                if eval_config.has_section('costs'):
                    self.discount_coeff = eval_config.getfloat('costs', 'DiscountingCoeff')
                    self.discount_after_year = eval_config.getint('costs', 'DiscountingAfterYear')
                    
                    self.cost_colo = eval_config.getfloat('costs', 'Colonoscopy')
                    self.cost_colo_polyp = eval_config.getfloat('costs', 'Colonoscopy_Polyp')
                    self.cost_colo_cancer = eval_config.getfloat('costs', 'Colonoscopy_Cancer')
                    self.cost_perf = eval_config.getfloat('costs', 'Colonoscopy_Perforation')
                    self.cost_bleed = eval_config.getfloat('costs', 'Colonoscopy_bleed')

                    self.cost_initial_cancer[1] = eval_config.getfloat('costs', 'Initial_I')
                    self.cost_initial_cancer[2] = eval_config.getfloat('costs', 'Initial_II')
                    self.cost_initial_cancer[3] = eval_config.getfloat('costs', 'Initial_III')
                    self.cost_initial_cancer[4] = eval_config.getfloat('costs', 'Initial_IV')
                    
                    self.cost_final_cancer[1] = eval_config.getfloat('costs', 'Final_I')
                    self.cost_final_cancer[2] = eval_config.getfloat('costs', 'Final_II')
                    self.cost_final_cancer[3] = eval_config.getfloat('costs', 'Final_III')
                    self.cost_final_cancer[4] = eval_config.getfloat('costs', 'Final_IV')
            else:
                print(f"[Warning] Evaluation INI file not found: {raw_path}")

        # =========================================================
        # [3] Optimization3D.ini 로드 (최적화) - 수정 없음
        # =========================================================
        self.opt_goals = [2]
        self.opt_num_colo = 3
        self.opt_min_age = 40
        self.opt_max_age = 80
        
        if self.perform_optimization or self.main_config.has_option('optimization', 'optimizationINIfile'):
            raw_path = self.main_config.get('optimization', 'optimizationINIfile')
            opt_path = self._resolve_path(raw_path)
            
            if opt_path:
                opt_config = configparser.ConfigParser()
                opt_config.optionxform = str
                opt_config.read(opt_path)
                
                if opt_config.has_section('general'):
                    if opt_config.has_option('general', 'goals'):
                        g_str = opt_config.get('general', 'goals')
                        self.opt_goals = [int(x) for x in g_str.split(',')]
                
                if opt_config.has_section('search_space'):
                    self.opt_num_colo = opt_config.getint('search_space', 'howManyColo')
                    self.opt_min_age = opt_config.getint('search_space', 'minAge')
                    self.opt_max_age = opt_config.getint('search_space', 'maxAge')
            else:
                print(f"[Warning] Optimization INI file not found: {raw_path}")

        # =========================================================
        # [4] ScreeningVarAdherence.ini 로드 (검진 시나리오) - 수정 없음
        # =========================================================
        self.screening_scenarios = []
        if self.evaluate_screening:
            raw_path = self.main_config.get('screening', 'screeningINIfile')
            scr_path = self._resolve_path(raw_path)
            
            if scr_path:
                scr_config = configparser.ConfigParser()
                scr_config.optionxform = str
                scr_config.read(scr_path)
                
                for section in scr_config.sections():
                    if section.startswith('adh'):
                        moments_str = scr_config.get(section, 'moments')
                        moments = [int(x) for x in moments_str.split(',')] if moments_str.strip() else []
                        compliance = scr_config.getfloat(section, 'compliance')
                        
                        self.screening_scenarios.append({
                            'name': section,
                            'moments': moments,
                            'compliance': compliance
                        })
            else:
                print(f"[Warning] Screening INI file not found: {raw_path}")

    def _resolve_path(self, raw_path):
        """InputFiles/ 폴더 경로를 현재 폴더 기준으로 보정"""
        if os.path.exists(raw_path): return raw_path
        basename = os.path.basename(raw_path)
        if os.path.exists(basename): return basename
        if os.path.exists(os.path.join('InputFiles', basename)):
            return os.path.join('InputFiles', basename)
        return None

    def _calc_cumulative(self, table):
        if len(table) == 0: return np.array([0.0, 1.0])
        cum = [0.0]
        for prob in table:
            new_val = (1 - cum[-1]) * prob + cum[-1]
            cum.append(new_val)
        cum.append(1.0)
        return np.array(cum)
