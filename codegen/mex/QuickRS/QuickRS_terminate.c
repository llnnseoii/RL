/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * QuickRS_terminate.c
 *
 * Code generation for function 'QuickRS_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "QuickRS.h"
#include "QuickRS_terminate.h"
#include "_coder_QuickRS_mex.h"
#include "QuickRS_data.h"

/* Function Definitions */
void QuickRS_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void QuickRS_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (QuickRS_terminate.c) */
