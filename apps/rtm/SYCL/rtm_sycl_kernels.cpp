//
// auto-generated by ops.py
//
//header
#define OPS_3D
#define OPS_SOA
#define OPS_API 2
#include "ops_lib_core.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#include <limits>
#endif

#include "ops_sycl_rt_support.h"
#include "ops_sycl_reduction.h"
// global constants
cl::sycl::buffer<float,1> *dx_p=nullptr;
extern float dx;
cl::sycl::buffer<float,1> *dz_p=nullptr;
extern float dz;
cl::sycl::buffer<float,1> *invdx_p=nullptr;
extern float invdx;
cl::sycl::buffer<float,1> *invdy_p=nullptr;
extern float invdy;
cl::sycl::buffer<float,1> *invdz_p=nullptr;
extern float invdz;
cl::sycl::buffer<int,1> *nx_p=nullptr;
extern int nx;
cl::sycl::buffer<int,1> *ny_p=nullptr;
extern int ny;
cl::sycl::buffer<int,1> *nz_p=nullptr;
extern int nz;
cl::sycl::buffer<int,1> *pml_width_p=nullptr;
extern int pml_width;
cl::sycl::buffer<int,1> *xbeg_p=nullptr;
extern int xbeg;
cl::sycl::buffer<int,1> *ybeg_p=nullptr;
extern int ybeg;
cl::sycl::buffer<int,1> *zbeg_p=nullptr;
extern int zbeg;
cl::sycl::buffer<int,1> *xend_p=nullptr;
extern int xend;
cl::sycl::buffer<int,1> *yend_p=nullptr;
extern int yend;
cl::sycl::buffer<int,1> *zend_p=nullptr;
extern int zend;
cl::sycl::buffer<int,1> *xpmlbeg_p=nullptr;
extern int xpmlbeg;
cl::sycl::buffer<int,1> *ypmlbeg_p=nullptr;
extern int ypmlbeg;
cl::sycl::buffer<int,1> *zpmlbeg_p=nullptr;
extern int zpmlbeg;
cl::sycl::buffer<int,1> *xpmlend_p=nullptr;
extern int xpmlend;
cl::sycl::buffer<int,1> *ypmlend_p=nullptr;
extern int ypmlend;
cl::sycl::buffer<int,1> *zpmlend_p=nullptr;
extern int zpmlend;
cl::sycl::buffer<int,1> *halff_p=nullptr;
extern int halff;
cl::sycl::buffer<int,1> *order_p=nullptr;
extern int order;
cl::sycl::buffer<float,1> *c_p=nullptr;
extern float *c;
cl::sycl::buffer<float,1> *cx_p=nullptr;
extern float *cx;
cl::sycl::buffer<float,1> *cy_p=nullptr;
extern float *cy;
cl::sycl::buffer<float,1> *cz_p=nullptr;
extern float *cz;

void ops_init_backend() {}

void ops_decl_const_char(OPS_instance *instance, int dim, char const * type, int size, char * dat, char const * name ) {
  if (!strcmp(name,"dx")) {
    if (dx_p == nullptr) dx_p = new cl::sycl::buffer<float,1>(cl::sycl::range<1>(dim));
    auto accessor = (*dx_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"dz")) {
    if (dz_p == nullptr) dz_p = new cl::sycl::buffer<float,1>(cl::sycl::range<1>(dim));
    auto accessor = (*dz_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"invdx")) {
    if (invdx_p == nullptr) invdx_p = new cl::sycl::buffer<float,1>(cl::sycl::range<1>(dim));
    auto accessor = (*invdx_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"invdy")) {
    if (invdy_p == nullptr) invdy_p = new cl::sycl::buffer<float,1>(cl::sycl::range<1>(dim));
    auto accessor = (*invdy_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"invdz")) {
    if (invdz_p == nullptr) invdz_p = new cl::sycl::buffer<float,1>(cl::sycl::range<1>(dim));
    auto accessor = (*invdz_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"nx")) {
    if (nx_p == nullptr) nx_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*nx_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"ny")) {
    if (ny_p == nullptr) ny_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*ny_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"nz")) {
    if (nz_p == nullptr) nz_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*nz_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"pml_width")) {
    if (pml_width_p == nullptr) pml_width_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*pml_width_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"xbeg")) {
    if (xbeg_p == nullptr) xbeg_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*xbeg_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"ybeg")) {
    if (ybeg_p == nullptr) ybeg_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*ybeg_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"zbeg")) {
    if (zbeg_p == nullptr) zbeg_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*zbeg_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"xend")) {
    if (xend_p == nullptr) xend_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*xend_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"yend")) {
    if (yend_p == nullptr) yend_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*yend_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"zend")) {
    if (zend_p == nullptr) zend_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*zend_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"xpmlbeg")) {
    if (xpmlbeg_p == nullptr) xpmlbeg_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*xpmlbeg_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"ypmlbeg")) {
    if (ypmlbeg_p == nullptr) ypmlbeg_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*ypmlbeg_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"zpmlbeg")) {
    if (zpmlbeg_p == nullptr) zpmlbeg_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*zpmlbeg_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"xpmlend")) {
    if (xpmlend_p == nullptr) xpmlend_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*xpmlend_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"ypmlend")) {
    if (ypmlend_p == nullptr) ypmlend_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*ypmlend_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"zpmlend")) {
    if (zpmlend_p == nullptr) zpmlend_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*zpmlend_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"halff")) {
    if (halff_p == nullptr) halff_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*halff_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"order")) {
    if (order_p == nullptr) order_p = new cl::sycl::buffer<int,1>(cl::sycl::range<1>(dim));
    auto accessor = (*order_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((int*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"c")) {
    if (c_p == nullptr) c_p = new cl::sycl::buffer<float,1>(cl::sycl::range<1>(dim));
    auto accessor = (*c_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"cx")) {
    if (cx_p == nullptr) cx_p = new cl::sycl::buffer<float,1>(cl::sycl::range<1>(dim));
    auto accessor = (*cx_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"cy")) {
    if (cy_p == nullptr) cy_p = new cl::sycl::buffer<float,1>(cl::sycl::range<1>(dim));
    auto accessor = (*cy_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"cz")) {
    if (cz_p == nullptr) cz_p = new cl::sycl::buffer<float,1>(cl::sycl::range<1>(dim));
    auto accessor = (*cz_p).get_access<cl::sycl::access::mode::write>();
    for ( int d=0; d<dim; d++ ){
      accessor[d] = ((float*)dat)[d];
    }
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}

//user kernel files
#include "rtm_kernel_populate_sycl_kernel.cpp"
#include "fd3d_pml_kernel_sycl_kernel.cpp"
#include "calc_ytemp_kernel_sycl_kernel.cpp"
#include "calc_ytemp2_kernel_sycl_kernel.cpp"
#include "final_update_kernel_sycl_kernel.cpp"
