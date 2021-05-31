/*
 * computeLinearResiduals.h
 *
 * Code generation for function 'computeLinearResiduals'
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
void computeLinearResiduals(const emlrtStack *sp, const real_T x[7], int32_T
  nVar, real_T *workspaceIneq, const real_T AineqT[9], real_T bineq);

/* End of code generation (computeLinearResiduals.h) */
