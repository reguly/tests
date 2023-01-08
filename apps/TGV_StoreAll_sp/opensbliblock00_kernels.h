#ifndef OPENSBLIBLOCK00_KERNEL_H
#define OPENSBLIBLOCK00_KERNEL_H
 void opensbliblock00Kernel087(float *rhoE_B0, float *rhou0_B0, float *rho_B0, float *rhou1_B0, float *rhou2_B0,
const int *idx)
{
   float x2 = 0.0f;
   float u1 = 0.0f;
   float r = 0.0f;
   float u2 = 0.0f;
   float p = 0.0f;
   float x0 = 0.0f;
   float x1 = 0.0f;
   float u0 = 0.0f;
   x0 = Delta0block0*idx[0];

   x1 = Delta1block0*idx[1];

   x2 = Delta2block0*idx[2];

   u0 = sin(x0)*cos(x1)*cos(x2);

   u1 = -sin(x1)*cos(x0)*cos(x2);

   u2 = 0.0f;

   p = (0.0625f*cos(2.0f*x0) + 0.0625f*cos(2.0f*x1))*(cos(2.0f*x2) + 2.0f) + 1.0f/(Minf*Minf*gama);

   r = Minf*Minf*gama*p;

   rho_B0[OPS_ACC2(0,0,0)] = r;

   rhou0_B0[OPS_ACC1(0,0,0)] = r*u0;

   rhou1_B0[OPS_ACC3(0,0,0)] = r*u1;

   rhou2_B0[OPS_ACC4(0,0,0)] = r*u2;

   rhoE_B0[OPS_ACC0(0,0,0)] = p/(gama - 1) + 0.5f*r*(u0*u0 + u1*u1 + u2*u2);

}

void opensbliblock00Kernel081(float *rhoE_B0, float *rhou0_B0, float *rho_B0, float *rhou2_B0, float *rhou1_B0)
{
   rho_B0[OPS_ACC2(-1,0,0)] = rho_B0[OPS_ACC2(1,0,0)];

   rhou0_B0[OPS_ACC1(-1,0,0)] = -1.0f*rhou0_B0[OPS_ACC1(1,0,0)];

   rhou1_B0[OPS_ACC4(-1,0,0)] = rhou1_B0[OPS_ACC4(1,0,0)];

   rhou2_B0[OPS_ACC3(-1,0,0)] = rhou2_B0[OPS_ACC3(1,0,0)];

   rhoE_B0[OPS_ACC0(-1,0,0)] = rhoE_B0[OPS_ACC0(1,0,0)];

   rho_B0[OPS_ACC2(-2,0,0)] = rho_B0[OPS_ACC2(2,0,0)];

   rhou0_B0[OPS_ACC1(-2,0,0)] = -1.0f*rhou0_B0[OPS_ACC1(2,0,0)];

   rhou1_B0[OPS_ACC4(-2,0,0)] = rhou1_B0[OPS_ACC4(2,0,0)];

   rhou2_B0[OPS_ACC3(-2,0,0)] = rhou2_B0[OPS_ACC3(2,0,0)];

   rhoE_B0[OPS_ACC0(-2,0,0)] = rhoE_B0[OPS_ACC0(2,0,0)];

}

void opensbliblock00Kernel082(float *rhoE_B0, float *rhou0_B0, float *rho_B0, float *rhou2_B0, float *rhou1_B0)
{
   rho_B0[OPS_ACC2(1,0,0)] = rho_B0[OPS_ACC2(-1,0,0)];

   rhou0_B0[OPS_ACC1(1,0,0)] = -1.0f*rhou0_B0[OPS_ACC1(-1,0,0)];

   rhou1_B0[OPS_ACC4(1,0,0)] = rhou1_B0[OPS_ACC4(-1,0,0)];

   rhou2_B0[OPS_ACC3(1,0,0)] = rhou2_B0[OPS_ACC3(-1,0,0)];

   rhoE_B0[OPS_ACC0(1,0,0)] = rhoE_B0[OPS_ACC0(-1,0,0)];

   rho_B0[OPS_ACC2(2,0,0)] = rho_B0[OPS_ACC2(-2,0,0)];

   rhou0_B0[OPS_ACC1(2,0,0)] = -1.0f*rhou0_B0[OPS_ACC1(-2,0,0)];

   rhou1_B0[OPS_ACC4(2,0,0)] = rhou1_B0[OPS_ACC4(-2,0,0)];

   rhou2_B0[OPS_ACC3(2,0,0)] = rhou2_B0[OPS_ACC3(-2,0,0)];

   rhoE_B0[OPS_ACC0(2,0,0)] = rhoE_B0[OPS_ACC0(-2,0,0)];

}

void opensbliblock00Kernel083(float *rhoE_B0, float *rhou0_B0, float *rho_B0, float *rhou2_B0, float *rhou1_B0)
{
   rho_B0[OPS_ACC2(0,-1,0)] = rho_B0[OPS_ACC2(0,1,0)];

   rhou0_B0[OPS_ACC1(0,-1,0)] = rhou0_B0[OPS_ACC1(0,1,0)];

   rhou1_B0[OPS_ACC4(0,-1,0)] = -1.0f*rhou1_B0[OPS_ACC4(0,1,0)];

   rhou2_B0[OPS_ACC3(0,-1,0)] = rhou2_B0[OPS_ACC3(0,1,0)];

   rhoE_B0[OPS_ACC0(0,-1,0)] = rhoE_B0[OPS_ACC0(0,1,0)];

   rho_B0[OPS_ACC2(0,-2,0)] = rho_B0[OPS_ACC2(0,2,0)];

   rhou0_B0[OPS_ACC1(0,-2,0)] = rhou0_B0[OPS_ACC1(0,2,0)];

   rhou1_B0[OPS_ACC4(0,-2,0)] = -1.0f*rhou1_B0[OPS_ACC4(0,2,0)];

   rhou2_B0[OPS_ACC3(0,-2,0)] = rhou2_B0[OPS_ACC3(0,2,0)];

   rhoE_B0[OPS_ACC0(0,-2,0)] = rhoE_B0[OPS_ACC0(0,2,0)];

}

void opensbliblock00Kernel084(float *rhoE_B0, float *rhou0_B0, float *rho_B0, float *rhou2_B0, float *rhou1_B0)
{
   rho_B0[OPS_ACC2(0,1,0)] = rho_B0[OPS_ACC2(0,-1,0)];

   rhou0_B0[OPS_ACC1(0,1,0)] = rhou0_B0[OPS_ACC1(0,-1,0)];

   rhou1_B0[OPS_ACC4(0,1,0)] = -1.0f*rhou1_B0[OPS_ACC4(0,-1,0)];

   rhou2_B0[OPS_ACC3(0,1,0)] = rhou2_B0[OPS_ACC3(0,-1,0)];

   rhoE_B0[OPS_ACC0(0,1,0)] = rhoE_B0[OPS_ACC0(0,-1,0)];

   rho_B0[OPS_ACC2(0,2,0)] = rho_B0[OPS_ACC2(0,-2,0)];

   rhou0_B0[OPS_ACC1(0,2,0)] = rhou0_B0[OPS_ACC1(0,-2,0)];

   rhou1_B0[OPS_ACC4(0,2,0)] = -1.0f*rhou1_B0[OPS_ACC4(0,-2,0)];

   rhou2_B0[OPS_ACC3(0,2,0)] = rhou2_B0[OPS_ACC3(0,-2,0)];

   rhoE_B0[OPS_ACC0(0,2,0)] = rhoE_B0[OPS_ACC0(0,-2,0)];

}

