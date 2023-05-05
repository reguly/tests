#cd ~/OPS3/apps/c/CloverLeaf
#./cloverleaf_$1 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=256 OPS_BLOCK_SIZE_Y=2 >> ~/c2d_$1_$2_7680_7680
#cd ~/OPS3/apps/c/CloverLeaf_3D
#./cloverleaf_$1 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=4 OPS_BLOCK_SIZE_Z=1 >> ~/c3d_$1_$2_408_408_408
cd ~/apps/rtm_ndrange
./rtm_$1 -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=1 OPS_BLOCK_SIZE_Z=8 >> ~/rtm_$1_$2_320_320_320
cd ~/apps/TGV_StoreAll
./opensbli_$1 384 384 384 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=64 OPS_BLOCK_SIZE_Y=16 OPS_BLOCK_SIZE_Z=1 >> ~/sa_$1_$2_384_384_384
cd ~/apps/TGV_StoreNone
./opensbli_$1 512 512 512 -OPS_DIAGS=2 OPS_BLOCK_SIZE_X=128 OPS_BLOCK_SIZE_Y=2 OPS_BLOCK_SIZE_Z=2 >> ~/sn_$1_$2_512_512_512
