#!/bin/bash
set -x
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
  cd miniWeather-omp
	OMP_PROC_BIND=TRUE OMP_NUM_THREADS=$threads_per_numa mpirun -np $numa_domains $bind_numa ./main_omp >> miniweather_mpi"$numa_domains"omp"$threads_per_numa"_diag2 2>&1
	OMP_PROC_BIND=spread OMP_NUM_THREADS=$physical_cores_per_numa mpirun -np $numa_domains $bind_numa ./main_omp >> miniweather_mpi"$numa_domains"omp"$physical_cores_per_numa"_diag2 2>&1
  cd ..
  cd miniWeather-sycl
	mpirun -np $numa_domains $bind_numa ./main_sycl_flat >> miniweather_mpisycl_flat_diag2 2>&1
	mpirun -np $numa_domains $bind_numa ./main_sycl_ndrange 4096 2 >> miniweather_mpisycl_ndrange_diag2 2>&1
  cd ..
done