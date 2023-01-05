#!/bin/bash
cd ~/apps/TGV_StoreNone
for j in {1..4}
do
	#default 512 512 512
	srun ./opensbli_mpi_hip $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=2 >> sn_mpihip_"$SLURM_NTASKS"_$1_$2_$3_diag2
	srun ./opensbli_mpi_hip $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=2 -gpudirect >> sn_mpihip_"$SLURM_NTASKS"_$1_$2_$3_direct_diag2
	srun ./opensbli_mpi_hip_tiled $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=2 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=6 >> sn_mpihip_"$SLURM_NTASKS"_$1_$2_$3_tiled_diag2
	srun ./opensbli_mpi_hip_tiled $1 $2 $3 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=2 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=6 -gpudirect >> sn_mpihip_"$SLURM_NTASKS"_$1_$2_$3_tiled_direct_diag2
done
