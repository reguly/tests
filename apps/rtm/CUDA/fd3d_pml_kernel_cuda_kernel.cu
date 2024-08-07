//
// auto-generated by ops.py
//
__constant__ int dims_fd3d_pml_kernel [5][3];
static int dims_fd3d_pml_kernel_h [5][3] = {{0}};

//user function
__device__

void fd3d_pml_kernel_gpu(const ACC<float> &rho,
  const ACC<float> &mu,
  const ACC<float>& yy,
  ACC<float>& dy,
  const int *idx)
{
  float sigma = mu(0,0,0)/rho(0,0,0);
  float sigmax=0.0f;
  float sigmay=0.0f;
  float sigmaz=0.0f;

  if(idx[0]<=xbeg+pml_width){
    sigmax = (xbeg+pml_width-idx[0])*sigma/pml_width;
  }
  if(idx[0]>=xend-pml_width){
    sigmax=(idx[0]-(xend-pml_width))*sigma/pml_width;
  }
  if(idx[1]<=ybeg+pml_width){
    sigmay=(ybeg+pml_width-idx[1])*sigma/pml_width;
  }
  if(idx[1]>=yend-pml_width){
    sigmay=(idx[1]-(yend-pml_width))*sigma/pml_width;
  }
  if(idx[2]<=zbeg+pml_width){
    sigmaz=(zbeg+pml_width-idx[2])*sigma/pml_width;
  }
  if(idx[2]>=zend-pml_width){
    sigmaz=(idx[2]-(zend-pml_width))*sigma/pml_width;
  }





  float px = yy(0,0,0,0);
  float py = yy(1,0,0,0);
  float pz = yy(2,0,0,0);

  float vx = yy(3,0,0,0);
  float vy = yy(4,0,0,0);
  float vz = yy(5,0,0,0);

  float vxx=0.0f;
  float vyy=0.0f;
  float vzz=0.0f;

  float pxx=0.0f;
  float pxy=0.0f;
  float pxz=0.0f;

  float pyx=0.0f;
  float pyy=0.0f;
  float pyz=0.0f;

  float pzx=0.0f;
  float pzy=0.0f;
  float pzz=0.0f;

  for(int i=-halff;i<=halff;i++)
    {
#define CX
#ifndef CX
      pxx += yy(0,i,0,0)*c[i]*invdx;
      pyx += yy(1,i,0,0)*c[i]*invdx;
      pzx += yy(2,i,0,0)*c[i]*invdx;
      vxx += yy(3,i,0,0)*c[i]*invdx;

      pxy += yy(0,0,i,0)*c[i]*invdy;
      pyy += yy(1,0,i,0)*c[i]*invdy;
      pzy += yy(2,0,i,0)*c[i]*invdy;
      vyy += yy(4,0,i,0)*c[i]*invdy;

      pxz += yy(0,0,0,i)*c[i]*invdz;
      pyz += yy(1,0,0,i)*c[i]*invdz;
      pzz += yy(2,0,0,i)*c[i]*invdz;
      vzz += yy(5,0,0,i)*c[i]*invdz;

#else
      int j = i+halff;
      pxx += yy(0,i,0,0)*cx[j];
      pyx += yy(1,i,0,0)*cx[j];
      pzx += yy(2,i,0,0)*cx[j];
      vxx += yy(3,i,0,0)*cx[j];

      pxy += yy(0,0,i,0)*cy[j];
      pyy += yy(1,0,i,0)*cy[j];
      pzy += yy(2,0,i,0)*cy[j];
      vyy += yy(4,0,i,0)*cy[j];

      pxz += yy(0,0,0,i)*cz[j];
      pyz += yy(1,0,0,i)*cz[j];
      pzz += yy(2,0,0,i)*cz[j];
      vzz += yy(5,0,0,i)*cz[j];
#endif
    }

  dy(0,0,0,0)=vxx/rho(0,0,0) - sigmax*px;
  dy(1,0,0,0)=vyy/rho(0,0,0) - sigmay*py;
  dy(2,0,0,0)=vzz/rho(0,0,0) - sigmaz*pz;

  dy(3,0,0,0)=(pxx+pyx+pzx)*mu(0,0,0) - sigmax*vx;
  dy(4,0,0,0)=(pxy+pyy+pzy)*mu(0,0,0) - sigmay*vy;
  dy(5,0,0,0)=(pxz+pyz+pzz)*mu(0,0,0) - sigmaz*vz;

}



