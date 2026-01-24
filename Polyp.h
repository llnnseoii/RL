#pragma once

#include "SimulationParameters.h"
#include "Cancer.h"

#include "boost/random.hpp"
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>

class Polyp
{
public:
	float ageDeveloped;
	float ageEnd; //when polyps vanishes, tranforms, etc.
	unsigned char stage;
	unsigned char location;

	short int cancerID;

	float earlyProgressionRisk; //risk of progression to next stage when polyp in early stage
	float advancedProgressionRisk; //risk of progression to next stage when polyp in advanced stage
	float earlyDirectProgressionRisk; //risk of progression directly to cancer when polyp in early stage
	float advancedDirectProgressionRisk; //risk of progression directly to cancer when polyp in advanced stage

	//vector in which we save trajectory
	//vector<float> up, down, trans;
	vector<float> hist_t;
	vector<unsigned char> hist_y;

	//PreCancer(){}; //standard constructor
	Polyp(float, bool, SimulationParameters*, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >*);
	~Polyp() {};

	//unsigned char progress(SimulationParameters*, RandomGenerator*);
	void simulate(SimulationParameters*, boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >*, bool, vector<Cancer> *);
	short int printNaturalHistory(std::ofstream *outfile);

	unsigned char stageAtColonoscopy(float);
};