void opensbliblock00Kernel085(float *rhoE_B0, float *rhou0_B0, float *rho_B0, float *rhou2_B0, float *rhou1_B0)
{
   rho_B0[OPS_ACC2(0,0,-1)] = rho_B0[OPS_ACC2(0,0,1)];

   rhou0_B0[OPS_ACC1(0,0,-1)] = rhou0_B0[OPS_ACC1(0,0,1)];

   rhou1_B0[OPS_ACC4(0,0,-1)] = rhou1_B0[OPS_ACC4(0,0,1)];

   rhou2_B0[OPS_ACC3(0,0,-1)] = -1.0f*rhou2_B0[OPS_ACC3(0,0,1)];

   rhoE_B0[OPS_ACC0(0,0,-1)] = rhoE_B0[OPS_ACC0(0,0,1)];

   rho_B0[OPS_ACC2(0,0,-2)] = rho_B0[OPS_ACC2(0,0,2)];

   rhou0_B0[OPS_ACC1(0,0,-2)] = rhou0_B0[OPS_ACC1(0,0,2)];

   rhou1_B0[OPS_ACC4(0,0,-2)] = rhou1_B0[OPS_ACC4(0,0,2)];

   rhou2_B0[OPS_ACC3(0,0,-2)] = -1.0f*rhou2_B0[OPS_ACC3(0,0,2)];

   rhoE_B0[OPS_ACC0(0,0,-2)] = rhoE_B0[OPS_ACC0(0,0,2)];

}

void opensbliblock00Kernel086(float *rhoE_B0, float *rhou0_B0, float *rho_B0, float *rhou2_B0, float *rhou1_B0)
{
   rho_B0[OPS_ACC2(0,0,1)] = rho_B0[OPS_ACC2(0,0,-1)];

   rhou0_B0[OPS_ACC1(0,0,1)] = rhou0_B0[OPS_ACC1(0,0,-1)];

   rhou1_B0[OPS_ACC4(0,0,1)] = rhou1_B0[OPS_ACC4(0,0,-1)];

   rhou2_B0[OPS_ACC3(0,0,1)] = -1.0f*rhou2_B0[OPS_ACC3(0,0,-1)];

   rhoE_B0[OPS_ACC0(0,0,1)] = rhoE_B0[OPS_ACC0(0,0,-1)];

   rho_B0[OPS_ACC2(0,0,2)] = rho_B0[OPS_ACC2(0,0,-2)];

   rhou0_B0[OPS_ACC1(0,0,2)] = rhou0_B0[OPS_ACC1(0,0,-2)];

   rhou1_B0[OPS_ACC4(0,0,2)] = rhou1_B0[OPS_ACC4(0,0,-2)];

   rhou2_B0[OPS_ACC3(0,0,2)] = -1.0f*rhou2_B0[OPS_ACC3(0,0,-2)];

   rhoE_B0[OPS_ACC0(0,0,2)] = rhoE_B0[OPS_ACC0(0,0,-2)];

}

 void opensbliblock00Kernel088(const float *rhoE_B0, const float *rhou0_B0, const float *rho_B0, const float
*rhou1_B0, const float *rhou2_B0, float *rho_RKold_B0, float *rhou2_RKold_B0, float *rhoE_RKold_B0, float
*rhou0_RKold_B0, float *rhou1_RKold_B0)
{
   rho_RKold_B0[OPS_ACC5(0,0,0)] = rho_B0[OPS_ACC2(0,0,0)];

   rhou0_RKold_B0[OPS_ACC8(0,0,0)] = rhou0_B0[OPS_ACC1(0,0,0)];

   rhou1_RKold_B0[OPS_ACC9(0,0,0)] = rhou1_B0[OPS_ACC3(0,0,0)];

   rhou2_RKold_B0[OPS_ACC6(0,0,0)] = rhou2_B0[OPS_ACC4(0,0,0)];

   rhoE_RKold_B0[OPS_ACC7(0,0,0)] = rhoE_B0[OPS_ACC0(0,0,0)];

}

void opensbliblock00Kernel003(const float *rho_B0, const float *rhou1_B0, float *u1_B0)
{
   u1_B0[OPS_ACC2(0,0,0)] = rhou1_B0[OPS_ACC1(0,0,0)]/rho_B0[OPS_ACC0(0,0,0)];

}

void opensbliblock00Kernel024(const float *rhou0_B0, const float *rho_B0, float *u0_B0)
{
   u0_B0[OPS_ACC2(0,0,0)] = rhou0_B0[OPS_ACC0(0,0,0)]/rho_B0[OPS_ACC1(0,0,0)];

}

void opensbliblock00Kernel038(const float *rho_B0, const float *rhou2_B0, float *u2_B0)
{
   u2_B0[OPS_ACC2(0,0,0)] = rhou2_B0[OPS_ACC1(0,0,0)]/rho_B0[OPS_ACC0(0,0,0)];

}

 void opensbliblock00Kernel009(const float *u2_B0, const float *u0_B0, const float *rhoE_B0, const float *rho_B0,
const float *u1_B0, float *p_B0)
{
    p_B0[OPS_ACC5(0,0,0)] = (gama - 1)*(rhoE_B0[OPS_ACC2(0,0,0)] -
      rc6*rho_B0[OPS_ACC3(0,0,0)]*u0_B0[OPS_ACC1(0,0,0)]*u0_B0[OPS_ACC1(0,0,0)] -
      rc6*rho_B0[OPS_ACC3(0,0,0)]*u1_B0[OPS_ACC4(0,0,0)]*u1_B0[OPS_ACC1(0,0,0)] -
      rc6*rho_B0[OPS_ACC3(0,0,0)]*u2_B0[OPS_ACC0(0,0,0)]*u2_B0[OPS_ACC1(0,0,0)]);

}

void opensbliblock00Kernel079(const float *p_B0, const float *rho_B0, float *T_B0)
{
   T_B0[OPS_ACC2(0,0,0)] = Minf*Minf*gama*p_B0[OPS_ACC0(0,0,0)]/rho_B0[OPS_ACC1(0,0,0)];

}

 void opensbliblock00Kernel000(const float *p_B0, const float *u1_B0, const float *rhoE_B0, const float *rhou0_B0,
const float *rho_B0, const float *rhou1_B0, const float *rhou2_B0, float *wk39_B0, float *wk42_B0, float *wk41_B0,
float *wk40_B0, float *wk44_B0, float *wk43_B0)
{
   wk39_B0[OPS_ACC7(0,0,0)] = p_B0[OPS_ACC0(0,0,0)]*u1_B0[OPS_ACC1(0,0,0)];

   wk40_B0[OPS_ACC10(0,0,0)] = rhou2_B0[OPS_ACC6(0,0,0)]*u1_B0[OPS_ACC1(0,0,0)];

   wk41_B0[OPS_ACC9(0,0,0)] = rhou0_B0[OPS_ACC3(0,0,0)]*u1_B0[OPS_ACC1(0,0,0)];

   wk42_B0[OPS_ACC8(0,0,0)] = rhoE_B0[OPS_ACC2(0,0,0)]*u1_B0[OPS_ACC1(0,0,0)];

   wk43_B0[OPS_ACC12(0,0,0)] = rho_B0[OPS_ACC4(0,0,0)]*u1_B0[OPS_ACC1(0,0,0)];

   wk44_B0[OPS_ACC11(0,0,0)] = rhou1_B0[OPS_ACC5(0,0,0)]*u1_B0[OPS_ACC1(0,0,0)];

}

