#
# The following environment variables should be predefined:
#
# OPS_COMPILER (gnu,intel,etc)
#

include $(OPS_INSTALL_PATH)/../makefiles/Makefile.common
include $(OPS_INSTALL_PATH)/../makefiles/Makefile.mpi
include $(OPS_INSTALL_PATH)/../makefiles/Makefile.cuda
#USE_HDF5=1
include $(OPS_INSTALL_PATH)/../makefiles/Makefile.hdf5




HEADERS=rtm_kernel.h

OPS_FILES=rtm.cpp

OPS_GENERATED=rtm_ops.cpp

OTHER_FILES=


APP=rtm
MAIN_SRC=rtm

include $(OPS_INSTALL_PATH)/../makefiles/Makefile.c_app_legacy
