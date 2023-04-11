#!/bin/bash
set -x
sed -i "s/end_step=.*/end_step=50/g" clover.in
array=( 3840 5430 7680 10860 )
for i in "${array[@]}"
do
	sed -i "s/x_cells=.*/x_cells=$i/g" clover.in
	sed -i "s/y_cells=.*/y_cells=$i/g" clover.in
	for j in {1..4}
	do
		srun ./cloverleaf_mpi_hip -OPS_DIAGS=1 >> c2d_mpihip_1_diag1
		srun ./cloverleaf_mpi_hip -OPS_DIAGS=2 >> c2d_mpihip_1_diag2
#		OMP_NUM_THREADS=1 mpirun  -np 192 -bind-to hwthread ./cloverleaf_mpi -OPS_DIAGS=1 >> c2d_mpi_icc_diag1
#		OMP_NUM_THREADS=1 mpirun  -np 192 -bind-to hwthread ./cloverleaf_mpi -OPS_DIAGS=2 >> c2d_mpi_icc_diag2
#		OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np $numa_domains  $bind_numa:1 ./cloverleaf_mpi_openmp -OPS_DIAGS=1 >> c2d_mpi4omp24_icc_diag1
#		OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np $numa_domains  $bind_numa:1 ./cloverleaf_mpi_openmp -OPS_DIAGS=2 >> c2d_mpi4omp24_icc_diag2
	done
done
