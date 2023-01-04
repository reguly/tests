//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_3D
#define OPS_API 2
#define OPS_NO_GLOBALS
#include "ops_macros.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5

//user function

void fd3d_pml_kernel(const ptr_float rho,
  const ptr_float mu,
  const ptrm_float  yy,
  ptrm_float  dy,
  const int *idx, const float invdx, const float invdy, const float invdz, const int pml_width, const int xbeg, const int ybeg, const int zbeg, const int xend, const int yend, const int zend, const int halff, __constant constfloat *c, __constant constfloat *cx, __constant constfloat *cy, __constant constfloat *cz)
{
  float sigma = OPS_ACCS(mu, 0,0,0)/OPS_ACCS(rho, 0,0,0);
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



  float px = OPS_ACCM(yy, 0,0,0,0);
  float py = OPS_ACCM(yy, 1,0,0,0);
  float pz = OPS_ACCM(yy, 2,0,0,0);

  float vx = OPS_ACCM(yy, 3,0,0,0);
  float vy = OPS_ACCM(yy, 4,0,0,0);
  float vz = OPS_ACCM(yy, 5,0,0,0);

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
      pxx += OPS_ACCM(yy, 0,i,0,0)*c[i]*invdx;
      pyx += OPS_ACCM(yy, 1,i,0,0)*c[i]*invdx;
      pzx += OPS_ACCM(yy, 2,i,0,0)*c[i]*invdx;
      vxx += OPS_ACCM(yy, 3,i,0,0)*c[i]*invdx;

      pxy += OPS_ACCM(yy, 0,0,i,0)*c[i]*invdy;
      pyy += OPS_ACCM(yy, 1,0,i,0)*c[i]*invdy;
      pzy += OPS_ACCM(yy, 2,0,i,0)*c[i]*invdy;
      vyy += OPS_ACCM(yy, 4,0,i,0)*c[i]*invdy;

      pxz += OPS_ACCM(yy, 0,0,0,i)*c[i]*invdz;
      pyz += OPS_ACCM(yy, 1,0,0,i)*c[i]*invdz;
      pzz += OPS_ACCM(yy, 2,0,0,i)*c[i]*invdz;
      vzz += OPS_ACCM(yy, 5,0,0,i)*c[i]*invdz;

#else
      int j = i+halff;
      pxx += OPS_ACCM(yy, 0,i,0,0)*cx[j];
      pyx += OPS_ACCM(yy, 1,i,0,0)*cx[j];
      pzx += OPS_ACCM(yy, 2,i,0,0)*cx[j];
      vxx += OPS_ACCM(yy, 3,i,0,0)*cx[j];

      pxy += OPS_ACCM(yy, 0,0,i,0)*cy[j];
      pyy += OPS_ACCM(yy, 1,0,i,0)*cy[j];
      pzy += OPS_ACCM(yy, 2,0,i,0)*cy[j];
      vyy += OPS_ACCM(yy, 4,0,i,0)*cy[j];

      pxz += OPS_ACCM(yy, 0,0,0,i)*cz[j];
      pyz += OPS_ACCM(yy, 1,0,0,i)*cz[j];
      pzz += OPS_ACCM(yy, 2,0,0,i)*cz[j];
      vzz += OPS_ACCM(yy, 5,0,0,i)*cz[j];
#endif
    }

  OPS_ACCM(dy, 0,0,0,0)=vxx/OPS_ACCS(rho, 0,0,0) - sigmax*px;
  OPS_ACCM(dy, 1,0,0,0)=vyy/OPS_ACCS(rho, 0,0,0) - sigmay*py;
  OPS_ACCM(dy, 2,0,0,0)=vzz/OPS_ACCS(rho, 0,0,0) - sigmaz*pz;

  OPS_ACCM(dy, 3,0,0,0)=(pxx+pyx+pzx)*OPS_ACCS(mu, 0,0,0) - sigmax*vx;
  OPS_ACCM(dy, 4,0,0,0)=(pxy+pyy+pzy)*OPS_ACCS(mu, 0,0,0) - sigmay*vy;
  OPS_ACCM(dy, 5,0,0,0)=(pxz+pyz+pzz)*OPS_ACCS(mu, 0,0,0) - sigmaz*vz;

}


__kernel void ops_fd3d_pml_kernel(
__global const float* restrict arg0,
__global const float* restrict arg1,
__global const float* restrict arg2,
__global float* restrict arg3,
const float invdx,
const float invdy,
const float invdz,
const int pml_width,
const int xbeg,
const int ybeg,
const int zbeg,
const int xend,
const int yend,
const int zend,
const int halff,
const float c,
const float cx,
const float cy,
const float cz,
const int base0,
const int base1,
const int base2,
const int base3,
int arg_idx0, int arg_idx1, int arg_idx2,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  int arg_idx[3];
  arg_idx[0] = arg_idx0+idx_x;
  arg_idx[1] = arg_idx1+idx_y;
  arg_idx[2] = arg_idx2+idx_z;
  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ptr_float ptr0 = { &arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_fd3d_pml_kernel + idx_z * 1 * xdim0_fd3d_pml_kernel * ydim0_fd3d_pml_kernel], xdim0_fd3d_pml_kernel, ydim0_fd3d_pml_kernel};
    const ptr_float ptr1 = { &arg1[base1 + idx_x * 1 + idx_y * 1 * xdim1_fd3d_pml_kernel + idx_z * 1 * xdim1_fd3d_pml_kernel * ydim1_fd3d_pml_kernel], xdim1_fd3d_pml_kernel, ydim1_fd3d_pml_kernel};
    #ifdef OPS_SOA
    const ptrm_float ptr2 = { &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_fd3d_pml_kernel + idx_z * 1 * xdim2_fd3d_pml_kernel * ydim2_fd3d_pml_kernel], xdim2_fd3d_pml_kernel, ydim2_fd3d_pml_kernel, zdim2_fd3d_pml_kernel};
    #else
    const ptrm_float ptr2 = { &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_fd3d_pml_kernel + idx_z * 1 * xdim2_fd3d_pml_kernel * ydim2_fd3d_pml_kernel], xdim2_fd3d_pml_kernel, ydim2_fd3d_pml_kernel, 6};
    #endif
    #ifdef OPS_SOA
    ptrm_float ptr3 = { &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_fd3d_pml_kernel + idx_z * 1 * xdim3_fd3d_pml_kernel * ydim3_fd3d_pml_kernel], xdim3_fd3d_pml_kernel, ydim3_fd3d_pml_kernel, zdim3_fd3d_pml_kernel};
    #else
    ptrm_float ptr3 = { &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_fd3d_pml_kernel + idx_z * 1 * xdim3_fd3d_pml_kernel * ydim3_fd3d_pml_kernel], xdim3_fd3d_pml_kernel, ydim3_fd3d_pml_kernel, 6};
    #endif
    fd3d_pml_kernel(ptr0,
                    ptr1,
                    ptr2,
                    ptr3,
                    arg_idx,
                    invdx,
                    invdy,
                    invdz,
                    pml_width,
                    xbeg,
                    ybeg,
                    zbeg,
                    xend,
                    yend,
                    zend,
                    halff,
                    c,
                    cx,
                    cy,
                    cz);
  }

}
