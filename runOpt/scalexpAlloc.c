/*
 * scalexpAlloc.c
 *
 * Code generation for function 'scalexpAlloc'
 *
 */

/* Include files */
#include "scalexpAlloc.h"
#include "rt_nonfinite.h"
#include "runOpt.h"

/* Function Definitions */
boolean_T dimagree(const int32_T z_size[3], const int32_T varargin_1_size[3],
                   const int32_T varargin_2_size[3])
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  p = true;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (z_size[k] != varargin_1_size[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    b_p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (z_size[k] != varargin_2_size[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (!b_p) {
      p = false;
    }
  } else {
    p = false;
  }

  return p;
}

/* End of code generation (scalexpAlloc.c) */
