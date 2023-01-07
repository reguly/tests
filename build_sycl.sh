#!/bin/bash
BASE=`pwd`
source source_sycl
cd $BASE/OPS/ops/c
make mpi_sycl -j8
cd $BASE/OP2-Common-sycl/op2/c
#make core seq hdf5 mpi_sycl
cd $BASE/OPS/apps/c/CloverLeaf
OPS_FLAT=1 make cloverleaf_mpi_sycl -B
mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_flat
OPS_CPU=1 make cloverleaf_mpi_sycl -B
mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_ndrange
cd $BASE/OPS/apps/c/CloverLeaf_3D
OPS_FLAT=1 make cloverleaf_mpi_sycl -B
mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_flat
OPS_CPU=1 make cloverleaf_mpi_sycl -B
mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_ndrange
cd $BASE/apps/rtm/
OPS_FLAT=1 make rtm_mpi_sycl -B
mv rtm_mpi_sycl rtm_mpi_sycl_flat
OPS_CPU=1 make rtm_mpi_sycl -B
mv rtm_mpi_sycl rtm_mpi_sycl_ndrange
cd $BASE/apps/TGV_StoreAll
OPS_FLAT=1 make opensbli_mpi_sycl -B
mv opensbli_mpi_sycl opensbli_mpi_sycl_flat
OPS_CPU=1 make opensbli_mpi_sycl -B
mv opensbli_mpi_sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/TGV_StoreNone
OPS_FLAT=1 make opensbli_mpi_sycl -B
mv opensbli_mpi_sycl opensbli_mpi_sycl_flat
OPS_CPU=1 make opensbli_mpi_sycl -B
mv opensbli_mpi_sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/MG-CFD-app-OP2/
export OP2_OLD=1
./translate2op2.sh
make mpi_sycl
mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_aos
OP_AUTO_SOA=1 ./translate2op2.sh
make mpi_sycl
mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_soa

OP2_COLOR2=1 ./translate2op2.sh
make mpi_sycl
mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_global_aos

OP2_COLOR2=1 OP_AUTO_SOA=1 ./translate2op2.sh
make mpi_sycl
mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_global_soa

OP2_SCALAR=1 ./translate2op2.sh
make mpi_sycl
mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_scalar_aos

OP2_SCALAR=1 OP_AUTO_SOA=1 ./translate2op2.sh
make mpi_sycl
mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_scalar_soa

OP2_SCALAR=1 OP2_BLOCKLOOP=1 ./translate2op2.sh
make mpi_sycl
mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_scalar_blockloop_aos

OP2_SCALAR=1 OP2_BLOCKLOOP=1 OP_AUTO_SOA=1 ./translate2op2.sh
make mpi_sycl
mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_scalar_blockloop_soa
cd $BASE/apps/volna/sp
./translate2op2.sh
make volna_mpi_sycl
mv volna_mpi_sycl volna_mpi_sycl_hier_aos

OP_AUTO_SOA=1 ./translate2op2.sh
make volna_mpi_sycl
mv volna_mpi_sycl volna_mpi_sycl_hier_soa

OP2_COLOR2=1 ./translate2op2.sh
make volna_mpi_sycl
mv volna_mpi_sycl volna_mpi_sycl_global_aos

OP2_COLOR2=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_mpi_sycl
mv volna_mpi_sycl volna_mpi_sycl_global_soa

OP2_SCALAR=1 ./translate2op2.sh
make volna_mpi_sycl
mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_aos

OP2_SCALAR=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_mpi_sycl
mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_soa

OP2_SCALAR=1 OP2_BLOCKLOOP=1 ./translate2op2.sh
make volna_mpi_sycl
mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_blockloop_aos

OP2_SCALAR=1 OP2_BLOCKLOOP=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_mpi_sycl
mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_blockloop_soa
