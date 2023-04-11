#!/bin/bash
set -x
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	OMP_NUM_THREADS=1 mpirun -np $logical_cores -bind-to hwthread ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2>> rtm_soa_mpi"$logical_cores"_diag2
	OMP_NUM_THREADS=1 mpirun -np $physical_cores -bind-to core ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2>> rtm_soa_mpi"$physical_cores"_diag2
	OMP_PROC_BIND=TRUE OMP_NUM_THREADS=$threads_per_numa mpirun -np $numa_domains $bind_numa ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 >> rtm_soa_mpi"$numa_domains"omp"$threads_per_numa"_diag2
	OMP_PROC_BIND=spread OMP_NUM_THREADS=$physical_cores_per_numa mpirun -np $numa_domains $bind_numa ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 >> rtm_soa_mpi"$numa_domains"omp"$physical_cores_per_numa"_diag2
	mpirun -np $numa_domains $bind_numa ./rtm_mpi_sycl_flat -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> rtm_soa_mpisycl_flat_diag2
	mpirun -np $numa_domains $bind_numa ./rtm_mpi_sycl_ndrange -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> rtm_soa_mpisycl_ndrange_diag2
done
