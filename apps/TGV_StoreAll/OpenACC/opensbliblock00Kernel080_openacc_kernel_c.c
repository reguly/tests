//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_opensbliblock00Kernel080;
int ydim0_opensbliblock00Kernel080;
int xdim1_opensbliblock00Kernel080;
int ydim1_opensbliblock00Kernel080;
int xdim2_opensbliblock00Kernel080;
int ydim2_opensbliblock00Kernel080;
int xdim3_opensbliblock00Kernel080;
int ydim3_opensbliblock00Kernel080;
int xdim4_opensbliblock00Kernel080;
int ydim4_opensbliblock00Kernel080;
int xdim5_opensbliblock00Kernel080;
int ydim5_opensbliblock00Kernel080;
int xdim6_opensbliblock00Kernel080;
int ydim6_opensbliblock00Kernel080;
int xdim7_opensbliblock00Kernel080;
int ydim7_opensbliblock00Kernel080;
int xdim8_opensbliblock00Kernel080;
int ydim8_opensbliblock00Kernel080;
int xdim9_opensbliblock00Kernel080;
int ydim9_opensbliblock00Kernel080;
int xdim10_opensbliblock00Kernel080;
int ydim10_opensbliblock00Kernel080;
int xdim11_opensbliblock00Kernel080;
int ydim11_opensbliblock00Kernel080;
int xdim12_opensbliblock00Kernel080;
int ydim12_opensbliblock00Kernel080;
int xdim13_opensbliblock00Kernel080;
int ydim13_opensbliblock00Kernel080;
int xdim14_opensbliblock00Kernel080;
int ydim14_opensbliblock00Kernel080;
int xdim15_opensbliblock00Kernel080;
int ydim15_opensbliblock00Kernel080;
int xdim16_opensbliblock00Kernel080;
int ydim16_opensbliblock00Kernel080;
int xdim17_opensbliblock00Kernel080;
int ydim17_opensbliblock00Kernel080;
int xdim18_opensbliblock00Kernel080;
int ydim18_opensbliblock00Kernel080;
int xdim19_opensbliblock00Kernel080;
int ydim19_opensbliblock00Kernel080;
int xdim20_opensbliblock00Kernel080;
int ydim20_opensbliblock00Kernel080;
int xdim21_opensbliblock00Kernel080;
int ydim21_opensbliblock00Kernel080;
int xdim22_opensbliblock00Kernel080;
int ydim22_opensbliblock00Kernel080;
int xdim23_opensbliblock00Kernel080;
int ydim23_opensbliblock00Kernel080;
int xdim24_opensbliblock00Kernel080;
int ydim24_opensbliblock00Kernel080;
int xdim25_opensbliblock00Kernel080;
int ydim25_opensbliblock00Kernel080;
int xdim26_opensbliblock00Kernel080;
int ydim26_opensbliblock00Kernel080;
int xdim27_opensbliblock00Kernel080;
int ydim27_opensbliblock00Kernel080;
int xdim28_opensbliblock00Kernel080;
int ydim28_opensbliblock00Kernel080;
int xdim29_opensbliblock00Kernel080;
int ydim29_opensbliblock00Kernel080;
int xdim30_opensbliblock00Kernel080;
int ydim30_opensbliblock00Kernel080;
int xdim31_opensbliblock00Kernel080;
int ydim31_opensbliblock00Kernel080;
int xdim32_opensbliblock00Kernel080;
int ydim32_opensbliblock00Kernel080;
int xdim33_opensbliblock00Kernel080;
int ydim33_opensbliblock00Kernel080;

