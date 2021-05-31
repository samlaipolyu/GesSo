/*
 * finDiffEvalAndChkErr.c
 *
 * Code generation for function 'finDiffEvalAndChkErr'
 *
 */

/* Include files */
#include "finDiffEvalAndChkErr.h"
#include "fwk.h"
#include "fwkeul_alpha.h"
#include "fwkeul_beta.h"
#include "fwkeul_gamma.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo yc_emlrtRSI = { 1,  /* lineNo */
  "finDiffEvalAndChkErr",              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+utils\\+FiniteDifferences\\+internal\\finDiffEvalAndChkErr.p"/* pathName */
};

/* Function Definitions */
boolean_T finDiffEvalAndChkErr(const emlrtStack *sp, const real_T
  c_obj_objfun_tunableEnvironment[3], const real_T
  d_obj_objfun_tunableEnvironment[7], const real_T
  e_obj_objfun_tunableEnvironment[3], real_T *fplus, int32_T dim, real_T delta,
  real_T xk[7])
{
  boolean_T evalOK;
  real_T temp_tmp;
  real_T x[3];
  real_T scale;
  real_T absxk;
  real_T t;
  real_T a;
  real_T b_a;
  int32_T k;
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
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  st.site = &yc_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  d_st.site = &m_emlrtRSI;
  fwk(&d_st, xk, x);
  scale = 3.3121686421112381E-170;
  absxk = muDoubleScalarAbs(c_obj_objfun_tunableEnvironment[0] - x[0]);
  if (absxk > 3.3121686421112381E-170) {
    a = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    a = t * t;
  }

  absxk = muDoubleScalarAbs(c_obj_objfun_tunableEnvironment[1] - x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    a = a * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    a += t * t;
  }

  absxk = muDoubleScalarAbs(c_obj_objfun_tunableEnvironment[2] - x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    a = a * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    a += t * t;
  }

  a = scale * muDoubleScalarSqrt(a);
  c_st.site = &m_emlrtRSI;
  b_a = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 6; k++) {
    absxk = muDoubleScalarAbs(xk[k] - d_obj_objfun_tunableEnvironment[k]);
    if (absxk > scale) {
      t = scale / absxk;
      b_a = b_a * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_a += t * t;
    }
  }

  b_a = scale * muDoubleScalarSqrt(b_a);
  c_st.site = &n_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  scale = fwkeul_alpha(&d_st, *(real_T (*)[6])&xk[0]) -
    e_obj_objfun_tunableEnvironment[0];
  absxk = muDoubleScalarAbs(scale);
  c_st.site = &o_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  scale = fwkeul_gamma(&d_st, *(real_T (*)[6])&xk[0]) -
    e_obj_objfun_tunableEnvironment[2];
  t = muDoubleScalarAbs(scale);
  c_st.site = &p_emlrtRSI;
  d_st.site = &p_emlrtRSI;
  scale = fwkeul_beta(&d_st, *(real_T (*)[6])&xk[0]) -
    e_obj_objfun_tunableEnvironment[1];
  scale = muDoubleScalarAbs(scale);
  *fplus = (((a * a + b_a * b_a) + absxk * absxk) + t * t) + scale * scale;
  evalOK = ((!muDoubleScalarIsInf(*fplus)) && (!muDoubleScalarIsNaN(*fplus)));
  if (evalOK) {
    xk[dim - 1] = temp_tmp;
  }

  return evalOK;
}

/* End of code generation (finDiffEvalAndChkErr.c) */
