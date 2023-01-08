#!/bin/bash
set -x
for j in {1..4}
do
	 ./volna_sycl_global_aos    volna_30m2.h5 0 old-format OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> volna_sycl1_global_aos
	 OP_AUTO_SOA=1 ./volna_sycl_global_soa    volna_30m2.h5 0 old-format OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> volna_sycl1_global_soa
	OP_AUTO_SOA=1  ./volna_sycl_hier_soa  volna_30m2.h5 0 old-format OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> volna_sycl1_hier_soa
	 ./volna_sycl_hier_aos      volna_30m2.h5 0 old-format OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> volna_sycl1_hier_aos

	OP_AUTO_SOA=1  ./volna_sycl_atomics_soa  volna_30m2.h5 0 old-format OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> volna_sycl1_atomics_soa
	 ./volna_sycl_atomics_aos      volna_30m2.h5 0 old-format OP_PART_SIZE=128 OP_BLOCK_SIZE=128 >> volna_sycl1_atomics_aos
done
