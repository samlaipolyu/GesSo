/*
 * driver.c
 *
 * Code generation for function 'driver'
 *
 */

/* Include files */
#include "driver.h"
#include "BFGSUpdate.h"
#include "computeFiniteDifferences.h"
#include "computeLinearResiduals.h"
#include "computeObjective_.h"
#include "eml_int_forloop_overflow_check.h"
#include "isDeltaXTooSmall.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "saveState.h"
#include "step.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include "xcopy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ld_emlrtRSI = { 1,  /* lineNo */
  "driver",                            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\driver.p"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 1,  /* lineNo */
  "saveJacobian",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+TrialState\\saveJacobian.p"/* pathName */
};

static emlrtRSInfo dj_emlrtRSI = { 1,  /* lineNo */
  "evalObjAndConstr",                  /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\evalObjAndConstr.p"/* pathName */
};

static emlrtRSInfo ej_emlrtRSI = { 1,  /* lineNo */
  "computeMeritFcn",                   /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+MeritFunction\\computeMeritFcn.p"/* pathName */
};

static emlrtRSInfo fj_emlrtRSI = { 1,  /* lineNo */
  "linesearch",                        /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\linesearch.p"/* pathName */
};

static emlrtRSInfo gj_emlrtRSI = { 1,  /* lineNo */
  "revertSolution",                    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+TrialState\\revertSolution.p"/* pathName */
};

static emlrtRSInfo hj_emlrtRSI = { 1,  /* lineNo */
  "computeDeltaLag",                   /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeDeltaLag.p"/* pathName */
};

