#include "Output.h"
#include <iostream>



Output::Output(SimulationParameters* sp) {

	deathCancer = 0;

	int N = (int)sp->YearsToSimulate;

	this->cancerFemales.assign(N,0);
	this->cancerMales.assign(N,0);

	this->populationFemales.assign(N,0);
	this->populationMales.assign(N,0);

	this->numberAnyPolypFemales.assign(N,0);
	this->numberAnyPolypMales.assign(N,0);

	this->numberAdvancedPolypFemales.assign(N,0);
	this->numberAdvancedPolypMales.assign(N,0);

	this->numberColonoscopiesFemale.assign(N,0);
	this->numberColonoscopiesMale.assign(N,0);

	this->polypsSummFemale.assign(N*(int)sp->NumPolypStages,0);
	this->polypsSummMale.assign(N*(int)sp->NumPolypStages,0);

	this->coloNoTumorAndNoPolypsScreen.assign(N,0);
	this->coloTumorNoPolypsScreen.assign(N,0);
	this->coloNoTumorAndPolypsScreen.assign(N,0);

	this->numPerforationsScreen.assign(N,0); 
	this->numSerosaScreen.assign(N,0);
	this->numBleedingScreen.assign(N,0);
	this->numBleedingTransfScreen.assign(N,0);

	this->coloNoTumorAndNoPolypsTreat.assign(N,0);
	this->coloTumorNoPolypsTreat.assign(N,0);
	this->coloNoTumorAndPolypsTreat.assign(N,0);

	this->numPerforationsTreat.assign(N,0); 
	this->numSerosaTreat.assign(N,0);
	this->numBleedingTreat.assign(N,0);
	this->numBleedingTransfTreat.assign(N,0);

	this->coloNoTumorAndNoPolypsFollowup.assign(N,0);
	this->coloTumorNoPolypsFollowup.assign(N,0);
	this->coloNoTumorAndPolypsFollowup.assign(N,0);

	this->numPerforationsFollowup.assign(N,0); 
	this->numSerosaFollowup.assign(N,0);
	this->numBleedingFollowup.assign(N,0);
	this->numBleedingTransfFollowup.assign(N,0);

	this->lifeYearsLostCa.assign(N,0.0f);
	this->lifeYearsLostColo.assign(N,0.0f);

	this->stageICostContinous.assign(N,0.0f);
	this->stageICostInitial.assign(N,0.0f);
	this->stageICostFinal.assign(N,0.0f);
	this->stageICostFinalOC.assign(N,0.0f);
	this->stageIICostContinous.assign(N,0.0f);
	this->stageIICostInitial.assign(N,0.0f);
	this->stageIICostFinal.assign(N,0.0f);
	this->stageIICostFinalOC.assign(N,0.0f);
	this->stageIIICostContinous.assign(N,0.0f);
	this->stageIIICostInitial.assign(N,0.0f);
	this->stageIIICostFinal.assign(N,0.0f);
	this->stageIIICostFinalOC.assign(N,0.0f);
	this->stageIVCostContinous.assign(N,0.0f);
	this->stageIVCostInitial.assign(N,0.0f);
	this->stageIVCostFinal.assign(N,0.0f);
	this->stageIVCostFinalOC.assign(N,0.0f);

	this->initPopSize = sp->PopulationSize;
	this->numberScreeningColonoscopies = 0;

	this->numberDetectedCancers.assign(N,0);
}

void Output::addResults(Output *outToAdd) {


	for (int i = 0; i < cancerFemales.size(); ++i) {
		this->cancerFemales[i] += outToAdd->cancerFemales[i];
		this->cancerMales[i] += outToAdd->cancerMales[i];
		this->populationFemales[i] += outToAdd->populationFemales[i];
		this->populationMales[i] += outToAdd->populationMales[i];
		this->numberAnyPolypMales[i] += outToAdd->numberAnyPolypMales[i];
		this->numberAnyPolypFemales[i] += outToAdd->numberAnyPolypFemales[i];
		this->numberAdvancedPolypMales[i] += outToAdd->numberAdvancedPolypMales[i];
		this->numberAdvancedPolypFemales[i] += outToAdd->numberAdvancedPolypFemales[i];
		this->numberColonoscopiesFemale[i] += outToAdd->numberColonoscopiesFemale[i];
		this->numberColonoscopiesMale[i] += outToAdd->numberColonoscopiesMale[i];

		this->coloNoTumorAndNoPolypsScreen[i] += outToAdd->coloNoTumorAndNoPolypsScreen[i];
		this->coloTumorNoPolypsScreen[i] += outToAdd->coloTumorNoPolypsScreen[i];
		this->coloNoTumorAndPolypsScreen[i] += outToAdd-> coloNoTumorAndPolypsScreen[i];

		this->numPerforationsScreen[i] += outToAdd->numPerforationsScreen[i];
		this->numSerosaScreen[i] += outToAdd->numSerosaScreen[i];
		this->numBleedingScreen[i] += outToAdd->numBleedingScreen[i];
		this->numBleedingTransfScreen[i] += outToAdd->numBleedingTransfScreen[i];

		this->coloNoTumorAndNoPolypsTreat[i] += outToAdd->coloNoTumorAndNoPolypsTreat[i];
		this->coloTumorNoPolypsTreat[i] += outToAdd->coloTumorNoPolypsTreat[i];
		this->coloNoTumorAndPolypsTreat[i] += outToAdd-> coloNoTumorAndPolypsTreat[i];

		this->numPerforationsTreat[i] += outToAdd->numPerforationsTreat[i];
		this->numSerosaTreat[i] += outToAdd->numSerosaTreat[i];
		this->numBleedingTreat[i] += outToAdd->numBleedingTreat[i];
		this->numBleedingTransfTreat[i] += outToAdd->numBleedingTransfTreat[i];


		this->coloNoTumorAndNoPolypsFollowup[i] += outToAdd->coloNoTumorAndNoPolypsFollowup[i];
		this->coloTumorNoPolypsFollowup[i] += outToAdd->coloTumorNoPolypsFollowup[i];
		this->coloNoTumorAndPolypsFollowup[i] += outToAdd-> coloNoTumorAndPolypsFollowup[i];

		this->numPerforationsFollowup[i] += outToAdd->numPerforationsFollowup[i];
		this->numSerosaFollowup[i] += outToAdd->numSerosaFollowup[i];
		this->numBleedingFollowup[i] += outToAdd->numBleedingFollowup[i];
		this->numBleedingTransfFollowup[i] += outToAdd->numBleedingTransfFollowup[i];

		this->lifeYearsLostCa[i] += outToAdd->lifeYearsLostCa[i];
		this->lifeYearsLostColo[i] += outToAdd->lifeYearsLostColo[i];

		this->stageICostContinous[i] += outToAdd->stageICostContinous[i];
		this->stageICostInitial[i] += outToAdd->stageICostInitial[i];
		this->stageICostFinal[i] += outToAdd->stageICostFinal[i];
		this->stageICostFinalOC[i] += outToAdd->stageICostFinalOC[i];
		this->stageIICostContinous[i] += outToAdd->stageIICostContinous[i];
		this->stageIICostInitial[i] += outToAdd->stageIICostInitial[i];
		this->stageIICostFinal[i] += outToAdd->stageIICostFinal[i];
		this->stageIICostFinalOC[i] += outToAdd->stageIICostFinalOC[i];
		this->stageIIICostContinous[i] += outToAdd->stageIIICostContinous[i];
		this->stageIIICostInitial[i] += outToAdd->stageIIICostInitial[i];
		this->stageIIICostFinal[i] += outToAdd->stageIIICostFinal[i];
		this->stageIIICostFinalOC[i] += outToAdd->stageIIICostFinalOC[i];
		this->stageIVCostContinous[i] += outToAdd->stageIVCostContinous[i];
		this->stageIVCostInitial[i] += outToAdd->stageIVCostInitial[i];
		this->stageIVCostFinal[i] += outToAdd->stageIVCostFinal[i];
		this->stageIVCostFinalOC[i] += outToAdd->stageIVCostFinalOC[i];

		this->numberDetectedCancers[i] += outToAdd->numberDetectedCancers[i];
	}

	this->deathCancer+=outToAdd->deathCancer;
	this->numberScreeningColonoscopies+=outToAdd->numberScreeningColonoscopies;
	

	for (int i = 0; i < this->polypsSummMale.size(); ++i) {
		this->polypsSummMale[i] += outToAdd->polypsSummMale[i];
		this->polypsSummFemale[i] += outToAdd->polypsSummFemale[i];
	}

}

