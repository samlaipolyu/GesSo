/*
 * test_exit.h
 *
 * Code generation for function 'test_exit'
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
void b_test_exit(const emlrtStack *sp, struct_T *Flags, b_struct_T *memspace,
                 h_struct_T *MeritFunction, const e_struct_T *WorkingSet,
                 f_struct_T *TrialState, i_struct_T *QRManager, const real_T lb
                 [7], const real_T ub[7]);
void test_exit(const emlrtStack *sp, h_struct_T *MeritFunction, const e_struct_T
               *WorkingSet, f_struct_T *TrialState, const real_T lb[7], const
               real_T ub[7], boolean_T *Flags_gradOK, boolean_T *Flags_fevalOK,
               boolean_T *Flags_done, boolean_T *Flags_stepAccepted, boolean_T
               *Flags_failedLineSearch, int32_T *Flags_stepType);

/* End of code generation (test_exit.h) */
