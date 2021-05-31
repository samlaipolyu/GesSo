/*
 * solve.c
 *
 * Code generation for function 'solve'
 *
 */

/* Include files */
#include "solve.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo gf_emlrtRSI = { 37, /* lineNo */
  "xtrsv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsv.m"/* pathName */
};

/* Function Definitions */
void solve(const emlrtStack *sp, const k_struct_T *obj, real_T rhs[9])
{
  int32_T n;
  int32_T j;
  int32_T jA;
  real_T temp;
  int32_T i;
  int32_T ix;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  n = obj->ndims;
  b_st.site = &ff_emlrtRSI;
  if (obj->ndims != 0) {
    c_st.site = &ci_emlrtRSI;
    if ((1 <= obj->ndims) && (obj->ndims > 2147483646)) {
      d_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (j = 0; j < n; j++) {
      jA = j * 17;
      temp = rhs[j];
      c_st.site = &di_emlrtRSI;
      if ((1 <= j) && (j > 2147483646)) {
        d_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (i = 0; i < j; i++) {
        temp -= obj->FMat[jA + i] * rhs[i];
      }

      rhs[j] = temp / obj->FMat[jA + j];
    }
  }

  st.site = &bi_emlrtRSI;
  n = obj->ndims;
  b_st.site = &ff_emlrtRSI;
  if (obj->ndims != 0) {
    for (j = n; j >= 1; j--) {
      jA = (j + (j - 1) * 17) - 1;
      rhs[j - 1] /= obj->FMat[jA];
      c_st.site = &gf_emlrtRSI;
      for (i = 0; i <= j - 2; i++) {
        ix = (j - i) - 2;
        rhs[ix] -= rhs[j - 1] * obj->FMat[(jA - i) - 1];
      }
    }
  }
}

/* End of code generation (solve.c) */
