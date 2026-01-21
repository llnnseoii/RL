#include "Cancer.h"
#include <iostream>


Cancer::Cancer(float age, bool gender, SimulationParameters* SimParams, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> > *RG) {//constructor for direct cancer
		
	this->dwellTime = 0.0f;

	this->location = 0;	
	float u = (*RG)();
	while (u > SimParams->NewCancerLocation[this->location]) { this->location++; };

	this->initialize(age, gender, SimParams, RG);
}


Cancer::Cancer(float age, bool gender, float polypCreationAge, unsigned char polypLocation, SimulationParameters* SimParams, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >* RG) {//constructor for cancers created from a polyp

	this->dwellTime = age - polypCreationAge;
	this->location = polypLocation;

	this->initialize(age, gender, SimParams, RG);
}


void Cancer::initialize(float age, bool gender, SimulationParameters* SimParams, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >* RG) {
	
	this->canDevelop = true;
	this->detected = false;
	this->ageDeveloped = age;
	
	//check which age groups the person belongs to
	float ageGroups[15] = { 19.0f, 24.0f, 29.0f, 34.0f, 39.0f, 44.0f, 49.0f, 54.0f, 59.0f, 64.0f, 69.0f, 74.0f, 79.0f, 84.0f, 254.0f };
	unsigned char ageG = 0;
	while (age > ageGroups[ageG]) { ++ageG; };


	//generate stage at symptoms development
	float u = (*RG)();
	this->symptomsStage = 0;
	if (gender) {
		while (u > SimParams->stageDistributionFemales[ageG*4+this->symptomsStage]) { this->symptomsStage++; };
	}
	else {
		while (u > SimParams->stageDistributionMales[ageG*4+this->symptomsStage]) { this->symptomsStage++; };
	}
	this->symptomsStage++;
	

	//generate time to symptoms, we use the empirical CDF to generate the random number
	u = (*RG)();
	unsigned char i = 0;
	switch (this->symptomsStage) {
	case 1:
		while (u > SimParams->sojournTimeStage1AtDiagnosisCDF[i]) { i++; };
		break;
	case 2:
		while (u > SimParams->sojournTimeStage2AtDiagnosisCDF[i]) { i++; };
		break;
	case 3:
		while (u > SimParams->sojournTimeStage3AtDiagnosisCDF[i]) { i++; };
		break;
	case 4:
		while (u > SimParams->sojournTimeStage4AtDiagnosisCDF[i]) { i++; };
		break;
	}
	float st = (float)(i+1)*SimParams->dt;
	this->symptomsAge = this->ageDeveloped + st;
	
	//set the age progression table
	switch (this->symptomsStage) {
	case 2:
		ageProgression[2] = age + st * SimParams->StageDurationStageIIDiagnosis;
		break;
	case 3:
		ageProgression[1] = age + st * SimParams->StageDurationStageIIIDiagnosis[0];
		ageProgression[2] = age + st * SimParams->StageDurationStageIIIDiagnosis[1];
		break;
	case 4:
		ageProgression[0] = age + st * SimParams->StageDurationStageIVDiagnosis[0];
		ageProgression[1] = age + st * SimParams->StageDurationStageIVDiagnosis[1];
		ageProgression[2] = age + st * SimParams->StageDurationStageIVDiagnosis[2];
		break;
	}

}

unsigned char Cancer::stageAtColonoscopy(float age) {

	unsigned char stageC = 1; //we start with stage I
	
	switch (this->symptomsStage) {
	case 2:
		if (age >= this->ageProgression[2]) stageC = 2;
		break;
	case 3:
		if (age >= this->ageProgression[2]) {
			stageC = 3;
		} else if(age >= this->ageProgression[1]) {
			stageC = 2;
		}
		break;
	case 4:
		if (age >= this->ageProgression[2]) {
			stageC = 4;
		} else if(age >= this->ageProgression[1]) {
			stageC = 3;
		} else if(age >= this->ageProgression[0]) {
			stageC = 2;
		}
		break;
	}
	//std::cout << (int)stageC << " " << (int)this->symptomsStage << std::endl;
	return stageC;
}

float Cancer::generateMortalityTime(bool gender, float age, unsigned char stage, SimulationParameters* SimParams, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >* RG) {
	//check which age group
	int ageGroup = 0;
	for (int i = 0; i < SimParams->nAgeGroups-1; ++i)
		if (age >= SimParams->osAgeRanges[i]) {
			ageGroup++;
		} else {
			break;
		}
	
	//first males, then stage, then age group
	int indxStart = gender * SimParams->numDataPointsPerSurvCurve * SimParams->nAgeGroups*4; //4 = num Stages
	indxStart += ((int)stage-1) * SimParams->numDataPointsPerSurvCurve * SimParams->nAgeGroups;
	indxStart += ageGroup*SimParams->numDataPointsPerSurvCurve;

	vector<float> OS(SimParams->osByGenderAgeStage.begin()+indxStart+1, SimParams->osByGenderAgeStage.begin()+indxStart+SimParams->survivalCutoff+1);
	OS.push_back(1.0f);

	float R = (float)(*RG)();
	unsigned char mort = 0;
	while (R > OS[mort]) { mort++; };
	if (mort < 5) {
		return (float)mort+SimParams->dt+(*RG)();
	} else {
		return -1.0f; //won't die of this cancer
	}
}

void Cancer::printNaturalHistory(std::ofstream *outfile) {
	(*outfile) << ", ageDeveloped: " << this->ageDeveloped;
	(*outfile) << ", dwell: " << this->dwellTime;
	(*outfile) << ", location: " << (int)location;
	(*outfile) << ", symptomsStage: " << (int)symptomsStage;
	(*outfile) << ", symptomsAge: " << symptomsAge;
	(*outfile) << ", ageProgression: " << ageProgression[0] << " " << ageProgression[1] << " " << ageProgression[2];
}
