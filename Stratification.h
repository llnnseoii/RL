#pragma once

#include <vector>
#include "Person.h"

#define LICENSE_S "MIDACO_LIMITED_VERSION___[CREATIVE_COMMONS_BY-NC-ND_LICENSE]"

class Stratification
{
public:
	Stratification(){};
	Stratification(std::string);

	vector<unsigned char> stratify(std::vector<Person>*, float*, float*, bool*, unsigned char*,boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >*);

private:

	void problem_function( double*, double*, double*, vector<float>*, vector<float>*, vector<unsigned char>*, float);

	float populationFraction;
	float foldChange;
	float tolerancePopulationFraction;
	float toleranceFoldChange;

	float minVal;
	float maxVal;
	vector<double> startingPoint;

	long int maxfuneval, maxcalctime;
	double accuracy;
	double seed;
	double fstop;
	double algostop;
	double evalstop;
	double focus;
	double ants;
	double kernel;
	double oracle;
	double paretomax;
	double epsilon;
	double balance;
	double character;
	long int printevalini;

 	long int o,n,ni,m,me,maxeval,maxtime,printeval,save2file,iflag,istop;
    long int liw,lrw,lpf,i,iw[5000],p=1; 
	double rw[20000],pf[20000];
    double f[10],g[1000],x[1000],xl[1000],xu[1000],param[13];
    char key[sizeof(LICENSE_S)];

};

