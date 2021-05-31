/*
 * computeLinearResiduals.c
 *
 * Code generation for function 'computeLinearResiduals'
 *
 */

/* Include files */
#include "computeLinearResiduals.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo ad_emlrtRSI = { 1,  /* lineNo */
  "computeLinearResiduals",            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+internal\\computeLinearResiduals.p"/* pathName */
};

/* Function Definitions */
void computeLinearResiduals(const emlrtStack *sp, const real_T x[7], int32_T
  nVar, real_T *workspaceIneq, const real_T AineqT[9], real_T bineq)
{
  int32_T ix;
  real_T c;
  int32_T ia;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ad_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &fd_emlrtRSI;
  c_st.site = &gd_emlrtRSI;
  *workspaceIneq = bineq;
  st.site = &ad_emlrtRSI;
  b_st.site = &bd_emlrtRSI;
  c_st.site = &bh_emlrtRSI;
  *workspaceIneq = -*workspaceIneq;
  c_st.site = &cd_emlrtRSI;
  ix = 0;
  c = 0.0;
  c_st.site = &dd_emlrtRSI;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    d_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (ia = 1; ia <= nVar; ia++) {
    c += AineqT[ia - 1] * x[ix];
    ix++;
  }

  *workspaceIneq += c;
}

/* End of code generation (computeLinearResiduals.c) */
