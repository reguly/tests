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

void opensbliblock00Kernel076(const ptr_double u2_B0,
  ptr_double wk24_B0, const double inv_1, const double rc8)
{
    OPS_ACCS(wk24_B0, 0,0,0) = (rc8)*inv_1*(8*OPS_ACCS(u2_B0, 1,0,0) + OPS_ACCS(u2_B0, -2,0,0) -
      8*OPS_ACCS(u2_B0, -1,0,0) - OPS_ACCS(u2_B0, 2,0,0));

}


__kernel void ops_opensbliblock00Kernel076(
__global const double* restrict arg0,
__global double* restrict arg1,
const double inv_1,
const double rc8,
const int base0,
const int base1,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_opensbliblock00Kernel076 + idx_z * 1*1 * xdim0_opensbliblock00Kernel076 * ydim0_opensbliblock00Kernel076], xdim0_opensbliblock00Kernel076, ydim0_opensbliblock00Kernel076};
    ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_opensbliblock00Kernel076 + idx_z * 1*1 * xdim1_opensbliblock00Kernel076 * ydim1_opensbliblock00Kernel076], xdim1_opensbliblock00Kernel076, ydim1_opensbliblock00Kernel076};
    opensbliblock00Kernel076(ptr0,
                                  ptr1,
                                  inv_1,
                                  rc8);
  }

}
