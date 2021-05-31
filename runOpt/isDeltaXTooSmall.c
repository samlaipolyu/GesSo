/*
 * isDeltaXTooSmall.c
 *
 * Code generation for function 'isDeltaXTooSmall'
 *
 */

/* Include files */
#include "isDeltaXTooSmall.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo vd_emlrtRSI = { 1,  /* lineNo */
  "isDeltaXTooSmall",                  /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\isDeltaXTooSmall.p"/* pathName */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "isDeltaXTooSmall",                  /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\isDeltaXTooSmall.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
boolean_T isDeltaXTooSmall(const emlrtStack *sp, const real_T xCurrent[7], const
  real_T delta_x[9], int32_T nVar)
{
  boolean_T tf;
  int32_T idx;
  boolean_T exitg1;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  tf = true;
  st.site = &vd_emlrtRSI;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= nVar - 1)) {
    i = idx + 1;
    if ((i < 1) || (i > 7)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 7, &d_emlrtBCI, sp);
    }

    if (1.0E-6 * muDoubleScalarMax(1.0, muDoubleScalarAbs(xCurrent[idx])) <=
        muDoubleScalarAbs(delta_x[idx])) {
      tf = false;
      exitg1 = true;
    } else {
      idx++;
    }
  }

  return tf;
}

/* End of code generation (isDeltaXTooSmall.c) */
