//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel029;
int ydim0_opensbliblock00Kernel029;
int xdim1_opensbliblock00Kernel029;
int ydim1_opensbliblock00Kernel029;


//user function



void opensbliblock00Kernel029_c_wrapper(
  double * restrict rhoE_B0_p,
  double * restrict wk19_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double rhoE_B0 = { rhoE_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel029*1 + n_z * xdim0_opensbliblock00Kernel029 * ydim0_opensbliblock00Kernel029*1, xdim0_opensbliblock00Kernel029, ydim0_opensbliblock00Kernel029};
        ptr_double wk19_B0 = { wk19_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel029*1 + n_z * xdim1_opensbliblock00Kernel029 * ydim1_opensbliblock00Kernel029*1, xdim1_opensbliblock00Kernel029, ydim1_opensbliblock00Kernel029};
        
    OPS_ACC(wk19_B0, 0,0,0) = inv_1*((rc8)*OPS_ACC(rhoE_B0, -2,0,0) - rc8*OPS_ACC(rhoE_B0, 2,0,0) +
      (rc7)*OPS_ACC(rhoE_B0, 1,0,0) - rc7*OPS_ACC(rhoE_B0, -1,0,0));


      }
    }
  }
}
