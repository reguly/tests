#!/bin/bash

source ~/source_sing_aomp
source ~/source_sing_dpcpp

cd /scratch/project_465000281/Rotor37_8M

~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_atomics -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_atomics_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_atomics -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_atomics_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_atomics -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_atomics_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_atomics -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_atomics_8M
omniperf profile -n mgcfd_dpcpp_atomics -- ~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_atomics -i input-mgcfd.dat OP_BLOCK_SIZE=256

~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_hier -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_hier_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_hier -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_hier_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_hier -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_hier_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_hier -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_hier_8M
omniperf profile -n mgcfd_dpcpp_hier -- ~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_hier -i input-mgcfd.dat OP_BLOCK_SIZE=256

#~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_hier_stage -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_hier_stage_8M
#~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_hier_stage -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_hier_stage_8M
#~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_hier_stage -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_hier_stage_8M
#~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_hier_stage -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_hier_stage_8M
#omniperf profile -n mgcfd_dpcpp_hier_stage -- ~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_hier_stage -i input-mgcfd.dat OP_BLOCK_SIZE=256

~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_global -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_global_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_global -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_global_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_global -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_global_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_global -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_dpcpp_global_8M
omniperf profile -n mgcfd_dpcpp_global -- ~/MG-CFD-app-OP2/bin/mgcfd_sycl_dpcpp_global -i input-mgcfd.dat OP_BLOCK_SIZE=256