static emlrtBCInfo j_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "linesearch",                        /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\linesearch.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "linesearch",                        /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\linesearch.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "driver",                            /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\driver.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "driver",                            /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\driver.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "driver",                            /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\driver.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void driver(const emlrtStack *sp, real_T bineq, const real_T lb[7], const real_T
            ub[7], f_struct_T *TrialState, h_struct_T *MeritFunction, const
            g_struct_T *FcnEvaluator, d_struct_T *FiniteDifferences, b_struct_T *
            memspace, e_struct_T *WorkingSet, i_struct_T *QRManager, j_struct_T *
            QPObjective, real_T Hessian[49], k_struct_T *CholManager)
{
  int32_T k;
  int32_T nVar;
  static const int8_T iv[49] = { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 1 };

  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  int32_T mConstr;
  int32_T ixlast;
  int32_T qpoptions_MaxIterations;
  struct_T Flags;
  c_struct_T expl_temp;
  int32_T idx;
  c_struct_T b_expl_temp;
  static const char_T qpoptions_SolverName[7] = { 'f', 'm', 'i', 'n', 'c', 'o',
    'n' };

  real_T phi_alpha;
  boolean_T socTaken;
  int32_T b_nVar;
  boolean_T evalWellDefined;
  int32_T i;
  real_T alpha;
  int32_T exitflagLnSrch;
  real_T b_TrialState[7];
  int32_T exitg1;
  real_T constrViolationIneq;
  boolean_T tooSmallX;
  int32_T i1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  memset(&CholManager->FMat[0], 0, 289U * sizeof(real_T));
  CholManager->ldm = 17;
  CholManager->ndims = 0;
  CholManager->info = 0;
  for (k = 0; k < 49; k++) {
    Hessian[k] = iv[k];
  }

  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mConstr = ((WorkingSet->sizes[0] + WorkingSet->sizes[3]) + WorkingSet->sizes[4])
    + 1;
  ixlast = ((WorkingSet->sizes[3] + WorkingSet->sizes[4]) + (WorkingSet->sizes[0]
             << 1)) + 1;
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet->nVar, ixlast);
  TrialState->steplength = 1.0;
  st.site = &ld_emlrtRSI;
  test_exit(&st, MeritFunction, WorkingSet, TrialState, lb, ub, &Flags.gradOK,
            &Flags.fevalOK, &Flags.done, &Flags.stepAccepted,
            &Flags.failedLineSearch, &Flags.stepType);
  st.site = &ld_emlrtRSI;
  b_st.site = &if_emlrtRSI;
  b_st.site = &if_emlrtRSI;
  st.site = &ld_emlrtRSI;
  saveState(TrialState);
  if (!Flags.done) {
    TrialState->sqpIterations = 1;
  }

  while (!Flags.done) {
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      st.site = &ld_emlrtRSI;
      updateWorkingSetForNewQP(&st, TrialState->xstarsqp, WorkingSet,
        TrialState->cIneq, mLB, lb, mUB, ub, mFixed);
      expl_temp.IterDisplayQP = false;
      expl_temp.RemainFeasible = false;
      expl_temp.ProbRelTolFactor = 1.0;
      expl_temp.ConstrRelTolFactor = 1.0;
      expl_temp.PricingTolerance = 0.0;
      expl_temp.ObjectiveLimit = -1.0E+20;
      expl_temp.ConstraintTolerance = 1.0E-6;
      expl_temp.OptimalityTolerance = 2.2204460492503131E-14;
      expl_temp.StepTolerance = 1.0E-6;
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (k = 0; k < 7; k++) {
        expl_temp.SolverName[k] = qpoptions_SolverName[k];
      }

      b_expl_temp = expl_temp;
      st.site = &ld_emlrtRSI;
      Flags.stepAccepted = step(&st, &Flags.stepType, Hessian, lb, ub,
        TrialState, MeritFunction, memspace, WorkingSet, QRManager, CholManager,
        QPObjective, &b_expl_temp);
      if (Flags.stepAccepted) {
        st.site = &ld_emlrtRSI;
        if ((1 <= nVar) && (nVar > 2147483646)) {
          b_st.site = &d_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (b_nVar = 0; b_nVar < nVar; b_nVar++) {
          k = b_nVar + 1;
          if ((k < 1) || (k > 7)) {
            emlrtDynamicBoundsCheckR2012b(k, 1, 7, &l_emlrtBCI, sp);
          }

          ixlast = b_nVar + 1;
          if ((ixlast < 1) || (ixlast > 7)) {
            emlrtDynamicBoundsCheckR2012b(ixlast, 1, 7, &m_emlrtBCI, sp);
          }

          TrialState->xstarsqp[k - 1] = TrialState->xstarsqp[ixlast - 1] +
            TrialState->delta_x[b_nVar];
        }

        st.site = &ld_emlrtRSI;
        for (i = 0; i < 7; i++) {
          b_TrialState[i] = TrialState->xstarsqp[i];
        }

        b_st.site = &dj_emlrtRSI;
        computeObjective_(&b_st, FcnEvaluator->objfun.tunableEnvironment.f1,
                          FcnEvaluator->objfun.tunableEnvironment.f2,
                          FcnEvaluator->objfun.tunableEnvironment.f3,
                          b_TrialState, &TrialState->sqpFval, &ixlast);
        if (ixlast == 1) {
          ixlast = 1;
        }

        Flags.fevalOK = (ixlast == 1);
        TrialState->FunctionEvaluations++;
        st.site = &ld_emlrtRSI;
        computeLinearResiduals(&st, TrialState->xstarsqp, nVar,
          &TrialState->cIneq, WorkingSet->Aineq, bineq);
        st.site = &ld_emlrtRSI;
        if (Flags.fevalOK) {
          b_st.site = &ej_emlrtRSI;
          phi_alpha = TrialState->cIneq;
          constrViolationIneq = 0.0;
          if (phi_alpha > 0.0) {
            constrViolationIneq = phi_alpha;
          }

          MeritFunction->phiFullStep = TrialState->sqpFval +
            MeritFunction->penaltyParam * constrViolationIneq;
        } else {
          MeritFunction->phiFullStep = rtInf;
        }
      }

      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }

        st.site = &ld_emlrtRSI;
        evalWellDefined = Flags.fevalOK;
        b_nVar = WorkingSet->nVar;
        alpha = 1.0;
        exitflagLnSrch = 1;
        phi_alpha = MeritFunction->phiFullStep;
        b_st.site = &fj_emlrtRSI;
        f_xcopy(&b_st, WorkingSet->nVar, TrialState->delta_x,
                TrialState->searchDir);
        do {
          exitg1 = 0;
          if (TrialState->FunctionEvaluations < 700) {
            if (evalWellDefined && (phi_alpha <= MeritFunction->phi + alpha *
                                    0.0001 * MeritFunction->phiPrimePlus)) {
              exitg1 = 1;
            } else {
              alpha *= 0.7;
              b_st.site = &fj_emlrtRSI;
              if ((1 <= b_nVar) && (b_nVar > 2147483646)) {
                c_st.site = &d_emlrtRSI;
                check_forloop_overflow_error(&c_st);
              }

              for (idx = 0; idx < b_nVar; idx++) {
                TrialState->delta_x[idx] = alpha * TrialState->searchDir[idx];
              }

              if (socTaken) {
                phi_alpha = alpha * alpha;
                if ((b_nVar >= 1) && (!(phi_alpha == 0.0))) {
                  ixlast = b_nVar - 1;
                  for (k = 0; k <= ixlast; k++) {
                    TrialState->delta_x[k] += phi_alpha *
                      TrialState->socDirection[k];
                  }
                }
              }

              b_st.site = &fj_emlrtRSI;
              tooSmallX = isDeltaXTooSmall(&b_st, TrialState->xstarsqp,
                TrialState->delta_x, b_nVar);
              if (tooSmallX) {
                exitflagLnSrch = -2;
                exitg1 = 1;
              } else {
                b_st.site = &fj_emlrtRSI;
                for (idx = 0; idx < b_nVar; idx++) {
                  k = idx + 1;
                  if ((k < 1) || (k > 7)) {
                    emlrtDynamicBoundsCheckR2012b(k, 1, 7, &j_emlrtBCI, &st);
                  }

                  ixlast = idx + 1;
                  if ((ixlast < 1) || (ixlast > 7)) {
                    emlrtDynamicBoundsCheckR2012b(ixlast, 1, 7, &k_emlrtBCI, &st);
                  }

                  TrialState->xstarsqp[k - 1] = TrialState->xstarsqp_old[ixlast
                    - 1] + TrialState->delta_x[idx];
                }

                b_st.site = &fj_emlrtRSI;
                for (i1 = 0; i1 < 7; i1++) {
                  b_TrialState[i1] = TrialState->xstarsqp[i1];
                }

                c_st.site = &dj_emlrtRSI;
                computeObjective_(&c_st,
                                  FcnEvaluator->objfun.tunableEnvironment.f1,
                                  FcnEvaluator->objfun.tunableEnvironment.f2,
                                  FcnEvaluator->objfun.tunableEnvironment.f3,
                                  b_TrialState, &TrialState->sqpFval, &ixlast);
                if (ixlast == 1) {
                  ixlast = 1;
                }

                b_st.site = &fj_emlrtRSI;
                computeLinearResiduals(&b_st, TrialState->xstarsqp, b_nVar,
                  &TrialState->cIneq, WorkingSet->Aineq, bineq);
                TrialState->FunctionEvaluations++;
                evalWellDefined = (ixlast == 1);
                b_st.site = &fj_emlrtRSI;
                if (evalWellDefined) {
                  phi_alpha = TrialState->cIneq;
                  constrViolationIneq = 0.0;
                  if (phi_alpha > 0.0) {
                    constrViolationIneq = phi_alpha;
                  }

                  phi_alpha = TrialState->sqpFval + MeritFunction->penaltyParam *
                    constrViolationIneq;
                } else {
                  phi_alpha = rtInf;
                }
              }
            }
          } else {
            exitflagLnSrch = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);

        Flags.fevalOK = evalWellDefined;
        TrialState->steplength = alpha;
        if (exitflagLnSrch > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }

    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      st.site = &ld_emlrtRSI;
      if ((1 <= nVar) && (nVar > 2147483646)) {
        b_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (idx = 0; idx < nVar; idx++) {
        k = idx + 1;
        if ((k < 1) || (k > 7)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, 7, &l_emlrtBCI, sp);
        }

        ixlast = idx + 1;
        if ((ixlast < 1) || (ixlast > 7)) {
          emlrtDynamicBoundsCheckR2012b(ixlast, 1, 7, &m_emlrtBCI, sp);
        }

        TrialState->xstarsqp[k - 1] = TrialState->xstarsqp_old[ixlast - 1] +
          TrialState->delta_x[idx];
      }

      st.site = &ld_emlrtRSI;
      if ((1 <= mConstr) && (mConstr > 2147483646)) {
        b_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (idx = 0; idx < mConstr; idx++) {
        ixlast = idx + 1;
        if ((ixlast < 1) || (ixlast > 17)) {
          emlrtDynamicBoundsCheckR2012b(ixlast, 1, 17, &n_emlrtBCI, sp);
        }

        phi_alpha = TrialState->lambdasqp[ixlast - 1];
        TrialState->lambdasqp[ixlast - 1] = phi_alpha + TrialState->steplength *
          (TrialState->lambda[ixlast - 1] - phi_alpha);
      }

      st.site = &ld_emlrtRSI;
      saveState(TrialState);
      st.site = &ld_emlrtRSI;
      Flags.gradOK = computeFiniteDifferences(&st, FiniteDifferences,
        TrialState->sqpFval, TrialState->xstarsqp, TrialState->grad, lb, ub);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      st.site = &ld_emlrtRSI;
      TrialState->sqpFval = TrialState->sqpFval_old;
      for (k = 0; k < 7; k++) {
        TrialState->xstarsqp[k] = TrialState->xstarsqp_old[k];
      }

      b_st.site = &gj_emlrtRSI;
      TrialState->cIneq = TrialState->cIneq_old;
    }

    st.site = &ld_emlrtRSI;
    b_test_exit(&st, &Flags, memspace, MeritFunction, WorkingSet, TrialState,
                QRManager, lb, ub);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      st.site = &ld_emlrtRSI;
      b_st.site = &hj_emlrtRSI;
      if ((1 <= nVar) && (nVar > 2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      if (0 <= nVar - 1) {
        memcpy(&TrialState->delta_gradLag[0], &TrialState->grad[0], nVar *
               sizeof(real_T));
      }

      if (nVar >= 1) {
        ixlast = nVar - 1;
        for (k = 0; k <= ixlast; k++) {
          TrialState->delta_gradLag[k] += -TrialState->grad_old[k];
        }
      }

      st.site = &ld_emlrtRSI;
      b_st.site = &if_emlrtRSI;
      b_st.site = &if_emlrtRSI;
      st.site = &ld_emlrtRSI;
      BFGSUpdate(&st, nVar, Hessian, TrialState->delta_x,
                 TrialState->delta_gradLag, memspace->workspace_double);
      TrialState->sqpIterations++;
    }
  }
}

/* End of code generation (driver.c) */
