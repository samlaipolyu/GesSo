/*
 * sortLambdaQP.c
 *
 * Code generation for function 'sortLambdaQP'
 *
 */

/* Include files */
#include "sortLambdaQP.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xcopy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hf_emlrtRSI = { 1,  /* lineNo */
  "sortLambdaQP",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+parseoutput\\sortLambdaQP.p"/* pathName */
};

static emlrtBCInfo w_emlrtBCI = { 1,   /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "sortLambdaQP",                      /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+parseoutput\\sortLambdaQP.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { 1,   /* iFirst */
  153,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "sortLambdaQP",                      /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+parseoutput\\sortLambdaQP.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { 1,   /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "sortLambdaQP",                      /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+parseoutput\\sortLambdaQP.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void sortLambdaQP(const emlrtStack *sp, real_T lambda[17], int32_T
                  WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5],
                  const int32_T WorkingSet_isActiveIdx[6], const int32_T
                  WorkingSet_Wid[17], const int32_T WorkingSet_Wlocalidx[17],
                  real_T workspace[153])
{
  int32_T mAll;
  int32_T currentMplier;
  int32_T idx;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (WorkingSet_nActiveConstr != 0) {
    mAll = ((WorkingSet_sizes[0] + WorkingSet_sizes[3]) + WorkingSet_sizes[4]) +
      1;
    st.site = &hf_emlrtRSI;
    b_st.site = &fd_emlrtRSI;
    c_st.site = &gd_emlrtRSI;
    if ((1 <= mAll) && (mAll > 2147483646)) {
      d_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    if (0 <= mAll - 1) {
      memcpy(&workspace[0], &lambda[0], mAll * sizeof(real_T));
    }

    st.site = &hf_emlrtRSI;
    c_xcopy(&st, mAll, lambda);
    currentMplier = 1;
    idx = 1;
    exitg1 = false;
    while ((!exitg1) && (idx <= WorkingSet_nActiveConstr)) {
      if (idx > 17) {
        emlrtDynamicBoundsCheckR2012b(18, 1, 17, &w_emlrtBCI, sp);
      }

      if (WorkingSet_Wid[idx - 1] <= 2) {
        switch (WorkingSet_Wid[idx - 1]) {
         case 1:
          mAll = 0;
          break;

         default:
          mAll = WorkingSet_isActiveIdx[1] - 1;
          break;
        }

        if (currentMplier > 153) {
          emlrtDynamicBoundsCheckR2012b(154, 1, 153, &x_emlrtBCI, sp);
        }

        mAll += WorkingSet_Wlocalidx[idx - 1];
        if ((mAll < 1) || (mAll > 17)) {
          emlrtDynamicBoundsCheckR2012b(mAll, 1, 17, &y_emlrtBCI, sp);
        }

        lambda[mAll - 1] = workspace[currentMplier - 1];
        currentMplier++;
        idx++;
      } else {
        exitg1 = true;
      }
    }

    while (idx <= WorkingSet_nActiveConstr) {
      if (idx > 17) {
        emlrtDynamicBoundsCheckR2012b(18, 1, 17, &w_emlrtBCI, sp);
      }

      switch (WorkingSet_Wid[idx - 1]) {
       case 3:
        mAll = WorkingSet_isActiveIdx[2];
        break;

       case 4:
        mAll = WorkingSet_isActiveIdx[3];
        break;

       default:
        mAll = WorkingSet_isActiveIdx[4];
        break;
      }

      if (currentMplier > 153) {
        emlrtDynamicBoundsCheckR2012b(154, 1, 153, &x_emlrtBCI, sp);
      }

      mAll = (mAll + WorkingSet_Wlocalidx[idx - 1]) - 1;
      if ((mAll < 1) || (mAll > 17)) {
        emlrtDynamicBoundsCheckR2012b(mAll, 1, 17, &y_emlrtBCI, sp);
      }

      lambda[mAll - 1] = workspace[currentMplier - 1];
      currentMplier++;
      idx++;
    }
  }
}

/* End of code generation (sortLambdaQP.c) */
