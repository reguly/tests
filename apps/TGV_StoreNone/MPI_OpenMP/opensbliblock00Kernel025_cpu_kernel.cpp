//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel025(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13, ops_arg arg14, ops_arg arg15,
 ops_arg arg16) {
#else
void ops_par_loop_opensbliblock00Kernel025_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
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
  double __t1,__t2,__c1,__c2;

  ops_arg args[17] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,17,range,23)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,23,"opensbliblock00Kernel025");
    block->instance->OPS_kernels[23].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "opensbliblock00Kernel025");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
  int arg_idx[3];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 17,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_opensbliblock00Kernel025 = args[0].dat->size[0];
  int ydim0_opensbliblock00Kernel025 = args[0].dat->size[1];
  int xdim1_opensbliblock00Kernel025 = args[1].dat->size[0];
  int ydim1_opensbliblock00Kernel025 = args[1].dat->size[1];
  int xdim2_opensbliblock00Kernel025 = args[2].dat->size[0];
  int ydim2_opensbliblock00Kernel025 = args[2].dat->size[1];
  int xdim3_opensbliblock00Kernel025 = args[3].dat->size[0];
  int ydim3_opensbliblock00Kernel025 = args[3].dat->size[1];
  int xdim4_opensbliblock00Kernel025 = args[4].dat->size[0];
  int ydim4_opensbliblock00Kernel025 = args[4].dat->size[1];
  int xdim5_opensbliblock00Kernel025 = args[5].dat->size[0];
  int ydim5_opensbliblock00Kernel025 = args[5].dat->size[1];
  int xdim6_opensbliblock00Kernel025 = args[6].dat->size[0];
  int ydim6_opensbliblock00Kernel025 = args[6].dat->size[1];
  int xdim7_opensbliblock00Kernel025 = args[7].dat->size[0];
  int ydim7_opensbliblock00Kernel025 = args[7].dat->size[1];
  int xdim8_opensbliblock00Kernel025 = args[8].dat->size[0];
  int ydim8_opensbliblock00Kernel025 = args[8].dat->size[1];
  int xdim9_opensbliblock00Kernel025 = args[9].dat->size[0];
  int ydim9_opensbliblock00Kernel025 = args[9].dat->size[1];
  int xdim10_opensbliblock00Kernel025 = args[10].dat->size[0];
  int ydim10_opensbliblock00Kernel025 = args[10].dat->size[1];
  int xdim11_opensbliblock00Kernel025 = args[11].dat->size[0];
  int ydim11_opensbliblock00Kernel025 = args[11].dat->size[1];
  int xdim12_opensbliblock00Kernel025 = args[12].dat->size[0];
  int ydim12_opensbliblock00Kernel025 = args[12].dat->size[1];
  int xdim13_opensbliblock00Kernel025 = args[13].dat->size[0];
  int ydim13_opensbliblock00Kernel025 = args[13].dat->size[1];
  int xdim14_opensbliblock00Kernel025 = args[14].dat->size[0];
  int ydim14_opensbliblock00Kernel025 = args[14].dat->size[1];
  int xdim15_opensbliblock00Kernel025 = args[15].dat->size[0];
  int ydim15_opensbliblock00Kernel025 = args[15].dat->size[1];
  int xdim16_opensbliblock00Kernel025 = args[16].dat->size[0];
  int ydim16_opensbliblock00Kernel025 = args[16].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ wk8_B0_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ wk3_B0_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ wk2_B0_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ u0_B0_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ wk1_B0_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ u1_B0_p = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ wk4_B0_p = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ wk7_B0_p = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset;
  double * __restrict__ T_B0_p = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset;
  double * __restrict__ u2_B0_p = (double *)(args[9].data + base9);

  int base10 = args[10].dat->base_offset;
  double * __restrict__ wk5_B0_p = (double *)(args[10].data + base10);

  int base11 = args[11].dat->base_offset;
  double * __restrict__ wk0_B0_p = (double *)(args[11].data + base11);

  int base12 = args[12].dat->base_offset;
  double * __restrict__ wk6_B0_p = (double *)(args[12].data + base12);

  int base13 = args[13].dat->base_offset;
  double * __restrict__ Residual4_B0_p = (double *)(args[13].data + base13);

  int base14 = args[14].dat->base_offset;
  double * __restrict__ Residual1_B0_p = (double *)(args[14].data + base14);

  int base15 = args[15].dat->base_offset;
  double * __restrict__ Residual3_B0_p = (double *)(args[15].data + base15);

  int base16 = args[16].dat->base_offset;
  double * __restrict__ Residual2_B0_p = (double *)(args[16].data + base16);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 17);
  ops_halo_exchanges(args,17,range);
  ops_H_D_exchanges_host(args, 17);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[23].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef __INTEL_COMPILER
      #pragma loop_count(10000)
      #pragma omp simd
      #elif defined(__clang__)
      #pragma clang loop vectorize(assume_safety)
      #elif defined(__GNUC__)
      #pragma GCC ivdep
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        const ACC<double> wk8_B0(xdim0_opensbliblock00Kernel025, ydim0_opensbliblock00Kernel025, wk8_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel025*1 + n_z * xdim0_opensbliblock00Kernel025 * ydim0_opensbliblock00Kernel025*1);
        const ACC<double> wk3_B0(xdim1_opensbliblock00Kernel025, ydim1_opensbliblock00Kernel025, wk3_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel025*1 + n_z * xdim1_opensbliblock00Kernel025 * ydim1_opensbliblock00Kernel025*1);
        const ACC<double> wk2_B0(xdim2_opensbliblock00Kernel025, ydim2_opensbliblock00Kernel025, wk2_B0_p + n_x*1 + n_y * xdim2_opensbliblock00Kernel025*1 + n_z * xdim2_opensbliblock00Kernel025 * ydim2_opensbliblock00Kernel025*1);
        const ACC<double> u0_B0(xdim3_opensbliblock00Kernel025, ydim3_opensbliblock00Kernel025, u0_B0_p + n_x*1 + n_y * xdim3_opensbliblock00Kernel025*1 + n_z * xdim3_opensbliblock00Kernel025 * ydim3_opensbliblock00Kernel025*1);
        const ACC<double> wk1_B0(xdim4_opensbliblock00Kernel025, ydim4_opensbliblock00Kernel025, wk1_B0_p + n_x*1 + n_y * xdim4_opensbliblock00Kernel025*1 + n_z * xdim4_opensbliblock00Kernel025 * ydim4_opensbliblock00Kernel025*1);
        const ACC<double> u1_B0(xdim5_opensbliblock00Kernel025, ydim5_opensbliblock00Kernel025, u1_B0_p + n_x*1 + n_y * xdim5_opensbliblock00Kernel025*1 + n_z * xdim5_opensbliblock00Kernel025 * ydim5_opensbliblock00Kernel025*1);
        const ACC<double> wk4_B0(xdim6_opensbliblock00Kernel025, ydim6_opensbliblock00Kernel025, wk4_B0_p + n_x*1 + n_y * xdim6_opensbliblock00Kernel025*1 + n_z * xdim6_opensbliblock00Kernel025 * ydim6_opensbliblock00Kernel025*1);
        const ACC<double> wk7_B0(xdim7_opensbliblock00Kernel025, ydim7_opensbliblock00Kernel025, wk7_B0_p + n_x*1 + n_y * xdim7_opensbliblock00Kernel025*1 + n_z * xdim7_opensbliblock00Kernel025 * ydim7_opensbliblock00Kernel025*1);
        const ACC<double> T_B0(xdim8_opensbliblock00Kernel025, ydim8_opensbliblock00Kernel025, T_B0_p + n_x*1 + n_y * xdim8_opensbliblock00Kernel025*1 + n_z * xdim8_opensbliblock00Kernel025 * ydim8_opensbliblock00Kernel025*1);
        const ACC<double> u2_B0(xdim9_opensbliblock00Kernel025, ydim9_opensbliblock00Kernel025, u2_B0_p + n_x*1 + n_y * xdim9_opensbliblock00Kernel025*1 + n_z * xdim9_opensbliblock00Kernel025 * ydim9_opensbliblock00Kernel025*1);
        const ACC<double> wk5_B0(xdim10_opensbliblock00Kernel025, ydim10_opensbliblock00Kernel025, wk5_B0_p + n_x*1 + n_y * xdim10_opensbliblock00Kernel025*1 + n_z * xdim10_opensbliblock00Kernel025 * ydim10_opensbliblock00Kernel025*1);
        const ACC<double> wk0_B0(xdim11_opensbliblock00Kernel025, ydim11_opensbliblock00Kernel025, wk0_B0_p + n_x*1 + n_y * xdim11_opensbliblock00Kernel025*1 + n_z * xdim11_opensbliblock00Kernel025 * ydim11_opensbliblock00Kernel025*1);
        const ACC<double> wk6_B0(xdim12_opensbliblock00Kernel025, ydim12_opensbliblock00Kernel025, wk6_B0_p + n_x*1 + n_y * xdim12_opensbliblock00Kernel025*1 + n_z * xdim12_opensbliblock00Kernel025 * ydim12_opensbliblock00Kernel025*1);
        ACC<double> Residual4_B0(xdim13_opensbliblock00Kernel025, ydim13_opensbliblock00Kernel025, Residual4_B0_p + n_x*1 + n_y * xdim13_opensbliblock00Kernel025*1 + n_z * xdim13_opensbliblock00Kernel025 * ydim13_opensbliblock00Kernel025*1);
        ACC<double> Residual1_B0(xdim14_opensbliblock00Kernel025, ydim14_opensbliblock00Kernel025, Residual1_B0_p + n_x*1 + n_y * xdim14_opensbliblock00Kernel025*1 + n_z * xdim14_opensbliblock00Kernel025 * ydim14_opensbliblock00Kernel025*1);
        ACC<double> Residual3_B0(xdim15_opensbliblock00Kernel025, ydim15_opensbliblock00Kernel025, Residual3_B0_p + n_x*1 + n_y * xdim15_opensbliblock00Kernel025*1 + n_z * xdim15_opensbliblock00Kernel025 * ydim15_opensbliblock00Kernel025*1);
        ACC<double> Residual2_B0(xdim16_opensbliblock00Kernel025, ydim16_opensbliblock00Kernel025, Residual2_B0_p + n_x*1 + n_y * xdim16_opensbliblock00Kernel025*1 + n_z * xdim16_opensbliblock00Kernel025 * ydim16_opensbliblock00Kernel025*1);
        
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
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[23].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 17);
  ops_set_halo_dirtybit3(&args[13],range);
  ops_set_halo_dirtybit3(&args[14],range);
  ops_set_halo_dirtybit3(&args[15],range);
  ops_set_halo_dirtybit3(&args[16],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[23].mpi_time += __t1-__t2;
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
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13, ops_arg arg14, ops_arg arg15,
 ops_arg arg16) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
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
