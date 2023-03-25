#!/bin/bash
BASE=`pwd`
source source_sycl
cd $BASE/OPS/ops/c
make mpi_sycl sycl -j8
cd $BASE/apps/TGV_StoreNone
OPS_FLAT=1 make opensbli_mpi_sycl -B
mv opensbli_mpi_sycl opensbli_mpi_sycl_flat
OPS_CPU=0 make opensbli_mpi_sycl -B
mv opensbli_mpi_sycl opensbli_mpi_sycl_ndrange
