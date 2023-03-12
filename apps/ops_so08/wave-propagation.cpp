#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys/time.h"

#define OPS_3D
#include "ops_seq.h"

int X_size;
int Y_size;
int Z_size;
float dt = 0.001, start = 0, stop = 1;  // time variables
int border_size = 10;                    // Abosrbent border
int space_order = 8;                     // Space order
int ii_src[6], u_dim_size;
float p[3], src_value;

#include "wave-propagation-kernels.h"

void initialize_slowness(float* m, int x_size, int y_size, int z_size);
void initialize_damp(float* damp, int x_size, int y_size, int z_size);
void initialize_source(float* src, int T_intervals);
void print_vector(float* vec, int x_limit, int y_limit, int z_limit);
void initialize_source_coordinates(float* src_coords);
void calculate_source_interpolation_position(float* src_coords, float* p, int* ii_src);

int main(int argc, const char* argv[]) {
    int t, T_intervals;
    int size[3], damp_size[3];
    int base[] = {0, 0, 0};
    int d_p[] = {4,4,4};
    int d_m[] = {-4, -4, -4};
    float *u[3]={NULL,NULL,NULL}, *m=NULL, *damp=NULL, *src, src_coords[3];
    char title[30];
    struct timeval start_propagation_section, end_propagation_section;
    double total_time = 0;

    // Read input
    if (argc < 2) {
        printf("Inform grid size\n");
        exit(-1);
    }

    X_size = Y_size = Z_size = atoi(argv[1]) - 2 * border_size - 2 * space_order;

    // Each dimension size. (This is only valid because X, Y, Z have the same size in this example).
    u_dim_size = X_size + 2 * border_size + 2 * space_order;

    size[0] = u_dim_size;
    size[1] = u_dim_size;
    size[2] = u_dim_size;
    damp_size[0] = X_size + 2 * border_size + space_order;
    damp_size[1] = Y_size + 2 * border_size + space_order;
    damp_size[2] = Z_size + 2 * border_size + space_order;

    T_intervals = ceil((stop - start + dt) / dt);
    // printf("T_intervals = %d\n", T_intervals);

    /*****************************************************************************************************************/
    /**************                                 Allocate Memory                                      *************/
    /*****************************************************************************************************************/

  /*  u = (float**)malloc(3 * sizeof(float*));
    u[0] = (float*)calloc((X_size + 2 * border_size + 2 * space_order) * (Y_size + 2 * border_size + 2 * space_order) *
                              (Z_size + 2 * border_size + 2 * space_order),
                          sizeof(float));
    u[1] = (float*)calloc((X_size + 2 * border_size + 2 * space_order) * (Y_size + 2 * border_size + 2 * space_order) *
                              (Z_size + 2 * border_size + 2 * space_order),
                          sizeof(float));
    u[2] = (float*)calloc((X_size + 2 * border_size + 2 * space_order) * (Y_size + 2 * border_size + 2 * space_order) *
                              (Z_size + 2 * border_size + 2 * space_order),
                          sizeof(float));
    m = (float*)malloc((X_size + 2 * border_size + 2 * space_order) * (Y_size + 2 * border_size + 2 * space_order) *
                       (Z_size + 2 * border_size + 2 * space_order) * sizeof(float));
    damp = (float*)calloc((X_size + 2 * border_size + space_order) * (Y_size + 2 * border_size + space_order) *
                              (Z_size + 2 * border_size + space_order),
                          sizeof(float));*/
    src = (float*)malloc(T_intervals * sizeof(float));

    /*****************************************************************************************************************/
    /**************                                 Initialize Vectors                                   *************/
    /*****************************************************************************************************************/

    // Initialize velocity model
  /*  initialize_slowness(m, X_size + 2 * border_size + 2 * space_order, Y_size + 2 * border_size + 2 * space_order,
                        Z_size + 2 * border_size + 2 * space_order);
    // print_vector(m, X_size + 2 * border_size + 2 * space_order, Y_size + 2 * border_size + 2 * space_order,
    //              Z_size + 2 * border_size + 2 * space_order);

    // Initialize Damp
    initialize_damp(damp, X_size + 2 * border_size + space_order, Y_size + 2 * border_size + space_order,
                    Z_size + 2 * border_size + space_order);
    // print_vector(damp, X_size + 2 * border_size + 1 + 1, Y_size + 2 * border_size + 1 + 1,
    //              Z_size + 2 * border_size + 1 + 1);
*/
    // Initialize source
    initialize_source(src, T_intervals);
    src_value = src[0];
    // printf("T_intervals = %d\n", T_intervals);
    // print_vector(src, T_intervals, 0, 0);

    // Initialize source position
    initialize_source_coordinates(src_coords);
    // printf("Src coordinates:%f %f %f\n", src_coords[0], src_coords[1],
    // src_coords[2]);

    // As we have only one source, this is simpler. For multiple sources, this has to be changed later.
    calculate_source_interpolation_position(src_coords, p, ii_src);
    // printf("ii_src: %d %d %d %d %d %d\n", ii_src[0], ii_src[1], ii_src[2], ii_src[3], ii_src[4], ii_src[5]);

    /*****************************************************************************************************************/
    /**************                                 Initialize OPS variables                             *************/
    /*****************************************************************************************************************/

    ops_init(argc, argv, 2);

    // Declare global constant
    ops_decl_const("X_size", 1, "int", &X_size);
    ops_decl_const("Y_size", 1, "int", &Y_size);
    ops_decl_const("Z_size", 1, "int", &Z_size);
    ops_decl_const("border_size", 1, "int", &border_size);
    ops_decl_const("dt", 1, "float", &dt);
    ops_decl_const("u_dim_size", 1, "int", &u_dim_size);
    ops_decl_const("ii_src", 6, "int", ii_src);
    ops_decl_const("p", 3, "float", p);

    // Declare ops_block
    ops_block grid = ops_decl_block(3, "grid");

    // Declare ops_dat objects
    ops_dat dat_ut[3];
    ops_dat dat_m;
    ops_dat dat_damp;
    dat_ut[0] = ops_decl_dat(grid, 1, size, base, d_m, d_p, u[0], "float", "ut0");
    dat_ut[1] = ops_decl_dat(grid, 1, size, base, d_m, d_p, u[1], "float", "ut1");
    dat_ut[2] = ops_decl_dat(grid, 1, size, base, d_m, d_p, u[2], "float", "ut2");
    dat_m = ops_decl_dat(grid, 1, size, base, d_m, d_p, m, "float", "m");
    dat_damp = ops_decl_dat(grid, 1, damp_size, base, d_m, d_p, damp, "float", "damp");

    // Define stencils
    int s3d_000[] = {0, 0, 0};
    int s3d_1pt[] = {-1, -1, -1};
    int s3d_so8[] = {-3, 0, 0, 0, -4, 0,  1, 0, 0,  0, 2, 0,  4, 0, 0,  0, -3, 0, 0, 0,  -1, 0, 0, -2, 0,
                     0,  4, 0, 0, -3, -2, 0, 0, -1, 0, 0, 2,  0, 0, 0,  0, 3,  0, 0, -4, 0,  0, 2, 0,  3,
                     0,  0, 0, 1, -4, 0,  0, 0, 0,  0, 0, -1, 0, 0, -2, 0, 0,  4, 0, 3,  0,  0, 0, 1,  0};

    ops_stencil S3D_000 = ops_decl_stencil(3, 1, s3d_000, "0,0,0");
    ops_stencil S3D_1PT = ops_decl_stencil(3, 1, s3d_1pt, "-1,-1,-1");
    ops_stencil S3D_SO8 = ops_decl_stencil(3, 25, s3d_so8, "so8");

    // Define range of propagation kernel
    int propagation_range[] = {space_order, space_order + X_size + 2 * border_size,
                               space_order, space_order + Y_size + 2 * border_size,
                               space_order, space_order + Z_size + 2 * border_size};
    // printf("%d %d, %d %d, %d %d\n", space_order, space_order + X_size + 2 * border_size, space_order,
    //        space_order + Y_size + 2 * border_size, space_order, space_order + Z_size + 2 * border_size);

    // Define range of injection kernel. That's the interpolation result.
    int injection_range[] = {ii_src[2] + 2,     ii_src[3] + 2 + 1, ii_src[1] + 2,
                             ii_src[4] + 2 + 1, ii_src[0] + 2,     ii_src[5] + 2 + 1};

    // printf("start propagation...\n");

    // Start time
    ops_partition("");

    for (t = 1; t < T_intervals; t++) {
        gettimeofday(&start_propagation_section, NULL);

        ops_par_loop(wave_propagation_kernel, "wave_propagation_kernel", grid, 3, propagation_range,
                     ops_arg_dat(dat_m, 1, S3D_000, "float", OPS_READ),
                     ops_arg_dat(dat_damp, 1, S3D_1PT, "float", OPS_READ),
                     ops_arg_dat(dat_ut[t % 3], 1, S3D_SO8, "float", OPS_READ),          // t0
                     ops_arg_dat(dat_ut[(t + 2) % 3], 1, S3D_000, "float", OPS_READ),    // t2
                     ops_arg_dat(dat_ut[(t + 1) % 3], 1, S3D_000, "float", OPS_WRITE));  // t1
                     
        gettimeofday(&end_propagation_section, NULL);

        total_time += (double)(end_propagation_section.tv_sec - start_propagation_section.tv_sec) +
                      (double)(end_propagation_section.tv_usec - start_propagation_section.tv_usec) / 1000000;

        ops_par_loop(source_injection_kernel, "source_injection_kernel", grid, 3, injection_range,
                     ops_arg_dat(dat_ut[(t + 1) % 3], 1, S3D_000, "float", OPS_WRITE),
                     ops_arg_dat(dat_m, 1, S3D_000, "float", OPS_READ), ops_arg_gbl(&src[t], 1, "float", OPS_READ),
                     ops_arg_idx());
    }

    // End time

    // printf("end propagation\n");

    // Calculated elapsed time
    // double total_time = (double)(end_section.tv_sec - start_section.tv_sec) +
    //                     (double)(end_section.tv_usec - start_section.tv_usec) / 1000000;
    ops_printf("Wave propagation time: %lf\n", total_time);

    // Save output to file.
    // sprintf(title, "output/u_ops_%03d.txt", X_size);
    // ops_print_dat_to_txtfile(dat_ut[t % 3], title);
     ops_timing_output(std::cout);

    ops_exit();


    return 0;
}

