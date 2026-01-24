#include "SimulationParameters.h"

template<typename T>
std::vector<T> to_array(const std::string s)
{
	std::vector<T> result;
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, ',')) result.push_back(boost::lexical_cast<T>(item));
	return result;
}

std::vector<unsigned char> to_array_UCHAR(const std::string s)
{
	std::vector<unsigned char> result;
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, ',')) result.push_back((unsigned char)(boost::lexical_cast<int>(item)));
	return result;
}



SimulationParameters::SimulationParameters(char const* settingsFile) {
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini(settingsFile, pt);
	
	PopulationSize  = boost::lexical_cast<unsigned int>(pt.get<std::string>("general.PopulationSize"));
	YearsToSimulate = boost::lexical_cast<float>(pt.get<std::string>("general.YearsToSimulate"));
	dt = boost::lexical_cast<float>(pt.get<std::string>("general.dt"));
	RandomNumberSeed = boost::lexical_cast<unsigned int>(pt.get<std::string>("general.RandomNumberSeed"));
	nCPUs = boost::lexical_cast<int>(pt.get<std::string>("general.nCPUs"));
	maxCPUsPerEvaluation = boost::lexical_cast<int>(pt.get<std::string>("general.maxCPUsPerEvaluation"));

	CalculateIncidence=boost::lexical_cast<bool>(pt.get<std::string>("evaluation.CalculateIncidence"));
	CalculatePolypsPrevalence=boost::lexical_cast<bool>(pt.get<std::string>("evaluation.CalculatePolypsPrevalence"));
	resultsFile=pt.get<std::string>("evaluation.resultsFile");

	EvalIniFile=pt.get<std::string>("evaluation.EvalIniFile");

	evaluateScreeningScenarios=boost::lexical_cast<bool>(pt.get<std::string>("screening.evaluateScreeningScenarios"));
	screeningINIfile=pt.get<std::string>("screening.screeningINIfile");
	screeningOutFile=pt.get<std::string>("screening.screeningOutFile");
	
	StratifyPopulation=boost::lexical_cast<bool>(pt.get<std::string>("stratification.StratifyPopulation"));
	StratificationIniFile=pt.get<std::string>("stratification.StratificationIniFile");

	
	performOptimization=boost::lexical_cast<bool>(pt.get<std::string>("optimization.performOptimization"));
	optimizationINIfile=pt.get<std::string>("optimization.optimizationINIfile");
	optimizationOutFile=pt.get<std::string>("optimization.optimizationOutFile");

	correlation = boost::lexical_cast<bool>(pt.get<std::string>("flags.correlation"));
	PolypSurveillance = boost::lexical_cast<bool>(pt.get<std::string>("flags.PolypSurveillance"));
	CancerSurveillance = boost::lexical_cast<bool>(pt.get<std::string>("flags.CancerSurveillance"));
	AllPolypFollowUp = boost::lexical_cast<bool>(pt.get<std::string>("flags.AllPolypFollowUp"));


	fractionFemale  = boost::lexical_cast<float>(pt.get<std::string>("population_parameters.fractionFemale"));
	LifeTableMales  = to_array<float>(pt.get<std::string>("population_parameters.LifeTableMales"));
	LifeTableFemales  = to_array<float>(pt.get<std::string>("population_parameters.LifeTableFemales"));

	
	initialPolypStage = (unsigned char)boost::lexical_cast<int>(pt.get<std::string>("polyp_related_parameters.initialPolypStage"));
	NumPolypStages = (unsigned char)boost::lexical_cast<int>(pt.get<std::string>("polyp_related_parameters.NumPolypStages"));
	advancedPolypStageTransition = (unsigned char)boost::lexical_cast<int>(pt.get<std::string>("polyp_related_parameters.advancedPolypStageTransition"));
	
	GeneralNewPolypsRisk = to_array<float>(pt.get<std::string>("polyp_related_parameters.GeneralNewPolypsRisk"));

	PolypStage1AgeProgressionRate = to_array<float>(pt.get<std::string>("polyp_related_parameters.PolypStage1AgeProgressionRate"));
	PolypStage2AgeProgressionRate = to_array<float>(pt.get<std::string>("polyp_related_parameters.PolypStage2AgeProgressionRate"));
	PolypStage3AgeProgressionRate = to_array<float>(pt.get<std::string>("polyp_related_parameters.PolypStage3AgeProgressionRate"));
	PolypStage4AgeProgressionRate = to_array<float>(pt.get<std::string>("polyp_related_parameters.PolypStage4AgeProgressionRate"));
	PolypStage5AgeProgressionRate = to_array<float>(pt.get<std::string>("polyp_related_parameters.PolypStage5AgeProgressionRate"));
	PolypStage6AgeProgressionRate = to_array<float>(pt.get<std::string>("polyp_related_parameters.PolypStage6AgeProgressionRate"));
	
	IndividualPolypRisk = to_array<float>(pt.get<std::string>("polyp_related_parameters.IndividualPolypRisk"));
	femaleNewPolypRisk = boost::lexical_cast<float>(pt.get<std::string>("polyp_related_parameters.femaleNewPolypRisk"));
	HealingRates = to_array<float>(pt.get<std::string>("polyp_related_parameters.HealingRates"));
	FastCancerRates = to_array<float>(pt.get<std::string>("polyp_related_parameters.FastCancerRates"));
	DwellSpeed = boost::lexical_cast<bool>(pt.get<std::string>("polyp_related_parameters.DwellSpeed"));


	GeneralDirectCancerRiskMale=to_array<float>(pt.get<std::string>("cancer_related_parameters.GeneralDirectCancerRiskMale"));
	GeneralDirectCancerRiskFemale=to_array<float>(pt.get<std::string>("cancer_related_parameters.GeneralDirectCancerRiskFemale"));
	DirectCancerSpeed=boost::lexical_cast<float>(pt.get<std::string>("cancer_related_parameters.DirectCancerSpeed"));
	StageDurationStageIIDiagnosis=boost::lexical_cast<float>(pt.get<std::string>("cancer_related_parameters.StageDurationStageIIDiagnosis"));
	StageDurationStageIIIDiagnosis=to_array<float>(pt.get<std::string>("cancer_related_parameters.StageDurationStageIIIDiagnosis"));
	StageDurationStageIVDiagnosis=to_array<float>(pt.get<std::string>("cancer_related_parameters.StageDurationStageIVDiagnosis"));


	survivalCutoff=(unsigned char)boost::lexical_cast<int>(pt.get<std::string>("cancer_related_parameters.survivalCutoff"));
	osByGenderAgeStage=to_array<float>(pt.get<std::string>("cancer_related_parameters.osByGenderAgeStage"));
	nAgeGroups=(unsigned char)boost::lexical_cast<int>(pt.get<std::string>("cancer_related_parameters.nAgeGroups"));
	osAgeRanges=to_array_UCHAR(pt.get<std::string>("cancer_related_parameters.osAgeRanges"));
	numDataPointsPerSurvCurve=(unsigned char)boost::lexical_cast<int>(pt.get<std::string>("cancer_related_parameters.numDataPointsPerSurvCurve"));

	fractionBySexAndAgeAtDiagnosis_Stage1=to_array<float>(pt.get<std::string>("cancer_related_parameters.fractionBySexAndAgeAtDiagnosis_Stage1"));
	fractionBySexAndAgeAtDiagnosis_Stage2=to_array<float>(pt.get<std::string>("cancer_related_parameters.fractionBySexAndAgeAtDiagnosis_Stage2"));
	fractionBySexAndAgeAtDiagnosis_Stage3=to_array<float>(pt.get<std::string>("cancer_related_parameters.fractionBySexAndAgeAtDiagnosis_Stage3"));
	fractionBySexAndAgeAtDiagnosis_Stage4=to_array<float>(pt.get<std::string>("cancer_related_parameters.fractionBySexAndAgeAtDiagnosis_Stage4"));

	sojournTimeStage1AtDiagnosisCDF=to_array<float>(pt.get<std::string>("cancer_related_parameters.sojournTimeStage1AtDiagnosisCDF"));
	sojournTimeStage2AtDiagnosisCDF=to_array<float>(pt.get<std::string>("cancer_related_parameters.sojournTimeStage2AtDiagnosisCDF"));
	sojournTimeStage3AtDiagnosisCDF=to_array<float>(pt.get<std::string>("cancer_related_parameters.sojournTimeStage3AtDiagnosisCDF"));
	sojournTimeStage4AtDiagnosisCDF=to_array<float>(pt.get<std::string>("cancer_related_parameters.sojournTimeStage4AtDiagnosisCDF"));

	femaleEarlyProgression=boost::lexical_cast<float>(pt.get<std::string>("progression_risk_parameters.femaleEarlyProgression"));
	femaleAdvancedProgression=boost::lexical_cast<float>(pt.get<std::string>("progression_risk_parameters.femaleAdvancedProgression"));
	
	EarlyPolypProgression=to_array<float>(pt.get<std::string>("progression_risk_parameters.EarlyPolypProgression"));
	AdvancedPolypProgression=to_array<float>(pt.get<std::string>("progression_risk_parameters.AdvancedPolypProgression"));

	numLocations=(unsigned char)boost::lexical_cast<int>(pt.get<std::string>("location_related_parameters.numLocations"));
	NewPolypLocation=to_array<float>(pt.get<std::string>("location_related_parameters.NewPolypLocation"));
	NewCancerLocation=to_array<float>(pt.get<std::string>("location_related_parameters.NewCancerLocation"));
	LocationEarlyPolypProgression=to_array<float>(pt.get<std::string>("location_related_parameters.LocationEarlyPolypProgression"));
	LocationAdvancedPolypProgression=to_array<float>(pt.get<std::string>("location_related_parameters.LocationAdvancedPolypProgression"));


	
	ColoReach=to_array<float>(pt.get<std::string>("colonoscopy_related_parameters.ColoReach"));
	ColoDetectionPolyp=to_array<float>(pt.get<std::string>("colonoscopy_related_parameters.ColoDetectionPolyp"));
	ColoDetectionCancer=to_array<float>(pt.get<std::string>("colonoscopy_related_parameters.ColoDetectionCancer"));
	ColoDetectionLocation=to_array<float>(pt.get<std::string>("colonoscopy_related_parameters.ColoDetectionLocation"));
	
	ColonoscopyRiscPerforation=boost::lexical_cast<float>(pt.get<std::string>("risks.ColonoscopyRiscPerforation"));
	RectosigmoPerforation=boost::lexical_cast<float>(pt.get<std::string>("risks.RectosigmoPerforation"));
	ColonoscopyRiscSerosaBurn=boost::lexical_cast<float>(pt.get<std::string>("risks.ColonoscopyRiscSerosaBurn"));
	ColonoscopyRiscBleedingTransfusion=boost::lexical_cast<float>(pt.get<std::string>("risks.ColonoscopyRiscBleedingTransfusion"));
	ColonoscopyRiscBleeding=boost::lexical_cast<float>(pt.get<std::string>("risks.ColonoscopyRiscBleeding"));
	DeathPerforation=boost::lexical_cast<float>(pt.get<std::string>("risks.DeathPerforation"));
	DeathBleedingTransfusion=boost::lexical_cast<float>(pt.get<std::string>("risks.DeathBleedingTransfusion"));

	//perform additional recalculation for simulations
	recalculate();
}