void opensbliblock00Kernel002(const float *rhou2_B0, float *wk0_B0)
{
    wk0_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc7*rhou2_B0[OPS_ACC0(0,-1,0)] + (rc7)*rhou2_B0[OPS_ACC0(0,1,0)] -
      rc8*rhou2_B0[OPS_ACC0(0,2,0)] + (rc8)*rhou2_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel004(const float *u1_B0, float *wk1_B0)
{
    wk1_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc7*u1_B0[OPS_ACC0(0,-1,0)] + (rc7)*u1_B0[OPS_ACC0(0,1,0)] -
      rc8*u1_B0[OPS_ACC0(0,2,0)] + (rc8)*u1_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel006(const float *rhoE_B0, float *wk2_B0)
{
    wk2_B0[OPS_ACC1(0,0,0)] = inv_0*((rc8)*rhoE_B0[OPS_ACC0(0,-2,0)] - rc8*rhoE_B0[OPS_ACC0(0,2,0)] +
      (rc7)*rhoE_B0[OPS_ACC0(0,1,0)] - rc7*rhoE_B0[OPS_ACC0(0,-1,0)]);

}

void opensbliblock00Kernel008(const float *rhou0_B0, float *wk3_B0)
{
    wk3_B0[OPS_ACC1(0,0,0)] = inv_0*((rc8)*rhou0_B0[OPS_ACC0(0,-2,0)] - rc7*rhou0_B0[OPS_ACC0(0,-1,0)] +
      (rc7)*rhou0_B0[OPS_ACC0(0,1,0)] - rc8*rhou0_B0[OPS_ACC0(0,2,0)]);

}

void opensbliblock00Kernel010(const float *wk39_B0, float *wk4_B0)
{
    wk4_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc7*wk39_B0[OPS_ACC0(0,-1,0)] + (rc7)*wk39_B0[OPS_ACC0(0,1,0)] +
      (rc8)*wk39_B0[OPS_ACC0(0,-2,0)] - rc8*wk39_B0[OPS_ACC0(0,2,0)]);

}

void opensbliblock00Kernel011(const float *p_B0, float *wk5_B0)
{
    wk5_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc7*p_B0[OPS_ACC0(0,-1,0)] + (rc7)*p_B0[OPS_ACC0(0,1,0)] -
      rc8*p_B0[OPS_ACC0(0,2,0)] + (rc8)*p_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel012(const float *wk40_B0, float *wk6_B0)
{
    wk6_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc8*wk40_B0[OPS_ACC0(0,2,0)] + (rc7)*wk40_B0[OPS_ACC0(0,1,0)] -
      rc7*wk40_B0[OPS_ACC0(0,-1,0)] + (rc8)*wk40_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel014(const float *rhou1_B0, float *wk7_B0)
{
    wk7_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc7*rhou1_B0[OPS_ACC0(0,-1,0)] + (rc7)*rhou1_B0[OPS_ACC0(0,1,0)] -
      rc8*rhou1_B0[OPS_ACC0(0,2,0)] + (rc8)*rhou1_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel015(const float *wk41_B0, float *wk8_B0)
{
    wk8_B0[OPS_ACC1(0,0,0)] = inv_0*((rc8)*wk41_B0[OPS_ACC0(0,-2,0)] - rc8*wk41_B0[OPS_ACC0(0,2,0)] +
      (rc7)*wk41_B0[OPS_ACC0(0,1,0)] - rc7*wk41_B0[OPS_ACC0(0,-1,0)]);

}

void opensbliblock00Kernel016(const float *wk42_B0, float *wk9_B0)
{
    wk9_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc7*wk42_B0[OPS_ACC0(0,-1,0)] + (rc7)*wk42_B0[OPS_ACC0(0,1,0)] -
      rc8*wk42_B0[OPS_ACC0(0,2,0)] + (rc8)*wk42_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel018(const float *wk43_B0, float *wk10_B0)
{
    wk10_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc8*wk43_B0[OPS_ACC0(0,2,0)] + (rc7)*wk43_B0[OPS_ACC0(0,1,0)] -
      rc7*wk43_B0[OPS_ACC0(0,-1,0)] + (rc8)*wk43_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel019(const float *rho_B0, float *wk11_B0)
{
    wk11_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc8*rho_B0[OPS_ACC0(0,2,0)] + (rc8)*rho_B0[OPS_ACC0(0,-2,0)] -
      rc7*rho_B0[OPS_ACC0(0,-1,0)] + (rc7)*rho_B0[OPS_ACC0(0,1,0)]);

}

void opensbliblock00Kernel020(const float *wk44_B0, float *wk12_B0)
{
    wk12_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc8*wk44_B0[OPS_ACC0(0,2,0)] + (rc7)*wk44_B0[OPS_ACC0(0,1,0)] -
      rc7*wk44_B0[OPS_ACC0(0,-1,0)] + (rc8)*wk44_B0[OPS_ACC0(0,-2,0)]);

}

 void opensbliblock00Kernel021(const float *p_B0, const float *u0_B0, const float *rhoE_B0, const float *rhou0_B0,
const float *rho_B0, const float *rhou1_B0, const float *rhou2_B0, float *wk39_B0, float *wk42_B0, float *wk41_B0,
float *wk40_B0, float *wk44_B0, float *wk43_B0)
{
   wk39_B0[OPS_ACC7(0,0,0)] = rhou2_B0[OPS_ACC6(0,0,0)]*u0_B0[OPS_ACC1(0,0,0)];

   wk40_B0[OPS_ACC10(0,0,0)] = rho_B0[OPS_ACC4(0,0,0)]*u0_B0[OPS_ACC1(0,0,0)];

   wk41_B0[OPS_ACC9(0,0,0)] = rhoE_B0[OPS_ACC2(0,0,0)]*u0_B0[OPS_ACC1(0,0,0)];

   wk42_B0[OPS_ACC8(0,0,0)] = rhou1_B0[OPS_ACC5(0,0,0)]*u0_B0[OPS_ACC1(0,0,0)];

   wk43_B0[OPS_ACC12(0,0,0)] = p_B0[OPS_ACC0(0,0,0)]*u0_B0[OPS_ACC1(0,0,0)];

   wk44_B0[OPS_ACC11(0,0,0)] = rhou0_B0[OPS_ACC3(0,0,0)]*u0_B0[OPS_ACC1(0,0,0)];

}

void opensbliblock00Kernel022(const float *p_B0, float *wk13_B0)
{
    wk13_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc7*p_B0[OPS_ACC0(-1,0,0)] + (rc7)*p_B0[OPS_ACC0(1,0,0)] -
      rc8*p_B0[OPS_ACC0(2,0,0)] + (rc8)*p_B0[OPS_ACC0(-2,0,0)]);

}

void opensbliblock00Kernel023(const float *rhou1_B0, float *wk14_B0)
{
    wk14_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc7*rhou1_B0[OPS_ACC0(-1,0,0)] + (rc7)*rhou1_B0[OPS_ACC0(1,0,0)] -
      rc8*rhou1_B0[OPS_ACC0(2,0,0)] + (rc8)*rhou1_B0[OPS_ACC0(-2,0,0)]);

}

void opensbliblock00Kernel025(const float *wk39_B0, float *wk15_B0)
{
    wk15_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc7*wk39_B0[OPS_ACC0(-1,0,0)] + (rc7)*wk39_B0[OPS_ACC0(1,0,0)] +
      (rc8)*wk39_B0[OPS_ACC0(-2,0,0)] - rc8*wk39_B0[OPS_ACC0(2,0,0)]);

}

void opensbliblock00Kernel026(const float *wk40_B0, float *wk16_B0)
{
    wk16_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc8*wk40_B0[OPS_ACC0(2,0,0)] + (rc7)*wk40_B0[OPS_ACC0(1,0,0)] -
      rc7*wk40_B0[OPS_ACC0(-1,0,0)] + (rc8)*wk40_B0[OPS_ACC0(-2,0,0)]);

}

