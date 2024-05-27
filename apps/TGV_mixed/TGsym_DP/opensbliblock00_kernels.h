#ifndef OPENSBLIBLOCK00_KERNEL_H
#define OPENSBLIBLOCK00_KERNEL_H
 void opensbliblock00Kernel087(ACC<double> &rhoE_B0, ACC<double> &rho_B0, ACC<double> &rhou0_B0, ACC<double> &rhou1_B0,
ACC<double> &rhou2_B0, const int *idx)
{
   double p = 0.0;
   double r = 0.0;
   double u0 = 0.0;
   double u1 = 0.0;
   double u2 = 0.0;
   double x0 = 0.0;
   double x1 = 0.0;
   double x2 = 0.0;
   x0 = Delta0block0*idx[0];

   x1 = Delta1block0*idx[1];

   x2 = Delta2block0*idx[2];

   u0 = cos(x1)*cos(x2)*sin(x0);

   u1 = -cos(x0)*cos(x2)*sin(x1);

   u2 = 0.0;

   p = (2.0 + cos(2.0*x2))*(0.0625*cos(2.0*x0) + 0.0625*cos(2.0*x1)) + 1.0/((Minf*Minf)*gama);

   r = gama*p*(Minf*Minf);

   rho_B0(0,0,0) = r;

   rhou0_B0(0,0,0) = r*u0;

   rhou1_B0(0,0,0) = r*u1;

   rhou2_B0(0,0,0) = r*u2;

   rhoE_B0(0,0,0) = p/(-1 + gama) + 0.5*r*((u0*u0) + (u1*u1) + (u2*u2));

}

 void opensbliblock00Kernel081(ACC<double> &rhoE_B0, ACC<double> &rho_B0, ACC<double> &rhou0_B0, ACC<double> &rhou1_B0,
ACC<double> &rhou2_B0)
{
   rho_B0(-1,0,0) = rho_B0(1,0,0);

   rhou0_B0(-1,0,0) = -1.0*rhou0_B0(1,0,0);

   rhou1_B0(-1,0,0) = rhou1_B0(1,0,0);

   rhou2_B0(-1,0,0) = rhou2_B0(1,0,0);

   rhoE_B0(-1,0,0) = rhoE_B0(1,0,0);

   rho_B0(-2,0,0) = rho_B0(2,0,0);

   rhou0_B0(-2,0,0) = -1.0*rhou0_B0(2,0,0);

   rhou1_B0(-2,0,0) = rhou1_B0(2,0,0);

   rhou2_B0(-2,0,0) = rhou2_B0(2,0,0);

   rhoE_B0(-2,0,0) = rhoE_B0(2,0,0);

}

 void opensbliblock00Kernel082(ACC<double> &rhoE_B0, ACC<double> &rho_B0, ACC<double> &rhou0_B0, ACC<double> &rhou1_B0,
ACC<double> &rhou2_B0)
{
   rho_B0(1,0,0) = rho_B0(-1,0,0);

   rhou0_B0(1,0,0) = -1.0*rhou0_B0(-1,0,0);

   rhou1_B0(1,0,0) = rhou1_B0(-1,0,0);

   rhou2_B0(1,0,0) = rhou2_B0(-1,0,0);

   rhoE_B0(1,0,0) = rhoE_B0(-1,0,0);

   rho_B0(2,0,0) = rho_B0(-2,0,0);

   rhou0_B0(2,0,0) = -1.0*rhou0_B0(-2,0,0);

   rhou1_B0(2,0,0) = rhou1_B0(-2,0,0);

   rhou2_B0(2,0,0) = rhou2_B0(-2,0,0);

   rhoE_B0(2,0,0) = rhoE_B0(-2,0,0);

}

 void opensbliblock00Kernel083(ACC<double> &rhoE_B0, ACC<double> &rho_B0, ACC<double> &rhou0_B0, ACC<double> &rhou1_B0,
ACC<double> &rhou2_B0)
{
   rho_B0(0,-1,0) = rho_B0(0,1,0);

   rhou0_B0(0,-1,0) = rhou0_B0(0,1,0);

   rhou1_B0(0,-1,0) = -1.0*rhou1_B0(0,1,0);

   rhou2_B0(0,-1,0) = rhou2_B0(0,1,0);

   rhoE_B0(0,-1,0) = rhoE_B0(0,1,0);

   rho_B0(0,-2,0) = rho_B0(0,2,0);

   rhou0_B0(0,-2,0) = rhou0_B0(0,2,0);

   rhou1_B0(0,-2,0) = -1.0*rhou1_B0(0,2,0);

   rhou2_B0(0,-2,0) = rhou2_B0(0,2,0);

   rhoE_B0(0,-2,0) = rhoE_B0(0,2,0);

}

 void opensbliblock00Kernel084(ACC<double> &rhoE_B0, ACC<double> &rho_B0, ACC<double> &rhou0_B0, ACC<double> &rhou1_B0,
ACC<double> &rhou2_B0)
{
   rho_B0(0,1,0) = rho_B0(0,-1,0);

   rhou0_B0(0,1,0) = rhou0_B0(0,-1,0);

   rhou1_B0(0,1,0) = -1.0*rhou1_B0(0,-1,0);

   rhou2_B0(0,1,0) = rhou2_B0(0,-1,0);

   rhoE_B0(0,1,0) = rhoE_B0(0,-1,0);

   rho_B0(0,2,0) = rho_B0(0,-2,0);

   rhou0_B0(0,2,0) = rhou0_B0(0,-2,0);

   rhou1_B0(0,2,0) = -1.0*rhou1_B0(0,-2,0);

   rhou2_B0(0,2,0) = rhou2_B0(0,-2,0);

   rhoE_B0(0,2,0) = rhoE_B0(0,-2,0);

}

 void opensbliblock00Kernel085(ACC<double> &rhoE_B0, ACC<double> &rho_B0, ACC<double> &rhou0_B0, ACC<double> &rhou1_B0,
ACC<double> &rhou2_B0)
{
   rho_B0(0,0,-1) = rho_B0(0,0,1);

   rhou0_B0(0,0,-1) = rhou0_B0(0,0,1);

   rhou1_B0(0,0,-1) = rhou1_B0(0,0,1);

   rhou2_B0(0,0,-1) = -1.0*rhou2_B0(0,0,1);

   rhoE_B0(0,0,-1) = rhoE_B0(0,0,1);

   rho_B0(0,0,-2) = rho_B0(0,0,2);

   rhou0_B0(0,0,-2) = rhou0_B0(0,0,2);

   rhou1_B0(0,0,-2) = rhou1_B0(0,0,2);

   rhou2_B0(0,0,-2) = -1.0*rhou2_B0(0,0,2);

   rhoE_B0(0,0,-2) = rhoE_B0(0,0,2);

}

 void opensbliblock00Kernel086(ACC<double> &rhoE_B0, ACC<double> &rho_B0, ACC<double> &rhou0_B0, ACC<double> &rhou1_B0,
ACC<double> &rhou2_B0)
{
   rho_B0(0,0,1) = rho_B0(0,0,-1);

   rhou0_B0(0,0,1) = rhou0_B0(0,0,-1);

   rhou1_B0(0,0,1) = rhou1_B0(0,0,-1);

   rhou2_B0(0,0,1) = -1.0*rhou2_B0(0,0,-1);

   rhoE_B0(0,0,1) = rhoE_B0(0,0,-1);

   rho_B0(0,0,2) = rho_B0(0,0,-2);

   rhou0_B0(0,0,2) = rhou0_B0(0,0,-2);

   rhou1_B0(0,0,2) = rhou1_B0(0,0,-2);

   rhou2_B0(0,0,2) = -1.0*rhou2_B0(0,0,-2);

   rhoE_B0(0,0,2) = rhoE_B0(0,0,-2);

}

 void opensbliblock00Kernel088(const ACC<double> &rhoE_B0, const ACC<double> &rho_B0, const ACC<double> &rhou0_B0, const
ACC<double> &rhou1_B0, const ACC<double> &rhou2_B0, ACC<double> &rhoE_RKold_B0, ACC<double> &rho_RKold_B0, ACC<double>
&rhou0_RKold_B0, ACC<double> &rhou1_RKold_B0, ACC<double> &rhou2_RKold_B0)
{
   rho_RKold_B0(0,0,0) = rho_B0(0,0,0);

   rhou0_RKold_B0(0,0,0) = rhou0_B0(0,0,0);

   rhou1_RKold_B0(0,0,0) = rhou1_B0(0,0,0);

   rhou2_RKold_B0(0,0,0) = rhou2_B0(0,0,0);

   rhoE_RKold_B0(0,0,0) = rhoE_B0(0,0,0);

}

