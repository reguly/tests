#!/bin/bash
set -x

cd ~/apps/rtm_ndrange/
#array=( hotspots hpc-performance performance-snapshot uarch-exploration memory-access )
#for test in "${array[@]}"
#do
#	name=rtm_mpi224_icc_diag2
#	OMP_NUM_THREADS=1 mpirun  -np 224 -bind-to hwthread vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2
#	name=rtm_mpi112_icc_diag2
#	OMP_NUM_THREADS=1 mpirun  -np 112 -bind-to core vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2
#done

array=( hotspots hpc-performance performance-snapshot uarch-exploration memory-access threading )
for test in "${array[@]}"
do
	#name=rtm_mpisycl_flat_diag2
	#mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./rtm_mpi_sycl_flat -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1
	name=rtm_mpisycl_ndrange_diag2
	mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./rtm_mpi_sycl_ndrange -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1
	name=rtm_mpi8omp28_icc_diag2
	OMP_NUM_THREADS=28 OMP_PROC_BIND=TRUE mpirun -np 8  -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2
	name=rtm_mpi8omp14_icc_diag2
	OMP_NUM_THREADS=14 OMP_PROC_BIND=spread mpirun -np 8  -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2
done

