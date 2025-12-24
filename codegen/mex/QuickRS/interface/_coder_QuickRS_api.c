/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_QuickRS_api.c
 *
 * Code generation for function '_coder_QuickRS_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "QuickRS.h"
#include "_coder_QuickRS_api.h"
#include "QuickRS_emxutil.h"
#include "QuickRS_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, 1, "_coder_QuickRS_api", "" };

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[100000];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *PatientNumber, const char_T *identifier))[1000000];
static const mxArray *c_emlrt_marshallOut(const real_T u[910]);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[1000000];
static const mxArray *d_emlrt_marshallOut(const real_T u);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n, const
  char_T *identifier);
static const mxArray *e_emlrt_marshallOut(const real_T u[10000000]);
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *DeathYear,
  const char_T *identifier))[100000];
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *f_emlrt_marshallOut(const real_T u[100]);
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[100000];
static const mxArray *g_emlrt_marshallOut(const emxArray_real_T *u);
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1000000];
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[100000]
{
  real_T (*y)[100000];
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *PatientNumber, const char_T *identifier))[1000000]
{
  real_T (*y)[1000000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(PatientNumber), &thisId);
  emlrtDestroyArray(&PatientNumber);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const real_T u[910])
{
  const mxArray *y;
  static const int32_T iv1[2] = { 0, 0 };

  const mxArray *m2;
  static const int32_T iv2[2] = { 70, 13 };

  y = NULL;
  m2 = emlrtCreateNumericArray(2, iv1, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m2, (void *)u);
  emlrtSetDimensions((mxArray *)m2, iv2, 2);
  emlrtAssign(&y, m2);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[1000000]
{
  real_T (*y)[1000000];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *d_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m3;
  y = NULL;
  m3 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m3);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(n), &thisId);
  emlrtDestroyArray(&n);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const real_T u[10000000])
{
  const mxArray *y;
  static const int32_T iv3[2] = { 0, 0 };

  const mxArray *m4;
  static const int32_T iv4[2] = { 100000, 100 };

  y = NULL;
  m4 = emlrtCreateNumericArray(2, iv3, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m4, (void *)u);
  emlrtSetDimensions((mxArray *)m4, iv4, 2);
  emlrtAssign(&y, m4);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *DeathYear,
  const char_T *identifier))[100000]
{
  real_T (*y)[100000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(DeathYear), &thisId);
  emlrtDestroyArray(&DeathYear);
  return y;
}
  static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *f_emlrt_marshallOut(const real_T u[100])
{
  const mxArray *y;
  static const int32_T iv5[2] = { 0, 0 };

  const mxArray *m5;
  static const int32_T iv6[2] = { 1, 100 };

  y = NULL;
  m5 = emlrtCreateNumericArray(2, iv5, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m5, (void *)u);
  emlrtSetDimensions((mxArray *)m5, iv6, 2);
  emlrtAssign(&y, m5);
  return y;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[100000]
{
  real_T (*ret)[100000];
  static const int32_T dims[2] = { 1, 100000 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[100000])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static const mxArray *g_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv7[2] = { 0, 0 };

  const mxArray *m6;
  y = NULL;
  m6 = emlrtCreateNumericArray(2, iv7, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m6, (void *)u->data);
  emlrtSetDimensions((mxArray *)m6, u->size, 2);
  emlrtAssign(&y, m6);
  return y;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1000000]
{
  real_T (*ret)[1000000];
  static const int32_T dims[2] = { 100, 10000 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[1000000])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void QuickRS_api(const mxArray * const prhs[6], const mxArray *plhs[6])
{
  real_T (*Tumor)[910];
  real_T (*SurvivalMatrix)[10000000];
  real_T (*CancerMortality)[100];
  real_T (*PatientsAtRisk)[100];
  emxArray_real_T *Survival;
  real_T (*DeathYear)[100000];
  real_T (*Included)[100000];
  real_T (*PatientNumber)[1000000];
  real_T (*Location)[1000000];
  real_T (*DeathCause)[100000];
  real_T n;
  real_T Counter;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  Tumor = (real_T (*)[910])mxMalloc(sizeof(real_T [910]));
  SurvivalMatrix = (real_T (*)[10000000])mxMalloc(sizeof(real_T [10000000]));
  CancerMortality = (real_T (*)[100])mxMalloc(sizeof(real_T [100]));
  PatientsAtRisk = (real_T (*)[100])mxMalloc(sizeof(real_T [100]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Survival, 2, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  DeathYear = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "DeathYear");
  Included = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Included");
  PatientNumber = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "PatientNumber");
  Location = c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Location");
  DeathCause = emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "DeathCause");
  n = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "n");

  /* Invoke the target function */
  QuickRS(&st, *DeathYear, *Included, *PatientNumber, *Location, *DeathCause, n,
          *Tumor, &Counter, *SurvivalMatrix, *CancerMortality, Survival,
          *PatientsAtRisk);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(*Tumor);
  plhs[1] = d_emlrt_marshallOut(Counter);
  plhs[2] = e_emlrt_marshallOut(*SurvivalMatrix);
  plhs[3] = f_emlrt_marshallOut(*CancerMortality);
  plhs[4] = g_emlrt_marshallOut(Survival);
  plhs[5] = f_emlrt_marshallOut(*PatientsAtRisk);
  Survival->canFreeData = false;
  emxFree_real_T(&Survival);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_QuickRS_api.c) */
