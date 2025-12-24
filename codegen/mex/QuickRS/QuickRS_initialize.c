/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * QuickRS_initialize.c
 *
 * Code generation for function 'QuickRS_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "QuickRS.h"
#include "QuickRS_initialize.h"
#include "_coder_QuickRS_mex.h"
#include "QuickRS_data.h"

/* Function Definitions */
void QuickRS_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (QuickRS_initialize.c) */
