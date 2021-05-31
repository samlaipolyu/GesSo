/*
 * computeGradLag.h
 *
 * Code generation for function 'computeGradLag'
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
void b_computeGradLag(const emlrtStack *sp, real_T workspace[153], int32_T nVar,
                      const real_T grad[9], const real_T AineqTrans[9], const
                      int32_T finiteFixed[9], int32_T mFixed, const int32_T
                      finiteLB[9], int32_T mLB, const int32_T finiteUB[9],
                      int32_T mUB, const real_T lambda[17]);
void computeGradLag(const emlrtStack *sp, real_T workspace[9], int32_T nVar,
                    const real_T grad[9], const real_T AineqTrans[9], const
                    int32_T finiteFixed[9], int32_T mFixed, const int32_T
                    finiteLB[9], int32_T mLB, const int32_T finiteUB[9], int32_T
                    mUB, const real_T lambda[17]);

/* End of code generation (computeGradLag.h) */
