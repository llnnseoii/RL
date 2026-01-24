/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_NumberCrunching_10000_api.c
 *
 * Code generation for function '_coder_NumberCrunching_10000_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NumberCrunching_10000.h"
#include "_coder_NumberCrunching_10000_api.h"
#include "NumberCrunching_10000_mexutil.h"
#include "NumberCrunching_10000_data.h"

/* Function Declarations */
static real_T (*ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[56];
static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10]);
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *ScreeningPreference, const char_T *identifier))[10000];
static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[13]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *StageVariables, const char_T *identifier, struct0_T *y);
static real_T (*cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[10000];
static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static real_T (*db_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *AgeProgression, const char_T *identifier))[900];
static boolean_T dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[10]);
static void e_emlrt_marshallOut(const real_T u[10000], const mxArray *y);
static real_T (*eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[900];
static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[25]);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *p, const
  char_T *identifier);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Location,
  const char_T *identifier, struct1_T *y);
static const mxArray *f_emlrt_marshallOut(const real_T u[10000]);
static real_T (*fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *NewPolyp, const char_T *identifier))[150];
static real_T (*fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[70];
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static const mxArray *g_emlrt_marshallOut(const struct8_T *u);
static real_T (*gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[150];
static real_T (*gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[56];
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[13]);
static const mxArray *h_emlrt_marshallOut(const real_T u[500]);
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *RiskDistribution, const char_T *identifier, struct7_T *y);
static real_T (*hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[10000];
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Cost, const
  char_T *identifier, struct2_T *y);
static const mxArray *i_emlrt_marshallOut(const real_T u[100]);
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct7_T *y);
static real_T (*ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[900];
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static const mxArray *j_emlrt_marshallOut(const struct9_T *u);
static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[500]);
static real_T (*jc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[150];
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *CostStage,
  const char_T *identifier, struct3_T *y);
static const mxArray *k_emlrt_marshallOut(const real_T u[100000]);
static real_T (*kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *LifeTable, const char_T *identifier))[302];
static void kc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[500]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static const mxArray *l_emlrt_marshallOut(const real_T u[1000000]);
static real_T (*lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[302];
static real_T (*lc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[302];
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static const mxArray *m_emlrt_marshallOut(const real_T u[600]);
static real_T (*mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *MortalityMatrix, const char_T *identifier))[400000];
static real_T (*mc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[400000];
static struct4_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *risc,
  const char_T *identifier);
static const mxArray *n_emlrt_marshallOut(const struct10_T *u);
static real_T (*nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[400000];
static real_T (*nc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2000];
static struct4_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static const mxArray *o_emlrt_marshallOut(const struct11_T *u);
static real_T (*ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *LocationMatrix, const char_T *identifier))[2000];
static real_T (*oc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[16];
static struct5_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *flag,
  const char_T *identifier);
static const mxArray *p_emlrt_marshallOut(const struct12_T *u);
static real_T (*pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2000];
static real_T (*pc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[100];
static struct5_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static const mxArray *q_emlrt_marshallOut(const boolean_T u[1000000]);
static real_T (*qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *StageDuration, const char_T *identifier))[16];
static real_T (*qc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[300];
static boolean_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static real_T (*rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[16];
static void rc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[4]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *SpecialText,
  const char_T *identifier, char_T y[25]);
static real_T (*sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tx1,
  const char_T *identifier))[100];
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[25]);
static real_T (*tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[100];
static struct6_T u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *female,
  const char_T *identifier);
static real_T (*ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *DirectCancerRate, const char_T *identifier))[300];
static struct6_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static real_T (*vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[300];
static real_T (*w_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *Sensitivity, const char_T *identifier))[70];
static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DwellSpeed,
  const char_T *identifier, char_T y[4]);
static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[70];
static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[4]);
static real_T (*y_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *ScreeningTest, const char_T *identifier))[56];
static real_T yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T (*ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[56]
{
  real_T (*y)[56];
  y = gc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, real_T ret[10])
{
  static const int32_T dims[2] = { 1, 10 };

  int32_T i0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i0 = 0; i0 < 10; i0++) {
    ret[i0] = (*(real_T (*)[10])mxGetData(src))[i0];
  }

  emlrtDestroyArray(&src);
}

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = yb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *ScreeningPreference, const char_T *identifier))[10000]
{
  real_T (*y)[10000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = cb_emlrt_marshallIn(sp, emlrtAlias(ScreeningPreference), &thisId);
  emlrtDestroyArray(&ScreeningPreference);
  return y;
}
  static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, real_T ret[13])
{
  static const int32_T dims[2] = { 1, 13 };

  int32_T i1;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i1 = 0; i1 < 13; i1++) {
    ret[i1] = (*(real_T (*)[13])mxGetData(src))[i1];
  }

  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *StageVariables, const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(StageVariables), &thisId, y);
  emlrtDestroyArray(&StageVariables);
}

static real_T (*cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[10000]
{
  real_T (*y)[10000];
  y = hc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 1, 4 };

  int32_T i2;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i2 = 0; i2 < 4; i2++) {
    ret[i2] = (*(real_T (*)[4])mxGetData(src))[i2];
  }

  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[7] = { "Progression", "FastCancer", "Healing",
    "Symptoms", "Colo_Detection", "RectoSigmo_Detection", "Mortality" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 7, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Progression";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Progression")),
                     &thisId, y->Progression);
  thisId.fIdentifier = "FastCancer";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "FastCancer")),
                     &thisId, y->FastCancer);
  thisId.fIdentifier = "Healing";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Healing")),
                     &thisId, y->Healing);
  thisId.fIdentifier = "Symptoms";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Symptoms")),
                     &thisId, y->Symptoms);
  thisId.fIdentifier = "Colo_Detection";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Colo_Detection")), &thisId, y->Colo_Detection);
  thisId.fIdentifier = "RectoSigmo_Detection";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "RectoSigmo_Detection")), &thisId, y->RectoSigmo_Detection);
  thisId.fIdentifier = "Mortality";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Mortality")),
                     &thisId, y->Mortality);
  emlrtDestroyArray(&u);
}

static real_T (*db_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *AgeProgression, const char_T *identifier))[900]
{
  real_T (*y)[900];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = eb_emlrt_marshallIn(sp, emlrtAlias(AgeProgression), &thisId);
  emlrtDestroyArray(&AgeProgression);
  return y;
}
  static boolean_T dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *mxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[10])
{
  ac_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallOut(const real_T u[10000], const mxArray *y)
{
  static const int32_T iv1[2] = { 1, 10000 };

  mxSetData((mxArray *)y, (void *)u);
  emlrtSetDimensions((mxArray *)y, iv1, 2);
}

static real_T (*eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[900]
{
  real_T (*y)[900];
  y = ic_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, char_T ret[25])
{
  static const int32_T dims[2] = { 1, 25 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, ret, 25);
  emlrtDestroyArray(&src);
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *p, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(p), &thisId);
  emlrtDestroyArray(&p);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Location,
  const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  g_emlrt_marshallIn(sp, emlrtAlias(Location), &thisId, y);
  emlrtDestroyArray(&Location);
}

static const mxArray *f_emlrt_marshallOut(const real_T u[10000])
{
  const mxArray *y;
  static const int32_T iv2[2] = { 0, 0 };

  const mxArray *m4;
  static const int32_T iv3[2] = { 1, 10000 };

  y = NULL;
  m4 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m4, (void *)u);
  emlrtSetDimensions((mxArray *)m4, iv3, 2);
  emlrtAssign(&y, m4);
  return y;
}