long int Output::totalNumberOfCancersMales() {
	long int result = 0;
	for (int i = 0; i < this->cancerMales.size(); ++i) {
		result += cancerMales[i];
	}
	return result;
}

long int Output::totalNumberOfCancersFemales() {
	long int result = 0;
	for (int i = 0; i < this->cancerFemales.size(); ++i) {
		result += cancerFemales[i];
	}
	return result;
}

long int Output::totalNumberOfCancers() {
	long int result = 0;
	for (int i = 0; i < this->cancerFemales.size(); ++i) {
		result += cancerFemales[i];
		result += cancerMales[i];
	}
	return result;
}

double Output::totalLifeYearsLost() {
	double result = 0;
	for (int i = 0; i < this->lifeYearsLostCa.size(); ++i) {
			result += (double)this->lifeYearsLostCa[i];
			result += (double)this->lifeYearsLostColo[i];
	}
	return result;
}

double Output::totalDiscLifeYearsLost(double discVal, double discAfter) {
	double result = 0;
	double discValCurrent = 1.0;
	for (int i =0; i < this->lifeYearsLostCa.size(); ++i) {
		result += discValCurrent*((double)this->lifeYearsLostCa[i]);
		result += discValCurrent*((double)this->lifeYearsLostColo[i]);
		if (i > (int)discAfter)
			discValCurrent *= discVal;
	}
	return result;
}

vector<double> Output::totalDiscLifeYearsLostVec(double discVal, double discAfter) {
	vector<double> result;
	double resultTmp;

	double discValCurrent = 1.0;
	for (int i = 0; i < this->lifeYearsLostCa.size(); ++i) {
		resultTmp = discValCurrent*((double)this->lifeYearsLostCa[i]);
		resultTmp += discValCurrent*((double)this->lifeYearsLostColo[i]);
		result.push_back(resultTmp);
		if (i > (int)discAfter)
			discValCurrent *= discVal;
	}
	return result;
}

double Output::totalScreeningCosts(double Colonoscopy,double Colonoscopy_Polyp,double  Colonoscopy_Cancer,
	double Colonoscopy_Perforation,double Colonoscopy_Serosal_burn,double Colonoscopy_bleed,double Colonoscopy_bleed_transfusion) {

	double result = 0.0;
	for (int i = 0; i < this->lifeYearsLostCa.size(); ++i) {
		result += (Colonoscopy*(double)this->coloNoTumorAndNoPolypsScreen[i]);
		result += (Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsScreen[i]);
		result += (Colonoscopy_Cancer*(double)this->coloTumorNoPolypsScreen[i]);
		result += (Colonoscopy_Perforation*(double)this->numPerforationsScreen[i]);
		result += (Colonoscopy_Serosal_burn*(double)this->numSerosaScreen[i]);
		result += (Colonoscopy_bleed*(double)this->numBleedingScreen[i]);
		result += (Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfScreen[i]);
	}
	
	return result;
}

double Output::totalFollowupCosts(double Colonoscopy,double Colonoscopy_Polyp,double  Colonoscopy_Cancer,
	double Colonoscopy_Perforation,double Colonoscopy_Serosal_burn,double Colonoscopy_bleed,double Colonoscopy_bleed_transfusion) {

	double result = 0.0;
	
	for (int i = 0; i < this->lifeYearsLostCa.size(); ++i) {
		result += (Colonoscopy*(double)this->coloNoTumorAndNoPolypsFollowup[i]);
		result += (Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsFollowup[i]);
		result += (Colonoscopy_Cancer*(double)this->coloTumorNoPolypsFollowup[i]);
		result += (Colonoscopy_Perforation*(double)this->numPerforationsFollowup[i]);
		result += (Colonoscopy_Serosal_burn*(double)this->numSerosaFollowup[i]);
		result += (Colonoscopy_bleed*(double)this->numBleedingFollowup[i]);
		result += (Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfFollowup[i]);
	}
	
	return result;
}

