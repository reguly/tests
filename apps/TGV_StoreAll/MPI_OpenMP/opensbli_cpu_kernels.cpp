//
// auto-generated by ops.py//

//header
#define OPS_3D
#define OPS_API 2
#include "ops_lib_core.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif

// global constants
extern int block0np0;
extern int block0np1;
extern int block0np2;
extern double Delta0block0;
extern double Delta1block0;
extern double Delta2block0;
extern int niter;
extern double dt;
extern double gama;
extern double Minf;
extern double Re;
extern double Pr;
extern double inv_0;
extern double inv_1;
extern double inv_2;
extern double inv_3;
extern double inv_4;
extern double inv_5;
extern double rc6;
extern double rc7;
extern double rc8;
extern double rcinv9;
extern double rc10;
extern double rc11;
extern double rcinv12;
extern double rcinv13;
extern double rcinv14;

void ops_init_backend() {}

//user kernel files
#include "opensbliblock00Kernel087_cpu_kernel.cpp"
#include "opensbliblock00Kernel081_cpu_kernel.cpp"
#include "opensbliblock00Kernel082_cpu_kernel.cpp"
#include "opensbliblock00Kernel083_cpu_kernel.cpp"
#include "opensbliblock00Kernel084_cpu_kernel.cpp"
#include "opensbliblock00Kernel085_cpu_kernel.cpp"
#include "opensbliblock00Kernel086_cpu_kernel.cpp"
#include "opensbliblock00Kernel088_cpu_kernel.cpp"
#include "opensbliblock00Kernel003_cpu_kernel.cpp"
#include "opensbliblock00Kernel024_cpu_kernel.cpp"
#include "opensbliblock00Kernel038_cpu_kernel.cpp"
#include "opensbliblock00Kernel009_cpu_kernel.cpp"
#include "opensbliblock00Kernel079_cpu_kernel.cpp"
#include "opensbliblock00Kernel000_cpu_kernel.cpp"
#include "opensbliblock00Kernel002_cpu_kernel.cpp"
#include "opensbliblock00Kernel004_cpu_kernel.cpp"
#include "opensbliblock00Kernel006_cpu_kernel.cpp"
#include "opensbliblock00Kernel008_cpu_kernel.cpp"
#include "opensbliblock00Kernel010_cpu_kernel.cpp"
#include "opensbliblock00Kernel011_cpu_kernel.cpp"
#include "opensbliblock00Kernel012_cpu_kernel.cpp"
#include "opensbliblock00Kernel014_cpu_kernel.cpp"
#include "opensbliblock00Kernel015_cpu_kernel.cpp"
#include "opensbliblock00Kernel016_cpu_kernel.cpp"
#include "opensbliblock00Kernel018_cpu_kernel.cpp"
#include "opensbliblock00Kernel019_cpu_kernel.cpp"
#include "opensbliblock00Kernel020_cpu_kernel.cpp"
#include "opensbliblock00Kernel021_cpu_kernel.cpp"
#include "opensbliblock00Kernel022_cpu_kernel.cpp"
#include "opensbliblock00Kernel023_cpu_kernel.cpp"
#include "opensbliblock00Kernel025_cpu_kernel.cpp"
#include "opensbliblock00Kernel026_cpu_kernel.cpp"
#include "opensbliblock00Kernel027_cpu_kernel.cpp"
#include "opensbliblock00Kernel028_cpu_kernel.cpp"
#include "opensbliblock00Kernel029_cpu_kernel.cpp"
#include "opensbliblock00Kernel030_cpu_kernel.cpp"
#include "opensbliblock00Kernel031_cpu_kernel.cpp"
#include "opensbliblock00Kernel032_cpu_kernel.cpp"
#include "opensbliblock00Kernel033_cpu_kernel.cpp"
#include "opensbliblock00Kernel034_cpu_kernel.cpp"
#include "opensbliblock00Kernel035_cpu_kernel.cpp"
#include "opensbliblock00Kernel036_cpu_kernel.cpp"
#include "opensbliblock00Kernel037_cpu_kernel.cpp"
#include "opensbliblock00Kernel039_cpu_kernel.cpp"
#include "opensbliblock00Kernel040_cpu_kernel.cpp"
#include "opensbliblock00Kernel041_cpu_kernel.cpp"
#include "opensbliblock00Kernel042_cpu_kernel.cpp"
#include "opensbliblock00Kernel043_cpu_kernel.cpp"
#include "opensbliblock00Kernel044_cpu_kernel.cpp"
#include "opensbliblock00Kernel045_cpu_kernel.cpp"
#include "opensbliblock00Kernel046_cpu_kernel.cpp"
#include "opensbliblock00Kernel047_cpu_kernel.cpp"
#include "opensbliblock00Kernel048_cpu_kernel.cpp"
#include "opensbliblock00Kernel049_cpu_kernel.cpp"
#include "opensbliblock00Kernel050_cpu_kernel.cpp"
#include "opensbliblock00Kernel051_cpu_kernel.cpp"
#include "opensbliblock00Kernel052_cpu_kernel.cpp"
#include "opensbliblock00Kernel053_cpu_kernel.cpp"
#include "opensbliblock00Kernel055_cpu_kernel.cpp"
#include "opensbliblock00Kernel056_cpu_kernel.cpp"
#include "opensbliblock00Kernel057_cpu_kernel.cpp"
#include "opensbliblock00Kernel058_cpu_kernel.cpp"
#include "opensbliblock00Kernel059_cpu_kernel.cpp"
#include "opensbliblock00Kernel060_cpu_kernel.cpp"
#include "opensbliblock00Kernel061_cpu_kernel.cpp"
#include "opensbliblock00Kernel062_cpu_kernel.cpp"
#include "opensbliblock00Kernel063_cpu_kernel.cpp"
#include "opensbliblock00Kernel065_cpu_kernel.cpp"
#include "opensbliblock00Kernel066_cpu_kernel.cpp"
#include "opensbliblock00Kernel067_cpu_kernel.cpp"
#include "opensbliblock00Kernel068_cpu_kernel.cpp"
#include "opensbliblock00Kernel070_cpu_kernel.cpp"
#include "opensbliblock00Kernel073_cpu_kernel.cpp"
#include "opensbliblock00Kernel074_cpu_kernel.cpp"
#include "opensbliblock00Kernel076_cpu_kernel.cpp"
#include "opensbliblock00Kernel077_cpu_kernel.cpp"
#include "opensbliblock00Kernel078_cpu_kernel.cpp"
#include "opensbliblock00Kernel054_cpu_kernel.cpp"
#include "opensbliblock00Kernel064_cpu_kernel.cpp"
#include "opensbliblock00Kernel069_cpu_kernel.cpp"
#include "opensbliblock00Kernel071_cpu_kernel.cpp"
#include "opensbliblock00Kernel072_cpu_kernel.cpp"
#include "opensbliblock00Kernel075_cpu_kernel.cpp"
#include "opensbliblock00Kernel080_cpu_kernel.cpp"
#include "opensbliblock00Kernel090_cpu_kernel.cpp"
#include "opensbliblock00Kernel089_cpu_kernel.cpp"