template<typename T>
void printArray(const vector<T> v) {
	size_t L = v.size()<10?v.size():10;
	std::cout << "(" << v.size() << ") ";
	for (size_t i = 0; i < L; ++i) 
		std::cout << v.at(i) << ", ";
	std::cout << "..." << std::endl;
}

void printArrayUCHAR(const vector<unsigned char> v) {
	size_t L = v.size()<10?v.size():10;
	for (size_t i = 0; i < L; ++i) 
		std::cout << (int)v.at(i) << ", ";
	
	std::cout << "..." << std::endl;
}


void SimulationParameters::recalculate(){

	//taking care of Life Tables
	LifeTableMalesCumulative.push_back(.0f);
	LifeTableFemalesCumulative.push_back(.0f);
	
	for (int i = 0; i < LifeTableMales.size(); ++i)
		LifeTableMalesCumulative.push_back((1-LifeTableMalesCumulative.at(i))*LifeTableMales.at(i)+LifeTableMalesCumulative.at(i));
	LifeTableMalesCumulative.push_back(1.0f);

	
	for (int i = 0; i < LifeTableFemales.size(); ++i)
		LifeTableFemalesCumulative.push_back((1-LifeTableFemalesCumulative.at(i))*LifeTableFemales.at(i)+LifeTableFemalesCumulative.at(i));
	LifeTableFemalesCumulative.push_back(1.0f);

	
	this->ageStageProgression.reserve(6*this->PolypStage1AgeProgressionRate.size());
	for (int i = 0; i < this->PolypStage1AgeProgressionRate.size(); ++i) {
		this->ageStageProgression.push_back(this->PolypStage1AgeProgressionRate[i]);
		this->ageStageProgression.push_back(this->PolypStage2AgeProgressionRate[i]);
		this->ageStageProgression.push_back(this->PolypStage3AgeProgressionRate[i]);
		this->ageStageProgression.push_back(this->PolypStage4AgeProgressionRate[i]);
		this->ageStageProgression.push_back(this->PolypStage5AgeProgressionRate[i]);
		this->ageStageProgression.push_back(this->PolypStage6AgeProgressionRate[i]);
	}

	this->stageDistributionFemales.reserve(4*this->fractionBySexAndAgeAtDiagnosis_Stage1.size());
	for (int i = 0; i < (this->fractionBySexAndAgeAtDiagnosis_Stage1.size()-15); ++i){
		this->stageDistributionFemales.push_back(this->fractionBySexAndAgeAtDiagnosis_Stage1[i]);
		this->stageDistributionFemales.push_back(this->fractionBySexAndAgeAtDiagnosis_Stage2[i] + this->fractionBySexAndAgeAtDiagnosis_Stage1[i]);
		this->stageDistributionFemales.push_back(this->fractionBySexAndAgeAtDiagnosis_Stage3[i] + this->fractionBySexAndAgeAtDiagnosis_Stage2[i] + this->fractionBySexAndAgeAtDiagnosis_Stage1[i]);
		this->stageDistributionFemales.push_back(1.0f);

		this->stageDistributionMales.push_back(this->fractionBySexAndAgeAtDiagnosis_Stage1[i+15]);
		this->stageDistributionMales.push_back(this->fractionBySexAndAgeAtDiagnosis_Stage2[i+15] + this->fractionBySexAndAgeAtDiagnosis_Stage1[i+15]);
		this->stageDistributionMales.push_back(this->fractionBySexAndAgeAtDiagnosis_Stage3[i+15] + this->fractionBySexAndAgeAtDiagnosis_Stage2[i+15] + this->fractionBySexAndAgeAtDiagnosis_Stage1[i+15]);
		this->stageDistributionMales.push_back(1.0f);
	}

	//recalculate OS curves
	for (size_t i = 0; i < this->osByGenderAgeStage.size(); ++i)
		osByGenderAgeStage[i] = 1 - osByGenderAgeStage[i];
}

