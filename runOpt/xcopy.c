/*
 * xcopy.c
 *
 * Code generation for function 'xcopy'
 *
 */

/* Include files */
#include "xcopy.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include <string.h>

/* Function Definitions */
void b_xcopy(const emlrtStack *sp, int32_T n, const real_T x[17], real_T y[17])
{
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &gd_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  if (0 <= n - 1) {
    memcpy(&y[0], &x[0], n * sizeof(real_T));
  }
}

void c_xcopy(const emlrtStack *sp, int32_T n, real_T y[17])
{
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &gd_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  if (0 <= n - 1) {
    memset(&y[0], 0, n * sizeof(real_T));
  }
}

void d_xcopy(const emlrtStack *sp, int32_T n, const real_T x[153], int32_T ix0,
             real_T y[289], int32_T iy0)
{
  int32_T k;
  int32_T b_k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &gd_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k < n; k++) {
    b_k = k - 1;
    y[iy0 + b_k] = x[ix0 + b_k];
  }
}

void e_xcopy(const emlrtStack *sp, int32_T n, const real_T x[7], real_T y[9])
{
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &gd_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  if (0 <= n - 1) {
    memcpy(&y[0], &x[0], n * sizeof(real_T));
  }
}

void f_xcopy(const emlrtStack *sp, int32_T n, const real_T x[9], real_T y[9])
{
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &gd_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  if (0 <= n - 1) {
    memcpy(&y[0], &x[0], n * sizeof(real_T));
  }
}

void g_xcopy(const emlrtStack *sp, int32_T n, real_T y[49], int32_T iy0)
{
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &gd_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  if (0 <= n - 1) {
    memset(&y[iy0 + -1], 0, ((n + iy0) - iy0) * sizeof(real_T));
  }
}

void xcopy(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0,
           real_T y[153], int32_T iy0)
{
  int32_T k;
  int32_T b_k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &gd_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k < n; k++) {
    b_k = k - 1;
    y[iy0 + b_k] = x[ix0 + b_k];
  }
}

/* End of code generation (xcopy.c) */
