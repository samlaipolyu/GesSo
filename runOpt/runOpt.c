/*
 * runOpt.c
 *
 * Code generation for function 'runOpt'
 *
 */

/* Include files */
#include "runOpt.h"
#include "checkLinearInputs.h"
#include "computeFiniteDifferences.h"
#include "computeObjective_.h"
#include "driver.h"
#include "factoryConstruct.h"
#include "factoryConstruct1.h"
#include "initActiveSet.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 8,     /* lineNo */
  "runOpt",                            /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\matleap 4.0\\runOpt.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 1,   /* lineNo */
  "fmincon",                           /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\eml\\fmincon.p"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 1,   /* lineNo */
  "evalObjAndConstrAndDerivatives",    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\evalObjAndConstrAndDerivatives.p"/* pathName */
};

static emlrtRTEInfo i_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "fmincon",                           /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\eml\\fmincon.p"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "compressBounds",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\compressBounds.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void runOpt(const emlrtStack *sp, const real_T task[3], real_T q_prev[7], const
            real_T x0[7], const real_T A[7], real_T b, const real_T lb[7], const
            real_T ub[7], const real_T set_angle[3], real_T q[7])
{
  int32_T i;
  real_T fun_tunableEnvironment_f2[7];
  f_struct_T TrialState;
  g_struct_T FcnEvaluator;
  int32_T k;
  int32_T mUB;
  int32_T mFixed;
  boolean_T guard1 = false;
  int32_T indexLB[7];
  int32_T indexUB[7];
  int32_T indexFixed[7];
  e_struct_T WorkingSet;
  int32_T b_i;
  real_T b_TrialState[7];
  d_struct_T FiniteDifferences;
  real_T c;
  int32_T ia;
  real_T d;
  h_struct_T MeritFunction;
  i_struct_T s;
  j_struct_T QPObjective;
  b_struct_T memspace;
  real_T Hessian[49];
  k_struct_T CholManager;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (i = 0; i < 7; i++) {
    fun_tunableEnvironment_f2[i] = q_prev[i];
  }

  st.site = &emlrtRSI;
  b_st.site = &b_emlrtRSI;
  checkLinearInputs(&b_st, x0, A, b, lb, ub);
  TrialState.nVarMax = 9;
  TrialState.mNonlinIneq = 0;
  TrialState.mNonlinEq = 0;
  TrialState.mIneq = 1;
  TrialState.mEq = 0;
  TrialState.iNonIneq0 = 2;
  TrialState.iNonEq0 = 1;
  TrialState.sqpFval_old = 0.0;
  for (i = 0; i < 7; i++) {
    TrialState.xstarsqp_old[i] = 0.0;
  }

  TrialState.cIneq = 0.0;
  TrialState.cIneq_old = 0.0;
  memset(&TrialState.grad[0], 0, 9U * sizeof(real_T));
  memset(&TrialState.grad_old[0], 0, 9U * sizeof(real_T));
  TrialState.FunctionEvaluations = 0;
  TrialState.sqpIterations = 0;
  TrialState.sqpExitFlag = 0;
  memset(&TrialState.lambdasqp[0], 0, 17U * sizeof(real_T));
  memset(&TrialState.lambdasqp_old[0], 0, 17U * sizeof(real_T));
  TrialState.steplength = 1.0;
  memset(&TrialState.delta_x[0], 0, 9U * sizeof(real_T));
  memset(&TrialState.socDirection[0], 0, 9U * sizeof(real_T));
  memset(&TrialState.lambda_old[0], 0, 17U * sizeof(real_T));
  memset(&TrialState.workingset_old[0], 0, 17U * sizeof(int32_T));
  memset(&TrialState.gradLag[0], 0, 9U * sizeof(real_T));
  memset(&TrialState.delta_gradLag[0], 0, 9U * sizeof(real_T));
  memset(&TrialState.xstar[0], 0, 9U * sizeof(real_T));
  TrialState.fstar = 0.0;
  TrialState.firstorderopt = 0.0;
  memset(&TrialState.lambda[0], 0, 17U * sizeof(real_T));
  TrialState.state = 0;
  TrialState.maxConstr = 0.0;
  TrialState.iterations = 0;
  memset(&TrialState.searchDir[0], 0, 9U * sizeof(real_T));
  FcnEvaluator.objfun.tunableEnvironment.f1[0] = task[0];
  FcnEvaluator.objfun.tunableEnvironment.f1[1] = task[1];
  FcnEvaluator.objfun.tunableEnvironment.f1[2] = task[2];
  for (k = 0; k < 7; k++) {
    TrialState.xstarsqp[k] = x0[k];
    FcnEvaluator.objfun.tunableEnvironment.f2[k] = fun_tunableEnvironment_f2[k];
  }

  FcnEvaluator.objfun.tunableEnvironment.f3[0] = set_angle[0];
  FcnEvaluator.objfun.tunableEnvironment.f3[1] = set_angle[1];
  FcnEvaluator.objfun.tunableEnvironment.f3[2] = set_angle[2];
  FcnEvaluator.nVar = 7;
  FcnEvaluator.mCineq = 0;
  FcnEvaluator.mCeq = 0;
  FcnEvaluator.NonFiniteSupport = true;
  FcnEvaluator.SpecifyObjectiveGradient = false;
  FcnEvaluator.SpecifyConstraintGradient = false;
  FcnEvaluator.ScaleProblem = false;
  b_st.site = &b_emlrtRSI;
  k = 0;
  mUB = 0;
  mFixed = 0;
  for (i = 0; i < 7; i++) {
    guard1 = false;
    if ((!muDoubleScalarIsInf(lb[i])) && (!muDoubleScalarIsNaN(lb[i]))) {
      if (muDoubleScalarAbs(lb[i] - ub[i]) < 1.0E-6) {
        mFixed++;
        if (mFixed > 7) {
          emlrtDynamicBoundsCheckR2012b(8, 1, 7, &e_emlrtBCI, &b_st);
        }

        indexFixed[mFixed - 1] = i + 1;
      } else {
        k++;
        if (k > 7) {
          emlrtDynamicBoundsCheckR2012b(8, 1, 7, &e_emlrtBCI, &b_st);
        }

        indexLB[k - 1] = i + 1;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 && ((!muDoubleScalarIsInf(ub[i])) && (!muDoubleScalarIsNaN(ub[i]))))
    {
      mUB++;
      if (mUB > 7) {
        emlrtDynamicBoundsCheckR2012b(8, 1, 7, &e_emlrtBCI, &b_st);
      }

      indexUB[mUB - 1] = i + 1;
    }
  }

  b_st.site = &b_emlrtRSI;
  b_factoryConstruct(&b_st, A, k, indexLB, mUB, indexUB, mFixed, indexFixed,
                     &WorkingSet);
  b_st.site = &b_emlrtRSI;
  for (i = 0; i < k; i++) {
    TrialState.xstarsqp[WorkingSet.indexLB[i] - 1] = muDoubleScalarMax
      (TrialState.xstarsqp[WorkingSet.indexLB[i] - 1], lb[WorkingSet.indexLB[i]
       - 1]);
  }

  b_st.site = &b_emlrtRSI;
  for (i = 0; i < mUB; i++) {
    TrialState.xstarsqp[WorkingSet.indexUB[i] - 1] = muDoubleScalarMin
      (TrialState.xstarsqp[WorkingSet.indexUB[i] - 1], ub[WorkingSet.indexUB[i]
       - 1]);
  }

  b_st.site = &b_emlrtRSI;
  for (i = 0; i < mFixed; i++) {
    TrialState.xstarsqp[WorkingSet.indexFixed[i] - 1] =
      ub[WorkingSet.indexFixed[i] - 1];
  }

  b_st.site = &b_emlrtRSI;
  for (b_i = 0; b_i < 7; b_i++) {
    b_TrialState[b_i] = TrialState.xstarsqp[b_i];
  }

  c_st.site = &j_emlrtRSI;
  computeObjective_(&c_st, FcnEvaluator.objfun.tunableEnvironment.f1,
                    FcnEvaluator.objfun.tunableEnvironment.f2,
                    FcnEvaluator.objfun.tunableEnvironment.f3, b_TrialState,
                    &TrialState.sqpFval, &i);
  if (i == 1) {
    i = 1;
  }

  if (i != 1) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
      "optim_codegen:fmincon:UndefAtX0", "optim_codegen:fmincon:UndefAtX0", 0);
  }

  factoryConstruct(task, fun_tunableEnvironment_f2, set_angle, lb, ub,
                   &FiniteDifferences);
  b_st.site = &b_emlrtRSI;
  computeFiniteDifferences(&b_st, &FiniteDifferences, TrialState.sqpFval,
    TrialState.xstarsqp, TrialState.grad, lb, ub);
  TrialState.FunctionEvaluations = FiniteDifferences.numEvals + 1;
  b_st.site = &b_emlrtRSI;
  i = 0;
  c = 0.0;
  for (ia = 0; ia < 7; ia++) {
    c += WorkingSet.Aineq[ia] * TrialState.xstarsqp[i];
    i++;
  }

  c += -b;
  TrialState.cIneq = c;
  b_st.site = &b_emlrtRSI;
  WorkingSet.bineq = -c;
  for (i = 0; i < k; i++) {
    WorkingSet.lb[WorkingSet.indexLB[i] - 1] = -lb[WorkingSet.indexLB[i] - 1] +
      x0[WorkingSet.indexLB[i] - 1];
  }

  for (i = 0; i < mUB; i++) {
    WorkingSet.ub[WorkingSet.indexUB[i] - 1] = ub[WorkingSet.indexUB[i] - 1] -
      x0[WorkingSet.indexUB[i] - 1];
  }

  for (i = 0; i < mFixed; i++) {
    d = ub[WorkingSet.indexFixed[i] - 1] - x0[WorkingSet.indexFixed[i] - 1];
    WorkingSet.ub[WorkingSet.indexFixed[i] - 1] = d;
    WorkingSet.bwset[i] = d;
  }

  b_st.site = &b_emlrtRSI;
  initActiveSet(&b_st, &WorkingSet);
  MeritFunction.initFval = TrialState.sqpFval;
  MeritFunction.penaltyParam = 1.0;
  MeritFunction.threshold = 0.0001;
  MeritFunction.nPenaltyDecreases = 0;
  MeritFunction.linearizedConstrViol = 0.0;
  MeritFunction.initConstrViolationEq = 0.0;
  MeritFunction.initConstrViolationIneq = 0.0;
  if (c > 0.0) {
    MeritFunction.initConstrViolationIneq = c;
  }

  MeritFunction.phi = 0.0;
  MeritFunction.phiPrimePlus = 0.0;
  MeritFunction.phiFullStep = 0.0;
  MeritFunction.feasRelativeFactor = 0.0;
  MeritFunction.nlpPrimalFeasError = 0.0;
  MeritFunction.nlpDualFeasError = 0.0;
  MeritFunction.nlpComplError = 0.0;
  MeritFunction.firstOrderOpt = 0.0;
  MeritFunction.hasObjective = true;
  s.ldq = 17;
  memset(&s.QR[0], 0, 289U * sizeof(real_T));
  memset(&s.Q[0], 0, 289U * sizeof(real_T));
  s.mrows = 0;
  s.ncols = 0;
  memset(&s.jpvt[0], 0, 17U * sizeof(int32_T));
  memset(&s.tau[0], 0, 17U * sizeof(real_T));
  s.minRowCol = 0;
  s.usedPivoting = false;
  memset(&QPObjective.grad[0], 0, 9U * sizeof(real_T));
  memset(&QPObjective.Hx[0], 0, 8U * sizeof(real_T));
  QPObjective.hasLinear = true;
  QPObjective.nvar = 7;
  QPObjective.maxVar = 9;
  QPObjective.beta = 0.0;
  QPObjective.rho = 0.0;
  QPObjective.objtype = 3;
  QPObjective.prev_objtype = 3;
  QPObjective.prev_nvar = 0;
  QPObjective.prev_hasLinear = false;
  QPObjective.gammaScalar = 0.0;
  b_st.site = &b_emlrtRSI;
  driver(&b_st, b, lb, ub, &TrialState, &MeritFunction, &FcnEvaluator,
         &FiniteDifferences, &memspace, &WorkingSet, &s, &QPObjective, Hessian,
         &CholManager);
  for (i = 0; i < 7; i++) {
    q[i] = TrialState.xstarsqp[i];
  }

  /*  //'interior-point-convex'; */
  for (i = 0; i < 7; i++) {
    q_prev[i] = TrialState.xstarsqp[i];
  }
}

/* End of code generation (runOpt.c) */
