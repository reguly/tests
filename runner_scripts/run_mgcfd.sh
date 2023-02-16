#!/bin/bash
set -x
if [[ -v REBUILD ]]; then
	cd $BASEDIR/MG-CFD-app-OP2
	./translate2op2.sh
#	export OP2_COMPILER=intel
#	make mpi mpi_vec mpi_openmp
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
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_scalar_blockloop_aos

	OP2_SCALAR=1 OP2_BLOCKLOOP=1 OP_AUTO_SOA=1 ./translate2op2.sh
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_hier_scalar_blockloop_soa

	OP2_ATOMICS=1 ./translate2op2.sh
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_atomics_aos

	OP2_ATOMICS=1 OP_AUTO_SOA=1 ./translate2op2.sh
	make mpi_sycl
	mv bin/mgcfd_mpi_sycl bin/mgcfd_mpi_sycl_atomics_soa

fi
cd $BASEDIR/Rotor37_8M
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	# OMP_NUM_THREADS=1 mpirun -np 224 -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi_vec -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpivec224_diag2
	# OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core ../MG-CFD-app-OP2/bin/mgcfd_mpi_vec -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpivec112_diag2
	# OMP_NUM_THREADS=1 mpirun -np 224 -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpi224_diag2
	# OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpi112_diag2
	# OMP_NUM_THREADS=14 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8omp14_part4096_diag2
	# OMP_PROC_BIND=spread OMP_NUM_THREADS=28 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8omp28_part4096_diag2
	mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_global_aos    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_global_aos
	mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_aos              -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_scalar_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_soa  -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_scalar_soa
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_global_soa    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_global_soa
	mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_blockloop_aos    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_scalar_blockloop_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_soa  -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_soa
	mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_aos      -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_blockloop_soa  -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_scalar_blockloop_soa

done
