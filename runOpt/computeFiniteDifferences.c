/*
 * computeFiniteDifferences.c
 *
 * Code generation for function 'computeFiniteDifferences'
 *
 */

/* Include files */
#include "computeFiniteDifferences.h"
#include "finDiffEvalAndChkErr.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"

/* Variable Definitions */
static emlrtRSInfo wc_emlrtRSI = { 1,  /* lineNo */
  "computeFiniteDifferences",          /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+utils\\+FiniteDifferences\\computeFiniteDifferences.p"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 1,  /* lineNo */
  "computeForwardDifferences",         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+utils\\+FiniteDifferences\\+internal\\computeForwardDifferences.p"/* pathName */
};

/* Function Definitions */
boolean_T computeFiniteDifferences(const emlrtStack *sp, d_struct_T *obj, real_T
  fCurrent, real_T xk[7], real_T gradf[9], const real_T lb[7], const real_T ub[7])
{
  boolean_T evalOK;
  int32_T idx;
  boolean_T exitg1;
  boolean_T modifiedStep;
  real_T deltaX;
  real_T t0_objfun_tunableEnvironment_f1[3];
  real_T ubDiff;
  int32_T i;
  real_T d;
  real_T t0_objfun_tunableEnvironment_f3[3];
  real_T t0_objfun_tunableEnvironment_f2[7];
  boolean_T guard1 = false;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  evalOK = true;
  obj->numEvals = 0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 7)) {
    modifiedStep = false;
    deltaX = 1.4901161193847656E-8 * (1.0 - 2.0 * (real_T)(xk[idx] < 0.0)) *
      muDoubleScalarMax(muDoubleScalarAbs(xk[idx]), 1.0);
    if (obj->hasLB[idx] || obj->hasUB[idx]) {
      if (obj->hasLB[idx] && obj->hasUB[idx]) {
        ubDiff = deltaX;
        if ((lb[idx] != ub[idx]) && (xk[idx] >= lb[idx]) && (xk[idx] <= ub[idx])
            && ((xk[idx] + deltaX > ub[idx]) || (xk[idx] + deltaX < lb[idx]))) {
          ubDiff = -deltaX;
          modifiedStep = true;
          d = xk[idx] + -deltaX;
          if ((d > ub[idx]) || (d < lb[idx])) {
            deltaX = xk[idx] - lb[idx];
            ubDiff = ub[idx] - xk[idx];
            if (deltaX <= ubDiff) {
              ubDiff = -deltaX;
            }
          }
        }

        deltaX = ubDiff;
      } else if (obj->hasUB[idx]) {
        if ((xk[idx] <= ub[idx]) && (xk[idx] + deltaX > ub[idx])) {
          deltaX = -deltaX;
          modifiedStep = true;
        }
      } else {
        if ((xk[idx] >= lb[idx]) && (xk[idx] + deltaX < lb[idx])) {
          deltaX = -deltaX;
          modifiedStep = true;
        }
      }
    }

    t0_objfun_tunableEnvironment_f1[0] = obj->objfun.tunableEnvironment.f1[0];
    t0_objfun_tunableEnvironment_f1[1] = obj->objfun.tunableEnvironment.f1[1];
    t0_objfun_tunableEnvironment_f1[2] = obj->objfun.tunableEnvironment.f1[2];
    for (i = 0; i < 7; i++) {
      t0_objfun_tunableEnvironment_f2[i] = obj->objfun.tunableEnvironment.f2[i];
    }

    t0_objfun_tunableEnvironment_f3[0] = obj->objfun.tunableEnvironment.f3[0];
    t0_objfun_tunableEnvironment_f3[1] = obj->objfun.tunableEnvironment.f3[1];
    t0_objfun_tunableEnvironment_f3[2] = obj->objfun.tunableEnvironment.f3[2];
    b_st.site = &xc_emlrtRSI;
    evalOK = finDiffEvalAndChkErr(&b_st, t0_objfun_tunableEnvironment_f1,
      t0_objfun_tunableEnvironment_f2, t0_objfun_tunableEnvironment_f3,
      &obj->f_1, idx + 1, deltaX, xk);
    obj->numEvals++;
    guard1 = false;
    if (!evalOK) {
      if (!modifiedStep) {
        deltaX = -deltaX;
        if (obj->hasLB[idx]) {
          d = xk[idx] + deltaX;
          if ((d >= lb[idx]) && obj->hasUB[idx] && (d <= ub[idx])) {
            modifiedStep = true;
          } else {
            modifiedStep = false;
          }
        } else {
          modifiedStep = false;
        }

        if ((!obj->hasBounds) || modifiedStep) {
          t0_objfun_tunableEnvironment_f1[0] = obj->
            objfun.tunableEnvironment.f1[0];
          t0_objfun_tunableEnvironment_f1[1] = obj->
            objfun.tunableEnvironment.f1[1];
          t0_objfun_tunableEnvironment_f1[2] = obj->
            objfun.tunableEnvironment.f1[2];
          for (i = 0; i < 7; i++) {
            t0_objfun_tunableEnvironment_f2[i] =
              obj->objfun.tunableEnvironment.f2[i];
          }

          t0_objfun_tunableEnvironment_f3[0] = obj->
            objfun.tunableEnvironment.f3[0];
          t0_objfun_tunableEnvironment_f3[1] = obj->
            objfun.tunableEnvironment.f3[1];
          t0_objfun_tunableEnvironment_f3[2] = obj->
            objfun.tunableEnvironment.f3[2];
          b_st.site = &xc_emlrtRSI;
          evalOK = finDiffEvalAndChkErr(&b_st, t0_objfun_tunableEnvironment_f1,
            t0_objfun_tunableEnvironment_f2, t0_objfun_tunableEnvironment_f3,
            &obj->f_1, idx + 1, deltaX, xk);
          obj->numEvals++;
        }
      }

      if (!evalOK) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      gradf[idx] = (obj->f_1 - fCurrent) / deltaX;
      idx++;
    }
  }

  return evalOK;
}

/* End of code generation (computeFiniteDifferences.c) */