double Output::totalTreatCosts(double Colonoscopy,double Colonoscopy_Polyp,double  Colonoscopy_Cancer,
	double Colonoscopy_Perforation,double Colonoscopy_Serosal_burn,double Colonoscopy_bleed,double Colonoscopy_bleed_transfusion, 
	double Initial_I,double Initial_II,double Initial_III,double Initial_IV,
	double Cont_I,double Cont_II,double Cont_III,double Cont_IV,
	double Final_I,double Final_II,double Final_III,double Final_IV,
	double Final_oc_I,double Final_oc_II,double Final_oc_III,double Final_oc_IV) {

	double result = 0.0;
	
	for (int i = 0; i < this->lifeYearsLostCa.size(); ++i) {
		
		result += (Colonoscopy*(double)this->coloNoTumorAndNoPolypsTreat[i]);
		result += (Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsTreat[i]);
		result += (Colonoscopy_Cancer*(double)this->coloTumorNoPolypsTreat[i]);
		result += (Colonoscopy_Perforation*(double)this->numPerforationsTreat[i]);
		result += (Colonoscopy_Serosal_burn*(double)this->numSerosaTreat[i]);
		result += (Colonoscopy_bleed*(double)this->numBleedingTreat[i]);
		result += (Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfTreat[i]);

		result += (Colonoscopy*(double)this->coloNoTumorAndNoPolypsFollowup[i]);
		result += (Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsFollowup[i]);
		result += (Colonoscopy_Cancer*(double)this->coloTumorNoPolypsFollowup[i]);
		result += (Colonoscopy_Perforation*(double)this->numPerforationsFollowup[i]);
		result += (Colonoscopy_Serosal_burn*(double)this->numSerosaFollowup[i]);
		result += (Colonoscopy_bleed*(double)this->numBleedingFollowup[i]);
		result += (Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfFollowup[i]);

		result += (Colonoscopy*(double)this->coloNoTumorAndNoPolypsScreen[i]);
		result += (Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsScreen[i]);
		result += (Colonoscopy_Cancer*(double)this->coloTumorNoPolypsScreen[i]);
		result += (Colonoscopy_Perforation*(double)this->numPerforationsScreen[i]);
		result += (Colonoscopy_Serosal_burn*(double)this->numSerosaScreen[i]);
		result += (Colonoscopy_bleed*(double)this->numBleedingScreen[i]);
		result += (Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfScreen[i]);

		result += (Initial_I*(double)this->stageICostInitial[i]);
		result += (Cont_I*(double)this->stageICostContinous[i]);
		result += (Final_I*(double)this->stageICostFinal[i]);
		result += (Final_oc_I*(double)this->stageICostFinalOC[i]);

		result += (Initial_II*(double)this->stageIICostInitial[i]);
		result += (Cont_II*(double)this->stageIICostContinous[i]);
		result += (Final_II*(double)this->stageIICostFinal[i]);
		result += (Final_oc_II*(double)this->stageIICostFinalOC[i]);

		result += (Initial_III*(double)this->stageIIICostInitial[i]);
		result += (Cont_III*(double)this->stageIIICostContinous[i]);
		result += (Final_III*(double)this->stageIIICostFinal[i]);
		result += (Final_oc_III*(double)this->stageIIICostFinalOC[i]);

		result += (Initial_IV*(double)this->stageIVCostInitial[i]);
		result += (Cont_IV*(double)this->stageIVCostContinous[i]);
		result += (Final_IV*(double)this->stageIVCostFinal[i]);
		result += (Final_oc_IV*(double)this->stageIVCostFinalOC[i]);
	}
	
	return result;
}

double Output::totalDiscCosts(double discVal, double discAfter, double Colonoscopy,double Colonoscopy_Polyp,double  Colonoscopy_Cancer,
	double Colonoscopy_Perforation,double Colonoscopy_Serosal_burn,double Colonoscopy_bleed,double Colonoscopy_bleed_transfusion, 
	double Initial_I,double Initial_II,double Initial_III,double Initial_IV,
	double Cont_I,double Cont_II,double Cont_III,double Cont_IV,
	double Final_I,double Final_II,double Final_III,double Final_IV,
	double Final_oc_I,double Final_oc_II,double Final_oc_III,double Final_oc_IV) {

	double result = 0.0;
	double discValCurrent = 1.0;
	for (int i = 0; i < this->lifeYearsLostCa.size(); ++i) {

		result += discValCurrent*(Colonoscopy*(double)this->coloNoTumorAndNoPolypsTreat[i]);
		result += discValCurrent*(Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsTreat[i]);
		result += discValCurrent*(Colonoscopy_Cancer*(double)this->coloTumorNoPolypsTreat[i]);
		result += discValCurrent*(Colonoscopy_Perforation*(double)this->numPerforationsTreat[i]);
		result += discValCurrent*(Colonoscopy_Serosal_burn*(double)this->numSerosaTreat[i]);
		result += discValCurrent*(Colonoscopy_bleed*(double)this->numBleedingTreat[i]);
		result += discValCurrent*(Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfTreat[i]);

		result += discValCurrent*(Colonoscopy*(double)this->coloNoTumorAndNoPolypsFollowup[i]);
		result += discValCurrent*(Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsFollowup[i]);
		result += discValCurrent*(Colonoscopy_Cancer*(double)this->coloTumorNoPolypsFollowup[i]);
		result += discValCurrent*(Colonoscopy_Perforation*(double)this->numPerforationsFollowup[i]);
		result += discValCurrent*(Colonoscopy_Serosal_burn*(double)this->numSerosaFollowup[i]);
		result += discValCurrent*(Colonoscopy_bleed*(double)this->numBleedingFollowup[i]);
		result += discValCurrent*(Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfFollowup[i]);

		result += discValCurrent*(Colonoscopy*(double)this->coloNoTumorAndNoPolypsScreen[i]);
		result += discValCurrent*(Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsScreen[i]);
		result += discValCurrent*(Colonoscopy_Cancer*(double)this->coloTumorNoPolypsScreen[i]);
		result += discValCurrent*(Colonoscopy_Perforation*(double)this->numPerforationsScreen[i]);
		result += discValCurrent*(Colonoscopy_Serosal_burn*(double)this->numSerosaScreen[i]);
		result += discValCurrent*(Colonoscopy_bleed*(double)this->numBleedingScreen[i]);
		result += discValCurrent*(Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfScreen[i]);

		result += discValCurrent*(Initial_I*(double)this->stageICostInitial[i]);
		result += discValCurrent*(Cont_I*(double)this->stageICostContinous[i]);
		result += discValCurrent*(Final_I*(double)this->stageICostFinal[i]);
		result += discValCurrent*(Final_oc_I*(double)this->stageICostFinalOC[i]);

		result += discValCurrent*(Initial_II*(double)this->stageIICostInitial[i]);
		result += discValCurrent*(Cont_II*(double)this->stageIICostContinous[i]);
		result += discValCurrent*(Final_II*(double)this->stageIICostFinal[i]);
		result += discValCurrent*(Final_oc_II*(double)this->stageIICostFinalOC[i]);

		result += discValCurrent*(Initial_III*(double)this->stageIIICostInitial[i]);
		result += discValCurrent*(Cont_III*(double)this->stageIIICostContinous[i]);
		result += discValCurrent*(Final_III*(double)this->stageIIICostFinal[i]);
		result += discValCurrent*(Final_oc_III*(double)this->stageIIICostFinalOC[i]);

		result += discValCurrent*(Initial_IV*(double)this->stageIVCostInitial[i]);
		result += discValCurrent*(Cont_IV*(double)this->stageIVCostContinous[i]);
		result += discValCurrent*(Final_IV*(double)this->stageIVCostFinal[i]);
		result += discValCurrent*(Final_oc_IV*(double)this->stageIVCostFinalOC[i]);
		if (i > (int)discAfter)
			discValCurrent *= discVal;
	}
	
	return result;
}

