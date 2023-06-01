#!/bin/bash
BASE=`pwd`
source source_sycl
cd $BASE/OPS/ops/c
make mpi_sycl sycl -j8
cd $BASE/OP2-Common-sycl/op2/c
make core seq sycl mpi_sycl #hdf5
cd $BASE/OPS/apps/c/CloverLeaf
OPS_FLAT=1 make cloverleaf_sycl -B
mv cloverleaf_sycl cloverleaf_sycl_flat
OPS_CPU=1 make cloverleaf_sycl -B
mv cloverleaf_sycl cloverleaf_sycl_ndrange
cd $BASE/OPS/apps/c/CloverLeaf_3D
OPS_FLAT=1 make cloverleaf_sycl -B
mv cloverleaf_sycl cloverleaf_sycl_flat
OPS_CPU=1 make cloverleaf_sycl -B
mv cloverleaf_sycl cloverleaf_sycl_ndrange
cd $BASE/apps/rtm/
OPS_FLAT=1 make rtm_sycl -B
mv rtm_sycl rtm_sycl_flat
OPS_CPU=1 make rtm_sycl -B
mv rtm_sycl rtm_sycl_ndrange
cd $BASE/apps/TGV_StoreAll
OPS_FLAT=1 make opensbli_sycl -B
mv opensbli_sycl opensbli_sycl_flat
OPS_CPU=1 make opensbli_sycl -B
mv opensbli_sycl opensbli_sycl_ndrange
cd $BASE/apps/TGV_StoreNone
OPS_FLAT=1 make opensbli_sycl -B
mv opensbli_sycl opensbli_sycl_flat
OPS_CPU=1 make opensbli_sycl -B
mv opensbli_sycl opensbli_sycl_ndrange
cd $BASE/apps/MG-CFD-app-OP2/
export OP2_OLD=1
./translate2op2.sh
make sycl
mv bin/mgcfd_sycl bin/mgcfd_sycl_hier_aos
OP_AUTO_SOA=1 ./translate2op2.sh
make sycl
mv bin/mgcfd_sycl bin/mgcfd_sycl_hier_soa

OP2_COLOR2=1 ./translate2op2.sh
make sycl
mv bin/mgcfd_sycl bin/mgcfd_sycl_global_aos

OP2_COLOR2=1 OP_AUTO_SOA=1 ./translate2op2.sh
make sycl
mv bin/mgcfd_sycl bin/mgcfd_sycl_global_soa

OP2_SCALAR=1 ./translate2op2.sh
make sycl
mv bin/mgcfd_sycl bin/mgcfd_sycl_hier_scalar_aos

OP2_SCALAR=1 OP_AUTO_SOA=1 ./translate2op2.sh
make sycl
mv bin/mgcfd_sycl bin/mgcfd_sycl_hier_scalar_soa

OP2_SCALAR=1 OP2_BLOCKLOOP=1 ./translate2op2.sh
make sycl
mv bin/mgcfd_sycl bin/mgcfd_sycl_hier_scalar_blockloop_aos

OP2_SCALAR=1 OP2_BLOCKLOOP=1 OP_AUTO_SOA=1 ./translate2op2.sh
make sycl
mv bin/mgcfd_sycl bin/mgcfd_sycl_hier_scalar_blockloop_soa

OP2_ATOMICS=1 ./translate2op2.sh
make sycl
mv bin/mgcfd_sycl bin/mgcfd_sycl_atomics_aos

OP2_ATOMICS=1 OP_AUTO_SOA=1 ./translate2op2.sh
make sycl
mv bin/mgcfd_sycl bin/mgcfd_sycl_atomics_soa

cd $BASE/apps/volna/sp
./translate2op2.sh
make volna_sycl
mv volna_sycl volna_sycl_hier_aos

OP_AUTO_SOA=1 ./translate2op2.sh
make volna_sycl
mv volna_sycl volna_sycl_hier_soa

OP2_COLOR2=1 ./translate2op2.sh
make volna_sycl
mv volna_sycl volna_sycl_global_aos

OP2_COLOR2=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_sycl
mv volna_sycl volna_sycl_global_soa

OP2_SCALAR=1 ./translate2op2.sh
make volna_sycl
mv volna_sycl volna_sycl_hier_scalar_aos

OP2_SCALAR=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_sycl
mv volna_sycl volna_sycl_hier_scalar_soa

OP2_SCALAR=1 OP2_BLOCKLOOP=1 ./translate2op2.sh
make volna_sycl
mv volna_sycl volna_sycl_hier_scalar_blockloop_aos

OP2_SCALAR=1 OP2_BLOCKLOOP=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_sycl
mv volna_sycl volna_sycl_hier_scalar_blockloop_soa

OP2_ATOMICS=1 ./translate2op2.sh
make volna_sycl
mv volna_sycl volna_sycl_atomics_aos

OP2_ATOMICS=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_sycl
mv volna_sycl volna_sycl_atomics_soa
