#!/bin/bash
cd ~/OPS/apps/c/CloverLeaf
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=$1/g" clover.in
sed -i "s/y_cells=.*/y_cells=$2/g" clover.in
for j in {1..4}
do
	srun ./cloverleaf_mpi_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=2 >> c2d_mpihip_"$SLURM_NTASKS"_$1_$2_diag2
        srun ./cloverleaf_mpi_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=2 -gpudirect >> c2d_mpihip_"$SLURM_NTASKS"_$1_$2_direct_diag2
        srun ./cloverleaf_mpi_hip_tiled -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=2 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=6 >> c2d_mpihip_"$SLURM_NTASKS"_$1_$2_tiled_diag2
        srun ./cloverleaf_mpi_hip_tiled -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=2 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=6 -gpudirect >> c2d_mpihip_"$SLURM_NTASKS"_$1_$2_tiled_direct_diag2
done
