/*
 * soc.c
 *
 * Code generation for function 'soc'
 *
 */

/* Include files */
#include "soc.h"
#include "addAineqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "eml_int_forloop_overflow_check.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "xnrm2.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo xi_emlrtRSI = { 1,  /* lineNo */
  "soc",                               /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\soc.p"/* pathName */
};

static emlrtRSInfo yi_emlrtRSI = { 1,  /* lineNo */
  "updateWorkingSet",                  /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+soc\\updateWorkingSet.p"/* pathName */
};

static emlrtRSInfo aj_emlrtRSI = { 1,  /* lineNo */
  "restoreWorkingSet",                 /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+soc\\restoreWorkingSet.p"/* pathName */
};

static emlrtBCInfo td_emlrtBCI = { 1,  /* iFirst */
  1,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSet",                  /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+soc\\updateWorkingSet.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSet",                  /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+soc\\updateWorkingSet.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "restoreWorkingSet",                 /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+soc\\restoreWorkingSet.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSet",                  /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+soc\\updateWorkingSet.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { 1,  /* iFirst */
  0,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "soc",                               /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\soc.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
boolean_T soc(const emlrtStack *sp, const real_T Hessian[49], const real_T grad
              [9], f_struct_T *TrialState, b_struct_T *memspace, e_struct_T
              *WorkingSet, i_struct_T *QRManager, k_struct_T *CholManager,
              j_struct_T *QPObjective, const c_struct_T *qpoptions)
{
  boolean_T success;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  int32_T nVar;
  int32_T iv[17];
  int32_T idxIneqOffset;
  int32_T mm1;
  int32_T b;
  int32_T ix;
  real_T c;
  int32_T idx_upper;
  int32_T idx;
  c_struct_T b_qpoptions;
  int32_T idx_Partition;
  c_struct_T c_qpoptions;
  int32_T i;
  real_T lenQPNormal;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  nWIneq_old = WorkingSet->nWConstr[2];
  nWLower_old = WorkingSet->nWConstr[3];
  nWUpper_old = WorkingSet->nWConstr[4];
  nVar = WorkingSet->nVar;
  st.site = &xi_emlrtRSI;
  b_st.site = &fd_emlrtRSI;
  c_st.site = &gd_emlrtRSI;
  if ((1 <= WorkingSet->nVar) && (WorkingSet->nVar > 2147483646)) {
    d_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  if (0 <= nVar - 1) {
    memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0], nVar * sizeof
           (real_T));
  }

  st.site = &xi_emlrtRSI;
  if ((1 <= WorkingSet->nVar) && (WorkingSet->nVar > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  if (0 <= nVar - 1) {
    memcpy(&TrialState->socDirection[0], &TrialState->xstar[0], nVar * sizeof
           (real_T));
  }

  st.site = &xi_emlrtRSI;
  b_xcopy(&st, 17, TrialState->lambda, TrialState->lambda_old);
  st.site = &xi_emlrtRSI;
  memcpy(&iv[0], &TrialState->workingset_old[0], 17U * sizeof(int32_T));
  idxIneqOffset = WorkingSet->isActiveIdx[2];
  b_st.site = &yi_emlrtRSI;
  WorkingSet->bineq = -TrialState->cIneq;
  b_st.site = &yi_emlrtRSI;
  c_st.site = &bd_emlrtRSI;
  mm1 = WorkingSet->nVar;
  d_st.site = &cd_emlrtRSI;
  b = WorkingSet->nVar;
  ix = 0;
  c = 0.0;
  d_st.site = &dd_emlrtRSI;
  if ((1 <= mm1) && (mm1 > 2147483646)) {
    e_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (mm1 = 1; mm1 <= b; mm1++) {
    c += WorkingSet->Aineq[mm1 - 1] * TrialState->searchDir[ix];
    ix++;
  }

  c += WorkingSet->bineq;
  WorkingSet->bineq = c;
  mm1 = 1;
  ix = 2;
  idx_upper = WorkingSet->sizes[3] + 2;
  b = WorkingSet->nActiveConstr;
  b_st.site = &yi_emlrtRSI;
  if ((WorkingSet->isActiveIdx[2] <= WorkingSet->nActiveConstr) &&
      (WorkingSet->nActiveConstr > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = idxIneqOffset; idx <= b; idx++) {
    if ((idx < 1) || (idx > 17)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &ud_emlrtBCI, &st);
    }

    switch (WorkingSet->Wid[idx - 1]) {
     case 3:
      idx_Partition = mm1;
      mm1++;
      i = WorkingSet->Wlocalidx[idx - 1];
      if ((i < 1) || (i > 1)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 1,
          &td_emlrtBCI, &st);
      }

      WorkingSet->bwset[idx - 1] = c;
      break;

     case 4:
      idx_Partition = ix;
      ix++;
      break;

     default:
      idx_Partition = idx_upper;
      idx_upper++;
      break;
    }

    if ((idx_Partition < 1) || (idx_Partition > 17)) {
      emlrtDynamicBoundsCheckR2012b(idx_Partition, 1, 17, &wd_emlrtBCI, &st);
    }

    iv[idx_Partition - 1] = WorkingSet->Wlocalidx[idx - 1];
  }

  memcpy(&TrialState->workingset_old[0], &iv[0], 17U * sizeof(int32_T));
  st.site = &xi_emlrtRSI;
  e_xcopy(&st, WorkingSet->nVar, TrialState->xstarsqp, TrialState->xstar);
  b_qpoptions = *qpoptions;
  c_qpoptions = *qpoptions;
  st.site = &xi_emlrtRSI;
  b_driver(&st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
           CholManager, QPObjective, &b_qpoptions, &c_qpoptions);
  if (WorkingSet->mEqRemoved > 0) {
    emlrtDynamicBoundsCheckR2012b(WorkingSet->mEqRemoved, 1, 0, &xd_emlrtBCI, sp);
  }

  st.site = &xi_emlrtRSI;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < nVar; idx++) {
    c = TrialState->socDirection[idx];
    TrialState->socDirection[idx] = TrialState->xstar[idx] -
      TrialState->socDirection[idx];
    TrialState->xstar[idx] = c;
  }

  st.site = &xi_emlrtRSI;
  c = xnrm2(&st, nVar, TrialState->socDirection);
  st.site = &xi_emlrtRSI;
  lenQPNormal = xnrm2(&st, nVar, TrialState->xstar);
  success = (c <= 2.0 * lenQPNormal);
  st.site = &xi_emlrtRSI;
  mm1 = WorkingSet->sizes[3];
  b_st.site = &aj_emlrtRSI;
  WorkingSet->bineq = -TrialState->cIneq;
  if (!success) {
    b_st.site = &aj_emlrtRSI;
    removeAllIneqConstr(&b_st, WorkingSet);
    b_st.site = &aj_emlrtRSI;
    if ((1 <= nWIneq_old) && (nWIneq_old > 2147483646)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = 0; idx < nWIneq_old; idx++) {
      i = idx + 1;
      if ((i < 1) || (i > 17)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 17, &vd_emlrtBCI, &st);
      }

      b_st.site = &aj_emlrtRSI;
      addAineqConstr(&b_st, WorkingSet, TrialState->workingset_old[i - 1]);
    }

    b_st.site = &aj_emlrtRSI;
    if ((1 <= nWLower_old) && (nWLower_old > 2147483646)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = 0; idx < nWLower_old; idx++) {
      b_st.site = &aj_emlrtRSI;
      i = idx + 2;
      if ((i < 1) || (i > 17)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 17, &vd_emlrtBCI, &b_st);
      }

      c_st.site = &lf_emlrtRSI;
      addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4,
        TrialState->workingset_old[idx + 1]);
    }

    b_st.site = &aj_emlrtRSI;
    if ((1 <= nWUpper_old) && (nWUpper_old > 2147483646)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (idx = 0; idx < nWUpper_old; idx++) {
      b_st.site = &aj_emlrtRSI;
      i = (idx + mm1) + 2;
      if ((i < 1) || (i > 17)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 17, &vd_emlrtBCI, &b_st);
      }

      c_st.site = &nf_emlrtRSI;
      addBoundToActiveSetMatrix_(&c_st, WorkingSet, 5,
        TrialState->workingset_old[i - 1]);
    }
  }

  if (!success) {
    st.site = &xi_emlrtRSI;
    b_xcopy(&st, 17, TrialState->lambda_old, TrialState->lambda);
  } else {
    st.site = &xi_emlrtRSI;
    sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
                 WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                 WorkingSet->Wlocalidx, memspace->workspace_double);
  }

  return success;
}

/* End of code generation (soc.c) */
