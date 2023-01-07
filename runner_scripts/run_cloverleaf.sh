#!/bin/bash
set -x
sed -i "s/end_step=.*/end_step=50/g" clover.in
#OPS_FLAT=1 make cloverleaf_mpi_sycl -B
#mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_flat
#OPS_CPU=1 make cloverleaf_mpi_sycl -B
#mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_ndrange
#export DPCPP_CPU_NUM_CUS=14
array=( 7680 )
for i in "${array[@]}"
do
	sed -i "s/x_cells=.*/x_cells=$i/g" clover.in
	sed -i "s/y_cells=.*/y_cells=$i/g" clover.in
	for j in {1..2}
	do
		OMP_NUM_THREADS=1 mpirun  -np 144 -bind-to hwthread ./cloverleaf_mpi -OPS_DIAGS=2 >> c2d_mpi144_icc_diag2
		OMP_NUM_THREADS=1 mpirun  -np 72 -bind-to core ./cloverleaf_mpi -OPS_DIAGS=2 >> c2d_mpi72_icc_diag2
		OMP_NUM_THREADS=72 OMP_PROC_BIND=TRUE mpirun -np 2  -bind-to numa ./cloverleaf_mpi -OPS_DIAGS=2 >> c2d_mpi2omp72_icc_diag2
		OMP_NUM_THREADS=36 OMP_PROC_BIND=spread mpirun -np 2  -bind-to numa ./cloverleaf_mpi -OPS_DIAGS=2 >> c2d_mpi2omp36_icc_diag2
		mpirun -np 2 -bind-to numa ./cloverleaf_mpi_sycl_flat -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> c2d_mpisycl_flat_diag2
		mpirun -np 2 -bind-to numa ./cloverleaf_mpi_sycl_ndrange -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> c2d_mpisycl_ndrange_diag2
	done
done
