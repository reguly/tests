#!/bin/bash -f
OPS_CPU=0 make opensbli_mpi_sycl
mv opensbli_mpi_sycl opensbli_mpi_sycl_ndrange
for k in {8,16,32,64,128,320}
do
	for j in {1,2,4,8,16,32}
	do
		for i in {1,2,4,8,16,32}
		do
			if [[ $((k*j*i)) -gt 8192 ]]; then
				break
			fi
			echo "wg size test ${k} ${j} ${i}"
			mpirun -np 2 -bind-to numa ./opensbli_mpi_sycl_ndrange 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_X=${k} OPS_BLOCK_SIZE_Z=${j} OPS_BLOCK_SIZE_Y=${i} >> sn_mpisycl_ndrange_wgtest3d
		done
	done
done
