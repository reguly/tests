#!/bin/bash

source ~/source_sing_aomp
source ~/source_sing_dpcpp

cd $OPS_INSTALL_PATH/c/
make sycl -B -j

cd $OPS_INSTALL_PATH/../apps/c/CloverLeaf
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=7680/g" clover.in
sed -i "s/y_cells=.*/y_cells=7680/g" clover.in
OPS_CPU=0 make cloverleaf_sycl -B
./cloverleaf_sycl -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=2
OPS_FLAT=1 make cloverleaf_sycl -B
./cloverleaf_sycl -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=2

cd $OPS_INSTALL_PATH/../apps/c/CloverLeaf_3D
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=408/g" clover.in
sed -i "s/y_cells=.*/y_cells=408/g" clover.in
sed -i "s/z_cells=.*/z_cells=408/g" clover.in
OPS_CPU=0 make cloverleaf_sycl -B
./cloverleaf_sycl -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1
OPS_FLAT=1 make cloverleaf_sycl -B
./cloverleaf_sycl -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1

cd ~/apps/rtm_ndrange
OPS_CPU=0 make rtm_sycl -B
./rtm_sycl  -sizex=384 -sizey=384 -sizez=384 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8
OPS_FLAT=1 make rtm_sycl -B
./rtm_sycl  -sizex=384 -sizey=384 -sizez=384 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8


cd ~/apps/TGV_StoreNone
OPS_CPU=0 make opensbli_sycl -B
./opensbli_sycl 512 512 512 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=2
OPS_FLAT=1 make opensbli_sycl -B
./opensbli_sycl 512 512 512 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=2


cd ~/apps/TGV_StoreAll
OPS_CPU=0 make opensbli_sycl -B
./opensbli_sycl 384 384 384 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=16 OPS_BLOCK_SIZE_Z=1
OPS_FLAT=1 make opensbli_sycl -B
./opensbli_sycl 384 384 384 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=16 OPS_BLOCK_SIZE_Z=1

cd ~/apps/ops_so08
OPS_CPU=0 make wave-propagation_sycl -B
./wave-propagation_sycl 1000 1000 1000 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=4
OPS_FLAT=1 make wave-propagation_sycl -B
./wave-propagation_sycl 1000 1000 1000 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=4
