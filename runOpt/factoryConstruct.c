/*
 * factoryConstruct.c
 *
 * Code generation for function 'factoryConstruct'
 *
 */

/* Include files */
#include "factoryConstruct.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"

/* Function Definitions */
void factoryConstruct(const real_T objfun_tunableEnvironment_f1[3], const real_T
                      objfun_tunableEnvironment_f2[7], const real_T
                      objfun_tunableEnvironment_f3[3], const real_T lb[7], const
                      real_T ub[7], d_struct_T *obj)
{
  int32_T i;
  boolean_T b;
  boolean_T bv[7];
  boolean_T bv1[7];
  obj->objfun.tunableEnvironment.f1[0] = objfun_tunableEnvironment_f1[0];
  obj->objfun.tunableEnvironment.f1[1] = objfun_tunableEnvironment_f1[1];
  obj->objfun.tunableEnvironment.f1[2] = objfun_tunableEnvironment_f1[2];
  obj->objfun.tunableEnvironment.f3[0] = objfun_tunableEnvironment_f3[0];
  obj->objfun.tunableEnvironment.f3[1] = objfun_tunableEnvironment_f3[1];
  obj->objfun.tunableEnvironment.f3[2] = objfun_tunableEnvironment_f3[2];
  obj->f_1 = 0.0;
  obj->f_2 = 0.0;
  obj->nVar = 7;
  obj->mIneq = 0;
  obj->mEq = 0;
  obj->numEvals = 0;
  obj->SpecifyObjectiveGradient = false;
  obj->SpecifyConstraintGradient = false;
  obj->FiniteDifferenceType = 0;
  for (i = 0; i < 7; i++) {
    obj->objfun.tunableEnvironment.f2[i] = objfun_tunableEnvironment_f2[i];
    bv[i] = obj->hasLB[i];
    bv1[i] = obj->hasUB[i];
  }

  b = false;
  i = 0;
  while ((!b) && (i + 1 <= 7)) {
    bv[i] = ((!muDoubleScalarIsInf(lb[i])) && (!muDoubleScalarIsNaN(lb[i])));
    bv1[i] = ((!muDoubleScalarIsInf(ub[i])) && (!muDoubleScalarIsNaN(ub[i])));
    if (bv[i] || bv1[i]) {
      b = true;
    }

    i++;
  }

  while (i + 1 <= 7) {
    bv[i] = ((!muDoubleScalarIsInf(lb[i])) && (!muDoubleScalarIsNaN(lb[i])));
    bv1[i] = ((!muDoubleScalarIsInf(ub[i])) && (!muDoubleScalarIsNaN(ub[i])));
    i++;
  }

  for (i = 0; i < 7; i++) {
    obj->hasLB[i] = bv[i];
    obj->hasUB[i] = bv1[i];
  }

  obj->hasBounds = b;
}

/* End of code generation (factoryConstruct.c) */
