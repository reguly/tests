cd ~/tests
#./build_cpu.sh
#./build_sycl.sh
SYCL=1 ./run_all.sh
cd ~/results_grr/default
find ../../tests/ -name "*diag2" -exec mv {} . \;
cd ~/tests
export TEST_ZMM=1
./build_cpu.sh
./run_all.sh
cd ~/results_grr/zmm_high
find ../../tests/ -name "*diag2" -exec mv {} . \;
