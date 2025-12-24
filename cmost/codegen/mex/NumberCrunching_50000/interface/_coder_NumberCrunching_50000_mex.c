/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_NumberCrunching_50000_mex.c
 *
 * Code generation for function '_coder_NumberCrunching_50000_mex'
 *
 */

/* Include files */
#include "NumberCrunching_50000.h"
#include "_coder_NumberCrunching_50000_mex.h"
#include "NumberCrunching_50000_terminate.h"
#include "_coder_NumberCrunching_50000_api.h"
#include "NumberCrunching_50000_initialize.h"
#include "NumberCrunching_50000_data.h"

/* Variable Definitions */
static NumberCrunching_50000StackData *c_NumberCrunching_50000StackDat = NULL;

/* Function Declarations */
static void c_NumberCrunching_50000_mexFunc(NumberCrunching_50000StackData *SD,
  int32_T nlhs, mxArray *plhs[29], int32_T nrhs, const mxArray *prhs[26]);

/* Function Definitions */
static void c_NumberCrunching_50000_mexFunc(NumberCrunching_50000StackData *SD,
  int32_T nlhs, mxArray *plhs[29], int32_T nrhs, const mxArray *prhs[26])
{
  int32_T n;
  const mxArray *inputs[26];
  const mxArray *outputs[29];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 26) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 26, 4,
                        21, "NumberCrunching_50000");
  }

  if (nlhs > 29) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "NumberCrunching_50000");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  NumberCrunching_50000_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  NumberCrunching_50000_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  c_NumberCrunching_50000StackDat = (NumberCrunching_50000StackData *)mxCalloc(1,
    1U * sizeof(NumberCrunching_50000StackData));
  mexAtExit(NumberCrunching_50000_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  NumberCrunching_50000_initialize();

  /* Dispatch the entry-point. */
  c_NumberCrunching_50000_mexFunc(c_NumberCrunching_50000StackDat, nlhs, plhs,
    nrhs, prhs);
  mxFree(c_NumberCrunching_50000StackDat);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_NumberCrunching_50000_mex.c) */
