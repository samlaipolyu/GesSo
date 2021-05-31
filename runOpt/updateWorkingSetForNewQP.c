/*
 * updateWorkingSetForNewQP.c
 *
 * Code generation for function 'updateWorkingSetForNewQP'
 *
 */

/* Include files */
#include "updateWorkingSetForNewQP.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xcopy.h"

/* Variable Definitions */
static emlrtRSInfo ed_emlrtRSI = { 1,  /* lineNo */
  "updateWorkingSetForNewQP",          /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+internal\\updateWorkingSetForNewQP.p"/* pathName */
};

static emlrtBCInfo r_emlrtBCI = { 1,   /* iFirst */
  1,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSetForNewQP",          /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+internal\\updateWorkingSetForNewQP.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSetForNewQP",          /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+internal\\updateWorkingSetForNewQP.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { 1,   /* iFirst */
  7,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSetForNewQP",          /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+internal\\updateWorkingSetForNewQP.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSetForNewQP",          /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+internal\\updateWorkingSetForNewQP.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { 1,   /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "updateWorkingSetForNewQP",          /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+internal\\updateWorkingSetForNewQP.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[7],
  e_struct_T *WorkingSet, real_T cIneq, int32_T mLB, const real_T lb[7], int32_T
  mUB, const real_T ub[7], int32_T mFixed)
{
  int32_T idx;
  int32_T ineqStart;
  int32_T b;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ed_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  st.site = &ed_emlrtRSI;
  st.site = &ed_emlrtRSI;
  WorkingSet->bineq = -cIneq;
  st.site = &ed_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mLB; idx++) {
    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 7)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 7, &t_emlrtBCI,
        sp);
    }

    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 7)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 7, &t_emlrtBCI,
        sp);
    }

    if ((WorkingSet->indexLB[idx] < 1) || (WorkingSet->indexLB[idx] > 9)) {
      emlrtDynamicBoundsCheckR2012b(WorkingSet->indexLB[idx], 1, 9, &u_emlrtBCI,
        sp);
    }

    WorkingSet->lb[WorkingSet->indexLB[idx] - 1] = -lb[WorkingSet->indexLB[idx]
      - 1] + xk[WorkingSet->indexLB[idx] - 1];
  }

  st.site = &ed_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mUB; idx++) {
    WorkingSet->ub[WorkingSet->indexUB[idx] - 1] = ub[WorkingSet->indexUB[idx] -
      1] - xk[WorkingSet->indexUB[idx] - 1];
  }

  st.site = &ed_emlrtRSI;
  if ((1 <= mFixed) && (mFixed > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < mFixed; idx++) {
    WorkingSet->ub[WorkingSet->indexFixed[idx] - 1] = ub[WorkingSet->
      indexFixed[idx] - 1] - xk[WorkingSet->indexFixed[idx] - 1];
    WorkingSet->bwset[idx] = ub[WorkingSet->indexFixed[idx] - 1] - xk
      [WorkingSet->indexFixed[idx] - 1];
  }

  if (WorkingSet->nActiveConstr > mFixed) {
    if (1 < mFixed + 1) {
      ineqStart = mFixed + 1;
    } else {
      ineqStart = 1;
    }

    b = WorkingSet->nActiveConstr;
    st.site = &ed_emlrtRSI;
    if ((ineqStart <= WorkingSet->nActiveConstr) && (WorkingSet->nActiveConstr >
         2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = ineqStart; idx <= b; idx++) {
      if ((idx < 1) || (idx > 17)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &s_emlrtBCI, sp);
      }

      switch (WorkingSet->Wid[idx - 1]) {
       case 4:
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 9)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 9,
            &v_emlrtBCI, sp);
        }

        WorkingSet->bwset[idx - 1] = WorkingSet->lb[i - 1];
        break;

       case 5:
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 9)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 9,
            &v_emlrtBCI, sp);
        }

        WorkingSet->bwset[idx - 1] = WorkingSet->ub[i - 1];
        break;

       default:
        i = WorkingSet->Wlocalidx[idx - 1];
        if ((i < 1) || (i > 1)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet->Wlocalidx[idx - 1], 1, 1,
            &r_emlrtBCI, sp);
        }

        WorkingSet->bwset[idx - 1] = WorkingSet->bineq;
        st.site = &ed_emlrtRSI;
        xcopy(&st, WorkingSet->nVar, WorkingSet->Aineq, 1, WorkingSet->ATwset, 9
              * (idx - 1) + 1);
        break;
      }
    }
  }
}

/* End of code generation (updateWorkingSetForNewQP.c) */