/**
 * Initialize slowness vector. In
 * Inverse squared velocity.
 **/
void initialize_slowness(float* m, int x_size, int y_size, int z_size) {
    // Initialize velocoty model.
    for (int z = 0; z < z_size; z++) {
        for (int j = 0; j < y_size; j++) {
            for (int i = 0; i < x_size; i++) {
                m[i + j * x_size + z * x_size * y_size] = 0.25;
            }
        }
    }
}

/**
 * Initializes damp vector.
 **/
void initialize_damp(float* damp, int x_size, int y_size, int z_size) {
    float dampcoeff;
    float pos;
    float val;

    dampcoeff = 0.2590408229618301;  // 1.5 * log(1.0 / 0.001) / (40.)

    for (int dim = 0; dim < 3; dim++) {
        for (int border = 0; border < border_size; border++) {
            pos = abs((border_size - border + 1) / (float)border_size);
            val = dampcoeff * (pos - sin(2 * M_PI * pos) / (2 * M_PI));

            for (int k = 1; k < z_size - 1; k++) {
                for (int j = 1; j < y_size - 1; j++) {
                    for (int i = 1; i < x_size - 1; i++) {
                        // Left slice
                        if ((dim == 0 && i == border + 1) || (dim == 1 && j == border + 1) ||
                            (dim == 2 && k == border + 1)) {
                            damp[i + j * x_size + k * x_size * y_size] += val;
                        }

                        // Right slice
                        if ((dim == 0 && i == x_size - border - 1) || (dim == 1 && j == y_size - border - 1) ||
                            (dim == 2 && k == z_size - border - 1)) {
                            damp[i + j * x_size + k * x_size * y_size] += val;
                        }
                    }
                }
            }
        }
    }

    // Pad edge
    int new_i, new_j, new_k;
    for (int k = 0; k < z_size; k++) {
        for (int j = 0; j < y_size; j++) {
            for (int i = 0; i < x_size; i++) {
                if ((i < 1 || i > X_size + 2 * border_size) || (j < 1 || j > Y_size + 2 * border_size) ||
                    (k < 1 || k > Z_size + 2 * border_size)) {
                    new_i = i < 1 ? i + 1 : i > x_size - 2 ? i - 1 : i;
                    new_j = j < 1 ? j + 1 : j > y_size - 2 ? j - 1 : j;
                    new_k = k < 1 ? k + 1 : k > z_size - 2 ? k - 1 : k;

                    // printf("(%d %d %d) -> (%d %d %d)\n", new_i, new_j, new_k, i, j, k);
                    damp[i + j * x_size + k * x_size * y_size] = damp[new_i + new_j * x_size + new_k * x_size * y_size];
                }
            }
        }
    }
}

