#!/bin/bash -f
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
			echo "wg size test ${k} ${j} ${i}" >> so08_"$ACCEL"_wgtest3d
			./wave-propagation_"$ACCEL" 1000 1000 1000 -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_X=${k} OPS_BLOCK_SIZE_Z=${j} OPS_BLOCK_SIZE_Y=${i} >> so08_"$ACCEL"_wgtest3d
		done
	done
done
