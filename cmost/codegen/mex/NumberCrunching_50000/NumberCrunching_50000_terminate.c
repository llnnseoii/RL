/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NumberCrunching_50000_terminate.c
 *
 * Code generation for function 'NumberCrunching_50000_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NumberCrunching_50000.h"
#include "NumberCrunching_50000_terminate.h"
#include "_coder_NumberCrunching_50000_mex.h"
#include "NumberCrunching_50000_data.h"

/* Function Definitions */
void NumberCrunching_50000_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void NumberCrunching_50000_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (NumberCrunching_50000_terminate.c) */
