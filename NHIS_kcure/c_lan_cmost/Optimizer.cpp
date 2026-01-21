#include "Optimizer.h"

extern"C"{ int midaco(long int*,long int*,long int*,long int*,long int*,
                      long int*,double*,double*,double*,double*,double*,
                      long int*,long int*,double*,double*,long int*,
                      long int*,long int*,double*,long int*,char*);}

/***********************************************************************/
extern"C"{ int midaco_print(int,long int,long int,long int*,long int*,double*,
                            double*,double*,double*,double*,long int,long int,
                            long int,long int,long int,double*,double*,
                            long int,long int,double*,long int,char*,
                            char*,char*,char*,char*);}

vector<double> Optimizer::checkIfPointEvaluated(double *x) {
    vector<double> result;

    std::string key = to_string((int)x[0]);
    if (this->n > 1)
		key += "_" + to_string((int)x[1]);
	if (this->n > 2)
		key += "_" + to_string((int)x[2]);
    if (this->n > 3)
        key += "_" + to_string((int)x[3]);

    std::map<std::string,vector<double> >::iterator it;
    it = this->evaluatedPoints.find(key);
        if (it != this->evaluatedPoints.end())
            return it->second;

    return result;
};

void Optimizer::addEvaluatedPoint(double *x, double *f) {
    std::string key = to_string((int)x[0]);
    if (this->n > 1)
		key += "_" + to_string((int)x[1]);
	if (this->n > 2)
		key += "_" + to_string((int)x[2]);
    if (this->n > 3)
        key += "_" + to_string((int)x[3]);

    vector<double> to_save(4,0.0);
    to_save[0] = f[0];
    to_save[1] = f[1];
    to_save[2] = f[2];
    to_save[3] = f[3];
    this->evaluatedPoints[key] = to_save;
};

void Optimizer::problem_function( double *f, double *g, double *x, SimulationParameters *SP, std::vector<Person> *population, vector<double> *Fnoscreening, Evaluate *eval)
{

	/* Equality constraints G(X) = 0 MUST COME FIRST in g[0:me-1] */
    //g[0] = x[0] - 1.0; 
    /* Inequality constraints G(X) >= 0 MUST COME SECOND in g[me:m-1] */
    //g[1] = x[1] - 1.333333333;
    //g[2] = x[2] - 2.666666666;
    
    bool violation = false;
    for (int i = 0; i < this->m; ++i) {
	    g[i] = x[i+1]-x[i]-this->timeSinceLastColo;
        if (g[i] < 0)
            violation = true;
    }
	
	if (violation) {
        for (int gl = 0; gl < this->goals.size(); ++gl)
		    f[gl] = 10.0;//Fnoscreening;
    } else {
        vector<double> check = this->checkIfPointEvaluated(x);
        if (!check.empty()) {
            std::cout << "Point already evaluated with: (" << check[0] << ", " << check[1] <<", " << check[2] <<", " << check[3] << ")" << std::endl;
            f[0] = check[0];
            f[1] = check[1];
            f[2] = check[2];
            f[3] = check[3];
        } else {

			SimulationParameters SimParamsOuter=(*SP);
            SimParamsOuter.screening = true;
            SimParamsOuter.compliance = this->complianceCurrent;
            SimParamsOuter.timeSinceLastColo = this->timeSinceLastColo;

			std::queue<float> moments;
            for (int i = 0; i < this->n; ++i)
			    moments.push(x[i]);
			
            SimParamsOuter.screeningMoments = moments;//here will be created queue

			Output out(&SimParamsOuter);
            vector<Output> outTh(SimParamsOuter.nCPUs,Output(&SimParamsOuter));
            //omp_set_num_threads(SimParams.maxCPUsPerEvaluation);
            #pragma omp parallel num_threads(SimParamsOuter.nCPUs)
            {
                unsigned int th_id = omp_get_thread_num();

        		SimulationParameters SimParamsLoc = SimParamsOuter;
        
        		//initializing random number generator
        		boost::random::mt11213b rng(SimParamsLoc.RandomNumberSeed+th_id);
        		boost::uniform_real<> uni_dist(0,1);
        		boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> > uni(rng, uni_dist);
        		//----
        
        		//calculate how many individuals per CPU
        		size_t N = (unsigned int)((double)SimParamsLoc.PopulationSize/(double)SimParamsLoc.nCPUs);
        		size_t N_nAdd = N;
        		if (th_id < SimParamsLoc.PopulationSize % SimParamsLoc.nCPUs)
            		N++;

        		//calculate at which individual to start
        		size_t add = th_id < SimParamsLoc.PopulationSize % SimParamsLoc.nCPUs?th_id:SimParamsLoc.PopulationSize % SimParamsLoc.nCPUs;
        		size_t Nstart = (th_id*N_nAdd + add);

       		 	        
        		size_t Nend = Nstart+N;
        		for (size_t i = Nstart; i < Nend; ++i) {
            		population->at(i).updateParams(&SimParamsLoc, &uni);
            		population->at(i).evaluateStrategy(&outTh[th_id]);
        		}
            }
            
        for (int i = 0; i < SimParamsOuter.nCPUs; ++i)
            out.addResults(&outTh[i]);
        outTh.clear();

        /* Objective functions F(X) */
        for (int gl = 0; gl < this->goals.size(); ++gl) {
        switch(this->goals[gl]) {
            case 1://mortality
                f[gl] = (double)out.deathCancer/Fnoscreening->at(gl);
                break;
            case 2://incidence
                f[gl] = (double)out.totalNumberOfCancers()/Fnoscreening->at(gl);
                break;
            case 3://LYG
                f[gl] = out.totalDiscLifeYearsLost(eval->DiscountingCoeff, eval->DiscountingAfterYear)/Fnoscreening->at(gl);
                break;
            case 4:
                f[gl] = eval->totalTreatCostsSingle(&out)/Fnoscreening->at(gl);
                break;
            default:
                std::cout << "Error: unknown goal!" << std::endl;
        }
      }
        //add evaluated points to map
         this->addEvaluatedPoint(x,f);
    }

        
	}

}

