//
// auto-generated by ops.py
//
__constant__ int dims_rtm_kernel_populate [7][3];
static int dims_rtm_kernel_populate_h [7][3] = {0};

//user function
__device__

void rtm_kernel_populate_gpu(const int *dispx,
  const int *dispy,
  const int *dispz,
  const int *idx,
  ACC<float> &rho,
  ACC<float> &mu,
  ACC<float> &yy) {
  float x = 1.0f*((float)(idx[0]-nx/2)/nx);
  float y = 1.0f*((float)(idx[1]-ny/2)/ny);
  float z = 1.0f*((float)(idx[2]-nz/2)/nz);
  const float C = 1.f;
  const float r0 = 0.001f;
  rho(0,0,0) = 1.f;
  mu(0,0,0) = 1.f;

  yy(0,0,0,0) = (1.f/3.f)*C*exp(-(x*x+y*y+z*z)/r0);
  yy(1,0,0,0) = (1.f/3.f)*C*exp(-(x*x+y*y+z*z)/r0);
  yy(2,0,0,0) = (1.f/3.f)*C*exp(-(x*x+y*y+z*z)/r0);

  yy(3,0,0,0) = 0.0;
  yy(4,0,0,0) = 0.0;
  yy(5,0,0,0) = 0.0;
}



