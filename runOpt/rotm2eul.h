/*
 * rotm2eul.h
 *
 * Code generation for function 'rotm2eul'
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
void rotm2eul(const emlrtStack *sp, const real_T R[9], real_T eul[3]);

/* End of code generation (rotm2eul.h) */
