#!/bin/bash
set -x
sed -i "s/end_step=.*/end_step=50/g" clover.in
##OPS_FLAT=1 make cloverleaf_mpi_sycl -B
#mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_flat
#OPS_CPU=1 make cloverleaf_mpi_sycl -B
#mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_ndrange
array=( 408 )
for i in "${array[@]}"
do
	sed -i "s/x_cells=.*/x_cells=$i/g" clover.in
	sed -i "s/y_cells=.*/y_cells=$i/g" clover.in
	sed -i "s/z_cells=.*/z_cells=$i/g" clover.in
	for j in {1..4}
	do
		OMP_NUM_THREADS=1 mpirun  -np $physical_cores -bind-to core ./cloverleaf_mpi -OPS_DIAGS=2 >> c3d_mpi"$physical_cores"_icx_diag2
		OMP_NUM_THREADS=1 mpirun  -np $logical_cores -bind-to hwthread ./cloverleaf_mpi -OPS_DIAGS=2 >> c3d_mpi"$logical_cores"_icx_diag2
		OMP_NUM_THREADS=$threads_per_numa OMP_PROC_BIND=TRUE mpirun -np $numa_domains  $bind_numa ./cloverleaf_mpi -OPS_DIAGS=2 >> c3d_mpi"$numa_domains"omp"$threads_per_numa"_icx_diag2
		OMP_NUM_THREADS=$physical_cores_per_numa OMP_PROC_BIND=spread mpirun -np $numa_domains  $bind_numa ./cloverleaf_mpi -OPS_DIAGS=2 >> c3d_mpi"$numa_domains"omp"$physical_cores_per_numa"_icx_diag2
		mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_sycl_flat -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> c3d_mpisycl_flat_diag2
		mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_sycl_ndrange -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> c3d_mpisycl_ndrange_diag2
	done
done