__global__ void ops_fd3d_pml_kernel(
float* __restrict arg0,
float* __restrict arg1,
float* __restrict arg2,
float* __restrict arg3,
int arg_idx0, int arg_idx1, int arg_idx2,
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
  arg0 += idx_x * 1+ idx_y * 1* dims_fd3d_pml_kernel[0][0] + idx_z * 1 * dims_fd3d_pml_kernel[0][0] * dims_fd3d_pml_kernel[0][1];
  arg1 += idx_x * 1+ idx_y * 1* dims_fd3d_pml_kernel[1][0] + idx_z * 1 * dims_fd3d_pml_kernel[1][0] * dims_fd3d_pml_kernel[1][1];
  arg2 += idx_x * 1+ idx_y * 1* dims_fd3d_pml_kernel[2][0] + idx_z * 1 * dims_fd3d_pml_kernel[2][0] * dims_fd3d_pml_kernel[2][1];
  arg3 += idx_x * 1+ idx_y * 1* dims_fd3d_pml_kernel[3][0] + idx_z * 1 * dims_fd3d_pml_kernel[3][0] * dims_fd3d_pml_kernel[3][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ACC<float> argp0(dims_fd3d_pml_kernel[0][0], dims_fd3d_pml_kernel[0][1], arg0);
    const ACC<float> argp1(dims_fd3d_pml_kernel[1][0], dims_fd3d_pml_kernel[1][1], arg1);
    const ACC<float> argp2(6, dims_fd3d_pml_kernel[2][0], dims_fd3d_pml_kernel[2][1], dims_fd3d_pml_kernel[2][2], arg2);
    ACC<float> argp3(6, dims_fd3d_pml_kernel[3][0], dims_fd3d_pml_kernel[3][1], dims_fd3d_pml_kernel[3][2], arg3);
    fd3d_pml_kernel_gpu(
     argp0, argp1, argp2, argp3, arg_idx);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_fd3d_pml_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
#else
void ops_par_loop_fd3d_pml_kernel_execute(ops_kernel_descriptor *desc) {
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
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,5,range,1)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,1,"fd3d_pml_kernel");
    block->instance->OPS_kernels[1].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];

  int arg_idx[3];
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 5,block, range, start, end, arg_idx) < 0) return;
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

  if (xdim0 != dims_fd3d_pml_kernel_h[0][0] || ydim0 != dims_fd3d_pml_kernel_h[0][1] || zdim0 != dims_fd3d_pml_kernel_h[0][2] || xdim1 != dims_fd3d_pml_kernel_h[1][0] || ydim1 != dims_fd3d_pml_kernel_h[1][1] || zdim1 != dims_fd3d_pml_kernel_h[1][2] || xdim2 != dims_fd3d_pml_kernel_h[2][0] || ydim2 != dims_fd3d_pml_kernel_h[2][1] || zdim2 != dims_fd3d_pml_kernel_h[2][2] || xdim3 != dims_fd3d_pml_kernel_h[3][0] || ydim3 != dims_fd3d_pml_kernel_h[3][1] || zdim3 != dims_fd3d_pml_kernel_h[3][2]) {
    dims_fd3d_pml_kernel_h[0][0] = xdim0;
    dims_fd3d_pml_kernel_h[0][1] = ydim0;
    dims_fd3d_pml_kernel_h[0][2] = zdim0;
    dims_fd3d_pml_kernel_h[1][0] = xdim1;
    dims_fd3d_pml_kernel_h[1][1] = ydim1;
    dims_fd3d_pml_kernel_h[1][2] = zdim1;
    dims_fd3d_pml_kernel_h[2][0] = xdim2;
    dims_fd3d_pml_kernel_h[2][1] = ydim2;
    dims_fd3d_pml_kernel_h[2][2] = zdim2;
    dims_fd3d_pml_kernel_h[3][0] = xdim3;
    dims_fd3d_pml_kernel_h[3][1] = ydim3;
    dims_fd3d_pml_kernel_h[3][2] = zdim3;
    cutilSafeCall(block->instance->ostream(), cudaMemcpyToSymbol( dims_fd3d_pml_kernel, dims_fd3d_pml_kernel_h, sizeof(dims_fd3d_pml_kernel)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, (z_size-1)/block->instance->OPS_block_size_z +1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  long long int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  long long int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  long long int dat2 = (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  long long int dat3 = (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);

  char *p_a[5];

  //set up initial pointers
  long long int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    (start[2] * args[0].stencil->stride[2]);
  p_a[0] = (char *)args[0].data_d + base0;

  long long int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    (start[2] * args[1].stencil->stride[2]);
  p_a[1] = (char *)args[1].data_d + base1;

  long long int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    (start[2] * args[2].stencil->stride[2]);
  p_a[2] = (char *)args[2].data_d + base2;

  long long int base3 = args[3].dat->base_offset + 
           dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    (start[2] * args[3].stencil->stride[2]);
  p_a[3] = (char *)args[3].data_d + base3;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 5);
  ops_halo_exchanges(args,5,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[1].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_fd3d_pml_kernel<<<grid, tblock >>> ( 
     (float *)p_a[0], (float *)p_a[1],
     (float *)p_a[2], (float *)p_a[3],
     arg_idx[0], arg_idx[1], arg_idx[2],
    x_size, y_size, z_size);

  cutilSafeCall(block->instance->ostream(), cudaGetLastError());

  if (block->instance->OPS_diags>1) {
    cutilSafeCall(block->instance->ostream(), cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[1].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 5);
  ops_set_halo_dirtybit3(&args[3],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[1].mpi_time += t2-t1;
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_fd3d_pml_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 1;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 1;
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
  desc->function = ops_par_loop_fd3d_pml_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,1,"fd3d_pml_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
