vtune -collect hpc-performance -data-limit=0 -r c2d_mpi224_icc_hpc_performance
vtune -collect hotspots -data-limit=0 -r c2d_mpi224_icc_hotspots
vtune -collect performance-snapshot -knob collect-memory-bandwidth=true -data-limit=0 -r c2d_mpi224_icc_performance-snapshot
vtune -collect uarch-exploration -knob collect-core-bound=true  -data-limit=0 -r c2d_mpi224_icc_uarch-exploration

name=c2d_mpi224_icc_avx512_tiled_diag2
test=hpc-performance
OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core vtune -collect $name -data-limit=0 -r "${name}_${test}" ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING OPS_TILING_MAXDEPTH=6 OPS_TILESIZE_X=10000 OPS_TILESIZE_Y=20


#!/bin/bash
set -x
sed -i "s/end_step=.*/end_step=50/g" clover.in
sed -i "s/x_cells=.*/x_cells=7680/g" clover.in
sed -i "s/y_cells=.*/y_cells=7680/g" clover.in
array=( hotspots hpc-performance performance-snapshot uarch-exploration memory-access )
for test in "${array[@]}"
do
	name=c2d_mpi224_icc_diag2
	OMP_NUM_THREADS=1 mpirun  -np 224 -bind-to hwthread vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./cloverleaf_mpi -OPS_DIAGS=2
	name=c2d_mpi112_icc_diag2
	OMP_NUM_THREADS=1 mpirun  -np 112 -bind-to core vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./cloverleaf_mpi -OPS_DIAGS=2
	name=c2d_mpi112_tiled_icc_diag2
	OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING OPS_TILING_MAXDEPTH=6 OPS_TILESIZE_X=10000 OPS_TILESIZE_Y=20
done

array=( hotspots hpc-performance performance-snapshot uarch-exploration memory-access threading )
for test in "${array[@]}"
do
	name=c2d_mpisycl_flat_diag2
	mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./cloverleaf_mpi_sycl_flat -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1
	name=c2d_mpisycl_ndrange_diag2
	mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./cloverleaf_mpi_sycl_ndrange -OPS_DIAGS=2 OPS_SYCL_DEVICE=1 -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1
	name=c2d_mpi8omp28_icc_diag2
	OMP_NUM_THREADS=28 OMP_PROC_BIND=TRUE mpirun -np 8  -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./cloverleaf_mpi -OPS_DIAGS=2
	name=c2d_mpi8omp14_icc_diag2
	OMP_NUM_THREADS=14 OMP_PROC_BIND=spread mpirun -np 8  -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./cloverleaf_mpi -OPS_DIAGS=2
done