static real_T (*fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *NewPolyp, const char_T *identifier))[150]
{
  real_T (*y)[150];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = gb_emlrt_marshallIn(sp, emlrtAlias(NewPolyp), &thisId);
  emlrtDestroyArray(&NewPolyp);
  return y;
}
  static real_T (*fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[70]
{
  real_T (*ret)[70];
  static const int32_T dims[2] = { 7, 10 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[70])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[10] = { "NewPolyp", "DirectCa",
    "EarlyProgression", "AdvancedProgression", "CancerProgression",
    "CancerSymptoms", "ColoDetection", "RectoSigmoDetection", "ColoReach",
    "RectoSigmoReach" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 10, fieldNames, 0U, &dims);
  thisId.fIdentifier = "NewPolyp";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "NewPolyp")),
                     &thisId, y->NewPolyp);
  thisId.fIdentifier = "DirectCa";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "DirectCa")),
                     &thisId, y->DirectCa);
  thisId.fIdentifier = "EarlyProgression";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "EarlyProgression")), &thisId, y->EarlyProgression);
  thisId.fIdentifier = "AdvancedProgression";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "AdvancedProgression")), &thisId, y->AdvancedProgression);
  thisId.fIdentifier = "CancerProgression";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "CancerProgression")), &thisId, y->CancerProgression);
  thisId.fIdentifier = "CancerSymptoms";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "CancerSymptoms")), &thisId, y->CancerSymptoms);
  thisId.fIdentifier = "ColoDetection";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "ColoDetection")), &thisId, y->ColoDetection);
  thisId.fIdentifier = "RectoSigmoDetection";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "RectoSigmoDetection")), &thisId, y->RectoSigmoDetection);
  thisId.fIdentifier = "ColoReach";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "ColoReach")),
                     &thisId, y->ColoReach);
  thisId.fIdentifier = "RectoSigmoReach";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "RectoSigmoReach")), &thisId, y->RectoSigmoReach);
  emlrtDestroyArray(&u);
}

static const mxArray *g_emlrt_marshallOut(const struct8_T *u)
{
  const mxArray *y;
  const mxArray *b_y;
  static const int32_T iv4[2] = { 1, 10000 };

  const mxArray *m5;
  real_T *pData;
  int32_T i;
  const mxArray *c_y;
  static const int32_T iv5[2] = { 1, 10000 };

  const mxArray *d_y;
  static const int32_T iv6[2] = { 1, 10000 };

  const mxArray *e_y;
  static const int32_T iv7[2] = { 1, 10000 };

  const mxArray *f_y;
  static const int32_T iv8[2] = { 1, 10000 };

  const mxArray *g_y;
  static const int32_T iv9[2] = { 1, 10000 };

  const mxArray *h_y;
  static const int32_T iv10[2] = { 1, 10000 };

  const mxArray *i_y;
  static const int32_T iv11[2] = { 1, 10000 };

  const mxArray *j_y;
  static const int32_T iv12[2] = { 1, 10000 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  m5 = emlrtCreateNumericArray(2, iv4, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m5);
  for (i = 0; i < 10000; i++) {
    pData[i] = u->Colonoscopy[i];
  }

  emlrtAssign(&b_y, m5);
  emlrtAddField(y, b_y, "Colonoscopy", 0);
  c_y = NULL;
  m5 = emlrtCreateNumericArray(2, iv5, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m5);
  for (i = 0; i < 10000; i++) {
    pData[i] = u->Polyp[i];
  }

  emlrtAssign(&c_y, m5);
  emlrtAddField(y, c_y, "Polyp", 0);
  d_y = NULL;
  m5 = emlrtCreateNumericArray(2, iv6, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m5);
  for (i = 0; i < 10000; i++) {
    pData[i] = u->AdvPolyp[i];
  }

  emlrtAssign(&d_y, m5);
  emlrtAddField(y, d_y, "AdvPolyp", 0);
  e_y = NULL;
  m5 = emlrtCreateNumericArray(2, iv7, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m5);
  for (i = 0; i < 10000; i++) {
    pData[i] = u->Cancer[i];
  }

  emlrtAssign(&e_y, m5);
  emlrtAddField(y, e_y, "Cancer", 0);
  f_y = NULL;
  m5 = emlrtCreateNumericArray(2, iv8, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m5);
  for (i = 0; i < 10000; i++) {
    pData[i] = u->ScreenTest[i];
  }

  emlrtAssign(&f_y, m5);
  emlrtAddField(y, f_y, "ScreenTest", 0);
  g_y = NULL;
  m5 = emlrtCreateNumericArray(2, iv9, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m5);
  for (i = 0; i < 10000; i++) {
    pData[i] = u->Included[i];
  }

  emlrtAssign(&g_y, m5);
  emlrtAddField(y, g_y, "Included", 0);
  h_y = NULL;
  m5 = emlrtCreateNumericArray(2, iv10, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m5);
  for (i = 0; i < 10000; i++) {
    pData[i] = u->TestDone[i];
  }

  emlrtAssign(&h_y, m5);
  emlrtAddField(y, h_y, "TestDone", 0);
  i_y = NULL;
  m5 = emlrtCreateNumericArray(2, iv11, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m5);
  for (i = 0; i < 10000; i++) {
    pData[i] = u->TestYear[i];
  }

  emlrtAssign(&i_y, m5);
  emlrtAddField(y, i_y, "TestYear", 0);
  j_y = NULL;
  m5 = emlrtCreateNumericArray(2, iv12, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m5);
  for (i = 0; i < 10000; i++) {
    pData[i] = u->TestYear2[i];
  }

  emlrtAssign(&j_y, m5);
  emlrtAddField(y, j_y, "TestYear2", 0);
  return y;
}

static real_T (*gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[150]
{
  real_T (*y)[150];
  y = jc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[56]
{
  real_T (*ret)[56];
  static const int32_T dims[2] = { 7, 8 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[56])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[13])
{
  bc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *h_emlrt_marshallOut(const real_T u[500])
{
  const mxArray *y;
  static const int32_T iv13[2] = { 0, 0 };

  const mxArray *m6;
  static const int32_T iv14[2] = { 5, 100 };

  y = NULL;
  m6 = emlrtCreateNumericArray(2, iv13, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m6, (void *)u);
  emlrtSetDimensions((mxArray *)m6, iv14, 2);
  emlrtAssign(&y, m6);
  return y;
}

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *RiskDistribution, const char_T *identifier, struct7_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  ib_emlrt_marshallIn(sp, emlrtAlias(RiskDistribution), &thisId, y);
  emlrtDestroyArray(&RiskDistribution);
}

static real_T (*hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[10000]
{
  real_T (*ret)[10000];
  static const int32_T dims[2] = { 1, 10000 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[10000])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Cost,
  const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(Cost), &thisId, y);
  emlrtDestroyArray(&Cost);
}

static const mxArray *i_emlrt_marshallOut(const real_T u[100])
{
  const mxArray *y;
  static const int32_T iv15[2] = { 0, 0 };

  const mxArray *m7;
  static const int32_T iv16[2] = { 1, 100 };

  y = NULL;
  m7 = emlrtCreateNumericArray(2, iv15, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m7, (void *)u);
  emlrtSetDimensions((mxArray *)m7, iv16, 2);
  emlrtAssign(&y, m7);
  return y;
}

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct7_T *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[2] = { "EarlyRisk", "AdvancedRisk" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, &dims);
  thisId.fIdentifier = "EarlyRisk";
  jb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "EarlyRisk")),
                      &thisId, y->EarlyRisk);
  thisId.fIdentifier = "AdvancedRisk";
  jb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "AdvancedRisk")), &thisId, y->AdvancedRisk);
  emlrtDestroyArray(&u);
}

