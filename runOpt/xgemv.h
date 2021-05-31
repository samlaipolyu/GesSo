/*
 * xgemv.h
 *
 * Code generation for function 'xgemv'
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
void b_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[49],
             int32_T lda, const real_T x[9], real_T y[8]);
void c_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[289],
             int32_T ia0, const real_T x[153], real_T y[9]);
void d_xgemv(const emlrtStack *sp, int32_T m, const real_T A[9], const real_T x
             [9], real_T y[153]);
void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[289],
           const real_T x[9], real_T y[153]);

/* End of code generation (xgemv.h) */
