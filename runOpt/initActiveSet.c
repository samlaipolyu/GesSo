/*
 * initActiveSet.c
 *
 * Code generation for function 'initActiveSet'
 *
 */

/* Include files */
#include "initActiveSet.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "setProblemType.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hd_emlrtRSI = { 1,  /* lineNo */
  "initActiveSet",                     /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\initActiveSet.p"/* pathName */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "initActiveSet",                     /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\initActiveSet.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void initActiveSet(const emlrtStack *sp, e_struct_T *obj)
{
  int32_T idxFillStart;
  int32_T idx;
  int32_T idx_local;
  int32_T a;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  setProblemType(&st, obj, 3);
  idxFillStart = obj->isActiveIdx[2];
  st.site = &hd_emlrtRSI;
  for (idx = idxFillStart; idx < 18; idx++) {
    if (idx < 1) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &f_emlrtBCI, sp);
    }

    obj->isActiveConstr[idx - 1] = false;
  }

  obj->nWConstr[0] = obj->sizes[0];
  obj->nWConstr[1] = 0;
  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = obj->nWConstr[0];
  idxFillStart = obj->sizes[0];
  st.site = &hd_emlrtRSI;
  if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx_local = 0; idx_local < idxFillStart; idx_local++) {
    obj->Wid[idx_local] = 1;
    obj->Wlocalidx[idx_local] = idx_local + 1;
    obj->isActiveConstr[idx_local] = true;
    idx = obj->indexFixed[idx_local];
    st.site = &hd_emlrtRSI;
    if ((1 <= obj->indexFixed[idx_local] - 1) && (obj->indexFixed[idx_local] - 1
         > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    if (0 <= idx - 2) {
      memset(&obj->ATwset[idx_local * 9], 0, (idx + -1) * sizeof(real_T));
    }

    obj->ATwset[(obj->indexFixed[idx_local] + 9 * idx_local) - 1] = 1.0;
    a = obj->indexFixed[idx_local] + 1;
    idx = obj->nVar;
    st.site = &hd_emlrtRSI;
    if ((obj->indexFixed[idx_local] + 1 <= obj->nVar) && (obj->nVar > 2147483646))
    {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    if (a <= idx) {
      memset(&obj->ATwset[(idx_local * 9 + a) + -1], 0, ((idx - a) + 1) * sizeof
             (real_T));
    }

    obj->bwset[idx_local] = obj->ub[obj->indexFixed[idx_local] - 1];
  }

  st.site = &hd_emlrtRSI;
}

/* End of code generation (initActiveSet.c) */
