/*
 * feasibleX0ForWorkingSet.h
 *
 * Code generation for function 'feasibleX0ForWorkingSet'
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
boolean_T feasibleX0ForWorkingSet(const emlrtStack *sp, real_T workspace[153],
  real_T xCurrent[9], e_struct_T *workingset, i_struct_T *qrmanager);

/* End of code generation (feasibleX0ForWorkingSet.h) */
