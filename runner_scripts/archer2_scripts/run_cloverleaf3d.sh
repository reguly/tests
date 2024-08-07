#!/bin/bash
cd /work/e647/e647/ireguly5/OPS/apps/c/CloverLeaf_3D
for j in {1..1}
do
	sed -i "s/end_step=.*/end_step=50/g" clover.in
	sed -i "s/x_cells=.*/x_cells=$1/g" clover.in
	sed -i "s/y_cells=.*/y_cells=$2/g" clover.in
	sed -i "s/z_cells=.*/z_cells=$3/g" clover.in
	OMP_PLACES=cores OMP_NUM_THREADS=1 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=128 --cpus-per-task=1 ./cloverleaf_mpi_tiled -OPS_DIAGS=2 >> c3d_mpi_"$SLURM_NNODES"_$1_$2_$3_diag2
  OMP_PLACES=cores OMP_NUM_THREADS=1 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=128 --cpus-per-task=1 ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=6 OPS_CACHE_SIZE=3 >> c3d_mpi_tiled_"$SLURM_NNODES"_$1_$2_$3_diag2
#  OMP_PLACES=cores OMP_NUM_THREADS=1 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=128 --cpus-per-task=1 ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=6 OPS_CACHE_SIZE=10000 >> c3d_mpi_tiledcomm_"$SLURM_NNODES"_$1_$2_$3_diag2
  OMP_PLACES=cores OMP_NUM_THREADS=16 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=8 --cpus-per-task=16 ./cloverleaf_mpi_tiled -OPS_DIAGS=2 >> c3d_mpiomp_"$SLURM_NNODES"_$1_$2_$3_diag2
  OMP_PLACES=cores OMP_NUM_THREADS=16 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=8 --cpus-per-task=16 ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=6 OPS_CACHE_SIZE=72 >> c3d_mpiomp_tiled_"$SLURM_NNODES"_$1_$2_$3_diag2
#  OMP_PLACES=cores OMP_NUM_THREADS=16 srun --unbuffered --hint=nomultithread --distribution=block:block --tasks-per-node=8 --cpus-per-task=16 ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=6 OPS_CACHE_SIZE=10000 >> c3d_mpiomp_tiledcomm_"$SLURM_NNODES"_$1_$2_$3_diag2
done
