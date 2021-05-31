/*
 * xgemm.c
 *
 * Code generation for function 'xgemm'
 *
 */

/* Include files */
#include "xgemm.h"
#include "blas.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ng_emlrtRSI = { 65, /* lineNo */
  "xgemm",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
};

static emlrtRSInfo rg_emlrtRSI = { 87, /* lineNo */
  "xgemm",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
};

static emlrtRSInfo sg_emlrtRSI = { 90, /* lineNo */
  "xgemm",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
};

static emlrtRSInfo fi_emlrtRSI = { 63, /* lineNo */
  "xgemm",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

static emlrtRSInfo gi_emlrtRSI = { 64, /* lineNo */
  "xgemm",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
};

static emlrtRSInfo hi_emlrtRSI = { 85, /* lineNo */
  "xgemm",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
};

/* Function Definitions */
void b_xgemm(int32_T m, int32_T k, const real_T A[289], const real_T B[153],
             real_T C[153])
{
  real_T alpha1;
  real_T beta1;
  char_T TRANSB1;
  char_T TRANSA1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  if (k >= 1) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)2;
    k_t = (ptrdiff_t)k;
    lda_t = (ptrdiff_t)17;
    ldb_t = (ptrdiff_t)17;
    ldc_t = (ptrdiff_t)17;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &A[0], &lda_t, &B[0],
          &ldb_t, &beta1, &C[0], &ldc_t);
  }
}

void c_xgemm(const emlrtStack *sp, int32_T m, int32_T n, int32_T k, const real_T
             A[49], int32_T lda, const real_T B[289], int32_T ib0, real_T C[153])
{
  int32_T br;
  int32_T lastColC;
  int32_T cr;
  int32_T a;
  int32_T b;
  int32_T ar;
  int32_T ib;
  int32_T ia;
  int32_T b_b;
  int32_T ic;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((m != 0) && (n != 0)) {
    br = ib0;
    lastColC = 17 * (n - 1);
    b_st.site = &gi_emlrtRSI;
    if ((0 <= lastColC) && (lastColC > 2147483630)) {
      c_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (cr = 0; cr <= lastColC; cr += 17) {
      a = cr + 1;
      b = cr + m;
      b_st.site = &ng_emlrtRSI;
      if ((cr + 1 <= b) && (b > 2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      if (a <= b) {
        memset(&C[a + -1], 0, ((b - a) + 1) * sizeof(real_T));
      }
    }

    b_st.site = &hi_emlrtRSI;
    for (cr = 0; cr <= lastColC; cr += 17) {
      ar = -1;
      b = (br + k) - 1;
      b_st.site = &rg_emlrtRSI;
      if ((br <= b) && (b > 2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (ib = br; ib <= b; ib++) {
        ia = ar;
        a = cr + 1;
        b_b = cr + m;
        b_st.site = &sg_emlrtRSI;
        if ((cr + 1 <= b_b) && (b_b > 2147483646)) {
          c_st.site = &d_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (ic = a; ic <= b_b; ic++) {
          ia++;
          C[ic - 1] += B[ib - 1] * A[ia];
        }

        ar += lda;
      }

      br += 17;
    }
  }
}

void d_xgemm(int32_T m, int32_T n, int32_T k, const real_T A[289], int32_T ia0,
             const real_T B[153], real_T C[289])
{
  real_T alpha1;
  real_T beta1;
  char_T TRANSB1;
  char_T TRANSA1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  if ((m >= 1) && (n >= 1) && (k >= 1)) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    k_t = (ptrdiff_t)k;
    lda_t = (ptrdiff_t)17;
    ldb_t = (ptrdiff_t)17;
    ldc_t = (ptrdiff_t)17;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &A[ia0 - 1], &lda_t,
          &B[0], &ldb_t, &beta1, &C[0], &ldc_t);
  }
}

void xgemm(int32_T m, int32_T k, const real_T A[289], const real_T B[153],
           real_T C[153])
{
  real_T alpha1;
  real_T beta1;
  char_T TRANSB1;
  char_T TRANSA1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  alpha1 = 1.0;
  beta1 = 0.0;
  TRANSB1 = 'N';
  TRANSA1 = 'T';
  m_t = (ptrdiff_t)m;
  n_t = (ptrdiff_t)2;
  k_t = (ptrdiff_t)k;
  lda_t = (ptrdiff_t)17;
  ldb_t = (ptrdiff_t)17;
  ldc_t = (ptrdiff_t)17;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &A[0], &lda_t, &B[0],
        &ldb_t, &beta1, &C[0], &ldc_t);
}

/* End of code generation (xgemm.c) */
