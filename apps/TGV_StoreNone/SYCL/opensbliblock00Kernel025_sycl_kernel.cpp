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

  ops_arg args[17] = { arg0, arg1, arg2, arg3, arg4,
 arg5, arg6, arg7, arg8, arg9,
 arg10, arg11, arg12, arg13, arg14,
 arg15, arg16};



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
  int base0 = args[0].dat->base_offset/sizeof(double);
  double* wk8_B0_p = (double*)args[0].data_d;

  int base1 = args[1].dat->base_offset/sizeof(double);
  double* wk3_B0_p = (double*)args[1].data_d;

  int base2 = args[2].dat->base_offset/sizeof(double);
  double* wk2_B0_p = (double*)args[2].data_d;

  int base3 = args[3].dat->base_offset/sizeof(double);
  double* u0_B0_p = (double*)args[3].data_d;

  int base4 = args[4].dat->base_offset/sizeof(double);
  double* wk1_B0_p = (double*)args[4].data_d;

  int base5 = args[5].dat->base_offset/sizeof(double);
  double* u1_B0_p = (double*)args[5].data_d;

  int base6 = args[6].dat->base_offset/sizeof(double);
  double* wk4_B0_p = (double*)args[6].data_d;

  int base7 = args[7].dat->base_offset/sizeof(double);
  double* wk7_B0_p = (double*)args[7].data_d;

  int base8 = args[8].dat->base_offset/sizeof(double);
  double* T_B0_p = (double*)args[8].data_d;

  int base9 = args[9].dat->base_offset/sizeof(double);
  double* u2_B0_p = (double*)args[9].data_d;

  int base10 = args[10].dat->base_offset/sizeof(double);
  double* wk5_B0_p = (double*)args[10].data_d;

  int base11 = args[11].dat->base_offset/sizeof(double);
  double* wk0_B0_p = (double*)args[11].data_d;

  int base12 = args[12].dat->base_offset/sizeof(double);
  double* wk6_B0_p = (double*)args[12].data_d;

  int base13 = args[13].dat->base_offset/sizeof(double);
  double* Residual4_B0_p = (double*)args[13].data_d;

  int base14 = args[14].dat->base_offset/sizeof(double);
  double* Residual1_B0_p = (double*)args[14].data_d;

  int base15 = args[15].dat->base_offset/sizeof(double);
  double* Residual3_B0_p = (double*)args[15].data_d;

  int base16 = args[16].dat->base_offset/sizeof(double);
  double* Residual2_B0_p = (double*)args[16].data_d;



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_device(args, 17);
  ops_halo_exchanges(args,17,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[23].mpi_time += __t1-__t2;
  }

  int start_0 = start[0];
  int end_0 = end[0];
  int start_1 = start[1];
  int end_1 = end[1];
  int start_2 = start[2];
  int end_2 = end[2];
  if ((end[0]-start[0])>0 && (end[1]-start[1])>0 && (end[2]-start[2])>0) {
    block->instance->sycl_instance->queue->submit([&](cl::sycl::handler &cgh) {

      auto inv_1_sycl = (*inv_1_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto inv_2_sycl = (*inv_2_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto inv_3_sycl = (*inv_3_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto inv_4_sycl = (*inv_4_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto inv_5_sycl = (*inv_5_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto rc7_sycl = (*rc7_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto rcinv8_sycl = (*rcinv8_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto rc9_sycl = (*rc9_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto rc10_sycl = (*rc10_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto rcinv11_sycl = (*rcinv11_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto rcinv12_sycl = (*rcinv12_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto rcinv13_sycl = (*rcinv13_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto rc14_sycl = (*rc14_p).template get_access<cl::sycl::access::mode::read>(cgh);

      cgh.parallel_for<class opensbliblock00Kernel025_kernel>(cl::sycl::nd_range<3>(cl::sycl::range<3>(
           ((end[2]-start[2]-1)/block->instance->OPS_block_size_z+1)*block->instance->OPS_block_size_z,
           ((end[1]-start[1]-1)/block->instance->OPS_block_size_y+1)*block->instance->OPS_block_size_y,
            ((end[0]-start[0]-1)/block->instance->OPS_block_size_x+1)*block->instance->OPS_block_size_x
             ),cl::sycl::range<3>(
             block->instance->OPS_block_size_z,
             block->instance->OPS_block_size_y,
      block->instance->OPS_block_size_x
             ))
      , [=](cl::sycl::nd_item<3> item
      ) [[intel::kernel_args_restrict]] {
        int n_z = item.get_global_id(0)+start_2;
        int n_y = item.get_global_id(1)+start_1;
        int n_x = item.get_global_id(2)+start_0;
        const ACC<double> wk8_B0(xdim0_opensbliblock00Kernel025, ydim0_opensbliblock00Kernel025, &wk8_B0_p[0] + base0 + n_x*1 + n_y * xdim0_opensbliblock00Kernel025*1 + n_z * xdim0_opensbliblock00Kernel025 * ydim0_opensbliblock00Kernel025*1);
        const ACC<double> wk3_B0(xdim1_opensbliblock00Kernel025, ydim1_opensbliblock00Kernel025, &wk3_B0_p[0] + base1 + n_x*1 + n_y * xdim1_opensbliblock00Kernel025*1 + n_z * xdim1_opensbliblock00Kernel025 * ydim1_opensbliblock00Kernel025*1);
        const ACC<double> wk2_B0(xdim2_opensbliblock00Kernel025, ydim2_opensbliblock00Kernel025, &wk2_B0_p[0] + base2 + n_x*1 + n_y * xdim2_opensbliblock00Kernel025*1 + n_z * xdim2_opensbliblock00Kernel025 * ydim2_opensbliblock00Kernel025*1);
        const ACC<double> u0_B0(xdim3_opensbliblock00Kernel025, ydim3_opensbliblock00Kernel025, &u0_B0_p[0] + base3 + n_x*1 + n_y * xdim3_opensbliblock00Kernel025*1 + n_z * xdim3_opensbliblock00Kernel025 * ydim3_opensbliblock00Kernel025*1);
        const ACC<double> wk1_B0(xdim4_opensbliblock00Kernel025, ydim4_opensbliblock00Kernel025, &wk1_B0_p[0] + base4 + n_x*1 + n_y * xdim4_opensbliblock00Kernel025*1 + n_z * xdim4_opensbliblock00Kernel025 * ydim4_opensbliblock00Kernel025*1);
        const ACC<double> u1_B0(xdim5_opensbliblock00Kernel025, ydim5_opensbliblock00Kernel025, &u1_B0_p[0] + base5 + n_x*1 + n_y * xdim5_opensbliblock00Kernel025*1 + n_z * xdim5_opensbliblock00Kernel025 * ydim5_opensbliblock00Kernel025*1);
        const ACC<double> wk4_B0(xdim6_opensbliblock00Kernel025, ydim6_opensbliblock00Kernel025, &wk4_B0_p[0] + base6 + n_x*1 + n_y * xdim6_opensbliblock00Kernel025*1 + n_z * xdim6_opensbliblock00Kernel025 * ydim6_opensbliblock00Kernel025*1);
        const ACC<double> wk7_B0(xdim7_opensbliblock00Kernel025, ydim7_opensbliblock00Kernel025, &wk7_B0_p[0] + base7 + n_x*1 + n_y * xdim7_opensbliblock00Kernel025*1 + n_z * xdim7_opensbliblock00Kernel025 * ydim7_opensbliblock00Kernel025*1);
        const ACC<double> T_B0(xdim8_opensbliblock00Kernel025, ydim8_opensbliblock00Kernel025, &T_B0_p[0] + base8 + n_x*1 + n_y * xdim8_opensbliblock00Kernel025*1 + n_z * xdim8_opensbliblock00Kernel025 * ydim8_opensbliblock00Kernel025*1);
        const ACC<double> u2_B0(xdim9_opensbliblock00Kernel025, ydim9_opensbliblock00Kernel025, &u2_B0_p[0] + base9 + n_x*1 + n_y * xdim9_opensbliblock00Kernel025*1 + n_z * xdim9_opensbliblock00Kernel025 * ydim9_opensbliblock00Kernel025*1);
        const ACC<double> wk5_B0(xdim10_opensbliblock00Kernel025, ydim10_opensbliblock00Kernel025, &wk5_B0_p[0] + base10 + n_x*1 + n_y * xdim10_opensbliblock00Kernel025*1 + n_z * xdim10_opensbliblock00Kernel025 * ydim10_opensbliblock00Kernel025*1);
        const ACC<double> wk0_B0(xdim11_opensbliblock00Kernel025, ydim11_opensbliblock00Kernel025, &wk0_B0_p[0] + base11 + n_x*1 + n_y * xdim11_opensbliblock00Kernel025*1 + n_z * xdim11_opensbliblock00Kernel025 * ydim11_opensbliblock00Kernel025*1);
        const ACC<double> wk6_B0(xdim12_opensbliblock00Kernel025, ydim12_opensbliblock00Kernel025, &wk6_B0_p[0] + base12 + n_x*1 + n_y * xdim12_opensbliblock00Kernel025*1 + n_z * xdim12_opensbliblock00Kernel025 * ydim12_opensbliblock00Kernel025*1);
        ACC<double> Residual4_B0(xdim13_opensbliblock00Kernel025, ydim13_opensbliblock00Kernel025, &Residual4_B0_p[0] + base13 + n_x*1 + n_y * xdim13_opensbliblock00Kernel025*1 + n_z * xdim13_opensbliblock00Kernel025 * ydim13_opensbliblock00Kernel025*1);
        ACC<double> Residual1_B0(xdim14_opensbliblock00Kernel025, ydim14_opensbliblock00Kernel025, &Residual1_B0_p[0] + base14 + n_x*1 + n_y * xdim14_opensbliblock00Kernel025*1 + n_z * xdim14_opensbliblock00Kernel025 * ydim14_opensbliblock00Kernel025*1);
        ACC<double> Residual3_B0(xdim15_opensbliblock00Kernel025, ydim15_opensbliblock00Kernel025, &Residual3_B0_p[0] + base15 + n_x*1 + n_y * xdim15_opensbliblock00Kernel025*1 + n_z * xdim15_opensbliblock00Kernel025 * ydim15_opensbliblock00Kernel025*1);
        ACC<double> Residual2_B0(xdim16_opensbliblock00Kernel025, ydim16_opensbliblock00Kernel025, &Residual2_B0_p[0] + base16 + n_x*1 + n_y * xdim16_opensbliblock00Kernel025*1 + n_z * xdim16_opensbliblock00Kernel025 * ydim16_opensbliblock00Kernel025*1);
        //USER CODE
        if (n_x < end_0 && n_y < end_1 && n_z < end_2) {
          
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
    localeval_0 = (rc7_sycl[0])*inv_3_sycl[0]*(16*T_B0(1,0,0) - 30*T_B0(0,0,0) - T_B0(2,0,0) -
      T_B0(-2,0,0) + 16*T_B0(-1,0,0));

    localeval_1 = (rc7_sycl[0])*inv_4_sycl[0]*(16*T_B0(0,1,0) - 30*T_B0(0,0,0) - T_B0(0,-2,0) -
      T_B0(0,2,0) + 16*T_B0(0,-1,0));

    localeval_2 = (rc7_sycl[0])*inv_5_sycl[0]*(-T_B0(0,0,-2) + 16*T_B0(0,0,-1) - 30*T_B0(0,0,0) -
      T_B0(0,0,2) + 16*T_B0(0,0,1));

    localeval_3 = (rc7_sycl[0])*inv_4_sycl[0]*(-u0_B0(0,2,0) + 16*u0_B0(0,1,0) - 30*u0_B0(0,0,0) +
      16*u0_B0(0,-1,0) - u0_B0(0,-2,0));

    localeval_4 = (rc7_sycl[0])*inv_5_sycl[0]*(16*u0_B0(0,0,1) - 30*u0_B0(0,0,0) + 16*u0_B0(0,0,-1) -
      u0_B0(0,0,-2) - u0_B0(0,0,2));

    localeval_5 = (rc7_sycl[0])*inv_3_sycl[0]*(-u0_B0(2,0,0) + 16*u0_B0(1,0,0) - 30*u0_B0(0,0,0) +
      16*u0_B0(-1,0,0) - u0_B0(-2,0,0));

    localeval_6 = (rc7_sycl[0])*inv_4_sycl[0]*(16*u1_B0(0,1,0) - u1_B0(0,2,0) - u1_B0(0,-2,0) +
      16*u1_B0(0,-1,0) - 30*u1_B0(0,0,0));

    localeval_7 = (rc7_sycl[0])*inv_3_sycl[0]*(16*u1_B0(1,0,0) - u1_B0(2,0,0) - u1_B0(-2,0,0) +
      16*u1_B0(-1,0,0) - 30*u1_B0(0,0,0));

    localeval_8 = (rc7_sycl[0])*inv_5_sycl[0]*(16*u1_B0(0,0,1) - u1_B0(0,0,2) - u1_B0(0,0,-2) +
      16*u1_B0(0,0,-1) - 30*u1_B0(0,0,0));

    localeval_9 = (rc7_sycl[0])*inv_5_sycl[0]*(-u2_B0(0,0,2) + 16*u2_B0(0,0,-1) - u2_B0(0,0,-2) -
      30*u2_B0(0,0,0) + 16*u2_B0(0,0,1));

    localeval_10 = (rc7_sycl[0])*inv_3_sycl[0]*(16*u2_B0(-1,0,0) - u2_B0(-2,0,0) - 30*u2_B0(0,0,0) +
      16*u2_B0(1,0,0) - u2_B0(2,0,0));

    localeval_11 = (rc7_sycl[0])*inv_4_sycl[0]*(16*u2_B0(0,-1,0) - u2_B0(0,-2,0) - 30*u2_B0(0,0,0) +
      16*u2_B0(0,1,0) - u2_B0(0,2,0));

    localeval_12 = (rc7_sycl[0])*inv_2_sycl[0]*(-wk0_B0(0,2,0) + wk0_B0(0,-2,0) - 8*wk0_B0(0,-1,0) +
      8*wk0_B0(0,1,0));

    localeval_13 = (rc7_sycl[0])*inv_1_sycl[0]*(wk0_B0(0,0,-2) - wk0_B0(0,0,2) + 8*wk0_B0(0,0,1) -
      8*wk0_B0(0,0,-1));

    localeval_14 = (rc7_sycl[0])*inv_2_sycl[0]*(-wk3_B0(0,2,0) + wk3_B0(0,-2,0) + 8*wk3_B0(0,1,0) -
      8*wk3_B0(0,-1,0));

    localeval_15 = (rc7_sycl[0])*inv_1_sycl[0]*(8*wk5_B0(0,0,1) - wk5_B0(0,0,2) + wk5_B0(0,0,-2) -
      8*wk5_B0(0,0,-1));

    localeval_16 = (rc7_sycl[0])*inv_1_sycl[0]*(-8*wk6_B0(0,0,-1) - wk6_B0(0,0,2) + wk6_B0(0,0,-2) +
      8*wk6_B0(0,0,1));

    localeval_17 = (rc7_sycl[0])*inv_1_sycl[0]*(-wk8_B0(0,0,2) + 8*wk8_B0(0,0,1) - 8*wk8_B0(0,0,-1) +
      wk8_B0(0,0,-2));

    Residual1_B0(0,0,0) = 1.0*rcinv8_sycl[0]*((rc9_sycl[0])*localeval_14 + (rc9_sycl[0])*localeval_16 + localeval_3 + localeval_4 +
      (rc10_sycl[0])*localeval_5) + Residual1_B0(0,0,0);

    Residual2_B0(0,0,0) = 1.0*rcinv8_sycl[0]*((rc9_sycl[0])*localeval_12 + (rc9_sycl[0])*localeval_17 + (rc10_sycl[0])*localeval_6 +
      localeval_7 + localeval_8) + Residual2_B0(0,0,0);

    Residual3_B0(0,0,0) = 1.0*rcinv8_sycl[0]*(localeval_10 + localeval_11 + (rc9_sycl[0])*localeval_13 + (rc9_sycl[0])*localeval_15 +
      (rc10_sycl[0])*localeval_9) + Residual3_B0(0,0,0);

    Residual4_B0(0,0,0) = 1.0*rcinv11_sycl[0]*rcinv12_sycl[0]*rcinv13_sycl[0]*rcinv8_sycl[0]*(localeval_0 + localeval_1 + localeval_2) +
      1.0*rcinv8_sycl[0]*(wk1_B0(0,0,0) + wk6_B0(0,0,0))*wk1_B0(0,0,0) +
      1.0*rcinv8_sycl[0]*(wk1_B0(0,0,0) + wk6_B0(0,0,0))*wk6_B0(0,0,0) +
      1.0*rcinv8_sycl[0]*(wk2_B0(0,0,0) + wk3_B0(0,0,0))*wk2_B0(0,0,0) +
      1.0*rcinv8_sycl[0]*(wk2_B0(0,0,0) + wk3_B0(0,0,0))*wk3_B0(0,0,0) +
      1.0*rcinv8_sycl[0]*(wk4_B0(0,0,0) + wk8_B0(0,0,0))*wk4_B0(0,0,0) +
      1.0*rcinv8_sycl[0]*(wk4_B0(0,0,0) + wk8_B0(0,0,0))*wk8_B0(0,0,0) +
      1.0*rcinv8_sycl[0]*(-rc14_sycl[0]*wk0_B0(0,0,0) - rc14_sycl[0]*wk5_B0(0,0,0) +
      (rc10_sycl[0])*wk7_B0(0,0,0))*wk7_B0(0,0,0) + 1.0*rcinv8_sycl[0]*(-rc14_sycl[0]*wk0_B0(0,0,0) +
      (rc10_sycl[0])*wk5_B0(0,0,0) - rc14_sycl[0]*wk7_B0(0,0,0))*wk5_B0(0,0,0) +
      1.0*rcinv8_sycl[0]*((rc10_sycl[0])*wk0_B0(0,0,0) - rc14_sycl[0]*wk5_B0(0,0,0) -
      rc14_sycl[0]*wk7_B0(0,0,0))*wk0_B0(0,0,0) + 1.0*rcinv8_sycl[0]*(localeval_10 + localeval_11 +
      (rc9_sycl[0])*localeval_13 + (rc9_sycl[0])*localeval_15 + (rc10_sycl[0])*localeval_9)*u2_B0(0,0,0) +
      1.0*rcinv8_sycl[0]*((rc9_sycl[0])*localeval_12 + (rc9_sycl[0])*localeval_17 + (rc10_sycl[0])*localeval_6 + localeval_7 +
      localeval_8)*u1_B0(0,0,0) + 1.0*rcinv8_sycl[0]*((rc9_sycl[0])*localeval_14 + (rc9_sycl[0])*localeval_16 + localeval_3 +
      localeval_4 + (rc10_sycl[0])*localeval_5)*u0_B0(0,0,0) + Residual4_B0(0,0,0);


        }
      });
    });
  }
  if (block->instance->OPS_diags > 1) {
    block->instance->sycl_instance->queue->wait();
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[23].time += __t2-__t1;
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
