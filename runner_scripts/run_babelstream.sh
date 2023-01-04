#!/bin/bash
set -x
array=( 800000 1600000 3200000 6400000 12800000 25600000 52100000 102400000 204800000 409600000 )
for i in "${array[@]}"
do
	OMP_NUM_THREADS=28 OMP_PROC_BIND=close numactl --cpunodebind=0 ./omp-stream -n 100 -s $i
done
for i in "${array[@]}"
do
	OMP_NUM_THREADS=112 OMP_PROC_BIND=close  numactl --cpunodebind=0-3 ./omp-stream -n 100 -s $i
done
for i in "${array[@]}"
do
	OMP_NUM_THREADS=224 OMP_PROC_BIND=close  ./omp-stream -n 100 -s $i
done
