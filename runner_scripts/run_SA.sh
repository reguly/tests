#!/bin/bash
set -x
if [ -n "$GPU" ]; then
        BS_X=128
        BS_Z=1
        BS_Y=8
fi
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	if [ -n "$CPUTEST" ]; then
	OMP_NUM_THREADS=1 mpirun -np $physical_cores -bind-to core ./opensbli_mpi 320 320 320 -OPS_DIAGS=2>> sa_mpi"$physical_cores"_icc_diag2
  if [ "$logical_cores" -ne "$physical_cores" ]; then
	OMP_NUM_THREADS=1 mpirun -np $logical_cores -bind-to hwthread ./opensbli_mpi 320 320 320 -OPS_DIAGS=2>> sa_mpi"$logical_cores"_icc_diag2
	OMP_PROC_BIND=spread OMP_NUM_THREADS=$physical_cores_per_numa mpirun -np $numa_domains $bind_numa ./opensbli_mpi 320 320 320 -OPS_DIAGS=2 >> sa_mpi"$numa_domains"omp"$physical_cores_per_numa"_icc_diag2
  fi
	OMP_PROC_BIND=TRUE OMP_NUM_THREADS=$threads_per_numa mpirun -np $numa_domains $bind_numa ./opensbli_mpi 320 320 320 -OPS_DIAGS=2 >> sa_mpi"$numa_domains"omp"$threads_per_numa"_icc_diag2
	fi
	if [ -n "$SYCL" ]; then
	mpirun -np $numa_domains $bind_numa ./opensbli_mpi_sycl_flat 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect >> sa_mpisycl_flat_diag2
	mpirun -np $numa_domains $bind_numa ./opensbli_mpi_sycl_ndrange 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_Z=$BS_Z OPS_BLOCK_SIZE_Y=$BS_Y OPS_BLOCK_SIZE_X=$BS_X >> sa_mpisycl_ndrange_diag2
	fi
	if [ -n "$ACCEL" ]; then
	./opensbli_"$ACCEL" 320 320 320 -OPS_DIAGS=2 $ACCEL_FLAGS OPS_BLOCK_SIZE_Z=$BS_Z OPS_BLOCK_SIZE_Y=$BS_Y OPS_BLOCK_SIZE_X=$BS_X >> sa_"$ACCEL"_diag2
	fi
done
