#!/bin/bash
set -x
array=( 800000 1600000 3200000 6400000 12800000 25600000 52100000 102400000 )
for i in "${array[@]}"
do
	OMP_PROC_BIND=TRUE KMP_AFFINITY=compact numactl --cpunodebind=0 ./omp-stream -n 100 -s $i
done
for i in "${array[@]}"
do
	OMP_PROC_BIND=TRUE KMP_AFFINITY=compact numactl --cpunodebind=0-3 ./omp-stream -n 100 -s $i
done
for i in "${array[@]}"
do
	OMP_PROC_BIND=TRUE KMP_AFFINITY=compact ./omp-stream -n 100 -s $i
done
