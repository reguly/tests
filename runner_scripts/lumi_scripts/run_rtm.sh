#!/bin/bash
cd ~/apps/rtm_ndrange
for j in {1..4}
do
	srun ./rtm_mpi_hip -sizex=$1 -sizey=$2 -sizez=$3 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8 >> rtm_mpihip_"$SLURM_NTASKS"_$1_$2_$3_diag2
	srun ./rtm_mpi_hip -sizex=$1 -sizey=$2 -sizez=$3 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8 -gpudirect >> rtm_mpihip_"$SLURM_NTASKS"_$1_$2_$3_direct_diag2
#	srun ./rtm_mpi_hip_tiled -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=8 >> rtm_mpihip_"$SLURM_NTASKS"_tiled_diag2
#	srun ./rtm_mpi_hip_tiled -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=8 -gpudirect >> rtm_mpihip_"$SLURM_NTASKS"_tiled_direct_diag2
done
