#!/bin/bash
set -x
#OPS_FLAT=1 make cloverleaf_mpi_sycl -B
#mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_flat
#OPS_CPU=1 make cloverleaf_mpi_sycl -B
#mv cloverleaf_mpi_sycl cloverleaf_mpi_sycl_ndrange
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ./volna_mpi_vec Problem.h5 0 old-format >> volna_mpivec_diag2
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ./volna_mpi_vec Problem.h5 0 old-format OP_PARTIAL_EXCHANGES=1 OP_TEST_FREQ=1000 >> volna_mpivec_partial_test_diag2
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ./volna_mpi Problem.h5 0 old-format  >> volna_mpi_diag2
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ./volna_mpi Problem.h5 0 old-format OP_PARTIAL_EXCHANGES=1 OP_TEST_FREQ=1000 >> volna_mpi_partial_test_diag2
	#OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np $numa_domains $bind_numa ./volna_mpi_openmp Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi"$numa_domains"omp24_part4096_diag2
	#OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np $numa_domains $bind_numa ./volna_mpi_openmp Problem.h5 0 old-format OP_PART_SIZE=4096 OP_PARTIAL_EXCHANGES=1 >> volna_mpi"$numa_domains"omp24_part4096_partial_diag2
	OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np 1 numactl --cpunodebind=0 ./volna_mpi_openmp Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi1omp24_part4096_diag2
	OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np 1 numactl --cpunodebind=0 ./volna_mpi_openmp Problem.h5 0 old-format OP_PART_SIZE=4096 OP_PARTIAL_EXCHANGES=1 >> volna_mpi1omp24_part4096_partial_diag2
done