vector<double> Output::totalDiscCostsVec(double discVal, double discAfter, double Colonoscopy,double Colonoscopy_Polyp,double  Colonoscopy_Cancer,
	double Colonoscopy_Perforation,double Colonoscopy_Serosal_burn,double Colonoscopy_bleed,double Colonoscopy_bleed_transfusion, 
	double Initial_I,double Initial_II,double Initial_III,double Initial_IV,
	double Cont_I,double Cont_II,double Cont_III,double Cont_IV,
	double Final_I,double Final_II,double Final_III,double Final_IV,
	double Final_oc_I,double Final_oc_II,double Final_oc_III,double Final_oc_IV) {

	vector<double> result;
	double resultTmp = 0.0;
	double discValCurrent = 1.0;
	for (int i = 0; i < this->lifeYearsLostCa.size(); ++i) {

		resultTmp = discValCurrent*(Colonoscopy*(double)this->coloNoTumorAndNoPolypsTreat[i]);
		resultTmp += discValCurrent*(Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsTreat[i]);
		resultTmp += discValCurrent*(Colonoscopy_Cancer*(double)this->coloTumorNoPolypsTreat[i]);
		resultTmp += discValCurrent*(Colonoscopy_Perforation*(double)this->numPerforationsTreat[i]);
		resultTmp += discValCurrent*(Colonoscopy_Serosal_burn*(double)this->numSerosaTreat[i]);
		resultTmp += discValCurrent*(Colonoscopy_bleed*(double)this->numBleedingTreat[i]);
		resultTmp += discValCurrent*(Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfTreat[i]);

		resultTmp += discValCurrent*(Colonoscopy*(double)this->coloNoTumorAndNoPolypsFollowup[i]);
		resultTmp += discValCurrent*(Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsFollowup[i]);
		resultTmp += discValCurrent*(Colonoscopy_Cancer*(double)this->coloTumorNoPolypsFollowup[i]);
		resultTmp += discValCurrent*(Colonoscopy_Perforation*(double)this->numPerforationsFollowup[i]);
		resultTmp += discValCurrent*(Colonoscopy_Serosal_burn*(double)this->numSerosaFollowup[i]);
		resultTmp += discValCurrent*(Colonoscopy_bleed*(double)this->numBleedingFollowup[i]);
		resultTmp += discValCurrent*(Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfFollowup[i]);

		resultTmp += discValCurrent*(Colonoscopy*(double)this->coloNoTumorAndNoPolypsScreen[i]);
		resultTmp += discValCurrent*(Colonoscopy_Polyp*(double)this->coloNoTumorAndPolypsScreen[i]);
		resultTmp += discValCurrent*(Colonoscopy_Cancer*(double)this->coloTumorNoPolypsScreen[i]);
		resultTmp += discValCurrent*(Colonoscopy_Perforation*(double)this->numPerforationsScreen[i]);
		resultTmp += discValCurrent*(Colonoscopy_Serosal_burn*(double)this->numSerosaScreen[i]);
		resultTmp += discValCurrent*(Colonoscopy_bleed*(double)this->numBleedingScreen[i]);
		resultTmp += discValCurrent*(Colonoscopy_bleed_transfusion*(double)this->numBleedingTransfScreen[i]);

		resultTmp += discValCurrent*(Initial_I*(double)this->stageICostInitial[i]);
		resultTmp += discValCurrent*(Cont_I*(double)this->stageICostContinous[i]);
		resultTmp += discValCurrent*(Final_I*(double)this->stageICostFinal[i]);
		resultTmp += discValCurrent*(Final_oc_I*(double)this->stageICostFinalOC[i]);

		resultTmp += discValCurrent*(Initial_II*(double)this->stageIICostInitial[i]);
		resultTmp += discValCurrent*(Cont_II*(double)this->stageIICostContinous[i]);
		resultTmp += discValCurrent*(Final_II*(double)this->stageIICostFinal[i]);
		resultTmp += discValCurrent*(Final_oc_II*(double)this->stageIICostFinalOC[i]);

		resultTmp += discValCurrent*(Initial_III*(double)this->stageIIICostInitial[i]);
		resultTmp += discValCurrent*(Cont_III*(double)this->stageIIICostContinous[i]);
		resultTmp += discValCurrent*(Final_III*(double)this->stageIIICostFinal[i]);
		resultTmp += discValCurrent*(Final_oc_III*(double)this->stageIIICostFinalOC[i]);

		resultTmp += discValCurrent*(Initial_IV*(double)this->stageIVCostInitial[i]);
		resultTmp += discValCurrent*(Cont_IV*(double)this->stageIVCostContinous[i]);
		resultTmp += discValCurrent*(Final_IV*(double)this->stageIVCostFinal[i]);
		resultTmp += discValCurrent*(Final_oc_IV*(double)this->stageIVCostFinalOC[i]);
		if (i > (int)discAfter)
			discValCurrent *= discVal;

		result.push_back(resultTmp);
	}
	
	return result;
}


