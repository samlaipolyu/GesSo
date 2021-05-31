/*
 * runOpt_initialize.c
 *
 * Code generation for function 'runOpt_initialize'
 *
 */

/* Include files */
#include "runOpt_initialize.h"
#include "_coder_runOpt_mex.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

/* Function Definitions */
void runOpt_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "optimization_toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (runOpt_initialize.c) */
