#!/bin/bash
set -x
if [ -n "$GPU" ]; then
        BS_X=512
        BS_Y=2
        if [[ "${NV_ARCH}" == "Hopper" || "${HIP_ARCH}" == "gfx90a" ]]; then
        BS_X=128
        BS_Y=2
        fi
fi
sed -i "s/end_step=.*/end_step=50/g" clover.in
array=( 7680 )
for i in "${array[@]}"
do
	sed -i "s/x_cells=.*/x_cells=$i/g" clover.in
	sed -i "s/y_cells=.*/y_cells=$i/g" clover.in
	for j in {1..4}
	do
		if [ -n "$CPUTEST" ]; then
		OMP_NUM_THREADS=1 mpirun  -np $logical_cores -bind-to hwthread ./cloverleaf_mpi -OPS_DIAGS=2 >> c2d_mpi"$logical_cores"_icc_diag2
  if [ "$logical_cores" -ne "$physical_cores" ]; then
		OMP_NUM_THREADS=1 mpirun  -np $physical_cores -bind-to core ./cloverleaf_mpi -OPS_DIAGS=2 >> c2d_mpi"$physical_cores"_icc_diag2
		OMP_NUM_THREADS=$threads_per_numa OMP_PROC_BIND=TRUE mpirun -np $numa_domains  $bind_numa ./cloverleaf_mpi -OPS_DIAGS=2 >> c2d_mpi"$numa_domains"omp"$threads_per_numa"_icc_diag2
  fi
		OMP_NUM_THREADS=$physical_cores_per_numa OMP_PROC_BIND=spread mpirun -np $numa_domains  $bind_numa ./cloverleaf_mpi -OPS_DIAGS=2 >> c2d_mpi"$numa_domains"omp"$physical_cores_per_numa"_icc_diag2
		fi
		if [ -n "$SYCL" ]; then
		mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_sycl_flat -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> c2d_mpisycl_flat_diag2
		mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_sycl_ndrange -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_Y=$BS_Y OPS_BLOCK_SIZE_X=$BS_X >> c2d_mpisycl_ndrange_diag2
		fi
		if [ -n "$ACCEL" ]; then
			./cloverleaf_"${ACCEL}" -OPS_DIAGS=2 OPS_BLOCK_SIZE_Y=$BS_Y OPS_BLOCK_SIZE_X=$BS_X $ACCEL_FLAGS >> c2d_"${ACCEL}"_diag2
		fi
	done
done
