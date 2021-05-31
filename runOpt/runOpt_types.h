/*
 * runOpt_types.h
 *
 * Code generation for function 'runOpt_types'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  real_T workspace_double[153];
  int32_T workspace_int[17];
  int32_T workspace_sort[17];
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef typedef_cell_1
#define typedef_cell_1

typedef struct {
  real_T f1[3];
  real_T f2[7];
  real_T f3[3];
} cell_1;

#endif                                 /*typedef_cell_1*/

#ifndef typedef_c_coder_internal_anonymous_func
#define typedef_c_coder_internal_anonymous_func

typedef struct {
  cell_1 tunableEnvironment;
} c_coder_internal_anonymous_func;

#endif                                 /*typedef_c_coder_internal_anonymous_func*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct {
  char_T SolverName[7];
  int32_T MaxIterations;
  real_T StepTolerance;
  real_T OptimalityTolerance;
  real_T ConstraintTolerance;
  real_T ObjectiveLimit;
  real_T PricingTolerance;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
  boolean_T RemainFeasible;
  boolean_T IterDisplayQP;
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef typedef_d_struct_T
#define typedef_d_struct_T

typedef struct {
  c_coder_internal_anonymous_func objfun;
  real_T f_1;
  real_T f_2;
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T hasLB[7];
  boolean_T hasUB[7];
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
} d_struct_T;

#endif                                 /*typedef_d_struct_T*/

#ifndef typedef_e_struct_T
#define typedef_e_struct_T

typedef struct {
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T Aineq[9];
  real_T bineq;
  real_T lb[9];
  real_T ub[9];
  int32_T indexLB[9];
  int32_T indexUB[9];
  int32_T indexFixed[9];
  int32_T mEqRemoved;
  real_T ATwset[153];
  real_T bwset[17];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[17];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[17];
  int32_T Wid[17];
  int32_T Wlocalidx[17];
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
} e_struct_T;

#endif                                 /*typedef_e_struct_T*/

#ifndef typedef_f_struct_T
#define typedef_f_struct_T

typedef struct {
  int32_T nVarMax;
  int32_T mNonlinIneq;
  int32_T mNonlinEq;
  int32_T mIneq;
  int32_T mEq;
  int32_T iNonIneq0;
  int32_T iNonEq0;
  real_T sqpFval;
  real_T sqpFval_old;
  real_T xstarsqp[7];
  real_T xstarsqp_old[7];
  real_T cIneq;
  real_T cIneq_old;
  real_T grad[9];
  real_T grad_old[9];
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  real_T lambdasqp[17];
  real_T lambdasqp_old[17];
  real_T steplength;
  real_T delta_x[9];
  real_T socDirection[9];
  real_T lambda_old[17];
  int32_T workingset_old[17];
  real_T gradLag[9];
  real_T delta_gradLag[9];
  real_T xstar[9];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[17];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[9];
} f_struct_T;

#endif                                 /*typedef_f_struct_T*/

#ifndef typedef_g_struct_T
#define typedef_g_struct_T

typedef struct {
  c_coder_internal_anonymous_func objfun;
  int32_T nVar;
  int32_T mCineq;
  int32_T mCeq;
  boolean_T NonFiniteSupport;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T ScaleProblem;
} g_struct_T;

#endif                                 /*typedef_g_struct_T*/

#ifndef typedef_h_struct_T
#define typedef_h_struct_T

typedef struct {
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationEq;
  real_T initConstrViolationIneq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
  real_T firstOrderOpt;
  boolean_T hasObjective;
} h_struct_T;

#endif                                 /*typedef_h_struct_T*/

#ifndef typedef_i_struct_T
#define typedef_i_struct_T

typedef struct {
  int32_T ldq;
  real_T QR[289];
  real_T Q[289];
  int32_T jpvt[17];
  int32_T mrows;
  int32_T ncols;
  real_T tau[17];
  int32_T minRowCol;
  boolean_T usedPivoting;
} i_struct_T;

#endif                                 /*typedef_i_struct_T*/

#ifndef typedef_j_struct_T
#define typedef_j_struct_T

typedef struct {
  real_T grad[9];
  real_T Hx[8];
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
} j_struct_T;

#endif                                 /*typedef_j_struct_T*/

#ifndef typedef_k_struct_T
#define typedef_k_struct_T

typedef struct {
  real_T FMat[289];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
} k_struct_T;

#endif                                 /*typedef_k_struct_T*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
} struct_T;

#endif                                 /*typedef_struct_T*/

/* End of code generation (runOpt_types.h) */
