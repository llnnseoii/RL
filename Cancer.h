#pragma once
#include "SimulationParameters.h"
//#include "RandomGenerator.h"

#include "boost/random.hpp"
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>


class Cancer
{
public:

	float ageDeveloped;
	unsigned char location;
	float dwellTime;

	unsigned char symptomsStage; //cancer stage when symptoms
	float symptomsAge;  //age at which symptoms develop
	
	float ageProgression[3];

	bool canDevelop,detected;

	unsigned char stageAtDetection;
	float ageDetected;

	//Cancer() {}; //default constructor
	Cancer(float, bool, SimulationParameters*, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >*); //constructor for direct cancers
	Cancer(float, bool, float, unsigned char, SimulationParameters*, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >*); //constructor for cancer from a polyp
	
	~Cancer(){};

	void printNaturalHistory(std::ofstream *outfile);
	unsigned char stageAtColonoscopy(float);
	float generateMortalityTime(bool, float, unsigned char, SimulationParameters*, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >*);


private:

	void initialize(float, bool, SimulationParameters*, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >*);
};

