#!/bin/bash
set -x
sed -i "s/end_step=.*/end_step=50/g" clover.in
array=( 7680 )
for i in "${array[@]}"
do
	sed -i "s/x_cells=.*/x_cells=$i/g" clover.in
	sed -i "s/y_cells=.*/y_cells=$i/g" clover.in
	for j in {1..8}
	do
		OMP_NUM_THREADS=1 mpirun  -np $logical_cores -bind-to hwthread ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING OPS_TILING_MAXDEPTH=6 OPS_TILESIZE_X=100000 OPS_TILESIZE_Y=14 >> c2d_mpi"$logical_cores"_icc_tiled_diag2
		OMP_NUM_THREADS=1 mpirun  -np $physical_cores -bind-to core ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING OPS_TILING_MAXDEPTH=6 OPS_TILESIZE_X=100000 OPS_TILESIZE_Y=28 >> c2d_mpi"$physical_cores"_icc_tiled_diag2
	done
done
