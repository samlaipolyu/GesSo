/*
 * xgemv.c
 *
 * Code generation for function 'xgemv'
 *
 */

/* Include files */
#include "xgemv.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include <string.h>

/* Function Definitions */
void b_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[49],
             int32_T lda, const real_T x[9], real_T y[8])
{
  int32_T ix;
  int32_T b_tmp;
  boolean_T overflow;
  int32_T iac;
  int32_T iy;
  int32_T b;
  int32_T ia;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((m != 0) && (n != 0)) {
    b_st.site = &re_emlrtRSI;
    if ((1 <= m) && (m > 2147483646)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    if (0 <= m - 1) {
      memset(&y[0], 0, m * sizeof(real_T));
    }

    ix = 0;
    b_tmp = lda * (n - 1) + 1;
    b_st.site = &pd_emlrtRSI;
    if ((lda == 0) || (1 > b_tmp)) {
      overflow = false;
    } else {
      overflow = (b_tmp > MAX_int32_T - lda);
    }

    if (lda == 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &l_emlrtRTEI,
        "Coder:builtins:VectorStride", "Coder:builtins:VectorStride", 0);
    }

    if (overflow) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (iac = 1; lda < 0 ? iac >= b_tmp : iac <= b_tmp; iac += lda) {
      iy = 0;
      b = (iac + m) - 1;
      b_st.site = &od_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (ia = iac; ia <= b; ia++) {
        y[iy] += A[ia - 1] * x[ix];
        iy++;
      }

      ix++;
    }
  }
}

void c_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[289],
             int32_T ia0, const real_T x[153], real_T y[9])
{
  int32_T ix;
  int32_T b;
  int32_T iac;
  int32_T iy;
  int32_T b_b;
  int32_T ia;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != 0) {
    b_st.site = &re_emlrtRSI;
    if ((1 <= m) && (m > 2147483646)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    if (0 <= m - 1) {
      memset(&y[0], 0, m * sizeof(real_T));
    }

    ix = 0;
    b = ia0 + 17 * (n - 1);
    b_st.site = &pd_emlrtRSI;
    if ((ia0 <= b) && (b > 2147483630)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (iac = ia0; iac <= b; iac += 17) {
      iy = 0;
      b_b = (iac + m) - 1;
      b_st.site = &od_emlrtRSI;
      if ((iac <= b_b) && (b_b > 2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (ia = iac; ia <= b_b; ia++) {
        y[iy] += A[ia - 1] * x[ix];
        iy++;
      }

      ix++;
    }
  }
}

void d_xgemv(const emlrtStack *sp, int32_T m, const real_T A[9], const real_T x
             [9], real_T y[153])
{
  int32_T ix;
  real_T c;
  int32_T ia;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &bh_emlrtRSI;
  y[0] = -y[0];
  b_st.site = &cd_emlrtRSI;
  ix = 0;
  c = 0.0;
  b_st.site = &dd_emlrtRSI;
  if ((1 <= m) && (m > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (ia = 1; ia <= m; ia++) {
    c += A[ia - 1] * x[ix];
    ix++;
  }

  y[0] += c;
}

void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[289],
           const real_T x[9], real_T y[153])
{
  int32_T iy;
  int32_T b_tmp;
  int32_T iac;
  int32_T ix;
  real_T c;
  int32_T b;
  int32_T ia;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != 0) {
    b_st.site = &re_emlrtRSI;
    if ((1 <= n) && (n > 2147483646)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    if (0 <= n - 1) {
      memset(&y[0], 0, n * sizeof(real_T));
    }

    iy = 0;
    b_tmp = 17 * (n - 1) + 1;
    b_st.site = &cd_emlrtRSI;
    if ((1 <= b_tmp) && (b_tmp > 2147483630)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (iac = 1; iac <= b_tmp; iac += 17) {
      ix = 0;
      c = 0.0;
      b = (iac + m) - 1;
      b_st.site = &dd_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (ia = iac; ia <= b; ia++) {
        c += A[ia - 1] * x[ix];
        ix++;
      }

      y[iy] += c;
      iy++;
    }
  }
}

/* End of code generation (xgemv.c) */
