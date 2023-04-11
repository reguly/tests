//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_opensbliblock00Kernel009;
int ydim0_opensbliblock00Kernel009;
int xdim1_opensbliblock00Kernel009;
int ydim1_opensbliblock00Kernel009;
int xdim2_opensbliblock00Kernel009;
int ydim2_opensbliblock00Kernel009;

//user function
inline 
void opensbliblock00Kernel009(const ptr_double rho_B0,
  const ptr_double rhou2_B0,
  ptr_double u2_B0)
{
   OPS_ACC(u2_B0, 0,0,0) = OPS_ACC(rhou2_B0, 0,0,0)/OPS_ACC(rho_B0, 0,0,0);

}


void opensbliblock00Kernel009_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2)
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
        const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_opensbliblock00Kernel009*1*1 + n_z*xdim0_opensbliblock00Kernel009*ydim0_opensbliblock00Kernel009*1*1, xdim0_opensbliblock00Kernel009, ydim0_opensbliblock00Kernel009};
        const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_opensbliblock00Kernel009*1*1 + n_z*xdim1_opensbliblock00Kernel009*ydim1_opensbliblock00Kernel009*1*1, xdim1_opensbliblock00Kernel009, ydim1_opensbliblock00Kernel009};
        ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_opensbliblock00Kernel009*1*1 + n_z*xdim2_opensbliblock00Kernel009*ydim2_opensbliblock00Kernel009*1*1, xdim2_opensbliblock00Kernel009, ydim2_opensbliblock00Kernel009};
        opensbliblock00Kernel009( ptr0, ptr1, ptr2);
      }
    }
  }
}
