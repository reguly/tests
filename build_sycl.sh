#!/bin/bash
BASE=`pwd`
source source_sycl
#mpi=
mpi=mpi_
export OPS_CPU=1 

#if $1 is not set, set it to all
if [ -z "$1" ]; then
  set -- "all"
fi

if [ "$1" == "all" ] || [ "$1" == "ops" ]; then
cd $BASE/OPS/ops/c
make mpi_sycl sycl hdf5_mpi -j8
cd $BASE/OPS/apps/c/CloverLeaf
OPS_FLAT=1 make cloverleaf_"$mpi"sycl -B &
cd $BASE/OPS/apps/c/CloverLeaf_3D
OPS_FLAT=1 make cloverleaf_"$mpi"sycl -B &
cd $BASE/apps/rtm/
OPS_FLAT=1 make rtm_"$mpi"sycl -B &
cd $BASE/apps/TGV_StoreAll
OPS_FLAT=1 make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_StoreNone
OPS_FLAT=1 make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_StoreAll_sp
OPS_FLAT=1 make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_StoreNone_sp
OPS_FLAT=1 make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_mixed/TGsym_DP
OPS_FLAT=1 make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_mixed/TGsym_SP
OPS_FLAT=1 make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_mixed/TGsym_HP
OPS_FLAT=1 make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_mixed/TGsym_SPDP
OPS_FLAT=1 make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_mixed/TGsym_HPSP
OPS_FLAT=1 make opensbli_"$mpi"sycl -B &
cd $BASE/apps/ops_so08
OPS_FLAT=1 make wave-propagation_"$mpi"sycl -B &
wait

cd $BASE/OPS/apps/c/CloverLeaf
mv cloverleaf_"$mpi"sycl cloverleaf_mpi_sycl_flat
cd $BASE/OPS/apps/c/CloverLeaf_3D
mv cloverleaf_"$mpi"sycl cloverleaf_mpi_sycl_flat
cd $BASE/apps/rtm/
mv rtm_"$mpi"sycl rtm_mpi_sycl_flat
cd $BASE/apps/TGV_StoreAll
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_flat
cd $BASE/apps/TGV_StoreNone
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_flat
cd $BASE/apps/TGV_StoreAll_sp
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_flat
cd $BASE/apps/TGV_StoreNone_sp
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_flat
cd $BASE/apps/TGV_mixed/TGsym_DP
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_flat
cd $BASE/apps/TGV_mixed/TGsym_SP
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_flat
cd $BASE/apps/TGV_mixed/TGsym_HP
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_flat
cd $BASE/apps/TGV_mixed/TGsym_SPDP
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_flat
cd $BASE/apps/TGV_mixed/TGsym_HPSP
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_flat
cd $BASE/apps/ops_so08
mv wave-propagation_"$mpi"sycl wave-propagation_mpi_sycl_flat

#OPS_CPU set above
cd $BASE/OPS/apps/c/CloverLeaf
make cloverleaf_"$mpi"sycl -B &
cd $BASE/OPS/apps/c/CloverLeaf_3D
make cloverleaf_"$mpi"sycl -B &
cd $BASE/apps/rtm/
make rtm_"$mpi"sycl -B &
cd $BASE/apps/TGV_StoreAll
make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_StoreNone
make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_StoreAll_sp
make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_StoreNone_sp
make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_mixed/TGsym_DP
make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_mixed/TGsym_SP
make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_mixed/TGsym_HP
make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_mixed/TGsym_SPDP
make opensbli_"$mpi"sycl -B &
cd $BASE/apps/TGV_mixed/TGsym_HPSP
make opensbli_"$mpi"sycl -B &
cd $BASE/apps/ops_so08
make wave-propagation_"$mpi"sycl -B &
wait

cd $BASE/OPS/apps/c/CloverLeaf
mv cloverleaf_"$mpi"sycl cloverleaf_mpi_sycl_ndrange
cd $BASE/OPS/apps/c/CloverLeaf_3D
mv cloverleaf_"$mpi"sycl cloverleaf_mpi_sycl_ndrange
cd $BASE/apps/rtm/
mv rtm_"$mpi"sycl rtm_mpi_sycl_ndrange
cd $BASE/apps/TGV_StoreAll
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/TGV_StoreNone
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/TGV_StoreAll_sp
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/TGV_StoreNone_sp
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/TGV_mixed/TGsym_DP
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/TGV_mixed/TGsym_SP
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/TGV_mixed/TGsym_HP
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/TGV_mixed/TGsym_SPDP
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/TGV_mixed/TGsym_HPSP
mv opensbli_"$mpi"sycl opensbli_mpi_sycl_ndrange
cd $BASE/apps/ops_so08
mv wave-propagation_"$mpi"sycl wave-propagation_mpi_sycl_ndrange

fi

