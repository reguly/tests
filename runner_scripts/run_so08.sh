#!/bin/bash
set -x
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	if [ -n "$CPUTEST" ]; then
	OMP_NUM_THREADS=1 mpirun -np $logical_cores -bind-to hwthread ./wave-propagation_mpi 1000 1000 1000 -OPS_DIAGS=2>> so08_mpi"$logical_cores"_diag2
  if [ "$logical_cores" -ne "$physical_cores" ]; then
	OMP_NUM_THREADS=1 mpirun -np $physical_cores -bind-to core ./wave-propagation_mpi 1000 1000 1000 -OPS_DIAGS=2>> so08_mpi"$physical_cores"_diag2
	OMP_PROC_BIND=TRUE OMP_NUM_THREADS=$threads_per_numa mpirun -np $numa_domains $bind_numa ./wave-propagation_mpi 1000 1000 1000 -OPS_DIAGS=2 >> so08_mpi"$numa_domains"omp"$threads_per_numa"_diag2
  fi
	OMP_PROC_BIND=spread OMP_NUM_THREADS=$physical_cores_per_numa mpirun -np $numa_domains $bind_numa ./wave-propagation_mpi 1000 1000 1000 -OPS_DIAGS=2 >> so08_mpi"$numa_domains"omp"$physical_cores_per_numa"_diag2
	fi
	if [ -n "$SYCL" ]; then
	mpirun -np $numa_domains $bind_numa ./wave-propagation_mpi_sycl_flat 1000 1000 1000 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> so08_mpisycl_flat_diag2
	mpirun -np $numa_domains $bind_numa ./wave-propagation_mpi_sycl_ndrange 1000 1000 1000 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> so08_mpisycl_ndrange_diag2
	fi
done
