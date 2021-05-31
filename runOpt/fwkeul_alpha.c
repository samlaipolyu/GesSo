/*
 * fwkeul_alpha.c
 *
 * Code generation for function 'fwkeul_alpha'
 *
 */

/* Include files */
#include "fwkeul_alpha.h"
#include "mwmathutil.h"
#include "rotm2eul.h"
#include "roty.h"
#include "rotz.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo ob_emlrtRSI = { 18, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 19, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 20, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 25, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 27, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 30, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 41, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 42, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 49, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 51, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 56, /* lineNo */
  "fwkeul_alpha",                      /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwkeul_alpha.m"/* pathName */
};

/* Function Definitions */
real_T fwkeul_alpha(const emlrtStack *sp, const real_T x[6])
{
  real_T b_x;
  real_T Phi_1;
  real_T theta_2;
  real_T phi_2;
  real_T phi_1;
  real_T A;
  real_T a_tmp;
  real_T br_tmp;
  real_T A_im;
  real_T R_02[9];
  real_T b[9];
  real_T b_b[9];
  real_T a[9];
  real_T c_b[9];
  real_T d_b[9];
  int32_T i;
  real_T unusedExpr[3];
  int32_T i1;
  real_T b_a[9];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;

  /*  mm */
  /*  K_A = EA/L = 0.8*pi*(4.5^2-1.8^2)/50 = 0.8550 N/mm */
  /*  I = (pi/4)*(4.5^4-1.8^4); % 313.8175 mm^4 */
  /*  0.8*313.8175/50 (EI/l=-M/theta_B) Nmmrad-1 // */
  st.site = &ob_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &ob_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &ob_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &ob_emlrtRSI;
  b_x = ((((x[3] * x[3] + x[4] * x[4]) + x[5] * x[5]) - x[3] * x[4]) - x[3] * x
         [5]) - x[4] * x[5];
  if (b_x < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  b_x = muDoubleScalarSqrt(b_x);
  Phi_1 = ((x[3] + x[4]) + x[5]) / 2.565;
  theta_2 = 3.15 * (Phi_1 + 50.0) / 5.0211 * b_x;
  st.site = &pb_emlrtRSI;
  phi_2 = muDoubleScalarAtan2(3.0 * (x[4] - x[5]), 1.7320508075688772 * ((x[4] +
    x[5]) - 2.0 * x[3]));
  st.site = &qb_emlrtRSI;
  phi_1 = muDoubleScalarAtan2(3.0 * (x[1] - x[2]), 1.7320508075688772 * ((x[1] +
    x[2]) - 2.0 * x[0]));

  /*  + deg2rad(60); */
  /* theta_1 = eta*(r*s_1(end)/K_B)*sqrt(x(1)^2+x(2)^2+x(3)^2-x(1)*x(2)-x(1)*x(3)-x(2)*x(3)); */
  st.site = &rb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &rb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &rb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &rb_emlrtRSI;
  b_x = ((((x[0] * x[0] + x[1] * x[1]) + x[2] * x[2]) - x[0] * x[1]) - x[0] * x
         [2]) - x[1] * x[2];
  if (b_x < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  b_x = muDoubleScalarSqrt(b_x);
  A = ((((x[0] + x[1]) + x[2]) + Phi_1) + 50.0) * 3.15 * b_x;
  st.site = &sb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &sb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &sb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &sb_emlrtRSI;
  a_tmp = (A * A - 2.0 * muDoubleScalarCos(phi_1 - phi_2) * A * 5.0211 * theta_2)
    + 25.211445209999997 * (theta_2 * theta_2);
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  d_st.site = &g_emlrtRSI;
  e_st.site = &h_emlrtRSI;
  f_st.site = &i_emlrtRSI;
  if (a_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&f_st, &g_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  /*      Phi_1 = atan2((cos(real(acos((A*cos(phi_1) - K_B*theta_2*cos(phi_2))/(A^2 - 2*cos(phi_1 - phi_2)*A*K_B*theta_2 + K_B^2*theta_2^2)^(1/2))))),... */
  /*                     sin(real(asin((A*sin(phi_1) - K_B*theta_2*sin(phi_2))/(A^2 - 2*cos(phi_1 - phi_2)*A*K_B*theta_2 + K_B^2*theta_2^2)^(1/2))))); */
  st.site = &tb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &tb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &tb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &tb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &tb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  d_st.site = &g_emlrtRSI;
  e_st.site = &h_emlrtRSI;
  st.site = &tb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &tb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &tb_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  d_st.site = &g_emlrtRSI;
  e_st.site = &h_emlrtRSI;
  Phi_1 = A * muDoubleScalarCos(phi_1) - 5.0211 * theta_2 * muDoubleScalarCos
    (phi_2);
  b_x = Phi_1 * 0.0;
  br_tmp = muDoubleScalarSqrt(a_tmp);
  if (Phi_1 == 0.0) {
    b_x /= br_tmp;
    A_im = 0.0;
  } else if (b_x == 0.0) {
    b_x = 0.0;
    A_im = Phi_1 / br_tmp;
  } else {
    b_x = rtNaN;
    A_im = Phi_1 / br_tmp;
  }

  b_x += (A * muDoubleScalarSin(phi_1) - 5.0211 * theta_2 * muDoubleScalarSin
          (phi_2)) / br_tmp;
  Phi_1 = 3.1415926535897931 - muDoubleScalarAtan2(A_im, b_x);

  /*  geometry pre-process */
  st.site = &ub_emlrtRSI;
  rotz(&st, 57.295779513082323 * Phi_1, R_02);
  st.site = &vb_emlrtRSI;
  rotz(&st, 57.295779513082323 * Phi_1, R_02);
  st.site = &vb_emlrtRSI;
  roty(&st, 57.295779513082323 * (muDoubleScalarSqrt(a_tmp) / 5.0211), b);
  st.site = &vb_emlrtRSI;
  rotz(&st, 57.295779513082323 * -(3.1415926535897931 - muDoubleScalarAtan2(A_im,
         b_x)), b_b);
  st.site = &wb_emlrtRSI;
  rotz(&st, 57.295779513082323 * phi_2, a);
  st.site = &wb_emlrtRSI;
  roty(&st, 57.295779513082323 * theta_2, c_b);
  st.site = &wb_emlrtRSI;
  rotz(&st, 57.295779513082323 * -phi_2, d_b);
  for (i = 0; i < 3; i++) {
    b_x = R_02[i + 3];
    Phi_1 = R_02[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_a[i + 3 * i1] = (R_02[i] * b[3 * i1] + b_x * b[3 * i1 + 1]) + Phi_1 * b
        [3 * i1 + 2];
    }

    b_x = a[i + 3];
    Phi_1 = a[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      R_02[i + 3 * i1] = (a[i] * c_b[3 * i1] + b_x * c_b[3 * i1 + 1]) + Phi_1 *
        c_b[3 * i1 + 2];
    }

    b_x = b_a[i + 3];
    Phi_1 = b_a[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      a[i + 3 * i1] = (b_a[i] * b_b[3 * i1] + b_x * b_b[3 * i1 + 1]) + Phi_1 *
        b_b[3 * i1 + 2];
    }

    b_x = R_02[i + 3];
    Phi_1 = R_02[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_a[i + 3 * i1] = (R_02[i] * d_b[3 * i1] + b_x * d_b[3 * i1 + 1]) + Phi_1 *
        d_b[3 * i1 + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    b_x = a[i + 3];
    Phi_1 = a[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      R_02[i + 3 * i1] = (a[i] * b_a[3 * i1] + b_x * b_a[3 * i1 + 1]) + Phi_1 *
        b_a[3 * i1 + 2];
    }
  }

  st.site = &xb_emlrtRSI;
  rotm2eul(&st, R_02, unusedExpr);
  st.site = &yb_emlrtRSI;
  rotm2eul(&st, R_02, unusedExpr);
  return unusedExpr[0];
}

/* End of code generation (fwkeul_alpha.c) */