template<typename T>
std::vector<T> to_array(const std::string s)
{
	std::vector<T> result;
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, ',')) result.push_back(boost::lexical_cast<T>(item));
	return result;
}

void Optimizer::readINIfile(std::string iniFile) {
    boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini(iniFile, pt);
	
    
    repetitions = boost::lexical_cast<int>(pt.get<std::string>("general.repetitions"));
    goals = to_array<int>(pt.get<std::string>("general.goals"));
    saveFile = boost::lexical_cast<int>(pt.get<std::string>("general.save2file"));

	howManyColo = boost::lexical_cast<long int>(pt.get<std::string>("search_space.howManyColo"));
	minAge = boost::lexical_cast<double>(pt.get<std::string>("search_space.minAge"));
    maxAge = boost::lexical_cast<double>(pt.get<std::string>("search_space.maxAge"));
    timeSinceLastColo = boost::lexical_cast<double>(pt.get<std::string>("search_space.timeSinceLastColo"));
	startingPoint = to_array<double>(pt.get<std::string>("search_space.startingPoint"));
    compliance = to_array<double>(pt.get<std::string>("search_space.compliance"));

	maxfuneval = boost::lexical_cast<long int>(pt.get<std::string>("optimizer_settings.maxfuneval"));
    maxcalctime = boost::lexical_cast<long int>(pt.get<std::string>("optimizer_settings.maxcalctime"));
	accuracy = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.accuracy"));
	seed = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.seed"));
	fstop = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.fstop"));
	algostop = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.algostop"));
	evalstop = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.evalstop"));
	focus = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.focus"));
	ants = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.ants"));
	kernel = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.kernel"));
	oracle = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.oracle"));
	paretomax = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.paretomax"));
	epsilon = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.epsilon"));
	balance = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.balance"));
	character = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.character"));
	printevalini = boost::lexical_cast<long int>(pt.get<std::string>("optimizer_settings.printevalini"));

}

