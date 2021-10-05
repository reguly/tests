#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>

int main(int argc, const char** argv)
{
  int sizemax = 1<<28;
  //Size along x
  int iters = 100;

  float *A    = (float *)malloc(sizemax * sizeof(float));
  //
  // Boundary condition loops
  //
  for (int imax = 1<<10; imax <= sizemax; imax = imax<<1) {
    auto start0 = std::chrono::steady_clock::now();
    for (int iter = 0; iter < 100; iter++) {
      if (iter == 1) start0 = std::chrono::steady_clock::now();
      // set boundary conditions
#pragma omp parallel for
      for (int i = 0; i < imax; i++)
        A[i]   += 1.0;
    }

    auto start = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = start-start0;
    std::cout << elapsed_seconds.count() << "\n";
#ifdef VERBOSE
    std::cout << "Size "<< imax*4 <<" Time: " << elapsed_seconds.count() << "s\n";
    std::cout << "Achieved bandwidth " << (double)((imax) * sizeof(float) * 2 * (iters-1) / elapsed_seconds.count()) / 1000000000.0 <<"\n";
#endif
  }
  free(A);
  return 0;
}

