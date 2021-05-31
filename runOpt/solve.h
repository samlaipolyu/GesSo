/*
 * solve.h
 *
 * Code generation for function 'solve'
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
void solve(const emlrtStack *sp, const k_struct_T *obj, real_T rhs[9]);

/* End of code generation (solve.h) */