void Optimizer::initialize() {
/*****************************************************************/

    xo.clear();
    yo.clear();
    zo.clear();
    ko.clear();
    f1.clear();
    f2.clear();
    f3.clear();
    f4.clear();

    evaluatedPoints.clear();

      /***  Step 1: Problem definition  ********************************/
      /*****************************************************************/

      /* STEP 1.A: Problem dimensions
      ******************************/
      o  = this->goals.size(); /* Number of objectives                          */
      n  = this->howManyColo; /* Number of variables (in total)                */
      ni = this->howManyColo; /* Number of integer variables (0 <= ni <= n)    */
      
	  m  = this->howManyColo-1; /* Number of constraints (in total)              */
      me = 0; /* Number of equality constraints (0 <= me <= m) */
      
      /* STEP 1.B: Lower and upper bounds 'xl' & 'xu'  
      **********************************************/ 
      for( i=0; i<n; i++)
      { 
         xl[i] = this->minAge+(double)i*this->timeSinceLastColo; 
         xu[i] = this->maxAge-(double)(n-1-i)*this->timeSinceLastColo; 
      }
    
      /* STEP 1.C: Starting point 'x'  
      ******************************/
      for (int i = 0; i < n; ++i)   
        x[i]=this->startingPoint[i];
      
      /*****************************************************************/
      /***  Step 2: Choose stopping criteria and printing options   ****/
      /*****************************************************************/

      /* STEP 2.A: Stopping criteria 
      *****************************/
      maxeval = this->maxfuneval;    /* Maximum number of function evaluation (e.g. 1000000)  */
      maxtime = this->maxcalctime; /* Maximum time limit in Seconds (e.g. 1 Day = 60*60*24) */

      /* STEP 2.B: Printing options  
      ****************************/
      printeval = this->printevalini; /* Print-Frequency for current best solution (e.g. 1000) */
      save2file = this->saveFile;    /* Save SCREEN and SOLUTION to TXT-files [ 0=NO/ 1=YES]  */
    
      /*****************************************************************/
      /***  Step 3: Choose MIDACO parameters (FOR ADVANCED USERS)    ***/
      /*****************************************************************/

      param[ 0] =  this->accuracy;  /* ACCURACY  */
      param[ 1] =  this->seed;  /* SEED      */
      param[ 2] =  this->fstop;  /* FSTOP     */
      param[ 3] =  this->algostop;  /* ALGOSTOP  */
      param[ 4] =  this->evalstop;  /* EVALSTOP  */
      param[ 5] =  this->focus;  /* FOCUS     */
      param[ 6] =  this->ants;  /* ANTS   */
      param[ 7] =  this->kernel;  /* KERNEL  */
      param[ 8] =  this->oracle;  /* ORACLE  */
      param[ 9] =  this->paretomax;  /* PARETOMAX */
      param[10] =  this->epsilon;  /* EPSILON  */
      param[11] =  this->balance;  /* BALANCE  */
      param[12] =  this->character;  /* CHARACTER */ 

}

Optimizer::Optimizer(std::string iniFile, std::string outFileI) {

    this->readINIfile(iniFile);
    this->outFile = outFileI;

	memcpy( key, LICENSE, sizeof(LICENSE));

	this->initialize();
    std::cout << "Optimizer initilized!" << std::endl;

}

