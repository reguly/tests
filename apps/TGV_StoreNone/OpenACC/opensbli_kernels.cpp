//
// auto-generated by ops.py
//
#include "./OpenACC/opensbli_common.h"

#include <openacc.h>

void ops_init_backend() {acc_set_device_num(ops_get_proc()%acc_get_num_devices(acc_device_nvidia),acc_device_nvidia); }

void ops_decl_const_char(OPS_instance *instance, int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(instance);
  if (!strcmp(name,"block0np0")) {
    block0np0 = *(int*)dat;
  }
  else
  if (!strcmp(name,"block0np1")) {
    block0np1 = *(int*)dat;
  }
  else
  if (!strcmp(name,"block0np2")) {
    block0np2 = *(int*)dat;
  }
  else
  if (!strcmp(name,"Delta0block0")) {
    Delta0block0 = *(double*)dat;
  }
  else
  if (!strcmp(name,"Delta1block0")) {
    Delta1block0 = *(double*)dat;
  }
  else
  if (!strcmp(name,"Delta2block0")) {
    Delta2block0 = *(double*)dat;
  }
  else
  if (!strcmp(name,"niter")) {
    niter = *(int*)dat;
  }
  else
  if (!strcmp(name,"dt")) {
    dt = *(double*)dat;
  }
  else
  if (!strcmp(name,"gama")) {
    gama = *(double*)dat;
  }
  else
  if (!strcmp(name,"Minf")) {
    Minf = *(double*)dat;
  }
  else
  if (!strcmp(name,"Re")) {
    Re = *(double*)dat;
  }
  else
  if (!strcmp(name,"Pr")) {
    Pr = *(double*)dat;
  }
  else
  if (!strcmp(name,"inv_0")) {
    inv_0 = *(double*)dat;
  }
  else
  if (!strcmp(name,"inv_1")) {
    inv_1 = *(double*)dat;
  }
  else
  if (!strcmp(name,"inv_2")) {
    inv_2 = *(double*)dat;
  }
  else
  if (!strcmp(name,"inv_3")) {
    inv_3 = *(double*)dat;
  }
  else
  if (!strcmp(name,"inv_4")) {
    inv_4 = *(double*)dat;
  }
  else
  if (!strcmp(name,"inv_5")) {
    inv_5 = *(double*)dat;
  }
  else
  if (!strcmp(name,"rc6")) {
    rc6 = *(double*)dat;
  }
  else
  if (!strcmp(name,"rc7")) {
    rc7 = *(double*)dat;
  }
  else
  if (!strcmp(name,"rcinv8")) {
    rcinv8 = *(double*)dat;
  }
  else
  if (!strcmp(name,"rc9")) {
    rc9 = *(double*)dat;
  }
  else
  if (!strcmp(name,"rc10")) {
    rc10 = *(double*)dat;
  }
  else
  if (!strcmp(name,"rcinv11")) {
    rcinv11 = *(double*)dat;
  }
  else
  if (!strcmp(name,"rcinv12")) {
    rcinv12 = *(double*)dat;
  }
  else
  if (!strcmp(name,"rcinv13")) {
    rcinv13 = *(double*)dat;
  }
  else
  if (!strcmp(name,"rc14")) {
    rc14 = *(double*)dat;
  }
  else
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}

//user kernel files
#include "opensbliblock00Kernel032_openacc_kernel.cpp"
#include "opensbliblock00Kernel026_openacc_kernel.cpp"
#include "opensbliblock00Kernel027_openacc_kernel.cpp"
#include "opensbliblock00Kernel028_openacc_kernel.cpp"
#include "opensbliblock00Kernel029_openacc_kernel.cpp"
#include "opensbliblock00Kernel030_openacc_kernel.cpp"
#include "opensbliblock00Kernel031_openacc_kernel.cpp"
#include "opensbliblock00Kernel033_openacc_kernel.cpp"
#include "opensbliblock00Kernel001_openacc_kernel.cpp"
#include "opensbliblock00Kernel005_openacc_kernel.cpp"
#include "opensbliblock00Kernel009_openacc_kernel.cpp"
#include "opensbliblock00Kernel017_openacc_kernel.cpp"
#include "opensbliblock00Kernel018_openacc_kernel.cpp"
#include "opensbliblock00Kernel000_openacc_kernel.cpp"
#include "opensbliblock00Kernel002_openacc_kernel.cpp"
#include "opensbliblock00Kernel003_openacc_kernel.cpp"
#include "opensbliblock00Kernel004_openacc_kernel.cpp"
#include "opensbliblock00Kernel006_openacc_kernel.cpp"
#include "opensbliblock00Kernel007_openacc_kernel.cpp"
#include "opensbliblock00Kernel008_openacc_kernel.cpp"
#include "opensbliblock00Kernel010_openacc_kernel.cpp"
#include "opensbliblock00Kernel011_openacc_kernel.cpp"
#include "opensbliblock00Kernel024_openacc_kernel.cpp"
#include "opensbliblock00Kernel025_openacc_kernel.cpp"
#include "opensbliblock00Kernel035_openacc_kernel.cpp"
#include "opensbliblock00Kernel034_openacc_kernel.cpp"
