/*
 * relaxed.h
 *
 * Code generation for function 'relaxed'
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
void relaxed(const emlrtStack *sp, const real_T Hessian[49], const real_T grad[9],
             f_struct_T *TrialState, h_struct_T *MeritFunction, b_struct_T
             *memspace, e_struct_T *WorkingSet, i_struct_T *QRManager,
             k_struct_T *CholManager, j_struct_T *QPObjective, c_struct_T
             *qpoptions);

/* End of code generation (relaxed.h) */
