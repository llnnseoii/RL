/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NumberCrunching_25000.h
 *
 * Code generation for function 'NumberCrunching_25000'
 *
 */

#ifndef __NUMBERCRUNCHING_25000_H__
#define __NUMBERCRUNCHING_25000_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "NumberCrunching_25000_types.h"

/* Function Declarations */
extern void NumberCrunching_25000(NumberCrunching_25000StackData *SD, const
  emlrtStack *sp, real_T p, const struct0_T *StageVariables, const struct1_T
  *Location, const struct2_T *Cost, const struct3_T *CostStage, const struct4_T *
  risc, const struct5_T *flag, const char_T SpecialText[25], const struct6_T
  *female, const real_T Sensitivity[70], const real_T ScreeningTest[56], real_T
  ScreeningPreference[25000], const real_T AgeProgression[900], const real_T
  NewPolyp[150], const real_T ColonoscopyLikelyhood[150], const real_T
  IndividualRisk[25000], const struct7_T *RiskDistribution, const real_T Gender
  [25000], const real_T LifeTable[302], const real_T MortalityMatrix[400000],
  real_T LocationMatrix[2000], const real_T StageDuration[16], const real_T tx1
  [100], const real_T DirectCancerRate[300], real_T DirectCancerSpeed, const
  char_T DwellSpeed[4], real_T *y, real_T DeathCause[25000], struct8_T *Last,
  real_T DeathYear[25000], real_T NaturalDeathYear[25000], real_T DirectCancer
  [500], real_T DirectCancerR[100], real_T DirectCancer2[100], real_T
  DirectCancer2R[100], real_T ProgressedCancer[100], real_T ProgressedCancerR
  [100], struct9_T *TumorRecord, real_T DwellTimeProgression[250000], real_T
  DwellTimeFastCancer[250000], real_T HasCancer[2500000], real_T NumPolyps
  [2500000], real_T MaxPolyps[2500000], real_T AllPolyps[600], real_T NumCancer
  [2500000], real_T MaxCancer[2500000], struct10_T *PaymentType, struct11_T
  *Money, struct12_T *Number, real_T EarlyPolypsRemoved[100], real_T
  DiagnosedCancer[2500000], real_T AdvancedPolypsRemoved[100], boolean_T
  YearIncluded[2500000], boolean_T YearAlive[2500000]);

#endif

/* End of code generation (NumberCrunching_25000.h) */
