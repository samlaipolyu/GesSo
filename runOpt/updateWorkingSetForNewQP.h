/*
 * updateWorkingSetForNewQP.h
 *
 * Code generation for function 'updateWorkingSetForNewQP'
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
void updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[7],
  e_struct_T *WorkingSet, real_T cIneq, int32_T mLB, const real_T lb[7], int32_T
  mUB, const real_T ub[7], int32_T mFixed);

/* End of code generation (updateWorkingSetForNewQP.h) */