if [ "$1" == "all" ] || [ "$1" == "op2" ] || [ "$1" == "mgcfd" ]; then
export OP2_INSTALL_PATH=$BASE/OP2-Common-sycl/op2
cd $BASE/OP2-Common-sycl/op2/c
make core seq sycl mpi_sycl hdf5
cd $BASE/apps/MG-CFD-app-OP2/
export OP2_OLD=1
./translate2op2.sh
make "$mpi"sycl
mv bin/mgcfd_"$mpi"sycl bin/mgcfd_mpi_sycl_hier_aos
OP_AUTO_SOA=1 ./translate2op2.sh
make "$mpi"sycl
mv bin/mgcfd_"$mpi"sycl bin/mgcfd_mpi_sycl_hier_soa

OP2_COLOR2=1 ./translate2op2.sh
make "$mpi"sycl
mv bin/mgcfd_"$mpi"sycl bin/mgcfd_mpi_sycl_global_aos

OP2_COLOR2=1 OP_AUTO_SOA=1 ./translate2op2.sh
make "$mpi"sycl
mv bin/mgcfd_"$mpi"sycl bin/mgcfd_mpi_sycl_global_soa

OP2_SCALAR=1 ./translate2op2.sh
make "$mpi"sycl
mv bin/mgcfd_"$mpi"sycl bin/mgcfd_mpi_sycl_hier_scalar_aos

OP2_SCALAR=1 OP_AUTO_SOA=1 ./translate2op2.sh
make "$mpi"sycl
mv bin/mgcfd_"$mpi"sycl bin/mgcfd_mpi_sycl_hier_scalar_soa

OP2_SCALAR=1 OP2_BLOCKLOOP=1 ./translate2op2.sh
make "$mpi"sycl
mv bin/mgcfd_"$mpi"sycl bin/mgcfd_mpi_sycl_hier_scalar_blockloop_aos

OP2_SCALAR=1 OP2_BLOCKLOOP=1 OP_AUTO_SOA=1 ./translate2op2.sh
make "$mpi"sycl
mv bin/mgcfd_"$mpi"sycl bin/mgcfd_mpi_sycl_hier_scalar_blockloop_soa

OP2_ATOMICS=1 OP_AUTO_SOA=1 ./translate2op2.sh
make "$mpi"sycl
mv bin/mgcfd_"$mpi"sycl bin/mgcfd_mpi_sycl_atomics_soa

OP2_ATOMICS=1 ./translate2op2.sh
make "$mpi"sycl
mv bin/mgcfd_"$mpi"sycl bin/mgcfd_mpi_sycl_atomics_aos
fi
if [ "$1" == "all" ] || [ "$1" == "op2" ] || [ "$1" == "volna" ]; then
export OP2_OLD=1
cd $BASE/apps/volna/sp
./translate2op2.sh
make volna_"$mpi"sycl
mv volna_"$mpi"sycl volna_mpi_sycl_hier_aos

OP_AUTO_SOA=1 ./translate2op2.sh
make volna_"$mpi"sycl
mv volna_"$mpi"sycl volna_mpi_sycl_hier_soa

OP2_COLOR2=1 ./translate2op2.sh
make volna_"$mpi"sycl
mv volna_"$mpi"sycl volna_mpi_sycl_global_aos

OP2_COLOR2=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_"$mpi"sycl
mv volna_"$mpi"sycl volna_mpi_sycl_global_soa

OP2_SCALAR=1 ./translate2op2.sh
make volna_"$mpi"sycl
mv volna_"$mpi"sycl volna_mpi_sycl_hier_scalar_aos

OP2_SCALAR=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_"$mpi"sycl
mv volna_"$mpi"sycl volna_mpi_sycl_hier_scalar_soa

OP2_SCALAR=1 OP2_BLOCKLOOP=1 ./translate2op2.sh
make volna_"$mpi"sycl
mv volna_"$mpi"sycl volna_mpi_sycl_hier_scalar_blockloop_aos

OP2_SCALAR=1 OP2_BLOCKLOOP=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_"$mpi"sycl
mv volna_"$mpi"sycl volna_mpi_sycl_hier_scalar_blockloop_soa

OP2_ATOMICS=1 ./translate2op2.sh
make volna_"$mpi"sycl
mv volna_"$mpi"sycl volna_mpi_sycl_atomics_aos

OP2_ATOMICS=1 OP_AUTO_SOA=1 ./translate2op2.sh
make volna_"$mpi"sycl
mv volna_"$mpi"sycl volna_mpi_sycl_atomics_soa
fi

if [ "$1" == "all" ] || [ "$1" == "other" ]; then
cd $BASE/apps/miniBUDE/sycl
if [ "$OPS_COMPILER" == "hipsycl" ]; then
  mkdir build; cd build; CC=clang CXX=syclcc cmake .. -DSYCL_RUNTIME=HIPSYCL -DHIPSYCL_INSTALL_DIR=$(dirname $(dirname `which syclcc`))  -DCMAKE_BUILD_TYPE=Release; make -j; cd ..
else
  mkdir build; cd build; CC=icx CXX=icpx cmake .. -DSYCL_RUNTIME=DPCPP -DCMAKE_BUILD_TYPE=Release; make -j; cd ..
fi
mv build/bude bude_sycl

cd $BASE/apps/miniWeather/miniWeather-sycl
make -B -f Makefile-dpcpp
mv main main_sycl_flat
make -B -f Makefile-dpcpp NDRANGE=1
mv main main_sycl_ndrange
fi
