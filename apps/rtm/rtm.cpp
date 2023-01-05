/*
* Open source copyright declaration based on BSD open source template:
* http://www.opensource.org/licenses/bsd-license.php
*
* This file is part of the OPS distribution.
*
* Copyright (c) 2013, Mike Giles and others. Please see the AUTHORS file in
* the main source directory for a full list of copyright holders.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* * Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* * The name of Mike Giles may not be used to endorse or promote products
* derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY Mike Giles ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Mike Giles BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/** @Test application for multi-block functionality
  * @author Gihan Mudalige, Istvan Reguly
  */

// standard headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifdef PROFILE_ITT
#include <ittnotify.h>
#endif

float dx,dy,dz,invdx,invdy,invdz;
float* cx;
float* cy;
float* cz;
int pml_width;
int halff, order, nx, ny, nz;
int xbeg;
int xend;
int ybeg;
int yend;
int zbeg;
int zend;
int xpmlbeg;
int ypmlbeg;
int zpmlbeg;
int xpmlend;
int ypmlend;
int zpmlend;
#define OPS_SOA
#include "./coeffs/coeffs8.h"
//#include "./coeffs/coeffs2.h"
float* c;
// OPS header file
#define OPS_3D
#include "ops_seq_v2.h"

#include "rtm_kernel.h"

void derivs(ops_block blocks, ops_stencil S3D_000, ops_stencil S3D_big_sten,  ops_dat rho, ops_dat mu, ops_dat yy, ops_dat dyy);

void calc_ytemp(ops_block blocks, ops_stencil S3D_000, float dt,
		ops_dat yy, ops_dat k, ops_dat ytemp);

void calc_ytemp2(ops_block blocks, ops_stencil S3D_000, float dt,
		 ops_dat yy, ops_dat k, ops_dat ytemp); 

void final_update(ops_block blocks, ops_stencil S3D_000, float dt,
		  ops_dat k1, ops_dat k2, ops_dat k3, ops_dat k4, ops_dat yy);

	      
