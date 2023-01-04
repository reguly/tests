//
// auto-generated by ops.py//

//header
#include <hip/hip_runtime.h>
#define OPS_API 2
#define OPS_3D
#include "ops_lib_core.h"

#include "ops_hip_rt_support.h"
#include "ops_hip_reduction.h"


#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
// global constants
#define block0np0 block0np0_OPSCONSTANT
__constant__ int block0np0;
#define block0np1 block0np1_OPSCONSTANT
__constant__ int block0np1;
#define block0np2 block0np2_OPSCONSTANT
__constant__ int block0np2;
#define Delta0block0 Delta0block0_OPSCONSTANT
__constant__ double Delta0block0;
#define Delta1block0 Delta1block0_OPSCONSTANT
__constant__ double Delta1block0;
#define Delta2block0 Delta2block0_OPSCONSTANT
__constant__ double Delta2block0;
#define niter niter_OPSCONSTANT
__constant__ int niter;
#define dt dt_OPSCONSTANT
__constant__ double dt;
#define gama gama_OPSCONSTANT
__constant__ double gama;
#define Minf Minf_OPSCONSTANT
__constant__ double Minf;
#define Re Re_OPSCONSTANT
__constant__ double Re;
#define Pr Pr_OPSCONSTANT
__constant__ double Pr;
#define inv_0 inv_0_OPSCONSTANT
__constant__ double inv_0;
#define inv_1 inv_1_OPSCONSTANT
__constant__ double inv_1;
#define inv_2 inv_2_OPSCONSTANT
__constant__ double inv_2;
#define inv_3 inv_3_OPSCONSTANT
__constant__ double inv_3;
#define inv_4 inv_4_OPSCONSTANT
__constant__ double inv_4;
#define inv_5 inv_5_OPSCONSTANT
__constant__ double inv_5;
#define rc6 rc6_OPSCONSTANT
__constant__ double rc6;
#define rc7 rc7_OPSCONSTANT
__constant__ double rc7;
#define rcinv8 rcinv8_OPSCONSTANT
__constant__ double rcinv8;
#define rc9 rc9_OPSCONSTANT
__constant__ double rc9;
#define rc10 rc10_OPSCONSTANT
__constant__ double rc10;
#define rcinv11 rcinv11_OPSCONSTANT
__constant__ double rcinv11;
#define rcinv12 rcinv12_OPSCONSTANT
__constant__ double rcinv12;
#define rcinv13 rcinv13_OPSCONSTANT
__constant__ double rcinv13;
#define rc14 rc14_OPSCONSTANT
__constant__ double rc14;

void ops_init_backend() {}

//Dummy kernel to make sure constants are not optimized out
__global__ void ops_internal_this_is_stupid() {
((int*)&block0np0)[0]=0;
((int*)&block0np1)[0]=0;
((int*)&block0np2)[0]=0;
((int*)&Delta0block0)[0]=0;
((int*)&Delta1block0)[0]=0;
((int*)&Delta2block0)[0]=0;
((int*)&niter)[0]=0;
((int*)&dt)[0]=0;
((int*)&gama)[0]=0;
((int*)&Minf)[0]=0;
((int*)&Re)[0]=0;
((int*)&Pr)[0]=0;
((int*)&inv_0)[0]=0;
((int*)&inv_1)[0]=0;
((int*)&inv_2)[0]=0;
((int*)&inv_3)[0]=0;
((int*)&inv_4)[0]=0;
((int*)&inv_5)[0]=0;
((int*)&rc6)[0]=0;
((int*)&rc7)[0]=0;
((int*)&rcinv8)[0]=0;
((int*)&rc9)[0]=0;
((int*)&rc10)[0]=0;
((int*)&rcinv11)[0]=0;
((int*)&rcinv12)[0]=0;
((int*)&rcinv13)[0]=0;
((int*)&rc14)[0]=0;
}

void ops_decl_const_char(OPS_instance *instance, int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(instance);
  if (!strcmp(name,"block0np0")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(block0np0_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"block0np1")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(block0np1_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"block0np2")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(block0np2_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"Delta0block0")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(Delta0block0_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"Delta1block0")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(Delta1block0_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"Delta2block0")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(Delta2block0_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"niter")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(niter_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"dt")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(dt_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"gama")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(gama_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"Minf")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(Minf_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"Re")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(Re_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"Pr")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(Pr_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"inv_0")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(inv_0_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"inv_1")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(inv_1_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"inv_2")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(inv_2_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"inv_3")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(inv_3_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"inv_4")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(inv_4_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"inv_5")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(inv_5_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rc6")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rc6_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rc7")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rc7_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rcinv8")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rcinv8_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rc9")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rc9_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rc10")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rc10_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rcinv11")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rcinv11_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rcinv12")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rcinv12_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rcinv13")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rcinv13_OPSCONSTANT), dat, dim*size));
  }
  else
  if (!strcmp(name,"rc14")) {
    hipSafeCall(instance->ostream(),hipMemcpyToSymbol(HIP_SYMBOL(rc14_OPSCONSTANT), dat, dim*size));
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}


//user kernel files
#include "opensbliblock00Kernel032_hip_kernel.cpp"
#include "opensbliblock00Kernel026_hip_kernel.cpp"
#include "opensbliblock00Kernel027_hip_kernel.cpp"
#include "opensbliblock00Kernel028_hip_kernel.cpp"
#include "opensbliblock00Kernel029_hip_kernel.cpp"
#include "opensbliblock00Kernel030_hip_kernel.cpp"
#include "opensbliblock00Kernel031_hip_kernel.cpp"
#include "opensbliblock00Kernel033_hip_kernel.cpp"
#include "opensbliblock00Kernel001_hip_kernel.cpp"
#include "opensbliblock00Kernel005_hip_kernel.cpp"
#include "opensbliblock00Kernel009_hip_kernel.cpp"
#include "opensbliblock00Kernel017_hip_kernel.cpp"
#include "opensbliblock00Kernel018_hip_kernel.cpp"
#include "opensbliblock00Kernel000_hip_kernel.cpp"
#include "opensbliblock00Kernel002_hip_kernel.cpp"
#include "opensbliblock00Kernel003_hip_kernel.cpp"
#include "opensbliblock00Kernel004_hip_kernel.cpp"
#include "opensbliblock00Kernel006_hip_kernel.cpp"
#include "opensbliblock00Kernel007_hip_kernel.cpp"
#include "opensbliblock00Kernel008_hip_kernel.cpp"
#include "opensbliblock00Kernel010_hip_kernel.cpp"
#include "opensbliblock00Kernel011_hip_kernel.cpp"
#include "opensbliblock00Kernel024_hip_kernel.cpp"
#include "opensbliblock00Kernel025_hip_kernel.cpp"
#include "opensbliblock00Kernel035_hip_kernel.cpp"
#include "opensbliblock00Kernel034_hip_kernel.cpp"
