/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NumberCrunching_100000_types.h
 *
 * Code generation for function 'NumberCrunching_100000'
 *
 */

#ifndef __NUMBERCRUNCHING_100000_TYPES_H__
#define __NUMBERCRUNCHING_100000_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  real_T Polyps[5100000];
  real_T PolypYear[5100000];
  real_T PolypLocation[5100000];
  real_T AdvProgression[5100000];
  real_T EarlyProgression[5100000];
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct {
  real_T Cancer[2500000];
  real_T CancerYear[2500000];
  real_T CancerLocation[2500000];
  real_T TimeStage_I[2500000];
  real_T TimeStage_II[2500000];
  real_T TimeStage_III[2500000];
  real_T SympTime[2500000];
  real_T SympStage[2500000];
  real_T DwellTime[2500000];
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  real_T Cancer[5000000];
  real_T CancerYear[5000000];
  real_T CancerLocation[5000000];
  real_T MortTime[5000000];
} struct_T;

#endif                                 /*typedef_struct_T*/

#ifndef typedef_struct10_T
#define typedef_struct10_T

typedef struct {
  real_T FOBT[100];
  real_T I_FOBT[100];
  real_T Sept9_HighSens[100];
  real_T Sept9_HighSpec[100];
  real_T RS[100];
  real_T RSPolyp[100];
  real_T Colonoscopy[400];
  real_T ColonoscopyPolyp[400];
  real_T Colonoscopy_Cancer[400];
  real_T Perforation[400];
  real_T Serosa[400];
  real_T Bleeding[400];
  real_T BleedingTransf[400];
  real_T Cancer_ini[404];
  real_T Cancer_con[404];
  real_T Cancer_fin[404];
  real_T QCancer_ini[1616];
  real_T QCancer_con[8080];
  real_T QCancer_fin[1616];
  real_T Other[100];
} struct10_T;

#endif                                 /*typedef_struct10_T*/

#ifndef typedef_struct8_T
#define typedef_struct8_T

typedef struct {
  real_T Colonoscopy[100000];
  real_T Polyp[100000];
  real_T AdvPolyp[100000];
  real_T Cancer[100000];
  real_T ScreenTest[100000];
  real_T Included[100000];
  real_T TestDone[100000];
  real_T TestYear[100000];
  real_T TestYear2[100000];
} struct8_T;

#endif                                 /*typedef_struct8_T*/

#ifndef typedef_struct9_T
#define typedef_struct9_T

typedef struct {
  real_T Stage[1000000];
  real_T Location[1000000];
  real_T Sojourn[1000000];
  real_T DwellTime[1000000];
  real_T Gender[1000000];
  real_T Detection[1000000];
  real_T PatientNumber[1000000];
} struct9_T;

#endif                                 /*typedef_struct9_T*/

#ifndef typedef_NumberCrunching_100000StackData
#define typedef_NumberCrunching_100000StackData

typedef struct {
  union
  {
    struct {
      real_T SubCost[10100];
    } f0;

    struct {
      real_T SubCost[10100];
    } f1;
  } u1;

  struct {
    b_struct_T Polyp;
    c_struct_T Ca;
    struct_T Detected;
    real_T PolypRate[100000];
    real_T TmpLoc[13000];
    boolean_T Included[100000];
    boolean_T Alive[100000];
  } f2;

  struct {
    struct9_T TumorRecord;
    struct8_T Last;
    struct10_T PaymentType;
  } f3;
} NumberCrunching_100000StackData;

#endif                                 /*typedef_NumberCrunching_100000StackData*/

#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T Progression[10];
  real_T FastCancer[10];
  real_T Healing[10];
  real_T Symptoms[10];
  real_T Colo_Detection[10];
  real_T RectoSigmo_Detection[10];
  real_T Mortality[10];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct11_T
#define typedef_struct11_T

typedef struct {
  real_T AllCost[100];
  real_T AllCostFuture[100];
  real_T Treatment[100];
  real_T FutureTreatment[100];
  real_T Screening[100];
  real_T FollowUp[100];
  real_T Other[100];
} struct11_T;

#endif                                 /*typedef_struct11_T*/

#ifndef typedef_struct12_T
#define typedef_struct12_T

typedef struct {
  real_T Screening_Colonoscopy[100];
  real_T Symptoms_Colonoscopy[100];
  real_T Follow_Up_Colonoscopy[100];
  real_T Baseline_Colonoscopy[100];
  real_T RectoSigmo[100];
  real_T FOBT[100];
  real_T I_FOBT[100];
  real_T Sept9[100];
  real_T other[100];
} struct12_T;

#endif                                 /*typedef_struct12_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T NewPolyp[13];
  real_T DirectCa[13];
  real_T EarlyProgression[13];
  real_T AdvancedProgression[13];
  real_T CancerProgression[13];
  real_T CancerSymptoms[13];
  real_T ColoDetection[13];
  real_T RectoSigmoDetection[13];
  real_T ColoReach[13];
  real_T RectoSigmoReach[13];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  real_T Colonoscopy;
  real_T Colonoscopy_Polyp;
  real_T Colonoscopy_Cancer;
  real_T Sigmoidoscopy;
  real_T Sigmoidoscopy_Polyp;
  real_T Colonoscopy_Perforation;
  real_T Colonoscopy_Serosal_burn;
  real_T Colonoscopy_bleed;
  real_T Colonoscopy_bleed_transfusion;
  real_T FOBT;
  real_T I_FOBT;
  real_T Sept9_HighSens;
  real_T Sept9_HighSpec;
  real_T other;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T Initial[4];
  real_T Cont[4];
  real_T Final[4];
  real_T Final_oc[4];
  real_T FutInitial[4];
  real_T FutCont[4];
  real_T FutFinal[4];
  real_T FutFinal_oc[4];
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  real_T Colonoscopy_RiscPerforation;
  real_T Rectosigmo_Perforation;
  real_T Colonoscopy_RiscSerosaBurn;
  real_T c_Colonoscopy_RiscBleedingTrans;
  real_T Colonoscopy_RiscBleeding;
  real_T DeathPerforation;
  real_T DeathBleedingTransfusion;
} struct4_T;

#endif                                 /*typedef_struct4_T*/

#ifndef typedef_struct5_T
#define typedef_struct5_T

typedef struct {
  boolean_T Polyp_Surveillance;
  boolean_T Cancer_Surveillance;
  boolean_T SpecialFlag;
  boolean_T Screening;
  boolean_T Correlation;
  boolean_T Schoen;
  boolean_T Holme;
  boolean_T Segnan;
  boolean_T Atkin;
  boolean_T perfect;
  boolean_T Mock;
  boolean_T Kolo1;
  boolean_T Kolo2;
  boolean_T Kolo3;
  boolean_T Po55;
  boolean_T treated;
  boolean_T AllPolypFollowUp;
} struct5_T;

#endif                                 /*typedef_struct5_T*/

#ifndef typedef_struct6_T
#define typedef_struct6_T

typedef struct {
  real_T fraction_female;
  real_T new_polyp_female;
  real_T early_progression_female;
  real_T advanced_progression_female;
  real_T symptoms_female;
} struct6_T;

#endif                                 /*typedef_struct6_T*/

#ifndef typedef_struct7_T
#define typedef_struct7_T

typedef struct {
  real_T EarlyRisk[500];
  real_T AdvancedRisk[500];
} struct7_T;

#endif                                 /*typedef_struct7_T*/
#endif

/* End of code generation (NumberCrunching_100000_types.h) */
