//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel003;
int ydim0_opensbliblock00Kernel003;
int xdim1_opensbliblock00Kernel003;
int ydim1_opensbliblock00Kernel003;


//user function



void opensbliblock00Kernel003_c_wrapper(
  double * restrict u0_B0_p,
  double * restrict wk2_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double u0_B0 = { u0_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel003*1 + n_z * xdim0_opensbliblock00Kernel003 * ydim0_opensbliblock00Kernel003*1, xdim0_opensbliblock00Kernel003, ydim0_opensbliblock00Kernel003};
        ptr_double wk2_B0 = { wk2_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel003*1 + n_z * xdim1_opensbliblock00Kernel003 * ydim1_opensbliblock00Kernel003*1, xdim1_opensbliblock00Kernel003, ydim1_opensbliblock00Kernel003};
        
    OPS_ACC(wk2_B0, 0,0,0) = (rc7)*inv_2*(OPS_ACC(u0_B0, 0,-2,0) - 8*OPS_ACC(u0_B0, 0,-1,0) +
      8*OPS_ACC(u0_B0, 0,1,0) - OPS_ACC(u0_B0, 0,2,0));


      }
    }
  }
}
