//
// auto-generated by ops.py
//
__constant__ int dims_opensbliblock00Kernel025 [17][2];
static int dims_opensbliblock00Kernel025_h [17][2] = {0};

//user function
__device__

 void opensbliblock00Kernel025_gpu(const ACC<double> &wk8_B0,
  const ACC<double> &wk3_B0,
  const ACC<double> &wk2_B0,
  const ACC<double> &u0_B0,
  const ACC<double> &wk1_B0,
  const ACC<double> &u1_B0,
  const ACC<double> &wk4_B0,
  const ACC<double> &wk7_B0,
  const ACC<double> &T_B0,
  const ACC<double>
&u2_B0,
  const ACC<double> &wk5_B0,
  const ACC<double> &wk0_B0,
  const ACC<double> &wk6_B0,
  ACC<double> &Residual4_B0,
  ACC<double> &Residual1_B0,
  ACC<double> &Residual3_B0,
  ACC<double> &Residual2_B0)
{
   double localeval_16 = 0.0;
   double localeval_5 = 0.0;
   double localeval_9 = 0.0;
   double localeval_7 = 0.0;
   double localeval_6 = 0.0;
   double localeval_15 = 0.0;
   double localeval_3 = 0.0;
   double localeval_2 = 0.0;
   double localeval_14 = 0.0;
   double localeval_10 = 0.0;
   double localeval_0 = 0.0;
   double localeval_1 = 0.0;
   double localeval_4 = 0.0;
   double localeval_8 = 0.0;
   double localeval_11 = 0.0;
   double localeval_12 = 0.0;
   double localeval_13 = 0.0;
   double localeval_17 = 0.0;
    localeval_0 = (rc7)*inv_3*(16*T_B0(1,0,0) - 30*T_B0(0,0,0) - T_B0(2,0,0) -
      T_B0(-2,0,0) + 16*T_B0(-1,0,0));

    localeval_1 = (rc7)*inv_4*(16*T_B0(0,1,0) - 30*T_B0(0,0,0) - T_B0(0,-2,0) -
      T_B0(0,2,0) + 16*T_B0(0,-1,0));

    localeval_2 = (rc7)*inv_5*(-T_B0(0,0,-2) + 16*T_B0(0,0,-1) - 30*T_B0(0,0,0) -
      T_B0(0,0,2) + 16*T_B0(0,0,1));

    localeval_3 = (rc7)*inv_4*(-u0_B0(0,2,0) + 16*u0_B0(0,1,0) - 30*u0_B0(0,0,0) +
      16*u0_B0(0,-1,0) - u0_B0(0,-2,0));

    localeval_4 = (rc7)*inv_5*(16*u0_B0(0,0,1) - 30*u0_B0(0,0,0) + 16*u0_B0(0,0,-1) -
      u0_B0(0,0,-2) - u0_B0(0,0,2));

    localeval_5 = (rc7)*inv_3*(-u0_B0(2,0,0) + 16*u0_B0(1,0,0) - 30*u0_B0(0,0,0) +
      16*u0_B0(-1,0,0) - u0_B0(-2,0,0));

    localeval_6 = (rc7)*inv_4*(16*u1_B0(0,1,0) - u1_B0(0,2,0) - u1_B0(0,-2,0) +
      16*u1_B0(0,-1,0) - 30*u1_B0(0,0,0));

    localeval_7 = (rc7)*inv_3*(16*u1_B0(1,0,0) - u1_B0(2,0,0) - u1_B0(-2,0,0) +
      16*u1_B0(-1,0,0) - 30*u1_B0(0,0,0));

    localeval_8 = (rc7)*inv_5*(16*u1_B0(0,0,1) - u1_B0(0,0,2) - u1_B0(0,0,-2) +
      16*u1_B0(0,0,-1) - 30*u1_B0(0,0,0));

    localeval_9 = (rc7)*inv_5*(-u2_B0(0,0,2) + 16*u2_B0(0,0,-1) - u2_B0(0,0,-2) -
      30*u2_B0(0,0,0) + 16*u2_B0(0,0,1));

    localeval_10 = (rc7)*inv_3*(16*u2_B0(-1,0,0) - u2_B0(-2,0,0) - 30*u2_B0(0,0,0) +
      16*u2_B0(1,0,0) - u2_B0(2,0,0));

    localeval_11 = (rc7)*inv_4*(16*u2_B0(0,-1,0) - u2_B0(0,-2,0) - 30*u2_B0(0,0,0) +
      16*u2_B0(0,1,0) - u2_B0(0,2,0));

    localeval_12 = (rc7)*inv_2*(-wk0_B0(0,2,0) + wk0_B0(0,-2,0) - 8*wk0_B0(0,-1,0) +
      8*wk0_B0(0,1,0));

    localeval_13 = (rc7)*inv_1*(wk0_B0(0,0,-2) - wk0_B0(0,0,2) + 8*wk0_B0(0,0,1) -
      8*wk0_B0(0,0,-1));

    localeval_14 = (rc7)*inv_2*(-wk3_B0(0,2,0) + wk3_B0(0,-2,0) + 8*wk3_B0(0,1,0) -
      8*wk3_B0(0,-1,0));

    localeval_15 = (rc7)*inv_1*(8*wk5_B0(0,0,1) - wk5_B0(0,0,2) + wk5_B0(0,0,-2) -
      8*wk5_B0(0,0,-1));

    localeval_16 = (rc7)*inv_1*(-8*wk6_B0(0,0,-1) - wk6_B0(0,0,2) + wk6_B0(0,0,-2) +
      8*wk6_B0(0,0,1));

    localeval_17 = (rc7)*inv_1*(-wk8_B0(0,0,2) + 8*wk8_B0(0,0,1) - 8*wk8_B0(0,0,-1) +
      wk8_B0(0,0,-2));

    Residual1_B0(0,0,0) = 1.0*rcinv8*((rc9)*localeval_14 + (rc9)*localeval_16 + localeval_3 + localeval_4 +
      (rc10)*localeval_5) + Residual1_B0(0,0,0);

    Residual2_B0(0,0,0) = 1.0*rcinv8*((rc9)*localeval_12 + (rc9)*localeval_17 + (rc10)*localeval_6 +
      localeval_7 + localeval_8) + Residual2_B0(0,0,0);

    Residual3_B0(0,0,0) = 1.0*rcinv8*(localeval_10 + localeval_11 + (rc9)*localeval_13 + (rc9)*localeval_15 +
      (rc10)*localeval_9) + Residual3_B0(0,0,0);

    Residual4_B0(0,0,0) = 1.0*rcinv11*rcinv12*rcinv13*rcinv8*(localeval_0 + localeval_1 + localeval_2) +
      1.0*rcinv8*(wk1_B0(0,0,0) + wk6_B0(0,0,0))*wk1_B0(0,0,0) +
      1.0*rcinv8*(wk1_B0(0,0,0) + wk6_B0(0,0,0))*wk6_B0(0,0,0) +
      1.0*rcinv8*(wk2_B0(0,0,0) + wk3_B0(0,0,0))*wk2_B0(0,0,0) +
      1.0*rcinv8*(wk2_B0(0,0,0) + wk3_B0(0,0,0))*wk3_B0(0,0,0) +
      1.0*rcinv8*(wk4_B0(0,0,0) + wk8_B0(0,0,0))*wk4_B0(0,0,0) +
      1.0*rcinv8*(wk4_B0(0,0,0) + wk8_B0(0,0,0))*wk8_B0(0,0,0) +
      1.0*rcinv8*(-rc14*wk0_B0(0,0,0) - rc14*wk5_B0(0,0,0) +
      (rc10)*wk7_B0(0,0,0))*wk7_B0(0,0,0) + 1.0*rcinv8*(-rc14*wk0_B0(0,0,0) +
      (rc10)*wk5_B0(0,0,0) - rc14*wk7_B0(0,0,0))*wk5_B0(0,0,0) +
      1.0*rcinv8*((rc10)*wk0_B0(0,0,0) - rc14*wk5_B0(0,0,0) -
      rc14*wk7_B0(0,0,0))*wk0_B0(0,0,0) + 1.0*rcinv8*(localeval_10 + localeval_11 +
      (rc9)*localeval_13 + (rc9)*localeval_15 + (rc10)*localeval_9)*u2_B0(0,0,0) +
      1.0*rcinv8*((rc9)*localeval_12 + (rc9)*localeval_17 + (rc10)*localeval_6 + localeval_7 +
      localeval_8)*u1_B0(0,0,0) + 1.0*rcinv8*((rc9)*localeval_14 + (rc9)*localeval_16 + localeval_3 +
      localeval_4 + (rc10)*localeval_5)*u0_B0(0,0,0) + Residual4_B0(0,0,0);

}



