/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * round.c
 *
 * Code generation for function 'round'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NumberCrunching_25000.h"
#include "round.h"

/* Function Definitions */
void b_round(real_T x[25])
{
  int32_T k;
  for (k = 0; k < 25; k++) {
    x[k] = muDoubleScalarRound(x[k]);
  }
}

/* End of code generation (round.c) */
