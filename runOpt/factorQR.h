/*
 * factorQR.h
 *
 * Code generation for function 'factorQR'
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
void factorQR(const emlrtStack *sp, i_struct_T *obj, const real_T A[153],
              int32_T mrows, int32_T ncols);

/* End of code generation (factorQR.h) */
