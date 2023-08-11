//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_opensbliblock00Kernel084;
int xdim0_opensbliblock00Kernel084_h = -1;
extern int ydim0_opensbliblock00Kernel084;
int ydim0_opensbliblock00Kernel084_h = -1;
extern int xdim1_opensbliblock00Kernel084;
int xdim1_opensbliblock00Kernel084_h = -1;
extern int ydim1_opensbliblock00Kernel084;
int ydim1_opensbliblock00Kernel084_h = -1;
extern int xdim2_opensbliblock00Kernel084;
int xdim2_opensbliblock00Kernel084_h = -1;
extern int ydim2_opensbliblock00Kernel084;
int ydim2_opensbliblock00Kernel084_h = -1;
extern int xdim3_opensbliblock00Kernel084;
int xdim3_opensbliblock00Kernel084_h = -1;
extern int ydim3_opensbliblock00Kernel084;
int ydim3_opensbliblock00Kernel084_h = -1;
extern int xdim4_opensbliblock00Kernel084;
int xdim4_opensbliblock00Kernel084_h = -1;
extern int ydim4_opensbliblock00Kernel084;
int ydim4_opensbliblock00Kernel084_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void opensbliblock00Kernel084_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_opensbliblock00Kernel084(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,5,range,4)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,4,"opensbliblock00Kernel084");
    block->instance->OPS_kernels[4].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block

  int start[3];
  int end[3];

  int arg_idx[3];
  int arg_idx_base[3];
  #ifdef OPS_MPI
  if (compute_ranges(args, 5,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  for ( int n=0; n<3; n++ ){
    arg_idx_base[n] = arg_idx[n];
  }

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;


  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0 + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0 + (long long int)(block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  long long int base1 = args[1].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1 + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1 + (long long int)(block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  long long int base2 = args[2].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2 + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2 + (long long int)(block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  long long int base3 = args[3].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3 + (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  base3 = base3 + (long long int)(block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    start[2] * args[3].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif

  long long int base4 = args[4].dat->base_offset + (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  base4 = base4 + (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    start[1] * args[4].stencil->stride[1];
  base4 = base4 + (long long int)(block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    start[2] * args[4].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data_d + base4);
  #else
  double *p_a4 = (double *)((char *)args[4].data + base4);
  #endif


  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  //initialize global variable with the dimension of dats
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
  if (xdim0 != xdim0_opensbliblock00Kernel084_h || ydim0 != ydim0_opensbliblock00Kernel084_h || xdim1 != xdim1_opensbliblock00Kernel084_h || ydim1 != ydim1_opensbliblock00Kernel084_h || xdim2 != xdim2_opensbliblock00Kernel084_h || ydim2 != ydim2_opensbliblock00Kernel084_h || xdim3 != xdim3_opensbliblock00Kernel084_h || ydim3 != ydim3_opensbliblock00Kernel084_h || xdim4 != xdim4_opensbliblock00Kernel084_h || ydim4 != ydim4_opensbliblock00Kernel084_h) {
    xdim0_opensbliblock00Kernel084 = xdim0;
    xdim0_opensbliblock00Kernel084_h = xdim0;
    ydim0_opensbliblock00Kernel084 = ydim0;
    ydim0_opensbliblock00Kernel084_h = ydim0;
    xdim1_opensbliblock00Kernel084 = xdim1;
    xdim1_opensbliblock00Kernel084_h = xdim1;
    ydim1_opensbliblock00Kernel084 = ydim1;
    ydim1_opensbliblock00Kernel084_h = ydim1;
    xdim2_opensbliblock00Kernel084 = xdim2;
    xdim2_opensbliblock00Kernel084_h = xdim2;
    ydim2_opensbliblock00Kernel084 = ydim2;
    ydim2_opensbliblock00Kernel084_h = ydim2;
    xdim3_opensbliblock00Kernel084 = xdim3;
    xdim3_opensbliblock00Kernel084_h = xdim3;
    ydim3_opensbliblock00Kernel084 = ydim3;
    ydim3_opensbliblock00Kernel084_h = ydim3;
    xdim4_opensbliblock00Kernel084 = xdim4;
    xdim4_opensbliblock00Kernel084_h = xdim4;
    ydim4_opensbliblock00Kernel084 = ydim4;
    ydim4_opensbliblock00Kernel084_h = ydim4;
  }

  //Halo Exchanges

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 5);
  #else
  ops_H_D_exchanges_host(args, 5);
  #endif
  ops_halo_exchanges(args,5,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 5);
  #else
  ops_H_D_exchanges_host(args, 5);
  #endif
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[4].mpi_time += t2-t1;
  }

  opensbliblock00Kernel084_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    x_size, y_size, z_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[4].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 5);
  #else
  ops_set_dirtybit_host(args, 5);
  #endif
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[4].mpi_time += t2-t1;
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}
