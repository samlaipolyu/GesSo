/*
 * computeGradLag.c
 *
 * Code generation for function 'computeGradLag'
 *
 */

/* Include files */
#include "computeGradLag.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo nd_emlrtRSI = { 1,  /* lineNo */
  "computeGradLag",                    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeGradLag.p"/* pathName */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeGradLag",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeGradLag.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeGradLag",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeGradLag.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  153,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeGradLag",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeGradLag.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void b_computeGradLag(const emlrtStack *sp, real_T workspace[153], int32_T nVar,
                      const real_T grad[9], const real_T AineqTrans[9], const
                      int32_T finiteFixed[9], int32_T mFixed, const int32_T
                      finiteLB[9], int32_T mLB, const int32_T finiteUB[9],
                      int32_T mUB, const real_T lambda[17])
{
  int32_T idx;
  int32_T iy;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  if (0 <= nVar - 1) {
    memcpy(&workspace[0], &grad[0], nVar * sizeof(real_T));
  }

  st.site = &nd_emlrtRSI;
  if ((1 <= mFixed) && (mFixed > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mFixed; idx++) {
    workspace[finiteFixed[idx] - 1] += lambda[idx];
  }

  st.site = &nd_emlrtRSI;
  iy = 0;
  for (idx = 1; idx <= nVar; idx++) {
    workspace[iy] += AineqTrans[idx - 1] * lambda[mFixed];
    iy++;
  }

  iy = mFixed + 2;
  st.site = &nd_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    if ((finiteLB[idx] < 1) || (finiteLB[idx] > 153)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, 153, &q_emlrtBCI, sp);
    }

    if ((iy < 1) || (iy > 17)) {
      emlrtDynamicBoundsCheckR2012b(iy, 1, 17, &p_emlrtBCI, sp);
    }

    workspace[finiteLB[idx] - 1] -= lambda[iy - 1];
    iy++;
  }

  st.site = &nd_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    if ((iy < 1) || (iy > 17)) {
      emlrtDynamicBoundsCheckR2012b(iy, 1, 17, &p_emlrtBCI, sp);
    }

    workspace[finiteUB[idx] - 1] += lambda[iy - 1];
    iy++;
  }
}

void computeGradLag(const emlrtStack *sp, real_T workspace[9], int32_T nVar,
                    const real_T grad[9], const real_T AineqTrans[9], const
                    int32_T finiteFixed[9], int32_T mFixed, const int32_T
                    finiteLB[9], int32_T mLB, const int32_T finiteUB[9], int32_T
                    mUB, const real_T lambda[17])
{
  int32_T idx;
  int32_T iy;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  if (0 <= nVar - 1) {
    memcpy(&workspace[0], &grad[0], nVar * sizeof(real_T));
  }

  st.site = &nd_emlrtRSI;
  if ((1 <= mFixed) && (mFixed > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mFixed; idx++) {
    workspace[finiteFixed[idx] - 1] += lambda[idx];
  }

  st.site = &nd_emlrtRSI;
  iy = 0;
  for (idx = 1; idx <= nVar; idx++) {
    workspace[iy] += AineqTrans[idx - 1] * lambda[mFixed];
    iy++;
  }

  iy = mFixed + 2;
  st.site = &nd_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    if ((finiteLB[idx] < 1) || (finiteLB[idx] > 9)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, 9, &o_emlrtBCI, sp);
    }

    if ((iy < 1) || (iy > 17)) {
      emlrtDynamicBoundsCheckR2012b(iy, 1, 17, &p_emlrtBCI, sp);
    }

    workspace[finiteLB[idx] - 1] -= lambda[iy - 1];
    iy++;
  }

  st.site = &nd_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    if ((iy < 1) || (iy > 17)) {
      emlrtDynamicBoundsCheckR2012b(iy, 1, 17, &p_emlrtBCI, sp);
    }

    workspace[finiteUB[idx] - 1] += lambda[iy - 1];
    iy++;
  }
}

/* End of code generation (computeGradLag.c) */
