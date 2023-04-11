#!/bin/bash
export BASE=`pwd`
source source_intel
source detect_hardware.sh
export OMP_PROC_BIND=TRUE
#these are for baskerville
#module purge; module load baskerville
#module load bask-apps/test
#module load HDF5/1.10.7-iimpi-2021a
cd $BASE/OPS/apps/c/CloverLeaf
$BASE/runner_scripts/run_cloverleaf.sh
cd $BASE/OPS/apps/c/CloverLeaf_3D
$BASE/runner_scripts/run_cloverleaf3d.sh
cd $BASE/apps/rtm
$BASE/runner_scripts/run_rtm.sh
cd $BASE/apps/ops_so08
$BASE/runner_scripts/run_so08.sh
cd $BASE/apps/TGV_StoreAll
$BASE/runner_scripts/run_SA.sh
cd $BASE/apps/TGV_StoreNone
$BASE/runner_scripts/run_SN.sh
cd $BASE/apps/Rotor37_8M
$BASE/runner_scripts/run_mgcfd.sh
cd $BASE/apps/volna/sp
$BASE/runner_scripts/run_volna.sh
cd $BASE/apps/ops_so08
$BASE/runner_scripts/run_so08.sh
