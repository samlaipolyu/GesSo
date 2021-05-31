/*
 * driver1.c
 *
 * Code generation for function 'driver1'
 *
 */

/* Include files */
#include "driver1.h"
#include "PresolveWorkingSet.h"
#include "computeFval.h"
#include "eml_int_forloop_overflow_check.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "phaseone.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xcopy.h"

/* Variable Definitions */
static emlrtRSInfo of_emlrtRSI = { 1,  /* lineNo */
  "snap_bounds",                       /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_bounds.p"/* pathName */
};

static emlrtRSInfo vg_emlrtRSI = { 1,  /* lineNo */
  "driver",                            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\driver.p"/* pathName */
};

static emlrtBCInfo dc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "snap_bounds",                       /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_bounds.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "snap_bounds",                       /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_bounds.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "snap_bounds",                       /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\snap_bounds.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void b_driver(const emlrtStack *sp, const real_T H[49], const real_T f[9],
              f_struct_T *solution, b_struct_T *memspace, e_struct_T *workingset,
              i_struct_T *qrmanager, k_struct_T *cholmanager, j_struct_T
              *objective, c_struct_T *options, c_struct_T *runTimeOptions)
{
  int32_T nVar;
  int32_T b;
  int32_T idx;
  int32_T i;
  real_T maxConstr_new;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  solution->iterations = 0;
  runTimeOptions->RemainFeasible = true;
  nVar = workingset->nVar;
  st.site = &vg_emlrtRSI;
  b = workingset->sizes[0];
  b_st.site = &of_emlrtRSI;
  if ((1 <= workingset->sizes[0]) && (workingset->sizes[0] > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx < b; idx++) {
    solution->xstar[workingset->indexFixed[idx] - 1] = workingset->ub
      [workingset->indexFixed[idx] - 1];
  }

  b = workingset->sizes[3];
  b_st.site = &of_emlrtRSI;
  if ((1 <= workingset->sizes[3]) && (workingset->sizes[3] > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx < b; idx++) {
    i = workingset->isActiveIdx[3] + idx;
    if ((i < 1) || (i > 17)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 17, &dc_emlrtBCI, &st);
    }

    if (workingset->isActiveConstr[i - 1]) {
      if ((workingset->indexLB[idx] < 1) || (workingset->indexLB[idx] > 9)) {
        emlrtDynamicBoundsCheckR2012b(workingset->indexLB[idx], 1, 9,
          &ec_emlrtBCI, &st);
      }

      if ((workingset->indexLB[idx] < 1) || (workingset->indexLB[idx] > 9)) {
        emlrtDynamicBoundsCheckR2012b(workingset->indexLB[idx], 1, 9,
          &fc_emlrtBCI, &st);
      }

      solution->xstar[workingset->indexLB[idx] - 1] = -workingset->lb
        [workingset->indexLB[idx] - 1];
    }
  }

  b = workingset->sizes[4];
  b_st.site = &of_emlrtRSI;
  if ((1 <= workingset->sizes[4]) && (workingset->sizes[4] > 2147483646)) {
    c_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (idx = 0; idx < b; idx++) {
    i = workingset->isActiveIdx[4] + idx;
    if ((i < 1) || (i > 17)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, 17, &dc_emlrtBCI, &st);
    }

    if (workingset->isActiveConstr[i - 1]) {
      solution->xstar[workingset->indexUB[idx] - 1] = workingset->ub
        [workingset->indexUB[idx] - 1];
    }
  }

  st.site = &vg_emlrtRSI;
  PresolveWorkingSet(&st, solution, memspace, workingset, qrmanager);
  if (solution->state >= 0) {
    solution->iterations = 0;
    st.site = &vg_emlrtRSI;
    solution->maxConstr = c_maxConstraintViolation(&st, workingset,
      solution->xstar);
    if (solution->maxConstr > 1.0E-6) {
      st.site = &vg_emlrtRSI;
      phaseone(&st, H, f, solution, memspace, workingset, qrmanager, cholmanager,
               objective, options, runTimeOptions);
      if (solution->state != 0) {
        st.site = &vg_emlrtRSI;
        solution->maxConstr = c_maxConstraintViolation(&st, workingset,
          solution->xstar);
        if (solution->maxConstr > 1.0E-6) {
          st.site = &vg_emlrtRSI;
          c_xcopy(&st, 17, solution->lambda);
          st.site = &vg_emlrtRSI;
          solution->fstar = computeFval(&st, objective,
            memspace->workspace_double, H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            st.site = &vg_emlrtRSI;
            f_xcopy(&st, nVar, solution->xstar, solution->searchDir);
            st.site = &vg_emlrtRSI;
            PresolveWorkingSet(&st, solution, memspace, workingset, qrmanager);
            st.site = &vg_emlrtRSI;
            maxConstr_new = c_maxConstraintViolation(&st, workingset,
              solution->xstar);
            if (maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = maxConstr_new;
              st.site = &vg_emlrtRSI;
              f_xcopy(&st, nVar, solution->searchDir, solution->xstar);
            }
          }

          st.site = &vg_emlrtRSI;
          iterate(&st, H, f, solution, memspace, workingset, qrmanager,
                  cholmanager, objective, options->StepTolerance,
                  options->ObjectiveLimit, runTimeOptions->MaxIterations);
        }
      }
    } else {
      st.site = &vg_emlrtRSI;
      iterate(&st, H, f, solution, memspace, workingset, qrmanager, cholmanager,
              objective, options->StepTolerance, options->ObjectiveLimit,
              runTimeOptions->MaxIterations);
    }
  }
}

/* End of code generation (driver1.c) */
