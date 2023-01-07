//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel088(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9) {
#else
void ops_par_loop_opensbliblock00Kernel088_execute(ops_kernel_descriptor *desc) {
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
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[10] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,10,range,7)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,7,"opensbliblock00Kernel088");
    block->instance->OPS_kernels[7].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "opensbliblock00Kernel088");
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
  if (compute_ranges(args, 10,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_opensbliblock00Kernel088 = args[0].dat->size[0];
  int ydim0_opensbliblock00Kernel088 = args[0].dat->size[1];
  int xdim1_opensbliblock00Kernel088 = args[1].dat->size[0];
  int ydim1_opensbliblock00Kernel088 = args[1].dat->size[1];
  int xdim2_opensbliblock00Kernel088 = args[2].dat->size[0];
  int ydim2_opensbliblock00Kernel088 = args[2].dat->size[1];
  int xdim3_opensbliblock00Kernel088 = args[3].dat->size[0];
  int ydim3_opensbliblock00Kernel088 = args[3].dat->size[1];
  int xdim4_opensbliblock00Kernel088 = args[4].dat->size[0];
  int ydim4_opensbliblock00Kernel088 = args[4].dat->size[1];
  int xdim5_opensbliblock00Kernel088 = args[5].dat->size[0];
  int ydim5_opensbliblock00Kernel088 = args[5].dat->size[1];
  int xdim6_opensbliblock00Kernel088 = args[6].dat->size[0];
  int ydim6_opensbliblock00Kernel088 = args[6].dat->size[1];
  int xdim7_opensbliblock00Kernel088 = args[7].dat->size[0];
  int ydim7_opensbliblock00Kernel088 = args[7].dat->size[1];
  int xdim8_opensbliblock00Kernel088 = args[8].dat->size[0];
  int ydim8_opensbliblock00Kernel088 = args[8].dat->size[1];
  int xdim9_opensbliblock00Kernel088 = args[9].dat->size[0];
  int ydim9_opensbliblock00Kernel088 = args[9].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ rhoE_B0_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ rhou0_B0_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ rho_B0_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ rhou1_B0_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ rhou2_B0_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ rho_RKold_B0_p = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ rhou2_RKold_B0_p = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ rhoE_RKold_B0_p = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset;
  double * __restrict__ rhou0_RKold_B0_p = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset;
  double * __restrict__ rhou1_RKold_B0_p = (double *)(args[9].data + base9);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 10);
  ops_halo_exchanges(args,10,range);
  ops_H_D_exchanges_host(args, 10);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[7].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef __INTEL_COMPILER
      #pragma loop_count(10000)
      #pragma omp simd
      #elif defined(__clang__)
      #pragma omp simd
      #elif defined(__GNUC__)
      #pragma GCC ivdep
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        const ACC<double> rhoE_B0(xdim0_opensbliblock00Kernel088, ydim0_opensbliblock00Kernel088, rhoE_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel088*1 + n_z * xdim0_opensbliblock00Kernel088 * ydim0_opensbliblock00Kernel088*1);
        const ACC<double> rhou0_B0(xdim1_opensbliblock00Kernel088, ydim1_opensbliblock00Kernel088, rhou0_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel088*1 + n_z * xdim1_opensbliblock00Kernel088 * ydim1_opensbliblock00Kernel088*1);
        const ACC<double> rho_B0(xdim2_opensbliblock00Kernel088, ydim2_opensbliblock00Kernel088, rho_B0_p + n_x*1 + n_y * xdim2_opensbliblock00Kernel088*1 + n_z * xdim2_opensbliblock00Kernel088 * ydim2_opensbliblock00Kernel088*1);
        const ACC<double> rhou1_B0(xdim3_opensbliblock00Kernel088, ydim3_opensbliblock00Kernel088, rhou1_B0_p + n_x*1 + n_y * xdim3_opensbliblock00Kernel088*1 + n_z * xdim3_opensbliblock00Kernel088 * ydim3_opensbliblock00Kernel088*1);
        const ACC<double> rhou2_B0(xdim4_opensbliblock00Kernel088, ydim4_opensbliblock00Kernel088, rhou2_B0_p + n_x*1 + n_y * xdim4_opensbliblock00Kernel088*1 + n_z * xdim4_opensbliblock00Kernel088 * ydim4_opensbliblock00Kernel088*1);
        ACC<double> rho_RKold_B0(xdim5_opensbliblock00Kernel088, ydim5_opensbliblock00Kernel088, rho_RKold_B0_p + n_x*1 + n_y * xdim5_opensbliblock00Kernel088*1 + n_z * xdim5_opensbliblock00Kernel088 * ydim5_opensbliblock00Kernel088*1);
        ACC<double> rhou2_RKold_B0(xdim6_opensbliblock00Kernel088, ydim6_opensbliblock00Kernel088, rhou2_RKold_B0_p + n_x*1 + n_y * xdim6_opensbliblock00Kernel088*1 + n_z * xdim6_opensbliblock00Kernel088 * ydim6_opensbliblock00Kernel088*1);
        ACC<double> rhoE_RKold_B0(xdim7_opensbliblock00Kernel088, ydim7_opensbliblock00Kernel088, rhoE_RKold_B0_p + n_x*1 + n_y * xdim7_opensbliblock00Kernel088*1 + n_z * xdim7_opensbliblock00Kernel088 * ydim7_opensbliblock00Kernel088*1);
        ACC<double> rhou0_RKold_B0(xdim8_opensbliblock00Kernel088, ydim8_opensbliblock00Kernel088, rhou0_RKold_B0_p + n_x*1 + n_y * xdim8_opensbliblock00Kernel088*1 + n_z * xdim8_opensbliblock00Kernel088 * ydim8_opensbliblock00Kernel088*1);
        ACC<double> rhou1_RKold_B0(xdim9_opensbliblock00Kernel088, ydim9_opensbliblock00Kernel088, rhou1_RKold_B0_p + n_x*1 + n_y * xdim9_opensbliblock00Kernel088*1 + n_z * xdim9_opensbliblock00Kernel088 * ydim9_opensbliblock00Kernel088*1);
        
   rho_RKold_B0(0,0,0) = rho_B0(0,0,0);

   rhou0_RKold_B0(0,0,0) = rhou0_B0(0,0,0);

   rhou1_RKold_B0(0,0,0) = rhou1_B0(0,0,0);

   rhou2_RKold_B0(0,0,0) = rhou2_B0(0,0,0);

   rhoE_RKold_B0(0,0,0) = rhoE_B0(0,0,0);


      }
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[7].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 10);
  ops_set_halo_dirtybit3(&args[5],range);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);
  ops_set_halo_dirtybit3(&args[8],range);
  ops_set_halo_dirtybit3(&args[9],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[7].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg6);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg7);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg8);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg9);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel088(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 7;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 7;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 10;
  desc->args = (ops_arg*)ops_malloc(10*sizeof(ops_arg));
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
  desc->function = ops_par_loop_opensbliblock00Kernel088_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,7,"opensbliblock00Kernel088");
  }
  ops_enqueue_kernel(desc);
}
#endif
