#pragma once

#include <vector>
#include <queue>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>

using namespace std;

class SimulationParameters
{
public:
	//--- General parameters of the simulation
	unsigned int PopulationSize; //number of people to simulate
	float YearsToSimulate; //number of years to simulate
	float dt; //time step duration, fraction of the year, e.g. 0.25 means that each step is 3 months
	unsigned int RandomNumberSeed;
	unsigned int nCPUs,maxCPUsPerEvaluation;
	//-----------------------------

	//---- Paramteres related to evaluation
	bool CalculateIncidence;
	bool CalculatePolypsPrevalence;
	std::string resultsFile;

	std::string EvalIniFile;


	//-------------------------
	bool evaluateScreeningScenarios,screening;
	std::string screeningINIfile;
	std::string screeningOutFile;
	queue<float> screeningMoments;
	float compliance, timeSinceLastColo;

	//------------------------
	bool StratifyPopulation;
    std::string StratificationIniFile;


	//------------------------
	bool performOptimization;
	std::string optimizationINIfile;
	std::string optimizationOutFile;


	//--- Flags
	bool correlation;
	bool PolypSurveillance;
	bool CancerSurveillance;
	bool AllPolypFollowUp;
	//-------


	//-- Population related parameters
	float fractionFemale;//fraction of the females in the simulated population
	vector<float> LifeTableMales, LifeTableMalesCumulative; 
	vector<float> LifeTableFemales, LifeTableFemalesCumulative;
	//-----------------------------

	//-- Polyp related parameters
	unsigned char initialPolypStage; //what stage are newly generated polyps
	unsigned char NumPolypStages; //starting with 1
	unsigned char advancedPolypStageTransition; //at which stage we start calling polyp advanced
	vector<float> GeneralNewPolypsRisk;

	vector<float> PolypStage1AgeProgressionRate;
	vector<float> PolypStage2AgeProgressionRate;
	vector<float> PolypStage3AgeProgressionRate;
	vector<float> PolypStage4AgeProgressionRate;
	vector<float> PolypStage5AgeProgressionRate;
	vector<float> PolypStage6AgeProgressionRate;

	vector<float> IndividualPolypRisk;
	float femaleNewPolypRisk;
	vector<float> HealingRates;
	vector<float> FastCancerRates;
	bool DwellSpeed;
	//-------------------------

	//-- Cancer related parameters
	vector<float> GeneralDirectCancerRiskMale;
	vector<float> GeneralDirectCancerRiskFemale;
	float DirectCancerSpeed;
	float StageDurationStageIIDiagnosis;
	vector<float> StageDurationStageIIIDiagnosis;
	vector<float> StageDurationStageIVDiagnosis;



	unsigned char survivalCutoff; //how long are the survival curves
	vector<float> osByGenderAgeStage;
	unsigned char nAgeGroups; //number of available age groups
	vector<unsigned char> osAgeRanges;
	unsigned char numDataPointsPerSurvCurve; //number of data points for survival, there is data for 0, 12, .., 120 months

	vector<float> fractionBySexAndAgeAtDiagnosis_Stage1;
	vector<float> fractionBySexAndAgeAtDiagnosis_Stage2;
	vector<float> fractionBySexAndAgeAtDiagnosis_Stage3;
	vector<float> fractionBySexAndAgeAtDiagnosis_Stage4;

	vector<float> sojournTimeStage1AtDiagnosisCDF;
	vector<float> sojournTimeStage2AtDiagnosisCDF;
	vector<float> sojournTimeStage3AtDiagnosisCDF;
	vector<float> sojournTimeStage4AtDiagnosisCDF;
	//-------------------------

	//--- Progression risk parameters
	float femaleEarlyProgression;
	float femaleAdvancedProgression;

	vector<float> EarlyPolypProgression;
	vector<float> AdvancedPolypProgression;
	//---

	//---Location related parameters
	unsigned char numLocations; //we consider 13 locations
	vector<float> NewPolypLocation; //empirical CDF
	vector<float> NewCancerLocation; //empirical CDF

	vector<float> LocationEarlyPolypProgression;
	vector<float> LocationAdvancedPolypProgression;


	

	//---Colonoscopy related parameters
	vector<float> ColoReach;
	vector<float> ColoDetectionPolyp;
	vector<float> ColoDetectionCancer;
	vector<float> ColoDetectionLocation;
	

	float ColonoscopyRiscPerforation;
	float RectosigmoPerforation;
	float ColonoscopyRiscSerosaBurn;
	float ColonoscopyRiscBleedingTransfusion;
	float ColonoscopyRiscBleeding;
	float DeathPerforation;
	float DeathBleedingTransfusion;
	//------------------------

	//------ AUXiliary variables (DON'T NEED TO HAVE VALUES BECAUSE WILL BE SET DURING SIMULATION)
	vector<float> stageDistributionMales;
	vector<float> stageDistributionFemales;
	vector<float> ageStageProgression;
	//------

	SimulationParameters(){};
	SimulationParameters(char const *);
	~SimulationParameters() {};

	void recalculate();

	void printParams(unsigned char);

	float ColoDetection(bool, unsigned char, unsigned char);

	void updateAgeRelatedParameters(unsigned char);

	bool readParamsFromFile();

};

