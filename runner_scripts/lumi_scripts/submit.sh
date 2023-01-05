#!/bin/bash -l
#SBATCH --job-name=scaling_ops   # Job name
#SBATCH --output=scaling_ops.o%j # Name of stdout output file
#SBATCH --error=scaling_ops.e%j  # Name of stderr error file
#SBATCH --partition=dev-g    # Partition (queue) name
#SBATCH --gpus=2
#SBATCH --ntasks=2
#SBATCH --account=project_465000281
#SBATCH --time=01:20:00      # Run time (d-hh:mm:ss)
#SBATCH --mem=127G

#TODO:
# - change, gpus, nstasks, mem, weak scaling values
cat ~/submit.sh
date
source ~/source_rocm
cd ~/
./run_cloverleaf2d.sh 15360 7680
#30720 30720
cd ~/
./run_cloverleaf2d.sh 18000 18000
cd ~/
./run_cloverleaf3d.sh 816 408 408
#1632 816 816
cd ~/
./run_cloverleaf3d.sh 600 600 600
cd ~/
./run_rtm.sh 640 320 320
#1280 640 640
cd ~/
./run_rtm.sh 720 720 720 
cd ~/
./run_SA.sh 768 384 384
#1536 768 768
cd ~/
./run_SA.sh 476 476 476
cd ~/
./run_SN.sh 1024 512 512
#2048 1024 1024
cd ~/
./run_SN.sh 640 640 640
date
