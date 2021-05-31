/*
 * computeDualFeasError.c
 *
 * Code generation for function 'computeDualFeasError'
 *
 */

/* Include files */
#include "computeDualFeasError.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo td_emlrtRSI = { 1,  /* lineNo */
  "computeDualFeasError",              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\computeDualFeasError.p"/* pathName */
};

/* Function Definitions */
void b_computeDualFeasError(const emlrtStack *sp, int32_T nVar, const real_T
  gradLag[153], boolean_T *gradOK, real_T *val)
{
  int32_T idx;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  *gradOK = true;
  *val = 0.0;
  st.site = &td_emlrtRSI;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= nVar - 1)) {
    *gradOK = ((!muDoubleScalarIsInf(gradLag[idx])) && (!muDoubleScalarIsNaN
                (gradLag[idx])));
    if (!*gradOK) {
      exitg1 = true;
    } else {
      *val = muDoubleScalarMax(*val, muDoubleScalarAbs(gradLag[idx]));
      idx++;
    }
  }
}

void computeDualFeasError(const emlrtStack *sp, int32_T nVar, const real_T
  gradLag[9], boolean_T *gradOK, real_T *val)
{
  int32_T idx;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  *gradOK = true;
  *val = 0.0;
  st.site = &td_emlrtRSI;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= nVar - 1)) {
    *gradOK = ((!muDoubleScalarIsInf(gradLag[idx])) && (!muDoubleScalarIsNaN
                (gradLag[idx])));
    if (!*gradOK) {
      exitg1 = true;
    } else {
      *val = muDoubleScalarMax(*val, muDoubleScalarAbs(gradLag[idx]));
      idx++;
    }
  }
}

/* End of code generation (computeDualFeasError.c) */
