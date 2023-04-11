//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_fd3d_pml_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
#else
void ops_par_loop_fd3d_pml_kernel_execute(ops_kernel_descriptor *desc) {
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
  if (!ops_checkpointing_before(args,5,range,1)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,1,"fd3d_pml_kernel");
    block->instance->OPS_kernels[1].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "fd3d_pml_kernel");
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
  if (compute_ranges(args, 5,block, range, start, end, arg_idx) < 0) return;
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
  int xdim0_fd3d_pml_kernel = args[0].dat->size[0];
  int ydim0_fd3d_pml_kernel = args[0].dat->size[1];
  int xdim1_fd3d_pml_kernel = args[1].dat->size[0];
  int ydim1_fd3d_pml_kernel = args[1].dat->size[1];
  int xdim2_fd3d_pml_kernel = args[2].dat->size[0];
  int ydim2_fd3d_pml_kernel = args[2].dat->size[1];
  int zdim2_fd3d_pml_kernel = args[2].dat->size[2];
  int xdim3_fd3d_pml_kernel = args[3].dat->size[0];
  int ydim3_fd3d_pml_kernel = args[3].dat->size[1];
  int zdim3_fd3d_pml_kernel = args[3].dat->size[2];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset/sizeof(float);
  float* rho_p = (float*)args[0].data_d;

  int base1 = args[1].dat->base_offset/sizeof(float);
  float* mu_p = (float*)args[1].data_d;

  int base2 = args[2].dat->base_offset/sizeof(float);
  float* yy_p = (float*)args[2].data_d;

  int base3 = args[3].dat->base_offset/sizeof(float);
  float* dy_p = (float*)args[3].data_d;




  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_device(args, 5);
  ops_halo_exchanges(args,5,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[1].mpi_time += __t1-__t2;
  }

  int start_0 = start[0];
  int end_0 = end[0];
  int arg_idx_0 = arg_idx[0];
  int start_1 = start[1];
  int end_1 = end[1];
  int arg_idx_1 = arg_idx[1];
  int start_2 = start[2];
  int end_2 = end[2];
  int arg_idx_2 = arg_idx[2];
  if ((end[0]-start[0])>0 && (end[1]-start[1])>0 && (end[2]-start[2])>0) {
    block->instance->sycl_instance->queue->submit([&](cl::sycl::handler &cgh) {

      auto invdx_sycl = (*invdx_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto invdy_sycl = (*invdy_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto invdz_sycl = (*invdz_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto pml_width_sycl = (*pml_width_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto xbeg_sycl = (*xbeg_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto ybeg_sycl = (*ybeg_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto zbeg_sycl = (*zbeg_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto xend_sycl = (*xend_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto yend_sycl = (*yend_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto zend_sycl = (*zend_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto halff_sycl = (*halff_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto c_sycl = (*c_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto cx_sycl = (*cx_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto cy_sycl = (*cy_p).template get_access<cl::sycl::access::mode::read>(cgh);
      auto cz_sycl = (*cz_p).template get_access<cl::sycl::access::mode::read>(cgh);

      cgh.parallel_for<class fd3d_pml_kernel_kernel>(cl::sycl::nd_range<3>(cl::sycl::range<3>(
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
        int idx[] = {arg_idx_0+n_x, arg_idx_1+n_y, arg_idx_2+n_z};
        const ACC<float> rho(xdim0_fd3d_pml_kernel, ydim0_fd3d_pml_kernel, &rho_p[0] + base0 + n_x*1 + n_y * xdim0_fd3d_pml_kernel*1 + n_z * xdim0_fd3d_pml_kernel * ydim0_fd3d_pml_kernel*1);
        const ACC<float> mu(xdim1_fd3d_pml_kernel, ydim1_fd3d_pml_kernel, &mu_p[0] + base1 + n_x*1 + n_y * xdim1_fd3d_pml_kernel*1 + n_z * xdim1_fd3d_pml_kernel * ydim1_fd3d_pml_kernel*1);
        #ifdef OPS_SOA
        const ACC<float> yy(6, xdim2_fd3d_pml_kernel, ydim2_fd3d_pml_kernel, zdim2_fd3d_pml_kernel, &yy_p[0] + base2 + n_x*1 + n_y * xdim2_fd3d_pml_kernel*1 + n_z * xdim2_fd3d_pml_kernel * ydim2_fd3d_pml_kernel*1);
        #else
        const ACC<float> yy(6, xdim2_fd3d_pml_kernel, ydim2_fd3d_pml_kernel, zdim2_fd3d_pml_kernel, &yy_p[0] + 6*(n_x*1 + n_y * xdim2_fd3d_pml_kernel*1 + n_z * xdim2_fd3d_pml_kernel * ydim2_fd3d_pml_kernel*1));
        #endif
        #ifdef OPS_SOA
        ACC<float> dy(6, xdim3_fd3d_pml_kernel, ydim3_fd3d_pml_kernel, zdim3_fd3d_pml_kernel, &dy_p[0] + base3 + n_x*1 + n_y * xdim3_fd3d_pml_kernel*1 + n_z * xdim3_fd3d_pml_kernel * ydim3_fd3d_pml_kernel*1);
        #else
        ACC<float> dy(6, xdim3_fd3d_pml_kernel, ydim3_fd3d_pml_kernel, zdim3_fd3d_pml_kernel, &dy_p[0] + 6*(n_x*1 + n_y * xdim3_fd3d_pml_kernel*1 + n_z * xdim3_fd3d_pml_kernel * ydim3_fd3d_pml_kernel*1));
        #endif
        //USER CODE
        if (n_x < end_0 && n_y < end_1 && n_z < end_2) {
          
  float sigma = mu(0,0,0)/rho(0,0,0);
  float sigmax=0.0f;
  float sigmay=0.0f;
  float sigmaz=0.0f;

  if(idx[0]<=xbeg_sycl[0]+pml_width_sycl[0]){
    sigmax = (xbeg_sycl[0]+pml_width_sycl[0]-idx[0])*sigma/pml_width_sycl[0];
  }
  if(idx[0]>=xend_sycl[0]-pml_width_sycl[0]){
    sigmax=(idx[0]-(xend_sycl[0]-pml_width_sycl[0]))*sigma/pml_width_sycl[0];
  }
  if(idx[1]<=ybeg_sycl[0]+pml_width_sycl[0]){
    sigmay=(ybeg_sycl[0]+pml_width_sycl[0]-idx[1])*sigma/pml_width_sycl[0];
  }
  if(idx[1]>=yend_sycl[0]-pml_width_sycl[0]){
    sigmay=(idx[1]-(yend_sycl[0]-pml_width_sycl[0]))*sigma/pml_width_sycl[0];
  }
  if(idx[2]<=zbeg_sycl[0]+pml_width_sycl[0]){
    sigmaz=(zbeg_sycl[0]+pml_width_sycl[0]-idx[2])*sigma/pml_width_sycl[0];
  }
  if(idx[2]>=zend_sycl[0]-pml_width_sycl[0]){
    sigmaz=(idx[2]-(zend_sycl[0]-pml_width_sycl[0]))*sigma/pml_width_sycl[0];
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

  for(int i=-halff_sycl[0];i<=halff_sycl[0];i++)
    {
#define CX
#ifndef CX
      pxx += yy(0,i,0,0)*c_sycl[i]*invdx_sycl[0];
      pyx += yy(1,i,0,0)*c_sycl[i]*invdx_sycl[0];
      pzx += yy(2,i,0,0)*c_sycl[i]*invdx_sycl[0];
      vxx += yy(3,i,0,0)*c_sycl[i]*invdx_sycl[0];

      pxy += yy(0,0,i,0)*c_sycl[i]*invdy_sycl[0];
      pyy += yy(1,0,i,0)*c_sycl[i]*invdy_sycl[0];
      pzy += yy(2,0,i,0)*c_sycl[i]*invdy_sycl[0];
      vyy += yy(4,0,i,0)*c_sycl[i]*invdy_sycl[0];

      pxz += yy(0,0,0,i)*c_sycl[i]*invdz_sycl[0];
      pyz += yy(1,0,0,i)*c_sycl[i]*invdz_sycl[0];
      pzz += yy(2,0,0,i)*c_sycl[i]*invdz_sycl[0];
      vzz += yy(5,0,0,i)*c_sycl[i]*invdz_sycl[0];

#else
      int j = i+halff_sycl[0];
      pxx += yy(0,i,0,0)*cx_sycl[j];
      pyx += yy(1,i,0,0)*cx_sycl[j];
      pzx += yy(2,i,0,0)*cx_sycl[j];
      vxx += yy(3,i,0,0)*cx_sycl[j];

      pxy += yy(0,0,i,0)*cy_sycl[j];
      pyy += yy(1,0,i,0)*cy_sycl[j];
      pzy += yy(2,0,i,0)*cy_sycl[j];
      vyy += yy(4,0,i,0)*cy_sycl[j];

      pxz += yy(0,0,0,i)*cz_sycl[j];
      pyz += yy(1,0,0,i)*cz_sycl[j];
      pzz += yy(2,0,0,i)*cz_sycl[j];
      vzz += yy(5,0,0,i)*cz_sycl[j];
#endif
    }

  dy(0,0,0,0)=vxx/rho(0,0,0) - sigmax*px;
  dy(1,0,0,0)=vyy/rho(0,0,0) - sigmay*py;
  dy(2,0,0,0)=vzz/rho(0,0,0) - sigmaz*pz;

  dy(3,0,0,0)=(pxx+pyx+pzx)*mu(0,0,0) - sigmax*vx;
  dy(4,0,0,0)=(pxy+pyy+pzy)*mu(0,0,0) - sigmay*vy;
  dy(5,0,0,0)=(pxz+pyz+pzz)*mu(0,0,0) - sigmaz*vz;


        }
      });
    });
  }
  if (block->instance->OPS_diags > 1) {
    block->instance->sycl_instance->queue->wait();
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[1].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 5);
  ops_set_halo_dirtybit3(&args[3],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[1].mpi_time += __t1-__t2;
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
