#!/bin/bash
set -x
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
	OMP_NUM_THREADS=1 mpirun -np 224 -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi_vec -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpivec224_diag2
	OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core ../MG-CFD-app-OP2/bin/mgcfd_mpi_vec -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpivec112_diag2
	OMP_NUM_THREADS=1 mpirun -np 224 -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpi224_diag2
	OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 >> mgcfd_mpi112_diag2
	OMP_NUM_THREADS=14 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8omp14_part4096_diag2
	OMP_PROC_BIND=spread OMP_NUM_THREADS=28 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8omp28_part4096_diag2
	mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_global_aos    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_global_aos
	mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_aos              -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_scalar_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_soa  -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_scalar_soa
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_global_soa    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_global_soa
	mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_blockloop_aos    -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_scalar_blockloop_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_soa  -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_soa
	mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_aos      -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_blockloop_soa  -i input-mgcfd.dat -m ptscotch OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi8_sycl_hier_scalar_blockloop_soa
#	OMP_NUM_THREADS=1 mpirun -np 144 -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi_vec -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 >> mgcfd_mpivec144_diag2
#	OMP_NUM_THREADS=1 mpirun -np 72 -bind-to core ../MG-CFD-app-OP2/bin/mgcfd_mpi_vec -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 >> mgcfd_mpivec72_diag2
#	OMP_NUM_THREADS=1 mpirun -np 144 -bind-to hwthread ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 >> mgcfd_mpi144_diag2
#	OMP_NUM_THREADS=1 mpirun -np 72 -bind-to core ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 >> mgcfd_mpi72_diag2
#	OMP_NUM_THREADS=72 OMP_PROC_BIND=TRUE mpirun -np 2 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi2omp72_part4096_diag2
#	OMP_PROC_BIND=spread OMP_NUM_THREADS=36 OMP_PROC_BIND=TRUE mpirun -np 2 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi2omp36_part4096_diag2
#	mpirun -np 2 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_global_aos    -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi2_sycl_global_aos
#	mpirun -np 2 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_aos              -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi2_sycl_hier_scalar_aos
#	OP_AUTO_SOA=1 mpirun -np 2 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_soa  -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi2_sycl_hier_scalar_soa
#	OP_AUTO_SOA=1 mpirun -np 2 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_global_soa    -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi2_sycl_global_soa
#	mpirun -np 2 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_blockloop_aos    -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi2_sycl_hier_scalar_blockloop_aos
#	OP_AUTO_SOA=1 mpirun -np 2 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_soa  -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi2_sycl_hier_soa
#	mpirun -np 2 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_aos      -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi2_sycl_hier_aos
#	OP_AUTO_SOA=1 mpirun -np 2 -bind-to numa ../MG-CFD-app-OP2/bin/mgcfd_mpi_sycl_hier_scalar_blockloop_soa  -i input-mgcfd.dat -m parmetis -r kway OP_TEST_FREQ=1000 OP_PART_SIZE=4096 >> mgcfd_mpi2_sycl_hier_scalar_blockloop_soa

done
