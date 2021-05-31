/*
 * normal.c
 *
 * Code generation for function 'normal'
 *
 */

/* Include files */
#include "normal.h"
#include "driver1.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "sortLambdaQP.h"

/* Variable Definitions */
static emlrtRSInfo ug_emlrtRSI = { 1,  /* lineNo */
  "normal",                            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\normal.p"/* pathName */
};

static emlrtBCInfo cc_emlrtBCI = { 1,  /* iFirst */
  0,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "normal",                            /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\normal.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void normal(const emlrtStack *sp, const real_T Hessian[49], const real_T grad[9],
            f_struct_T *TrialState, h_struct_T *MeritFunction, b_struct_T
            *memspace, e_struct_T *WorkingSet, i_struct_T *QRManager, k_struct_T
            *CholManager, j_struct_T *QPObjective, const c_struct_T *qpoptions)
{
  c_struct_T b_qpoptions;
  c_struct_T c_qpoptions;
  real_T penaltyParamTrial;
  real_T linearizedConstrViolPrev;
  real_T constrViolationIneq;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_qpoptions = *qpoptions;
  c_qpoptions = *qpoptions;
  st.site = &ug_emlrtRSI;
  b_driver(&st, Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
           CholManager, QPObjective, &b_qpoptions, &c_qpoptions);
  if (TrialState->state > 0) {
    penaltyParamTrial = MeritFunction->penaltyParam;
    linearizedConstrViolPrev = TrialState->cIneq;
    constrViolationIneq = 0.0;
    if (linearizedConstrViolPrev > 0.0) {
      constrViolationIneq = linearizedConstrViolPrev;
    }

    linearizedConstrViolPrev = MeritFunction->linearizedConstrViol;
    MeritFunction->linearizedConstrViol = 0.0;
    linearizedConstrViolPrev += constrViolationIneq;
    if ((linearizedConstrViolPrev > 2.2204460492503131E-16) &&
        (TrialState->fstar > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        penaltyParamTrial = 1.0;
      } else {
        penaltyParamTrial = 1.5;
      }

      penaltyParamTrial = penaltyParamTrial * TrialState->fstar /
        linearizedConstrViolPrev;
    }

    if (penaltyParamTrial < MeritFunction->penaltyParam) {
      MeritFunction->phi = TrialState->sqpFval + penaltyParamTrial *
        constrViolationIneq;
      if ((MeritFunction->initFval + penaltyParamTrial *
           MeritFunction->initConstrViolationIneq) - MeritFunction->phi >
          (real_T)MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) > TrialState->sqpIterations)
        {
          MeritFunction->threshold *= 10.0;
        }

        MeritFunction->penaltyParam = muDoubleScalarMax(penaltyParamTrial,
          1.0E-10);
      } else {
        MeritFunction->phi = TrialState->sqpFval + MeritFunction->penaltyParam *
          constrViolationIneq;
      }
    } else {
      MeritFunction->penaltyParam = muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
      MeritFunction->phi = TrialState->sqpFval + MeritFunction->penaltyParam *
        constrViolationIneq;
    }

    MeritFunction->phiPrimePlus = muDoubleScalarMin(TrialState->fstar -
      MeritFunction->penaltyParam * constrViolationIneq, 0.0);
  }

  st.site = &ug_emlrtRSI;
  sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
               WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
               WorkingSet->Wlocalidx, memspace->workspace_double);
  if (WorkingSet->mEqRemoved > 0) {
    emlrtDynamicBoundsCheckR2012b(WorkingSet->mEqRemoved, 1, 0, &cc_emlrtBCI, sp);
  }
}

/* End of code generation (normal.c) */
