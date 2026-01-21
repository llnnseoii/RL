#include "Person.h"

Person::Person() {

}

Person::Person(SimulationParameters* sp, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >* rg) {
	SimParams = sp;
	RG = rg;

	LastEarlyPolyp = -1.0f;
	LastAdvPolyp = -1.0f;
	LastColonoscopy = -1.0f;
	LastCancer = -1.0f;

	deathCancerRelated = -1.0f;

	gender = (*RG)() < SimParams->fractionFemale;//male = 0, female = 1
	individualRiskOfPolypCreation = SimParams->IndividualPolypRisk[(int)((*RG)()*(double)(SimParams->IndividualPolypRisk.size()))];
	if (gender)
		individualRiskOfPolypCreation *= SimParams->femaleNewPolypRisk;

}

void Person::updateParams(SimulationParameters* sp, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >* rg) {
	SimParams = sp;
	RG = rg;
}

unsigned char Person::getNumberDetectedCancers() {
	return this->numberDetectedCancers;
}

void Person::simulate() {

	//generate death year from life tables
	unsigned char deathYearNoCancer = 0;
	float R = (float)(*RG)(); //only one rundom number generation and only one invocation to life tables
	if (gender) {
		while (R > SimParams->LifeTableFemalesCumulative[deathYearNoCancer+1])
			deathYearNoCancer++;
	} else {
		while (R > SimParams->LifeTableMalesCumulative[deathYearNoCancer+1])
			deathYearNoCancer++;
	}
	this->deathYearLifeTables = (float)deathYearNoCancer + (*RG)();

	//generate polyps in the whole lifetime
	unsigned char subN = (unsigned char)1.0f/SimParams->dt;
	unsigned char N = (unsigned char)SimParams->YearsToSimulate;
	for (unsigned char age = 0; age < N; ++age) {
		for (unsigned char s=0; s < subN; ++s) {
			if ((*RG)() < this->individualRiskOfPolypCreation * SimParams->GeneralNewPolypsRisk[age])
				this->polyps.push_back(Polyp((float)age+(float)s*SimParams->dt, this->gender, SimParams, RG));		
		}
	}
	
	//progress all polyps at the same time at see which will generate cancers
	for (size_t i = 0; i < this->polyps.size(); ++i)
		this->polyps[i].simulate(SimParams, RG,this->gender,&this->cancers);

	
	//generate direct cancers in the whole lifetime
	for (unsigned char age = 0; age < N; ++age){
		float risk = (this->gender ? SimParams->DirectCancerSpeed*SimParams->GeneralDirectCancerRiskFemale[age] : SimParams->DirectCancerSpeed*SimParams->GeneralDirectCancerRiskMale[age]);
		for (unsigned char s=0; s < subN; ++s)
			if ((*RG)() < risk)
				this->cancers.push_back(Cancer((float)age+(float)s*SimParams->dt, this->gender, SimParams, RG));
	}
}

float max(float a, float b) {
	return a>b?a:b;
}

