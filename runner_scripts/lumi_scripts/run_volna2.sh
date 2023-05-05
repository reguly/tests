#!/bin/bash
set -x
if [[ -v REBUILD ]]; then
	cd $BASEDIR/volna/sp
	python2 ~/OP2-Common-sycl/translator/c/python/op2.py volna.cpp volna_event.cpp  volna_init.cpp volna_output.cpp  volna_simulation.cpp
	#export OP2_COMPILER=intel
	#make volna_mpi_genseq volna_mpi_vec volna_mpi_openmp
	export OP2_COMPILER=intel-sycl
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_aos

	OP_AUTO_SOA=1 python2 ~/OP2-Common-sycl/translator/c/python/op2.py volna.cpp volna_event.cpp  volna_init.cpp volna_output.cpp  volna_simulation.cpp
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_soa

	OP2_COLOR2=1 python2 ~/OP2-Common-sycl/translator/c/python/op2.py volna.cpp volna_event.cpp  volna_init.cpp volna_output.cpp  volna_simulation.cpp
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_global_aos

	OP2_COLOR2=1 OP_AUTO_SOA=1 python2 ~/OP2-Common-sycl/translator/c/python/op2.py volna.cpp volna_event.cpp  volna_init.cpp volna_output.cpp  volna_simulation.cpp
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_global_soa

	OP2_SCALAR=1 python2 ~/OP2-Common-sycl/translator/c/python/op2.py volna.cpp volna_event.cpp  volna_init.cpp volna_output.cpp  volna_simulation.cpp
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_aos

	OP2_SCALAR=1 OP_AUTO_SOA=1 python2 ~/OP2-Common-sycl/translator/c/python/op2.py volna.cpp volna_event.cpp  volna_init.cpp volna_output.cpp  volna_simulation.cpp
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_soa

	OP2_SCALAR=1 OP2_BLOCKLOOP=1 python2 ~/OP2-Common-sycl/translator/c/python/op2.py volna.cpp volna_event.cpp  volna_init.cpp volna_output.cpp  volna_simulation.cpp
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_blockloop_soa

	OP2_SCALAR=1 OP2_BLOCKLOOP=1 OP_AUTO_SOA=1 python2 ~/OP2-Common-sycl/translator/c/python/op2.py volna.cpp volna_event.cpp  volna_init.cpp volna_output.cpp  volna_simulation.cpp
	make volna_mpi_sycl
	mv volna_mpi_sycl volna_mpi_sycl_hier_scalar_blockloop_soa
fi
cd $BASEDIR/volna/sp
export OMP_PROC_BIND=TRUE
for j in {1..4}
do
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ./volna_mpi_vec Problem.h5 0 old-format >> volna_mpivec_diag2
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ./volna_mpi_vec Problem.h5 0 old-format OP_PARTIAL_EXCHANGES=1 OP_TEST_FREQ=1000 >> volna_mpivec_partial_test_diag2
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ./volna_mpi Problem.h5 0 old-format >> volna_mpi_diag2
#	OMP_NUM_THREADS=1 mpirun -np 192 -bind-to hwthread ./volna_mpi Problem.h5 0 old-format OP_PARTIAL_EXCHANGES=1 OP_TEST_FREQ=1000 >> volna_mpi_partial_test_diag2
#	OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa ./volna_mpi_openmp Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi8omp24_part4096_diag2
#	OMP_NUM_THREADS=24 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa ./volna_mpi_openmp Problem.h5 0 old-format OP_PART_SIZE=4096 OP_PARTIAL_EXCHANGES=1 >> volna_mpi8omp24_part4096_partial_diag2
	mpirun -np 8 -bind-to numa ./volna_mpi_sycl_global_aos    Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi8_sycl_global_aos
	mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_scalar_aos              Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_scalar_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_scalar_soa  Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_scalar_soa
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ./volna_mpi_sycl_global_soa    Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi8_sycl_global_soa
	mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_scalar_blockloop_aos    Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_scalar_blockloop_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_soa  Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_soa
	mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_aos      Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_aos
	OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa ./volna_mpi_sycl_hier_scalar_blockloop_soa  Problem.h5 0 old-format OP_PART_SIZE=4096 >> volna_mpi8_sycl_hier_scalar_blockloop_soa

done
