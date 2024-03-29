//
// auto-generated by ops.py
//

extern int xdim0_fd3d_pml_kernel;
int xdim0_fd3d_pml_kernel_h = -1;
extern int ydim0_fd3d_pml_kernel;
int ydim0_fd3d_pml_kernel_h = -1;
extern int zdim0_fd3d_pml_kernel;
int zdim0_fd3d_pml_kernel_h = -1;
extern int xdim1_fd3d_pml_kernel;
int xdim1_fd3d_pml_kernel_h = -1;
extern int ydim1_fd3d_pml_kernel;
int ydim1_fd3d_pml_kernel_h = -1;
extern int zdim1_fd3d_pml_kernel;
int zdim1_fd3d_pml_kernel_h = -1;
extern int xdim2_fd3d_pml_kernel;
int xdim2_fd3d_pml_kernel_h = -1;
extern int ydim2_fd3d_pml_kernel;
int ydim2_fd3d_pml_kernel_h = -1;
extern int zdim2_fd3d_pml_kernel;
int zdim2_fd3d_pml_kernel_h = -1;
extern int xdim3_fd3d_pml_kernel;
int xdim3_fd3d_pml_kernel_h = -1;
extern int ydim3_fd3d_pml_kernel;
int ydim3_fd3d_pml_kernel_h = -1;
extern int zdim3_fd3d_pml_kernel;
int zdim3_fd3d_pml_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void fd3d_pml_kernel_c_wrapper(
  float *p_a0,
  float *p_a1,
  float *p_a2,
  float *p_a3,
  int *p_a4,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_fd3d_pml_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,5,range,1)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,1,"fd3d_pml_kernel");
    block->instance->OPS_kernels[1].count++;
  }

  //compute localy allocated range for the sub-block
  int start[3];
  int end[3];
  int arg_idx[3];

  #ifdef OPS_MPI
  if (compute_ranges(args, 5,block, range, start, end, arg_idx) < 0) return;
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int zdim0 = args[0].dat->size[2];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int zdim1 = args[1].dat->size[2];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int zdim2 = args[2].dat->size[2];
  int xdim3 = args[3].dat->size[0];
  int ydim3 = args[3].dat->size[1];
  int zdim3 = args[3].dat->size[2];

  //Timing
  double t1,t2,c1,c2;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
  }

  if (xdim0 != xdim0_fd3d_pml_kernel_h || ydim0 != ydim0_fd3d_pml_kernel_h || zdim0 != zdim0_fd3d_pml_kernel_h || xdim1 != xdim1_fd3d_pml_kernel_h || ydim1 != ydim1_fd3d_pml_kernel_h || zdim1 != zdim1_fd3d_pml_kernel_h || xdim2 != xdim2_fd3d_pml_kernel_h || ydim2 != ydim2_fd3d_pml_kernel_h || zdim2 != zdim2_fd3d_pml_kernel_h || xdim3 != xdim3_fd3d_pml_kernel_h || ydim3 != ydim3_fd3d_pml_kernel_h || zdim3 != zdim3_fd3d_pml_kernel_h) {
    xdim0_fd3d_pml_kernel = xdim0;
    xdim0_fd3d_pml_kernel_h = xdim0;
    ydim0_fd3d_pml_kernel = ydim0;
    ydim0_fd3d_pml_kernel_h = ydim0;
    zdim0_fd3d_pml_kernel = zdim0;
    zdim0_fd3d_pml_kernel_h = zdim0;
    xdim1_fd3d_pml_kernel = xdim1;
    xdim1_fd3d_pml_kernel_h = xdim1;
    ydim1_fd3d_pml_kernel = ydim1;
    ydim1_fd3d_pml_kernel_h = ydim1;
    zdim1_fd3d_pml_kernel = zdim1;
    zdim1_fd3d_pml_kernel_h = zdim1;
    xdim2_fd3d_pml_kernel = xdim2;
    xdim2_fd3d_pml_kernel_h = xdim2;
    ydim2_fd3d_pml_kernel = ydim2;
    ydim2_fd3d_pml_kernel_h = ydim2;
    zdim2_fd3d_pml_kernel = zdim2;
    zdim2_fd3d_pml_kernel_h = zdim2;
    xdim3_fd3d_pml_kernel = xdim3;
    xdim3_fd3d_pml_kernel_h = xdim3;
    ydim3_fd3d_pml_kernel = ydim3;
    ydim3_fd3d_pml_kernel_h = ydim3;
    zdim3_fd3d_pml_kernel = zdim3;
    zdim3_fd3d_pml_kernel_h = zdim3;
  }



  //set up initial pointers and exchange halos if necessary
  long long int base0 = args[0].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0+ (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0+ (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  float *p_a0 = (float *)(args[0].data + base0);

  long long int base1 = args[1].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1+ (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1+ (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  float *p_a1 = (float *)(args[1].data + base1);

  long long int base2 = args[2].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2+ (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2+ (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  float *p_a2 = (float *)(args[2].data + base2);

  long long int base3 = args[3].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3+ (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  base3 = base3+ (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    start[2] * args[3].stencil->stride[2];
  float *p_a3 = (float *)(args[3].data + base3);

  int *p_a4 = NULL;



  ops_H_D_exchanges_host(args, 5);
  ops_halo_exchanges(args,5,range);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[1].mpi_time += t1-t2;
  }

  fd3d_pml_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    arg_idx[0], arg_idx[1], arg_idx[2],
    x_size, y_size, z_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[1].time += t2-t1;
  }
  ops_set_dirtybit_host(args, 5);
  ops_set_halo_dirtybit3(&args[3],range);

  //Update kernel record
  if (block->instance->OPS_diags > 1) {
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}
