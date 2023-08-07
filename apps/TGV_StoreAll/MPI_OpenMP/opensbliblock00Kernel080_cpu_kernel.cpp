//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel080(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13, ops_arg arg14, ops_arg arg15,
 ops_arg arg16, ops_arg arg17, ops_arg arg18, ops_arg arg19,
 ops_arg arg20, ops_arg arg21, ops_arg arg22, ops_arg arg23,
 ops_arg arg24, ops_arg arg25, ops_arg arg26, ops_arg arg27,
 ops_arg arg28, ops_arg arg29, ops_arg arg30, ops_arg arg31,
 ops_arg arg32, ops_arg arg33) {
#else
void ops_par_loop_opensbliblock00Kernel080_execute(ops_kernel_descriptor *desc) {
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
  ops_arg arg17 = desc->args[17];
  ops_arg arg18 = desc->args[18];
  ops_arg arg19 = desc->args[19];
  ops_arg arg20 = desc->args[20];
  ops_arg arg21 = desc->args[21];
  ops_arg arg22 = desc->args[22];
  ops_arg arg23 = desc->args[23];
  ops_arg arg24 = desc->args[24];
  ops_arg arg25 = desc->args[25];
  ops_arg arg26 = desc->args[26];
  ops_arg arg27 = desc->args[27];
  ops_arg arg28 = desc->args[28];
  ops_arg arg29 = desc->args[29];
  ops_arg arg30 = desc->args[30];
  ops_arg arg31 = desc->args[31];
  ops_arg arg32 = desc->args[32];
  ops_arg arg33 = desc->args[33];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[34] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,34,range,83)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,83,"opensbliblock00Kernel080");
    block->instance->OPS_kernels[83].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "opensbliblock00Kernel080");
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
  if (compute_ranges(args, 34,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_opensbliblock00Kernel080 = args[0].dat->size[0];
  int ydim0_opensbliblock00Kernel080 = args[0].dat->size[1];
  int xdim1_opensbliblock00Kernel080 = args[1].dat->size[0];
  int ydim1_opensbliblock00Kernel080 = args[1].dat->size[1];
  int xdim2_opensbliblock00Kernel080 = args[2].dat->size[0];
  int ydim2_opensbliblock00Kernel080 = args[2].dat->size[1];
  int xdim3_opensbliblock00Kernel080 = args[3].dat->size[0];
  int ydim3_opensbliblock00Kernel080 = args[3].dat->size[1];
  int xdim4_opensbliblock00Kernel080 = args[4].dat->size[0];
  int ydim4_opensbliblock00Kernel080 = args[4].dat->size[1];
  int xdim5_opensbliblock00Kernel080 = args[5].dat->size[0];
  int ydim5_opensbliblock00Kernel080 = args[5].dat->size[1];
  int xdim6_opensbliblock00Kernel080 = args[6].dat->size[0];
  int ydim6_opensbliblock00Kernel080 = args[6].dat->size[1];
  int xdim7_opensbliblock00Kernel080 = args[7].dat->size[0];
  int ydim7_opensbliblock00Kernel080 = args[7].dat->size[1];
  int xdim8_opensbliblock00Kernel080 = args[8].dat->size[0];
  int ydim8_opensbliblock00Kernel080 = args[8].dat->size[1];
  int xdim9_opensbliblock00Kernel080 = args[9].dat->size[0];
  int ydim9_opensbliblock00Kernel080 = args[9].dat->size[1];
  int xdim10_opensbliblock00Kernel080 = args[10].dat->size[0];
  int ydim10_opensbliblock00Kernel080 = args[10].dat->size[1];
  int xdim11_opensbliblock00Kernel080 = args[11].dat->size[0];
  int ydim11_opensbliblock00Kernel080 = args[11].dat->size[1];
  int xdim12_opensbliblock00Kernel080 = args[12].dat->size[0];
  int ydim12_opensbliblock00Kernel080 = args[12].dat->size[1];
  int xdim13_opensbliblock00Kernel080 = args[13].dat->size[0];
  int ydim13_opensbliblock00Kernel080 = args[13].dat->size[1];
  int xdim14_opensbliblock00Kernel080 = args[14].dat->size[0];
  int ydim14_opensbliblock00Kernel080 = args[14].dat->size[1];
  int xdim15_opensbliblock00Kernel080 = args[15].dat->size[0];
  int ydim15_opensbliblock00Kernel080 = args[15].dat->size[1];
  int xdim16_opensbliblock00Kernel080 = args[16].dat->size[0];
  int ydim16_opensbliblock00Kernel080 = args[16].dat->size[1];
  int xdim17_opensbliblock00Kernel080 = args[17].dat->size[0];
  int ydim17_opensbliblock00Kernel080 = args[17].dat->size[1];
  int xdim18_opensbliblock00Kernel080 = args[18].dat->size[0];
  int ydim18_opensbliblock00Kernel080 = args[18].dat->size[1];
  int xdim19_opensbliblock00Kernel080 = args[19].dat->size[0];
  int ydim19_opensbliblock00Kernel080 = args[19].dat->size[1];
  int xdim20_opensbliblock00Kernel080 = args[20].dat->size[0];
  int ydim20_opensbliblock00Kernel080 = args[20].dat->size[1];
  int xdim21_opensbliblock00Kernel080 = args[21].dat->size[0];
  int ydim21_opensbliblock00Kernel080 = args[21].dat->size[1];
  int xdim22_opensbliblock00Kernel080 = args[22].dat->size[0];
  int ydim22_opensbliblock00Kernel080 = args[22].dat->size[1];
  int xdim23_opensbliblock00Kernel080 = args[23].dat->size[0];
  int ydim23_opensbliblock00Kernel080 = args[23].dat->size[1];
  int xdim24_opensbliblock00Kernel080 = args[24].dat->size[0];
  int ydim24_opensbliblock00Kernel080 = args[24].dat->size[1];
  int xdim25_opensbliblock00Kernel080 = args[25].dat->size[0];
  int ydim25_opensbliblock00Kernel080 = args[25].dat->size[1];
  int xdim26_opensbliblock00Kernel080 = args[26].dat->size[0];
  int ydim26_opensbliblock00Kernel080 = args[26].dat->size[1];
  int xdim27_opensbliblock00Kernel080 = args[27].dat->size[0];
  int ydim27_opensbliblock00Kernel080 = args[27].dat->size[1];
  int xdim28_opensbliblock00Kernel080 = args[28].dat->size[0];
  int ydim28_opensbliblock00Kernel080 = args[28].dat->size[1];
  int xdim29_opensbliblock00Kernel080 = args[29].dat->size[0];
  int ydim29_opensbliblock00Kernel080 = args[29].dat->size[1];
  int xdim30_opensbliblock00Kernel080 = args[30].dat->size[0];
  int ydim30_opensbliblock00Kernel080 = args[30].dat->size[1];
  int xdim31_opensbliblock00Kernel080 = args[31].dat->size[0];
  int ydim31_opensbliblock00Kernel080 = args[31].dat->size[1];
  int xdim32_opensbliblock00Kernel080 = args[32].dat->size[0];
  int ydim32_opensbliblock00Kernel080 = args[32].dat->size[1];
  int xdim33_opensbliblock00Kernel080 = args[33].dat->size[0];
  int ydim33_opensbliblock00Kernel080 = args[33].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ wk10_B0_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ wk11_B0_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ u0_B0_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ wk25_B0_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ wk16_B0_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ wk9_B0_p = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ u1_B0_p = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ wk6_B0_p = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset;
  double * __restrict__ wk21_B0_p = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset;
  double * __restrict__ wk26_B0_p = (double *)(args[9].data + base9);

  int base10 = args[10].dat->base_offset;
  double * __restrict__ wk24_B0_p = (double *)(args[10].data + base10);

  int base11 = args[11].dat->base_offset;
  double * __restrict__ wk5_B0_p = (double *)(args[11].data + base11);

  int base12 = args[12].dat->base_offset;
  double * __restrict__ wk3_B0_p = (double *)(args[12].data + base12);

  int base13 = args[13].dat->base_offset;
  double * __restrict__ wk1_B0_p = (double *)(args[13].data + base13);

  int base14 = args[14].dat->base_offset;
  double * __restrict__ u2_B0_p = (double *)(args[14].data + base14);

  int base15 = args[15].dat->base_offset;
  double * __restrict__ wk13_B0_p = (double *)(args[15].data + base15);

  int base16 = args[16].dat->base_offset;
  double * __restrict__ wk20_B0_p = (double *)(args[16].data + base16);

  int base17 = args[17].dat->base_offset;
  double * __restrict__ wk18_B0_p = (double *)(args[17].data + base17);

  int base18 = args[18].dat->base_offset;
  double * __restrict__ wk22_B0_p = (double *)(args[18].data + base18);

  int base19 = args[19].dat->base_offset;
  double * __restrict__ wk23_B0_p = (double *)(args[19].data + base19);

  int base20 = args[20].dat->base_offset;
  double * __restrict__ wk17_B0_p = (double *)(args[20].data + base20);

  int base21 = args[21].dat->base_offset;
  double * __restrict__ wk15_B0_p = (double *)(args[21].data + base21);

  int base22 = args[22].dat->base_offset;
  double * __restrict__ wk12_B0_p = (double *)(args[22].data + base22);

  int base23 = args[23].dat->base_offset;
  double * __restrict__ wk4_B0_p = (double *)(args[23].data + base23);

  int base24 = args[24].dat->base_offset;
  double * __restrict__ wk0_B0_p = (double *)(args[24].data + base24);

  int base25 = args[25].dat->base_offset;
  double * __restrict__ wk19_B0_p = (double *)(args[25].data + base25);

  int base26 = args[26].dat->base_offset;
  double * __restrict__ wk7_B0_p = (double *)(args[26].data + base26);

  int base27 = args[27].dat->base_offset;
  double * __restrict__ wk8_B0_p = (double *)(args[27].data + base27);

  int base28 = args[28].dat->base_offset;
  double * __restrict__ wk2_B0_p = (double *)(args[28].data + base28);

  int base29 = args[29].dat->base_offset;
  double * __restrict__ wk14_B0_p = (double *)(args[29].data + base29);

  int base30 = args[30].dat->base_offset;
  double * __restrict__ Residual4_B0_p = (double *)(args[30].data + base30);

  int base31 = args[31].dat->base_offset;
  double * __restrict__ Residual3_B0_p = (double *)(args[31].data + base31);

  int base32 = args[32].dat->base_offset;
  double * __restrict__ Residual1_B0_p = (double *)(args[32].data + base32);

  int base33 = args[33].dat->base_offset;
  double * __restrict__ Residual2_B0_p = (double *)(args[33].data + base33);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 34);
  ops_halo_exchanges(args,34,range);
  ops_H_D_exchanges_host(args, 34);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[83].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #pragma omp simd
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        const ACC<double> wk10_B0(xdim0_opensbliblock00Kernel080, ydim0_opensbliblock00Kernel080, wk10_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel080*1 + n_z * xdim0_opensbliblock00Kernel080 * ydim0_opensbliblock00Kernel080*1);
        const ACC<double> wk11_B0(xdim1_opensbliblock00Kernel080, ydim1_opensbliblock00Kernel080, wk11_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel080*1 + n_z * xdim1_opensbliblock00Kernel080 * ydim1_opensbliblock00Kernel080*1);
        const ACC<double> u0_B0(xdim2_opensbliblock00Kernel080, ydim2_opensbliblock00Kernel080, u0_B0_p + n_x*1 + n_y * xdim2_opensbliblock00Kernel080*1 + n_z * xdim2_opensbliblock00Kernel080 * ydim2_opensbliblock00Kernel080*1);
        const ACC<double> wk25_B0(xdim3_opensbliblock00Kernel080, ydim3_opensbliblock00Kernel080, wk25_B0_p + n_x*1 + n_y * xdim3_opensbliblock00Kernel080*1 + n_z * xdim3_opensbliblock00Kernel080 * ydim3_opensbliblock00Kernel080*1);
        const ACC<double> wk16_B0(xdim4_opensbliblock00Kernel080, ydim4_opensbliblock00Kernel080, wk16_B0_p + n_x*1 + n_y * xdim4_opensbliblock00Kernel080*1 + n_z * xdim4_opensbliblock00Kernel080 * ydim4_opensbliblock00Kernel080*1);
        const ACC<double> wk9_B0(xdim5_opensbliblock00Kernel080, ydim5_opensbliblock00Kernel080, wk9_B0_p + n_x*1 + n_y * xdim5_opensbliblock00Kernel080*1 + n_z * xdim5_opensbliblock00Kernel080 * ydim5_opensbliblock00Kernel080*1);
        const ACC<double> u1_B0(xdim6_opensbliblock00Kernel080, ydim6_opensbliblock00Kernel080, u1_B0_p + n_x*1 + n_y * xdim6_opensbliblock00Kernel080*1 + n_z * xdim6_opensbliblock00Kernel080 * ydim6_opensbliblock00Kernel080*1);
        const ACC<double> wk6_B0(xdim7_opensbliblock00Kernel080, ydim7_opensbliblock00Kernel080, wk6_B0_p + n_x*1 + n_y * xdim7_opensbliblock00Kernel080*1 + n_z * xdim7_opensbliblock00Kernel080 * ydim7_opensbliblock00Kernel080*1);
        const ACC<double> wk21_B0(xdim8_opensbliblock00Kernel080, ydim8_opensbliblock00Kernel080, wk21_B0_p + n_x*1 + n_y * xdim8_opensbliblock00Kernel080*1 + n_z * xdim8_opensbliblock00Kernel080 * ydim8_opensbliblock00Kernel080*1);
        const ACC<double> wk26_B0(xdim9_opensbliblock00Kernel080, ydim9_opensbliblock00Kernel080, wk26_B0_p + n_x*1 + n_y * xdim9_opensbliblock00Kernel080*1 + n_z * xdim9_opensbliblock00Kernel080 * ydim9_opensbliblock00Kernel080*1);
        const ACC<double> wk24_B0(xdim10_opensbliblock00Kernel080, ydim10_opensbliblock00Kernel080, wk24_B0_p + n_x*1 + n_y * xdim10_opensbliblock00Kernel080*1 + n_z * xdim10_opensbliblock00Kernel080 * ydim10_opensbliblock00Kernel080*1);
        const ACC<double> wk5_B0(xdim11_opensbliblock00Kernel080, ydim11_opensbliblock00Kernel080, wk5_B0_p + n_x*1 + n_y * xdim11_opensbliblock00Kernel080*1 + n_z * xdim11_opensbliblock00Kernel080 * ydim11_opensbliblock00Kernel080*1);
        const ACC<double> wk3_B0(xdim12_opensbliblock00Kernel080, ydim12_opensbliblock00Kernel080, wk3_B0_p + n_x*1 + n_y * xdim12_opensbliblock00Kernel080*1 + n_z * xdim12_opensbliblock00Kernel080 * ydim12_opensbliblock00Kernel080*1);
        const ACC<double> wk1_B0(xdim13_opensbliblock00Kernel080, ydim13_opensbliblock00Kernel080, wk1_B0_p + n_x*1 + n_y * xdim13_opensbliblock00Kernel080*1 + n_z * xdim13_opensbliblock00Kernel080 * ydim13_opensbliblock00Kernel080*1);
        const ACC<double> u2_B0(xdim14_opensbliblock00Kernel080, ydim14_opensbliblock00Kernel080, u2_B0_p + n_x*1 + n_y * xdim14_opensbliblock00Kernel080*1 + n_z * xdim14_opensbliblock00Kernel080 * ydim14_opensbliblock00Kernel080*1);
        const ACC<double> wk13_B0(xdim15_opensbliblock00Kernel080, ydim15_opensbliblock00Kernel080, wk13_B0_p + n_x*1 + n_y * xdim15_opensbliblock00Kernel080*1 + n_z * xdim15_opensbliblock00Kernel080 * ydim15_opensbliblock00Kernel080*1);
        const ACC<double> wk20_B0(xdim16_opensbliblock00Kernel080, ydim16_opensbliblock00Kernel080, wk20_B0_p + n_x*1 + n_y * xdim16_opensbliblock00Kernel080*1 + n_z * xdim16_opensbliblock00Kernel080 * ydim16_opensbliblock00Kernel080*1);
        const ACC<double> wk18_B0(xdim17_opensbliblock00Kernel080, ydim17_opensbliblock00Kernel080, wk18_B0_p + n_x*1 + n_y * xdim17_opensbliblock00Kernel080*1 + n_z * xdim17_opensbliblock00Kernel080 * ydim17_opensbliblock00Kernel080*1);
        const ACC<double> wk22_B0(xdim18_opensbliblock00Kernel080, ydim18_opensbliblock00Kernel080, wk22_B0_p + n_x*1 + n_y * xdim18_opensbliblock00Kernel080*1 + n_z * xdim18_opensbliblock00Kernel080 * ydim18_opensbliblock00Kernel080*1);
        const ACC<double> wk23_B0(xdim19_opensbliblock00Kernel080, ydim19_opensbliblock00Kernel080, wk23_B0_p + n_x*1 + n_y * xdim19_opensbliblock00Kernel080*1 + n_z * xdim19_opensbliblock00Kernel080 * ydim19_opensbliblock00Kernel080*1);
        const ACC<double> wk17_B0(xdim20_opensbliblock00Kernel080, ydim20_opensbliblock00Kernel080, wk17_B0_p + n_x*1 + n_y * xdim20_opensbliblock00Kernel080*1 + n_z * xdim20_opensbliblock00Kernel080 * ydim20_opensbliblock00Kernel080*1);
        const ACC<double> wk15_B0(xdim21_opensbliblock00Kernel080, ydim21_opensbliblock00Kernel080, wk15_B0_p + n_x*1 + n_y * xdim21_opensbliblock00Kernel080*1 + n_z * xdim21_opensbliblock00Kernel080 * ydim21_opensbliblock00Kernel080*1);
        const ACC<double> wk12_B0(xdim22_opensbliblock00Kernel080, ydim22_opensbliblock00Kernel080, wk12_B0_p + n_x*1 + n_y * xdim22_opensbliblock00Kernel080*1 + n_z * xdim22_opensbliblock00Kernel080 * ydim22_opensbliblock00Kernel080*1);
        const ACC<double> wk4_B0(xdim23_opensbliblock00Kernel080, ydim23_opensbliblock00Kernel080, wk4_B0_p + n_x*1 + n_y * xdim23_opensbliblock00Kernel080*1 + n_z * xdim23_opensbliblock00Kernel080 * ydim23_opensbliblock00Kernel080*1);
        const ACC<double> wk0_B0(xdim24_opensbliblock00Kernel080, ydim24_opensbliblock00Kernel080, wk0_B0_p + n_x*1 + n_y * xdim24_opensbliblock00Kernel080*1 + n_z * xdim24_opensbliblock00Kernel080 * ydim24_opensbliblock00Kernel080*1);
        const ACC<double> wk19_B0(xdim25_opensbliblock00Kernel080, ydim25_opensbliblock00Kernel080, wk19_B0_p + n_x*1 + n_y * xdim25_opensbliblock00Kernel080*1 + n_z * xdim25_opensbliblock00Kernel080 * ydim25_opensbliblock00Kernel080*1);
        const ACC<double> wk7_B0(xdim26_opensbliblock00Kernel080, ydim26_opensbliblock00Kernel080, wk7_B0_p + n_x*1 + n_y * xdim26_opensbliblock00Kernel080*1 + n_z * xdim26_opensbliblock00Kernel080 * ydim26_opensbliblock00Kernel080*1);
        const ACC<double> wk8_B0(xdim27_opensbliblock00Kernel080, ydim27_opensbliblock00Kernel080, wk8_B0_p + n_x*1 + n_y * xdim27_opensbliblock00Kernel080*1 + n_z * xdim27_opensbliblock00Kernel080 * ydim27_opensbliblock00Kernel080*1);
        const ACC<double> wk2_B0(xdim28_opensbliblock00Kernel080, ydim28_opensbliblock00Kernel080, wk2_B0_p + n_x*1 + n_y * xdim28_opensbliblock00Kernel080*1 + n_z * xdim28_opensbliblock00Kernel080 * ydim28_opensbliblock00Kernel080*1);
        const ACC<double> wk14_B0(xdim29_opensbliblock00Kernel080, ydim29_opensbliblock00Kernel080, wk14_B0_p + n_x*1 + n_y * xdim29_opensbliblock00Kernel080*1 + n_z * xdim29_opensbliblock00Kernel080 * ydim29_opensbliblock00Kernel080*1);
        ACC<double> Residual4_B0(xdim30_opensbliblock00Kernel080, ydim30_opensbliblock00Kernel080, Residual4_B0_p + n_x*1 + n_y * xdim30_opensbliblock00Kernel080*1 + n_z * xdim30_opensbliblock00Kernel080 * ydim30_opensbliblock00Kernel080*1);
        ACC<double> Residual3_B0(xdim31_opensbliblock00Kernel080, ydim31_opensbliblock00Kernel080, Residual3_B0_p + n_x*1 + n_y * xdim31_opensbliblock00Kernel080*1 + n_z * xdim31_opensbliblock00Kernel080 * ydim31_opensbliblock00Kernel080*1);
        ACC<double> Residual1_B0(xdim32_opensbliblock00Kernel080, ydim32_opensbliblock00Kernel080, Residual1_B0_p + n_x*1 + n_y * xdim32_opensbliblock00Kernel080*1 + n_z * xdim32_opensbliblock00Kernel080 * ydim32_opensbliblock00Kernel080*1);
        ACC<double> Residual2_B0(xdim33_opensbliblock00Kernel080, ydim33_opensbliblock00Kernel080, Residual2_B0_p + n_x*1 + n_y * xdim33_opensbliblock00Kernel080*1 + n_z * xdim33_opensbliblock00Kernel080 * ydim33_opensbliblock00Kernel080*1);
        
    Residual1_B0(0,0,0) = 1.0*rcinv9*((rc10)*wk14_B0(0,0,0) + (rc11)*wk17_B0(0,0,0) +
      (rc11)*wk23_B0(0,0,0) + wk4_B0(0,0,0) + wk8_B0(0,0,0)) +
      Residual1_B0(0,0,0);

    Residual2_B0(0,0,0) = 1.0*rcinv9*((rc10)*wk0_B0(0,0,0) + (rc11)*wk19_B0(0,0,0) +
      wk22_B0(0,0,0) + (rc11)*wk2_B0(0,0,0) + wk5_B0(0,0,0)) +
      Residual2_B0(0,0,0);

    Residual3_B0(0,0,0) = 1.0*rcinv9*((rc11)*wk12_B0(0,0,0) + wk13_B0(0,0,0) +
      (rc11)*wk20_B0(0,0,0) + wk21_B0(0,0,0) + (rc10)*wk7_B0(0,0,0)) +
      Residual3_B0(0,0,0);

    Residual4_B0(0,0,0) = 1.0*rcinv12*rcinv13*rcinv14*rcinv9*(wk16_B0(0,0,0) +
      wk18_B0(0,0,0) + wk25_B0(0,0,0)) + 1.0*rcinv9*(wk11_B0(0,0,0) +
      wk15_B0(0,0,0))*wk11_B0(0,0,0) + 1.0*rcinv9*(wk11_B0(0,0,0) +
      wk15_B0(0,0,0))*wk15_B0(0,0,0) + 1.0*rcinv9*(wk24_B0(0,0,0) +
      wk26_B0(0,0,0))*wk24_B0(0,0,0) + 1.0*rcinv9*(wk24_B0(0,0,0) +
      wk26_B0(0,0,0))*wk26_B0(0,0,0) + 1.0*rcinv9*(wk3_B0(0,0,0) +
      wk9_B0(0,0,0))*wk3_B0(0,0,0) + 1.0*rcinv9*(wk3_B0(0,0,0) +
      wk9_B0(0,0,0))*wk9_B0(0,0,0) + 1.0*rcinv9*(-rc7*wk10_B0(0,0,0) -
      rc7*wk1_B0(0,0,0) + (rc10)*wk6_B0(0,0,0))*wk6_B0(0,0,0) +
      1.0*rcinv9*(-rc7*wk10_B0(0,0,0) + (rc10)*wk1_B0(0,0,0) -
      rc7*wk6_B0(0,0,0))*wk1_B0(0,0,0) + 1.0*rcinv9*((rc10)*wk10_B0(0,0,0) -
      rc7*wk1_B0(0,0,0) - rc7*wk6_B0(0,0,0))*wk10_B0(0,0,0) +
      1.0*rcinv9*((rc10)*wk0_B0(0,0,0) + (rc11)*wk19_B0(0,0,0) + wk22_B0(0,0,0) +
      (rc11)*wk2_B0(0,0,0) + wk5_B0(0,0,0))*u1_B0(0,0,0) +
      1.0*rcinv9*((rc11)*wk12_B0(0,0,0) + wk13_B0(0,0,0) + (rc11)*wk20_B0(0,0,0) +
      wk21_B0(0,0,0) + (rc10)*wk7_B0(0,0,0))*u2_B0(0,0,0) +
      1.0*rcinv9*((rc10)*wk14_B0(0,0,0) + (rc11)*wk17_B0(0,0,0) + (rc11)*wk23_B0(0,0,0)
      + wk4_B0(0,0,0) + wk8_B0(0,0,0))*u0_B0(0,0,0) + Residual4_B0(0,0,0);


      }
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[83].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 34);
  ops_set_halo_dirtybit3(&args[30],range);
  ops_set_halo_dirtybit3(&args[31],range);
  ops_set_halo_dirtybit3(&args[32],range);
  ops_set_halo_dirtybit3(&args[33],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[83].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg6);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg7);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg8);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg9);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg10);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg11);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg12);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg13);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg14);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg15);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg16);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg17);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg18);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg19);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg20);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg21);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg22);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg23);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg24);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg25);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg26);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg27);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg28);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg29);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg30);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg31);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg32);
    block->instance->OPS_kernels[83].transfer += ops_compute_transfer(dim, start, end, &arg33);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel080(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13, ops_arg arg14, ops_arg arg15,
 ops_arg arg16, ops_arg arg17, ops_arg arg18, ops_arg arg19,
 ops_arg arg20, ops_arg arg21, ops_arg arg22, ops_arg arg23,
 ops_arg arg24, ops_arg arg25, ops_arg arg26, ops_arg arg27,
 ops_arg arg28, ops_arg arg29, ops_arg arg30, ops_arg arg31,
 ops_arg arg32, ops_arg arg33) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 83;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 83;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 34;
  desc->args = (ops_arg*)ops_malloc(34*sizeof(ops_arg));
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
  desc->args[17] = arg17;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg17.dat->index;
  desc->args[18] = arg18;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg18.dat->index;
  desc->args[19] = arg19;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg19.dat->index;
  desc->args[20] = arg20;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg20.dat->index;
  desc->args[21] = arg21;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg21.dat->index;
  desc->args[22] = arg22;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg22.dat->index;
  desc->args[23] = arg23;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg23.dat->index;
  desc->args[24] = arg24;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg24.dat->index;
  desc->args[25] = arg25;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg25.dat->index;
  desc->args[26] = arg26;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg26.dat->index;
  desc->args[27] = arg27;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg27.dat->index;
  desc->args[28] = arg28;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg28.dat->index;
  desc->args[29] = arg29;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg29.dat->index;
  desc->args[30] = arg30;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg30.dat->index;
  desc->args[31] = arg31;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg31.dat->index;
  desc->args[32] = arg32;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg32.dat->index;
  desc->args[33] = arg33;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg33.dat->index;
  desc->function = ops_par_loop_opensbliblock00Kernel080_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,83,"opensbliblock00Kernel080");
  }
  ops_enqueue_kernel(desc);
}
#endif
