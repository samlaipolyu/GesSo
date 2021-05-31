/*
 * test_exit.c
 *
 * Code generation for function 'test_exit'
 *
 */

/* Include files */
#include "test_exit.h"
#include "computeComplError.h"
#include "computeDualFeasError.h"
#include "computeGradLag.h"
#include "computePrimalFeasError.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQRE.h"
#include "isDeltaXTooSmall.h"
#include "ixamax.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "xgemv.h"
#include "xtrsv.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo md_emlrtRSI = { 1,  /* lineNo */
  "test_exit",                         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\test_exit.p"/* pathName */
};

static emlrtRSInfo bf_emlrtRSI = { 1,  /* lineNo */
  "computeLambdaLSQ",                  /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeLambdaLSQ.p"/* pathName */
};

static emlrtBCInfo yd_emlrtBCI = { 1,  /* iFirst */
  289,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeLambdaLSQ",                  /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeLambdaLSQ.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "test_exit",                         /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\test_exit.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void b_test_exit(const emlrtStack *sp, struct_T *Flags, b_struct_T *memspace,
                 h_struct_T *MeritFunction, const e_struct_T *WorkingSet,
                 f_struct_T *TrialState, i_struct_T *QRManager, const real_T lb
                 [7], const real_T ub[7])
{
  int32_T mFixed;
  int32_T mLambda;
  int32_T idx_max;
  real_T optimRelativeFactor;
  boolean_T isFeasible;
  boolean_T dxTooSmall;
  real_T tol;
  real_T nlpComplErrorTmp;
  real_T d;
  boolean_T guard1 = false;
  real_T dv[153];
  int32_T rankR;
  int32_T iQR_diag;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  mFixed = WorkingSet->sizes[0];
  mLambda = ((WorkingSet->sizes[0] + WorkingSet->sizes[3]) + WorkingSet->sizes[4])
    + 1;
  st.site = &md_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aineq, WorkingSet->indexFixed, WorkingSet->sizes[0],
                 WorkingSet->indexLB, WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdasqp);
  st.site = &md_emlrtRSI;
  idx_max = ixamax(&st, WorkingSet->nVar, TrialState->grad);
  optimRelativeFactor = muDoubleScalarMax(1.0, muDoubleScalarAbs
    (TrialState->grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }

  st.site = &md_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(&st,
    TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
    WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub);
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor = muDoubleScalarMax(1.0,
      MeritFunction->nlpPrimalFeasError);
  }

  isFeasible = (MeritFunction->nlpPrimalFeasError <= 1.0E-6 *
                MeritFunction->feasRelativeFactor);
  st.site = &md_emlrtRSI;
  computeDualFeasError(&st, WorkingSet->nVar, TrialState->gradLag,
                       &Flags->gradOK, &MeritFunction->nlpDualFeasError);
  if (!Flags->gradOK) {
    Flags->done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    st.site = &md_emlrtRSI;
    MeritFunction->nlpComplError = computeComplError(&st, TrialState->xstarsqp,
      TrialState->cIneq, WorkingSet->indexLB, WorkingSet->sizes[3], lb,
      WorkingSet->indexUB, WorkingSet->sizes[4], ub, TrialState->lambdasqp,
      WorkingSet->sizes[0] + 1);
    MeritFunction->firstOrderOpt = muDoubleScalarMax
      (MeritFunction->nlpDualFeasError, MeritFunction->nlpComplError);
    if (TrialState->sqpIterations > 1) {
      st.site = &md_emlrtRSI;
      b_computeGradLag(&st, memspace->workspace_double, WorkingSet->nVar,
                       TrialState->grad, WorkingSet->Aineq,
                       WorkingSet->indexFixed, WorkingSet->sizes[0],
                       WorkingSet->indexLB, WorkingSet->sizes[3],
                       WorkingSet->indexUB, WorkingSet->sizes[4],
                       TrialState->lambdasqp_old);
      st.site = &md_emlrtRSI;
      b_computeDualFeasError(&st, WorkingSet->nVar, memspace->workspace_double,
        &dxTooSmall, &tol);
      st.site = &md_emlrtRSI;
      nlpComplErrorTmp = computeComplError(&st, TrialState->xstarsqp,
        TrialState->cIneq, WorkingSet->indexLB, WorkingSet->sizes[3], lb,
        WorkingSet->indexUB, WorkingSet->sizes[4], ub, TrialState->lambdasqp_old,
        WorkingSet->sizes[0] + 1);
      d = muDoubleScalarMax(tol, nlpComplErrorTmp);
      if (d < muDoubleScalarMax(MeritFunction->nlpDualFeasError,
           MeritFunction->nlpComplError)) {
        MeritFunction->nlpDualFeasError = tol;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        MeritFunction->firstOrderOpt = d;
        st.site = &md_emlrtRSI;
        b_xcopy(&st, mLambda, TrialState->lambdasqp_old, TrialState->lambdasqp);
      } else {
        st.site = &md_emlrtRSI;
        b_xcopy(&st, mLambda, TrialState->lambdasqp, TrialState->lambdasqp_old);
      }
    } else {
      st.site = &md_emlrtRSI;
      b_xcopy(&st, mLambda, TrialState->lambdasqp, TrialState->lambdasqp_old);
    }

    if (isFeasible && (MeritFunction->nlpDualFeasError <= 1.0E-6 *
                       optimRelativeFactor) && (MeritFunction->nlpComplError <=
         1.0E-6 * optimRelativeFactor)) {
      Flags->done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags->done = false;
      guard1 = false;
      if (TrialState->sqpIterations > 0) {
        st.site = &md_emlrtRSI;
        dxTooSmall = isDeltaXTooSmall(&st, TrialState->xstarsqp,
          TrialState->delta_x, WorkingSet->nVar);
        if (dxTooSmall) {
          if (!isFeasible) {
            if (Flags->stepType != 2) {
              Flags->stepType = 2;
              Flags->failedLineSearch = false;
              Flags->stepAccepted = false;
              guard1 = true;
            } else {
              Flags->done = true;
              TrialState->sqpExitFlag = -2;
            }
          } else if (WorkingSet->nActiveConstr > 0) {
            st.site = &md_emlrtRSI;
            b_st.site = &bf_emlrtRSI;
            c_xcopy(&b_st, WorkingSet->nActiveConstr, TrialState->lambda);
            b_st.site = &bf_emlrtRSI;
            factorQRE(&b_st, QRManager, WorkingSet->ATwset, WorkingSet->nVar,
                      WorkingSet->nActiveConstr);
            b_st.site = &bf_emlrtRSI;
            c_st.site = &cf_emlrtRSI;
            computeQ_(&c_st, QRManager, QRManager->mrows);
            memcpy(&dv[0], &memspace->workspace_double[0], 153U * sizeof(real_T));
            b_st.site = &bf_emlrtRSI;
            xgemv(&b_st, WorkingSet->nVar, WorkingSet->nVar, QRManager->Q,
                  TrialState->grad, dv);
            tol = muDoubleScalarAbs(QRManager->QR[0]) * muDoubleScalarMin
              (1.4901161193847656E-8, (real_T)muIntScalarMax_sint32
               (WorkingSet->nVar, WorkingSet->nActiveConstr) *
               2.2204460492503131E-16);
            idx_max = muIntScalarMin_sint32(WorkingSet->nVar,
              WorkingSet->nActiveConstr);
            rankR = 0;
            iQR_diag = 1;
            exitg1 = false;
            while ((!exitg1) && (rankR < idx_max)) {
              if (iQR_diag > 289) {
                emlrtDynamicBoundsCheckR2012b(iQR_diag, 1, 289, &yd_emlrtBCI,
                  &st);
              }

              if (muDoubleScalarAbs(QRManager->QR[iQR_diag - 1]) > tol) {
                rankR++;
                iQR_diag += 18;
              } else {
                exitg1 = true;
              }
            }

            b_st.site = &bf_emlrtRSI;
            xtrsv(rankR, QRManager->QR, dv);
            idx_max = muIntScalarMin_sint32(WorkingSet->nActiveConstr, idx_max);
            b_st.site = &bf_emlrtRSI;
            if ((1 <= idx_max) && (idx_max > 2147483646)) {
              c_st.site = &d_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            for (rankR = 0; rankR < idx_max; rankR++) {
              if ((QRManager->jpvt[rankR] < 1) || (QRManager->jpvt[rankR] > 17))
              {
                emlrtDynamicBoundsCheckR2012b(QRManager->jpvt[rankR], 1, 17,
                  &ae_emlrtBCI, &st);
              }

              TrialState->lambda[QRManager->jpvt[rankR] - 1] = dv[rankR];
            }

            idx_max = WorkingSet->sizes[0] + 1;
            st.site = &md_emlrtRSI;
            if ((WorkingSet->sizes[0] + 1 <= WorkingSet->sizes[0]) &&
                (WorkingSet->sizes[0] > 2147483646)) {
              b_st.site = &d_emlrtRSI;
              check_forloop_overflow_error(&b_st);
            }

            for (rankR = idx_max; rankR <= mFixed; rankR++) {
              TrialState->lambda[rankR - 1] = -TrialState->lambda[rankR - 1];
            }

            memcpy(&memspace->workspace_double[0], &dv[0], 153U * sizeof(real_T));
            st.site = &md_emlrtRSI;
            sortLambdaQP(&st, TrialState->lambda, WorkingSet->nActiveConstr,
                         WorkingSet->sizes, WorkingSet->isActiveIdx,
                         WorkingSet->Wid, WorkingSet->Wlocalidx,
                         memspace->workspace_double);
            st.site = &md_emlrtRSI;
            b_computeGradLag(&st, memspace->workspace_double, WorkingSet->nVar,
                             TrialState->grad, WorkingSet->Aineq,
                             WorkingSet->indexFixed, WorkingSet->sizes[0],
                             WorkingSet->indexLB, WorkingSet->sizes[3],
                             WorkingSet->indexUB, WorkingSet->sizes[4],
                             TrialState->lambda);
            st.site = &md_emlrtRSI;
            b_computeDualFeasError(&st, WorkingSet->nVar,
              memspace->workspace_double, &dxTooSmall, &tol);
            st.site = &md_emlrtRSI;
            nlpComplErrorTmp = computeComplError(&st, TrialState->xstarsqp,
              TrialState->cIneq, WorkingSet->indexLB, WorkingSet->sizes[3], lb,
              WorkingSet->indexUB, WorkingSet->sizes[4], ub, TrialState->lambda,
              WorkingSet->sizes[0] + 1);
            if ((tol <= 1.0E-6 * optimRelativeFactor) && (nlpComplErrorTmp <=
                 1.0E-6 * optimRelativeFactor)) {
              MeritFunction->nlpDualFeasError = tol;
              MeritFunction->nlpComplError = nlpComplErrorTmp;
              MeritFunction->firstOrderOpt = muDoubleScalarMax(tol,
                nlpComplErrorTmp);
              st.site = &md_emlrtRSI;
              b_xcopy(&st, mLambda, TrialState->lambda, TrialState->lambdasqp);
              Flags->done = true;
              TrialState->sqpExitFlag = 1;
            } else {
              Flags->done = true;
              TrialState->sqpExitFlag = 2;
            }
          } else {
            Flags->done = true;
            TrialState->sqpExitFlag = 2;
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        if (TrialState->sqpIterations >= 400) {
          Flags->done = true;
          TrialState->sqpExitFlag = 0;
        } else {
          if (TrialState->FunctionEvaluations >= 700) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          }
        }
      }
    }
  }
}

void test_exit(const emlrtStack *sp, h_struct_T *MeritFunction, const e_struct_T
               *WorkingSet, f_struct_T *TrialState, const real_T lb[7], const
               real_T ub[7], boolean_T *Flags_gradOK, boolean_T *Flags_fevalOK,
               boolean_T *Flags_done, boolean_T *Flags_stepAccepted, boolean_T
               *Flags_failedLineSearch, int32_T *Flags_stepType)
{
  int32_T idx_max;
  real_T optimRelativeFactor;
  boolean_T isFeasible;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  *Flags_fevalOK = true;
  *Flags_done = false;
  *Flags_stepAccepted = false;
  *Flags_failedLineSearch = false;
  *Flags_stepType = 1;
  st.site = &md_emlrtRSI;
  computeGradLag(&st, TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
                 WorkingSet->Aineq, WorkingSet->indexFixed, WorkingSet->sizes[0],
                 WorkingSet->indexLB, WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdasqp);
  st.site = &md_emlrtRSI;
  idx_max = ixamax(&st, WorkingSet->nVar, TrialState->grad);
  optimRelativeFactor = muDoubleScalarMax(1.0, muDoubleScalarAbs
    (TrialState->grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }

  st.site = &md_emlrtRSI;
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(&st,
    TrialState->xstarsqp, TrialState->cIneq, WorkingSet->indexLB,
    WorkingSet->sizes[3], lb, WorkingSet->indexUB, WorkingSet->sizes[4], ub);
  MeritFunction->feasRelativeFactor = muDoubleScalarMax(1.0,
    MeritFunction->nlpPrimalFeasError);
  isFeasible = (MeritFunction->nlpPrimalFeasError <= 1.0E-6 *
                MeritFunction->feasRelativeFactor);
  st.site = &md_emlrtRSI;
  computeDualFeasError(&st, WorkingSet->nVar, TrialState->gradLag, Flags_gradOK,
                       &MeritFunction->nlpDualFeasError);
  if (!*Flags_gradOK) {
    *Flags_done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    st.site = &md_emlrtRSI;
    computeComplError(&st, TrialState->xstarsqp, TrialState->cIneq,
                      WorkingSet->indexLB, WorkingSet->sizes[3], lb,
                      WorkingSet->indexUB, WorkingSet->sizes[4], ub,
                      TrialState->lambdasqp, WorkingSet->sizes[0] + 1);
    MeritFunction->nlpComplError = 0.0;
    MeritFunction->firstOrderOpt = muDoubleScalarMax
      (MeritFunction->nlpDualFeasError, 0.0);
    st.site = &md_emlrtRSI;
    b_xcopy(&st, ((WorkingSet->sizes[0] + WorkingSet->sizes[3]) +
                  WorkingSet->sizes[4]) + 1, TrialState->lambdasqp,
            TrialState->lambdasqp_old);
    if (isFeasible && (MeritFunction->nlpDualFeasError <= 1.0E-6 *
                       optimRelativeFactor)) {
      *Flags_done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      if (TrialState->FunctionEvaluations >= 700) {
        *Flags_done = true;
        TrialState->sqpExitFlag = 0;
      }
    }
  }
}

/* End of code generation (test_exit.c) */
