/*
 * step.h
 *
 * Code generation for function 'step'
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
boolean_T step(const emlrtStack *sp, int32_T *STEP_TYPE, real_T Hessian[49],
               const real_T lb[7], const real_T ub[7], f_struct_T *TrialState,
               h_struct_T *MeritFunction, b_struct_T *memspace, e_struct_T
               *WorkingSet, i_struct_T *QRManager, k_struct_T *CholManager,
               j_struct_T *QPObjective, c_struct_T *qpoptions);

/* End of code generation (step.h) */
