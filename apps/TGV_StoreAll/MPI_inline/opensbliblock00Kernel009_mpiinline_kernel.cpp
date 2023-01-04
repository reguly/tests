//
// auto-generated by ops.py
//

extern int xdim0_opensbliblock00Kernel009;
int xdim0_opensbliblock00Kernel009_h = -1;
extern int ydim0_opensbliblock00Kernel009;
int ydim0_opensbliblock00Kernel009_h = -1;
extern int xdim1_opensbliblock00Kernel009;
int xdim1_opensbliblock00Kernel009_h = -1;
extern int ydim1_opensbliblock00Kernel009;
int ydim1_opensbliblock00Kernel009_h = -1;
extern int xdim2_opensbliblock00Kernel009;
int xdim2_opensbliblock00Kernel009_h = -1;
extern int ydim2_opensbliblock00Kernel009;
int ydim2_opensbliblock00Kernel009_h = -1;
extern int xdim3_opensbliblock00Kernel009;
int xdim3_opensbliblock00Kernel009_h = -1;
extern int ydim3_opensbliblock00Kernel009;
int ydim3_opensbliblock00Kernel009_h = -1;
extern int xdim4_opensbliblock00Kernel009;
int xdim4_opensbliblock00Kernel009_h = -1;
extern int ydim4_opensbliblock00Kernel009;
int ydim4_opensbliblock00Kernel009_h = -1;
extern int xdim5_opensbliblock00Kernel009;
int xdim5_opensbliblock00Kernel009_h = -1;
extern int ydim5_opensbliblock00Kernel009;
int ydim5_opensbliblock00Kernel009_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void opensbliblock00Kernel009_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_opensbliblock00Kernel009(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5) {

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,6,range,11)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,11,"opensbliblock00Kernel009");
    block->instance->OPS_kernels[11].count++;
  }

  //compute localy allocated range for the sub-block
  int start[3];
  int end[3];
  int arg_idx[3];

  #ifdef OPS_MPI
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
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

  //Timing
  double t1,t2,c1,c2;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
  }

  if (xdim0 != xdim0_opensbliblock00Kernel009_h || ydim0 != ydim0_opensbliblock00Kernel009_h || xdim1 != xdim1_opensbliblock00Kernel009_h || ydim1 != ydim1_opensbliblock00Kernel009_h || xdim2 != xdim2_opensbliblock00Kernel009_h || ydim2 != ydim2_opensbliblock00Kernel009_h || xdim3 != xdim3_opensbliblock00Kernel009_h || ydim3 != ydim3_opensbliblock00Kernel009_h || xdim4 != xdim4_opensbliblock00Kernel009_h || ydim4 != ydim4_opensbliblock00Kernel009_h || xdim5 != xdim5_opensbliblock00Kernel009_h || ydim5 != ydim5_opensbliblock00Kernel009_h) {
    xdim0_opensbliblock00Kernel009 = xdim0;
    xdim0_opensbliblock00Kernel009_h = xdim0;
    ydim0_opensbliblock00Kernel009 = ydim0;
    ydim0_opensbliblock00Kernel009_h = ydim0;
    xdim1_opensbliblock00Kernel009 = xdim1;
    xdim1_opensbliblock00Kernel009_h = xdim1;
    ydim1_opensbliblock00Kernel009 = ydim1;
    ydim1_opensbliblock00Kernel009_h = ydim1;
    xdim2_opensbliblock00Kernel009 = xdim2;
    xdim2_opensbliblock00Kernel009_h = xdim2;
    ydim2_opensbliblock00Kernel009 = ydim2;
    ydim2_opensbliblock00Kernel009_h = ydim2;
    xdim3_opensbliblock00Kernel009 = xdim3;
    xdim3_opensbliblock00Kernel009_h = xdim3;
    ydim3_opensbliblock00Kernel009 = ydim3;
    ydim3_opensbliblock00Kernel009_h = ydim3;
    xdim4_opensbliblock00Kernel009 = xdim4;
    xdim4_opensbliblock00Kernel009_h = xdim4;
    ydim4_opensbliblock00Kernel009 = ydim4;
    ydim4_opensbliblock00Kernel009_h = ydim4;
    xdim5_opensbliblock00Kernel009 = xdim5;
    xdim5_opensbliblock00Kernel009_h = xdim5;
    ydim5_opensbliblock00Kernel009 = ydim5;
    ydim5_opensbliblock00Kernel009_h = ydim5;
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
  double *p_a0 = (double *)(args[0].data + base0);

  long long int base1 = args[1].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1+ (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1+ (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  double *p_a1 = (double *)(args[1].data + base1);

  long long int base2 = args[2].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2+ (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2+ (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  double *p_a2 = (double *)(args[2].data + base2);

  long long int base3 = args[3].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3+ (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  base3 = base3+ (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    start[2] * args[3].stencil->stride[2];
  double *p_a3 = (double *)(args[3].data + base3);

  long long int base4 = args[4].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  base4 = base4+ (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    start[1] * args[4].stencil->stride[1];
  base4 = base4+ (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    start[2] * args[4].stencil->stride[2];
  double *p_a4 = (double *)(args[4].data + base4);

  long long int base5 = args[5].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) * start[0] * args[5].stencil->stride[0];
  base5 = base5+ (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    start[1] * args[5].stencil->stride[1];
  base5 = base5+ (long long int)(block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    start[2] * args[5].stencil->stride[2];
  double *p_a5 = (double *)(args[5].data + base5);



  ops_H_D_exchanges_host(args, 6);
  ops_halo_exchanges(args,6,range);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[11].mpi_time += t1-t2;
  }

  opensbliblock00Kernel009_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    x_size, y_size, z_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[11].time += t2-t1;
  }
  ops_set_dirtybit_host(args, 6);
  ops_set_halo_dirtybit3(&args[5],range);

  //Update kernel record
  if (block->instance->OPS_diags > 1) {
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg5);
  }
}
