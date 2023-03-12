#ifndef WAVE_PROPAGATION_KERNELS_H
#define WAVE_PROPAGATION_KERNELS_H

void wave_propagation_kernel(const float *mx0, const float *dampx0, const float *ut00, const float *ut20, float *ut10) {
/*    float r0 = 5.0e-1F * dt * dampx0[OPS_ACC1(0, 0, 0)] + 1.0F * mx0[OPS_ACC0(0, 0, 0)];
    float r1 =
        1.75609756e-1F * dt * dampx0[OPS_ACC1(0, 0, 0)] * ut20[OPS_ACC3(0, 0, 0)] +
        (dt * dt) * (5.6195122e-1F * (ut00[OPS_ACC2(-1, 0, 0)] + ut00[OPS_ACC2(0, -1, 0)] + ut00[OPS_ACC2(0, 0, -1)] +
                                      ut00[OPS_ACC2(0, 0, 1)] + ut00[OPS_ACC2(0, 1, 0)] + ut00[OPS_ACC2(1, 0, 0)]) -
                     7.02439024e-2F * (ut00[OPS_ACC2(-2, 0, 0)] + ut00[OPS_ACC2(0, -2, 0)] + ut00[OPS_ACC2(0, 0, -2)] +
                                       ut00[OPS_ACC2(0, 0, 2)] + ut00[OPS_ACC2(0, 2, 0)] + ut00[OPS_ACC2(2, 0, 0)]) +
                     8.91986063e-3F * (ut00[OPS_ACC2(-3, 0, 0)] + ut00[OPS_ACC2(0, -3, 0)] + ut00[OPS_ACC2(0, 0, -3)] +
                                       ut00[OPS_ACC2(0, 0, 3)] + ut00[OPS_ACC2(0, 3, 0)] + ut00[OPS_ACC2(3, 0, 0)]) -
                     6.271777e-4F * (ut00[OPS_ACC2(-4, 0, 0)] + ut00[OPS_ACC2(0, -4, 0)] + ut00[OPS_ACC2(0, 0, -4)] +
                                     ut00[OPS_ACC2(0, 0, 4)] + ut00[OPS_ACC2(0, 4, 0)] + ut00[OPS_ACC2(4, 0, 0)]) -
                     3.0F * ut00[OPS_ACC2(0, 0, 0)]) +
        7.02439024e-1F * mx0[OPS_ACC0(0, 0, 0)] * ut00[OPS_ACC2(0, 0, 0)] -
        3.51219512e-1F * mx0[OPS_ACC0(0, 0, 0)] * ut20[OPS_ACC3(0, 0, 0)];
    ut10[OPS_ACC4(0, 0, 0)] = 2.84722222F * r1 / r0;
*/
float r15 = 1.0/dt;
          float r14 = 1.0/(dt*dt);
          float r13 = 1.0/(mx0[OPS_ACC0(0, 0, 0)]*mx0[OPS_ACC0(0, 0, 0)]);
          ut10[OPS_ACC4(0, 0, 0)] = (r13*(-r14*(-2.0F*ut00[OPS_ACC2(0, 0, 0)] + ut20[OPS_ACC3(0, 0, 0)])) + r15*(dampx0[OPS_ACC1(0, 0, 0)]*ut00[OPS_ACC2(0, 0, 0)]) - 7.93650813e-6F*(ut00[OPS_ACC2(-4, 0, 0)] + ut00[OPS_ACC2(0,-4, 0)] + ut00[OPS_ACC2(-4,0,0)] + ut00[OPS_ACC2(4, 0, 0)] + ut00[OPS_ACC2(0,4,0)] + ut00[OPS_ACC2(0, 0, 4)]) + 1.12874782e-4F*(ut00[OPS_ACC2(0, 0, -3)] + ut00[OPS_ACC2(0, -3, 0)] + ut00[OPS_ACC2(-3, 0, 0)] + ut00[OPS_ACC2(3, 0, 0)] + ut00[OPS_ACC2(0, 3, 0)] + ut00[OPS_ACC2(0,0, 3)]) - 8.8888891e-4F*(ut00[OPS_ACC2(0, 0, -2)] + ut00[OPS_ACC2(0, -2,0)] + ut00[OPS_ACC2(-2, 0, 0)] + ut00[OPS_ACC2(0, 0, 2)] + ut00[OPS_ACC2(0, 2, 0)] + ut00[OPS_ACC2(2, 0, 0)]) + 7.11111128e-3F*(ut00[OPS_ACC2(0, 0, -1)] + ut00[OPS_ACC2(0, -1, 0)] + ut00[OPS_ACC2(-1, 0, 0)] + ut00[OPS_ACC2(1, 0, 0)] + ut00[OPS_ACC2(0, 1, 0)] + ut00[OPS_ACC2(0, 0, 1)]) - 3.79629639e-2F*ut00[OPS_ACC2(0, 0, 0)])/(r13*r14 + r15*dampx0[OPS_ACC1(0, 0, 0)]);

}

