#pragma once

#include <cstring>

#include "SimulationParameters.h"
#include "Output.h"
#include "Person.h"

#include "omp.h"

//for random number generation
#include <boost/random.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>

#include <boost/chrono.hpp>
#include <chrono>
#include "Evaluate.h"

#include <map>

#define LICENSE "MIDACO_LIMITED_VERSION___[CREATIVE_COMMONS_BY-NC-ND_LICENSE]"

class Optimizer
{
public:
	Optimizer(std::string, std::string);
	void optimize( SimulationParameters*, std::vector<Person>*,Output*, Evaluate*,int);

	vector<double> compliance;
	int repetitions;

	double seed;

private:

	boost::property_tree::ptree pt;
	std::string outFile;

	
	vector<int> goals;
	int saveFile;

	long int howManyColo;
	double minAge, maxAge, timeSinceLastColo;
	
	vector<double> startingPoint;
	double complianceCurrent;

	long int maxfuneval, maxcalctime;
	double accuracy;
	
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

	 void readINIfile(std::string);
	 void initialize();
	 void problem_function( double*, double*, double*, SimulationParameters*, std::vector<Person>*, vector<double>*, Evaluate*);
	 void saveResults(boost::chrono::duration<float>, int, int);

	 vector<double> checkIfPointEvaluated(double*);
	 void addEvaluatedPoint(double*, double*);

	  /* Variable and Workspace Declarations */
 	  long int o,n,ni,m,me,maxeval,maxtime,printeval,save2file,iflag,istop;
      long int liw,lrw,lpf,i,iw[5000],p=1; 
	  double rw[20000],pf[20000];
      double f[10],g[1000],x[1000],xl[1000],xu[1000],param[13];
      char key[sizeof(LICENSE)];

	  map<std::string, vector<double> > evaluatedPoints;

	  vector<unsigned int> xo, yo, zo, ko;
	  vector<double> f1,f2,f3,f4;

};

