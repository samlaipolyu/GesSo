/*
 * factoryConstruct1.c
 *
 * Code generation for function 'factoryConstruct1'
 *
 */

/* Include files */
#include "factoryConstruct1.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = { 1,   /* lineNo */
  "factoryConstruct",                  /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\factoryConstruct.p"/* pathName */
};

/* Function Definitions */
void b_factoryConstruct(const emlrtStack *sp, const real_T Aineq[7], int32_T mLB,
  const int32_T indexLB[7], int32_T mUB, const int32_T indexUB[7], int32_T
  mFixed, const int32_T indexFixed[7], e_struct_T *obj)
{
  int32_T i;
  int32_T obj_tmp[5];
  int32_T b_obj_tmp[6];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  i = ((mLB + mUB) + mFixed) + 1;
  obj->mConstr = i;
  obj->mConstrOrig = i;
  obj->mConstrMax = 17;
  obj->nVar = 7;
  obj->nVarOrig = 7;
  obj->nVarMax = 9;
  obj->ldA = 9;
  obj->mEqRemoved = 0;
  obj->nActiveConstr = 0;
  obj_tmp[0] = mFixed;
  obj_tmp[1] = 0;
  obj_tmp[2] = 1;
  obj_tmp[3] = mLB;
  obj_tmp[4] = mUB;
  for (i = 0; i < 5; i++) {
    obj->sizes[i] = obj_tmp[i];
    obj->sizesNormal[i] = obj_tmp[i];
  }

  obj_tmp[0] = mFixed;
  obj_tmp[1] = 0;
  obj_tmp[2] = 1;
  obj_tmp[3] = mLB + 1;
  obj_tmp[4] = mUB;
  obj->sizesRegPhaseOne[0] = mFixed;
  obj->sizesRegPhaseOne[1] = 0;
  obj->sizesRegPhaseOne[2] = 1;
  obj->sizesRegPhaseOne[3] = mLB + 2;
  obj->sizesRegPhaseOne[4] = mUB;
  b_obj_tmp[0] = 1;
  b_obj_tmp[1] = mFixed;
  b_obj_tmp[2] = 0;
  b_obj_tmp[3] = 1;
  b_obj_tmp[4] = mLB;
  b_obj_tmp[5] = mUB;
  for (i = 0; i < 5; i++) {
    obj->sizesPhaseOne[i] = obj_tmp[i];
    obj->sizesRegularized[i] = obj_tmp[i];
    b_obj_tmp[i + 1] += b_obj_tmp[i];
  }

  for (i = 0; i < 6; i++) {
    obj->isActiveIdx[i] = b_obj_tmp[i];
    obj->isActiveIdxNormal[i] = b_obj_tmp[i];
  }

  b_obj_tmp[0] = 1;
  b_obj_tmp[1] = mFixed;
  b_obj_tmp[2] = 0;
  b_obj_tmp[3] = 1;
  b_obj_tmp[4] = mLB + 1;
  b_obj_tmp[5] = mUB;
  for (i = 0; i < 5; i++) {
    b_obj_tmp[i + 1] += b_obj_tmp[i];
  }

  for (i = 0; i < 6; i++) {
    obj->isActiveIdxPhaseOne[i] = b_obj_tmp[i];
    obj->isActiveIdxRegularized[i] = b_obj_tmp[i];
  }

  b_obj_tmp[0] = 1;
  b_obj_tmp[1] = mFixed;
  b_obj_tmp[2] = 0;
  b_obj_tmp[3] = 1;
  b_obj_tmp[4] = mLB + 2;
  b_obj_tmp[5] = mUB;
  for (i = 0; i < 5; i++) {
    b_obj_tmp[i + 1] += b_obj_tmp[i];
  }

  for (i = 0; i < 6; i++) {
    obj->isActiveIdxRegPhaseOne[i] = b_obj_tmp[i];
  }

  for (i = 0; i < 5; i++) {
    obj->nWConstr[i] = 0;
  }

  obj->probType = 3;
  obj->SLACK0 = 1.0E-5;
  for (i = 0; i < 7; i++) {
    obj->Aineq[i] = Aineq[i];
  }

  st.site = &c_emlrtRSI;
  if ((1 <= mLB) && (mLB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  if (0 <= mLB - 1) {
    memcpy(&obj->indexLB[0], &indexLB[0], mLB * sizeof(int32_T));
  }

  st.site = &c_emlrtRSI;
  if ((1 <= mUB) && (mUB > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  if (0 <= mUB - 1) {
    memcpy(&obj->indexUB[0], &indexUB[0], mUB * sizeof(int32_T));
  }

  st.site = &c_emlrtRSI;
  if ((1 <= mFixed) && (mFixed > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  if (0 <= mFixed - 1) {
    memcpy(&obj->indexFixed[0], &indexFixed[0], mFixed * sizeof(int32_T));
  }
}

/* End of code generation (factoryConstruct1.c) */
