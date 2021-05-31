/*
 * fwk.c
 *
 * Code generation for function 'fwk'
 *
 */

/* Include files */
#include "fwk.h"
#include "mwmathutil.h"
#include "rotm2eul.h"
#include "roty.h"
#include "rotz.h"
#include "rt_nonfinite.h"
#include "runOpt.h"
#include "runOpt_data.h"

/* Variable Definitions */
static emlrtRSInfo q_emlrtRSI = { 16,  /* lineNo */
  "fwk",                               /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwk.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 17,  /* lineNo */
  "fwk",                               /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwk.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 18,  /* lineNo */
  "fwk",                               /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwk.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 22,  /* lineNo */
  "fwk",                               /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwk.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 24,  /* lineNo */
  "fwk",                               /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwk.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 27,  /* lineNo */
  "fwk",                               /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwk.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 39,  /* lineNo */
  "fwk",                               /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwk.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 46,  /* lineNo */
  "fwk",                               /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwk.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 48,  /* lineNo */
  "fwk",                               /* fcnName */
  "D:\\OneDrive - PolyU\\OneDrive - The Hong Kong Polytechnic University\\1112_code\\fwk.m"/* pathName */
};

static emlrtRTEInfo c_emlrtRTEI = { 82,/* lineNo */
  5,                                   /* colNo */
  "fltpower",                          /* fName */
  "D:\\MATLAB R2020a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

/* Function Definitions */
void fwk(const emlrtStack *sp, const real_T x[7], real_T p_02[3])
{
  real_T ds_2_tmp;
  real_T ds_1;
  int32_T i;
  real_T s_2[50];
  real_T s_1[50];
  real_T theta_2;
  real_T phi_2;
  real_T phi_1;
  real_T A;
  real_T a_tmp;
  real_T Theta_1;
  real_T Phi_1_tmp;
  real_T ar_tmp;
  real_T a[9];
  real_T b[9];
  real_T b_b[9];
  int32_T i1;
  real_T b_a[9];
  real_T unusedExpr[3];
  real_T R_01[9];
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
  ds_2_tmp = ((x[3] + x[4]) + x[5]) / 2.565;
  ds_1 = ((x[0] + x[1]) + x[2]) + ds_2_tmp;
  for (i = 0; i < 50; i++) {
    s_2[i] = ((real_T)i + 1.0) + ds_2_tmp;
    s_1[i] = ((real_T)i + 1.0) + ds_1;
  }

  st.site = &q_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &q_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &q_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  ds_1 = ((((x[3] * x[3] + x[4] * x[4]) + x[5] * x[5]) - x[3] * x[4]) - x[3] *
          x[5]) - x[4] * x[5];
  st.site = &q_emlrtRSI;
  if (ds_1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  ds_1 = muDoubleScalarSqrt(ds_1);
  theta_2 = 3.15 * s_2[49] / 5.0211 * ds_1;
  st.site = &r_emlrtRSI;
  phi_2 = muDoubleScalarAtan2(3.0 * (x[4] - x[5]), 1.7320508075688772 * ((x[4] +
    x[5]) - 2.0 * x[3]));
  st.site = &s_emlrtRSI;
  phi_1 = muDoubleScalarAtan2(3.0 * (x[1] - x[2]), 1.7320508075688772 * ((x[1] +
    x[2]) - 2.0 * x[0]));

  /*  + deg2rad(60); */
  /* theta_1 = eta*(r*s_1(end)/K_B)*sqrt(x(1)^2+x(2)^2+x(3)^2-x(1)*x(2)-x(1)*x(3)-x(2)*x(3)); */
  st.site = &t_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &t_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &t_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  ds_1 = ((((x[0] * x[0] + x[1] * x[1]) + x[2] * x[2]) - x[0] * x[1]) - x[0] *
          x[2]) - x[1] * x[2];
  st.site = &t_emlrtRSI;
  if (ds_1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  ds_1 = muDoubleScalarSqrt(ds_1);
  A = s_1[49] * 3.15 * ds_1;
  st.site = &u_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &u_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &u_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &u_emlrtRSI;
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

  if (a_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  Theta_1 = muDoubleScalarSqrt(a_tmp) / 5.0211;

  /*      Phi_1 = atan2((cos(real(acos((A*cos(phi_1) - K_B*theta_2*cos(phi_2))/(A^2 - 2*cos(phi_1 - phi_2)*A*K_B*theta_2 + K_B^2*theta_2^2)^(1/2))))),... */
  /*                     sin(real(asin((A*sin(phi_1) - K_B*theta_2*sin(phi_2))/(A^2 - 2*cos(phi_1 - phi_2)*A*K_B*theta_2 + K_B^2*theta_2^2)^(1/2))))); */
  st.site = &v_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  Phi_1_tmp = muDoubleScalarCos(phi_2);
  st.site = &v_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &v_emlrtRSI;
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

  ds_1 = muDoubleScalarSqrt(a_tmp);
  st.site = &v_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &v_emlrtRSI;
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

  ar_tmp = A * muDoubleScalarCos(phi_1) - 5.0211 * theta_2 * Phi_1_tmp;
  ds_2_tmp = ar_tmp * 0.0;
  if (ar_tmp == 0.0) {
    ds_2_tmp /= ds_1;
    ds_1 = 0.0;
  } else if (ds_2_tmp == 0.0) {
    ds_2_tmp = 0.0;
    ds_1 = ar_tmp / ds_1;
  } else {
    ds_2_tmp = rtNaN;
    ds_1 = ar_tmp / ds_1;
  }

  ar_tmp = muDoubleScalarSin(phi_2);
  ds_2_tmp += (A * muDoubleScalarSin(phi_1) - 5.0211 * theta_2 * ar_tmp) /
    muDoubleScalarSqrt(a_tmp);
  phi_1 = 3.1415926535897931 - muDoubleScalarAtan2(ds_1, ds_2_tmp);

  /*  geometry pre-process */
  /*  R_0b = rotz(rad2deg(phi_1-phi_1)); */
  st.site = &w_emlrtRSI;
  rotz(&st, 57.295779513082323 * phi_1, a);
  st.site = &w_emlrtRSI;
  roty(&st, 57.295779513082323 * Theta_1, b);
  st.site = &w_emlrtRSI;
  rotz(&st, 57.295779513082323 * -(3.1415926535897931 - muDoubleScalarAtan2(ds_1,
         ds_2_tmp)), b_b);
  for (i = 0; i < 3; i++) {
    ds_1 = a[i + 3];
    ds_2_tmp = a[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_a[i + 3 * i1] = (a[i] * b[3 * i1] + ds_1 * b[3 * i1 + 1]) + ds_2_tmp *
        b[3 * i1 + 2];
    }

    ds_1 = b_a[i + 3];
    ds_2_tmp = b_a[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      R_01[i + 3 * i1] = (b_a[i] * b_b[3 * i1] + ds_1 * b_b[3 * i1 + 1]) +
        ds_2_tmp * b_b[3 * i1 + 2];
    }
  }

  st.site = &x_emlrtRSI;
  rotz(&st, 57.295779513082323 * phi_2, a);
  st.site = &x_emlrtRSI;
  roty(&st, 57.295779513082323 * theta_2, b);
  st.site = &x_emlrtRSI;
  rotz(&st, 57.295779513082323 * -phi_2, b_b);
  for (i = 0; i < 3; i++) {
    ds_1 = a[i + 3];
    ds_2_tmp = a[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_a[i + 3 * i1] = (a[i] * b[3 * i1] + ds_1 * b[3 * i1 + 1]) + ds_2_tmp *
        b[3 * i1 + 2];
    }

    ds_1 = b_a[i + 3];
    ds_2_tmp = b_a[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      a[i + 3 * i1] = (b_a[i] * b_b[3 * i1] + ds_1 * b_b[3 * i1 + 1]) + ds_2_tmp
        * b_b[3 * i1 + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    ds_1 = R_01[i + 3];
    ds_2_tmp = R_01[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b[i + 3 * i1] = (R_01[i] * a[3 * i1] + ds_1 * a[3 * i1 + 1]) + ds_2_tmp *
        a[3 * i1 + 2];
    }
  }

  st.site = &y_emlrtRSI;
  rotm2eul(&st, b, unusedExpr);
  ds_1 = s_2[49] / theta_2;
  ds_2_tmp = ds_1 * (1.0 - muDoubleScalarCos(theta_2));
  a_tmp = ds_2_tmp * Phi_1_tmp;
  A = ds_2_tmp * ar_tmp;
  ds_2_tmp = ds_1 * muDoubleScalarSin(theta_2);
  ds_1 = s_1[49] / Theta_1;
  ar_tmp = ds_1 * (1.0 - muDoubleScalarCos(Theta_1));
  p_02[0] = ar_tmp * muDoubleScalarCos(phi_1);
  p_02[1] = ar_tmp * muDoubleScalarSin(phi_1);
  p_02[2] = ds_1 * muDoubleScalarSin(Theta_1) + x[6];
  for (i = 0; i < 3; i++) {
    p_02[i] += (R_01[i] * a_tmp + R_01[i + 3] * A) + R_01[i + 6] * ds_2_tmp;
  }
}

/* End of code generation (fwk.c) */
