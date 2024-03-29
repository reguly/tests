//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel037;
int ydim0_opensbliblock00Kernel037;
int xdim1_opensbliblock00Kernel037;
int ydim1_opensbliblock00Kernel037;


//user function



void opensbliblock00Kernel037_c_wrapper(
  double * restrict p_B0_p,
  double * restrict wk26_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double p_B0 = { p_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel037*1 + n_z * xdim0_opensbliblock00Kernel037 * ydim0_opensbliblock00Kernel037*1, xdim0_opensbliblock00Kernel037, ydim0_opensbliblock00Kernel037};
        ptr_double wk26_B0 = { wk26_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel037*1 + n_z * xdim1_opensbliblock00Kernel037 * ydim1_opensbliblock00Kernel037*1, xdim1_opensbliblock00Kernel037, ydim1_opensbliblock00Kernel037};
        
    OPS_ACC(wk26_B0, 0,0,0) = inv_2*(-rc7*OPS_ACC(p_B0, 0,0,-1) - rc8*OPS_ACC(p_B0, 0,0,2) +
      (rc8)*OPS_ACC(p_B0, 0,0,-2) + (rc7)*OPS_ACC(p_B0, 0,0,1));


      }
    }
  }
}
