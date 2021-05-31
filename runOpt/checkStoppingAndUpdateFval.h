/*
 * checkStoppingAndUpdateFval.h
 *
 * Code generation for function 'checkStoppingAndUpdateFval'
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
void checkStoppingAndUpdateFval(const emlrtStack *sp, int32_T *activeSetChangeID,
  const real_T f[9], f_struct_T *solution, b_struct_T *memspace, const
  j_struct_T *objective, e_struct_T *workingset, i_struct_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, boolean_T
  updateFval);

/* End of code generation (checkStoppingAndUpdateFval.h) */
