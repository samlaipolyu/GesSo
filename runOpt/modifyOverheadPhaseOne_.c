/*
 * modifyOverheadPhaseOne_.c
 *
 * Code generation for function 'modifyOverheadPhaseOne_'
 *
 */

/* Include files */
#include "modifyOverheadPhaseOne_.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo jd_emlrtRSI = { 1,  /* lineNo */
  "modifyOverheadPhaseOne_",           /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\modifyOverheadPhaseOne_.p"/* pathName */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "modifyOverheadPhaseOne_",           /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\modifyOverheadPhaseOne_.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void modifyOverheadPhaseOne_(const emlrtStack *sp, e_struct_T *obj)
{
  int32_T b;
  int32_T idx;
  int32_T idxStartIneq;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b = obj->sizes[0];
  st.site = &jd_emlrtRSI;
  if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < b; idx++) {
    obj->ATwset[(obj->nVar + 9 * idx) - 1] = 0.0;
  }

  st.site = &jd_emlrtRSI;
  st.site = &jd_emlrtRSI;
  obj->Aineq[obj->nVar - 1] = -1.0;
  obj->indexLB[obj->sizes[3] - 1] = obj->nVar;
  obj->lb[obj->nVar - 1] = 1.0E-5;
  idxStartIneq = obj->isActiveIdx[2];
  b = obj->nActiveConstr;
  st.site = &jd_emlrtRSI;
  if ((obj->isActiveIdx[2] <= obj->nActiveConstr) && (obj->nActiveConstr >
       2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = idxStartIneq; idx <= b; idx++) {
    if ((idx < 1) || (idx > 17)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &i_emlrtBCI, sp);
    }

    obj->ATwset[(obj->nVar + 9 * (idx - 1)) - 1] = -1.0;
  }
}

/* End of code generation (modifyOverheadPhaseOne_.c) */
