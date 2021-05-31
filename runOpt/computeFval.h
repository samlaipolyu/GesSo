/*
 * computeFval.h
 *
 * Code generation for function 'computeFval'
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
real_T computeFval(const emlrtStack *sp, const j_struct_T *obj, real_T
                   workspace[153], const real_T H[49], const real_T f[9], const
                   real_T x[9]);

/* End of code generation (computeFval.h) */