/******************************************************************************
/* Main program
*******************************************************************************/
int main(int argc, char **argv)
{
  /**-------------------------- Initialisation --------------------------**/

  // OPS initialisation
  ops_init(argc,argv,1);
  OPS_instance::getOPSInstance()->OPS_soa = 1;

  //Mesh
//#define LARGE  
#ifdef LARGE 
  int logical_size_x = 400;
  int logical_size_y = 400;
  int logical_size_z = 400;
#else
  int logical_size_x = 128;
  int logical_size_y = 128;
  int logical_size_z = 128;
#endif
  int ngrid_x = 1;
  int ngrid_y = 1;
  int ngrid_z = 1;
  int n_iter = 10;
  int next_write = 9;
  int write_num = 0;
  int iter2 = 0;
  int itertile = 1;
  int non_copy = 0;

  char* pch;
  for ( int n = 1; n < argc; n++ ) {
    pch = strstr(argv[n], "-sizex=");
    if(pch != NULL) {
      logical_size_x = atoi ( argv[n] + 7 ); continue;
    }
    pch = strstr(argv[n], "-sizey=");
    if(pch != NULL) {
      logical_size_y = atoi ( argv[n] + 7 ); continue;
    }
    pch = strstr(argv[n], "-sizez=");
    if(pch != NULL) {
      logical_size_z = atoi ( argv[n] + 7 ); continue;
    }
    pch = strstr(argv[n], "-iters=");
    if(pch != NULL) {
      n_iter = atoi ( argv[n] + 7 ); continue;
    }
    pch = strstr(argv[n], "-itert=");
    if(pch != NULL) {
      itertile = atoi ( argv[n] + 7 ); continue;
    }
    pch = strstr(argv[n], "-non-copy");
    if(pch != NULL) {
      non_copy = 1; continue;
    }
  }

  nx = logical_size_x;
  ny = logical_size_y;
  nz = logical_size_z;
  ops_printf("Grid: %dx%d in %dx%d in %dz%d blocks, %d iterations, %d tile height\n",logical_size_x,logical_size_y,logical_size_z,ngrid_x,ngrid_y,ngrid_z,n_iter,itertile);
  dx = 1./(float)nx;
  dy = 1./(float)ny;
  dz = 1./(float)nz;
  invdx = 1./dx;
  invdy = 1./dy;
  invdz = 1./dz;
  pml_width = 10;
  xbeg=halff;
  xend=nx-halff;
  ybeg=halff;
  yend=ny-halff;
  zbeg=halff;
  zend=nz-halff;
  xpmlbeg=xbeg+pml_width;
  ypmlbeg=ybeg+pml_width;
  zpmlbeg=zbeg+pml_width;
  xpmlend=xend-pml_width;
  ypmlend=yend-pml_width;
  zpmlend=zend-pml_width;
  ops_decl_const("dx",1,"float",&dx);
  ops_decl_const("dz",1,"float",&dz);
  ops_decl_const("invdx",1,"float",&invdx);
  ops_decl_const("invdy",1,"float",&invdy);
  ops_decl_const("invdz",1,"float",&invdz);
  ops_decl_const("nx",1,"int",&nx);
  ops_decl_const("ny",1,"int",&ny);
  ops_decl_const("nz",1,"int",&nz);
  ops_decl_const("pml_width",1,"int",&pml_width);
  ops_decl_const("xbeg",1,"int",&xbeg);
  ops_decl_const("ybeg",1,"int",&ybeg);
  ops_decl_const("zbeg",1,"int",&zbeg);
  ops_decl_const("xend",1,"int",&xend);
  ops_decl_const("yend",1,"int",&yend);
  ops_decl_const("zend",1,"int",&zend);
  ops_decl_const("xpmlbeg",1,"int",&xpmlbeg);
  ops_decl_const("ypmlbeg",1,"int",&ypmlbeg);
  ops_decl_const("zpmlbeg",1,"int",&zpmlbeg);
  ops_decl_const("xpmlend",1,"int",&xpmlend);
  ops_decl_const("ypmlend",1,"int",&ypmlend);
  ops_decl_const("zpmlend",1,"int",&zpmlend);
  int ncoeffs = (ORDER+1)*(ORDER+1);
  ops_decl_const("coeffs",ncoeffs,"float",&coeffs[0][0]);
  halff = HALF;
  ops_decl_const("halff",1,"int",&halff);
  order = ORDER;
  ops_decl_const("order",1,"int",&order);
  c = &coeffs[halff][halff];
  ops_decl_const("c",order+1,"float",c);
  cx = (float *)malloc((order+1)*sizeof(float));
  cy = (float *)malloc((order+1)*sizeof(float));
  cz = (float *)malloc((order+1)*sizeof(float));
  for (int i = -halff; i <= halff; i++) {
    cx[i+halff] = c[i]*invdx;
    cy[i+halff] = c[i]*invdy;
    cz[i+halff] = c[i]*invdz;
  }
  ops_decl_const("cx",order+1,"float",cx);
  ops_decl_const("cy",order+1,"float",cy);
  ops_decl_const("cz",order+1,"float",cz);
  //declare block
  char buf[50];
  sprintf(buf,"block");
  ops_block blocks = ops_decl_block(3,"block");
  
  //declare stencils
  int s3D_000[]         = {0,0,0};
  ops_stencil S3D_000 = ops_decl_stencil( 3, 1, s3D_000, "000");
  int s3D_7p_sten[]         = {0,0,0, 1,0,0, -1,0,0, 0,1,0, 0,-1,0, 0,0,1, 0,0,-1};
  ops_stencil S3D_7p_sten = ops_decl_stencil( 3, 7, s3D_7p_sten, "7p_sten");
  int s3D_big_sten[3*(ORDER+1)];
  int is = 0;
  for (int ix=-HALF;ix<=HALF;ix++) {
    s3D_big_sten[is] = ix;
    is = is + 1;
    s3D_big_sten[is] = 0;
    is = is + 1;
    s3D_big_sten[is] = 0;
    is = is + 1;
  }
  for (int ix=-HALF;ix<=HALF;ix++) {
    s3D_big_sten[is] = 0;
    is = is + 1;
    s3D_big_sten[is] = ix;
    is = is + 1;
    s3D_big_sten[is] = 0;
    is = is + 1;
  }
  for (int ix=-HALF;ix<=HALF;ix++) {
    s3D_big_sten[is] = 0;
    is = is + 1;
    s3D_big_sten[is] = 0;
    is = is + 1;
    s3D_big_sten[is] = ix;
    is = is + 1;
  }
  ops_stencil S3D_big_sten = ops_decl_stencil( 3, 3*(ORDER+1), s3D_big_sten, "big_sten");

  ops_reduction red_err = ops_decl_reduction_handle(sizeof(float), "float", "err");

  //declare datasets
  int d_p[3] = {HALF,HALF,HALF}; //max halo depths for the dat in the possitive direction
  int d_m[3] = {-HALF,-HALF,-HALF}; //max halo depths for the dat in the negative direction
  int base[3] = {0,0,0};
  int uniform_size[3] = {(logical_size_x-1)/ngrid_x+1,(logical_size_y-1)/ngrid_y+1,(logical_size_z-1)/ngrid_z+1};
  float* temp = NULL;
  int *sizes = (int*)malloc(3*sizeof(int));
  int *disps = (int*)malloc(3*sizeof(int));

  int size[3] = {nx,ny,nz};
	
  sprintf(buf,"coordx");
  ops_dat coordx = ops_decl_dat(blocks, 1, size, base, d_m, d_p, temp, "float", buf);
  sprintf(buf,"coordy");
  ops_dat coordy = ops_decl_dat(blocks, 1, size, base, d_m, d_p, temp, "float", buf);
  sprintf(buf,"coordz");
  ops_dat coordz= ops_decl_dat(blocks, 1, size, base, d_m, d_p, temp, "float", buf);
  sprintf(buf,"rho");
  ops_dat rho = ops_decl_dat(blocks, 1, size, base, d_m, d_p, temp, "float", buf);
  sprintf(buf,"mu");
  ops_dat mu = ops_decl_dat(blocks, 1, size, base, d_m, d_p, temp, "float", buf);
  
  sprintf(buf,"yy");
  ops_dat yy = ops_decl_dat(blocks, 6, size, base, d_m, d_p, temp, "float", buf);
  sprintf(buf,"ytemp");
  ops_dat ytemp = ops_decl_dat(blocks, 6, size, base, d_m, d_p, temp, "float", buf);
  
  sprintf(buf,"k1");
  ops_dat k1 = ops_decl_dat(blocks, 6, size, base, d_m, d_p, temp, "float", buf);
  sprintf(buf,"k2");
  ops_dat k2 = ops_decl_dat(blocks, 6, size, base, d_m, d_p, temp, "float", buf);
  sprintf(buf,"k3");
  ops_dat k3 = ops_decl_dat(blocks, 6, size, base, d_m, d_p, temp, "float", buf);
  sprintf(buf,"k4");
  ops_dat k4 = ops_decl_dat(blocks, 6, size, base, d_m, d_p, temp, "float", buf);
  
  sizes[0] = size[0];
  sizes[1] = size[1];
  sizes[2] = size[2];
  disps[0] = 0;
  disps[1] = 0;
  disps[2] = 0;

  ops_partition("");
  //ops_checkpointing_init("check.h5", 5.0, 0);
  ops_diagnostic_output();
  /**-------------------------- Computations --------------------------**/

  
  double ct0, ct1, et0, et1;
	
  //populate density, bulk modulus, velx, vely, velz, and boundary conditions
	
  int iter_range[] = {0,sizes[0],0,sizes[1],0,sizes[2]};

  ops_par_loop(rtm_kernel_populate, "rtm_kernel_populate", blocks, 3, iter_range,
	       ops_arg_gbl(&disps[0], 1, "int", OPS_READ),
	       ops_arg_gbl(&disps[1], 1, "int", OPS_READ),
	       ops_arg_gbl(&disps[2], 1, "int", OPS_READ),
	       ops_arg_idx(),
	       ops_arg_dat(rho, 1, S3D_000, "float", OPS_WRITE),
	       ops_arg_dat(mu, 1, S3D_000, "float", OPS_WRITE),
	       ops_arg_dat(yy, 6, S3D_000, "float", OPS_WRITE)
	       );

  //printf(" DONE populate\n");
#ifdef PROFILE_ITT
  __itt_resume();
#endif
  ops_timers(&ct0, &et0);
  double it0, it1, it2, it3;
  ops_timers(&ct0, &it0);
  for (int iter = 0; iter < n_iter; iter++) {

    //printf(" iter = %d\n",iter);
    //if (ngrid_x>1 || ngrid_y>1 || ngrid_z>1) ops_halo_transfer(u_halos);
    if (iter%itertile == 0) ops_execute(blocks->instance);

    double ct20, it20, it21, it22, it23;
    //ops_timers(&ct20, &it22);
    /* The following is 4th order Runga-Kutta */
    float dt = 0.5*dx/1.; //c = sqrt(mu/rho), mu = 1 and rho =1 for this problem
    // calc dydt (store it in k1)
    derivs(blocks, S3D_000, S3D_big_sten,
    	   rho, mu, yy, k1);
    //ops_timers(&ct20, &it23);
    //ops_printf("time derivs %lf\n",it23-it22);
    
    //k1 = dt*k1
    //ytemp = yy + k1/2.
    //ops_timers(&ct20, &it20);
    calc_ytemp(blocks, S3D_000, dt,
    	       yy, k1, ytemp); 
	       
    //ops_timers(&ct20, &it21);
    //ops_printf("time ytemp %lf\n",it21-it20);

    // calc dytemp/dt store it in k2
    derivs(blocks, S3D_000, S3D_big_sten,
    	   rho, mu, ytemp, k2);
    //k2 = dt*k2 parallel_loop
    //ytemp = yy + k2/2.
    calc_ytemp(blocks, S3D_000, dt,
    	       yy, k2, ytemp);

    //calc dytemp/dt (stored it in k3)
    derivs(blocks, S3D_000, S3D_big_sten,
    	   rho, mu, ytemp, k3);
    //k3 = k3*dt
    //ytemp = yy + k3
    calc_ytemp2(blocks, S3D_000, dt,
    		yy, k3, ytemp);

    //calc dytemp/dt, stored in k4
    derivs(blocks, S3D_000, S3D_big_sten,
    	   rho, mu, ytemp, k4); 
    //k4 = dt*k4
    //yy = yy + k1/6. + k2/3. + k3/3. + k4/6.
    final_update(blocks, S3D_000, dt,
    		 k1, k2, k3, k4, yy);

    /*
    printf("next_write = %d, write_num = %d\n",next_write,write_num);
    if (iter2 == next_write || iter2 == 0) {
      printf(" WRITING FILE \n");
      FILE* file;
      sprintf(buf,"out%d.dat",write_num);
      file = fopen(buf,"w");
      fprintf(file,"VARIABLES = \"X\", \"Y\", \"Z\", \"PRESS\"\n"); 
      fprintf(file,"ZONE DATAPACKING=POINT, I=%d J=%d K=%d\n",nx,ny,nz); 
      ops_par_loop(rtm_kernel_out, "rtm_kernel_out", blocks, 3, iter_range,
		   ops_arg_gbl(&disps[0], 1, "int", OPS_READ),
		   ops_arg_gbl(&disps[1], 1, "int", OPS_READ),
		   ops_arg_gbl(&disps[2], 1, "int", OPS_READ),
		   ops_arg_idx(),
		   ops_arg_dat(yy, 6, S3D_000, "float", OPS_READ)
		   ops_arg_gbl(file, 1, "FILE", OPS_READ)
		   );
      printf(" FILE WRITTEN \n ");
      fclose(file);
      next_write = next_write+10;
      write_num = write_num+1;
    }
    */ 
    iter2 = iter2 + 1;

  }
  ops_execute(blocks->instance);
  ops_timers(&ct0, &it1);

  //exit(0);

  ops_timers(&ct1, &et1);
#ifdef PROFILE_ITT
  __itt_pause();
#endif
  ops_timing_output(std::cout);
  ops_printf("\nTotal Wall time %lf\n",et1-et0);
  //ops_fetch_block_hdf5_file(blocks, "multidim.h5");
  //ops_fetch_dat_hdf5_file(yy, "multidim.h5");

  ops_printf("%lf\n",it1-it0);
  //#endif  
  ops_exit();
}

