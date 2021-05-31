/*
 * xgeqrf.h
 *
 * Code generation for function 'xgeqrf'
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
void xgeqrf(const emlrtStack *sp, real_T A[289], int32_T m, int32_T n, real_T
            tau[17]);

/* End of code generation (xgeqrf.h) */
