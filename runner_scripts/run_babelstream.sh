#!/bin/bash
set -x
array=( 800000 1600000 3200000 6400000 12800000 25600000 52100000 102400000 204800000 409600000 )
for i in "${array[@]}"
do
OMP_NUM_THREADS=224 OMP_PROC_BIND=close  ./sycl2020-stream -n 100 -s $i --device 2
done
