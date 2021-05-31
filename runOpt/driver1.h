/*
 * driver1.h
 *
 * Code generation for function 'driver1'
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
void b_driver(const emlrtStack *sp, const real_T H[49], const real_T f[9],
              f_struct_T *solution, b_struct_T *memspace, e_struct_T *workingset,
              i_struct_T *qrmanager, k_struct_T *cholmanager, j_struct_T
              *objective, c_struct_T *options, c_struct_T *runTimeOptions);

/* End of code generation (driver1.h) */
