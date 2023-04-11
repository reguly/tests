#!/bin/bash
set -x
if [[ -v REBUILD ]]; then
	cd $BASEDIR/MG-CFD-app-OP2
	./translate2op2.sh
	export OP2_COMPILER=intel
	make mpi mpi_vec mpi_openmp
	export OP2_COMPILER=intel-sycl
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_aos

	OP_AUTO_SOA=1 ./translate2op2.sh
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_soa

	OP2_COLOR2=1 ./translate2op2.sh
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_global_aos

	OP2_COLOR2=1 OP_AUTO_SOA=1 ./translate2op2.sh
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_global_soa

	OP2_SCALAR=1 ./translate2op2.sh
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_scalar_aos

	OP2_SCALAR=1 OP_AUTO_SOA=1 ./translate2op2.sh
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_scalar_soa

	OP2_SCALAR=1 OP2_BLOCKLOOP=1 ./translate2op2.sh
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_scalar_blockloop_soa

	OP2_SCALAR=1 OP2_BLOCKLOOP=1 OP_AUTO_SOA=1 ./translate2op2.sh
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_scalar_blockloop_soa
fi
cd $BASEDIR/Rotor37_8M
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi_vec -i input-mgcfd.dat -m ptscotch >> mgcfd_mpivec_diag2
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi_vec -i input-mgcfd.dat -m ptscotch OP_PARTIAL_EXCHANGES=1 OP_TEST_FREQ=1000 >> mgcfd_mpivec_partial_test_diag2
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch >> mgcfd_mpi_diag2
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch OP_PARTIAL_EXCHANGES=1 OP_TEST_FREQ=1000 >> mgcfd_mpi_partial_test_diag2
#	OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m ptscotch OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"omp24_part4096_diag2
#	OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m ptscotch OP_PART_SIZE=4096 OP_PARTIAL_EXCHANGES=1 >> mgcfd_mpi"$numa_domains"omp24_part4096_partial_diag2
	mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_global_aos    -i input-mgcfd.dat -m ptscotch OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"_sycl_global_aos
	mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_aos              -i input-mgcfd.dat -m ptscotch OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"_sycl_hier_scalar_aos
	OP_AUTO_SOA=1 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_soa  -i input-mgcfd.dat -m ptscotch OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"_sycl_hier_scalar_soa
	OP_AUTO_SOA=1 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_global_soa    -i input-mgcfd.dat -m ptscotch OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"_sycl_global_soa
	mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_blockloop_aos    -i input-mgcfd.dat -m ptscotch OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"_sycl_hier_scalar_blockloop_aos
	OP_AUTO_SOA=1 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_soa  -i input-mgcfd.dat -m ptscotch OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"_sycl_hier_soa
	mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_aos      -i input-mgcfd.dat -m ptscotch OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"_sycl_hier_aos
	OP_AUTO_SOA=1 mpirun -np $numa_domains $bind_numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_blockloop_soa  -i input-mgcfd.dat -m ptscotch OP_PART_SIZE=4096 >> mgcfd_mpi"$numa_domains"_sycl_hier_scalar_blockloop_soa

done
