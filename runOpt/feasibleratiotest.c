/*
 * feasibleratiotest.c
 *
 * Code generation for function 'feasibleratiotest'
 *
 */

/* Include files */
#include "feasibleratiotest.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xgemv.h"
#include "xnrm2.h"

/* Variable Definitions */
static emlrtRSInfo li_emlrtRSI = { 1,  /* lineNo */
  "feasibleratiotest",                 /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\feasibleratiotest.p"/* pathName */
};

static emlrtBCInfo kd_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "feasibleratiotest",                 /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\feasibleratiotest.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void feasibleratiotest(const emlrtStack *sp, const real_T solution_xstar[9],
  const real_T solution_searchDir[9], real_T workspace[153], int32_T
  workingset_nVar, const real_T workingset_Aineq[9], real_T workingset_bineq,
  const real_T workingset_lb[9], const real_T workingset_ub[9], const int32_T
  workingset_indexLB[9], const int32_T workingset_indexUB[9], const int32_T
  workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const boolean_T
  workingset_isActiveConstr[17], const int32_T workingset_nWConstr[5], boolean_T
  isPhaseOne, real_T *alpha, boolean_T *newBlocking, int32_T *constrType,
  int32_T *constrIdx)
{
  int32_T totalUB;
  real_T denomTol;
  real_T phaseOneCorrectionX;
  real_T phaseOneCorrectionP;
  int32_T ix;
  int32_T idx;
  int32_T ia;
  real_T c;
  real_T ratio;
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
  totalUB = workingset_sizes[4];
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  st.site = &li_emlrtRSI;
  denomTol = 2.2204460492503131E-13 * xnrm2(&st, workingset_nVar,
    solution_searchDir);
  if (workingset_nWConstr[2] < 1) {
    st.site = &li_emlrtRSI;
    b_st.site = &fd_emlrtRSI;
    c_st.site = &gd_emlrtRSI;
    workspace[0] = workingset_bineq;
    st.site = &li_emlrtRSI;
    d_xgemv(&st, workingset_nVar, workingset_Aineq, solution_xstar, workspace);
    st.site = &li_emlrtRSI;
    b_st.site = &bd_emlrtRSI;
    workspace[17] = 0.0;
    c_st.site = &cd_emlrtRSI;
    ix = 0;
    c = 0.0;
    c_st.site = &dd_emlrtRSI;
    if ((1 <= workingset_nVar) && (workingset_nVar > 2147483646)) {
      d_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (ia = 1; ia <= workingset_nVar; ia++) {
      c += workingset_Aineq[ia - 1] * solution_searchDir[ix];
      ix++;
    }

    workspace[17] += c;
    st.site = &li_emlrtRSI;
    if (workspace[17] > denomTol) {
      st.site = &li_emlrtRSI;
      if ((workingset_isActiveIdx[2] < 1) || (workingset_isActiveIdx[2] > 17)) {
        emlrtDynamicBoundsCheckR2012b(workingset_isActiveIdx[2], 1, 17,
          &xb_emlrtBCI, &st);
      }

      if (!workingset_isActiveConstr[workingset_isActiveIdx[2] - 1]) {
        c = muDoubleScalarMin(muDoubleScalarAbs(workspace[0]), 1.0E-6 -
                              workspace[0]) / workspace[17];
        if (c < 1.0E+30) {
          *alpha = c;
          *constrType = 3;
          *constrIdx = 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX = (real_T)isPhaseOne * solution_xstar[workingset_nVar -
      1];
    phaseOneCorrectionP = (real_T)isPhaseOne *
      solution_searchDir[workingset_nVar - 1];
    ix = workingset_sizes[3];
    st.site = &li_emlrtRSI;
    for (idx = 0; idx <= ix - 2; idx++) {
      if ((workingset_indexLB[idx] < 1) || (workingset_indexLB[idx] > 9)) {
        emlrtDynamicBoundsCheckR2012b(workingset_indexLB[idx], 1, 9,
          &kd_emlrtBCI, sp);
      }

      c = -solution_searchDir[workingset_indexLB[idx] - 1] - phaseOneCorrectionP;
      if (c > denomTol) {
        st.site = &li_emlrtRSI;
        ia = workingset_isActiveIdx[3] + idx;
        if ((ia < 1) || (ia > 17)) {
          emlrtDynamicBoundsCheckR2012b(ia, 1, 17, &xb_emlrtBCI, &st);
        }

        if (!workingset_isActiveConstr[ia - 1]) {
          ratio = (-solution_xstar[workingset_indexLB[idx] - 1] -
                   workingset_lb[workingset_indexLB[idx] - 1]) -
            phaseOneCorrectionX;
          c = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) / c;
          if (c < *alpha) {
            *alpha = c;
            *constrType = 4;
            *constrIdx = idx + 1;
            *newBlocking = true;
          }
        }
      }
    }

    if ((workingset_sizes[3] < 1) || (workingset_sizes[3] > 9)) {
      emlrtDynamicBoundsCheckR2012b(workingset_sizes[3], 1, 9, &kd_emlrtBCI, sp);
    }

    ia = workingset_indexLB[workingset_sizes[3] - 1];
    if ((ia < 1) || (ia > 9)) {
      emlrtDynamicBoundsCheckR2012b(ia, 1, 9, &kd_emlrtBCI, sp);
    }

    if (-solution_searchDir[ia - 1] > denomTol) {
      st.site = &li_emlrtRSI;
      ia = workingset_isActiveIdx[3] + workingset_sizes[3];
      ix = ia - 1;
      if ((ix < 1) || (ix > 17)) {
        emlrtDynamicBoundsCheckR2012b(ix, 1, 17, &xb_emlrtBCI, &st);
      }

      if (!workingset_isActiveConstr[ia - 2]) {
        ratio = -solution_xstar[workingset_indexLB[workingset_sizes[3] - 1] - 1]
          - workingset_lb[workingset_indexLB[workingset_sizes[3] - 1] - 1];
        c = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) /
          -solution_searchDir[workingset_indexLB[workingset_sizes[3] - 1] - 1];
        if (c < *alpha) {
          *alpha = c;
          *constrType = 4;
          *constrIdx = workingset_sizes[3];
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    phaseOneCorrectionX = (real_T)isPhaseOne * solution_xstar[workingset_nVar -
      1];
    phaseOneCorrectionP = (real_T)isPhaseOne *
      solution_searchDir[workingset_nVar - 1];
    st.site = &li_emlrtRSI;
    if ((1 <= workingset_sizes[4]) && (workingset_sizes[4] > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < totalUB; idx++) {
      c = solution_searchDir[workingset_indexUB[idx] - 1] - phaseOneCorrectionP;
      if (c > denomTol) {
        st.site = &li_emlrtRSI;
        ia = workingset_isActiveIdx[4] + idx;
        if ((ia < 1) || (ia > 17)) {
          emlrtDynamicBoundsCheckR2012b(ia, 1, 17, &xb_emlrtBCI, &st);
        }

        if (!workingset_isActiveConstr[ia - 1]) {
          ratio = (solution_xstar[workingset_indexUB[idx] - 1] -
                   workingset_ub[workingset_indexUB[idx] - 1]) -
            phaseOneCorrectionX;
          c = muDoubleScalarMin(muDoubleScalarAbs(ratio), 1.0E-6 - ratio) / c;
          if (c < *alpha) {
            *alpha = c;
            *constrType = 5;
            *constrIdx = idx + 1;
            *newBlocking = true;
          }
        }
      }
    }
  }

  if (!isPhaseOne) {
    if ((*newBlocking) && (*alpha > 1.0)) {
      *newBlocking = false;
    }

    *alpha = muDoubleScalarMin(*alpha, 1.0);
  }
}

/* End of code generation (feasibleratiotest.c) */
