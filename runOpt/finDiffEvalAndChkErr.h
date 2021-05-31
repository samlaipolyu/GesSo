/*
 * finDiffEvalAndChkErr.h
 *
 * Code generation for function 'finDiffEvalAndChkErr'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "runOpt_types.h"

/* Function Declarations */
boolean_T finDiffEvalAndChkErr(const emlrtStack *sp, const real_T
  c_obj_objfun_tunableEnvironment[3], const real_T
  d_obj_objfun_tunableEnvironment[7], const real_T
  e_obj_objfun_tunableEnvironment[3], real_T *fplus, int32_T dim, real_T delta,
  real_T xk[7]);

/* End of code generation (finDiffEvalAndChkErr.h) */
