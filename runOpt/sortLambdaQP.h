/*
 * sortLambdaQP.h
 *
 * Code generation for function 'sortLambdaQP'
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
void sortLambdaQP(const emlrtStack *sp, real_T lambda[17], int32_T
                  WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5],
                  const int32_T WorkingSet_isActiveIdx[6], const int32_T
                  WorkingSet_Wid[17], const int32_T WorkingSet_Wlocalidx[17],
                  real_T workspace[153]);

/* End of code generation (sortLambdaQP.h) */
