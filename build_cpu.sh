#!/bin/bash
BASE=`pwd`
source source_intel

#if $1 is not set, set it to all
if [ -z "$1" ]; then
  set -- "all"
fi

if [ "$1" == "all" ] || [ "$1" == "ops" ]; then
cd $BASE/OPS/ops/c
make mpi -j8 -B
cd $BASE/OPS/apps/c/CloverLeaf
make cloverleaf_mpi cloverleaf_mpi_tiled -B &
cd $BASE/OPS/apps/c/CloverLeaf_3D
make cloverleaf_mpi cloverleaf_mpi_tiled -B &
cd $BASE/apps/rtm/
make rtm_mpi rtm_mpi_tiled -B &
cd $BASE/apps/TGV_StoreAll
make opensbli_mpi opensbli_mpi_tiled -B &
cd $BASE/apps/TGV_StoreAll_sp
make opensbli_mpi opensbli_mpi_tiled -B &
cd $BASE/apps/TGV_StoreNone
make opensbli_mpi opensbli_mpi_tiled -B &
cd $BASE/apps/TGV_StoreNone_sp
make opensbli_mpi opensbli_mpi_tiled -B &
cd $BASE/apps/ops_so08
make wave-propagation_mpi wave-propagation_mpi_tiled -B &
wait
fi
if [ "$1" == "all" ] || [ "$1" == "op2" ]; then
cd $BASE/OP2-Common/op2/
make config -B
make mpi -j8 -B
cd $BASE/apps/MG-CFD-app-OP2/
./translate2op2.sh
make mpi mpi_vec mpi_openmp -B
cd $BASE/apps/volna/sp
./translate2op2.sh
make volna_mpi_genseq volna_mpi_vec volna_mpi_openmp -B
mv volna_mpi_genseq volna_mpi
fi
if [ "$1" == "all" ] || [ "$1" == "other" ]; then
cd $BASE/apps/miniBUDE/openmp
make COMPILER=INTEL ARCH=avx512
mv bude bude_icx_omp
cd $BASE/apps/miniWeather/miniWeather-omp
make -B
mv main main_omp
fi