static real_T (*ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[900]
{
  real_T (*ret)[900];
  static const int32_T dims[2] = { 6, 150 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[900])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[14] = { "Colonoscopy", "Colonoscopy_Polyp",
    "Colonoscopy_Cancer", "Sigmoidoscopy", "Sigmoidoscopy_Polyp",
    "Colonoscopy_Perforation", "Colonoscopy_Serosal_burn", "Colonoscopy_bleed",
    "Colonoscopy_bleed_transfusion", "FOBT", "I_FOBT", "Sept9_HighSens",
    "Sept9_HighSpec", "other" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 14, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Colonoscopy";
  y->Colonoscopy = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "Colonoscopy")), &thisId);
  thisId.fIdentifier = "Colonoscopy_Polyp";
  y->Colonoscopy_Polyp = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a
    (sp, u, 0, "Colonoscopy_Polyp")), &thisId);
  thisId.fIdentifier = "Colonoscopy_Cancer";
  y->Colonoscopy_Cancer = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a
    (sp, u, 0, "Colonoscopy_Cancer")), &thisId);
  thisId.fIdentifier = "Sigmoidoscopy";
  y->Sigmoidoscopy = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "Sigmoidoscopy")), &thisId);
  thisId.fIdentifier = "Sigmoidoscopy_Polyp";
  y->Sigmoidoscopy_Polyp = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a
    (sp, u, 0, "Sigmoidoscopy_Polyp")), &thisId);
  thisId.fIdentifier = "Colonoscopy_Perforation";
  y->Colonoscopy_Perforation = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "Colonoscopy_Perforation")), &thisId);
  thisId.fIdentifier = "Colonoscopy_Serosal_burn";
  y->Colonoscopy_Serosal_burn = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "Colonoscopy_Serosal_burn")), &thisId);
  thisId.fIdentifier = "Colonoscopy_bleed";
  y->Colonoscopy_bleed = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a
    (sp, u, 0, "Colonoscopy_bleed")), &thisId);
  thisId.fIdentifier = "Colonoscopy_bleed_transfusion";
  y->Colonoscopy_bleed_transfusion = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "Colonoscopy_bleed_transfusion")), &thisId);
  thisId.fIdentifier = "FOBT";
  y->FOBT = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "FOBT")), &thisId);
  thisId.fIdentifier = "I_FOBT";
  y->I_FOBT = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "I_FOBT")), &thisId);
  thisId.fIdentifier = "Sept9_HighSens";
  y->Sept9_HighSens = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "Sept9_HighSens")), &thisId);
  thisId.fIdentifier = "Sept9_HighSpec";
  y->Sept9_HighSpec = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "Sept9_HighSpec")), &thisId);
  thisId.fIdentifier = "other";
  y->other = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "other")), &thisId);
  emlrtDestroyArray(&u);
}

static const mxArray *j_emlrt_marshallOut(const struct9_T *u)
{
  const mxArray *y;
  const mxArray *b_y;
  static const int32_T iv17[2] = { 100, 1000 };

  const mxArray *m8;
  real_T *pData;
  int32_T i;
  const mxArray *c_y;
  static const int32_T iv18[2] = { 100, 1000 };

  const mxArray *d_y;
  static const int32_T iv19[2] = { 100, 1000 };

  const mxArray *e_y;
  static const int32_T iv20[2] = { 100, 1000 };

  const mxArray *f_y;
  static const int32_T iv21[2] = { 100, 1000 };

  const mxArray *g_y;
  static const int32_T iv22[2] = { 100, 1000 };

  const mxArray *h_y;
  static const int32_T iv23[2] = { 100, 1000 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv17, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m8);
  for (i = 0; i < 100000; i++) {
    pData[i] = u->Stage[i];
  }

  emlrtAssign(&b_y, m8);
  emlrtAddField(y, b_y, "Stage", 0);
  c_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv18, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m8);
  for (i = 0; i < 100000; i++) {
    pData[i] = u->Location[i];
  }

  emlrtAssign(&c_y, m8);
  emlrtAddField(y, c_y, "Location", 0);
  d_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv19, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m8);
  for (i = 0; i < 100000; i++) {
    pData[i] = u->Sojourn[i];
  }

  emlrtAssign(&d_y, m8);
  emlrtAddField(y, d_y, "Sojourn", 0);
  e_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv20, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m8);
  for (i = 0; i < 100000; i++) {
    pData[i] = u->DwellTime[i];
  }

  emlrtAssign(&e_y, m8);
  emlrtAddField(y, e_y, "DwellTime", 0);
  f_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv21, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m8);
  for (i = 0; i < 100000; i++) {
    pData[i] = u->Gender[i];
  }

  emlrtAssign(&f_y, m8);
  emlrtAddField(y, f_y, "Gender", 0);
  g_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv22, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m8);
  for (i = 0; i < 100000; i++) {
    pData[i] = u->Detection[i];
  }

  emlrtAssign(&g_y, m8);
  emlrtAddField(y, g_y, "Detection", 0);
  h_y = NULL;
  m8 = emlrtCreateNumericArray(2, iv23, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m8);
  for (i = 0; i < 100000; i++) {
    pData[i] = u->PatientNumber[i];
  }

  emlrtAssign(&h_y, m8);
  emlrtAddField(y, h_y, "PatientNumber", 0);
  return y;
}

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[500])
{
  kc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*jc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[150]
{
  real_T (*ret)[150];
  static const int32_T dims[2] = { 1, 150 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[150])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *CostStage,
  const char_T *identifier, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(CostStage), &thisId, y);
  emlrtDestroyArray(&CostStage);
}

static const mxArray *k_emlrt_marshallOut(const real_T u[100000])
{
  const mxArray *y;
  static const int32_T iv24[2] = { 0, 0 };

  const mxArray *m9;
  static const int32_T iv25[2] = { 100, 1000 };

  y = NULL;
  m9 = emlrtCreateNumericArray(2, iv24, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m9, (void *)u);
  emlrtSetDimensions((mxArray *)m9, iv25, 2);
  emlrtAssign(&y, m9);
  return y;
}

