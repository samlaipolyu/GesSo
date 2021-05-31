/*
 * xtrsv.c
 *
 * Code generation for function 'xtrsv'
 *
 */

/* Include files */
#include "xtrsv.h"
#include "rt_nonfinite.h"
#include "runOpt.h"

/* Function Definitions */
void xtrsv(int32_T n, const real_T A[289], real_T x[153])
{
  int32_T j;
  int32_T jjA;
  int32_T i;
  int32_T ix;
  if (n != 0) {
    for (j = n; j >= 1; j--) {
      jjA = (j + (j - 1) * 17) - 1;
      x[j - 1] /= A[jjA];
      for (i = 0; i <= j - 2; i++) {
        ix = (j - i) - 2;
        x[ix] -= x[j - 1] * A[(jjA - i) - 1];
      }
    }
  }
}

/* End of code generation (xtrsv.c) */