void derivs(ops_block blocks, ops_stencil S3D_000, ops_stencil S3D_big_sten,  ops_dat rho, ops_dat mu, ops_dat yy, ops_dat dyy)
{

  int iter_range[] = {xbeg,xend,ybeg,yend,zbeg,zend};
  ops_par_loop(fd3d_pml_kernel, "fd3d_pml_kernel", blocks, 3, iter_range,
	       ops_arg_dat(rho, 1, S3D_000, "float", OPS_READ),
	       ops_arg_dat(mu, 1, S3D_000, "float", OPS_READ),
	       ops_arg_dat(yy, 6, S3D_big_sten, "float", OPS_READ),
	       ops_arg_dat(dyy, 6, S3D_000, "float", OPS_WRITE),
	       ops_arg_idx());
}

void calc_ytemp(ops_block blocks, ops_stencil S3D_000, float dt,
		ops_dat yy, ops_dat k, ops_dat ytemp)
{

  int iter_range[] = {0,nx-1,0,ny-1,0,nz-1};
  ops_par_loop(calc_ytemp_kernel, "calc_ytemp_kernel", blocks, 3, iter_range,
	       ops_arg_idx(),
	       ops_arg_gbl(&dt, 1, "float", OPS_READ),	       
	       ops_arg_dat(yy, 6, S3D_000, "float", OPS_READ),
	       ops_arg_dat(k, 6, S3D_000, "float", OPS_RW),
	       ops_arg_dat(ytemp, 6, S3D_000, "float", OPS_WRITE));
}

