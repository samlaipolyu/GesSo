/*
 * xcopy.h
 *
 * Code generation for function 'xcopy'
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
void b_xcopy(const emlrtStack *sp, int32_T n, const real_T x[17], real_T y[17]);
void c_xcopy(const emlrtStack *sp, int32_T n, real_T y[17]);
void d_xcopy(const emlrtStack *sp, int32_T n, const real_T x[153], int32_T ix0,
             real_T y[289], int32_T iy0);
void e_xcopy(const emlrtStack *sp, int32_T n, const real_T x[7], real_T y[9]);
void f_xcopy(const emlrtStack *sp, int32_T n, const real_T x[9], real_T y[9]);
void g_xcopy(const emlrtStack *sp, int32_T n, real_T y[49], int32_T iy0);
void xcopy(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0,
           real_T y[153], int32_T iy0);

/* End of code generation (xcopy.h) */
