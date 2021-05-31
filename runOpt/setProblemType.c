/*
 * setProblemType.c
 *
 * Code generation for function 'setProblemType'
 *
 */

/* Include files */
#include "setProblemType.h"
#include "eml_int_forloop_overflow_check.h"
#include "modifyOverheadPhaseOne_.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo id_emlrtRSI = { 1,  /* lineNo */
  "setProblemType",                    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\setProblemType.p"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 1,  /* lineNo */
  "modifyOverheadRegularized_",        /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\modifyOverheadRegularized_.p"/* pathName */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "modifyOverheadRegularized_",        /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\modifyOverheadRegularized_.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "modifyOverheadRegularized_",        /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\modifyOverheadRegularized_.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void setProblemType(const emlrtStack *sp, e_struct_T *obj, int32_T PROBLEM_TYPE)
{
  int32_T idx;
  int32_T b;
  int32_T idx_col;
  int32_T idx_lb;
  int32_T idxStartIneq;
  int32_T idx_row;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = 7;
    obj->mConstr = obj->mConstrOrig;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesNormal[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxNormal[idx];
    }
    break;

   case 1:
    obj->nVar = 8;
    obj->mConstr = obj->mConstrOrig + 1;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesPhaseOne[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxPhaseOne[idx];
    }

    st.site = &id_emlrtRSI;
    modifyOverheadPhaseOne_(&st, obj);
    break;

   case 2:
    obj->nVar = 8;
    obj->mConstr = 16;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesRegularized[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxRegularized[idx];
    }

    if (obj->probType != 4) {
      st.site = &id_emlrtRSI;
      b = obj->sizes[0];
      b_st.site = &kd_emlrtRSI;
      if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx_col = 0; idx_col < b; idx_col++) {
        b_st.site = &kd_emlrtRSI;
        obj->ATwset[9 * idx_col + 7] = 0.0;
      }

      b_st.site = &kd_emlrtRSI;
      obj->Aineq[7] = -1.0;
      b_st.site = &kd_emlrtRSI;
      b_st.site = &kd_emlrtRSI;
      b_st.site = &kd_emlrtRSI;
      idx_lb = 7;
      idxStartIneq = obj->sizesNormal[3] + 1;
      b = obj->sizesRegularized[3];
      b_st.site = &kd_emlrtRSI;
      if ((obj->sizesNormal[3] + 1 <= obj->sizesRegularized[3]) &&
          (obj->sizesRegularized[3] > 2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx = idxStartIneq; idx <= b; idx++) {
        idx_lb++;
        obj->indexLB[idx - 1] = idx_lb;
      }

      b_st.site = &kd_emlrtRSI;
      obj->lb[7] = 0.0;
      idxStartIneq = obj->isActiveIdx[2];
      b = obj->nActiveConstr;
      b_st.site = &kd_emlrtRSI;
      if ((obj->isActiveIdx[2] <= obj->nActiveConstr) && (obj->nActiveConstr >
           2147483646)) {
        c_st.site = &d_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx_col = idxStartIneq; idx_col <= b; idx_col++) {
        if ((idx_col < 1) || (idx_col > 17)) {
          emlrtDynamicBoundsCheckR2012b(idx_col, 1, 17, &h_emlrtBCI, &st);
        }

        switch (obj->Wid[idx_col - 1]) {
         case 3:
          idx_lb = obj->Wlocalidx[idx_col - 1] + 6;
          b_st.site = &kd_emlrtRSI;
          if ((8 <= idx_lb) && (idx_lb > 2147483646)) {
            c_st.site = &d_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (idx_row = 8; idx_row <= idx_lb; idx_row++) {
            if (idx_row > 9) {
              emlrtDynamicBoundsCheckR2012b(idx_row, 1, 9, &g_emlrtBCI, &st);
            }

            obj->ATwset[(idx_row + 9 * (idx_col - 1)) - 1] = 0.0;
          }

          idx = obj->Wlocalidx[idx_col - 1] + 7;
          if ((idx < 1) || (idx > 9)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, 9, &g_emlrtBCI, &st);
          }

          idx_lb = 9 * (idx_col - 1);
          obj->ATwset[(idx + idx_lb) - 1] = -1.0;
          idx = obj->Wlocalidx[idx_col - 1] + 8;
          b_st.site = &kd_emlrtRSI;
          for (idx_row = idx; idx_row < 9; idx_row++) {
            if (idx_row < 1) {
              emlrtDynamicBoundsCheckR2012b(idx_row, 1, 9, &g_emlrtBCI, &st);
            }

            obj->ATwset[(idx_row + idx_lb) - 1] = 0.0;
          }
          break;

         default:
          b_st.site = &kd_emlrtRSI;
          obj->ATwset[9 * (idx_col - 1) + 7] = 0.0;
          break;
        }
      }
    }
    break;

   default:
    obj->nVar = 9;
    obj->mConstr = 17;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesRegPhaseOne[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxRegPhaseOne[idx];
    }

    st.site = &id_emlrtRSI;
    modifyOverheadPhaseOne_(&st, obj);
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

/* End of code generation (setProblemType.c) */
