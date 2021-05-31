/*
 * atan2.c
 *
 * Code generation for function 'atan2'
 *
 */

/* Include files */
#include "atan2.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "scalexpAlloc.h"

/* Variable Definitions */
static emlrtRSInfo ib_emlrtRSI = { 12, /* lineNo */
  "atan2",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\lib\\matlab\\elfun\\atan2.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 46, /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = { 19,/* lineNo */
  23,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"/* pName */
};

/* Function Definitions */
void b_atan2(const emlrtStack *sp, const real_T y_data[], const int32_T y_size[3],
             const real_T x_data[], const int32_T x_size[3], real_T r_data[],
             int32_T r_size[3])
{
  int32_T z_size[3];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ib_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &jb_emlrtRSI;
  z_size[0] = 1;
  z_size[1] = 1;
  if (y_size[2] <= x_size[2]) {
    z_size[2] = (int8_T)y_size[2];
  } else {
    z_size[2] = 0;
  }

  if (!dimagree(z_size, y_size, x_size)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  r_size[0] = 1;
  r_size[1] = 1;
  if (y_size[2] <= x_size[2]) {
    r_size[2] = (int8_T)y_size[2];
  } else {
    r_size[2] = 0;
  }

  if (0 <= z_size[2] - 1) {
    r_data[0] = muDoubleScalarAtan2(y_data[0], x_data[0]);
  }
}

/* End of code generation (atan2.c) */