//user function
inline 
 void opensbliblock00Kernel080(const ptr_double wk10_B0,
  const ptr_double wk11_B0,
  const ptr_double u0_B0,
  const ptr_double wk25_B0,
  const ptr_double wk16_B0,
  const ptr_double wk9_B0,
  const ptr_double u1_B0,
  const ptr_double wk6_B0,
  const ptr_double wk21_B0,
  const
ptr_double wk26_B0,
  const ptr_double wk24_B0,
  const ptr_double wk5_B0,
  const ptr_double wk3_B0,
  const ptr_double wk1_B0,
  const ptr_double u2_B0,
  const ptr_double wk13_B0,
  const ptr_double wk20_B0,
  const ptr_double wk18_B0,
  const ptr_double wk22_B0,
  const ptr_double wk23_B0,
  const ptr_double wk17_B0,
  const ptr_double wk15_B0,
  const ptr_double wk12_B0,
  const ptr_double wk4_B0,
  const ptr_double wk0_B0,
  const ptr_double wk19_B0,
  const ptr_double wk7_B0,
  const ptr_double wk8_B0,
  const ptr_double wk2_B0,
  const ptr_double wk14_B0,
  ptr_double Residual4_B0,
  ptr_double Residual3_B0,
  ptr_double Residual1_B0,
  ptr_double Residual2_B0)
{
    OPS_ACC(Residual1_B0, 0,0,0) = 1.0*rcinv9*((rc10)*OPS_ACC(wk14_B0, 0,0,0) + (rc11)*OPS_ACC(wk17_B0, 0,0,0) +
      (rc11)*OPS_ACC(wk23_B0, 0,0,0) + OPS_ACC(wk4_B0, 0,0,0) + OPS_ACC(wk8_B0, 0,0,0)) +
      OPS_ACC(Residual1_B0, 0,0,0);

    OPS_ACC(Residual2_B0, 0,0,0) = 1.0*rcinv9*((rc10)*OPS_ACC(wk0_B0, 0,0,0) + (rc11)*OPS_ACC(wk19_B0, 0,0,0) +
      OPS_ACC(wk22_B0, 0,0,0) + (rc11)*OPS_ACC(wk2_B0, 0,0,0) + OPS_ACC(wk5_B0, 0,0,0)) +
      OPS_ACC(Residual2_B0, 0,0,0);

    OPS_ACC(Residual3_B0, 0,0,0) = 1.0*rcinv9*((rc11)*OPS_ACC(wk12_B0, 0,0,0) + OPS_ACC(wk13_B0, 0,0,0) +
      (rc11)*OPS_ACC(wk20_B0, 0,0,0) + OPS_ACC(wk21_B0, 0,0,0) + (rc10)*OPS_ACC(wk7_B0, 0,0,0)) +
      OPS_ACC(Residual3_B0, 0,0,0);

    OPS_ACC(Residual4_B0, 0,0,0) = 1.0*rcinv12*rcinv13*rcinv14*rcinv9*(OPS_ACC(wk16_B0, 0,0,0) +
      OPS_ACC(wk18_B0, 0,0,0) + OPS_ACC(wk25_B0, 0,0,0)) + 1.0*rcinv9*(OPS_ACC(wk11_B0, 0,0,0) +
      OPS_ACC(wk15_B0, 0,0,0))*OPS_ACC(wk11_B0, 0,0,0) + 1.0*rcinv9*(OPS_ACC(wk11_B0, 0,0,0) +
      OPS_ACC(wk15_B0, 0,0,0))*OPS_ACC(wk15_B0, 0,0,0) + 1.0*rcinv9*(OPS_ACC(wk24_B0, 0,0,0) +
      OPS_ACC(wk26_B0, 0,0,0))*OPS_ACC(wk24_B0, 0,0,0) + 1.0*rcinv9*(OPS_ACC(wk24_B0, 0,0,0) +
      OPS_ACC(wk26_B0, 0,0,0))*OPS_ACC(wk26_B0, 0,0,0) + 1.0*rcinv9*(OPS_ACC(wk3_B0, 0,0,0) +
      OPS_ACC(wk9_B0, 0,0,0))*OPS_ACC(wk3_B0, 0,0,0) + 1.0*rcinv9*(OPS_ACC(wk3_B0, 0,0,0) +
      OPS_ACC(wk9_B0, 0,0,0))*OPS_ACC(wk9_B0, 0,0,0) + 1.0*rcinv9*(-rc7*OPS_ACC(wk10_B0, 0,0,0) -
      rc7*OPS_ACC(wk1_B0, 0,0,0) + (rc10)*OPS_ACC(wk6_B0, 0,0,0))*OPS_ACC(wk6_B0, 0,0,0) +
      1.0*rcinv9*(-rc7*OPS_ACC(wk10_B0, 0,0,0) + (rc10)*OPS_ACC(wk1_B0, 0,0,0) -
      rc7*OPS_ACC(wk6_B0, 0,0,0))*OPS_ACC(wk1_B0, 0,0,0) + 1.0*rcinv9*((rc10)*OPS_ACC(wk10_B0, 0,0,0) -
      rc7*OPS_ACC(wk1_B0, 0,0,0) - rc7*OPS_ACC(wk6_B0, 0,0,0))*OPS_ACC(wk10_B0, 0,0,0) +
      1.0*rcinv9*((rc10)*OPS_ACC(wk0_B0, 0,0,0) + (rc11)*OPS_ACC(wk19_B0, 0,0,0) + OPS_ACC(wk22_B0, 0,0,0) +
      (rc11)*OPS_ACC(wk2_B0, 0,0,0) + OPS_ACC(wk5_B0, 0,0,0))*OPS_ACC(u1_B0, 0,0,0) +
      1.0*rcinv9*((rc11)*OPS_ACC(wk12_B0, 0,0,0) + OPS_ACC(wk13_B0, 0,0,0) + (rc11)*OPS_ACC(wk20_B0, 0,0,0) +
      OPS_ACC(wk21_B0, 0,0,0) + (rc10)*OPS_ACC(wk7_B0, 0,0,0))*OPS_ACC(u2_B0, 0,0,0) +
      1.0*rcinv9*((rc10)*OPS_ACC(wk14_B0, 0,0,0) + (rc11)*OPS_ACC(wk17_B0, 0,0,0) + (rc11)*OPS_ACC(wk23_B0, 0,0,0)
      + OPS_ACC(wk4_B0, 0,0,0) + OPS_ACC(wk8_B0, 0,0,0))*OPS_ACC(u0_B0, 0,0,0) + OPS_ACC(Residual4_B0, 0,0,0);

}


