/*
 * roty.c
 *
 * Code generation for function 'roty'
 *
 */

/* Include files */
#include "roty.h"
#include "cosd.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "sind.h"

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = { 31, /* lineNo */
  "roty",                              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\phased\\phased\\roty.m"/* pathName */
};

/* Function Definitions */
void roty(const emlrtStack *sp, real_T beta, real_T rotmat[9])
{
  boolean_T p;
  real_T rotmat_tmp;
  real_T b_rotmat_tmp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &bb_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  p = ((!muDoubleScalarIsInf(beta)) && (!muDoubleScalarIsNaN(beta)));
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:roty:expectedFinite", 3, 4, 4, "BETA");
  }

  c_st.site = &cb_emlrtRSI;
  p = !muDoubleScalarIsNaN(beta);
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:roty:expectedNonNaN", 3, 4, 4, "BETA");
  }

  rotmat_tmp = beta;
  b_sind(&rotmat_tmp);
  b_rotmat_tmp = beta;
  b_cosd(&b_rotmat_tmp);
  rotmat[0] = b_rotmat_tmp;
  rotmat[3] = 0.0;
  rotmat[6] = rotmat_tmp;
  rotmat[1] = 0.0;
  rotmat[4] = 1.0;
  rotmat[7] = 0.0;
  rotmat[2] = -rotmat_tmp;
  rotmat[5] = 0.0;
  rotmat[8] = b_rotmat_tmp;
}

/* End of code generation (roty.c) */
