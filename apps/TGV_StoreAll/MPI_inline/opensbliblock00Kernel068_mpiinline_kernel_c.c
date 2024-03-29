//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel068;
int ydim0_opensbliblock00Kernel068;
int xdim1_opensbliblock00Kernel068;
int ydim1_opensbliblock00Kernel068;


//user function



void opensbliblock00Kernel068_c_wrapper(
  double * restrict T_B0_p,
  double * restrict wk16_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double T_B0 = { T_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel068*1 + n_z * xdim0_opensbliblock00Kernel068 * ydim0_opensbliblock00Kernel068*1, xdim0_opensbliblock00Kernel068, ydim0_opensbliblock00Kernel068};
        ptr_double wk16_B0 = { wk16_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel068*1 + n_z * xdim1_opensbliblock00Kernel068 * ydim1_opensbliblock00Kernel068*1, xdim1_opensbliblock00Kernel068, ydim1_opensbliblock00Kernel068};
        
    OPS_ACC(wk16_B0, 0,0,0) = -rc8*inv_5*(OPS_ACC(T_B0, 0,0,2) - 16*OPS_ACC(T_B0, 0,0,1) - 16*OPS_ACC(T_B0, 0,0,-1)
      + OPS_ACC(T_B0, 0,0,-2) + 30*OPS_ACC(T_B0, 0,0,0));


      }
    }
  }
}
