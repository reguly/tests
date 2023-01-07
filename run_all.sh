#!/bin/bash
export BASE=`pwd`
source source_intel
cd $BASE/OPS/apps/c/CloverLeaf
$BASE/runner_scripts/run_cloverleaf.sh
cd $BASE/OPS/apps/c/CloverLeaf_3D
$BASE/runner_scripts/run_cloverleaf3d.sh
cd $BASE/apps/rtm
$BASE/runner_scripts/run_rtm.sh
cd $BASE/apps/TGV_StoreAll
$BASE/runner_scripts/run_SA.sh
cd $BASE/apps/TGV_StoreNone
$BASE/runner_scripts/run_SN.sh

