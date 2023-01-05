#!/bin/bash
set -x
sed -i "s/end_step=.*/end_step=50/g" clover.in
array=( 3840 5430 7680 10860 )
for i in "${array[@]}"
do
	sed -i "s/x_cells=.*/x_cells=$i/g" clover.in
	sed -i "s/y_cells=.*/y_cells=$i/g" clover.in
	for j in {1..2}
	do
		srun ./cloverleaf_mpi_hip -OPS_DIAGS=1 >> c2d_mpihip_16_diag1
		srun ./cloverleaf_mpi_hip -OPS_DIAGS=2 >> c2d_mpihip_16_diag2
		srun ./cloverleaf_mpi_hip -OPS_DIAGS=1 -gpudirect >> c2d_mpihip_16_direct_diag1
		srun ./cloverleaf_mpi_hip -OPS_DIAGS=2 -gpudirect >> c2d_mpihip_16_direct_diag2
		srun ./cloverleaf_mpi_hip_tiled OPS_TILING OPS_TILING_MAXDEPTH=6 OPS_TILESIZE_X=20000 OPS_TILESIZE_Y=20000 -OPS_DIAGS=1 >> c2d_mpihip_16_tiled_diag1
		srun ./cloverleaf_mpi_hip_tiled OPS_TILING OPS_TILING_MAXDEPTH=6 OPS_TILESIZE_X=20000 OPS_TILESIZE_Y=20000 -OPS_DIAGS=2 >> c2d_mpihip_16_tiled_diag2
		srun ./cloverleaf_mpi_hip_tiled OPS_TILING OPS_TILING_MAXDEPTH=6 OPS_TILESIZE_X=20000 OPS_TILESIZE_Y=20000 -OPS_DIAGS=1 -gpudirect >> c2d_mpihip_16_tiled_direct_diag1
		srun ./cloverleaf_mpi_hip_tiled OPS_TILING OPS_TILING_MAXDEPTH=6 OPS_TILESIZE_X=20000 OPS_TILESIZE_Y=20000 -OPS_DIAGS=2 -gpudirect >> c2d_mpihip_16_tiled_direct_diag2

#		OMP_NUM_THREADS=1 mpirun  -np 192 -bind-to hwthread ./cloverleaf_mpi -OPS_DIAGS=1 >> c2d_mpi_icc_diag1
#		OMP_NUM_THREADS=1 mpirun  -np 192 -bind-to hwthread ./cloverleaf_mpi -OPS_DIAGS=2 >> c2d_mpi_icc_diag2
#		OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np 8  -bind-to numa:1 ./cloverleaf_mpi_openmp -OPS_DIAGS=1 >> c2d_mpi4omp24_icc_diag1
#		OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np 8  -bind-to numa:1 ./cloverleaf_mpi_openmp -OPS_DIAGS=2 >> c2d_mpi4omp24_icc_diag2
	done
done
