#!/bin/bash
set -x
#OPS_FLAT=1 make opensbli_mpi_sycl -B
#mv opensbli_mpi_sycl opensbli_mpi_sycl_flat
#OPS_CPU=1 make opensbli_mpi_sycl -B
#mv opensbli_mpi_sycl opensbli_mpi_sycl_ndrange
#export OMP_PROC_BIND=TRUE
for j in {1..4}
do
#	OMP_NUM_THREADS=1 mpirun -np $physical_cores $bind_core ./opensbli_mpi 320 320 320 -OPS_DIAGS=2>> sa_mpi"$physical_cores"_icc_diag2
#	OMP_NUM_THREADS=1 mpirun -np $logical_cores $bind_hwthread ./opensbli_mpi 320 320 320 -OPS_DIAGS=2>> sa_mpi"$logical_cores"_icc_diag2
#	OMP_PROC_BIND=spread OMP_NUM_THREADS=$physical_cores_per_numa mpirun -np $numa_domains $bind_numa ./opensbli_mpi 320 320 320 -OPS_DIAGS=2 >> sa_mpi"$numa_domains"omp"$physical_cores_per_numa"_icc_diag2
#	OMP_PROC_BIND=TRUE OMP_NUM_THREADS=$threads_per_numa mpirun -np $numa_domains $bind_numa ./opensbli_mpi 320 320 320 -OPS_DIAGS=2 >> sa_mpi"$numa_domains"omp"$threads_per_numa"_icc_diag2
	./opensbli_mpi_sycl_flat 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=0 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> sa_sycl_flat_diag2
#	./opensbli_mpi_sycl_ndrange 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=0 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> sa_sycl_ndrange_diag2
done