static real_T (*kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *LifeTable, const char_T *identifier))[302]
{
  real_T (*y)[302];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = lb_emlrt_marshallIn(sp, emlrtAlias(LifeTable), &thisId);
  emlrtDestroyArray(&LifeTable);
  return y;
}
  static void kc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, real_T ret[500])
{
  static const int32_T dims[2] = { 1, 500 };

  int32_T i3;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i3 = 0; i3 < 500; i3++) {
    ret[i3] = (*(real_T (*)[500])mxGetData(src))[i3];
  }

  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[8] = { "Initial", "Cont", "Final", "Final_oc",
    "FutInitial", "FutCont", "FutFinal", "FutFinal_oc" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 8, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Initial";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Initial")),
                     &thisId, y->Initial);
  thisId.fIdentifier = "Cont";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Cont")),
                     &thisId, y->Cont);
  thisId.fIdentifier = "Final";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Final")),
                     &thisId, y->Final);
  thisId.fIdentifier = "Final_oc";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Final_oc")),
                     &thisId, y->Final_oc);
  thisId.fIdentifier = "FutInitial";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "FutInitial")),
                     &thisId, y->FutInitial);
  thisId.fIdentifier = "FutCont";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "FutCont")),
                     &thisId, y->FutCont);
  thisId.fIdentifier = "FutFinal";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "FutFinal")),
                     &thisId, y->FutFinal);
  thisId.fIdentifier = "FutFinal_oc";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "FutFinal_oc")),
                     &thisId, y->FutFinal_oc);
  emlrtDestroyArray(&u);
}

static const mxArray *l_emlrt_marshallOut(const real_T u[1000000])
{
  const mxArray *y;
  static const int32_T iv26[2] = { 0, 0 };

  const mxArray *m10;
  static const int32_T iv27[2] = { 100, 10000 };

  y = NULL;
  m10 = emlrtCreateNumericArray(2, iv26, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m10, (void *)u);
  emlrtSetDimensions((mxArray *)m10, iv27, 2);
  emlrtAssign(&y, m10);
  return y;
}

static real_T (*lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[302]
{
  real_T (*y)[302];
  y = lc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*lc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[302]
{
  real_T (*ret)[302];
  static const int32_T dims[2] = { 151, 2 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[302])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  cc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *m_emlrt_marshallOut(const real_T u[600])
{
  const mxArray *y;
  static const int32_T iv28[2] = { 0, 0 };

  const mxArray *m11;
  static const int32_T iv29[2] = { 6, 100 };

  y = NULL;
  m11 = emlrtCreateNumericArray(2, iv28, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m11, (void *)u);
  emlrtSetDimensions((mxArray *)m11, iv29, 2);
  emlrtAssign(&y, m11);
  return y;
}

static real_T (*mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *MortalityMatrix, const char_T *identifier))[400000]
{
  real_T (*y)[400000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = nb_emlrt_marshallIn(sp, emlrtAlias(MortalityMatrix), &thisId);
  emlrtDestroyArray(&MortalityMatrix);
  return y;
}
  static real_T (*mc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[400000]
{
  real_T (*ret)[400000];
  static const int32_T dims[3] = { 4, 100, 1000 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 3U, dims);
  ret = (real_T (*)[400000])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static struct4_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *risc,
  const char_T *identifier)
{
  struct4_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = o_emlrt_marshallIn(sp, emlrtAlias(risc), &thisId);
  emlrtDestroyArray(&risc);
  return y;
}

static const mxArray *n_emlrt_marshallOut(const struct10_T *u)
{
  const mxArray *y;
  const mxArray *b_y;
  static const int32_T iv30[2] = { 1, 100 };

  const mxArray *m12;
  real_T *pData;
  int32_T i;
  const mxArray *c_y;
  static const int32_T iv31[2] = { 1, 100 };

  const mxArray *d_y;
  static const int32_T iv32[2] = { 1, 100 };

  const mxArray *e_y;
  static const int32_T iv33[2] = { 1, 100 };

  const mxArray *f_y;
  static const int32_T iv34[2] = { 1, 100 };

  const mxArray *g_y;
  static const int32_T iv35[2] = { 1, 100 };

  const mxArray *h_y;
  static const int32_T iv36[2] = { 4, 100 };

  const mxArray *i_y;
  static const int32_T iv37[2] = { 4, 100 };

  const mxArray *j_y;
  static const int32_T iv38[2] = { 4, 100 };

  const mxArray *k_y;
  static const int32_T iv39[2] = { 4, 100 };

  const mxArray *l_y;
  static const int32_T iv40[2] = { 4, 100 };

  const mxArray *m_y;
  static const int32_T iv41[2] = { 4, 100 };

  const mxArray *n_y;
  static const int32_T iv42[2] = { 4, 100 };

  const mxArray *o_y;
  static const int32_T iv43[2] = { 4, 101 };

  const mxArray *p_y;
  static const int32_T iv44[2] = { 4, 101 };

  const mxArray *q_y;
  static const int32_T iv45[2] = { 4, 101 };

  const mxArray *r_y;
  static const int32_T iv46[3] = { 4, 101, 4 };

  const mxArray *s_y;
  static const int32_T iv47[3] = { 4, 101, 20 };

  const mxArray *t_y;
  static const int32_T iv48[3] = { 4, 101, 4 };

  const mxArray *u_y;
  static const int32_T iv49[2] = { 1, 100 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv30, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 100; i++) {
    pData[i] = u->FOBT[i];
  }

  emlrtAssign(&b_y, m12);
  emlrtAddField(y, b_y, "FOBT", 0);
  c_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv31, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 100; i++) {
    pData[i] = u->I_FOBT[i];
  }

  emlrtAssign(&c_y, m12);
  emlrtAddField(y, c_y, "I_FOBT", 0);
  d_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv32, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Sept9_HighSens[i];
  }

  emlrtAssign(&d_y, m12);
  emlrtAddField(y, d_y, "Sept9_HighSens", 0);
  e_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv33, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Sept9_HighSpec[i];
  }

  emlrtAssign(&e_y, m12);
  emlrtAddField(y, e_y, "Sept9_HighSpec", 0);
  f_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv34, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 100; i++) {
    pData[i] = u->RS[i];
  }

  emlrtAssign(&f_y, m12);
  emlrtAddField(y, f_y, "RS", 0);
  g_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv35, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 100; i++) {
    pData[i] = u->RSPolyp[i];
  }

  emlrtAssign(&g_y, m12);
  emlrtAddField(y, g_y, "RSPolyp", 0);
  h_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv36, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 400; i++) {
    pData[i] = u->Colonoscopy[i];
  }

  emlrtAssign(&h_y, m12);
  emlrtAddField(y, h_y, "Colonoscopy", 0);
  i_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv37, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 400; i++) {
    pData[i] = u->ColonoscopyPolyp[i];
  }

  emlrtAssign(&i_y, m12);
  emlrtAddField(y, i_y, "ColonoscopyPolyp", 0);
  j_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv38, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 400; i++) {
    pData[i] = u->Colonoscopy_Cancer[i];
  }

  emlrtAssign(&j_y, m12);
  emlrtAddField(y, j_y, "Colonoscopy_Cancer", 0);
  k_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv39, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 400; i++) {
    pData[i] = u->Perforation[i];
  }

  emlrtAssign(&k_y, m12);
  emlrtAddField(y, k_y, "Perforation", 0);
  l_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv40, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 400; i++) {
    pData[i] = u->Serosa[i];
  }

  emlrtAssign(&l_y, m12);
  emlrtAddField(y, l_y, "Serosa", 0);
  m_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv41, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 400; i++) {
    pData[i] = u->Bleeding[i];
  }

  emlrtAssign(&m_y, m12);
  emlrtAddField(y, m_y, "Bleeding", 0);
  n_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv42, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 400; i++) {
    pData[i] = u->BleedingTransf[i];
  }

  emlrtAssign(&n_y, m12);
  emlrtAddField(y, n_y, "BleedingTransf", 0);
  o_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv43, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 404; i++) {
    pData[i] = u->Cancer_ini[i];
  }

  emlrtAssign(&o_y, m12);
  emlrtAddField(y, o_y, "Cancer_ini", 0);
  p_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv44, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 404; i++) {
    pData[i] = u->Cancer_con[i];
  }

  emlrtAssign(&p_y, m12);
  emlrtAddField(y, p_y, "Cancer_con", 0);
  q_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv45, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 404; i++) {
    pData[i] = u->Cancer_fin[i];
  }

  emlrtAssign(&q_y, m12);
  emlrtAddField(y, q_y, "Cancer_fin", 0);
  r_y = NULL;
  m12 = emlrtCreateNumericArray(3, iv46, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 1616; i++) {
    pData[i] = u->QCancer_ini[i];
  }

  emlrtAssign(&r_y, m12);
  emlrtAddField(y, r_y, "QCancer_ini", 0);
  s_y = NULL;
  m12 = emlrtCreateNumericArray(3, iv47, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 8080; i++) {
    pData[i] = u->QCancer_con[i];
  }

  emlrtAssign(&s_y, m12);
  emlrtAddField(y, s_y, "QCancer_con", 0);
  t_y = NULL;
  m12 = emlrtCreateNumericArray(3, iv48, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 1616; i++) {
    pData[i] = u->QCancer_fin[i];
  }

  emlrtAssign(&t_y, m12);
  emlrtAddField(y, t_y, "QCancer_fin", 0);
  u_y = NULL;
  m12 = emlrtCreateNumericArray(2, iv49, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m12);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Other[i];
  }

  emlrtAssign(&u_y, m12);
  emlrtAddField(y, u_y, "Other", 0);
  return y;
}