void opensbliblock00Kernel002(const ACC<double> &rho_B0, const ACC<double> &rhou0_B0, ACC<double> &u0_B0)
{
   u0_B0(0,0,0) = rhou0_B0(0,0,0)/rho_B0(0,0,0);

}

void opensbliblock00Kernel024(const ACC<double> &rho_B0, const ACC<double> &rhou1_B0, ACC<double> &u1_B0)
{
   u1_B0(0,0,0) = rhou1_B0(0,0,0)/rho_B0(0,0,0);

}

void opensbliblock00Kernel037(const ACC<double> &rho_B0, const ACC<double> &rhou2_B0, ACC<double> &u2_B0)
{
   u2_B0(0,0,0) = rhou2_B0(0,0,0)/rho_B0(0,0,0);

}

 void opensbliblock00Kernel008(const ACC<double> &rhoE_B0, const ACC<double> &rho_B0, const ACC<double> &u0_B0, const
ACC<double> &u1_B0, const ACC<double> &u2_B0, ACC<double> &p_B0)
{
    p_B0(0,0,0) = (-1 + gama)*(-(1.0/2.0)*(u0_B0(0,0,0)*u0_B0(0,0,0))*rho_B0(0,0,0) -
      (1.0/2.0)*(u1_B0(0,0,0)*u1_B0(0,0,0))*rho_B0(0,0,0) - (1.0/2.0)*(u2_B0(0,0,0)*u2_B0(0,0,0))*rho_B0(0,0,0) +
      rhoE_B0(0,0,0));

}

void opensbliblock00Kernel079(const ACC<double> &p_B0, const ACC<double> &rho_B0, ACC<double> &T_B0)
{
   T_B0(0,0,0) = (Minf*Minf)*gama*p_B0(0,0,0)/rho_B0(0,0,0);

}

 void opensbliblock00Kernel000(const ACC<double> &p_B0, const ACC<double> &rhoE_B0, const ACC<double> &rho_B0, const
ACC<double> &rhou0_B0, const ACC<double> &rhou1_B0, const ACC<double> &rhou2_B0, const ACC<double> &u0_B0, ACC<double>
&wk39_B0, ACC<double> &wk40_B0, ACC<double> &wk41_B0, ACC<double> &wk42_B0, ACC<double> &wk43_B0, ACC<double>
&wk44_B0)
{
   wk39_B0(0,0,0) = u0_B0(0,0,0)*rhou1_B0(0,0,0);

   wk40_B0(0,0,0) = u0_B0(0,0,0)*rhou2_B0(0,0,0);

   wk41_B0(0,0,0) = u0_B0(0,0,0)*rhoE_B0(0,0,0);

   wk42_B0(0,0,0) = p_B0(0,0,0)*u0_B0(0,0,0);

   wk43_B0(0,0,0) = u0_B0(0,0,0)*rho_B0(0,0,0);

   wk44_B0(0,0,0) = u0_B0(0,0,0)*rhou0_B0(0,0,0);

}

