//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel083;
int ydim0_opensbliblock00Kernel083;
int xdim1_opensbliblock00Kernel083;
int ydim1_opensbliblock00Kernel083;
int xdim2_opensbliblock00Kernel083;
int ydim2_opensbliblock00Kernel083;
int xdim3_opensbliblock00Kernel083;
int ydim3_opensbliblock00Kernel083;
int xdim4_opensbliblock00Kernel083;
int ydim4_opensbliblock00Kernel083;


//user function



void opensbliblock00Kernel083_c_wrapper(
  double * restrict rhoE_B0_p,
  double * restrict rhou0_B0_p,
  double * restrict rho_B0_p,
  double * restrict rhou2_B0_p,
  double * restrict rhou1_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        ptr_double rhoE_B0 = { rhoE_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel083*1 + n_z * xdim0_opensbliblock00Kernel083 * ydim0_opensbliblock00Kernel083*1, xdim0_opensbliblock00Kernel083, ydim0_opensbliblock00Kernel083};
        ptr_double rhou0_B0 = { rhou0_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel083*1 + n_z * xdim1_opensbliblock00Kernel083 * ydim1_opensbliblock00Kernel083*1, xdim1_opensbliblock00Kernel083, ydim1_opensbliblock00Kernel083};
        ptr_double rho_B0 = { rho_B0_p + n_x*1 + n_y * xdim2_opensbliblock00Kernel083*1 + n_z * xdim2_opensbliblock00Kernel083 * ydim2_opensbliblock00Kernel083*1, xdim2_opensbliblock00Kernel083, ydim2_opensbliblock00Kernel083};
        ptr_double rhou2_B0 = { rhou2_B0_p + n_x*1 + n_y * xdim3_opensbliblock00Kernel083*1 + n_z * xdim3_opensbliblock00Kernel083 * ydim3_opensbliblock00Kernel083*1, xdim3_opensbliblock00Kernel083, ydim3_opensbliblock00Kernel083};
        ptr_double rhou1_B0 = { rhou1_B0_p + n_x*1 + n_y * xdim4_opensbliblock00Kernel083*1 + n_z * xdim4_opensbliblock00Kernel083 * ydim4_opensbliblock00Kernel083*1, xdim4_opensbliblock00Kernel083, ydim4_opensbliblock00Kernel083};
        
   OPS_ACC(rho_B0, 0,-1,0) = OPS_ACC(rho_B0, 0,1,0);

   OPS_ACC(rhou0_B0, 0,-1,0) = OPS_ACC(rhou0_B0, 0,1,0);

   OPS_ACC(rhou1_B0, 0,-1,0) = -1.0*OPS_ACC(rhou1_B0, 0,1,0);

   OPS_ACC(rhou2_B0, 0,-1,0) = OPS_ACC(rhou2_B0, 0,1,0);

   OPS_ACC(rhoE_B0, 0,-1,0) = OPS_ACC(rhoE_B0, 0,1,0);

   OPS_ACC(rho_B0, 0,-2,0) = OPS_ACC(rho_B0, 0,2,0);

   OPS_ACC(rhou0_B0, 0,-2,0) = OPS_ACC(rhou0_B0, 0,2,0);

   OPS_ACC(rhou1_B0, 0,-2,0) = -1.0*OPS_ACC(rhou1_B0, 0,2,0);

   OPS_ACC(rhou2_B0, 0,-2,0) = OPS_ACC(rhou2_B0, 0,2,0);

   OPS_ACC(rhoE_B0, 0,-2,0) = OPS_ACC(rhoE_B0, 0,2,0);


      }
    }
  }
}
