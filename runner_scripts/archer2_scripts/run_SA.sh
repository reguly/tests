#!/bin/bash
cd /work/e647/e647/ireguly5/tests/apps/TGV_StoreAll
for j in {1..1}
do
	OMP_PLACES=cores OMP_NUM_THREADS=1 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=128 --cpus-per-task=1 ./opensbli_mpi_tiled $1 $2 $3 -OPS_DIAGS=2 >> sa_mpi_"$SLURM_NNODES"_$1_$2_$3_diag2
	OMP_PLACES=cores OMP_NUM_THREADS=1 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=128 --cpus-per-task=1 ./opensbli_mpi_tiled $1 $2 $3 -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=12 OPS_CACHE_SIZE=3 >> sa_mpi_tiled_"$SLURM_NNODES"_$1_$2_$3_diag2
#	OMP_PLACES=cores OMP_NUM_THREADS=1 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=128 --cpus-per-task=1 ./opensbli_mpi_tiled $1 $2 $3 -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=12 OPS_CACHE_SIZE=10000 >> sa_mpi_tiledcomm_"$SLURM_NNODES"_$1_$2_$3_diag2
	OMP_PLACES=cores OMP_NUM_THREADS=16 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=8 --cpus-per-task=16 ./opensbli_mpi_tiled $1 $2 $3 -OPS_DIAGS=2 >> sa_mpiomp_"$SLURM_NNODES"_$1_$2_$3_diag2
	OMP_PLACES=cores OMP_NUM_THREADS=16 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=8 --cpus-per-task=16 ./opensbli_mpi_tiled $1 $2 $3 -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=12 OPS_CACHE_SIZE=56 >> sa_mpiomp_tiled_"$SLURM_NNODES"_$1_$2_$3_diag2
#	OMP_PLACES=cores OMP_NUM_THREADS=16 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=8 --cpus-per-task=16 ./opensbli_mpi_tiled $1 $2 $3 -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=12 OPS_CACHE_SIZE=10000 >> sa_mpiomp_tiledcomm_"$SLURM_NNODES"_$1_$2_$3_diag2
done
