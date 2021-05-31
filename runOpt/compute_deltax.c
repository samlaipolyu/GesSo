/*
 * compute_deltax.c
 *
 * Code generation for function 'compute_deltax'
 *
 */

/* Include files */
#include "compute_deltax.h"
#include "eml_int_forloop_overflow_check.h"
#include "factor.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"
#include "solve.h"
#include "xgemm.h"
#include "xgemv.h"
#include "xpotrf.h"
#include "xtrsv.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo sh_emlrtRSI = { 1,  /* lineNo */
  "compute_deltax",                    /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\compute_deltax.p"/* pathName */
};

static emlrtRSInfo ei_emlrtRSI = { 1,  /* lineNo */
  "computeProjectedHessian",           /* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\computeProjectedHessian.p"/* pathName */
};

static emlrtRSInfo ii_emlrtRSI = { 1,  /* lineNo */
  "computeProjectedHessian_regularized",/* fcnName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\computeProjectedHessian_regularized.p"/* pathName */
};

static emlrtBCInfo ed_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "compute_deltax",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\compute_deltax.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "compute_deltax",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\compute_deltax.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "compute_deltax",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\compute_deltax.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { 1,  /* iFirst */
  153,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "compute_deltax",                    /* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\compute_deltax.p",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { 1,  /* iFirst */
  17,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeProjectedHessian_regularized",/* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\computeProjectedHessian_regularized.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { 1,  /* iFirst */
  9,                                   /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeProjectedHessian_regularized",/* fName */
  "D:\\MATLAB R2020a\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+step\\+relaxed\\computeProjectedHessian_regularized.p",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void compute_deltax(const emlrtStack *sp, const real_T H[49], f_struct_T
                    *solution, b_struct_T *memspace, const i_struct_T *qrmanager,
                    k_struct_T *cholmanager, const j_struct_T *objective)
{
  int32_T nVar;
  int32_T mNull_tmp;
  int32_T idx;
  int32_T jA;
  int32_T b;
  int32_T nullStartIdx_tmp;
  int32_T nVars;
  real_T c;
  int32_T idx_col;
  int32_T idx_row;
  real_T dv[153];
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
  nVar = qrmanager->mrows - 1;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (mNull_tmp <= 0) {
    st.site = &sh_emlrtRSI;
    if ((1 <= qrmanager->mrows) && (qrmanager->mrows > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx <= nVar; idx++) {
      b = idx + 1;
      if ((b < 1) || (b > 9)) {
        emlrtDynamicBoundsCheckR2012b(b, 1, 9, &ed_emlrtBCI, sp);
      }

      solution->searchDir[b - 1] = 0.0;
    }
  } else {
    st.site = &sh_emlrtRSI;
    if ((1 <= qrmanager->mrows) && (qrmanager->mrows > 2147483646)) {
      b_st.site = &d_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (idx = 0; idx <= nVar; idx++) {
      jA = idx + 1;
      if ((jA < 1) || (jA > 9)) {
        emlrtDynamicBoundsCheckR2012b(jA, 1, 9, &fd_emlrtBCI, sp);
      }

      solution->searchDir[jA - 1] = -objective->grad[jA - 1];
    }

    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
       case 5:
        break;

       case 3:
        st.site = &sh_emlrtRSI;
        factor(&st, cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          st.site = &sh_emlrtRSI;
          solve(&st, cholmanager, solution->searchDir);
        }
        break;

       case 4:
        st.site = &sh_emlrtRSI;
        factor(&st, cholmanager, H, objective->nvar, objective->nvar);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          st.site = &sh_emlrtRSI;
          solve(&st, cholmanager, solution->searchDir);
          st.site = &sh_emlrtRSI;
          c = 1.0 / objective->beta;
          jA = objective->nvar + 1;
          b_st.site = &pe_emlrtRSI;
          b = qrmanager->mrows;
          c_st.site = &qe_emlrtRSI;
          if ((jA <= b) && (b > 2147483646)) {
            d_st.site = &d_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          for (nVars = jA; nVars <= b; nVars++) {
            solution->searchDir[nVars - 1] *= c;
          }
        }
        break;
      }
    } else {
      nullStartIdx_tmp = 17 * qrmanager->ncols + 1;
      switch (objective->objtype) {
       case 5:
        st.site = &sh_emlrtRSI;
        if (mNull_tmp > 2147483646) {
          b_st.site = &d_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (idx = 0; idx < mNull_tmp; idx++) {
          b = nVar + 1;
          if ((b < 1) || (b > 17)) {
            emlrtDynamicBoundsCheckR2012b(b, 1, 17, &gd_emlrtBCI, sp);
          }

          jA = (qrmanager->ncols + idx) + 1;
          if ((jA < 1) || (jA > 17)) {
            emlrtDynamicBoundsCheckR2012b(jA, 1, 17, &gd_emlrtBCI, sp);
          }

          nVars = idx + 1;
          if (nVars > 153) {
            emlrtDynamicBoundsCheckR2012b(nVars, 1, 153, &hd_emlrtBCI, sp);
          }

          memspace->workspace_double[nVars - 1] = -qrmanager->Q[(b + 17 * (jA -
            1)) - 1];
        }

        st.site = &sh_emlrtRSI;
        c_xgemv(&st, qrmanager->mrows, mNull_tmp, qrmanager->Q, nullStartIdx_tmp,
                memspace->workspace_double, solution->searchDir);
        break;

       default:
        switch (objective->objtype) {
         case 3:
          st.site = &sh_emlrtRSI;
          b_st.site = &ei_emlrtRSI;
          c_xgemm(&b_st, qrmanager->mrows, mNull_tmp, qrmanager->mrows, H,
                  qrmanager->mrows, qrmanager->Q, nullStartIdx_tmp,
                  memspace->workspace_double);
          b_st.site = &ei_emlrtRSI;
          d_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_double,
                  cholmanager->FMat);
          break;

         default:
          jA = objective->nvar + 1;
          st.site = &sh_emlrtRSI;
          nVars = qrmanager->mrows;
          b_st.site = &ii_emlrtRSI;
          c_xgemm(&b_st, objective->nvar, mNull_tmp, objective->nvar, H,
                  objective->nvar, qrmanager->Q, nullStartIdx_tmp,
                  memspace->workspace_double);
          b_st.site = &ii_emlrtRSI;
          if (mNull_tmp > 2147483646) {
            c_st.site = &d_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (idx_col = 0; idx_col < mNull_tmp; idx_col++) {
            idx = idx_col + 1;
            b_st.site = &ii_emlrtRSI;
            if ((jA <= nVars) && (nVars > 2147483646)) {
              c_st.site = &d_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            for (idx_row = jA; idx_row <= nVars; idx_row++) {
              if ((idx_row < 1) || (idx_row > 17)) {
                emlrtDynamicBoundsCheckR2012b(idx_row, 1, 17, &id_emlrtBCI, &st);
              }

              b = idx + qrmanager->ncols;
              if ((b < 1) || (b > 17)) {
                emlrtDynamicBoundsCheckR2012b(b, 1, 17, &id_emlrtBCI, &st);
              }

              if (idx > 9) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, 9, &jd_emlrtBCI, &st);
              }

              memspace->workspace_double[(idx_row + 17 * (idx - 1)) - 1] =
                objective->beta * qrmanager->Q[(idx_row + 17 * (b - 1)) - 1];
            }
          }

          b_st.site = &ii_emlrtRSI;
          d_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_double,
                  cholmanager->FMat);
          break;
        }

        st.site = &sh_emlrtRSI;
        cholmanager->ndims = mNull_tmp;
        b_st.site = &th_emlrtRSI;
        cholmanager->info = xpotrf(&b_st, mNull_tmp, cholmanager->FMat);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          st.site = &sh_emlrtRSI;
          b_st.site = &bd_emlrtRSI;
          if (qrmanager->mrows != 0) {
            c_st.site = &re_emlrtRSI;
            if (mNull_tmp > 2147483646) {
              d_st.site = &d_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }

            if (0 <= mNull_tmp - 1) {
              memset(&memspace->workspace_double[0], 0, mNull_tmp * sizeof
                     (real_T));
            }

            jA = 0;
            b = nullStartIdx_tmp + 17 * (mNull_tmp - 1);
            c_st.site = &cd_emlrtRSI;
            if ((nullStartIdx_tmp <= b) && (b > 2147483630)) {
              d_st.site = &d_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }

            for (idx_col = nullStartIdx_tmp; idx_col <= b; idx_col += 17) {
              nVars = 0;
              c = 0.0;
              idx = idx_col + nVar;
              c_st.site = &dd_emlrtRSI;
              if ((idx_col <= idx) && (idx > 2147483646)) {
                d_st.site = &d_emlrtRSI;
                check_forloop_overflow_error(&d_st);
              }

              for (idx_row = idx_col; idx_row <= idx; idx_row++) {
                c += qrmanager->Q[idx_row - 1] * objective->grad[nVars];
                nVars++;
              }

              memspace->workspace_double[jA] += -c;
              jA++;
            }
          }

          st.site = &sh_emlrtRSI;
          memcpy(&dv[0], &memspace->workspace_double[0], 153U * sizeof(real_T));
          b_st.site = &bi_emlrtRSI;
          c_st.site = &ff_emlrtRSI;
          d_st.site = &ci_emlrtRSI;
          if (mNull_tmp > 2147483646) {
            e_st.site = &d_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }

          for (nVars = 0; nVars < mNull_tmp; nVars++) {
            jA = nVars * 17;
            c = dv[nVars];
            d_st.site = &di_emlrtRSI;
            for (idx = 0; idx < nVars; idx++) {
              c -= cholmanager->FMat[jA + idx] * dv[idx];
            }

            dv[nVars] = c / cholmanager->FMat[jA + nVars];
          }

          memcpy(&memspace->workspace_double[0], &dv[0], 153U * sizeof(real_T));
          b_st.site = &bi_emlrtRSI;
          xtrsv(mNull_tmp, cholmanager->FMat, memspace->workspace_double);
          st.site = &sh_emlrtRSI;
          c_xgemv(&st, qrmanager->mrows, mNull_tmp, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_double,
                  solution->searchDir);
        }
        break;
      }
    }
  }
}

/* End of code generation (compute_deltax.c) */
