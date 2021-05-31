/*
 * saveState.c
 *
 * Code generation for function 'saveState'
 *
 */

/* Include files */
#include "saveState.h"
#include "rt_nonfinite.h"
#include "runOpt.h"

/* Function Definitions */
void saveState(f_struct_T *obj)
{
  int32_T k;
  obj->sqpFval_old = obj->sqpFval;
  for (k = 0; k < 7; k++) {
    obj->xstarsqp_old[k] = obj->xstarsqp[k];
    obj->grad_old[k] = obj->grad[k];
  }

  obj->cIneq_old = obj->cIneq;
}

/* End of code generation (saveState.c) */