static real_T (*nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[400000]
{
  real_T (*y)[400000];
  y = mc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*nc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2000]
{
  real_T (*ret)[2000];
  static const int32_T dims[2] = { 2, 1000 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[2000])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static struct4_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  struct4_T y;
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[7] = { "Colonoscopy_RiscPerforation",
    "Rectosigmo_Perforation", "Colonoscopy_RiscSerosaBurn",
    "Colonoscopy_RiscBleedingTransfusion", "Colonoscopy_RiscBleeding",
    "DeathPerforation", "DeathBleedingTransfusion" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 7, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Colonoscopy_RiscPerforation";
  y.Colonoscopy_RiscPerforation = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "Colonoscopy_RiscPerforation")), &thisId);
  thisId.fIdentifier = "Rectosigmo_Perforation";
  y.Rectosigmo_Perforation = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "Rectosigmo_Perforation")), &thisId);
  thisId.fIdentifier = "Colonoscopy_RiscSerosaBurn";
  y.Colonoscopy_RiscSerosaBurn = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "Colonoscopy_RiscSerosaBurn")), &thisId);
  thisId.fIdentifier = "Colonoscopy_RiscBleedingTransfusion";
  y.c_Colonoscopy_RiscBleedingTrans = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "Colonoscopy_RiscBleedingTransfusion")),
    &thisId);
  thisId.fIdentifier = "Colonoscopy_RiscBleeding";
  y.Colonoscopy_RiscBleeding = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "Colonoscopy_RiscBleeding")), &thisId);
  thisId.fIdentifier = "DeathPerforation";
  y.DeathPerforation = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "DeathPerforation")), &thisId);
  thisId.fIdentifier = "DeathBleedingTransfusion";
  y.DeathBleedingTransfusion = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "DeathBleedingTransfusion")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *o_emlrt_marshallOut(const struct11_T *u)
{
  const mxArray *y;
  const mxArray *b_y;
  static const int32_T iv50[1] = { 100 };

  const mxArray *m13;
  real_T *pData;
  int32_T i;
  const mxArray *c_y;
  static const int32_T iv51[1] = { 100 };

  const mxArray *d_y;
  static const int32_T iv52[1] = { 100 };

  const mxArray *e_y;
  static const int32_T iv53[1] = { 100 };

  const mxArray *f_y;
  static const int32_T iv54[1] = { 100 };

  const mxArray *g_y;
  static const int32_T iv55[1] = { 100 };

  const mxArray *h_y;
  static const int32_T iv56[1] = { 100 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  m13 = emlrtCreateNumericArray(1, iv50, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m13);
  for (i = 0; i < 100; i++) {
    pData[i] = u->AllCost[i];
  }

  emlrtAssign(&b_y, m13);
  emlrtAddField(y, b_y, "AllCost", 0);
  c_y = NULL;
  m13 = emlrtCreateNumericArray(1, iv51, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m13);
  for (i = 0; i < 100; i++) {
    pData[i] = u->AllCostFuture[i];
  }

  emlrtAssign(&c_y, m13);
  emlrtAddField(y, c_y, "AllCostFuture", 0);
  d_y = NULL;
  m13 = emlrtCreateNumericArray(1, iv52, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m13);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Treatment[i];
  }

  emlrtAssign(&d_y, m13);
  emlrtAddField(y, d_y, "Treatment", 0);
  e_y = NULL;
  m13 = emlrtCreateNumericArray(1, iv53, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m13);
  for (i = 0; i < 100; i++) {
    pData[i] = u->FutureTreatment[i];
  }

  emlrtAssign(&e_y, m13);
  emlrtAddField(y, e_y, "FutureTreatment", 0);
  f_y = NULL;
  m13 = emlrtCreateNumericArray(1, iv54, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m13);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Screening[i];
  }

  emlrtAssign(&f_y, m13);
  emlrtAddField(y, f_y, "Screening", 0);
  g_y = NULL;
  m13 = emlrtCreateNumericArray(1, iv55, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m13);
  for (i = 0; i < 100; i++) {
    pData[i] = u->FollowUp[i];
  }

  emlrtAssign(&g_y, m13);
  emlrtAddField(y, g_y, "FollowUp", 0);
  h_y = NULL;
  m13 = emlrtCreateNumericArray(1, iv56, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m13);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Other[i];
  }

  emlrtAssign(&h_y, m13);
  emlrtAddField(y, h_y, "Other", 0);
  return y;
}

