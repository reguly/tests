#!/bin/bash -l
#SBATCH --job-name=scaling_ops   # Job name
#SBATCH --output=scaling_ops.o%j # Name of stdout output file
#SBATCH --error=scaling_ops.e%j  # Name of stderr error file
#SBATCH --partition=dev-g    # Partition (queue) name
#SBATCH --gpus=1
#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=63
#SBATCH --account=project_465000281
#SBATCH --time=01:20:00      # Run time (d-hh:mm:ss)
#SBATCH --mem=0

#TODO:
# - change, gpus, nstasks, mem, weak scaling values
cat ~/submit.sh
source ~/source_rocm
#export FI_CXI_RX_MATCH_MODE=software
#export HSA_ENABLE_DEBUG=1
#export HSA_TOOLS_LIB=$ROCM_PATH/lib/librocm-debug-agent.so.2
#export ROCM_DEBUG_AGENT_OPTIONS="--output=debug-agent-outdir/output.txt --save-code-objects=debug-agent-outdir"
x=1
y=1
z=1
echo $ROCM_PATH
cd ~/
#base: 7680 7680
./run_cloverleaf2d.sh $(( 1*7680 )) $(( 1*7680 ))
cd ~/
./run_cloverleaf2d.sh 18000 18000
cd ~/
#base: 408 408 408
./run_cloverleaf3d.sh $(( $x*408 )) $(( $y*408 )) $(( $z*408 ))
##1632 816 816
cd ~/
./run_cloverleaf3d.sh 600 600 600
cd ~/
#base: 320^3
./run_rtm.sh $(( $x*320 )) $(( $y*320 )) $(( $z*320 ))
##1280 640 640
cd ~/
./run_rtm.sh 720 720 720 
cd ~/
#base 384^3
./run_SA.sh $(( $x*384 )) $(( $y*384 )) $(( $z*384 ))
##1536 768 768
cd ~/
./run_SA.sh 476 476 476
cd ~/
#base 512^3
./run_SN.sh $(( $x*512 )) $(( $y*512 )) $(( $z*512 ))
##2048 1024 1024
cd ~/
./run_SN.sh 640 640 640
cd ~/
#base 1000^3
./run_so08.sh $(( $x*1000 )) $(( $y*1000 )) $(( $z*1000 ))
##1200 1200 1200
cd ~/
./run_so08.sh 1200 1200 1200
date
exit 0
cd /scratch/project_465000281/rig250
srun --unbuffered ~/MG-CFD-app-OP2/bin/mgcfd_mpi_hip -i input-mgcfd.dat -m ptscotch OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_mpi_hip_atomics_rig250_1024

