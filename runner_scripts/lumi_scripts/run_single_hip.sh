#!/bin/bash

source ~/source_sing_aomp

cd $OPS_INSTALL_PATH/c/
#make hip -B -j

cd ~/apps/TGV_StoreAll

#rm opensbli_hip
#make opensbli_hip
./opensbli_hip 384 384 384 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=4
#./opensbli_hip 384 384 384 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=1
exit 0


cd $OPS_INSTALL_PATH/../apps/c/CloverLeaf
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=7680/g" clover.in
sed -i "s/y_cells=.*/y_cells=7680/g" clover.in
rm cloverleaf_hip
make cloverleaf_hip
#./cloverleaf_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=2
./cloverleaf_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1

cd $OPS_INSTALL_PATH/../apps/c/CloverLeaf_3D
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=408/g" clover.in
sed -i "s/y_cells=.*/y_cells=408/g" clover.in
sed -i "s/z_cells=.*/z_cells=408/g" clover.in
rm cloverleaf_hip
make cloverleaf_hip
#./cloverleaf_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1
./cloverleaf_hip -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=1

cd ~/apps/rtm_ndrange
rm rtm_hip
make rtm_hip
#./rtm_sycl  -sizex=384 -sizey=384 -sizez=384 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8
./rtm_sycl  -sizex=384 -sizey=384 -sizez=384 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=1

cd ~/apps/rtm_ndrange
rm rtm_hip
make rtm_hip
#./rtm_hip  -sizex=384 -sizey=384 -sizez=384 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8
./rtm_hip  -sizex=384 -sizey=384 -sizez=384 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=1

cd ~/apps/TGV_StoreNone
rm opensbli_hip
make opensbli_hip
#./opensbli_hip 512 512 512 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=2
./opensbli_hip 512 512 512 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=1



cd ~/apps/ops_so08
rm wave-propagation_hip
make wave-propagation_hip
#./wave-propagation_hip 1000 1000 1000 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=4
./wave-propagation_hip 1000 1000 1000 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=1

