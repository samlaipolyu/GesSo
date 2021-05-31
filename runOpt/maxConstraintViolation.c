/*
 * maxConstraintViolation.c
 *
 * Code generation for function 'maxConstraintViolation'
 *
 */

/* Include files */
#include "maxConstraintViolation.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo yg_emlrtRSI = { 1,  /* lineNo */
  "maxConstraintViolation",            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\maxConstraintViolation.p"/* pathName */
};

static emlrtRSInfo ah_emlrtRSI = { 1,  /* lineNo */
  "maxConstraintViolation_AMats_regularized_",/* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\maxConstraintViolation_AMats_regularized_.p"/* pathName */
};

static emlrtRSInfo ch_emlrtRSI = { 1,  /* lineNo */
  "maxConstraintViolation_AMats_nonregularized_",/* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\maxConstraintViolation_AMats_nonregularized_.p"/* pathName */
};

static emlrtBCInfo ic_emlrtBCI = { 1,  /* iFirst */
  153,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "maxConstraintViolation",            /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\maxConstraintViolation.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "maxConstraintViolation",            /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\maxConstraintViolation.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T b_maxConstraintViolation(const emlrtStack *sp, e_struct_T *obj, const
  real_T x[153])
{
  real_T v;
  int32_T mLB;
  int32_T mUB;
  int32_T mFixed;
  int32_T mm1;
  int32_T ix;
  real_T c;
  int32_T b;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  switch (obj->probType) {
   case 2:
    st.site = &yg_emlrtRSI;
    b_st.site = &ah_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &gd_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &ah_emlrtRSI;
    c_st.site = &bd_emlrtRSI;
    d_st.site = &bh_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &cd_emlrtRSI;
    ix = 17;
    c = 0.0;
    d_st.site = &dd_emlrtRSI;
    for (mm1 = 0; mm1 < 7; mm1++) {
      c += obj->Aineq[mm1] * x[ix];
      ix++;
    }

    obj->maxConstrWorkspace[0] += c;
    b_st.site = &ah_emlrtRSI;
    obj->maxConstrWorkspace[0] -= x[24];
    v = muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]);
    break;

   default:
    st.site = &yg_emlrtRSI;
    b_st.site = &ch_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &gd_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &ch_emlrtRSI;
    c_st.site = &bd_emlrtRSI;
    mm1 = obj->nVar;
    d_st.site = &bh_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &cd_emlrtRSI;
    ix = 17;
    c = 0.0;
    b = obj->nVar;
    d_st.site = &dd_emlrtRSI;
    if ((1 <= mm1) && (mm1 > 2147483646)) {
      e_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (mm1 = 1; mm1 <= b; mm1++) {
      c += obj->Aineq[mm1 - 1] * x[ix];
      ix++;
    }

    obj->maxConstrWorkspace[0] += c;
    b_st.site = &ch_emlrtRSI;
    v = muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]);
    break;
  }

  if (obj->sizes[3] > 0) {
    st.site = &yg_emlrtRSI;
    if ((1 <= obj->sizes[3]) && (obj->sizes[3] > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (b = 0; b < mLB; b++) {
      mm1 = obj->indexLB[b];
      ix = obj->indexLB[b] + 17;
      if ((ix < 1) || (ix > 153)) {
        emlrtDynamicBoundsCheckR2012b(ix, 1, 153, &ic_emlrtBCI, sp);
      }

      if ((obj->indexLB[b] < 1) || (obj->indexLB[b] > 9)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[b], 1, 9, &jc_emlrtBCI, sp);
      }

      v = muDoubleScalarMax(v, -x[mm1 + 16] - obj->lb[mm1 - 1]);
    }
  }

  if (obj->sizes[4] > 0) {
    st.site = &yg_emlrtRSI;
    if ((1 <= obj->sizes[4]) && (obj->sizes[4] > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (b = 0; b < mUB; b++) {
      mm1 = obj->indexUB[b];
      v = muDoubleScalarMax(v, x[mm1 + 16] - obj->ub[mm1 - 1]);
    }
  }

  if (obj->sizes[0] > 0) {
    st.site = &yg_emlrtRSI;
    if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (b = 0; b < mFixed; b++) {
      v = muDoubleScalarMax(v, muDoubleScalarAbs(x[obj->indexFixed[b] + 16] -
        obj->ub[obj->indexFixed[b] - 1]));
    }
  }

  return v;
}

real_T c_maxConstraintViolation(const emlrtStack *sp, e_struct_T *obj, const
  real_T x[9])
{
  real_T v;
  int32_T mLB;
  int32_T mUB;
  int32_T mFixed;
  int32_T mm1;
  int32_T ix;
  real_T c;
  int32_T b;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  switch (obj->probType) {
   case 2:
    st.site = &yg_emlrtRSI;
    b_st.site = &ah_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &gd_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &ah_emlrtRSI;
    c_st.site = &bd_emlrtRSI;
    d_st.site = &bh_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &cd_emlrtRSI;
    ix = 0;
    c = 0.0;
    d_st.site = &dd_emlrtRSI;
    for (mm1 = 0; mm1 < 7; mm1++) {
      c += obj->Aineq[mm1] * x[ix];
      ix++;
    }

    obj->maxConstrWorkspace[0] += c;
    b_st.site = &ah_emlrtRSI;
    obj->maxConstrWorkspace[0] -= x[7];
    v = muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]);
    break;

   default:
    st.site = &yg_emlrtRSI;
    b_st.site = &ch_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &gd_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &ch_emlrtRSI;
    c_st.site = &bd_emlrtRSI;
    mm1 = obj->nVar;
    d_st.site = &bh_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &cd_emlrtRSI;
    ix = 0;
    c = 0.0;
    b = obj->nVar;
    d_st.site = &dd_emlrtRSI;
    if ((1 <= mm1) && (mm1 > 2147483646)) {
      e_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (mm1 = 1; mm1 <= b; mm1++) {
      c += obj->Aineq[mm1 - 1] * x[ix];
      ix++;
    }

    obj->maxConstrWorkspace[0] += c;
    b_st.site = &ch_emlrtRSI;
    v = muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]);
    break;
  }

  if (obj->sizes[3] > 0) {
    st.site = &yg_emlrtRSI;
    if ((1 <= obj->sizes[3]) && (obj->sizes[3] > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (ix = 0; ix < mLB; ix++) {
      mm1 = obj->indexLB[ix] - 1;
      if ((obj->indexLB[ix] < 1) || (obj->indexLB[ix] > 9)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[ix], 1, 9, &jc_emlrtBCI, sp);
      }

      if ((obj->indexLB[ix] < 1) || (obj->indexLB[ix] > 9)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[ix], 1, 9, &jc_emlrtBCI, sp);
      }

      v = muDoubleScalarMax(v, -x[mm1] - obj->lb[mm1]);
    }
  }

  if (obj->sizes[4] > 0) {
    st.site = &yg_emlrtRSI;
    if ((1 <= obj->sizes[4]) && (obj->sizes[4] > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (ix = 0; ix < mUB; ix++) {
      mm1 = obj->indexUB[ix] - 1;
      v = muDoubleScalarMax(v, x[mm1] - obj->ub[mm1]);
    }
  }

  if (obj->sizes[0] > 0) {
    st.site = &yg_emlrtRSI;
    if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (ix = 0; ix < mFixed; ix++) {
      v = muDoubleScalarMax(v, muDoubleScalarAbs(x[obj->indexFixed[ix] - 1] -
        obj->ub[obj->indexFixed[ix] - 1]));
    }
  }

  return v;
}

real_T maxConstraintViolation(const emlrtStack *sp, e_struct_T *obj, const
  real_T x[153])
{
  real_T v;
  int32_T mLB;
  int32_T mUB;
  int32_T mFixed;
  int32_T mm1;
  int32_T ix;
  real_T c;
  int32_T b;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  switch (obj->probType) {
   case 2:
    st.site = &yg_emlrtRSI;
    b_st.site = &ah_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &gd_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &ah_emlrtRSI;
    c_st.site = &bd_emlrtRSI;
    d_st.site = &bh_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &cd_emlrtRSI;
    ix = 0;
    c = 0.0;
    d_st.site = &dd_emlrtRSI;
    for (mm1 = 0; mm1 < 7; mm1++) {
      c += obj->Aineq[mm1] * x[ix];
      ix++;
    }

    obj->maxConstrWorkspace[0] += c;
    b_st.site = &ah_emlrtRSI;
    obj->maxConstrWorkspace[0] -= x[7];
    v = muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]);
    break;

   default:
    st.site = &yg_emlrtRSI;
    b_st.site = &ch_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &gd_emlrtRSI;
    obj->maxConstrWorkspace[0] = obj->bineq;
    b_st.site = &ch_emlrtRSI;
    c_st.site = &bd_emlrtRSI;
    mm1 = obj->nVar;
    d_st.site = &bh_emlrtRSI;
    obj->maxConstrWorkspace[0] = -obj->maxConstrWorkspace[0];
    d_st.site = &cd_emlrtRSI;
    ix = 0;
    c = 0.0;
    b = obj->nVar;
    d_st.site = &dd_emlrtRSI;
    if ((1 <= mm1) && (mm1 > 2147483646)) {
      e_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (mm1 = 1; mm1 <= b; mm1++) {
      c += obj->Aineq[mm1 - 1] * x[ix];
      ix++;
    }

    obj->maxConstrWorkspace[0] += c;
    b_st.site = &ch_emlrtRSI;
    v = muDoubleScalarMax(0.0, obj->maxConstrWorkspace[0]);
    break;
  }

  if (obj->sizes[3] > 0) {
    st.site = &yg_emlrtRSI;
    if ((1 <= obj->sizes[3]) && (obj->sizes[3] > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (ix = 0; ix < mLB; ix++) {
      mm1 = obj->indexLB[ix] - 1;
      if ((obj->indexLB[ix] < 1) || (obj->indexLB[ix] > 153)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[ix], 1, 153, &ic_emlrtBCI, sp);
      }

      if ((obj->indexLB[ix] < 1) || (obj->indexLB[ix] > 9)) {
        emlrtDynamicBoundsCheckR2012b(obj->indexLB[ix], 1, 9, &jc_emlrtBCI, sp);
      }

      v = muDoubleScalarMax(v, -x[mm1] - obj->lb[mm1]);
    }
  }

  if (obj->sizes[4] > 0) {
    st.site = &yg_emlrtRSI;
    if ((1 <= obj->sizes[4]) && (obj->sizes[4] > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (ix = 0; ix < mUB; ix++) {
      mm1 = obj->indexUB[ix] - 1;
      v = muDoubleScalarMax(v, x[mm1] - obj->ub[mm1]);
    }
  }

  if (obj->sizes[0] > 0) {
    st.site = &yg_emlrtRSI;
    if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (ix = 0; ix < mFixed; ix++) {
      v = muDoubleScalarMax(v, muDoubleScalarAbs(x[obj->indexFixed[ix] - 1] -
        obj->ub[obj->indexFixed[ix] - 1]));
    }
  }

  return v;
}

/* End of code generation (maxConstraintViolation.c) */
