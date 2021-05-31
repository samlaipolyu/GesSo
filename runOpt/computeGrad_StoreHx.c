/*
 * computeGrad_StoreHx.c
 *
 * Code generation for function 'computeGrad_StoreHx'
 *
 */

/* Include files */
#include "computeGrad_StoreHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xgemv.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kh_emlrtRSI = { 1,  /* lineNo */
  "computeGrad_StoreHx",               /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeGrad_StoreHx.p"/* pathName */
};

static emlrtBCInfo xc_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeGrad_StoreHx",               /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeGrad_StoreHx.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { 1,  /* iFirst */
  8,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeGrad_StoreHx",               /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeGrad_StoreHx.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void computeGrad_StoreHx(const emlrtStack *sp, j_struct_T *obj, const real_T H
  [49], const real_T f[9], const real_T x[9])
{
  int32_T ixlast;
  int32_T i;
  int32_T b_i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  switch (obj->objtype) {
   case 5:
    ixlast = obj->nvar;
    st.site = &kh_emlrtRSI;
    i = obj->nvar - 1;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    if (0 <= ixlast - 2) {
      memset(&obj->grad[0], 0, (ixlast + -1) * sizeof(real_T));
    }

    if ((obj->nvar < 1) || (obj->nvar > 9)) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, 9, &xc_emlrtBCI, sp);
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    st.site = &kh_emlrtRSI;
    b_xgemv(&st, obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    ixlast = obj->nvar;
    st.site = &kh_emlrtRSI;
    if ((1 <= obj->nvar) && (obj->nvar > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (b_i = 0; b_i < ixlast; b_i++) {
      i = b_i + 1;
      if ((i < 1) || (i > 8)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 8, &yc_emlrtBCI, sp);
      }

      obj->grad[b_i] = obj->Hx[i - 1];
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar - 1;
      for (b_i = 0; b_i <= ixlast; b_i++) {
        obj->grad[b_i] += f[b_i];
      }
    }
    break;

   case 4:
    st.site = &kh_emlrtRSI;
    b_xgemv(&st, obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    i = obj->nvar + 1;
    st.site = &kh_emlrtRSI;
    for (ixlast = i; ixlast < 9; ixlast++) {
      obj->Hx[ixlast - 1] = obj->beta * x[ixlast - 1];
    }

    st.site = &kh_emlrtRSI;
    memcpy(&obj->grad[0], &obj->Hx[0], 8U * sizeof(real_T));
    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar - 1;
      for (b_i = 0; b_i <= ixlast; b_i++) {
        obj->grad[b_i] += f[b_i];
      }
    }

    if (8 - obj->nvar >= 1) {
      ixlast = obj->nvar;
      i = 7 - obj->nvar;
      for (b_i = 0; b_i <= i; b_i++) {
        obj->grad[ixlast] += obj->rho;
        ixlast++;
      }
    }
    break;
  }
}

/* End of code generation (computeGrad_StoreHx.c) */
