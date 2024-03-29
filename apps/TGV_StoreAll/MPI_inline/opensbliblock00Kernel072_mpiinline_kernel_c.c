//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel072;
int ydim0_opensbliblock00Kernel072;
int xdim1_opensbliblock00Kernel072;
int ydim1_opensbliblock00Kernel072;


//user function



void opensbliblock00Kernel072_c_wrapper(
  double * restrict wk1_B0_p,
  double * restrict wk20_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double wk1_B0 = { wk1_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel072*1 + n_z * xdim0_opensbliblock00Kernel072 * ydim0_opensbliblock00Kernel072*1, xdim0_opensbliblock00Kernel072, ydim0_opensbliblock00Kernel072};
        ptr_double wk20_B0 = { wk20_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel072*1 + n_z * xdim1_opensbliblock00Kernel072 * ydim1_opensbliblock00Kernel072*1, xdim1_opensbliblock00Kernel072, ydim1_opensbliblock00Kernel072};
        
    OPS_ACC(wk20_B0, 0,0,0) = -rc8*inv_2*(-OPS_ACC(wk1_B0, 0,0,-2) + OPS_ACC(wk1_B0, 0,0,2) +
      8*OPS_ACC(wk1_B0, 0,0,-1) - 8*OPS_ACC(wk1_B0, 0,0,1));


      }
    }
  }
}
