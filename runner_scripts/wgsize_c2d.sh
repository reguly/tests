#!/bin/bash -f
#OPS_CPU=0 make cloverleaf_mpi_sycl -B
#mv cloverleaf_mpi_sycl cloverleaf_"$ACCEL"
sed -i "s/end_step=.*/end_step=5/g" clover.in
sed -i "s/x_cells=.*/x_cells=7680/g" clover.in
sed -i "s/y_cells=.*/y_cells=7680/g" clover.in
#for k in {8,16,32,64,128,256}
for k in {256,512}
do
	j=1
	#for j in {1}
	#do
		for i in {1,2,4,8,16,32}
		do
			#if [[ $((k*j*i)) -gt 1024 ]]; then
			if [[ $((k*j*i)) -gt 1024 ]] || [[ $((k*j*i)) -lt 64 ]]; then
				break
			fi
			echo "wg size test ${k} ${j} ${i}" 
			echo "wg size test ${k} ${j} ${i}" >> c2d_"$ACCEL"_wgtest3d
			./cloverleaf_"$ACCEL" -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_X=${k} OPS_BLOCK_SIZE_Z=${j} OPS_BLOCK_SIZE_Y=${i} >> c2d_"$ACCEL"_wgtest3d
		done
	#done
done