void opensbliblock00Kernel027(const float *u0_B0, float *wk17_B0)
{
    wk17_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc8*u0_B0[OPS_ACC0(2,0,0)] + (rc8)*u0_B0[OPS_ACC0(-2,0,0)] -
      rc7*u0_B0[OPS_ACC0(-1,0,0)] + (rc7)*u0_B0[OPS_ACC0(1,0,0)]);

}

void opensbliblock00Kernel028(const float *rhou0_B0, float *wk18_B0)
{
    wk18_B0[OPS_ACC1(0,0,0)] = inv_1*((rc8)*rhou0_B0[OPS_ACC0(-2,0,0)] - rc7*rhou0_B0[OPS_ACC0(-1,0,0)] +
      (rc7)*rhou0_B0[OPS_ACC0(1,0,0)] - rc8*rhou0_B0[OPS_ACC0(2,0,0)]);

}

void opensbliblock00Kernel029(const float *rhoE_B0, float *wk19_B0)
{
    wk19_B0[OPS_ACC1(0,0,0)] = inv_1*((rc8)*rhoE_B0[OPS_ACC0(-2,0,0)] - rc8*rhoE_B0[OPS_ACC0(2,0,0)] +
      (rc7)*rhoE_B0[OPS_ACC0(1,0,0)] - rc7*rhoE_B0[OPS_ACC0(-1,0,0)]);

}

void opensbliblock00Kernel030(const float *wk41_B0, float *wk20_B0)
{
    wk20_B0[OPS_ACC1(0,0,0)] = inv_1*((rc8)*wk41_B0[OPS_ACC0(-2,0,0)] - rc8*wk41_B0[OPS_ACC0(2,0,0)] +
      (rc7)*wk41_B0[OPS_ACC0(1,0,0)] - rc7*wk41_B0[OPS_ACC0(-1,0,0)]);

}

void opensbliblock00Kernel031(const float *rhou2_B0, float *wk21_B0)
{
    wk21_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc7*rhou2_B0[OPS_ACC0(-1,0,0)] + (rc7)*rhou2_B0[OPS_ACC0(1,0,0)] -
      rc8*rhou2_B0[OPS_ACC0(2,0,0)] + (rc8)*rhou2_B0[OPS_ACC0(-2,0,0)]);

}

void opensbliblock00Kernel032(const float *wk42_B0, float *wk22_B0)
{
    wk22_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc7*wk42_B0[OPS_ACC0(-1,0,0)] + (rc7)*wk42_B0[OPS_ACC0(1,0,0)] -
      rc8*wk42_B0[OPS_ACC0(2,0,0)] + (rc8)*wk42_B0[OPS_ACC0(-2,0,0)]);

}

void opensbliblock00Kernel033(const float *wk43_B0, float *wk23_B0)
{
    wk23_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc8*wk43_B0[OPS_ACC0(2,0,0)] + (rc7)*wk43_B0[OPS_ACC0(1,0,0)] -
      rc7*wk43_B0[OPS_ACC0(-1,0,0)] + (rc8)*wk43_B0[OPS_ACC0(-2,0,0)]);

}

void opensbliblock00Kernel034(const float *rho_B0, float *wk24_B0)
{
    wk24_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc8*rho_B0[OPS_ACC0(2,0,0)] + (rc8)*rho_B0[OPS_ACC0(-2,0,0)] -
      rc7*rho_B0[OPS_ACC0(-1,0,0)] + (rc7)*rho_B0[OPS_ACC0(1,0,0)]);

}

void opensbliblock00Kernel035(const float *wk44_B0, float *wk25_B0)
{
    wk25_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc8*wk44_B0[OPS_ACC0(2,0,0)] + (rc7)*wk44_B0[OPS_ACC0(1,0,0)] -
      rc7*wk44_B0[OPS_ACC0(-1,0,0)] + (rc8)*wk44_B0[OPS_ACC0(-2,0,0)]);

}

 void opensbliblock00Kernel036(const float *p_B0, const float *u2_B0, const float *rhoE_B0, const float *rhou2_B0,
const float *rhou0_B0, const float *rho_B0, const float *rhou1_B0, float *wk39_B0, float *wk42_B0, float *wk41_B0,
float *wk40_B0, float *wk44_B0, float *wk43_B0)
{
   wk39_B0[OPS_ACC7(0,0,0)] = rhoE_B0[OPS_ACC2(0,0,0)]*u2_B0[OPS_ACC1(0,0,0)];

   wk40_B0[OPS_ACC10(0,0,0)] = p_B0[OPS_ACC0(0,0,0)]*u2_B0[OPS_ACC1(0,0,0)];

   wk41_B0[OPS_ACC9(0,0,0)] = rho_B0[OPS_ACC5(0,0,0)]*u2_B0[OPS_ACC1(0,0,0)];

   wk42_B0[OPS_ACC8(0,0,0)] = rhou1_B0[OPS_ACC6(0,0,0)]*u2_B0[OPS_ACC1(0,0,0)];

   wk43_B0[OPS_ACC12(0,0,0)] = rhou0_B0[OPS_ACC4(0,0,0)]*u2_B0[OPS_ACC1(0,0,0)];

   wk44_B0[OPS_ACC11(0,0,0)] = rhou2_B0[OPS_ACC3(0,0,0)]*u2_B0[OPS_ACC1(0,0,0)];

}

void opensbliblock00Kernel037(const float *p_B0, float *wk26_B0)
{
    wk26_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc7*p_B0[OPS_ACC0(0,0,-1)] - rc8*p_B0[OPS_ACC0(0,0,2)] +
      (rc8)*p_B0[OPS_ACC0(0,0,-2)] + (rc7)*p_B0[OPS_ACC0(0,0,1)]);

}

void opensbliblock00Kernel039(const float *wk39_B0, float *wk27_B0)
{
    wk27_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc7*wk39_B0[OPS_ACC0(0,0,-1)] + (rc8)*wk39_B0[OPS_ACC0(0,0,-2)] -
      rc8*wk39_B0[OPS_ACC0(0,0,2)] + (rc7)*wk39_B0[OPS_ACC0(0,0,1)]);

}

void opensbliblock00Kernel040(const float *wk40_B0, float *wk28_B0)
{
    wk28_B0[OPS_ACC1(0,0,0)] = inv_2*((rc7)*wk40_B0[OPS_ACC0(0,0,1)] - rc8*wk40_B0[OPS_ACC0(0,0,2)] -
      rc7*wk40_B0[OPS_ACC0(0,0,-1)] + (rc8)*wk40_B0[OPS_ACC0(0,0,-2)]);

}

void opensbliblock00Kernel041(const float *rhou1_B0, float *wk29_B0)
{
    wk29_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc7*rhou1_B0[OPS_ACC0(0,0,-1)] + (rc8)*rhou1_B0[OPS_ACC0(0,0,-2)] -
      rc8*rhou1_B0[OPS_ACC0(0,0,2)] + (rc7)*rhou1_B0[OPS_ACC0(0,0,1)]);

}

void opensbliblock00Kernel042(const float *wk41_B0, float *wk30_B0)
{
    wk30_B0[OPS_ACC1(0,0,0)] = inv_2*((rc7)*wk41_B0[OPS_ACC0(0,0,1)] - rc8*wk41_B0[OPS_ACC0(0,0,2)] +
      (rc8)*wk41_B0[OPS_ACC0(0,0,-2)] - rc7*wk41_B0[OPS_ACC0(0,0,-1)]);

}

void opensbliblock00Kernel043(const float *u2_B0, float *wk31_B0)
{
    wk31_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc7*u2_B0[OPS_ACC0(0,0,-1)] + (rc7)*u2_B0[OPS_ACC0(0,0,1)] +
      (rc8)*u2_B0[OPS_ACC0(0,0,-2)] - rc8*u2_B0[OPS_ACC0(0,0,2)]);

}

