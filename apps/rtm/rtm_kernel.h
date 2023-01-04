#ifndef rtm_KERNEL_H
#define rtm_KERNEL_H

void rtm_kernel_populate(const int *dispx,
  const int *dispy,
  const int *dispz,
  const int *idx,
  ACC<float> &rho,
  ACC<float> &mu,
  ACC<float> &yy) {
  float x = 1.0f*((float)(idx[0]-nx/2)/nx);
  float y = 1.0f*((float)(idx[1]-ny/2)/ny);
  float z = 1.0f*((float)(idx[2]-nz/2)/nz);
  const float C = 1.f;
  const float r0 = 0.001f;
  rho(0,0,0) = 1.f;
  mu(0,0,0) = 1.f;

  yy(0,0,0,0) = (1.f/3.f)*C*exp(-(x*x+y*y+z*z)/r0);
  yy(1,0,0,0) = (1.f/3.f)*C*exp(-(x*x+y*y+z*z)/r0);
  yy(2,0,0,0) = (1.f/3.f)*C*exp(-(x*x+y*y+z*z)/r0);

  yy(3,0,0,0) = 0.0;
  yy(4,0,0,0) = 0.0;
  yy(5,0,0,0) = 0.0;
}

void rtm_kernel_out(const int *dispx,
  const int *dispy,
  const int *dispz,
  const int *idx,
  const ACC<float>& yy,
  FILE* file) {
  float x = 1.0f*((float)(idx[0]-nx/2)/nx);
  float y = 1.0f*((float)(idx[1]-ny/2)/ny);
  float z = 1.0f*((float)(idx[2]-nz/2)/nz);
  float r = sqrt(x*x+y*y+z*z);

//  fprintf(file,"%e %e %e %e\n",x,y,z,yy(0,0,0,0)+yy(1,0,0,0)+yy(2,0,0,0));
}

void calc_ytemp_kernel(const int *idx,
  const float *dt,
  const ACC<float>& yy,
  ACC<float>& k,
  ACC<float>& ytemp) {

  for (int i = 0; i < 6; i++) {
    k(i,0,0,0) = k(i,0,0,0)* *dt;
    ytemp(i,0,0,0) = yy(i,0,0,0) + k(i,0,0,0)*0.5f;
  }

}

void calc_ytemp2_kernel(const int *idx,
  const float *dt,
  const ACC<float>& yy,
  ACC<float>& k,
  ACC<float>& ytemp) {

  for (int i = 0; i < 6; i++) {
    k(i,0,0,0) = k(i,0,0,0)* *dt;
    ytemp(i,0,0,0) = yy(i,0,0,0) + k(i,0,0,0);
  }

}

void final_update_kernel(const int *idx,
  const float *dt,
  const ACC<float>& k1,
  const ACC<float>& k2,
  const ACC<float>& k3,
  ACC<float>& k4,
  ACC<float>& yy)
{
  for (int i = 0; i<6; i++) {

    k4(i,0,0,0) = k4(i,0,0,0)* *dt;

    yy(i,0,0,0) = yy(i,0,0,0) +
      k1(i,0,0,0)/6.f +
      k2(i,0,0,0)/3.f +
      k3(i,0,0,0)/3.f +
      k4(i,0,0,0)/6.f;
    /*
    printf(" k1, k2, k3, k4 = %e %e %e %e\n",
     k1[OPS_ACC_MD2(i,0,0,0)],
     k2[OPS_ACC_MD3(i,0,0,0)],
     k3[OPS_ACC_MD4(i,0,0,0)],
     k4[OPS_ACC_MD5(i,0,0,0)]);
    */
  }
}

