//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel028(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
#else
void ops_par_loop_opensbliblock00Kernel028_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,5,range,3)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,3,"opensbliblock00Kernel028");
    block->instance->OPS_kernels[3].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "opensbliblock00Kernel028");
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
  if (compute_ranges(args, 5,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_opensbliblock00Kernel028 = args[0].dat->size[0];
  int ydim0_opensbliblock00Kernel028 = args[0].dat->size[1];
  int xdim1_opensbliblock00Kernel028 = args[1].dat->size[0];
  int ydim1_opensbliblock00Kernel028 = args[1].dat->size[1];
  int xdim2_opensbliblock00Kernel028 = args[2].dat->size[0];
  int ydim2_opensbliblock00Kernel028 = args[2].dat->size[1];
  int xdim3_opensbliblock00Kernel028 = args[3].dat->size[0];
  int ydim3_opensbliblock00Kernel028 = args[3].dat->size[1];
  int xdim4_opensbliblock00Kernel028 = args[4].dat->size[0];
  int ydim4_opensbliblock00Kernel028 = args[4].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset/sizeof(double);
  double* rhoE_B0_p = (double*)args[0].data_d;

  int base1 = args[1].dat->base_offset/sizeof(double);
  double* rho_B0_p = (double*)args[1].data_d;

  int base2 = args[2].dat->base_offset/sizeof(double);
  double* rhou0_B0_p = (double*)args[2].data_d;

  int base3 = args[3].dat->base_offset/sizeof(double);
  double* rhou2_B0_p = (double*)args[3].data_d;

  int base4 = args[4].dat->base_offset/sizeof(double);
  double* rhou1_B0_p = (double*)args[4].data_d;



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_device(args, 5);
  ops_halo_exchanges(args,5,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[3].mpi_time += __t1-__t2;
  }

  int start_0 = start[0];
  int end_0 = end[0];
  int start_1 = start[1];
  int end_1 = end[1];
  int start_2 = start[2];
  int end_2 = end[2];
  if ((end[0]-start[0])>0 && (end[1]-start[1])>0 && (end[2]-start[2])>0) {
    block->instance->sycl_instance->queue->submit([&](cl::sycl::handler &cgh) {


      cgh.parallel_for<class opensbliblock00Kernel028_kernel>(cl::sycl::nd_range<3>(cl::sycl::range<3>(
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
        ACC<double> rhoE_B0(xdim0_opensbliblock00Kernel028, ydim0_opensbliblock00Kernel028, &rhoE_B0_p[0] + base0 + n_x*1 + n_y * xdim0_opensbliblock00Kernel028*1 + n_z * xdim0_opensbliblock00Kernel028 * ydim0_opensbliblock00Kernel028*1);
        ACC<double> rho_B0(xdim1_opensbliblock00Kernel028, ydim1_opensbliblock00Kernel028, &rho_B0_p[0] + base1 + n_x*1 + n_y * xdim1_opensbliblock00Kernel028*1 + n_z * xdim1_opensbliblock00Kernel028 * ydim1_opensbliblock00Kernel028*1);
        ACC<double> rhou0_B0(xdim2_opensbliblock00Kernel028, ydim2_opensbliblock00Kernel028, &rhou0_B0_p[0] + base2 + n_x*1 + n_y * xdim2_opensbliblock00Kernel028*1 + n_z * xdim2_opensbliblock00Kernel028 * ydim2_opensbliblock00Kernel028*1);
        ACC<double> rhou2_B0(xdim3_opensbliblock00Kernel028, ydim3_opensbliblock00Kernel028, &rhou2_B0_p[0] + base3 + n_x*1 + n_y * xdim3_opensbliblock00Kernel028*1 + n_z * xdim3_opensbliblock00Kernel028 * ydim3_opensbliblock00Kernel028*1);
        ACC<double> rhou1_B0(xdim4_opensbliblock00Kernel028, ydim4_opensbliblock00Kernel028, &rhou1_B0_p[0] + base4 + n_x*1 + n_y * xdim4_opensbliblock00Kernel028*1 + n_z * xdim4_opensbliblock00Kernel028 * ydim4_opensbliblock00Kernel028*1);
        //USER CODE
        if (n_x < end_0 && n_y < end_1 && n_z < end_2) {
          
   rho_B0(0,-1,0) = rho_B0(0,1,0);

   rhou0_B0(0,-1,0) = rhou0_B0(0,1,0);

   rhou1_B0(0,-1,0) = -1.0*rhou1_B0(0,1,0);

   rhou2_B0(0,-1,0) = rhou2_B0(0,1,0);

   rhoE_B0(0,-1,0) = rhoE_B0(0,1,0);

   rho_B0(0,-2,0) = rho_B0(0,2,0);

   rhou0_B0(0,-2,0) = rhou0_B0(0,2,0);

   rhou1_B0(0,-2,0) = -1.0*rhou1_B0(0,2,0);

   rhou2_B0(0,-2,0) = rhou2_B0(0,2,0);

   rhoE_B0(0,-2,0) = rhoE_B0(0,2,0);


        }
      });
    });
  }
  if (block->instance->OPS_diags > 1) {
    block->instance->sycl_instance->queue->wait();
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[3].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 5);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[3].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel028(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 3;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 3;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 5;
  desc->args = (ops_arg*)ops_malloc(5*sizeof(ops_arg));
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
  desc->function = ops_par_loop_opensbliblock00Kernel028_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,3,"opensbliblock00Kernel028");
  }
  ops_enqueue_kernel(desc);
}
#endif
