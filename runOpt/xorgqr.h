/*
 * xorgqr.h
 *
 * Code generation for function 'xorgqr'
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
void xorgqr(const emlrtStack *sp, int32_T m, int32_T n, int32_T k, real_T A[289],
            const real_T tau[17]);

/* End of code generation (xorgqr.h) */
