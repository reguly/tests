//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_opensbliblock00Kernel035;
int ydim0_opensbliblock00Kernel035;
int xdim1_opensbliblock00Kernel035;
int ydim1_opensbliblock00Kernel035;
int xdim2_opensbliblock00Kernel035;
int ydim2_opensbliblock00Kernel035;
int xdim3_opensbliblock00Kernel035;
int ydim3_opensbliblock00Kernel035;
int xdim4_opensbliblock00Kernel035;
int ydim4_opensbliblock00Kernel035;
int xdim5_opensbliblock00Kernel035;
int ydim5_opensbliblock00Kernel035;
int xdim6_opensbliblock00Kernel035;
int ydim6_opensbliblock00Kernel035;
int xdim7_opensbliblock00Kernel035;
int ydim7_opensbliblock00Kernel035;
int xdim8_opensbliblock00Kernel035;
int ydim8_opensbliblock00Kernel035;
int xdim9_opensbliblock00Kernel035;
int ydim9_opensbliblock00Kernel035;
int xdim10_opensbliblock00Kernel035;
int ydim10_opensbliblock00Kernel035;
int xdim11_opensbliblock00Kernel035;
int ydim11_opensbliblock00Kernel035;
int xdim12_opensbliblock00Kernel035;
int ydim12_opensbliblock00Kernel035;
int xdim13_opensbliblock00Kernel035;
int ydim13_opensbliblock00Kernel035;
int xdim14_opensbliblock00Kernel035;
int ydim14_opensbliblock00Kernel035;

//user function
inline 
 void opensbliblock00Kernel035(const ptr_double rhoE_RKold_B0,
  const ptr_double Residual3_B0,
  const ptr_double rho_RKold_B0,
  const ptr_double Residual1_B0,
  const ptr_double rhou0_RKold_B0,
  const ptr_double Residual0_B0,
  const ptr_double Residual4_B0,
  const
ptr_double rhou2_RKold_B0,
  const ptr_double rhou1_RKold_B0,
  const ptr_double Residual2_B0,
  ptr_double rhoE_B0,
  ptr_double rho_B0,
  ptr_double rhou0_B0,
  ptr_double rhou2_B0,
  ptr_double rhou1_B0,
  const double *rknew)
{
   OPS_ACC(rho_B0, 0,0,0) = dt*rknew[0]*OPS_ACC(Residual0_B0, 0,0,0) + OPS_ACC(rho_RKold_B0, 0,0,0);

   OPS_ACC(rhou0_B0, 0,0,0) = dt*rknew[0]*OPS_ACC(Residual1_B0, 0,0,0) + OPS_ACC(rhou0_RKold_B0, 0,0,0);

   OPS_ACC(rhou1_B0, 0,0,0) = dt*rknew[0]*OPS_ACC(Residual2_B0, 0,0,0) + OPS_ACC(rhou1_RKold_B0, 0,0,0);

   OPS_ACC(rhou2_B0, 0,0,0) = dt*rknew[0]*OPS_ACC(Residual3_B0, 0,0,0) + OPS_ACC(rhou2_RKold_B0, 0,0,0);

   OPS_ACC(rhoE_B0, 0,0,0) = dt*rknew[0]*OPS_ACC(Residual4_B0, 0,0,0) + OPS_ACC(rhoE_RKold_B0, 0,0,0);

}


