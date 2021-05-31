/*
 * linearForm_.c
 *
 * Code generation for function 'linearForm_'
 *
 */

/* Include files */
#include "linearForm_.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo gh_emlrtRSI = { 1,  /* lineNo */
  "linearForm_",                       /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\linearForm_.p"/* pathName */
};

/* Function Definitions */
void linearForm_(const emlrtStack *sp, boolean_T obj_hasLinear, int32_T obj_nvar,
                 real_T workspace[153], const real_T H[49], const real_T f[9],
                 const real_T x[9])
{
  int32_T ix;
  int32_T b_tmp;
  boolean_T overflow;
  int32_T iac;
  real_T c;
  int32_T iy;
  int32_T b;
  int32_T ia;
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
  ix = 0;
  if (obj_hasLinear) {
    st.site = &gh_emlrtRSI;
    if ((1 <= obj_nvar) && (obj_nvar > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    if (0 <= obj_nvar - 1) {
      memcpy(&workspace[0], &f[0], obj_nvar * sizeof(real_T));
    }

    ix = 1;
  }

  st.site = &gh_emlrtRSI;
  b_st.site = &bd_emlrtRSI;
  if (obj_nvar != 0) {
    if (ix != 1) {
      c_st.site = &re_emlrtRSI;
      if ((1 <= obj_nvar) && (obj_nvar > 2147483646)) {
        d_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      if (0 <= obj_nvar - 1) {
        memset(&workspace[0], 0, obj_nvar * sizeof(real_T));
      }
    }

    ix = 0;
    b_tmp = obj_nvar * (obj_nvar - 1) + 1;
    c_st.site = &pd_emlrtRSI;
    if ((obj_nvar == 0) || (1 > b_tmp)) {
      overflow = false;
    } else {
      overflow = (b_tmp > MAX_int32_T - obj_nvar);
    }

    if (obj_nvar == 0) {
      emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI,
        "Coder:builtins:VectorStride", "Coder:builtins:VectorStride", 0);
    }

    if (overflow) {
      d_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (iac = 1; obj_nvar < 0 ? iac >= b_tmp : iac <= b_tmp; iac += obj_nvar) {
      c = 0.5 * x[ix];
      iy = 0;
      b = (iac + obj_nvar) - 1;
      c_st.site = &od_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        d_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (ia = iac; ia <= b; ia++) {
        workspace[iy] += H[ia - 1] * c;
        iy++;
      }

      ix++;
    }
  }
}

/* End of code generation (linearForm_.c) */
