#!/bin/bash
cd ~/OPS/apps/c/CloverLeaf_3D
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=$1/g" clover.in
sed -i "s/y_cells=.*/y_cells=$2/g" clover.in
sed -i "s/z_cells=.*/z_cells=$3/g" clover.in
for j in {1..4}
do
	srun ./cloverleaf_mpi_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 >> c3d_mpihip_"$SLURM_NTASKS"_$1_$2_$3_diag2
        srun ./cloverleaf_mpi_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 -gpudirect >> c3d_mpihip_"$SLURM_NTASKS"_$1_$2_$3_direct_diag2
        srun ./cloverleaf_mpi_hip_tiled -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=6 >> c3d_mpihip_"$SLURM_NTASKS"_$1_$2_$3_tiled_diag2
        srun ./cloverleaf_mpi_hip_tiled -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=6 -gpudirect >> c3d_mpihip_"$SLURM_NTASKS"_$1_$2_$3_tiled_direct_diag2
done