void opensbliblock00Kernel003(const ACC<double> &wk39_B0, ACC<double> &wk0_B0)
{
    wk0_B0(0,0,0) = (-(2.0/3.0)*wk39_B0(-1,0,0) - (1.0/12.0)*wk39_B0(2,0,0) + ((1.0/12.0))*wk39_B0(-2,0,0) +
      ((2.0/3.0))*wk39_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel005(const ACC<double> &rhou0_B0, ACC<double> &wk1_B0)
{
    wk1_B0(0,0,0) = (-(2.0/3.0)*rhou0_B0(-1,0,0) - (1.0/12.0)*rhou0_B0(2,0,0) + ((1.0/12.0))*rhou0_B0(-2,0,0) +
      ((2.0/3.0))*rhou0_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel007(const ACC<double> &wk40_B0, ACC<double> &wk2_B0)
{
    wk2_B0(0,0,0) = (-(2.0/3.0)*wk40_B0(-1,0,0) - (1.0/12.0)*wk40_B0(2,0,0) + ((1.0/12.0))*wk40_B0(-2,0,0) +
      ((2.0/3.0))*wk40_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel009(const ACC<double> &p_B0, ACC<double> &wk3_B0)
{
    wk3_B0(0,0,0) = (-(2.0/3.0)*p_B0(-1,0,0) - (1.0/12.0)*p_B0(2,0,0) + ((1.0/12.0))*p_B0(-2,0,0) +
      ((2.0/3.0))*p_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel011(const ACC<double> &wk41_B0, ACC<double> &wk4_B0)
{
    wk4_B0(0,0,0) = (-(2.0/3.0)*wk41_B0(-1,0,0) - (1.0/12.0)*wk41_B0(2,0,0) + ((1.0/12.0))*wk41_B0(-2,0,0) +
      ((2.0/3.0))*wk41_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel012(const ACC<double> &rhoE_B0, ACC<double> &wk5_B0)
{
    wk5_B0(0,0,0) = (-(2.0/3.0)*rhoE_B0(-1,0,0) - (1.0/12.0)*rhoE_B0(2,0,0) + ((1.0/12.0))*rhoE_B0(-2,0,0) +
      ((2.0/3.0))*rhoE_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel013(const ACC<double> &rhou1_B0, ACC<double> &wk6_B0)
{
    wk6_B0(0,0,0) = (-(2.0/3.0)*rhou1_B0(-1,0,0) - (1.0/12.0)*rhou1_B0(2,0,0) + ((1.0/12.0))*rhou1_B0(-2,0,0) +
      ((2.0/3.0))*rhou1_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel014(const ACC<double> &wk42_B0, ACC<double> &wk7_B0)
{
    wk7_B0(0,0,0) = (-(2.0/3.0)*wk42_B0(-1,0,0) - (1.0/12.0)*wk42_B0(2,0,0) + ((1.0/12.0))*wk42_B0(-2,0,0) +
      ((2.0/3.0))*wk42_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel016(const ACC<double> &wk43_B0, ACC<double> &wk8_B0)
{
    wk8_B0(0,0,0) = (-(2.0/3.0)*wk43_B0(-1,0,0) - (1.0/12.0)*wk43_B0(2,0,0) + ((1.0/12.0))*wk43_B0(-2,0,0) +
      ((2.0/3.0))*wk43_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel017(const ACC<double> &u0_B0, ACC<double> &wk9_B0)
{
    wk9_B0(0,0,0) = (-(2.0/3.0)*u0_B0(-1,0,0) - (1.0/12.0)*u0_B0(2,0,0) + ((1.0/12.0))*u0_B0(-2,0,0) +
      ((2.0/3.0))*u0_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel018(const ACC<double> &rhou2_B0, ACC<double> &wk10_B0)
{
    wk10_B0(0,0,0) = (-(2.0/3.0)*rhou2_B0(-1,0,0) - (1.0/12.0)*rhou2_B0(2,0,0) + ((1.0/12.0))*rhou2_B0(-2,0,0) +
      ((2.0/3.0))*rhou2_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel019(const ACC<double> &wk44_B0, ACC<double> &wk11_B0)
{
    wk11_B0(0,0,0) = (-(2.0/3.0)*wk44_B0(-1,0,0) - (1.0/12.0)*wk44_B0(2,0,0) + ((1.0/12.0))*wk44_B0(-2,0,0) +
      ((2.0/3.0))*wk44_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel020(const ACC<double> &rho_B0, ACC<double> &wk12_B0)
{
    wk12_B0(0,0,0) = (-(2.0/3.0)*rho_B0(-1,0,0) - (1.0/12.0)*rho_B0(2,0,0) + ((1.0/12.0))*rho_B0(-2,0,0) +
      ((2.0/3.0))*rho_B0(1,0,0))*invDelta0block0;

}

 void opensbliblock00Kernel021(const ACC<double> &p_B0, const ACC<double> &rhoE_B0, const ACC<double> &rho_B0, const
ACC<double> &rhou0_B0, const ACC<double> &rhou1_B0, const ACC<double> &rhou2_B0, const ACC<double> &u1_B0, ACC<double>
&wk39_B0, ACC<double> &wk40_B0, ACC<double> &wk41_B0, ACC<double> &wk42_B0, ACC<double> &wk43_B0, ACC<double>
&wk44_B0)
{
   wk39_B0(0,0,0) = u1_B0(0,0,0)*rhou1_B0(0,0,0);

   wk40_B0(0,0,0) = u1_B0(0,0,0)*rho_B0(0,0,0);

   wk41_B0(0,0,0) = u1_B0(0,0,0)*rhou0_B0(0,0,0);

   wk42_B0(0,0,0) = p_B0(0,0,0)*u1_B0(0,0,0);

   wk43_B0(0,0,0) = u1_B0(0,0,0)*rhoE_B0(0,0,0);

   wk44_B0(0,0,0) = u1_B0(0,0,0)*rhou2_B0(0,0,0);

}

void opensbliblock00Kernel022(const ACC<double> &rhou1_B0, ACC<double> &wk13_B0)
{
    wk13_B0(0,0,0) = (-(2.0/3.0)*rhou1_B0(0,-1,0) - (1.0/12.0)*rhou1_B0(0,2,0) + ((1.0/12.0))*rhou1_B0(0,-2,0) +
      ((2.0/3.0))*rhou1_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel023(const ACC<double> &rho_B0, ACC<double> &wk14_B0)
{
    wk14_B0(0,0,0) = (-(2.0/3.0)*rho_B0(0,-1,0) - (1.0/12.0)*rho_B0(0,2,0) + ((1.0/12.0))*rho_B0(0,-2,0) +
      ((2.0/3.0))*rho_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel025(const ACC<double> &wk39_B0, ACC<double> &wk15_B0)
{
    wk15_B0(0,0,0) = (-(2.0/3.0)*wk39_B0(0,-1,0) - (1.0/12.0)*wk39_B0(0,2,0) + ((1.0/12.0))*wk39_B0(0,-2,0) +
      ((2.0/3.0))*wk39_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel026(const ACC<double> &wk40_B0, ACC<double> &wk16_B0)
{
    wk16_B0(0,0,0) = (-(2.0/3.0)*wk40_B0(0,-1,0) - (1.0/12.0)*wk40_B0(0,2,0) + ((1.0/12.0))*wk40_B0(0,-2,0) +
      ((2.0/3.0))*wk40_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel027(const ACC<double> &rhou2_B0, ACC<double> &wk17_B0)
{
    wk17_B0(0,0,0) = (-(2.0/3.0)*rhou2_B0(0,-1,0) - (1.0/12.0)*rhou2_B0(0,2,0) + ((1.0/12.0))*rhou2_B0(0,-2,0) +
      ((2.0/3.0))*rhou2_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel028(const ACC<double> &p_B0, ACC<double> &wk18_B0)
{
    wk18_B0(0,0,0) = (-(2.0/3.0)*p_B0(0,-1,0) - (1.0/12.0)*p_B0(0,2,0) + ((1.0/12.0))*p_B0(0,-2,0) +
      ((2.0/3.0))*p_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel029(const ACC<double> &wk41_B0, ACC<double> &wk19_B0)
{
    wk19_B0(0,0,0) = (-(2.0/3.0)*wk41_B0(0,-1,0) - (1.0/12.0)*wk41_B0(0,2,0) + ((1.0/12.0))*wk41_B0(0,-2,0) +
      ((2.0/3.0))*wk41_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel030(const ACC<double> &rhoE_B0, ACC<double> &wk20_B0)
{
    wk20_B0(0,0,0) = (-(2.0/3.0)*rhoE_B0(0,-1,0) - (1.0/12.0)*rhoE_B0(0,2,0) + ((1.0/12.0))*rhoE_B0(0,-2,0) +
      ((2.0/3.0))*rhoE_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel031(const ACC<double> &rhou0_B0, ACC<double> &wk21_B0)
{
    wk21_B0(0,0,0) = (-(2.0/3.0)*rhou0_B0(0,-1,0) - (1.0/12.0)*rhou0_B0(0,2,0) + ((1.0/12.0))*rhou0_B0(0,-2,0) +
      ((2.0/3.0))*rhou0_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel032(const ACC<double> &wk42_B0, ACC<double> &wk22_B0)
{
    wk22_B0(0,0,0) = (-(2.0/3.0)*wk42_B0(0,-1,0) - (1.0/12.0)*wk42_B0(0,2,0) + ((1.0/12.0))*wk42_B0(0,-2,0) +
      ((2.0/3.0))*wk42_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel033(const ACC<double> &u1_B0, ACC<double> &wk23_B0)
{
    wk23_B0(0,0,0) = (-(2.0/3.0)*u1_B0(0,-1,0) - (1.0/12.0)*u1_B0(0,2,0) + ((1.0/12.0))*u1_B0(0,-2,0) +
      ((2.0/3.0))*u1_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel034(const ACC<double> &wk43_B0, ACC<double> &wk24_B0)
{
    wk24_B0(0,0,0) = (-(2.0/3.0)*wk43_B0(0,-1,0) - (1.0/12.0)*wk43_B0(0,2,0) + ((1.0/12.0))*wk43_B0(0,-2,0) +
      ((2.0/3.0))*wk43_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel035(const ACC<double> &wk44_B0, ACC<double> &wk25_B0)
{
    wk25_B0(0,0,0) = (-(2.0/3.0)*wk44_B0(0,-1,0) - (1.0/12.0)*wk44_B0(0,2,0) + ((1.0/12.0))*wk44_B0(0,-2,0) +
      ((2.0/3.0))*wk44_B0(0,1,0))*invDelta1block0;

}

 void opensbliblock00Kernel036(const ACC<double> &p_B0, const ACC<double> &rhoE_B0, const ACC<double> &rho_B0, const
ACC<double> &rhou0_B0, const ACC<double> &rhou1_B0, const ACC<double> &rhou2_B0, const ACC<double> &u2_B0, ACC<double>
&wk39_B0, ACC<double> &wk40_B0, ACC<double> &wk41_B0, ACC<double> &wk42_B0, ACC<double> &wk43_B0, ACC<double>
&wk44_B0)
{
   wk39_B0(0,0,0) = u2_B0(0,0,0)*rhou2_B0(0,0,0);

   wk40_B0(0,0,0) = u2_B0(0,0,0)*rhoE_B0(0,0,0);

   wk41_B0(0,0,0) = u2_B0(0,0,0)*rho_B0(0,0,0);

   wk42_B0(0,0,0) = u2_B0(0,0,0)*rhou0_B0(0,0,0);

   wk43_B0(0,0,0) = p_B0(0,0,0)*u2_B0(0,0,0);

   wk44_B0(0,0,0) = u2_B0(0,0,0)*rhou1_B0(0,0,0);

}

void opensbliblock00Kernel038(const ACC<double> &wk39_B0, ACC<double> &wk26_B0)
{
    wk26_B0(0,0,0) = (-(2.0/3.0)*wk39_B0(0,0,-1) - (1.0/12.0)*wk39_B0(0,0,2) + ((1.0/12.0))*wk39_B0(0,0,-2) +
      ((2.0/3.0))*wk39_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel039(const ACC<double> &rhoE_B0, ACC<double> &wk27_B0)
{
    wk27_B0(0,0,0) = (-(2.0/3.0)*rhoE_B0(0,0,-1) - (1.0/12.0)*rhoE_B0(0,0,2) + ((1.0/12.0))*rhoE_B0(0,0,-2) +
      ((2.0/3.0))*rhoE_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel040(const ACC<double> &wk40_B0, ACC<double> &wk28_B0)
{
    wk28_B0(0,0,0) = (-(2.0/3.0)*wk40_B0(0,0,-1) - (1.0/12.0)*wk40_B0(0,0,2) + ((1.0/12.0))*wk40_B0(0,0,-2) +
      ((2.0/3.0))*wk40_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel041(const ACC<double> &rhou0_B0, ACC<double> &wk29_B0)
{
    wk29_B0(0,0,0) = (-(2.0/3.0)*rhou0_B0(0,0,-1) - (1.0/12.0)*rhou0_B0(0,0,2) + ((1.0/12.0))*rhou0_B0(0,0,-2) +
      ((2.0/3.0))*rhou0_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel042(const ACC<double> &wk41_B0, ACC<double> &wk30_B0)
{
    wk30_B0(0,0,0) = (-(2.0/3.0)*wk41_B0(0,0,-1) - (1.0/12.0)*wk41_B0(0,0,2) + ((1.0/12.0))*wk41_B0(0,0,-2) +
      ((2.0/3.0))*wk41_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel043(const ACC<double> &wk42_B0, ACC<double> &wk31_B0)
{
    wk31_B0(0,0,0) = (-(2.0/3.0)*wk42_B0(0,0,-1) - (1.0/12.0)*wk42_B0(0,0,2) + ((1.0/12.0))*wk42_B0(0,0,-2) +
      ((2.0/3.0))*wk42_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel044(const ACC<double> &rhou1_B0, ACC<double> &wk32_B0)
{
    wk32_B0(0,0,0) = (-(2.0/3.0)*rhou1_B0(0,0,-1) - (1.0/12.0)*rhou1_B0(0,0,2) + ((1.0/12.0))*rhou1_B0(0,0,-2) +
      ((2.0/3.0))*rhou1_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel045(const ACC<double> &p_B0, ACC<double> &wk33_B0)
{
    wk33_B0(0,0,0) = (-(2.0/3.0)*p_B0(0,0,-1) - (1.0/12.0)*p_B0(0,0,2) + ((1.0/12.0))*p_B0(0,0,-2) +
      ((2.0/3.0))*p_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel046(const ACC<double> &rhou2_B0, ACC<double> &wk34_B0)
{
    wk34_B0(0,0,0) = (-(2.0/3.0)*rhou2_B0(0,0,-1) - (1.0/12.0)*rhou2_B0(0,0,2) + ((1.0/12.0))*rhou2_B0(0,0,-2) +
      ((2.0/3.0))*rhou2_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel047(const ACC<double> &wk43_B0, ACC<double> &wk35_B0)
{
    wk35_B0(0,0,0) = (-(2.0/3.0)*wk43_B0(0,0,-1) - (1.0/12.0)*wk43_B0(0,0,2) + ((1.0/12.0))*wk43_B0(0,0,-2) +
      ((2.0/3.0))*wk43_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel048(const ACC<double> &wk44_B0, ACC<double> &wk36_B0)
{
    wk36_B0(0,0,0) = (-(2.0/3.0)*wk44_B0(0,0,-1) - (1.0/12.0)*wk44_B0(0,0,2) + ((1.0/12.0))*wk44_B0(0,0,-2) +
      ((2.0/3.0))*wk44_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel049(const ACC<double> &rho_B0, ACC<double> &wk37_B0)
{
    wk37_B0(0,0,0) = (-(2.0/3.0)*rho_B0(0,0,-1) - (1.0/12.0)*rho_B0(0,0,2) + ((1.0/12.0))*rho_B0(0,0,-2) +
      ((2.0/3.0))*rho_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel050(const ACC<double> &u2_B0, ACC<double> &wk38_B0)
{
    wk38_B0(0,0,0) = (-(2.0/3.0)*u2_B0(0,0,-1) - (1.0/12.0)*u2_B0(0,0,2) + ((1.0/12.0))*u2_B0(0,0,-2) +
      ((2.0/3.0))*u2_B0(0,0,1))*invDelta2block0;

}

 void opensbliblock00Kernel051(const ACC<double> &rhoE_B0, const ACC<double> &rho_B0, const ACC<double> &rhou0_B0, const
ACC<double> &rhou1_B0, const ACC<double> &rhou2_B0, const ACC<double> &u0_B0, const ACC<double> &u1_B0, const
ACC<double> &u2_B0, const ACC<double> &wk0_B0, const ACC<double> &wk10_B0, const ACC<double> &wk11_B0, const ACC<double>
&wk12_B0, const ACC<double> &wk13_B0, const ACC<double> &wk14_B0, const ACC<double> &wk15_B0, const ACC<double>
&wk16_B0, const ACC<double> &wk17_B0, const ACC<double> &wk18_B0, const ACC<double> &wk19_B0, const ACC<double> &wk1_B0,
const ACC<double> &wk20_B0, const ACC<double> &wk21_B0, const ACC<double> &wk22_B0, const ACC<double> &wk23_B0, const
ACC<double> &wk24_B0, const ACC<double> &wk25_B0, const ACC<double> &wk26_B0, const ACC<double> &wk27_B0, const
ACC<double> &wk28_B0, const ACC<double> &wk29_B0, const ACC<double> &wk2_B0, const ACC<double> &wk30_B0, const
ACC<double> &wk31_B0, const ACC<double> &wk32_B0, const ACC<double> &wk33_B0, const ACC<double> &wk34_B0, const
ACC<double> &wk35_B0, const ACC<double> &wk36_B0, const ACC<double> &wk37_B0, const ACC<double> &wk38_B0, const
ACC<double> &wk3_B0, const ACC<double> &wk4_B0, const ACC<double> &wk5_B0, const ACC<double> &wk6_B0, const ACC<double>
&wk7_B0, const ACC<double> &wk8_B0, const ACC<double> &wk9_B0, ACC<double> &Residual0_B0, ACC<double> &Residual1_B0,
ACC<double> &Residual2_B0, ACC<double> &Residual3_B0, ACC<double> &Residual4_B0)
{
    Residual0_B0(0,0,0) = -(1.0/2.0)*wk8_B0(0,0,0) - (1.0/2.0)*wk16_B0(0,0,0) - (1.0/2.0)*wk30_B0(0,0,0) -
      (1.0/2.0)*(wk9_B0(0,0,0) + wk23_B0(0,0,0) + wk38_B0(0,0,0))*rho_B0(0,0,0) - (1.0/2.0)*u0_B0(0,0,0)*wk12_B0(0,0,0)
      - (1.0/2.0)*u1_B0(0,0,0)*wk14_B0(0,0,0) - (1.0/2.0)*u2_B0(0,0,0)*wk37_B0(0,0,0);

    Residual1_B0(0,0,0) = -wk3_B0(0,0,0) - (1.0/2.0)*wk11_B0(0,0,0) - (1.0/2.0)*wk19_B0(0,0,0) -
      (1.0/2.0)*wk31_B0(0,0,0) - (1.0/2.0)*(wk9_B0(0,0,0) + wk23_B0(0,0,0) + wk38_B0(0,0,0))*rhou0_B0(0,0,0) -
      (1.0/2.0)*u0_B0(0,0,0)*wk1_B0(0,0,0) - (1.0/2.0)*u1_B0(0,0,0)*wk21_B0(0,0,0) -
      (1.0/2.0)*u2_B0(0,0,0)*wk29_B0(0,0,0);

    Residual2_B0(0,0,0) = -wk18_B0(0,0,0) - (1.0/2.0)*wk0_B0(0,0,0) - (1.0/2.0)*wk15_B0(0,0,0) -
      (1.0/2.0)*wk36_B0(0,0,0) - (1.0/2.0)*(wk9_B0(0,0,0) + wk23_B0(0,0,0) + wk38_B0(0,0,0))*rhou1_B0(0,0,0) -
      (1.0/2.0)*u0_B0(0,0,0)*wk6_B0(0,0,0) - (1.0/2.0)*u1_B0(0,0,0)*wk13_B0(0,0,0) -
      (1.0/2.0)*u2_B0(0,0,0)*wk32_B0(0,0,0);

    Residual3_B0(0,0,0) = -wk33_B0(0,0,0) - (1.0/2.0)*wk2_B0(0,0,0) - (1.0/2.0)*wk25_B0(0,0,0) -
      (1.0/2.0)*wk26_B0(0,0,0) - (1.0/2.0)*(wk9_B0(0,0,0) + wk23_B0(0,0,0) + wk38_B0(0,0,0))*rhou2_B0(0,0,0) -
      (1.0/2.0)*u0_B0(0,0,0)*wk10_B0(0,0,0) - (1.0/2.0)*u1_B0(0,0,0)*wk17_B0(0,0,0) -
      (1.0/2.0)*u2_B0(0,0,0)*wk34_B0(0,0,0);

    Residual4_B0(0,0,0) = -wk7_B0(0,0,0) - wk22_B0(0,0,0) - wk35_B0(0,0,0) - (1.0/2.0)*wk4_B0(0,0,0) -
      (1.0/2.0)*wk24_B0(0,0,0) - (1.0/2.0)*wk28_B0(0,0,0) - (1.0/2.0)*(wk9_B0(0,0,0) + wk23_B0(0,0,0) +
      wk38_B0(0,0,0))*rhoE_B0(0,0,0) - (1.0/2.0)*u0_B0(0,0,0)*wk5_B0(0,0,0) - (1.0/2.0)*u1_B0(0,0,0)*wk20_B0(0,0,0) -
      (1.0/2.0)*u2_B0(0,0,0)*wk27_B0(0,0,0);

}

void opensbliblock00Kernel053(const ACC<double> &u0_B0, ACC<double> &wk1_B0)
{
    wk1_B0(0,0,0) = -(1.0/12.0)*(-16*u0_B0(1,0,0) - 16*u0_B0(-1,0,0) + 30*u0_B0(0,0,0) + u0_B0(-2,0,0) +
      u0_B0(2,0,0))*inv2Delta0block0;

}

void opensbliblock00Kernel055(const ACC<double> &T_B0, ACC<double> &wk3_B0)
{
    wk3_B0(0,0,0) = -(1.0/12.0)*(-16*T_B0(1,0,0) - 16*T_B0(-1,0,0) + 30*T_B0(0,0,0) + T_B0(-2,0,0) +
      T_B0(2,0,0))*inv2Delta0block0;

}

void opensbliblock00Kernel057(const ACC<double> &u2_B0, ACC<double> &wk5_B0)
{
   wk5_B0(0,0,0) = -(1.0/12.0)*(-u2_B0(0,-2,0) - 8*u2_B0(0,1,0) + 8*u2_B0(0,-1,0) + u2_B0(0,2,0))*invDelta1block0;

}

void opensbliblock00Kernel058(const ACC<double> &u0_B0, ACC<double> &wk6_B0)
{
   wk6_B0(0,0,0) = -(1.0/12.0)*(-u0_B0(0,-2,0) - 8*u0_B0(0,1,0) + 8*u0_B0(0,-1,0) + u0_B0(0,2,0))*invDelta1block0;

}

void opensbliblock00Kernel059(const ACC<double> &u2_B0, ACC<double> &wk7_B0)
{
    wk7_B0(0,0,0) = -(1.0/12.0)*(-16*u2_B0(0,1,0) - 16*u2_B0(0,-1,0) + 30*u2_B0(0,0,0) + u2_B0(0,-2,0) +
      u2_B0(0,2,0))*inv2Delta1block0;

}

void opensbliblock00Kernel060(const ACC<double> &u1_B0, ACC<double> &wk8_B0)
{
    wk8_B0(0,0,0) = -(1.0/12.0)*(-16*u1_B0(0,1,0) - 16*u1_B0(0,-1,0) + 30*u1_B0(0,0,0) + u1_B0(0,-2,0) +
      u1_B0(0,2,0))*inv2Delta1block0;

}

void opensbliblock00Kernel061(const ACC<double> &u1_B0, ACC<double> &wk9_B0)
{
    wk9_B0(0,0,0) = ((1.0/12.0))*(-u1_B0(0,0,-2) - u1_B0(0,0,2) - 30*u1_B0(0,0,0) + 16*u1_B0(0,0,1) +
      16*u1_B0(0,0,-1))*inv2Delta2block0;

}

void opensbliblock00Kernel063(const ACC<double> &u1_B0, ACC<double> &wk11_B0)
{
   wk11_B0(0,0,0) = ((1.0/12.0))*(-u1_B0(0,0,2) - 8*u1_B0(0,0,-1) + 8*u1_B0(0,0,1) + u1_B0(0,0,-2))*invDelta2block0;

}

void opensbliblock00Kernel064(const ACC<double> &u1_B0, ACC<double> &wk12_B0)
{
    wk12_B0(0,0,0) = -(1.0/12.0)*(-16*u1_B0(1,0,0) - 16*u1_B0(-1,0,0) + 30*u1_B0(0,0,0) + u1_B0(-2,0,0) +
      u1_B0(2,0,0))*inv2Delta0block0;

}

void opensbliblock00Kernel065(const ACC<double> &u2_B0, ACC<double> &wk13_B0)
{
    wk13_B0(0,0,0) = -(1.0/12.0)*(-16*u2_B0(0,0,1) - 16*u2_B0(0,0,-1) + 30*u2_B0(0,0,0) + u2_B0(0,0,-2) +
      u2_B0(0,0,2))*inv2Delta2block0;

}

void opensbliblock00Kernel066(const ACC<double> &u2_B0, ACC<double> &wk14_B0)
{
    wk14_B0(0,0,0) = -(1.0/12.0)*(-16*u2_B0(1,0,0) - 16*u2_B0(-1,0,0) + 30*u2_B0(0,0,0) + u2_B0(-2,0,0) +
      u2_B0(2,0,0))*inv2Delta0block0;

}

void opensbliblock00Kernel067(const ACC<double> &u0_B0, ACC<double> &wk15_B0)
{
    wk15_B0(0,0,0) = -(1.0/12.0)*(-16*u0_B0(0,0,1) - 16*u0_B0(0,0,-1) + 30*u0_B0(0,0,0) + u0_B0(0,0,-2) +
      u0_B0(0,0,2))*inv2Delta2block0;

}

void opensbliblock00Kernel068(const ACC<double> &u0_B0, ACC<double> &wk16_B0)
{
    wk16_B0(0,0,0) = -(1.0/12.0)*(-16*u0_B0(0,1,0) - 16*u0_B0(0,-1,0) + 30*u0_B0(0,0,0) + u0_B0(0,-2,0) +
      u0_B0(0,2,0))*inv2Delta1block0;

}

void opensbliblock00Kernel069(const ACC<double> &u1_B0, ACC<double> &wk17_B0)
{
   wk17_B0(0,0,0) = -(1.0/12.0)*(-u1_B0(-2,0,0) - 8*u1_B0(1,0,0) + 8*u1_B0(-1,0,0) + u1_B0(2,0,0))*invDelta0block0;

}

void opensbliblock00Kernel070(const ACC<double> &u1_B0, ACC<double> &wk18_B0)
{
   wk18_B0(0,0,0) = -(1.0/12.0)*(-u1_B0(0,-2,0) - 8*u1_B0(0,1,0) + 8*u1_B0(0,-1,0) + u1_B0(0,2,0))*invDelta1block0;

}

void opensbliblock00Kernel073(const ACC<double> &T_B0, ACC<double> &wk21_B0)
{
    wk21_B0(0,0,0) = -(1.0/12.0)*(-16*T_B0(0,1,0) - 16*T_B0(0,-1,0) + 30*T_B0(0,0,0) + T_B0(0,-2,0) +
      T_B0(0,2,0))*inv2Delta1block0;

}

void opensbliblock00Kernel074(const ACC<double> &u2_B0, ACC<double> &wk22_B0)
{
   wk22_B0(0,0,0) = -(1.0/12.0)*(-u2_B0(-2,0,0) - 8*u2_B0(1,0,0) + 8*u2_B0(-1,0,0) + u2_B0(2,0,0))*invDelta0block0;

}

void opensbliblock00Kernel075(const ACC<double> &u0_B0, ACC<double> &wk23_B0)
{
   wk23_B0(0,0,0) = -(1.0/12.0)*(-u0_B0(0,0,-2) - 8*u0_B0(0,0,1) + 8*u0_B0(0,0,-1) + u0_B0(0,0,2))*invDelta2block0;

}

void opensbliblock00Kernel076(const ACC<double> &u0_B0, ACC<double> &wk24_B0)
{
   wk24_B0(0,0,0) = -(1.0/12.0)*(-u0_B0(-2,0,0) - 8*u0_B0(1,0,0) + 8*u0_B0(-1,0,0) + u0_B0(2,0,0))*invDelta0block0;

}

void opensbliblock00Kernel077(const ACC<double> &u2_B0, ACC<double> &wk25_B0)
{
   wk25_B0(0,0,0) = ((1.0/12.0))*(-u2_B0(0,0,2) - 8*u2_B0(0,0,-1) + 8*u2_B0(0,0,1) + u2_B0(0,0,-2))*invDelta2block0;

}

void opensbliblock00Kernel078(const ACC<double> &T_B0, ACC<double> &wk26_B0)
{
    wk26_B0(0,0,0) = -(1.0/12.0)*(-16*T_B0(0,0,1) - 16*T_B0(0,0,-1) + 30*T_B0(0,0,0) + T_B0(0,0,-2) +
      T_B0(0,0,2))*inv2Delta2block0;

}

void opensbliblock00Kernel052(const ACC<double> &wk24_B0, ACC<double> &wk0_B0)
{
    wk0_B0(0,0,0) = -(1.0/12.0)*(-wk24_B0(0,0,-2) - 8*wk24_B0(0,0,1) + 8*wk24_B0(0,0,-1) +
      wk24_B0(0,0,2))*invDelta2block0;

}

void opensbliblock00Kernel054(const ACC<double> &wk24_B0, ACC<double> &wk2_B0)
{
    wk2_B0(0,0,0) = -(1.0/12.0)*(-wk24_B0(0,-2,0) - 8*wk24_B0(0,1,0) + 8*wk24_B0(0,-1,0) +
      wk24_B0(0,2,0))*invDelta1block0;

}

void opensbliblock00Kernel056(const ACC<double> &wk5_B0, ACC<double> &wk4_B0)
{
   wk4_B0(0,0,0) = ((1.0/12.0))*(-wk5_B0(0,0,2) - 8*wk5_B0(0,0,-1) + 8*wk5_B0(0,0,1) + wk5_B0(0,0,-2))*invDelta2block0;

}

void opensbliblock00Kernel062(const ACC<double> &wk22_B0, ACC<double> &wk10_B0)
{
    wk10_B0(0,0,0) = -(1.0/12.0)*(-wk22_B0(0,0,-2) - 8*wk22_B0(0,0,1) + 8*wk22_B0(0,0,-1) +
      wk22_B0(0,0,2))*invDelta2block0;

}

void opensbliblock00Kernel071(const ACC<double> &wk17_B0, ACC<double> &wk19_B0)
{
    wk19_B0(0,0,0) = -(1.0/12.0)*(-wk17_B0(0,-2,0) - 8*wk17_B0(0,1,0) + 8*wk17_B0(0,-1,0) +
      wk17_B0(0,2,0))*invDelta1block0;

}

void opensbliblock00Kernel072(const ACC<double> &wk18_B0, ACC<double> &wk20_B0)
{
    wk20_B0(0,0,0) = ((1.0/12.0))*(-wk18_B0(0,0,2) - 8*wk18_B0(0,0,-1) + 8*wk18_B0(0,0,1) +
      wk18_B0(0,0,-2))*invDelta2block0;

}

 void opensbliblock00Kernel080(const ACC<double> &u0_B0, const ACC<double> &u1_B0, const ACC<double> &u2_B0, const
ACC<double> &wk0_B0, const ACC<double> &wk10_B0, const ACC<double> &wk11_B0, const ACC<double> &wk12_B0, const
ACC<double> &wk13_B0, const ACC<double> &wk14_B0, const ACC<double> &wk15_B0, const ACC<double> &wk16_B0, const
ACC<double> &wk17_B0, const ACC<double> &wk18_B0, const ACC<double> &wk19_B0, const ACC<double> &wk1_B0, const
ACC<double> &wk20_B0, const ACC<double> &wk21_B0, const ACC<double> &wk22_B0, const ACC<double> &wk23_B0, const
ACC<double> &wk24_B0, const ACC<double> &wk25_B0, const ACC<double> &wk26_B0, const ACC<double> &wk2_B0, const
ACC<double> &wk3_B0, const ACC<double> &wk4_B0, const ACC<double> &wk5_B0, const ACC<double> &wk6_B0, const ACC<double>
&wk7_B0, const ACC<double> &wk8_B0, const ACC<double> &wk9_B0, ACC<double> &Residual1_B0, ACC<double> &Residual2_B0,
ACC<double> &Residual3_B0, ACC<double> &Residual4_B0)
{
    Residual1_B0(0,0,0) = 1.0*(((1.0/3.0))*wk10_B0(0,0,0) + ((1.0/3.0))*wk19_B0(0,0,0) + ((4.0/3.0))*wk1_B0(0,0,0) +
      wk15_B0(0,0,0) + wk16_B0(0,0,0))*invRe + Residual1_B0(0,0,0);

    Residual2_B0(0,0,0) = 1.0*(((1.0/3.0))*wk2_B0(0,0,0) + ((1.0/3.0))*wk4_B0(0,0,0) + ((4.0/3.0))*wk8_B0(0,0,0) +
      wk9_B0(0,0,0) + wk12_B0(0,0,0))*invRe + Residual2_B0(0,0,0);

    Residual3_B0(0,0,0) = 1.0*(((1.0/3.0))*wk0_B0(0,0,0) + ((1.0/3.0))*wk20_B0(0,0,0) + ((4.0/3.0))*wk13_B0(0,0,0) +
      wk7_B0(0,0,0) + wk14_B0(0,0,0))*invRe + Residual3_B0(0,0,0);

    Residual4_B0(0,0,0) = 1.0*(wk5_B0(0,0,0) + wk11_B0(0,0,0))*invRe*wk5_B0(0,0,0) + 1.0*(wk5_B0(0,0,0) +
      wk11_B0(0,0,0))*invRe*wk11_B0(0,0,0) + 1.0*(wk6_B0(0,0,0) + wk17_B0(0,0,0))*invRe*wk6_B0(0,0,0) +
      1.0*(wk6_B0(0,0,0) + wk17_B0(0,0,0))*invRe*wk17_B0(0,0,0) + 1.0*(wk22_B0(0,0,0) +
      wk23_B0(0,0,0))*invRe*wk22_B0(0,0,0) + 1.0*(wk22_B0(0,0,0) + wk23_B0(0,0,0))*invRe*wk23_B0(0,0,0) +
      1.0*(-(2.0/3.0)*wk18_B0(0,0,0) - (2.0/3.0)*wk24_B0(0,0,0) + ((4.0/3.0))*wk25_B0(0,0,0))*invRe*wk25_B0(0,0,0) +
      1.0*(-(2.0/3.0)*wk18_B0(0,0,0) - (2.0/3.0)*wk25_B0(0,0,0) + ((4.0/3.0))*wk24_B0(0,0,0))*invRe*wk24_B0(0,0,0) +
      1.0*(-(2.0/3.0)*wk24_B0(0,0,0) - (2.0/3.0)*wk25_B0(0,0,0) + ((4.0/3.0))*wk18_B0(0,0,0))*invRe*wk18_B0(0,0,0) +
      1.0*(((1.0/3.0))*wk0_B0(0,0,0) + ((1.0/3.0))*wk20_B0(0,0,0) + ((4.0/3.0))*wk13_B0(0,0,0) + wk7_B0(0,0,0) +
      wk14_B0(0,0,0))*invRe*u2_B0(0,0,0) + 1.0*(((1.0/3.0))*wk2_B0(0,0,0) + ((1.0/3.0))*wk4_B0(0,0,0) +
      ((4.0/3.0))*wk8_B0(0,0,0) + wk9_B0(0,0,0) + wk12_B0(0,0,0))*invRe*u1_B0(0,0,0) + 1.0*(((1.0/3.0))*wk10_B0(0,0,0) +
      ((1.0/3.0))*wk19_B0(0,0,0) + ((4.0/3.0))*wk1_B0(0,0,0) + wk15_B0(0,0,0) + wk16_B0(0,0,0))*invRe*u0_B0(0,0,0) +
      1.0*(wk3_B0(0,0,0) + wk21_B0(0,0,0) + wk26_B0(0,0,0))*invPr*invRe*inv2Minf*inv_gamma_m1 + Residual4_B0(0,0,0);

}

 void opensbliblock00Kernel090(const ACC<double> &Residual0_B0, const ACC<double> &Residual1_B0, const ACC<double>
&Residual2_B0, const ACC<double> &Residual3_B0, const ACC<double> &Residual4_B0, const ACC<double> &rhoE_RKold_B0, const
ACC<double> &rho_RKold_B0, const ACC<double> &rhou0_RKold_B0, const ACC<double> &rhou1_RKold_B0, const ACC<double>
&rhou2_RKold_B0, ACC<double> &rhoE_B0, ACC<double> &rho_B0, ACC<double> &rhou0_B0, ACC<double> &rhou1_B0, ACC<double>
&rhou2_B0, const double *rknew)
{
   rho_B0(0,0,0) = rknew[0]*dt*Residual0_B0(0,0,0) + rho_RKold_B0(0,0,0);

   rhou0_B0(0,0,0) = rknew[0]*dt*Residual1_B0(0,0,0) + rhou0_RKold_B0(0,0,0);

   rhou1_B0(0,0,0) = rknew[0]*dt*Residual2_B0(0,0,0) + rhou1_RKold_B0(0,0,0);

   rhou2_B0(0,0,0) = rknew[0]*dt*Residual3_B0(0,0,0) + rhou2_RKold_B0(0,0,0);

   rhoE_B0(0,0,0) = rknew[0]*dt*Residual4_B0(0,0,0) + rhoE_RKold_B0(0,0,0);

}

 void opensbliblock00Kernel089(const ACC<double> &Residual0_B0, const ACC<double> &Residual1_B0, const ACC<double>
&Residual2_B0, const ACC<double> &Residual3_B0, const ACC<double> &Residual4_B0, ACC<double> &rhoE_RKold_B0, ACC<double>
&rho_RKold_B0, ACC<double> &rhou0_RKold_B0, ACC<double> &rhou1_RKold_B0, ACC<double> &rhou2_RKold_B0, const double
*rkold)
{
   rho_RKold_B0(0,0,0) = rkold[0]*dt*Residual0_B0(0,0,0) + rho_RKold_B0(0,0,0);

   rhou0_RKold_B0(0,0,0) = rkold[0]*dt*Residual1_B0(0,0,0) + rhou0_RKold_B0(0,0,0);

   rhou1_RKold_B0(0,0,0) = rkold[0]*dt*Residual2_B0(0,0,0) + rhou1_RKold_B0(0,0,0);

   rhou2_RKold_B0(0,0,0) = rkold[0]*dt*Residual3_B0(0,0,0) + rhou2_RKold_B0(0,0,0);

   rhoE_RKold_B0(0,0,0) = rkold[0]*dt*Residual4_B0(0,0,0) + rhoE_RKold_B0(0,0,0);

}

#endif
