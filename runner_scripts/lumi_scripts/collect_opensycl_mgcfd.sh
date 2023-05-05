#!/bin/bash

source ~/source_sing_aomp
source ~/source_sing_opensycl

cd /scratch/project_465000281/Rotor37_8M

# ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_atomics -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_atomics_8M
# ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_atomics -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_atomics_8M
# ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_atomics -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_atomics_8M
# ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_atomics -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_atomics_8M
# omniperf profile -n mgcfd_opensycl_atomics -- ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_atomics -i input-mgcfd.dat OP_BLOCK_SIZE=256

# ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_hier -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_hier_8M
# ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_hier -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_hier_8M
# ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_hier -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_hier_8M
# ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_hier -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_hier_8M
# omniperf profile -n mgcfd_opensycl_hier -- ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_hier -i input-mgcfd.dat OP_BLOCK_SIZE=256

## DIDN"T WORK
#~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_hier_stage -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_hier_stage_8M
#~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_hier_stage -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_hier_stage_8M
#~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_hier_stage -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_hier_stage_8M
#~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_hier_stage -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_hier_stage_8M
#omniperf profile -n mgcfd_opensycl_hier_stage -- ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_hier_stage -i input-mgcfd.dat OP_BLOCK_SIZE=256

~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_global -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_global_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_global -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_global_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_global -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_global_8M
~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_global -i input-mgcfd.dat OP_BLOCK_SIZE=256 >> ~/results_mi250x/mgcfd_sycl_opensycl_global_8M
omniperf profile -n mgcfd_opensycl_global -- ~/MG-CFD-app-OP2/bin/mgcfd_sycl_opensycl_global -i input-mgcfd.dat OP_BLOCK_SIZE=256
