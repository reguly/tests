#!/bin/bash
set -x
OPS_FLAT=1 make rtm_mpi_sycl -B
mv rtm_mpi_sycl rtm_mpi_sycl_flat
OPS_CPU=1 make rtm_mpi_sycl -B
mv rtm_mpi_sycl rtm_mpi_sycl_ndrange
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
#	OMP_NUM_THREADS=1 mpirun -np 224 -bind-to hwthread ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2>> rtm_soa_mpi224_diag2
#	OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2>> rtm_soa_mpi112_diag2
#	OMP_NUM_THREADS=28 mpirun -np 8 -bind-to numa ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 >> rtm_soa_mpi8omp28_diag2
#	OMP_NUM_THREADS=14 mpirun -np 8 -bind-to numa ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 >> rtm_soa_mpi8omp14_diag2
	mpirun -np 8 -bind-to numa ./rtm_mpi_sycl_flat -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> rtm_soa_mpisycl_flat_diag2
	mpirun -np 8 -bind-to numa ./rtm_mpi_sycl_ndrange -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> rtm_soa_mpisycl_ndrange_diag2
done
