/*
 * countsort.c
 *
 * Code generation for function 'countsort'
 *
 */

/* Include files */
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo vf_emlrtRSI = { 1,  /* lineNo */
  "countsort",                         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+utils\\countsort.p"/* pathName */
};

static emlrtBCInfo qb_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "countsort",                         /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+utils\\countsort.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "countsort",                         /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+utils\\countsort.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void countsort(const emlrtStack *sp, int32_T x[17], int32_T xLen, int32_T
               workspace[17], int32_T xMin, int32_T xMax)
{
  int32_T b_tmp;
  int32_T idx;
  int32_T idxFill;
  int32_T idxStart;
  int32_T idxEnd;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((xLen > 1) && (xMax > xMin)) {
    b_tmp = (xMax - xMin) + 1;
    st.site = &vf_emlrtRSI;
    if ((1 <= b_tmp) && (b_tmp > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < b_tmp; idx++) {
      idxFill = idx + 1;
      if ((idxFill < 1) || (idxFill > 17)) {
        emlrtDynamicBoundsCheckR2012b(idxFill, 1, 17, &qb_emlrtBCI, sp);
      }

      workspace[idxFill - 1] = 0;
    }

    st.site = &vf_emlrtRSI;
    if (xLen > 2147483646) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < xLen; idx++) {
      idxFill = idx + 1;
      if (idxFill > 17) {
        emlrtDynamicBoundsCheckR2012b(idxFill, 1, 17, &rb_emlrtBCI, sp);
      }

      idxFill = (x[idxFill - 1] - xMin) + 1;
      if ((idxFill < 1) || (idxFill > 17)) {
        emlrtDynamicBoundsCheckR2012b(idxFill, 1, 17, &rb_emlrtBCI, sp);
      }

      idxEnd = idx + 1;
      if (idxEnd > 17) {
        emlrtDynamicBoundsCheckR2012b(idxEnd, 1, 17, &rb_emlrtBCI, sp);
      }

      idxEnd = (x[idxEnd - 1] - xMin) + 1;
      if ((idxEnd < 1) || (idxEnd > 17)) {
        emlrtDynamicBoundsCheckR2012b(idxEnd, 1, 17, &qb_emlrtBCI, sp);
      }

      workspace[idxEnd - 1] = workspace[idxFill - 1] + 1;
    }

    st.site = &vf_emlrtRSI;
    for (idx = 2; idx <= b_tmp; idx++) {
      if (idx > 17) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &rb_emlrtBCI, sp);
      }

      workspace[idx - 1] += workspace[idx - 2];
    }

    idxStart = 1;
    idxEnd = workspace[0];
    st.site = &vf_emlrtRSI;
    if ((1 <= b_tmp - 1) && (b_tmp - 1 > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx <= b_tmp - 2; idx++) {
      st.site = &vf_emlrtRSI;
      if ((idxStart <= idxEnd) && (idxEnd > 2147483646)) {
        b_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        if ((idxFill < 1) || (idxFill > 17)) {
          emlrtDynamicBoundsCheckR2012b(idxFill, 1, 17, &qb_emlrtBCI, sp);
        }

        x[idxFill - 1] = idx + xMin;
      }

      idxFill = idx + 1;
      if ((idxFill < 1) || (idxFill > 17)) {
        emlrtDynamicBoundsCheckR2012b(idxFill, 1, 17, &rb_emlrtBCI, sp);
      }

      idxStart = workspace[idxFill - 1] + 1;
      idxFill = idx + 2;
      if ((idxFill < 1) || (idxFill > 17)) {
        emlrtDynamicBoundsCheckR2012b(idxFill, 1, 17, &rb_emlrtBCI, sp);
      }

      idxEnd = workspace[idxFill - 1];
    }

    st.site = &vf_emlrtRSI;
    if ((idxStart <= idxEnd) && (idxEnd > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = idxStart; idx <= idxEnd; idx++) {
      if ((idx < 1) || (idx > 17)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &qb_emlrtBCI, sp);
      }

      x[idx - 1] = xMax;
    }
  }
}

/* End of code generation (countsort.c) */