void opensbliblock00Kernel035_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  double *p_a11,
  double *p_a12,
  double *p_a13,
  double *p_a14,
  double p_a15,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7,p_a8,p_a9,p_a10,p_a11,p_a12,p_a13,p_a14)
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
        const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_opensbliblock00Kernel035*1*1 + n_z*xdim0_opensbliblock00Kernel035*ydim0_opensbliblock00Kernel035*1*1, xdim0_opensbliblock00Kernel035, ydim0_opensbliblock00Kernel035};
        const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_opensbliblock00Kernel035*1*1 + n_z*xdim1_opensbliblock00Kernel035*ydim1_opensbliblock00Kernel035*1*1, xdim1_opensbliblock00Kernel035, ydim1_opensbliblock00Kernel035};
        const ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_opensbliblock00Kernel035*1*1 + n_z*xdim2_opensbliblock00Kernel035*ydim2_opensbliblock00Kernel035*1*1, xdim2_opensbliblock00Kernel035, ydim2_opensbliblock00Kernel035};
        const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_opensbliblock00Kernel035*1*1 + n_z*xdim3_opensbliblock00Kernel035*ydim3_opensbliblock00Kernel035*1*1, xdim3_opensbliblock00Kernel035, ydim3_opensbliblock00Kernel035};
        const ptr_double ptr4 = {  p_a4 + n_x*1*1 + n_y*xdim4_opensbliblock00Kernel035*1*1 + n_z*xdim4_opensbliblock00Kernel035*ydim4_opensbliblock00Kernel035*1*1, xdim4_opensbliblock00Kernel035, ydim4_opensbliblock00Kernel035};
        const ptr_double ptr5 = {  p_a5 + n_x*1*1 + n_y*xdim5_opensbliblock00Kernel035*1*1 + n_z*xdim5_opensbliblock00Kernel035*ydim5_opensbliblock00Kernel035*1*1, xdim5_opensbliblock00Kernel035, ydim5_opensbliblock00Kernel035};
        const ptr_double ptr6 = {  p_a6 + n_x*1*1 + n_y*xdim6_opensbliblock00Kernel035*1*1 + n_z*xdim6_opensbliblock00Kernel035*ydim6_opensbliblock00Kernel035*1*1, xdim6_opensbliblock00Kernel035, ydim6_opensbliblock00Kernel035};
        const ptr_double ptr7 = {  p_a7 + n_x*1*1 + n_y*xdim7_opensbliblock00Kernel035*1*1 + n_z*xdim7_opensbliblock00Kernel035*ydim7_opensbliblock00Kernel035*1*1, xdim7_opensbliblock00Kernel035, ydim7_opensbliblock00Kernel035};
        const ptr_double ptr8 = {  p_a8 + n_x*1*1 + n_y*xdim8_opensbliblock00Kernel035*1*1 + n_z*xdim8_opensbliblock00Kernel035*ydim8_opensbliblock00Kernel035*1*1, xdim8_opensbliblock00Kernel035, ydim8_opensbliblock00Kernel035};
        const ptr_double ptr9 = {  p_a9 + n_x*1*1 + n_y*xdim9_opensbliblock00Kernel035*1*1 + n_z*xdim9_opensbliblock00Kernel035*ydim9_opensbliblock00Kernel035*1*1, xdim9_opensbliblock00Kernel035, ydim9_opensbliblock00Kernel035};
        ptr_double ptr10 = {  p_a10 + n_x*1*1 + n_y*xdim10_opensbliblock00Kernel035*1*1 + n_z*xdim10_opensbliblock00Kernel035*ydim10_opensbliblock00Kernel035*1*1, xdim10_opensbliblock00Kernel035, ydim10_opensbliblock00Kernel035};
        ptr_double ptr11 = {  p_a11 + n_x*1*1 + n_y*xdim11_opensbliblock00Kernel035*1*1 + n_z*xdim11_opensbliblock00Kernel035*ydim11_opensbliblock00Kernel035*1*1, xdim11_opensbliblock00Kernel035, ydim11_opensbliblock00Kernel035};
        ptr_double ptr12 = {  p_a12 + n_x*1*1 + n_y*xdim12_opensbliblock00Kernel035*1*1 + n_z*xdim12_opensbliblock00Kernel035*ydim12_opensbliblock00Kernel035*1*1, xdim12_opensbliblock00Kernel035, ydim12_opensbliblock00Kernel035};
        ptr_double ptr13 = {  p_a13 + n_x*1*1 + n_y*xdim13_opensbliblock00Kernel035*1*1 + n_z*xdim13_opensbliblock00Kernel035*ydim13_opensbliblock00Kernel035*1*1, xdim13_opensbliblock00Kernel035, ydim13_opensbliblock00Kernel035};
        ptr_double ptr14 = {  p_a14 + n_x*1*1 + n_y*xdim14_opensbliblock00Kernel035*1*1 + n_z*xdim14_opensbliblock00Kernel035*ydim14_opensbliblock00Kernel035*1*1, xdim14_opensbliblock00Kernel035, ydim14_opensbliblock00Kernel035};
        opensbliblock00Kernel035( ptr0, ptr1, ptr2, ptr3,
           ptr4, ptr5, ptr6, ptr7,
           ptr8, ptr9, ptr10, ptr11,
           ptr12, ptr13, ptr14, &p_a15);
      }
    }
  }
}
