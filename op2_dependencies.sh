#!/bin/bash
BASE=$1
cd hdf5-1.12.2/
CC=mpicc CXX=mpicxx ./configure --enable-parallel --prefix=$BASE/hdf5
make install -j20
cd ..
echo "export HDF5_INSTALL_PATH=${BASE}/hdf5"
echo "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HDF5_INSTALL_PATH/lib"
#wget http://glaros.dtc.umn.edu/gkhome/fetch/sw/parmetis/parmetis-4.0.3.tar.gz
