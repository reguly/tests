all: vecsizetest_sycl_cpu_wait vecsizetest_sycl_cpu_nowait vecsizetest_sycl_gpu_wait vecsizetest_sycl_gpu_nowait vecsizetest_omp vecsizetest_ompoffload_cpu vecsizetest_ompoffload_gpu

vecsizetest_sycl_cpu_wait: vecsizetest_sycl.cpp Makefile
	dpcpp -O3 -fsycl -DWAIT -DCPU vecsizetest_sycl.cpp -o $@

vecsizetest_sycl_cpu_nowait: vecsizetest_sycl.cpp Makefile
	dpcpp -O3 -fsycl -DCPU vecsizetest_sycl.cpp -o $@

vecsizetest_sycl_gpu_wait: vecsizetest_sycl.cpp Makefile
	dpcpp -O3 -fsycl -DWAIT vecsizetest_sycl.cpp -o $@

vecsizetest_sycl_gpu_nowait: vecsizetest_sycl.cpp Makefile
	dpcpp -O3 -fsycl vecsizetest_sycl.cpp -o $@

vecsizetest_omp: vecsizetest_omp.cpp Makefile
	dpcpp -O3 -fopenmp vecsizetest_omp.cpp -o $@

vecsizetest_ompoffload_cpu: vecsizetest_ompoffload.cpp Makefile
	dpcpp -O3 -fopenmp vecsizetest_ompoffload.cpp -o $@

vecsizetest_ompoffload_gpu: vecsizetest_ompoffload.cpp Makefile
	dpcpp -O3 -fiopenmp -fopenmp-targets=spir64 vecsizetest_ompoffload.cpp -o $@

clean:
	rm vecsizetest_sycl_cpu_wait vecsizetest_sycl_cpu_nowait vecsizetest_sycl_gpu_wait vecsizetest_sycl_gpu_nowait vecsizetest_omp vecsizetest_ompoffload_cpu vecsizetest_ompoffload_gpu
