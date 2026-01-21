#include <iostream>

#include "SimulationParameters.h"
#include "Person.h"
#include "Output.h"
#include "Screening.h"
#include "Stratification.h"
#include "Evaluate.h"
#include "Optimizer.h"

//for random number generation
#include <boost/random.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>

//for string operations
#include <boost/algorithm/string/replace.hpp> 

//to parse program options
#include <boost/program_options.hpp>

//in order to measure time of execution
#include <boost/chrono.hpp>
#include <chrono>

#include <omp.h>

using namespace std;

template<typename T>
std::string arrayToString(const vector<T> v)
{
	std::ostringstream result;
	result << v.at(0);
	for(int i = 1; i < v.size(); ++i) result << "," << v[i];
	
	return result.str();
}

/***********************************************************************/
/************************   MAIN PROGRAM   *****************************/
/***********************************************************************/
int main(int argc, char *argv[])
{
    boost::program_options::options_description description("Allowed options");
    
    description.add_options()
        ("populationsize,p", boost::program_options::value<unsigned int>(),"Population size")
        ("settingsfile,s", boost::program_options::value<string>(),"Settings file to be processed")
        ("outputfile,o", boost::program_options::value<string>(),"Output file for baseline simulation")
        ("optinputfile,n", boost::program_options::value<string>(),"Input file for optimization")
        ("optoutputfile,r", boost::program_options::value<string>(),"Output file for optimization")
        ("optcompliance,c", boost::program_options::value<double>(),"Compliance to be considered in optimization")
        //("compression,c", boost::program_options::value<int>(), "Compression level")
        //("score,s", boost::program_options::value<int>()->default_value(60), "Final score")
    ;
    
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, description),vm);
    boost::program_options::notify(vm);

    SimulationParameters SimParams;

    if (vm.count("settingsfile")) {
        cout << "Processing input file: " << vm["settingsfile"].as<string>() << "\n";
        SimulationParameters SimParamsTmp(vm["settingsfile"].as<string>().c_str());
        SimParams = SimParamsTmp;
    } else {//read default ini file
        SimulationParameters SimParamsTmp("settings.ini");
        SimParams = SimParamsTmp;
    }

    if (vm.count("populationsize")) {
        SimParams.PopulationSize = vm["populationsize"].as<unsigned int>();
        cout << "Population size: " << vm["populationsize"].as<unsigned int>() << "\n";
    }

    if (vm.count("optinputfile")) {
        SimParams.optimizationINIfile = vm["optinputfile"].as<string>();
        cout << "Processing optmiziation input file: " << vm["optinputfile"].as<string>() << "\n";
    }
    
    if (vm.count("optoutputfile")) {
        SimParams.optimizationOutFile = vm["optoutputfile"].as<string>();
        cout << "Optimization results will be saved in: " << vm["optoutputfile"].as<string>() << "\n";
    }
        
    if (vm.count("outputfile")) {
        SimParams.resultsFile = vm["outputfile"].as<string>();
        cout << "Besaline results will be saved in: " << vm["outputfile"].as<string>() << "\n";
    }
    

    //initializing simulation parametrs
    SimParams.printParams(1);
    //---

    //initializing global random number generator
    boost::random::mt11213b rngGlobal(SimParams.RandomNumberSeed);
    boost::uniform_real<> uni_distGlobal(0,1);
    boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> > uniGlobal(rngGlobal, uni_distGlobal);
    //----
    

    Evaluate eval(SimParams.EvalIniFile, &SimParams);
    //
    boost::chrono::high_resolution_clock::time_point start = boost::chrono::high_resolution_clock::now();

    std::vector<Person> population(SimParams.PopulationSize,Person());

    SimParams.screening = false;

    omp_set_num_threads(SimParams.nCPUs);
    omp_set_nested(1);
   
    #pragma omp parallel num_threads(SimParams.nCPUs)
    {
        unsigned int th_id = omp_get_thread_num();

        SimulationParameters SimParamsLoc = SimParams;
        
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

        //std::cout << "Thread " << th_id << " will calculate for " << N << " individuals" << std::endl;
        size_t Nend = Nstart+N;
        for (size_t i = Nstart; i < Nend; ++i) {//simulate N individuals
            //initialize individual
            Person individual(&SimParamsLoc, &uni);

            //perform simulation
            individual.simulate();

            //gather output from an individual and save to external variable
            population[i] = individual;
        }
    }

    boost::chrono::high_resolution_clock::time_point end = boost::chrono::high_resolution_clock::now();
    boost::chrono::duration<float> fsec = end - start;
    
    std::cout << "It took " << fsec.count() <<" seconds to simulate the population." << std::endl << std::endl;
    
    //this is only for debugging purposes
    /*
    std::ofstream outfile("testPop.txt");
    if(outfile.is_open()) {
        for (size_t i = 0; i < population.size(); ++i){
            population.at(i).printNaturalHistory(i,&outfile);
        }
        outfile.close();
    }
    */
  
  
    Output outBaseline(&SimParams);
    vector<Output> outTh(SimParams.nCPUs,Output(&SimParams));
    //now the evaluation part with different settings
    start = boost::chrono::high_resolution_clock::now();
    
    #pragma omp parallel num_threads(SimParams.nCPUs)
    {
        unsigned int th_id = omp_get_thread_num();

        SimulationParameters SimParamsLoc = SimParams;
        
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
            population[i].updateParams(&SimParamsLoc, &uni);
            population[i].evaluateStrategy(&outTh[th_id]);
        }
    }

    for (int i = 0; i < SimParams.nCPUs; ++i)
        outBaseline.addResults(&outTh[i]);

    outTh.clear();


    end = boost::chrono::high_resolution_clock::now();
    fsec = end - start;
    std::cout << "It took " << fsec.count() <<" seconds to evaluate the results without screening." << std::endl << std::endl;

    //save the results to output file
    boost::property_tree::ptree ptBaseline;
    ptBaseline.put("general.executionTime", to_string(fsec.count()));
    outBaseline.saveResults(&ptBaseline, true);
    write_ini(SimParams.resultsFile, ptBaseline);
    //--- END of all initial calculations ----////

    float finalPopulationFraction = 0.0f;
    float finalFoldChange = 0.0f;
    bool stratificationSuccess = false;

    vector<Person> empty;
    vector<vector<Person> > populationStratified; //up to 10 strata
    vector<unsigned char> strata;
    unsigned char nStrata;

    if (SimParams.StratifyPopulation) {
        std::cout << "Initializing stratification routine!" << std::endl;
        Stratification stratification(SimParams.StratificationIniFile);
        std::cout << "Performing stratification" << std::endl;
        strata = stratification.stratify(&population, &finalPopulationFraction, &finalFoldChange, &stratificationSuccess,&nStrata,&uniGlobal);
        std::cout << "Out of stratification" << std::endl;
    } else {
        nStrata = 1;
        strata.assign(population.size(),0);
    }

    vector<unsigned int> strataPopSize;
    strataPopSize.assign(nStrata,0);
    for(size_t i = 0; i < strata.size(); ++i)
        strataPopSize[strata[i]]++;

    vector<Output> outsBaseline; //vector that will hold the output characteristics
    //recalculate baseline output for each population
    //THE FOLLOWING NEEDS TO BE DONE IN THIS WAY, BECAUSE WE NEED EXACLTY THE SAME RNG STATE
    if (SimParams.StratifyPopulation) {
        
        
        std::cout << "Reevaluating population." << std::endl;
        start = boost::chrono::high_resolution_clock::now();
        //prepare the output, i.e. outputs with number of strata
        SimulationParameters SimParamsTmp = SimParams;
        for (int oc = 0; oc < nStrata; ++oc) {
            SimParamsTmp.PopulationSize = strataPopSize[oc];
            outsBaseline.push_back(Output(&SimParamsTmp));
        }

        #pragma omp parallel num_threads(SimParams.nCPUs)
        {
            unsigned int th_id = omp_get_thread_num();

            //prepare the output, i.e. outputs with number of strata
            SimulationParameters SimParamsLoc = SimParams;

            vector<Output> outsBaselineLoc; //vector that will hold the output characteristics locally
            for (int oc = 0; oc < nStrata; ++oc) {
                SimParamsLoc.PopulationSize = strataPopSize[oc]; //update the actual population size
                outsBaselineLoc.push_back(Output(&SimParamsLoc));
            }

            SimParamsLoc.PopulationSize = SimParams.PopulationSize;
        
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

            Output outTh(&SimParamsLoc);
        
            size_t Nend = Nstart+N;
            for (size_t i = Nstart; i < Nend; ++i) {
                population[i].updateParams(&SimParamsLoc, &uni);
                population[i].evaluateStrategy(&outsBaselineLoc[strata[i]]);
            }

            #pragma omp critical
            {
                for (int oc = 0; oc < nStrata; ++oc)
                    outsBaseline[oc].addResults(&outsBaselineLoc[oc]);
            }
        }

        end = boost::chrono::high_resolution_clock::now();
        fsec = end - start;
        std::cout << "It took " << fsec.count() <<" seconds to evaluate the results without screening after stratification." << std::endl << std::endl;
    } else {
        outsBaseline.push_back(outBaseline);
    }

    //if (SimParams.StratifyPopulation) {
        //SAVE THE OUTPUT FOR BASELINE RESULTS
         for (int oc = 0; oc < outsBaseline.size(); ++oc) {
            std::string outFile = SimParams.resultsFile;
            boost::algorithm::replace_last(outFile, "/", "/strata" + to_string(oc) + "_");
            
            boost::property_tree::ptree ptBaselineStrata;
            outsBaseline.at(oc).saveResults(&ptBaselineStrata, true);
            eval.addEvaluationResults("eval", &ptBaselineStrata, &outsBaseline[oc], &outsBaseline[oc]);
            write_ini(outFile, ptBaselineStrata);
        }
    //}

    //apply stratification
    while (!population.empty()) {
        while (strata.back() >= populationStratified.size())
            populationStratified.push_back(empty);
        populationStratified[strata.back()].push_back(population.back());
        population.pop_back();
        strata.pop_back();
    }


    for (int i = 0; i < populationStratified.size(); ++i)
        std::cout << "pop " << i << " size: " << populationStratified[i].size() << std::endl;

    for (size_t st = 0; st < populationStratified.size(); ++st) { //perform everything for each strata

        SimParams.PopulationSize = populationStratified[st].size(); //update the actual population size
        std::string outFile = SimParams.optimizationOutFile;
        boost::algorithm::replace_last(outFile, "/", "/strata" + to_string(st) + "_");
        
        //if to perform optimization
        if (SimParams.performOptimization) {
            start = boost::chrono::high_resolution_clock::now();

            Optimizer optim(SimParams.optimizationINIfile, outFile);
            std::vector<Optimizer> optimRep;
            for (int opt = 0; opt < optim.repetitions; opt++) 
                optimRep.push_back(Optimizer(SimParams.optimizationINIfile, outFile));

            for (int opt = 0; opt < optim.repetitions; opt++) {
                if (vm.count("optcompliance")) {
                    optimRep.at(opt).compliance.clear();
                    optimRep.at(opt).compliance.push_back(vm["optcompliance"].as<double>());
                    cout << "Considered compliance: " << vm["optcompliance"].as<double>() << "\n";
                }

                optimRep.at(opt).optimize(&SimParams, &populationStratified[st],&outsBaseline[st],&eval,opt);//out.totalLifeYearsLost());
                end = boost::chrono::high_resolution_clock::now();
                fsec = end - start;
                std::cout << "It took " << fsec.count() <<" seconds to optimize screening." << std::endl << std::endl;
            }
        }

        if (SimParams.evaluateScreeningScenarios) {
        
            //now we will evaluate screening strategy
            SimParams.CalculatePolypsPrevalence = false;
            Screening screen(SimParams.screeningINIfile);
    
            boost::chrono::high_resolution_clock::time_point startTotal = boost::chrono::high_resolution_clock::now();  
            int NCPUsForScenarios = (int)((double)SimParams.nCPUs/(double)SimParams.maxCPUsPerEvaluation);
    
            vector<Output> outputScenarios;
            outputScenarios.assign(screen.compliances.size(),Output(&SimParams));

            #pragma omp parallel num_threads(NCPUsForScenarios)
            {
                //report_num_threads(1);
                unsigned int th_id = omp_get_thread_num();
                std::vector<Person> *populationLoc = &populationStratified[st];
                std::vector<Person> populationCopy;
                if (th_id > 0) {
                    populationCopy = populationStratified[st]; //copy for other processes
                    populationLoc = &populationCopy;
                }
     
        
                //calculate how many scenarios per CPU
                int Nscenarios = screen.compliances.size();
                size_t N = (unsigned int)((double)Nscenarios/(double)NCPUsForScenarios);
                size_t N_nAdd = N;
                if (th_id < Nscenarios % NCPUsForScenarios)
                    N++;

                //calculate at which scenario to start
                size_t add = th_id < Nscenarios % NCPUsForScenarios?th_id:Nscenarios % NCPUsForScenarios;
                size_t Nstart = (th_id*N_nAdd + add);

                size_t Nend = Nstart+N;

        
                for (size_t s = Nstart; s < Nend; ++s) {

                    //Output outS(&SimParams);
                    SimulationParameters SimParamsOuter=SimParams;
                    SimParamsOuter.screening = true;
                    SimParamsOuter.compliance = screen.compliances[s];
                    SimParamsOuter.timeSinceLastColo = screen.timeSinceLastColo[s];
                    SimParamsOuter.screeningMoments = screen.scenarioMoments[s];


                    //omp_set_num_threads(SimParams.maxCPUsPerEvaluation);
                    #pragma omp parallel num_threads(SimParams.maxCPUsPerEvaluation)
                    {
                        //report_num_threads(2);
                        unsigned int th_id_Inner = omp_get_thread_num();

                        SimulationParameters SimParamsLoc = SimParamsOuter;
        
                        //initializing random number generator
                        boost::random::mt11213b rng(SimParamsLoc.RandomNumberSeed+th_id_Inner);
                        boost::uniform_real<> uni_dist(0,1);
                        boost::variate_generator<boost::random::mt11213b&, boost::uniform_real<> > uni(rng, uni_dist);
                        //----
        
                        //calculate how many individuals per CPU
                        size_t N_Inner = (unsigned int)((double)SimParamsLoc.PopulationSize/(double)SimParams.maxCPUsPerEvaluation);
                        size_t N_nAdd_Inner = N_Inner;
                        if (th_id_Inner < SimParamsLoc.PopulationSize % SimParams.maxCPUsPerEvaluation)
                            N_Inner++;

                        //calculate at which individual to start
                        size_t add_Inner = th_id_Inner < SimParamsLoc.PopulationSize % SimParams.maxCPUsPerEvaluation?th_id:SimParamsLoc.PopulationSize % SimParams.maxCPUsPerEvaluation;
                        size_t Nstart_Inner = (th_id_Inner*N_nAdd_Inner + add_Inner);

                        Output outTh(&SimParamsLoc);
        
        
                        size_t Nend_Inner = Nstart_Inner+N_Inner;
                        for (size_t i = Nstart_Inner; i < Nend_Inner; ++i) {
                            populationLoc->at(i).updateParams(&SimParamsLoc, &uni);
                            populationLoc->at(i).evaluateStrategy(&outTh);
                        }
                
                        #pragma omp critical
                        {
                            outputScenarios[s].addResults(&outTh);
                        }
                    }
            
                }
            }


            boost::chrono::high_resolution_clock::time_point endTotal = boost::chrono::high_resolution_clock::now();
            fsec = endTotal - startTotal;
            std::cout << "It took " << fsec.count() <<" seconds to evaluate all scenarios." << std::endl << std::endl;

            //save the results to output file
            boost::property_tree::ptree pt;
            pt.put("general.executionTime", to_string(fsec.count()));
            for (int i = 0; i < outputScenarios.size(); ++i) {
                outputScenarios[i].saveResultsPt(screen.scenarioNames[i],&pt);
                //here add evaluation info
                eval.addEvaluationResults(screen.scenarioNames[i], &pt, &outsBaseline[st], &outputScenarios[i]);
            }
            std::string outFile = SimParams.screeningOutFile;
            boost::algorithm::replace_last(outFile, "/", "/strata" + to_string(st) + "_");
            write_ini(outFile, pt );
        }
    }
    return 0;
}
