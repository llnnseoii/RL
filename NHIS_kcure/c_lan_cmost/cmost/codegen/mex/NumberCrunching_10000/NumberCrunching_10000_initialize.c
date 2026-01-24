/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NumberCrunching_10000_initialize.c
 *
 * Code generation for function 'NumberCrunching_10000_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NumberCrunching_10000.h"
#include "NumberCrunching_10000_initialize.h"
#include "_coder_NumberCrunching_10000_mex.h"
#include "NumberCrunching_10000_data.h"

/* Function Definitions */
void NumberCrunching_10000_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (NumberCrunching_10000_initialize.c) */
