/*
 * BFGSUpdate.h
 *
 * Code generation for function 'BFGSUpdate'
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
boolean_T BFGSUpdate(const emlrtStack *sp, int32_T nvar, real_T Bk[49], const
                     real_T sk[9], real_T yk[9], real_T workspace[153]);

/* End of code generation (BFGSUpdate.h) */
