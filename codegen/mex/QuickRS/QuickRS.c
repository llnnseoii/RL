/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * QuickRS.c
 *
 * Code generation for function 'QuickRS'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "QuickRS.h"
#include "QuickRS_emxutil.h"
#include "QuickRS_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 22, 88, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m" };

static emlrtDCInfo emlrtDCI = { 28, 28, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 4 };

static emlrtDCInfo b_emlrtDCI = { 28, 28, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 1 };

static emlrtRTEInfo c_emlrtRTEI = { 32, 1, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m" };

static emlrtDCInfo c_emlrtDCI = { 36, 70, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 1 };

static emlrtBCInfo emlrtBCI = { 1, 100, 36, 70, "PatientsAtRisk", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtDCInfo d_emlrtDCI = { 36, 13, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 1 };

static emlrtBCInfo b_emlrtBCI = { 1, 100, 36, 13, "PatientsAtRisk", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtECInfo emlrtECI = { -1, 36, 13, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m" };

static emlrtRTEInfo d_emlrtRTEI = { 37, 13, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m" };

static emlrtDCInfo e_emlrtDCI = { 38, 42, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 1 };

static emlrtBCInfo c_emlrtBCI = { 1, 100, 38, 42, "PatientNumber", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtDCInfo f_emlrtDCI = { 41, 60, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 1 };

static emlrtBCInfo d_emlrtBCI = { 1, 70, 41, 60, "Tumor", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtDCInfo g_emlrtDCI = { 41, 27, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 1 };

static emlrtBCInfo e_emlrtBCI = { 1, 70, 41, 27, "Tumor", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtECInfo b_emlrtECI = { -1, 41, 21, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m" };

static emlrtBCInfo f_emlrtBCI = { 1, 100000, 51, 28, "SurvivalMatrix", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtDCInfo h_emlrtDCI = { 51, 37, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 1 };

static emlrtBCInfo g_emlrtBCI = { 1, 100, 51, 37, "SurvivalMatrix", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtBCInfo h_emlrtBCI = { 1, 100000, 33, 16, "Included", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 50, 13, "Survival", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtDCInfo i_emlrtDCI = { 41, 41, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 1 };

static emlrtBCInfo j_emlrtBCI = { 1, 13, 41, 41, "Tumor", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtBCInfo k_emlrtBCI = { 1, 100, 45, 57, "CancerMortality", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtDCInfo j_emlrtDCI = { 45, 57, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 1 };

static emlrtBCInfo l_emlrtBCI = { 1, 100, 45, 25, "CancerMortality", "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 0 };

static emlrtDCInfo k_emlrtDCI = { 45, 25, "QuickRS",
  "U:\\CMOST\\CMOST_01_August_2016\\QuickRS.m", 1 };

/* Function Definitions */
void QuickRS(const emlrtStack *sp, const real_T DeathYear[100000], const real_T
             Included[100000], const real_T PatientNumber[1000000], const real_T
             Location[1000000], const real_T DeathCause[100000], real_T n,
             real_T Tumor[910], real_T *Counter, real_T SurvivalMatrix[10000000],
             real_T CancerMortality[100], emxArray_real_T *Survival, real_T
             PatientsAtRisk[100])
{
  boolean_T b0;
  int32_T i0;
  real_T d0;
  int32_T idx;
  int32_T z;
  real_T TestYear;
  boolean_T p;
  boolean_T b_p;
  real_T PatientsAtRisk_data[100];
  int32_T y;
  real_T b_y;
  boolean_T x[10000];
  int16_T ii_data[1];
  int8_T ii_size[2];
  int32_T ii;
  boolean_T exitg1;
  int16_T pos_data[1];
  real_T Location2_data[1];
  int32_T tmp_data[1];
  real_T b_tmp_data[1];
  int32_T iv0[2];
  int32_T b_Tumor[2];
  b0 = false;

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
  for (i0 = 0; i0 < 10000000; i0++) {
    SurvivalMatrix[i0] = 0.0;
  }

  for (i0 = 0; i0 < 100; i0++) {
    CancerMortality[i0] = 0.0;
  }

  for (i0 = 0; i0 < 100; i0++) {
    PatientsAtRisk[i0] = 0.0;
  }

  i0 = Survival->size[0] * Survival->size[1];
  Survival->size[0] = 1;
  if (!(n > 0.0)) {
    emlrtNonNegativeCheckR2012b(n, &emlrtDCI, sp);
  }

  if (n != (int32_T)muDoubleScalarFloor(n)) {
    emlrtIntegerCheckR2012b(n, &b_emlrtDCI, sp);
  }

  Survival->size[1] = (int32_T)n;
  emxEnsureCapacity(sp, (emxArray__common *)Survival, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  if (!(n > 0.0)) {
    emlrtNonNegativeCheckR2012b(n, &emlrtDCI, sp);
  }

  d0 = n;
  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &b_emlrtDCI, sp);
  }

  idx = (int32_T)d0;
  for (i0 = 0; i0 < idx; i0++) {
    Survival->data[i0] = 0.0;
  }

  for (i0 = 0; i0 < 910; i0++) {
    Tumor[i0] = 0.0;
  }

  *Counter = 1.0;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
    &c_emlrtRTEI, sp);
  z = 0;
  while (z <= (int32_T)n - 1) {
    if (!((z + 1 >= 1) && (z + 1 <= 100000))) {
      emlrtDynamicBoundsCheckR2012b(z + 1, 1, 100000, &h_emlrtBCI, sp);
    }

    TestYear = Included[z];
    if (DeathYear[z] > Included[z]) {
      /*  if the patient had been alive during the test period */
      p = false;
      b_p = true;
      if (!(Included[z] == -1.0)) {
        b_p = false;
      }

      if (!b_p) {
      } else {
        p = true;
      }

      if (!p) {
        /*  if the patient had not been excluded */
        d0 = (muDoubleScalarRound(DeathYear[z]) - Included[z]) + 1.0;
        if (1.0 > d0) {
          idx = 0;
        } else {
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &c_emlrtDCI, sp);
          }

          idx = (int32_T)d0;
          if (!((idx >= 1) && (idx <= 100))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 100, &emlrtBCI, sp);
          }
        }

        d0 = (muDoubleScalarRound(DeathYear[z]) - Included[z]) + 1.0;
        if (1.0 > d0) {
          i0 = 0;
        } else {
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &d_emlrtDCI, sp);
          }

          i0 = (int32_T)d0;
          if (!((i0 >= 1) && (i0 <= 100))) {
            emlrtDynamicBoundsCheckR2012b(i0, 1, 100, &b_emlrtBCI, sp);
          }
        }

        if (i0 != idx) {
          emlrtSizeEqCheck1DR2012b(i0, idx, &emlrtECI, sp);
        }

        for (i0 = 0; i0 < idx; i0++) {
          PatientsAtRisk_data[i0] = PatientsAtRisk[i0] + 1.0;
        }

        for (i0 = 0; i0 < idx; i0++) {
          PatientsAtRisk[i0] = PatientsAtRisk_data[i0];
        }

        emlrtForLoopVectorCheckR2012b(Included[z] - 1.0, 1.0, 100.0,
          mxDOUBLE_CLASS, (int32_T)(100.0 + (1.0 - (Included[z] - 1.0))),
          &d_emlrtRTEI, sp);
        y = 0;
        while (y <= (int32_T)(100.0 + (1.0 - (Included[z] - 1.0))) - 1) {
          b_y = (TestYear - 1.0) + (real_T)y;
          if (b_y != (int32_T)muDoubleScalarFloor(b_y)) {
            emlrtIntegerCheckR2012b(b_y, &e_emlrtDCI, sp);
          }

          i0 = (int32_T)b_y;
          if (!((i0 >= 1) && (i0 <= 100))) {
            emlrtDynamicBoundsCheckR2012b(i0, 1, 100, &c_emlrtBCI, sp);
          }

          for (i0 = 0; i0 < 10000; i0++) {
            x[i0] = (PatientNumber[((int32_T)b_y + 100 * i0) - 1] == 1.0 +
                     (real_T)z);
          }

          idx = 0;
          for (i0 = 0; i0 < 2; i0++) {
            ii_size[i0] = 1;
          }

          ii = 1;
          exitg1 = false;
          while ((!exitg1) && (ii < 10001)) {
            if (x[ii - 1]) {
              idx = 1;
              ii_data[0] = (int16_T)ii;
              exitg1 = true;
            } else {
              ii++;
            }
          }

          if (idx == 0) {
            ii_size[1] = 0;
          }

          idx = ii_size[1];
          for (i0 = 0; i0 < idx; i0++) {
            pos_data[i0] = ii_data[i0];
          }

          if (!(ii_size[1] == 0)) {
            for (i0 = 0; i0 < 1; i0++) {
              Location2_data[0] = Location[((int32_T)b_y + 100 * (pos_data[0] -
                1)) - 1];
            }

            d0 = (b_y - TestYear) + 2.0;
            if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
              emlrtIntegerCheckR2012b(d0, &g_emlrtDCI, sp);
            }

            i0 = (int32_T)d0;
            if (!((i0 >= 1) && (i0 <= 70))) {
              emlrtDynamicBoundsCheckR2012b(i0, 1, 70, &e_emlrtBCI, sp);
            }

            i0--;
            for (idx = 0; idx < 1; idx++) {
              d0 = Location2_data[0];
              if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
                emlrtIntegerCheckR2012b(d0, &i_emlrtDCI, sp);
              }

              ii = (int32_T)d0;
              if (!((ii >= 1) && (ii <= 13))) {
                emlrtDynamicBoundsCheckR2012b(ii, 1, 13, &j_emlrtBCI, sp);
              }

              tmp_data[0] = ii - 1;
            }

            d0 = (b_y - TestYear) + 2.0;
            if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
              emlrtIntegerCheckR2012b(d0, &f_emlrtDCI, sp);
            }

            ii = (int32_T)d0;
            if (!((ii >= 1) && (ii <= 70))) {
              emlrtDynamicBoundsCheckR2012b(ii, 1, 70, &d_emlrtBCI, sp);
            }

            for (idx = 0; idx < 1; idx++) {
              b_tmp_data[0] = Tumor[(ii + 70 * ((int32_T)Location2_data[0] - 1))
                - 1];
            }

            if (!b0) {
              iv0[0] = 1;
              iv0[1] = 1;
              b0 = true;
            }

            for (idx = 0; idx < 2; idx++) {
              b_Tumor[idx] = 1;
            }

            emlrtSubAssignSizeCheckR2012b(iv0, 2, b_Tumor, 2, &b_emlrtECI, sp);
            for (idx = 0; idx < 1; idx++) {
              Tumor[i0 + 70 * tmp_data[0]] = b_tmp_data[0] + 1.0;
            }
          }

          p = false;
          b_p = true;
          if (!(DeathYear[z] == b_y)) {
            b_p = false;
          }

          if (!b_p) {
          } else {
            p = true;
          }

          if (p) {
            p = false;
            b_p = true;
            if (!(DeathCause[z] == 2.0)) {
              b_p = false;
            }

            if (!b_p) {
            } else {
              p = true;
            }

            if (p) {
              /*  CRC specific mortality */
              d0 = (b_y - TestYear) + 2.0;
              if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
                emlrtIntegerCheckR2012b(d0, &j_emlrtDCI, sp);
              }

              i0 = (int32_T)d0;
              if (!((i0 >= 1) && (i0 <= 100))) {
                emlrtDynamicBoundsCheckR2012b(i0, 1, 100, &k_emlrtBCI, sp);
              }

              d0 = (b_y - TestYear) + 2.0;
              if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
                emlrtIntegerCheckR2012b(d0, &k_emlrtDCI, sp);
              }

              idx = (int32_T)d0;
              if (!((idx >= 1) && (idx <= 100))) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, 100, &l_emlrtBCI, sp);
              }

              CancerMortality[idx - 1] = CancerMortality[i0 - 1] + 1.0;
            }
          }

          y++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        i0 = Survival->size[1];
        idx = (int32_T)*Counter;
        if (!((idx >= 1) && (idx <= i0))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i0, &i_emlrtBCI, sp);
        }

        Survival->data[idx - 1] = DeathYear[z] - Included[z];
        d0 = muDoubleScalarRound(DeathYear[z]) - Included[z];
        if (1.0 > d0) {
          idx = 0;
        } else {
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &h_emlrtDCI, sp);
          }

          idx = (int32_T)d0;
          if (!((idx >= 1) && (idx <= 100))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 100, &g_emlrtBCI, sp);
          }
        }

        ii = (int32_T)*Counter;
        if (!((ii >= 1) && (ii <= 100000))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, 100000, &f_emlrtBCI, sp);
        }

        for (i0 = 0; i0 < idx; i0++) {
          SurvivalMatrix[(ii + 100000 * i0) - 1] = 1.0;
        }

        (*Counter)++;
      }

      /*      end */
    }

    z++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (QuickRS.c) */
