/*
 * rotz.c
 *
 * Code generation for function 'rotz'
 *
 */

/* Include files */
#include "rotz.h"
#include "cosd.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "sind.h"

/* Variable Definitions */
static emlrtRSInfo ab_emlrtRSI = { 30, /* lineNo */
  "rotz",                              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\phased\\phased\\rotz.m"/* pathName */
};

/* Function Definitions */
void rotz(const emlrtStack *sp, real_T b_gamma, real_T rotmat[9])
{
  boolean_T p;
  real_T rotmat_tmp;
  real_T b_rotmat_tmp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ab_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &bb_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  p = ((!muDoubleScalarIsInf(b_gamma)) && (!muDoubleScalarIsNaN(b_gamma)));
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:rotz:expectedFinite", 3, 4, 5, "GAMMA");
  }

  c_st.site = &cb_emlrtRSI;
  p = !muDoubleScalarIsNaN(b_gamma);
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:rotz:expectedNonNaN", 3, 4, 5, "GAMMA");
  }

  rotmat_tmp = b_gamma;
  b_sind(&rotmat_tmp);
  b_rotmat_tmp = b_gamma;
  b_cosd(&b_rotmat_tmp);
  rotmat[0] = b_rotmat_tmp;
  rotmat[3] = -rotmat_tmp;
  rotmat[6] = 0.0;
  rotmat[1] = rotmat_tmp;
  rotmat[4] = b_rotmat_tmp;
  rotmat[7] = 0.0;
  rotmat[2] = 0.0;
  rotmat[5] = 0.0;
  rotmat[8] = 1.0;
}

/* End of code generation (rotz.c) */
