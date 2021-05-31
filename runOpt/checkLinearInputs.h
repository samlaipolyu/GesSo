/*
 * checkLinearInputs.h
 *
 * Code generation for function 'checkLinearInputs'
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
void checkLinearInputs(const emlrtStack *sp, const real_T x0[7], const real_T
  Aineq[7], real_T bineq, const real_T lb[7], const real_T ub[7]);

/* End of code generation (checkLinearInputs.h) */