float Person::findColonoscopyMoment(vector<Cancer> *c, float maxAge, queue<float> *sM, unsigned char *type) {
	
	(*type) = 0; //default value

	//take into account symptomps development
	float moment = -1.0f;
	for (int i = 0; i < c->size(); ++i) 
		if (c->at(i).canDevelop && !c->at(i).detected && (moment < 0.0f || moment > c->at(i).symptomsAge) && c->at(i).symptomsAge < maxAge) {
			moment = c->at(i).symptomsAge;
			(*type) = 1;
		}
	

	float momentSurv = -1.0f;
	//takie into account surveillance
	if (this->LastColonoscopy > 0.0f) {
		vector<float> moments;

		if (SimParams->PolypSurveillance) {
				
			if (this->LastEarlyPolyp > 0.0f)
				if (this->LastEarlyPolyp == this->LastColonoscopy) {
					moments.push_back(this->LastEarlyPolyp + 5.0f);
				} else {
					//first that is 5-9 years after lastAdv polyp and 5 years after last colonoscopy
					float c = max(this->LastColonoscopy,this->LastEarlyPolyp+1.0f)+5.0f;
					if (c <= this->LastEarlyPolyp + 9.0f)
						moments.push_back(c);
				}

			if (this->LastAdvPolyp > 0.0f) {
				if (this->LastAdvPolyp == this->LastColonoscopy) {
					moments.push_back(this->LastAdvPolyp + 3.0f);
				} else {
					//first that is 5 years after lastAdv polyp and 5 years after last colonoscopy
					moments.push_back(max(this->LastColonoscopy,this->LastAdvPolyp)+5.0f);
				}
			}
		}

		if (SimParams->CancerSurveillance) {
			if (this->LastCancer > 0.0f) {//if had cancer
				if (this->LastCancer == this->LastColonoscopy) {
					moments.push_back(this->LastCancer+1.0f);
				} else if (this->LastCancer == this->LastColonoscopy - 1.0f) {
					moments.push_back(this->LastCancer+4.0f);
				} else {
					//first that is 5 years after lastAdv polyp and 5 years after last colonoscopy
					moments.push_back(max(this->LastColonoscopy,this->LastCancer)+5.0f);
				}
			}
		}

		if (!moments.empty()) {
			sort(moments.begin(), moments.end());
			for (int i = 0; i < moments.size(); ++ i)
				if (moments[i] > this->LastColonoscopy) {
					momentSurv = moments[i];
					break;
				}
		}
	}

	if (moment > 0.0f && momentSurv > 0.0f) {
		if (momentSurv < moment) {
			moment = momentSurv;
			(*type) = 2;
		}
		//moment = momentSurv < moment?momentSurv:moment;
	} else if (momentSurv > 0.0f) {
		moment = momentSurv;
		(*type) = 2;
	}

	//take into account screening 
	if (SimParams->screening) {
		
		while (!sM->empty()) {
			if (moment < 0.0f) {//no other colonoscopy scheduled
				if (sM->front()-this->LastColonoscopy >= SimParams->timeSinceLastColo && (*RG)() < SimParams->compliance) {//patient will comply
					moment=sM->front();
					sM->pop();
					(*type) = 3;
					break;
				} else {
					sM->pop();
				}
			} else {
				if (sM->front() < moment && sM->front()-this->LastColonoscopy >= SimParams->timeSinceLastColo && (*RG)() < SimParams->compliance) {//patient will comply
					moment=sM->front();
					sM->pop();
					(*type) = 3;
					break;
				} else if (sM->front() > moment) {
					break;
				} else {
					sM->pop();
				}
			}
		}

	}
	

	return moment<maxAge?moment:-1.0f;
}


void Person::evaluateStrategy(Output *out) {
	
	//reset at the beginning
	this->deathCancerRelated = -1.0f;
	this->deathCause = 0;
	this->LastEarlyPolyp = -1.0f;
	this->LastAdvPolyp = -1.0f;
	this->LastColonoscopy = -1.0f;
	this->LastCancer = -1.0f;
	this->numberDetectedCancers = 0;


	queue<float> screeningMoments = this->SimParams->screeningMoments;
	
	unsigned short int cancerCounter, counterEarly, counterAdvanced ;
	bool perforation, serosa, bleeding, bleedingTransfusion;
	unsigned char type;

				
			//copy cancers for processing purposes
			vector<Cancer> cancersE = this->cancers;
			//copy polyps for processinf purposes
			vector<Polyp> polypsE = this->polyps;
			
			while (true) {
				//find colonoscopy moment
				float colonoscopyMoment = findColonoscopyMoment(&cancersE, this->deathYearLifeTables>SimParams->YearsToSimulate?SimParams->YearsToSimulate:this->deathYearLifeTables, &screeningMoments, &type);
				
				if (colonoscopyMoment < 0.0) break; //break if no colonoscopied to be performed
				
				if (this->deathCancerRelated > 0.0f && colonoscopyMoment >= this->deathCancerRelated)//died of cancer
					break;

				//perform colonscopy
				this->colonoscopy(colonoscopyMoment, &cancersE, &polypsE, &cancerCounter, &counterEarly, &counterAdvanced,
										&perforation, &serosa, &bleeding, &bleedingTransfusion);
				
				out->addColonoscopy(colonoscopyMoment, this->gender, cancerCounter, counterEarly, counterAdvanced,
					perforation, serosa, bleeding, bleedingTransfusion, type);
			}

			out->saveSummary(&cancersE, this->gender, this->deathCause, this->deathCancerRelated, this->deathYearLifeTables, this->SimParams->dt);

			if (SimParams->CalculatePolypsPrevalence)
				out->recordPolypsPrevalence(&polypsE, this->deathCancerRelated>0?min(this->deathCancerRelated,this->deathYearLifeTables):this->deathYearLifeTables, this->gender);
			
	out->recordDeath(this->deathCancerRelated,this->deathYearLifeTables, this->deathCause, this->gender);
}

