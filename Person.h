#pragma once
#include <vector>

#include "SimulationParameters.h"
#include "Output.h"

#include "boost/random.hpp"
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>

#include "Polyp.h"
#include "Cancer.h"

class Person
{
public:
	Person(SimulationParameters*, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >*);
	Person();

	void updateParams(SimulationParameters*, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >*);
	void simulate();
	void evaluateStrategy(Output*);
	void printNaturalHistory(size_t, std::ofstream *);

	
	bool gender; //0 - male, 1 - female
	float getIndividualRisk(){return this->individualRiskOfPolypCreation;};
	unsigned char getNumberDetectedCancers();

private:
	
	boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >* RG;
	SimulationParameters* SimParams;

	float individualRiskOfPolypCreation; //depends on the gender, taken care at initialiation

	float LastEarlyPolyp, LastAdvPolyp, LastColonoscopy, LastCancer;

	std::vector<Polyp> polyps; //vector containing all polyps
	std::vector<Cancer> cancers; //vector containing all cancers

	float deathYearLifeTables;
	float deathCancerRelated;
	unsigned char deathCause; //0 - nothing happened, 1 - cancer, 2 - during colonoscopy

	unsigned char numberDetectedCancers;


	bool colonoscopy(float, vector<Cancer>*, vector<Polyp>*, unsigned short int*,unsigned short int*,unsigned short int*,
					bool*,bool*,bool*,bool*);
	float findColonoscopyMoment(vector<Cancer>*, float, queue<float>*, unsigned char*);

/*
	float age;

	//unsigned char age; //age is unecessary because it is defined by the main simulation loop
	
	unsigned char deathYear = 0;
	
	float cancerTreatmentUntil = 0.0f;

	unsigned char cancerStageDeath = 0;
	unsigned char causeOfDeath = 0; //dictionary 1 - natural causes, 2 - cancer

	//polyp related parameters
	
	
	std::vector<PreCancer> polyps; //vector containing all preCancer stages (polyps in case of colon)
	std::vector<Cancer> cancers; //vector containing all cancers
	
	//Person() {}; //default constructor

	Person(SimulationParameters*, RandomGenerator*);//constructor taking into account simulation parameters

	~Person() {}; //defualt destructor
	
	bool processDeath(float, SimulationParameters*, RandomGenerator*);

	void generateNewPolyps(float, SimulationParameters*, RandomGenerator*);
	void generateNewCancers(unsigned char, SimulationParameters*, RandomGenerator*);

	void progressPolyps(float, SimulationParameters*, RandomGenerator*);

	bool symptomsDevelopment(float, SimulationParameters*, RandomGenerator*);
	
	//bool cancerDiagnosed(unsigned char, SimulationParameters*, RandomGenerator*);
	
	void progressCancer(float);
	bool toSurveil();
	*/

};

