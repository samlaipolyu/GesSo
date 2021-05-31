/*
 * removeAllIneqConstr.c
 *
 * Code generation for function 'removeAllIneqConstr'
 *
 */

/* Include files */
#include "removeAllIneqConstr.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo dh_emlrtRSI = { 1,  /* lineNo */
  "removeAllIneqConstr",               /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeAllIneqConstr.p"/* pathName */
};

static emlrtBCInfo kc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeAllIneqConstr",               /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeAllIneqConstr.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { 1,  /* iFirst */
  6,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeAllIneqConstr",               /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeAllIneqConstr.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeAllIneqConstr",               /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeAllIneqConstr.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void removeAllIneqConstr(const emlrtStack *sp, e_struct_T *obj)
{
  int32_T idxStartIneq;
  int32_T idxEndIneq;
  int32_T idx_global;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idxStartIneq = (obj->nWConstr[0] + obj->nWConstr[1]) + 1;
  idxEndIneq = obj->nActiveConstr;
  st.site = &dh_emlrtRSI;
  if ((idxStartIneq <= obj->nActiveConstr) && (obj->nActiveConstr > 2147483646))
  {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx_global = idxStartIneq; idx_global <= idxEndIneq; idx_global++) {
    if ((idx_global < 1) || (idx_global > 17)) {
      emlrtDynamicBoundsCheckR2012b(idx_global, 1, 17, &kc_emlrtBCI, sp);
    }

    i = obj->Wid[idx_global - 1];
    if ((i < 1) || (i > 6)) {
      emlrtDynamicBoundsCheckR2012b(obj->Wid[idx_global - 1], 1, 6, &lc_emlrtBCI,
        sp);
    }

    i = (obj->isActiveIdx[i - 1] + obj->Wlocalidx[idx_global - 1]) - 1;
    if ((i < 1) || (i > 17)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 17, &mc_emlrtBCI, sp);
    }

    obj->isActiveConstr[i - 1] = false;
  }

  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = obj->nWConstr[0] + obj->nWConstr[1];
}

/* End of code generation (removeAllIneqConstr.c) */
