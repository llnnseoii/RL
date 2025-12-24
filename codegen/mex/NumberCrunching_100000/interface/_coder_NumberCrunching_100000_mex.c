/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_NumberCrunching_100000_mex.c
 *
 * Code generation for function '_coder_NumberCrunching_100000_mex'
 *
 */

/* Include files */
#include "NumberCrunching_100000.h"
#include "_coder_NumberCrunching_100000_mex.h"
#include "NumberCrunching_100000_terminate.h"
#include "_coder_NumberCrunching_100000_api.h"
#include "NumberCrunching_100000_initialize.h"
#include "NumberCrunching_100000_data.h"

/* Variable Definitions */
static NumberCrunching_100000StackData *b_NumberCrunching_100000StackDa = NULL;

/* Function Declarations */
static void c_NumberCrunching_100000_mexFun(NumberCrunching_100000StackData *SD,
  int32_T nlhs, mxArray *plhs[29], int32_T nrhs, const mxArray *prhs[26]);

/* Function Definitions */
static void c_NumberCrunching_100000_mexFun(NumberCrunching_100000StackData *SD,
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
                        22, "NumberCrunching_100000");
  }

  if (nlhs > 29) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 22,
                        "NumberCrunching_100000");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  NumberCrunching_100000_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  NumberCrunching_100000_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  b_NumberCrunching_100000StackDa = (NumberCrunching_100000StackData *)mxCalloc
    (1, 1U * sizeof(NumberCrunching_100000StackData));
  mexAtExit(NumberCrunching_100000_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  NumberCrunching_100000_initialize();

  /* Dispatch the entry-point. */
  c_NumberCrunching_100000_mexFun(b_NumberCrunching_100000StackDa, nlhs, plhs,
    nrhs, prhs);
  mxFree(b_NumberCrunching_100000StackDa);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_NumberCrunching_100000_mex.c) */
