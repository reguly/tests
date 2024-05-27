ops_dat p_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
p_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "p_B0");
}
ops_dat Residual0_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
Residual0_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "Residual0_B0");
}
ops_dat Residual1_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
Residual1_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "Residual1_B0");
}
ops_dat Residual2_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
Residual2_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "Residual2_B0");
}
ops_dat Residual3_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
Residual3_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "Residual3_B0");
}
ops_dat Residual4_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
Residual4_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "Residual4_B0");
}
ops_dat rho_B0;
{
if (restart == 1){
rho_B0 = ops_decl_dat_hdf5(opensbliblock00, 1, "float", "rho_B0", "restart.h5");
}
else {
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
rho_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "rho_B0");
}
}
ops_dat rho_RKold_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
rho_RKold_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "rho_RKold_B0");
}
ops_dat rhoE_B0;
{
if (restart == 1){
rhoE_B0 = ops_decl_dat_hdf5(opensbliblock00, 1, "float", "rhoE_B0", "restart.h5");
}
else {
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
rhoE_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "rhoE_B0");
}
}
ops_dat rhoE_RKold_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
rhoE_RKold_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "rhoE_RKold_B0");
}
ops_dat rhou0_B0;
{
if (restart == 1){
rhou0_B0 = ops_decl_dat_hdf5(opensbliblock00, 1, "float", "rhou0_B0", "restart.h5");
}
else {
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
rhou0_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "rhou0_B0");
}
}
ops_dat rhou0_RKold_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
rhou0_RKold_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "rhou0_RKold_B0");
}
ops_dat rhou1_B0;
{
if (restart == 1){
rhou1_B0 = ops_decl_dat_hdf5(opensbliblock00, 1, "float", "rhou1_B0", "restart.h5");
}
else {
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
rhou1_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "rhou1_B0");
}
}
ops_dat rhou1_RKold_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
rhou1_RKold_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "rhou1_RKold_B0");
}
ops_dat rhou2_B0;
{
if (restart == 1){
rhou2_B0 = ops_decl_dat_hdf5(opensbliblock00, 1, "float", "rhou2_B0", "restart.h5");
}
else {
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
rhou2_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "rhou2_B0");
}
}
ops_dat rhou2_RKold_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
rhou2_RKold_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "rhou2_RKold_B0");
}
ops_dat T_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
T_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "T_B0");
}
ops_dat u0_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
u0_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "u0_B0");
}
ops_dat u1_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
u1_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "u1_B0");
}
ops_dat u2_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
float* value = NULL;
u2_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "float", "u2_B0");
}
ops_dat wk0_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk0_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk0_B0");
}
ops_dat wk10_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk10_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk10_B0");
}
ops_dat wk11_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk11_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk11_B0");
}
ops_dat wk12_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk12_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk12_B0");
}
ops_dat wk13_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk13_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk13_B0");
}
ops_dat wk14_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk14_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk14_B0");
}
ops_dat wk15_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk15_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk15_B0");
}
ops_dat wk16_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk16_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk16_B0");
}
ops_dat wk17_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk17_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk17_B0");
}
ops_dat wk18_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk18_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk18_B0");
}
ops_dat wk19_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk19_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk19_B0");
}
ops_dat wk1_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk1_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk1_B0");
}
ops_dat wk20_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk20_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk20_B0");
}
ops_dat wk21_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk21_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk21_B0");
}
ops_dat wk22_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk22_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk22_B0");
}
ops_dat wk23_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk23_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk23_B0");
}
ops_dat wk24_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk24_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk24_B0");
}
ops_dat wk25_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk25_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk25_B0");
}
ops_dat wk26_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk26_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk26_B0");
}
ops_dat wk27_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk27_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk27_B0");
}
ops_dat wk28_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk28_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk28_B0");
}
ops_dat wk29_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk29_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk29_B0");
}
ops_dat wk2_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk2_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk2_B0");
}
ops_dat wk30_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk30_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk30_B0");
}
ops_dat wk31_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk31_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk31_B0");
}
ops_dat wk32_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk32_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk32_B0");
}
ops_dat wk33_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk33_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk33_B0");
}
ops_dat wk34_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk34_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk34_B0");
}
ops_dat wk35_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk35_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk35_B0");
}
ops_dat wk36_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk36_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk36_B0");
}
ops_dat wk37_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk37_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk37_B0");
}
ops_dat wk38_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk38_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk38_B0");
}
ops_dat wk39_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk39_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk39_B0");
}
ops_dat wk3_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk3_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk3_B0");
}
ops_dat wk40_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk40_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk40_B0");
}
ops_dat wk41_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk41_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk41_B0");
}
ops_dat wk42_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk42_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk42_B0");
}
ops_dat wk43_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk43_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk43_B0");
}
ops_dat wk44_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk44_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk44_B0");
}
ops_dat wk4_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk4_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk4_B0");
}
ops_dat wk5_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk5_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk5_B0");
}
ops_dat wk6_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk6_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk6_B0");
}
ops_dat wk7_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk7_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk7_B0");
}
ops_dat wk8_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk8_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk8_B0");
}
ops_dat wk9_B0;
{
int halo_p[] = {5, 5, 5};
int halo_m[] = {-5, -5, -5};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
half* value = NULL;
wk9_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "half", "wk9_B0");
}
