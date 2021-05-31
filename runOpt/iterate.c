/*
 * iterate.c
 *
 * Code generation for function 'iterate'
 *
 */

/* Include files */
#include "iterate.h"
#include "addAineqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "blas.h"
#include "checkStoppingAndUpdateFval.h"
#include "checkUnboundedOrIllPosed.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "deleteColMoveEnd.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "feasibleratiotest.h"
#include "moveConstraint_.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "xcopy.h"
#include "xgemv.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xtrsv.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo jh_emlrtRSI = { 1,  /* lineNo */
  "iterate",                           /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\iterate.p"/* pathName */
};

static emlrtRSInfo mh_emlrtRSI = { 1,  /* lineNo */
  "squareQ_appendCol",                 /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\squareQ_appendCol.p"/* pathName */
};

static emlrtRSInfo nh_emlrtRSI = { 28, /* lineNo */
  "xrotg",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg.m"/* pathName */
};

static emlrtRSInfo oh_emlrtRSI = { 27, /* lineNo */
  "xrotg",                             /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg.m"/* pathName */
};

static emlrtRSInfo ji_emlrtRSI = { 1,  /* lineNo */
  "compute_lambda",                    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\compute_lambda.p"/* pathName */
};

static emlrtRSInfo ki_emlrtRSI = { 1,  /* lineNo */
  "find_neg_lambda",                   /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\find_neg_lambda.p"/* pathName */
};

