/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NumberCrunching_10000.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = { 13, "sum",
  "C:\\Program Files\\MATLAB\\R2015b_x64\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 19, 15, "sumprod",
  "C:\\Program Files\\MATLAB\\R2015b_x64\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"
};

/* Function Definitions */
real_T b_sum(const emlrtStack *sp, const real_T x_data[], const int32_T x_size[2])
{
  real_T y;
  boolean_T b0;
  int32_T k;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jc_emlrtRSI;
  if ((x_size[1] == 1) || (x_size[1] != 1)) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (b0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &b_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  y = x_data[0];
  for (k = 2; k <= x_size[1]; k++) {
    y += x_data[k - 1];
  }

  return y;
}

real_T c_sum(const real_T x[13])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 12; k++) {
    y += x[k + 1];
  }

  return y;
}

real_T d_sum(const real_T x[25])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 24; k++) {
    y += x[k + 1];
  }

  return y;
}

real_T e_sum(const real_T x_data[], const int32_T x_size[1])
{
  real_T y;
  int32_T k;
  y = x_data[0];
  for (k = 2; k <= x_size[0]; k++) {
    y += x_data[k - 1];
  }

  return y;
}

real_T f_sum(const boolean_T x[10000])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 9999; k++) {
    y += (real_T)x[k + 1];
  }

  return y;
}

real_T g_sum(const real_T x[50])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 49; k++) {
    y += x[k + 1];
  }

  return y;
}

void h_sum(const real_T x[10100], real_T y[404])
{
  int32_T ix;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  real_T s;
  ix = -1;
  iy = -1;
  for (i = 0; i < 404; i++) {
    ixstart = ix + 1;
    ix++;
    s = x[ixstart];
    for (ixstart = 0; ixstart < 24; ixstart++) {
      ix++;
      s += x[ix];
    }

    iy++;
    y[iy] = s;
  }
}

real_T i_sum(const real_T x[3])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 2; k++) {
    y += x[k + 1];
  }

  return y;
}

void sum(const real_T x[13000], real_T y[1000])
{
  int32_T ix;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  real_T s;
  ix = -1;
  iy = -1;
  for (i = 0; i < 1000; i++) {
    ixstart = ix + 1;
    ix++;
    s = x[ixstart];
    for (ixstart = 0; ixstart < 12; ixstart++) {
      ix++;
      s += x[ix];
    }

    iy++;
    y[iy] = s;
  }
}

/* End of code generation (sum.c) */
