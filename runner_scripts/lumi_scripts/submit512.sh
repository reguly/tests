#!/bin/bash -l
#SBATCH --job-name=scaling_ops   # Job name
#SBATCH --output=scaling_ops.o%j # Name of stdout output file
#SBATCH --error=scaling_ops.e%j  # Name of stderr error file
#SBATCH --partition=standard-g    # Partition (queue) name
#SBATCH --gpus=512
#SBATCH --ntasks=512
#SBATCH --ntasks-per-node=8
##SBATCH --cpus-per-task=7
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
x=8
y=8
z=8
echo $ROCM_PATH
cd ~/
#base: 7680 7680
#./run_cloverleaf2d.sh $(( 32*7680 )) $(( 16*7680 ))
cd ~/
#base: 408 408 408
./run_cloverleaf3d.sh $(( $x*408 )) $(( $y*408 )) $(( $z*408 ))

