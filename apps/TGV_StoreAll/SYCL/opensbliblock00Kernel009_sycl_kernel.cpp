//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel009(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
#else
void ops_par_loop_opensbliblock00Kernel009_execute(ops_kernel_descriptor *desc) {
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

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4,
 arg5};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,6,range,11)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,11,"opensbliblock00Kernel009");
    block->instance->OPS_kernels[11].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "opensbliblock00Kernel009");
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
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_opensbliblock00Kernel009 = args[0].dat->size[0];
  int ydim0_opensbliblock00Kernel009 = args[0].dat->size[1];
  int xdim1_opensbliblock00Kernel009 = args[1].dat->size[0];
  int ydim1_opensbliblock00Kernel009 = args[1].dat->size[1];
  int xdim2_opensbliblock00Kernel009 = args[2].dat->size[0];
  int ydim2_opensbliblock00Kernel009 = args[2].dat->size[1];
  int xdim3_opensbliblock00Kernel009 = args[3].dat->size[0];
  int ydim3_opensbliblock00Kernel009 = args[3].dat->size[1];
  int xdim4_opensbliblock00Kernel009 = args[4].dat->size[0];
  int ydim4_opensbliblock00Kernel009 = args[4].dat->size[1];
  int xdim5_opensbliblock00Kernel009 = args[5].dat->size[0];
  int ydim5_opensbliblock00Kernel009 = args[5].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset/sizeof(double);
  double* u2_B0_p = (double*)args[0].data_d;

  int base1 = args[1].dat->base_offset/sizeof(double);
  double* u0_B0_p = (double*)args[1].data_d;

  int base2 = args[2].dat->base_offset/sizeof(double);
  double* rhoE_B0_p = (double*)args[2].data_d;

  int base3 = args[3].dat->base_offset/sizeof(double);
  double* rho_B0_p = (double*)args[3].data_d;

  int base4 = args[4].dat->base_offset/sizeof(double);
  double* u1_B0_p = (double*)args[4].data_d;

  int base5 = args[5].dat->base_offset/sizeof(double);
  double* p_B0_p = (double*)args[5].data_d;



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_device(args, 6);
  ops_halo_exchanges(args,6,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[11].mpi_time += __t1-__t2;
  }

  int start_0 = start[0];
  int end_0 = end[0];
  int start_1 = start[1];
  int end_1 = end[1];
  int start_2 = start[2];
  int end_2 = end[2];
  if ((end[0]-start[0])>0 && (end[1]-start[1])>0 && (end[2]-start[2])>0) {
    block->instance->sycl_instance->queue->submit([&](cl::sycl::handler &cgh) {

      auto gama_sycl = (*gama_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto rc6_sycl = (*rc6_p).template get_access<cl::sycl::access::mode::read>(cgh);

      cgh.parallel_for<class opensbliblock00Kernel009_kernel>(cl::sycl::nd_range<3>(cl::sycl::range<3>(
           ((end[2]-start[2]-1)/block->instance->OPS_block_size_z+1)*block->instance->OPS_block_size_z,
           ((end[1]-start[1]-1)/block->instance->OPS_block_size_y+1)*block->instance->OPS_block_size_y,
            end[0]-start[0]
             ),cl::sycl::range<3>(
             block->instance->OPS_block_size_z,
             block->instance->OPS_block_size_y,
            end[0]-start[0]
             ))
      , [=](cl::sycl::nd_item<3> item
      ) [[intel::kernel_args_restrict]] {
        int n_z = item.get_global_id()[0]+start_2;
        int n_y = item.get_global_id()[1]+start_1;
        int n_x = item.get_global_id()[2]+start_0;
        const ACC<double> u2_B0(xdim0_opensbliblock00Kernel009, ydim0_opensbliblock00Kernel009, &u2_B0_p[0] + base0 + n_x*1 + n_y * xdim0_opensbliblock00Kernel009*1 + n_z * xdim0_opensbliblock00Kernel009 * ydim0_opensbliblock00Kernel009*1);
        const ACC<double> u0_B0(xdim1_opensbliblock00Kernel009, ydim1_opensbliblock00Kernel009, &u0_B0_p[0] + base1 + n_x*1 + n_y * xdim1_opensbliblock00Kernel009*1 + n_z * xdim1_opensbliblock00Kernel009 * ydim1_opensbliblock00Kernel009*1);
        const ACC<double> rhoE_B0(xdim2_opensbliblock00Kernel009, ydim2_opensbliblock00Kernel009, &rhoE_B0_p[0] + base2 + n_x*1 + n_y * xdim2_opensbliblock00Kernel009*1 + n_z * xdim2_opensbliblock00Kernel009 * ydim2_opensbliblock00Kernel009*1);
        const ACC<double> rho_B0(xdim3_opensbliblock00Kernel009, ydim3_opensbliblock00Kernel009, &rho_B0_p[0] + base3 + n_x*1 + n_y * xdim3_opensbliblock00Kernel009*1 + n_z * xdim3_opensbliblock00Kernel009 * ydim3_opensbliblock00Kernel009*1);
        const ACC<double> u1_B0(xdim4_opensbliblock00Kernel009, ydim4_opensbliblock00Kernel009, &u1_B0_p[0] + base4 + n_x*1 + n_y * xdim4_opensbliblock00Kernel009*1 + n_z * xdim4_opensbliblock00Kernel009 * ydim4_opensbliblock00Kernel009*1);
        ACC<double> p_B0(xdim5_opensbliblock00Kernel009, ydim5_opensbliblock00Kernel009, &p_B0_p[0] + base5 + n_x*1 + n_y * xdim5_opensbliblock00Kernel009*1 + n_z * xdim5_opensbliblock00Kernel009 * ydim5_opensbliblock00Kernel009*1);
        //USER CODE
        if (n_x < end_0 && n_y < end_1 && n_z < end_2) {
          
    p_B0(0,0,0) = (gama_sycl[0] - 1)*(rhoE_B0(0,0,0) -
      rc6_sycl[0]*rho_B0(0,0,0)*pow(u0_B0(0,0,0), 2) -
      rc6_sycl[0]*rho_B0(0,0,0)*pow(u1_B0(0,0,0), 2) -
      rc6_sycl[0]*rho_B0(0,0,0)*pow(u2_B0(0,0,0), 2));


        }
      });
    });
  }
  if (block->instance->OPS_diags > 1) {
    block->instance->sycl_instance->queue->wait();
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[11].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 6);
  ops_set_halo_dirtybit3(&args[5],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[11].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg5);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel009(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 11;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 11;
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
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->function = ops_par_loop_opensbliblock00Kernel009_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,11,"opensbliblock00Kernel009");
  }
  ops_enqueue_kernel(desc);
}
#endif
