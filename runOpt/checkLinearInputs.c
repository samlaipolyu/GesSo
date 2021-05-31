/*
 * checkLinearInputs.c
 *
 * Code generation for function 'checkLinearInputs'
 *
 */

/* Include files */
#include "checkLinearInputs.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  1,                                   /* colNo */
  "checkLinearInputs",                 /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+validate\\checkLinearInputs.p"/* pName */
};

/* Function Definitions */
void checkLinearInputs(const emlrtStack *sp, const real_T x0[7], const real_T
  Aineq[7], real_T bineq, const real_T lb[7], const real_T ub[7])
{
  int32_T i;
  boolean_T y;
  boolean_T b[7];
  boolean_T b_b[7];
  boolean_T exitg1;
  boolean_T guard1 = false;
  for (i = 0; i < 7; i++) {
    b[i] = muDoubleScalarIsInf(Aineq[i]);
    b_b[i] = muDoubleScalarIsNaN(Aineq[i]);
  }

  y = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 7)) {
    if (b[i] || b_b[i]) {
      y = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (!y) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
      "optim_codegen:common:InfNaNComplexDetected",
      "optim_codegen:common:InfNaNComplexDetected", 3, 4, 1, "A");
  }

  if (muDoubleScalarIsInf(bineq) || muDoubleScalarIsNaN(bineq)) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
      "optim_codegen:common:InfNaNComplexDetected",
      "optim_codegen:common:InfNaNComplexDetected", 3, 4, 1, "B");
  }

  for (i = 0; i < 7; i++) {
    b[i] = muDoubleScalarIsNaN(lb[i]);
  }

  y = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 7)) {
    if (b[i]) {
      y = true;
      exitg1 = true;
    } else {
      i++;
    }
  }

  guard1 = false;
  if (y) {
    guard1 = true;
  } else {
    y = false;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 7)) {
      if (lb[i] == rtInf) {
        y = true;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (y) {
      guard1 = true;
    }
  }

  if (guard1) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
      "optim_codegen:common:InfNaNComplexDetectedLB",
      "optim_codegen:common:InfNaNComplexDetectedLB", 0);
  }

  for (i = 0; i < 7; i++) {
    b[i] = muDoubleScalarIsNaN(ub[i]);
  }

  y = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 7)) {
    if (b[i]) {
      y = true;
      exitg1 = true;
    } else {
      i++;
    }
  }

  guard1 = false;
  if (y) {
    guard1 = true;
  } else {
    y = false;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 7)) {
      if (ub[i] == rtMinusInf) {
        y = true;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (y) {
      guard1 = true;
    }
  }

  if (guard1) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
      "optim_codegen:common:InfNaNComplexDetectedUB",
      "optim_codegen:common:InfNaNComplexDetectedUB", 0);
  }

  for (i = 0; i < 7; i++) {
    b[i] = muDoubleScalarIsInf(x0[i]);
    b_b[i] = muDoubleScalarIsNaN(x0[i]);
  }

  y = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 7)) {
    if (b[i] || b_b[i]) {
      y = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (!y) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
      "optim_codegen:common:InfNaNComplexDetected",
      "optim_codegen:common:InfNaNComplexDetected", 3, 4, 2, "X0");
  }
}

/* End of code generation (checkLinearInputs.c) */
