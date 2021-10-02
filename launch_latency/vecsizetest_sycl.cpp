#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <iostream>

#include <CL/sycl.hpp>

using namespace cl::sycl;
using namespace std;
int main(int argc, const char** argv)
{
  int sizemax = 1<<28;
  //Size along x
  int iters = 100;

  float *A    = (float *)malloc(sizemax * sizeof(float));

  {
#ifdef CPU
    cpu_selector device_selector;
#else
    gpu_selector device_selector;
#endif
    queue q(device_selector);
    buffer  Ab(A, range(sizemax));

    for (int imax = 1<<10; imax <= sizemax; imax = imax<<1) {
      auto start0 = std::chrono::steady_clock::now();
      for (int iter = 0; iter < iters; iter++) {
        if (iter == 1) {q.wait_and_throw(); start0 = std::chrono::steady_clock::now();}

        // set boundary conditions
        q.submit([&](handler &h) {
            accessor A(Ab, h);
            h.parallel_for<class stencil>(range<1>(imax),[=](id<1> it) {
                int i = it.get(0);
                A[i]   += 1.0;
                });});
#ifdef WAIT
        q.wait_and_throw();
#endif
      }
      q.wait_and_throw();
      auto start = std::chrono::steady_clock::now();
      std::chrono::duration<double> elapsed_seconds = start-start0;
      std::cout << "Size "<< imax*4 <<" Time: " << elapsed_seconds.count() << "s\n";
      std::cout << "Achieved bandwidth " << (double)((imax) * sizeof(float) * 2 * (iters-1) / elapsed_seconds.count()) / 1000000000.0 <<"\n";
    }
  }
  free(A);
  return 0;
}

