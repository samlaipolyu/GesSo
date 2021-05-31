/*
 * xdot.h
 *
 * Code generation for function 'xdot'
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
real_T b_xdot(const emlrtStack *sp, int32_T n, const real_T x[9], const real_T
              y[8]);
real_T c_xdot(const emlrtStack *sp, int32_T n, const real_T x[9], const real_T
              y[9]);
real_T xdot(const emlrtStack *sp, int32_T n, const real_T x[9], const real_T y
            [153]);

/* End of code generation (xdot.h) */
