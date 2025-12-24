/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * QuickRS.h
 *
 * Code generation for function 'QuickRS'
 *
 */

#ifndef __QUICKRS_H__
#define __QUICKRS_H__

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
#include "QuickRS_types.h"

/* Function Declarations */
extern void QuickRS(const emlrtStack *sp, const real_T DeathYear[100000], const
                    real_T Included[100000], const real_T PatientNumber[1000000],
                    const real_T Location[1000000], const real_T DeathCause
                    [100000], real_T n, real_T Tumor[910], real_T *Counter,
                    real_T SurvivalMatrix[10000000], real_T CancerMortality[100],
                    emxArray_real_T *Survival, real_T PatientsAtRisk[100]);

#endif

/* End of code generation (QuickRS.h) */
