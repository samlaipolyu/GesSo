/*
 * PresolveWorkingSet.c
 *
 * Code generation for function 'PresolveWorkingSet'
 *
 */

/* Include files */
#include "PresolveWorkingSet.h"
#include "RemoveDependentEq_.h"
#include "RemoveDependentIneq_.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "runOpt.h"

/* Variable Definitions */
static emlrtRSInfo wg_emlrtRSI = { 1,  /* lineNo */
  "PresolveWorkingSet",                /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\PresolveWorkingSet.p"/* pathName */
};

/* Function Definitions */
void PresolveWorkingSet(const emlrtStack *sp, f_struct_T *solution, b_struct_T
  *memspace, e_struct_T *workingset, i_struct_T *qrmanager)
{
  int32_T i;
  boolean_T okWorkingSet;
  boolean_T guard1 = false;
  real_T constrViolation;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  solution->state = 82;
  st.site = &wg_emlrtRSI;
  i = RemoveDependentEq_(&st, memspace, workingset, qrmanager);
  if (i != -1) {
    st.site = &wg_emlrtRSI;
    RemoveDependentIneq_(&st, workingset, qrmanager, memspace, 100.0);
    st.site = &wg_emlrtRSI;
    okWorkingSet = feasibleX0ForWorkingSet(&st, memspace->workspace_double,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      st.site = &wg_emlrtRSI;
      RemoveDependentIneq_(&st, workingset, qrmanager, memspace, 1000.0);
      st.site = &wg_emlrtRSI;
      okWorkingSet = feasibleX0ForWorkingSet(&st, memspace->workspace_double,
        solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 && (workingset->nWConstr[0] + workingset->nWConstr[1] ==
                   workingset->nVar)) {
      st.site = &wg_emlrtRSI;
      constrViolation = c_maxConstraintViolation(&st, workingset,
        solution->xstar);
      if (constrViolation > 1.0E-6) {
        solution->state = -2;
      }
    }
  } else {
    solution->state = -3;
    st.site = &wg_emlrtRSI;
    removeAllIneqConstr(&st, workingset);
  }
}

/* End of code generation (PresolveWorkingSet.c) */
