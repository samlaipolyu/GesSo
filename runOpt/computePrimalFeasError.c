/*
 * computePrimalFeasError.c
 *
 * Code generation for function 'computePrimalFeasError'
 *
 */

/* Include files */
#include "computePrimalFeasError.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo sd_emlrtRSI = { 1,  /* lineNo */
  "computePrimalFeasError",            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computePrimalFeasError.p"/* pathName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computePrimalFeasError",            /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computePrimalFeasError.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T computePrimalFeasError(const emlrtStack *sp, const real_T x[7], real_T
  cIneq, const int32_T finiteLB[9], int32_T mLB, const real_T lb[7], const
  int32_T finiteUB[9], int32_T mUB, const real_T ub[7])
{
  real_T feasError;
  int32_T idx;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  st.site = &sd_emlrtRSI;
  feasError = muDoubleScalarMax(0.0, cIneq);
  st.site = &sd_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    if ((finiteLB[idx] < 1) || (finiteLB[idx] > 7)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, 7, &emlrtBCI, sp);
    }

    feasError = muDoubleScalarMax(feasError, lb[finiteLB[idx] - 1] -
      x[finiteLB[idx] - 1]);
  }

  st.site = &sd_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    feasError = muDoubleScalarMax(feasError, x[finiteUB[idx] - 1] -
      ub[finiteUB[idx] - 1]);
  }

  return feasError;
}

/* End of code generation (computePrimalFeasError.c) */
