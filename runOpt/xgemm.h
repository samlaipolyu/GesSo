/*
 * xgemm.h
 *
 * Code generation for function 'xgemm'
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
void b_xgemm(int32_T m, int32_T k, const real_T A[289], const real_T B[153],
             real_T C[153]);
void c_xgemm(const emlrtStack *sp, int32_T m, int32_T n, int32_T k, const real_T
             A[49], int32_T lda, const real_T B[289], int32_T ib0, real_T C[153]);
void d_xgemm(int32_T m, int32_T n, int32_T k, const real_T A[289], int32_T ia0,
             const real_T B[153], real_T C[289]);
void xgemm(int32_T m, int32_T k, const real_T A[289], const real_T B[153],
           real_T C[153]);

/* End of code generation (xgemm.h) */
