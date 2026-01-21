#include "Stratification.h"

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
                            
void Stratification::problem_function( double *f, double *g, double *x, vector<float> *R, vector<float> *ir, vector<unsigned char> *dc, float maxIR)
{
    double a = x[0];//intersection at 0
    double b = x[1];//intersection at 1

    long unsigned int N = dc->size();
    long unsigned int pos = 0;
    long unsigned int detectedCancPos = 0, detectedCancNeg = 0;

    for (int i = 0; i < ir->size(); ++i) {
        if (R->at(i) <  a + (b-a)*ir->at(i)/maxIR ) {
            pos++;
            detectedCancPos += dc->at(i);
        } else {
            detectedCancNeg += dc->at(i);
        }
    }
    float incidenceLowRisk = (float)(detectedCancNeg)/(float)(N-pos);
    float incidenceHighRisk = (float)(detectedCancPos)/(float)pos;
    float frac = (float)pos/(float)N;

    if (this->foldChange > 1.0f) {
        f[0] = (frac - this->populationFraction)*(frac - this->populationFraction) + 
            (incidenceLowRisk/incidenceHighRisk - 1.0f/this->foldChange)*(incidenceLowRisk/incidenceHighRisk - 1.0f/this->foldChange);
    } else {
        f[0] = (frac - this->populationFraction)*(frac - this->populationFraction) + 
            (incidenceHighRisk/incidenceLowRisk - this->foldChange)*(incidenceHighRisk/incidenceLowRisk - this->foldChange);
    }
    f[1] = frac;
    f[2] = incidenceHighRisk/incidenceLowRisk;
    
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

Stratification::Stratification(std::string iniFile) {
    boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini(iniFile, pt);

    populationFraction=boost::lexical_cast<double>(pt.get<std::string>("goal.populationFraction"));
    //std::cout << "populationFraction" << populationFraction << std::endl;
    foldChange=boost::lexical_cast<double>(pt.get<std::string>("goal.foldChange"));
    //std::cout << "foldChange " << foldChange << std::endl;
    tolerancePopulationFraction=boost::lexical_cast<double>(pt.get<std::string>("goal.tolerancePopulationFraction"));
    //std::cout << "tolerancePopulationFraction " << tolerancePopulationFraction<< std::endl;
    toleranceFoldChange=boost::lexical_cast<double>(pt.get<std::string>("goal.toleranceFoldChange"));  
    //std::cout << "toleranceFoldChange " << toleranceFoldChange << std::endl;

	minVal=boost::lexical_cast<double>(pt.get<std::string>("search_space.minVal"));  
    //std::cout << "minVal " << minVal<< std::endl;
	maxVal=boost::lexical_cast<double>(pt.get<std::string>("search_space.maxVal"));  
    //std::cout << "maxVal " <<maxVal << std::endl;
    startingPoint = to_array<double>(pt.get<std::string>("search_space.startingPoint"));
    //std::cout << "startingPoint " << startingPoint[0] << "," << startingPoint[1] << std::endl;
    
	maxfuneval = boost::lexical_cast<long int>(pt.get<std::string>("optimizer_settings.maxfuneval"));
    //std::cout << "maxfuneval " << maxfuneval<< std::endl;
    maxcalctime = boost::lexical_cast<long int>(pt.get<std::string>("optimizer_settings.maxcalctime"));
    //std::cout << "maxcalctime " << maxcalctime << std::endl;
	accuracy = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.accuracy"));
    //std::cout << "accuracy " <<accuracy << std::endl;
	seed = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.seed"));
    //std::cout << "seed " <<seed << std::endl;
	fstop = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.fstop"));
    //std::cout << "fstop " <<fstop << std::endl;
	algostop = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.algostop"));
    //std::cout << "algostop " <<algostop << std::endl;
	evalstop = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.evalstop"));
    //std::cout << "evalstop " <<evalstop << std::endl;
	focus = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.focus"));
    //std::cout << "focus " <<focus<< std::endl;
	ants = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.ants"));
    //std::cout << "ants " << ants<< std::endl;
	kernel = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.kernel"));
    //std::cout << "kernel " <<kernel << std::endl;
	oracle = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.oracle"));
    //std::cout << "oracle " << oracle<< std::endl;
	paretomax = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.paretomax"));
    //std::cout << "paretomax " <<paretomax << std::endl;
	epsilon = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.epsilon"));
    //std::cout << "epsilon " <<epsilon << std::endl;
	balance = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.balance"));
    //std::cout << "balance " <<balance<< std::endl;
	character = boost::lexical_cast<double>(pt.get<std::string>("optimizer_settings.character"));
    //std::cout << "character " <<character << std::endl;
	printevalini = boost::lexical_cast<long int>(pt.get<std::string>("optimizer_settings.printevalini"));
    //std::cout << "printevalini " << printevalini << std::endl;

}

vector<unsigned char> Stratification::stratify(std::vector<Person>* population, float *fractionFinal, float *foldChangeFinal,bool* success, unsigned char* nStrata,
        boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> >* RG) {

     (*nStrata) = 2;
    
    size_t N = population->size();
    vector<unsigned char> out(N,0);
    vector<float> individualRisk(N,0.0f);
    vector<float> R(N,0.0f);

    float maxIR = 0;
    vector<unsigned char> detectedCancers(N,0);

    for (int i = 0; i < N; ++i) {
        individualRisk[i] = population->at(i).getIndividualRisk();
        detectedCancers[i] = population->at(i).getNumberDetectedCancers();

        R[i] = (*RG)();
        
        if (individualRisk[i]>maxIR)
            maxIR = individualRisk[i]; //get maximal individual risk
    }    
    
    //optimize

      memcpy( key, LICENSE_S, sizeof(LICENSE_S));

      /***  Step 1: Problem definition  ********************************/
      /*****************************************************************/

  /* STEP 1.A: Problem dimensions
      ******************************/
      o  = 1; /* Number of objectives                          */
      n  = 2; /* Number of variables (in total)                */
      ni = 0; /* Number of integer variables (0 <= ni <= n)    */
      
	  m  = 0; /* Number of constraints (in total)              */
      me = 0; /* Number of equality constraints (0 <= me <= m) */
      
      /* STEP 1.B: Lower and upper bounds 'xl' & 'xu'  
      **********************************************/ 
      for( i=0; i<n; i++)
      { 
         xl[i] = this->minVal; 
         xu[i] = this->maxVal; 
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
      save2file = 0;    /* Save SCREEN and SOLUTION to TXT-files [ 0=NO/ 1=YES]  */
    
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

      /*****************************************************************/
      /*   
         Call MIDACO by Reverse Communication
      */
      /*****************************************************************/
      /* Workspace length calculation */
      lrw=sizeof(rw)/sizeof(double); 
      lpf=sizeof(pf)/sizeof(double);   
      liw=sizeof(iw)/sizeof(long int);     

      std::string file_SCREEN = "stratification_SCREEN.txt";
      std::string file_SOLUTION = "stratification_SOLUTION.txt";
      std::string file_HISTORY = "stratification_HISTORY.txt";
      std::string file_PARETOFRONT = "stratification_PARETOFRONT.txt";

     /* Print midaco headline and basic information */
      midaco_print(1,printeval,save2file,&iflag,&istop,&*f,&*g,&*x,&*xl,&*xu,
                 o,n,ni,m,me,&*rw,&*pf,maxeval,maxtime,&*param,p,&*key, 
                 (char *)file_SCREEN.c_str(), (char *)file_SOLUTION.c_str(), (char *)file_HISTORY.c_str(), (char *)file_PARETOFRONT.c_str());
	  

       while(istop==0) /*~~~ Start of the reverse communication loop ~~~*/
      {   
          /* Evaluate objective function */
          problem_function( &*f, &*g, &*x,&R, &individualRisk,&detectedCancers,maxIR);

          /* Call MIDACO */
          midaco(&p,&o,&n,&ni,&m,&me,&*x,&*f,&*g,&*xl,&*xu,&iflag,
                 &istop,&*param,&*rw,&lrw,&*iw,&liw,&*pf,&lpf,&*key);                  
          /* Call MIDACO printing routine */            
          midaco_print(2,printeval,save2file,&iflag,&istop,&*f,&*g,&*x,&*xl,&*xu,
                       o,n,ni,m,me,&*rw,&*pf,maxeval,maxtime,&*param,p,&*key,
                       (char *)file_SCREEN.c_str(), (char *)file_SOLUTION.c_str(), (char *)file_HISTORY.c_str(), (char *)file_PARETOFRONT.c_str());
      } /*~~~End of the reverse communication loop ~~~*/  
      
      
      this->problem_function( &*f, &*g, &*x, &R, &individualRisk,&detectedCancers,maxIR);
      
      if (abs(f[1]-this->populationFraction)<this->tolerancePopulationFraction &&
          abs(f[2]-this->foldChange) < this->toleranceFoldChange) {
          std::cout << "Stratification success!" << std::endl;
          for (int i = 0; i < individualRisk.size(); ++i)
            if (R[i] <  x[0] + (x[1]-x[0])*individualRisk[i]/maxIR )
                out[i] = 1;

          (*fractionFinal) = f[1];
          (*foldChangeFinal) = f[2];
          (*success) = true;
      } else {
          std::cout << "Stratification failure!" << std::endl;
          (*success) = false;
      }


    return out;

    return out;
}