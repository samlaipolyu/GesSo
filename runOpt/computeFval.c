/*
 * computeFval.c
 *
 * Code generation for function 'computeFval'
 *
 */

/* Include files */
#include "computeFval.h"
#include "linearForm_.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "xdot.h"

/* Variable Definitions */
static emlrtRSInfo fh_emlrtRSI = { 1,  /* lineNo */
  "computeFval",                       /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeFval.p"/* pathName */
};

static emlrtBCInfo pc_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeFval",                       /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\computeFval.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T computeFval(const emlrtStack *sp, const j_struct_T *obj, real_T
                   workspace[153], const real_T H[49], const real_T f[9], const
                   real_T x[9])
{
  real_T val;
  int32_T i;
  int32_T idx;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  val = 0.0;
  switch (obj->objtype) {
   case 5:
    if ((obj->nvar < 1) || (obj->nvar > 9)) {
      emlrtDynamicBoundsCheckR2012b(obj->nvar, 1, 9, &pc_emlrtBCI, sp);
    }

    val = obj->gammaScalar * x[obj->nvar - 1];
    break;

   case 3:
    st.site = &fh_emlrtRSI;
    linearForm_(&st, obj->hasLinear, obj->nvar, workspace, H, f, x);
    st.site = &fh_emlrtRSI;
    val = xdot(&st, obj->nvar, x, workspace);
    break;

   case 4:
    st.site = &fh_emlrtRSI;
    linearForm_(&st, obj->hasLinear, obj->nvar, workspace, H, f, x);
    i = obj->nvar + 1;
    for (idx = i; idx < 9; idx++) {
      workspace[idx - 1] = 0.5 * obj->beta * x[idx - 1] + obj->rho;
    }

    st.site = &fh_emlrtRSI;
    val = xdot(&st, 8, x, workspace);
    break;
  }

  return val;
}

/* End of code generation (computeFval.c) */
