/*
 * feasibleratiotest.h
 *
 * Code generation for function 'feasibleratiotest'
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
void feasibleratiotest(const emlrtStack *sp, const real_T solution_xstar[9],
  const real_T solution_searchDir[9], real_T workspace[153], int32_T
  workingset_nVar, const real_T workingset_Aineq[9], real_T workingset_bineq,
  const real_T workingset_lb[9], const real_T workingset_ub[9], const int32_T
  workingset_indexLB[9], const int32_T workingset_indexUB[9], const int32_T
  workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const boolean_T
  workingset_isActiveConstr[17], const int32_T workingset_nWConstr[5], boolean_T
  isPhaseOne, real_T *alpha, boolean_T *newBlocking, int32_T *constrType,
  int32_T *constrIdx);

/* End of code generation (feasibleratiotest.h) */