void opensbliblock00Kernel044(const float *rho_B0, float *wk32_B0)
{
    wk32_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc8*rho_B0[OPS_ACC0(0,0,2)] + (rc8)*rho_B0[OPS_ACC0(0,0,-2)] +
      (rc7)*rho_B0[OPS_ACC0(0,0,1)] - rc7*rho_B0[OPS_ACC0(0,0,-1)]);

}

void opensbliblock00Kernel045(const float *rhoE_B0, float *wk33_B0)
{
    wk33_B0[OPS_ACC1(0,0,0)] = inv_2*((rc7)*rhoE_B0[OPS_ACC0(0,0,1)] + (rc8)*rhoE_B0[OPS_ACC0(0,0,-2)] -
      rc8*rhoE_B0[OPS_ACC0(0,0,2)] - rc7*rhoE_B0[OPS_ACC0(0,0,-1)]);

}

void opensbliblock00Kernel046(const float *wk42_B0, float *wk34_B0)
{
    wk34_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc7*wk42_B0[OPS_ACC0(0,0,-1)] - rc8*wk42_B0[OPS_ACC0(0,0,2)] +
      (rc8)*wk42_B0[OPS_ACC0(0,0,-2)] + (rc7)*wk42_B0[OPS_ACC0(0,0,1)]);

}

void opensbliblock00Kernel047(const float *wk43_B0, float *wk35_B0)
{
    wk35_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc8*wk43_B0[OPS_ACC0(0,0,2)] + (rc7)*wk43_B0[OPS_ACC0(0,0,1)] +
      (rc8)*wk43_B0[OPS_ACC0(0,0,-2)] - rc7*wk43_B0[OPS_ACC0(0,0,-1)]);

}

void opensbliblock00Kernel048(const float *rhou2_B0, float *wk36_B0)
{
    wk36_B0[OPS_ACC1(0,0,0)] = inv_2*((rc7)*rhou2_B0[OPS_ACC0(0,0,1)] - rc7*rhou2_B0[OPS_ACC0(0,0,-1)] -
      rc8*rhou2_B0[OPS_ACC0(0,0,2)] + (rc8)*rhou2_B0[OPS_ACC0(0,0,-2)]);

}

void opensbliblock00Kernel049(const float *rhou0_B0, float *wk37_B0)
{
    wk37_B0[OPS_ACC1(0,0,0)] = inv_2*((rc8)*rhou0_B0[OPS_ACC0(0,0,-2)] - rc7*rhou0_B0[OPS_ACC0(0,0,-1)] +
      (rc7)*rhou0_B0[OPS_ACC0(0,0,1)] - rc8*rhou0_B0[OPS_ACC0(0,0,2)]);

}

void opensbliblock00Kernel050(const float *wk44_B0, float *wk38_B0)
{
    wk38_B0[OPS_ACC1(0,0,0)] = inv_2*((rc7)*wk44_B0[OPS_ACC0(0,0,1)] - rc8*wk44_B0[OPS_ACC0(0,0,2)] -
      rc7*wk44_B0[OPS_ACC0(0,0,-1)] + (rc8)*wk44_B0[OPS_ACC0(0,0,-2)]);

}

 void opensbliblock00Kernel051(const float *wk10_B0, const float *wk38_B0, const float *rhoE_B0, const float
*rho_B0, const float *wk11_B0, const float *rhou2_B0, const float *wk27_B0, const float *u0_B0, const float
*wk25_B0, const float *wk16_B0, const float *wk32_B0, const float *wk28_B0, const float *wk9_B0, const float
*wk29_B0, const float *u1_B0, const float *wk37_B0, const float *wk6_B0, const float *wk21_B0, const float
*rhou0_B0, const float *wk26_B0, const float *wk31_B0, const float *wk24_B0, const float *wk30_B0, const float
*wk5_B0, const float *wk3_B0, const float *wk1_B0, const float *u2_B0, const float *wk13_B0, const float *wk20_B0,
const float *wk18_B0, const float *wk22_B0, const float *rhou1_B0, const float *wk23_B0, const float *wk17_B0,
const float *wk15_B0, const float *wk33_B0, const float *wk12_B0, const float *wk4_B0, const float *wk0_B0, const
float *wk34_B0, const float *wk19_B0, const float *wk7_B0, const float *wk8_B0, const float *wk2_B0, const float
*wk35_B0, const float *wk14_B0, const float *wk36_B0, float *Residual4_B0, float *Residual3_B0, float
*Residual0_B0, float *Residual2_B0, float *Residual1_B0)
{
    Residual0_B0[OPS_ACC49(0,0,0)] = -rc6*(wk17_B0[OPS_ACC33(0,0,0)] + wk1_B0[OPS_ACC25(0,0,0)] +
      wk31_B0[OPS_ACC20(0,0,0)])*rho_B0[OPS_ACC3(0,0,0)] - rc6*u0_B0[OPS_ACC7(0,0,0)]*wk24_B0[OPS_ACC21(0,0,0)] -
      rc6*u1_B0[OPS_ACC14(0,0,0)]*wk11_B0[OPS_ACC4(0,0,0)] - rc6*u2_B0[OPS_ACC26(0,0,0)]*wk32_B0[OPS_ACC10(0,0,0)] -
      rc6*wk10_B0[OPS_ACC0(0,0,0)] - rc6*wk16_B0[OPS_ACC9(0,0,0)] - rc6*wk30_B0[OPS_ACC22(0,0,0)];

    Residual1_B0[OPS_ACC51(0,0,0)] = -rc6*(wk17_B0[OPS_ACC33(0,0,0)] + wk1_B0[OPS_ACC25(0,0,0)] +
      wk31_B0[OPS_ACC20(0,0,0)])*rhou0_B0[OPS_ACC18(0,0,0)] - rc6*u0_B0[OPS_ACC7(0,0,0)]*wk18_B0[OPS_ACC29(0,0,0)] -
      rc6*u1_B0[OPS_ACC14(0,0,0)]*wk3_B0[OPS_ACC24(0,0,0)] - rc6*u2_B0[OPS_ACC26(0,0,0)]*wk37_B0[OPS_ACC15(0,0,0)] -
      wk13_B0[OPS_ACC27(0,0,0)] - rc6*wk25_B0[OPS_ACC8(0,0,0)] - rc6*wk35_B0[OPS_ACC44(0,0,0)] -
      rc6*wk8_B0[OPS_ACC42(0,0,0)];

    Residual2_B0[OPS_ACC50(0,0,0)] = -rc6*(wk17_B0[OPS_ACC33(0,0,0)] + wk1_B0[OPS_ACC25(0,0,0)] +
      wk31_B0[OPS_ACC20(0,0,0)])*rhou1_B0[OPS_ACC31(0,0,0)] - rc6*u0_B0[OPS_ACC7(0,0,0)]*wk14_B0[OPS_ACC45(0,0,0)] -
      rc6*u1_B0[OPS_ACC14(0,0,0)]*wk7_B0[OPS_ACC41(0,0,0)] - rc6*u2_B0[OPS_ACC26(0,0,0)]*wk29_B0[OPS_ACC13(0,0,0)] -
      rc6*wk12_B0[OPS_ACC36(0,0,0)] - rc6*wk22_B0[OPS_ACC30(0,0,0)] - rc6*wk34_B0[OPS_ACC39(0,0,0)] -
      wk5_B0[OPS_ACC23(0,0,0)];

    Residual3_B0[OPS_ACC48(0,0,0)] = -rc6*(wk17_B0[OPS_ACC33(0,0,0)] + wk1_B0[OPS_ACC25(0,0,0)] +
      wk31_B0[OPS_ACC20(0,0,0)])*rhou2_B0[OPS_ACC5(0,0,0)] - rc6*u0_B0[OPS_ACC7(0,0,0)]*wk21_B0[OPS_ACC17(0,0,0)] -
      rc6*u1_B0[OPS_ACC14(0,0,0)]*wk0_B0[OPS_ACC38(0,0,0)] - rc6*u2_B0[OPS_ACC26(0,0,0)]*wk36_B0[OPS_ACC46(0,0,0)] -
      rc6*wk15_B0[OPS_ACC34(0,0,0)] - wk26_B0[OPS_ACC19(0,0,0)] - rc6*wk38_B0[OPS_ACC1(0,0,0)] -
      rc6*wk6_B0[OPS_ACC16(0,0,0)];

    Residual4_B0[OPS_ACC47(0,0,0)] = -rc6*(wk17_B0[OPS_ACC33(0,0,0)] + wk1_B0[OPS_ACC25(0,0,0)] +
      wk31_B0[OPS_ACC20(0,0,0)])*rhoE_B0[OPS_ACC2(0,0,0)] - rc6*u0_B0[OPS_ACC7(0,0,0)]*wk19_B0[OPS_ACC40(0,0,0)] -
      rc6*u1_B0[OPS_ACC14(0,0,0)]*wk2_B0[OPS_ACC43(0,0,0)] - rc6*u2_B0[OPS_ACC26(0,0,0)]*wk33_B0[OPS_ACC35(0,0,0)] -
      rc6*wk20_B0[OPS_ACC28(0,0,0)] - wk23_B0[OPS_ACC32(0,0,0)] - rc6*wk27_B0[OPS_ACC6(0,0,0)] -
      wk28_B0[OPS_ACC11(0,0,0)] - wk4_B0[OPS_ACC37(0,0,0)] - rc6*wk9_B0[OPS_ACC12(0,0,0)];

}

