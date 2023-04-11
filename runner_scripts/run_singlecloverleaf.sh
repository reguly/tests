#!/bin/bash
set -x
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	OMP_NUM_THREADS=1 mpirun -np $logical_cores -bind-to hwthread ./cloverleaf_mpi -OPS_DIAGS=1>> c3d324_mpi_diag1
	OMP_NUM_THREADS=$threads_per_numa mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_openmp -OPS_DIAGS=1 >> c3d324_mpi"$numa_domains"omp"$threads_per_numa"_diag1
	mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_sycl_flat -OPS_DIAGS=1 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> c3d324_mpisycl_flat_diag1
	mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_sycl_ndrange -OPS_DIAGS=1 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> c3d324_mpisycl_ndrange_diag1
done
