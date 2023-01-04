#!/bin/bash
source /glob/development-tools/versions/oneapi/2022.1.2/oneapi/setvars.sh --force
source ~/source_intel
source ~/source_ompi
${@}
