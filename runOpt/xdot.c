/*
 * xdot.c
 *
 * Code generation for function 'xdot'
 *
 */

/* Include files */
#include "xdot.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo hh_emlrtRSI = { 32, /* lineNo */
  "xdotx",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdotx.m"/* pathName */
};

/* Function Definitions */
real_T b_xdot(const emlrtStack *sp, int32_T n, const real_T x[9], const real_T
              y[8])
{
  real_T d;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &sf_emlrtRSI;
  d = 0.0;
  if (n >= 1) {
    c_st.site = &hh_emlrtRSI;
    if (n > 2147483646) {
      d_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k < n; k++) {
      d += x[k] * y[k];
    }
  }

  return d;
}

real_T c_xdot(const emlrtStack *sp, int32_T n, const real_T x[9], const real_T
              y[9])
{
  real_T d;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &sf_emlrtRSI;
  d = 0.0;
  c_st.site = &hh_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    d_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k < n; k++) {
    d += x[k] * y[k];
  }

  return d;
}

real_T xdot(const emlrtStack *sp, int32_T n, const real_T x[9], const real_T y
            [153])
{
  real_T d;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &sf_emlrtRSI;
  d = 0.0;
  if (n >= 1) {
    c_st.site = &hh_emlrtRSI;
    if (n > 2147483646) {
      d_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k < n; k++) {
      d += x[k] * y[k];
    }
  }

  return d;
}

/* End of code generation (xdot.c) */
