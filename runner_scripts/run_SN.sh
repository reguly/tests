#!/bin/bash
set -x
#OPS_FLAT=1 make opensbli_mpi_sycl -B
#mv opensbli_mpi_sycl opensbli_mpi_sycl_flat
#OPS_CPU=1 make opensbli_mpi_sycl -B
#mv opensbli_mpi_sycl opensbli_mpi_sycl_ndrange
#export OMP_PROC_BIND=TRUE
for j in {1..4}
do
#	OMP_NUM_THREADS=1 mpirun -np 72 -bind-to core ./opensbli_mpi 320 320 320 -OPS_DIAGS=2>> sn_mpi72_icc_diag2
#	OMP_NUM_THREADS=1 mpirun -np 144 -bind-to hwthread ./opensbli_mpi 320 320 320 -OPS_DIAGS=2>> sn_mpi144_icc_diag2
	OMP_PROC_BIND=spread OMP_NUM_THREADS=36 mpirun -np 2 -bind-to numa ./opensbli_mpi 320 320 320 -OPS_DIAGS=2 >> sn_mpi2omp36_icc_diag2
	OMP_PROC_BIND=TRUE OMP_NUM_THREADS=72 mpirun -np 2 -bind-to numa ./opensbli_mpi 320 320 320 -OPS_DIAGS=2 >> sn_mpi2omp72_icc_diag2
	mpirun -np 2 -bind-to numa ./opensbli_mpi_sycl_flat 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> sn_mpisycl_flat_diag2
	mpirun -np 2 -bind-to numa ./opensbli_mpi_sycl_ndrange 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> sn_mpisycl_ndrange_diag2
done
