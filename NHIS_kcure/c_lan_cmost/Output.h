#pragma once

#include <vector>
#include "SimulationParameters.h"
#include "Polyp.h"
#include "Cancer.h"

using namespace std;


class Output
{
public:
	void saveSummary(vector<Cancer>*, bool, unsigned char, float, float, float);
	void addColonoscopy(float, bool, unsigned short int, unsigned short int, unsigned short int,
					bool,bool,bool,bool,unsigned char);
	void recordDeath(float,float,unsigned char, bool);
	void recordPolypsPrevalence(vector<Polyp>*, float, bool);

	long int totalNumberOfCancers();
	long int totalNumberOfCancersMales();
	long int totalNumberOfCancersFemales();
	double totalLifeYearsLost();
	double totalDiscLifeYearsLost(double, double);

	vector<double> totalDiscLifeYearsLostVec(double, double);

	double totalDiscCosts(double discVal, double discAfter, double Colonoscopy,double Colonoscopy_Polyp,double  Colonoscopy_Cancer,
		double Colonoscopy_Perforation,double Colonoscopy_Serosal_burn,double Colonoscopy_bleed,double Colonoscopy_bleed_transfusion, 
		double Initial_I,double Initial_II,double Initial_III,double Initial_IV,
		double Cont_I,double Cont_II,double Cont_III,double Cont_IV,
		double Final_I,double Final_II,double Final_III,double Final_IV,
		double Final_oc_I,double Final_oc_II,double Final_oc_III,double Final_oc_IV);

	vector<double> totalDiscCostsVec(double discVal, double discAfter, double Colonoscopy,double Colonoscopy_Polyp,double  Colonoscopy_Cancer,
		double Colonoscopy_Perforation,double Colonoscopy_Serosal_burn,double Colonoscopy_bleed,double Colonoscopy_bleed_transfusion, 
		double Initial_I,double Initial_II,double Initial_III,double Initial_IV,
		double Cont_I,double Cont_II,double Cont_III,double Cont_IV,
		double Final_I,double Final_II,double Final_III,double Final_IV,
		double Final_oc_I,double Final_oc_II,double Final_oc_III,double Final_oc_IV);

	double totalScreeningCosts(double Colonoscopy,double Colonoscopy_Polyp,double  Colonoscopy_Cancer,
		double Colonoscopy_Perforation,double Colonoscopy_Serosal_burn,double Colonoscopy_bleed,double Colonoscopy_bleed_transfusion);
	double totalFollowupCosts(double Colonoscopy,double Colonoscopy_Polyp,double  Colonoscopy_Cancer,
		double Colonoscopy_Perforation,double Colonoscopy_Serosal_burn,double Colonoscopy_bleed,double Colonoscopy_bleed_transfusion);
	double totalTreatCosts(double Colonoscopy,double Colonoscopy_Polyp,double  Colonoscopy_Cancer,
		double Colonoscopy_Perforation,double Colonoscopy_Serosal_burn,double Colonoscopy_bleed,double Colonoscopy_bleed_transfusion, 
		double Initial_I,double Initial_II,double Initial_III,double Initial_IV,
		double Cont_I,double Cont_II,double Cont_III,double Cont_IV,
		double Final_I,double Final_II,double Final_III,double Final_IV,
		double Final_oc_I,double Final_oc_II,double Final_oc_III,double Final_oc_IV);


	double initialPopulationSize() {return (double)this->initPopSize;};

	void addResults(Output *outToAdd);
	
	unsigned long deathCancer;
	unsigned long numberScreeningColonoscopies;

	void printResults();
	void saveResults(boost::property_tree::ptree*, bool);
	void saveResultsPt(string, boost::property_tree::ptree*);

	Output(SimulationParameters*);

private:

	unsigned long initPopSize;
	vector<unsigned long> numberDetectedCancers;


	vector<unsigned long> populationFemales, populationMales;
	vector<unsigned long> cancerFemales, cancerMales;

	vector<unsigned long> numberAnyPolypFemales, numberAnyPolypMales;
	vector<unsigned long> numberAdvancedPolypFemales, numberAdvancedPolypMales;

	vector<unsigned long> polypsSummMale, polypsSummFemale;

	vector<unsigned long> numberColonoscopiesFemale, numberColonoscopiesMale;
	
	//screening
	vector<unsigned long> coloNoTumorAndNoPolypsScreen, coloTumorNoPolypsScreen, coloNoTumorAndPolypsScreen; 
	vector<unsigned long> numPerforationsScreen, numSerosaScreen, numBleedingScreen, numBleedingTransfScreen;

	//treatment
	vector<unsigned long> coloNoTumorAndNoPolypsTreat, coloTumorNoPolypsTreat, coloNoTumorAndPolypsTreat; 
	vector<unsigned long> numPerforationsTreat, numSerosaTreat, numBleedingTreat, numBleedingTransfTreat;

	vector<float> stageICostContinous, stageICostInitial, stageICostFinal, stageICostFinalOC;
	vector<float> stageIICostContinous, stageIICostInitial, stageIICostFinal, stageIICostFinalOC;
	vector<float> stageIIICostContinous, stageIIICostInitial, stageIIICostFinal, stageIIICostFinalOC;
	vector<float> stageIVCostContinous, stageIVCostInitial, stageIVCostFinal, stageIVCostFinalOC;

	//follow-up
	vector<unsigned long> coloNoTumorAndNoPolypsFollowup, coloTumorNoPolypsFollowup, coloNoTumorAndPolypsFollowup; 
	vector<unsigned long> numPerforationsFollowup, numSerosaFollowup, numBleedingFollowup, numBleedingTransfFollowup;

	vector<float> lifeYearsLostCa, lifeYearsLostColo;

};

