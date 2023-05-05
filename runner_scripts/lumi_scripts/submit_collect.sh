#!/bin/bash -l
#SBATCH --job-name=scaling_ops   # Job name
#SBATCH --output=scaling_ops.o%j # Name of stdout output file
#SBATCH --error=scaling_ops.e%j  # Name of stderr error file
#SBATCH --partition=dev-g    # Partition (queue) name
#SBATCH --gpus=1
#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --account=project_465000281
#SBATCH --time=05:20:00      # Run time (d-hh:mm:ss)
#SBATCH --mem=64G


# srun --unbuffered singularity exec --bind /scratch:/scratch,/pfs,/opt/cray ~/amdsycl.sif ~/collect_aomp.sh >> collection_omniperf_aomp
# srun --unbuffered ~/collect_crayomp.sh >> collection_omniperf_crayomp


#srun --unbuffered ~/collect_hip_mgcfd.sh
srun --unbuffered singularity exec --bind /scratch:/scratch,/pfs,/opt/cray ~/amdsycl.sif ~/collect_opensycl_mgcfd.sh
srun --unbuffered singularity exec --bind /scratch:/scratch,/pfs,/opt/cray ~/amdsycl.sif ~/collect_dpcpp_mgcfd.sh
