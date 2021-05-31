/*
 * relaxed.c
 *
 * Code generation for function 'relaxed'
 *
 */

/* Include files */
#include "relaxed.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "eml_int_forloop_overflow_check.h"
#include "ixamax.h"
#include "moveConstraint_.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include "xasum.h"
#include "xgemv.h"

/* Variable Definitions */
static emlrtRSInfo pi_emlrtRSI = { 1,  /* lineNo */
  "updatePenaltyParam",                /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+MeritFunction\\updatePenaltyParam.p"/* pathName */
};

static emlrtRSInfo qi_emlrtRSI = { 1,  /* lineNo */
  "computeConstrViolationIneq_",       /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+MeritFunction\\computeConstrViolationIneq_.p"/* pathName */
};

static emlrtRSInfo ri_emlrtRSI = { 1,  /* lineNo */
  "relaxed",                           /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\relaxed.p"/* pathName */
};

static emlrtRSInfo si_emlrtRSI = { 1,  /* lineNo */
  "assignResidualsToXSlack",           /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\assignResidualsToXSlack.p"/* pathName */
};

static emlrtRSInfo ti_emlrtRSI = { 1,  /* lineNo */
  "findActiveSlackLowerBounds",        /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\findActiveSlackLowerBounds.p"/* pathName */
};

static emlrtRSInfo wi_emlrtRSI = { 1,  /* lineNo */
  "removeActiveSlackLowerBounds",      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\removeActiveSlackLowerBounds.p"/* pathName */
};

