set -x
cd ~/volna/sp
#array=( hotspots hpc-performance performance-snapshot uarch-exploration memory-access )
#for test in "${array[@]}"
#do
#    name=volna_mpivec224_diag2
#    OMP_NUM_THREADS=1 mpirun -np 224 -bind-to hwthread vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_vec Problem.h5 0 old-format OP_TEST_FREQ=1000 
#    name=volna_mpivec112_diag2
##    OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_vec Problem.h5 0 old-format OP_TEST_FREQ=1000 
#    name=volna_mpi224_diag2
#    OMP_NUM_THREADS=1 mpirun -np 224 -bind-to hwthread vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi Problem.h5 0 old-format OP_TEST_FREQ=1000 
#    name=volna_mpi112_diag2
#    OMP_NUM_THREADS=1 mpirun -np 112 -bind-to core vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi Problem.h5 0 old-format OP_TEST_FREQ=1000 
#done
#array=( hotspots hpc-performance performance-snapshot uarch-exploration memory-access threading )
array=( hpc-performance performance-snapshot uarch-exploration memory-access threading )
for test in "${array[@]}"
do
    name=volna_mpi8omp28_part4096_diag2
    OMP_NUM_THREADS=28 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_openmp Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 
    name=volna_mpi8omp14_part4096_diag2
    OMP_NUM_THREADS=14 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_openmp Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 
#    name=volna_mpi8_sycl_global_aos
#    mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_sycl_global_aos    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 
    name=volna_mpi8_sycl_hier_scalar_aos
    mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_sycl_hier_scalar_aos              Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 
    name=volna_mpi8_sycl_hier_scalar_soa
    OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_sycl_hier_scalar_soa  Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 
#    name=volna_mpi8_sycl_global_soa
#    OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_sycl_global_soa    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 
    name=volna_mpi8_sycl_hier_scalar_blockloop_aos
    mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_sycl_hier_scalar_blockloop_aos    Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 
    name=volna_mpi8_sycl_hier_soa
    OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_sycl_hier_soa  Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 
    name=volna_mpi8_sycl_hier_aos
    mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_sycl_hier_aos      Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 
    name=volna_mpi8_sycl_hier_scalar_blockloop_soa
    OP_AUTO_SOA=1 mpirun -np 8 -bind-to numa vtune -collect "${test}" -data-limit=0 -r "${name}_${test}" ./volna_mpi_sycl_hier_scalar_blockloop_soa  Problem.h5 0 old-format OP_TEST_FREQ=1000 OP_PART_SIZE=4096 
done
