#!/bin/bash

source ~/source_sing_aomp

cd $OPS_INSTALL_PATH/../apps/c/CloverLeaf
sed -i "s/end_step=.*/end_step=5/g" clover.in
sed -i "s/x_cells=.*/x_cells=7680/g" clover.in
sed -i "s/y_cells=.*/y_cells=7680/g" clover.in
make cloverleaf_hip
omniperf profile -n c2d_hip -- ./cloverleaf_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=2

cd $OPS_INSTALL_PATH/../apps/c/CloverLeaf_3D
sed -i "s/end_step=.*/end_step=5/g" clover.in
sed -i "s/x_cells=.*/x_cells=408/g" clover.in
sed -i "s/y_cells=.*/y_cells=408/g" clover.in
sed -i "s/z_cells=.*/z_cells=408/g" clover.in
make cloverleaf_hip
omniperf profile -n c3d_hip -- ./cloverleaf_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1

cd ~/apps/rtm_ndrange
make rtm_hip
omniperf profile -n rtm_hip -- ./rtm_hip  -sizex=384 -sizey=384 -sizez=384 -iters=10 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8


#cd ~/apps/TGV_StoreNone
#make opensbli_hip
#omniperf profile -n sn_hip -- ./opensbli_hip 512 512 512 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=2


cd ~/apps/TGV_StoreAll
make opensbli_hip
omniperf profile -n sa_hip -- ./opensbli_hip 384 384 384 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=16 OPS_BLOCK_SIZE_Z=1

cd ~/apps/ops_so08
make wave-propagation_hip
omniperf profile -n so08_hip -- ./wave-propagation_hip 384 384 384 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=8 OPS_BLOCK_SIZE_Z=1
