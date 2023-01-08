#!/bin/bash
set -x
for j in {1..4}
do
	 ../MG-CFD-app-OP2-sp/bin/mgcfd_sycl_global_aos -i input-mgcfd.dat OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> mgcfd_sycl1_global_aos
	 OP_AUTO_SOA=1 ../MG-CFD-app-OP2-sp/bin/mgcfd_sycl_global_soa -i input-mgcfd.dat OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> mgcfd_sycl1_global_soa
	OP_AUTO_SOA=1  ../MG-CFD-app-OP2-sp/bin/mgcfd_sycl_hier_soa  -i input-mgcfd.dat OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> mgcfd_sycl1_hier_soa
	 ../MG-CFD-app-OP2-sp/bin/mgcfd_sycl_hier_aos   -i input-mgcfd.dat OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> mgcfd_sycl1_hier_aos
	OP_AUTO_SOA=1  ../MG-CFD-app-OP2-sp/bin/mgcfd_sycl_atomics_soa  -i input-mgcfd.dat OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> mgcfd_sycl1_atomics_soa
	 ../MG-CFD-app-OP2-sp/bin/mgcfd_sycl_atomics_aos   -i input-mgcfd.dat OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> mgcfd_sycl1_atomics_aos

done
