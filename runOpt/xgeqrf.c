/*
 * xgeqrf.c
 *
 * Code generation for function 'xgeqrf'
 *
 */

/* Include files */
#include "xgeqrf.h"
#include "eml_int_forloop_overflow_check.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo cg_emlrtRSI = { 27, /* lineNo */
  "xgeqrf",                            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 99, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 94, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 93, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo gg_emlrtRSI = { 91, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 84, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 79, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 53, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 52, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

/* Function Definitions */
void xgeqrf(const emlrtStack *sp, real_T A[289], int32_T m, int32_T n, real_T
            tau[17])
{
  ptrdiff_t info_t;
  int32_T minmn;
  boolean_T p;
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 'q', 'r', 'f' };

  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &kg_emlrtRSI;
  b_st.site = &jg_emlrtRSI;
  if (n == 0) {
    memset(&tau[0], 0, 17U * sizeof(real_T));
  } else {
    b_st.site = &ig_emlrtRSI;
    b_st.site = &hg_emlrtRSI;
    info_t = LAPACKE_dgeqrf(102, (ptrdiff_t)m, (ptrdiff_t)n, &A[0], (ptrdiff_t)
      17, &tau[0]);
    minmn = (int32_T)info_t;
    b_st.site = &gg_emlrtRSI;
    if (minmn != 0) {
      p = true;
      if (minmn != -4) {
        if (minmn == -1010) {
          emlrtErrorWithMessageIdR2018a(&b_st, &k_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, minmn);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      b_st.site = &fg_emlrtRSI;
      if ((1 <= n) && (n > 2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (minmn = 0; minmn < n; minmn++) {
        b_st.site = &eg_emlrtRSI;
        if ((1 <= m) && (m > 2147483646)) {
          c_st.site = &d_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (i = 0; i < m; i++) {
          A[minmn * 17 + i] = rtNaN;
        }
      }

      minmn = muIntScalarMin_sint32(m, n);
      b_st.site = &dg_emlrtRSI;
      for (i = 0; i < minmn; i++) {
        tau[i] = rtNaN;
      }

      minmn++;
      for (i = minmn; i < 18; i++) {
        tau[i - 1] = 0.0;
      }
    }
  }
}

/* End of code generation (xgeqrf.c) */
