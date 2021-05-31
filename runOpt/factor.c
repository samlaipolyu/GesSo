/*
 * factor.c
 *
 * Code generation for function 'factor'
 *
 */

/* Include files */
#include "factor.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xpotrf.h"

/* Function Definitions */
void factor(const emlrtStack *sp, k_struct_T *obj, const real_T A[49], int32_T
            ndims, int32_T ldA)
{
  int32_T idx;
  int32_T ix0;
  int32_T iy0;
  int32_T k;
  int32_T b_k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj->ndims = ndims;
  st.site = &th_emlrtRSI;
  if ((1 <= ndims) && (ndims > 2147483646)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (idx = 0; idx < ndims; idx++) {
    ix0 = ldA * idx;
    iy0 = 17 * idx;
    st.site = &th_emlrtRSI;
    for (k = 0; k < ndims; k++) {
      b_k = k + 1;
      obj->FMat[(iy0 + b_k) - 1] = A[(ix0 + b_k) - 1];
    }
  }

  st.site = &th_emlrtRSI;
  obj->info = xpotrf(&st, ndims, obj->FMat);
}

/* End of code generation (factor.c) */
