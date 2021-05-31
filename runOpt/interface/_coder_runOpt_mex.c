/*
 * _coder_runOpt_mex.c
 *
 * Code generation for function '_coder_runOpt_mex'
 *
 */

/* Include files */
#include "_coder_runOpt_mex.h"
#include "_coder_runOpt_api.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "runOpt_initialize.h"
#include "runOpt_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void runOpt_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[8]);

/* Function Definitions */
void runOpt_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const
  mxArray *prhs[8])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4, 6,
                        "runOpt");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 6,
                        "runOpt");
  }

  /* Call the function. */
  runOpt_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&runOpt_atexit);

  /* Module initialization. */
  runOpt_initialize();

  /* Dispatch the entry-point. */
  runOpt_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  runOpt_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_runOpt_mex.c) */
