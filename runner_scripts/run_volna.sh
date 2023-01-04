#!/bin/bash
set -x
cd ~/volna/sp
if [[ -v REBUILD ]]; then
	export OP2_COMPILER=intel
#	make volna_mpi_genseq volna_mpi_vec volna_mpi_openmp
#	mv volna_mpi_genseq volna_mpi
	export OP2_COMPILER=intel-sycl
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_aos

	OP_AUTO_SOA=1 ./translate2op2.sh
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_soa

	OP2_COLOR2=1 ./translate2op2.sh
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_global_aos

	OP2_COLOR2=1 OP_AUTO_SOA=1 ./translate2op2.sh
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_global_soa

	OP2_SCALAR=1 ./translate2op2.sh
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_aos

	OP2_SCALAR=1 OP_AUTO_SOA=1 ./translate2op2.sh
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_soa

	OP2_SCALAR=1 OP2_BLOCKLOOP=1 ./translate2op2.sh
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_blockloop_aos

	OP2_SCALAR=1 OP2_BLOCKLOOP=1 OP_AUTO_SOA=1 ./translate2op2.sh
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_blockloop_soa
fi
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	OMP_NUM_THREADS=1 mpirun -np 224 -bind-to hwthread ./volna_mpi_vec Problem.h5 0 old-format OP_TEST_FREQ=1000 >> volna_mpivec224_diag2
	OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core ./volna_mpi_vec Problem.h5 0 old-format OP_TEST_FREQ=1000 >> volna_mpivec112_diag2
	OMP_NUM_THREADS=1 mpirun -np 224 -bind-to hwthread ./volna_mpi Problem.h5 0 old-format OP_TEST_FREQ=1000 >> volna_mpi224_diag2
	OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core ./volna_mpi Problem.h5 0 old-format OP_TEST_FREQ=1000 >> volna_mpi112_diag2
	OMP_NUM_THREADS=28 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa ./volna_mpi_openmp Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi8omp28_part4096_diag2
	OMP_NUM_THREADS=14 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa ./volna_mpi_openmp Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi8omp14_part4096_diag2
	mpirun -np 8 -bind-to numa ./volna_mpi_sycl_global_aos    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi8_sycl_global_aos
	mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_scalar_aos              Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_scalar_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_scalar_soa  Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_scalar_soa
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ./volna_mpi_sycl_global_soa    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi8_sycl_global_soa
	mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_scalar_blockloop_aos    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_scalar_blockloop_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_soa  Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_soa
	mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_aos      Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_scalar_blockloop_soa  Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_scalar_blockloop_soa

done
