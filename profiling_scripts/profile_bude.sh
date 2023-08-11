
#!/bin/bash
set -x
export OMP_PROC_BIND=close
array=( hotspots hpc-performance performance-snapshot uarch-exploration memory-access threading )
for test in "${array[@]}"
do
	cd openmp
	name=bude_icx_omp"$logical_cores"_diag2
	vtune -collect "${test}" -start-paused -data-limit=0 -r "${name}_${test}" ./bude_icx_omp -i 100  >> profile_"$name"
	name=bude_icx_omp"$physical_cores"_diag2
	OMP_NUM_THREADS=$physical_cores OMP_PROC_BIND=close vtune -collect "${test}" -start-paused -data-limit=0 -r "${name}_${test}" ./bude_icx_omp -i 100 >> profile_"$name"
	cd ..
	cd sycl
	name=bude_sycl_flat_diag2
	vtune -collect "${test}" -start-paused -data-limit=0 -r "${name}_${test}" ./bude_sycl -d 1 -i 100 -w 0 >> profile_"$name"
	name=bude_sycl_ndrange_diag2
	vtune -collect "${test}" -start-paused -data-limit=0 -r "${name}_${test}" ./bude_sycl -d 1 -i 100 -w 256 >> profile_"$name"
	cd ..
done

