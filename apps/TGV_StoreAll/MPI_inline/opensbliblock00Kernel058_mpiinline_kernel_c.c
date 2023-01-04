//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel058;
int ydim0_opensbliblock00Kernel058;
int xdim1_opensbliblock00Kernel058;
int ydim1_opensbliblock00Kernel058;


//user function



void opensbliblock00Kernel058_c_wrapper(
  double * restrict u0_B0_p,
  double * restrict wk6_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double u0_B0 = { u0_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel058*1 + n_z * xdim0_opensbliblock00Kernel058 * ydim0_opensbliblock00Kernel058*1, xdim0_opensbliblock00Kernel058, ydim0_opensbliblock00Kernel058};
        ptr_double wk6_B0 = { wk6_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel058*1 + n_z * xdim1_opensbliblock00Kernel058 * ydim1_opensbliblock00Kernel058*1, xdim1_opensbliblock00Kernel058, ydim1_opensbliblock00Kernel058};
        
    OPS_ACC(wk6_B0, 0,0,0) = -rc8*inv_1*(OPS_ACC(u0_B0, 2,0,0) + 8*OPS_ACC(u0_B0, -1,0,0) - OPS_ACC(u0_B0, -2,0,0) -
      8*OPS_ACC(u0_B0, 1,0,0));


      }
    }
  }
}
