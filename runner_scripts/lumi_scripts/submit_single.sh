#!/bin/bash -l
#SBATCH --job-name=scaling_ops   # Job name
#SBATCH --output=scaling_ops.o%j # Name of stdout output file
#SBATCH --error=scaling_ops.e%j  # Name of stderr error file
#SBATCH --partition=dev-g    # Partition (queue) name
#SBATCH --gpus=1
#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --account=project_465000281
#SBATCH --time=02:20:00      # Run time (d-hh:mm:ss)
#SBATCH --mem=64G

#srun --unbuffered singularity exec --bind /scratch:/scratch,/pfs,/opt/cray ~/amdsycl.sif ~/run_single_aomp.sh >> results_single_aomp
#srun --unbuffered singularity exec --bind /scratch:/scratch,/pfs,/opt/cray ~/amdsycl.sif ~/run_single_dpcpp.sh >> results_single_dpcpp
#srun --unbuffered singularity exec --bind /scratch:/scratch,/pfs,/opt/cray ~/amdsycl.sif ~/run_single_opensycl.sh >> results_single_opensycl
srun --unbuffered singularity exec --bind /scratch:/scratch,/pfs,/opt/cray ~/amdsycl.sif ~/run_single_hip.sh >> results_single_hip_badblocksize
#srun --unbuffered ~/run_single_crayomp.sh >> results_single_crayomp
