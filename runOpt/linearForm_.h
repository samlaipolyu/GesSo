/*
 * linearForm_.h
 *
 * Code generation for function 'linearForm_'
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
void linearForm_(const emlrtStack *sp, boolean_T obj_hasLinear, int32_T obj_nvar,
                 real_T workspace[153], const real_T H[49], const real_T f[9],
                 const real_T x[9]);

/* End of code generation (linearForm_.h) */
