#!/bin/bash -l
#SBATCH --job-name=scaling_ops   # Job name
#SBATCH --output=scaling_ops.o%j # Name of stdout output file
#SBATCH --error=scaling_ops.e%j  # Name of stderr error file
#SBATCH --time=01:40:00
#SBATCH --partition=standard
#SBATCH --qos=standard
##SBATCH --reservation=shortqos
#SBATCH --account=e647
#SBATCH --mem=0


#SBATCH --nodes=16

#TODO:
# - change, gpus, nstasks, mem, weak scaling values
cat /work/e647/e647/ireguly5/tests/runner_scripts/lumi_scripts/submit.sh
source /work/e647/e647/ireguly5/source_archer2_cray
x=4
y=2
z=2
cd /work/e647/e647/ireguly5/tests/runner_scripts/lumi_scripts/
#base: 7680 7680
./run_cloverleaf2d.sh $(( 4*7680 )) $(( 4*7680 ))
cd /work/e647/e647/ireguly5/tests/runner_scripts/lumi_scripts/
./run_cloverleaf2d.sh 18000 18000
cd /work/e647/e647/ireguly5/tests/runner_scripts/lumi_scripts/
#base: 408 408 408
./run_cloverleaf3d.sh $(( $x*408 )) $(( $y*408 )) $(( $z*408 ))
cd /work/e647/e647/ireguly5/tests/runner_scripts/lumi_scripts/
./run_cloverleaf3d.sh 600 600 600
cd /work/e647/e647/ireguly5/tests/runner_scripts/lumi_scripts/
#base 384^3
./run_SA.sh $(( $x*384 )) $(( $y*384 )) $(( $z*384 ))
cd /work/e647/e647/ireguly5/tests/runner_scripts/lumi_scripts/
./run_SA.sh 476 476 476
cd /work/e647/e647/ireguly5/tests/runner_scripts/lumi_scripts/
#base 512^3
./run_SN.sh $(( $x*512 )) $(( $y*512 )) $(( $z*512 ))
cd /work/e647/e647/ireguly5/tests/runner_scripts/lumi_scripts/
./run_SN.sh 640 640 640
cd /work/e647/e647/ireguly5/tests/runner_scripts/lumi_scripts/