void source_injection_kernel(float *u, const float *m, const float *src_value, const int *idx) {
    if (idx[2] == ii_src[0] + 2 && idx[1] == ii_src[1] + 2 && idx[0] == ii_src[2] + 2) {
        float r7 = 2.2801e-2F *
                   (-1.0F * p[0] * p[1] * p[2] + 1.0F * p[0] * p[1] + 1.0F * p[0] * p[2] - 1.0F * p[0] +
                    1.0F * p[1] * p[2] - 1.0F * p[1] - 1.0F * p[2] + 1) *
                   src_value[0] / m[OPS_ACC1(0, 0, 0)];
        // printf("u[%d][%d][%d]=%f\n", idx[0], idx[1], idx[2], r7);
        u[OPS_ACC0(0, 0, 0)] += r7;
    } else if (idx[2] == ii_src[0] + 2 && idx[1] == ii_src[1] + 2 && idx[0] == ii_src[3] + 2) {
        float r11 = 2.2801e-2F * (1.0F * p[0] * p[1] * p[2] - 1.0F * p[0] * p[2] - 1.0F * p[1] * p[2] + 1.0F * p[2]) *
                    src_value[0] / m[OPS_ACC1(0, 0, 0)];
        // printf("u[%d][%d][%d]=%f\n", idx[0], idx[1], idx[2], r11);
        u[OPS_ACC0(0, 0, 0)] += r11;
    } else if (idx[2] == ii_src[0] + 2 && idx[1] == ii_src[4] + 2 && idx[0] == ii_src[2] + 2) {
        float r15 = 2.2801e-2F * (1.0F * p[0] * p[1] * p[2] - 1.0F * p[0] * p[1] - 1.0F * p[1] * p[2] + 1.0F * p[1]) *
                    src_value[0] / m[OPS_ACC1(0, 0, 0)];
        // printf("u[%d][%d][%d]=%f\n", idx[0], idx[1], idx[2], r15);
        u[OPS_ACC0(0, 0, 0)] += r15;
    } else if (idx[2] == ii_src[0] + 2 && idx[1] == ii_src[4] + 2 && idx[0] == ii_src[3] + 2) {
        float r19 =
            2.2801e-2F * (-1.0F * p[0] * p[1] * p[2] + 1.0F * p[1] * p[2]) * src_value[0] / m[OPS_ACC1(0, 0, 0)];
        // printf("u[%d][%d][%d]=%f\n", idx[0], idx[1], idx[2], r19);
        u[OPS_ACC0(0, 0, 0)] += r19;
    } else if (idx[2] == ii_src[5] + 2 && idx[1] == ii_src[1] + 2 && idx[0] == ii_src[2] + 2) {
        float r23 = 2.2801e-2F * (1.0F * p[0] * p[1] * p[2] - 1.0F * p[0] * p[1] - 1.0F * p[0] * p[2] + 1.0F * p[0]) *
                    src_value[0] / m[OPS_ACC1(0, 0, 0)];
        // printf("u[%d][%d][%d]=%f\n", idx[0], idx[1], idx[2], r23);
        u[OPS_ACC0(0, 0, 0)] += r23;
    } else if (idx[2] == ii_src[5] + 2 && idx[1] == ii_src[1] + 2 && idx[0] == ii_src[3] + 2) {
        float r27 =
            2.2801e-2F * (-1.0F * p[0] * p[1] * p[2] + 1.0F * p[0] * p[2]) * src_value[0] / m[OPS_ACC1(0, 0, 0)];
        // printf("u[%d][%d][%d]=%f\n", idx[0], idx[1], idx[2], r27);
        u[OPS_ACC0(0, 0, 0)] += r27;
    } else if (idx[2] == ii_src[5] + 2 && idx[1] == ii_src[4] + 2 && idx[0] == ii_src[2] + 2) {
        float r31 =
            2.2801e-2F * (-1.0F * p[0] * p[1] * p[2] + 1.0F * p[0] * p[1]) * src_value[0] / m[OPS_ACC1(0, 0, 0)];
        // printf("u[%d][%d][%d]=%f\n", idx[0], idx[1], idx[2], r31);
        u[OPS_ACC0(0, 0, 0)] += r31;
    } else if (idx[2] == ii_src[5] + 2 && idx[1] == ii_src[4] + 2 && idx[0] == ii_src[3] + 2) {
        float r35 = 2.2801e-2F * p[0] * p[1] * p[2] * src_value[0] / m[OPS_ACC1(0, 0, 0)];
        // printf("u[%d][%d][%d]=%f\n", idx[0], idx[1], idx[2], r35);
        u[OPS_ACC0(0, 0, 0)] += r35;
    }
}

#endif
