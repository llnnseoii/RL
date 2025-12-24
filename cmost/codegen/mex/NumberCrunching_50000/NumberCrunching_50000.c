/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NumberCrunching_50000.c
 *
 * Code generation for function 'NumberCrunching_50000'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NumberCrunching_50000.h"
#include "sum.h"
#include "rand.h"
#include "NumberCrunching_50000_emxutil.h"
#include "isequal.h"
#include "round.h"
#include "strcmp.h"
#include "NumberCrunching_50000_mexutil.h"
#include "NumberCrunching_50000_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 1191, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo b_emlrtRSI = { 1182, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo c_emlrtRSI = { 1173, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo d_emlrtRSI = { 1163, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo e_emlrtRSI = { 1154, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo f_emlrtRSI = { 1144, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo g_emlrtRSI = { 1092, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo h_emlrtRSI = { 1077, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo i_emlrtRSI = { 1056, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo j_emlrtRSI = { 1055, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo k_emlrtRSI = { 1032, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo l_emlrtRSI = { 1014, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo m_emlrtRSI = { 987, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo n_emlrtRSI = { 986, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo o_emlrtRSI = { 963, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo p_emlrtRSI = { 945, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo q_emlrtRSI = { 908, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo r_emlrtRSI = { 907, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo s_emlrtRSI = { 902, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo t_emlrtRSI = { 898, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo u_emlrtRSI = { 896, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo v_emlrtRSI = { 895, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo w_emlrtRSI = { 866, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo x_emlrtRSI = { 851, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo y_emlrtRSI = { 825, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo ab_emlrtRSI = { 824, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo bb_emlrtRSI = { 776, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo db_emlrtRSI = { 772, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo eb_emlrtRSI = { 762, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo fb_emlrtRSI = { 747, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo gb_emlrtRSI = { 744, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo hb_emlrtRSI = { 739, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo ib_emlrtRSI = { 736, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo jb_emlrtRSI = { 727, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo kb_emlrtRSI = { 700, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo lb_emlrtRSI = { 585, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo mb_emlrtRSI = { 559, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo nb_emlrtRSI = { 513, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo ob_emlrtRSI = { 512, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo pb_emlrtRSI = { 491, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo qb_emlrtRSI = { 456, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo rb_emlrtRSI = { 455, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo sb_emlrtRSI = { 443, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo tb_emlrtRSI = { 388, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo ub_emlrtRSI = { 240, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo vb_emlrtRSI = { 387, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo wb_emlrtRSI = { 383, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo xb_emlrtRSI = { 376, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo yb_emlrtRSI = { 364, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo ac_emlrtRSI = { 357, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo bc_emlrtRSI = { 353, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo cc_emlrtRSI = { 350, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo dc_emlrtRSI = { 344, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo ec_emlrtRSI = { 322, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo fc_emlrtRSI = { 292, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo gc_emlrtRSI = { 280, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo hc_emlrtRSI = { 241, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo ic_emlrtRSI = { 219, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRSInfo kc_emlrtRSI = { 16, "max",
  "C:\\Program Files\\MATLAB\\R2015b_x64\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"
};

static emlrtRSInfo lc_emlrtRSI = { 18, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b_x64\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo sc_emlrtRSI = { 1481, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtMCInfo emlrtMCI = { 1278, 13, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtMCInfo b_emlrtMCI = { 1278, 5, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRTEInfo emlrtRTEI = { 27, 7, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo emlrtBCI = { 1, 15, 1055, 60, "tmp", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo emlrtDCI = { 1055, 60, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo b_emlrtBCI = { 1, 10, 986, 60, "tmp", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo b_emlrtDCI = { 986, 60, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo c_emlrtBCI = { 1, 20, 895, 60, "tmp", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo c_emlrtDCI = { 895, 60, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo d_emlrtBCI = { 1, 10, 824, 60, "tmp", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo d_emlrtDCI = { 824, 60, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo e_emlrtBCI = { 1, 7, 720, 55, "ScreeningTest",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo e_emlrtDCI = { 720, 55, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtRTEInfo c_emlrtRTEI = { 581, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtECInfo emlrtECI = { -1, 568, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo f_emlrtBCI = { 1, 51, 568, 86, "Polyp.AdvProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo b_emlrtECI = { -1, 567, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo g_emlrtBCI = { 1, 51, 567, 88, "Polyp.EarlyProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo c_emlrtECI = { -1, 566, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo h_emlrtBCI = { 1, 51, 566, 85, "Polyp.PolypLocation",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo d_emlrtECI = { -1, 565, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo i_emlrtBCI = { 1, 51, 565, 81, "Polyp.PolypYear",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo e_emlrtECI = { -1, 564, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo j_emlrtBCI = { 1, 51, 564, 78, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtRTEInfo d_emlrtRTEI = { 558, 17, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtECInfo f_emlrtECI = { -1, 546, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo k_emlrtBCI = { 1, 51, 546, 82, "Polyp.AdvProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo g_emlrtECI = { -1, 545, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo l_emlrtBCI = { 1, 51, 545, 84, "Polyp.EarlyProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo h_emlrtECI = { -1, 544, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo m_emlrtBCI = { 1, 51, 544, 81, "Polyp.PolypLocation",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo i_emlrtECI = { -1, 543, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo n_emlrtBCI = { 1, 51, 543, 77, "Polyp.PolypYear",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo j_emlrtECI = { -1, 542, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo o_emlrtBCI = { 1, 51, 542, 74, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo p_emlrtBCI = { 1, 4, 513, 65, "SojournMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo q_emlrtBCI = { 1, 1000, 513, 46, "SojournMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo f_emlrtDCI = { 513, 46, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo r_emlrtBCI = { 1, 500, 500, 53,
  "RiskDistribution.AdvancedRisk", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo g_emlrtDCI = { 500, 53, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo s_emlrtBCI = { 1, 500, 499, 53, "RiskDistribution.EarlyRisk",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo h_emlrtDCI = { 499, 53, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo t_emlrtBCI = { 1, 2, 498, 48, "GenderProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo i_emlrtDCI = { 498, 48, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo u_emlrtBCI = { 1, 13, 497, 50, "LocationProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo j_emlrtDCI = { 497, 50, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo v_emlrtBCI = { 1, 10, 495, 56, "StageVariables.FastCancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo w_emlrtBCI = { 1, 2, 494, 48, "GenderProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo k_emlrtDCI = { 494, 48, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo x_emlrtBCI = { 1, 13, 493, 50, "LocationProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo l_emlrtDCI = { 493, 50, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo y_emlrtBCI = { 1, 10, 491, 64, "StageVariables.FastCancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo k_emlrtECI = { -1, 489, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo ab_emlrtBCI = { 1, 51, 489, 86, "Polyp.AdvProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo l_emlrtECI = { -1, 488, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo bb_emlrtBCI = { 1, 51, 488, 88, "Polyp.EarlyProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo m_emlrtECI = { -1, 487, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo cb_emlrtBCI = { 1, 51, 487, 85, "Polyp.PolypLocation",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo n_emlrtECI = { -1, 486, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo db_emlrtBCI = { 1, 51, 486, 81, "Polyp.PolypYear",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo o_emlrtECI = { -1, 485, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo eb_emlrtBCI = { 1, 51, 485, 78, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { 1, 4, 456, 69, "SojournMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { 1, 1000, 456, 50, "SojournMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo m_emlrtDCI = { 456, 50, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo hb_emlrtBCI = { 1, 500, 428, 51,
  "RiskDistribution.AdvancedRisk", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo n_emlrtDCI = { 428, 51, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo ib_emlrtBCI = { 1, 500, 427, 53, "RiskDistribution.EarlyRisk",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo o_emlrtDCI = { 427, 53, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo jb_emlrtBCI = { 1, 51, 427, 45, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { 1, 2, 426, 65, "GenderProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo p_emlrtDCI = { 426, 65, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo lb_emlrtBCI = { 1, 10, 426, 45, "GenderProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { 1, 13, 425, 66, "LocationProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo q_emlrtDCI = { 425, 66, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo nb_emlrtBCI = { 1, 10, 425, 47, "LocationProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { 1, 6, 424, 42, "AgeProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtRTEInfo e_emlrtRTEI = { 423, 17, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo pb_emlrtBCI = { 1, 4, 388, 65, "SojournMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { 1, 1000, 388, 46, "SojournMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo r_emlrtDCI = { 388, 46, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo rb_emlrtBCI = { 1, 1000, 243, 31, "SojournMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo s_emlrtDCI = { 243, 31, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo sb_emlrtBCI = { 1, 1000, 240, 27, "SojournMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo t_emlrtDCI = { 240, 27, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtECInfo p_emlrtECI = { -1, 362, 29, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo tb_emlrtBCI = { 1, 4, 328, 29, "CaSurv",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { 1, 4, 328, 62, "CaSurv",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo vb_emlrtBCI = { 1, 4, 323, 33, "CaDeath",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { 1, 4, 323, 67, "CaDeath",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo xb_emlrtBCI = { 1, 2, 280, 41, "LifeTable",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo u_emlrtDCI = { 280, 41, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtECInfo q_emlrtECI = { -1, 266, 5, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo yb_emlrtBCI = { 1, 2000, 220, 5, "LocationMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo v_emlrtDCI = { 220, 5, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo ac_emlrtBCI = { 1, 1000, 210, 15, "TmpLoc",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo w_emlrtDCI = { 210, 15, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo bc_emlrtBCI = { 1, 1000, 201, 15, "TmpLoc",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo x_emlrtDCI = { 201, 15, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtRTEInfo f_emlrtRTEI = { 81, 19, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b_x64\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtBCInfo cc_emlrtBCI = { 1, 51, 351, 41, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo dc_emlrtBCI = { 1, 1000, 353, 76, "LocationMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo y_emlrtDCI = { 353, 76, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo ec_emlrtBCI = { 1, 2, 376, 44, "DirectCancerRate",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo ab_emlrtDCI = { 376, 44, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo fc_emlrtBCI = { 1, 1000, 383, 70, "LocationMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo bb_emlrtDCI = { 383, 70, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo gc_emlrtBCI = { 1, 1000, 387, 32, "StageMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo cb_emlrtDCI = { 387, 32, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo hc_emlrtBCI = { 1, 5000, 409, 49, "DwellTimeProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ic_emlrtBCI = { 1, 25, 582, 50, "Ca.SympTime",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { 1, 10, 766, 85, "Sensitivity",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { 1, 10, 769, 85, "Sensitivity",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { 1, 10, 559, 31, "StageVariables.Healing",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { 1, 51, 559, 70, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { 1, 51, 560, 62, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { 1, 51, 560, 41, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo pc_emlrtBCI = { 1, 25, 506, 38, "Ca.Cancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { 1, 1000, 512, 32, "StageMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo db_emlrtDCI = { 512, 32, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo rc_emlrtBCI = { 1, 5000, 534, 48, "DwellTimeFastCancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { 1, 5, 537, 76, "DirectCancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo tc_emlrtBCI = { 1, 5, 537, 38, "DirectCancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { 1, 25, 449, 42, "Ca.Cancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { 1, 1000, 455, 36, "StageMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo eb_emlrtDCI = { 455, 36, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo wc_emlrtBCI = { 1, 5000, 477, 53, "DwellTimeProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { 1, 404, 1764, 24, "SubCostFut",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo fb_emlrtDCI = { 1764, 24, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo yc_emlrtBCI = { 1, 404, 1752, 28, "SubCostFut",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo gb_emlrtDCI = { 1752, 28, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo ad_emlrtBCI = { 1, 404, 1722, 24, "SubCostFut",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo hb_emlrtDCI = { 1722, 24, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo bd_emlrtBCI = { 1, 404, 1712, 28, "SubCostFut",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo ib_emlrtDCI = { 1712, 28, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo cd_emlrtBCI = { 1, 404, 1763, 21, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo jb_emlrtDCI = { 1763, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo dd_emlrtBCI = { 1, 404, 1751, 25, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo kb_emlrtDCI = { 1751, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo ed_emlrtBCI = { 1, 404, 1721, 21, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo lb_emlrtDCI = { 1721, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo fd_emlrtBCI = { 1, 404, 1711, 25, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo mb_emlrtDCI = { 1711, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtRTEInfo g_emlrtRTEI = { 1737, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRTEInfo h_emlrtRTEI = { 1714, 13, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo gd_emlrtBCI = { 1, 404, 1792, 59, "SubCostAll",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { 1, 4, 1759, 54, "CostStage.Initial",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo id_emlrtBCI = { 1, 25, 1759, 17, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { 1, 404, 1759, 21, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo nb_emlrtDCI = { 1759, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo kd_emlrtBCI = { 1, 4, 1760, 54, "CostStage.FutInitial",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { 1, 404, 1760, 24, "SubCostFut",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo ob_emlrtDCI = { 1760, 24, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo md_emlrtBCI = { 1, 4, 1763, 54, "CostStage.Cont",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { 1, 4, 1764, 54, "CostStage.FutCont",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo od_emlrtBCI = { 1, 4, 1765, 97, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { 1, 101, 1765, 123, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { 1, 4, 1765, 32, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo rd_emlrtBCI = { 1, 101, 1765, 58, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo sd_emlrtBCI = { 1, 4, 1766, 100, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo td_emlrtBCI = { 1, 101, 1766, 126, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ud_emlrtBCI = { 1, 4, 1766, 33, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo vd_emlrtBCI = { 1, 101, 1766, 59, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { 1, 4, 1777, 104, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { 1, 101, 1777, 130, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { 1, 4, 1777, 32, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { 1, 101, 1777, 58, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo be_emlrtBCI = { 1, 4, 1779, 118, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { 1, 101, 1779, 143, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo de_emlrtBCI = { 1, 4, 1779, 37, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { 1, 101, 1779, 63, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { 1, 4, 1772, 107, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { 1, 101, 1772, 132, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo he_emlrtBCI = { 1, 4, 1772, 36, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ie_emlrtBCI = { 1, 101, 1772, 62, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo je_emlrtBCI = { 1, 4, 1774, 120, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ke_emlrtBCI = { 1, 101, 1774, 145, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo le_emlrtBCI = { 1, 20, 1774, 164, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo me_emlrtBCI = { 1, 4, 1774, 41, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ne_emlrtBCI = { 1, 101, 1774, 67, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo oe_emlrtBCI = { 1, 20, 1774, 86, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { 1, 4, 1719, 55, "CostStage.Initial",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { 1, 25, 1719, 17, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo re_emlrtBCI = { 1, 404, 1719, 21, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo pb_emlrtDCI = { 1719, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo se_emlrtBCI = { 1, 4, 1720, 55, "CostStage.FutInitial",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo te_emlrtBCI = { 1, 404, 1720, 24, "SubCostFut",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo qb_emlrtDCI = { 1720, 24, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo ue_emlrtBCI = { 1, 4, 1721, 59, "CostStage.Cont",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { 1, 4, 1722, 59, "CostStage.FutCont",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo we_emlrtBCI = { 1, 4, 1723, 97, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo xe_emlrtBCI = { 1, 101, 1723, 122, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ye_emlrtBCI = { 1, 4, 1723, 32, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo af_emlrtBCI = { 1, 101, 1723, 58, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { 1, 4, 1724, 100, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo cf_emlrtBCI = { 1, 101, 1724, 126, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo df_emlrtBCI = { 1, 4, 1724, 33, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { 1, 101, 1724, 59, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { 1, 4, 1736, 104, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { 1, 101, 1736, 130, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo hf_emlrtBCI = { 1, 4, 1736, 32, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo if_emlrtBCI = { 1, 101, 1736, 58, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo jf_emlrtBCI = { 1, 4, 1751, 63, "CostStage.Cont",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo kf_emlrtBCI = { 1, 4, 1752, 63, "CostStage.FutCont",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo lf_emlrtBCI = { 1, 4, 1753, 102, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo mf_emlrtBCI = { 1, 101, 1753, 127, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo nf_emlrtBCI = { 1, 4, 1753, 36, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo of_emlrtBCI = { 1, 101, 1753, 62, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo pf_emlrtBCI = { 1, 4, 1755, 136, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo qf_emlrtBCI = { 1, 101, 1755, 162, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo rf_emlrtBCI = { 1, 20, 1755, 176, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo rb_emlrtDCI = { 1755, 176, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo sf_emlrtBCI = { 1, 4, 1755, 41, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { 1, 101, 1755, 67, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { 1, 20, 1755, 81, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo sb_emlrtDCI = { 1755, 81, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo vf_emlrtBCI = { 1, 4, 1738, 126, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo wf_emlrtBCI = { 1, 101, 1738, 151, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo xf_emlrtBCI = { 1, 20, 1738, 172, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo yf_emlrtBCI = { 1, 4, 1738, 37, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ag_emlrtBCI = { 1, 101, 1738, 63, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { 1, 20, 1738, 84, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo cg_emlrtBCI = { 1, 4, 1730, 107, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo dg_emlrtBCI = { 1, 101, 1730, 132, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { 1, 4, 1730, 36, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { 1, 101, 1730, 62, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo gg_emlrtBCI = { 1, 4, 1732, 120, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo hg_emlrtBCI = { 1, 101, 1732, 145, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ig_emlrtBCI = { 1, 4, 1732, 41, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo jg_emlrtBCI = { 1, 101, 1732, 67, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { 1, 4, 1698, 39, "CostStage.Initial",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { 1, 25, 1698, 17, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { 1, 404, 1698, 22, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo tb_emlrtDCI = { 1698, 22, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo ng_emlrtBCI = { 1, 4, 1699, 39, "CostStage.FutInitial",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo og_emlrtBCI = { 1, 404, 1699, 25, "SubCostFut",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo ub_emlrtDCI = { 1699, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo pg_emlrtBCI = { 1, 4, 1700, 97, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo qg_emlrtBCI = { 1, 101, 1700, 123, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo rg_emlrtBCI = { 1, 4, 1700, 32, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo sg_emlrtBCI = { 1, 101, 1700, 58, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo tg_emlrtBCI = { 1, 4, 1701, 100, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ug_emlrtBCI = { 1, 101, 1701, 126, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo vg_emlrtBCI = { 1, 4, 1701, 33, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo wg_emlrtBCI = { 1, 101, 1701, 59, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo xg_emlrtBCI = { 1, 4, 1711, 63, "CostStage.Cont",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo yg_emlrtBCI = { 1, 4, 1712, 63, "CostStage.FutCont",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ah_emlrtBCI = { 1, 4, 1713, 103, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo bh_emlrtBCI = { 1, 101, 1713, 129, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ch_emlrtBCI = { 1, 4, 1713, 36, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo dh_emlrtBCI = { 1, 101, 1713, 62, "PaymentType.Cancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo eh_emlrtBCI = { 1, 4, 1715, 116, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo fh_emlrtBCI = { 1, 101, 1715, 142, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo gh_emlrtBCI = { 1, 20, 1715, 156, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo hh_emlrtBCI = { 1, 4, 1715, 41, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ih_emlrtBCI = { 1, 101, 1715, 67, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo jh_emlrtBCI = { 1, 20, 1715, 81, "PaymentType.QCancer_con",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo kh_emlrtBCI = { 1, 4, 1692, 47, "CostStage.Initial",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo lh_emlrtBCI = { 1, 25, 1692, 17, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo mh_emlrtBCI = { 1, 404, 1692, 22, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo vb_emlrtDCI = { 1692, 22, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo nh_emlrtBCI = { 1, 4, 1693, 47, "CostStage.FutInitial",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo oh_emlrtBCI = { 1, 404, 1693, 25, "SubCostFut",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo wb_emlrtDCI = { 1693, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo ph_emlrtBCI = { 1, 4, 1694, 97, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo qh_emlrtBCI = { 1, 101, 1694, 123, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo rh_emlrtBCI = { 1, 4, 1694, 32, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo sh_emlrtBCI = { 1, 101, 1694, 58, "PaymentType.Cancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo th_emlrtBCI = { 1, 4, 1695, 101, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo uh_emlrtBCI = { 1, 101, 1695, 127, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo vh_emlrtBCI = { 1, 4, 1695, 33, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo wh_emlrtBCI = { 1, 101, 1695, 59, "PaymentType.QCancer_ini",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo xh_emlrtBCI = { 1, 404, 1745, 28, "SubCostFut",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo xb_emlrtDCI = { 1745, 28, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo yh_emlrtBCI = { 1, 404, 1705, 28, "SubCostFut",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo yb_emlrtDCI = { 1705, 28, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo ai_emlrtBCI = { 1, 404, 1744, 25, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo ac_emlrtDCI = { 1744, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo bi_emlrtBCI = { 1, 404, 1704, 25, "SubCost",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo bc_emlrtDCI = { 1704, 25, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtRTEInfo i_emlrtRTEI = { 1707, 13, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo ci_emlrtBCI = { 1, 4, 1744, 63, "CostStage.Final",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo di_emlrtBCI = { 1, 4, 1745, 63, "CostStage.FutFinal",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ei_emlrtBCI = { 1, 4, 1746, 102, "PaymentType.Cancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo fi_emlrtBCI = { 1, 101, 1746, 127, "PaymentType.Cancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo gi_emlrtBCI = { 1, 4, 1746, 36, "PaymentType.Cancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo hi_emlrtBCI = { 1, 101, 1746, 62, "PaymentType.Cancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ii_emlrtBCI = { 1, 4, 1748, 116, "PaymentType.QCancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ji_emlrtBCI = { 1, 101, 1748, 142, "PaymentType.QCancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ki_emlrtBCI = { 1, 4, 1748, 41, "PaymentType.QCancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo li_emlrtBCI = { 1, 101, 1748, 67, "PaymentType.QCancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo mi_emlrtBCI = { 1, 4, 1704, 63, "CostStage.Final",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ni_emlrtBCI = { 1, 4, 1705, 63, "CostStage.FutFinal",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo oi_emlrtBCI = { 1, 4, 1706, 103, "PaymentType.Cancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo pi_emlrtBCI = { 1, 101, 1706, 129, "PaymentType.Cancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo qi_emlrtBCI = { 1, 4, 1706, 36, "PaymentType.Cancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ri_emlrtBCI = { 1, 101, 1706, 62, "PaymentType.Cancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo si_emlrtBCI = { 1, 4, 1708, 116, "PaymentType.QCancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ti_emlrtBCI = { 1, 101, 1708, 142, "PaymentType.QCancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ui_emlrtBCI = { 1, 4, 1708, 156, "PaymentType.QCancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo vi_emlrtBCI = { 1, 4, 1708, 41, "PaymentType.QCancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo wi_emlrtBCI = { 1, 101, 1708, 67, "PaymentType.QCancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo xi_emlrtBCI = { 1, 4, 1708, 81, "PaymentType.QCancer_fin",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo r_emlrtECI = { -1, 1415, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo yi_emlrtBCI = { 1, 25, 1415, 57, "Ca.TimeStage_III",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo s_emlrtECI = { -1, 1414, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo aj_emlrtBCI = { 1, 25, 1414, 56, "Ca.TimeStage_II",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo t_emlrtECI = { -1, 1413, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo bj_emlrtBCI = { 1, 25, 1413, 55, "Ca.TimeStage_I",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo u_emlrtECI = { -1, 1412, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo cj_emlrtBCI = { 1, 25, 1412, 53, "Ca.SympStage",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo v_emlrtECI = { -1, 1411, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo dj_emlrtBCI = { 1, 25, 1411, 52, "Ca.SympTime",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo w_emlrtECI = { -1, 1410, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo ej_emlrtBCI = { 1, 25, 1410, 48, "Ca.DwellTime",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo x_emlrtECI = { -1, 1409, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo fj_emlrtBCI = { 1, 25, 1409, 58, "Ca.CancerLocation",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo y_emlrtECI = { -1, 1408, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo gj_emlrtBCI = { 1, 25, 1408, 54, "Ca.CancerYear",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo ab_emlrtECI = { -1, 1407, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo hj_emlrtBCI = { 1, 25, 1407, 50, "Ca.Cancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ij_emlrtBCI = { 1, 13, 1386, 13, "CurrentReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo cc_emlrtDCI = { 1386, 13, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtRTEInfo j_emlrtRTEI = { 1383, 1, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtECInfo bb_emlrtECI = { -1, 1347, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo jj_emlrtBCI = { 1, 51, 1347, 66, "Polyp.AdvProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo cb_emlrtECI = { -1, 1346, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo kj_emlrtBCI = { 1, 51, 1346, 68, "Polyp.EarlyProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo db_emlrtECI = { -1, 1345, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo lj_emlrtBCI = { 1, 51, 1345, 65, "Polyp.PolypLocation",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo eb_emlrtECI = { -1, 1344, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo mj_emlrtBCI = { 1, 51, 1344, 61, "Polyp.PolypYear",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo fb_emlrtECI = { -1, 1343, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo nj_emlrtBCI = { 1, 51, 1343, 58, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo oj_emlrtBCI = { 1, 13, 1340, 13, "CurrentReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo dc_emlrtDCI = { 1340, 13, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo pj_emlrtBCI = { 1, 13, 1333, 1, "CurrentReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtRTEInfo k_emlrtRTEI = { 1336, 1, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo qj_emlrtBCI = { 1, 1000, 1331, 16, "ColoReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo ec_emlrtDCI = { 1331, 16, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo rj_emlrtBCI = { 1, 5000, 1443, 26, "TumorRecord.Stage",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo sj_emlrtBCI = { 1, 25, 1384, 26, "Ca.Cancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo tj_emlrtBCI = { 1, 10, 1385, 19,
  "StageVariables.Colo_Detection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo uj_emlrtBCI = { 1, 50, 1393, 28, "Detected.Cancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo vj_emlrtBCI = { 1, 4, 1396, 59, "MortalityMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo wj_emlrtBCI = { 1, 1000, 1396, 81, "MortalityMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo fc_emlrtDCI = { 1396, 81, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo xj_emlrtBCI = { 1, 51, 1337, 29, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo yj_emlrtBCI = { 1, 10, 1338, 19,
  "StageVariables.Colo_Detection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo ak_emlrtBCI = { 1, 13, 1339, 13, "Location.ColoDetection",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo gc_emlrtDCI = { 1339, 13, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtDCInfo hc_emlrtDCI = { 1528, 16, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo bk_emlrtBCI = { 1, 1000, 1528, 16, "RectoSigmoReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtRTEInfo l_emlrtRTEI = { 1536, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo ck_emlrtBCI = { 1, 51, 1537, 37, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo dk_emlrtBCI = { 1, 13, 1530, 1, "CurrentReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo ic_emlrtDCI = { 1540, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo ek_emlrtBCI = { 1, 13, 1540, 21, "CurrentReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtRTEInfo m_emlrtRTEI = { 1555, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtDCInfo jc_emlrtDCI = { 1559, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo fk_emlrtBCI = { 1, 13, 1559, 21, "CurrentReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo gk_emlrtBCI = { 1, 51, 1570, 70, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo gb_emlrtECI = { -1, 1570, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo hk_emlrtBCI = { 1, 51, 1571, 73, "Polyp.PolypYear",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo hb_emlrtECI = { -1, 1571, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo ik_emlrtBCI = { 1, 51, 1572, 77, "Polyp.PolypLocation",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo ib_emlrtECI = { -1, 1572, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo jk_emlrtBCI = { 1, 51, 1573, 80, "Polyp.EarlyProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo jb_emlrtECI = { -1, 1573, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo kk_emlrtBCI = { 1, 51, 1574, 78, "Polyp.AdvProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo kb_emlrtECI = { -1, 1574, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRTEInfo n_emlrtRTEI = { 1582, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo lk_emlrtBCI = { 1, 51, 1583, 37, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo kc_emlrtDCI = { 1586, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo mk_emlrtBCI = { 1, 13, 1586, 21, "CurrentReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo nk_emlrtBCI = { 1, 51, 1595, 70, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo lb_emlrtECI = { -1, 1595, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo ok_emlrtBCI = { 1, 51, 1596, 73, "Polyp.PolypYear",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo mb_emlrtECI = { -1, 1596, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo pk_emlrtBCI = { 1, 51, 1597, 77, "Polyp.PolypLocation",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo nb_emlrtECI = { -1, 1597, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo qk_emlrtBCI = { 1, 51, 1598, 80, "Polyp.EarlyProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo ob_emlrtECI = { -1, 1598, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo rk_emlrtBCI = { 1, 51, 1599, 78, "Polyp.AdvProgression",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtECInfo pb_emlrtECI = { -1, 1599, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtRTEInfo o_emlrtRTEI = { 1604, 9, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo sk_emlrtBCI = { 1, 51, 1605, 37, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo lc_emlrtDCI = { 1608, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo tk_emlrtBCI = { 1, 13, 1608, 21, "CurrentReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtRTEInfo p_emlrtRTEI = { 1621, 1, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

static emlrtBCInfo uk_emlrtBCI = { 1, 25, 1622, 26, "Ca.Cancer",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo mc_emlrtDCI = { 1624, 13, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo vk_emlrtBCI = { 1, 13, 1624, 13, "CurrentReachMatrix",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo wk_emlrtBCI = { 1, 10, 1606, 27,
  "StageVariables.RectoSigmo_Detection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo xk_emlrtBCI = { 1, 13, 1607, 21,
  "Location.RectoSigmoDetection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo nc_emlrtDCI = { 1607, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo yk_emlrtBCI = { 1, 10, 1584, 27,
  "StageVariables.RectoSigmo_Detection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo al_emlrtBCI = { 1, 13, 1585, 21,
  "Location.RectoSigmoDetection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo oc_emlrtDCI = { 1585, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo bl_emlrtBCI = { 1, 51, 1556, 37, "Polyp.Polyps",
  "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo cl_emlrtBCI = { 1, 10, 1557, 27,
  "StageVariables.RectoSigmo_Detection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo dl_emlrtBCI = { 1, 13, 1558, 21,
  "Location.RectoSigmoDetection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo pc_emlrtDCI = { 1558, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtBCInfo el_emlrtBCI = { 1, 10, 1623, 19,
  "StageVariables.RectoSigmo_Detection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo fl_emlrtBCI = { 1, 10, 1538, 27,
  "StageVariables.RectoSigmo_Detection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtBCInfo gl_emlrtBCI = { 1, 13, 1539, 21,
  "Location.RectoSigmoDetection", "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 0 };

static emlrtDCInfo qc_emlrtDCI = { 1539, 21, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m", 1 };

static emlrtRSInfo gd_emlrtRSI = { 1278, "NumberCrunching_50000",
  "U:\\CMOST\\CMOST_01_August_2016\\NumberCrunching_50000.m" };

/* Function Declarations */
static void AddCosts(NumberCrunching_50000StackData *SD, const emlrtStack *sp,
                     const real_T Detected_Cancer[2500000], const real_T
                     Detected_CancerYear[2500000], const real_T
                     CostStage_Initial[4], const real_T CostStage_Cont[4], const
                     real_T CostStage_FutInitial[4], const real_T
                     CostStage_FutCont[4], struct10_T *PaymentType, struct11_T
                     *Money, real_T time, real_T z);
static void Colonoscopy(NumberCrunching_50000StackData *SD, const emlrtStack *sp,
  real_T z, real_T y, real_T q, const real_T Gender[50000], b_struct_T *Polyp,
  c_struct_T *Ca, struct_T *Detected, boolean_T Included[50000], real_T
  DeathCause[50000], real_T DeathYear[50000], real_T DiagnosedCancer[5000000],
  real_T AdvancedPolypsRemoved[100], real_T EarlyPolypsRemoved[100], struct8_T
  *Last, struct9_T *TumorRecord, struct10_T *PaymentType, struct11_T *Money,
  const struct0_T *StageVariables, const struct2_T *Cost, const struct1_T
  *Location, const struct4_T risc, const real_T ColoReachMatrix[1000], const
  real_T MortalityMatrix[400000], const struct3_T *CostStage);
static void RectoSigmo(const emlrtStack *sp, real_T z, real_T y, b_struct_T
  *Polyp, const real_T Ca_Cancer[1250000], const real_T Ca_CancerLocation
  [1250000], boolean_T Included[50000], real_T DeathCause[50000], real_T
  DeathYear[50000], struct10_T *PaymentType, struct11_T *Money, const real_T
  c_StageVariables_RectoSigmo_Det[10], real_T Cost_Sigmoidoscopy, real_T
  Cost_Sigmoidoscopy_Polyp, real_T Cost_Colonoscopy_Perforation, const real_T
  Location_RectoSigmoDetection[13], const struct4_T risc, const real_T
  RectoSigmoReachMatrix[1000], const struct5_T flag, real_T *PolypFlag, real_T
  *AdvPolypFlag, real_T *CancerFlag);
static void b_AddCosts(NumberCrunching_50000StackData *SD, const emlrtStack *sp,
  const real_T Detected_Cancer[2500000], const real_T Detected_CancerYear
  [2500000], const real_T CostStage_Initial[4], const real_T CostStage_Cont[4],
  const real_T CostStage_Final[4], const real_T CostStage_FutInitial[4], const
  real_T CostStage_FutCont[4], const real_T CostStage_FutFinal[4], struct10_T
  *PaymentType, struct11_T *Money, real_T time, real_T z);
static void b_Colonoscopy(NumberCrunching_50000StackData *SD, const emlrtStack
  *sp, real_T z, real_T y, real_T q, const real_T Gender[50000], b_struct_T
  *Polyp, c_struct_T *Ca, struct_T *Detected, boolean_T Included[50000], real_T
  DeathCause[50000], real_T DeathYear[50000], real_T DiagnosedCancer[5000000],
  real_T AdvancedPolypsRemoved[100], real_T EarlyPolypsRemoved[100], struct8_T
  *Last, struct9_T *TumorRecord, struct10_T *PaymentType, struct11_T *Money,
  const struct0_T *StageVariables, const struct2_T *Cost, const struct1_T
  *Location, const struct4_T risc, const real_T ColoReachMatrix[1000], const
  real_T MortalityMatrix[400000], const struct3_T *CostStage);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void c_Colonoscopy(NumberCrunching_50000StackData *SD, const emlrtStack
  *sp, real_T z, real_T y, real_T q, const real_T Gender[50000], b_struct_T
  *Polyp, c_struct_T *Ca, struct_T *Detected, boolean_T Included[50000], real_T
  DeathCause[50000], real_T DeathYear[50000], real_T DiagnosedCancer[5000000],
  real_T AdvancedPolypsRemoved[100], real_T EarlyPolypsRemoved[100], struct8_T
  *Last, struct9_T *TumorRecord, struct10_T *PaymentType, struct11_T *Money,
  const struct0_T *StageVariables, const struct2_T *Cost, const struct1_T
  *Location, const struct4_T risc, const real_T ColoReachMatrix[1000], const
  real_T MortalityMatrix[400000], const struct3_T *CostStage);
static void display(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const char_T u[19]);

/* Function Definitions */
static void AddCosts(NumberCrunching_50000StackData *SD, const emlrtStack *sp,
                     const real_T Detected_Cancer[2500000], const real_T
                     Detected_CancerYear[2500000], const real_T
                     CostStage_Initial[4], const real_T CostStage_Cont[4], const
                     real_T CostStage_FutInitial[4], const real_T
                     CostStage_FutCont[4], struct10_T *PaymentType, struct11_T
                     *Money, real_T time, real_T z)
{
  int32_T i13;
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T ii_size_idx_1;
  int32_T x1;
  real_T Start;
  real_T Difference;
  int32_T i14;
  real_T d0;
  int32_T i15;
  real_T d1;
  int32_T Qcount;
  int32_T yyears;
  real_T qquarters;
  int32_T con_y;
  int32_T b_con_y;
  int32_T b_Qcount;
  int32_T i16;
  real_T SubCostAll[404];
  real_T SubCostAllFut[404];
  int32_T Counter;
  int32_T x2;

  /*  in this case a cancer has been diagnosed and */
  /*  we need to take care of the costs */
  /*  for temporary calculations */
  for (i13 = 0; i13 < 10100; i13++) {
    SD->u1.f0.SubCost[i13] = 0.0;
    SD->u1.f0.SubCostFut[i13] = 0.0;
  }

  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 51)) {
    guard1 = false;
    if (Detected_Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
      idx++;
      if (idx >= 50) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (1 > idx) {
    ii_size_idx_1 = 0;
  } else {
    ii_size_idx_1 = idx;
  }

  /*  we add the cost for the rest of the */
  /*  treatment time */
  x1 = 0;
  while (x1 <= ii_size_idx_1 - 1) {
    Start = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1];
    Difference = time - Detected_CancerYear[((int32_T)z + 50000 * x1) - 1];

    /*  costs differ dependent if patient died of tumor or of other causes */
    /*      if isequal(mode, 'oc') % died of other causes */
    /*          FinalCosts    = CostStage.Final_oc(Detected.Cancer(z, x1)-6);  */
    /*          FutFinalCosts = CostStage.FutFinal_oc(Detected.Cancer(z, x1)-6);  */
    /*      else */
    /*          FinalCosts    = CostStage.Final(Detected.Cancer(z, x1)-6); % patient died of tumor */
    /*          FutFinalCosts = CostStage.FutFinal(Detected.Cancer(z, x1)-6); % patient died of tumor */
    /*      end */
    /*  all other tumors */
    /* m for the costs, the following changes are made: */
    /* m after 5 years, the treatment is discontinued */
    /* m during the 5 years of treatment if the death is due to other */
    /* reasons, these costs are not included */
    /* m the initial phase is for 3 months, and the remaining time until the */
    /* terminal or the 5th year are the continuing costs. */
    if (Difference <= 0.25) {
      /*  the costs for the first year of treatment apply, independent */
      /*  whether the patient survived a full year or not */
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &kh_emlrtBCI, sp);
      }

      i14 = 1 + x1;
      if (!((i14 >= 1) && (i14 <= 25))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 25, &lh_emlrtBCI, sp);
      }

      d0 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, &vb_emlrtDCI, sp);
      }

      i15 = (int32_T)d0;
      if (!((i15 >= 1) && (i15 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 404, &mh_emlrtBCI, sp);
      }

      SD->u1.f0.SubCost[(i14 + 25 * (i15 - 1)) - 1] = CostStage_Initial[i13 - 1];

      /*  START */
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &nh_emlrtBCI, sp);
      }

      d0 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, &wb_emlrtDCI, sp);
      }

      i14 = (int32_T)d0;
      if (!((i14 >= 1) && (i14 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &oh_emlrtBCI, sp);
      }

      SD->u1.f0.SubCostFut[x1 + 25 * (i14 - 1)] = CostStage_FutInitial[i13 - 1];
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &ph_emlrtBCI, sp);
      }

      i14 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i14 >= 1) && (i14 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &qh_emlrtBCI, sp);
      }

      i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i15 >= 1) && (i15 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &rh_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &sh_emlrtBCI, sp);
      }

      PaymentType->Cancer_ini[(i15 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_ini[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &th_emlrtBCI, sp);
      }

      i14 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i14 >= 1) && (i14 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &uh_emlrtBCI, sp);
      }

      i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i15 >= 1) && (i15 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &vh_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &wh_emlrtBCI, sp);
      }

      PaymentType->QCancer_ini[(i15 + ((idx - 1) << 2)) - 1] =
        PaymentType->QCancer_ini[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;
    } else if ((Difference > 0.25) && (Difference <= 1.25)) {
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &kg_emlrtBCI, sp);
      }

      i14 = 1 + x1;
      if (!((i14 >= 1) && (i14 <= 25))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 25, &lg_emlrtBCI, sp);
      }

      d0 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, &tb_emlrtDCI, sp);
      }

      i15 = (int32_T)d0;
      if (!((i15 >= 1) && (i15 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 404, &mg_emlrtBCI, sp);
      }

      SD->u1.f0.SubCost[(i14 + 25 * (i15 - 1)) - 1] = CostStage_Initial[i13 - 1];
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &ng_emlrtBCI, sp);
      }

      d0 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, &ub_emlrtDCI, sp);
      }

      i14 = (int32_T)d0;
      if (!((i14 >= 1) && (i14 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &og_emlrtBCI, sp);
      }

      SD->u1.f0.SubCostFut[x1 + 25 * (i14 - 1)] = CostStage_FutInitial[i13 - 1];
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &pg_emlrtBCI, sp);
      }

      i14 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i14 >= 1) && (i14 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &qg_emlrtBCI, sp);
      }

      i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i15 >= 1) && (i15 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &rg_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &sg_emlrtBCI, sp);
      }

      PaymentType->Cancer_ini[(i15 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_ini[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &tg_emlrtBCI, sp);
      }

      i14 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i14 >= 1) && (i14 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &ug_emlrtBCI, sp);
      }

      i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i15 >= 1) && (i15 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &vg_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &wg_emlrtBCI, sp);
      }

      PaymentType->QCancer_ini[(i15 + ((idx - 1) << 2)) - 1] =
        PaymentType->QCancer_ini[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;
      d0 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
        1.0;
      d1 = time * 4.0;
      if (d0 > d1) {
        i13 = 0;
        i14 = 0;
      } else {
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &mb_emlrtDCI, sp);
        }

        i13 = (int32_T)d0;
        if (!((i13 >= 1) && (i13 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 404, &fd_emlrtBCI, sp);
        }

        i13--;
        if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
          emlrtIntegerCheckR2012b(d1, &mb_emlrtDCI, sp);
        }

        i14 = (int32_T)d1;
        if (!((i14 >= 1) && (i14 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &fd_emlrtBCI, sp);
        }
      }

      idx = i14 - i13;
      for (i14 = 0; i14 < idx; i14++) {
        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &xg_emlrtBCI, sp);
        }

        SD->u1.f0.SubCost[x1 + 25 * (i13 + i14)] = 0.25 * CostStage_Cont[i15 - 1];
      }

      /*  START */
      d0 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
        1.0;
      d1 = time * 4.0;
      if (d0 > d1) {
        i13 = 0;
        i14 = 0;
      } else {
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &ib_emlrtDCI, sp);
        }

        i13 = (int32_T)d0;
        if (!((i13 >= 1) && (i13 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 404, &bd_emlrtBCI, sp);
        }

        i13--;
        if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
          emlrtIntegerCheckR2012b(d1, &ib_emlrtDCI, sp);
        }

        i14 = (int32_T)d1;
        if (!((i14 >= 1) && (i14 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &bd_emlrtBCI, sp);
        }
      }

      idx = i14 - i13;
      for (i14 = 0; i14 < idx; i14++) {
        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &yg_emlrtBCI, sp);
        }

        SD->u1.f0.SubCostFut[x1 + 25 * (i13 + i14)] = 0.25 *
          CostStage_FutCont[i15 - 1];
      }

      /*  START */
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &ah_emlrtBCI, sp);
      }

      i14 = (int32_T)muDoubleScalarFloor(time - 1.0);
      if (!((i14 >= 1) && (i14 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &bh_emlrtBCI, sp);
      }

      i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i15 >= 1) && (i15 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &ch_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(time - 1.0);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &dh_emlrtBCI, sp);
      }

      PaymentType->Cancer_con[(i15 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_con[(i13 + ((i14 - 1) << 2)) - 1] + (4.0 * time -
        (4.0 * Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] + 1.0)) / 4.0;

      /* m2 ini is for q1, and the cont is for rest. but to keep it all integers, I use y */
      d0 = 4.0 * time - (4.0 * Detected_CancerYear[((int32_T)z + 50000 * x1) - 1]
                         + 1.0);
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, d0, mxDOUBLE_CLASS, (int32_T)d0,
        &h_emlrtRTEI, sp);
      Qcount = 1;
      while (Qcount - 1 <= (int32_T)d0 - 1) {
        i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i13 >= 1) && (i13 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &eh_emlrtBCI, sp);
        }

        i14 = (int32_T)muDoubleScalarFloor(time - 1.0);
        if (!((i14 >= 1) && (i14 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &fh_emlrtBCI, sp);
        }

        if (!((Qcount >= 1) && (Qcount <= 20))) {
          emlrtDynamicBoundsCheckR2012b(Qcount, 1, 20, &gh_emlrtBCI, sp);
        }

        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &hh_emlrtBCI, sp);
        }

        idx = (int32_T)muDoubleScalarFloor(time - 1.0);
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ih_emlrtBCI, sp);
        }

        if (!((Qcount >= 1) && (Qcount <= 20))) {
          emlrtDynamicBoundsCheckR2012b(Qcount, 1, 20, &jh_emlrtBCI, sp);
        }

        PaymentType->QCancer_con[((i15 + ((idx - 1) << 2)) + 404 * (Qcount - 1))
          - 1] = PaymentType->QCancer_con[((i13 + ((i14 - 1) << 2)) + 404 *
          (Qcount - 1)) - 1] + 1.0;

        /* m2 this finQ is counting in quarters */
        Qcount++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } else if ((Difference > 1.25) && (Difference <= 5.0)) {
      /* m new costs treatment o */
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &pe_emlrtBCI, sp);
      }

      i14 = 1 + x1;
      if (!((i14 >= 1) && (i14 <= 25))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 25, &qe_emlrtBCI, sp);
      }

      d0 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, &pb_emlrtDCI, sp);
      }

      i15 = (int32_T)d0;
      if (!((i15 >= 1) && (i15 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 404, &re_emlrtBCI, sp);
      }

      SD->u1.f0.SubCost[(i14 + 25 * (i15 - 1)) - 1] = CostStage_Initial[i13 - 1];
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &se_emlrtBCI, sp);
      }

      d0 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, &qb_emlrtDCI, sp);
      }

      i14 = (int32_T)d0;
      if (!((i14 >= 1) && (i14 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &te_emlrtBCI, sp);
      }

      SD->u1.f0.SubCostFut[x1 + 25 * (i14 - 1)] = CostStage_FutInitial[i13 - 1];
      d0 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
        1.0;
      d1 = (time - 1.0) * 4.0;
      if (d0 > d1) {
        i13 = 0;
        i14 = 0;
      } else {
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &lb_emlrtDCI, sp);
        }

        i13 = (int32_T)d0;
        if (!((i13 >= 1) && (i13 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 404, &ed_emlrtBCI, sp);
        }

        i13--;
        if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
          emlrtIntegerCheckR2012b(d1, &lb_emlrtDCI, sp);
        }

        i14 = (int32_T)d1;
        if (!((i14 >= 1) && (i14 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &ed_emlrtBCI, sp);
        }
      }

      idx = i14 - i13;
      for (i14 = 0; i14 < idx; i14++) {
        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &ue_emlrtBCI, sp);
        }

        SD->u1.f0.SubCost[x1 + 25 * (i13 + i14)] = 0.25 * CostStage_Cont[i15 - 1];
      }

      /*  CONT */
      d0 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
        1.0;
      d1 = (time - 1.0) * 4.0;
      if (d0 > d1) {
        i13 = 0;
        i14 = 0;
      } else {
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &hb_emlrtDCI, sp);
        }

        i13 = (int32_T)d0;
        if (!((i13 >= 1) && (i13 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 404, &ad_emlrtBCI, sp);
        }

        i13--;
        if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
          emlrtIntegerCheckR2012b(d1, &hb_emlrtDCI, sp);
        }

        i14 = (int32_T)d1;
        if (!((i14 >= 1) && (i14 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &ad_emlrtBCI, sp);
        }
      }

      idx = i14 - i13;
      for (i14 = 0; i14 < idx; i14++) {
        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &ve_emlrtBCI, sp);
        }

        SD->u1.f0.SubCostFut[x1 + 25 * (i13 + i14)] = 0.25 *
          CostStage_FutCont[i15 - 1];
      }

      /*  CONT */
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &we_emlrtBCI, sp);
      }

      i14 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i14 >= 1) && (i14 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &xe_emlrtBCI, sp);
      }

      i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i15 >= 1) && (i15 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &ye_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &af_emlrtBCI, sp);
      }

      PaymentType->Cancer_ini[(i15 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_ini[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;
      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &bf_emlrtBCI, sp);
      }

      i14 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i14 >= 1) && (i14 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &cf_emlrtBCI, sp);
      }

      i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i15 >= 1) && (i15 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &df_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ef_emlrtBCI, sp);
      }

      PaymentType->QCancer_ini[(i15 + ((idx - 1) << 2)) - 1] =
        PaymentType->QCancer_ini[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;
      yyears = (int32_T)muDoubleScalarFloor(Difference - 1.25);
      qquarters = (Difference - 1.25) - muDoubleScalarFloor(Difference - 1.25);
      con_y = 1;
      b_con_y = 0;
      while (b_con_y <= yyears - 1) {
        con_y = 1 + b_con_y;
        i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i13 >= 1) && (i13 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &cg_emlrtBCI, sp);
        }

        i14 = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
        if (!((i14 >= 1) && (i14 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &dg_emlrtBCI, sp);
        }

        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &eg_emlrtBCI, sp);
        }

        idx = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &fg_emlrtBCI, sp);
        }

        PaymentType->Cancer_con[(i15 + ((idx - 1) << 2)) - 1] =
          PaymentType->Cancer_con[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;

        /* ((4*Ende-4*1)-(4*Start+1))/4; */
        i13 = ((1 + b_con_y) << 2) - 3;
        i14 = ((1 + b_con_y) << 2) - i13;
        Qcount = -1;
        while (Qcount + 1 <= i14) {
          b_Qcount = i13 + Qcount;
          i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i15 >= 1) && (i15 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &gg_emlrtBCI, sp);
          }

          idx = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
          if (!((idx >= 1) && (idx <= 101))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &hg_emlrtBCI, sp);
          }

          ii = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((ii >= 1) && (ii <= 4))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, 4, &ig_emlrtBCI, sp);
          }

          i16 = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
          if (!((i16 >= 1) && (i16 <= 101))) {
            emlrtDynamicBoundsCheckR2012b(i16, 1, 101, &jg_emlrtBCI, sp);
          }

          PaymentType->QCancer_con[((ii + ((i16 - 1) << 2)) + 404 * b_Qcount) -
            1] = PaymentType->QCancer_con[((i15 + ((idx - 1) << 2)) + 404 *
            b_Qcount) - 1] + 1.0;

          /* ((4*Ende-4*1)-(4*Start+1))/4; */
          Qcount++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        b_con_y++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &ff_emlrtBCI, sp);
      }

      i14 = (int32_T)((muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
        50000 * x1) - 1]) + (real_T)con_y) + 1.0);
      if (!((i14 >= 1) && (i14 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &gf_emlrtBCI, sp);
      }

      i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i15 >= 1) && (i15 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &hf_emlrtBCI, sp);
      }

      idx = (int32_T)((muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
        50000 * x1) - 1]) + (real_T)con_y) + 1.0);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &if_emlrtBCI, sp);
      }

      PaymentType->Cancer_con[(i15 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_con[(i13 + ((i14 - 1) << 2)) - 1] + qquarters;
      d0 = 4.0 * qquarters;
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, d0, mxDOUBLE_CLASS, (int32_T)d0,
        &g_emlrtRTEI, sp);
      Qcount = 1;
      while (Qcount - 1 <= (int32_T)d0 - 1) {
        i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i13 >= 1) && (i13 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &vf_emlrtBCI, sp);
        }

        i14 = (int32_T)((muDoubleScalarFloor(Start) + (real_T)con_y) + 1.0);
        if (!((i14 >= 1) && (i14 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &wf_emlrtBCI, sp);
        }

        i15 = (con_y << 2) + Qcount;
        if (!((i15 >= 1) && (i15 <= 20))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 20, &xf_emlrtBCI, sp);
        }

        idx = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((idx >= 1) && (idx <= 4))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 4, &yf_emlrtBCI, sp);
        }

        ii = (int32_T)((muDoubleScalarFloor(Start) + (real_T)con_y) + 1.0);
        if (!((ii >= 1) && (ii <= 101))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, 101, &ag_emlrtBCI, sp);
        }

        i16 = (con_y << 2) + Qcount;
        if (!((i16 >= 1) && (i16 <= 20))) {
          emlrtDynamicBoundsCheckR2012b(i16, 1, 20, &bg_emlrtBCI, sp);
        }

        PaymentType->QCancer_con[((idx + ((ii - 1) << 2)) + 404 * (i16 - 1)) - 1]
          = PaymentType->QCancer_con[((i13 + ((i14 - 1) << 2)) + 404 * (i15 - 1))
          - 1] + 1.0;

        /* ((4*Ende-4*1)-(4*Start+1))/4; */
        Qcount++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /* m PaymentType.Cancer_con(Detected.Cancer(z, x1)-6, floor(Start)) = PaymentType.Cancer_con(Detected.Cancer(z, x1)-6,floor(Start)) + ((4*Ende-4*1)-(4*Start+1))/4; */
      d0 = (time - 1.0) * 4.0 + 1.0;
      d1 = time * 4.0;
      if (d0 > d1) {
        i13 = 0;
        i14 = 0;
      } else {
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &kb_emlrtDCI, sp);
        }

        i13 = (int32_T)d0;
        if (!((i13 >= 1) && (i13 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 404, &dd_emlrtBCI, sp);
        }

        i13--;
        if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
          emlrtIntegerCheckR2012b(d1, &kb_emlrtDCI, sp);
        }

        i14 = (int32_T)d1;
        if (!((i14 >= 1) && (i14 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &dd_emlrtBCI, sp);
        }
      }

      idx = i14 - i13;
      for (i14 = 0; i14 < idx; i14++) {
        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &jf_emlrtBCI, sp);
        }

        SD->u1.f0.SubCost[x1 + 25 * (i13 + i14)] = 0.25 * CostStage_Cont[i15 - 1];
      }

      d0 = (time - 1.0) * 4.0 + 1.0;
      d1 = time * 4.0;
      if (d0 > d1) {
        i13 = 0;
        i14 = 0;
      } else {
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &gb_emlrtDCI, sp);
        }

        i13 = (int32_T)d0;
        if (!((i13 >= 1) && (i13 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 404, &yc_emlrtBCI, sp);
        }

        i13--;
        if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
          emlrtIntegerCheckR2012b(d1, &gb_emlrtDCI, sp);
        }

        i14 = (int32_T)d1;
        if (!((i14 >= 1) && (i14 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &yc_emlrtBCI, sp);
        }
      }

      idx = i14 - i13;
      for (i14 = 0; i14 < idx; i14++) {
        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &kf_emlrtBCI, sp);
        }

        SD->u1.f0.SubCostFut[x1 + 25 * (i13 + i14)] = 0.25 *
          CostStage_FutCont[i15 - 1];
      }

      i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i13 >= 1) && (i13 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &lf_emlrtBCI, sp);
      }

      i14 = (int32_T)(muDoubleScalarFloor(time) - 1.0);
      if (!((i14 >= 1) && (i14 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &mf_emlrtBCI, sp);
      }

      i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i15 >= 1) && (i15 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &nf_emlrtBCI, sp);
      }

      idx = (int32_T)(muDoubleScalarFloor(time) - 1.0);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &of_emlrtBCI, sp);
      }

      PaymentType->Cancer_con[(i15 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_con[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;
      Qcount = 0;
      while (Qcount < 4) {
        /* m8 (4*Ende-(4*Start+1)) %m here all 4 quarters of treatment are followed, unlike when difference<1.25 where only few quarters of final year are implemented */
        i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i13 >= 1) && (i13 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &pf_emlrtBCI, sp);
        }

        i14 = (int32_T)muDoubleScalarFloor(time - 1.0);
        if (!((i14 >= 1) && (i14 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &qf_emlrtBCI, sp);
        }

        d0 = ((real_T)con_y * 4.0 + qquarters * 4.0) + (1.0 + (real_T)Qcount);
        if (d0 != muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &rb_emlrtDCI, sp);
        }

        i15 = (int32_T)d0;
        if (!((i15 >= 1) && (i15 <= 20))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 20, &rf_emlrtBCI, sp);
        }

        idx = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((idx >= 1) && (idx <= 4))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 4, &sf_emlrtBCI, sp);
        }

        ii = (int32_T)muDoubleScalarFloor(time - 1.0);
        if (!((ii >= 1) && (ii <= 101))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, 101, &tf_emlrtBCI, sp);
        }

        d0 = ((real_T)con_y * 4.0 + qquarters * 4.0) + (1.0 + (real_T)Qcount);
        if (d0 != muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &sb_emlrtDCI, sp);
        }

        i16 = (int32_T)d0;
        if (!((i16 >= 1) && (i16 <= 20))) {
          emlrtDynamicBoundsCheckR2012b(i16, 1, 20, &uf_emlrtBCI, sp);
        }

        PaymentType->QCancer_con[((idx + ((ii - 1) << 2)) + 404 * (i16 - 1)) - 1]
          = PaymentType->QCancer_con[((i13 + ((i14 - 1) << 2)) + 404 * (i15 - 1))
          - 1] + 1.0;

        /* m2 this finQ is counting in quarters %m8 */
        Qcount++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } else {
      if (Difference > 5.0) {
        i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i13 >= 1) && (i13 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &hd_emlrtBCI, sp);
        }

        i14 = 1 + x1;
        if (!((i14 >= 1) && (i14 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 25, &id_emlrtBCI, sp);
        }

        d0 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &nb_emlrtDCI, sp);
        }

        i15 = (int32_T)d0;
        if (!((i15 >= 1) && (i15 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 404, &jd_emlrtBCI, sp);
        }

        SD->u1.f0.SubCost[(i14 + 25 * (i15 - 1)) - 1] = CostStage_Initial[i13 -
          1];
        i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i13 >= 1) && (i13 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &kd_emlrtBCI, sp);
        }

        d0 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &ob_emlrtDCI, sp);
        }

        i14 = (int32_T)d0;
        if (!((i14 >= 1) && (i14 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &ld_emlrtBCI, sp);
        }

        SD->u1.f0.SubCostFut[x1 + 25 * (i14 - 1)] = CostStage_FutInitial[i13 - 1];

        /* m8 SubCost(x1, (Start*4+1)+1 : (Start+5)*4)        = 1/4*CostStage.Cont(Detected.Cancer(z, x1)-6); % CONT */
        /* m8 SubCostFut(x1, (Start*4+1)+1 : (Start+5)*4)     = 1/4*CostStage.FutCont(Detected.Cancer(z, x1)-6); % CONT */
        d0 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
          1.0;
        d1 = time * 4.0;
        if (d0 > d1) {
          i13 = 0;
          i14 = 0;
        } else {
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &jb_emlrtDCI, sp);
          }

          i13 = (int32_T)d0;
          if (!((i13 >= 1) && (i13 <= 404))) {
            emlrtDynamicBoundsCheckR2012b(i13, 1, 404, &cd_emlrtBCI, sp);
          }

          i13--;
          if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
            emlrtIntegerCheckR2012b(d1, &jb_emlrtDCI, sp);
          }

          i14 = (int32_T)d1;
          if (!((i14 >= 1) && (i14 <= 404))) {
            emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &cd_emlrtBCI, sp);
          }
        }

        idx = i14 - i13;
        for (i14 = 0; i14 < idx; i14++) {
          i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i15 >= 1) && (i15 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &md_emlrtBCI, sp);
          }

          SD->u1.f0.SubCost[x1 + 25 * (i13 + i14)] = 0.25 * CostStage_Cont[i15 -
            1];
        }

        /*  CONT */
        d0 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
          1.0;
        d1 = time * 4.0;
        if (d0 > d1) {
          i13 = 0;
          i14 = 0;
        } else {
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &fb_emlrtDCI, sp);
          }

          i13 = (int32_T)d0;
          if (!((i13 >= 1) && (i13 <= 404))) {
            emlrtDynamicBoundsCheckR2012b(i13, 1, 404, &xc_emlrtBCI, sp);
          }

          i13--;
          if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
            emlrtIntegerCheckR2012b(d1, &fb_emlrtDCI, sp);
          }

          i14 = (int32_T)d1;
          if (!((i14 >= 1) && (i14 <= 404))) {
            emlrtDynamicBoundsCheckR2012b(i14, 1, 404, &xc_emlrtBCI, sp);
          }
        }

        idx = i14 - i13;
        for (i14 = 0; i14 < idx; i14++) {
          i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i15 >= 1) && (i15 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &nd_emlrtBCI, sp);
          }

          SD->u1.f0.SubCostFut[x1 + 25 * (i13 + i14)] = 0.25 *
            CostStage_FutCont[i15 - 1];
        }

        /*  CONT */
        i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i13 >= 1) && (i13 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &od_emlrtBCI, sp);
        }

        i14 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]);
        if (!((i14 >= 1) && (i14 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &pd_emlrtBCI, sp);
        }

        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &qd_emlrtBCI, sp);
        }

        idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]);
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &rd_emlrtBCI, sp);
        }

        PaymentType->Cancer_ini[(i15 + ((idx - 1) << 2)) - 1] =
          PaymentType->Cancer_ini[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;
        i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i13 >= 1) && (i13 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &sd_emlrtBCI, sp);
        }

        i14 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]);
        if (!((i14 >= 1) && (i14 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &td_emlrtBCI, sp);
        }

        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &ud_emlrtBCI, sp);
        }

        idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]);
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &vd_emlrtBCI, sp);
        }

        PaymentType->QCancer_ini[(i15 + ((idx - 1) << 2)) - 1] =
          PaymentType->QCancer_ini[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;

        /* m the following con_y is for all Difference. it must be just upto */
        /* year 5. So, yyears must be 5? */
        /* %m yyears = floor(Difference-1.25); */
        /* %m qquarters = (Difference-1.25) - floor(Difference-1.25); */
        con_y = 1;
        b_con_y = 0;
        while (b_con_y < 4) {
          con_y = 1 + b_con_y;

          /* %m yyears */
          i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i13 >= 1) && (i13 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &fe_emlrtBCI, sp);
          }

          i14 = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
          if (!((i14 >= 1) && (i14 <= 101))) {
            emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &ge_emlrtBCI, sp);
          }

          i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i15 >= 1) && (i15 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &he_emlrtBCI, sp);
          }

          idx = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
          if (!((idx >= 1) && (idx <= 101))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ie_emlrtBCI, sp);
          }

          PaymentType->Cancer_con[(i15 + ((idx - 1) << 2)) - 1] =
            PaymentType->Cancer_con[(i13 + ((i14 - 1) << 2)) - 1] + 1.0;

          /* ((4*Ende-4*1)-(4*Start+1))/4; */
          i13 = ((1 + b_con_y) << 2) - 3;
          i14 = ((1 + b_con_y) << 2) - i13;
          Qcount = 0;
          while (Qcount <= i14) {
            b_Qcount = i13 + Qcount;
            i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
            if (!((i15 >= 1) && (i15 <= 4))) {
              emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &je_emlrtBCI, sp);
            }

            idx = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
            if (!((idx >= 1) && (idx <= 101))) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ke_emlrtBCI, sp);
            }

            if (!(b_Qcount <= 20)) {
              emlrtDynamicBoundsCheckR2012b(b_Qcount, 1, 20, &le_emlrtBCI, sp);
            }

            ii = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
            if (!((ii >= 1) && (ii <= 4))) {
              emlrtDynamicBoundsCheckR2012b(ii, 1, 4, &me_emlrtBCI, sp);
            }

            i16 = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
            if (!((i16 >= 1) && (i16 <= 101))) {
              emlrtDynamicBoundsCheckR2012b(i16, 1, 101, &ne_emlrtBCI, sp);
            }

            if (!(b_Qcount <= 20)) {
              emlrtDynamicBoundsCheckR2012b(b_Qcount, 1, 20, &oe_emlrtBCI, sp);
            }

            PaymentType->QCancer_con[((ii + ((i16 - 1) << 2)) + 404 * (b_Qcount
              - 1)) - 1] = PaymentType->QCancer_con[((i15 + ((idx - 1) << 2)) +
              404 * (b_Qcount - 1)) - 1] + 1.0;

            /* ((4*Ende-4*1)-(4*Start+1))/4; */
            Qcount++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
          }

          b_con_y++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i13 >= 1) && (i13 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &wd_emlrtBCI, sp);
        }

        i14 = (int32_T)((muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]) + (real_T)con_y) + 1.0);
        if (!((i14 >= 1) && (i14 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &xd_emlrtBCI, sp);
        }

        i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i15 >= 1) && (i15 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &yd_emlrtBCI, sp);
        }

        idx = (int32_T)((muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]) + (real_T)con_y) + 1.0);
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ae_emlrtBCI, sp);
        }

        PaymentType->Cancer_con[(i15 + ((idx - 1) << 2)) - 1] =
          PaymentType->Cancer_con[(i13 + ((i14 - 1) << 2)) - 1] + 0.75;
        Qcount = 0;
        while (Qcount < 3) {
          i13 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i13 >= 1) && (i13 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i13, 1, 4, &be_emlrtBCI, sp);
          }

          i14 = (int32_T)((muDoubleScalarFloor(Start) + (real_T)con_y) + 1.0);
          if (!((i14 >= 1) && (i14 <= 101))) {
            emlrtDynamicBoundsCheckR2012b(i14, 1, 101, &ce_emlrtBCI, sp);
          }

          i15 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i15 >= 1) && (i15 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i15, 1, 4, &de_emlrtBCI, sp);
          }

          idx = (int32_T)((muDoubleScalarFloor(Start) + (real_T)con_y) + 1.0);
          if (!((idx >= 1) && (idx <= 101))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ee_emlrtBCI, sp);
          }

          PaymentType->QCancer_con[((i15 + ((idx - 1) << 2)) + 404 * Qcount) - 1]
            = PaymentType->QCancer_con[((i13 + ((i14 - 1) << 2)) + 404 * Qcount)
            - 1] + 1.0;

          /* ((4*Ende-4*1)-(4*Start+1))/4; */
          Qcount++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        /* m PaymentType.Cancer_con(Detected.Cancer(z, x1)-6, floor(Start))  = PaymentType.Cancer_con(Detected.Cancer(z, x1)-6, floor(Start)) + (4*Ende-(4*Start+1))/4; %m2 ini is for q1, and the cont is for rest. but to keep it all integers, I use y */
      }
    }

    x1++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  h_sum(SD->u1.f0.SubCost, SubCostAll);

  /* m2 sum(SubCost,1); remove max and add sum %max(SubCost)/4; % since all costs are quarterly we need to adjust %m3 and remove max() */
  h_sum(SD->u1.f0.SubCostFut, SubCostAllFut);

  /*  since all costs are quarterly we need to adjust %m3 */
  Counter = 1;
  x1 = 0;
  while (x1 < 100) {
    x2 = 0;
    while (x2 < 4) {
      if (!((Counter >= 1) && (Counter <= 404))) {
        emlrtDynamicBoundsCheckR2012b(Counter, 1, 404, &gd_emlrtBCI, sp);
      }

      Money->Treatment[x1] += SubCostAll[Counter - 1];
      Money->FutureTreatment[x1] += SubCostAllFut[Counter - 1];
      Counter++;
      x2++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    x1++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

static void Colonoscopy(NumberCrunching_50000StackData *SD, const emlrtStack *sp,
  real_T z, real_T y, real_T q, const real_T Gender[50000], b_struct_T *Polyp,
  c_struct_T *Ca, struct_T *Detected, boolean_T Included[50000], real_T
  DeathCause[50000], real_T DeathYear[50000], real_T DiagnosedCancer[5000000],
  real_T AdvancedPolypsRemoved[100], real_T EarlyPolypsRemoved[100], struct8_T
  *Last, struct9_T *TumorRecord, struct10_T *PaymentType, struct11_T *Money,
  const struct0_T *StageVariables, const struct2_T *Cost, const struct1_T
  *Location, const struct4_T risc, const real_T ColoReachMatrix[1000], const
  real_T MortalityMatrix[400000], const struct3_T *CostStage)
{
  real_T x;
  real_T b_x;
  int32_T i21;
  int8_T CurrentReachMatrix[13];
  int32_T idx;
  int32_T ii;
  int32_T i22;
  int32_T tmp_data[13];
  real_T counter;
  boolean_T exitg6;
  boolean_T guard6 = false;
  int32_T i23;
  int32_T f;
  int32_T b_f;
  real_T Tumor;
  boolean_T b2;
  boolean_T exitg5;
  boolean_T guard5 = false;
  int32_T ii_size_idx_1;
  int32_T i24;
  int32_T i25;
  int32_T i26;
  int32_T b_tmp_data[51];
  int32_T b_Ca[2];
  int32_T Polyp_size[2];
  int32_T b_Polyp[2];
  real_T Polyp_data[51];
  int32_T iv84[2];
  int32_T b_Polyp_size[2];
  int32_T iv85[2];
  int32_T c_Polyp_size[2];
  int32_T iv86[2];
  int32_T d_Polyp_size[2];
  int32_T iv87[2];
  int32_T e_Polyp_size[2];
  real_T StageTmp;
  real_T EStage;
  real_T ELocation;
  real_T ESojourn;
  real_T EDwellTime;
  real_T LocationTmp;
  real_T SojournTmp;
  real_T DwellTimeTmp;
  boolean_T exitg4;
  boolean_T guard4 = false;
  int32_T i27;
  boolean_T exitg3;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T c_tmp_data[25];
  int32_T iv88[2];
  int32_T Ca_size[2];
  real_T Ca_data[25];
  int32_T iv89[2];
  int32_T b_Ca_size[2];
  int32_T iv90[2];
  int32_T c_Ca_size[2];
  int32_T iv91[2];
  int32_T d_Ca_size[2];
  int32_T iv92[2];
  int32_T e_Ca_size[2];
  int32_T iv93[2];
  int32_T f_Ca_size[2];
  int32_T iv94[2];
  int32_T g_Ca_size[2];
  int32_T iv95[2];
  int32_T h_Ca_size[2];
  int32_T iv96[2];
  int32_T i_Ca_size[2];
  boolean_T exitg1;
  boolean_T guard1 = false;
  real_T factor;
  real_T moneyspent;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  display(sprintf('In RS-Study %d patients excluded due to Ca, %d due to Kolo, %d due to past polyps',... */
  /*      AusschlussCa, AusschlussKolo, AusschlussPolyp))  */
  /*  display(sprintf('In RS-examinations %d times polyps, %d times cancer and %d times polyps and cancer found',... */
  /*      PosCa, PosPolyp, PosPolypCa)) */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%         COLONOSCOPY                               %%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  */
  /*  in this function we do a colonoscopy for the respective patient (number */
  /*  z). We cure all detected polyps, and handle the case if a cancer was */
  /*  detected */
  /*  we determine the reach of this colonoscopy (cecum = 1, rectum = 13)) */
  x = b_rand() * 999.0 + 1.0;
  b_x = muDoubleScalarRound(x);
  x = muDoubleScalarRound(x);
  if (x != (int32_T)muDoubleScalarFloor(x)) {
    emlrtIntegerCheckR2012b(x, &ec_emlrtDCI, sp);
  }

  i21 = (int32_T)x;
  if (!((i21 >= 1) && (i21 <= 1000))) {
    emlrtDynamicBoundsCheckR2012b(i21, 1, 1000, &qj_emlrtBCI, sp);
  }

  for (i21 = 0; i21 < 13; i21++) {
    CurrentReachMatrix[i21] = 0;
  }

  if (ColoReachMatrix[(int32_T)b_x - 1] > 13.0) {
    i21 = 0;
    idx = -1;
  } else {
    i21 = (int32_T)ColoReachMatrix[(int32_T)b_x - 1];
    if (!((i21 >= 1) && (i21 <= 13))) {
      emlrtDynamicBoundsCheckR2012b(i21, 1, 13, &pj_emlrtBCI, sp);
    }

    i21--;
    idx = 12;
  }

  ii = idx - i21;
  for (i22 = 0; i22 <= ii; i22++) {
    tmp_data[i22] = i21 + i22;
  }

  ii = (idx - i21) + 1;
  for (i21 = 0; i21 < ii; i21++) {
    CurrentReachMatrix[tmp_data[i21]] = 1;
  }

  counter = 0.0;
  idx = 0;
  ii = 1;
  exitg6 = false;
  while ((!exitg6) && (ii < 52)) {
    guard6 = false;
    if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
      idx++;
      if (idx >= 51) {
        exitg6 = true;
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6) {
      ii++;
    }
  }

  if (1 > idx) {
    i21 = 0;
  } else {
    i21 = idx;
  }

  if (1 > idx) {
    i23 = 0;
  } else {
    i23 = idx;
  }

  emlrtForLoopVectorCheckR2012b(i23, -1.0, 1.0, mxDOUBLE_CLASS, i21,
    &k_emlrtRTEI, sp);
  f = 0;
  while (f <= i21 - 1) {
    b_f = i21 - f;
    if (!((b_f >= 1) && (b_f <= 51))) {
      emlrtDynamicBoundsCheckR2012b(b_f, 1, 51, &xj_emlrtBCI, sp);
    }

    Tumor = Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1];

    /*     % influence of polyp stage */
    /*     % influence of location on detection */
    idx = (int32_T)Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (!((idx >= 1) && (idx <= 10))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &yj_emlrtBCI, sp);
    }

    x = Polyp->PolypLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (x != (int32_T)muDoubleScalarFloor(x)) {
      emlrtIntegerCheckR2012b(x, &gc_emlrtDCI, sp);
    }

    i22 = (int32_T)x;
    if (!((i22 >= 1) && (i22 <= 13))) {
      emlrtDynamicBoundsCheckR2012b(i22, 1, 13, &ak_emlrtBCI, sp);
    }

    b2 = (b_rand() < StageVariables->Colo_Detection[idx - 1] *
          Location->ColoDetection[i22 - 1]);
    x = Polyp->PolypLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (x != (int32_T)muDoubleScalarFloor(x)) {
      emlrtIntegerCheckR2012b(x, &dc_emlrtDCI, sp);
    }

    idx = (int32_T)x;
    if (!((idx >= 1) && (idx <= 13))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &oj_emlrtBCI, sp);
    }

    if (b2 && (CurrentReachMatrix[(int32_T)Polyp->PolypLocation[((int32_T)z +
          50000 * (b_f - 1)) - 1] - 1] == 1)) {
      /*  has current current colonoscopy reached location of polyp? */
      /*  we delete the current polyp */
      idx = 0;
      ii = 1;
      exitg5 = false;
      while ((!exitg5) && (ii < 52)) {
        guard5 = false;
        if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
          idx++;
          if (idx >= 51) {
            exitg5 = true;
          } else {
            guard5 = true;
          }
        } else {
          guard5 = true;
        }

        if (guard5) {
          ii++;
        }
      }

      if (1 > idx) {
        ii_size_idx_1 = 0;
      } else {
        ii_size_idx_1 = idx;
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &nj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &nj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        b_tmp_data[i26] = i24 + i26;
      }

      b_Ca[0] = 1;
      b_Ca[1] = i25 - i24;
      Polyp_size[0] = 1;
      Polyp_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Polyp[i24] = Polyp_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(b_Ca, 2, b_Polyp, 2, &fb_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Polyp_data[i24] = Polyp->Polyps[((int32_T)z + 50000 * (idx + i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->Polyps[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &mj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &mj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        b_tmp_data[i26] = i24 + i26;
      }

      iv84[0] = 1;
      iv84[1] = i25 - i24;
      b_Polyp_size[0] = 1;
      b_Polyp_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Polyp[i24] = b_Polyp_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv84, 2, b_Polyp, 2, &eb_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Polyp_data[i24] = Polyp->PolypYear[((int32_T)z + 50000 * (idx + i24)) -
          1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->PolypYear[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &lj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &lj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        b_tmp_data[i26] = i24 + i26;
      }

      iv85[0] = 1;
      iv85[1] = i25 - i24;
      c_Polyp_size[0] = 1;
      c_Polyp_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Polyp[i24] = c_Polyp_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv85, 2, b_Polyp, 2, &db_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Polyp_data[i24] = Polyp->PolypLocation[((int32_T)z + 50000 * (idx + i24))
          - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->PolypLocation[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &kj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &kj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        b_tmp_data[i26] = i24 + i26;
      }

      iv86[0] = 1;
      iv86[1] = i25 - i24;
      d_Polyp_size[0] = 1;
      d_Polyp_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Polyp[i24] = d_Polyp_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv86, 2, b_Polyp, 2, &cb_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Polyp_data[i24] = Polyp->EarlyProgression[((int32_T)z + 50000 * (idx +
          i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->EarlyProgression[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &jj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &jj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        ii_size_idx_1 = 0;
      } else {
        i24 = b_f - 1;
      }

      ii = ii_size_idx_1 - i24;
      for (i25 = 0; i25 < ii; i25++) {
        b_tmp_data[i25] = i24 + i25;
      }

      iv87[0] = 1;
      iv87[1] = ii_size_idx_1 - i24;
      e_Polyp_size[0] = 1;
      e_Polyp_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Polyp[i24] = e_Polyp_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv87, 2, b_Polyp, 2, &bb_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Polyp_data[i24] = Polyp->AdvProgression[((int32_T)z + 50000 * (idx + i24))
          - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->AdvProgression[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      counter++;
      if (Tumor > 4.0) {
        AdvancedPolypsRemoved[(int32_T)y - 1]++;
        Last->AdvPolyp[(int32_T)z - 1] = y;
      } else {
        Last->Polyp[(int32_T)z - 1] = y;
        EarlyPolypsRemoved[(int32_T)y - 1]++;
      }
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (counter > 2.0) {
    Last->AdvPolyp[(int32_T)z - 1] = y;

    /*  3 polyps counts as an advanced polyp */
  }

  StageTmp = 0.0;
  EStage = 0.0;
  ELocation = 0.0;
  ESojourn = 0.0;
  EDwellTime = 0.0;
  LocationTmp = 0.0;
  SojournTmp = 0.0;
  DwellTimeTmp = 0.0;

  /*  Symptoms */
  idx = 0;
  ii = 1;
  exitg4 = false;
  while ((!exitg4) && (ii < 26)) {
    guard4 = false;
    if (Ca->Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
      idx++;
      if (idx >= 25) {
        exitg4 = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4) {
      ii++;
    }
  }

  if (1 > idx) {
    i21 = 0;
  } else {
    i21 = idx;
  }

  if (1 > idx) {
    i27 = 0;
  } else {
    i27 = idx;
  }

  emlrtForLoopVectorCheckR2012b(i27, -1.0, 1.0, mxDOUBLE_CLASS, i21,
    &j_emlrtRTEI, sp);
  f = 0;
  while (f <= i21 - 1) {
    b_f = i21 - f;
    if (!((b_f >= 1) && (b_f <= 25))) {
      emlrtDynamicBoundsCheckR2012b(b_f, 1, 25, &sj_emlrtBCI, sp);
    }

    Tumor = Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1];

    /*         % influence of cancer stage on detection */
    idx = (int32_T)Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (!((idx >= 1) && (idx <= 10))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &tj_emlrtBCI, sp);
    }

    b2 = (b_rand() < StageVariables->Colo_Detection[idx - 1]);
    x = Ca->CancerLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (x != (int32_T)muDoubleScalarFloor(x)) {
      emlrtIntegerCheckR2012b(x, &cc_emlrtDCI, sp);
    }

    idx = (int32_T)x;
    if (!((idx >= 1) && (idx <= 13))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &ij_emlrtBCI, sp);
    }

    if (b2 && (CurrentReachMatrix[(int32_T)Ca->CancerLocation[((int32_T)z +
          50000 * (b_f - 1)) - 1] - 1] == 1)) {
      /*  has current current colonoscopy reached location of polyp? */
      if (isequal(counter, 0.0)) {
        counter = -1.0;
      }

      /*  the cancer is now a detected cancer */
      idx = 0;
      ii = 1;
      exitg3 = false;
      while ((!exitg3) && (ii < 51)) {
        guard3 = false;
        if (Detected->Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
          idx++;
          if (idx >= 50) {
            exitg3 = true;
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }

        if (guard3) {
          ii++;
        }
      }

      if (1 > idx) {
        ii_size_idx_1 = 0;
      } else {
        ii_size_idx_1 = idx;
      }

      if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 50))) {
        emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 50, &uj_emlrtBCI, sp);
      }

      Detected->Cancer[((int32_T)z + 50000 * ii_size_idx_1) - 1] = Ca->Cancer
        [((int32_T)z + 50000 * (b_f - 1)) - 1];
      Detected->CancerYear[((int32_T)z + 50000 * ii_size_idx_1) - 1] = y + (q -
        1.0) / 4.0;
      Detected->CancerLocation[((int32_T)z + 50000 * ii_size_idx_1) - 1] =
        Ca->CancerLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
      x = b_rand() * 999.0 + 1.0;
      idx = (int32_T)(Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1] - 6.0);
      if (!((idx >= 1) && (idx <= 4))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 4, &vj_emlrtBCI, sp);
      }

      x = muDoubleScalarRound(x);
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &fc_emlrtDCI, sp);
      }

      i22 = (int32_T)x;
      if (!((i22 >= 1) && (i22 <= 1000))) {
        emlrtDynamicBoundsCheckR2012b(i22, 1, 1000, &wj_emlrtBCI, sp);
      }

      Detected->MortTime[((int32_T)z + 50000 * ii_size_idx_1) - 1] =
        MortalityMatrix[((idx + (((int32_T)y - 1) << 2)) + 400 * (i22 - 1)) - 1];

      /*  dfisplay(sprintf('cancer stage %d mortality %d months', Detected.Cancer(z, pos), Detected.MortTime(z, pos))) */
      /*  we need keep track of key parameters */
      /*  Stage Location SojournTime Sex DetectionMode */
      StageTmp = Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1];
      LocationTmp = Ca->CancerLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
      SojournTmp = (y + (q - 1.0) / 4.0) - Ca->CancerYear[((int32_T)z + 50000 *
        (b_f - 1)) - 1];
      DwellTimeTmp = Ca->DwellTime[((int32_T)z + 50000 * (b_f - 1)) - 1];

      /*  the original cancer is removed from the database */
      idx = 0;
      ii = 1;
      exitg2 = false;
      while ((!exitg2) && (ii < 26)) {
        guard2 = false;
        if (Ca->Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
          idx++;
          if (idx >= 25) {
            exitg2 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          ii++;
        }
      }

      if (1 > idx) {
        ii_size_idx_1 = 0;
      } else {
        ii_size_idx_1 = idx;
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &hj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &hj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        c_tmp_data[i26] = i24 + i26;
      }

      iv88[0] = 1;
      iv88[1] = i25 - i24;
      Ca_size[0] = 1;
      Ca_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Ca[i24] = Ca_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv88, 2, b_Ca, 2, &ab_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Ca_data[i24] = Ca->Cancer[((int32_T)z + 50000 * (idx + i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->Cancer[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &gj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &gj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        c_tmp_data[i26] = i24 + i26;
      }

      iv89[0] = 1;
      iv89[1] = i25 - i24;
      b_Ca_size[0] = 1;
      b_Ca_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Ca[i24] = b_Ca_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv89, 2, b_Ca, 2, &y_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Ca_data[i24] = Ca->CancerYear[((int32_T)z + 50000 * (idx + i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->CancerYear[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &fj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &fj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        c_tmp_data[i26] = i24 + i26;
      }

      iv90[0] = 1;
      iv90[1] = i25 - i24;
      c_Ca_size[0] = 1;
      c_Ca_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Ca[i24] = c_Ca_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv90, 2, b_Ca, 2, &x_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Ca_data[i24] = Ca->CancerLocation[((int32_T)z + 50000 * (idx + i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->CancerLocation[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &ej_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &ej_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        c_tmp_data[i26] = i24 + i26;
      }

      iv91[0] = 1;
      iv91[1] = i25 - i24;
      d_Ca_size[0] = 1;
      d_Ca_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Ca[i24] = d_Ca_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv91, 2, b_Ca, 2, &w_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Ca_data[i24] = Ca->DwellTime[((int32_T)z + 50000 * (idx + i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->DwellTime[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      /*  POSSIBLY DELETE */
      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &dj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &dj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        c_tmp_data[i26] = i24 + i26;
      }

      iv92[0] = 1;
      iv92[1] = i25 - i24;
      e_Ca_size[0] = 1;
      e_Ca_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Ca[i24] = e_Ca_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv92, 2, b_Ca, 2, &v_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Ca_data[i24] = Ca->SympTime[((int32_T)z + 50000 * (idx + i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->SympTime[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &cj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &cj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        c_tmp_data[i26] = i24 + i26;
      }

      iv93[0] = 1;
      iv93[1] = i25 - i24;
      f_Ca_size[0] = 1;
      f_Ca_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Ca[i24] = f_Ca_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv93, 2, b_Ca, 2, &u_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Ca_data[i24] = Ca->SympStage[((int32_T)z + 50000 * (idx + i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->SympStage[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &bj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &bj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        c_tmp_data[i26] = i24 + i26;
      }

      iv94[0] = 1;
      iv94[1] = i25 - i24;
      g_Ca_size[0] = 1;
      g_Ca_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Ca[i24] = g_Ca_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv94, 2, b_Ca, 2, &t_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Ca_data[i24] = Ca->TimeStage_I[((int32_T)z + 50000 * (idx + i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->TimeStage_I[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &aj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &aj_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = b_f - 1;
        i25 = ii_size_idx_1;
      }

      ii = i25 - i24;
      for (i26 = 0; i26 < ii; i26++) {
        c_tmp_data[i26] = i24 + i26;
      }

      iv95[0] = 1;
      iv95[1] = i25 - i24;
      h_Ca_size[0] = 1;
      h_Ca_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Ca[i24] = h_Ca_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv95, 2, b_Ca, 2, &s_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Ca_data[i24] = Ca->TimeStage_II[((int32_T)z + 50000 * (idx + i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->TimeStage_II[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i22 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &yi_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &yi_emlrtBCI,
            sp);
        }

        i22 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i24 = 0;
        ii_size_idx_1 = 0;
      } else {
        i24 = b_f - 1;
      }

      ii = ii_size_idx_1 - i24;
      for (i25 = 0; i25 < ii; i25++) {
        c_tmp_data[i25] = i24 + i25;
      }

      iv96[0] = 1;
      iv96[1] = ii_size_idx_1 - i24;
      i_Ca_size[0] = 1;
      i_Ca_size[1] = i22 - idx;
      for (i24 = 0; i24 < 2; i24++) {
        b_Ca[i24] = i_Ca_size[i24];
      }

      emlrtSubAssignSizeCheckR2012b(iv96, 2, b_Ca, 2, &r_emlrtECI, sp);
      ii = i22 - idx;
      for (i24 = 0; i24 < ii; i24++) {
        Ca_data[i24] = Ca->TimeStage_III[((int32_T)z + 50000 * (idx + i24)) - 1];
      }

      ii = i22 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->TimeStage_III[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      DiagnosedCancer[((int32_T)y + 100 * ((int32_T)z - 1)) - 1] =
        muDoubleScalarMax(DiagnosedCancer[((int32_T)y + 100 * ((int32_T)z - 1))
                          - 1], Tumor);

      /*  max in case we would have found 2 tumors */
      Last->Cancer[(int32_T)z - 1] = y;

      /*  Symptoms */
    }

    if ((!isequal(StageTmp, 0.0)) && (StageTmp > EStage)) {
      EStage = StageTmp;
      ELocation = LocationTmp;
      ESojourn = SojournTmp;
      EDwellTime = DwellTimeTmp;
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (!isequal(StageTmp, 0.0)) {
    idx = 0;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii < 5001)) {
      guard1 = false;
      if (TumorRecord->Stage[((int32_T)y + 100 * (ii - 1)) - 1] != 0.0) {
        idx++;
        if (idx >= 5000) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (1 > idx) {
      ii_size_idx_1 = 0;
    } else {
      ii_size_idx_1 = idx;
    }

    if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 5000))) {
      emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 5000, &rj_emlrtBCI, sp);
    }

    TumorRecord->Stage[((int32_T)y + 100 * ii_size_idx_1) - 1] = EStage;
    TumorRecord->Location[((int32_T)y + 100 * ii_size_idx_1) - 1] = ELocation;
    TumorRecord->DwellTime[((int32_T)y + 100 * ii_size_idx_1) - 1] = EDwellTime;
    TumorRecord->Sojourn[((int32_T)y + 100 * ii_size_idx_1) - 1] = ESojourn;
    TumorRecord->Gender[((int32_T)y + 100 * ii_size_idx_1) - 1] = Gender
      [(int32_T)z - 1];
    TumorRecord->Detection[((int32_T)y + 100 * ii_size_idx_1) - 1] = 2.0;
    TumorRecord->PatientNumber[((int32_T)y + 100 * ii_size_idx_1) - 1] = z;

    /*  RS ONLY !!!!!! */
  }

  Last->Colonoscopy[(int32_T)z - 1] = y;
  if (isequal(counter, 0.0)) {
    /*  in this case no tumor or polyp */
    factor = 0.75;
    moneyspent = Cost->Colonoscopy;
    PaymentType->Colonoscopy[1 + (((int32_T)y - 1) << 2)]++;

    /*  AllCost(y) = AllCost(y) + Cost.Colonoscopy; */
  } else if (isequal(counter, -1.0)) {
    factor = 1.5;
    moneyspent = Cost->Colonoscopy_Cancer;
    PaymentType->Colonoscopy_Cancer[1 + (((int32_T)y - 1) << 2)]++;

    /*  AllCost(y) = AllCost(y) + Cost.Colonoscopy_Polyp; */
  } else {
    factor = 1.5;
    moneyspent = Cost->Colonoscopy_Polyp;
    PaymentType->ColonoscopyPolyp[1 + (((int32_T)y - 1) << 2)]++;
  }

  /* %%% Complications */
  if (b_rand() < risc.Colonoscopy_RiscPerforation * factor) {
    /*  a perforation happend */
    moneyspent += Cost->Colonoscopy_Perforation;
    PaymentType->Perforation[1 + (((int32_T)y - 1) << 2)]++;
    if (b_rand() < risc.DeathPerforation) {
      /*  patient died during colonoscopy from a perforation */
      Included[(int32_T)z - 1] = false;
      DeathCause[(int32_T)z - 1] = 3.0;
      DeathYear[(int32_T)z - 1] = y;

      /*  we add the costs */
      st.site = &sc_emlrtRSI;
      AddCosts(SD, &st, Detected->Cancer, Detected->CancerYear,
               CostStage->Initial, CostStage->Cont, CostStage->FutInitial,
               CostStage->FutCont, PaymentType, Money, y + (q - 1.0) / 4.0, z);
    }
  } else if (b_rand() < risc.Colonoscopy_RiscSerosaBurn * factor) {
    /*  serosal burn */
    moneyspent += Cost->Colonoscopy_Serosal_burn;
    PaymentType->Serosa[1 + (((int32_T)y - 1) << 2)]++;
  } else if (b_rand() < risc.Colonoscopy_RiscBleeding * factor) {
    /*  a bleeding episode (no transfusion) */
    moneyspent += Cost->Colonoscopy_bleed;
    PaymentType->Bleeding[1 + (((int32_T)y - 1) << 2)]++;
  } else {
    if (b_rand() < risc.c_Colonoscopy_RiscBleedingTrans * factor) {
      /*  bleeding recquiring transfusion */
      moneyspent += Cost->Colonoscopy_bleed_transfusion;
      PaymentType->BleedingTransf[1 + (((int32_T)y - 1) << 2)]++;
      if (b_rand() < risc.DeathBleedingTransfusion) {
        /*  patient died during colonoscopy from a bleeding complication */
        Included[(int32_T)z - 1] = false;
        DeathCause[(int32_T)z - 1] = 3.0;
        DeathYear[(int32_T)z - 1] = y;
      }
    }
  }

  /*  Symptoms */
  Money->Treatment[(int32_T)y - 1] += moneyspent;
}

static void RectoSigmo(const emlrtStack *sp, real_T z, real_T y, b_struct_T
  *Polyp, const real_T Ca_Cancer[1250000], const real_T Ca_CancerLocation
  [1250000], boolean_T Included[50000], real_T DeathCause[50000], real_T
  DeathYear[50000], struct10_T *PaymentType, struct11_T *Money, const real_T
  c_StageVariables_RectoSigmo_Det[10], real_T Cost_Sigmoidoscopy, real_T
  Cost_Sigmoidoscopy_Polyp, real_T Cost_Colonoscopy_Perforation, const real_T
  Location_RectoSigmoDetection[13], const struct4_T risc, const real_T
  RectoSigmoReachMatrix[1000], const struct5_T flag, real_T *PolypFlag, real_T
  *AdvPolypFlag, real_T *CancerFlag)
{
  real_T x;
  real_T b_x;
  int32_T i42;
  int8_T CurrentReachMatrix[13];
  int32_T idx;
  int32_T ii;
  int32_T i43;
  int32_T tmp_data[13];
  real_T counter;
  real_T PolypMax;
  boolean_T exitg7;
  boolean_T guard7 = false;
  int32_T ii_size_idx_1;
  int32_T f;
  int32_T b_f;
  boolean_T b5;
  boolean_T exitg6;
  boolean_T guard6 = false;
  int32_T i44;
  real_T Tumor;
  boolean_T exitg5;
  boolean_T guard5 = false;
  int32_T i45;
  int32_T i46;
  int32_T i47;
  int32_T b_tmp_data[51];
  int32_T iv123[2];
  int32_T Polyp_size[2];
  int32_T b_Polyp[2];
  real_T Polyp_data[51];
  int32_T iv124[2];
  int32_T b_Polyp_size[2];
  int32_T iv125[2];
  int32_T c_Polyp_size[2];
  int32_T iv126[2];
  int32_T d_Polyp_size[2];
  int32_T iv127[2];
  int32_T e_Polyp_size[2];
  boolean_T exitg4;
  boolean_T guard4 = false;
  int32_T i48;
  boolean_T exitg3;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  boolean_T exitg1;
  boolean_T guard1 = false;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%         Rectosigmoidoscpy                         %%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  in this function we do a rectosigmoidoscopy for the respective patient (number */
  /*  z). We just note whether a polyp or a cancer was found and pass the */
  /*  information back to the calling function */
  /*  we determine the reach of this rectosigmoidoscopy (cecum = 1, rectum = 13)) */
  x = b_rand() * 999.0 + 1.0;
  b_x = muDoubleScalarRound(x);
  x = muDoubleScalarRound(x);
  if (x != (int32_T)muDoubleScalarFloor(x)) {
    emlrtIntegerCheckR2012b(x, &hc_emlrtDCI, sp);
  }

  i42 = (int32_T)x;
  if (!((i42 >= 1) && (i42 <= 1000))) {
    emlrtDynamicBoundsCheckR2012b(i42, 1, 1000, &bk_emlrtBCI, sp);
  }

  for (i42 = 0; i42 < 13; i42++) {
    CurrentReachMatrix[i42] = 0;
  }

  if (RectoSigmoReachMatrix[(int32_T)b_x - 1] > 13.0) {
    i42 = 1;
    idx = 1;
  } else {
    i42 = (int32_T)RectoSigmoReachMatrix[(int32_T)b_x - 1];
    if (!((i42 >= 1) && (i42 <= 13))) {
      emlrtDynamicBoundsCheckR2012b(i42, 1, 13, &dk_emlrtBCI, sp);
    }

    idx = 14;
  }

  ii = idx - i42;
  for (i43 = 0; i43 < ii; i43++) {
    tmp_data[i43] = (i42 + i43) - 1;
  }

  ii = idx - i42;
  for (i42 = 0; i42 < ii; i42++) {
    CurrentReachMatrix[tmp_data[i42]] = 1;
  }

  counter = 0.0;
  *PolypFlag = 0.0;
  *AdvPolypFlag = 0.0;
  *CancerFlag = 0.0;

  /* m */
  PolypMax = 0.0;
  if (flag.Schoen) {
    /*  schoen */
    idx = 0;
    ii = 1;
    exitg7 = false;
    while ((!exitg7) && (ii < 52)) {
      guard7 = false;
      if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
        idx++;
        if (idx >= 51) {
          exitg7 = true;
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }

      if (guard7) {
        ii++;
      }
    }

    if (1 > idx) {
      i42 = 0;
    } else {
      i42 = idx;
    }

    if (1 > idx) {
      ii_size_idx_1 = 0;
    } else {
      ii_size_idx_1 = idx;
    }

    emlrtForLoopVectorCheckR2012b(ii_size_idx_1, -1.0, 1.0, mxDOUBLE_CLASS, i42,
      &l_emlrtRTEI, sp);
    f = 1;
    while (f - 1 <= ii_size_idx_1 - 1) {
      b_f = i42 - f;
      idx = b_f + 1;
      if (!((idx >= 1) && (idx <= 51))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 51, &ck_emlrtBCI, sp);
      }

      /*     % influence of polyp stage */
      /*     % influence of location on detection */
      idx = (int32_T)Polyp->Polyps[((int32_T)z + 50000 * b_f) - 1];
      if (!((idx >= 1) && (idx <= 10))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &fl_emlrtBCI, sp);
      }

      x = Polyp->PolypLocation[((int32_T)z + 50000 * b_f) - 1];
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &qc_emlrtDCI, sp);
      }

      i43 = (int32_T)x;
      if (!((i43 >= 1) && (i43 <= 13))) {
        emlrtDynamicBoundsCheckR2012b(i43, 1, 13, &gl_emlrtBCI, sp);
      }

      b5 = (b_rand() < c_StageVariables_RectoSigmo_Det[idx - 1] *
            Location_RectoSigmoDetection[i43 - 1]);
      x = Polyp->PolypLocation[((int32_T)z + 50000 * b_f) - 1];
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &ic_emlrtDCI, sp);
      }

      idx = (int32_T)x;
      if (!((idx >= 1) && (idx <= 13))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &ek_emlrtBCI, sp);
      }

      if (b5 && (CurrentReachMatrix[(int32_T)Polyp->PolypLocation[((int32_T)z +
            50000 * b_f) - 1] - 1] == 1)) {
        /*  has current current colonoscopy reached location of polyp? */
        /*  we record the polyp */
        /*  in this scenario we only do follow up for larger polyps */
        if (Polyp->Polyps[((int32_T)z + 50000 * b_f) - 1] > 2.0) {
          *PolypFlag = 1.5;
        } else if (isequal(*PolypFlag, 1.5)) {
          *PolypFlag = 1.5;
        } else {
          *PolypFlag = 1.0;
        }

        counter++;
        PolypMax = muDoubleScalarMax(PolypMax, Polyp->Polyps[((int32_T)z + 50000
          * b_f) - 1]);
      }

      f++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  } else if (flag.Atkin) {
    /*  atkin */
    idx = 0;
    ii = 1;
    exitg6 = false;
    while ((!exitg6) && (ii < 52)) {
      guard6 = false;
      if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
        idx++;
        if (idx >= 51) {
          exitg6 = true;
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }

      if (guard6) {
        ii++;
      }
    }

    if (1 > idx) {
      i42 = 0;
    } else {
      i42 = idx;
    }

    if (1 > idx) {
      i44 = 0;
    } else {
      i44 = idx;
    }

    emlrtForLoopVectorCheckR2012b(i44, -1.0, 1.0, mxDOUBLE_CLASS, i42,
      &m_emlrtRTEI, sp);
    f = 0;
    while (f <= i42 - 1) {
      b_f = i42 - f;
      if (!((b_f >= 1) && (b_f <= 51))) {
        emlrtDynamicBoundsCheckR2012b(b_f, 1, 51, &bl_emlrtBCI, sp);
      }

      Tumor = Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1];

      /*     % influence of polyp stage */
      /*     % influence of location on detection */
      idx = (int32_T)Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1];
      if (!((idx >= 1) && (idx <= 10))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &cl_emlrtBCI, sp);
      }

      x = Polyp->PolypLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &pc_emlrtDCI, sp);
      }

      i43 = (int32_T)x;
      if (!((i43 >= 1) && (i43 <= 13))) {
        emlrtDynamicBoundsCheckR2012b(i43, 1, 13, &dl_emlrtBCI, sp);
      }

      b5 = (b_rand() < c_StageVariables_RectoSigmo_Det[idx - 1] *
            Location_RectoSigmoDetection[i43 - 1]);
      x = Polyp->PolypLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &jc_emlrtDCI, sp);
      }

      idx = (int32_T)x;
      if (!((idx >= 1) && (idx <= 13))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &fk_emlrtBCI, sp);
      }

      if (b5 && (CurrentReachMatrix[(int32_T)Polyp->PolypLocation[((int32_T)z +
            50000 * (b_f - 1)) - 1] - 1] == 1)) {
        /*  has current current colonoscopy reached location of polyp? */
        /*  we record the polyp */
        if (Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1] > 2.0) {
          *PolypFlag = 1.0;
        }

        counter++;

        /*  we delete the current polyp only in the Atkins study. outside this */
        /*  study we would remove the polyp during colonoscopy */
        if (Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1] > 2.0) {
          idx = 0;
          ii = 1;
          exitg5 = false;
          while ((!exitg5) && (ii < 52)) {
            guard5 = false;
            if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
              idx++;
              if (idx >= 51) {
                exitg5 = true;
              } else {
                guard5 = true;
              }
            } else {
              guard5 = true;
            }

            if (guard5) {
              ii++;
            }
          }

          if (1 > idx) {
            ii_size_idx_1 = 0;
          } else {
            ii_size_idx_1 = idx;
          }

          if (b_f + 1 > ii_size_idx_1 + 1) {
            idx = 0;
            i43 = 0;
          } else {
            if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &gk_emlrtBCI, sp);
            }

            idx = b_f;
            if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51,
                &gk_emlrtBCI, sp);
            }

            i43 = ii_size_idx_1 + 1;
          }

          if (b_f > ii_size_idx_1) {
            i45 = 0;
            i46 = 0;
          } else {
            i45 = b_f - 1;
            i46 = ii_size_idx_1;
          }

          ii = i46 - i45;
          for (i47 = 0; i47 < ii; i47++) {
            b_tmp_data[i47] = i45 + i47;
          }

          iv123[0] = 1;
          iv123[1] = i46 - i45;
          Polyp_size[0] = 1;
          Polyp_size[1] = i43 - idx;
          for (i45 = 0; i45 < 2; i45++) {
            b_Polyp[i45] = Polyp_size[i45];
          }

          emlrtSubAssignSizeCheckR2012b(iv123, 2, b_Polyp, 2, &gb_emlrtECI, sp);
          ii = i43 - idx;
          for (i45 = 0; i45 < ii; i45++) {
            Polyp_data[i45] = Polyp->Polyps[((int32_T)z + 50000 * (idx + i45)) -
              1];
          }

          ii = i43 - idx;
          for (idx = 0; idx < ii; idx++) {
            Polyp->Polyps[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
              Polyp_data[idx];
          }

          if (b_f + 1 > ii_size_idx_1 + 1) {
            idx = 0;
            i43 = 0;
          } else {
            if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &hk_emlrtBCI, sp);
            }

            idx = b_f;
            if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51,
                &hk_emlrtBCI, sp);
            }

            i43 = ii_size_idx_1 + 1;
          }

          if (b_f > ii_size_idx_1) {
            i45 = 0;
            i46 = 0;
          } else {
            i45 = b_f - 1;
            i46 = ii_size_idx_1;
          }

          ii = i46 - i45;
          for (i47 = 0; i47 < ii; i47++) {
            b_tmp_data[i47] = i45 + i47;
          }

          iv124[0] = 1;
          iv124[1] = i46 - i45;
          b_Polyp_size[0] = 1;
          b_Polyp_size[1] = i43 - idx;
          for (i45 = 0; i45 < 2; i45++) {
            b_Polyp[i45] = b_Polyp_size[i45];
          }

          emlrtSubAssignSizeCheckR2012b(iv124, 2, b_Polyp, 2, &hb_emlrtECI, sp);
          ii = i43 - idx;
          for (i45 = 0; i45 < ii; i45++) {
            Polyp_data[i45] = Polyp->PolypYear[((int32_T)z + 50000 * (idx + i45))
              - 1];
          }

          ii = i43 - idx;
          for (idx = 0; idx < ii; idx++) {
            Polyp->PolypYear[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
              Polyp_data[idx];
          }

          if (b_f + 1 > ii_size_idx_1 + 1) {
            idx = 0;
            i43 = 0;
          } else {
            if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &ik_emlrtBCI, sp);
            }

            idx = b_f;
            if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51,
                &ik_emlrtBCI, sp);
            }

            i43 = ii_size_idx_1 + 1;
          }

          if (b_f > ii_size_idx_1) {
            i45 = 0;
            i46 = 0;
          } else {
            i45 = b_f - 1;
            i46 = ii_size_idx_1;
          }

          ii = i46 - i45;
          for (i47 = 0; i47 < ii; i47++) {
            b_tmp_data[i47] = i45 + i47;
          }

          iv125[0] = 1;
          iv125[1] = i46 - i45;
          c_Polyp_size[0] = 1;
          c_Polyp_size[1] = i43 - idx;
          for (i45 = 0; i45 < 2; i45++) {
            b_Polyp[i45] = c_Polyp_size[i45];
          }

          emlrtSubAssignSizeCheckR2012b(iv125, 2, b_Polyp, 2, &ib_emlrtECI, sp);
          ii = i43 - idx;
          for (i45 = 0; i45 < ii; i45++) {
            Polyp_data[i45] = Polyp->PolypLocation[((int32_T)z + 50000 * (idx +
              i45)) - 1];
          }

          ii = i43 - idx;
          for (idx = 0; idx < ii; idx++) {
            Polyp->PolypLocation[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
              Polyp_data[idx];
          }

          if (b_f + 1 > ii_size_idx_1 + 1) {
            idx = 0;
            i43 = 0;
          } else {
            if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &jk_emlrtBCI, sp);
            }

            idx = b_f;
            if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51,
                &jk_emlrtBCI, sp);
            }

            i43 = ii_size_idx_1 + 1;
          }

          if (b_f > ii_size_idx_1) {
            i45 = 0;
            i46 = 0;
          } else {
            i45 = b_f - 1;
            i46 = ii_size_idx_1;
          }

          ii = i46 - i45;
          for (i47 = 0; i47 < ii; i47++) {
            b_tmp_data[i47] = i45 + i47;
          }

          iv126[0] = 1;
          iv126[1] = i46 - i45;
          d_Polyp_size[0] = 1;
          d_Polyp_size[1] = i43 - idx;
          for (i45 = 0; i45 < 2; i45++) {
            b_Polyp[i45] = d_Polyp_size[i45];
          }

          emlrtSubAssignSizeCheckR2012b(iv126, 2, b_Polyp, 2, &jb_emlrtECI, sp);
          ii = i43 - idx;
          for (i45 = 0; i45 < ii; i45++) {
            Polyp_data[i45] = Polyp->EarlyProgression[((int32_T)z + 50000 * (idx
              + i45)) - 1];
          }

          ii = i43 - idx;
          for (idx = 0; idx < ii; idx++) {
            Polyp->EarlyProgression[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
              Polyp_data[idx];
          }

          if (b_f + 1 > ii_size_idx_1 + 1) {
            idx = 0;
            i43 = 0;
          } else {
            if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &kk_emlrtBCI, sp);
            }

            idx = b_f;
            if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51,
                &kk_emlrtBCI, sp);
            }

            i43 = ii_size_idx_1 + 1;
          }

          if (b_f > ii_size_idx_1) {
            i45 = 0;
            ii_size_idx_1 = 0;
          } else {
            i45 = b_f - 1;
          }

          ii = ii_size_idx_1 - i45;
          for (i46 = 0; i46 < ii; i46++) {
            b_tmp_data[i46] = i45 + i46;
          }

          iv127[0] = 1;
          iv127[1] = ii_size_idx_1 - i45;
          e_Polyp_size[0] = 1;
          e_Polyp_size[1] = i43 - idx;
          for (i45 = 0; i45 < 2; i45++) {
            b_Polyp[i45] = e_Polyp_size[i45];
          }

          emlrtSubAssignSizeCheckR2012b(iv127, 2, b_Polyp, 2, &kb_emlrtECI, sp);
          ii = i43 - idx;
          for (i45 = 0; i45 < ii; i45++) {
            Polyp_data[i45] = Polyp->AdvProgression[((int32_T)z + 50000 * (idx +
              i45)) - 1];
          }

          ii = i43 - idx;
          for (idx = 0; idx < ii; idx++) {
            Polyp->AdvProgression[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
              Polyp_data[idx];
          }
        }

        PolypMax = muDoubleScalarMax(PolypMax, Tumor);
      }

      f++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  } else if (flag.Segnan) {
    /*  italian/ Segnan study */
    idx = 0;
    ii = 1;
    exitg4 = false;
    while ((!exitg4) && (ii < 52)) {
      guard4 = false;
      if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
        idx++;
        if (idx >= 51) {
          exitg4 = true;
        } else {
          guard4 = true;
        }
      } else {
        guard4 = true;
      }

      if (guard4) {
        ii++;
      }
    }

    if (1 > idx) {
      i42 = 0;
    } else {
      i42 = idx;
    }

    if (1 > idx) {
      i48 = 0;
    } else {
      i48 = idx;
    }

    emlrtForLoopVectorCheckR2012b(i48, -1.0, 1.0, mxDOUBLE_CLASS, i42,
      &n_emlrtRTEI, sp);
    f = 0;
    while (f <= i42 - 1) {
      b_f = i42 - f;
      idx = b_f;
      if (!((idx >= 1) && (idx <= 51))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 51, &lk_emlrtBCI, sp);
      }

      /*     % influence of polyp stage */
      /*     % influence of location on detection */
      idx = (int32_T)Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1];
      if (!((idx >= 1) && (idx <= 10))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &yk_emlrtBCI, sp);
      }

      x = Polyp->PolypLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &oc_emlrtDCI, sp);
      }

      i43 = (int32_T)x;
      if (!((i43 >= 1) && (i43 <= 13))) {
        emlrtDynamicBoundsCheckR2012b(i43, 1, 13, &al_emlrtBCI, sp);
      }

      b5 = (b_rand() < c_StageVariables_RectoSigmo_Det[idx - 1] *
            Location_RectoSigmoDetection[i43 - 1]);
      x = Polyp->PolypLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &kc_emlrtDCI, sp);
      }

      idx = (int32_T)x;
      if (!((idx >= 1) && (idx <= 13))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &mk_emlrtBCI, sp);
      }

      if (b5 && (CurrentReachMatrix[(int32_T)Polyp->PolypLocation[((int32_T)z +
            50000 * (b_f - 1)) - 1] - 1] == 1)) {
        /*  has current current colonoscopy reached location of polyp? */
        /*  we record the polyp */
        if (Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1] > 2.0) {
          *PolypFlag = 1.0;
          PolypMax = muDoubleScalarMax(PolypMax, Polyp->Polyps[((int32_T)z +
            50000 * (b_f - 1)) - 1]);
          counter++;
        } else {
          /*  in this study we only delete small polyps; larger polyps are referred to colonoscopy */
          idx = 0;
          ii = 1;
          exitg3 = false;
          while ((!exitg3) && (ii < 52)) {
            guard3 = false;
            if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
              idx++;
              if (idx >= 51) {
                exitg3 = true;
              } else {
                guard3 = true;
              }
            } else {
              guard3 = true;
            }

            if (guard3) {
              ii++;
            }
          }

          if (1 > idx) {
            ii_size_idx_1 = 0;
          } else {
            ii_size_idx_1 = idx;
          }

          if (b_f + 1 > ii_size_idx_1 + 1) {
            idx = 0;
            i43 = 0;
          } else {
            if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &nk_emlrtBCI, sp);
            }

            idx = b_f;
            if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51,
                &nk_emlrtBCI, sp);
            }

            i43 = ii_size_idx_1 + 1;
          }

          if (b_f > ii_size_idx_1) {
            i45 = 0;
            i46 = 0;
          } else {
            i45 = b_f - 1;
            i46 = ii_size_idx_1;
          }

          ii = i46 - i45;
          for (i47 = 0; i47 < ii; i47++) {
            b_tmp_data[i47] = i45 + i47;
          }

          iv123[0] = 1;
          iv123[1] = i46 - i45;
          Polyp_size[0] = 1;
          Polyp_size[1] = i43 - idx;
          for (i45 = 0; i45 < 2; i45++) {
            b_Polyp[i45] = Polyp_size[i45];
          }

          emlrtSubAssignSizeCheckR2012b(iv123, 2, b_Polyp, 2, &lb_emlrtECI, sp);
          ii = i43 - idx;
          for (i45 = 0; i45 < ii; i45++) {
            Polyp_data[i45] = Polyp->Polyps[((int32_T)z + 50000 * (idx + i45)) -
              1];
          }

          ii = i43 - idx;
          for (idx = 0; idx < ii; idx++) {
            Polyp->Polyps[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
              Polyp_data[idx];
          }

          if (b_f + 1 > ii_size_idx_1 + 1) {
            idx = 0;
            i43 = 0;
          } else {
            if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &ok_emlrtBCI, sp);
            }

            idx = b_f;
            if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51,
                &ok_emlrtBCI, sp);
            }

            i43 = ii_size_idx_1 + 1;
          }

          if (b_f > ii_size_idx_1) {
            i45 = 0;
            i46 = 0;
          } else {
            i45 = b_f - 1;
            i46 = ii_size_idx_1;
          }

          ii = i46 - i45;
          for (i47 = 0; i47 < ii; i47++) {
            b_tmp_data[i47] = i45 + i47;
          }

          iv124[0] = 1;
          iv124[1] = i46 - i45;
          b_Polyp_size[0] = 1;
          b_Polyp_size[1] = i43 - idx;
          for (i45 = 0; i45 < 2; i45++) {
            b_Polyp[i45] = b_Polyp_size[i45];
          }

          emlrtSubAssignSizeCheckR2012b(iv124, 2, b_Polyp, 2, &mb_emlrtECI, sp);
          ii = i43 - idx;
          for (i45 = 0; i45 < ii; i45++) {
            Polyp_data[i45] = Polyp->PolypYear[((int32_T)z + 50000 * (idx + i45))
              - 1];
          }

          ii = i43 - idx;
          for (idx = 0; idx < ii; idx++) {
            Polyp->PolypYear[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
              Polyp_data[idx];
          }

          if (b_f + 1 > ii_size_idx_1 + 1) {
            idx = 0;
            i43 = 0;
          } else {
            if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &pk_emlrtBCI, sp);
            }

            idx = b_f;
            if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51,
                &pk_emlrtBCI, sp);
            }

            i43 = ii_size_idx_1 + 1;
          }

          if (b_f > ii_size_idx_1) {
            i45 = 0;
            i46 = 0;
          } else {
            i45 = b_f - 1;
            i46 = ii_size_idx_1;
          }

          ii = i46 - i45;
          for (i47 = 0; i47 < ii; i47++) {
            b_tmp_data[i47] = i45 + i47;
          }

          iv125[0] = 1;
          iv125[1] = i46 - i45;
          c_Polyp_size[0] = 1;
          c_Polyp_size[1] = i43 - idx;
          for (i45 = 0; i45 < 2; i45++) {
            b_Polyp[i45] = c_Polyp_size[i45];
          }

          emlrtSubAssignSizeCheckR2012b(iv125, 2, b_Polyp, 2, &nb_emlrtECI, sp);
          ii = i43 - idx;
          for (i45 = 0; i45 < ii; i45++) {
            Polyp_data[i45] = Polyp->PolypLocation[((int32_T)z + 50000 * (idx +
              i45)) - 1];
          }

          ii = i43 - idx;
          for (idx = 0; idx < ii; idx++) {
            Polyp->PolypLocation[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
              Polyp_data[idx];
          }

          if (b_f + 1 > ii_size_idx_1 + 1) {
            idx = 0;
            i43 = 0;
          } else {
            if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &qk_emlrtBCI, sp);
            }

            idx = b_f;
            if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51,
                &qk_emlrtBCI, sp);
            }

            i43 = ii_size_idx_1 + 1;
          }

          if (b_f > ii_size_idx_1) {
            i45 = 0;
            i46 = 0;
          } else {
            i45 = b_f - 1;
            i46 = ii_size_idx_1;
          }

          ii = i46 - i45;
          for (i47 = 0; i47 < ii; i47++) {
            b_tmp_data[i47] = i45 + i47;
          }

          iv126[0] = 1;
          iv126[1] = i46 - i45;
          d_Polyp_size[0] = 1;
          d_Polyp_size[1] = i43 - idx;
          for (i45 = 0; i45 < 2; i45++) {
            b_Polyp[i45] = d_Polyp_size[i45];
          }

          emlrtSubAssignSizeCheckR2012b(iv126, 2, b_Polyp, 2, &ob_emlrtECI, sp);
          ii = i43 - idx;
          for (i45 = 0; i45 < ii; i45++) {
            Polyp_data[i45] = Polyp->EarlyProgression[((int32_T)z + 50000 * (idx
              + i45)) - 1];
          }

          ii = i43 - idx;
          for (idx = 0; idx < ii; idx++) {
            Polyp->EarlyProgression[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
              Polyp_data[idx];
          }

          if (b_f + 1 > ii_size_idx_1 + 1) {
            idx = 0;
            i43 = 0;
          } else {
            if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &rk_emlrtBCI, sp);
            }

            idx = b_f;
            if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51,
                &rk_emlrtBCI, sp);
            }

            i43 = ii_size_idx_1 + 1;
          }

          if (b_f > ii_size_idx_1) {
            i45 = 0;
            ii_size_idx_1 = 0;
          } else {
            i45 = b_f - 1;
          }

          ii = ii_size_idx_1 - i45;
          for (i46 = 0; i46 < ii; i46++) {
            b_tmp_data[i46] = i45 + i46;
          }

          iv127[0] = 1;
          iv127[1] = ii_size_idx_1 - i45;
          e_Polyp_size[0] = 1;
          e_Polyp_size[1] = i43 - idx;
          for (i45 = 0; i45 < 2; i45++) {
            b_Polyp[i45] = e_Polyp_size[i45];
          }

          emlrtSubAssignSizeCheckR2012b(iv127, 2, b_Polyp, 2, &pb_emlrtECI, sp);
          ii = i43 - idx;
          for (i45 = 0; i45 < ii; i45++) {
            Polyp_data[i45] = Polyp->AdvProgression[((int32_T)z + 50000 * (idx +
              i45)) - 1];
          }

          ii = i43 - idx;
          for (idx = 0; idx < ii; idx++) {
            Polyp->AdvProgression[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
              Polyp_data[idx];
          }
        }
      }

      f++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  } else {
    idx = 0;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii < 52)) {
      guard2 = false;
      if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
        idx++;
        if (idx >= 51) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        ii++;
      }
    }

    if (1 > idx) {
      i42 = 0;
    } else {
      i42 = idx;
    }

    if (1 > idx) {
      ii_size_idx_1 = 0;
    } else {
      ii_size_idx_1 = idx;
    }

    emlrtForLoopVectorCheckR2012b(ii_size_idx_1, -1.0, 1.0, mxDOUBLE_CLASS, i42,
      &o_emlrtRTEI, sp);
    f = 1;
    while (f - 1 <= ii_size_idx_1 - 1) {
      b_f = i42 - f;
      idx = b_f + 1;
      if (!((idx >= 1) && (idx <= 51))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 51, &sk_emlrtBCI, sp);
      }

      /*     % influence of polyp stage */
      /*     % influence of location on detection */
      idx = (int32_T)Polyp->Polyps[((int32_T)z + 50000 * b_f) - 1];
      if (!((idx >= 1) && (idx <= 10))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &wk_emlrtBCI, sp);
      }

      x = Polyp->PolypLocation[((int32_T)z + 50000 * b_f) - 1];
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &nc_emlrtDCI, sp);
      }

      i43 = (int32_T)x;
      if (!((i43 >= 1) && (i43 <= 13))) {
        emlrtDynamicBoundsCheckR2012b(i43, 1, 13, &xk_emlrtBCI, sp);
      }

      b5 = (b_rand() < c_StageVariables_RectoSigmo_Det[idx - 1] *
            Location_RectoSigmoDetection[i43 - 1]);
      x = Polyp->PolypLocation[((int32_T)z + 50000 * b_f) - 1];
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &lc_emlrtDCI, sp);
      }

      idx = (int32_T)x;
      if (!((idx >= 1) && (idx <= 13))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &tk_emlrtBCI, sp);
      }

      if (b5 && (CurrentReachMatrix[(int32_T)Polyp->PolypLocation[((int32_T)z +
            50000 * b_f) - 1] - 1] == 1)) {
        /*  has current current colonoscopy reached location of polyp? */
        /*  we record the polyp */
        *PolypFlag = 1.0;
        counter++;
        PolypMax = muDoubleScalarMax(PolypMax, Polyp->Polyps[((int32_T)z + 50000
          * b_f) - 1]);
      }

      f++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  if ((PolypMax > 4.0) || (counter > 2.0)) {
    *AdvPolypFlag = 1.0;
  }

  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 26)) {
    guard1 = false;
    if (Ca_Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
      idx++;
      if (idx >= 25) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (1 > idx) {
    i42 = 0;
  } else {
    i42 = idx;
  }

  if (1 > idx) {
    ii_size_idx_1 = 0;
  } else {
    ii_size_idx_1 = idx;
  }

  emlrtForLoopVectorCheckR2012b(ii_size_idx_1, -1.0, 1.0, mxDOUBLE_CLASS, i42,
    &p_emlrtRTEI, sp);
  f = 1;
  while (f - 1 <= ii_size_idx_1 - 1) {
    b_f = i42 - f;
    idx = b_f + 1;
    if (!((idx >= 1) && (idx <= 25))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 25, &uk_emlrtBCI, sp);
    }

    /*            % influence of cancer stage on detection */
    idx = (int32_T)Ca_Cancer[((int32_T)z + 50000 * b_f) - 1];
    if (!((idx >= 1) && (idx <= 10))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &el_emlrtBCI, sp);
    }

    b5 = (b_rand() < c_StageVariables_RectoSigmo_Det[idx - 1]);
    x = Ca_CancerLocation[((int32_T)z + 50000 * b_f) - 1];
    if (x != (int32_T)muDoubleScalarFloor(x)) {
      emlrtIntegerCheckR2012b(x, &mc_emlrtDCI, sp);
    }

    idx = (int32_T)x;
    if (!((idx >= 1) && (idx <= 13))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &vk_emlrtBCI, sp);
    }

    if (b5 && (CurrentReachMatrix[(int32_T)Ca_CancerLocation[((int32_T)z + 50000
          * b_f) - 1] - 1] == 1)) {
      /*  has current current colonoscopy reached location of polyp? */
      counter++;
      *CancerFlag = 1.0;
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (isequal(counter, 0.0)) {
    /*  in this case no tumor or polyp */
    Money->Screening[(int32_T)y - 1] += Cost_Sigmoidoscopy;
    PaymentType->RS[(int32_T)y - 1]++;

    /* m2 assumption. RS is only done for screening. not for followup or treatment */
  } else {
    Money->Screening[(int32_T)y - 1] += Cost_Sigmoidoscopy_Polyp;
    PaymentType->RSPolyp[(int32_T)y - 1]++;

    /* m2 assumption. RS is only done for screening. not for followup or treatment */
  }

  /* %%% Complications */
  if (b_rand() < risc.Rectosigmo_Perforation) {
    /*  a perforation happend */
    Money->Screening[(int32_T)y - 1] += Cost_Colonoscopy_Perforation;
    PaymentType->Perforation[((int32_T)y - 1) << 2]++;
    if (b_rand() < risc.DeathPerforation) {
      /*  patient died during colonoscopy from a perforation */
      Included[(int32_T)z - 1] = false;
      DeathCause[(int32_T)z - 1] = 3.0;
      DeathYear[(int32_T)z - 1] = y;

      /*  we set these flags to zero to prevent colonoscopy on a deceased */
      /*  patienta */
      *CancerFlag = 0.0;
      *PolypFlag = 0.0;
    }
  }
}

static void b_AddCosts(NumberCrunching_50000StackData *SD, const emlrtStack *sp,
  const real_T Detected_Cancer[2500000], const real_T Detected_CancerYear
  [2500000], const real_T CostStage_Initial[4], const real_T CostStage_Cont[4],
  const real_T CostStage_Final[4], const real_T CostStage_FutInitial[4], const
  real_T CostStage_FutCont[4], const real_T CostStage_FutFinal[4], struct10_T
  *PaymentType, struct11_T *Money, real_T time, real_T z)
{
  int32_T i17;
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T ii_size_idx_1;
  int32_T x1;
  real_T Start;
  real_T Difference;
  int32_T i18;
  real_T d2;
  int32_T i19;
  real_T d3;
  int32_T Qcount;
  int32_T yyears;
  real_T qquarters;
  int32_T con_y;
  int32_T b_con_y;
  int32_T b_Qcount;
  int32_T i20;
  real_T SubCostAll[404];
  real_T SubCostAllFut[404];
  int32_T Counter;
  int32_T x2;

  /*  in this case a cancer has been diagnosed and */
  /*  we need to take care of the costs */
  /*  for temporary calculations */
  for (i17 = 0; i17 < 10100; i17++) {
    SD->u1.f1.SubCost[i17] = 0.0;
    SD->u1.f1.SubCostFut[i17] = 0.0;
  }

  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 51)) {
    guard1 = false;
    if (Detected_Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
      idx++;
      if (idx >= 50) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (1 > idx) {
    ii_size_idx_1 = 0;
  } else {
    ii_size_idx_1 = idx;
  }

  /*  we add the cost for the rest of the */
  /*  treatment time */
  x1 = 0;
  while (x1 <= ii_size_idx_1 - 1) {
    Start = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1];
    Difference = time - Detected_CancerYear[((int32_T)z + 50000 * x1) - 1];

    /*  costs differ dependent if patient died of tumor or of other causes */
    /*      if isequal(mode, 'oc') % died of other causes */
    /*          FinalCosts    = CostStage.Final_oc(Detected.Cancer(z, x1)-6);  */
    /*          FutFinalCosts = CostStage.FutFinal_oc(Detected.Cancer(z, x1)-6);  */
    /*      else */
    /*          FinalCosts    = CostStage.Final(Detected.Cancer(z, x1)-6); % patient died of tumor */
    /*          FutFinalCosts = CostStage.FutFinal(Detected.Cancer(z, x1)-6); % patient died of tumor */
    /*      end */
    /*  all other tumors */
    /* m for the costs, the following changes are made: */
    /* m after 5 years, the treatment is discontinued */
    /* m during the 5 years of treatment if the death is due to other */
    /* reasons, these costs are not included */
    /* m the initial phase is for 3 months, and the remaining time until the */
    /* terminal or the 5th year are the continuing costs. */
    if (Difference <= 0.25) {
      /*  the costs for the first year of treatment apply, independent */
      /*  whether the patient survived a full year or not */
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &kh_emlrtBCI, sp);
      }

      i18 = 1 + x1;
      if (!((i18 >= 1) && (i18 <= 25))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 25, &lh_emlrtBCI, sp);
      }

      d2 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
        emlrtIntegerCheckR2012b(d2, &vb_emlrtDCI, sp);
      }

      i19 = (int32_T)d2;
      if (!((i19 >= 1) && (i19 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 404, &mh_emlrtBCI, sp);
      }

      SD->u1.f1.SubCost[(i18 + 25 * (i19 - 1)) - 1] = CostStage_Initial[i17 - 1];

      /*  START */
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &nh_emlrtBCI, sp);
      }

      d2 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
        emlrtIntegerCheckR2012b(d2, &wb_emlrtDCI, sp);
      }

      i18 = (int32_T)d2;
      if (!((i18 >= 1) && (i18 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &oh_emlrtBCI, sp);
      }

      SD->u1.f1.SubCostFut[x1 + 25 * (i18 - 1)] = CostStage_FutInitial[i17 - 1];
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &ph_emlrtBCI, sp);
      }

      i18 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i18 >= 1) && (i18 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &qh_emlrtBCI, sp);
      }

      i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i19 >= 1) && (i19 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &rh_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &sh_emlrtBCI, sp);
      }

      PaymentType->Cancer_ini[(i19 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_ini[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &th_emlrtBCI, sp);
      }

      i18 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i18 >= 1) && (i18 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &uh_emlrtBCI, sp);
      }

      i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i19 >= 1) && (i19 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &vh_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &wh_emlrtBCI, sp);
      }

      PaymentType->QCancer_ini[(i19 + ((idx - 1) << 2)) - 1] =
        PaymentType->QCancer_ini[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;
    } else if ((Difference > 0.25) && (Difference <= 1.25)) {
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &kg_emlrtBCI, sp);
      }

      i18 = 1 + x1;
      if (!((i18 >= 1) && (i18 <= 25))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 25, &lg_emlrtBCI, sp);
      }

      d2 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
        emlrtIntegerCheckR2012b(d2, &tb_emlrtDCI, sp);
      }

      i19 = (int32_T)d2;
      if (!((i19 >= 1) && (i19 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 404, &mg_emlrtBCI, sp);
      }

      SD->u1.f1.SubCost[(i18 + 25 * (i19 - 1)) - 1] = CostStage_Initial[i17 - 1];
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &ng_emlrtBCI, sp);
      }

      d2 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
        emlrtIntegerCheckR2012b(d2, &ub_emlrtDCI, sp);
      }

      i18 = (int32_T)d2;
      if (!((i18 >= 1) && (i18 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &og_emlrtBCI, sp);
      }

      SD->u1.f1.SubCostFut[x1 + 25 * (i18 - 1)] = CostStage_FutInitial[i17 - 1];
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &pg_emlrtBCI, sp);
      }

      i18 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i18 >= 1) && (i18 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &qg_emlrtBCI, sp);
      }

      i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i19 >= 1) && (i19 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &rg_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &sg_emlrtBCI, sp);
      }

      PaymentType->Cancer_ini[(i19 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_ini[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &tg_emlrtBCI, sp);
      }

      i18 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i18 >= 1) && (i18 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &ug_emlrtBCI, sp);
      }

      i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i19 >= 1) && (i19 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &vg_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &wg_emlrtBCI, sp);
      }

      PaymentType->QCancer_ini[(i19 + ((idx - 1) << 2)) - 1] =
        PaymentType->QCancer_ini[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;
      d2 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
        1.0;
      d3 = time * 4.0;
      if (d2 > d3) {
        i17 = 0;
        i18 = 0;
      } else {
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &bc_emlrtDCI, sp);
        }

        i17 = (int32_T)d2;
        if (!((i17 >= 1) && (i17 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 404, &bi_emlrtBCI, sp);
        }

        i17--;
        if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
          emlrtIntegerCheckR2012b(d3, &bc_emlrtDCI, sp);
        }

        i18 = (int32_T)d3;
        if (!((i18 >= 1) && (i18 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &bi_emlrtBCI, sp);
        }
      }

      idx = i18 - i17;
      for (i18 = 0; i18 < idx; i18++) {
        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &mi_emlrtBCI, sp);
        }

        SD->u1.f1.SubCost[x1 + 25 * (i17 + i18)] = 0.25 * CostStage_Final[i19 -
          1];
      }

      /*  START */
      d2 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
        1.0;
      d3 = time * 4.0;
      if (d2 > d3) {
        i17 = 0;
        i18 = 0;
      } else {
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &yb_emlrtDCI, sp);
        }

        i17 = (int32_T)d2;
        if (!((i17 >= 1) && (i17 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 404, &yh_emlrtBCI, sp);
        }

        i17--;
        if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
          emlrtIntegerCheckR2012b(d3, &yb_emlrtDCI, sp);
        }

        i18 = (int32_T)d3;
        if (!((i18 >= 1) && (i18 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &yh_emlrtBCI, sp);
        }
      }

      idx = i18 - i17;
      for (i18 = 0; i18 < idx; i18++) {
        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &ni_emlrtBCI, sp);
        }

        SD->u1.f1.SubCostFut[x1 + 25 * (i17 + i18)] = 0.25 *
          CostStage_FutFinal[i19 - 1];
      }

      /*  START */
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &oi_emlrtBCI, sp);
      }

      i18 = (int32_T)muDoubleScalarFloor(time - 1.0);
      if (!((i18 >= 1) && (i18 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &pi_emlrtBCI, sp);
      }

      i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i19 >= 1) && (i19 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &qi_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(time - 1.0);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ri_emlrtBCI, sp);
      }

      PaymentType->Cancer_fin[(i19 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_fin[(i17 + ((i18 - 1) << 2)) - 1] + (4.0 * time -
        (4.0 * Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] + 1.0)) / 4.0;

      /* m2 ini is for q1, and the cont is for rest. but to keep it all integers, I use y */
      d2 = 4.0 * time - (4.0 * Detected_CancerYear[((int32_T)z + 50000 * x1) - 1]
                         + 1.0);
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, d2, mxDOUBLE_CLASS, (int32_T)d2,
        &i_emlrtRTEI, sp);
      Qcount = 1;
      while (Qcount - 1 <= (int32_T)d2 - 1) {
        i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i17 >= 1) && (i17 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &si_emlrtBCI, sp);
        }

        i18 = (int32_T)muDoubleScalarFloor(time - 1.0);
        if (!((i18 >= 1) && (i18 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &ti_emlrtBCI, sp);
        }

        if (!((Qcount >= 1) && (Qcount <= 4))) {
          emlrtDynamicBoundsCheckR2012b(Qcount, 1, 4, &ui_emlrtBCI, sp);
        }

        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &vi_emlrtBCI, sp);
        }

        idx = (int32_T)muDoubleScalarFloor(time - 1.0);
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &wi_emlrtBCI, sp);
        }

        if (!((Qcount >= 1) && (Qcount <= 4))) {
          emlrtDynamicBoundsCheckR2012b(Qcount, 1, 4, &xi_emlrtBCI, sp);
        }

        PaymentType->QCancer_fin[((i19 + ((idx - 1) << 2)) + 404 * (Qcount - 1))
          - 1] = PaymentType->QCancer_fin[((i17 + ((i18 - 1) << 2)) + 404 *
          (Qcount - 1)) - 1] + 1.0;

        /* m2 this finQ is counting in quarters */
        Qcount++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } else if ((Difference > 1.25) && (Difference <= 5.0)) {
      /* m new costs treatment o */
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &pe_emlrtBCI, sp);
      }

      i18 = 1 + x1;
      if (!((i18 >= 1) && (i18 <= 25))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 25, &qe_emlrtBCI, sp);
      }

      d2 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
        emlrtIntegerCheckR2012b(d2, &pb_emlrtDCI, sp);
      }

      i19 = (int32_T)d2;
      if (!((i19 >= 1) && (i19 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 404, &re_emlrtBCI, sp);
      }

      SD->u1.f1.SubCost[(i18 + 25 * (i19 - 1)) - 1] = CostStage_Initial[i17 - 1];
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &se_emlrtBCI, sp);
      }

      d2 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
      if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
        emlrtIntegerCheckR2012b(d2, &qb_emlrtDCI, sp);
      }

      i18 = (int32_T)d2;
      if (!((i18 >= 1) && (i18 <= 404))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &te_emlrtBCI, sp);
      }

      SD->u1.f1.SubCostFut[x1 + 25 * (i18 - 1)] = CostStage_FutInitial[i17 - 1];
      d2 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
        1.0;
      d3 = (time - 1.0) * 4.0;
      if (d2 > d3) {
        i17 = 0;
        i18 = 0;
      } else {
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &lb_emlrtDCI, sp);
        }

        i17 = (int32_T)d2;
        if (!((i17 >= 1) && (i17 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 404, &ed_emlrtBCI, sp);
        }

        i17--;
        if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
          emlrtIntegerCheckR2012b(d3, &lb_emlrtDCI, sp);
        }

        i18 = (int32_T)d3;
        if (!((i18 >= 1) && (i18 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &ed_emlrtBCI, sp);
        }
      }

      idx = i18 - i17;
      for (i18 = 0; i18 < idx; i18++) {
        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &ue_emlrtBCI, sp);
        }

        SD->u1.f1.SubCost[x1 + 25 * (i17 + i18)] = 0.25 * CostStage_Cont[i19 - 1];
      }

      /*  CONT */
      d2 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
        1.0;
      d3 = (time - 1.0) * 4.0;
      if (d2 > d3) {
        i17 = 0;
        i18 = 0;
      } else {
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &hb_emlrtDCI, sp);
        }

        i17 = (int32_T)d2;
        if (!((i17 >= 1) && (i17 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 404, &ad_emlrtBCI, sp);
        }

        i17--;
        if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
          emlrtIntegerCheckR2012b(d3, &hb_emlrtDCI, sp);
        }

        i18 = (int32_T)d3;
        if (!((i18 >= 1) && (i18 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &ad_emlrtBCI, sp);
        }
      }

      idx = i18 - i17;
      for (i18 = 0; i18 < idx; i18++) {
        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &ve_emlrtBCI, sp);
        }

        SD->u1.f1.SubCostFut[x1 + 25 * (i17 + i18)] = 0.25 *
          CostStage_FutCont[i19 - 1];
      }

      /*  CONT */
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &we_emlrtBCI, sp);
      }

      i18 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i18 >= 1) && (i18 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &xe_emlrtBCI, sp);
      }

      i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i19 >= 1) && (i19 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &ye_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &af_emlrtBCI, sp);
      }

      PaymentType->Cancer_ini[(i19 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_ini[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;
      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &bf_emlrtBCI, sp);
      }

      i18 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((i18 >= 1) && (i18 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &cf_emlrtBCI, sp);
      }

      i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i19 >= 1) && (i19 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &df_emlrtBCI, sp);
      }

      idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z + 50000
        * x1) - 1]);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ef_emlrtBCI, sp);
      }

      PaymentType->QCancer_ini[(i19 + ((idx - 1) << 2)) - 1] =
        PaymentType->QCancer_ini[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;
      yyears = (int32_T)muDoubleScalarFloor(Difference - 1.25);
      qquarters = (Difference - 1.25) - muDoubleScalarFloor(Difference - 1.25);
      con_y = 1;
      b_con_y = 0;
      while (b_con_y <= yyears - 1) {
        con_y = 1 + b_con_y;
        i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i17 >= 1) && (i17 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &cg_emlrtBCI, sp);
        }

        i18 = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
        if (!((i18 >= 1) && (i18 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &dg_emlrtBCI, sp);
        }

        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &eg_emlrtBCI, sp);
        }

        idx = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &fg_emlrtBCI, sp);
        }

        PaymentType->Cancer_con[(i19 + ((idx - 1) << 2)) - 1] =
          PaymentType->Cancer_con[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;

        /* ((4*Ende-4*1)-(4*Start+1))/4; */
        i17 = ((1 + b_con_y) << 2) - 3;
        i18 = ((1 + b_con_y) << 2) - i17;
        Qcount = -1;
        while (Qcount + 1 <= i18) {
          b_Qcount = i17 + Qcount;
          i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i19 >= 1) && (i19 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &gg_emlrtBCI, sp);
          }

          idx = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
          if (!((idx >= 1) && (idx <= 101))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &hg_emlrtBCI, sp);
          }

          ii = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((ii >= 1) && (ii <= 4))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, 4, &ig_emlrtBCI, sp);
          }

          i20 = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
          if (!((i20 >= 1) && (i20 <= 101))) {
            emlrtDynamicBoundsCheckR2012b(i20, 1, 101, &jg_emlrtBCI, sp);
          }

          PaymentType->QCancer_con[((ii + ((i20 - 1) << 2)) + 404 * b_Qcount) -
            1] = PaymentType->QCancer_con[((i19 + ((idx - 1) << 2)) + 404 *
            b_Qcount) - 1] + 1.0;

          /* ((4*Ende-4*1)-(4*Start+1))/4; */
          Qcount++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        b_con_y++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &ff_emlrtBCI, sp);
      }

      i18 = (int32_T)((muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
        50000 * x1) - 1]) + (real_T)con_y) + 1.0);
      if (!((i18 >= 1) && (i18 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &gf_emlrtBCI, sp);
      }

      i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i19 >= 1) && (i19 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &hf_emlrtBCI, sp);
      }

      idx = (int32_T)((muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
        50000 * x1) - 1]) + (real_T)con_y) + 1.0);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &if_emlrtBCI, sp);
      }

      PaymentType->Cancer_con[(i19 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_con[(i17 + ((i18 - 1) << 2)) - 1] + qquarters;
      d2 = 4.0 * qquarters;
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, d2, mxDOUBLE_CLASS, (int32_T)d2,
        &g_emlrtRTEI, sp);
      Qcount = 1;
      while (Qcount - 1 <= (int32_T)d2 - 1) {
        i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i17 >= 1) && (i17 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &vf_emlrtBCI, sp);
        }

        i18 = (int32_T)((muDoubleScalarFloor(Start) + (real_T)con_y) + 1.0);
        if (!((i18 >= 1) && (i18 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &wf_emlrtBCI, sp);
        }

        i19 = (con_y << 2) + Qcount;
        if (!((i19 >= 1) && (i19 <= 20))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 20, &xf_emlrtBCI, sp);
        }

        idx = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((idx >= 1) && (idx <= 4))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 4, &yf_emlrtBCI, sp);
        }

        ii = (int32_T)((muDoubleScalarFloor(Start) + (real_T)con_y) + 1.0);
        if (!((ii >= 1) && (ii <= 101))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, 101, &ag_emlrtBCI, sp);
        }

        i20 = (con_y << 2) + Qcount;
        if (!((i20 >= 1) && (i20 <= 20))) {
          emlrtDynamicBoundsCheckR2012b(i20, 1, 20, &bg_emlrtBCI, sp);
        }

        PaymentType->QCancer_con[((idx + ((ii - 1) << 2)) + 404 * (i20 - 1)) - 1]
          = PaymentType->QCancer_con[((i17 + ((i18 - 1) << 2)) + 404 * (i19 - 1))
          - 1] + 1.0;

        /* ((4*Ende-4*1)-(4*Start+1))/4; */
        Qcount++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /* m PaymentType.Cancer_con(Detected.Cancer(z, x1)-6, floor(Start)) = PaymentType.Cancer_con(Detected.Cancer(z, x1)-6,floor(Start)) + ((4*Ende-4*1)-(4*Start+1))/4; */
      d2 = (time - 1.0) * 4.0 + 1.0;
      d3 = time * 4.0;
      if (d2 > d3) {
        i17 = 0;
        i18 = 0;
      } else {
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &ac_emlrtDCI, sp);
        }

        i17 = (int32_T)d2;
        if (!((i17 >= 1) && (i17 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 404, &ai_emlrtBCI, sp);
        }

        i17--;
        if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
          emlrtIntegerCheckR2012b(d3, &ac_emlrtDCI, sp);
        }

        i18 = (int32_T)d3;
        if (!((i18 >= 1) && (i18 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &ai_emlrtBCI, sp);
        }
      }

      idx = i18 - i17;
      for (i18 = 0; i18 < idx; i18++) {
        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &ci_emlrtBCI, sp);
        }

        SD->u1.f1.SubCost[x1 + 25 * (i17 + i18)] = 0.25 * CostStage_Final[i19 -
          1];
      }

      d2 = (time - 1.0) * 4.0 + 1.0;
      d3 = time * 4.0;
      if (d2 > d3) {
        i17 = 0;
        i18 = 0;
      } else {
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &xb_emlrtDCI, sp);
        }

        i17 = (int32_T)d2;
        if (!((i17 >= 1) && (i17 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 404, &xh_emlrtBCI, sp);
        }

        i17--;
        if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
          emlrtIntegerCheckR2012b(d3, &xb_emlrtDCI, sp);
        }

        i18 = (int32_T)d3;
        if (!((i18 >= 1) && (i18 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &xh_emlrtBCI, sp);
        }
      }

      idx = i18 - i17;
      for (i18 = 0; i18 < idx; i18++) {
        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &di_emlrtBCI, sp);
        }

        SD->u1.f1.SubCostFut[x1 + 25 * (i17 + i18)] = 0.25 *
          CostStage_FutFinal[i19 - 1];
      }

      i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i17 >= 1) && (i17 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &ei_emlrtBCI, sp);
      }

      i18 = (int32_T)(muDoubleScalarFloor(time) - 1.0);
      if (!((i18 >= 1) && (i18 <= 101))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &fi_emlrtBCI, sp);
      }

      i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
      if (!((i19 >= 1) && (i19 <= 4))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &gi_emlrtBCI, sp);
      }

      idx = (int32_T)(muDoubleScalarFloor(time) - 1.0);
      if (!((idx >= 1) && (idx <= 101))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &hi_emlrtBCI, sp);
      }

      PaymentType->Cancer_fin[(i19 + ((idx - 1) << 2)) - 1] =
        PaymentType->Cancer_fin[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;
      Qcount = 0;
      while (Qcount < 4) {
        /* m here all 4 quarters of treatment are followed, unlike when difference<1.25 where only few quarters of final year are implemented */
        i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i17 >= 1) && (i17 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &ii_emlrtBCI, sp);
        }

        i18 = (int32_T)muDoubleScalarFloor(time - 1.0);
        if (!((i18 >= 1) && (i18 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &ji_emlrtBCI, sp);
        }

        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &ki_emlrtBCI, sp);
        }

        idx = (int32_T)muDoubleScalarFloor(time - 1.0);
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &li_emlrtBCI, sp);
        }

        PaymentType->QCancer_fin[((i19 + ((idx - 1) << 2)) + 404 * Qcount) - 1] =
          PaymentType->QCancer_fin[((i17 + ((i18 - 1) << 2)) + 404 * Qcount) - 1]
          + 1.0;

        /* m2 this finQ is counting in quarters */
        Qcount++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } else {
      if (Difference > 5.0) {
        i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i17 >= 1) && (i17 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &hd_emlrtBCI, sp);
        }

        i18 = 1 + x1;
        if (!((i18 >= 1) && (i18 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 25, &id_emlrtBCI, sp);
        }

        d2 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &nb_emlrtDCI, sp);
        }

        i19 = (int32_T)d2;
        if (!((i19 >= 1) && (i19 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 404, &jd_emlrtBCI, sp);
        }

        SD->u1.f1.SubCost[(i18 + 25 * (i19 - 1)) - 1] = CostStage_Initial[i17 -
          1];
        i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i17 >= 1) && (i17 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &kd_emlrtBCI, sp);
        }

        d2 = Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0;
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &ob_emlrtDCI, sp);
        }

        i18 = (int32_T)d2;
        if (!((i18 >= 1) && (i18 <= 404))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &ld_emlrtBCI, sp);
        }

        SD->u1.f1.SubCostFut[x1 + 25 * (i18 - 1)] = CostStage_FutInitial[i17 - 1];

        /* m8 SubCost(x1, (Start*4+1)+1 : (Start+5)*4)        = 1/4*CostStage.Cont(Detected.Cancer(z, x1)-6); % CONT */
        /* m8 SubCostFut(x1, (Start*4+1)+1 : (Start+5)*4)     = 1/4*CostStage.FutCont(Detected.Cancer(z, x1)-6); % CONT */
        d2 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
          1.0;
        d3 = time * 4.0;
        if (d2 > d3) {
          i17 = 0;
          i18 = 0;
        } else {
          if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
            emlrtIntegerCheckR2012b(d2, &jb_emlrtDCI, sp);
          }

          i17 = (int32_T)d2;
          if (!((i17 >= 1) && (i17 <= 404))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, 404, &cd_emlrtBCI, sp);
          }

          i17--;
          if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
            emlrtIntegerCheckR2012b(d3, &jb_emlrtDCI, sp);
          }

          i18 = (int32_T)d3;
          if (!((i18 >= 1) && (i18 <= 404))) {
            emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &cd_emlrtBCI, sp);
          }
        }

        idx = i18 - i17;
        for (i18 = 0; i18 < idx; i18++) {
          i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i19 >= 1) && (i19 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &md_emlrtBCI, sp);
          }

          SD->u1.f1.SubCost[x1 + 25 * (i17 + i18)] = 0.25 * CostStage_Cont[i19 -
            1];
        }

        /*  CONT */
        d2 = (Detected_CancerYear[((int32_T)z + 50000 * x1) - 1] * 4.0 + 1.0) +
          1.0;
        d3 = time * 4.0;
        if (d2 > d3) {
          i17 = 0;
          i18 = 0;
        } else {
          if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
            emlrtIntegerCheckR2012b(d2, &fb_emlrtDCI, sp);
          }

          i17 = (int32_T)d2;
          if (!((i17 >= 1) && (i17 <= 404))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, 404, &xc_emlrtBCI, sp);
          }

          i17--;
          if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
            emlrtIntegerCheckR2012b(d3, &fb_emlrtDCI, sp);
          }

          i18 = (int32_T)d3;
          if (!((i18 >= 1) && (i18 <= 404))) {
            emlrtDynamicBoundsCheckR2012b(i18, 1, 404, &xc_emlrtBCI, sp);
          }
        }

        idx = i18 - i17;
        for (i18 = 0; i18 < idx; i18++) {
          i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i19 >= 1) && (i19 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &nd_emlrtBCI, sp);
          }

          SD->u1.f1.SubCostFut[x1 + 25 * (i17 + i18)] = 0.25 *
            CostStage_FutCont[i19 - 1];
        }

        /*  CONT */
        i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i17 >= 1) && (i17 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &od_emlrtBCI, sp);
        }

        i18 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]);
        if (!((i18 >= 1) && (i18 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &pd_emlrtBCI, sp);
        }

        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &qd_emlrtBCI, sp);
        }

        idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]);
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &rd_emlrtBCI, sp);
        }

        PaymentType->Cancer_ini[(i19 + ((idx - 1) << 2)) - 1] =
          PaymentType->Cancer_ini[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;
        i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i17 >= 1) && (i17 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &sd_emlrtBCI, sp);
        }

        i18 = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]);
        if (!((i18 >= 1) && (i18 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &td_emlrtBCI, sp);
        }

        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &ud_emlrtBCI, sp);
        }

        idx = (int32_T)muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]);
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &vd_emlrtBCI, sp);
        }

        PaymentType->QCancer_ini[(i19 + ((idx - 1) << 2)) - 1] =
          PaymentType->QCancer_ini[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;

        /* m the following con_y is for all Difference. it must be just upto */
        /* year 5. So, yyears must be 5? */
        /* %m yyears = floor(Difference-1.25); */
        /* %m qquarters = (Difference-1.25) - floor(Difference-1.25); */
        con_y = 1;
        b_con_y = 0;
        while (b_con_y < 4) {
          con_y = 1 + b_con_y;

          /* %m yyears */
          i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i17 >= 1) && (i17 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &fe_emlrtBCI, sp);
          }

          i18 = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
          if (!((i18 >= 1) && (i18 <= 101))) {
            emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &ge_emlrtBCI, sp);
          }

          i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i19 >= 1) && (i19 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &he_emlrtBCI, sp);
          }

          idx = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
          if (!((idx >= 1) && (idx <= 101))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ie_emlrtBCI, sp);
          }

          PaymentType->Cancer_con[(i19 + ((idx - 1) << 2)) - 1] =
            PaymentType->Cancer_con[(i17 + ((i18 - 1) << 2)) - 1] + 1.0;

          /* ((4*Ende-4*1)-(4*Start+1))/4; */
          i17 = ((1 + b_con_y) << 2) - 3;
          i18 = ((1 + b_con_y) << 2) - i17;
          Qcount = 0;
          while (Qcount <= i18) {
            b_Qcount = i17 + Qcount;
            i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
            if (!((i19 >= 1) && (i19 <= 4))) {
              emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &je_emlrtBCI, sp);
            }

            idx = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
            if (!((idx >= 1) && (idx <= 101))) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ke_emlrtBCI, sp);
            }

            if (!(b_Qcount <= 20)) {
              emlrtDynamicBoundsCheckR2012b(b_Qcount, 1, 20, &le_emlrtBCI, sp);
            }

            ii = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
            if (!((ii >= 1) && (ii <= 4))) {
              emlrtDynamicBoundsCheckR2012b(ii, 1, 4, &me_emlrtBCI, sp);
            }

            i20 = (int32_T)(muDoubleScalarFloor(Start) + (1.0 + (real_T)b_con_y));
            if (!((i20 >= 1) && (i20 <= 101))) {
              emlrtDynamicBoundsCheckR2012b(i20, 1, 101, &ne_emlrtBCI, sp);
            }

            if (!(b_Qcount <= 20)) {
              emlrtDynamicBoundsCheckR2012b(b_Qcount, 1, 20, &oe_emlrtBCI, sp);
            }

            PaymentType->QCancer_con[((ii + ((i20 - 1) << 2)) + 404 * (b_Qcount
              - 1)) - 1] = PaymentType->QCancer_con[((i19 + ((idx - 1) << 2)) +
              404 * (b_Qcount - 1)) - 1] + 1.0;

            /* ((4*Ende-4*1)-(4*Start+1))/4; */
            Qcount++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
          }

          b_con_y++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i17 >= 1) && (i17 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &wd_emlrtBCI, sp);
        }

        i18 = (int32_T)((muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]) + (real_T)con_y) + 1.0);
        if (!((i18 >= 1) && (i18 <= 101))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &xd_emlrtBCI, sp);
        }

        i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
        if (!((i19 >= 1) && (i19 <= 4))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &yd_emlrtBCI, sp);
        }

        idx = (int32_T)((muDoubleScalarFloor(Detected_CancerYear[((int32_T)z +
          50000 * x1) - 1]) + (real_T)con_y) + 1.0);
        if (!((idx >= 1) && (idx <= 101))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ae_emlrtBCI, sp);
        }

        PaymentType->Cancer_con[(i19 + ((idx - 1) << 2)) - 1] =
          PaymentType->Cancer_con[(i17 + ((i18 - 1) << 2)) - 1] + 0.75;
        Qcount = 0;
        while (Qcount < 3) {
          i17 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i17 >= 1) && (i17 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, 4, &be_emlrtBCI, sp);
          }

          i18 = (int32_T)((muDoubleScalarFloor(Start) + (real_T)con_y) + 1.0);
          if (!((i18 >= 1) && (i18 <= 101))) {
            emlrtDynamicBoundsCheckR2012b(i18, 1, 101, &ce_emlrtBCI, sp);
          }

          i19 = (int32_T)(Detected_Cancer[((int32_T)z + 50000 * x1) - 1] - 6.0);
          if (!((i19 >= 1) && (i19 <= 4))) {
            emlrtDynamicBoundsCheckR2012b(i19, 1, 4, &de_emlrtBCI, sp);
          }

          idx = (int32_T)((muDoubleScalarFloor(Start) + (real_T)con_y) + 1.0);
          if (!((idx >= 1) && (idx <= 101))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 101, &ee_emlrtBCI, sp);
          }

          PaymentType->QCancer_con[((i19 + ((idx - 1) << 2)) + 404 * Qcount) - 1]
            = PaymentType->QCancer_con[((i17 + ((i18 - 1) << 2)) + 404 * Qcount)
            - 1] + 1.0;

          /* ((4*Ende-4*1)-(4*Start+1))/4; */
          Qcount++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        /* m PaymentType.Cancer_con(Detected.Cancer(z, x1)-6, floor(Start))  = PaymentType.Cancer_con(Detected.Cancer(z, x1)-6, floor(Start)) + (4*Ende-(4*Start+1))/4; %m2 ini is for q1, and the cont is for rest. but to keep it all integers, I use y */
      }
    }

    x1++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  h_sum(SD->u1.f1.SubCost, SubCostAll);

  /* m2 sum(SubCost,1); remove max and add sum %max(SubCost)/4; % since all costs are quarterly we need to adjust %m3 and remove max() */
  h_sum(SD->u1.f1.SubCostFut, SubCostAllFut);

  /*  since all costs are quarterly we need to adjust %m3 */
  Counter = 1;
  x1 = 0;
  while (x1 < 100) {
    x2 = 0;
    while (x2 < 4) {
      if (!((Counter >= 1) && (Counter <= 404))) {
        emlrtDynamicBoundsCheckR2012b(Counter, 1, 404, &gd_emlrtBCI, sp);
      }

      Money->Treatment[x1] += SubCostAll[Counter - 1];
      Money->FutureTreatment[x1] += SubCostAllFut[Counter - 1];
      Counter++;
      x2++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    x1++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

static void b_Colonoscopy(NumberCrunching_50000StackData *SD, const emlrtStack
  *sp, real_T z, real_T y, real_T q, const real_T Gender[50000], b_struct_T
  *Polyp, c_struct_T *Ca, struct_T *Detected, boolean_T Included[50000], real_T
  DeathCause[50000], real_T DeathYear[50000], real_T DiagnosedCancer[5000000],
  real_T AdvancedPolypsRemoved[100], real_T EarlyPolypsRemoved[100], struct8_T
  *Last, struct9_T *TumorRecord, struct10_T *PaymentType, struct11_T *Money,
  const struct0_T *StageVariables, const struct2_T *Cost, const struct1_T
  *Location, const struct4_T risc, const real_T ColoReachMatrix[1000], const
  real_T MortalityMatrix[400000], const struct3_T *CostStage)
{
  real_T x;
  real_T b_x;
  int32_T i28;
  int8_T CurrentReachMatrix[13];
  int32_T idx;
  int32_T ii;
  int32_T i29;
  int32_T tmp_data[13];
  real_T counter;
  boolean_T exitg6;
  boolean_T guard6 = false;
  int32_T i30;
  int32_T f;
  int32_T b_f;
  real_T Tumor;
  boolean_T b3;
  boolean_T exitg5;
  boolean_T guard5 = false;
  int32_T ii_size_idx_1;
  int32_T i31;
  int32_T i32;
  int32_T i33;
  int32_T b_tmp_data[51];
  int32_T b_Ca[2];
  int32_T Polyp_size[2];
  int32_T b_Polyp[2];
  real_T Polyp_data[51];
  int32_T iv97[2];
  int32_T b_Polyp_size[2];
  int32_T iv98[2];
  int32_T c_Polyp_size[2];
  int32_T iv99[2];
  int32_T d_Polyp_size[2];
  int32_T iv100[2];
  int32_T e_Polyp_size[2];
  real_T StageTmp;
  real_T EStage;
  real_T ELocation;
  real_T ESojourn;
  real_T EDwellTime;
  real_T LocationTmp;
  real_T SojournTmp;
  real_T DwellTimeTmp;
  boolean_T exitg4;
  boolean_T guard4 = false;
  int32_T i34;
  boolean_T exitg3;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T c_tmp_data[25];
  int32_T iv101[2];
  int32_T Ca_size[2];
  real_T Ca_data[25];
  int32_T iv102[2];
  int32_T b_Ca_size[2];
  int32_T iv103[2];
  int32_T c_Ca_size[2];
  int32_T iv104[2];
  int32_T d_Ca_size[2];
  int32_T iv105[2];
  int32_T e_Ca_size[2];
  int32_T iv106[2];
  int32_T f_Ca_size[2];
  int32_T iv107[2];
  int32_T g_Ca_size[2];
  int32_T iv108[2];
  int32_T h_Ca_size[2];
  int32_T iv109[2];
  int32_T i_Ca_size[2];
  boolean_T exitg1;
  boolean_T guard1 = false;
  real_T factor;
  real_T moneyspent;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  display(sprintf('In RS-Study %d patients excluded due to Ca, %d due to Kolo, %d due to past polyps',... */
  /*      AusschlussCa, AusschlussKolo, AusschlussPolyp))  */
  /*  display(sprintf('In RS-examinations %d times polyps, %d times cancer and %d times polyps and cancer found',... */
  /*      PosCa, PosPolyp, PosPolypCa)) */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%         COLONOSCOPY                               %%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  */
  /*  in this function we do a colonoscopy for the respective patient (number */
  /*  z). We cure all detected polyps, and handle the case if a cancer was */
  /*  detected */
  /*  we determine the reach of this colonoscopy (cecum = 1, rectum = 13)) */
  x = b_rand() * 999.0 + 1.0;
  b_x = muDoubleScalarRound(x);
  x = muDoubleScalarRound(x);
  if (x != (int32_T)muDoubleScalarFloor(x)) {
    emlrtIntegerCheckR2012b(x, &ec_emlrtDCI, sp);
  }

  i28 = (int32_T)x;
  if (!((i28 >= 1) && (i28 <= 1000))) {
    emlrtDynamicBoundsCheckR2012b(i28, 1, 1000, &qj_emlrtBCI, sp);
  }

  for (i28 = 0; i28 < 13; i28++) {
    CurrentReachMatrix[i28] = 0;
  }

  if (ColoReachMatrix[(int32_T)b_x - 1] > 13.0) {
    i28 = 0;
    idx = -1;
  } else {
    i28 = (int32_T)ColoReachMatrix[(int32_T)b_x - 1];
    if (!((i28 >= 1) && (i28 <= 13))) {
      emlrtDynamicBoundsCheckR2012b(i28, 1, 13, &pj_emlrtBCI, sp);
    }

    i28--;
    idx = 12;
  }

  ii = idx - i28;
  for (i29 = 0; i29 <= ii; i29++) {
    tmp_data[i29] = i28 + i29;
  }

  ii = (idx - i28) + 1;
  for (i28 = 0; i28 < ii; i28++) {
    CurrentReachMatrix[tmp_data[i28]] = 1;
  }

  counter = 0.0;
  idx = 0;
  ii = 1;
  exitg6 = false;
  while ((!exitg6) && (ii < 52)) {
    guard6 = false;
    if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
      idx++;
      if (idx >= 51) {
        exitg6 = true;
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6) {
      ii++;
    }
  }

  if (1 > idx) {
    i28 = 0;
  } else {
    i28 = idx;
  }

  if (1 > idx) {
    i30 = 0;
  } else {
    i30 = idx;
  }

  emlrtForLoopVectorCheckR2012b(i30, -1.0, 1.0, mxDOUBLE_CLASS, i28,
    &k_emlrtRTEI, sp);
  f = 0;
  while (f <= i28 - 1) {
    b_f = i28 - f;
    if (!((b_f >= 1) && (b_f <= 51))) {
      emlrtDynamicBoundsCheckR2012b(b_f, 1, 51, &xj_emlrtBCI, sp);
    }

    Tumor = Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1];

    /*     % influence of polyp stage */
    /*     % influence of location on detection */
    idx = (int32_T)Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (!((idx >= 1) && (idx <= 10))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &yj_emlrtBCI, sp);
    }

    x = Polyp->PolypLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (x != (int32_T)muDoubleScalarFloor(x)) {
      emlrtIntegerCheckR2012b(x, &gc_emlrtDCI, sp);
    }

    i29 = (int32_T)x;
    if (!((i29 >= 1) && (i29 <= 13))) {
      emlrtDynamicBoundsCheckR2012b(i29, 1, 13, &ak_emlrtBCI, sp);
    }

    b3 = (b_rand() < StageVariables->Colo_Detection[idx - 1] *
          Location->ColoDetection[i29 - 1]);
    x = Polyp->PolypLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (x != (int32_T)muDoubleScalarFloor(x)) {
      emlrtIntegerCheckR2012b(x, &dc_emlrtDCI, sp);
    }

    idx = (int32_T)x;
    if (!((idx >= 1) && (idx <= 13))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &oj_emlrtBCI, sp);
    }

    if (b3 && (CurrentReachMatrix[(int32_T)Polyp->PolypLocation[((int32_T)z +
          50000 * (b_f - 1)) - 1] - 1] == 1)) {
      /*  has current current colonoscopy reached location of polyp? */
      /*  we delete the current polyp */
      idx = 0;
      ii = 1;
      exitg5 = false;
      while ((!exitg5) && (ii < 52)) {
        guard5 = false;
        if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
          idx++;
          if (idx >= 51) {
            exitg5 = true;
          } else {
            guard5 = true;
          }
        } else {
          guard5 = true;
        }

        if (guard5) {
          ii++;
        }
      }

      if (1 > idx) {
        ii_size_idx_1 = 0;
      } else {
        ii_size_idx_1 = idx;
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &nj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &nj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        b_tmp_data[i33] = i31 + i33;
      }

      b_Ca[0] = 1;
      b_Ca[1] = i32 - i31;
      Polyp_size[0] = 1;
      Polyp_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Polyp[i31] = Polyp_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(b_Ca, 2, b_Polyp, 2, &fb_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Polyp_data[i31] = Polyp->Polyps[((int32_T)z + 50000 * (idx + i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->Polyps[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &mj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &mj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        b_tmp_data[i33] = i31 + i33;
      }

      iv97[0] = 1;
      iv97[1] = i32 - i31;
      b_Polyp_size[0] = 1;
      b_Polyp_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Polyp[i31] = b_Polyp_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv97, 2, b_Polyp, 2, &eb_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Polyp_data[i31] = Polyp->PolypYear[((int32_T)z + 50000 * (idx + i31)) -
          1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->PolypYear[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &lj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &lj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        b_tmp_data[i33] = i31 + i33;
      }

      iv98[0] = 1;
      iv98[1] = i32 - i31;
      c_Polyp_size[0] = 1;
      c_Polyp_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Polyp[i31] = c_Polyp_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv98, 2, b_Polyp, 2, &db_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Polyp_data[i31] = Polyp->PolypLocation[((int32_T)z + 50000 * (idx + i31))
          - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->PolypLocation[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &kj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &kj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        b_tmp_data[i33] = i31 + i33;
      }

      iv99[0] = 1;
      iv99[1] = i32 - i31;
      d_Polyp_size[0] = 1;
      d_Polyp_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Polyp[i31] = d_Polyp_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv99, 2, b_Polyp, 2, &cb_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Polyp_data[i31] = Polyp->EarlyProgression[((int32_T)z + 50000 * (idx +
          i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->EarlyProgression[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &jj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &jj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        ii_size_idx_1 = 0;
      } else {
        i31 = b_f - 1;
      }

      ii = ii_size_idx_1 - i31;
      for (i32 = 0; i32 < ii; i32++) {
        b_tmp_data[i32] = i31 + i32;
      }

      iv100[0] = 1;
      iv100[1] = ii_size_idx_1 - i31;
      e_Polyp_size[0] = 1;
      e_Polyp_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Polyp[i31] = e_Polyp_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv100, 2, b_Polyp, 2, &bb_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Polyp_data[i31] = Polyp->AdvProgression[((int32_T)z + 50000 * (idx + i31))
          - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->AdvProgression[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      counter++;
      if (Tumor > 4.0) {
        AdvancedPolypsRemoved[(int32_T)y - 1]++;
        Last->AdvPolyp[(int32_T)z - 1] = y;
      } else {
        Last->Polyp[(int32_T)z - 1] = y;
        EarlyPolypsRemoved[(int32_T)y - 1]++;
      }
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (counter > 2.0) {
    Last->AdvPolyp[(int32_T)z - 1] = y;

    /*  3 polyps counts as an advanced polyp */
  }

  StageTmp = 0.0;
  EStage = 0.0;
  ELocation = 0.0;
  ESojourn = 0.0;
  EDwellTime = 0.0;
  LocationTmp = 0.0;
  SojournTmp = 0.0;
  DwellTimeTmp = 0.0;

  /*  Follow-up */
  idx = 0;
  ii = 1;
  exitg4 = false;
  while ((!exitg4) && (ii < 26)) {
    guard4 = false;
    if (Ca->Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
      idx++;
      if (idx >= 25) {
        exitg4 = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4) {
      ii++;
    }
  }

  if (1 > idx) {
    i28 = 0;
  } else {
    i28 = idx;
  }

  if (1 > idx) {
    i34 = 0;
  } else {
    i34 = idx;
  }

  emlrtForLoopVectorCheckR2012b(i34, -1.0, 1.0, mxDOUBLE_CLASS, i28,
    &j_emlrtRTEI, sp);
  f = 0;
  while (f <= i28 - 1) {
    b_f = i28 - f;
    if (!((b_f >= 1) && (b_f <= 25))) {
      emlrtDynamicBoundsCheckR2012b(b_f, 1, 25, &sj_emlrtBCI, sp);
    }

    Tumor = Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1];

    /*         % influence of cancer stage on detection */
    idx = (int32_T)Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (!((idx >= 1) && (idx <= 10))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &tj_emlrtBCI, sp);
    }

    b3 = (b_rand() < StageVariables->Colo_Detection[idx - 1]);
    x = Ca->CancerLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (x != (int32_T)muDoubleScalarFloor(x)) {
      emlrtIntegerCheckR2012b(x, &cc_emlrtDCI, sp);
    }

    idx = (int32_T)x;
    if (!((idx >= 1) && (idx <= 13))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &ij_emlrtBCI, sp);
    }

    if (b3 && (CurrentReachMatrix[(int32_T)Ca->CancerLocation[((int32_T)z +
          50000 * (b_f - 1)) - 1] - 1] == 1)) {
      /*  has current current colonoscopy reached location of polyp? */
      if (isequal(counter, 0.0)) {
        counter = -1.0;
      }

      /*  the cancer is now a detected cancer */
      idx = 0;
      ii = 1;
      exitg3 = false;
      while ((!exitg3) && (ii < 51)) {
        guard3 = false;
        if (Detected->Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
          idx++;
          if (idx >= 50) {
            exitg3 = true;
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }

        if (guard3) {
          ii++;
        }
      }

      if (1 > idx) {
        ii_size_idx_1 = 0;
      } else {
        ii_size_idx_1 = idx;
      }

      if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 50))) {
        emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 50, &uj_emlrtBCI, sp);
      }

      Detected->Cancer[((int32_T)z + 50000 * ii_size_idx_1) - 1] = Ca->Cancer
        [((int32_T)z + 50000 * (b_f - 1)) - 1];
      Detected->CancerYear[((int32_T)z + 50000 * ii_size_idx_1) - 1] = y + (q -
        1.0) / 4.0;
      Detected->CancerLocation[((int32_T)z + 50000 * ii_size_idx_1) - 1] =
        Ca->CancerLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
      x = b_rand() * 999.0 + 1.0;
      idx = (int32_T)(Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1] - 6.0);
      if (!((idx >= 1) && (idx <= 4))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 4, &vj_emlrtBCI, sp);
      }

      x = muDoubleScalarRound(x);
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &fc_emlrtDCI, sp);
      }

      i29 = (int32_T)x;
      if (!((i29 >= 1) && (i29 <= 1000))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, 1000, &wj_emlrtBCI, sp);
      }

      Detected->MortTime[((int32_T)z + 50000 * ii_size_idx_1) - 1] =
        MortalityMatrix[((idx + (((int32_T)y - 1) << 2)) + 400 * (i29 - 1)) - 1];

      /*  dfisplay(sprintf('cancer stage %d mortality %d months', Detected.Cancer(z, pos), Detected.MortTime(z, pos))) */
      /*  we need keep track of key parameters */
      /*  Stage Location SojournTime Sex DetectionMode */
      StageTmp = Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1];
      LocationTmp = Ca->CancerLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
      SojournTmp = (y + (q - 1.0) / 4.0) - Ca->CancerYear[((int32_T)z + 50000 *
        (b_f - 1)) - 1];
      DwellTimeTmp = Ca->DwellTime[((int32_T)z + 50000 * (b_f - 1)) - 1];

      /*  the original cancer is removed from the database */
      idx = 0;
      ii = 1;
      exitg2 = false;
      while ((!exitg2) && (ii < 26)) {
        guard2 = false;
        if (Ca->Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
          idx++;
          if (idx >= 25) {
            exitg2 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          ii++;
        }
      }

      if (1 > idx) {
        ii_size_idx_1 = 0;
      } else {
        ii_size_idx_1 = idx;
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &hj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &hj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        c_tmp_data[i33] = i31 + i33;
      }

      iv101[0] = 1;
      iv101[1] = i32 - i31;
      Ca_size[0] = 1;
      Ca_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Ca[i31] = Ca_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv101, 2, b_Ca, 2, &ab_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Ca_data[i31] = Ca->Cancer[((int32_T)z + 50000 * (idx + i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->Cancer[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &gj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &gj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        c_tmp_data[i33] = i31 + i33;
      }

      iv102[0] = 1;
      iv102[1] = i32 - i31;
      b_Ca_size[0] = 1;
      b_Ca_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Ca[i31] = b_Ca_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv102, 2, b_Ca, 2, &y_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Ca_data[i31] = Ca->CancerYear[((int32_T)z + 50000 * (idx + i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->CancerYear[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &fj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &fj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        c_tmp_data[i33] = i31 + i33;
      }

      iv103[0] = 1;
      iv103[1] = i32 - i31;
      c_Ca_size[0] = 1;
      c_Ca_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Ca[i31] = c_Ca_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv103, 2, b_Ca, 2, &x_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Ca_data[i31] = Ca->CancerLocation[((int32_T)z + 50000 * (idx + i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->CancerLocation[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &ej_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &ej_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        c_tmp_data[i33] = i31 + i33;
      }

      iv104[0] = 1;
      iv104[1] = i32 - i31;
      d_Ca_size[0] = 1;
      d_Ca_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Ca[i31] = d_Ca_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv104, 2, b_Ca, 2, &w_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Ca_data[i31] = Ca->DwellTime[((int32_T)z + 50000 * (idx + i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->DwellTime[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      /*  POSSIBLY DELETE */
      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &dj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &dj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        c_tmp_data[i33] = i31 + i33;
      }

      iv105[0] = 1;
      iv105[1] = i32 - i31;
      e_Ca_size[0] = 1;
      e_Ca_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Ca[i31] = e_Ca_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv105, 2, b_Ca, 2, &v_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Ca_data[i31] = Ca->SympTime[((int32_T)z + 50000 * (idx + i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->SympTime[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &cj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &cj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        c_tmp_data[i33] = i31 + i33;
      }

      iv106[0] = 1;
      iv106[1] = i32 - i31;
      f_Ca_size[0] = 1;
      f_Ca_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Ca[i31] = f_Ca_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv106, 2, b_Ca, 2, &u_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Ca_data[i31] = Ca->SympStage[((int32_T)z + 50000 * (idx + i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->SympStage[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &bj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &bj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        c_tmp_data[i33] = i31 + i33;
      }

      iv107[0] = 1;
      iv107[1] = i32 - i31;
      g_Ca_size[0] = 1;
      g_Ca_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Ca[i31] = g_Ca_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv107, 2, b_Ca, 2, &t_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Ca_data[i31] = Ca->TimeStage_I[((int32_T)z + 50000 * (idx + i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->TimeStage_I[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &aj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &aj_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = b_f - 1;
        i32 = ii_size_idx_1;
      }

      ii = i32 - i31;
      for (i33 = 0; i33 < ii; i33++) {
        c_tmp_data[i33] = i31 + i33;
      }

      iv108[0] = 1;
      iv108[1] = i32 - i31;
      h_Ca_size[0] = 1;
      h_Ca_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Ca[i31] = h_Ca_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv108, 2, b_Ca, 2, &s_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Ca_data[i31] = Ca->TimeStage_II[((int32_T)z + 50000 * (idx + i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->TimeStage_II[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i29 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &yi_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &yi_emlrtBCI,
            sp);
        }

        i29 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i31 = 0;
        ii_size_idx_1 = 0;
      } else {
        i31 = b_f - 1;
      }

      ii = ii_size_idx_1 - i31;
      for (i32 = 0; i32 < ii; i32++) {
        c_tmp_data[i32] = i31 + i32;
      }

      iv109[0] = 1;
      iv109[1] = ii_size_idx_1 - i31;
      i_Ca_size[0] = 1;
      i_Ca_size[1] = i29 - idx;
      for (i31 = 0; i31 < 2; i31++) {
        b_Ca[i31] = i_Ca_size[i31];
      }

      emlrtSubAssignSizeCheckR2012b(iv109, 2, b_Ca, 2, &r_emlrtECI, sp);
      ii = i29 - idx;
      for (i31 = 0; i31 < ii; i31++) {
        Ca_data[i31] = Ca->TimeStage_III[((int32_T)z + 50000 * (idx + i31)) - 1];
      }

      ii = i29 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->TimeStage_III[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      DiagnosedCancer[((int32_T)y + 100 * ((int32_T)z - 1)) - 1] =
        muDoubleScalarMax(DiagnosedCancer[((int32_T)y + 100 * ((int32_T)z - 1))
                          - 1], Tumor);

      /*  max in case we would have found 2 tumors */
      Last->Cancer[(int32_T)z - 1] = y;

      /*  Follow-up */
    }

    if ((!isequal(StageTmp, 0.0)) && (StageTmp > EStage)) {
      EStage = StageTmp;
      ELocation = LocationTmp;
      ESojourn = SojournTmp;
      EDwellTime = DwellTimeTmp;
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (!isequal(StageTmp, 0.0)) {
    idx = 0;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii < 5001)) {
      guard1 = false;
      if (TumorRecord->Stage[((int32_T)y + 100 * (ii - 1)) - 1] != 0.0) {
        idx++;
        if (idx >= 5000) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (1 > idx) {
      ii_size_idx_1 = 0;
    } else {
      ii_size_idx_1 = idx;
    }

    if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 5000))) {
      emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 5000, &rj_emlrtBCI, sp);
    }

    TumorRecord->Stage[((int32_T)y + 100 * ii_size_idx_1) - 1] = EStage;
    TumorRecord->Location[((int32_T)y + 100 * ii_size_idx_1) - 1] = ELocation;
    TumorRecord->DwellTime[((int32_T)y + 100 * ii_size_idx_1) - 1] = EDwellTime;
    TumorRecord->Sojourn[((int32_T)y + 100 * ii_size_idx_1) - 1] = ESojourn;
    TumorRecord->Gender[((int32_T)y + 100 * ii_size_idx_1) - 1] = Gender
      [(int32_T)z - 1];
    TumorRecord->Detection[((int32_T)y + 100 * ii_size_idx_1) - 1] = 3.0;
    TumorRecord->PatientNumber[((int32_T)y + 100 * ii_size_idx_1) - 1] = z;

    /*  RS ONLY !!!!!! */
  }

  Last->Colonoscopy[(int32_T)z - 1] = y;
  if (isequal(counter, 0.0)) {
    /*  in this case no tumor or polyp */
    factor = 0.75;
    moneyspent = Cost->Colonoscopy;
    PaymentType->Colonoscopy[2 + (((int32_T)y - 1) << 2)]++;

    /*  AllCost(y) = AllCost(y) + Cost.Colonoscopy; */
  } else if (isequal(counter, -1.0)) {
    factor = 1.5;
    moneyspent = Cost->Colonoscopy_Cancer;
    PaymentType->Colonoscopy_Cancer[2 + (((int32_T)y - 1) << 2)]++;

    /*  AllCost(y) = AllCost(y) + Cost.Colonoscopy_Polyp; */
  } else {
    factor = 1.5;
    moneyspent = Cost->Colonoscopy_Polyp;
    PaymentType->ColonoscopyPolyp[2 + (((int32_T)y - 1) << 2)]++;
  }

  /* %%% Complications */
  if (b_rand() < risc.Colonoscopy_RiscPerforation * factor) {
    /*  a perforation happend */
    moneyspent += Cost->Colonoscopy_Perforation;
    PaymentType->Perforation[2 + (((int32_T)y - 1) << 2)]++;
    if (b_rand() < risc.DeathPerforation) {
      /*  patient died during colonoscopy from a perforation */
      Included[(int32_T)z - 1] = false;
      DeathCause[(int32_T)z - 1] = 3.0;
      DeathYear[(int32_T)z - 1] = y;

      /*  we add the costs */
      st.site = &sc_emlrtRSI;
      AddCosts(SD, &st, Detected->Cancer, Detected->CancerYear,
               CostStage->Initial, CostStage->Cont, CostStage->FutInitial,
               CostStage->FutCont, PaymentType, Money, y + (q - 1.0) / 4.0, z);
    }
  } else if (b_rand() < risc.Colonoscopy_RiscSerosaBurn * factor) {
    /*  serosal burn */
    moneyspent += Cost->Colonoscopy_Serosal_burn;
    PaymentType->Serosa[2 + (((int32_T)y - 1) << 2)]++;
  } else if (b_rand() < risc.Colonoscopy_RiscBleeding * factor) {
    /*  a bleeding episode (no transfusion) */
    moneyspent += Cost->Colonoscopy_bleed;
    PaymentType->Bleeding[2 + (((int32_T)y - 1) << 2)]++;
  } else {
    if (b_rand() < risc.c_Colonoscopy_RiscBleedingTrans * factor) {
      /*  bleeding recquiring transfusion */
      moneyspent += Cost->Colonoscopy_bleed_transfusion;
      PaymentType->BleedingTransf[2 + (((int32_T)y - 1) << 2)]++;
      if (b_rand() < risc.DeathBleedingTransfusion) {
        /*  patient died during colonoscopy from a bleeding complication */
        Included[(int32_T)z - 1] = false;
        DeathCause[(int32_T)z - 1] = 3.0;
        DeathYear[(int32_T)z - 1] = y;
      }
    }
  }

  /*  Follow-up */
  Money->FollowUp[(int32_T)y - 1] += moneyspent;
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m16;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m16, 2, pArrays, "sprintf", true,
    location);
}

static void c_Colonoscopy(NumberCrunching_50000StackData *SD, const emlrtStack
  *sp, real_T z, real_T y, real_T q, const real_T Gender[50000], b_struct_T
  *Polyp, c_struct_T *Ca, struct_T *Detected, boolean_T Included[50000], real_T
  DeathCause[50000], real_T DeathYear[50000], real_T DiagnosedCancer[5000000],
  real_T AdvancedPolypsRemoved[100], real_T EarlyPolypsRemoved[100], struct8_T
  *Last, struct9_T *TumorRecord, struct10_T *PaymentType, struct11_T *Money,
  const struct0_T *StageVariables, const struct2_T *Cost, const struct1_T
  *Location, const struct4_T risc, const real_T ColoReachMatrix[1000], const
  real_T MortalityMatrix[400000], const struct3_T *CostStage)
{
  real_T x;
  real_T b_x;
  int32_T i35;
  int8_T CurrentReachMatrix[13];
  int32_T idx;
  int32_T ii;
  int32_T i36;
  int32_T tmp_data[13];
  real_T counter;
  boolean_T exitg6;
  boolean_T guard6 = false;
  int32_T i37;
  int32_T f;
  int32_T b_f;
  real_T Tumor;
  boolean_T b4;
  boolean_T exitg5;
  boolean_T guard5 = false;
  int32_T ii_size_idx_1;
  int32_T i38;
  int32_T i39;
  int32_T i40;
  int32_T b_tmp_data[51];
  int32_T b_Ca[2];
  int32_T Polyp_size[2];
  int32_T b_Polyp[2];
  real_T Polyp_data[51];
  int32_T iv110[2];
  int32_T b_Polyp_size[2];
  int32_T iv111[2];
  int32_T c_Polyp_size[2];
  int32_T iv112[2];
  int32_T d_Polyp_size[2];
  int32_T iv113[2];
  int32_T e_Polyp_size[2];
  real_T StageTmp;
  real_T EStage;
  real_T ELocation;
  real_T ESojourn;
  real_T EDwellTime;
  real_T LocationTmp;
  real_T SojournTmp;
  real_T DwellTimeTmp;
  boolean_T exitg4;
  boolean_T guard4 = false;
  int32_T i41;
  boolean_T exitg3;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T c_tmp_data[25];
  int32_T iv114[2];
  int32_T Ca_size[2];
  real_T Ca_data[25];
  int32_T iv115[2];
  int32_T b_Ca_size[2];
  int32_T iv116[2];
  int32_T c_Ca_size[2];
  int32_T iv117[2];
  int32_T d_Ca_size[2];
  int32_T iv118[2];
  int32_T e_Ca_size[2];
  int32_T iv119[2];
  int32_T f_Ca_size[2];
  int32_T iv120[2];
  int32_T g_Ca_size[2];
  int32_T iv121[2];
  int32_T h_Ca_size[2];
  int32_T iv122[2];
  int32_T i_Ca_size[2];
  boolean_T exitg1;
  boolean_T guard1 = false;
  real_T factor;
  real_T moneyspent;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  display(sprintf('In RS-Study %d patients excluded due to Ca, %d due to Kolo, %d due to past polyps',... */
  /*      AusschlussCa, AusschlussKolo, AusschlussPolyp))  */
  /*  display(sprintf('In RS-examinations %d times polyps, %d times cancer and %d times polyps and cancer found',... */
  /*      PosCa, PosPolyp, PosPolypCa)) */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%         COLONOSCOPY                               %%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  */
  /*  in this function we do a colonoscopy for the respective patient (number */
  /*  z). We cure all detected polyps, and handle the case if a cancer was */
  /*  detected */
  /*  we determine the reach of this colonoscopy (cecum = 1, rectum = 13)) */
  x = b_rand() * 999.0 + 1.0;
  b_x = muDoubleScalarRound(x);
  x = muDoubleScalarRound(x);
  if (x != (int32_T)muDoubleScalarFloor(x)) {
    emlrtIntegerCheckR2012b(x, &ec_emlrtDCI, sp);
  }

  i35 = (int32_T)x;
  if (!((i35 >= 1) && (i35 <= 1000))) {
    emlrtDynamicBoundsCheckR2012b(i35, 1, 1000, &qj_emlrtBCI, sp);
  }

  for (i35 = 0; i35 < 13; i35++) {
    CurrentReachMatrix[i35] = 0;
  }

  if (ColoReachMatrix[(int32_T)b_x - 1] > 13.0) {
    i35 = 0;
    idx = -1;
  } else {
    i35 = (int32_T)ColoReachMatrix[(int32_T)b_x - 1];
    if (!((i35 >= 1) && (i35 <= 13))) {
      emlrtDynamicBoundsCheckR2012b(i35, 1, 13, &pj_emlrtBCI, sp);
    }

    i35--;
    idx = 12;
  }

  ii = idx - i35;
  for (i36 = 0; i36 <= ii; i36++) {
    tmp_data[i36] = i35 + i36;
  }

  ii = (idx - i35) + 1;
  for (i35 = 0; i35 < ii; i35++) {
    CurrentReachMatrix[tmp_data[i35]] = 1;
  }

  counter = 0.0;
  idx = 0;
  ii = 1;
  exitg6 = false;
  while ((!exitg6) && (ii < 52)) {
    guard6 = false;
    if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
      idx++;
      if (idx >= 51) {
        exitg6 = true;
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6) {
      ii++;
    }
  }

  if (1 > idx) {
    i35 = 0;
  } else {
    i35 = idx;
  }

  if (1 > idx) {
    i37 = 0;
  } else {
    i37 = idx;
  }

  emlrtForLoopVectorCheckR2012b(i37, -1.0, 1.0, mxDOUBLE_CLASS, i35,
    &k_emlrtRTEI, sp);
  f = 0;
  while (f <= i35 - 1) {
    b_f = i35 - f;
    if (!((b_f >= 1) && (b_f <= 51))) {
      emlrtDynamicBoundsCheckR2012b(b_f, 1, 51, &xj_emlrtBCI, sp);
    }

    Tumor = Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1];

    /*     % influence of polyp stage */
    /*     % influence of location on detection */
    idx = (int32_T)Polyp->Polyps[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (!((idx >= 1) && (idx <= 10))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &yj_emlrtBCI, sp);
    }

    x = Polyp->PolypLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (x != (int32_T)muDoubleScalarFloor(x)) {
      emlrtIntegerCheckR2012b(x, &gc_emlrtDCI, sp);
    }

    i36 = (int32_T)x;
    if (!((i36 >= 1) && (i36 <= 13))) {
      emlrtDynamicBoundsCheckR2012b(i36, 1, 13, &ak_emlrtBCI, sp);
    }

    b4 = (b_rand() < StageVariables->Colo_Detection[idx - 1] *
          Location->ColoDetection[i36 - 1]);
    x = Polyp->PolypLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (x != (int32_T)muDoubleScalarFloor(x)) {
      emlrtIntegerCheckR2012b(x, &dc_emlrtDCI, sp);
    }

    idx = (int32_T)x;
    if (!((idx >= 1) && (idx <= 13))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &oj_emlrtBCI, sp);
    }

    if (b4 && (CurrentReachMatrix[(int32_T)Polyp->PolypLocation[((int32_T)z +
          50000 * (b_f - 1)) - 1] - 1] == 1)) {
      /*  has current current colonoscopy reached location of polyp? */
      /*  we delete the current polyp */
      idx = 0;
      ii = 1;
      exitg5 = false;
      while ((!exitg5) && (ii < 52)) {
        guard5 = false;
        if (Polyp->Polyps[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
          idx++;
          if (idx >= 51) {
            exitg5 = true;
          } else {
            guard5 = true;
          }
        } else {
          guard5 = true;
        }

        if (guard5) {
          ii++;
        }
      }

      if (1 > idx) {
        ii_size_idx_1 = 0;
      } else {
        ii_size_idx_1 = idx;
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &nj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &nj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        b_tmp_data[i40] = i38 + i40;
      }

      b_Ca[0] = 1;
      b_Ca[1] = i39 - i38;
      Polyp_size[0] = 1;
      Polyp_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Polyp[i38] = Polyp_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(b_Ca, 2, b_Polyp, 2, &fb_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Polyp_data[i38] = Polyp->Polyps[((int32_T)z + 50000 * (idx + i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->Polyps[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &mj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &mj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        b_tmp_data[i40] = i38 + i40;
      }

      iv110[0] = 1;
      iv110[1] = i39 - i38;
      b_Polyp_size[0] = 1;
      b_Polyp_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Polyp[i38] = b_Polyp_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv110, 2, b_Polyp, 2, &eb_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Polyp_data[i38] = Polyp->PolypYear[((int32_T)z + 50000 * (idx + i38)) -
          1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->PolypYear[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &lj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &lj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        b_tmp_data[i40] = i38 + i40;
      }

      iv111[0] = 1;
      iv111[1] = i39 - i38;
      c_Polyp_size[0] = 1;
      c_Polyp_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Polyp[i38] = c_Polyp_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv111, 2, b_Polyp, 2, &db_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Polyp_data[i38] = Polyp->PolypLocation[((int32_T)z + 50000 * (idx + i38))
          - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->PolypLocation[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &kj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &kj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        b_tmp_data[i40] = i38 + i40;
      }

      iv112[0] = 1;
      iv112[1] = i39 - i38;
      d_Polyp_size[0] = 1;
      d_Polyp_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Polyp[i38] = d_Polyp_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv112, 2, b_Polyp, 2, &cb_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Polyp_data[i38] = Polyp->EarlyProgression[((int32_T)z + 50000 * (idx +
          i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->EarlyProgression[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &jj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 51))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 51, &jj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        ii_size_idx_1 = 0;
      } else {
        i38 = b_f - 1;
      }

      ii = ii_size_idx_1 - i38;
      for (i39 = 0; i39 < ii; i39++) {
        b_tmp_data[i39] = i38 + i39;
      }

      iv113[0] = 1;
      iv113[1] = ii_size_idx_1 - i38;
      e_Polyp_size[0] = 1;
      e_Polyp_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Polyp[i38] = e_Polyp_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv113, 2, b_Polyp, 2, &bb_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Polyp_data[i38] = Polyp->AdvProgression[((int32_T)z + 50000 * (idx + i38))
          - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Polyp->AdvProgression[((int32_T)z + 50000 * b_tmp_data[idx]) - 1] =
          Polyp_data[idx];
      }

      counter++;
      if (Tumor > 4.0) {
        AdvancedPolypsRemoved[(int32_T)y - 1]++;
        Last->AdvPolyp[(int32_T)z - 1] = y;
      } else {
        Last->Polyp[(int32_T)z - 1] = y;
        EarlyPolypsRemoved[(int32_T)y - 1]++;
      }
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (counter > 2.0) {
    Last->AdvPolyp[(int32_T)z - 1] = y;

    /*  3 polyps counts as an advanced polyp */
  }

  StageTmp = 0.0;
  EStage = 0.0;
  ELocation = 0.0;
  ESojourn = 0.0;
  EDwellTime = 0.0;
  LocationTmp = 0.0;
  SojournTmp = 0.0;
  DwellTimeTmp = 0.0;

  /* m2 moved the switch statement up. otherwise without cancer m remains 0 */
  /*  Screening */
  idx = 0;
  ii = 1;
  exitg4 = false;
  while ((!exitg4) && (ii < 26)) {
    guard4 = false;
    if (Ca->Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
      idx++;
      if (idx >= 25) {
        exitg4 = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4) {
      ii++;
    }
  }

  if (1 > idx) {
    i35 = 0;
  } else {
    i35 = idx;
  }

  if (1 > idx) {
    i41 = 0;
  } else {
    i41 = idx;
  }

  emlrtForLoopVectorCheckR2012b(i41, -1.0, 1.0, mxDOUBLE_CLASS, i35,
    &j_emlrtRTEI, sp);
  f = 0;
  while (f <= i35 - 1) {
    b_f = i35 - f;
    if (!((b_f >= 1) && (b_f <= 25))) {
      emlrtDynamicBoundsCheckR2012b(b_f, 1, 25, &sj_emlrtBCI, sp);
    }

    Tumor = Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1];

    /*         % influence of cancer stage on detection */
    idx = (int32_T)Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (!((idx >= 1) && (idx <= 10))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 10, &tj_emlrtBCI, sp);
    }

    b4 = (b_rand() < StageVariables->Colo_Detection[idx - 1]);
    x = Ca->CancerLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
    if (x != (int32_T)muDoubleScalarFloor(x)) {
      emlrtIntegerCheckR2012b(x, &cc_emlrtDCI, sp);
    }

    idx = (int32_T)x;
    if (!((idx >= 1) && (idx <= 13))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 13, &ij_emlrtBCI, sp);
    }

    if (b4 && (CurrentReachMatrix[(int32_T)Ca->CancerLocation[((int32_T)z +
          50000 * (b_f - 1)) - 1] - 1] == 1)) {
      /*  has current current colonoscopy reached location of polyp? */
      if (isequal(counter, 0.0)) {
        counter = -1.0;
      }

      /*  the cancer is now a detected cancer */
      idx = 0;
      ii = 1;
      exitg3 = false;
      while ((!exitg3) && (ii < 51)) {
        guard3 = false;
        if (Detected->Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
          idx++;
          if (idx >= 50) {
            exitg3 = true;
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }

        if (guard3) {
          ii++;
        }
      }

      if (1 > idx) {
        ii_size_idx_1 = 0;
      } else {
        ii_size_idx_1 = idx;
      }

      if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 50))) {
        emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 50, &uj_emlrtBCI, sp);
      }

      Detected->Cancer[((int32_T)z + 50000 * ii_size_idx_1) - 1] = Ca->Cancer
        [((int32_T)z + 50000 * (b_f - 1)) - 1];
      Detected->CancerYear[((int32_T)z + 50000 * ii_size_idx_1) - 1] = y + (q -
        1.0) / 4.0;
      Detected->CancerLocation[((int32_T)z + 50000 * ii_size_idx_1) - 1] =
        Ca->CancerLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
      x = b_rand() * 999.0 + 1.0;
      idx = (int32_T)(Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1] - 6.0);
      if (!((idx >= 1) && (idx <= 4))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 4, &vj_emlrtBCI, sp);
      }

      x = muDoubleScalarRound(x);
      if (x != (int32_T)muDoubleScalarFloor(x)) {
        emlrtIntegerCheckR2012b(x, &fc_emlrtDCI, sp);
      }

      i36 = (int32_T)x;
      if (!((i36 >= 1) && (i36 <= 1000))) {
        emlrtDynamicBoundsCheckR2012b(i36, 1, 1000, &wj_emlrtBCI, sp);
      }

      Detected->MortTime[((int32_T)z + 50000 * ii_size_idx_1) - 1] =
        MortalityMatrix[((idx + (((int32_T)y - 1) << 2)) + 400 * (i36 - 1)) - 1];

      /*  dfisplay(sprintf('cancer stage %d mortality %d months', Detected.Cancer(z, pos), Detected.MortTime(z, pos))) */
      /*  we need keep track of key parameters */
      /*  Stage Location SojournTime Sex DetectionMode */
      StageTmp = Ca->Cancer[((int32_T)z + 50000 * (b_f - 1)) - 1];
      LocationTmp = Ca->CancerLocation[((int32_T)z + 50000 * (b_f - 1)) - 1];
      SojournTmp = (y + (q - 1.0) / 4.0) - Ca->CancerYear[((int32_T)z + 50000 *
        (b_f - 1)) - 1];
      DwellTimeTmp = Ca->DwellTime[((int32_T)z + 50000 * (b_f - 1)) - 1];

      /*  the original cancer is removed from the database */
      idx = 0;
      ii = 1;
      exitg2 = false;
      while ((!exitg2) && (ii < 26)) {
        guard2 = false;
        if (Ca->Cancer[((int32_T)z + 50000 * (ii - 1)) - 1] != 0.0) {
          idx++;
          if (idx >= 25) {
            exitg2 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          ii++;
        }
      }

      if (1 > idx) {
        ii_size_idx_1 = 0;
      } else {
        ii_size_idx_1 = idx;
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &hj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &hj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        c_tmp_data[i40] = i38 + i40;
      }

      iv114[0] = 1;
      iv114[1] = i39 - i38;
      Ca_size[0] = 1;
      Ca_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Ca[i38] = Ca_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv114, 2, b_Ca, 2, &ab_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Ca_data[i38] = Ca->Cancer[((int32_T)z + 50000 * (idx + i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->Cancer[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &gj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &gj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        c_tmp_data[i40] = i38 + i40;
      }

      iv115[0] = 1;
      iv115[1] = i39 - i38;
      b_Ca_size[0] = 1;
      b_Ca_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Ca[i38] = b_Ca_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv115, 2, b_Ca, 2, &y_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Ca_data[i38] = Ca->CancerYear[((int32_T)z + 50000 * (idx + i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->CancerYear[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &fj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &fj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        c_tmp_data[i40] = i38 + i40;
      }

      iv116[0] = 1;
      iv116[1] = i39 - i38;
      c_Ca_size[0] = 1;
      c_Ca_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Ca[i38] = c_Ca_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv116, 2, b_Ca, 2, &x_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Ca_data[i38] = Ca->CancerLocation[((int32_T)z + 50000 * (idx + i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->CancerLocation[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &ej_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &ej_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        c_tmp_data[i40] = i38 + i40;
      }

      iv117[0] = 1;
      iv117[1] = i39 - i38;
      d_Ca_size[0] = 1;
      d_Ca_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Ca[i38] = d_Ca_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv117, 2, b_Ca, 2, &w_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Ca_data[i38] = Ca->DwellTime[((int32_T)z + 50000 * (idx + i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->DwellTime[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      /*  POSSIBLY DELETE */
      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &dj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &dj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        c_tmp_data[i40] = i38 + i40;
      }

      iv118[0] = 1;
      iv118[1] = i39 - i38;
      e_Ca_size[0] = 1;
      e_Ca_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Ca[i38] = e_Ca_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv118, 2, b_Ca, 2, &v_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Ca_data[i38] = Ca->SympTime[((int32_T)z + 50000 * (idx + i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->SympTime[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &cj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &cj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        c_tmp_data[i40] = i38 + i40;
      }

      iv119[0] = 1;
      iv119[1] = i39 - i38;
      f_Ca_size[0] = 1;
      f_Ca_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Ca[i38] = f_Ca_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv119, 2, b_Ca, 2, &u_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Ca_data[i38] = Ca->SympStage[((int32_T)z + 50000 * (idx + i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->SympStage[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] = Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &bj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &bj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        c_tmp_data[i40] = i38 + i40;
      }

      iv120[0] = 1;
      iv120[1] = i39 - i38;
      g_Ca_size[0] = 1;
      g_Ca_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Ca[i38] = g_Ca_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv120, 2, b_Ca, 2, &t_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Ca_data[i38] = Ca->TimeStage_I[((int32_T)z + 50000 * (idx + i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->TimeStage_I[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &aj_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &aj_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = b_f - 1;
        i39 = ii_size_idx_1;
      }

      ii = i39 - i38;
      for (i40 = 0; i40 < ii; i40++) {
        c_tmp_data[i40] = i38 + i40;
      }

      iv121[0] = 1;
      iv121[1] = i39 - i38;
      h_Ca_size[0] = 1;
      h_Ca_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Ca[i38] = h_Ca_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv121, 2, b_Ca, 2, &s_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Ca_data[i38] = Ca->TimeStage_II[((int32_T)z + 50000 * (idx + i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->TimeStage_II[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      if (b_f + 1 > ii_size_idx_1 + 1) {
        idx = 0;
        i36 = 0;
      } else {
        if (!((b_f + 1 >= 1) && (b_f + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 25, &yi_emlrtBCI, sp);
        }

        idx = b_f;
        if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
          emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25, &yi_emlrtBCI,
            sp);
        }

        i36 = ii_size_idx_1 + 1;
      }

      if (b_f > ii_size_idx_1) {
        i38 = 0;
        ii_size_idx_1 = 0;
      } else {
        i38 = b_f - 1;
      }

      ii = ii_size_idx_1 - i38;
      for (i39 = 0; i39 < ii; i39++) {
        c_tmp_data[i39] = i38 + i39;
      }

      iv122[0] = 1;
      iv122[1] = ii_size_idx_1 - i38;
      i_Ca_size[0] = 1;
      i_Ca_size[1] = i36 - idx;
      for (i38 = 0; i38 < 2; i38++) {
        b_Ca[i38] = i_Ca_size[i38];
      }

      emlrtSubAssignSizeCheckR2012b(iv122, 2, b_Ca, 2, &r_emlrtECI, sp);
      ii = i36 - idx;
      for (i38 = 0; i38 < ii; i38++) {
        Ca_data[i38] = Ca->TimeStage_III[((int32_T)z + 50000 * (idx + i38)) - 1];
      }

      ii = i36 - idx;
      for (idx = 0; idx < ii; idx++) {
        Ca->TimeStage_III[((int32_T)z + 50000 * c_tmp_data[idx]) - 1] =
          Ca_data[idx];
      }

      DiagnosedCancer[((int32_T)y + 100 * ((int32_T)z - 1)) - 1] =
        muDoubleScalarMax(DiagnosedCancer[((int32_T)y + 100 * ((int32_T)z - 1))
                          - 1], Tumor);

      /*  max in case we would have found 2 tumors */
      Last->Cancer[(int32_T)z - 1] = y;

      /*  Screening */
    }

    if ((!isequal(StageTmp, 0.0)) && (StageTmp > EStage)) {
      EStage = StageTmp;
      ELocation = LocationTmp;
      ESojourn = SojournTmp;
      EDwellTime = DwellTimeTmp;
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (!isequal(StageTmp, 0.0)) {
    idx = 0;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii < 5001)) {
      guard1 = false;
      if (TumorRecord->Stage[((int32_T)y + 100 * (ii - 1)) - 1] != 0.0) {
        idx++;
        if (idx >= 5000) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (1 > idx) {
      ii_size_idx_1 = 0;
    } else {
      ii_size_idx_1 = idx;
    }

    if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 5000))) {
      emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 5000, &rj_emlrtBCI, sp);
    }

    TumorRecord->Stage[((int32_T)y + 100 * ii_size_idx_1) - 1] = EStage;
    TumorRecord->Location[((int32_T)y + 100 * ii_size_idx_1) - 1] = ELocation;
    TumorRecord->DwellTime[((int32_T)y + 100 * ii_size_idx_1) - 1] = EDwellTime;
    TumorRecord->Sojourn[((int32_T)y + 100 * ii_size_idx_1) - 1] = ESojourn;
    TumorRecord->Gender[((int32_T)y + 100 * ii_size_idx_1) - 1] = Gender
      [(int32_T)z - 1];
    TumorRecord->Detection[((int32_T)y + 100 * ii_size_idx_1) - 1] = 1.0;
    TumorRecord->PatientNumber[((int32_T)y + 100 * ii_size_idx_1) - 1] = z;

    /*  RS ONLY !!!!!! */
  }

  Last->Colonoscopy[(int32_T)z - 1] = y;
  if (isequal(counter, 0.0)) {
    /*  in this case no tumor or polyp */
    factor = 0.75;
    moneyspent = Cost->Colonoscopy;
    PaymentType->Colonoscopy[((int32_T)y - 1) << 2]++;

    /*  AllCost(y) = AllCost(y) + Cost.Colonoscopy; */
  } else if (isequal(counter, -1.0)) {
    factor = 1.5;
    moneyspent = Cost->Colonoscopy_Cancer;
    PaymentType->Colonoscopy_Cancer[((int32_T)y - 1) << 2]++;

    /*  AllCost(y) = AllCost(y) + Cost.Colonoscopy_Polyp; */
  } else {
    factor = 1.5;
    moneyspent = Cost->Colonoscopy_Polyp;
    PaymentType->ColonoscopyPolyp[((int32_T)y - 1) << 2]++;
  }

  /* %%% Complications */
  if (b_rand() < risc.Colonoscopy_RiscPerforation * factor) {
    /*  a perforation happend */
    moneyspent += Cost->Colonoscopy_Perforation;
    PaymentType->Perforation[((int32_T)y - 1) << 2]++;
    if (b_rand() < risc.DeathPerforation) {
      /*  patient died during colonoscopy from a perforation */
      Included[(int32_T)z - 1] = false;
      DeathCause[(int32_T)z - 1] = 3.0;
      DeathYear[(int32_T)z - 1] = y;

      /*  we add the costs */
      st.site = &sc_emlrtRSI;
      AddCosts(SD, &st, Detected->Cancer, Detected->CancerYear,
               CostStage->Initial, CostStage->Cont, CostStage->FutInitial,
               CostStage->FutCont, PaymentType, Money, y + (q - 1.0) / 4.0, z);
    }
  } else if (b_rand() < risc.Colonoscopy_RiscSerosaBurn * factor) {
    /*  serosal burn */
    moneyspent += Cost->Colonoscopy_Serosal_burn;
    PaymentType->Serosa[((int32_T)y - 1) << 2]++;
  } else if (b_rand() < risc.Colonoscopy_RiscBleeding * factor) {
    /*  a bleeding episode (no transfusion) */
    moneyspent += Cost->Colonoscopy_bleed;
    PaymentType->Bleeding[((int32_T)y - 1) << 2]++;
  } else {
    if (b_rand() < risc.c_Colonoscopy_RiscBleedingTrans * factor) {
      /*  bleeding recquiring transfusion */
      moneyspent += Cost->Colonoscopy_bleed_transfusion;
      PaymentType->BleedingTransf[((int32_T)y - 1) << 2]++;
      if (b_rand() < risc.DeathBleedingTransfusion) {
        /*  patient died during colonoscopy from a bleeding complication */
        Included[(int32_T)z - 1] = false;
        DeathCause[(int32_T)z - 1] = 3.0;
        DeathYear[(int32_T)z - 1] = y;
      }
    }
  }

  /*  Screening */
  Money->Screening[(int32_T)y - 1] += moneyspent;
}

static void display(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "display", true, location);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const char_T u[19])
{
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 19 };

  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateCharArray(2, iv0);
  emlrtInitCharArrayR2013a(sp, 19, m0, &u[0]);
  emlrtAssign(&y, m0);
  return y;
}

void NumberCrunching_50000(NumberCrunching_50000StackData *SD, const emlrtStack *
  sp, real_T p, const struct0_T *StageVariables, const struct1_T *Location,
  const struct2_T *Cost, const struct3_T *CostStage, const struct4_T *risc,
  const struct5_T *flag, const char_T SpecialText[25], const struct6_T *female,
  const real_T Sensitivity[70], const real_T ScreeningTest[56], real_T
  ScreeningPreference[50000], const real_T AgeProgression[900], const real_T
  NewPolyp[150], const real_T ColonoscopyLikelyhood[150], const real_T
  IndividualRisk[50000], const struct7_T *RiskDistribution, const real_T Gender
  [50000], const real_T LifeTable[302], const real_T MortalityMatrix[400000],
  real_T LocationMatrix[2000], const real_T StageDuration[16], const real_T tx1
  [100], const real_T DirectCancerRate[300], real_T DirectCancerSpeed, const
  char_T DwellSpeed[4], real_T *y, real_T DeathCause[50000], struct8_T *Last,
  real_T DeathYear[50000], real_T NaturalDeathYear[50000], real_T DirectCancer
  [500], real_T DirectCancerR[100], real_T DirectCancer2[100], real_T
  DirectCancer2R[100], real_T ProgressedCancer[100], real_T ProgressedCancerR
  [100], struct9_T *TumorRecord, real_T DwellTimeProgression[500000], real_T
  DwellTimeFastCancer[500000], real_T HasCancer[5000000], real_T NumPolyps
  [5000000], real_T MaxPolyps[5000000], real_T AllPolyps[600], real_T NumCancer
  [5000000], real_T MaxCancer[5000000], struct10_T *PaymentType, struct11_T
  *Money, struct12_T *Number, real_T EarlyPolypsRemoved[100], real_T
  DiagnosedCancer[5000000], real_T AdvancedPolypsRemoved[100], boolean_T
  YearIncluded[5000000], boolean_T YearAlive[5000000])
{
  boolean_T b1;
  boolean_T Included[50000];
  boolean_T Alive[50000];
  int32_T i4;
  int32_T ii;
  real_T GenderProgression[20];
  real_T LocationProgression[130];
  int32_T f;
  real_T mtmp;
  int32_T loop_ub;
  int8_T TmpLoc[1000];
  real_T RectoSigmoReachMatrix[1000];
  real_T ColoReachMatrix[1000];
  real_T Counter;
  real_T Location_data[13];
  int32_T Polyp[2];
  real_T Ende;
  int32_T i5;
  int32_T i6;
  int32_T tmp_data[2000];
  int8_T StageMatrix[1000];
  real_T SojournMatrix[4000];
  real_T tx3[25];
  int32_T f2;
  real_T tx3_data[25];
  int32_T tx3_size[1];
  int32_T b_tx3_size[1];
  emxArray_real_T *r0;
  emxArray_int32_T *r1;
  int32_T idx;
  int32_T z;
  int32_T q;
  real_T time;
  real_T Detected[50];
  int8_T ii_size[2];
  boolean_T exitg22;
  boolean_T exitg21;
  boolean_T guard15 = false;
  int32_T ii_size_idx_1;
  boolean_T exitg20;
  boolean_T guard14 = false;
  int8_T ii_data[1];
  boolean_T exitg19;
  int8_T pos_data[1];
  int32_T b_tmp_data[1];
  real_T b_mtmp;
  int32_T iv68[2];
  int8_T Polyp_size[2];
  boolean_T exitg18;
  boolean_T guard13 = false;
  real_T x;
  int32_T tmp1;
  real_T b_x;
  real_T b_StageDuration[3];
  boolean_T exitg17;
  boolean_T guard12 = false;
  int32_T i7;
  boolean_T exitg16;
  boolean_T guard11 = false;
  int32_T i8;
  int32_T b_f;
  boolean_T exitg15;
  boolean_T guard10 = false;
  boolean_T exitg14;
  boolean_T guard9 = false;
  int32_T i9;
  int32_T c_tmp_data[51];
  int32_T iv69[2];
  int32_T b_Polyp_size[2];
  real_T Polyp_data[51];
  int32_T iv70[2];
  int32_T c_Polyp_size[2];
  int32_T iv71[2];
  int32_T d_Polyp_size[2];
  int32_T iv72[2];
  int32_T e_Polyp_size[2];
  int32_T iv73[2];
  int32_T f_Polyp_size[2];
  boolean_T exitg13;
  boolean_T guard8 = false;
  boolean_T exitg12;
  boolean_T guard7 = false;
  int32_T i10;
  int32_T iv74[2];
  int32_T g_Polyp_size[2];
  int32_T iv75[2];
  int32_T h_Polyp_size[2];
  int32_T iv76[2];
  int32_T i_Polyp_size[2];
  int32_T iv77[2];
  int32_T j_Polyp_size[2];
  int32_T iv78[2];
  int32_T k_Polyp_size[2];
  boolean_T exitg11;
  boolean_T guard6 = false;
  int32_T i11;
  int32_T iv79[2];
  int32_T l_Polyp_size[2];
  int32_T iv80[2];
  int32_T m_Polyp_size[2];
  int32_T iv81[2];
  int32_T n_Polyp_size[2];
  int32_T iv82[2];
  int32_T o_Polyp_size[2];
  int32_T iv83[2];
  int32_T p_Polyp_size[2];
  boolean_T exitg10;
  boolean_T guard5 = false;
  boolean_T exitg9;
  boolean_T exitg8;
  boolean_T guard4 = false;
  int32_T SurveillanceFlag;
  real_T preference;
  real_T CancerFlag;
  real_T AdvPolypFlag;
  real_T PolypFlag;
  real_T Limit;
  boolean_T exitg7;
  boolean_T exitg6;
  boolean_T exitg5;
  boolean_T exitg4;
  boolean_T guard3 = false;
  boolean_T c_x[51];
  boolean_T exitg3;
  boolean_T guard2 = false;
  int32_T i12;
  boolean_T exitg2;
  boolean_T exitg1;
  boolean_T guard1 = false;
  static const char_T cv2[19] = { 'C', 'a', 'l', 'c', 'u', 'l', 'a', 't', 'i',
    'n', 'g', ' ', 'y', 'e', 'a', 'r', ' ', '%', 'd' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  (void)p;
  (void)SpecialText;
  (void)ColonoscopyLikelyhood;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  b1 = false;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*       */
  /*      CMOST: Colon Modeling with Open Source Tool */
  /*      created by Meher Prakash and Benjamin Misselwitz 2012 - 2016 */
  /*  */
  /*      This program is part of free software package CMOST for colo-rectal   */
  /*      cancer simulations: You can redistribute it and/or modify  */
  /*      it under the terms of the GNU General Public License as published by */
  /*      the Free Software Foundation, either version 3 of the License, or */
  /*      (at your option) any later version. */
  /*   */
  /*         */
  /*      This program is distributed in the hope that it will be useful, */
  /*      but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*      GNU General Public License for more details. */
  /*   */
  /*      You should have received a copy of the GNU General Public License */
  /*      along with this program.  If not, see <http://www.gnu.org/licenses/>. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  to do: */
  /*  write subfunction for adjustment of costs if patient died, to be included */
  /*  for colonoscopy and rectosigmoidoscopy */
  /*  INITIALIZE */
  /*  initially all patients are included */
  /*  initially all patients are alive */
  for (i4 = 0; i4 < 50000; i4++) {
    Included[i4] = true;
    Alive[i4] = true;
    DeathCause[i4] = 0.0;
    DeathYear[i4] = 0.0;
    NaturalDeathYear[i4] = 0.0;
  }

  memset(&DirectCancer[0], 0, 500U * sizeof(real_T));
  for (i4 = 0; i4 < 100; i4++) {
    DirectCancerR[i4] = 0.0;
    DirectCancer2[i4] = 0.0;
    DirectCancer2R[i4] = 0.0;
    ProgressedCancer[i4] = 0.0;
    ProgressedCancerR[i4] = 0.0;
  }

  /*  RS ONLY !!!!!! */
  /*  these we won't summarize in the same variable since they are recorded */
  /*  while the tumor progresses, the TumorRecord variable while detected. */
  for (i4 = 0; i4 < 500000; i4++) {
    TumorRecord->Stage[i4] = 0.0;
    TumorRecord->Location[i4] = 0.0;
    TumorRecord->Sojourn[i4] = 0.0;
    TumorRecord->DwellTime[i4] = 0.0;
    TumorRecord->Gender[i4] = 0.0;
    TumorRecord->Detection[i4] = 0.0;
    TumorRecord->PatientNumber[i4] = 0.0;
    DwellTimeProgression[i4] = 0.0;
    DwellTimeFastCancer[i4] = 0.0;
  }

  /*  RS ONLY !!!!!! */
  /*  RS ONLY !!!!!! */
  /*  RS ONLY !!!!!! */
  for (i4 = 0; i4 < 50000; i4++) {
    Last->Colonoscopy[i4] = 0.0;
    Last->Polyp[i4] = -100.0;
    Last->AdvPolyp[i4] = -100.0;
    Last->Cancer[i4] = -100.0;
    Last->ScreenTest[i4] = 0.0;
    Last->Included[i4] = 0.0;
    Last->TestDone[i4] = 0.0;
    Last->TestYear[i4] = 0.0;
    Last->TestYear2[i4] = 0.0;
  }

  /*  RS ONLY !!!!!! */
  /*  we initialize the polyps cells */
  /*  we initialize the field for keeping track of years */
  for (i4 = 0; i4 < 2550000; i4++) {
    SD->f2.Polyp.Polyps[i4] = 0.0;
    SD->f2.Polyp.PolypYear[i4] = 0.0;
    SD->f2.Polyp.PolypLocation[i4] = 0.0;
    SD->f2.Polyp.AdvProgression[i4] = 0.0;
    SD->f2.Polyp.EarlyProgression[i4] = 0.0;
  }

  /*  we initialize the cancer cells */
  /*  we initialize the field for keeping track of years */
  for (i4 = 0; i4 < 1250000; i4++) {
    SD->f2.Ca.Cancer[i4] = 0.0;
    SD->f2.Ca.CancerYear[i4] = 0.0;
    SD->f2.Ca.CancerLocation[i4] = 0.0;
    SD->f2.Ca.TimeStage_I[i4] = 0.0;
    SD->f2.Ca.TimeStage_II[i4] = 0.0;
    SD->f2.Ca.TimeStage_III[i4] = 0.0;
    SD->f2.Ca.SympTime[i4] = 0.0;
    SD->f2.Ca.SympStage[i4] = 0.0;
    SD->f2.Ca.DwellTime[i4] = 0.0;
  }

  /*  consider increasing this to  */
  /*  this cancers are detected, patient might die */
  /*  year this cancer had beed diagnosed */
  for (i4 = 0; i4 < 2500000; i4++) {
    SD->f2.Detected.Cancer[i4] = 0.0;
    SD->f2.Detected.CancerYear[i4] = 0.0;
    SD->f2.Detected.CancerLocation[i4] = 0.0;
    SD->f2.Detected.MortTime[i4] = 0.0;
  }

  for (i4 = 0; i4 < 5000000; i4++) {
    HasCancer[i4] = 0.0;
    NumPolyps[i4] = 0.0;
    MaxPolyps[i4] = 0.0;
  }

  /*  MaxPolypsRight  = zeros(100, 50000); */
  /*  MaxPolypsRectum = zeros(100, 50000); */
  /*  MaxPolypsRest   = zeros(100, 50000); */
  memset(&AllPolyps[0], 0, 600U * sizeof(real_T));
  for (i4 = 0; i4 < 5000000; i4++) {
    DiagnosedCancer[i4] = 0.0;
    NumCancer[i4] = 0.0;
    MaxCancer[i4] = 0.0;
  }

  for (ii = 0; ii < 100; ii++) {
    Money->AllCost[ii] = 0.0;
    Money->AllCostFuture[ii] = 0.0;
    Money->Treatment[ii] = 0.0;
    Money->FutureTreatment[ii] = 0.0;
    Money->Screening[ii] = 0.0;
    Money->FollowUp[ii] = 0.0;
    Money->Other[ii] = 0.0;
    Number->Screening_Colonoscopy[ii] = 0.0;
    Number->Symptoms_Colonoscopy[ii] = 0.0;
    Number->Follow_Up_Colonoscopy[ii] = 0.0;
    Number->Baseline_Colonoscopy[ii] = 0.0;
    Number->RectoSigmo[ii] = 0.0;
    Number->FOBT[ii] = 0.0;
    Number->I_FOBT[ii] = 0.0;
    Number->Sept9[ii] = 0.0;
    Number->other[ii] = 0.0;
    EarlyPolypsRemoved[ii] = 0.0;
    AdvancedPolypsRemoved[ii] = 0.0;
  }

  for (i4 = 0; i4 < 5000000; i4++) {
    YearIncluded[i4] = false;
    YearAlive[i4] = false;
  }

  /*  Colo_Detection_bckup = StageVariables.Colo_Detection; */
  /* m2  */
  /* m2 Number for each cost type */
  /*  4 types, Type 1: For screening, Type 2: treatment; Type 3: Followup; Type */
  /*  4: Other */
  /* m2 Purely screening */
  for (i4 = 0; i4 < 100; i4++) {
    PaymentType->FOBT[i4] = 0.0;
    PaymentType->I_FOBT[i4] = 0.0;
    PaymentType->Sept9_HighSens[i4] = 0.0;
    PaymentType->Sept9_HighSpec[i4] = 0.0;
    PaymentType->RS[i4] = 0.0;
    PaymentType->RSPolyp[i4] = 0.0;
  }

  /* m2 Colonoscopy can be for screening, treatment, followup,   */
  /* m2 Complications at anytime screening, treatment or followup */
  for (i4 = 0; i4 < 400; i4++) {
    PaymentType->Colonoscopy[i4] = 0.0;
    PaymentType->ColonoscopyPolyp[i4] = 0.0;
    PaymentType->Colonoscopy_Cancer[i4] = 0.0;
    PaymentType->Perforation[i4] = 0.0;
    PaymentType->Serosa[i4] = 0.0;
    PaymentType->Bleeding[i4] = 0.0;
    PaymentType->BleedingTransf[i4] = 0.0;
  }

  /* m2 cancer treatment costs index is for stage */
  for (i4 = 0; i4 < 404; i4++) {
    PaymentType->Cancer_ini[i4] = 0.0;
    PaymentType->Cancer_con[i4] = 0.0;
    PaymentType->Cancer_fin[i4] = 0.0;
  }

  /* m2 cancer treatment costs index is for stage, noted by quarters */
  for (i4 = 0; i4 < 1616; i4++) {
    PaymentType->QCancer_ini[i4] = 0.0;
  }

  for (i4 = 0; i4 < 8080; i4++) {
    PaymentType->QCancer_con[i4] = 0.0;
  }

  for (i4 = 0; i4 < 1616; i4++) {
    PaymentType->QCancer_fin[i4] = 0.0;
  }

  for (i4 = 0; i4 < 100; i4++) {
    PaymentType->Other[i4] = 0.0;
  }

  /*  matrix for fast indexing */
  for (i4 = 0; i4 < 20; i4++) {
    GenderProgression[i4] = 1.0;
  }

  for (i4 = 0; i4 < 4; i4++) {
    GenderProgression[10 + i4] = female->early_progression_female;
  }

  for (i4 = 0; i4 < 2; i4++) {
    GenderProgression[i4 + 14] = female->advanced_progression_female;
  }

  /*  matrix for fast indexing */
  /*  10 polyps x 13 locations */
  /* LocationProgression(5, :)= Location.AdvancedProgression; */
  for (i4 = 0; i4 < 13; i4++) {
    LocationProgression[10 * i4] = Location->EarlyProgression[i4];
    LocationProgression[1 + 10 * i4] = Location->EarlyProgression[i4];
    LocationProgression[2 + 10 * i4] = Location->EarlyProgression[i4];
    LocationProgression[3 + 10 * i4] = Location->EarlyProgression[i4];
    LocationProgression[4 + 10 * i4] = Location->EarlyProgression[i4];
    LocationProgression[5 + 10 * i4] = Location->AdvancedProgression[i4];
    LocationProgression[6 + 10 * i4] = Location->CancerProgression[i4];
    LocationProgression[7 + 10 * i4] = Location->CancerProgression[i4];
    LocationProgression[8 + 10 * i4] = Location->CancerProgression[i4];
    LocationProgression[9 + 10 * i4] = Location->CancerProgression[i4];
  }

  /*  reach of rectosigmoidoscopy */
  memset(&SD->f2.TmpLoc[0], 0, 13000U * sizeof(real_T));
  f = 0;
  while (f < 13) {
    mtmp = muDoubleScalarRound(1000.0 * Location->RectoSigmoReach[f]);
    if (1.0 > mtmp) {
      loop_ub = 0;
    } else {
      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
        emlrtIntegerCheckR2012b(mtmp, &x_emlrtDCI, sp);
      }

      loop_ub = (int32_T)mtmp;
      if (!((loop_ub >= 1) && (loop_ub <= 1000))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 1000, &bc_emlrtBCI, sp);
      }
    }

    for (i4 = 0; i4 < loop_ub; i4++) {
      SD->f2.TmpLoc[f + 13 * i4] = 1.0;
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  f = 0;
  while (f < 12) {
    for (i4 = 0; i4 < 1000; i4++) {
      TmpLoc[i4] = (int8_T)((SD->f2.TmpLoc[(f + 13 * i4) + 1] != 0.0) ||
                            (SD->f2.TmpLoc[f + 13 * i4] != 0.0));
    }

    for (i4 = 0; i4 < 1000; i4++) {
      SD->f2.TmpLoc[(f + 13 * i4) + 1] = TmpLoc[i4];
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  sum(SD->f2.TmpLoc, RectoSigmoReachMatrix);
  for (i4 = 0; i4 < 1000; i4++) {
    RectoSigmoReachMatrix[i4] = -RectoSigmoReachMatrix[i4] + 14.0;
  }

  /*  reach of colonoscopy */
  memset(&SD->f2.TmpLoc[0], 0, 13000U * sizeof(real_T));
  f = 0;
  while (f < 13) {
    mtmp = muDoubleScalarRound(1000.0 * Location->ColoReach[f]);
    if (1.0 > mtmp) {
      loop_ub = 0;
    } else {
      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
        emlrtIntegerCheckR2012b(mtmp, &w_emlrtDCI, sp);
      }

      loop_ub = (int32_T)mtmp;
      if (!((loop_ub >= 1) && (loop_ub <= 1000))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 1000, &ac_emlrtBCI, sp);
      }
    }

    for (i4 = 0; i4 < loop_ub; i4++) {
      SD->f2.TmpLoc[f + 13 * i4] = 1.0;
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  f = 0;
  while (f < 12) {
    for (i4 = 0; i4 < 1000; i4++) {
      TmpLoc[i4] = (int8_T)((SD->f2.TmpLoc[(f + 13 * i4) + 1] != 0.0) ||
                            (SD->f2.TmpLoc[f + 13 * i4] != 0.0));
    }

    for (i4 = 0; i4 < 1000; i4++) {
      SD->f2.TmpLoc[(f + 13 * i4) + 1] = TmpLoc[i4];
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  sum(SD->f2.TmpLoc, ColoReachMatrix);
  for (i4 = 0; i4 < 1000; i4++) {
    ColoReachMatrix[i4] = -ColoReachMatrix[i4] + 14.0;
  }

  Counter = 1.0;
  f = 0;
  while (f < 13) {
    Polyp[0] = 1;
    Polyp[1] = f + 1;
    for (i4 = 0; i4 <= f; i4++) {
      Location_data[i4] = Location->NewPolyp[i4];
    }

    st.site = &ic_emlrtRSI;
    mtmp = b_sum(&st, Location_data, Polyp);
    Ende = muDoubleScalarRound(mtmp / c_sum(Location->NewPolyp) * 1000.0);
    if (Counter > Ende) {
      i4 = 0;
      i5 = 0;
    } else {
      if (Counter != (int32_T)muDoubleScalarFloor(Counter)) {
        emlrtIntegerCheckR2012b(Counter, &v_emlrtDCI, sp);
      }

      i4 = (int32_T)Counter;
      if (!((i4 >= 1) && (i4 <= 2000))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 2000, &yb_emlrtBCI, sp);
      }

      i4--;
      if (Ende != (int32_T)muDoubleScalarFloor(Ende)) {
        emlrtIntegerCheckR2012b(Ende, &v_emlrtDCI, sp);
      }

      i5 = (int32_T)Ende;
      if (!((i5 >= 1) && (i5 <= 2000))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, 2000, &yb_emlrtBCI, sp);
      }
    }

    loop_ub = i5 - i4;
    for (i6 = 0; i6 < loop_ub; i6++) {
      tmp_data[i6] = i4 + i6;
    }

    loop_ub = i5 - i4;
    for (i4 = 0; i4 < loop_ub; i4++) {
      LocationMatrix[tmp_data[i4]] = 1.0 + (real_T)f;
    }

    Counter = Ende;
    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  Cancer progression */
  /*  Stage 1: 5%, Stage 2: 35%, Stage 3: 40%, Stage 4: 20%. */
  memset(&StageMatrix[0], 0, 1000U * sizeof(int8_T));
  memset(&StageMatrix[0], 7, 150U * sizeof(int8_T));
  memset(&StageMatrix[150], 8, 356U * sizeof(int8_T));
  memset(&StageMatrix[506], 9, 279U * sizeof(int8_T));
  memset(&StageMatrix[785], 10, 215U * sizeof(int8_T));
  memset(&SojournMatrix[0], 0, 4000U * sizeof(real_T));
  f = 0;
  while (f < 4) {
    mtmp = d_sum(*(real_T (*)[25])&tx1[25 * f]);
    for (i4 = 0; i4 < 25; i4++) {
      tx3[i4] = tx1[i4 + 25 * f] / mtmp * 10.0 * 1000.0;
    }

    b_round(tx3);
    Counter = 1.0;
    f2 = 0;
    while (f2 < 25) {
      if (!isequal(muDoubleScalarRound(tx3[f2] / 10.0), 0.0)) {
        tx3_size[0] = f2 + 1;
        for (i4 = 0; i4 <= f2; i4++) {
          tx3_data[i4] = tx3[i4];
        }

        st.site = &ub_emlrtRSI;
        mtmp = e_sum(tx3_data, tx3_size);
        mtmp = muDoubleScalarRound(mtmp / 10.0);
        if (Counter > mtmp) {
          i4 = 0;
          i5 = 0;
        } else {
          if (Counter != (int32_T)muDoubleScalarFloor(Counter)) {
            emlrtIntegerCheckR2012b(Counter, &t_emlrtDCI, sp);
          }

          i4 = (int32_T)Counter;
          if (!((i4 >= 1) && (i4 <= 1000))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &sb_emlrtBCI, sp);
          }

          i4--;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &t_emlrtDCI, sp);
          }

          i5 = (int32_T)mtmp;
          if (!((i5 >= 1) && (i5 <= 1000))) {
            emlrtDynamicBoundsCheckR2012b(i5, 1, 1000, &sb_emlrtBCI, sp);
          }
        }

        loop_ub = i5 - i4;
        for (i5 = 0; i5 < loop_ub; i5++) {
          SojournMatrix[(i4 + i5) + 1000 * f] = 0.25 + 0.25 * (real_T)f2;
        }

        b_tx3_size[0] = f2 + 1;
        for (i4 = 0; i4 <= f2; i4++) {
          tx3_data[i4] = tx3[i4];
        }

        st.site = &hc_emlrtRSI;
        mtmp = e_sum(tx3_data, b_tx3_size);
        Counter = muDoubleScalarRound(mtmp / 10.0);
        if (isequal(1.0 + (real_T)f2, 25.0) && (!isequal(Counter, 1000.0))) {
          if (Counter > 1000.0) {
            i4 = 0;
            i5 = 0;
          } else {
            if (Counter != (int32_T)muDoubleScalarFloor(Counter)) {
              emlrtIntegerCheckR2012b(Counter, &s_emlrtDCI, sp);
            }

            i4 = (int32_T)Counter;
            if (!((i4 >= 1) && (i4 <= 1000))) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &rb_emlrtBCI, sp);
            }

            i4--;
            i5 = 1000;
          }

          loop_ub = i5 - i4;
          for (i5 = 0; i5 < loop_ub; i5++) {
            SojournMatrix[(i4 + i5) + 1000 * f] = 0.25 + 0.25 * (real_T)f2;
          }
        }
      }

      f2++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  *y = 0.0;

  /*  year */
  emxInit_real_T(sp, &r0, 2, &emlrtRTEI, true);
  emxInit_int32_T(sp, &r1, 2, &emlrtRTEI, true);
  while ((f_sum(Included) > 0.0) && (*y < 100.0)) {
    (*y)++;

    /*      if y==2 */
    /*           save variables_3_10_2013.mat */
    /*      end */
    /*  for speed we make this calculation in advance */
    /*  we need to check, whether this works */
    /*  the individual risc */
    /*  the age specific risc */
    for (i4 = 0; i4 < 50000; i4++) {
      SD->f2.PolypRate[i4] = IndividualRisk[i4] * NewPolyp[(int32_T)*y - 1];
    }

    /*  the gender specific risc */
    idx = 0;
    for (ii = 0; ii < 50000; ii++) {
      if (Gender[ii] == 2.0) {
        idx++;
      }
    }

    i4 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = idx;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i4, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    idx = 0;
    for (ii = 0; ii < 50000; ii++) {
      if (Gender[ii] == 2.0) {
        r1->data[idx] = ii + 1;
        idx++;
      }
    }

    i4 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    r0->size[1] = r1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r0, i4, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = r1->size[0] * r1->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      r0->data[i4] = SD->f2.PolypRate[r1->data[i4] - 1] *
        female->new_polyp_female;
    }

    idx = 0;
    for (ii = 0; ii < 50000; ii++) {
      if (Gender[ii] == 2.0) {
        idx++;
      }
    }

    i4 = r0->size[1];
    if (idx != i4) {
      emlrtSizeEqCheck1DR2012b(idx, i4, &q_emlrtECI, sp);
    }

    idx = 0;
    for (ii = 0; ii < 50000; ii++) {
      if (Gender[ii] == 2.0) {
        SD->f2.PolypRate[ii] = r0->data[idx];
        idx++;
      }
    }

    z = 0;
    while (z < 50000) {
      q = 0;
      while (q < 4) {
        time = *y + ((1.0 + (real_T)q) - 1.0) / 4.0;

        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /*   people die of natural causes     % */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /*      try */
        if (Alive[z]) {
          /*  divided by 4 since this is a quarterly calculation */
          mtmp = Gender[z];
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &u_emlrtDCI, sp);
          }

          i4 = (int32_T)mtmp;
          if (!((i4 >= 1) && (i4 <= 2))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 2, &xb_emlrtBCI, sp);
          }

          st.site = &gc_emlrtRSI;
          if (b_rand() < LifeTable[((int32_T)*y + 151 * ((int32_T)Gender[z] - 1))
              - 1] / 4.0) {
            Alive[z] = false;
            NaturalDeathYear[z] = time;

            /*  in these cases the patient was really alive */
            if (Included[z]) {
              Included[z] = false;
              DeathCause[z] = 1.0;
              DeathYear[z] = time;

              /*  we need to calculate the costs */
              for (i4 = 0; i4 < 50; i4++) {
                Detected[i4] = SD->f2.Detected.Cancer[z + 50000 * i4];
              }

              if (g_sum(Detected) > 0.0) {
                st.site = &fc_emlrtRSI;
                AddCosts(SD, &st, SD->f2.Detected.Cancer,
                         SD->f2.Detected.CancerYear, CostStage->Initial,
                         CostStage->Cont, CostStage->FutInitial,
                         CostStage->FutCont, PaymentType, Money, time, 1.0 +
                         (real_T)z);
              }
            }
          }
        }

        /*              catch exception */
        /*                  rethrow (exception) */
        /*              end */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /*     people die of cancer           % */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /*          try */
        if (Included[z]) {
          idx = 0;
          for (i4 = 0; i4 < 2; i4++) {
            ii_size[i4] = 1;
          }

          ii = 1;
          exitg22 = false;
          while ((!exitg22) && (ii < 51)) {
            if (SD->f2.Detected.Cancer[z + 50000 * (ii - 1)] != 0.0) {
              idx = 1;
              exitg22 = true;
            } else {
              ii++;
            }
          }

          if (idx == 0) {
            ii_size[1] = 0;
          }

          if (!(ii_size[1] == 0)) {
            idx = 0;
            ii = 1;
            exitg21 = false;
            while ((!exitg21) && (ii < 51)) {
              guard15 = false;
              if (SD->f2.Detected.Cancer[z + 50000 * (ii - 1)] != 0.0) {
                idx++;
                if (idx >= 50) {
                  exitg21 = true;
                } else {
                  guard15 = true;
                }
              } else {
                guard15 = true;
              }

              if (guard15) {
                ii++;
              }
            }

            if (1 > idx) {
              ii_size_idx_1 = 0;
            } else {
              ii_size_idx_1 = idx;
            }

            f = 0;
            exitg20 = false;
            while ((!exitg20) && (f <= ii_size_idx_1 - 1)) {
              guard14 = false;
              if (SD->f2.Detected.MortTime[z + 50000 * f] < 21.0) {
                if (time - SD->f2.Detected.CancerYear[z + 50000 * f] >=
                    SD->f2.Detected.MortTime[z + 50000 * f] / 4.0) {
                  /*  patient died of cancer */
                  Included[z] = false;
                  DeathCause[z] = 2.0;
                  DeathYear[z] = time;

                  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
                  /*  we need to calculate the costs  % */
                  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
                  st.site = &ec_emlrtRSI;
                  b_AddCosts(SD, &st, SD->f2.Detected.Cancer,
                             SD->f2.Detected.CancerYear, CostStage->Initial,
                             CostStage->Cont, CostStage->Final,
                             CostStage->FutInitial, CostStage->FutCont,
                             CostStage->FutFinal, PaymentType, Money, time, 1.0
                             + (real_T)z);
                  i4 = (int32_T)(SD->f2.Detected.Cancer[z + 50000 * f] - 6.0);
                  if (!((i4 >= 1) && (i4 <= 4))) {
                    emlrtDynamicBoundsCheckR2012b(i4, 1, 4, &vb_emlrtBCI, sp);
                  }

                  i4 = (int32_T)(SD->f2.Detected.Cancer[z + 50000 * f] - 6.0);
                  if (!((i4 >= 1) && (i4 <= 4))) {
                    emlrtDynamicBoundsCheckR2012b(i4, 1, 4, &wb_emlrtBCI, sp);
                  }

                  /*  we leave the loop */
                  exitg20 = true;
                } else {
                  guard14 = true;
                }
              } else {
                if (time - SD->f2.Detected.CancerYear[z + 50000 * f] == 5.25) {
                  i4 = (int32_T)(SD->f2.Detected.Cancer[z + 50000 * f] - 6.0);
                  if (!((i4 >= 1) && (i4 <= 4))) {
                    emlrtDynamicBoundsCheckR2012b(i4, 1, 4, &tb_emlrtBCI, sp);
                  }

                  i4 = (int32_T)(SD->f2.Detected.Cancer[z + 50000 * f] - 6.0);
                  if (!((i4 >= 1) && (i4 <= 4))) {
                    emlrtDynamicBoundsCheckR2012b(i4, 1, 4, &ub_emlrtBCI, sp);
                  }
                }

                guard14 = true;
              }

              if (guard14) {
                f++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(sp);
                }
              }
            }
          }
        }

        /*              catch exception */
        /*                  rethrow (exception) */
        /*              end */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /*  a NEW POLYP appears               % */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        if (Included[z]) {
          /*  only in the first quarter */
          /*     try */
          /*  a new polyp appears */
          st.site = &dc_emlrtRSI;
          if (b_rand() < SD->f2.PolypRate[z]) {
            if (SD->f2.Polyp.Polyps[z] > 0.0) {
              idx = 0;
              for (i4 = 0; i4 < 2; i4++) {
                ii_size[i4] = 1;
              }

              ii = 51;
              exitg19 = false;
              while ((!exitg19) && (ii > 0)) {
                if (SD->f2.Polyp.Polyps[z + 50000 * (ii - 1)] != 0.0) {
                  idx = 1;
                  ii_data[0] = (int8_T)ii;
                  exitg19 = true;
                } else {
                  ii--;
                }
              }

              if (idx == 0) {
                ii_size[1] = 0;
              }

              idx = ii_size[1];
              loop_ub = ii_size[1];
              for (i4 = 0; i4 < loop_ub; i4++) {
                pos_data[i4] = (int8_T)(ii_data[i4] + 1);
              }
            } else {
              idx = 1;
              pos_data[0] = 1;
            }

            st.site = &cc_emlrtRSI;
            b_st.site = &kc_emlrtRSI;
            c_st.site = &lc_emlrtRSI;
            if (idx > 0) {
            } else {
              emlrtErrorWithMessageIdR2012b(&c_st, &f_emlrtRTEI,
                "Coder:toolbox:eml_min_or_max_varDimZero", 0);
            }

            if (pos_data[0] < 50) {
              /*  number polyps limited to 50 */
              for (i4 = 0; i4 < idx; i4++) {
                i5 = pos_data[i4];
                if (!((i5 >= 1) && (i5 <= 51))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 51, &cc_emlrtBCI, sp);
                }

                b_tmp_data[i4] = i5;
              }

              for (i4 = 0; i4 < 1; i4++) {
                SD->f2.Polyp.Polyps[z + 50000 * (b_tmp_data[0] - 1)] = 1.0;
              }

              for (i4 = 0; i4 < idx; i4++) {
                b_tmp_data[i4] = pos_data[i4];
              }

              for (i4 = 0; i4 < 1; i4++) {
                SD->f2.Polyp.PolypYear[z + 50000 * (b_tmp_data[0] - 1)] = time;
              }

              for (i4 = 0; i4 < idx; i4++) {
                b_tmp_data[i4] = pos_data[i4];
              }

              st.site = &bc_emlrtRSI;
              b_mtmp = b_rand() * 999.0;
              b_mtmp = muDoubleScalarRound(b_mtmp);
              for (i4 = 0; i4 < 1; i4++) {
                if (b_mtmp + 1.0 != (int32_T)muDoubleScalarFloor(b_mtmp + 1.0))
                {
                  emlrtIntegerCheckR2012b(b_mtmp + 1.0, &y_emlrtDCI, sp);
                }

                i5 = (int32_T)(b_mtmp + 1.0);
                if (!((i5 >= 1) && (i5 <= 1000))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 1000, &dc_emlrtBCI, sp);
                }

                SD->f2.Polyp.PolypLocation[z + 50000 * (b_tmp_data[0] - 1)] =
                  LocationMatrix[(i5 - 1) << 1];
              }

              /*  we just save the percentile of the risk, not the */
              /*  absolute risk */
              for (i4 = 0; i4 < idx; i4++) {
                b_tmp_data[i4] = pos_data[i4];
              }

              st.site = &ac_emlrtRSI;
              b_mtmp = b_rand() * 499.0;
              b_mtmp = muDoubleScalarRound(b_mtmp);
              for (i4 = 0; i4 < 1; i4++) {
                SD->f2.Polyp.EarlyProgression[z + 50000 * (b_tmp_data[0] - 1)] =
                  b_mtmp + 1.0;
              }

              /*  if correlation applies, both percentiles are */
              /*  identical */
              if (flag->Correlation) {
                for (i4 = 0; i4 < idx; i4++) {
                  b_tmp_data[i4] = pos_data[i4] - 1;
                }

                if (!b1) {
                  iv68[0] = 1;
                  iv68[1] = 1;
                  b1 = true;
                }

                Polyp_size[0] = 1;
                Polyp_size[1] = (int8_T)idx;
                for (i4 = 0; i4 < 2; i4++) {
                  Polyp[i4] = Polyp_size[i4];
                }

                emlrtSubAssignSizeCheckR2012b(iv68, 2, Polyp, 2, &p_emlrtECI, sp);
                for (i4 = 0; i4 < idx; i4++) {
                  SD->f2.Polyp.AdvProgression[z + 50000 * b_tmp_data[i4]] =
                    SD->f2.Polyp.EarlyProgression[z + 50000 * (pos_data[i4] - 1)];
                }
              } else {
                for (i4 = 0; i4 < idx; i4++) {
                  b_tmp_data[i4] = pos_data[i4];
                }

                st.site = &yb_emlrtRSI;
                b_mtmp = b_rand() * 499.0;
                b_mtmp = muDoubleScalarRound(b_mtmp);
                for (i4 = 0; i4 < 1; i4++) {
                  SD->f2.Polyp.AdvProgression[z + 50000 * (b_tmp_data[0] - 1)] =
                    b_mtmp + 1.0;
                }
              }
            }
          }

          /*                  catch exception */
          /*                      rethrow(exception) */
          /*                  end */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*  a NEW Cancer appears DIRECTLY     % */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          mtmp = Gender[z];
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &ab_emlrtDCI, sp);
          }

          i4 = (int32_T)mtmp;
          if (!((i4 >= 1) && (i4 <= 2))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 2, &ec_emlrtBCI, sp);
          }

          st.site = &xb_emlrtRSI;
          if (b_rand() < DirectCancerRate[(i4 + (((int32_T)*y - 1) << 1)) - 1] *
              DirectCancerSpeed) {
            /*  this is cancer now. we need to write */
            /*  everything into the cancer variable */
            idx = 0;
            ii = 1;
            exitg18 = false;
            while ((!exitg18) && (ii < 26)) {
              guard13 = false;
              if (SD->f2.Ca.Cancer[z + 50000 * (ii - 1)] != 0.0) {
                idx++;
                if (idx >= 25) {
                  exitg18 = true;
                } else {
                  guard13 = true;
                }
              } else {
                guard13 = true;
              }

              if (guard13) {
                ii++;
              }
            }

            if (1 > idx) {
              ii_size_idx_1 = 0;
            } else {
              ii_size_idx_1 = idx;
            }

            if (ii_size_idx_1 + 1 < 25) {
              SD->f2.Ca.Cancer[z + 50000 * ii_size_idx_1] = 7.0;
              SD->f2.Ca.CancerYear[z + 50000 * ii_size_idx_1] = time;
              st.site = &wb_emlrtRSI;
              b_mtmp = b_rand() * 999.0;
              mtmp = muDoubleScalarRound(b_mtmp) + 1.0;
              if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                emlrtIntegerCheckR2012b(mtmp, &bb_emlrtDCI, sp);
              }

              i4 = (int32_T)mtmp;
              if (!((i4 >= 1) && (i4 <= 1000))) {
                emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &fc_emlrtBCI, sp);
              }

              SD->f2.Ca.CancerLocation[z + 50000 * ii_size_idx_1] =
                LocationMatrix[1 + ((i4 - 1) << 1)];
              SD->f2.Ca.DwellTime[z + 50000 * ii_size_idx_1] = 0.0;

              /*  POSSIBLY DELETE LATER */
              /*  a random number for stage and sojourn time */
              st.site = &vb_emlrtRSI;
              b_mtmp = b_rand() * 999.0 + 1.0;
              x = muDoubleScalarRound(b_mtmp);
              mtmp = muDoubleScalarRound(b_mtmp);
              if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                emlrtIntegerCheckR2012b(mtmp, &cb_emlrtDCI, sp);
              }

              i4 = (int32_T)mtmp;
              if (!((i4 >= 1) && (i4 <= 1000))) {
                emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &gc_emlrtBCI, sp);
              }

              tmp1 = StageMatrix[i4 - 1];
              st.site = &tb_emlrtRSI;
              mtmp = b_rand() * 999.0 + 1.0;
              b_x = muDoubleScalarRound(mtmp);
              mtmp = muDoubleScalarRound(mtmp);
              if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                emlrtIntegerCheckR2012b(mtmp, &r_emlrtDCI, sp);
              }

              i4 = (int32_T)mtmp;
              if (!((i4 >= 1) && (i4 <= 1000))) {
                emlrtDynamicBoundsCheckR2012b(i4, 1, 1000, &qb_emlrtBCI, sp);
              }

              i4 = StageMatrix[(int32_T)x - 1] - 6;
              if (!((i4 >= 1) && (i4 <= 4))) {
                emlrtDynamicBoundsCheckR2012b(i4, 1, 4, &pb_emlrtBCI, sp);
              }

              SD->f2.Ca.SympTime[z + 50000 * ii_size_idx_1] = time +
                SojournMatrix[((int32_T)b_x + 1000 * (StageMatrix[(int32_T)
                muDoubleScalarRound(b_mtmp) - 1] - 7)) - 1];
              SD->f2.Ca.SympStage[z + 50000 * ii_size_idx_1] = StageMatrix
                [(int32_T)x - 1];
              if (StageMatrix[(int32_T)x - 1] > 7) {
                SD->f2.Ca.TimeStage_I[z + 50000 * ii_size_idx_1] = time +
                  muDoubleScalarRound(SojournMatrix[((int32_T)b_x + 1000 *
                  (StageMatrix[(int32_T)muDoubleScalarRound(b_mtmp) - 1] - 7)) -
                                      1] * StageDuration[StageMatrix[(int32_T)x
                                      - 1] - 7] * 4.0) / 4.0;
              } else {
                SD->f2.Ca.TimeStage_I[z + 50000 * ii_size_idx_1] = 1000.0;
              }

              if (StageMatrix[(int32_T)x - 1] > 8) {
                SD->f2.Ca.TimeStage_II[z + 50000 * ii_size_idx_1] = time +
                  muDoubleScalarRound(SojournMatrix[((int32_T)b_x + 1000 *
                  (StageMatrix[(int32_T)muDoubleScalarRound(b_mtmp) - 1] - 7)) -
                                      1] * (StageDuration[StageMatrix[(int32_T)x
                  - 1] - 7] + StageDuration[tmp1 - 3]) * 4.0) / 4.0;
              } else {
                SD->f2.Ca.TimeStage_II[z + 50000 * ii_size_idx_1] = 1000.0;
              }

              if (StageMatrix[(int32_T)x - 1] > 9) {
                for (i4 = 0; i4 < 3; i4++) {
                  b_StageDuration[i4] = StageDuration[3 + (i4 << 2)];
                }

                SD->f2.Ca.TimeStage_III[z + 50000 * ii_size_idx_1] = time +
                  muDoubleScalarRound(SojournMatrix[((int32_T)b_x + 1000 *
                  (StageMatrix[(int32_T)muDoubleScalarRound(b_mtmp) - 1] - 7)) -
                                      1] * i_sum(b_StageDuration) * 4.0) / 4.0;
              } else {
                SD->f2.Ca.TimeStage_III[z + 50000 * ii_size_idx_1] = 1000.0;
              }

              /*  we keep track */
              idx = 0;
              ii = 1;
              exitg17 = false;
              while ((!exitg17) && (ii < 5001)) {
                guard12 = false;
                if (DwellTimeProgression[((int32_T)*y + 100 * (ii - 1)) - 1] !=
                    0.0) {
                  idx++;
                  if (idx >= 5000) {
                    exitg17 = true;
                  } else {
                    guard12 = true;
                  }
                } else {
                  guard12 = true;
                }

                if (guard12) {
                  ii++;
                }
              }

              if (1 > idx) {
                i7 = 0;
              } else {
                i7 = idx;
              }

              i4 = i7 + 1;
              if (!((i4 >= 1) && (i4 <= 5000))) {
                emlrtDynamicBoundsCheckR2012b(i4, 1, 5000, &hc_emlrtBCI, sp);
              }

              DwellTimeProgression[((int32_T)*y + 100 * (i4 - 1)) - 1] = 0.0;
              loop_ub = 101 - (int32_T)*y;
              for (i4 = 0; i4 < loop_ub; i4++) {
                HasCancer[(((int32_T)*y + i4) + 100 * z) - 1] = 1.0;
              }

              DirectCancer2[(int32_T)*y - 1]++;
              if (SD->f2.Ca.CancerLocation[z + 50000 * ii_size_idx_1] < 4.0) {
                DirectCancer2R[(int32_T)*y - 1]++;
              }
            }
          }

          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*       a polyp progresses           % */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*       try */
          idx = 0;
          ii = 1;
          exitg16 = false;
          while ((!exitg16) && (ii < 52)) {
            guard11 = false;
            if (SD->f2.Polyp.Polyps[z + 50000 * (ii - 1)] != 0.0) {
              idx++;
              if (idx >= 51) {
                exitg16 = true;
              } else {
                guard11 = true;
              }
            } else {
              guard11 = true;
            }

            if (guard11) {
              ii++;
            }
          }

          if (1 > idx) {
            i4 = 0;
          } else {
            i4 = idx;
          }

          if (1 > idx) {
            i8 = 0;
          } else {
            i8 = idx;
          }

          emlrtForLoopVectorCheckR2012b(i8, -1.0, 1.0, mxDOUBLE_CLASS, i4,
            &e_emlrtRTEI, sp);
          f = 1;
          while (f - 1 <= i4 - 1) {
            b_f = i4 - f;

            /*  % location influence */
            /*  % gender influence */
            i5 = b_f + 1;
            if (!((i5 >= 1) && (i5 <= 51))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, 51, &jb_emlrtBCI, sp);
            }

            mtmp = SD->f2.Polyp.EarlyProgression[z + 50000 * b_f];
            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &o_emlrtDCI, sp);
            }

            i5 = (int32_T)mtmp;
            if (!((i5 >= 1) && (i5 <= 500))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, 500, &ib_emlrtBCI, sp);
            }

            mtmp = SD->f2.Polyp.AdvProgression[z + 50000 * b_f];
            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &n_emlrtDCI, sp);
            }

            i5 = (int32_T)mtmp;
            if (!((i5 >= 1) && (i5 <= 500))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, 500, &hb_emlrtBCI, sp);
            }

            i5 = (int32_T)SD->f2.Polyp.Polyps[z + 50000 * b_f];
            if (!((i5 >= 1) && (i5 <= 6))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, 6, &ob_emlrtBCI, sp);
            }

            i5 = (int32_T)SD->f2.Polyp.Polyps[z + 50000 * b_f];
            if (!((i5 >= 1) && (i5 <= 10))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, 10, &nb_emlrtBCI, sp);
            }

            mtmp = SD->f2.Polyp.PolypLocation[z + 50000 * b_f];
            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &q_emlrtDCI, sp);
            }

            i5 = (int32_T)mtmp;
            if (!((i5 >= 1) && (i5 <= 13))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, 13, &mb_emlrtBCI, sp);
            }

            i5 = (int32_T)SD->f2.Polyp.Polyps[z + 50000 * b_f];
            if (!((i5 >= 1) && (i5 <= 10))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, 10, &lb_emlrtBCI, sp);
            }

            mtmp = Gender[z];
            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &p_emlrtDCI, sp);
            }

            i5 = (int32_T)mtmp;
            if (!((i5 >= 1) && (i5 <= 2))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, 2, &kb_emlrtBCI, sp);
            }

            /*                      switch DwellSpeed  %m2 moved the switch statement up. otherwise without cancer m remains 0 */
            /*                          case 'Slow' */
            /*                              tmp2 = StageVariables.FastCancer(Polyp.Polyps(z, f))... */
            /*                                  * AgeProgression(6, y)... */
            /*                                  * LocationProgression(6, Polyp.PolypLocation(z, f))... */
            /*                                  * GenderProgression(6, Gender(z)); */
            /*                          case 'Fast' */
            /*                              tmp2 = StageVariables.FastCancer(Polyp.Polyps(z, f))... */
            /*                                  * AgeProgression(6, y)... */
            /*                                  * LocationProgression(6, Polyp.PolypLocation(z, f))... */
            /*                                  * GenderProgression(6, Gender(z));        */
            /*                      end */
            st.site = &sb_emlrtRSI;
            if (b_rand() < AgeProgression[((int32_T)SD->f2.Polyp.Polyps[z +
                 50000 * b_f] + 6 * ((int32_T)*y - 1)) - 1] *
                LocationProgression[((int32_T)SD->f2.Polyp.Polyps[z + 50000 *
                 b_f] + 10 * ((int32_T)SD->f2.Polyp.PolypLocation[z + 50000 *
                              b_f] - 1)) - 1] * GenderProgression[((int32_T)
                 SD->f2.Polyp.Polyps[z + 50000 * b_f] + 10 * ((int32_T)Gender[z]
                  - 1)) - 1] * ((real_T)(SD->f2.Polyp.Polyps[z + 50000 * b_f] <
                  5.0) * RiskDistribution->EarlyRisk[(int32_T)
                                SD->f2.Polyp.EarlyProgression[z + 50000 * b_f] -
                                1] + (real_T)(SD->f2.Polyp.Polyps[z + 50000 *
                  b_f] > 4.0) * RiskDistribution->AdvancedRisk[(int32_T)
                                SD->f2.Polyp.AdvProgression[z + 50000 * b_f] - 1]))
            {
              SD->f2.Polyp.Polyps[z + 50000 * b_f]++;
              if (SD->f2.Polyp.Polyps[z + 50000 * b_f] > 6.0) {
                /*  this is cancer now. we need to write */
                /*  everything into the cancer variable */
                idx = 0;
                ii = 1;
                exitg15 = false;
                while ((!exitg15) && (ii < 26)) {
                  guard10 = false;
                  if (SD->f2.Ca.Cancer[z + 50000 * (ii - 1)] != 0.0) {
                    idx++;
                    if (idx >= 25) {
                      exitg15 = true;
                    } else {
                      guard10 = true;
                    }
                  } else {
                    guard10 = true;
                  }

                  if (guard10) {
                    ii++;
                  }
                }

                if (1 > idx) {
                  ii_size_idx_1 = 0;
                } else {
                  ii_size_idx_1 = idx;
                }

                if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
                  emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25,
                    &uc_emlrtBCI, sp);
                }

                SD->f2.Ca.Cancer[z + 50000 * ii_size_idx_1] = 7.0;
                SD->f2.Ca.CancerYear[z + 50000 * ii_size_idx_1] = time;
                SD->f2.Ca.CancerLocation[z + 50000 * ii_size_idx_1] =
                  SD->f2.Polyp.PolypLocation[z + 50000 * b_f];
                SD->f2.Ca.DwellTime[z + 50000 * ii_size_idx_1] = time -
                  SD->f2.Polyp.PolypYear[z + 50000 * b_f];

                /*  POSSIBLY DELETE LATER */
                /*  a random number for stage and sojourn time */
                st.site = &rb_emlrtRSI;
                b_mtmp = b_rand() * 999.0 + 1.0;
                x = muDoubleScalarRound(b_mtmp);
                mtmp = muDoubleScalarRound(b_mtmp);
                if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                  emlrtIntegerCheckR2012b(mtmp, &eb_emlrtDCI, sp);
                }

                i5 = (int32_T)mtmp;
                if (!((i5 >= 1) && (i5 <= 1000))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 1000, &vc_emlrtBCI, sp);
                }

                tmp1 = StageMatrix[i5 - 1];
                st.site = &qb_emlrtRSI;
                mtmp = b_rand() * 999.0 + 1.0;
                b_x = muDoubleScalarRound(mtmp);
                mtmp = muDoubleScalarRound(mtmp);
                if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                  emlrtIntegerCheckR2012b(mtmp, &m_emlrtDCI, sp);
                }

                i5 = (int32_T)mtmp;
                if (!((i5 >= 1) && (i5 <= 1000))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 1000, &gb_emlrtBCI, sp);
                }

                i5 = StageMatrix[(int32_T)x - 1] - 6;
                if (!((i5 >= 1) && (i5 <= 4))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 4, &fb_emlrtBCI, sp);
                }

                SD->f2.Ca.SympTime[z + 50000 * ii_size_idx_1] = time +
                  SojournMatrix[((int32_T)b_x + 1000 * (StageMatrix[(int32_T)
                  muDoubleScalarRound(b_mtmp) - 1] - 7)) - 1];
                SD->f2.Ca.SympStage[z + 50000 * ii_size_idx_1] = StageMatrix
                  [(int32_T)x - 1];
                if (StageMatrix[(int32_T)x - 1] > 7) {
                  SD->f2.Ca.TimeStage_I[z + 50000 * ii_size_idx_1] = time +
                    muDoubleScalarRound(SojournMatrix[((int32_T)b_x + 1000 *
                    (StageMatrix[(int32_T)muDoubleScalarRound(b_mtmp) - 1] - 7))
                                        - 1] * StageDuration[StageMatrix
                                        [(int32_T)x - 1] - 7] * 4.0) / 4.0;
                } else {
                  SD->f2.Ca.TimeStage_I[z + 50000 * ii_size_idx_1] = 1000.0;
                }

                if (StageMatrix[(int32_T)x - 1] > 8) {
                  SD->f2.Ca.TimeStage_II[z + 50000 * ii_size_idx_1] = time +
                    muDoubleScalarRound(SojournMatrix[((int32_T)b_x + 1000 *
                    (StageMatrix[(int32_T)muDoubleScalarRound(b_mtmp) - 1] - 7))
                                        - 1] * (StageDuration[StageMatrix
                    [(int32_T)x - 1] - 7] + StageDuration[tmp1 - 3]) * 4.0) /
                    4.0;
                } else {
                  SD->f2.Ca.TimeStage_II[z + 50000 * ii_size_idx_1] = 1000.0;
                }

                if (StageMatrix[(int32_T)x - 1] > 9) {
                  for (i5 = 0; i5 < 3; i5++) {
                    b_StageDuration[i5] = StageDuration[3 + (i5 << 2)];
                  }

                  SD->f2.Ca.TimeStage_III[z + 50000 * ii_size_idx_1] = time +
                    muDoubleScalarRound(SojournMatrix[((int32_T)b_x + 1000 *
                    (StageMatrix[(int32_T)muDoubleScalarRound(b_mtmp) - 1] - 7))
                                        - 1] * i_sum(b_StageDuration) * 4.0) /
                    4.0;
                } else {
                  SD->f2.Ca.TimeStage_III[z + 50000 * ii_size_idx_1] = 1000.0;
                }

                /*  we keep track */
                idx = 0;
                ii = 1;
                exitg14 = false;
                while ((!exitg14) && (ii < 5001)) {
                  guard9 = false;
                  if (DwellTimeProgression[((int32_T)*y + 100 * (ii - 1)) - 1]
                      != 0.0) {
                    idx++;
                    if (idx >= 5000) {
                      exitg14 = true;
                    } else {
                      guard9 = true;
                    }
                  } else {
                    guard9 = true;
                  }

                  if (guard9) {
                    ii++;
                  }
                }

                if (1 > idx) {
                  i9 = 0;
                } else {
                  i9 = idx;
                }

                i5 = i9 + 1;
                if (!((i5 >= 1) && (i5 <= 5000))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 5000, &wc_emlrtBCI, sp);
                }

                DwellTimeProgression[((int32_T)*y + 100 * (i5 - 1)) - 1] = time
                  - SD->f2.Polyp.PolypYear[z + 50000 * b_f];
                loop_ub = 101 - (int32_T)*y;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  HasCancer[(((int32_T)*y + i5) + 100 * z) - 1] = 1.0;
                }

                ProgressedCancer[(int32_T)*y - 1]++;
                if (SD->f2.Ca.CancerLocation[z + 50000 * ii_size_idx_1] < 4.0) {
                  ProgressedCancerR[(int32_T)*y - 1]++;
                }

                /*  and we delete the polyp */
                if (b_f + 2 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 2 >= 1) && (b_f + 2 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 2, 1, 51, &eb_emlrtBCI,
                      sp);
                  }

                  i5 = b_f + 1;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &eb_emlrtBCI,
                      sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f + 1 > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv69[0] = 1;
                iv69[1] = ii - idx;
                b_Polyp_size[0] = 1;
                b_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = b_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv69, 2, Polyp, 2, &o_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.Polyps[z + 50000 * (i5 + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.Polyps[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 2 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 2 >= 1) && (b_f + 2 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 2, 1, 51, &db_emlrtBCI,
                      sp);
                  }

                  i5 = b_f + 1;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &db_emlrtBCI,
                      sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f + 1 > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv70[0] = 1;
                iv70[1] = ii - idx;
                c_Polyp_size[0] = 1;
                c_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = c_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv70, 2, Polyp, 2, &n_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.PolypYear[z + 50000 * (i5 + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.PolypYear[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 2 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 2 >= 1) && (b_f + 2 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 2, 1, 51, &cb_emlrtBCI,
                      sp);
                  }

                  i5 = b_f + 1;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &cb_emlrtBCI,
                      sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f + 1 > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv71[0] = 1;
                iv71[1] = ii - idx;
                d_Polyp_size[0] = 1;
                d_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = d_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv71, 2, Polyp, 2, &m_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.PolypLocation[z + 50000 * (i5 +
                    idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.PolypLocation[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 2 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 2 >= 1) && (b_f + 2 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 2, 1, 51, &bb_emlrtBCI,
                      sp);
                  }

                  i5 = b_f + 1;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &bb_emlrtBCI,
                      sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f + 1 > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv72[0] = 1;
                iv72[1] = ii - idx;
                e_Polyp_size[0] = 1;
                e_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = e_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv72, 2, Polyp, 2, &l_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.EarlyProgression[z + 50000 *
                    (i5 + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.EarlyProgression[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 2 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 2 >= 1) && (b_f + 2 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 2, 1, 51, &ab_emlrtBCI,
                      sp);
                  }

                  i5 = b_f + 1;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &ab_emlrtBCI,
                      sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f + 1 > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv73[0] = 1;
                iv73[1] = ii - idx;
                f_Polyp_size[0] = 1;
                f_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = f_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv73, 2, Polyp, 2, &k_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.AdvProgression[z + 50000 * (i5
                    + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.AdvProgression[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }
              }
            } else {
              i5 = (int32_T)SD->f2.Polyp.Polyps[z + 50000 * b_f];
              if (!((i5 >= 1) && (i5 <= 10))) {
                emlrtDynamicBoundsCheckR2012b(i5, 1, 10, &y_emlrtBCI, sp);
              }

              mtmp = SD->f2.Polyp.PolypLocation[z + 50000 * b_f];
              if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                emlrtIntegerCheckR2012b(mtmp, &l_emlrtDCI, sp);
              }

              i5 = (int32_T)mtmp;
              if (!((i5 >= 1) && (i5 <= 13))) {
                emlrtDynamicBoundsCheckR2012b(i5, 1, 13, &x_emlrtBCI, sp);
              }

              mtmp = Gender[z];
              if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                emlrtIntegerCheckR2012b(mtmp, &k_emlrtDCI, sp);
              }

              i5 = (int32_T)mtmp;
              if (!((i5 >= 1) && (i5 <= 2))) {
                emlrtDynamicBoundsCheckR2012b(i5, 1, 2, &w_emlrtBCI, sp);
              }

              i5 = (int32_T)SD->f2.Polyp.Polyps[z + 50000 * b_f];
              if (!((i5 >= 1) && (i5 <= 10))) {
                emlrtDynamicBoundsCheckR2012b(i5, 1, 10, &v_emlrtBCI, sp);
              }

              mtmp = SD->f2.Polyp.PolypLocation[z + 50000 * b_f];
              if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                emlrtIntegerCheckR2012b(mtmp, &j_emlrtDCI, sp);
              }

              i5 = (int32_T)mtmp;
              if (!((i5 >= 1) && (i5 <= 13))) {
                emlrtDynamicBoundsCheckR2012b(i5, 1, 13, &u_emlrtBCI, sp);
              }

              mtmp = Gender[z];
              if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                emlrtIntegerCheckR2012b(mtmp, &i_emlrtDCI, sp);
              }

              i5 = (int32_T)mtmp;
              if (!((i5 >= 1) && (i5 <= 2))) {
                emlrtDynamicBoundsCheckR2012b(i5, 1, 2, &t_emlrtBCI, sp);
              }

              mtmp = SD->f2.Polyp.EarlyProgression[z + 50000 * b_f];
              if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                emlrtIntegerCheckR2012b(mtmp, &h_emlrtDCI, sp);
              }

              i5 = (int32_T)mtmp;
              if (!((i5 >= 1) && (i5 <= 500))) {
                emlrtDynamicBoundsCheckR2012b(i5, 1, 500, &s_emlrtBCI, sp);
              }

              mtmp = SD->f2.Polyp.AdvProgression[z + 50000 * b_f];
              if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                emlrtIntegerCheckR2012b(mtmp, &g_emlrtDCI, sp);
              }

              i5 = (int32_T)mtmp;
              if (!((i5 >= 1) && (i5 <= 500))) {
                emlrtDynamicBoundsCheckR2012b(i5, 1, 500, &r_emlrtBCI, sp);
              }

              st.site = &pb_emlrtRSI;
              if (b_rand() < (real_T)b_strcmp(DwellSpeed) *
                  (StageVariables->FastCancer[(int32_T)SD->f2.Polyp.Polyps[z +
                   50000 * b_f] - 1] * AgeProgression[5 + 6 * ((int32_T)*y - 1)]
                   * LocationProgression[5 + 10 * ((int32_T)
                    SD->f2.Polyp.PolypLocation[z + 50000 * b_f] - 1)] *
                   GenderProgression[5 + 10 * ((int32_T)Gender[z] - 1)]) +
                  (real_T)c_strcmp(DwellSpeed) * (StageVariables->FastCancer
                   [(int32_T)SD->f2.Polyp.Polyps[z + 50000 * b_f] - 1] *
                   AgeProgression[5 + 6 * ((int32_T)*y - 1)] *
                   LocationProgression[5 + 10 * ((int32_T)
                    SD->f2.Polyp.PolypLocation[z + 50000 * b_f] - 1)] *
                   GenderProgression[5 + 10 * ((int32_T)Gender[z] - 1)]) *
                  ((real_T)(SD->f2.Polyp.Polyps[z + 50000 * b_f] < 5.0) *
                   RiskDistribution->EarlyRisk[(int32_T)
                   SD->f2.Polyp.EarlyProgression[z + 50000 * b_f] - 1] + (real_T)
                   (SD->f2.Polyp.Polyps[z + 50000 * b_f] > 4.0) *
                   RiskDistribution->AdvancedRisk[(int32_T)
                   SD->f2.Polyp.AdvProgression[z + 50000 * b_f] - 1])) {
                /*  this is fast progressed cancer now. we need to write */
                /*  everything into the cancer variable */
                idx = 0;
                ii = 1;
                exitg13 = false;
                while ((!exitg13) && (ii < 26)) {
                  guard8 = false;
                  if (SD->f2.Ca.Cancer[z + 50000 * (ii - 1)] != 0.0) {
                    idx++;
                    if (idx >= 25) {
                      exitg13 = true;
                    } else {
                      guard8 = true;
                    }
                  } else {
                    guard8 = true;
                  }

                  if (guard8) {
                    ii++;
                  }
                }

                if (1 > idx) {
                  ii_size_idx_1 = 0;
                } else {
                  ii_size_idx_1 = idx;
                }

                if (!((ii_size_idx_1 + 1 >= 1) && (ii_size_idx_1 + 1 <= 25))) {
                  emlrtDynamicBoundsCheckR2012b(ii_size_idx_1 + 1, 1, 25,
                    &pc_emlrtBCI, sp);
                }

                SD->f2.Ca.Cancer[z + 50000 * ii_size_idx_1] = 7.0;
                SD->f2.Ca.CancerYear[z + 50000 * ii_size_idx_1] = time;
                SD->f2.Ca.CancerLocation[z + 50000 * ii_size_idx_1] =
                  SD->f2.Polyp.PolypLocation[z + 50000 * b_f];
                SD->f2.Ca.DwellTime[z + 50000 * ii_size_idx_1] = time -
                  SD->f2.Polyp.PolypYear[z + 50000 * b_f];

                /*  POSSIBLY DELETE LATER */
                /*  a random number for stage and sojourn time */
                st.site = &ob_emlrtRSI;
                b_mtmp = b_rand() * 999.0 + 1.0;
                x = muDoubleScalarRound(b_mtmp);
                mtmp = muDoubleScalarRound(b_mtmp);
                if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                  emlrtIntegerCheckR2012b(mtmp, &db_emlrtDCI, sp);
                }

                i5 = (int32_T)mtmp;
                if (!((i5 >= 1) && (i5 <= 1000))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 1000, &qc_emlrtBCI, sp);
                }

                tmp1 = StageMatrix[i5 - 1];
                st.site = &nb_emlrtRSI;
                mtmp = b_rand() * 999.0 + 1.0;
                b_x = muDoubleScalarRound(mtmp);
                mtmp = muDoubleScalarRound(mtmp);
                if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                  emlrtIntegerCheckR2012b(mtmp, &f_emlrtDCI, sp);
                }

                i5 = (int32_T)mtmp;
                if (!((i5 >= 1) && (i5 <= 1000))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 1000, &q_emlrtBCI, sp);
                }

                i5 = StageMatrix[(int32_T)x - 1] - 6;
                if (!((i5 >= 1) && (i5 <= 4))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 4, &p_emlrtBCI, sp);
                }

                SD->f2.Ca.SympTime[z + 50000 * ii_size_idx_1] = time +
                  SojournMatrix[((int32_T)b_x + 1000 * (StageMatrix[(int32_T)
                  muDoubleScalarRound(b_mtmp) - 1] - 7)) - 1];
                SD->f2.Ca.SympStage[z + 50000 * ii_size_idx_1] = StageMatrix
                  [(int32_T)x - 1];
                if (StageMatrix[(int32_T)x - 1] > 7) {
                  SD->f2.Ca.TimeStage_I[z + 50000 * ii_size_idx_1] = time +
                    muDoubleScalarRound(SojournMatrix[((int32_T)b_x + 1000 *
                    (StageMatrix[(int32_T)muDoubleScalarRound(b_mtmp) - 1] - 7))
                                        - 1] * StageDuration[StageMatrix
                                        [(int32_T)x - 1] - 7] * 4.0) / 4.0;
                } else {
                  SD->f2.Ca.TimeStage_I[z + 50000 * ii_size_idx_1] = 1000.0;
                }

                if (StageMatrix[(int32_T)x - 1] > 8) {
                  SD->f2.Ca.TimeStage_II[z + 50000 * ii_size_idx_1] = time +
                    muDoubleScalarRound(SojournMatrix[((int32_T)b_x + 1000 *
                    (StageMatrix[(int32_T)muDoubleScalarRound(b_mtmp) - 1] - 7))
                                        - 1] * (StageDuration[StageMatrix
                    [(int32_T)x - 1] - 7] + StageDuration[tmp1 - 3]) * 4.0) /
                    4.0;
                } else {
                  SD->f2.Ca.TimeStage_II[z + 50000 * ii_size_idx_1] = 1000.0;
                }

                if (StageMatrix[(int32_T)x - 1] > 9) {
                  for (i5 = 0; i5 < 3; i5++) {
                    b_StageDuration[i5] = StageDuration[3 + (i5 << 2)];
                  }

                  SD->f2.Ca.TimeStage_III[z + 50000 * ii_size_idx_1] = time +
                    muDoubleScalarRound(SojournMatrix[((int32_T)b_x + 1000 *
                    (StageMatrix[(int32_T)muDoubleScalarRound(b_mtmp) - 1] - 7))
                                        - 1] * i_sum(b_StageDuration) * 4.0) /
                    4.0;
                } else {
                  SD->f2.Ca.TimeStage_III[z + 50000 * ii_size_idx_1] = 1000.0;
                }

                /*  we keep track */
                idx = 0;
                ii = 1;
                exitg12 = false;
                while ((!exitg12) && (ii < 5001)) {
                  guard7 = false;
                  if (DwellTimeFastCancer[((int32_T)*y + 100 * (ii - 1)) - 1] !=
                      0.0) {
                    idx++;
                    if (idx >= 5000) {
                      exitg12 = true;
                    } else {
                      guard7 = true;
                    }
                  } else {
                    guard7 = true;
                  }

                  if (guard7) {
                    ii++;
                  }
                }

                if (1 > idx) {
                  i10 = 0;
                } else {
                  i10 = idx;
                }

                i5 = i10 + 1;
                if (!((i5 >= 1) && (i5 <= 5000))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 5000, &rc_emlrtBCI, sp);
                }

                DwellTimeFastCancer[((int32_T)*y + 100 * (i5 - 1)) - 1] = time -
                  SD->f2.Polyp.PolypYear[z + 50000 * b_f];
                loop_ub = 101 - (int32_T)*y;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  HasCancer[(((int32_T)*y + i5) + 100 * z) - 1] = 1.0;
                }

                i5 = (int32_T)SD->f2.Polyp.Polyps[z + 50000 * b_f];
                if (!((i5 >= 1) && (i5 <= 5))) {
                  emlrtDynamicBoundsCheckR2012b(i5, 1, 5, &sc_emlrtBCI, sp);
                }

                i6 = (int32_T)SD->f2.Polyp.Polyps[z + 50000 * b_f];
                if (!((i6 >= 1) && (i6 <= 5))) {
                  emlrtDynamicBoundsCheckR2012b(i6, 1, 5, &tc_emlrtBCI, sp);
                }

                DirectCancer[(i6 + 5 * ((int32_T)*y - 1)) - 1] = DirectCancer
                  [(i5 + 5 * ((int32_T)*y - 1)) - 1] + 1.0;
                if (SD->f2.Ca.CancerLocation[z + 50000 * ii_size_idx_1] < 4.0) {
                  DirectCancerR[(int32_T)*y - 1]++;
                }

                /*  and we delete the polyp */
                if (b_f + 2 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 2 >= 1) && (b_f + 2 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 2, 1, 51, &o_emlrtBCI,
                      sp);
                  }

                  i5 = b_f + 1;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &o_emlrtBCI, sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f + 1 > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv74[0] = 1;
                iv74[1] = ii - idx;
                g_Polyp_size[0] = 1;
                g_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = g_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv74, 2, Polyp, 2, &j_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.Polyps[z + 50000 * (i5 + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.Polyps[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 2 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 2 >= 1) && (b_f + 2 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 2, 1, 51, &n_emlrtBCI,
                      sp);
                  }

                  i5 = b_f + 1;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &n_emlrtBCI, sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f + 1 > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv75[0] = 1;
                iv75[1] = ii - idx;
                h_Polyp_size[0] = 1;
                h_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = h_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv75, 2, Polyp, 2, &i_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.PolypYear[z + 50000 * (i5 + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.PolypYear[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 2 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 2 >= 1) && (b_f + 2 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 2, 1, 51, &m_emlrtBCI,
                      sp);
                  }

                  i5 = b_f + 1;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &m_emlrtBCI, sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f + 1 > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv76[0] = 1;
                iv76[1] = ii - idx;
                i_Polyp_size[0] = 1;
                i_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = i_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv76, 2, Polyp, 2, &h_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.PolypLocation[z + 50000 * (i5 +
                    idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.PolypLocation[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 2 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 2 >= 1) && (b_f + 2 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 2, 1, 51, &l_emlrtBCI,
                      sp);
                  }

                  i5 = b_f + 1;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &l_emlrtBCI, sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f + 1 > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv77[0] = 1;
                iv77[1] = ii - idx;
                j_Polyp_size[0] = 1;
                j_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = j_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv77, 2, Polyp, 2, &g_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.EarlyProgression[z + 50000 *
                    (i5 + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.EarlyProgression[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 2 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 2 >= 1) && (b_f + 2 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 2, 1, 51, &k_emlrtBCI,
                      sp);
                  }

                  i5 = b_f + 1;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &k_emlrtBCI, sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f + 1 > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv78[0] = 1;
                iv78[1] = ii - idx;
                k_Polyp_size[0] = 1;
                k_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = k_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv78, 2, Polyp, 2, &f_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.AdvProgression[z + 50000 * (i5
                    + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.AdvProgression[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }
              }
            }

            f++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
          }

          /*                  catch exception */
          /*                      rethrow(exception) */
          /*                  end */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*    a polyp shrinks or disappears      % */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*     try */
          idx = 0;
          ii = 1;
          exitg11 = false;
          while ((!exitg11) && (ii < 52)) {
            guard6 = false;
            if (SD->f2.Polyp.Polyps[z + 50000 * (ii - 1)] != 0.0) {
              idx++;
              if (idx >= 51) {
                exitg11 = true;
              } else {
                guard6 = true;
              }
            } else {
              guard6 = true;
            }

            if (guard6) {
              ii++;
            }
          }

          if (1 > idx) {
            i4 = 0;
          } else {
            i4 = idx;
          }

          /*  we need to calculate the length again */
          if (1 > idx) {
            i11 = 0;
          } else {
            i11 = idx;
          }

          emlrtForLoopVectorCheckR2012b(i11, -1.0, 1.0, mxDOUBLE_CLASS, i4,
            &d_emlrtRTEI, sp);
          f = 0;
          while (f <= i4 - 1) {
            b_f = i4 - f;
            if (!((b_f >= 1) && (b_f <= 51))) {
              emlrtDynamicBoundsCheckR2012b(b_f, 1, 51, &mc_emlrtBCI, sp);
            }

            i5 = (int32_T)SD->f2.Polyp.Polyps[z + 50000 * (b_f - 1)];
            if (!((i5 >= 1) && (i5 <= 10))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, 10, &lc_emlrtBCI, sp);
            }

            st.site = &mb_emlrtRSI;
            if (b_rand() < StageVariables->Healing[i5 - 1]) {
              if (!((b_f >= 1) && (b_f <= 51))) {
                emlrtDynamicBoundsCheckR2012b(b_f, 1, 51, &nc_emlrtBCI, sp);
              }

              if (!((b_f >= 1) && (b_f <= 51))) {
                emlrtDynamicBoundsCheckR2012b(b_f, 1, 51, &oc_emlrtBCI, sp);
              }

              SD->f2.Polyp.Polyps[z + 50000 * (b_f - 1)]--;
              if (isequal(SD->f2.Polyp.Polyps[z + 50000 * (b_f - 1)], 0.0)) {
                /*  in this case, the polyp had been of the smallest size, */
                /*  further shrinkage causes disappearance */
                if (b_f + 1 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &j_emlrtBCI,
                      sp);
                  }

                  i5 = b_f;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &j_emlrtBCI, sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f - 1;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv79[0] = 1;
                iv79[1] = ii - idx;
                l_Polyp_size[0] = 1;
                l_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = l_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv79, 2, Polyp, 2, &e_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.Polyps[z + 50000 * (i5 + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.Polyps[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 1 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &i_emlrtBCI,
                      sp);
                  }

                  i5 = b_f;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &i_emlrtBCI, sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f - 1;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv80[0] = 1;
                iv80[1] = ii - idx;
                m_Polyp_size[0] = 1;
                m_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = m_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv80, 2, Polyp, 2, &d_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.PolypYear[z + 50000 * (i5 + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.PolypYear[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 1 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &h_emlrtBCI,
                      sp);
                  }

                  i5 = b_f;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &h_emlrtBCI, sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f - 1;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv81[0] = 1;
                iv81[1] = ii - idx;
                n_Polyp_size[0] = 1;
                n_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = n_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv81, 2, Polyp, 2, &c_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.PolypLocation[z + 50000 * (i5 +
                    idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.PolypLocation[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 1 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &g_emlrtBCI,
                      sp);
                  }

                  i5 = b_f;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &g_emlrtBCI, sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f - 1;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv82[0] = 1;
                iv82[1] = ii - idx;
                o_Polyp_size[0] = 1;
                o_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = o_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv82, 2, Polyp, 2, &b_emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.EarlyProgression[z + 50000 *
                    (i5 + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.EarlyProgression[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }

                if (b_f + 1 > i4 + 1) {
                  i5 = 0;
                  i6 = 0;
                } else {
                  if (!((b_f + 1 >= 1) && (b_f + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(b_f + 1, 1, 51, &f_emlrtBCI,
                      sp);
                  }

                  i5 = b_f;
                  if (!((i4 + 1 >= 1) && (i4 + 1 <= 51))) {
                    emlrtDynamicBoundsCheckR2012b(i4 + 1, 1, 51, &f_emlrtBCI, sp);
                  }

                  i6 = i4 + 1;
                }

                if (b_f > i4) {
                  idx = 0;
                  ii = 0;
                } else {
                  idx = b_f - 1;
                  ii = i4;
                }

                loop_ub = ii - idx;
                for (ii_size_idx_1 = 0; ii_size_idx_1 < loop_ub; ii_size_idx_1++)
                {
                  c_tmp_data[ii_size_idx_1] = idx + ii_size_idx_1;
                }

                iv83[0] = 1;
                iv83[1] = ii - idx;
                p_Polyp_size[0] = 1;
                p_Polyp_size[1] = i6 - i5;
                for (idx = 0; idx < 2; idx++) {
                  Polyp[idx] = p_Polyp_size[idx];
                }

                emlrtSubAssignSizeCheckR2012b(iv83, 2, Polyp, 2, &emlrtECI, sp);
                loop_ub = i6 - i5;
                for (idx = 0; idx < loop_ub; idx++) {
                  Polyp_data[idx] = SD->f2.Polyp.AdvProgression[z + 50000 * (i5
                    + idx)];
                }

                loop_ub = i6 - i5;
                for (i5 = 0; i5 < loop_ub; i5++) {
                  SD->f2.Polyp.AdvProgression[z + 50000 * c_tmp_data[i5]] =
                    Polyp_data[i5];
                }
              }
            }

            f++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
          }

          /*                  catch exception */
          /*                      rethrow(exception) */
          /*                  end */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*  symptom development               % */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*  try */
          idx = 0;
          ii = 1;
          exitg10 = false;
          while ((!exitg10) && (ii < 26)) {
            guard5 = false;
            if (SD->f2.Ca.Cancer[z + 50000 * (ii - 1)] != 0.0) {
              idx++;
              if (idx >= 25) {
                exitg10 = true;
              } else {
                guard5 = true;
              }
            } else {
              guard5 = true;
            }

            if (guard5) {
              ii++;
            }
          }

          if (1 > idx) {
            i4 = 0;
          } else {
            i4 = idx;
          }

          emlrtForLoopVectorCheckR2012b(i4, -1.0, 1.0, mxDOUBLE_CLASS, i4,
            &c_emlrtRTEI, sp);
          f = 0;
          exitg9 = false;
          while ((!exitg9) && (f <= i4 - 1)) {
            i5 = i4 - f;
            if (!((i5 >= 1) && (i5 <= 25))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, 25, &ic_emlrtBCI, sp);
            }

            if (time >= SD->f2.Ca.SympTime[z + 50000 * (i5 - 1)]) {
              /*  if symptoms appear we do colonoscopy */
              Number->Symptoms_Colonoscopy[(int32_T)*y - 1]++;
              st.site = &lb_emlrtRSI;
              Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 + (real_T)q, Gender,
                          &SD->f2.Polyp, &SD->f2.Ca, &SD->f2.Detected, Included,
                          DeathCause, DeathYear, DiagnosedCancer,
                          AdvancedPolypsRemoved, EarlyPolypsRemoved, Last,
                          TumorRecord, PaymentType, Money, StageVariables, Cost,
                          Location, *risc, ColoReachMatrix, MortalityMatrix,
                          CostStage);
              exitg9 = true;
            } else {
              f++;
              if (*emlrtBreakCheckR2012bFlagVar != 0) {
                emlrtBreakCheckR2012b(sp);
              }
            }
          }

          /*                  catch exception */
          /*                      rethrow(exception) */
          /*                  end */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*  Cancer Progression                % */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*                 try */
          idx = 0;
          ii = 1;
          exitg8 = false;
          while ((!exitg8) && (ii < 26)) {
            guard4 = false;
            if (SD->f2.Ca.Cancer[z + 50000 * (ii - 1)] != 0.0) {
              idx++;
              if (idx >= 25) {
                exitg8 = true;
              } else {
                guard4 = true;
              }
            } else {
              guard4 = true;
            }

            if (guard4) {
              ii++;
            }
          }

          if (1 > idx) {
            ii_size_idx_1 = 0;
          } else {
            ii_size_idx_1 = idx;
          }

          f = 0;
          while (f <= ii_size_idx_1 - 1) {
            if (isequal(SD->f2.Ca.Cancer[z + 50000 * f], 7.0)) {
              if (time >= SD->f2.Ca.TimeStage_I[z + 50000 * f]) {
                SD->f2.Ca.Cancer[z + 50000 * f] = 8.0;
              }
            } else if (isequal(SD->f2.Ca.Cancer[z + 50000 * f], 8.0)) {
              if (time >= SD->f2.Ca.TimeStage_II[z + 50000 * f]) {
                SD->f2.Ca.Cancer[z + 50000 * f] = 9.0;
              }
            } else {
              if (isequal(SD->f2.Ca.Cancer[z + 50000 * f], 9.0) && (time >=
                   SD->f2.Ca.TimeStage_III[z + 50000 * f])) {
                SD->f2.Ca.Cancer[z + 50000 * f] = 10.0;
              }
            }

            f++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
          }

          /*                  catch exception */
          /*                      rethrow(exception) */
          /*                  end */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*     baseline colonoscopy           % */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*  There is a small chance, */
          /*  symptoms appear even without a leasion */
          /*                  if isequal(q,1) */
          /*                      if rand < ColonoscopyLikelyhood(y) */
          /*                          % symptoms without a polyp: we do baseline colonoscopy */
          /*                          Number.Baseline_Colonoscopy(y) = Number.Baseline_Colonoscopy(y) +1; */
          /*                          [Polyp, Ca, Detected, Included, DeathCause, DeathYear,... */
          /*                              DiagnosedCancer, AdvancedPolypsRemoved, EarlyPolypsRemoved, Last, TumorRecord, PaymentType, Money]... */
          /*                              = Colonoscopy(z, y, q, 'Base', Gender, Polyp,... */
          /*                              Ca, Detected, Included, DeathCause, DeathYear,... */
          /*                              DiagnosedCancer, AdvancedPolypsRemoved, EarlyPolypsRemoved, Last, TumorRecord, PaymentType, Money,... */
          /*                              StageVariables, Cost, Location, risc, ColoReachMatrix, MortalityMatrix, CostStage); */
          /*                      end */
          /*                  end */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*  polyp and cancer surveillance     % */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          if (isequal(1.0 + (real_T)q, 1.0)) {
            SurveillanceFlag = 0;
            if (flag->Polyp_Surveillance) {
              /*  a polyp removed 5 years ago if no colonoscopy */
              /*  performed inbetween. */
              /*       try */
              if (isequal(*y - Last->Polyp[z], 5.0) && (*y - Last->Colonoscopy[z]
                   >= 5.0)) {
                SurveillanceFlag = 1;

                /*  between 5 and 9 years after polyp removal after last colonoscopy */
              } else if ((*y - Last->Polyp[z] > 5.0) && (*y - Last->Polyp[z] <=
                          9.0) && (*y - Last->Colonoscopy[z] >= 5.0)) {
                SurveillanceFlag = 1;

                /*  This provides surveillance every 5 years after */
                /*  each polyp !!! */
                /*    elseif and(~isequal(Last.Polyp(z), -100), y-Last.Colonoscopy(z) >=5) */
                /*        SurveillanceFlag = 1; */
                /*  an advanced polyp 3 years ago */
              } else if (isequal(*y - Last->AdvPolyp[z], 3.0) && (*y -
                          Last->Colonoscopy[z] >= 3.0)) {
                SurveillanceFlag = 1;

                /*  5 years intervals if an advanced polyp had been */
                /*  diagnosed */
              } else if (!isequal(Last->AdvPolyp[z], -100.0)) {
                if ((*y - Last->AdvPolyp[z] >= 5.0) && (*y - Last->Colonoscopy[z]
                     >= 5.0)) {
                  /*  and((y - LastAdvPolyp(z))>8, (y - LastAdvPolyp(z))<=13) && ((y-LastColonoscopy(z)) >=5) */
                  SurveillanceFlag = 1;
                }
              } else {
                if (flag->AllPolypFollowUp && (!isequal(Last->Polyp[z], -100.0))
                    && ((*y - Last->Polyp[z] >= 5.0) && (*y - Last->
                      Colonoscopy[z] >= 5.0))) {
                  SurveillanceFlag = 1;
                }
              }

              /*                      catch exception */
              /*                          rethrow(exception) */
              /*                      end */
            }

            if (flag->Cancer_Surveillance && (!isequal(Last->Cancer[z], -100.0)))
            {
              /*  1 year after cancer diagnosis */
              if (isequal(*y - Last->Cancer[z], 1.0) && isequal(*y -
                   Last->Colonoscopy[z], 1.0)) {
                SurveillanceFlag = 1;

                /*  4 years after cancer diagnosis */
              } else if (isequal(*y - Last->Cancer[z], 4.0) && isequal(*y -
                          Last->Colonoscopy[z], 3.0)) {
                SurveillanceFlag = 1;

                /*  5 years intervals after this */
              } else {
                if ((*y - Last->Cancer[z] >= 5.0) && (*y - Last->Colonoscopy[z] >=
                     5.0)) {
                  SurveillanceFlag = 1;
                }
              }
            }

            if (isequal(SurveillanceFlag, 1.0)) {
              Number->Follow_Up_Colonoscopy[(int32_T)*y - 1]++;
              st.site = &kb_emlrtRSI;
              b_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 + (real_T)q,
                            Gender, &SD->f2.Polyp, &SD->f2.Ca, &SD->f2.Detected,
                            Included, DeathCause, DeathYear, DiagnosedCancer,
                            AdvancedPolypsRemoved, EarlyPolypsRemoved, Last,
                            TumorRecord, PaymentType, Money, StageVariables,
                            Cost, Location, *risc, ColoReachMatrix,
                            MortalityMatrix, CostStage);
            }

            /*  perhaps we do screening? */
            if (flag->Screening && (Included[z] && (!isequal
                  (ScreeningPreference[z], 0.0)))) {
              /*  we only screen patients who are alive */
              /*  x-matrix */
              /*  1: PercentPop, 2: Adherence,    3: FollowUp,   4:y-start, 5:y-end, */
              /*  6: interval,   7: y after colo, 8: specificity */
              /*  y-matrix */
              /*  1: colonoscopy, 2: Rectosigmoidoscopy, 3: FOBT, 4: I_FOBT */
              /*  5: Sept9_HiSens, 6: Sept9_HiSpec, 7: other */
              preference = ScreeningPreference[z];
              if (ScreeningPreference[z] != (int32_T)muDoubleScalarFloor
                  (ScreeningPreference[z])) {
                emlrtIntegerCheckR2012b(ScreeningPreference[z], &e_emlrtDCI, sp);
              }

              i4 = (int32_T)ScreeningPreference[z];
              if (!((i4 >= 1) && (i4 <= 7))) {
                emlrtDynamicBoundsCheckR2012b(i4, 1, 7, &e_emlrtBCI, sp);
              }

              if ((*y >= ScreeningTest[(int32_T)ScreeningPreference[z] + 20]) &&
                  (*y < ScreeningTest[(int32_T)ScreeningPreference[z] + 27]) &&
                  (*y - Last->Colonoscopy[z] >= ScreeningTest[(int32_T)
                   ScreeningPreference[z] + 41])) {
                /*  if and(y >= Screening.Year_Start, y <Screening.Year_End) % if the patients qualifies agewise */
                /*  we only screen so and so many years after the last Colonoscopy */
                if (isequal(ScreeningPreference[z], 1.0)) {
                  /*  Colonoscopy */
                  if (*y - Last->Colonoscopy[z] >= ScreeningTest[(int32_T)
                      ScreeningPreference[z] + 34]) {
                    /*  interval */
                    Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                    st.site = &jb_emlrtRSI;
                    c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 + (real_T)q,
                                  Gender, &SD->f2.Polyp, &SD->f2.Ca,
                                  &SD->f2.Detected, Included, DeathCause,
                                  DeathYear, DiagnosedCancer,
                                  AdvancedPolypsRemoved, EarlyPolypsRemoved,
                                  Last, TumorRecord, PaymentType, Money,
                                  StageVariables, Cost, Location, *risc,
                                  ColoReachMatrix, MortalityMatrix, CostStage);
                  }
                } else if (isequal(ScreeningPreference[z], 2.0)) {
                  /*  Rectosigmoidoscopy */
                  st.site = &ib_emlrtRSI;
                  if ((*y - Last->ScreenTest[z] >= ScreeningTest[(int32_T)
                       ScreeningPreference[z] + 34]) && (b_rand() <
                       ScreeningTest[(int32_T)ScreeningPreference[z] + 6])) {
                    /*  interval */
                    /*  compliance with test */
                    Number->RectoSigmo[(int32_T)*y - 1]++;
                    Last->ScreenTest[z] = *y;
                    st.site = &hb_emlrtRSI;
                    RectoSigmo(&st, 1.0 + (real_T)z, *y, &SD->f2.Polyp,
                               SD->f2.Ca.Cancer, SD->f2.Ca.CancerLocation,
                               Included, DeathCause, DeathYear, PaymentType,
                               Money, StageVariables->RectoSigmo_Detection,
                               Cost->Sigmoidoscopy, Cost->Sigmoidoscopy_Polyp,
                               Cost->Colonoscopy_Perforation,
                               Location->RectoSigmoDetection, *risc,
                               RectoSigmoReachMatrix, *flag, &PolypFlag,
                               &AdvPolypFlag, &CancerFlag);
                    if ((PolypFlag != 0.0) || (CancerFlag != 0.0) ||
                        (AdvPolypFlag != 0.0)) {
                      /*  StageVariables.Colo_Detection(7:10) = 1; % BM 29.5.2016 */
                      st.site = &gb_emlrtRSI;
                      if (b_rand() < ScreeningTest[(int32_T)
                          ScreeningPreference[z] + 13]) {
                        /*  compliance with follow up kolo */
                        Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                        ScreeningPreference[z] = 1.0;

                        /*  according to paper by Zauber et al. we need to continue with colonoscopy screening */
                        st.site = &fb_emlrtRSI;
                        c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 +
                                      (real_T)q, Gender, &SD->f2.Polyp,
                                      &SD->f2.Ca, &SD->f2.Detected, Included,
                                      DeathCause, DeathYear, DiagnosedCancer,
                                      AdvancedPolypsRemoved, EarlyPolypsRemoved,
                                      Last, TumorRecord, PaymentType, Money,
                                      StageVariables, Cost, Location, *risc,
                                      ColoReachMatrix, MortalityMatrix,
                                      CostStage);
                      }

                      /*  StageVariables.Colo_Detection = Colo_Detection_bckup; */
                    }
                  }

                  /* %% we need to fill this */
                } else {
                  /*  other test */
                  /*  we do the Septin9 or any other test */
                  st.site = &eb_emlrtRSI;
                  if ((*y - Last->ScreenTest[z] >= ScreeningTest[(int32_T)
                       ScreeningPreference[z] + 34]) && (b_rand() <
                       ScreeningTest[(int32_T)ScreeningPreference[z] + 6])) {
                    /*  compliance with test */
                    Last->ScreenTest[z] = *y;
                    Limit = 0.0;
                    idx = 0;
                    for (i4 = 0; i4 < 2; i4++) {
                      ii_size[i4] = 1;
                    }

                    ii = 51;
                    exitg7 = false;
                    while ((!exitg7) && (ii > 0)) {
                      if (SD->f2.Polyp.Polyps[z + 50000 * (ii - 1)] != 0.0) {
                        idx = 1;
                        exitg7 = true;
                      } else {
                        ii--;
                      }
                    }

                    if (idx == 0) {
                      ii_size[1] = 0;
                    }

                    if (!(ii_size[1] == 0)) {
                      b_mtmp = SD->f2.Polyp.Polyps[z];
                      for (ii = 0; ii < 50; ii++) {
                        if (SD->f2.Polyp.Polyps[z + 50000 * (ii + 1)] > b_mtmp)
                        {
                          b_mtmp = SD->f2.Polyp.Polyps[z + 50000 * (ii + 1)];
                        }
                      }

                      i4 = (int32_T)b_mtmp;
                      if (!((i4 >= 1) && (i4 <= 10))) {
                        emlrtDynamicBoundsCheckR2012b(i4, 1, 10, &jc_emlrtBCI,
                          sp);
                      }

                      Limit = Sensitivity[((int32_T)ScreeningPreference[z] + 7 *
                                           (i4 - 1)) - 1];
                    }

                    idx = 0;
                    for (i4 = 0; i4 < 2; i4++) {
                      ii_size[i4] = 1;
                    }

                    ii = 25;
                    exitg6 = false;
                    while ((!exitg6) && (ii > 0)) {
                      if (SD->f2.Ca.Cancer[z + 50000 * (ii - 1)] != 0.0) {
                        idx = 1;
                        exitg6 = true;
                      } else {
                        ii--;
                      }
                    }

                    if (idx == 0) {
                      ii_size[1] = 0;
                    }

                    if (!(ii_size[1] == 0)) {
                      b_mtmp = SD->f2.Ca.Cancer[z];
                      for (ii = 0; ii < 24; ii++) {
                        if (SD->f2.Ca.Cancer[z + 50000 * (ii + 1)] > b_mtmp) {
                          b_mtmp = SD->f2.Ca.Cancer[z + 50000 * (ii + 1)];
                        }
                      }

                      i4 = (int32_T)b_mtmp;
                      if (!((i4 >= 1) && (i4 <= 10))) {
                        emlrtDynamicBoundsCheckR2012b(i4, 1, 10, &kc_emlrtBCI,
                          sp);
                      }

                      Limit = Sensitivity[((int32_T)ScreeningPreference[z] + 7 *
                                           (i4 - 1)) - 1];
                    }

                    Limit = muDoubleScalarMax(Limit, 1.0 - ScreeningTest
                      [(int32_T)ScreeningPreference[z] + 48]);
                    st.site = &db_emlrtRSI;
                    if ((b_rand() < Limit) && (b_rand() < ScreeningTest[(int32_T)
                         ScreeningPreference[z] + 13])) {
                      /*  if the test happens to be positive */
                      /*  compliance with follow up */
                      Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                      ScreeningPreference[z] = 1.0;

                      /*  according to paper by Zauber et al. we need to continue with colonoscopy screening */
                      st.site = &bb_emlrtRSI;
                      c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 + (real_T)
                                    q, Gender, &SD->f2.Polyp, &SD->f2.Ca,
                                    &SD->f2.Detected, Included, DeathCause,
                                    DeathYear, DiagnosedCancer,
                                    AdvancedPolypsRemoved, EarlyPolypsRemoved,
                                    Last, TumorRecord, PaymentType, Money,
                                    StageVariables, Cost, Location, *risc,
                                    ColoReachMatrix, MortalityMatrix, CostStage);
                    }

                    if (isequal(preference, 3.0)) {
                      Number->FOBT[(int32_T)*y - 1]++;
                      Money->Screening[(int32_T)*y - 1] += Cost->FOBT;
                      PaymentType->FOBT[(int32_T)*y - 1]++;
                    } else if (isequal(preference, 4.0)) {
                      Number->I_FOBT[(int32_T)*y - 1]++;
                      Money->Screening[(int32_T)*y - 1] += Cost->I_FOBT;
                      PaymentType->I_FOBT[(int32_T)*y - 1]++;
                    } else if (isequal(preference, 5.0)) {
                      Number->Sept9[(int32_T)*y - 1]++;
                      Money->Screening[(int32_T)*y - 1] += Cost->Sept9_HighSens;
                      PaymentType->Sept9_HighSens[(int32_T)*y - 1]++;
                    } else if (isequal(preference, 6.0)) {
                      Number->Sept9[(int32_T)*y - 1]++;
                      Money->Screening[(int32_T)*y - 1] += Cost->Sept9_HighSpec;
                      PaymentType->Sept9_HighSpec[(int32_T)*y - 1]++;
                    } else {
                      if (isequal(preference, 7.0)) {
                        Number->other[(int32_T)*y - 1]++;
                        Money->Screening[(int32_T)*y - 1] += Cost->other;
                        PaymentType->Other[(int32_T)*y - 1]++;
                      }
                    }
                  }
                }
              }
            }

            /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
            /*     special scenarios              % */
            /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
            if (flag->SpecialFlag && isequal(1.0 + (real_T)q, 1.0)) {
              if (flag->Atkin) {
                if (isequal(*y, 1.0)) {
                  if (isequal(1.0 + (real_T)z, 1.0)) {
                    /*  randomly one test year between 55 and 64 */
                    f = 0;
                    while (f < 50000) {
                      st.site = &ab_emlrtRSI;
                      b_mtmp = b_rand() * 9.0 + 1.0;
                      mtmp = muDoubleScalarRound(b_mtmp);
                      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                        emlrtIntegerCheckR2012b(mtmp, &d_emlrtDCI, sp);
                      }

                      i4 = (int32_T)mtmp;
                      if (!((i4 >= 1) && (i4 <= 10))) {
                        emlrtDynamicBoundsCheckR2012b(i4, 1, 10, &d_emlrtBCI, sp);
                      }

                      Last->Included[f] = 55.0 + ((real_T)i4 - 1.0);
                      st.site = &y_emlrtRSI;
                      if (b_rand() < 0.71) {
                        /*  adherence to first screening */
                        Last->TestYear[f] = Last->Included[f];
                      }

                      f++;
                      if (*emlrtBreakCheckR2012bFlagVar != 0) {
                        emlrtBreakCheckR2012b(sp);
                      }
                    }
                  }
                } else {
                  if (isequal(Last->Included[z], *y) && (!((*y -
                         Last->Colonoscopy[z] > 3.0) && isequal(Last->Cancer[z],
                         -100.0) && isequal(Last->Polyp[z], -100.0) && isequal
                        (Last->AdvPolyp[z], -100.0)))) {
                    /*  we need to check inclusion criteria */
                    /*  we exclude the patient by setting the years to -1 */
                    Last->TestYear[z] = -1.0;
                    Last->TestYear2[z] = -1.0;
                    Last->Included[z] = -1.0;
                  }

                  if (isequal(Last->TestYear[z], *y)) {
                    Last->TestDone[z] = 1.0;
                    if (!flag->Mock) {
                      Number->RectoSigmo[(int32_T)*y - 1]++;

                      /*  Number.Custom(y)     = Number.Custom(y) + 1; */
                      st.site = &x_emlrtRSI;
                      RectoSigmo(&st, 1.0 + (real_T)z, *y, &SD->f2.Polyp,
                                 SD->f2.Ca.Cancer, SD->f2.Ca.CancerLocation,
                                 Included, DeathCause, DeathYear, PaymentType,
                                 Money, StageVariables->RectoSigmo_Detection,
                                 Cost->Sigmoidoscopy, Cost->Sigmoidoscopy_Polyp,
                                 Cost->Colonoscopy_Perforation,
                                 Location->RectoSigmoDetection, *risc,
                                 RectoSigmoReachMatrix, *flag, &PolypFlag,
                                 &AdvPolypFlag, &CancerFlag);
                      if (AdvPolypFlag != 0.0) {
                        /*  */
                        Last->AdvPolyp[z] = *y;
                      } else {
                        if (PolypFlag != 0.0) {
                          Last->Polyp[z] = *y;
                        }
                      }

                      if ((AdvPolypFlag != 0.0) || (CancerFlag != 0.0)) {
                        /* m */
                        /*  StageVariables.Colo_Detection(7:10) = 1; % BM 29.5.2017 */
                        Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                        st.site = &w_emlrtRSI;
                        c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 +
                                      (real_T)q, Gender, &SD->f2.Polyp,
                                      &SD->f2.Ca, &SD->f2.Detected, Included,
                                      DeathCause, DeathYear, DiagnosedCancer,
                                      AdvancedPolypsRemoved, EarlyPolypsRemoved,
                                      Last, TumorRecord, PaymentType, Money,
                                      StageVariables, Cost, Location, *risc,
                                      ColoReachMatrix, MortalityMatrix,
                                      CostStage);

                        /*  StageVariables.Colo_Detection = Colo_Detection_bckup; */
                      }
                    }
                  }
                }
              } else if (flag->Schoen) {
                /*  for this validation we use the study by */
                /*  Schoen et al., NEJM 2012. */
                /*  patients aged 55-74 were 1:1 randomized to */
                /*  undergo two rectosigmoidoscopies. adherence for the first RS: 83.5%,  */
                /*  to the second RS: 54%. "In the intervention */
                /*  group, 83.5% of the participants underwent baseline screening and  */
                /*  54.0% underwent subsequent screening. A  */
                /*  total of 86.6% of participants underwent at least one flexible  */
                /*  sigmoidoscopic screening, and 50.9%  */
                /* if strcmp(SpecialText, 'RS-RCT') */
                /* SpecialText */
                /* fprintf('reached here 54 ') */
                if (isequal(*y, 1.0)) {
                  /*  for the first year, for the first patient we setup this validation */
                  if (isequal(1.0 + (real_T)z, 1.0)) {
                    /*  randomly one test year between 55 and 74 */
                    f = 0;
                    while (f < 50000) {
                      st.site = &v_emlrtRSI;
                      b_mtmp = b_rand() * 19.0 + 1.0;
                      mtmp = muDoubleScalarRound(b_mtmp);
                      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                        emlrtIntegerCheckR2012b(mtmp, &c_emlrtDCI, sp);
                      }

                      i4 = (int32_T)mtmp;
                      if (!((i4 >= 1) && (i4 <= 20))) {
                        emlrtDynamicBoundsCheckR2012b(i4, 1, 20, &c_emlrtBCI, sp);
                      }

                      Last->Included[f] = 55.0 + ((real_T)i4 - 1.0);
                      st.site = &u_emlrtRSI;
                      if (b_rand() < 0.83) {
                        /*  adherence to first screening */
                        Last->TestYear[f] = Last->Included[f];
                        st.site = &t_emlrtRSI;
                        if (b_rand() < 0.65) {
                          /* 0.54/0.83 % 54% of all individuals (more of the 83% screened individuals) */
                          /*  in the first 2 years */
                          /*  second screening after 3 */
                          /*  years, last 6y after 5y */
                          st.site = &s_emlrtRSI;
                          if (b_rand() < 0.25) {
                            Last->TestYear2[f] = Last->Included[f] + 3.0;
                          } else {
                            Last->TestYear2[f] = Last->Included[f] + 5.0;
                          }
                        } else {
                          st.site = &r_emlrtRSI;
                          if (b_rand() < 0.035) {
                            /*  only second screening */
                            st.site = &q_emlrtRSI;
                            if (b_rand() < 0.25) {
                              Last->TestYear2[f] = Last->Included[f] + 3.0;
                            } else {
                              Last->TestYear2[f] = Last->Included[f] + 5.0;
                            }
                          }
                        }
                      }

                      f++;
                      if (*emlrtBreakCheckR2012bFlagVar != 0) {
                        emlrtBreakCheckR2012b(sp);
                      }
                    }
                  }
                } else {
                  if (isequal(Last->Included[z], *y) && (!((*y -
                         Last->Colonoscopy[z] > 3.0) && isequal(Last->Cancer[z],
                         -100.0) && isequal(Last->Polyp[z], -100.0) && isequal
                        (Last->AdvPolyp[z], -100.0)))) {
                    /*  we need to check inclusion and */
                    /*  exclusion criteria at the year of */
                    /*  inclusion, first quarter */
                    /*  we exclude the patient by setting the years to -1 */
                    Last->TestYear[z] = -1.0;
                    Last->TestYear2[z] = -1.0;
                    Last->Included[z] = -1.0;
                  }

                  if ((isequal(Last->TestYear[z], *y) || isequal(Last->
                        TestYear2[z], *y)) && isequal(1.0 + (real_T)q, 1.0)) {
                    /*  now we do the screening */
                    Last->TestDone[z] = 1.0;

                    /*  for the per protocol analysis if necessary */
                    if (!flag->Mock) {
                      /*  special text would be: 'RS-RCT-Validation_Mock' */
                      Number->RectoSigmo[(int32_T)*y - 1]++;

                      /*  Number.Custom(y)     = Number.Custom(y) + 1; */
                      st.site = &p_emlrtRSI;
                      RectoSigmo(&st, 1.0 + (real_T)z, *y, &SD->f2.Polyp,
                                 SD->f2.Ca.Cancer, SD->f2.Ca.CancerLocation,
                                 Included, DeathCause, DeathYear, PaymentType,
                                 Money, StageVariables->RectoSigmo_Detection,
                                 Cost->Sigmoidoscopy, Cost->Sigmoidoscopy_Polyp,
                                 Cost->Colonoscopy_Perforation,
                                 Location->RectoSigmoDetection, *risc,
                                 RectoSigmoReachMatrix, *flag, &PolypFlag,
                                 &AdvPolypFlag, &CancerFlag);
                      if (AdvPolypFlag != 0.0) {
                        /*  */
                        Last->AdvPolyp[z] = *y;
                      } else {
                        if (PolypFlag > 0.0) {
                          Last->Polyp[z] = *y;
                        }
                      }

                      if ((PolypFlag > 1.0) || ((AdvPolypFlag != 0.0) ||
                           (CancerFlag != 0.0))) {
                        /*  we do follow up for a polyp >0.5 cm or a cancer */
                        /*  please note that for this */
                        /*  study PolypFlag will be */
                        /*  1.5 for polyps >0.5mm */
                        /*  StageVariables.Colo_Detection(7:10) = 1; % BM 29.5.2017 */
                        Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                        st.site = &o_emlrtRSI;
                        c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 +
                                      (real_T)q, Gender, &SD->f2.Polyp,
                                      &SD->f2.Ca, &SD->f2.Detected, Included,
                                      DeathCause, DeathYear, DiagnosedCancer,
                                      AdvancedPolypsRemoved, EarlyPolypsRemoved,
                                      Last, TumorRecord, PaymentType, Money,
                                      StageVariables, Cost, Location, *risc,
                                      ColoReachMatrix, MortalityMatrix,
                                      CostStage);

                        /*  StageVariables.Colo_Detection = Colo_Detection_bckup; */
                      }
                    }
                  }
                }
              } else if (flag->Segnan) {
                /*  Segnan */
                /*  for this validation we use the study by */
                /*  SEgnan et al., JNCI 2011. */
                /*  patients aged 55-64 were 1:1 randomized to */
                /*  undergo two rectosigmoidoscopy. adherence 58.35%  */
                if (isequal(*y, 1.0)) {
                  /*  for the first year, for the first patient we setup this validation */
                  if (isequal(1.0 + (real_T)z, 1.0)) {
                    /*  randomly one test year between 55 and 74 */
                    f = 0;
                    while (f < 50000) {
                      st.site = &n_emlrtRSI;
                      b_mtmp = b_rand() * 9.0 + 1.0;
                      mtmp = muDoubleScalarRound(b_mtmp);
                      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                        emlrtIntegerCheckR2012b(mtmp, &b_emlrtDCI, sp);
                      }

                      i4 = (int32_T)mtmp;
                      if (!((i4 >= 1) && (i4 <= 10))) {
                        emlrtDynamicBoundsCheckR2012b(i4, 1, 10, &b_emlrtBCI, sp);
                      }

                      Last->Included[f] = 55.0 + ((real_T)i4 - 1.0);
                      st.site = &m_emlrtRSI;
                      if (b_rand() < 0.583) {
                        /*  adherence to screening */
                        Last->TestYear[f] = Last->Included[f];
                      }

                      f++;
                      if (*emlrtBreakCheckR2012bFlagVar != 0) {
                        emlrtBreakCheckR2012b(sp);
                      }
                    }
                  }
                } else {
                  if (isequal(Last->Included[z], *y) && (!((*y -
                         Last->Colonoscopy[z] > 2.0) && isequal(Last->Cancer[z],
                         -100.0)))) {
                    /*  we need to check inclusion and */
                    /*  exclusion criteria at the year of */
                    /*  inclusion, first quarter */
                    /*  we exclude the patient by setting the years to -1 */
                    Last->TestYear[z] = -1.0;
                    Last->TestYear2[z] = -1.0;
                    Last->Included[z] = -1.0;
                  }

                  if (isequal(Last->TestYear[z], *y) && isequal(1.0 + (real_T)q,
                       1.0)) {
                    /*  now we do the screening */
                    Last->TestDone[z] = 1.0;

                    /*  for the per protocol analysis if necessary */
                    if (!flag->Mock) {
                      /*  special text would be: 'RS-RCT-Validation_Mock' */
                      Number->RectoSigmo[(int32_T)*y - 1]++;

                      /*  Number.Custom(y)     = Number.Custom(y) + 1; */
                      st.site = &l_emlrtRSI;
                      RectoSigmo(&st, 1.0 + (real_T)z, *y, &SD->f2.Polyp,
                                 SD->f2.Ca.Cancer, SD->f2.Ca.CancerLocation,
                                 Included, DeathCause, DeathYear, PaymentType,
                                 Money, StageVariables->RectoSigmo_Detection,
                                 Cost->Sigmoidoscopy, Cost->Sigmoidoscopy_Polyp,
                                 Cost->Colonoscopy_Perforation,
                                 Location->RectoSigmoDetection, *risc,
                                 RectoSigmoReachMatrix, *flag, &PolypFlag,
                                 &AdvPolypFlag, &CancerFlag);
                      if (AdvPolypFlag != 0.0) {
                        /*  */
                        Last->AdvPolyp[z] = *y;
                      } else {
                        if (PolypFlag > 0.0) {
                          Last->Polyp[z] = *y;
                        }
                      }

                      if ((PolypFlag > 1.0) || ((AdvPolypFlag != 0.0) ||
                           (CancerFlag != 0.0))) {
                        /*  we do follow up for a polyp >0.5 cm or a cancer */
                        /*  please note that for this */
                        /*  study PolypFlag will be */
                        /*  1.5 for polyps >0.5mm */
                        /*  StageVariables.Colo_Detection(7:10) = 1; % BM 29.5.2016 */
                        Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                        st.site = &k_emlrtRSI;
                        c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 +
                                      (real_T)q, Gender, &SD->f2.Polyp,
                                      &SD->f2.Ca, &SD->f2.Detected, Included,
                                      DeathCause, DeathYear, DiagnosedCancer,
                                      AdvancedPolypsRemoved, EarlyPolypsRemoved,
                                      Last, TumorRecord, PaymentType, Money,
                                      StageVariables, Cost, Location, *risc,
                                      ColoReachMatrix, MortalityMatrix,
                                      CostStage);

                        /*  StageVariables.Colo_Detection = Colo_Detection_bckup; */
                      }
                    }
                  }
                }
              } else {
                if (flag->Holme) {
                  /*  This uses the Norwegian Holme trial (JAMA 2014) for validation  */
                  /*  it includes patients 50-64 years of age. 63% */
                  /*  screening adherence. We model the intention to */
                  /*  screen analysis of the subgroup with */
                  /*  rectosigmoidoscopy only. */
                  if (isequal(*y, 1.0)) {
                    if (isequal(1.0 + (real_T)z, 1.0)) {
                      /*  randomly one test year between 55 and 64 */
                      f = 0;
                      while (f < 50000) {
                        st.site = &j_emlrtRSI;
                        b_mtmp = b_rand() * 14.0 + 1.0;
                        mtmp = muDoubleScalarRound(b_mtmp);
                        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
                          emlrtIntegerCheckR2012b(mtmp, &emlrtDCI, sp);
                        }

                        i4 = (int32_T)mtmp;
                        if (!((i4 >= 1) && (i4 <= 15))) {
                          emlrtDynamicBoundsCheckR2012b(i4, 1, 15, &emlrtBCI, sp);
                        }

                        Last->Included[f] = 51.0 + ((real_T)i4 - 1.0);
                        st.site = &i_emlrtRSI;
                        if (b_rand() < 0.651) {
                          /*  adherence to screening */
                          Last->TestYear[f] = Last->Included[f];
                        }

                        f++;
                        if (*emlrtBreakCheckR2012bFlagVar != 0) {
                          emlrtBreakCheckR2012b(sp);
                        }
                      }
                    }
                  } else {
                    if (isequal(Last->TestYear[z], *y) && (!isequal
                         (Last->TestDone[z], 1.0)) && isequal(Last->Cancer[z],
                         -100.0)) {
                      /*  we need to check inclusion and */
                      /*  exclusion criteria - only */
                      /*  patients with previous ca will be */
                      /*  excluded */
                      Last->TestDone[z] = 1.0;
                      if (!flag->Mock) {
                        Number->RectoSigmo[(int32_T)*y - 1]++;

                        /*  Number.Custom(y)     = Number.Custom(y) + 1; */
                        st.site = &h_emlrtRSI;
                        RectoSigmo(&st, 1.0 + (real_T)z, *y, &SD->f2.Polyp,
                                   SD->f2.Ca.Cancer, SD->f2.Ca.CancerLocation,
                                   Included, DeathCause, DeathYear, PaymentType,
                                   Money, StageVariables->RectoSigmo_Detection,
                                   Cost->Sigmoidoscopy,
                                   Cost->Sigmoidoscopy_Polyp,
                                   Cost->Colonoscopy_Perforation,
                                   Location->RectoSigmoDetection, *risc,
                                   RectoSigmoReachMatrix, *flag, &PolypFlag,
                                   &AdvPolypFlag, &CancerFlag);
                        if (AdvPolypFlag != 0.0) {
                          /*  */
                          Last->AdvPolyp[z] = *y;
                        } else {
                          if (PolypFlag != 0.0) {
                            Last->Polyp[z] = *y;
                          }
                        }

                        if ((PolypFlag != 0.0) || ((AdvPolypFlag != 0.0) ||
                             (CancerFlag != 0.0))) {
                          /*  follow up for all lesions here  */
                          /*  StageVariables.Colo_Detection(7:10) = 1; % BM 29.5.2016 */
                          Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                          st.site = &g_emlrtRSI;
                          c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 +
                                        (real_T)q, Gender, &SD->f2.Polyp,
                                        &SD->f2.Ca, &SD->f2.Detected, Included,
                                        DeathCause, DeathYear, DiagnosedCancer,
                                        AdvancedPolypsRemoved,
                                        EarlyPolypsRemoved, Last, TumorRecord,
                                        PaymentType, Money, StageVariables, Cost,
                                        Location, *risc, ColoReachMatrix,
                                        MortalityMatrix, CostStage);

                          /*  StageVariables.Colo_Detection = Colo_Detection_bckup; */
                        }
                      }
                    }
                  }
                }
              }

              if (flag->perfect) {
                /*  we do analysis, examining a perfect screening */
                /*  intervention once */
                if (isequal(*y, 66.0)) {
                  /*  we initialize the polyps cells */
                  /*  we initialize the field for keeping track of years */
                  for (i4 = 0; i4 < 2550000; i4++) {
                    SD->f2.Polyp.Polyps[i4] = 0.0;
                    SD->f2.Polyp.PolypYear[i4] = 0.0;
                    SD->f2.Polyp.PolypLocation[i4] = 0.0;
                    SD->f2.Polyp.AdvProgression[i4] = 0.0;
                    SD->f2.Polyp.EarlyProgression[i4] = 0.0;
                  }

                  /*  we initialize the cancer cells */
                  /*  we initialize the field for keeping track of years */
                  for (i4 = 0; i4 < 1250000; i4++) {
                    SD->f2.Ca.Cancer[i4] = 0.0;
                    SD->f2.Ca.CancerYear[i4] = 0.0;
                    SD->f2.Ca.CancerLocation[i4] = 0.0;
                    SD->f2.Ca.TimeStage_I[i4] = 0.0;
                    SD->f2.Ca.TimeStage_II[i4] = 0.0;
                    SD->f2.Ca.TimeStage_III[i4] = 0.0;
                    SD->f2.Ca.SympTime[i4] = 0.0;
                    SD->f2.Ca.SympStage[i4] = 0.0;
                    SD->f2.Ca.DwellTime[i4] = 0.0;
                  }

                  /*  this cancers are detected, patient might die */
                  /*  year this cancer had beed diagnosed */
                  for (i4 = 0; i4 < 2500000; i4++) {
                    SD->f2.Detected.Cancer[i4] = 0.0;
                    SD->f2.Detected.CancerYear[i4] = 0.0;
                    SD->f2.Detected.CancerLocation[i4] = 0.0;
                    SD->f2.Detected.MortTime[i4] = 0.0;
                  }

                  for (i4 = 0; i4 < 500000; i4++) {
                    TumorRecord->Stage[i4] = 0.0;
                    TumorRecord->Location[i4] = 0.0;
                    TumorRecord->Sojourn[i4] = 0.0;
                    TumorRecord->DwellTime[i4] = 0.0;
                    TumorRecord->Gender[i4] = 0.0;
                    TumorRecord->Detection[i4] = 0.0;
                    TumorRecord->PatientNumber[i4] = 0.0;
                  }

                  /*  RS ONLY !!!!!! */
                }
              } else if (flag->Kolo1) {
                if (isequal(ScreeningTest[21], *y)) {
                  Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                  st.site = &f_emlrtRSI;
                  c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 + (real_T)q,
                                Gender, &SD->f2.Polyp, &SD->f2.Ca,
                                &SD->f2.Detected, Included, DeathCause,
                                DeathYear, DiagnosedCancer,
                                AdvancedPolypsRemoved, EarlyPolypsRemoved, Last,
                                TumorRecord, PaymentType, Money, StageVariables,
                                Cost, Location, *risc, ColoReachMatrix,
                                MortalityMatrix, CostStage);
                }
              } else if (flag->Kolo2) {
                if (isequal(ScreeningTest[21], *y)) {
                  Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                  st.site = &e_emlrtRSI;
                  c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 + (real_T)q,
                                Gender, &SD->f2.Polyp, &SD->f2.Ca,
                                &SD->f2.Detected, Included, DeathCause,
                                DeathYear, DiagnosedCancer,
                                AdvancedPolypsRemoved, EarlyPolypsRemoved, Last,
                                TumorRecord, PaymentType, Money, StageVariables,
                                Cost, Location, *risc, ColoReachMatrix,
                                MortalityMatrix, CostStage);
                }

                if (isequal(ScreeningTest[28], *y)) {
                  Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                  st.site = &d_emlrtRSI;
                  c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 + (real_T)q,
                                Gender, &SD->f2.Polyp, &SD->f2.Ca,
                                &SD->f2.Detected, Included, DeathCause,
                                DeathYear, DiagnosedCancer,
                                AdvancedPolypsRemoved, EarlyPolypsRemoved, Last,
                                TumorRecord, PaymentType, Money, StageVariables,
                                Cost, Location, *risc, ColoReachMatrix,
                                MortalityMatrix, CostStage);
                }
              } else if (flag->Kolo3) {
                if (isequal(ScreeningTest[21], *y)) {
                  Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                  st.site = &c_emlrtRSI;
                  c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 + (real_T)q,
                                Gender, &SD->f2.Polyp, &SD->f2.Ca,
                                &SD->f2.Detected, Included, DeathCause,
                                DeathYear, DiagnosedCancer,
                                AdvancedPolypsRemoved, EarlyPolypsRemoved, Last,
                                TumorRecord, PaymentType, Money, StageVariables,
                                Cost, Location, *risc, ColoReachMatrix,
                                MortalityMatrix, CostStage);
                }

                if (isequal(ScreeningTest[28], *y)) {
                  Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                  st.site = &b_emlrtRSI;
                  c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 + (real_T)q,
                                Gender, &SD->f2.Polyp, &SD->f2.Ca,
                                &SD->f2.Detected, Included, DeathCause,
                                DeathYear, DiagnosedCancer,
                                AdvancedPolypsRemoved, EarlyPolypsRemoved, Last,
                                TumorRecord, PaymentType, Money, StageVariables,
                                Cost, Location, *risc, ColoReachMatrix,
                                MortalityMatrix, CostStage);
                }

                if (isequal(ScreeningTest[35], *y)) {
                  Number->Screening_Colonoscopy[(int32_T)*y - 1]++;
                  st.site = &emlrtRSI;
                  c_Colonoscopy(SD, &st, 1.0 + (real_T)z, *y, 1.0 + (real_T)q,
                                Gender, &SD->f2.Polyp, &SD->f2.Ca,
                                &SD->f2.Detected, Included, DeathCause,
                                DeathYear, DiagnosedCancer,
                                AdvancedPolypsRemoved, EarlyPolypsRemoved, Last,
                                TumorRecord, PaymentType, Money, StageVariables,
                                Cost, Location, *risc, ColoReachMatrix,
                                MortalityMatrix, CostStage);
                }
              } else {
                if (flag->Po55) {
                  if (isequal(*y, 56.0)) {
                    b_mtmp = SD->f2.Polyp.Polyps[z];
                    for (ii = 0; ii < 50; ii++) {
                      if (SD->f2.Polyp.Polyps[z + 50000 * (ii + 1)] > b_mtmp) {
                        b_mtmp = SD->f2.Polyp.Polyps[z + 50000 * (ii + 1)];
                      }
                    }

                    mtmp = SD->f2.Ca.Cancer[z];
                    for (ii = 0; ii < 24; ii++) {
                      if (SD->f2.Ca.Cancer[z + 50000 * (ii + 1)] > mtmp) {
                        mtmp = SD->f2.Ca.Cancer[z + 50000 * (ii + 1)];
                      }
                    }

                    if ((b_mtmp > 0.0) || (mtmp > 0.0) || ((Last->Polyp[z] >
                          -100.0) || (Last->Cancer[z] > -100.0))) {
                      Last->TestDone[z] = 1.0;
                    } else {
                      Last->TestDone[z] = 2.0;
                    }

                    if (flag->treated) {
                      for (i4 = 0; i4 < 51; i4++) {
                        SD->f2.Polyp.Polyps[z + 50000 * i4] = 0.0;
                        SD->f2.Polyp.PolypYear[z + 50000 * i4] = 0.0;
                        SD->f2.Polyp.PolypLocation[z + 50000 * i4] = 0.0;
                        SD->f2.Polyp.AdvProgression[z + 50000 * i4] = 0.0;
                        SD->f2.Polyp.EarlyProgression[z + 50000 * i4] = 0.0;
                      }

                      for (i4 = 0; i4 < 25; i4++) {
                        SD->f2.Ca.Cancer[z + 50000 * i4] = 0.0;
                        SD->f2.Ca.CancerYear[z + 50000 * i4] = 0.0;
                        SD->f2.Ca.CancerLocation[z + 50000 * i4] = 0.0;
                        SD->f2.Ca.TimeStage_I[z + 50000 * i4] = 0.0;
                        SD->f2.Ca.TimeStage_II[z + 50000 * i4] = 0.0;
                        SD->f2.Ca.TimeStage_III[z + 50000 * i4] = 0.0;
                        SD->f2.Ca.SympTime[z + 50000 * i4] = 0.0;
                        SD->f2.Ca.SympStage[z + 50000 * i4] = 0.0;
                      }

                      /*  this cancers are detected, patient might die */
                      for (i4 = 0; i4 < 50; i4++) {
                        SD->f2.Detected.Cancer[z + 50000 * i4] = 0.0;
                        SD->f2.Detected.CancerYear[z + 50000 * i4] = 0.0;
                        SD->f2.Detected.CancerLocation[z + 50000 * i4] = 0.0;
                        SD->f2.Detected.MortTime[z + 50000 * i4] = 0.0;
                      }
                    }
                  }

                  /*  elseif (isequal(SpecialText(1:16), 'Po+-55nontreated')) */
                }
              }
            }

            /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
            /*     summarizing polyps             % */
            /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
            /*  before a polyp can be detected and removed for screening we */
            /*  summarize the prevalence of all polyps and cancers */
            /* try */
            idx = 0;
            for (i4 = 0; i4 < 2; i4++) {
              ii_size[i4] = 1;
            }

            ii = 1;
            exitg5 = false;
            while ((!exitg5) && (ii < 52)) {
              if (SD->f2.Polyp.Polyps[z + 50000 * (ii - 1)] != 0.0) {
                idx = 1;
                exitg5 = true;
              } else {
                ii++;
              }
            }

            if (idx == 0) {
              ii_size[1] = 0;
            }

            if (!(ii_size[1] == 0)) {
              b_mtmp = SD->f2.Polyp.Polyps[z];
              for (ii = 0; ii < 50; ii++) {
                if (SD->f2.Polyp.Polyps[z + 50000 * (ii + 1)] > b_mtmp) {
                  b_mtmp = SD->f2.Polyp.Polyps[z + 50000 * (ii + 1)];
                }
              }

              MaxPolyps[((int32_T)*y + 100 * z) - 1] = b_mtmp;
              idx = 0;
              ii = 1;
              exitg4 = false;
              while ((!exitg4) && (ii < 52)) {
                guard3 = false;
                if (SD->f2.Polyp.Polyps[z + 50000 * (ii - 1)] != 0.0) {
                  idx++;
                  if (idx >= 51) {
                    exitg4 = true;
                  } else {
                    guard3 = true;
                  }
                } else {
                  guard3 = true;
                }

                if (guard3) {
                  ii++;
                }
              }

              if (1 > idx) {
                NumPolyps[((int32_T)*y + 100 * z) - 1] = 0.0;
              } else {
                NumPolyps[((int32_T)*y + 100 * z) - 1] = idx;
              }

              /*                      if ~isempty(find(Polyp.PolypLocation(z, :)<4, 1, 'first')) */
              /*                          MaxPolypsRight(y,z)  = max(Polyp.Polyps(z, (Polyp.PolypLocation(z, :)<4))); */
              /*                      end */
              /*                      if ~isempty(find(and(Polyp.PolypLocation(z, :)>3, Polyp.PolypLocation(z,:)<13), 1, 'first')) */
              /*                          MaxPolypsRest(y,z)   = max(Polyp.Polyps(z, and(Polyp.PolypLocation(z, :)>3, Polyp.PolypLocation(z,:)<13))); */
              /*                      end */
              /*                      if ~isempty(find(Polyp.PolypLocation(z, :)==13, 1, 'first')) */
              /*                          MaxPolypsRectum(y,z) = max(Polyp.Polyps(z, (Polyp.PolypLocation(z, :)==13))); */
              /*                      end */
              f = 0;
              while (f < 6) {
                for (i4 = 0; i4 < 51; i4++) {
                  c_x[i4] = (SD->f2.Polyp.Polyps[z + 50000 * i4] == 1.0 +
                             (real_T)f);
                }

                idx = 0;
                ii = 1;
                exitg3 = false;
                while ((!exitg3) && (ii < 52)) {
                  guard2 = false;
                  if (c_x[ii - 1]) {
                    idx++;
                    if (idx >= 51) {
                      exitg3 = true;
                    } else {
                      guard2 = true;
                    }
                  } else {
                    guard2 = true;
                  }

                  if (guard2) {
                    ii++;
                  }
                }

                if (1 > idx) {
                  i12 = 0;
                } else {
                  i12 = idx;
                }

                AllPolyps[f + 6 * ((int32_T)*y - 1)] += (real_T)i12;
                f++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(sp);
                }
              }
            }
          }
        }

        /*                  catch Exception */
        /*                      rethrow(Exception) */
        /*                  end */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /*     summarizing cancer             % */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        q++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      idx = 0;
      for (i4 = 0; i4 < 2; i4++) {
        ii_size[i4] = 1;
      }

      ii = 1;
      exitg2 = false;
      while ((!exitg2) && (ii < 26)) {
        if (SD->f2.Ca.Cancer[z + 50000 * (ii - 1)] != 0.0) {
          idx = 1;
          exitg2 = true;
        } else {
          ii++;
        }
      }

      if (idx == 0) {
        ii_size[1] = 0;
      }

      if (!(ii_size[1] == 0)) {
        b_mtmp = SD->f2.Ca.Cancer[z];
        for (ii = 0; ii < 24; ii++) {
          if (SD->f2.Ca.Cancer[z + 50000 * (ii + 1)] > b_mtmp) {
            b_mtmp = SD->f2.Ca.Cancer[z + 50000 * (ii + 1)];
          }
        }

        MaxCancer[((int32_T)*y + 100 * z) - 1] = b_mtmp;
        idx = 0;
        ii = 1;
        exitg1 = false;
        while ((!exitg1) && (ii < 26)) {
          guard1 = false;
          if (SD->f2.Ca.Cancer[z + 50000 * (ii - 1)] != 0.0) {
            idx++;
            if (idx >= 25) {
              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            ii++;
          }
        }

        if (1 > idx) {
          NumCancer[((int32_T)*y + 100 * z) - 1] = 0.0;
        } else {
          NumCancer[((int32_T)*y + 100 * z) - 1] = idx;
        }
      }

      z++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  we summarize the whole cohort */
    for (i4 = 0; i4 < 50000; i4++) {
      YearIncluded[((int32_T)*y + 100 * i4) - 1] = Included[i4];
      YearAlive[((int32_T)*y + 100 * i4) - 1] = Alive[i4];
    }

    /* display(sprintf('calculating results for year: %d', y)) */
    st.site = &gd_emlrtRSI;
    display(&st, b_sprintf(&st, emlrt_marshallOut(&st, cv2), b_emlrt_marshallOut
             (*y), &emlrtMCI), &b_emlrtMCI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&r1);
  emxFree_real_T(&r0);

  /*  Death  = zeros(1,4); */
  /*  AliveX = zeros(1,4); */
  /*  for f=1:n */
  /*      if isequal(length(find(Detected.Cancer(f,:))), 1) */
  /*          Stage = Detected.Cancer(f, 1)-6; */
  /*          DiagnoseTime = Detected.CancerYear(f, 1); */
  /*          if DeathYear(f) - DiagnoseTime <= 5 */
  /*              if DeathCause(f) == 2 */
  /*                  Death(Stage) = Death(Stage)+1; */
  /*              end */
  /*          else */
  /*              AliveX(Stage) = AliveX(Stage)+1; */
  /*          end */
  /*      end */
  /*  end */
  /*  RelMort = zeros(1,4); */
  /*  RelMort = Death./(AliveX+Death)*100 */
  f = 0;
  while (f < 50000) {
    if (Alive[f]) {
      NaturalDeathYear[f] = 100.0;
    }

    f++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i4 = 0; i4 < 100; i4++) {
    Money->AllCost[i4] = ((Money->Treatment[i4] + Money->Screening[i4]) +
                          Money->FollowUp[i4]) + Money->Other[i4];
    Money->AllCostFuture[i4] = ((Money->FutureTreatment[i4] + Money->
      Screening[i4]) + Money->FollowUp[i4]) + Money->Other[i4];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (NumberCrunching_50000.c) */
