//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_opensbliblock00Kernel016;
int ydim0_opensbliblock00Kernel016;
int xdim1_opensbliblock00Kernel016;
int ydim1_opensbliblock00Kernel016;

//user function
inline 
void opensbliblock00Kernel016(const ptr_double wk42_B0,
  ptr_double wk9_B0)
{
    OPS_ACC(wk9_B0, 0,0,0) = inv_0*(-rc7*OPS_ACC(wk42_B0, 0,-1,0) + (rc7)*OPS_ACC(wk42_B0, 0,1,0) -
      rc8*OPS_ACC(wk42_B0, 0,2,0) + (rc8)*OPS_ACC(wk42_B0, 0,-2,0));

}


void opensbliblock00Kernel016_c_wrapper(
  double *p_a0,
  double *p_a1,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1)
  #pragma acc loop
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_opensbliblock00Kernel016*1*1 + n_z*xdim0_opensbliblock00Kernel016*ydim0_opensbliblock00Kernel016*1*1, xdim0_opensbliblock00Kernel016, ydim0_opensbliblock00Kernel016};
        ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_opensbliblock00Kernel016*1*1 + n_z*xdim1_opensbliblock00Kernel016*ydim1_opensbliblock00Kernel016*1*1, xdim1_opensbliblock00Kernel016, ydim1_opensbliblock00Kernel016};
        opensbliblock00Kernel016( ptr0,
          ptr1 );

      }
    }
  }
}