static emlrtBCInfo nd_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "relaxed",                           /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\relaxed.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "relaxed",                           /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\relaxed.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeActiveSlackLowerBounds",      /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\removeActiveSlackLowerBounds.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { 1,  /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "relaxed",                           /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\relaxed.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeActiveSlackLowerBounds",      /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\removeActiveSlackLowerBounds.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "assignResidualsToXSlack",           /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\assignResidualsToXSlack.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void relaxed(const emlrtStack *sp, const real_T Hessian[49], const real_T grad[9],
             f_struct_T *TrialState, h_struct_T *MeritFunction, b_struct_T
             *memspace, e_struct_T *WorkingSet, i_struct_T *QRManager,
             k_struct_T *CholManager, j_struct_T *QPObjective, c_struct_T
             *qpoptions)
{
  int32_T nVarOrig;
  real_T beta;
  int32_T idx;
  int32_T temp;
  int32_T idx_max;
  real_T smax;
  int32_T ix;
  int32_T k;
  real_T s;
  int32_T i;
  c_struct_T b_qpoptions;
  c_struct_T c_qpoptions;
  real_T qpfvalQuadExcess;
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
  nVarOrig = WorkingSet->nVar;
  beta = 0.0;
  st.site = &ri_emlrtRSI;
  if ((1 <= WorkingSet->nVar) && (WorkingSet->nVar > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < nVarOrig; idx++) {
    temp = idx + 1;
    if ((temp < 1) || (temp > 7)) {
      emlrtDynamicBoundsCheckR2012b(temp, 1, 7, &qd_emlrtBCI, sp);
    }

    beta += Hessian[(temp + 7 * (temp - 1)) - 1];
  }

  beta /= (real_T)WorkingSet->nVar;
  if (TrialState->sqpIterations <= 1) {
    st.site = &ri_emlrtRSI;
    idx_max = ixamax(&st, QPObjective->nvar, grad);
    if ((idx_max < 1) || (idx_max > 9)) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, 9, &od_emlrtBCI, sp);
    }

    smax = 100.0 * muDoubleScalarMax(1.0, muDoubleScalarAbs(grad[idx_max - 1]));
  } else {
    st.site = &ri_emlrtRSI;
    temp = WorkingSet->mConstr;
    b_st.site = &qd_emlrtRSI;
    idx_max = 1;
    if (WorkingSet->mConstr > 1) {
      ix = 0;
      smax = muDoubleScalarAbs(TrialState->lambdasqp[0]);
      c_st.site = &rd_emlrtRSI;
      if ((2 <= WorkingSet->mConstr) && (WorkingSet->mConstr > 2147483646)) {
        d_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 2; k <= temp; k++) {
        ix++;
        s = muDoubleScalarAbs(TrialState->lambdasqp[ix]);
        if (s > smax) {
          idx_max = k;
          smax = s;
        }
      }
    }

    if (idx_max > 17) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, 17, &nd_emlrtBCI, sp);
    }

    smax = muDoubleScalarAbs(TrialState->lambdasqp[idx_max - 1]);
  }

  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = smax;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  st.site = &ri_emlrtRSI;
  setProblemType(&st, WorkingSet, 2);
  st.site = &ri_emlrtRSI;
  b_st.site = &si_emlrtRSI;
  c_st.site = &fd_emlrtRSI;
  memspace->workspace_double[0] = WorkingSet->bineq;
  b_st.site = &si_emlrtRSI;
  d_xgemv(&b_st, nVarOrig, WorkingSet->Aineq, TrialState->xstar,
          memspace->workspace_double);
  b_st.site = &si_emlrtRSI;
  i = nVarOrig + 1;
  if ((i < 1) || (i > 9)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 9, &sd_emlrtBCI, &st);
  }

  TrialState->xstar[i - 1] = (real_T)(memspace->workspace_double[0] > 0.0) *
    memspace->workspace_double[0];
  if (memspace->workspace_double[0] <= 1.0E-6) {
    b_st.site = &si_emlrtRSI;
    c_st.site = &lf_emlrtRSI;
    addBoundToActiveSetMatrix_(&c_st, WorkingSet, 4, WorkingSet->sizes[3]);
  }

  b_st.site = &si_emlrtRSI;
  temp = qpoptions->MaxIterations;
  qpoptions->MaxIterations = (qpoptions->MaxIterations + WorkingSet->nVar) -
    nVarOrig;
  b_qpoptions = *qpoptions;
  c_qpoptions = *qpoptions;
  st.site = &ri_emlrtRSI;
  b_driver(&st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
           CholManager, QPObjective, &b_qpoptions, &c_qpoptions);
  qpoptions->MaxIterations = temp;
  st.site = &ri_emlrtRSI;
  b_st.site = &ti_emlrtRSI;
  b_st.site = &ti_emlrtRSI;
  b_st.site = &ti_emlrtRSI;
  i = (WorkingSet->isActiveIdx[3] + WorkingSet->sizes[3]) - 1;
  if ((i < 1) || (i > 17)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 17, &xb_emlrtBCI, &b_st);
  }

  k = WorkingSet->isActiveConstr[i - 1];
  memspace->workspace_int[0] = k;
  if (TrialState->state != -6) {
    st.site = &ri_emlrtRSI;
    s = xasum(&st, 8 - nVarOrig, TrialState->xstar, nVarOrig + 1);
    st.site = &ri_emlrtRSI;
    b_st.site = &rf_emlrtRSI;
    c_st.site = &sf_emlrtRSI;
    qpfvalQuadExcess = 0.0;
    if (8 - nVarOrig >= 1) {
      qpfvalQuadExcess = TrialState->xstar[nVarOrig] * TrialState->
        xstar[nVarOrig];
    }

    s = (TrialState->fstar - smax * s) - beta / 2.0 * qpfvalQuadExcess;
    st.site = &ri_emlrtRSI;
    qpfvalQuadExcess = MeritFunction->penaltyParam;
    b_st.site = &pi_emlrtRSI;
    smax = TrialState->cIneq;
    beta = 0.0;
    c_st.site = &qi_emlrtRSI;
    if (smax > 0.0) {
      beta = smax;
    }

    smax = MeritFunction->linearizedConstrViol;
    b_st.site = &pi_emlrtRSI;
    MeritFunction->linearizedConstrViol = xasum(&b_st, 8 - nVarOrig,
      TrialState->xstar, nVarOrig + 1);
    smax = (beta + smax) - MeritFunction->linearizedConstrViol;
    if ((smax > 2.2204460492503131E-16) && (s > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        qpfvalQuadExcess = 1.0;
      } else {
        qpfvalQuadExcess = 1.5;
      }

      qpfvalQuadExcess = qpfvalQuadExcess * s / smax;
    }

    if (qpfvalQuadExcess < MeritFunction->penaltyParam) {
      MeritFunction->phi = TrialState->sqpFval + qpfvalQuadExcess * beta;
      if ((MeritFunction->initFval + qpfvalQuadExcess *
           MeritFunction->initConstrViolationIneq) - MeritFunction->phi >
          (real_T)MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) > TrialState->sqpIterations)
        {
          MeritFunction->threshold *= 10.0;
        }

        MeritFunction->penaltyParam = muDoubleScalarMax(qpfvalQuadExcess,
          1.0E-10);
      } else {
        MeritFunction->phi = TrialState->sqpFval + MeritFunction->penaltyParam *
          beta;
      }
    } else {
      MeritFunction->penaltyParam = muDoubleScalarMax(qpfvalQuadExcess, 1.0E-10);
      MeritFunction->phi = TrialState->sqpFval + MeritFunction->penaltyParam *
        beta;
    }

    MeritFunction->phiPrimePlus = muDoubleScalarMin(s -
      MeritFunction->penaltyParam * beta, 0.0);
    st.site = &ri_emlrtRSI;
    temp = WorkingSet->isActiveIdx[2];
    idx_max = WorkingSet->nActiveConstr;
    st.site = &ri_emlrtRSI;
    if ((WorkingSet->isActiveIdx[2] <= WorkingSet->nActiveConstr) &&
        (WorkingSet->nActiveConstr > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = temp; idx <= idx_max; idx++) {
      if ((idx < 1) || (idx > 17)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &nd_emlrtBCI, sp);
      }

      if (WorkingSet->Wid[idx - 1] == 3) {
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 17)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 17,
            &nd_emlrtBCI, sp);
        }

        TrialState->lambda[idx - 1] *= (real_T)memspace->workspace_int[i - 1];
      }
    }
  }

  st.site = &ri_emlrtRSI;
  idx_max = WorkingSet->sizes[0];
  ix = WorkingSet->sizes[3] - 1;
  idx = WorkingSet->nActiveConstr - 1;
  while ((idx + 1 > idx_max) && (k > 0)) {
    i = idx + 1;
    if ((i < 1) || (i > 17)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 17, &rd_emlrtBCI, &st);
    }

    if ((WorkingSet->Wid[i - 1] == 4) && (WorkingSet->Wlocalidx[idx] > ix)) {
      if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > 17)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, 17,
          &rd_emlrtBCI, &st);
      }

      smax = TrialState->lambda[WorkingSet->nActiveConstr - 1];
      if ((WorkingSet->nActiveConstr < 1) || (WorkingSet->nActiveConstr > 17)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->nActiveConstr, 1, 17,
          &pd_emlrtBCI, &st);
      }

      TrialState->lambda[WorkingSet->nActiveConstr - 1] = 0.0;
      TrialState->lambda[idx] = smax;
      b_st.site = &wi_emlrtRSI;
      temp = WorkingSet->Wid[idx];
      if ((WorkingSet->Wid[idx] < 1) || (WorkingSet->Wid[idx] > 6)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet->Wid[idx], 1, 6, &db_emlrtBCI,
          &b_st);
      }

      i = (WorkingSet->isActiveIdx[WorkingSet->Wid[idx] - 1] +
           WorkingSet->Wlocalidx[idx]) - 1;
      if ((i < 1) || (i > 17)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 17, &nb_emlrtBCI, &b_st);
      }

      WorkingSet->isActiveConstr[i - 1] = false;
      c_st.site = &xf_emlrtRSI;
      moveConstraint_(&c_st, WorkingSet, WorkingSet->nActiveConstr, idx + 1);
      WorkingSet->nActiveConstr--;
      if ((temp < 1) || (temp > 5)) {
        emlrtDynamicBoundsCheckR2012b(temp, 1, 5, &pb_emlrtBCI, &b_st);
      }

      WorkingSet->nWConstr[temp - 1]--;
      k = 0;
    }

    idx--;
  }

  QPObjective->nvar = nVarOrig;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  st.site = &ri_emlrtRSI;
  setProblemType(&st, WorkingSet, 3);
  st.site = &ri_emlrtRSI;
  sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
               WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
               WorkingSet->Wlocalidx, memspace->workspace_double);
}

/* End of code generation (relaxed.c) */