void Output::saveSummary(vector<Cancer> *c, bool gender, unsigned char causeOfDeath, float deathCancerRelated, float deathYearLifeTables, float dt) {

	
	float deathMoment = deathCancerRelated < 0.0f?deathYearLifeTables:min(deathYearLifeTables,deathCancerRelated);
	float costsUntil;

	if (causeOfDeath == 1)
		this->deathCancer++;

	//if (deathMoment < 100.0f) {

	for (int i = 0; i < c->size(); ++i) {//go through each cancer
		if (c->at(i).detected) {//if the cancer was detected
			float start = c->at(i).ageDetected;
			float difference = min(deathMoment - start, 5.0f);
			bool survived5years = difference == 5.0f;
			switch (c->at(i).stageAtDetection) {
				case 1:
					//costs are mutually exclusive
					for (float t = start; t < start+difference; t+=dt) {
						if (survived5years) {//patient did not die within 5 years
							if (t - start < 1.0f) {//initial year
								this->stageICostInitial[(int)t]+=dt;
							} else {
								this->stageICostContinous[(int)t]+=dt;
							}
						} else {//there was death
							if ( t >= start + difference - 1.0f) {//last year
								if (causeOfDeath == 1) {//died of cancer
									this->stageICostFinal[(int)t]+=dt;
								} else {
									this->stageICostFinalOC[(int)t]+=dt;
								}
							} else if (t - start < 1.0f) {//initial year
								this->stageICostInitial[(int)t]+=dt;
							} else {
								this->stageICostContinous[(int)t]+=dt;
							}
						}
					}
					break;
				case 2:
					for (float t = start; t < start+difference; t+=dt) {
						if (survived5years) {//patient did not die within 5 years
							if (t - start < 1.0f) {//initial year
								this->stageIICostInitial[(int)t]+=dt;
							} else {
								this->stageIICostContinous[(int)t]+=dt;
							}
						} else {//there was death
							if ( t >= start + difference - 1.0f) {//last year
								if (causeOfDeath == 1) {//died of cancer
									this->stageIICostFinal[(int)t]+=dt;
								} else {
									this->stageIICostFinalOC[(int)t]+=dt;
								}
							} else if (t - start < 1.0f) {//initial year
								this->stageIICostInitial[(int)t]+=dt;
							} else {
								this->stageIICostContinous[(int)t]+=dt;
							}
						}
					}
					break;
				case 3:
					for (float t = start; t < start+difference; t+=dt) {
						if (survived5years) {//patient did not die within 5 years
							if (t - start < 1.0f) {//initial year
								this->stageIIICostInitial[(int)t]+=dt;
							} else {
								this->stageIIICostContinous[(int)t]+=dt;
							}
						} else {//there was death
							if ( t >= start + difference - 1.0f) {//last year
								if (causeOfDeath == 1) {//died of cancer
									this->stageIIICostFinal[(int)t]+=dt;
								} else {
									this->stageIIICostFinalOC[(int)t]+=dt;
								}
							} else if (t - start < 1.0f) {//initial year
								this->stageIIICostInitial[(int)t]+=dt;
							} else {
								this->stageIIICostContinous[(int)t]+=dt;
							}
						}
					}				
					break;
				case 4:
					for (float t = start; t < start+difference; t+=dt) {
						if (survived5years) {//patient did not die within 5 years
							if (t - start < 1.0f) {//initial year
								this->stageIVCostInitial[(int)t]+=dt;
							} else {
								this->stageIVCostContinous[(int)t]+=dt;
							}
						} else {//there was death
							if ( t >= start + difference - 1.0f) {//last year
								if (causeOfDeath == 1) {//died of cancer
									this->stageIVCostFinal[(int)t]+=dt;
								} else {
									this->stageIVCostFinalOC[(int)t]+=dt;
								}
							} else if (t - start < 1.0f) {//initial year
								this->stageIVCostInitial[(int)t]+=dt;
							} else {
								this->stageIVCostContinous[(int)t]+=dt;
							}
						}
					}				
					break;

				default:
					std::cout << "Error: cancer stage out of range!" << std::endl;
			}			

		}
	}
	//}
	
}

void Output::addColonoscopy(float age, bool gender, unsigned short int cancerCounter, unsigned short int earlyCounter, unsigned short int advancedCounter,
						bool perforation, bool serosa, bool bleeding, bool bleedingTransfusion, unsigned char type) {
	//type 1 = symptoms, type 2 = follow-up, type 3 = screening						
	int indx = (int)age;
	if (gender) {
		this->numberColonoscopiesFemale[indx]++;
	} else {
		this->numberColonoscopiesMale[indx]++;
	}
	//add the information about removed polyp
	if (type == 1) {
		if (cancerCounter == 0 && earlyCounter == 0 && advancedCounter == 0)
			this->coloNoTumorAndNoPolypsTreat[indx]++;
		if (cancerCounter > 0 && earlyCounter == 0 && advancedCounter == 0)
			this->coloTumorNoPolypsTreat[indx]++;
		if (cancerCounter == 0 && (earlyCounter > 0 || advancedCounter > 0))
			this->coloNoTumorAndPolypsTreat[indx]++;
	
		if (perforation) this->numPerforationsTreat[indx]++;
		if (serosa) this->numSerosaTreat[indx]++;
		if (bleeding) this->numBleedingTreat[indx]++;
		if (bleedingTransfusion) this->numBleedingTransfTreat[indx]++;
	} else if (type == 2) {
		if (cancerCounter == 0 && earlyCounter == 0 && advancedCounter == 0)
			this->coloNoTumorAndNoPolypsFollowup[indx]++;
		if (cancerCounter > 0 && earlyCounter == 0 && advancedCounter == 0)
			this->coloTumorNoPolypsFollowup[indx]++;
		if (cancerCounter == 0 && (earlyCounter > 0 || advancedCounter > 0))
			this->coloNoTumorAndPolypsFollowup[indx]++;
	
		if (perforation) this->numPerforationsFollowup[indx]++;
		if (serosa) this->numSerosaFollowup[indx]++;
		if (bleeding) this->numBleedingFollowup[indx]++;
		if (bleedingTransfusion) this->numBleedingTransfFollowup[indx]++;
	} else if (type == 3) {
		if (cancerCounter == 0 && earlyCounter == 0 && advancedCounter == 0)
			this->coloNoTumorAndNoPolypsScreen[indx]++;
		if (cancerCounter > 0 && earlyCounter == 0 && advancedCounter == 0)
			this->coloTumorNoPolypsScreen[indx]++;
		if (cancerCounter == 0 && (earlyCounter > 0 || advancedCounter > 0))
			this->coloNoTumorAndPolypsScreen[indx]++;
	
		if (perforation) this->numPerforationsScreen[indx]++;
		if (serosa) this->numSerosaScreen[indx]++;
		if (bleeding) this->numBleedingScreen[indx]++;
		if (bleedingTransfusion) this->numBleedingTransfScreen[indx]++;

		this->numberScreeningColonoscopies++;
	}

	if (cancerCounter > 0) {//save for incidence
		if (gender) {
			this->cancerFemales[indx]++;
		} else {
			this->cancerMales[indx]++;
		}
		this->numberDetectedCancers[indx] += cancerCounter;
	}
}


