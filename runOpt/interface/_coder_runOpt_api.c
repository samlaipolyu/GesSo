/*
 * _coder_runOpt_api.c
 *
 * Code generation for function '_coder_runOpt_api'
 *
 */

/* Include files */
#include "_coder_runOpt_api.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void b_emlrt_marshallOut(const real_T u[7], const mxArray *y);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *task,
  const char_T *identifier))[3];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *q_prev,
  const char_T *identifier))[7];
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_feval_, const char_T *identifier);
static const mxArray *emlrt_marshallOut(const real_T u[7]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[7];
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *A, const
  char_T *identifier))[7];
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[7];
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *set_angle, const char_T *identifier))[3];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7];
static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7];
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void b_emlrt_marshallOut(const real_T u[7], const mxArray *y)
{
  static const int32_T iv[1] = { 7 };

  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, iv, 1);
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *task,
  const char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(task), &thisId);
  emlrtDestroyArray(&task);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *q_prev,
  const char_T *identifier))[7]
{
  real_T (*y)[7];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(q_prev), &thisId);
  emlrtDestroyArray(&q_prev);
  return y;
}
  static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_feval_, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_feval_), &thisId);
  emlrtDestroyArray(&a__output_of_feval_);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[7])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 7 };

  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[7]
{
  real_T (*y)[7];
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *A,
  const char_T *identifier))[7]
{
  real_T (*y)[7];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(A), &thisId);
  emlrtDestroyArray(&A);
  return y;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[7]
{
  real_T (*y)[7];
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *set_angle, const char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(set_angle), &thisId);
  emlrtDestroyArray(&set_angle);
  return y;
}

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  static const int32_T dims[1] = { 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7]
{
  real_T (*ret)[7];
  static const int32_T dims[1] = { 7 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[7])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7]
{
  real_T (*ret)[7];
  static const int32_T dims[2] = { 1, 7 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[7])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  static const int32_T dims[2] = { 1, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void runOpt_api(const mxArray * const prhs[8], int32_T nlhs, const mxArray *
                plhs[2])
{
  real_T (*q)[7];
  const mxArray *prhs_copy_idx_1;
  real_T (*task)[3];
  real_T (*q_prev)[7];
  real_T (*x0)[7];
  real_T (*A)[7];
  real_T b;
  real_T (*lb)[7];
  real_T (*ub)[7];
  real_T (*set_angle)[3];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  q = (real_T (*)[7])mxMalloc(sizeof(real_T [7]));
  prhs_copy_idx_1 = emlrtProtectR2012b(prhs[1], 1, true, -1);

  /* Marshall function inputs */
  task = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "task");
  q_prev = e_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "q_prev");
  x0 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "x0");
  A = g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "A");
  b = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "b");
  lb = e_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "lb");
  ub = e_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "ub");
  set_angle = i_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "set_angle");

  /* Invoke the target function */
  runOpt(&st, *task, *q_prev, *x0, *A, b, *lb, *ub, *set_angle, *q);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*q);
  if (nlhs > 1) {
    b_emlrt_marshallOut(*q_prev, prhs_copy_idx_1);
    plhs[1] = prhs_copy_idx_1;
  }
}

/* End of code generation (_coder_runOpt_api.c) */
