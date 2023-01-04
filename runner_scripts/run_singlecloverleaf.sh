#!/bin/bash
set -x
OPS_FLAT=1 make cloverleaf_mpi_sycl -B
mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_flat
OPS_CPU=1 make cloverleaf_mpi_sycl -B
mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_ndrange
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	OMP_NUM_THREADS=1 mpirun -np 224 -bind-to hwthread ./cloverleaf_mpi -OPS_DIAGS=1>> c3d324_mpi_diag1
	OMP_NUM_THREADS=28 mpirun -np 8 -bind-to numa ./cloverleaf_mpi_openmp -OPS_DIAGS=1 >> c3d324_mpi8omp24_diag1
#	mpirun -np 8 -bind-to numa ./cloverleaf_mpi_sycl_flat -OPS_DIAGS=1 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> c3d324_mpisycl_flat_diag1
#	mpirun -np 8 -bind-to numa ./cloverleaf_mpi_sycl_ndrange -OPS_DIAGS=1 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> c3d324_mpisycl_ndrange_diag1
done
