/*
 * computeDualFeasError.h
 *
 * Code generation for function 'computeDualFeasError'
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
void b_computeDualFeasError(const emlrtStack *sp, int32_T nVar, const real_T
  gradLag[153], boolean_T *gradOK, real_T *val);
void computeDualFeasError(const emlrtStack *sp, int32_T nVar, const real_T
  gradLag[9], boolean_T *gradOK, real_T *val);

/* End of code generation (computeDualFeasError.h) */
