/*
 * xasum.c
 *
 * Code generation for function 'xasum'
 *
 */

/* Include files */
#include "xasum.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo ui_emlrtRSI = { 23, /* lineNo */
  "xasum",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xasum.m"/* pathName */
};

static emlrtRSInfo vi_emlrtRSI = { 23, /* lineNo */
  "xasum",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xasum.m"/* pathName */
};

/* Function Definitions */
real_T xasum(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0)
{
  real_T y;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ui_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  if (n >= 1) {
    b_st.site = &vi_emlrtRSI;
    if (ix0 > 2147483646) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = ix0; k <= ix0; k++) {
      y += muDoubleScalarAbs(x[k - 1]);
    }
  }

  return y;
}

/* End of code generation (xasum.c) */
