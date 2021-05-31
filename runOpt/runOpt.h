/*
 * runOpt.h
 *
 * Code generation for function 'runOpt'
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
void runOpt(const emlrtStack *sp, const real_T task[3], real_T q_prev[7], const
            real_T x0[7], const real_T A[7], real_T b, const real_T lb[7], const
            real_T ub[7], const real_T set_angle[3], real_T q[7]);

/* End of code generation (runOpt.h) */