__global__ void ops_rtm_kernel_populate(
const int arg0,
const int arg1,
const int arg2,
int arg_idx0, int arg_idx1, int arg_idx2,
float* __restrict arg4,
float* __restrict arg5,
float* __restrict arg6,
int size0,
int size1,
int size2 ){


  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  int arg_idx[3];
  arg_idx[0] = arg_idx0+idx_x;
  arg_idx[1] = arg_idx1+idx_y;
  arg_idx[2] = arg_idx2+idx_z;
  arg4 += idx_x * 1+ idx_y * 1* dims_rtm_kernel_populate[4][0] + idx_z * 1 * dims_rtm_kernel_populate[4][0] * dims_rtm_kernel_populate[4][1];
  arg5 += idx_x * 1+ idx_y * 1* dims_rtm_kernel_populate[5][0] + idx_z * 1 * dims_rtm_kernel_populate[5][0] * dims_rtm_kernel_populate[5][1];
  arg6 += idx_x * 1+ idx_y * 1* dims_rtm_kernel_populate[6][0] + idx_z * 1 * dims_rtm_kernel_populate[6][0] * dims_rtm_kernel_populate[6][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    ACC<float> argp4(dims_rtm_kernel_populate[4][0], dims_rtm_kernel_populate[4][1], arg4);
    ACC<float> argp5(dims_rtm_kernel_populate[5][0], dims_rtm_kernel_populate[5][1], arg5);
    ACC<float> argp6(6, dims_rtm_kernel_populate[6][0], dims_rtm_kernel_populate[6][1], dims_rtm_kernel_populate[6][2], arg6);
    rtm_kernel_populate_gpu(&arg0, &arg1, &arg2, arg_idx,
                   argp4, argp5, argp6);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_rtm_kernel_populate(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6) {
#else
void ops_par_loop_rtm_kernel_populate_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[7] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,7,range,0)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,0,"rtm_kernel_populate");
    block->instance->OPS_kernels[0].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[3];
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 7,block, range, start, end, arg_idx) < 0) return;
  #endif

  #if defined(OPS_MPI)
  #if defined(OPS_LAZY)
  sub_block_list sb = OPS_sub_block_list[block->index];
  arg_idx[0] = sb->decomp_disp[0]+start[0];
  arg_idx[1] = sb->decomp_disp[1]+start[1];
  arg_idx[2] = sb->decomp_disp[2]+start[2];
  #endif
  #else //OPS_MPI
  arg_idx[0] = start[0];
  arg_idx[1] = start[1];
  arg_idx[2] = start[2];
  #endif //OPS_MPI
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];
  int zdim4 = args[4].dat->size[2];
  int xdim5 = args[5].dat->size[0];
  int ydim5 = args[5].dat->size[1];
  int zdim5 = args[5].dat->size[2];
  int xdim6 = args[6].dat->size[0];
  int ydim6 = args[6].dat->size[1];
  int zdim6 = args[6].dat->size[2];

  if (xdim4 != dims_rtm_kernel_populate_h[4][0] || ydim4 != dims_rtm_kernel_populate_h[4][1] || zdim4 != dims_rtm_kernel_populate_h[4][2] || xdim5 != dims_rtm_kernel_populate_h[5][0] || ydim5 != dims_rtm_kernel_populate_h[5][1] || zdim5 != dims_rtm_kernel_populate_h[5][2] || xdim6 != dims_rtm_kernel_populate_h[6][0] || ydim6 != dims_rtm_kernel_populate_h[6][1] || zdim6 != dims_rtm_kernel_populate_h[6][2]) {
    dims_rtm_kernel_populate_h[4][0] = xdim4;
    dims_rtm_kernel_populate_h[4][1] = ydim4;
    dims_rtm_kernel_populate_h[4][2] = zdim4;
    dims_rtm_kernel_populate_h[5][0] = xdim5;
    dims_rtm_kernel_populate_h[5][1] = ydim5;
    dims_rtm_kernel_populate_h[5][2] = zdim5;
    dims_rtm_kernel_populate_h[6][0] = xdim6;
    dims_rtm_kernel_populate_h[6][1] = ydim6;
    dims_rtm_kernel_populate_h[6][2] = zdim6;
    hipSafeCall(block->instance->ostream(), hipMemcpyToSymbol( dims_rtm_kernel_populate, dims_rtm_kernel_populate_h, sizeof(dims_rtm_kernel_populate)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, (z_size-1)/block->instance->OPS_block_size_z +1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  long long int dat4 = (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  long long int dat5 = (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  long long int dat6 = (block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);

  char *p_a[7];

  //set up initial pointers
  long long int base4 = args[4].dat->base_offset + 
           dat4 * 1 * (start[0] * args[4].stencil->stride[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    (start[2] * args[4].stencil->stride[2]);
  p_a[4] = (char *)args[4].data_d + base4;

  long long int base5 = args[5].dat->base_offset + 
           dat5 * 1 * (start[0] * args[5].stencil->stride[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    (start[2] * args[5].stencil->stride[2]);
  p_a[5] = (char *)args[5].data_d + base5;

  long long int base6 = args[6].dat->base_offset + 
           dat6 * 1 * (start[0] * args[6].stencil->stride[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    (start[2] * args[6].stencil->stride[2]);
  p_a[6] = (char *)args[6].data_d + base6;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 7);
  ops_halo_exchanges(args,7,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[0].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_rtm_kernel_populate<<<grid, tblock >>> (  *(int *)arg0.data, *(int *)arg1.data,
         *(int *)arg2.data, arg_idx[0], arg_idx[1], arg_idx[2],
         (float *)p_a[4], (float *)p_a[5],
         (float *)p_a[6],x_size, y_size, z_size);

  hipSafeCall(block->instance->ostream(), hipGetLastError());

  if (block->instance->OPS_diags>1) {
    hipSafeCall(block->instance->ostream(), hipDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[0].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 7);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);
  ops_set_halo_dirtybit3(&args[6],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[0].mpi_time += t2-t1;
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_rtm_kernel_populate(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 0;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 0;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 7;
  desc->args = (ops_arg*)ops_malloc(7*sizeof(ops_arg));
  desc->args[0] = arg0;
  char *tmp = (char*)ops_malloc(arg0.dim*sizeof(int));
  memcpy(tmp, arg0.data,arg0.dim*sizeof(int));
  desc->args[0].data = tmp;
  desc->args[1] = arg1;
  tmp = (char*)ops_malloc(arg1.dim*sizeof(int));
  memcpy(tmp, arg1.data,arg1.dim*sizeof(int));
  desc->args[1].data = tmp;
  desc->args[2] = arg2;
  tmp = (char*)ops_malloc(arg2.dim*sizeof(int));
  memcpy(tmp, arg2.data,arg2.dim*sizeof(int));
  desc->args[2].data = tmp;
  desc->args[3] = arg3;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->function = ops_par_loop_rtm_kernel_populate_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,0,"rtm_kernel_populate");
  }
  ops_enqueue_kernel(desc);
}
#endif