void SimulationParameters::printParams(unsigned char level) {
	if (level > 0) {
		std::cout << "Population size: " << PopulationSize << std::endl;
		std::cout << "RandomNumberSeed: " << RandomNumberSeed << std::endl;
		std::cout << "nCPUs: " << nCPUs << std::endl;
		std::cout << std::endl;
	}

	if (level > 1) {
		std::cout << "YearsToSimulate: " << YearsToSimulate << std::endl;
		std::cout << "dt: " << dt << std::endl;
		std::cout << "correlation: " << (int)correlation << std::endl;
		std::cout << "PolypSurveillance: " << (int)PolypSurveillance << std::endl;
		std::cout << "CancerSurveillance: " << (int)CancerSurveillance << std::endl;
		std::cout << "AllPolypFollowUp: " << (int)AllPolypFollowUp << std::endl;
		std::cout << "fractionFemale: " << fractionFemale << std::endl;
		std::cout << "LifeTableMales: "; printArray<float>(LifeTableMales);
		std::cout << "LifeTableFemales: "; printArray<float>(LifeTableFemales);
		std::cout << std::endl;
		
		std::cout << "initialPolypStage: " << (int)initialPolypStage << std::endl;
		std::cout << "NumPolypStages: " << (int)NumPolypStages << std::endl;
		std::cout << "advancedPolypStageTransition: " << (int)advancedPolypStageTransition << std::endl;
		std::cout << std::endl;

		std::cout << "GeneralNewPolypsRisk: "; printArray<float>(GeneralNewPolypsRisk);
		std::cout << std::endl;

		std::cout << "PolypStage1AgeProgressionRate: "; printArray<float>(PolypStage1AgeProgressionRate);
		std::cout << "PolypStage2AgeProgressionRate: "; printArray<float>(PolypStage2AgeProgressionRate);
		std::cout << "PolypStage3AgeProgressionRate: "; printArray<float>(PolypStage3AgeProgressionRate);
		std::cout << "PolypStage4AgeProgressionRate: "; printArray<float>(PolypStage4AgeProgressionRate);
		std::cout << "PolypStage5AgeProgressionRate: "; printArray<float>(PolypStage5AgeProgressionRate);
		std::cout << "PolypStage6AgeProgressionRate: "; printArray<float>(PolypStage6AgeProgressionRate);
		std::cout << std::endl;

		std::cout << "IndividualPolypRisk: "; printArray<float>(IndividualPolypRisk);
		std::cout << "femaleNewPolypRisk: " << femaleNewPolypRisk << std::endl;
		std::cout << "HealingRates: "; printArray<float>(HealingRates);
		std::cout << "FastCancerRates: "; printArray<float>(FastCancerRates);
		std::cout << "DwellSpeed: " << (int)DwellSpeed << std::endl;
		std::cout << std::endl;

		std::cout << "GeneralDirectCancerRiskMale: "; printArray<float>(GeneralDirectCancerRiskMale);
		std::cout << "GeneralDirectCancerRiskFemale: "; printArray<float>(GeneralDirectCancerRiskFemale);
		std::cout << "DirectCancerSpeed: " << DirectCancerSpeed << std::endl;
		std::cout << "StageDurationStageIIDiagnosis: " << StageDurationStageIIDiagnosis << std::endl;
		std::cout << "StageDurationStageIIIDiagnosis: "; printArray<float>(StageDurationStageIIIDiagnosis);
		std::cout << "StageDurationStageIVDiagnosis: "; printArray<float>(StageDurationStageIVDiagnosis);
		std::cout << std::endl;

		std::cout << "survivalCutoff: " << (int)survivalCutoff << std::endl;
		std::cout << "osByGenderAgeStage: "; printArray<float>(osByGenderAgeStage);
		std::cout << "nAgeGroups: " << (int)nAgeGroups << std::endl;
		std::cout << "osAgeRanges: "; printArrayUCHAR(osAgeRanges);
		std::cout << "numDataPointsPerSurvCurve: " << (int)numDataPointsPerSurvCurve << std::endl;
		std::cout << std::endl;
		
		std::cout << "fractionBySexAndAgeAtDiagnosis_Stage1: "; printArray<float>(fractionBySexAndAgeAtDiagnosis_Stage1);
		std::cout << "fractionBySexAndAgeAtDiagnosis_Stage2: "; printArray<float>(fractionBySexAndAgeAtDiagnosis_Stage2);
		std::cout << "fractionBySexAndAgeAtDiagnosis_Stage3: "; printArray<float>(fractionBySexAndAgeAtDiagnosis_Stage3);
		std::cout << "fractionBySexAndAgeAtDiagnosis_Stage4: "; printArray<float>(fractionBySexAndAgeAtDiagnosis_Stage4);

		std::cout << "sojournTimeStage1AtDiagnosisCDF: "; printArray<float>(sojournTimeStage1AtDiagnosisCDF);
		std::cout << "sojournTimeStage2AtDiagnosisCDF: "; printArray<float>(sojournTimeStage2AtDiagnosisCDF);
		std::cout << "sojournTimeStage3AtDiagnosisCDF: "; printArray<float>(sojournTimeStage3AtDiagnosisCDF);
		std::cout << "sojournTimeStage4AtDiagnosisCDF: "; printArray<float>(sojournTimeStage4AtDiagnosisCDF);

		std::cout << "femaleEarlyProgression: " << femaleEarlyProgression << std::endl;
		std::cout << "femaleAdvancedProgression: " << femaleAdvancedProgression << std::endl;
		
		std::cout << "EarlyPolypProgression: "; printArray<float>(EarlyPolypProgression);
		std::cout << "AdvancedPolypProgression: "; printArray<float>(AdvancedPolypProgression);
		
		std::cout << "numLocations: " << (int)numLocations << std::endl;
		std::cout << "NewPolypLocation: "; printArray<float>(NewPolypLocation);
		std::cout << "NewCancerLocation: "; printArray<float>(NewCancerLocation);
		std::cout << "LocationEarlyPolypProgression: "; printArray<float>(LocationEarlyPolypProgression);
		std::cout << "LocationAdvancedPolypProgression: "; printArray<float>(LocationAdvancedPolypProgression);

		std::cout << "ColoReach: "; printArray<float>(ColoReach);
		std::cout << "ColoDetectionPolyp: "; printArray<float>(ColoDetectionPolyp);
		std::cout << "ColoDetectionCancer: "; printArray<float>(ColoDetectionCancer);
		std::cout << "ColoDetectionLocation: "; printArray<float>(ColoDetectionLocation);

		std::cout << "ColonoscopyRiscPerforation: " << ColonoscopyRiscPerforation << std::endl;
		std::cout << "RectosigmoPerforation: " << RectosigmoPerforation << std::endl;
		std::cout << "ColonoscopyRiscSerosaBurn: " << ColonoscopyRiscSerosaBurn << std::endl;
		std::cout << "ColonoscopyRiscBleedingTransfusion: " << ColonoscopyRiscBleedingTransfusion << std::endl;
		std::cout << "ColonoscopyRiscBleeding: " << ColonoscopyRiscBleeding << std::endl;
		std::cout << "DeathPerforation: " << DeathPerforation << std::endl;
		std::cout << "DeathBleedingTransfusion: " << DeathBleedingTransfusion << std::endl;
	
	}
}


float SimulationParameters::ColoDetection(bool type, unsigned char stage, unsigned char location) {
	//type = false for polyp, true for cancer
	if (type) {//cancer
		return this->ColoDetectionCancer[stage - 1];
	}
	else {//polyp
		return this->ColoDetectionPolyp[stage - 1] * this->ColoDetectionLocation[location];
	}
};