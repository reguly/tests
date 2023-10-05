#!/bin/bash
set -x

if [ -n "$GPU" ]; then
        BS_X=32
        BS_Z=4
        BS_Y=4
        if [[ "${NV_ARCH}" == "Hopper" ]]; then
        BS_X=64
        BS_Y=2
        BS_Z=1
        fi
fi
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	if [ -n "$CPUTEST" ]; then
	OMP_NUM_THREADS=1 mpirun -np $logical_cores -bind-to hwthread ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2>> rtm_soa_mpi"$logical_cores"_diag2
  if [ "$logical_cores" -ne "$physical_cores" ]; then
	OMP_NUM_THREADS=1 mpirun -np $physical_cores -bind-to core ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2>> rtm_soa_mpi"$physical_cores"_diag2
	OMP_PROC_BIND=TRUE OMP_NUM_THREADS=$threads_per_numa mpirun -np $numa_domains $bind_numa ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 >> rtm_soa_mpi"$numa_domains"omp"$threads_per_numa"_diag2
  fi	
	OMP_PROC_BIND=spread OMP_NUM_THREADS=$physical_cores_per_numa mpirun -np $numa_domains $bind_numa ./rtm_mpi -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 >> rtm_soa_mpi"$numa_domains"omp"$physical_cores_per_numa"_diag2
	fi
	if [ -n "$SYCL" ]; then
	mpirun -np $numa_domains $bind_numa ./rtm_mpi_sycl_flat -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> rtm_soa_mpisycl_flat_diag2
	mpirun -np $numa_domains $bind_numa ./rtm_mpi_sycl_ndrange -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_Z=$BS_Z OPS_BLOCK_SIZE_Y=$BS_Y OPS_BLOCK_SIZE_X=$BS_X >> rtm_soa_mpisycl_ndrange_diag2
	fi
	if [ -n "$ACCEL" ]; then
	./rtm_"$ACCEL" -sizex=320 -sizey=320 -sizez=320 -iters=20 -OPS_DIAGS=2 $ACCEL_FLAGS OPS_BLOCK_SIZE_X=$BS_X OPS_BLOCK_SIZE_Z=$BS_Z OPS_BLOCK_SIZE_Y=$BS_Y >> rtm_"$ACCEL"_diag2
	fi
done
