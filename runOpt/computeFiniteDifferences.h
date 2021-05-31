/*
 * computeFiniteDifferences.h
 *
 * Code generation for function 'computeFiniteDifferences'
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
boolean_T computeFiniteDifferences(const emlrtStack *sp, d_struct_T *obj, real_T
  fCurrent, real_T xk[7], real_T gradf[9], const real_T lb[7], const real_T ub[7]);

/* End of code generation (computeFiniteDifferences.h) */
