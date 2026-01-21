#pragma once

#include "SimulationParameters.h"
#include "Output.h"

#include <vector>

using namespace std;


class Evaluate
{
public:
	
	Evaluate(std::string, SimulationParameters*);
	Evaluate(){};

	void addEvaluationResults(string, boost::property_tree::ptree*, Output*, Output*);

	double totalTreatCostsSingle(Output *out);

	double DiscountingCoeff;
	double DiscountingAfterYear;

private:



	double Colonoscopy;
	double Colonoscopy_Polyp;
	double Colonoscopy_Cancer;
	double Colonoscopy_Perforation;
	double Colonoscopy_Serosal_burn;
	double Colonoscopy_bleed;
	double Colonoscopy_bleed_transfusion;
	double Initial_I;
	double Initial_II;
	double Initial_III;
	double Initial_IV;
	double Cont_I;
	double Cont_II;
	double Cont_III;
	double Cont_IV;
	double Final_I;
	double Final_II;
	double Final_III;
	double Final_IV;
	double Final_oc_I;
	double Final_oc_II;
	double Final_oc_III;
	double Final_oc_IV;

	
	
	//incidence reduction
	float IncidenceReduction(Output*, Output*);
	
	//mortality reduction
	float MortalityReduction(Output*, Output*);
	
	//dsicounted life years gained per 1000
	float DiscountedLYgained(Output*, Output*);
	
	//US dollar per LYG
	float USdollatPerLYG(Output*, Output*);

	double totalTreatCosts(Output*, Output*);
	double totalScreenCosts(Output*, Output*);
	double totalFollowupCosts(Output*, Output*);
	

};

