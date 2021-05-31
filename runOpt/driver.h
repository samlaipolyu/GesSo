/*
 * driver.h
 *
 * Code generation for function 'driver'
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
void driver(const emlrtStack *sp, real_T bineq, const real_T lb[7], const real_T
            ub[7], f_struct_T *TrialState, h_struct_T *MeritFunction, const
            g_struct_T *FcnEvaluator, d_struct_T *FiniteDifferences, b_struct_T *
            memspace, e_struct_T *WorkingSet, i_struct_T *QRManager, j_struct_T *
            QPObjective, real_T Hessian[49], k_struct_T *CholManager);

/* End of code generation (driver.h) */
