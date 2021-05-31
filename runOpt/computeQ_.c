/*
 * computeQ_.c
 *
 * Code generation for function 'computeQ_'
 *
 */

/* Include files */
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xorgqr.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo df_emlrtRSI = { 1,  /* lineNo */
  "computeQ_",                         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\computeQ_.p"/* pathName */
};

/* Function Definitions */
void computeQ_(const emlrtStack *sp, i_struct_T *obj, int32_T nrows)
{
  int32_T b;
  int32_T idx;
  int32_T iQR0;
  int32_T n;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b = obj->minRowCol;
  st.site = &df_emlrtRSI;
  if ((1 <= obj->minRowCol) && (obj->minRowCol > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < b; idx++) {
    iQR0 = 17 * idx + idx;
    st.site = &df_emlrtRSI;
    n = (obj->mrows - idx) - 1;
    b_st.site = &fd_emlrtRSI;
    c_st.site = &gd_emlrtRSI;
    if ((1 <= n) && (n > 2147483646)) {
      d_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    if (0 <= n - 1) {
      memcpy(&obj->Q[iQR0 + 1], &obj->QR[iQR0 + 1], ((n + iQR0) - iQR0) * sizeof
             (real_T));
    }
  }

  st.site = &df_emlrtRSI;
  xorgqr(&st, obj->mrows, nrows, obj->minRowCol, obj->Q, obj->tau);
}

/* End of code generation (computeQ_.c) */
