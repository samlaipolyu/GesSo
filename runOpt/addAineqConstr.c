/*
 * addAineqConstr.c
 *
 * Code generation for function 'addAineqConstr'
 *
 */

/* Include files */
#include "addAineqConstr.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xcopy.h"

/* Variable Definitions */
static emlrtRSInfo mi_emlrtRSI = { 1,  /* lineNo */
  "addAineqConstr",                    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\addAineqConstr.p"/* pathName */
};

static emlrtBCInfo ld_emlrtBCI = { 1,  /* iFirst */
  1,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "addAineqConstr",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\addAineqConstr.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "addAineqConstr",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\addAineqConstr.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void addAineqConstr(const emlrtStack *sp, e_struct_T *obj, int32_T idx_local)
{
  int32_T i;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mi_emlrtRSI;
  obj->nWConstr[2]++;
  i = (obj->isActiveIdx[2] + idx_local) - 1;
  if ((i < 1) || (i > 17)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 17, &ab_emlrtBCI, &st);
  }

  obj->isActiveConstr[i - 1] = true;
  obj->nActiveConstr++;
  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 17)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 17, &ab_emlrtBCI, &st);
  }

  obj->Wid[obj->nActiveConstr - 1] = 3;
  obj->Wlocalidx[obj->nActiveConstr - 1] = idx_local;
  st.site = &mi_emlrtRSI;
  xcopy(&st, obj->nVar, obj->Aineq, 9 * (idx_local - 1) + 1, obj->ATwset, 9 *
        (obj->nActiveConstr - 1) + 1);
  if ((idx_local < 1) || (idx_local > 1)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, 1, &ld_emlrtBCI, sp);
  }

  if ((obj->nActiveConstr < 1) || (obj->nActiveConstr > 17)) {
    emlrtDynamicBoundsCheckR2012b(obj->nActiveConstr, 1, 17, &md_emlrtBCI, sp);
  }

  obj->bwset[obj->nActiveConstr - 1] = obj->bineq;
}

/* End of code generation (addAineqConstr.c) */
