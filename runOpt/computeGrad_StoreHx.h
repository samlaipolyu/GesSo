/*
 * computeGrad_StoreHx.h
 *
 * Code generation for function 'computeGrad_StoreHx'
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
void computeGrad_StoreHx(const emlrtStack *sp, j_struct_T *obj, const real_T H
  [49], const real_T f[9], const real_T x[9]);

/* End of code generation (computeGrad_StoreHx.h) */
