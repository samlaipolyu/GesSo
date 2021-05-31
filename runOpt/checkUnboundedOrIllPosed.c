/*
 * checkUnboundedOrIllPosed.c
 *
 * Code generation for function 'checkUnboundedOrIllPosed'
 *
 */

/* Include files */
#include "checkUnboundedOrIllPosed.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "xnrm2.h"

/* Variable Definitions */
static emlrtRSInfo ni_emlrtRSI = { 1,  /* lineNo */
  "checkUnboundedOrIllPosed",          /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+stopping\\checkUnboundedOrIllPosed.p"/* pathName */
};

/* Function Definitions */
void checkUnboundedOrIllPosed(const emlrtStack *sp, f_struct_T *solution, const
  j_struct_T *objective)
{
  real_T normDelta;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (objective->objtype == 5) {
    st.site = &ni_emlrtRSI;
    normDelta = xnrm2(&st, objective->nvar, solution->searchDir);
    if (normDelta > 100.0 * (real_T)objective->nvar * 1.4901161193847656E-8) {
      solution->state = 3;
    } else {
      solution->state = 4;
    }
  }
}

/* End of code generation (checkUnboundedOrIllPosed.c) */