static real_T (*ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *LocationMatrix, const char_T *identifier))[2000]
{
  real_T (*y)[2000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = pb_emlrt_marshallIn(sp, emlrtAlias(LocationMatrix), &thisId);
  emlrtDestroyArray(&LocationMatrix);
  return y;
}
  static real_T (*oc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[16]
{
  real_T (*ret)[16];
  static const int32_T dims[2] = { 4, 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[16])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static struct5_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *flag,
  const char_T *identifier)
{
  struct5_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = q_emlrt_marshallIn(sp, emlrtAlias(flag), &thisId);
  emlrtDestroyArray(&flag);
  return y;
}

static const mxArray *p_emlrt_marshallOut(const struct12_T *u)
{
  const mxArray *y;
  const mxArray *b_y;
  static const int32_T iv57[2] = { 1, 100 };

  const mxArray *m14;
  real_T *pData;
  int32_T i;
  const mxArray *c_y;
  static const int32_T iv58[2] = { 1, 100 };

  const mxArray *d_y;
  static const int32_T iv59[2] = { 1, 100 };

  const mxArray *e_y;
  static const int32_T iv60[2] = { 1, 100 };

  const mxArray *f_y;
  static const int32_T iv61[2] = { 1, 100 };

  const mxArray *g_y;
  static const int32_T iv62[2] = { 1, 100 };

  const mxArray *h_y;
  static const int32_T iv63[2] = { 1, 100 };

  const mxArray *i_y;
  static const int32_T iv64[2] = { 1, 100 };

  const mxArray *j_y;
  static const int32_T iv65[2] = { 1, 100 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  m14 = emlrtCreateNumericArray(2, iv57, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m14);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Screening_Colonoscopy[i];
  }

  emlrtAssign(&b_y, m14);
  emlrtAddField(y, b_y, "Screening_Colonoscopy", 0);
  c_y = NULL;
  m14 = emlrtCreateNumericArray(2, iv58, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m14);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Symptoms_Colonoscopy[i];
  }

  emlrtAssign(&c_y, m14);
  emlrtAddField(y, c_y, "Symptoms_Colonoscopy", 0);
  d_y = NULL;
  m14 = emlrtCreateNumericArray(2, iv59, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m14);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Follow_Up_Colonoscopy[i];
  }

  emlrtAssign(&d_y, m14);
  emlrtAddField(y, d_y, "Follow_Up_Colonoscopy", 0);
  e_y = NULL;
  m14 = emlrtCreateNumericArray(2, iv60, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m14);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Baseline_Colonoscopy[i];
  }

  emlrtAssign(&e_y, m14);
  emlrtAddField(y, e_y, "Baseline_Colonoscopy", 0);
  f_y = NULL;
  m14 = emlrtCreateNumericArray(2, iv61, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m14);
  for (i = 0; i < 100; i++) {
    pData[i] = u->RectoSigmo[i];
  }

  emlrtAssign(&f_y, m14);
  emlrtAddField(y, f_y, "RectoSigmo", 0);
  g_y = NULL;
  m14 = emlrtCreateNumericArray(2, iv62, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m14);
  for (i = 0; i < 100; i++) {
    pData[i] = u->FOBT[i];
  }

  emlrtAssign(&g_y, m14);
  emlrtAddField(y, g_y, "FOBT", 0);
  h_y = NULL;
  m14 = emlrtCreateNumericArray(2, iv63, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m14);
  for (i = 0; i < 100; i++) {
    pData[i] = u->I_FOBT[i];
  }

  emlrtAssign(&h_y, m14);
  emlrtAddField(y, h_y, "I_FOBT", 0);
  i_y = NULL;
  m14 = emlrtCreateNumericArray(2, iv64, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m14);
  for (i = 0; i < 100; i++) {
    pData[i] = u->Sept9[i];
  }

  emlrtAssign(&i_y, m14);
  emlrtAddField(y, i_y, "Sept9", 0);
  j_y = NULL;
  m14 = emlrtCreateNumericArray(2, iv65, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m14);
  for (i = 0; i < 100; i++) {
    pData[i] = u->other[i];
  }

  emlrtAssign(&j_y, m14);
  emlrtAddField(y, j_y, "other", 0);
  return y;
}

static real_T (*pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2000]
{
  real_T (*y)[2000];
  y = nc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*pc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[100]
{
  real_T (*ret)[100];
  static const int32_T dims[2] = { 25, 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[100])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static struct5_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  struct5_T y;
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[17] = { "Polyp_Surveillance",
    "Cancer_Surveillance", "SpecialFlag", "Screening", "Correlation", "Schoen",
    "Holme", "Segnan", "Atkin", "perfect", "Mock", "Kolo1", "Kolo2", "Kolo3",
    "Po55", "treated", "AllPolypFollowUp" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 17, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Polyp_Surveillance";
  y.Polyp_Surveillance = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a
    (sp, u, 0, "Polyp_Surveillance")), &thisId);
  thisId.fIdentifier = "Cancer_Surveillance";
  y.Cancer_Surveillance = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a
    (sp, u, 0, "Cancer_Surveillance")), &thisId);
  thisId.fIdentifier = "SpecialFlag";
  y.SpecialFlag = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "SpecialFlag")), &thisId);
  thisId.fIdentifier = "Screening";
  y.Screening = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Screening")), &thisId);
  thisId.fIdentifier = "Correlation";
  y.Correlation = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Correlation")), &thisId);
  thisId.fIdentifier = "Schoen";
  y.Schoen = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Schoen")), &thisId);
  thisId.fIdentifier = "Holme";
  y.Holme = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Holme")), &thisId);
  thisId.fIdentifier = "Segnan";
  y.Segnan = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Segnan")), &thisId);
  thisId.fIdentifier = "Atkin";
  y.Atkin = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Atkin")), &thisId);
  thisId.fIdentifier = "perfect";
  y.perfect = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "perfect")), &thisId);
  thisId.fIdentifier = "Mock";
  y.Mock = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Mock")), &thisId);
  thisId.fIdentifier = "Kolo1";
  y.Kolo1 = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Kolo1")), &thisId);
  thisId.fIdentifier = "Kolo2";
  y.Kolo2 = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Kolo2")), &thisId);
  thisId.fIdentifier = "Kolo3";
  y.Kolo3 = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Kolo3")), &thisId);
  thisId.fIdentifier = "Po55";
  y.Po55 = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Po55")), &thisId);
  thisId.fIdentifier = "treated";
  y.treated = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "treated")), &thisId);
  thisId.fIdentifier = "AllPolypFollowUp";
  y.AllPolypFollowUp = r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "AllPolypFollowUp")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *q_emlrt_marshallOut(const boolean_T u[1000000])
{
  const mxArray *y;
  static const int32_T iv66[2] = { 0, 0 };

  const mxArray *m15;
  static const int32_T iv67[2] = { 100, 10000 };

  y = NULL;
  m15 = emlrtCreateLogicalArray(2, iv66);
  mxSetData((mxArray *)m15, (void *)u);
  emlrtSetDimensions((mxArray *)m15, iv67, 2);
  emlrtAssign(&y, m15);
  return y;
}

