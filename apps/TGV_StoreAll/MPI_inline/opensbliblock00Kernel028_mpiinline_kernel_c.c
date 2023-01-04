//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel028;
int ydim0_opensbliblock00Kernel028;
int xdim1_opensbliblock00Kernel028;
int ydim1_opensbliblock00Kernel028;


//user function



void opensbliblock00Kernel028_c_wrapper(
  double * restrict rhou0_B0_p,
  double * restrict wk18_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double rhou0_B0 = { rhou0_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel028*1 + n_z * xdim0_opensbliblock00Kernel028 * ydim0_opensbliblock00Kernel028*1, xdim0_opensbliblock00Kernel028, ydim0_opensbliblock00Kernel028};
        ptr_double wk18_B0 = { wk18_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel028*1 + n_z * xdim1_opensbliblock00Kernel028 * ydim1_opensbliblock00Kernel028*1, xdim1_opensbliblock00Kernel028, ydim1_opensbliblock00Kernel028};
        
    OPS_ACC(wk18_B0, 0,0,0) = inv_1*((rc8)*OPS_ACC(rhou0_B0, -2,0,0) - rc7*OPS_ACC(rhou0_B0, -1,0,0) +
      (rc7)*OPS_ACC(rhou0_B0, 1,0,0) - rc8*OPS_ACC(rhou0_B0, 2,0,0));


      }
    }
  }
}
