#include "Evaluate.h"

Evaluate::Evaluate(std::string iniFile, SimulationParameters *sp) {

	
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini(iniFile, pt);

	DiscountingCoeff = boost::lexical_cast<double>(pt.get<std::string>("costs.DiscountingCoeff"));
	DiscountingAfterYear = boost::lexical_cast<double>(pt.get<std::string>("costs.DiscountingAfterYear"));

	
	Colonoscopy = boost::lexical_cast<double>(pt.get<std::string>("costs.Colonoscopy"));
	Colonoscopy_Polyp = boost::lexical_cast<double>(pt.get<std::string>("costs.Colonoscopy_Polyp"));
	Colonoscopy_Cancer = boost::lexical_cast<double>(pt.get<std::string>("costs.Colonoscopy_Cancer"));
	Colonoscopy_Perforation = boost::lexical_cast<double>(pt.get<std::string>("costs.Colonoscopy_Perforation"));
	Colonoscopy_Serosal_burn = boost::lexical_cast<double>(pt.get<std::string>("costs.Colonoscopy_Serosal_burn"));
	Colonoscopy_bleed = boost::lexical_cast<double>(pt.get<std::string>("costs.Colonoscopy_bleed"));
	Colonoscopy_bleed_transfusion = boost::lexical_cast<double>(pt.get<std::string>("costs.Colonoscopy_bleed_transfusion"));
	
	Initial_I = boost::lexical_cast<double>(pt.get<std::string>("costs.Initial_I"));
	Initial_II = boost::lexical_cast<double>(pt.get<std::string>("costs.Initial_II"));
	Initial_III = boost::lexical_cast<double>(pt.get<std::string>("costs.Initial_III"));
	Initial_IV = boost::lexical_cast<double>(pt.get<std::string>("costs.Initial_IV"));
	Cont_I = boost::lexical_cast<double>(pt.get<std::string>("costs.Cont_I"));
	Cont_II = boost::lexical_cast<double>(pt.get<std::string>("costs.Cont_II"));
	Cont_III = boost::lexical_cast<double>(pt.get<std::string>("costs.Cont_III"));
	Cont_IV = boost::lexical_cast<double>(pt.get<std::string>("costs.Cont_IV"));
	Final_I = boost::lexical_cast<double>(pt.get<std::string>("costs.Final_I"));
	Final_II = boost::lexical_cast<double>(pt.get<std::string>("costs.Final_II"));
	Final_III = boost::lexical_cast<double>(pt.get<std::string>("costs.Final_III"));
	Final_IV = boost::lexical_cast<double>(pt.get<std::string>("costs.Final_IV"));
	Final_oc_I = boost::lexical_cast<double>(pt.get<std::string>("costs.Final_oc_I"));
	Final_oc_II = boost::lexical_cast<double>(pt.get<std::string>("costs.Final_oc_II"));
	Final_oc_III = boost::lexical_cast<double>(pt.get<std::string>("costs.Final_oc_III"));
	Final_oc_IV = boost::lexical_cast<double>(pt.get<std::string>("costs.Final_oc_IV"));
		
}

//incidence reduction
float Evaluate::IncidenceReduction(Output *outBaseline, Output *outStrategy) {
	double c1 = (double)outBaseline->totalNumberOfCancers();
	double c2 = (double)outStrategy->totalNumberOfCancers();
	return (float)((c1-c2)/c1)*100.0f;
}
	
//mortality reduction
float Evaluate::MortalityReduction(Output *outBaseline, Output *outStrategy){
	double c1 = outBaseline->deathCancer;
	double c2 = outStrategy->deathCancer;
	return (float)((c1-c2)/c1)*100.0f;
}
	
//dsicounted life years gained per 1000
float Evaluate::DiscountedLYgained(Output *outBaseline, Output *outStrategy){
	double c1 = outBaseline->totalDiscLifeYearsLost(this->DiscountingCoeff, this->DiscountingAfterYear);
	double c2 = outStrategy->totalDiscLifeYearsLost(this->DiscountingCoeff, this->DiscountingAfterYear);
	double c3 = outBaseline->initialPopulationSize();
	return (float)((c1-c2)/c3)*1000.0f;
}
	