void Optimizer::optimize( SimulationParameters *SP, std::vector<Person> *population, Output *outBaseline, Evaluate *eval, int iter) {

for (int j = 0; j < this->compliance.size(); ++j) {
    this->complianceCurrent = this->compliance[j];
    //for (int iter  = 0; iter < this->repetitions; ++iter) {
        boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();
        this->seed += 5*iter;
        this->initialize();

       std::string file_SCREEN = this->outFile + "_run_" + to_string(iter) + "_compliance_" + to_string(j) + "_SCREEN.txt";
       std::string file_SOLUTION = this->outFile + "_run_" + to_string(iter) + "_compliance_" + to_string(j) + "_SOLUTION.txt";
       std::string file_HISTORY = this->outFile + "_run_" + to_string(iter) + "_compliance_" + to_string(j) + "_HISTORY.txt";
       std::string file_PARETOFRONT = this->outFile + "_run_" + to_string(iter) + "_compliance_" + to_string(j) + "_PARETOFRONT.txt";

        
	  /*****************************************************************/
      /*   
         Call MIDACO by Reverse Communication
      */
      /*****************************************************************/
      /* Workspace length calculation */
      lrw=sizeof(rw)/sizeof(double); 
      lpf=sizeof(pf)/sizeof(double);   
      liw=sizeof(iw)/sizeof(long int);     
      /* Print midaco headline and basic information */
      midaco_print(1,printeval,save2file,&iflag,&istop,&*f,&*g,&*x,&*xl,&*xu,
                 o,n,ni,m,me,&*rw,&*pf,maxeval,maxtime,&*param,p,&*key, 
                 (char *)file_SCREEN.c_str(), (char *)file_SOLUTION.c_str(), (char *)file_HISTORY.c_str(), (char *)file_PARETOFRONT.c_str());

      //std::cout << "Finished 1" << std::endl;
      vector<double> Fnoscreening;
      for (int gl = 0; gl < this->goals.size(); ++gl) {
        switch(this->goals[gl]) {
            case 1://mortality
                Fnoscreening.push_back((double)outBaseline->deathCancer);
                break;
            case 2://incidence
                Fnoscreening.push_back((double)outBaseline->totalNumberOfCancers());
                break;
            case 3://LYG
                Fnoscreening.push_back(outBaseline->totalDiscLifeYearsLost(eval->DiscountingCoeff, eval->DiscountingAfterYear));
                break;
            case 4: //costs
                Fnoscreening.push_back(eval->totalTreatCostsSingle(outBaseline));
                break;
            default:
                std::cout << "Error: unknown goal!" << std::endl;
        }
      }

      /*
      problem_function( &*f, &*g, &*x, SP, population, &Fnoscreening, eval);
      std::cout << f[0] << ", " << f[1] << ", " << f[2] << ", " << f[3] << std::endl;
      x[0] = 50;
      problem_function( &*f, &*g, &*x, SP, population, &Fnoscreening, eval);
      x[0] = 44;
      std::cout << f[0] << ", " << f[1] << ", " << f[2] << ", " << f[3] << std::endl;
      problem_function( &*f, &*g, &*x, SP, population, &Fnoscreening, eval);
      std::cout << f[0] << ", " << f[1] << ", " << f[2] << ", " << f[3] << std::endl;
      problem_function( &*f, &*g, &*x, SP, population, &Fnoscreening, eval);
      std::cout << f[0] << ", " << f[1] << ", " << f[2] << ", " << f[3] << std::endl;
      problem_function( &*f, &*g, &*x, SP, population, &Fnoscreening, eval);
      std::cout << f[0] << ", " << f[1] << ", " << f[2] << ", " << f[3] << std::endl;
      */
      
      // = outBaseline->deathCancer;
	//std::cout << "Finished 2" << std::endl;
      while(istop==0) //~~~ Start of the reverse communication loop ~~~//
      {   
          // Evaluate objective function //
          problem_function( &*f, &*g, &*x, SP, population, &Fnoscreening, eval);
		  //std::cout << "Finished 3" << std::endl;
		  xo.push_back(x[0]);
          if (this->n > 1)
		    yo.push_back(x[1]);
		  if (this->n > 2)
		    zo.push_back(x[2]);
          if (this->n > 3)
            ko.push_back(x[3]);
        //std::cout << "Finished 4" << std::endl;
		  //fo.push_back(f[0]);
           for (int gl = 0; gl < this->goals.size(); ++gl) {
                switch(this->goals[gl]) {
                    case 1://mortality
                        f1.push_back(f[0]);
                        break;
                    case 2://incidence
                        f2.push_back(f[1]);
                        break;
                    case 3://LYG
                        f3.push_back(f[2]);
                        break;
                    case 4:
                        f4.push_back(f[3]);
                    break;
                    default:
                    std::cout << "Error: unknown goal!" << std::endl;
                }
            }
           //std::cout << "Finished 5" << std::endl;                
          // Call MIDACO
          midaco(&p,&o,&n,&ni,&m,&me,&*x,&*f,&*g,&*xl,&*xu,&iflag,
                 &istop,&*param,&*rw,&lrw,&*iw,&liw,&*pf,&lpf,&*key);                  
          // Call MIDACO printing routine         
          midaco_print(2,printeval,save2file,&iflag,&istop,&*f,&*g,&*x,&*xl,&*xu,
                       o,n,ni,m,me,&*rw,&*pf,maxeval,maxtime,&*param,p,&*key, 
                       (char *)file_SCREEN.c_str(), (char *)file_SOLUTION.c_str(), (char *)file_HISTORY.c_str(), (char *)file_PARETOFRONT.c_str());   
      } //~~~End of the reverse communication loop ~~~
      boost::chrono::high_resolution_clock::time_point end = boost::chrono::high_resolution_clock::now();
      boost::chrono::duration<float> fsec = end - start; 
      this->saveResults(fsec,iter,j);

       //save results
       write_ini( this->outFile, pt );
       
    //}
}

}

template<typename T>
std::string arrayToString(const vector<T> v)
{
	std::ostringstream result;
	result << v.at(0);
	for(int i = 1; i < v.size(); ++i) result << "," << v[i];
	
	return result.str();
}


void Optimizer::saveResults(boost::chrono::duration<float> execTime, int i, int j) {
	
    std::string runNumber = "run_" + to_string(i) + "_compliance_" + to_string(j);
   
	pt.put(runNumber+".istop",to_string(istop));
	pt.put(runNumber+".execTime",to_string(execTime));
	

   	pt.put(runNumber+".xo", arrayToString<unsigned int>(this->xo));
    if (this->n > 1)
	    pt.put(runNumber+".yo", arrayToString<unsigned int>(this->yo));
	if (this->n > 2)
        pt.put(runNumber+".zo", arrayToString<unsigned int>(this->zo));
    if (this->n > 3)
        pt.put(runNumber+".ko", arrayToString<unsigned int>(this->ko));

    if (!this->f1.empty())
	    pt.put(runNumber+".f1", arrayToString<double>(this->f1));
    if (!this->f2.empty())    
        pt.put(runNumber+".f2", arrayToString<double>(this->f2));
    if (!this->f3.empty())
        pt.put(runNumber+".f3", arrayToString<double>(this->f3));
    if (!this->f4.empty())
        pt.put(runNumber+".f4", arrayToString<double>(this->f4));
   	
}


