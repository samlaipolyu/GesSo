/*
 * moveConstraint_.c
 *
 * Code generation for function 'moveConstraint_'
 *
 */

/* Include files */
#include "moveConstraint_.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo yf_emlrtRSI = { 1,  /* lineNo */
  "moveConstraint_",                   /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\moveConstraint_.p"/* pathName */
};

static emlrtBCInfo sb_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "moveConstraint_",                   /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\moveConstraint_.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "moveConstraint_",                   /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\moveConstraint_.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void moveConstraint_(const emlrtStack *sp, e_struct_T *obj, int32_T
                     idx_global_start, int32_T idx_global_dest)
{
  int32_T b;
  int32_T idx;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((idx_global_start < 1) || (idx_global_start > 17)) {
    emlrtDynamicBoundsCheckR2012b(idx_global_start, 1, 17, &sb_emlrtBCI, sp);
  }

  if ((idx_global_dest < 1) || (idx_global_dest > 17)) {
    emlrtDynamicBoundsCheckR2012b(idx_global_dest, 1, 17, &tb_emlrtBCI, sp);
  }

  obj->Wid[idx_global_dest - 1] = obj->Wid[idx_global_start - 1];
  obj->Wlocalidx[idx_global_dest - 1] = obj->Wlocalidx[idx_global_start - 1];
  b = obj->nVar;
  st.site = &yf_emlrtRSI;
  if ((1 <= obj->nVar) && (obj->nVar > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < b; idx++) {
    obj->ATwset[idx + 9 * (idx_global_dest - 1)] = obj->ATwset[idx + 9 *
      (idx_global_start - 1)];
  }

  obj->bwset[idx_global_dest - 1] = obj->bwset[idx_global_start - 1];
}

/* End of code generation (moveConstraint_.c) */
