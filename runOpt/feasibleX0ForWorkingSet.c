/*
 * feasibleX0ForWorkingSet.c
 *
 * Code generation for function 'feasibleX0ForWorkingSet'
 *
 */

/* Include files */
#include "feasibleX0ForWorkingSet.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "maxConstraintViolation.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xgemm.h"
#include "xgeqrf.h"
#include "xtrsm.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qg_emlrtRSI = { 1,  /* lineNo */
  "computeTallQ",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\computeTallQ.p"/* pathName */
};

static emlrtRSInfo xg_emlrtRSI = { 1,  /* lineNo */
  "feasibleX0ForWorkingSet",           /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\feasibleX0ForWorkingSet.p"/* pathName */
};

static emlrtBCInfo gc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "feasibleX0ForWorkingSet",           /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\feasibleX0ForWorkingSet.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "feasibleX0ForWorkingSet",           /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\feasibleX0ForWorkingSet.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
boolean_T feasibleX0ForWorkingSet(const emlrtStack *sp, real_T workspace[153],
  real_T xCurrent[9], e_struct_T *workingset, i_struct_T *qrmanager)
{
  boolean_T nonDegenerateWset;
  int32_T mWConstr;
  int32_T nVar;
  int32_T ix;
  int32_T b_tmp;
  int32_T iy;
  int32_T iac;
  real_T dv[153];
  real_T c;
  int32_T b;
  int32_T ia;
  int32_T exitg1;
  real_T constrViolation_basicX;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  mWConstr = workingset->nActiveConstr;
  nVar = workingset->nVar - 1;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    st.site = &xg_emlrtRSI;
    if ((1 <= workingset->nActiveConstr) && (workingset->nActiveConstr >
         2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (ix = 0; ix < mWConstr; ix++) {
      b_tmp = ix + 1;
      if ((b_tmp < 1) || (b_tmp > 17)) {
        emlrtDynamicBoundsCheckR2012b(b_tmp, 1, 17, &gc_emlrtBCI, sp);
      }

      iy = ix + 1;
      if ((iy < 1) || (iy > 17)) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, 17, &hc_emlrtBCI, sp);
      }

      workspace[iy - 1] = workingset->bwset[b_tmp - 1];
      workspace[ix + 17] = workingset->bwset[ix];
    }

    st.site = &xg_emlrtRSI;
    b_st.site = &bd_emlrtRSI;
    if (workingset->nActiveConstr != 0) {
      iy = 0;
      b_tmp = 9 * (workingset->nActiveConstr - 1) + 1;
      c_st.site = &cd_emlrtRSI;
      if ((1 <= b_tmp) && (b_tmp > 2147483638)) {
        d_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (iac = 1; iac <= b_tmp; iac += 9) {
        ix = 0;
        c = 0.0;
        b = iac + nVar;
        c_st.site = &dd_emlrtRSI;
        if ((iac <= b) && (b > 2147483646)) {
          d_st.site = &d_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (ia = iac; ia <= b; ia++) {
          c += workingset->ATwset[ia - 1] * xCurrent[ix];
          ix++;
        }

        workspace[iy] += -c;
        iy++;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      st.site = &xg_emlrtRSI;
      if ((1 <= workingset->nVar) && (workingset->nVar > 2147483646)) {
        b_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (iy = 0; iy <= nVar; iy++) {
        st.site = &xg_emlrtRSI;
        if ((1 <= mWConstr) && (mWConstr > 2147483646)) {
          b_st.site = &d_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (ix = 0; ix < mWConstr; ix++) {
          b_tmp = ix + 1;
          if ((b_tmp < 1) || (b_tmp > 17)) {
            emlrtDynamicBoundsCheckR2012b(b_tmp, 1, 17, &gc_emlrtBCI, sp);
          }

          qrmanager->QR[(b_tmp + 17 * iy) - 1] = workingset->ATwset[iy + 9 *
            (b_tmp - 1)];
        }
      }

      st.site = &xg_emlrtRSI;
      b_tmp = workingset->nVar;
      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      b_st.site = &bg_emlrtRSI;
      if ((1 <= workingset->nVar) && (workingset->nVar > 2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (ix = 0; ix < b_tmp; ix++) {
        qrmanager->jpvt[ix] = ix + 1;
      }

      qrmanager->minRowCol = muIntScalarMin_sint32(workingset->nActiveConstr,
        workingset->nVar);
      b_st.site = &bg_emlrtRSI;
      xgeqrf(&b_st, qrmanager->QR, workingset->nActiveConstr, workingset->nVar,
             qrmanager->tau);
      st.site = &xg_emlrtRSI;
      b_st.site = &cf_emlrtRSI;
      computeQ_(&b_st, qrmanager, workingset->nActiveConstr);
      memcpy(&dv[0], &workspace[0], 153U * sizeof(real_T));
      st.site = &xg_emlrtRSI;
      xgemm(workingset->nVar, workingset->nActiveConstr, qrmanager->Q, dv,
            workspace);
      st.site = &xg_emlrtRSI;
      xtrsm(workingset->nVar, qrmanager->QR, workspace);
    } else {
      st.site = &xg_emlrtRSI;
      factorQR(&st, qrmanager, workingset->ATwset, workingset->nVar,
               workingset->nActiveConstr);
      st.site = &xg_emlrtRSI;
      b_st.site = &qg_emlrtRSI;
      computeQ_(&b_st, qrmanager, qrmanager->minRowCol);
      st.site = &xg_emlrtRSI;
      b_xtrsm(workingset->nActiveConstr, qrmanager->QR, workspace);
      memcpy(&dv[0], &workspace[0], 153U * sizeof(real_T));
      st.site = &xg_emlrtRSI;
      b_xgemm(workingset->nVar, workingset->nActiveConstr, qrmanager->Q, dv,
              workspace);
    }

    st.site = &xg_emlrtRSI;
    if ((1 <= workingset->nVar) && (workingset->nVar > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    ix = 0;
    do {
      exitg1 = 0;
      if (ix <= nVar) {
        if (muDoubleScalarIsInf(workspace[ix]) || muDoubleScalarIsNaN
            (workspace[ix])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          c = workspace[ix + 17];
          if (muDoubleScalarIsInf(c) || muDoubleScalarIsNaN(c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            ix++;
          }
        }
      } else {
        for (iy = 0; iy <= nVar; iy++) {
          workspace[iy] += xCurrent[iy];
        }

        st.site = &xg_emlrtRSI;
        c = maxConstraintViolation(&st, workingset, workspace);
        st.site = &xg_emlrtRSI;
        constrViolation_basicX = b_maxConstraintViolation(&st, workingset,
          workspace);
        if ((c <= 2.2204460492503131E-16) || (c < constrViolation_basicX)) {
          st.site = &xg_emlrtRSI;
          b_st.site = &fd_emlrtRSI;
          c_st.site = &gd_emlrtRSI;
          if ((1 <= nVar + 1) && (nVar + 1 > 2147483646)) {
            d_st.site = &d_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          if (0 <= nVar) {
            memcpy(&xCurrent[0], &workspace[0], (nVar + 1) * sizeof(real_T));
          }
        } else {
          st.site = &xg_emlrtRSI;
          b_st.site = &fd_emlrtRSI;
          c_st.site = &gd_emlrtRSI;
          if ((1 <= nVar + 1) && (nVar + 1 > 2147483646)) {
            d_st.site = &d_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          if (0 <= nVar) {
            memcpy(&xCurrent[0], &workspace[17], (nVar + 1) * sizeof(real_T));
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

/* End of code generation (feasibleX0ForWorkingSet.c) */
