#!/bin/bash

source ~/source_rocm
cd /scratch/project_465000281/Rotor37_8M
omniperf profile -n mgcfd_hip_hierstage_8M -- ~/MG-CFD-app-OP2/bin/mgcfd_hip_hier_stage -i input-mgcfd.dat OP_PART_SIZE=256 OP_BLOCK_SIZE=256
omniperf profile -n mgcfd_hip_hier_8M -- ~/MG-CFD-app-OP2/bin/mgcfd_hip_hier -i input-mgcfd.dat OP_PART_SIZE=512 OP_BLOCK_SIZE=512

