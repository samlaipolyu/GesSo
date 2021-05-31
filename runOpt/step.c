/*
 * step.c
 *
 * Code generation for function 'step'
 *
 */

/* Include files */
#include "step.h"
#include "addBoundToActiveSetMatrix_.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "normal.h"
#include "relaxed.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "soc.h"
#include "xcopy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kf_emlrtRSI = { 1,  /* lineNo */
  "makeBoundFeasible",                 /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\makeBoundFeasible.p"/* pathName */
};

static emlrtRSInfo tg_emlrtRSI = { 1,  /* lineNo */
  "step",                              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\step.p"/* pathName */
};

static emlrtRSInfo bj_emlrtRSI = { 1,  /* lineNo */
  "saturateDirection",                 /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\saturateDirection.p"/* pathName */
};

static emlrtRSInfo cj_emlrtRSI = { 1,  /* lineNo */
  "BFGSReset",                         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\BFGSReset.p"/* pathName */
};

static emlrtBCInfo yb_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "makeBoundFeasible",                 /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\makeBoundFeasible.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { 1,  /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "saturateDirection",                 /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\saturateDirection.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "saturateDirection",                 /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\saturateDirection.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
boolean_T step(const emlrtStack *sp, int32_T *STEP_TYPE, real_T Hessian[49],
               const real_T lb[7], const real_T ub[7], f_struct_T *TrialState,
               h_struct_T *MeritFunction, b_struct_T *memspace, e_struct_T
               *WorkingSet, i_struct_T *QRManager, k_struct_T *CholManager,
               j_struct_T *QPObjective, c_struct_T *qpoptions)
{
  boolean_T stepSuccess;
  boolean_T checkBoundViolation;
  int32_T nVar;
  real_T dv[9];
  int32_T mLB;
  int32_T mUB;
  int32_T idx;
  real_T nrmGradInf;
  int32_T i;
  int32_T exitg1;
  boolean_T guard1 = false;
  f_struct_T b_TrialState;
  real_T nrmDirInf;
  real_T dv1[9];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  stepSuccess = true;
  checkBoundViolation = true;
  nVar = WorkingSet->nVar;
  if (*STEP_TYPE != 3) {
    st.site = &tg_emlrtRSI;
    e_xcopy(&st, WorkingSet->nVar, TrialState->xstarsqp, TrialState->xstar);
  } else {
    st.site = &tg_emlrtRSI;
    f_xcopy(&st, WorkingSet->nVar, TrialState->xstar, TrialState->searchDir);
  }

  st.site = &tg_emlrtRSI;
  memcpy(&dv[0], &TrialState->xstar[0], 9U * sizeof(real_T));
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  b_st.site = &kf_emlrtRSI;
  if ((1 <= WorkingSet->sizes[3]) && (WorkingSet->sizes[3] > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 9)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 9, &yb_emlrtBCI,
        &st);
    }

    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 9)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 9, &yb_emlrtBCI,
        &st);
    }

    nrmGradInf = WorkingSet->lb[WorkingSet->indexLB[idx] - 1];
    if (-dv[WorkingSet->indexLB[idx] - 1] >= nrmGradInf) {
      dv[WorkingSet->indexLB[idx] - 1] = -nrmGradInf;
      b_st.site = &kf_emlrtRSI;
      i = WorkingSet->isActiveIdx[3] + idx;
      if ((i < 1) || (i > 17)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 17, &xb_emlrtBCI, &b_st);
      }

      if (!WorkingSet->isActiveConstr[i - 1]) {
        b_st.site = &kf_emlrtRSI;
        c_st.site = &lf_emlrtRSI;
        addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4, idx + 1);
      }
    }
  }

  b_st.site = &kf_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    nrmGradInf = WorkingSet->ub[WorkingSet->indexUB[idx] - 1];
    if (dv[WorkingSet->indexUB[idx] - 1] >= nrmGradInf) {
      dv[WorkingSet->indexUB[idx] - 1] = nrmGradInf;
      b_st.site = &kf_emlrtRSI;
      i = WorkingSet->isActiveIdx[4] + idx;
      if ((i < 1) || (i > 17)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 17, &xb_emlrtBCI, &b_st);
      }

      if (!WorkingSet->isActiveConstr[i - 1]) {
        b_st.site = &kf_emlrtRSI;
        c_st.site = &nf_emlrtRSI;
        addBoundToActiveSetMatrix_(&c_st, WorkingSet, 5, idx + 1);
      }
    }
  }

  memcpy(&TrialState->xstar[0], &dv[0], 9U * sizeof(real_T));
  do {
    exitg1 = 0;
    guard1 = false;
    switch (*STEP_TYPE) {
     case 1:
      b_TrialState = *TrialState;
      st.site = &tg_emlrtRSI;
      normal(&st, Hessian, TrialState->grad, &b_TrialState, MeritFunction,
             memspace, WorkingSet, QRManager, CholManager, QPObjective,
             qpoptions);
      *TrialState = b_TrialState;
      if ((b_TrialState.state <= 0) && (b_TrialState.state != -6)) {
        *STEP_TYPE = 2;
      } else {
        memcpy(&TrialState->delta_x[0], &b_TrialState.delta_x[0], 9U * sizeof
               (real_T));
        st.site = &tg_emlrtRSI;
        f_xcopy(&st, nVar, b_TrialState.xstar, TrialState->delta_x);
        guard1 = true;
      }
      break;

     case 2:
      b_TrialState = *TrialState;
      st.site = &tg_emlrtRSI;
      relaxed(&st, Hessian, TrialState->grad, &b_TrialState, MeritFunction,
              memspace, WorkingSet, QRManager, CholManager, QPObjective,
              qpoptions);
      *TrialState = b_TrialState;
      memcpy(&TrialState->delta_x[0], &b_TrialState.delta_x[0], 9U * sizeof
             (real_T));
      st.site = &tg_emlrtRSI;
      f_xcopy(&st, nVar, b_TrialState.xstar, TrialState->delta_x);
      guard1 = true;
      break;

     default:
      memcpy(&dv[0], &TrialState->grad[0], 9U * sizeof(real_T));
      st.site = &tg_emlrtRSI;
      stepSuccess = soc(&st, Hessian, dv, TrialState, memspace, WorkingSet,
                        QRManager, CholManager, QPObjective, qpoptions);
      checkBoundViolation = stepSuccess;
      if (stepSuccess && (TrialState->state != -6)) {
        st.site = &tg_emlrtRSI;
        if ((1 <= nVar) && (nVar > 2147483646)) {
          b_st.site = &d_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (idx = 0; idx < nVar; idx++) {
          TrialState->delta_x[idx] = TrialState->xstar[idx] +
            TrialState->socDirection[idx];
        }
      }

      guard1 = true;
      break;
    }

    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        st.site = &tg_emlrtRSI;
        nrmGradInf = 0.0;
        nrmDirInf = 1.0;
        for (idx = 0; idx < 7; idx++) {
          nrmGradInf = muDoubleScalarMax(nrmGradInf, muDoubleScalarAbs
            (TrialState->grad[idx]));
          nrmDirInf = muDoubleScalarMax(nrmDirInf, muDoubleScalarAbs
            (TrialState->xstar[idx]));
        }

        nrmGradInf = muDoubleScalarMax(2.2204460492503131E-16, nrmGradInf /
          nrmDirInf);
        for (mUB = 0; mUB < 7; mUB++) {
          mLB = 7 * mUB;
          b_st.site = &cj_emlrtRSI;
          g_xcopy(&b_st, mUB, Hessian, mLB + 1);
          Hessian[mUB + 7 * mUB] = nrmGradInf;
          mLB += mUB;
          b_st.site = &cj_emlrtRSI;
          g_xcopy(&b_st, 6 - mUB, Hessian, mLB + 2);
        }
      }
    }
  } while (exitg1 == 0);

  if (checkBoundViolation) {
    mLB = WorkingSet->sizes[3];
    mUB = WorkingSet->sizes[4];
    st.site = &tg_emlrtRSI;
    memcpy(&dv[0], &TrialState->delta_x[0], 9U * sizeof(real_T));
    memcpy(&dv1[0], &TrialState->xstar[0], 9U * sizeof(real_T));
    b_st.site = &bj_emlrtRSI;
    if ((1 <= WorkingSet->sizes[3]) && (WorkingSet->sizes[3] > 2147483646)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = 0; idx < mLB; idx++) {
      if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 7,
          &ac_emlrtBCI, &st);
      }

      if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 9)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 9,
          &bc_emlrtBCI, &st);
      }

      if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 7)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 7,
          &ac_emlrtBCI, &st);
      }

      nrmGradInf = dv[WorkingSet->indexLB[idx] - 1];
      nrmDirInf = (TrialState->xstarsqp[WorkingSet->indexLB[idx] - 1] +
                   nrmGradInf) - lb[WorkingSet->indexLB[idx] - 1];
      if (nrmDirInf < 0.0) {
        dv[WorkingSet->indexLB[idx] - 1] = nrmGradInf - nrmDirInf;
        dv1[WorkingSet->indexLB[idx] - 1] -= nrmDirInf;
      }
    }

    b_st.site = &bj_emlrtRSI;
    if ((1 <= WorkingSet->sizes[4]) && (WorkingSet->sizes[4] > 2147483646)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = 0; idx < mUB; idx++) {
      nrmGradInf = dv[WorkingSet->indexUB[idx] - 1];
      nrmDirInf = (ub[WorkingSet->indexUB[idx] - 1] - TrialState->
                   xstarsqp[WorkingSet->indexUB[idx] - 1]) - nrmGradInf;
      if (nrmDirInf < 0.0) {
        dv[WorkingSet->indexUB[idx] - 1] = nrmGradInf + nrmDirInf;
        dv1[WorkingSet->indexUB[idx] - 1] += nrmDirInf;
      }
    }

    memcpy(&TrialState->delta_x[0], &dv[0], 9U * sizeof(real_T));
    memcpy(&TrialState->xstar[0], &dv1[0], 9U * sizeof(real_T));
  }

  return stepSuccess;
}

/* End of code generation (step.c) */
