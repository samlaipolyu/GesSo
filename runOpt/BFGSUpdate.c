/*
 * BFGSUpdate.c
 *
 * Code generation for function 'BFGSUpdate'
 *
 */

/* Include files */
#include "BFGSUpdate.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xdot.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo se_emlrtRSI = { 45, /* lineNo */
  "xger",                              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 15, /* lineNo */
  "xger",                              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

static emlrtRSInfo ue_emlrtRSI = { 41, /* lineNo */
  "xgerx",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 54, /* lineNo */
  "xgerx",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo ij_emlrtRSI = { 1,  /* lineNo */
  "BFGSUpdate",                        /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\BFGSUpdate.p"/* pathName */
};

/* Function Definitions */
boolean_T BFGSUpdate(const emlrtStack *sp, int32_T nvar, real_T Bk[49], const
                     real_T sk[9], real_T yk[9], real_T workspace[153])
{
  boolean_T success;
  real_T dotSY;
  int32_T ix;
  int32_T ixlast;
  int32_T iac;
  int32_T jy;
  int32_T b;
  real_T curvatureS;
  real_T theta;
  int32_T ia;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ij_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  dotSY = c_xdot(&st, nvar, sk, yk);
  st.site = &ij_emlrtRSI;
  b_st.site = &bd_emlrtRSI;
  c_st.site = &re_emlrtRSI;
  if ((1 <= nvar) && (nvar > 2147483646)) {
    d_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  if (0 <= nvar - 1) {
    memset(&workspace[0], 0, nvar * sizeof(real_T));
  }

  ix = 0;
  ixlast = 7 * (nvar - 1) + 1;
  for (iac = 1; iac <= ixlast; iac += 7) {
    jy = 0;
    b = (iac + nvar) - 1;
    c_st.site = &od_emlrtRSI;
    if ((iac <= b) && (b > 2147483646)) {
      d_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (ia = iac; ia <= b; ia++) {
      workspace[jy] += Bk[ia - 1] * sk[ix];
      jy++;
    }

    ix++;
  }

  st.site = &ij_emlrtRSI;
  curvatureS = xdot(&st, nvar, sk, workspace);
  if (dotSY < 0.2 * curvatureS) {
    theta = 0.8 * curvatureS / (curvatureS - dotSY);
    st.site = &ij_emlrtRSI;
    b_st.site = &pe_emlrtRSI;
    c_st.site = &qe_emlrtRSI;
    for (jy = 0; jy < nvar; jy++) {
      yk[jy] *= theta;
    }

    if (!(1.0 - theta == 0.0)) {
      ixlast = nvar - 1;
      for (jy = 0; jy <= ixlast; jy++) {
        yk[jy] += (1.0 - theta) * workspace[jy];
      }
    }

    st.site = &ij_emlrtRSI;
    dotSY = c_xdot(&st, nvar, sk, yk);
  }

  if ((curvatureS > 2.2204460492503131E-16) && (dotSY > 2.2204460492503131E-16))
  {
    success = true;
  } else {
    success = false;
  }

  if (success) {
    theta = -1.0 / curvatureS;
    st.site = &ij_emlrtRSI;
    b_st.site = &se_emlrtRSI;
    c_st.site = &te_emlrtRSI;
    if (!(theta == 0.0)) {
      ixlast = 1;
      jy = 0;
      d_st.site = &ue_emlrtRSI;
      for (iac = 0; iac < nvar; iac++) {
        if (workspace[jy] != 0.0) {
          curvatureS = workspace[jy] * theta;
          ix = 0;
          b = (nvar + ixlast) - 1;
          d_st.site = &ve_emlrtRSI;
          if ((ixlast <= b) && (b > 2147483646)) {
            e_st.site = &d_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }

          for (ia = ixlast; ia <= b; ia++) {
            Bk[ia - 1] += workspace[ix] * curvatureS;
            ix++;
          }
        }

        jy++;
        ixlast += 7;
      }
    }

    theta = 1.0 / dotSY;
    st.site = &ij_emlrtRSI;
    b_st.site = &se_emlrtRSI;
    c_st.site = &te_emlrtRSI;
    if (!(theta == 0.0)) {
      ixlast = 1;
      jy = 0;
      d_st.site = &ue_emlrtRSI;
      for (iac = 0; iac < nvar; iac++) {
        if (yk[jy] != 0.0) {
          curvatureS = yk[jy] * theta;
          ix = 0;
          b = (nvar + ixlast) - 1;
          d_st.site = &ve_emlrtRSI;
          if ((ixlast <= b) && (b > 2147483646)) {
            e_st.site = &d_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }

          for (ia = ixlast; ia <= b; ia++) {
            Bk[ia - 1] += yk[ix] * curvatureS;
            ix++;
          }
        }

        jy++;
        ixlast += 7;
      }
    }
  }

  return success;
}

/* End of code generation (BFGSUpdate.c) */
