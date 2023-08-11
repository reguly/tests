#!/bin/bash

#source ~/source_sing_aomp
#source ~/source_sing_dpcpp

cd $OPS_INSTALL_PATH/c/
make sycl -B -j

cd $OPS_INSTALL_PATH/../apps/c/CloverLeaf
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=7680/g" clover.in
sed -i "s/y_cells=.*/y_cells=7680/g" clover.in
OPS_CPU=0 make cloverleaf_sycl -B
for j in {1..4}
do
./cloverleaf_sycl -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 >> c2d_a100_sycl_opensycl_ndrange
done
OPS_FLAT=1 make cloverleaf_sycl -B
for j in {1..4}
do
./cloverleaf_sycl -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 >> c2d_a100_sycl_opensycl_flat
done

cd $OPS_INSTALL_PATH/../apps/c/CloverLeaf_3D
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=408/g" clover.in
sed -i "s/y_cells=.*/y_cells=408/g" clover.in
sed -i "s/z_cells=.*/z_cells=408/g" clover.in
OPS_CPU=0 make cloverleaf_sycl -B
for j in {1..4}
do
./cloverleaf_sycl -OPS_DIAGS=2 >> c3d_a100_sycl_opensycl_ndrange
done
OPS_FLAT=1 make cloverleaf_sycl -B
for j in {1..4}
do
./cloverleaf_sycl -OPS_DIAGS=2 >> c3d_a100_sycl_opensycl_flat
done

cd ~/projects/tests/apps/rtm
OPS_CPU=0 make rtm_sycl -B
for j in {1..4}
do
./rtm_sycl  -sizex=384 -sizey=384 -sizez=384 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 >> rtm_a100_sycl_opensycl_ndrange
done
OPS_FLAT=1 make rtm_sycl -B
for j in {1..4}
do
./rtm_sycl  -sizex=384 -sizey=384 -sizez=384 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4  >> rtm_a100_sycl_opensycl_ndflat
done


cd ~/projects/tests/apps/TGV_StoreNone
OPS_CPU=0 make opensbli_sycl -B
for j in {1..4}
do
./opensbli_sycl 512 512 512 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=32 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8  >> sn_a100_sycl_opensycl_ndrange
done
OPS_FLAT=1 make opensbli_sycl -B
for j in {1..4}
do
./opensbli_sycl 512 512 512 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=32 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8 >> sn_a100_sycl_opensycl_flat
done


cd ~/projects/tests/apps/TGV_StoreAll
OPS_CPU=0 make opensbli_sycl -B
for j in {1..4}
do
./opensbli_sycl 384 384 384 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 >> sa_a100_sycl_opensycl_ndrange
done
OPS_FLAT=1 make opensbli_sycl -B
for j in {1..4}
do
./opensbli_sycl 384 384 384 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1  >> sa_a100_sycl_opensycl_flat
done

cd ~/projects/tests/apps/ops_so08
OPS_CPU=0 make wave-propagation_sycl -B
for j in {1..4}
do
./wave-propagation_sycl 1000 1000 1000 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=4 >> so08_a100_sycl_opensycl_ndrange
done
OPS_FLAT=1 make wave-propagation_sycl -B
for j in {1..4}
do
./wave-propagation_sycl 1000 1000 1000 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=4  >> so08_a100_sycl_opensycl_flat
done
