//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel030(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
#else
void ops_par_loop_opensbliblock00Kernel030_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[2] = { arg0, arg1};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,2,range,35)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,35,"opensbliblock00Kernel030");
    block->instance->OPS_kernels[35].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "opensbliblock00Kernel030");
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
  if (compute_ranges(args, 2,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_opensbliblock00Kernel030 = args[0].dat->size[0];
  int ydim0_opensbliblock00Kernel030 = args[0].dat->size[1];
  int xdim1_opensbliblock00Kernel030 = args[1].dat->size[0];
  int ydim1_opensbliblock00Kernel030 = args[1].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset/sizeof(double);
  double* wk41_B0_p = (double*)args[0].data_d;

  int base1 = args[1].dat->base_offset/sizeof(double);
  double* wk20_B0_p = (double*)args[1].data_d;



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_device(args, 2);
  ops_halo_exchanges(args,2,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[35].mpi_time += __t1-__t2;
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
      auto rc7_sycl = (*rc7_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto rc8_sycl = (*rc8_p).template get_access<cl::sycl::access::mode::read>(cgh);

      cgh.parallel_for<class opensbliblock00Kernel030_kernel>(cl::sycl::nd_range<3>(cl::sycl::range<3>(
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
        const ACC<double> wk41_B0(xdim0_opensbliblock00Kernel030, ydim0_opensbliblock00Kernel030, &wk41_B0_p[0] + base0 + n_x*1 + n_y * xdim0_opensbliblock00Kernel030*1 + n_z * xdim0_opensbliblock00Kernel030 * ydim0_opensbliblock00Kernel030*1);
        ACC<double> wk20_B0(xdim1_opensbliblock00Kernel030, ydim1_opensbliblock00Kernel030, &wk20_B0_p[0] + base1 + n_x*1 + n_y * xdim1_opensbliblock00Kernel030*1 + n_z * xdim1_opensbliblock00Kernel030 * ydim1_opensbliblock00Kernel030*1);
        //USER CODE
        if (n_x < end_0 && n_y < end_1 && n_z < end_2) {
          
    wk20_B0(0,0,0) = inv_1_sycl[0]*((rc8_sycl[0])*wk41_B0(-2,0,0) - rc8_sycl[0]*wk41_B0(2,0,0) +
      (rc7_sycl[0])*wk41_B0(1,0,0) - rc7_sycl[0]*wk41_B0(-1,0,0));


        }
      });
    });
  }
  if (block->instance->OPS_diags > 1) {
    block->instance->sycl_instance->queue->wait();
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[35].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 2);
  ops_set_halo_dirtybit3(&args[1],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[35].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[35].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[35].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel030(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 35;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 35;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 2;
  desc->args = (ops_arg*)ops_malloc(2*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->function = ops_par_loop_opensbliblock00Kernel030_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,35,"opensbliblock00Kernel030");
  }
  ops_enqueue_kernel(desc);
}
#endif
