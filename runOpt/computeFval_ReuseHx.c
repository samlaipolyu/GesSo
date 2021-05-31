/*
 * computeFval_ReuseHx.c
 *
 * Code generation for function 'computeFval_ReuseHx'
 *
 */

/* Include files */
#include "computeFval_ReuseHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xdot.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo lh_emlrtRSI = { 1,  /* lineNo */
  "computeFval_ReuseHx",               /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeFval_ReuseHx.p"/* pathName */
};

static emlrtBCInfo ad_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeFval_ReuseHx",               /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeFval_ReuseHx.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { 1,  /* iFirst */
  8,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeFval_ReuseHx",               /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeFval_ReuseHx.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T computeFval_ReuseHx(const emlrtStack *sp, const j_struct_T *obj, real_T
  workspace[153], const real_T f[9], const real_T x[9])
{
  real_T val;
  int32_T b;
  int32_T i;
  int32_T b_i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  val = 0.0;
  switch (obj->objtype) {
   case 5:
    if ((obj->nvar < 1) || (obj->nvar > 9)) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, 9, &ad_emlrtBCI, sp);
    }

    val = obj->gammaScalar * x[obj->nvar - 1];
    break;

   case 3:
    if (obj->hasLinear) {
      b = obj->nvar;
      st.site = &lh_emlrtRSI;
      if ((1 <= obj->nvar) && (obj->nvar > 2147483646)) {
        b_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (b_i = 0; b_i < b; b_i++) {
        i = b_i + 1;
        if ((i < 1) || (i > 8)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 8, &bd_emlrtBCI, sp);
        }

        workspace[b_i] = 0.5 * obj->Hx[i - 1] + f[b_i];
      }

      st.site = &lh_emlrtRSI;
      val = xdot(&st, obj->nvar, x, workspace);
    } else {
      st.site = &lh_emlrtRSI;
      val = b_xdot(&st, obj->nvar, x, obj->Hx);
      val *= 0.5;
    }
    break;

   case 4:
    if (obj->hasLinear) {
      b = obj->nvar;
      st.site = &lh_emlrtRSI;
      if ((1 <= obj->nvar) && (obj->nvar > 2147483646)) {
        b_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      if (0 <= b - 1) {
        memcpy(&workspace[0], &f[0], b * sizeof(real_T));
      }

      b = 7 - obj->nvar;
      st.site = &lh_emlrtRSI;
      i = 8 - obj->nvar;
      if ((1 <= i) && (i > 2147483646)) {
        b_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (b_i = 0; b_i <= b; b_i++) {
        workspace[obj->nvar + b_i] = obj->rho;
      }

      st.site = &lh_emlrtRSI;
      for (b_i = 0; b_i < 8; b_i++) {
        workspace[b_i] += 0.5 * obj->Hx[b_i];
      }

      st.site = &lh_emlrtRSI;
      val = xdot(&st, 8, x, workspace);
    } else {
      st.site = &lh_emlrtRSI;
      val = b_xdot(&st, 8, x, obj->Hx);
      val *= 0.5;
      i = obj->nvar + 1;
      st.site = &lh_emlrtRSI;
      for (b = i; b < 9; b++) {
        val += x[b - 1] * obj->rho;
      }
    }
    break;
  }

  return val;
}

/* End of code generation (computeFval_ReuseHx.c) */
