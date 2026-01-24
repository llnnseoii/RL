#include "Polyp.h"


Polyp::Polyp(float age, bool gender, SimulationParameters* SimParams, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >* RG) {
	this->ageDeveloped = age;
	this->ageEnd = SimParams->YearsToSimulate;

	this->stage = SimParams->initialPolypStage; //we start with stage 1

	this->cancerID = -1;
	
	this->location = 0;	
	float u = (*RG)();
	while (u > SimParams->NewPolypLocation[this->location]) { this->location++; };

	//RG->generateProgressionRisks(&this->earlyProgressionRisk, &this->advancedProgressionRisk, &this->earlyDirectProgressionRisk,&this->advancedDirectProgressionRisk, gender, this->location, SimParams);
	int R = (int)( (*RG)() * (double)(SimParams->EarlyPolypProgression.size()) ); //generate random integer
	this->earlyProgressionRisk = SimParams->EarlyPolypProgression[R];
	if (SimParams->correlation) {
		this->advancedProgressionRisk = SimParams->AdvancedPolypProgression[R];
	} else {
		int R2 = (int)( (*RG)() * (double)(SimParams->EarlyPolypProgression.size()) ); 
		this->advancedProgressionRisk = SimParams->AdvancedPolypProgression[R2];
	}

	//taking into account location
	this->earlyProgressionRisk *= SimParams->LocationEarlyPolypProgression[location];
	this->advancedProgressionRisk *= SimParams->LocationAdvancedPolypProgression[location];

	//taking into account gender
	if (gender) {
		this->earlyProgressionRisk *= SimParams->femaleEarlyProgression;
		this->advancedProgressionRisk *= SimParams->femaleAdvancedProgression;
	}
	
	//direct progression rates
	this->earlyDirectProgressionRisk = SimParams->LocationAdvancedPolypProgression[location]; //this is on purpose to be in line with previous code
	this->advancedDirectProgressionRisk = SimParams->LocationAdvancedPolypProgression[location];
	if (gender) {
		this->earlyDirectProgressionRisk *= SimParams->femaleAdvancedProgression; //this is on purpose to be in line with previous code
		this->advancedDirectProgressionRisk *= SimParams->femaleAdvancedProgression;
	}
	if (SimParams->DwellSpeed) {
		this->earlyDirectProgressionRisk *= SimParams->EarlyPolypProgression[R];
		this->advancedDirectProgressionRisk *= SimParams->AdvancedPolypProgression[R];
	}

}

void Polyp::simulate(SimulationParameters* SimParams, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> > *RG, bool gender, vector<Cancer> *outCancers) {
	
	float t = this->ageDeveloped;// + SimParams->dt; %to be in line with previous code one step can happen at the moment of creation
	while( t < SimParams->YearsToSimulate) {
		unsigned int shiftV = (unsigned int)floor(t)*6;
		//progress polyp
		if (this->stage >= SimParams->advancedPolypStageTransition) {//this is an advanced polyp
			if ((*RG)() < (SimParams->ageStageProgression[shiftV+(int)this->stage - 1] * this->advancedProgressionRisk)) {//decide if progression to next stage
				this->stage++;
				this->hist_t.push_back(t);
				this->hist_y.push_back(1);
			}
			else if ((*RG)() < SimParams->ageStageProgression[shiftV+(int)SimParams->NumPolypStages-1]*SimParams->FastCancerRates[this->stage - 1]*this->earlyDirectProgressionRisk) {//decide if direct progression to cancer
				outCancers->push_back(Cancer(t, gender, this->ageDeveloped, this->location, SimParams, RG)); //create new cancer
				this->cancerID = (short int)outCancers->size()-1;
				this->hist_t.push_back(t);
				this->hist_y.push_back(2);
				break;
			}
		}
		else {//it is an early polyp otherwise
			if ((*RG)() < (SimParams->ageStageProgression[shiftV+(int)this->stage - 1] * this->earlyProgressionRisk)) {//decide if progression to next stage
				this->stage++;
				this->hist_t.push_back(t);
				this->hist_y.push_back(1);
			}
			else if ((*RG)() < SimParams->ageStageProgression[shiftV+(int)SimParams->NumPolypStages - 1]*SimParams->FastCancerRates[this->stage-1]*this->advancedDirectProgressionRisk) {//decide if direct progression to cancer
				outCancers->push_back(Cancer(t, gender, this->ageDeveloped, this->location, SimParams, RG)); //create new cancer
				this->cancerID = (short int)outCancers->size()-1;
				this->hist_t.push_back(t);
				this->hist_y.push_back(1);
				break;
			}
		}

		//check if progressed to cancer
		if (this->stage > SimParams->NumPolypStages) {//progression to cancer, break loop and exit with status 2
			outCancers->push_back(Cancer(t, gender, this->ageDeveloped, this->location, SimParams, RG)); //create new cancer
			this->cancerID = (short int)outCancers->size()-1;
			this->hist_y.back() = 2;
			break;
		}
		
		//check if there is healing
		if ((*RG)() < SimParams->HealingRates[this->stage-1]) {
			this->stage--;
			this->hist_t.push_back(t);
			this->hist_y.push_back(0);
		}

		if (this->stage == 0) //polyp vanishes, break loop and exit with status 1
			break;

		t += SimParams->dt;
	}
	this->ageEnd = t;
}

unsigned char Polyp::stageAtColonoscopy(float age){
	
	unsigned char stageLoc = 1; //we start with stage 1
	for (size_t i = 0; i < this->hist_t.size(); ++i) {
		if (hist_t[i] >= age) break;
		if (hist_y[i] == 0) stageLoc--; 
		if (hist_y[i] == 1) stageLoc++;
		if (hist_y[i] == 2) stageLoc = 0; //if transormed to cancer then return 0
	}
	return stageLoc;
}

short int Polyp::printNaturalHistory(std::ofstream *outfile) {
	(*outfile)  << "1(" << this->ageDeveloped << ")";
	float t = this->ageDeveloped;
	int stageH = 1;
	for (size_t i = 0; i < this->hist_t.size(); ++i) {
		int Nrep = (int)((hist_t[i]-t)/0.25);
		for(int j = 0; j < Nrep; ++j) (*outfile) << "-";

		if (hist_y[i] == 0) {stageH--; (*outfile) << " " << stageH << "(" << hist_t[i] << ")" << " ";}; 
		if (hist_y[i] == 1) {stageH++; (*outfile) << " " << stageH << "(" << hist_t[i] << ")" << " ";}; 
		if (hist_y[i] == 2) {(*outfile) << " C ";};
		t = hist_t[i];
	}

	return this->cancerID;
}