void opensbliblock00Kernel052(const float *u1_B0, float *wk0_B0)
{
    wk0_B0[OPS_ACC1(0,0,0)] = -rc8*inv_3*(-16*u1_B0[OPS_ACC0(0,-1,0)] + u1_B0[OPS_ACC0(0,-2,0)] + u1_B0[OPS_ACC0(0,2,0)]
      - 16*u1_B0[OPS_ACC0(0,1,0)] + 30*u1_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel053(const float *u1_B0, float *wk1_B0)
{
    wk1_B0[OPS_ACC1(0,0,0)] = -rc8*inv_0*(-u1_B0[OPS_ACC0(0,-2,0)] - 8*u1_B0[OPS_ACC0(0,1,0)] + u1_B0[OPS_ACC0(0,2,0)] +
      8*u1_B0[OPS_ACC0(0,-1,0)]);

}

void opensbliblock00Kernel055(const float *u0_B0, float *wk3_B0)
{
    wk3_B0[OPS_ACC1(0,0,0)] = -rc8*inv_0*(u0_B0[OPS_ACC0(0,2,0)] + 8*u0_B0[OPS_ACC0(0,-1,0)] - u0_B0[OPS_ACC0(0,-2,0)] -
      8*u0_B0[OPS_ACC0(0,1,0)]);

}

void opensbliblock00Kernel056(const float *u0_B0, float *wk4_B0)
{
    wk4_B0[OPS_ACC1(0,0,0)] = -rc8*inv_3*(u0_B0[OPS_ACC0(0,2,0)] - 16*u0_B0[OPS_ACC0(0,1,0)] + 30*u0_B0[OPS_ACC0(0,0,0)]
      - 16*u0_B0[OPS_ACC0(0,-1,0)] + u0_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel057(const float *u1_B0, float *wk5_B0)
{
    wk5_B0[OPS_ACC1(0,0,0)] = -rc8*inv_4*(-16*u1_B0[OPS_ACC0(-1,0,0)] + u1_B0[OPS_ACC0(-2,0,0)] + u1_B0[OPS_ACC0(2,0,0)]
      - 16*u1_B0[OPS_ACC0(1,0,0)] + 30*u1_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel058(const float *u0_B0, float *wk6_B0)
{
    wk6_B0[OPS_ACC1(0,0,0)] = -rc8*inv_1*(u0_B0[OPS_ACC0(2,0,0)] + 8*u0_B0[OPS_ACC0(-1,0,0)] - u0_B0[OPS_ACC0(-2,0,0)] -
      8*u0_B0[OPS_ACC0(1,0,0)]);

}

void opensbliblock00Kernel059(const float *u2_B0, float *wk7_B0)
{
    wk7_B0[OPS_ACC1(0,0,0)] = -rc8*inv_5*(-16*u2_B0[OPS_ACC0(0,0,-1)] + u2_B0[OPS_ACC0(0,0,-2)] + u2_B0[OPS_ACC0(0,0,2)]
      - 16*u2_B0[OPS_ACC0(0,0,1)] + 30*u2_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel060(const float *u0_B0, float *wk8_B0)
{
    wk8_B0[OPS_ACC1(0,0,0)] = (rc8)*inv_5*(16*u0_B0[OPS_ACC0(0,0,1)] - 30*u0_B0[OPS_ACC0(0,0,0)] +
      16*u0_B0[OPS_ACC0(0,0,-1)] - u0_B0[OPS_ACC0(0,0,2)] - u0_B0[OPS_ACC0(0,0,-2)]);

}

void opensbliblock00Kernel061(const float *u1_B0, float *wk9_B0)
{
    wk9_B0[OPS_ACC1(0,0,0)] = -rc8*inv_1*(-u1_B0[OPS_ACC0(-2,0,0)] - 8*u1_B0[OPS_ACC0(1,0,0)] +
      8*u1_B0[OPS_ACC0(-1,0,0)] + u1_B0[OPS_ACC0(2,0,0)]);

}

void opensbliblock00Kernel062(const float *u2_B0, float *wk10_B0)
{
    wk10_B0[OPS_ACC1(0,0,0)] = -rc8*inv_2*(-u2_B0[OPS_ACC0(0,0,-2)] - 8*u2_B0[OPS_ACC0(0,0,1)] + u2_B0[OPS_ACC0(0,0,2)]
      + 8*u2_B0[OPS_ACC0(0,0,-1)]);

}

void opensbliblock00Kernel063(const float *u1_B0, float *wk11_B0)
{
    wk11_B0[OPS_ACC1(0,0,0)] = (rc8)*inv_2*(u1_B0[OPS_ACC0(0,0,-2)] - 8*u1_B0[OPS_ACC0(0,0,-1)] - u1_B0[OPS_ACC0(0,0,2)]
      + 8*u1_B0[OPS_ACC0(0,0,1)]);

}

void opensbliblock00Kernel065(const float *u2_B0, float *wk13_B0)
{
    wk13_B0[OPS_ACC1(0,0,0)] = (rc8)*inv_4*(16*u2_B0[OPS_ACC0(-1,0,0)] - u2_B0[OPS_ACC0(-2,0,0)] -
      u2_B0[OPS_ACC0(2,0,0)] + 16*u2_B0[OPS_ACC0(1,0,0)] - 30*u2_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel066(const float *u0_B0, float *wk14_B0)
{
    wk14_B0[OPS_ACC1(0,0,0)] = -rc8*inv_4*(u0_B0[OPS_ACC0(2,0,0)] - 16*u0_B0[OPS_ACC0(1,0,0)] +
      30*u0_B0[OPS_ACC0(0,0,0)] + u0_B0[OPS_ACC0(-2,0,0)] - 16*u0_B0[OPS_ACC0(-1,0,0)]);

}

void opensbliblock00Kernel067(const float *u2_B0, float *wk15_B0)
{
    wk15_B0[OPS_ACC1(0,0,0)] = (rc8)*inv_0*(8*u2_B0[OPS_ACC0(0,1,0)] - 8*u2_B0[OPS_ACC0(0,-1,0)] +
      u2_B0[OPS_ACC0(0,-2,0)] - u2_B0[OPS_ACC0(0,2,0)]);

}

void opensbliblock00Kernel068(const float *T_B0, float *wk16_B0)
{
    wk16_B0[OPS_ACC1(0,0,0)] = -rc8*inv_5*(T_B0[OPS_ACC0(0,0,2)] - 16*T_B0[OPS_ACC0(0,0,1)] - 16*T_B0[OPS_ACC0(0,0,-1)]
      + T_B0[OPS_ACC0(0,0,-2)] + 30*T_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel070(const float *T_B0, float *wk18_B0)
{
    wk18_B0[OPS_ACC1(0,0,0)] = -rc8*inv_3*(-16*T_B0[OPS_ACC0(0,-1,0)] + T_B0[OPS_ACC0(0,-2,0)] + T_B0[OPS_ACC0(0,2,0)] -
      16*T_B0[OPS_ACC0(0,1,0)] + 30*T_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel073(const float *u2_B0, float *wk21_B0)
{
    wk21_B0[OPS_ACC1(0,0,0)] = -rc8*inv_3*(-16*u2_B0[OPS_ACC0(0,-1,0)] + u2_B0[OPS_ACC0(0,-2,0)] +
      u2_B0[OPS_ACC0(0,2,0)] - 16*u2_B0[OPS_ACC0(0,1,0)] + 30*u2_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel074(const float *u1_B0, float *wk22_B0)
{
    wk22_B0[OPS_ACC1(0,0,0)] = -rc8*inv_5*(u1_B0[OPS_ACC0(0,0,2)] - 16*u1_B0[OPS_ACC0(0,0,1)] -
      16*u1_B0[OPS_ACC0(0,0,-1)] + u1_B0[OPS_ACC0(0,0,-2)] + 30*u1_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel076(const float *u2_B0, float *wk24_B0)
{
    wk24_B0[OPS_ACC1(0,0,0)] = (rc8)*inv_1*(8*u2_B0[OPS_ACC0(1,0,0)] + u2_B0[OPS_ACC0(-2,0,0)] -
      8*u2_B0[OPS_ACC0(-1,0,0)] - u2_B0[OPS_ACC0(2,0,0)]);

}

void opensbliblock00Kernel077(const float *T_B0, float *wk25_B0)
{
    wk25_B0[OPS_ACC1(0,0,0)] = -rc8*inv_4*(-16*T_B0[OPS_ACC0(-1,0,0)] + T_B0[OPS_ACC0(-2,0,0)] + T_B0[OPS_ACC0(2,0,0)] -
      16*T_B0[OPS_ACC0(1,0,0)] + 30*T_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel078(const float *u0_B0, float *wk26_B0)
{
    wk26_B0[OPS_ACC1(0,0,0)] = -rc8*inv_2*(u0_B0[OPS_ACC0(0,0,2)] - 8*u0_B0[OPS_ACC0(0,0,1)] - u0_B0[OPS_ACC0(0,0,-2)] +
      8*u0_B0[OPS_ACC0(0,0,-1)]);

}

void opensbliblock00Kernel054(const float *wk6_B0, float *wk2_B0)
{
    wk2_B0[OPS_ACC1(0,0,0)] = (rc8)*inv_0*(8*wk6_B0[OPS_ACC0(0,1,0)] - 8*wk6_B0[OPS_ACC0(0,-1,0)] +
      wk6_B0[OPS_ACC0(0,-2,0)] - wk6_B0[OPS_ACC0(0,2,0)]);

}

void opensbliblock00Kernel064(const float *wk6_B0, float *wk12_B0)
{
    wk12_B0[OPS_ACC1(0,0,0)] = (rc8)*inv_2*(wk6_B0[OPS_ACC0(0,0,-2)] - 8*wk6_B0[OPS_ACC0(0,0,-1)] +
      8*wk6_B0[OPS_ACC0(0,0,1)] - wk6_B0[OPS_ACC0(0,0,2)]);

}

void opensbliblock00Kernel069(const float *wk24_B0, float *wk17_B0)
{
    wk17_B0[OPS_ACC1(0,0,0)] = (rc8)*inv_2*(wk24_B0[OPS_ACC0(0,0,-2)] - 8*wk24_B0[OPS_ACC0(0,0,-1)] +
      8*wk24_B0[OPS_ACC0(0,0,1)] - wk24_B0[OPS_ACC0(0,0,2)]);

}

void opensbliblock00Kernel071(const float *wk15_B0, float *wk19_B0)
{
    wk19_B0[OPS_ACC1(0,0,0)] = -rc8*inv_2*(-wk15_B0[OPS_ACC0(0,0,-2)] - 8*wk15_B0[OPS_ACC0(0,0,1)] +
      wk15_B0[OPS_ACC0(0,0,2)] + 8*wk15_B0[OPS_ACC0(0,0,-1)]);

}

void opensbliblock00Kernel072(const float *wk1_B0, float *wk20_B0)
{
    wk20_B0[OPS_ACC1(0,0,0)] = -rc8*inv_2*(-wk1_B0[OPS_ACC0(0,0,-2)] + wk1_B0[OPS_ACC0(0,0,2)] +
      8*wk1_B0[OPS_ACC0(0,0,-1)] - 8*wk1_B0[OPS_ACC0(0,0,1)]);

}

void opensbliblock00Kernel075(const float *wk9_B0, float *wk23_B0)
{
    wk23_B0[OPS_ACC1(0,0,0)] = (rc8)*inv_0*(8*wk9_B0[OPS_ACC0(0,1,0)] - 8*wk9_B0[OPS_ACC0(0,-1,0)] +
      wk9_B0[OPS_ACC0(0,-2,0)] - wk9_B0[OPS_ACC0(0,2,0)]);

}

 void opensbliblock00Kernel080(const float *wk10_B0, const float *wk11_B0, const float *u0_B0, const float *wk25_B0,
const float *wk16_B0, const float *wk9_B0, const float *u1_B0, const float *wk6_B0, const float *wk21_B0, const
float *wk26_B0, const float *wk24_B0, const float *wk5_B0, const float *wk3_B0, const float *wk1_B0, const float
*u2_B0, const float *wk13_B0, const float *wk20_B0, const float *wk18_B0, const float *wk22_B0, const float
*wk23_B0, const float *wk17_B0, const float *wk15_B0, const float *wk12_B0, const float *wk4_B0, const float
*wk0_B0, const float *wk19_B0, const float *wk7_B0, const float *wk8_B0, const float *wk2_B0, const float *wk14_B0,
float *Residual4_B0, float *Residual3_B0, float *Residual1_B0, float *Residual2_B0)
{
    Residual1_B0[OPS_ACC32(0,0,0)] = 1.0f*rcinv9*((rc10)*wk14_B0[OPS_ACC29(0,0,0)] + (rc11)*wk17_B0[OPS_ACC20(0,0,0)] +
      (rc11)*wk23_B0[OPS_ACC19(0,0,0)] + wk4_B0[OPS_ACC23(0,0,0)] + wk8_B0[OPS_ACC27(0,0,0)]) +
      Residual1_B0[OPS_ACC32(0,0,0)];

    Residual2_B0[OPS_ACC33(0,0,0)] = 1.0f*rcinv9*((rc10)*wk0_B0[OPS_ACC24(0,0,0)] + (rc11)*wk19_B0[OPS_ACC25(0,0,0)] +
      wk22_B0[OPS_ACC18(0,0,0)] + (rc11)*wk2_B0[OPS_ACC28(0,0,0)] + wk5_B0[OPS_ACC11(0,0,0)]) +
      Residual2_B0[OPS_ACC33(0,0,0)];

    Residual3_B0[OPS_ACC31(0,0,0)] = 1.0f*rcinv9*((rc11)*wk12_B0[OPS_ACC22(0,0,0)] + wk13_B0[OPS_ACC15(0,0,0)] +
      (rc11)*wk20_B0[OPS_ACC16(0,0,0)] + wk21_B0[OPS_ACC8(0,0,0)] + (rc10)*wk7_B0[OPS_ACC26(0,0,0)]) +
      Residual3_B0[OPS_ACC31(0,0,0)];

    Residual4_B0[OPS_ACC30(0,0,0)] = 1.0f*rcinv12*rcinv13*rcinv14*rcinv9*(wk16_B0[OPS_ACC4(0,0,0)] +
      wk18_B0[OPS_ACC17(0,0,0)] + wk25_B0[OPS_ACC3(0,0,0)]) + 1.0f*rcinv9*(wk11_B0[OPS_ACC1(0,0,0)] +
      wk15_B0[OPS_ACC21(0,0,0)])*wk11_B0[OPS_ACC1(0,0,0)] + 1.0f*rcinv9*(wk11_B0[OPS_ACC1(0,0,0)] +
      wk15_B0[OPS_ACC21(0,0,0)])*wk15_B0[OPS_ACC21(0,0,0)] + 1.0f*rcinv9*(wk24_B0[OPS_ACC10(0,0,0)] +
      wk26_B0[OPS_ACC9(0,0,0)])*wk24_B0[OPS_ACC10(0,0,0)] + 1.0f*rcinv9*(wk24_B0[OPS_ACC10(0,0,0)] +
      wk26_B0[OPS_ACC9(0,0,0)])*wk26_B0[OPS_ACC9(0,0,0)] + 1.0f*rcinv9*(wk3_B0[OPS_ACC12(0,0,0)] +
      wk9_B0[OPS_ACC5(0,0,0)])*wk3_B0[OPS_ACC12(0,0,0)] + 1.0f*rcinv9*(wk3_B0[OPS_ACC12(0,0,0)] +
      wk9_B0[OPS_ACC5(0,0,0)])*wk9_B0[OPS_ACC5(0,0,0)] + 1.0f*rcinv9*(-rc7*wk10_B0[OPS_ACC0(0,0,0)] -
      rc7*wk1_B0[OPS_ACC13(0,0,0)] + (rc10)*wk6_B0[OPS_ACC7(0,0,0)])*wk6_B0[OPS_ACC7(0,0,0)] +
      1.0f*rcinv9*(-rc7*wk10_B0[OPS_ACC0(0,0,0)] + (rc10)*wk1_B0[OPS_ACC13(0,0,0)] -
      rc7*wk6_B0[OPS_ACC7(0,0,0)])*wk1_B0[OPS_ACC13(0,0,0)] + 1.0f*rcinv9*((rc10)*wk10_B0[OPS_ACC0(0,0,0)] -
      rc7*wk1_B0[OPS_ACC13(0,0,0)] - rc7*wk6_B0[OPS_ACC7(0,0,0)])*wk10_B0[OPS_ACC0(0,0,0)] +
      1.0f*rcinv9*((rc10)*wk0_B0[OPS_ACC24(0,0,0)] + (rc11)*wk19_B0[OPS_ACC25(0,0,0)] + wk22_B0[OPS_ACC18(0,0,0)] +
      (rc11)*wk2_B0[OPS_ACC28(0,0,0)] + wk5_B0[OPS_ACC11(0,0,0)])*u1_B0[OPS_ACC6(0,0,0)] +
      1.0f*rcinv9*((rc11)*wk12_B0[OPS_ACC22(0,0,0)] + wk13_B0[OPS_ACC15(0,0,0)] + (rc11)*wk20_B0[OPS_ACC16(0,0,0)] +
      wk21_B0[OPS_ACC8(0,0,0)] + (rc10)*wk7_B0[OPS_ACC26(0,0,0)])*u2_B0[OPS_ACC14(0,0,0)] +
      1.0f*rcinv9*((rc10)*wk14_B0[OPS_ACC29(0,0,0)] + (rc11)*wk17_B0[OPS_ACC20(0,0,0)] + (rc11)*wk23_B0[OPS_ACC19(0,0,0)]
      + wk4_B0[OPS_ACC23(0,0,0)] + wk8_B0[OPS_ACC27(0,0,0)])*u0_B0[OPS_ACC2(0,0,0)] + Residual4_B0[OPS_ACC30(0,0,0)];

}

 void opensbliblock00Kernel090(const float *rho_RKold_B0, const float *Residual0_B0, const float *rhou2_RKold_B0,
const float *Residual3_B0, const float *Residual4_B0, const float *Residual2_B0, const float *Residual1_B0, const
float *rhoE_RKold_B0, const float *rhou0_RKold_B0, const float *rhou1_RKold_B0, float *rhoE_B0, float *rhou0_B0,
float *rho_B0, float *rhou1_B0, float *rhou2_B0, const float *rknew)
{
   rho_B0[OPS_ACC12(0,0,0)] = dt*rknew[0]*Residual0_B0[OPS_ACC1(0,0,0)] + rho_RKold_B0[OPS_ACC0(0,0,0)];

   rhou0_B0[OPS_ACC11(0,0,0)] = dt*rknew[0]*Residual1_B0[OPS_ACC6(0,0,0)] + rhou0_RKold_B0[OPS_ACC8(0,0,0)];

   rhou1_B0[OPS_ACC13(0,0,0)] = dt*rknew[0]*Residual2_B0[OPS_ACC5(0,0,0)] + rhou1_RKold_B0[OPS_ACC9(0,0,0)];

   rhou2_B0[OPS_ACC14(0,0,0)] = dt*rknew[0]*Residual3_B0[OPS_ACC3(0,0,0)] + rhou2_RKold_B0[OPS_ACC2(0,0,0)];

   rhoE_B0[OPS_ACC10(0,0,0)] = dt*rknew[0]*Residual4_B0[OPS_ACC4(0,0,0)] + rhoE_RKold_B0[OPS_ACC7(0,0,0)];

}

 void opensbliblock00Kernel089(const float *Residual0_B0, const float *Residual4_B0, const float *Residual3_B0, const
float *Residual2_B0, const float *Residual1_B0, float *rho_RKold_B0, float *rhou2_RKold_B0, float *rhoE_RKold_B0,
float *rhou0_RKold_B0, float *rhou1_RKold_B0, const float *rkold)
{
   rho_RKold_B0[OPS_ACC5(0,0,0)] = dt*rkold[0]*Residual0_B0[OPS_ACC0(0,0,0)] + rho_RKold_B0[OPS_ACC5(0,0,0)];

   rhou0_RKold_B0[OPS_ACC8(0,0,0)] = dt*rkold[0]*Residual1_B0[OPS_ACC4(0,0,0)] + rhou0_RKold_B0[OPS_ACC8(0,0,0)];

   rhou1_RKold_B0[OPS_ACC9(0,0,0)] = dt*rkold[0]*Residual2_B0[OPS_ACC3(0,0,0)] + rhou1_RKold_B0[OPS_ACC9(0,0,0)];

   rhou2_RKold_B0[OPS_ACC6(0,0,0)] = dt*rkold[0]*Residual3_B0[OPS_ACC2(0,0,0)] + rhou2_RKold_B0[OPS_ACC6(0,0,0)];

   rhoE_RKold_B0[OPS_ACC7(0,0,0)] = dt*rkold[0]*Residual4_B0[OPS_ACC1(0,0,0)] + rhoE_RKold_B0[OPS_ACC7(0,0,0)];

}

#endif
