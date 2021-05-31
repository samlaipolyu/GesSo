/*
 * computeComplError.c
 *
 * Code generation for function 'computeComplError'
 *
 */

/* Include files */
#include "computeComplError.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo ud_emlrtRSI = { 1,  /* lineNo */
  "computeComplError",                 /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeComplError.p"/* pathName */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeComplError",                 /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeComplError.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeComplError",                 /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeComplError.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T computeComplError(const emlrtStack *sp, const real_T xCurrent[7], real_T
  cIneq, const int32_T finiteLB[9], int32_T mLB, const real_T lb[7], const
  int32_T finiteUB[9], int32_T mUB, const real_T ub[7], const real_T lambda[17],
  int32_T iL0)
{
  real_T nlpComplError;
  real_T lbDelta;
  int32_T ubOffset;
  int32_T idx;
  real_T lbLambda;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  lbDelta = lambda[iL0 - 1];
  nlpComplError = muDoubleScalarMax(0.0, muDoubleScalarMin(muDoubleScalarAbs
    (cIneq * lbDelta), muDoubleScalarMin(muDoubleScalarAbs(cIneq), lbDelta)));
  ubOffset = (iL0 + mLB) + 1;
  st.site = &ud_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    if ((finiteLB[idx] < 1) || (finiteLB[idx] > 7)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, 7, &b_emlrtBCI, sp);
    }

    lbDelta = xCurrent[finiteLB[idx] - 1] - lb[finiteLB[idx] - 1];
    lbLambda = lambda[iL0 + idx];
    nlpComplError = muDoubleScalarMax(nlpComplError, muDoubleScalarMin
      (muDoubleScalarAbs(lbDelta * lbLambda), muDoubleScalarMin
       (muDoubleScalarAbs(lbDelta), lbLambda)));
  }

  st.site = &ud_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    lbDelta = ub[finiteUB[idx] - 1] - xCurrent[finiteUB[idx] - 1];
    i = ubOffset + idx;
    if ((i < 1) || (i > 17)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 17, &c_emlrtBCI, sp);
    }

    lbLambda = lambda[i - 1];
    nlpComplError = muDoubleScalarMax(nlpComplError, muDoubleScalarMin
      (muDoubleScalarAbs(lbDelta * lbLambda), muDoubleScalarMin
       (muDoubleScalarAbs(lbDelta), lbLambda)));
  }

  return nlpComplError;
}

/* End of code generation (computeComplError.c) */
