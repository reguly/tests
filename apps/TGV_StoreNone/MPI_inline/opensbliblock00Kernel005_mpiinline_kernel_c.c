//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel005;
int ydim0_opensbliblock00Kernel005;
int xdim1_opensbliblock00Kernel005;
int ydim1_opensbliblock00Kernel005;
int xdim2_opensbliblock00Kernel005;
int ydim2_opensbliblock00Kernel005;


//user function



void opensbliblock00Kernel005_c_wrapper(
  double * restrict rho_B0_p,
  double * restrict rhou1_B0_p,
  double * restrict u1_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double rho_B0 = { rho_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel005*1 + n_z * xdim0_opensbliblock00Kernel005 * ydim0_opensbliblock00Kernel005*1, xdim0_opensbliblock00Kernel005, ydim0_opensbliblock00Kernel005};
        const ptr_double rhou1_B0 = { rhou1_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel005*1 + n_z * xdim1_opensbliblock00Kernel005 * ydim1_opensbliblock00Kernel005*1, xdim1_opensbliblock00Kernel005, ydim1_opensbliblock00Kernel005};
        ptr_double u1_B0 = { u1_B0_p + n_x*1 + n_y * xdim2_opensbliblock00Kernel005*1 + n_z * xdim2_opensbliblock00Kernel005 * ydim2_opensbliblock00Kernel005*1, xdim2_opensbliblock00Kernel005, ydim2_opensbliblock00Kernel005};
        
   OPS_ACC(u1_B0, 0,0,0) = OPS_ACC(rhou1_B0, 0,0,0)/OPS_ACC(rho_B0, 0,0,0);


      }
    }
  }
}
