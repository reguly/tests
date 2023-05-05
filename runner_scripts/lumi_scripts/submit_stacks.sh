#!/bin/bash -l
#SBATCH --job-name=scaling_ops   # Job name
#SBATCH --output=scaling_ops.o%j # Name of stdout output file
#SBATCH --error=scaling_ops.e%j  # Name of stderr error file
#SBATCH --partition=dev-g    # Partition (queue) name
#SBATCH --gpus=16
#SBATCH --ntasks=16
#SBATCH --ntasks-per-node=8
#SBATCH --account=project_465000281
#SBATCH --time=01:20:00      # Run time (d-hh:mm:ss)
#SBATCH --mem=450G

#TODO:
# - change, gpus, nstasks, mem, weak scaling values
source ~/source_rocm2
srun --ntasks=1 env
cd ~/OPS/apps/c/CloverLeaf_3D
sed -i "s/x_cells=.*/x_cells=1632/g" clover.in
sed -i "s/y_cells=.*/y_cells=816/g" clover.in
sed -i "s/z_cells=.*/z_cells=816/g" clover.in
srun --unbuffered --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./cloverleaf_mpi_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 -gpudirect
#sed -i "s/x_cells=.*/x_cells=1000/g" clover.in
#sed -i "s/y_cells=.*/y_cells=1000/g" clover.in
#sed -i "s/z_cells=.*/z_cells=1000/g" clover.in
#srun --unbuffered --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./cloverleaf_mpi_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 -gpudirect
#sed -i "s/x_cells=.*/x_cells=1200/g" clover.in
#sed -i "s/y_cells=.*/y_cells=1200/g" clover.in
#sed -i "s/z_cells=.*/z_cells=1200/g" clover.in
#srun --unbuffered --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./cloverleaf_mpi_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 -gpudirect
sed -i "s/x_cells=.*/x_cells=1632/g" clover.in
sed -i "s/y_cells=.*/y_cells=816/g" clover.in
sed -i "s/z_cells=.*/z_cells=816/g" clover.in
srun --unbuffered --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./cloverleaf_mpi_hip_tiled -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=6 -gpudirect
unset MPICH_GPU_IPC_ENABLED
srun --unbuffered --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./cloverleaf_mpi_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 -gpudirect
srun --unbuffered --cpu-bind=map_cpu:48,56,16,24,1,8,32,40 ./cloverleaf_mpi_hip_tiled -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 OPS_TILESIZE_X=1000000 OPS_TILESIZE_Y=1000000 OPS_TILESIZE_Z=1000000 OPS_TILING OPS_TILING_MAXDEPTH=6 -gpudirect