static emlrtBCInfo qc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "isNonDegenerate",                   /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\isNonDegenerate.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "squareQ_appendCol",                 /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\squareQ_appendCol.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "iterate",                           /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\iterate.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "squareQ_appendCol",                 /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+QRManager\\squareQ_appendCol.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "find_neg_lambda",                   /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\find_neg_lambda.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { 1,  /* iFirst */
  153,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "compute_lambda",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\compute_lambda.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "compute_lambda",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\compute_lambda.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void iterate(const emlrtStack *sp, const real_T H[49], const real_T f[9],
             f_struct_T *solution, b_struct_T *memspace, e_struct_T *workingset,
             i_struct_T *qrmanager, k_struct_T *cholmanager, j_struct_T
             *objective, real_T options_StepTolerance, real_T
             options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations)
{
  boolean_T subProblemChanged;
  boolean_T updateFval;
  int32_T activeSetChangeID;
  int32_T TYPE;
  int32_T nVar;
  int32_T globalActiveConstrIdx;
  int32_T exitg1;
  boolean_T guard1 = false;
  int32_T idxMinLambda;
  int32_T iyend;
  int32_T iy;
  real_T c;
  real_T a;
  real_T dv[153];
  int32_T idx;
  int32_T ix;
  boolean_T guard2 = false;
  int32_T b;
  boolean_T exitg4;
  int32_T exitg3;
  int32_T ia;
  real_T b_b;
  real_T s;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective->objtype;
  nVar = workingset->nVar;
  globalActiveConstrIdx = 0;
  st.site = &jh_emlrtRSI;
  computeGrad_StoreHx(&st, objective, H, f, solution->xstar);
  st.site = &jh_emlrtRSI;
  solution->fstar = computeFval_ReuseHx(&st, objective,
    memspace->workspace_double, f, solution->xstar);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  st.site = &jh_emlrtRSI;
  c_xcopy(&st, 17, solution->lambda);
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
         case 1:
          idxMinLambda = 9 * (workingset->nActiveConstr - 1);
          st.site = &jh_emlrtRSI;
          iyend = qrmanager->ncols + 1;
          qrmanager->minRowCol = muIntScalarMin_sint32(qrmanager->mrows, iyend);
          iy = 17 * qrmanager->ncols;
          b_st.site = &mh_emlrtRSI;
          c_st.site = &bd_emlrtRSI;
          if (qrmanager->mrows != 0) {
            iyend = iy + qrmanager->mrows;
            d_st.site = &re_emlrtRSI;
            if ((iy + 1 <= iyend) && (iyend > 2147483646)) {
              e_st.site = &d_emlrtRSI;
              check_forloop_overflow_error(&e_st);
            }

            if (iy + 1 <= iyend) {
              memset(&qrmanager->QR[iy], 0, (iyend - iy) * sizeof(real_T));
            }

            iyend = 17 * (qrmanager->mrows - 1) + 1;
            d_st.site = &cd_emlrtRSI;
            if ((1 <= iyend) && (iyend > 2147483630)) {
              e_st.site = &d_emlrtRSI;
              check_forloop_overflow_error(&e_st);
            }

            for (idx = 1; idx <= iyend; idx += 17) {
              ix = idxMinLambda;
              c = 0.0;
              b = (idx + qrmanager->mrows) - 1;
              d_st.site = &dd_emlrtRSI;
              if ((idx <= b) && (b > 2147483646)) {
                e_st.site = &d_emlrtRSI;
                check_forloop_overflow_error(&e_st);
              }

              for (ia = idx; ia <= b; ia++) {
                c += qrmanager->Q[ia - 1] * workingset->ATwset[ix];
                ix++;
              }

              qrmanager->QR[iy] += c;
              iy++;
            }
          }

          qrmanager->ncols++;
          if ((qrmanager->ncols < 1) || (qrmanager->ncols > 17)) {
            emlrtDynamicBoundsCheckR2012b(qrmanager->ncols, 1, 17, &rc_emlrtBCI,
              &st);
          }

          qrmanager->jpvt[qrmanager->ncols - 1] = qrmanager->ncols;
          for (idx = qrmanager->mrows; idx > qrmanager->ncols; idx--) {
            b_st.site = &mh_emlrtRSI;
            iy = idx - 1;
            if ((iy < 1) || (iy > 17)) {
              emlrtDynamicBoundsCheckR2012b(iy, 1, 17, &tc_emlrtBCI, &b_st);
            }

            if ((qrmanager->ncols < 1) || (qrmanager->ncols > 17)) {
              emlrtDynamicBoundsCheckR2012b(qrmanager->ncols, 1, 17,
                &tc_emlrtBCI, &b_st);
            }

            iyend = 17 * (qrmanager->ncols - 1);
            a = qrmanager->QR[(iy + iyend) - 1];
            if ((idx < 1) || (idx > 17)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &tc_emlrtBCI, &b_st);
            }

            if ((qrmanager->ncols < 1) || (qrmanager->ncols > 17)) {
              emlrtDynamicBoundsCheckR2012b(qrmanager->ncols, 1, 17,
                &tc_emlrtBCI, &b_st);
            }

            b_b = qrmanager->QR[(idx + iyend) - 1];
            c_st.site = &oh_emlrtRSI;
            c_st.site = &nh_emlrtRSI;
            c = 0.0;
            s = 0.0;
            drotg(&a, &b_b, &c, &s);
            iy = idx - 1;
            if (iy < 1) {
              emlrtDynamicBoundsCheckR2012b(0, 1, 17, &rc_emlrtBCI, &b_st);
            }

            if ((qrmanager->ncols < 1) || (qrmanager->ncols > 17)) {
              emlrtDynamicBoundsCheckR2012b(qrmanager->ncols, 1, 17,
                &rc_emlrtBCI, &b_st);
            }

            qrmanager->QR[(iy + iyend) - 1] = a;
            if ((qrmanager->ncols < 1) || (qrmanager->ncols > 17)) {
              emlrtDynamicBoundsCheckR2012b(qrmanager->ncols, 1, 17,
                &rc_emlrtBCI, &b_st);
            }

            qrmanager->QR[(idx + 17 * (qrmanager->ncols - 1)) - 1] = b_b;
            iyend = 17 * (idx - 2) + 1;
            b_st.site = &mh_emlrtRSI;
            xrot(&b_st, qrmanager->mrows, qrmanager->Q, iyend, iyend + 17, c, s);
          }
          break;

         case -1:
          st.site = &jh_emlrtRSI;
          deleteColMoveEnd(&st, qrmanager, globalActiveConstrIdx);
          break;

         default:
          st.site = &jh_emlrtRSI;
          factorQR(&st, qrmanager, workingset->ATwset, nVar,
                   workingset->nActiveConstr);
          st.site = &jh_emlrtRSI;
          b_st.site = &cf_emlrtRSI;
          computeQ_(&b_st, qrmanager, qrmanager->mrows);
          break;
        }

        st.site = &jh_emlrtRSI;
        compute_deltax(&st, H, solution, memspace, qrmanager, cholmanager,
                       objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          st.site = &jh_emlrtRSI;
          c = xnrm2(&st, nVar, solution->searchDir);
          if ((c < options_StepTolerance) || (workingset->nActiveConstr >= nVar))
          {
            guard1 = true;
          } else {
            st.site = &jh_emlrtRSI;
            feasibleratiotest(&st, solution->xstar, solution->searchDir,
                              memspace->workspace_double, workingset->nVar,
                              workingset->Aineq, workingset->bineq,
                              workingset->lb, workingset->ub,
                              workingset->indexLB, workingset->indexUB,
                              workingset->sizes, workingset->isActiveIdx,
                              workingset->isActiveConstr, workingset->nWConstr,
                              TYPE == 5, &a, &updateFval, &iy, &iyend);
            if (updateFval) {
              switch (iy) {
               case 3:
                st.site = &jh_emlrtRSI;
                addAineqConstr(&st, workingset, iyend);
                break;

               case 4:
                st.site = &jh_emlrtRSI;
                b_st.site = &lf_emlrtRSI;
                addBoundToActiveSetMatrix_(&b_st, workingset, 4, iyend);
                break;

               default:
                st.site = &jh_emlrtRSI;
                b_st.site = &nf_emlrtRSI;
                addBoundToActiveSetMatrix_(&b_st, workingset, 5, iyend);
                break;
              }

              activeSetChangeID = 1;
            } else {
              st.site = &jh_emlrtRSI;
              checkUnboundedOrIllPosed(&st, solution, objective);
              subProblemChanged = false;
              if (workingset->nActiveConstr == 0) {
                solution->state = 1;
              }
            }

            if ((nVar >= 1) && (!(a == 0.0))) {
              iyend = nVar - 1;
              for (ix = 0; ix <= iyend; ix++) {
                solution->xstar[ix] += a * solution->searchDir[ix];
              }
            }

            st.site = &jh_emlrtRSI;
            computeGrad_StoreHx(&st, objective, H, f, solution->xstar);
            updateFval = true;
            st.site = &jh_emlrtRSI;
            checkStoppingAndUpdateFval(&st, &activeSetChangeID, f, solution,
              memspace, objective, workingset, qrmanager, options_ObjectiveLimit,
              runTimeOptions_MaxIterations, updateFval);
          }
        }
      } else {
        st.site = &jh_emlrtRSI;
        b_st.site = &fd_emlrtRSI;
        c_st.site = &gd_emlrtRSI;
        if ((1 <= nVar) && (nVar > 2147483646)) {
          d_st.site = &d_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        if (0 <= nVar - 1) {
          memset(&solution->searchDir[0], 0, nVar * sizeof(real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        st.site = &jh_emlrtRSI;
        memcpy(&dv[0], &memspace->workspace_double[0], 153U * sizeof(real_T));
        iyend = qrmanager->ncols;
        if (qrmanager->ncols > 0) {
          c = 100.0 * (real_T)qrmanager->mrows * 2.2204460492503131E-16;
          b_st.site = &ji_emlrtRSI;
          if ((qrmanager->mrows > 0) && (qrmanager->ncols > 0)) {
            updateFval = true;
          } else {
            updateFval = false;
          }

          if (updateFval) {
            idx = qrmanager->ncols;
            guard2 = false;
            if (qrmanager->mrows < qrmanager->ncols) {
              exitg4 = false;
              while ((!exitg4) && (idx > qrmanager->mrows)) {
                if ((qrmanager->mrows < 1) || (qrmanager->mrows > 17)) {
                  emlrtDynamicBoundsCheckR2012b(qrmanager->mrows, 1, 17,
                    &qc_emlrtBCI, &b_st);
                }

                if ((idx < 1) || (idx > 17)) {
                  emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &qc_emlrtBCI, &b_st);
                }

                if (muDoubleScalarAbs(qrmanager->QR[(qrmanager->mrows + 17 *
                      (idx - 1)) - 1]) >= c) {
                  idx--;
                } else {
                  exitg4 = true;
                }
              }

              updateFval = (idx == qrmanager->mrows);
              if (updateFval) {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }

            if (guard2) {
              do {
                exitg3 = 0;
                if (idx >= 1) {
                  if (idx > 17) {
                    emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &qc_emlrtBCI,
                      &b_st);
                  }

                  if (muDoubleScalarAbs(qrmanager->QR[(idx + 17 * (idx - 1)) - 1])
                      >= c) {
                    idx--;
                  } else {
                    updateFval = (idx == 0);
                    exitg3 = 1;
                  }
                } else {
                  updateFval = (idx == 0);
                  exitg3 = 1;
                }
              } while (exitg3 == 0);
            }
          }

          if (!updateFval) {
            solution->state = -7;
          } else {
            b_st.site = &ji_emlrtRSI;
            xgemv(&b_st, qrmanager->mrows, qrmanager->ncols, qrmanager->Q,
                  objective->grad, dv);
            b_st.site = &ji_emlrtRSI;
            xtrsv(qrmanager->ncols, qrmanager->QR, dv);
            b_st.site = &ji_emlrtRSI;
            if ((1 <= qrmanager->ncols) && (qrmanager->ncols > 2147483646)) {
              c_st.site = &d_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            for (idx = 0; idx < iyend; idx++) {
              ix = idx + 1;
              if ((ix < 1) || (ix > 153)) {
                emlrtDynamicBoundsCheckR2012b(ix, 1, 153, &vc_emlrtBCI, &st);
              }

              if (ix > 17) {
                emlrtDynamicBoundsCheckR2012b(ix, 1, 17, &wc_emlrtBCI, &st);
              }

              solution->lambda[ix - 1] = -dv[ix - 1];
            }
          }
        }

        memcpy(&memspace->workspace_double[0], &dv[0], 153U * sizeof(real_T));
        if (solution->state != -7) {
          st.site = &jh_emlrtRSI;
          idxMinLambda = -1;
          c = 0.0;
          iyend = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
          b = workingset->nActiveConstr;
          b_st.site = &ki_emlrtRSI;
          if ((iyend <= workingset->nActiveConstr) && (workingset->nActiveConstr
               > 2147483646)) {
            c_st.site = &d_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (idx = iyend; idx <= b; idx++) {
            if ((idx < 1) || (idx > 17)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, 17, &uc_emlrtBCI, &st);
            }

            a = solution->lambda[idx - 1];
            if (a < c) {
              c = a;
              idxMinLambda = idx - 1;
            }
          }

          if (idxMinLambda + 1 == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = idxMinLambda + 1;
            subProblemChanged = true;
            st.site = &jh_emlrtRSI;
            ix = workingset->Wid[idxMinLambda];
            if ((workingset->Wid[idxMinLambda] < 1) || (workingset->
                 Wid[idxMinLambda] > 6)) {
              emlrtDynamicBoundsCheckR2012b(workingset->Wid[idxMinLambda], 1, 6,
                &db_emlrtBCI, &st);
            }

            iy = (workingset->isActiveIdx[workingset->Wid[idxMinLambda] - 1] +
                  workingset->Wlocalidx[idxMinLambda]) - 1;
            if ((iy < 1) || (iy > 17)) {
              emlrtDynamicBoundsCheckR2012b(iy, 1, 17, &nb_emlrtBCI, &st);
            }

            workingset->isActiveConstr[iy - 1] = false;
            b_st.site = &xf_emlrtRSI;
            moveConstraint_(&b_st, workingset, workingset->nActiveConstr,
                            idxMinLambda + 1);
            workingset->nActiveConstr--;
            if ((ix < 1) || (ix > 5)) {
              emlrtDynamicBoundsCheckR2012b(ix, 1, 5, &pb_emlrtBCI, &st);
            }

            workingset->nWConstr[ix - 1]--;
            solution->lambda[idxMinLambda] = 0.0;
          }
        } else {
          idxMinLambda = workingset->nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset->nActiveConstr;
          subProblemChanged = true;
          if ((workingset->nActiveConstr < 1) || (workingset->nActiveConstr > 17))
          {
            emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1, 17,
              &sc_emlrtBCI, sp);
          }

          st.site = &jh_emlrtRSI;
          if ((workingset->nActiveConstr < 1) || (workingset->nActiveConstr > 17))
          {
            emlrtDynamicBoundsCheckR2012b(workingset->nActiveConstr, 1, 17,
              &lb_emlrtBCI, &st);
          }

          iyend = workingset->nActiveConstr - 1;
          ix = workingset->Wid[iyend];
          if ((workingset->Wid[iyend] < 1) || (workingset->Wid[iyend] > 6)) {
            emlrtDynamicBoundsCheckR2012b(workingset->Wid
              [workingset->nActiveConstr - 1], 1, 6, &db_emlrtBCI, &st);
          }

          iy = (workingset->isActiveIdx[workingset->Wid[iyend] - 1] +
                workingset->Wlocalidx[iyend]) - 1;
          if ((iy < 1) || (iy > 17)) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 17, &nb_emlrtBCI, &st);
          }

          workingset->isActiveConstr[iy - 1] = false;
          b_st.site = &xf_emlrtRSI;
          moveConstraint_(&b_st, workingset, workingset->nActiveConstr,
                          workingset->nActiveConstr);
          workingset->nActiveConstr--;
          if ((ix < 1) || (ix > 5)) {
            emlrtDynamicBoundsCheckR2012b(ix, 1, 5, &pb_emlrtBCI, &st);
          }

          workingset->nWConstr[ix - 1]--;
          solution->lambda[idxMinLambda - 1] = 0.0;
        }

        updateFval = false;
        st.site = &jh_emlrtRSI;
        checkStoppingAndUpdateFval(&st, &activeSetChangeID, f, solution,
          memspace, objective, workingset, qrmanager, options_ObjectiveLimit,
          runTimeOptions_MaxIterations, updateFval);
      }
    } else {
      if (!updateFval) {
        st.site = &jh_emlrtRSI;
        solution->fstar = computeFval_ReuseHx(&st, objective,
          memspace->workspace_double, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (iterate.c) */
