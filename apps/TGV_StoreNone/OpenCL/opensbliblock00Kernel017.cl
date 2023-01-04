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

 void opensbliblock00Kernel017(const ptr_double rhoE_B0,
  const ptr_double u2_B0,
  const ptr_double u0_B0,
  const ptr_double rho_B0,
  const ptr_double u1_B0,
  ptr_double p_B0, const double gama, const double rc6)
{
    OPS_ACCS(p_B0, 0,0,0) = (gama - 1)*(OPS_ACCS(rhoE_B0, 0,0,0) -
      rc6*OPS_ACCS(rho_B0, 0,0,0)*pow(OPS_ACCS(u0_B0, 0,0,0), 2) -
      rc6*OPS_ACCS(rho_B0, 0,0,0)*pow(OPS_ACCS(u1_B0, 0,0,0), 2) -
      rc6*OPS_ACCS(rho_B0, 0,0,0)*pow(OPS_ACCS(u2_B0, 0,0,0), 2));

}


__kernel void ops_opensbliblock00Kernel017(
__global const double* restrict arg0,
__global const double* restrict arg1,
__global const double* restrict arg2,
__global const double* restrict arg3,
__global const double* restrict arg4,
__global double* restrict arg5,
const double gama,
const double rc6,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int base5,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_opensbliblock00Kernel017 + idx_z * 1*1 * xdim0_opensbliblock00Kernel017 * ydim0_opensbliblock00Kernel017], xdim0_opensbliblock00Kernel017, ydim0_opensbliblock00Kernel017};
    const ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_opensbliblock00Kernel017 + idx_z * 1*1 * xdim1_opensbliblock00Kernel017 * ydim1_opensbliblock00Kernel017], xdim1_opensbliblock00Kernel017, ydim1_opensbliblock00Kernel017};
    const ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1 + idx_y * 1*1 * xdim2_opensbliblock00Kernel017 + idx_z * 1*1 * xdim2_opensbliblock00Kernel017 * ydim2_opensbliblock00Kernel017], xdim2_opensbliblock00Kernel017, ydim2_opensbliblock00Kernel017};
    const ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 1*1 * xdim3_opensbliblock00Kernel017 + idx_z * 1*1 * xdim3_opensbliblock00Kernel017 * ydim3_opensbliblock00Kernel017], xdim3_opensbliblock00Kernel017, ydim3_opensbliblock00Kernel017};
    const ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1 + idx_y * 1*1 * xdim4_opensbliblock00Kernel017 + idx_z * 1*1 * xdim4_opensbliblock00Kernel017 * ydim4_opensbliblock00Kernel017], xdim4_opensbliblock00Kernel017, ydim4_opensbliblock00Kernel017};
    ptr_double ptr5 = { &arg5[base5 + idx_x * 1*1 + idx_y * 1*1 * xdim5_opensbliblock00Kernel017 + idx_z * 1*1 * xdim5_opensbliblock00Kernel017 * ydim5_opensbliblock00Kernel017], xdim5_opensbliblock00Kernel017, ydim5_opensbliblock00Kernel017};
    opensbliblock00Kernel017(ptr0,
                                  ptr1,
                                  ptr2,
                                  ptr3,
                                  ptr4,
                                  ptr5,
                                  gama,
                                  rc6);
  }

}