void opensbliblock00Kernel080_c_wrapper(
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
  double *p_a15,
  double *p_a16,
  double *p_a17,
  double *p_a18,
  double *p_a19,
  double *p_a20,
  double *p_a21,
  double *p_a22,
  double *p_a23,
  double *p_a24,
  double *p_a25,
  double *p_a26,
  double *p_a27,
  double *p_a28,
  double *p_a29,
  double *p_a30,
  double *p_a31,
  double *p_a32,
  double *p_a33,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7,p_a8,p_a9,p_a10,p_a11,p_a12,p_a13,p_a14,p_a15,p_a16,p_a17,p_a18,p_a19,p_a20,p_a21,p_a22,p_a23,p_a24,p_a25,p_a26,p_a27,p_a28,p_a29,p_a30,p_a31,p_a32,p_a33)
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
        const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_opensbliblock00Kernel080*1*1 + n_z*xdim0_opensbliblock00Kernel080*ydim0_opensbliblock00Kernel080*1*1, xdim0_opensbliblock00Kernel080, ydim0_opensbliblock00Kernel080};
        const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_opensbliblock00Kernel080*1*1 + n_z*xdim1_opensbliblock00Kernel080*ydim1_opensbliblock00Kernel080*1*1, xdim1_opensbliblock00Kernel080, ydim1_opensbliblock00Kernel080};
        const ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_opensbliblock00Kernel080*1*1 + n_z*xdim2_opensbliblock00Kernel080*ydim2_opensbliblock00Kernel080*1*1, xdim2_opensbliblock00Kernel080, ydim2_opensbliblock00Kernel080};
        const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_opensbliblock00Kernel080*1*1 + n_z*xdim3_opensbliblock00Kernel080*ydim3_opensbliblock00Kernel080*1*1, xdim3_opensbliblock00Kernel080, ydim3_opensbliblock00Kernel080};
        const ptr_double ptr4 = {  p_a4 + n_x*1*1 + n_y*xdim4_opensbliblock00Kernel080*1*1 + n_z*xdim4_opensbliblock00Kernel080*ydim4_opensbliblock00Kernel080*1*1, xdim4_opensbliblock00Kernel080, ydim4_opensbliblock00Kernel080};
        const ptr_double ptr5 = {  p_a5 + n_x*1*1 + n_y*xdim5_opensbliblock00Kernel080*1*1 + n_z*xdim5_opensbliblock00Kernel080*ydim5_opensbliblock00Kernel080*1*1, xdim5_opensbliblock00Kernel080, ydim5_opensbliblock00Kernel080};
        const ptr_double ptr6 = {  p_a6 + n_x*1*1 + n_y*xdim6_opensbliblock00Kernel080*1*1 + n_z*xdim6_opensbliblock00Kernel080*ydim6_opensbliblock00Kernel080*1*1, xdim6_opensbliblock00Kernel080, ydim6_opensbliblock00Kernel080};
        const ptr_double ptr7 = {  p_a7 + n_x*1*1 + n_y*xdim7_opensbliblock00Kernel080*1*1 + n_z*xdim7_opensbliblock00Kernel080*ydim7_opensbliblock00Kernel080*1*1, xdim7_opensbliblock00Kernel080, ydim7_opensbliblock00Kernel080};
        const ptr_double ptr8 = {  p_a8 + n_x*1*1 + n_y*xdim8_opensbliblock00Kernel080*1*1 + n_z*xdim8_opensbliblock00Kernel080*ydim8_opensbliblock00Kernel080*1*1, xdim8_opensbliblock00Kernel080, ydim8_opensbliblock00Kernel080};
        const ptr_double ptr9 = {  p_a9 + n_x*1*1 + n_y*xdim9_opensbliblock00Kernel080*1*1 + n_z*xdim9_opensbliblock00Kernel080*ydim9_opensbliblock00Kernel080*1*1, xdim9_opensbliblock00Kernel080, ydim9_opensbliblock00Kernel080};
        const ptr_double ptr10 = {  p_a10 + n_x*1*1 + n_y*xdim10_opensbliblock00Kernel080*1*1 + n_z*xdim10_opensbliblock00Kernel080*ydim10_opensbliblock00Kernel080*1*1, xdim10_opensbliblock00Kernel080, ydim10_opensbliblock00Kernel080};
        const ptr_double ptr11 = {  p_a11 + n_x*1*1 + n_y*xdim11_opensbliblock00Kernel080*1*1 + n_z*xdim11_opensbliblock00Kernel080*ydim11_opensbliblock00Kernel080*1*1, xdim11_opensbliblock00Kernel080, ydim11_opensbliblock00Kernel080};
        const ptr_double ptr12 = {  p_a12 + n_x*1*1 + n_y*xdim12_opensbliblock00Kernel080*1*1 + n_z*xdim12_opensbliblock00Kernel080*ydim12_opensbliblock00Kernel080*1*1, xdim12_opensbliblock00Kernel080, ydim12_opensbliblock00Kernel080};
        const ptr_double ptr13 = {  p_a13 + n_x*1*1 + n_y*xdim13_opensbliblock00Kernel080*1*1 + n_z*xdim13_opensbliblock00Kernel080*ydim13_opensbliblock00Kernel080*1*1, xdim13_opensbliblock00Kernel080, ydim13_opensbliblock00Kernel080};
        const ptr_double ptr14 = {  p_a14 + n_x*1*1 + n_y*xdim14_opensbliblock00Kernel080*1*1 + n_z*xdim14_opensbliblock00Kernel080*ydim14_opensbliblock00Kernel080*1*1, xdim14_opensbliblock00Kernel080, ydim14_opensbliblock00Kernel080};
        const ptr_double ptr15 = {  p_a15 + n_x*1*1 + n_y*xdim15_opensbliblock00Kernel080*1*1 + n_z*xdim15_opensbliblock00Kernel080*ydim15_opensbliblock00Kernel080*1*1, xdim15_opensbliblock00Kernel080, ydim15_opensbliblock00Kernel080};
        const ptr_double ptr16 = {  p_a16 + n_x*1*1 + n_y*xdim16_opensbliblock00Kernel080*1*1 + n_z*xdim16_opensbliblock00Kernel080*ydim16_opensbliblock00Kernel080*1*1, xdim16_opensbliblock00Kernel080, ydim16_opensbliblock00Kernel080};
        const ptr_double ptr17 = {  p_a17 + n_x*1*1 + n_y*xdim17_opensbliblock00Kernel080*1*1 + n_z*xdim17_opensbliblock00Kernel080*ydim17_opensbliblock00Kernel080*1*1, xdim17_opensbliblock00Kernel080, ydim17_opensbliblock00Kernel080};
        const ptr_double ptr18 = {  p_a18 + n_x*1*1 + n_y*xdim18_opensbliblock00Kernel080*1*1 + n_z*xdim18_opensbliblock00Kernel080*ydim18_opensbliblock00Kernel080*1*1, xdim18_opensbliblock00Kernel080, ydim18_opensbliblock00Kernel080};
        const ptr_double ptr19 = {  p_a19 + n_x*1*1 + n_y*xdim19_opensbliblock00Kernel080*1*1 + n_z*xdim19_opensbliblock00Kernel080*ydim19_opensbliblock00Kernel080*1*1, xdim19_opensbliblock00Kernel080, ydim19_opensbliblock00Kernel080};
        const ptr_double ptr20 = {  p_a20 + n_x*1*1 + n_y*xdim20_opensbliblock00Kernel080*1*1 + n_z*xdim20_opensbliblock00Kernel080*ydim20_opensbliblock00Kernel080*1*1, xdim20_opensbliblock00Kernel080, ydim20_opensbliblock00Kernel080};
        const ptr_double ptr21 = {  p_a21 + n_x*1*1 + n_y*xdim21_opensbliblock00Kernel080*1*1 + n_z*xdim21_opensbliblock00Kernel080*ydim21_opensbliblock00Kernel080*1*1, xdim21_opensbliblock00Kernel080, ydim21_opensbliblock00Kernel080};
        const ptr_double ptr22 = {  p_a22 + n_x*1*1 + n_y*xdim22_opensbliblock00Kernel080*1*1 + n_z*xdim22_opensbliblock00Kernel080*ydim22_opensbliblock00Kernel080*1*1, xdim22_opensbliblock00Kernel080, ydim22_opensbliblock00Kernel080};
        const ptr_double ptr23 = {  p_a23 + n_x*1*1 + n_y*xdim23_opensbliblock00Kernel080*1*1 + n_z*xdim23_opensbliblock00Kernel080*ydim23_opensbliblock00Kernel080*1*1, xdim23_opensbliblock00Kernel080, ydim23_opensbliblock00Kernel080};
        const ptr_double ptr24 = {  p_a24 + n_x*1*1 + n_y*xdim24_opensbliblock00Kernel080*1*1 + n_z*xdim24_opensbliblock00Kernel080*ydim24_opensbliblock00Kernel080*1*1, xdim24_opensbliblock00Kernel080, ydim24_opensbliblock00Kernel080};
        const ptr_double ptr25 = {  p_a25 + n_x*1*1 + n_y*xdim25_opensbliblock00Kernel080*1*1 + n_z*xdim25_opensbliblock00Kernel080*ydim25_opensbliblock00Kernel080*1*1, xdim25_opensbliblock00Kernel080, ydim25_opensbliblock00Kernel080};
        const ptr_double ptr26 = {  p_a26 + n_x*1*1 + n_y*xdim26_opensbliblock00Kernel080*1*1 + n_z*xdim26_opensbliblock00Kernel080*ydim26_opensbliblock00Kernel080*1*1, xdim26_opensbliblock00Kernel080, ydim26_opensbliblock00Kernel080};
        const ptr_double ptr27 = {  p_a27 + n_x*1*1 + n_y*xdim27_opensbliblock00Kernel080*1*1 + n_z*xdim27_opensbliblock00Kernel080*ydim27_opensbliblock00Kernel080*1*1, xdim27_opensbliblock00Kernel080, ydim27_opensbliblock00Kernel080};
        const ptr_double ptr28 = {  p_a28 + n_x*1*1 + n_y*xdim28_opensbliblock00Kernel080*1*1 + n_z*xdim28_opensbliblock00Kernel080*ydim28_opensbliblock00Kernel080*1*1, xdim28_opensbliblock00Kernel080, ydim28_opensbliblock00Kernel080};
        const ptr_double ptr29 = {  p_a29 + n_x*1*1 + n_y*xdim29_opensbliblock00Kernel080*1*1 + n_z*xdim29_opensbliblock00Kernel080*ydim29_opensbliblock00Kernel080*1*1, xdim29_opensbliblock00Kernel080, ydim29_opensbliblock00Kernel080};
        ptr_double ptr30 = {  p_a30 + n_x*1*1 + n_y*xdim30_opensbliblock00Kernel080*1*1 + n_z*xdim30_opensbliblock00Kernel080*ydim30_opensbliblock00Kernel080*1*1, xdim30_opensbliblock00Kernel080, ydim30_opensbliblock00Kernel080};
        ptr_double ptr31 = {  p_a31 + n_x*1*1 + n_y*xdim31_opensbliblock00Kernel080*1*1 + n_z*xdim31_opensbliblock00Kernel080*ydim31_opensbliblock00Kernel080*1*1, xdim31_opensbliblock00Kernel080, ydim31_opensbliblock00Kernel080};
        ptr_double ptr32 = {  p_a32 + n_x*1*1 + n_y*xdim32_opensbliblock00Kernel080*1*1 + n_z*xdim32_opensbliblock00Kernel080*ydim32_opensbliblock00Kernel080*1*1, xdim32_opensbliblock00Kernel080, ydim32_opensbliblock00Kernel080};
        ptr_double ptr33 = {  p_a33 + n_x*1*1 + n_y*xdim33_opensbliblock00Kernel080*1*1 + n_z*xdim33_opensbliblock00Kernel080*ydim33_opensbliblock00Kernel080*1*1, xdim33_opensbliblock00Kernel080, ydim33_opensbliblock00Kernel080};
        opensbliblock00Kernel080( ptr0, ptr1, ptr2, ptr3,
           ptr4, ptr5, ptr6, ptr7,
           ptr8, ptr9, ptr10, ptr11,
           ptr12, ptr13, ptr14, ptr15,
           ptr16, ptr17, ptr18, ptr19,
           ptr20, ptr21, ptr22, ptr23,
           ptr24, ptr25, ptr26, ptr27,
           ptr28, ptr29, ptr30, ptr31,
           ptr32, ptr33);
      }
    }
  }
}
