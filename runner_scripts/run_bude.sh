#!/bin/bash
set -x
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
  cd openmp
	OMP_PROC_BIND=TRUE ./bude_icx_omp -i 30 >> bude_icx_omp
  cd ..
  cd sycl
	./bude_sycl -d 1 -i 30 -w 0 >> bude_sycl_flat
	./bude_sycl -d 1 -i 30 -w 256 >> bude_sycl_ndrage
  cd ..
done
