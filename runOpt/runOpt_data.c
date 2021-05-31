/*
 * runOpt_data.c
 *
 * Code generation for function 'runOpt_data'
 *
 */

/* Include files */
#include "runOpt_data.h"
#include "rt_nonfinite.h"
#include "runOpt.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131594U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "runOpt",                            /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2666790369U, 2630951428U, 3350295197U, 1643587045U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo d_emlrtRSI = { 21,         /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo e_emlrtRSI = { 45,         /* lineNo */
  "mpower",                            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m"/* pathName */
};

emlrtRSInfo f_emlrtRSI = { 70,         /* lineNo */
  "power",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

emlrtRSInfo g_emlrtRSI = { 79,         /* lineNo */
  "fltpower",                          /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

emlrtRSInfo h_emlrtRSI = { 41,         /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

emlrtRSInfo i_emlrtRSI = { 139,        /* lineNo */
  "scalar_float_power",                /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

emlrtRSInfo l_emlrtRSI = { 39,         /* lineNo */
  "function_handle/parenReference",    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\function_handle.m"/* pathName */
};

emlrtRSInfo m_emlrtRSI = { 3,          /* lineNo */
  "@(q)((norm(task-fwk(q)))^2 +  (1)*(norm(q(1:6)-q_prev(1:6)))^2  +...\n    norm(fwkeul_alpha(q(1:6)) - (set_angle(1,1)))^2 +...\n  "
  "  norm(fwkeul_gamma(q(1:6)) - (set_angle(1,3)))^2 +...\n    norm(fwkeul_beta(q(1:6))  - (set_angle(1,2)))^2)",/* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\matleap 4.0\\runOpt.m"/* pathName */
};

emlrtRSInfo n_emlrtRSI = { 4,          /* lineNo */
  "@(q)((norm(task-fwk(q)))^2 +  (1)*(norm(q(1:6)-q_prev(1:6)))^2  +...\n    norm(fwkeul_alpha(q(1:6)) - (set_angle(1,1)))^2 +...\n  "
  "  norm(fwkeul_gamma(q(1:6)) - (set_angle(1,3)))^2 +...\n    norm(fwkeul_beta(q(1:6))  - (set_angle(1,2)))^2)",/* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\matleap 4.0\\runOpt.m"/* pathName */
};

emlrtRSInfo o_emlrtRSI = { 5,          /* lineNo */
  "@(q)((norm(task-fwk(q)))^2 +  (1)*(norm(q(1:6)-q_prev(1:6)))^2  +...\n    norm(fwkeul_alpha(q(1:6)) - (set_angle(1,1)))^2 +...\n  "
  "  norm(fwkeul_gamma(q(1:6)) - (set_angle(1,3)))^2 +...\n    norm(fwkeul_beta(q(1:6))  - (set_angle(1,2)))^2)",/* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\matleap 4.0\\runOpt.m"/* pathName */
};

emlrtRSInfo p_emlrtRSI = { 6,          /* lineNo */
  "@(q)((norm(task-fwk(q)))^2 +  (1)*(norm(q(1:6)-q_prev(1:6)))^2  +...\n    norm(fwkeul_alpha(q(1:6)) - (set_angle(1,1)))^2 +...\n  "
  "  norm(fwkeul_gamma(q(1:6)) - (set_angle(1,3)))^2 +...\n    norm(fwkeul_beta(q(1:6))  - (set_angle(1,2)))^2)",/* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\matleap 4.0\\runOpt.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 29,        /* lineNo */
  "validateAngle",                     /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\shared\\siglib\\+sigdatatypes\\validateAngle.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 76,        /* lineNo */
  "validateattributes",                /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

emlrtRSInfo kb_emlrtRSI = { 66,        /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

emlrtRSInfo lb_emlrtRSI = { 202,       /* lineNo */
  "flatIter",                          /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 64,        /* lineNo */
  "xgemv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 71,        /* lineNo */
  "xgemv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 74,        /* lineNo */
  "xgemv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 38,        /* lineNo */
  "xcopy",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xcopy.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 69,        /* lineNo */
  "xcopy",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xcopy.m"/* pathName */
};

emlrtRSInfo od_emlrtRSI = { 58,        /* lineNo */
  "xgemv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

emlrtRSInfo pd_emlrtRSI = { 51,        /* lineNo */
  "xgemv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

emlrtRSInfo qd_emlrtRSI = { 23,        /* lineNo */
  "ixamax",                            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\ixamax.m"/* pathName */
};

emlrtRSInfo rd_emlrtRSI = { 24,        /* lineNo */
  "ixamax",                            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\ixamax.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 1,         /* lineNo */
  "factorQRE",                         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\factorQRE.p"/* pathName */
};

emlrtRSInfo ke_emlrtRSI = { 9,         /* lineNo */
  "int",                               /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\int.m"/* pathName */
};

emlrtRSInfo le_emlrtRSI = { 8,         /* lineNo */
  "majority",                          /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\majority.m"/* pathName */
};

emlrtRSInfo me_emlrtRSI = { 31,        /* lineNo */
  "infocheck",                         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pathName */
};

emlrtRSInfo pe_emlrtRSI = { 31,        /* lineNo */
  "xscal",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal.m"/* pathName */
};

emlrtRSInfo qe_emlrtRSI = { 18,        /* lineNo */
  "xscal",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xscal.m"/* pathName */
};

emlrtRSInfo re_emlrtRSI = { 37,        /* lineNo */
  "xgemv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

emlrtRSInfo we_emlrtRSI = { 38,        /* lineNo */
  "ceval_xorgqr",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xorgqr.m"/* pathName */
};

emlrtRSInfo xe_emlrtRSI = { 46,        /* lineNo */
  "ceval_xorgqr",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xorgqr.m"/* pathName */
};

emlrtRSInfo ye_emlrtRSI = { 51,        /* lineNo */
  "ceval_xorgqr",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xorgqr.m"/* pathName */
};

emlrtRSInfo cf_emlrtRSI = { 1,         /* lineNo */
  "computeSquareQ",                    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\computeSquareQ.p"/* pathName */
};

emlrtRSInfo ff_emlrtRSI = { 55,        /* lineNo */
  "xtrsv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsv.m"/* pathName */
};

emlrtRSInfo jf_emlrtRSI = { 1,         /* lineNo */
  "saveState",                         /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+TrialState\\saveState.p"/* pathName */
};

emlrtRSInfo lf_emlrtRSI = { 1,         /* lineNo */
  "addLBConstr",                       /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\addLBConstr.p"/* pathName */
};

emlrtRSInfo nf_emlrtRSI = { 1,         /* lineNo */
  "addUBConstr",                       /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\addUBConstr.p"/* pathName */
};

emlrtRSInfo rf_emlrtRSI = { 35,        /* lineNo */
  "xdot",                              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdot.m"/* pathName */
};

emlrtRSInfo sf_emlrtRSI = { 15,        /* lineNo */
  "xdot",                              /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdot.m"/* pathName */
};

emlrtRSInfo tf_emlrtRSI = { 42,        /* lineNo */
  "xdotx",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdotx.m"/* pathName */
};

emlrtRSInfo xf_emlrtRSI = { 1,         /* lineNo */
  "removeConstr",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeConstr.p"/* pathName */
};

emlrtRSInfo bg_emlrtRSI = { 1,         /* lineNo */
  "factorQR",                          /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\factorQR.p"/* pathName */
};

emlrtRSInfo lg_emlrtRSI = { 88,        /* lineNo */
  "xgemm",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

emlrtRSInfo mg_emlrtRSI = { 86,        /* lineNo */
  "xgemm",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

emlrtRSInfo og_emlrtRSI = { 77,        /* lineNo */
  "xtrsm",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

emlrtRSInfo pg_emlrtRSI = { 76,        /* lineNo */
  "xtrsm",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

emlrtRSInfo bh_emlrtRSI = { 41,        /* lineNo */
  "xgemv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

emlrtRSInfo ih_emlrtRSI = { 1,         /* lineNo */
  "linearFormReg_",                    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+Objective\\linearFormReg_.p"/* pathName */
};

emlrtRSInfo th_emlrtRSI = { 1,         /* lineNo */
  "factor",                            /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+CholManager\\factor.p"/* pathName */
};

emlrtRSInfo vh_emlrtRSI = { 73,        /* lineNo */
  "ceval_xpotrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xpotrf.m"/* pathName */
};

emlrtRSInfo wh_emlrtRSI = { 70,        /* lineNo */
  "ceval_xpotrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xpotrf.m"/* pathName */
};

emlrtRSInfo xh_emlrtRSI = { 37,        /* lineNo */
  "ceval_xpotrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xpotrf.m"/* pathName */
};

emlrtRSInfo yh_emlrtRSI = { 36,        /* lineNo */
  "ceval_xpotrf",                      /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xpotrf.m"/* pathName */
};

emlrtRSInfo bi_emlrtRSI = { 1,         /* lineNo */
  "solve",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+CholManager\\solve.p"/* pathName */
};

emlrtRSInfo ci_emlrtRSI = { 65,        /* lineNo */
  "xtrsv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsv.m"/* pathName */
};

emlrtRSInfo di_emlrtRSI = { 72,        /* lineNo */
  "xtrsv",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsv.m"/* pathName */
};

emlrtRTEInfo d_emlrtRTEI = { 14,       /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

emlrtRTEInfo e_emlrtRTEI = { 14,       /* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

emlrtRTEInfo g_emlrtRTEI = { 13,       /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

emlrtRTEInfo j_emlrtRTEI = { 48,       /* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

emlrtRTEInfo k_emlrtRTEI = { 45,       /* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

emlrtBCInfo ab_emlrtBCI = { 1,         /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "addConstrUpdateRecords_",           /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\addConstrUpdateRecords_.p",/* pName */
  3                                    /* checkKind */
};

emlrtBCInfo db_emlrtBCI = { 1,         /* iFirst */
  6,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeConstr",                      /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeConstr.p",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo lb_emlrtBCI = { 1,         /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeConstr",                      /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeConstr.p",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo nb_emlrtBCI = { 1,         /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeConstr",                      /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeConstr.p",/* pName */
  3                                    /* checkKind */
};

emlrtBCInfo pb_emlrtBCI = { 1,         /* iFirst */
  5,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "removeConstr",                      /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\removeConstr.p",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo xb_emlrtBCI = { 1,         /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "isActive",                          /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\isActive.p",/* pName */
  0                                    /* checkKind */
};

emlrtRTEInfo l_emlrtRTEI = { 19,       /* lineNo */
  19,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

/* End of code generation (runOpt_data.c) */
