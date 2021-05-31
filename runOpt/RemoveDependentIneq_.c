/*
 * RemoveDependentIneq_.c
 *
 * Code generation for function 'RemoveDependentIneq_'
 *
 */

/* Include files */
#include "RemoveDependentIneq_.h"
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQRE.h"
#include "moveConstraint_.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo ag_emlrtRSI = { 1,  /* lineNo */
  "RemoveDependentIneq_",              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\RemoveDependentIneq_.p"/* pathName */
};

static emlrtBCInfo ub_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "RemoveDependentIneq_",              /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\RemoveDependentIneq_.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "RemoveDependentIneq_",              /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+initialize\\RemoveDependentIneq_.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void RemoveDependentIneq_(const emlrtStack *sp, e_struct_T *workingset,
  i_struct_T *qrmanager, b_struct_T *memspace, real_T tolfactor)
{
  int32_T nActiveConstr;
  int32_T nFixedConstr;
  real_T tol;
  int32_T idx;
  int32_T a;
  int32_T i;
  int32_T nDepIneq;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nActiveConstr = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[1] + workingset->nWConstr[0];
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    tol = tolfactor * (real_T)workingset->nVar * 2.2204460492503131E-16;
    st.site = &ag_emlrtRSI;
    if ((1 <= nFixedConstr) && (nFixedConstr > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx < nFixedConstr; idx++) {
      i = idx + 1;
      if ((i < 1) || (i > 17)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 17, &ub_emlrtBCI, sp);
      }

      qrmanager->jpvt[i - 1] = 1;
    }

    a = nFixedConstr + 1;
    st.site = &ag_emlrtRSI;
    if ((nFixedConstr + 1 <= workingset->nActiveConstr) &&
        (workingset->nActiveConstr > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = a; idx <= nActiveConstr; idx++) {
      if ((idx < 1) || (idx > 17)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &ub_emlrtBCI, sp);
      }

      qrmanager->jpvt[idx - 1] = 0;
    }

    st.site = &ag_emlrtRSI;
    factorQRE(&st, qrmanager, workingset->ATwset, workingset->nVar,
              workingset->nActiveConstr);
    nDepIneq = 0;
    for (idx = workingset->nActiveConstr; idx > workingset->nVar; idx--) {
      nDepIneq++;
      if ((idx < 1) || (idx > 17)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &vb_emlrtBCI, sp);
      }

      if (nDepIneq > 17) {
        emlrtDynamicBoundsCheckR2012b(18, 1, 17, &ub_emlrtBCI, sp);
      }

      memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
    }

    if (idx <= workingset->nVar) {
      exitg1 = false;
      while ((!exitg1) && (idx > nFixedConstr)) {
        if ((idx < 1) || (idx > 17)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &vb_emlrtBCI, sp);
        }

        if (muDoubleScalarAbs(qrmanager->QR[(idx + 17 * (idx - 1)) - 1]) < tol)
        {
          nDepIneq++;
          if (nDepIneq > 17) {
            emlrtDynamicBoundsCheckR2012b(18, 1, 17, &ub_emlrtBCI, sp);
          }

          memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
          idx--;
        } else {
          exitg1 = true;
        }
      }
    }

    st.site = &ag_emlrtRSI;
    countsort(&st, memspace->workspace_int, nDepIneq, memspace->workspace_sort,
              nFixedConstr + 1, workingset->nActiveConstr);
    for (idx = nDepIneq; idx >= 1; idx--) {
      st.site = &ag_emlrtRSI;
      i = memspace->workspace_int[idx - 1];
      if ((i < 1) || (i > 17)) {
        emlrtDynamicBoundsCheckR2012b(memspace->workspace_int[idx - 1], 1, 17,
          &lb_emlrtBCI, &st);
      }

      a = i - 1;
      nActiveConstr = workingset->Wid[a];
      i = workingset->Wid[a];
      if ((i < 1) || (i > 6)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 6, &db_emlrtBCI, &st);
      }

      i = (workingset->isActiveIdx[workingset->Wid[a] - 1] +
           workingset->Wlocalidx[a]) - 1;
      if ((i < 1) || (i > 17)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 17, &nb_emlrtBCI, &st);
      }

      workingset->isActiveConstr[i - 1] = false;
      b_st.site = &xf_emlrtRSI;
      moveConstraint_(&b_st, workingset, workingset->nActiveConstr,
                      memspace->workspace_int[idx - 1]);
      workingset->nActiveConstr--;
      if ((nActiveConstr < 1) || (nActiveConstr > 5)) {
        emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, 5, &pb_emlrtBCI, &st);
      }

      workingset->nWConstr[nActiveConstr - 1]--;
    }
  }
}

/* End of code generation (RemoveDependentIneq_.c) */