__global__ void ops_opensbliblock00Kernel025(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
double* __restrict arg4,
double* __restrict arg5,
double* __restrict arg6,
double* __restrict arg7,
double* __restrict arg8,
double* __restrict arg9,
double* __restrict arg10,
double* __restrict arg11,
double* __restrict arg12,
double* __restrict arg13,
double* __restrict arg14,
double* __restrict arg15,
double* __restrict arg16,
int size0,
int size1,
int size2 ){


  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[0][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[0][0] * dims_opensbliblock00Kernel025[0][1];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[1][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[1][0] * dims_opensbliblock00Kernel025[1][1];
  arg2 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[2][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[2][0] * dims_opensbliblock00Kernel025[2][1];
  arg3 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[3][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[3][0] * dims_opensbliblock00Kernel025[3][1];
  arg4 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[4][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[4][0] * dims_opensbliblock00Kernel025[4][1];
  arg5 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[5][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[5][0] * dims_opensbliblock00Kernel025[5][1];
  arg6 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[6][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[6][0] * dims_opensbliblock00Kernel025[6][1];
  arg7 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[7][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[7][0] * dims_opensbliblock00Kernel025[7][1];
  arg8 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[8][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[8][0] * dims_opensbliblock00Kernel025[8][1];
  arg9 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[9][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[9][0] * dims_opensbliblock00Kernel025[9][1];
  arg10 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[10][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[10][0] * dims_opensbliblock00Kernel025[10][1];
  arg11 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[11][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[11][0] * dims_opensbliblock00Kernel025[11][1];
  arg12 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[12][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[12][0] * dims_opensbliblock00Kernel025[12][1];
  arg13 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[13][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[13][0] * dims_opensbliblock00Kernel025[13][1];
  arg14 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[14][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[14][0] * dims_opensbliblock00Kernel025[14][1];
  arg15 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[15][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[15][0] * dims_opensbliblock00Kernel025[15][1];
  arg16 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel025[16][0] + idx_z * 1*1 * dims_opensbliblock00Kernel025[16][0] * dims_opensbliblock00Kernel025[16][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ACC<double> argp0(dims_opensbliblock00Kernel025[0][0], dims_opensbliblock00Kernel025[0][1], arg0);
    const ACC<double> argp1(dims_opensbliblock00Kernel025[1][0], dims_opensbliblock00Kernel025[1][1], arg1);
    const ACC<double> argp2(dims_opensbliblock00Kernel025[2][0], dims_opensbliblock00Kernel025[2][1], arg2);
    const ACC<double> argp3(dims_opensbliblock00Kernel025[3][0], dims_opensbliblock00Kernel025[3][1], arg3);
    const ACC<double> argp4(dims_opensbliblock00Kernel025[4][0], dims_opensbliblock00Kernel025[4][1], arg4);
    const ACC<double> argp5(dims_opensbliblock00Kernel025[5][0], dims_opensbliblock00Kernel025[5][1], arg5);
    const ACC<double> argp6(dims_opensbliblock00Kernel025[6][0], dims_opensbliblock00Kernel025[6][1], arg6);
    const ACC<double> argp7(dims_opensbliblock00Kernel025[7][0], dims_opensbliblock00Kernel025[7][1], arg7);
    const ACC<double> argp8(dims_opensbliblock00Kernel025[8][0], dims_opensbliblock00Kernel025[8][1], arg8);
    const ACC<double> argp9(dims_opensbliblock00Kernel025[9][0], dims_opensbliblock00Kernel025[9][1], arg9);
    const ACC<double> argp10(dims_opensbliblock00Kernel025[10][0], dims_opensbliblock00Kernel025[10][1], arg10);
    const ACC<double> argp11(dims_opensbliblock00Kernel025[11][0], dims_opensbliblock00Kernel025[11][1], arg11);
    const ACC<double> argp12(dims_opensbliblock00Kernel025[12][0], dims_opensbliblock00Kernel025[12][1], arg12);
    ACC<double> argp13(dims_opensbliblock00Kernel025[13][0], dims_opensbliblock00Kernel025[13][1], arg13);
    ACC<double> argp14(dims_opensbliblock00Kernel025[14][0], dims_opensbliblock00Kernel025[14][1], arg14);
    ACC<double> argp15(dims_opensbliblock00Kernel025[15][0], dims_opensbliblock00Kernel025[15][1], arg15);
    ACC<double> argp16(dims_opensbliblock00Kernel025[16][0], dims_opensbliblock00Kernel025[16][1], arg16);
    opensbliblock00Kernel025_gpu(argp0, argp1, argp2, argp3,
                   argp4, argp5, argp6, argp7, argp8,
                   argp9, argp10, argp11, argp12, argp13,
                   argp14, argp15, argp16);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel025(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8,
 ops_arg arg9, ops_arg arg10, ops_arg arg11, ops_arg arg12, ops_arg arg13,
 ops_arg arg14, ops_arg arg15, ops_arg arg16) {
#else
void ops_par_loop_opensbliblock00Kernel025_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  ops_arg arg7 = desc->args[7];
  ops_arg arg8 = desc->args[8];
  ops_arg arg9 = desc->args[9];
  ops_arg arg10 = desc->args[10];
  ops_arg arg11 = desc->args[11];
  ops_arg arg12 = desc->args[12];
  ops_arg arg13 = desc->args[13];
  ops_arg arg14 = desc->args[14];
  ops_arg arg15 = desc->args[15];
  ops_arg arg16 = desc->args[16];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[17] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,17,range,23)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,23,"opensbliblock00Kernel025");
    block->instance->OPS_kernels[23].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  #ifdef OPS_MPI
  int arg_idx[3];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 17,block, range, start, end, arg_idx) < 0) return;
  #endif

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0];
  int ydim3 = args[3].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];
  int xdim5 = args[5].dat->size[0];
  int ydim5 = args[5].dat->size[1];
  int xdim6 = args[6].dat->size[0];
  int ydim6 = args[6].dat->size[1];
  int xdim7 = args[7].dat->size[0];
  int ydim7 = args[7].dat->size[1];
  int xdim8 = args[8].dat->size[0];
  int ydim8 = args[8].dat->size[1];
  int xdim9 = args[9].dat->size[0];
  int ydim9 = args[9].dat->size[1];
  int xdim10 = args[10].dat->size[0];
  int ydim10 = args[10].dat->size[1];
  int xdim11 = args[11].dat->size[0];
  int ydim11 = args[11].dat->size[1];
  int xdim12 = args[12].dat->size[0];
  int ydim12 = args[12].dat->size[1];
  int xdim13 = args[13].dat->size[0];
  int ydim13 = args[13].dat->size[1];
  int xdim14 = args[14].dat->size[0];
  int ydim14 = args[14].dat->size[1];
  int xdim15 = args[15].dat->size[0];
  int ydim15 = args[15].dat->size[1];
  int xdim16 = args[16].dat->size[0];
  int ydim16 = args[16].dat->size[1];

  if (xdim0 != dims_opensbliblock00Kernel025_h[0][0] || ydim0 != dims_opensbliblock00Kernel025_h[0][1] || xdim1 != dims_opensbliblock00Kernel025_h[1][0] || ydim1 != dims_opensbliblock00Kernel025_h[1][1] || xdim2 != dims_opensbliblock00Kernel025_h[2][0] || ydim2 != dims_opensbliblock00Kernel025_h[2][1] || xdim3 != dims_opensbliblock00Kernel025_h[3][0] || ydim3 != dims_opensbliblock00Kernel025_h[3][1] || xdim4 != dims_opensbliblock00Kernel025_h[4][0] || ydim4 != dims_opensbliblock00Kernel025_h[4][1] || xdim5 != dims_opensbliblock00Kernel025_h[5][0] || ydim5 != dims_opensbliblock00Kernel025_h[5][1] || xdim6 != dims_opensbliblock00Kernel025_h[6][0] || ydim6 != dims_opensbliblock00Kernel025_h[6][1] || xdim7 != dims_opensbliblock00Kernel025_h[7][0] || ydim7 != dims_opensbliblock00Kernel025_h[7][1] || xdim8 != dims_opensbliblock00Kernel025_h[8][0] || ydim8 != dims_opensbliblock00Kernel025_h[8][1] || xdim9 != dims_opensbliblock00Kernel025_h[9][0] || ydim9 != dims_opensbliblock00Kernel025_h[9][1] || xdim10 != dims_opensbliblock00Kernel025_h[10][0] || ydim10 != dims_opensbliblock00Kernel025_h[10][1] || xdim11 != dims_opensbliblock00Kernel025_h[11][0] || ydim11 != dims_opensbliblock00Kernel025_h[11][1] || xdim12 != dims_opensbliblock00Kernel025_h[12][0] || ydim12 != dims_opensbliblock00Kernel025_h[12][1] || xdim13 != dims_opensbliblock00Kernel025_h[13][0] || ydim13 != dims_opensbliblock00Kernel025_h[13][1] || xdim14 != dims_opensbliblock00Kernel025_h[14][0] || ydim14 != dims_opensbliblock00Kernel025_h[14][1] || xdim15 != dims_opensbliblock00Kernel025_h[15][0] || ydim15 != dims_opensbliblock00Kernel025_h[15][1] || xdim16 != dims_opensbliblock00Kernel025_h[16][0] || ydim16 != dims_opensbliblock00Kernel025_h[16][1]) {
    dims_opensbliblock00Kernel025_h[0][0] = xdim0;
    dims_opensbliblock00Kernel025_h[0][1] = ydim0;
    dims_opensbliblock00Kernel025_h[1][0] = xdim1;
    dims_opensbliblock00Kernel025_h[1][1] = ydim1;
    dims_opensbliblock00Kernel025_h[2][0] = xdim2;
    dims_opensbliblock00Kernel025_h[2][1] = ydim2;
    dims_opensbliblock00Kernel025_h[3][0] = xdim3;
    dims_opensbliblock00Kernel025_h[3][1] = ydim3;
    dims_opensbliblock00Kernel025_h[4][0] = xdim4;
    dims_opensbliblock00Kernel025_h[4][1] = ydim4;
    dims_opensbliblock00Kernel025_h[5][0] = xdim5;
    dims_opensbliblock00Kernel025_h[5][1] = ydim5;
    dims_opensbliblock00Kernel025_h[6][0] = xdim6;
    dims_opensbliblock00Kernel025_h[6][1] = ydim6;
    dims_opensbliblock00Kernel025_h[7][0] = xdim7;
    dims_opensbliblock00Kernel025_h[7][1] = ydim7;
    dims_opensbliblock00Kernel025_h[8][0] = xdim8;
    dims_opensbliblock00Kernel025_h[8][1] = ydim8;
    dims_opensbliblock00Kernel025_h[9][0] = xdim9;
    dims_opensbliblock00Kernel025_h[9][1] = ydim9;
    dims_opensbliblock00Kernel025_h[10][0] = xdim10;
    dims_opensbliblock00Kernel025_h[10][1] = ydim10;
    dims_opensbliblock00Kernel025_h[11][0] = xdim11;
    dims_opensbliblock00Kernel025_h[11][1] = ydim11;
    dims_opensbliblock00Kernel025_h[12][0] = xdim12;
    dims_opensbliblock00Kernel025_h[12][1] = ydim12;
    dims_opensbliblock00Kernel025_h[13][0] = xdim13;
    dims_opensbliblock00Kernel025_h[13][1] = ydim13;
    dims_opensbliblock00Kernel025_h[14][0] = xdim14;
    dims_opensbliblock00Kernel025_h[14][1] = ydim14;
    dims_opensbliblock00Kernel025_h[15][0] = xdim15;
    dims_opensbliblock00Kernel025_h[15][1] = ydim15;
    dims_opensbliblock00Kernel025_h[16][0] = xdim16;
    dims_opensbliblock00Kernel025_h[16][1] = ydim16;
    hipSafeCall(block->instance->ostream(), hipMemcpyToSymbol( dims_opensbliblock00Kernel025, dims_opensbliblock00Kernel025_h, sizeof(dims_opensbliblock00Kernel025)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, (z_size-1)/block->instance->OPS_block_size_z +1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  long long int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  long long int dat2 = (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  long long int dat3 = (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  long long int dat4 = (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  long long int dat5 = (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  long long int dat6 = (block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);
  long long int dat7 = (block->instance->OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size);
  long long int dat8 = (block->instance->OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size);
  long long int dat9 = (block->instance->OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size);
  long long int dat10 = (block->instance->OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size);
  long long int dat11 = (block->instance->OPS_soa ? args[11].dat->type_size : args[11].dat->elem_size);
  long long int dat12 = (block->instance->OPS_soa ? args[12].dat->type_size : args[12].dat->elem_size);
  long long int dat13 = (block->instance->OPS_soa ? args[13].dat->type_size : args[13].dat->elem_size);
  long long int dat14 = (block->instance->OPS_soa ? args[14].dat->type_size : args[14].dat->elem_size);
  long long int dat15 = (block->instance->OPS_soa ? args[15].dat->type_size : args[15].dat->elem_size);
  long long int dat16 = (block->instance->OPS_soa ? args[16].dat->type_size : args[16].dat->elem_size);

  char *p_a[17];

  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    (start[2] * args[0].stencil->stride[2]);
  p_a[0] = (char *)args[0].data_d + base0;

  long long int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    (start[2] * args[1].stencil->stride[2]);
  p_a[1] = (char *)args[1].data_d + base1;

  long long int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    (start[2] * args[2].stencil->stride[2]);
  p_a[2] = (char *)args[2].data_d + base2;

  long long int base3 = args[3].dat->base_offset + 
           dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    (start[2] * args[3].stencil->stride[2]);
  p_a[3] = (char *)args[3].data_d + base3;

  long long int base4 = args[4].dat->base_offset + 
           dat4 * 1 * (start[0] * args[4].stencil->stride[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    (start[2] * args[4].stencil->stride[2]);
  p_a[4] = (char *)args[4].data_d + base4;

  long long int base5 = args[5].dat->base_offset + 
           dat5 * 1 * (start[0] * args[5].stencil->stride[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    (start[2] * args[5].stencil->stride[2]);
  p_a[5] = (char *)args[5].data_d + base5;

  long long int base6 = args[6].dat->base_offset + 
           dat6 * 1 * (start[0] * args[6].stencil->stride[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    (start[2] * args[6].stencil->stride[2]);
  p_a[6] = (char *)args[6].data_d + base6;

  long long int base7 = args[7].dat->base_offset + 
           dat7 * 1 * (start[0] * args[7].stencil->stride[0]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    (start[1] * args[7].stencil->stride[1]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    args[7].dat->size[1] *
    (start[2] * args[7].stencil->stride[2]);
  p_a[7] = (char *)args[7].data_d + base7;

  long long int base8 = args[8].dat->base_offset + 
           dat8 * 1 * (start[0] * args[8].stencil->stride[0]);
  base8 = base8+ dat8 *
    args[8].dat->size[0] *
    (start[1] * args[8].stencil->stride[1]);
  base8 = base8+ dat8 *
    args[8].dat->size[0] *
    args[8].dat->size[1] *
    (start[2] * args[8].stencil->stride[2]);
  p_a[8] = (char *)args[8].data_d + base8;

  long long int base9 = args[9].dat->base_offset + 
           dat9 * 1 * (start[0] * args[9].stencil->stride[0]);
  base9 = base9+ dat9 *
    args[9].dat->size[0] *
    (start[1] * args[9].stencil->stride[1]);
  base9 = base9+ dat9 *
    args[9].dat->size[0] *
    args[9].dat->size[1] *
    (start[2] * args[9].stencil->stride[2]);
  p_a[9] = (char *)args[9].data_d + base9;

  long long int base10 = args[10].dat->base_offset + 
           dat10 * 1 * (start[0] * args[10].stencil->stride[0]);
  base10 = base10+ dat10 *
    args[10].dat->size[0] *
    (start[1] * args[10].stencil->stride[1]);
  base10 = base10+ dat10 *
    args[10].dat->size[0] *
    args[10].dat->size[1] *
    (start[2] * args[10].stencil->stride[2]);
  p_a[10] = (char *)args[10].data_d + base10;

  long long int base11 = args[11].dat->base_offset + 
           dat11 * 1 * (start[0] * args[11].stencil->stride[0]);
  base11 = base11+ dat11 *
    args[11].dat->size[0] *
    (start[1] * args[11].stencil->stride[1]);
  base11 = base11+ dat11 *
    args[11].dat->size[0] *
    args[11].dat->size[1] *
    (start[2] * args[11].stencil->stride[2]);
  p_a[11] = (char *)args[11].data_d + base11;

  long long int base12 = args[12].dat->base_offset + 
           dat12 * 1 * (start[0] * args[12].stencil->stride[0]);
  base12 = base12+ dat12 *
    args[12].dat->size[0] *
    (start[1] * args[12].stencil->stride[1]);
  base12 = base12+ dat12 *
    args[12].dat->size[0] *
    args[12].dat->size[1] *
    (start[2] * args[12].stencil->stride[2]);
  p_a[12] = (char *)args[12].data_d + base12;

  long long int base13 = args[13].dat->base_offset + 
           dat13 * 1 * (start[0] * args[13].stencil->stride[0]);
  base13 = base13+ dat13 *
    args[13].dat->size[0] *
    (start[1] * args[13].stencil->stride[1]);
  base13 = base13+ dat13 *
    args[13].dat->size[0] *
    args[13].dat->size[1] *
    (start[2] * args[13].stencil->stride[2]);
  p_a[13] = (char *)args[13].data_d + base13;

  long long int base14 = args[14].dat->base_offset + 
           dat14 * 1 * (start[0] * args[14].stencil->stride[0]);
  base14 = base14+ dat14 *
    args[14].dat->size[0] *
    (start[1] * args[14].stencil->stride[1]);
  base14 = base14+ dat14 *
    args[14].dat->size[0] *
    args[14].dat->size[1] *
    (start[2] * args[14].stencil->stride[2]);
  p_a[14] = (char *)args[14].data_d + base14;

  long long int base15 = args[15].dat->base_offset + 
           dat15 * 1 * (start[0] * args[15].stencil->stride[0]);
  base15 = base15+ dat15 *
    args[15].dat->size[0] *
    (start[1] * args[15].stencil->stride[1]);
  base15 = base15+ dat15 *
    args[15].dat->size[0] *
    args[15].dat->size[1] *
    (start[2] * args[15].stencil->stride[2]);
  p_a[15] = (char *)args[15].data_d + base15;

  long long int base16 = args[16].dat->base_offset + 
           dat16 * 1 * (start[0] * args[16].stencil->stride[0]);
  base16 = base16+ dat16 *
    args[16].dat->size[0] *
    (start[1] * args[16].stencil->stride[1]);
  base16 = base16+ dat16 *
    args[16].dat->size[0] *
    args[16].dat->size[1] *
    (start[2] * args[16].stencil->stride[2]);
  p_a[16] = (char *)args[16].data_d + base16;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 17);
  ops_halo_exchanges(args,17,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[23].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_opensbliblock00Kernel025<<<grid, tblock >>> (  (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)p_a[3],
         (double *)p_a[4], (double *)p_a[5],
         (double *)p_a[6], (double *)p_a[7],
         (double *)p_a[8], (double *)p_a[9],
         (double *)p_a[10], (double *)p_a[11],
         (double *)p_a[12], (double *)p_a[13],
         (double *)p_a[14], (double *)p_a[15],
         (double *)p_a[16],x_size, y_size, z_size);

  hipSafeCall(block->instance->ostream(), hipGetLastError());

  if (block->instance->OPS_diags>1) {
    hipSafeCall(block->instance->ostream(), hipDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[23].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 17);
  ops_set_halo_dirtybit3(&args[13],range);
  ops_set_halo_dirtybit3(&args[14],range);
  ops_set_halo_dirtybit3(&args[15],range);
  ops_set_halo_dirtybit3(&args[16],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[23].mpi_time += t2-t1;
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg6);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg7);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg8);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg9);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg10);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg11);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg12);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg13);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg14);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg15);
    block->instance->OPS_kernels[23].transfer += ops_compute_transfer(dim, start, end, &arg16);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel025(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11, ops_arg arg12, ops_arg arg13, ops_arg arg14, ops_arg arg15, ops_arg arg16) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 23;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 23;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 17;
  desc->args = (ops_arg*)ops_malloc(17*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->args[7] = arg7;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg7.dat->index;
  desc->args[8] = arg8;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg8.dat->index;
  desc->args[9] = arg9;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg9.dat->index;
  desc->args[10] = arg10;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg10.dat->index;
  desc->args[11] = arg11;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg11.dat->index;
  desc->args[12] = arg12;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg12.dat->index;
  desc->args[13] = arg13;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg13.dat->index;
  desc->args[14] = arg14;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg14.dat->index;
  desc->args[15] = arg15;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg15.dat->index;
  desc->args[16] = arg16;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg16.dat->index;
  desc->function = ops_par_loop_opensbliblock00Kernel025_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,23,"opensbliblock00Kernel025");
  }
  ops_enqueue_kernel(desc);
}
#endif
