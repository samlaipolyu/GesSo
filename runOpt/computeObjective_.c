/*
 * computeObjective_.c
 *
 * Code generation for function 'computeObjective_'
 *
 */

/* Include files */
#include "computeObjective_.h"
#include "fwk.h"
#include "fwkeul_alpha.h"
#include "fwkeul_beta.h"
#include "fwkeul_gamma.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = { 1,   /* lineNo */
  "computeObjective_",                 /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\computeObjective_.p"/* pathName */
};

/* Function Definitions */
void computeObjective_(const emlrtStack *sp, const real_T
  c_obj_objfun_tunableEnvironment[3], const real_T
  d_obj_objfun_tunableEnvironment[7], const real_T
  e_obj_objfun_tunableEnvironment[3], const real_T x[7], real_T *fval, int32_T
  *status)
{
  real_T b_x[3];
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
  st.site = &k_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  d_st.site = &m_emlrtRSI;
  fwk(&d_st, x, b_x);
  scale = 3.3121686421112381E-170;
  absxk = muDoubleScalarAbs(c_obj_objfun_tunableEnvironment[0] - b_x[0]);
  if (absxk > 3.3121686421112381E-170) {
    a = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    a = t * t;
  }

  absxk = muDoubleScalarAbs(c_obj_objfun_tunableEnvironment[1] - b_x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    a = a * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    a += t * t;
  }

  absxk = muDoubleScalarAbs(c_obj_objfun_tunableEnvironment[2] - b_x[2]);
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
    absxk = muDoubleScalarAbs(x[k] - d_obj_objfun_tunableEnvironment[k]);
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
  scale = fwkeul_alpha(&d_st, *(real_T (*)[6])&x[0]) -
    e_obj_objfun_tunableEnvironment[0];
  absxk = muDoubleScalarAbs(scale);
  c_st.site = &o_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  scale = fwkeul_gamma(&d_st, *(real_T (*)[6])&x[0]) -
    e_obj_objfun_tunableEnvironment[2];
  t = muDoubleScalarAbs(scale);
  c_st.site = &p_emlrtRSI;
  d_st.site = &p_emlrtRSI;
  scale = fwkeul_beta(&d_st, *(real_T (*)[6])&x[0]) -
    e_obj_objfun_tunableEnvironment[1];
  scale = muDoubleScalarAbs(scale);
  *fval = (((a * a + b_a * b_a) + absxk * absxk) + t * t) + scale * scale;
  *status = 1;
  if (muDoubleScalarIsInf(*fval) || muDoubleScalarIsNaN(*fval)) {
    if (muDoubleScalarIsNaN(*fval)) {
      *status = -6;
    } else {
      *status = -5;
    }
  }
}

/* End of code generation (computeObjective_.c) */