void fd3d_pml_kernel(const ACC<float> &rho,
  const ACC<float> &mu,
  const ACC<float>& yy,
  ACC<float>& dy,
  const int *idx)
{
  float sigma = mu(0,0,0)/rho(0,0,0);
  float sigmax=0.0f;
  float sigmay=0.0f;
  float sigmaz=0.0f;

  if(idx[0]<=xbeg+pml_width){
    sigmax = (xbeg+pml_width-idx[0])*sigma/pml_width;
  }
  if(idx[0]>=xend-pml_width){
    sigmax=(idx[0]-(xend-pml_width))*sigma/pml_width;
  }
  if(idx[1]<=ybeg+pml_width){
    sigmay=(ybeg+pml_width-idx[1])*sigma/pml_width;
  }
  if(idx[1]>=yend-pml_width){
    sigmay=(idx[1]-(yend-pml_width))*sigma/pml_width;
  }
  if(idx[2]<=zbeg+pml_width){
    sigmaz=(zbeg+pml_width-idx[2])*sigma/pml_width;
  }
  if(idx[2]>=zend-pml_width){
    sigmaz=(idx[2]-(zend-pml_width))*sigma/pml_width;
  }





  float px = yy(0,0,0,0);
  float py = yy(1,0,0,0);
  float pz = yy(2,0,0,0);

  float vx = yy(3,0,0,0);
  float vy = yy(4,0,0,0);
  float vz = yy(5,0,0,0);

  float vxx=0.0f;
  float vyy=0.0f;
  float vzz=0.0f;

  float pxx=0.0f;
  float pxy=0.0f;
  float pxz=0.0f;

  float pyx=0.0f;
  float pyy=0.0f;
  float pyz=0.0f;

  float pzx=0.0f;
  float pzy=0.0f;
  float pzz=0.0f;

  for(int i=-halff;i<=halff;i++)
    {
#define CX
#ifndef CX
      pxx += yy(0,i,0,0)*c[i]*invdx;
      pyx += yy(1,i,0,0)*c[i]*invdx;
      pzx += yy(2,i,0,0)*c[i]*invdx;
      vxx += yy(3,i,0,0)*c[i]*invdx;

      pxy += yy(0,0,i,0)*c[i]*invdy;
      pyy += yy(1,0,i,0)*c[i]*invdy;
      pzy += yy(2,0,i,0)*c[i]*invdy;
      vyy += yy(4,0,i,0)*c[i]*invdy;

      pxz += yy(0,0,0,i)*c[i]*invdz;
      pyz += yy(1,0,0,i)*c[i]*invdz;
      pzz += yy(2,0,0,i)*c[i]*invdz;
      vzz += yy(5,0,0,i)*c[i]*invdz;

#else
      int j = i+halff;
      pxx += yy(0,i,0,0)*cx[j];
      pyx += yy(1,i,0,0)*cx[j];
      pzx += yy(2,i,0,0)*cx[j];
      vxx += yy(3,i,0,0)*cx[j];

      pxy += yy(0,0,i,0)*cy[j];
      pyy += yy(1,0,i,0)*cy[j];
      pzy += yy(2,0,i,0)*cy[j];
      vyy += yy(4,0,i,0)*cy[j];

      pxz += yy(0,0,0,i)*cz[j];
      pyz += yy(1,0,0,i)*cz[j];
      pzz += yy(2,0,0,i)*cz[j];
      vzz += yy(5,0,0,i)*cz[j];
#endif
    }

  dy(0,0,0,0)=vxx/rho(0,0,0) - sigmax*px;
  dy(1,0,0,0)=vyy/rho(0,0,0) - sigmay*py;
  dy(2,0,0,0)=vzz/rho(0,0,0) - sigmaz*pz;

  dy(3,0,0,0)=(pxx+pyx+pzx)*mu(0,0,0) - sigmax*vx;
  dy(4,0,0,0)=(pxy+pyy+pzy)*mu(0,0,0) - sigmay*vy;
  dy(5,0,0,0)=(pxz+pyz+pzz)*mu(0,0,0) - sigmaz*vz;

}

#endif //rtm_KERNEL_H
