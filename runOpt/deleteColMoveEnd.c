/*
 * deleteColMoveEnd.c
 *
 * Code generation for function 'deleteColMoveEnd'
 *
 */

/* Include files */
#include "deleteColMoveEnd.h"
#include "blas.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xrot.h"

/* Variable Definitions */
static emlrtRSInfo rh_emlrtRSI = { 1,  /* lineNo */
  "deleteColMoveEnd",                  /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\deleteColMoveEnd.p"/* pathName */
};

static emlrtBCInfo cd_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "deleteColMoveEnd",                  /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\deleteColMoveEnd.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "deleteColMoveEnd",                  /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\deleteColMoveEnd.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void deleteColMoveEnd(const emlrtStack *sp, i_struct_T *obj, int32_T idx)
{
  int32_T i;
  boolean_T exitg1;
  int32_T k;
  int32_T b_k;
  int32_T endIdx;
  int32_T a_tmp;
  real_T a;
  int32_T QRk0;
  real_T b;
  real_T c;
  real_T s;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj->usedPivoting) {
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i <= obj->ncols)) {
      if (i > 17) {
        emlrtDynamicBoundsCheckR2012b(18, 1, 17, &dd_emlrtBCI, sp);
      }

      if (obj->jpvt[i - 1] != idx) {
        i++;
      } else {
        exitg1 = true;
      }
    }

    idx = i;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    if ((obj->ncols < 1) || (obj->ncols > 17)) {
      emlrtDynamicBoundsCheckR2012b(obj->ncols, 1, 17, &dd_emlrtBCI, sp);
    }

    if ((idx < 1) || (idx > 17)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &cd_emlrtBCI, sp);
    }

    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    i = obj->minRowCol;
    st.site = &rh_emlrtRSI;
    if ((1 <= obj->minRowCol) && (obj->minRowCol > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 0; k < i; k++) {
      b_k = k + 1;
      if ((b_k < 1) || (b_k > 17)) {
        emlrtDynamicBoundsCheckR2012b(b_k, 1, 17, &dd_emlrtBCI, sp);
      }

      if ((obj->ncols < 1) || (obj->ncols > 17)) {
        emlrtDynamicBoundsCheckR2012b(obj->ncols, 1, 17, &dd_emlrtBCI, sp);
      }

      obj->QR[(b_k + 17 * (idx - 1)) - 1] = obj->QR[(b_k + 17 * (obj->ncols - 1))
        - 1];
    }

    obj->ncols--;
    obj->minRowCol = muIntScalarMin_sint32(obj->mrows, obj->ncols);
    if (idx < obj->mrows) {
      i = obj->mrows - 1;
      endIdx = muIntScalarMin_sint32(i, obj->ncols);
      for (b_k = endIdx; b_k >= idx; b_k--) {
        st.site = &rh_emlrtRSI;
        if (b_k > 17) {
          emlrtDynamicBoundsCheckR2012b(b_k, 1, 17, &dd_emlrtBCI, &st);
        }

        a_tmp = (b_k + 17 * (idx - 1)) - 1;
        a = obj->QR[a_tmp];
        QRk0 = b_k + 1;
        if (QRk0 > 17) {
          emlrtDynamicBoundsCheckR2012b(18, 1, 17, &dd_emlrtBCI, &st);
        }

        i = 17 * (idx - 1);
        b = obj->QR[(QRk0 + i) - 1];
        c = 0.0;
        s = 0.0;
        drotg(&a, &b, &c, &s);
        obj->QR[a_tmp] = a;
        QRk0 = b_k + 1;
        if (QRk0 > 17) {
          emlrtDynamicBoundsCheckR2012b(18, 1, 17, &cd_emlrtBCI, &st);
        }

        obj->QR[(QRk0 + i) - 1] = b;
        QRk0 = b_k + 1;
        if (QRk0 > 17) {
          emlrtDynamicBoundsCheckR2012b(18, 1, 17, &cd_emlrtBCI, sp);
        }

        i = 17 * (b_k - 1);
        obj->QR[(QRk0 + i) - 1] = 0.0;
        QRk0 = b_k + 17 * idx;
        st.site = &rh_emlrtRSI;
        b_xrot(&st, obj->ncols - idx, obj->QR, QRk0, QRk0 + 1, c, s);
        i++;
        st.site = &rh_emlrtRSI;
        xrot(&st, obj->mrows, obj->Q, i, i + 17, c, s);
      }

      b_k = idx + 1;
      st.site = &rh_emlrtRSI;
      if ((idx + 1 <= endIdx) && (endIdx > 2147483646)) {
        b_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (k = b_k; k <= endIdx; k++) {
        st.site = &rh_emlrtRSI;
        if (k > 17) {
          emlrtDynamicBoundsCheckR2012b(k, 1, 17, &dd_emlrtBCI, &st);
        }

        a_tmp = 17 * (k - 1);
        i = (k + a_tmp) - 1;
        a = obj->QR[i];
        QRk0 = k + 1;
        if (QRk0 > 17) {
          emlrtDynamicBoundsCheckR2012b(18, 1, 17, &dd_emlrtBCI, &st);
        }

        b = obj->QR[(QRk0 + a_tmp) - 1];
        c = 0.0;
        s = 0.0;
        drotg(&a, &b, &c, &s);
        obj->QR[i] = a;
        QRk0 = k + 1;
        if (QRk0 > 17) {
          emlrtDynamicBoundsCheckR2012b(18, 1, 17, &cd_emlrtBCI, &st);
        }

        obj->QR[(QRk0 + a_tmp) - 1] = b;
        QRk0 = k * 18;
        st.site = &rh_emlrtRSI;
        b_xrot(&st, obj->ncols - k, obj->QR, QRk0, QRk0 + 1, c, s);
        i = a_tmp + 1;
        st.site = &rh_emlrtRSI;
        xrot(&st, obj->mrows, obj->Q, i, i + 17, c, s);
      }
    }
  }
}

/* End of code generation (deleteColMoveEnd.c) */