//US dollar per LYG
float Evaluate::USdollatPerLYG(Output *outBaseline, Output *outStrategy){

	
	double c1 = outBaseline->totalDiscCosts(this->DiscountingCoeff, this->DiscountingAfterYear,Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion, 
		Initial_I, Initial_II, Initial_III, Initial_IV,
		Cont_I,Cont_II,Cont_III,Cont_IV,
		Final_I,Final_II,Final_III,Final_IV,
		Final_oc_I,Final_oc_II,Final_oc_III,Final_oc_IV);
	double c2 = outStrategy->totalDiscCosts(this->DiscountingCoeff, this->DiscountingAfterYear,Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion, 
		Initial_I, Initial_II, Initial_III, Initial_IV,
		Cont_I,Cont_II,Cont_III,Cont_IV,
		Final_I,Final_II,Final_III,Final_IV,
		Final_oc_I,Final_oc_II,Final_oc_III,Final_oc_IV);
	double c3 = outBaseline->totalDiscLifeYearsLost(this->DiscountingCoeff, this->DiscountingAfterYear);
	double c4 = outStrategy->totalDiscLifeYearsLost(this->DiscountingCoeff, this->DiscountingAfterYear);
	
	return (c2-c1)/(c3-c4);
	

	/*
	vector<double> c1 = outBaseline->totalDiscCostsVec(this->DiscountingCoeff, this->DiscountingAfterYear,Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion, 
		Initial_I, Initial_II, Initial_III, Initial_IV,
		Cont_I,Cont_II,Cont_III,Cont_IV,
		Final_I,Final_II,Final_III,Final_IV,
		Final_oc_I,Final_oc_II,Final_oc_III,Final_oc_IV);
	vector<double> c2 = outStrategy->totalDiscCostsVec(this->DiscountingCoeff, this->DiscountingAfterYear,Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion, 
		Initial_I, Initial_II, Initial_III, Initial_IV,
		Cont_I,Cont_II,Cont_III,Cont_IV,
		Final_I,Final_II,Final_III,Final_IV,
		Final_oc_I,Final_oc_II,Final_oc_III,Final_oc_IV);
	vector<double> c3 = outBaseline->totalDiscLifeYearsLostVec(this->DiscountingCoeff, this->DiscountingAfterYear);
	vector<double> c4 = outStrategy->totalDiscLifeYearsLostVec(this->DiscountingCoeff, this->DiscountingAfterYear);
	
	double out = 0.0;
	for (int i = 0; i < c1.size(); ++i) 
		out += (c2[i]-c1[i])/(c3[i]-c4[i]);

	return out;
	*/
}

double Evaluate::totalTreatCostsSingle(Output *out){
	return out->totalDiscCosts(this->DiscountingCoeff, this->DiscountingAfterYear,Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion, 
		Initial_I, Initial_II, Initial_III, Initial_IV,
		Cont_I,Cont_II,Cont_III,Cont_IV,
		Final_I,Final_II,Final_III,Final_IV,
		Final_oc_I,Final_oc_II,Final_oc_III,Final_oc_IV);
}

double Evaluate::totalTreatCosts(Output *outBaseline, Output *outStrategy){
	double c1 = outBaseline->totalTreatCosts(Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion, 
		Initial_I, Initial_II, Initial_III, Initial_IV,
		Cont_I,Cont_II,Cont_III,Cont_IV,
		Final_I,Final_II,Final_III,Final_IV,
		Final_oc_I,Final_oc_II,Final_oc_III,Final_oc_IV);
	double c2 = outStrategy->totalTreatCosts(Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion, 
		Initial_I, Initial_II, Initial_III, Initial_IV,
		Cont_I,Cont_II,Cont_III,Cont_IV,
		Final_I,Final_II,Final_III,Final_IV,
		Final_oc_I,Final_oc_II,Final_oc_III,Final_oc_IV);
	double c3 = outBaseline->initialPopulationSize();

	return (c2-c1)/c3;
}

