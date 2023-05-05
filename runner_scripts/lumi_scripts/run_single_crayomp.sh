#!/bin/bash

source ~/source_rocm
export OPS_INSTALL_PATH=/users/regulyre/OPS3/ops

cd $OPS_INSTALL_PATH/c/
make ompoffload -B -j

cd $OPS_INSTALL_PATH/../apps/c/CloverLeaf
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=7680/g" clover.in
sed -i "s/y_cells=.*/y_cells=7680/g" clover.in
rm cloverleaf_ompoffload
make cloverleaf_ompoffload
./cloverleaf_ompoffload -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=2

cd $OPS_INSTALL_PATH/../apps/c/CloverLeaf_3D
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=408/g" clover.in
sed -i "s/y_cells=.*/y_cells=408/g" clover.in
sed -i "s/z_cells=.*/z_cells=408/g" clover.in
rm cloverleaf_ompoffload
make cloverleaf_ompoffload
./cloverleaf_ompoffload -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1

cd ~/apps/ops_so08
rm wave-propagation_ompoffload
make wave-propagation_ompoffload
./wave-propagation_ompoffload 1000 1000 1000 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=4

cd ~/apps/rtm_ndrange
rm rtm_ompoffload
make rtm_ompoffload
./rtm_ompoffload  -sizex=384 -sizey=384 -sizez=384 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8


cd ~/apps/TGV_StoreNone
rm opensbli_ompoffload
make opensbli_ompoffload
./opensbli_ompoffload 512 512 512 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=2


cd ~/apps/TGV_StoreAll
make opensbli_ompoffload
rm opensbli_ompoffload
make opensbli_ompoffload
./opensbli_ompoffload 384 384 384 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=16 OPS_BLOCK_SIZE_Z=1