void Output::recordPolypsPrevalence(vector<Polyp> *polyps, float deathAge, bool gender) {
	
	vector<unsigned char> maxStage(this->populationFemales.size(),0);

	for (int i = 0; i < polyps->size(); ++i) {
		int tstart = (int)ceil(polyps->at(i).ageDeveloped);
		int tend = (int)polyps->at(i).ageEnd;

		tend = polyps->at(i).ageEnd > deathAge ? (int)deathAge : tend;
		
		unsigned char stageLoc = 1;
		int w = 0;
		for (int j = tstart; j <= tend; ++j) {
			
			while ( w < polyps->at(i).hist_t.size() && (float)j >= polyps->at(i).hist_t.at(w)) {
				if (polyps->at(i).hist_y[w] == 0) stageLoc--; 
				if (polyps->at(i).hist_y[w] == 1) stageLoc++;
				if (polyps->at(i).hist_y[w] == 2) stageLoc=0;
				w++;
			}
			maxStage[j] = maxStage[j]<stageLoc?stageLoc:maxStage[j];
			//if (stageLoc >= 5)
			//	advancedPolyp[j] = true;
		}
	}

	if (gender) {
		for (int i = 0; i < maxStage.size(); i++){
			if (maxStage[i]>0)
			this->polypsSummFemale[i*6+(int)maxStage[i]-1]++;
			//if (anyPolyp[i]) this->numberAnyPolypFemales[i]++;
			//if (advancedPolyp[i]) this->numberAdvancedPolypFemales[i]++;
		}
	} else {
		for (int i = 0; i < maxStage.size(); i++) {
			if (maxStage[i]>0)
			this->polypsSummMale[i*6+(int)maxStage[i]-1]++;
			//if (anyPolyp[i]) this->numberAnyPolypMales[i]++;
			//if (advancedPolyp[i]) this->numberAdvancedPolypMales[i]++;
		}
	}
		
};

