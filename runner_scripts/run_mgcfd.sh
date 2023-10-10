#!/bin/bash
set -x
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	if [ -n "$CPUTEST" ]; then
	OMP_NUM_THREADS=1 mpirun -np $logical_cores -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi_vec -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpivec"$logical_cores"_diag2
  if [ "$logical_cores" -ne "$physical_cores" ]; then
	OMP_NUM_THREADS=1 mpirun -np $physical_cores -bind-to core ../MG-CFD-app-OP2/bin/mgcfd_mpi_vec -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpivec"$physical_cores"_diag2
	OMP_NUM_THREADS=1 mpirun -np $logical_cores -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpi"$logical_cores"_diag2
  fi
	OMP_NUM_THREADS=1 mpirun -np $physical_cores -bind-to core ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpi"$physical_cores"_diag2
	OMP_NUM_THREADS=$physical_cores_per_numa OMP_PROC_BIND=TRUE mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"omp"$physical_cores_per_numa"_part4096_diag2
  if [ "$logical_cores" -ne "$physical_cores" ]; then
	OMP_PROC_BIND=spread OMP_NUM_THREADS=$threads_per_numa OMP_PROC_BIND=TRUE mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"omp"$threads_per_numa"_part4096_diag2
  fi
	fi
	if [ -n "$SYCL" ]; then
	 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_atomics_aos    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> mgcfd_mpi"$numa_domains"_sycl_atomics_aos_diag2
	 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_atomics_soa    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> mgcfd_mpi"$numa_domains"_sycl_atomics_soa_diag2
	 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_global_aos    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> mgcfd_mpi"$numa_domains"_sycl_global_aos_diag2
#	 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_aos              -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> mgcfd_mpi"$numa_domains"_sycl_hier_scalar_aos_diag2
#	 OP_AUTO_SOA=1 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_soa  -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> mgcfd_mpi"$numa_domains"_sycl_hier_scalar_soa_diag2
	 OP_AUTO_SOA=1 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_global_soa    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> mgcfd_mpi"$numa_domains"_sycl_global_soa_diag2
#	 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_blockloop_aos    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> mgcfd_mpi"$numa_domains"_sycl_hier_scalar_blockloop_aos_diag2
	OP_AUTO_SOA=1 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_soa  -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> mgcfd_mpi"$numa_domains"_sycl_hier_soa_diag2
	mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_aos      -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> mgcfd_mpi"$numa_domains"_sycl_hier_aos_diag2
#	 OP_AUTO_SOA=1 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_blockloop_soa  -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256 >> mgcfd_mpi"$numa_domains"_sycl_hier_scalar_blockloop_soa_diag2
	fi
	if [ -n "$ACCEL" ]; then
		../MG-CFD-app-OP2/bin/mgcfd_"$ACCEL"    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=256 OP_BLOCK_SIZE=256  >> mgcfd_"$ACCEL"_diag2
	fi
done