static real_T (*qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *StageDuration, const char_T *identifier))[16]
{
  real_T (*y)[16];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = rb_emlrt_marshallIn(sp, emlrtAlias(StageDuration), &thisId);
  emlrtDestroyArray(&StageDuration);
  return y;
}
  static real_T (*qc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[300]
{
  real_T (*ret)[300];
  static const int32_T dims[2] = { 2, 150 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[300])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = dc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[16]
{
  real_T (*y)[16];
  y = oc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void rc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, char_T ret[4])
{
  static const int32_T dims[2] = { 1, 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, ret, 4);
  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *SpecialText,
  const char_T *identifier, char_T y[25])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  t_emlrt_marshallIn(sp, emlrtAlias(SpecialText), &thisId, y);
  emlrtDestroyArray(&SpecialText);
}

static real_T (*sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tx1,
  const char_T *identifier))[100]
{
  real_T (*y)[100];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = tb_emlrt_marshallIn(sp, emlrtAlias(tx1), &thisId);
  emlrtDestroyArray(&tx1);
  return y;
}
  static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[25])
{
  ec_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[100]
{
  real_T (*y)[100];
  y = pc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static struct6_T u_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *female, const char_T *identifier)
{
  struct6_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = v_emlrt_marshallIn(sp, emlrtAlias(female), &thisId);
  emlrtDestroyArray(&female);
  return y;
}

static real_T (*ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *DirectCancerRate, const char_T *identifier))[300]
{
  real_T (*y)[300];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = vb_emlrt_marshallIn(sp, emlrtAlias(DirectCancerRate), &thisId);
  emlrtDestroyArray(&DirectCancerRate);
  return y;
}
  static struct6_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  struct6_T y;
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[5] = { "fraction_female", "new_polyp_female",
    "early_progression_female", "advanced_progression_female", "symptoms_female"
  };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 5, fieldNames, 0U, &dims);
  thisId.fIdentifier = "fraction_female";
  y.fraction_female = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "fraction_female")), &thisId);
  thisId.fIdentifier = "new_polyp_female";
  y.new_polyp_female = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "new_polyp_female")), &thisId);
  thisId.fIdentifier = "early_progression_female";
  y.early_progression_female = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "early_progression_female")), &thisId);
  thisId.fIdentifier = "advanced_progression_female";
  y.advanced_progression_female = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "advanced_progression_female")), &thisId);
  thisId.fIdentifier = "symptoms_female";
  y.symptoms_female = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "symptoms_female")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[300]
{
  real_T (*y)[300];
  y = qc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*w_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *Sensitivity, const char_T *identifier))[70]
{
  real_T (*y)[70];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = x_emlrt_marshallIn(sp, emlrtAlias(Sensitivity), &thisId);
  emlrtDestroyArray(&Sensitivity);
  return y;
}

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DwellSpeed,
  const char_T *identifier, char_T y[4])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  xb_emlrt_marshallIn(sp, emlrtAlias(DwellSpeed), &thisId, y);
  emlrtDestroyArray(&DwellSpeed);
}

