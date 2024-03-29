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

void calc_ytemp_kernel(const int *idx,
  const float *dt,
  const ptrm_float  yy,
  ptrm_float  k,
  ptrm_float  ytemp) {

  for (int i = 0; i < 6; i++) {
    OPS_ACCM(k, i,0,0,0) = OPS_ACCM(k, i,0,0,0)* *dt;
    OPS_ACCM(ytemp, i,0,0,0) = OPS_ACCM(yy, i,0,0,0) + OPS_ACCM(k, i,0,0,0)*0.5f;
  }

}


__kernel void ops_calc_ytemp_kernel(
const float arg1,
__global const float* restrict arg2,
__global float* restrict arg3,
__global float* restrict arg4,
const int base2,
const int base3,
const int base4,
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
    #ifdef OPS_SOA
    const ptrm_float ptr2 = { &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_calc_ytemp_kernel + idx_z * 1 * xdim2_calc_ytemp_kernel * ydim2_calc_ytemp_kernel], xdim2_calc_ytemp_kernel, ydim2_calc_ytemp_kernel, zdim2_calc_ytemp_kernel};
    #else
    const ptrm_float ptr2 = { &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_calc_ytemp_kernel + idx_z * 1 * xdim2_calc_ytemp_kernel * ydim2_calc_ytemp_kernel], xdim2_calc_ytemp_kernel, ydim2_calc_ytemp_kernel, 6};
    #endif
    #ifdef OPS_SOA
    ptrm_float ptr3 = { &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_calc_ytemp_kernel + idx_z * 1 * xdim3_calc_ytemp_kernel * ydim3_calc_ytemp_kernel], xdim3_calc_ytemp_kernel, ydim3_calc_ytemp_kernel, zdim3_calc_ytemp_kernel};
    #else
    ptrm_float ptr3 = { &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_calc_ytemp_kernel + idx_z * 1 * xdim3_calc_ytemp_kernel * ydim3_calc_ytemp_kernel], xdim3_calc_ytemp_kernel, ydim3_calc_ytemp_kernel, 6};
    #endif
    #ifdef OPS_SOA
    ptrm_float ptr4 = { &arg4[base4 + idx_x * 1 + idx_y * 1 * xdim4_calc_ytemp_kernel + idx_z * 1 * xdim4_calc_ytemp_kernel * ydim4_calc_ytemp_kernel], xdim4_calc_ytemp_kernel, ydim4_calc_ytemp_kernel, zdim4_calc_ytemp_kernel};
    #else
    ptrm_float ptr4 = { &arg4[base4 + idx_x * 1 + idx_y * 1 * xdim4_calc_ytemp_kernel + idx_z * 1 * xdim4_calc_ytemp_kernel * ydim4_calc_ytemp_kernel], xdim4_calc_ytemp_kernel, ydim4_calc_ytemp_kernel, 6};
    #endif
    calc_ytemp_kernel(arg_idx,
                      &arg1,
                      ptr2,
                      ptr3,
                      ptr4);
  }

}
