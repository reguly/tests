#!/bin/bash
set -x
cd ~/apps/TGV_StoreNone/
array=( hotspots hpc-performance performance-snapshot uarch-exploration memory-access )
for test in "${array[@]}"
do
	name=sn_mpi224_icc_diag2
	OMP_NUM_THREADS=1 mpirun  -np 224 -bind-to hwthread vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./opensbli_mpi 320 320 320 -OPS_DIAGS=2
	name=sn_mpi112_icc_diag2
	OMP_NUM_THREADS=1 mpirun  -np 112 -bind-to core vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./opensbli_mpi 320 320 320 -OPS_DIAGS=2
done

array=( hotspots hpc-performance performance-snapshot uarch-exploration memory-access threading )
for test in "${array[@]}"
do
	name=sn_mpisycl_flat_diag2
	mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./opensbli_mpi_sycl_flat 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1
	name=sn_mpisycl_ndrange_diag2
	mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./opensbli_mpi_sycl_ndrange 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1
	name=sn_mpi8omp28_icc_diag2
	OMP_NUM_THREADS=28 OMP_PROC_BIND=TRUE mpirun -np 8  -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./opensbli_mpi 320 320 320 -OPS_DIAGS=2
	name=sn_mpi8omp14_icc_diag2
	OMP_NUM_THREADS=14 OMP_PROC_BIND=spread mpirun -np 8  -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./opensbli_mpi 320 320 320 -OPS_DIAGS=2
done

