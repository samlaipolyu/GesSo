/*
 * soc.h
 *
 * Code generation for function 'soc'
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
boolean_T soc(const emlrtStack *sp, const real_T Hessian[49], const real_T grad
              [9], f_struct_T *TrialState, b_struct_T *memspace, e_struct_T
              *WorkingSet, i_struct_T *QRManager, k_struct_T *CholManager,
              j_struct_T *QPObjective, const c_struct_T *qpoptions);

/* End of code generation (soc.h) */
