/*
 * checkStoppingAndUpdateFval.c
 *
 * Code generation for function 'checkStoppingAndUpdateFval'
 *
 */

/* Include files */
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xcopy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo oi_emlrtRSI = { 1,  /* lineNo */
  "checkStoppingAndUpdateFval",        /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+stopping\\checkStoppingAndUpdateFval.p"/* pathName */
};

/* Function Definitions */
void checkStoppingAndUpdateFval(const emlrtStack *sp, int32_T *activeSetChangeID,
  const real_T f[9], f_struct_T *solution, b_struct_T *memspace, const
  j_struct_T *objective, e_struct_T *workingset, i_struct_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, boolean_T
  updateFval)
{
  int32_T nVar;
  boolean_T nonDegenerateWset;
  real_T constrViolation_new;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  solution->iterations++;
  nVar = objective->nvar;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }

  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    st.site = &oi_emlrtRSI;
    solution->maxConstr = c_maxConstraintViolation(&st, workingset,
      solution->xstar);
    if (solution->maxConstr > 1.0E-6) {
      st.site = &oi_emlrtRSI;
      f_xcopy(&st, objective->nvar, solution->xstar, solution->searchDir);
      st.site = &oi_emlrtRSI;
      nonDegenerateWset = feasibleX0ForWorkingSet(&st,
        memspace->workspace_double, solution->searchDir, workingset, qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }

      *activeSetChangeID = 0;
      st.site = &oi_emlrtRSI;
      constrViolation_new = c_maxConstraintViolation(&st, workingset,
        solution->searchDir);
      if (constrViolation_new < solution->maxConstr) {
        st.site = &oi_emlrtRSI;
        if ((1 <= objective->nvar) && (objective->nvar > 2147483646)) {
          b_st.site = &d_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        if (0 <= nVar - 1) {
          memcpy(&solution->xstar[0], &solution->searchDir[0], nVar * sizeof
                 (real_T));
        }

        solution->maxConstr = constrViolation_new;
      }
    }
  }

  if ((options_ObjectiveLimit > rtMinusInf) && updateFval) {
    st.site = &oi_emlrtRSI;
    solution->fstar = computeFval_ReuseHx(&st, objective,
      memspace->workspace_double, f, solution->xstar);
    if ((solution->fstar < options_ObjectiveLimit) && ((solution->state != 0) ||
         (objective->objtype != 5))) {
      solution->state = 2;
    }
  }
}

/* End of code generation (checkStoppingAndUpdateFval.c) */
