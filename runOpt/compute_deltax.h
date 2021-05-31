/*
 * compute_deltax.h
 *
 * Code generation for function 'compute_deltax'
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
void compute_deltax(const emlrtStack *sp, const real_T H[49], f_struct_T
                    *solution, b_struct_T *memspace, const i_struct_T *qrmanager,
                    k_struct_T *cholmanager, const j_struct_T *objective);

/* End of code generation (compute_deltax.h) */
