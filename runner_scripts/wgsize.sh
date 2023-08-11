#!/bin/bash -f
sed -i "s/end_step=.*/end_step=5/g" clover.in
sed -i "s/x_cells=.*/x_cells=408/g" clover.in
sed -i "s/y_cells=.*/y_cells=408/g" clover.in
sed -i "s/z_cells=.*/z_cells=408/g" clover.in
for k in {8,16,32,64,128}
do
	for j in {1,2,4,8,16,32}
	do
		for i in {1,2,4,8,16,32}
		do
			#if [[ $((k*j*i)) -gt 1024 ]]; then
			if [[ $((k*j*i)) -gt 1024 ]] || [[ $((k*j*i)) -lt 64 ]]; then
				break
			fi
			echo "wg size test ${k} ${j} ${i}"
			echo "wg size test ${k} ${j} ${i}" >> >> c3d_"$ACCEL"_wgtest3d
			./cloverleaf_"$ACCEL" -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_X=${k} OPS_BLOCK_SIZE_Z=${j} OPS_BLOCK_SIZE_Y=${i} >> c3d_"$ACCEL"_wgtest3d
		done
	done
done