double Evaluate::totalScreenCosts(Output *outBaseline, Output *outStrategy){
	double c1 = outBaseline->totalScreeningCosts(Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion);
	double c2 = outStrategy->totalScreeningCosts(Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion);
	double c3 = outBaseline->initialPopulationSize();

	return (c2-c1)/c3;
}


double Evaluate::totalFollowupCosts(Output *outBaseline, Output *outStrategy){
	double c1 = outBaseline->totalFollowupCosts(Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion);
	double c2 = outStrategy->totalFollowupCosts(Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion);
	double c3 = outBaseline->initialPopulationSize();

	return (c2-c1)/c3;
}


void Evaluate::addEvaluationResults(string scenarioName, boost::property_tree::ptree* pt, Output* outBaseline, Output* outStrategy) {

   pt->put(scenarioName+".Incidence",to_string((double)outStrategy->totalNumberOfCancers()/(double)outStrategy->initialPopulationSize()*100000.0));
   pt->put(scenarioName+".Mortality", to_string((double)outStrategy->deathCancer/(double)outStrategy->initialPopulationSize()*100000.0));
   pt->put(scenarioName+".LYlost", to_string((double)outStrategy->totalDiscLifeYearsLost(1.0, 1000000)/(double)outStrategy->initialPopulationSize()*1000.0));
   pt->put(scenarioName+".TotalCosts", to_string(outStrategy->totalDiscCosts(1.0, 1000000,Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion, 
		Initial_I, Initial_II, Initial_III, Initial_IV,
		Cont_I,Cont_II,Cont_III,Cont_IV,
		Final_I,Final_II,Final_III,Final_IV,
		Final_oc_I,Final_oc_II,Final_oc_III,Final_oc_IV)/(double)outStrategy->initialPopulationSize()*1000.0));	

 	pt->put(scenarioName+".discLYlost", to_string((double)outStrategy->totalDiscLifeYearsLost(this->DiscountingCoeff, this->DiscountingAfterYear)));
	pt->put(scenarioName+".discTotalCosts", to_string((double)outStrategy->totalDiscCosts(this->DiscountingCoeff, this->DiscountingAfterYear,Colonoscopy, Colonoscopy_Polyp, Colonoscopy_Cancer, Colonoscopy_Perforation,
		Colonoscopy_Serosal_burn, Colonoscopy_bleed, Colonoscopy_bleed_transfusion, 
		Initial_I, Initial_II, Initial_III, Initial_IV,
		Cont_I,Cont_II,Cont_III,Cont_IV,
		Final_I,Final_II,Final_III,Final_IV,
		Final_oc_I,Final_oc_II,Final_oc_III,Final_oc_IV)));

   pt->put(scenarioName+".IncidenceReduction",to_string(this->IncidenceReduction(outBaseline, outStrategy)));
   pt->put(scenarioName+".MortalityReduction", to_string(this->MortalityReduction(outBaseline, outStrategy)));
   pt->put(scenarioName+".DiscountedLYgained", to_string(this->DiscountedLYgained(outBaseline, outStrategy)));
   pt->put(scenarioName+".USdollarPerLYG", to_string(this->USdollatPerLYG(outBaseline, outStrategy)));	

   pt->put(scenarioName+".totalTreatCosts", to_string(this->totalTreatCosts(outBaseline, outStrategy)));
   pt->put(scenarioName+".totalScreenCosts", to_string(this->totalScreenCosts(outBaseline, outStrategy)));
   pt->put(scenarioName+".totalFollowupCosts", to_string(this->totalFollowupCosts(outBaseline, outStrategy)));
   pt->put(scenarioName+".numberOfScreeningColonoscopies", to_string(outStrategy->numberScreeningColonoscopies));

}