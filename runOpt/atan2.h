/*
 * atan2.h
 *
 * Code generation for function 'atan2'
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
void b_atan2(const emlrtStack *sp, const real_T y_data[], const int32_T y_size[3],
             const real_T x_data[], const int32_T x_size[3], real_T r_data[],
             int32_T r_size[3]);

/* End of code generation (atan2.h) */
