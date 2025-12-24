/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.h
 *
 * Code generation for function 'sum'
 *
 */

#ifndef __SUM_H__
#define __SUM_H__

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
#include "NumberCrunching_10000_types.h"

/* Function Declarations */
extern real_T b_sum(const emlrtStack *sp, const real_T x_data[], const int32_T
                    x_size[2]);

#ifdef __WATCOMC__

#pragma aux b_sum value [8087];

#endif

extern real_T c_sum(const real_T x[13]);

#ifdef __WATCOMC__

#pragma aux c_sum value [8087];

#endif

extern real_T d_sum(const real_T x[25]);

#ifdef __WATCOMC__

#pragma aux d_sum value [8087];

#endif

extern real_T e_sum(const real_T x_data[], const int32_T x_size[1]);

#ifdef __WATCOMC__

#pragma aux e_sum value [8087];

#endif

extern real_T f_sum(const boolean_T x[10000]);

#ifdef __WATCOMC__

#pragma aux f_sum value [8087];

#endif

extern real_T g_sum(const real_T x[50]);

#ifdef __WATCOMC__

#pragma aux g_sum value [8087];

#endif

extern void h_sum(const real_T x[10100], real_T y[404]);
extern real_T i_sum(const real_T x[3]);

#ifdef __WATCOMC__

#pragma aux i_sum value [8087];

#endif

extern void sum(const real_T x[13000], real_T y[1000]);

#endif

/* End of code generation (sum.h) */
