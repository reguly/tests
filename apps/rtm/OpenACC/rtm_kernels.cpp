//
// auto-generated by ops.py
//
#include "./OpenACC/rtm_common.h"

#include <openacc.h>

void ops_init_backend() {acc_set_device_num(ops_get_proc()%acc_get_num_devices(acc_device_nvidia),acc_device_nvidia); }

void ops_decl_const_char(OPS_instance *instance, int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(instance);
  if (!strcmp(name,"dx")) {
    dx = *(float*)dat;
  }
  else
  if (!strcmp(name,"dz")) {
    dz = *(float*)dat;
  }
  else
  if (!strcmp(name,"invdx")) {
    invdx = *(float*)dat;
  }
  else
  if (!strcmp(name,"invdy")) {
    invdy = *(float*)dat;
  }
  else
  if (!strcmp(name,"invdz")) {
    invdz = *(float*)dat;
  }
  else
  if (!strcmp(name,"nx")) {
    nx = *(int*)dat;
  }
  else
  if (!strcmp(name,"ny")) {
    ny = *(int*)dat;
  }
  else
  if (!strcmp(name,"nz")) {
    nz = *(int*)dat;
  }
  else
  if (!strcmp(name,"pml_width")) {
    pml_width = *(int*)dat;
  }
  else
  if (!strcmp(name,"xbeg")) {
    xbeg = *(int*)dat;
  }
  else
  if (!strcmp(name,"ybeg")) {
    ybeg = *(int*)dat;
  }
  else
  if (!strcmp(name,"zbeg")) {
    zbeg = *(int*)dat;
  }
  else
  if (!strcmp(name,"xend")) {
    xend = *(int*)dat;
  }
  else
  if (!strcmp(name,"yend")) {
    yend = *(int*)dat;
  }
  else
  if (!strcmp(name,"zend")) {
    zend = *(int*)dat;
  }
  else
  if (!strcmp(name,"xpmlbeg")) {
    xpmlbeg = *(int*)dat;
  }
  else
  if (!strcmp(name,"ypmlbeg")) {
    ypmlbeg = *(int*)dat;
  }
  else
  if (!strcmp(name,"zpmlbeg")) {
    zpmlbeg = *(int*)dat;
  }
  else
  if (!strcmp(name,"xpmlend")) {
    xpmlend = *(int*)dat;
  }
  else
  if (!strcmp(name,"ypmlend")) {
    ypmlend = *(int*)dat;
  }
  else
  if (!strcmp(name,"zpmlend")) {
    zpmlend = *(int*)dat;
  }
  else
  if (!strcmp(name,"halff")) {
    halff = *(int*)dat;
  }
  else
  if (!strcmp(name,"order")) {
    order = *(int*)dat;
  }
  else
  if (!strcmp(name,"c")) {
    for ( int d=0; d<order+1; d++ ){
      c[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"cx")) {
    for ( int d=0; d<order+1; d++ ){
      cx[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"cy")) {
    for ( int d=0; d<order+1; d++ ){
      cy[d] = ((float*)dat)[d];
    }
  }
  else
  if (!strcmp(name,"cz")) {
    for ( int d=0; d<order+1; d++ ){
      cz[d] = ((float*)dat)[d];
    }
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}

//user kernel files
#include "rtm_kernel_populate_openacc_kernel.cpp"
#include "fd3d_pml_kernel_openacc_kernel.cpp"
#include "calc_ytemp_kernel_openacc_kernel.cpp"
#include "calc_ytemp2_kernel_openacc_kernel.cpp"
#include "final_update_kernel_openacc_kernel.cpp"
