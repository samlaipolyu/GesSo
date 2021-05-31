/*
 * rotm2eul.c
 *
 * Code generation for function 'rotm2eul'
 *
 */

/* Include files */
#include "rotm2eul.h"
#include "atan2.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = { 44, /* lineNo */
  "rotm2eul",                          /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\shared\\robotics\\robotcore\\rotm2eul.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 128,/* lineNo */
  "calculateEulerAngles",              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\shared\\robotics\\robotcore\\rotm2eul.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 129,/* lineNo */
  "calculateEulerAngles",              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\shared\\robotics\\robotcore\\rotm2eul.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 118,/* lineNo */
  "calculateEulerAngles",              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\shared\\robotics\\robotcore\\rotm2eul.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 32, /* lineNo */
  "cat",                               /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 102,/* lineNo */
  "cat_impl",                          /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  128,                                 /* lineNo */
  9,                                   /* colNo */
  "calculateEulerAngles",              /* fName */
  "D:\\MATLAB R2020a\\toolbox\\shared\\robotics\\robotcore\\rotm2eul.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 283,/* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

/* Function Definitions */
void rotm2eul(const emlrtStack *sp, const real_T R[9], real_T eul[3])
{
  real_T sy;
  int32_T R_size[3];
  real_T R_data[1];
  int32_T b_R_size[3];
  real_T b_R_data[1];
  real_T varargin_1_data[1];
  int32_T varargin_1_size[3];
  real_T varargin_2_data[1];
  int32_T varargin_2_size[3];
  boolean_T b;
  int32_T tmp_size[3];
  int32_T trueCount;
  int32_T i;
  real_T tmp_data[3];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &hb_emlrtRSI;
  sy = R[0] * R[0] + R[1] * R[1];
  if (sy < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  sy = muDoubleScalarSqrt(sy);
  eul[0] = muDoubleScalarAtan2(R[5], R[8]);
  eul[1] = muDoubleScalarAtan2(-R[2], sy);
  eul[2] = muDoubleScalarAtan2(R[1], R[0]);
  if (sy < 2.2204460492503131E-15) {
    b_st.site = &fb_emlrtRSI;
    R_size[0] = 1;
    R_size[1] = 1;
    R_size[2] = 1;
    R_data[0] = -R[7];
    b_R_size[0] = 1;
    b_R_size[1] = 1;
    b_R_size[2] = 1;
    b_R_data[0] = R[4];
    c_st.site = &fb_emlrtRSI;
    b_atan2(&c_st, R_data, R_size, b_R_data, b_R_size, varargin_1_data,
            varargin_1_size);
    R_size[0] = 1;
    R_size[1] = 1;
    R_size[2] = 1;
    R_data[0] = -R[2];
    b_R_size[0] = 1;
    b_R_size[1] = 1;
    b_R_size[2] = 1;
    b_R_data[0] = sy;
    c_st.site = &gb_emlrtRSI;
    b_atan2(&c_st, R_data, R_size, b_R_data, b_R_size, varargin_2_data,
            varargin_2_size);
    c_st.site = &mb_emlrtRSI;
    d_st.site = &nb_emlrtRSI;
    b = (varargin_2_size[2] == varargin_1_size[2]);
    if (!b) {
      emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    b = ((1 == varargin_1_size[2]) && b);
    if (!b) {
      emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    tmp_size[0] = 1;
    tmp_size[1] = 3;
    tmp_size[2] = varargin_1_size[2];
    trueCount = varargin_1_size[2];
    for (i = 0; i < trueCount; i++) {
      tmp_data[3 * i] = varargin_1_data[i];
    }

    trueCount = varargin_2_size[2];
    for (i = 0; i < trueCount; i++) {
      tmp_data[3 * i + 1] = varargin_2_data[i];
    }

    R_size[0] = 1;
    R_size[1] = 3;
    R_size[2] = 1;
    emlrtSubAssignSizeCheckR2012b(&R_size[0], 3, &tmp_size[0], 3, &emlrtECI, &st);
    eul[0] = tmp_data[0];
    eul[1] = tmp_data[1];
    eul[2] = 0.0;
  }

  sy = eul[0];
  eul[0] = eul[2];
  eul[2] = sy;
}

/* End of code generation (rotm2eul.c) */