static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[70]
{
  real_T (*y)[70];
  y = fc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[4])
{
  rc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*y_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *ScreeningTest, const char_T *identifier))[56]
{
  real_T (*y)[56];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = ab_emlrt_marshallIn(sp, emlrtAlias(ScreeningTest), &thisId);
  emlrtDestroyArray(&ScreeningTest);
  return y;
}
  static real_T yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void NumberCrunching_10000_api(NumberCrunching_10000StackData *SD, const mxArray
  *prhs[26], const mxArray *plhs[29])
{
  real_T (*DeathCause)[10000];
  real_T (*DeathYear)[10000];
  real_T (*NaturalDeathYear)[10000];
  real_T (*DirectCancer)[500];
  real_T (*DirectCancerR)[100];
  real_T (*DirectCancer2)[100];
  real_T (*DirectCancer2R)[100];
  real_T (*ProgressedCancer)[100];
  real_T (*ProgressedCancerR)[100];
  real_T (*DwellTimeProgression)[100000];
  real_T (*DwellTimeFastCancer)[100000];
  real_T (*HasCancer)[1000000];
  real_T (*NumPolyps)[1000000];
  real_T (*MaxPolyps)[1000000];
  real_T (*AllPolyps)[600];
  real_T (*NumCancer)[1000000];
  real_T (*MaxCancer)[1000000];
  real_T (*EarlyPolypsRemoved)[100];
  real_T (*DiagnosedCancer)[1000000];
  real_T (*AdvancedPolypsRemoved)[100];
  boolean_T (*YearIncluded)[1000000];
  boolean_T (*YearAlive)[1000000];
  real_T p;
  struct0_T StageVariables;
  struct1_T Location;
  struct2_T Cost;
  struct3_T CostStage;
  struct4_T risc;
  struct5_T flag;
  char_T SpecialText[25];
  struct6_T female;
  real_T (*Sensitivity)[70];
  real_T (*ScreeningTest)[56];
  real_T (*ScreeningPreference)[10000];
  real_T (*AgeProgression)[900];
  real_T (*NewPolyp)[150];
  real_T (*ColonoscopyLikelyhood)[150];
  real_T (*IndividualRisk)[10000];
  struct7_T RiskDistribution;
  real_T (*Gender)[10000];
  real_T (*LifeTable)[302];
  real_T (*MortalityMatrix)[400000];
  real_T (*LocationMatrix)[2000];
  real_T (*StageDuration)[16];
  real_T (*tx1)[100];
  real_T (*DirectCancerRate)[300];
  real_T DirectCancerSpeed;
  char_T DwellSpeed[4];
  struct12_T Number;
  struct11_T Money;
  real_T y;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  DeathCause = (real_T (*)[10000])mxMalloc(sizeof(real_T [10000]));
  DeathYear = (real_T (*)[10000])mxMalloc(sizeof(real_T [10000]));
  NaturalDeathYear = (real_T (*)[10000])mxMalloc(sizeof(real_T [10000]));
  DirectCancer = (real_T (*)[500])mxMalloc(sizeof(real_T [500]));
  DirectCancerR = (real_T (*)[100])mxMalloc(sizeof(real_T [100]));
  DirectCancer2 = (real_T (*)[100])mxMalloc(sizeof(real_T [100]));
  DirectCancer2R = (real_T (*)[100])mxMalloc(sizeof(real_T [100]));
  ProgressedCancer = (real_T (*)[100])mxMalloc(sizeof(real_T [100]));
  ProgressedCancerR = (real_T (*)[100])mxMalloc(sizeof(real_T [100]));
  DwellTimeProgression = (real_T (*)[100000])mxMalloc(sizeof(real_T [100000]));
  DwellTimeFastCancer = (real_T (*)[100000])mxMalloc(sizeof(real_T [100000]));
  HasCancer = (real_T (*)[1000000])mxMalloc(sizeof(real_T [1000000]));
  NumPolyps = (real_T (*)[1000000])mxMalloc(sizeof(real_T [1000000]));
  MaxPolyps = (real_T (*)[1000000])mxMalloc(sizeof(real_T [1000000]));
  AllPolyps = (real_T (*)[600])mxMalloc(sizeof(real_T [600]));
  NumCancer = (real_T (*)[1000000])mxMalloc(sizeof(real_T [1000000]));
  MaxCancer = (real_T (*)[1000000])mxMalloc(sizeof(real_T [1000000]));
  EarlyPolypsRemoved = (real_T (*)[100])mxMalloc(sizeof(real_T [100]));
  DiagnosedCancer = (real_T (*)[1000000])mxMalloc(sizeof(real_T [1000000]));
  AdvancedPolypsRemoved = (real_T (*)[100])mxMalloc(sizeof(real_T [100]));
  YearIncluded = (boolean_T (*)[1000000])mxMalloc(sizeof(boolean_T [1000000]));
  YearAlive = (boolean_T (*)[1000000])mxMalloc(sizeof(boolean_T [1000000]));
  prhs[11] = emlrtProtectR2012b(prhs[11], 11, false, -1);
  prhs[17] = emlrtProtectR2012b(prhs[17], 17, true, -1);
  prhs[20] = emlrtProtectR2012b(prhs[20], 20, false, -1);

  /* Marshall function inputs */
  p = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "p");
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "StageVariables",
                     &StageVariables);
  f_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "Location", &Location);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "Cost", &Cost);
  k_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "CostStage", &CostStage);
  risc = n_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "risc");
  flag = p_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "flag");
  s_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "SpecialText", SpecialText);
  female = u_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "female");
  Sensitivity = w_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "Sensitivity");
  ScreeningTest = y_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "ScreeningTest");
  ScreeningPreference = bb_emlrt_marshallIn(&st, emlrtAlias(prhs[11]),
    "ScreeningPreference");
  AgeProgression = db_emlrt_marshallIn(&st, emlrtAlias(prhs[12]),
    "AgeProgression");
  NewPolyp = fb_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "NewPolyp");
  ColonoscopyLikelyhood = fb_emlrt_marshallIn(&st, emlrtAlias(prhs[14]),
    "ColonoscopyLikelyhood");
  IndividualRisk = bb_emlrt_marshallIn(&st, emlrtAlias(prhs[15]),
    "IndividualRisk");
  hb_emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "RiskDistribution",
                      &RiskDistribution);
  Gender = bb_emlrt_marshallIn(&st, emlrtAlias(prhs[17]), "Gender");
  LifeTable = kb_emlrt_marshallIn(&st, emlrtAlias(prhs[18]), "LifeTable");
  MortalityMatrix = mb_emlrt_marshallIn(&st, emlrtAlias(prhs[19]),
    "MortalityMatrix");
  LocationMatrix = ob_emlrt_marshallIn(&st, emlrtAlias(prhs[20]),
    "LocationMatrix");
  StageDuration = qb_emlrt_marshallIn(&st, emlrtAlias(prhs[21]), "StageDuration");
  tx1 = sb_emlrt_marshallIn(&st, emlrtAlias(prhs[22]), "tx1");
  DirectCancerRate = ub_emlrt_marshallIn(&st, emlrtAlias(prhs[23]),
    "DirectCancerRate");
  DirectCancerSpeed = emlrt_marshallIn(&st, emlrtAliasP(prhs[24]),
    "DirectCancerSpeed");
  wb_emlrt_marshallIn(&st, emlrtAliasP(prhs[25]), "DwellSpeed", DwellSpeed);

  /* Invoke the target function */
  NumberCrunching_10000(SD, &st, p, &StageVariables, &Location, &Cost,
                        &CostStage, &risc, &flag, SpecialText, &female,
                        *Sensitivity, *ScreeningTest, *ScreeningPreference,
                        *AgeProgression, *NewPolyp, *ColonoscopyLikelyhood,
                        *IndividualRisk, &RiskDistribution, *Gender, *LifeTable,
                        *MortalityMatrix, *LocationMatrix, *StageDuration, *tx1,
                        *DirectCancerRate, DirectCancerSpeed, DwellSpeed, &y,
                        *DeathCause, &SD->f3.Last, *DeathYear, *NaturalDeathYear,
                        *DirectCancer, *DirectCancerR, *DirectCancer2,
                        *DirectCancer2R, *ProgressedCancer, *ProgressedCancerR,
                        &SD->f3.TumorRecord, *DwellTimeProgression,
                        *DwellTimeFastCancer, *HasCancer, *NumPolyps, *MaxPolyps,
                        *AllPolyps, *NumCancer, *MaxCancer, &SD->f3.PaymentType,
                        &Money, &Number, *EarlyPolypsRemoved, *DiagnosedCancer, *
                        AdvancedPolypsRemoved, *YearIncluded, *YearAlive);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(y);
  e_emlrt_marshallOut(*Gender, prhs[17]);
  plhs[1] = prhs[17];
  plhs[2] = f_emlrt_marshallOut(*DeathCause);
  plhs[3] = g_emlrt_marshallOut(&SD->f3.Last);
  plhs[4] = f_emlrt_marshallOut(*DeathYear);
  plhs[5] = f_emlrt_marshallOut(*NaturalDeathYear);
  plhs[6] = h_emlrt_marshallOut(*DirectCancer);
  plhs[7] = i_emlrt_marshallOut(*DirectCancerR);
  plhs[8] = i_emlrt_marshallOut(*DirectCancer2);
  plhs[9] = i_emlrt_marshallOut(*DirectCancer2R);
  plhs[10] = i_emlrt_marshallOut(*ProgressedCancer);
  plhs[11] = i_emlrt_marshallOut(*ProgressedCancerR);
  plhs[12] = j_emlrt_marshallOut(&SD->f3.TumorRecord);
  plhs[13] = k_emlrt_marshallOut(*DwellTimeProgression);
  plhs[14] = k_emlrt_marshallOut(*DwellTimeFastCancer);
  plhs[15] = l_emlrt_marshallOut(*HasCancer);
  plhs[16] = l_emlrt_marshallOut(*NumPolyps);
  plhs[17] = l_emlrt_marshallOut(*MaxPolyps);
  plhs[18] = m_emlrt_marshallOut(*AllPolyps);
  plhs[19] = l_emlrt_marshallOut(*NumCancer);
  plhs[20] = l_emlrt_marshallOut(*MaxCancer);
  plhs[21] = n_emlrt_marshallOut(&SD->f3.PaymentType);
  plhs[22] = o_emlrt_marshallOut(&Money);
  plhs[23] = p_emlrt_marshallOut(&Number);
  plhs[24] = i_emlrt_marshallOut(*EarlyPolypsRemoved);
  plhs[25] = l_emlrt_marshallOut(*DiagnosedCancer);
  plhs[26] = i_emlrt_marshallOut(*AdvancedPolypsRemoved);
  plhs[27] = q_emlrt_marshallOut(*YearIncluded);
  plhs[28] = q_emlrt_marshallOut(*YearAlive);
}

/* End of code generation (_coder_NumberCrunching_10000_api.c) */
