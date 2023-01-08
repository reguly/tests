#!/bin/bash
BASE=`pwd`
source source_intel
cd $BASE/OPS/ops/c
make mpi -j8
cd $BASE/OP2-Common/op2/
#make config
make mpi -j8
cd $BASE/OPS/apps/c/CloverLeaf
make cloverleaf_mpi cloverleaf_mpi_tiled &
cd $BASE/OPS/apps/c/CloverLeaf_3D
make cloverleaf_mpi cloverleaf_mpi_tiled &
cd $BASE/apps/rtm/
make rtm_mpi rtm_mpi_tiled &
cd $BASE/apps/TGV_StoreAll
make opensbli_mpi opensbli_mpi_tiled &
cd $BASE/apps/TGV_StoreNone
make opensbli_mpi opensbli_mpi_tiled &
wait
cd $BASE/apps/MG-CFD-app-OP2/
./translate2op2.sh
make mpi mpi_vec
cd $BASE/apps/volna/sp
./translate2op2.sh
make volna_mpi_genseq volna_mpi_vec
mv volna_mpi_genseq volna_mpi 
