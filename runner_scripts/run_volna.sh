#!/bin/bash
set -x
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	if [ -n "$CPUTEST" ]; then
	OMP_NUM_THREADS=1 mpirun $mpirunflags -np $logical_cores $bind_hwthread ./volna_mpi_vec Problem.h5 0 old-format OP_TEST_FREQ=1000 >> volna_mpivec"$logical_cores"_diag2

  if [ "$logical_cores" -ne "$physical_cores" ]; then
	OMP_NUM_THREADS=1 mpirun $mpirunflags -np $physical_cores $bind_core ./volna_mpi_vec Problem.h5 0 old-format OP_TEST_FREQ=1000 >> volna_mpivec"$physical_cores"_diag2
	OMP_NUM_THREADS=1 mpirun $mpirunflags -np $logical_cores $bind_hwthread ./volna_mpi Problem.h5 0 old-format OP_TEST_FREQ=1000 >> volna_mpi"$logical_cores"_diag2
  fi
	OMP_NUM_THREADS=1 mpirun $mpirunflags -np $physical_cores $bind_core ./volna_mpi Problem.h5 0 old-format OP_TEST_FREQ=1000 >> volna_mpi"$physical_cores"_diag2
	OMP_NUM_THREADS=$threads_per_numa OMP_PROC_BIND=TRUE mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_openmp Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi"$numa_domains"omp"$threads_per_numa"_part4096_diag2
  if [ "$logical_cores" -ne "$physical_cores" ]; then
	OMP_NUM_THREADS=$physical_cores_per_numa OMP_PROC_BIND=TRUE mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_openmp Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi"$numa_domains"omp"$physical_cores_per_numa"_part4096_diag2
  fi
	fi
	if [ -n "$SYCL" ]; then
	mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_sycl_atomics_aos    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_mpi"$numa_domains"_sycl_atomics_aos_diag2
	mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_sycl_atomics_soa    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_mpi"$numa_domains"_sycl_atomics_soa_diag2
	mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_sycl_global_aos    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_mpi"$numa_domains"_sycl_global_aos_diag2
#	mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_sycl_hier_scalar_aos              Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_mpi"$numa_domains"_sycl_hier_scalar_aos_diag2
#	OP_AUTO_SOA=1 mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_sycl_hier_scalar_soa  Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_mpi"$numa_domains"_sycl_hier_scalar_soa_diag2
	OP_AUTO_SOA=1 mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_sycl_global_soa    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_mpi"$numa_domains"_sycl_global_soa_diag2
#	mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_sycl_hier_scalar_blockloop_aos    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_mpi"$numa_domains"_sycl_hier_scalar_blockloop_aos_diag2
	OP_AUTO_SOA=1 mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_sycl_hier_soa  Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_mpi"$numa_domains"_sycl_hier_soa_diag2
	mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_sycl_hier_aos      Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_mpi"$numa_domains"_sycl_hier_aos_diag2
#	OP_AUTO_SOA=1 mpirun $mpirunflags -np $numa_domains $bind_numa ./volna_mpi_sycl_hier_scalar_blockloop_soa  Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_mpi"$numa_domains"_sycl_hier_scalar_blockloop_soa_diag2
	fi

	if [ -n "$ACCEL" ]; then
	./volna_"$ACCEL"    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> volna_"$ACCEL"_diag2
	fi
done
