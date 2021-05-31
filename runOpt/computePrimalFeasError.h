/*
 * computePrimalFeasError.h
 *
 * Code generation for function 'computePrimalFeasError'
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
real_T computePrimalFeasError(const emlrtStack *sp, const real_T x[7], real_T
  cIneq, const int32_T finiteLB[9], int32_T mLB, const real_T lb[7], const
  int32_T finiteUB[9], int32_T mUB, const real_T ub[7]);

/* End of code generation (computePrimalFeasError.h) */
