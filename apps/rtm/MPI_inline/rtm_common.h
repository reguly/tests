//
// auto-generated by ops.py
//
//header
#include <math.h>
#define OPS_API 2
#define OPS_3D
#define OPS_SOA
#include "ops_macros.h"
#ifdef __cplusplus
#include "ops_lib_core.h"
#endif
#if defined(OPS_MPI) && defined(__cplusplus)
#include "ops_mpi_core.h"
#endif

// global constants
extern float dx;
extern float dz;
extern float invdx;
extern float invdy;
extern float invdz;
extern int nx;
extern int ny;
extern int nz;
extern int pml_width;
extern int xbeg;
extern int ybeg;
extern int zbeg;
extern int xend;
extern int yend;
extern int zend;
extern int xpmlbeg;
extern int ypmlbeg;
extern int zpmlbeg;
extern int xpmlend;
extern int ypmlend;
extern int zpmlend;
extern int halff;
extern int order;
extern float *c;
extern float *cx;
extern float *cy;
extern float *cz;