bool Person::colonoscopy(float age, vector<Cancer> *cancersE, vector<Polyp> *polypsE, short unsigned int *cancerCounter, short unsigned int *counterEarly, short unsigned int *counterAdvanced,
						bool *perforation, bool *serosa, bool *bleeding, bool *bleedingTransfusion) {

	//bool cancerDetectionEvent = false;

	(*counterEarly) = 0;
	(*counterAdvanced) = 0;
	(*cancerCounter) = 0;

	(*perforation) = false;
	(*serosa) = false;
	(*bleeding) = false;
	(*bleedingTransfusion) = false;

	//generate radnom number about colonoscopy reach
	float R = (float)(*RG)();
	unsigned char coloReach = 0;
	while (R > SimParams->ColoReach[coloReach]) { coloReach++; };


	//go through each polyp and decide if detected
	std::vector<Polyp>::iterator polyp = polypsE->begin();
	while (polyp != polypsE->end()) {
		if (polyp->ageDeveloped <= age && age < polyp->ageEnd && polyp->location >= coloReach) {//if detected
			unsigned char stageAtColo = polyp->stageAtColonoscopy(age);//calculate stage at colonscopy
			if (stageAtColo == 0) {//transormed to cancer or vanished at exactly that time and we should remove it
				++polyp;
			} else if ((*RG)() < SimParams->ColoDetectionPolyp[stageAtColo - 1] * SimParams->ColoDetectionLocation[polyp->location]) {//detected
				
				if (stageAtColo < SimParams->advancedPolypStageTransition) {
					(*counterEarly)++;
				} else {
					(*counterAdvanced)++;
				}

				//flag corresponding cancers so they can't develop
				if (polyp->cancerID >= 0)
					cancersE->at(polyp->cancerID).canDevelop = false;

				polyp->ageEnd = age;//removed at colonoscopy
				++polyp;
			} else {//polyp missed after all, do nothing with it
				++polyp;
			}
		} else {//polyp missed, do nothing
			++polyp;
		}		  
	}


	//go through each cancer and decide if detected
	std::vector<Cancer>::iterator cancer = cancersE->begin();
	while (cancer != cancersE->end()) {
		if (cancer->canDevelop && !cancer->detected && cancer->ageDeveloped < age && cancer->location >= coloReach) {//if candidate for detection
			unsigned char stageAtColo = cancer->stageAtColonoscopy(age);
			if ((*RG)() < SimParams->ColoDetectionCancer[stageAtColo - 1]) {//cancer detected
				cancer->detected = true;
				cancer->stageAtDetection = stageAtColo;
				cancer->ageDetected = age;
				(*cancerCounter)++;
				
				float MT = cancer->generateMortalityTime(this->gender, age, stageAtColo, SimParams, RG);
				if (MT > 0 && (this->deathCancerRelated < 0 || this->deathCancerRelated > age+MT)) {//there is cancer associated death
					this->deathCancerRelated = age+MT;
					this->deathCause = 1;
				}

			}
		} 
		++cancer;
	}

	if ((*cancerCounter) > 0) this->LastCancer = age;
	if ((*counterEarly) > 0) this->LastEarlyPolyp = age;
	if ((*counterAdvanced) > 0 || (*counterEarly) > 2) this->LastAdvPolyp = age;//three early polyps count as adanced one

	this->LastColonoscopy = age; //remember the time of last colonoscopy


	//simulating complications
	float factor = 1.5f; //to be in line with previous code
	if ((*RG)() < SimParams->ColonoscopyRiscPerforation*factor) {//perforation
		(*perforation) = true;
		if ((*RG)() < SimParams->DeathPerforation) { //death
			this->deathCancerRelated = age;
			this->deathCause = 2;
		}
	} else if ((*RG)() < SimParams->ColonoscopyRiscSerosaBurn*factor) {//serosa burn
		(*serosa) = true;


	} else if ((*RG)() < SimParams->ColonoscopyRiscBleeding*factor){//bleeding
		(*bleeding) = true;


	} else if ((*RG)() < SimParams->ColonoscopyRiscBleedingTransfusion*factor){//bleeding transfusion
		(*bleedingTransfusion) = true;
		if ((*RG)() < SimParams->DeathBleedingTransfusion) { //death
			this->deathCancerRelated = age;
			this->deathCause = 2;
		}
	}


	if (*cancerCounter > 0)
		this->numberDetectedCancers++;

	return (*cancerCounter) > 0;
}

void Person::printNaturalHistory(size_t PID, std::ofstream *outfile) {
	
	bool anythingToShow = !polyps.empty() || !cancers.empty();
	
	//go through each polyp and print its trajectory
	if (anythingToShow) {
		(*outfile) << "Person ID: " << PID << ", death year LT: " << this->deathYearLifeTables;
		for (size_t p=0; p < polyps.size(); ++p) {
			(*outfile)  << std::endl;
			short int cancerID = polyps[p].printNaturalHistory(outfile);
			
			if (cancerID >= 0) {
				cancers[cancerID].printNaturalHistory(outfile);
			} else {
				(*outfile) << std::endl;
			}
		}		
	}

}