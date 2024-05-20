#!/bin/bash
set -x
export OMP_PROC_BIND=TRUE
# export DPCPP_CPU_CU_AFFINITY=spread
# export DPCPP_CPU_NUM_CUS=$physical_cores
for j in {1..4}
do
  if [ -n "$CPUTEST" ]; then
  cd openmp
  OMP_PROC_BIND=TRUE ./bude_icx_omp -i 30 >> bude_icx_omp"$logical_cores"_diag2
  if [ "$logical_cores" -ne "$physical_cores" ]; then
	  OMP_NUM_THREADS=$physical_cores OMP_PROC_BIND=close ./bude_icx_omp -i 30 >> bude_icx_omp"$physical_cores"_diag2
  fi
  cd ..
  fi
  #if environment variable SYCL exists
  if [ -n "$SYCL" ]; then
    cd sycl
    ./bude_sycl -d $SYCL_DEVICE -i 30 -w 0 >> bude_sycl_flat_diag2
    ./bude_sycl -d $SYCL_DEVICE -i 30 -w 256 >> bude_sycl_ndrage_diag2
    cd ..
  fi
  if [ -n "$ACCEL" ]; then
	  cd $ACCEL
	  #./bude_"${ACCEL}" -i 30 -w 256 $ACCEL_FLAGS >> bude_"${ACCEL}"_diag2
	  ./bude_"${ACCEL}" -i 30 $ACCEL_FLAGS >> bude_"${ACCEL}"_diag2
	  cd ..
  fi
done
