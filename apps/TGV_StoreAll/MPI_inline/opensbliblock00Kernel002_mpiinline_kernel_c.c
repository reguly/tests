//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel002;
int ydim0_opensbliblock00Kernel002;
int xdim1_opensbliblock00Kernel002;
int ydim1_opensbliblock00Kernel002;


//user function



void opensbliblock00Kernel002_c_wrapper(
  double * restrict rhou2_B0_p,
  double * restrict wk0_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double rhou2_B0 = { rhou2_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel002*1 + n_z * xdim0_opensbliblock00Kernel002 * ydim0_opensbliblock00Kernel002*1, xdim0_opensbliblock00Kernel002, ydim0_opensbliblock00Kernel002};
        ptr_double wk0_B0 = { wk0_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel002*1 + n_z * xdim1_opensbliblock00Kernel002 * ydim1_opensbliblock00Kernel002*1, xdim1_opensbliblock00Kernel002, ydim1_opensbliblock00Kernel002};
        
    OPS_ACC(wk0_B0, 0,0,0) = inv_0*(-rc7*OPS_ACC(rhou2_B0, 0,-1,0) + (rc7)*OPS_ACC(rhou2_B0, 0,1,0) -
      rc8*OPS_ACC(rhou2_B0, 0,2,0) + (rc8)*OPS_ACC(rhou2_B0, 0,-2,0));


      }
    }
  }
}
