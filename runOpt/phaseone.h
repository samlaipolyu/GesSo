/*
 * phaseone.h
 *
 * Code generation for function 'phaseone'
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
void phaseone(const emlrtStack *sp, const real_T H[49], const real_T f[9],
              f_struct_T *solution, b_struct_T *memspace, e_struct_T *workingset,
              i_struct_T *qrmanager, k_struct_T *cholmanager, j_struct_T
              *objective, c_struct_T *options, const c_struct_T *runTimeOptions);

/* End of code generation (phaseone.h) */
