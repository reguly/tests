//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel087(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
#else
void ops_par_loop_opensbliblock00Kernel087_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,6,range,0)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,0,"opensbliblock00Kernel087");
    block->instance->OPS_kernels[0].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "opensbliblock00Kernel087");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  int arg_idx[3];
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #endif

  #if defined(OPS_MPI)
  #if defined(OPS_LAZY)
  sub_block_list sb = OPS_sub_block_list[block->index];
  arg_idx[0] = sb->decomp_disp[0];
  arg_idx[1] = sb->decomp_disp[1];
  arg_idx[2] = sb->decomp_disp[2];
  #else
  arg_idx[0] -= start[0];
  arg_idx[1] -= start[1];
  arg_idx[2] -= start[2];
  #endif
  #else //OPS_MPI
  arg_idx[0] = 0;
  arg_idx[1] = 0;
  arg_idx[2] = 0;
  #endif //OPS_MPI

  //initialize global variable with the dimension of dats
  int xdim0_opensbliblock00Kernel087 = args[0].dat->size[0];
  int ydim0_opensbliblock00Kernel087 = args[0].dat->size[1];
  int xdim1_opensbliblock00Kernel087 = args[1].dat->size[0];
  int ydim1_opensbliblock00Kernel087 = args[1].dat->size[1];
  int xdim2_opensbliblock00Kernel087 = args[2].dat->size[0];
  int ydim2_opensbliblock00Kernel087 = args[2].dat->size[1];
  int xdim3_opensbliblock00Kernel087 = args[3].dat->size[0];
  int ydim3_opensbliblock00Kernel087 = args[3].dat->size[1];
  int xdim4_opensbliblock00Kernel087 = args[4].dat->size[0];
  int ydim4_opensbliblock00Kernel087 = args[4].dat->size[1];

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




  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 6);
  ops_halo_exchanges(args,6,range);
  ops_H_D_exchanges_host(args, 6);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[0].mpi_time += __t1-__t2;
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
        int idx[] = {arg_idx[0]+n_x, arg_idx[1]+n_y, arg_idx[2]+n_z};
        ACC<double> rhoE_B0(xdim0_opensbliblock00Kernel087, ydim0_opensbliblock00Kernel087, rhoE_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel087*1 + n_z * xdim0_opensbliblock00Kernel087 * ydim0_opensbliblock00Kernel087*1);
        ACC<double> rhou0_B0(xdim1_opensbliblock00Kernel087, ydim1_opensbliblock00Kernel087, rhou0_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel087*1 + n_z * xdim1_opensbliblock00Kernel087 * ydim1_opensbliblock00Kernel087*1);
        ACC<double> rho_B0(xdim2_opensbliblock00Kernel087, ydim2_opensbliblock00Kernel087, rho_B0_p + n_x*1 + n_y * xdim2_opensbliblock00Kernel087*1 + n_z * xdim2_opensbliblock00Kernel087 * ydim2_opensbliblock00Kernel087*1);
        ACC<double> rhou1_B0(xdim3_opensbliblock00Kernel087, ydim3_opensbliblock00Kernel087, rhou1_B0_p + n_x*1 + n_y * xdim3_opensbliblock00Kernel087*1 + n_z * xdim3_opensbliblock00Kernel087 * ydim3_opensbliblock00Kernel087*1);
        ACC<double> rhou2_B0(xdim4_opensbliblock00Kernel087, ydim4_opensbliblock00Kernel087, rhou2_B0_p + n_x*1 + n_y * xdim4_opensbliblock00Kernel087*1 + n_z * xdim4_opensbliblock00Kernel087 * ydim4_opensbliblock00Kernel087*1);
        
   double x2 = 0.0;
   double u1 = 0.0;
   double r = 0.0;
   double u2 = 0.0;
   double p = 0.0;
   double x0 = 0.0;
   double x1 = 0.0;
   double u0 = 0.0;
   x0 = Delta0block0*idx[0];

   x1 = Delta1block0*idx[1];

   x2 = Delta2block0*idx[2];

   u0 = sin(x0)*cos(x1)*cos(x2);

   u1 = -sin(x1)*cos(x0)*cos(x2);

   u2 = 0.0;

   p = (0.0625*cos(2.0*x0) + 0.0625*cos(2.0*x1))*(cos(2.0*x2) + 2.0) + 1.0/(pow(Minf, 2)*gama);

   r = pow(Minf, 2)*gama*p;

   rho_B0(0,0,0) = r;

   rhou0_B0(0,0,0) = r*u0;

   rhou1_B0(0,0,0) = r*u1;

   rhou2_B0(0,0,0) = r*u2;

   rhoE_B0(0,0,0) = p/(gama - 1) + 0.5*r*(pow(u0, 2) + pow(u1, 2) + pow(u2, 2));


      }
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[0].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 6);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[0].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel087(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 0;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 0;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 6;
  desc->args = (ops_arg*)ops_malloc(6*sizeof(ops_arg));
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
  desc->function = ops_par_loop_opensbliblock00Kernel087_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,0,"opensbliblock00Kernel087");
  }
  ops_enqueue_kernel(desc);
}
#endif
