#!/bin/bash
cd ~/apps/TGV_StoreAll 
for j in {1..4}
do
	#defalt size 384 384 384
	srun --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./opensbli_mpi_hip $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=16 OPS_BLOCK_SIZE_Z=1 >> sa_new_mpihip_"$SLURM_NTASKS"_$1_$2_$3_diag2
	srun --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./opensbli_mpi_hip $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=16 OPS_BLOCK_SIZE_Z=1 -gpudirect >> sa_new_mpihip_"$SLURM_NTASKS"_$1_$2_$3_direct_diag2
#	srun --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./opensbli_mpi_hip_tiled $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=16 OPS_BLOCK_SIZE_Z=1 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=12 >> sa_new_mpihip_"$SLURM_NTASKS"_$1_$2_$3_tiled_diag2
	srun --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./opensbli_mpi_hip_tiled $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=16 OPS_BLOCK_SIZE_Z=1 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=12 -gpudirect >> sa_new_mpihip_"$SLURM_NTASKS"_$1_$2_$3_tiled_direct_diag2
done