/**
 * Initialize source with a Ricker Source.
 **/
void initialize_source(float* src, int total_time) {
    float f0 = 0.1;  // Peak frequency
    float r;
    // double sigma = 1.0 / (M_PI * f0 * sqrt(2.0));
    // double t0 = 6.0 * sigma;

    for (int t = 0; t < total_time; t++) {
        // float r = (M_PI * f0 * (t * dt - t0)) * (M_PI * f0 * (t * dt - t0));
        // src[t] = (1 - 2.0 * r) * exp(-r);
        r = (M_PI * f0 * (t * dt - 1 / f0));
        src[t] = (1 - 2 * r * r) * exp(-r * r);
    }
}

/**
 * Initializes the sources coordinates.
 * This example only has one source, so the initialization is simple, but in the
 *future it will handle multiple sources. The current source is intialize in the
 *middle top of the volume.
 **/
void initialize_source_coordinates(float* src_coords) {
    src_coords[0] = (float)(X_size - 1) / (float)2;
    src_coords[1] = (float)(Y_size - 1) / (float)2;
    src_coords[2] = (float)1.;
}

/**
 * @brief  Calculates the source interpolation.
 * @note
 * @param  *src_coords: Source coordinates defined in other system.
 * @param  *p: [output] source center position.
 * @param  *ii_src: [output] Interpolation position.
 * @retval None
 */
