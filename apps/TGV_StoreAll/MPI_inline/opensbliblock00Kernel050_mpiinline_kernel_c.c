//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel050;
int ydim0_opensbliblock00Kernel050;
int xdim1_opensbliblock00Kernel050;
int ydim1_opensbliblock00Kernel050;


//user function



void opensbliblock00Kernel050_c_wrapper(
  double * restrict wk44_B0_p,
  double * restrict wk38_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double wk44_B0 = { wk44_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel050*1 + n_z * xdim0_opensbliblock00Kernel050 * ydim0_opensbliblock00Kernel050*1, xdim0_opensbliblock00Kernel050, ydim0_opensbliblock00Kernel050};
        ptr_double wk38_B0 = { wk38_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel050*1 + n_z * xdim1_opensbliblock00Kernel050 * ydim1_opensbliblock00Kernel050*1, xdim1_opensbliblock00Kernel050, ydim1_opensbliblock00Kernel050};
        
    OPS_ACC(wk38_B0, 0,0,0) = inv_2*((rc7)*OPS_ACC(wk44_B0, 0,0,1) - rc8*OPS_ACC(wk44_B0, 0,0,2) -
      rc7*OPS_ACC(wk44_B0, 0,0,-1) + (rc8)*OPS_ACC(wk44_B0, 0,0,-2));


      }
    }
  }
}
