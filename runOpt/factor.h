/*
 * factor.h
 *
 * Code generation for function 'factor'
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
void factor(const emlrtStack *sp, k_struct_T *obj, const real_T A[49], int32_T
            ndims, int32_T ldA);

/* End of code generation (factor.h) */