void Output::recordDeath(float deathCancerRelated, float deathYearLifeTables, unsigned char causeOfDeath, bool gender) {

	float age = deathCancerRelated>0.0f?min(deathCancerRelated,deathYearLifeTables):deathYearLifeTables;
	int tAge = (int)ceil(age)-1;
	if (gender) {
		for (int i = 0; i <= tAge; ++i) populationFemales[i]++;
	} else {
		for (int i = 0; i <= tAge; ++i) populationMales[i]++;
	}

	//record life years lost
	if (deathCancerRelated > 0.0f){
		float LY = max(deathYearLifeTables - deathCancerRelated,0.0f);
		if (LY > 0.0f) {
			if (causeOfDeath == 1) {//cancer
				for (int i = (int)deathCancerRelated; i < (int)deathCancerRelated+(int)LY; ++i) 
					this->lifeYearsLostCa[i]++;
				if (LY-floor(LY) > 0.0f)
					this->lifeYearsLostCa[(int)deathCancerRelated+(int)LY+1] += LY-floor(LY);
			} else if (causeOfDeath == 2) {//colonoscopy
				for (int i = (int)deathCancerRelated; i < (int)deathCancerRelated+(int)LY; ++i) 
					this->lifeYearsLostColo[i]++;
				if (LY-floor(LY) > 0.0f)
					this->lifeYearsLostColo[(int)deathCancerRelated+(int)LY+1] += LY-floor(LY);
			}
		}
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




void Output::printResults() {
	/*
	std::cout <<"Cancer incidence females: " << std::endl;
	for (int i = 0; i < this->cancerFemales.size(); ++ i) {
		std::cout << (double)cancerFemales[i]/(double)populationFemales[i]*100000.0 << ", ";
	}
	std::cout << std::endl;

	std::cout <<"Cancer incidence males: " << std::endl;
	for (int i = 0; i < this->cancerMales.size(); ++ i) {
		std::cout << (double)cancerMales[i]/(double)populationMales[i]*100000.0 << ", ";
	}
	std::cout << std::endl;*/

	std::cout << "coloNoTumorAndNoPolyps: " << arrayToString<unsigned long>(this->coloNoTumorAndNoPolypsTreat) << std::endl << std::endl;
	std::cout << "coloTumorNoPolyps: " << arrayToString<unsigned long>(this->coloTumorNoPolypsTreat) << std::endl << std::endl;
	std::cout << "coloNoTumorAndPolyps: " << arrayToString<unsigned long>(this->coloNoTumorAndPolypsTreat) << std::endl << std::endl;

	std::cout << "numPerforations: " << arrayToString<unsigned long>(this->numPerforationsTreat) << std::endl << std::endl;
	std::cout << "numSerosa: " << arrayToString<unsigned long>(this->numSerosaTreat) << std::endl << std::endl;
	std::cout << "numBleeding: " << arrayToString<unsigned long>(this->numBleedingTreat) << std::endl << std::endl;
	std::cout << "numBleedingTransf: " << arrayToString<unsigned long>(this->numBleedingTransfTreat) << std::endl << std::endl;

	std::cout << "Total number od cancers: " << this->totalNumberOfCancers() << std::endl;

	/*
	std::cout << "StageIa: " << this->stageICostContinous << std::endl;
	std::cout << "StageIb: " << this->stageICostInitial << std::endl;
	std::cout << "StageIc: " << this->stageICostFinal << std::endl;
	std::cout << "StageId: " << this->stageICostFinalOC << std::endl;

	std::cout << "StageIIa: " << this->stageIICostContinous << std::endl;
	std::cout << "StageIIb: " << this->stageIICostInitial << std::endl;
	std::cout << "StageIIc: " << this->stageIICostFinal << std::endl;
	std::cout << "StageIId: " << this->stageIICostFinalOC << std::endl;

	std::cout << "StageIIIa: " << this->stageIIICostContinous << std::endl;
	std::cout << "StageIIIb: " << this->stageIIICostInitial << std::endl;
	std::cout << "StageIIIc: " << this->stageIIICostFinal << std::endl;
	std::cout << "StageIIId: " << this->stageIIICostFinalOC << std::endl;

	std::cout << "StageIVa: " << this->stageIVCostContinous << std::endl;
	std::cout << "StageIVb: " << this->stageIVCostInitial << std::endl;
	std::cout << "StageIVc: " << this->stageIVCostFinal << std::endl;
	std::cout << "StageIVd: " << this->stageIVCostFinalOC << std::endl << std::endl;
	*/

	/*
	std::cout <<"People with polyp overall: " << std::endl;
	for (int i = 0; i < this->numberAnyPolyp.size(); ++ i) {
		std::cout << numberAnyPolyp[i] << ", ";
	}
	std::cout << std::endl;
	
	std::cout <<"Polyp prevalence overall: " << std::endl;
	for (int i = 0; i < this->numberAnyPolyp.size(); ++ i) {
		std::cout << (double)numberAnyPolyp[i]/(double)(populationMales[i]+populationFemales[i])*100.0 << "%, ";
	}
	std::cout << std::endl;
	*/
}



void Output::saveResults(boost::property_tree::ptree *pt, bool full) {
   
   pt->put("population.males", arrayToString<unsigned long>(this->populationMales));
   pt->put("population.females", arrayToString<unsigned long>(this->populationFemales));
   
   pt->put("detectedCancers.males", arrayToString<unsigned long>(this->cancerMales));
   pt->put("detectedCancers.females", arrayToString<unsigned long>(this->cancerFemales));

   pt->put("totalDetectedCancers.count", arrayToString<unsigned long>(this->numberDetectedCancers));
   pt->put("cancerDeaths.total", to_string(this->deathCancer));

   pt->put("lifeyearslost.cancer", arrayToString<float>(this->lifeYearsLostCa));
   pt->put("lifeyearslost.colo", arrayToString<float>(this->lifeYearsLostColo));

	if (full) {
   		pt->put("peopleWithPolyps.males", arrayToString<unsigned long>(this->numberAnyPolypMales));
   		pt->put("peopleWithPolyps.females", arrayToString<unsigned long>(this->numberAnyPolypFemales));
   
   		pt->put("peopleWithAdvancedPolyps.males", arrayToString<unsigned long>(this->numberAdvancedPolypMales));
   		pt->put("peopleWithAdvancedPolyps.females", arrayToString<unsigned long>(this->numberAdvancedPolypFemales));
      
   		pt->put("numberColonoscopies.males", arrayToString<unsigned long>(this->numberColonoscopiesMale));
   		pt->put("numberColonoscopies.females", arrayToString<unsigned long>(this->numberColonoscopiesFemale));

  		pt->put("polypSumm.males", arrayToString<unsigned long>(this->polypsSummMale));
   		pt->put("polypSumm.females", arrayToString<unsigned long>(this->polypsSummFemale));
	}

   pt->put("costs.coloNoTumorAndNoPolypsTreat",arrayToString<unsigned long>(this->coloNoTumorAndNoPolypsTreat));
	pt->put("costs.coloTumorNoPolypsTreat",arrayToString<unsigned long>(this->coloTumorNoPolypsTreat));
	pt->put("costs.coloNoTumorAndPolypsTreat",arrayToString<unsigned long>(this->coloNoTumorAndPolypsTreat));

	pt->put("costs.numPerforationsTreat",arrayToString<unsigned long>(this->numPerforationsTreat));
	pt->put("costs.numSerosaTreat",arrayToString<unsigned long>(this->numSerosaTreat));
	pt->put("costs.numBleedingTreat",arrayToString<unsigned long>(this->numBleedingTreat));
	pt->put("costs.numBleedingTransfTreat",arrayToString<unsigned long>(this->numBleedingTransfTreat));

	
   pt->put("costs.coloNoTumorAndNoPolypsFollowup",arrayToString<unsigned long>(this->coloNoTumorAndNoPolypsFollowup));
	pt->put("costs.coloTumorNoPolypsFollowup",arrayToString<unsigned long>(this->coloTumorNoPolypsFollowup));
	pt->put("costs.coloNoTumorAndPolypsFollowup",arrayToString<unsigned long>(this->coloNoTumorAndPolypsFollowup));

	pt->put("costs.numPerforationsFollowup",arrayToString<unsigned long>(this->numPerforationsFollowup));
	pt->put("costs.numSerosaFollowup",arrayToString<unsigned long>(this->numSerosaFollowup));
	pt->put("costs.numBleedingFollowup",arrayToString<unsigned long>(this->numBleedingFollowup));
	pt->put("costs.numBleedingTransfFollowup",arrayToString<unsigned long>(this->numBleedingTransfFollowup));

	
   pt->put("costs.coloNoTumorAndNoPolypsScreen",arrayToString<unsigned long>(this->coloNoTumorAndNoPolypsScreen));
	pt->put("costs.coloTumorNoPolypsScreen",arrayToString<unsigned long>(this->coloTumorNoPolypsScreen));
	pt->put("costs.coloNoTumorAndPolypsScreen",arrayToString<unsigned long>(this->coloNoTumorAndPolypsScreen));

	pt->put("costs.numPerforationsScreen",arrayToString<unsigned long>(this->numPerforationsScreen));
	pt->put("costs.numSerosaScreen",arrayToString<unsigned long>(this->numSerosaScreen));
	pt->put("costs.numBleedingScreen",arrayToString<unsigned long>(this->numBleedingScreen));
	pt->put("costs.numBleedingTransfScreen",arrayToString<unsigned long>(this->numBleedingTransfScreen));

	pt->put("costs.StageIa",arrayToString<float>(this->stageICostContinous));
	pt->put("costs.StageIb",arrayToString<float>(this->stageICostInitial));
	pt->put("costs.StageIc",arrayToString<float>(this->stageICostFinal));
	pt->put("costs.StageId",arrayToString<float>(this->stageICostFinalOC));

	pt->put("costs.StageIIa",arrayToString<float>(this->stageIICostContinous));
	pt->put("costs.StageIIb",arrayToString<float>(this->stageIICostInitial));
	pt->put("costs.StageIIc",arrayToString<float>(this->stageIICostFinal));
	pt->put("costs.StageIId",arrayToString<float>(this->stageIICostFinalOC));

	pt->put("costs.StageIIIa",arrayToString<float>(this->stageIIICostContinous));
	pt->put("costs.StageIIIb",arrayToString<float>(this->stageIIICostInitial));
	pt->put("costs.StageIIIc",arrayToString<float>(this->stageIIICostFinal));
	pt->put("costs.StageIIId",arrayToString<float>(this->stageIIICostFinalOC));

	pt->put("costs.StageIVa",arrayToString<float>(this->stageIVCostContinous));
	pt->put("costs.StageIVb",arrayToString<float>(this->stageIVCostInitial));
	pt->put("costs.StageIVc",arrayToString<float>(this->stageIVCostFinal));
	pt->put("costs.StageIVd",arrayToString<float>(this->stageIVCostFinalOC));



}

void Output::saveResultsPt(string scenarioName, boost::property_tree::ptree *pt) {
	
   pt->put(scenarioName+".populationMales", arrayToString<unsigned long>(this->populationMales));
   pt->put(scenarioName+".populationFemales", arrayToString<unsigned long>(this->populationFemales));
   
   pt->put(scenarioName+".detectedCancersMales", arrayToString<unsigned long>(this->cancerMales));
   pt->put(scenarioName+".detectedCancersFemales", arrayToString<unsigned long>(this->cancerFemales));

   pt->put(scenarioName+".coloNoTumorAndNoPolypsTreat",arrayToString<unsigned long>(this->coloNoTumorAndNoPolypsTreat));
	pt->put(scenarioName+".coloTumorNoPolypsTreat",arrayToString<unsigned long>(this->coloTumorNoPolypsTreat));
	pt->put(scenarioName+".coloNoTumorAndPolypsTreat",arrayToString<unsigned long>(this->coloNoTumorAndPolypsTreat));

	pt->put(scenarioName+".numPerforationsTreat",arrayToString<unsigned long>(this->numPerforationsTreat));
	pt->put(scenarioName+".numSerosaTreat",arrayToString<unsigned long>(this->numSerosaTreat));
	pt->put(scenarioName+".numBleedingTreat",arrayToString<unsigned long>(this->numBleedingTreat));
	pt->put(scenarioName+".numBleedingTransfTreat",arrayToString<unsigned long>(this->numBleedingTransfTreat));

	pt->put(scenarioName+".coloNoTumorAndNoPolypsFollowup",arrayToString<unsigned long>(this->coloNoTumorAndNoPolypsFollowup));
	pt->put(scenarioName+".coloTumorNoPolypsFollowup",arrayToString<unsigned long>(this->coloTumorNoPolypsFollowup));
	pt->put(scenarioName+".coloNoTumorAndPolypsFollowup",arrayToString<unsigned long>(this->coloNoTumorAndPolypsFollowup));

	pt->put(scenarioName+".numPerforationsFollowup",arrayToString<unsigned long>(this->numPerforationsFollowup));
	pt->put(scenarioName+".numSerosaFollowup",arrayToString<unsigned long>(this->numSerosaFollowup));
	pt->put(scenarioName+".numBleedingFollowup",arrayToString<unsigned long>(this->numBleedingFollowup));
	pt->put(scenarioName+".numBleedingTransfFollowup",arrayToString<unsigned long>(this->numBleedingTransfFollowup));

	pt->put(scenarioName+".coloNoTumorAndNoPolypsScreen",arrayToString<unsigned long>(this->coloNoTumorAndNoPolypsScreen));
	pt->put(scenarioName+".coloTumorNoPolypsScreen",arrayToString<unsigned long>(this->coloTumorNoPolypsScreen));
	pt->put(scenarioName+".coloNoTumorAndPolypsScreen",arrayToString<unsigned long>(this->coloNoTumorAndPolypsScreen));

	pt->put(scenarioName+".numPerforationsScreen",arrayToString<unsigned long>(this->numPerforationsScreen));
	pt->put(scenarioName+".numSerosaScreen",arrayToString<unsigned long>(this->numSerosaScreen));
	pt->put(scenarioName+".numBleedingScreen",arrayToString<unsigned long>(this->numBleedingScreen));
	pt->put(scenarioName+".numBleedingTransfScreen",arrayToString<unsigned long>(this->numBleedingTransfScreen));

	pt->put(scenarioName+".StageIa",arrayToString<float>(this->stageICostContinous));
	pt->put(scenarioName+".StageIb",arrayToString<float>(this->stageICostInitial));
	pt->put(scenarioName+".StageIc",arrayToString<float>(this->stageICostFinal));
	pt->put(scenarioName+".StageId",arrayToString<float>(this->stageICostFinalOC));

	pt->put(scenarioName+".StageIIa",arrayToString<float>(this->stageIICostContinous));
	pt->put(scenarioName+".StageIIb",arrayToString<float>(this->stageIICostInitial));
	pt->put(scenarioName+".StageIIc",arrayToString<float>(this->stageIICostFinal));
	pt->put(scenarioName+".StageIId",arrayToString<float>(this->stageIICostFinalOC));

	pt->put(scenarioName+".StageIIIa",arrayToString<float>(this->stageIIICostContinous));
	pt->put(scenarioName+".StageIIIb",arrayToString<float>(this->stageIIICostInitial));
	pt->put(scenarioName+".StageIIIc",arrayToString<float>(this->stageIIICostFinal));
	pt->put(scenarioName+".StageIIId",arrayToString<float>(this->stageIIICostFinalOC));

	pt->put(scenarioName+".StageIVa",arrayToString<float>(this->stageIVCostContinous));
	pt->put(scenarioName+".StageIVb",arrayToString<float>(this->stageIVCostInitial));
	pt->put(scenarioName+".StageIVc",arrayToString<float>(this->stageIVCostFinal));
	pt->put(scenarioName+".StageIVd",arrayToString<float>(this->stageIVCostFinalOC));

	pt->put(scenarioName+".numberColonoscopiesMales", arrayToString<unsigned long>(this->numberColonoscopiesMale));
	pt->put(scenarioName+".numberColonoscopiesFemales", arrayToString<unsigned long>(this->numberColonoscopiesFemale));

}