/*
 * xpotrf.c
 *
 * Code generation for function 'xpotrf'
 *
 */

/* Include files */
#include "xpotrf.h"
#include "lapacke.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo uh_emlrtRSI = { 77, /* lineNo */
  "ceval_xpotrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xpotrf.m"/* pathName */
};

static emlrtRSInfo ai_emlrtRSI = { 13, /* lineNo */
  "xpotrf",                            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xpotrf.m"/* pathName */
};

/* Function Definitions */
int32_T xpotrf(const emlrtStack *sp, int32_T n, real_T A[289])
{
  int32_T info;
  ptrdiff_t info_t;
  static const char_T fname[19] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'p', 'o', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ai_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info_t = LAPACKE_dpotrf_work(102, 'U', (ptrdiff_t)n, &A[0], (ptrdiff_t)17);
  info = (int32_T)info_t;
  b_st.site = &uh_emlrtRSI;
  if (info < 0) {
    if (info == -1010) {
      emlrtErrorWithMessageIdR2018a(&b_st, &k_emlrtRTEI, "MATLAB:nomem",
        "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:LAPACKCallErrorInfo", "Coder:toolbox:LAPACKCallErrorInfo",
        5, 4, 19, fname, 12, info);
    }
  }

  return info;
}

/* End of code generation (xpotrf.c) */
