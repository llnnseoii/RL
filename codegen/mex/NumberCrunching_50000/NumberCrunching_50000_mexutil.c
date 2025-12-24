/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NumberCrunching_50000_mexutil.c
 *
 * Code generation for function 'NumberCrunching_50000_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NumberCrunching_50000.h"
#include "NumberCrunching_50000_mexutil.h"

/* Function Definitions */
const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m1);
  return y;
}

/* End of code generation (NumberCrunching_50000_mexutil.c) */