void calc_ytemp2(ops_block blocks, ops_stencil S3D_000, float dt,
		 ops_dat yy, ops_dat k, ops_dat ytemp)
{

  int iter_range[] = {0,nx-1,0,ny-1,0,nz-1};
  ops_par_loop(calc_ytemp2_kernel, "calc_ytemp2_kernel", blocks, 3, iter_range,
	       ops_arg_idx(),
	       ops_arg_gbl(&dt, 1, "float", OPS_READ),	       
	       ops_arg_dat(yy, 6, S3D_000, "float", OPS_READ),
	       ops_arg_dat(k, 6, S3D_000, "float", OPS_RW),
	       ops_arg_dat(ytemp, 6, S3D_000, "float", OPS_WRITE));
}

void final_update(ops_block blocks, ops_stencil S3D_000, float dt,
		  ops_dat k1, ops_dat k2, ops_dat k3, ops_dat k4, ops_dat yy)
{

  int iter_range[] = {0,nx-1,0,ny-1,0,nz-1};
  ops_par_loop(final_update_kernel, "final_update_kernel", blocks, 3, iter_range,
	       ops_arg_idx(),
	       ops_arg_gbl(&dt, 1, "float", OPS_READ),	       
	       ops_arg_dat(k1, 6, S3D_000, "float", OPS_READ),
	       ops_arg_dat(k2, 6, S3D_000, "float", OPS_READ),
	       ops_arg_dat(k3, 6, S3D_000, "float", OPS_READ),
	       ops_arg_dat(k4, 6, S3D_000, "float", OPS_RW),
	       ops_arg_dat(yy, 6, S3D_000, "float", OPS_WRITE)
	       );
}  