void calculate_source_interpolation_position(float* src_coords, float* p, int* ii_src) {
    // source injection interpolation
    float r1 = (int)(floor(-1.0F * -border_size + 1.0F * src_coords[0]));
    ii_src[0] = r1;
    float r2 = (int)(floor(-1.0F * -border_size + 1.0F * src_coords[1]));
    ii_src[1] = r2;
    float r3 = (int)(floor(-1.0F * -border_size + 1.0F * src_coords[2]));
    ii_src[2] = r3;
    ii_src[3] = r3 + 1;
    ii_src[4] = r2 + 1;
    ii_src[5] = r1 + 1;
    p[0] = (float)(border_size - 1.0F * r1 + src_coords[0]);
    p[1] = (float)(border_size - 1.0F * r2 + src_coords[1]);
    p[2] = (float)(border_size - 1.0F * r3 + src_coords[2]);
}

/**
 * Print a 3d vector with the given size.
 * For debug porporse.
 *
 **/
void print_vector(float* vec, int x_limit, int y_limit, int z_limit) {
    ops_printf("Vector of dimensions: %d %d %d\n", x_limit, y_limit, z_limit);

    for (int k = 0; k < (z_limit == 0 ? 1 : z_limit); k++) {
        for (int j = 0; j < (y_limit == 0 ? 1 : y_limit); j++) {
            for (int i = 0; i < (x_limit == 0 ? 1 : x_limit); i++) {
                ops_printf("%.6e ", vec[i + j * x_limit + k * x_limit * y_limit]);
            }
            ops_printf("\n");
        }
        ops_printf("\n");
    }

    ops_printf("\n\n");
}
