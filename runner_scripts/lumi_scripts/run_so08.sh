#!/bin/bash
cd ~/apps/ops_so08
for j in {1..4}
do
	#default 1000 1000 1000
	srun --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./wave-propagation_mpi_hip $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=4 >> so08_new_mpihip_"$SLURM_NTASKS"_$1_$2_$3_diag2
	srun --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./wave-propagation_mpi_hip $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=4 -gpudirect >> so08_new_mpihip_"$SLURM_NTASKS"_$1_$2_$3_direct_diag2
#	srun --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./wave-propagation_mpi_hip_tiled $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=4 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=6 >> so08_new_mpihip_"$SLURM_NTASKS"_$1_$2_$3_tiled_diag2
	srun --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./wave-propagation_mpi_hip_tiled $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=4 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=8 -gpudirect >> so08_new_mpihip_"$SLURM_NTASKS"_$1_$2_$3_tiled_direct_diag2
done
