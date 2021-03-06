/*
 * FMMV - the Fastest Multipole Method of Vienna
 * Copyright (c) 2006-2015 Harald Hofstaetter
 * http://www.harald-hofstaetter.at
 * 
 * This file is part of FMMV.
 * 
 * FMMV is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * FMMV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with FMMV; if not, write to the Free Software  Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 */

#include<math.h>
#include"_fmmv.h"

#include "simd.h"
#if (FMM_PRECISION==0)
   #include"simd4s.h"
#else
   #include"simd4d.h"
#endif

#define V4_IS_ZERO(q) ((((V4_BASETYPE *)(&(q)))[0]==0)&& \
                       (((V4_BASETYPE *)(&(q)))[1]==0)&& \
                       (((V4_BASETYPE *)(&(q)))[2]==0)&& \
                       (((V4_BASETYPE *)(&(q)))[3]==0)) 


extern void (*compute_spherical_harmonics_simd4[])(int p, V4_BASETYPE *Y, V4_TYPE sin_phi, V4_TYPE cos_phi, V4_TYPE cos_theta);
extern void bessel_i_scaled_simd4(V4_TYPE x, V4_BASETYPE i[], int n, int n1);
extern void bessel_k_scaled_simd4(V4_TYPE x, V4_BASETYPE k[], int n);

extern void core_gen_M_L_simd4(int p, V4_BASETYPE *RR, V4_TYPE q, V4_BASETYPE *Y, V4_BASETYPE *M);
extern void core_gen_M_L_dipole_minus_simd4(int p, V4_BASETYPE *RR, V4_TYPE mx, V4_TYPE my, V4_TYPE mz, V4_BASETYPE *Y, V4_BASETYPE *M);
extern void core_gen_M_L_dipole_plus_simd4(int p, V4_BASETYPE *RR, V4_TYPE mx, V4_TYPE my, V4_TYPE mz, V4_BASETYPE *Y, V4_BASETYPE *M);

extern V4_TYPE core_eval_L_M_simd4(int p, V4_BASETYPE *RR, V4_BASETYPE *L, V4_BASETYPE *Y);
extern void core_eval_L_M_grad_minus_simd4(int p, V4_BASETYPE *RR, V4_BASETYPE *L, V4_BASETYPE *Y, V4_TYPE *dx, V4_TYPE *dy, V4_TYPE *dz);
extern void core_eval_L_M_grad_plus_simd4(int p, V4_BASETYPE *RR, V4_BASETYPE *L, V4_BASETYPE *Y, V4_TYPE *dx, V4_TYPE *dy, V4_TYPE *dz);


#if (FMM_PRECISION==0)
   #define FF FF_single
   #define FF_INV FF_INV_single
   #define R R_single
#endif

extern _FLOAT_ FF[];
extern _FLOAT_ FF_INV[];
extern _FLOAT_ R[];   


void gen_M_base_simd4(FmmvHandle *FMMV, Box *box, V4_TYPE x, V4_TYPE y, V4_TYPE z, V4_TYPE q, V4_TYPE mx, V4_TYPE my, V4_TYPE mz, int dipole)
{
	int p = FMMV->pM;
        V4_BASETYPE beta = FMMV->beta;

	V4_TYPE rho, sin_phi, cos_phi, one_over_rho_sin_theta, cos_theta, scale, rho_scale;
        SIMD_ALIGN V4_BASETYPE Y[4*(FMM_P_MAX + 1) * (FMM_P_MAX + 2)];
        SIMD_ALIGN V4_BASETYPE RR[4*(2*FMM_P_MAX+2)];
	V4_BASETYPE *M;
	int k;
	V4_TYPE mx_m, my_m, mz_m;
	V4_TYPE mx_p, my_p, mz_p;
	
	M = box->M;

	scale = V4_SET1(ldexp(1.0, box->level));

	rho = V4_SQRT(V4_FMA(x, x, V4_FMA(y, y, V4_MUL(z, z))));
        one_over_rho_sin_theta = V4_RECIP_SQRT(V4_FMA(x, x, V4_MUL(y, y)));
        sin_phi = V4_MUL(y, one_over_rho_sin_theta);
        cos_phi = V4_MUL(x, one_over_rho_sin_theta);
	cos_theta = V4_DIV(z, rho);


        if (beta==0.0) {
		    compute_spherical_harmonics_simd4[p](p, Y, V4_NEG(sin_phi), cos_phi, cos_theta);
                    rho_scale = V4_MUL(rho, scale);
                    //RR[0] = V4_SET1(0.0);
                    V4_SETITEM(RR, 0, V4_SET1(0.0));
                    //RR[1] = V4_SET1(1.0);
                    V4_SETITEM(RR, 4, V4_SET1(1.0));
                    //RR[2] = rho_scale;
                    V4_SETITEM(RR, 8, rho_scale);
                    for (k=2; k<=p+1; k++) {
                        //RR[k+1] = V4_MUL(RR[k], rho_scale);
                        V4_SETITEM(RR, 4*(k+1), V4_MUL(V4_GETITEM(RR, 4*k), rho_scale));
                    }  

		    if (!V4_IS_ZERO(q)) {
			    core_gen_M_L_simd4(p, RR+4, q, Y, M); 
		    }
		    if (dipole) {
                            mx = V4_MUL(mx, scale);
                            my = V4_MUL(my, scale);
                            mz = V4_MUL(mz, scale);
			    core_gen_M_L_dipole_minus_simd4(p, RR, mx, my, mz, Y, M);
		    }
        }
        else {
                    V4_TYPE h;
                    SIMD_ALIGN V4_BASETYPE scale_0[4*(FMM_P_MAX+1)];
                    V4_TYPE rho_beta = V4_MUL(rho, V4_SET1(beta));
		    
		    if (dipole) {
                            SIMD_ALIGN V4_BASETYPE scale_m[4*(FMM_P_MAX+1)];
                            SIMD_ALIGN V4_BASETYPE scale_p[4*(FMM_P_MAX+1)];
                            V4_TYPE rho_beta2 = V4_MUL (rho_beta,rho_beta);

		            //compute_spherical_harmonics[p+1](p+1, Y, V4_NEG(sin_phi), cos_phi, cos_theta);
                            //bessel_i_scaled(rho_beta, RR, p+2, 2*p+4);
		            compute_spherical_harmonics_simd4[p](p, Y, V4_NEG(sin_phi), cos_phi, cos_theta);
                            bessel_i_scaled_simd4(rho_beta, RR, p+1, 2*p+2);

                            rho_scale = V4_MUL(rho, scale);
                            h = rho_scale;
    
                            //scale_0[0] = V4_MUL(RR[0], V4_SET1(FF[0]));
                            V4_SETITEM(scale_0, 0, V4_MUL(V4_GETITEM(RR, 0), V4_SET1(FF[0])));
                            //scale_0[1] = V4_MUL(RR[1], V4_MUL(h, V4_SET1(FF[1])));
                            V4_SETITEM(scale_0, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 4),h), V4_SET1(FF[1])));
		            //scale_m[0] = V4_SET1(0);
                            V4_SETITEM(scale_m, 0, V4_SET1(0));
                            //scale_p[0] = V4_MUL(RR[1], V4_SET1(FF[0])); 
                            V4_SETITEM(scale_p, 0, V4_MUL(V4_GETITEM(RR, 4), V4_SET1(FF[0]))); 
		            //scale_m[1] = V4_MUL(V4_MUL(RR[0], h),V4_SET1(FF[1]*R[3])); 
		            V4_SETITEM(scale_m, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), h),V4_SET1(FF[1]*R[3]))); 
                            //scale_p[1] = V4_MUL(V4_MUL(RR[2], h),V4_SET1(FF[1]*R[3]));
                            V4_SETITEM(scale_p, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 8), h),V4_SET1(FF[1]*R[3])));
    
		            for (k=2;k<=p; k++){	
                                h = V4_MUL(h, rho_scale);
                                //scale_0[k] = V4_MUL(V4_MUL(RR[k], h), V4_SET1(FF[k]));
                                V4_SETITEM(scale_0, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*k), h), V4_SET1(FF[k])));
		                //scale_m[k] = V4_MUL(V4_MUL(RR[k-1], h), V4_SET1(FF[k]*R[2*k+1]));
		                V4_SETITEM(scale_m, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*(k-1)), h), V4_SET1(FF[k]*R[2*k+1])));
		                //scale_p[k] = V4_MUL(V4_MUL(RR[k+1], h), V4_SET1(FF[k]*R[2*k+1]));
		                V4_SETITEM(scale_p, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*(k+1)), h), V4_SET1(FF[k]*R[2*k+1])));
	                    }	

			    mx_m = V4_MUL(mx, V4_SET1(beta));
			    my_m = V4_MUL(my, V4_SET1(beta));
			    mz_m = V4_MUL(mz, V4_SET1(beta));
                            mx_p = V4_NEG(V4_MUL(mx_m, rho_beta2));
                            my_p = V4_NEG(V4_MUL(my_m, rho_beta2));
                            mz_p = V4_NEG(V4_MUL(mz_m, rho_beta2));
                            
			    core_gen_M_L_dipole_minus_simd4(p, scale_m, mx_m, my_m, mz_m, Y, M);
			    //core_gen_M_L_dipole_plus_simd4(p, scale_p, mx_p, my_p, mz_p, Y, M);
			    core_gen_M_L_dipole_plus_simd4(p-1, scale_p, mx_p, my_p, mz_p, Y, M);

		            if (!V4_IS_ZERO(q)) { 
			         core_gen_M_L_simd4(p, scale_0, V4_MUL(rho_beta,q), Y, M);
		            }
		    }
                    else if (!V4_IS_ZERO(q)) { 
		            compute_spherical_harmonics_simd4[p](p, Y, V4_NEG(sin_phi), cos_phi, cos_theta);
                            bessel_i_scaled_simd4(rho_beta, RR, p+1, 2*p+2);

                            rho_scale = V4_MUL(rho, scale);
                            h = rho_scale;

                            //scale_0[0] = V4_MUL(RR[0], V4_SET1(FF[0]));
                            V4_SETITEM(scale_0, 0, V4_MUL(V4_GETITEM(RR, 0), V4_SET1(FF[0])));
                            //scale_0[1] = V4_MUL(V4_MUL(RR[1],h), V4_SET1(FF[1]));
                            V4_SETITEM(scale_0, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 4),h), V4_SET1(FF[1])));

		            for (k=2;k<=p; k++){	
                                h = V4_MUL(h, rho_scale);
                                //scale_0[k] = V4_MUL(V4_MUL(RR[k], h), V4_SET1(FF[k]));
                                V4_SETITEM(scale_0, 4*k,  V4_MUL(V4_MUL(V4_GETITEM(RR, 4*k), h), V4_SET1(FF[k])));
	                    }	

		            core_gen_M_L_simd4(p, scale_0, V4_MUL(rho_beta, q), Y, M);
                    }
        }    
}

void gen_L_base_simd4(FmmvHandle *FMMV, Box *target, V4_TYPE x, V4_TYPE y, V4_TYPE z, V4_TYPE q, V4_TYPE mx, V4_TYPE my, V4_TYPE mz, int dipole)
{
	int p = FMMV->pL;
        V4_BASETYPE beta = FMMV->beta;

	V4_TYPE one_over_rho_scale;
	V4_TYPE rho, one_over_rho, sin_phi, cos_phi, one_over_rho_sin_theta, cos_theta, h, scale, inv_scale;
	SIMD_ALIGN V4_BASETYPE Y[4*(FMM_P_MAX+2)*(FMM_P_MAX+3)];
        SIMD_ALIGN V4_BASETYPE RR[4*(FMM_P_MAX+2)];
	V4_BASETYPE  *L;
	int k;
	
	scale = V4_SET1(ldexp(1.0, target->level));
	inv_scale = V4_SET1(ldexp(1.0, -target->level));

	L = target->L;

        rho = V4_SQRT(V4_FMA(x, x, V4_FMA(y, y, V4_MUL(z, z))));
	one_over_rho = V4_DIV(V4_SET1(1.0), rho);
        one_over_rho_sin_theta = V4_RECIP_SQRT(V4_FMA(x, x, V4_MUL(y, y)));
        sin_phi = V4_MUL(y, one_over_rho_sin_theta);
        cos_phi = V4_MUL(x, one_over_rho_sin_theta);
	cos_theta = V4_MUL(z, one_over_rho);

        if(dipole) {
		compute_spherical_harmonics_simd4[p+1](p+1, Y, V4_NEG(sin_phi), cos_phi, cos_theta);
        }
        else{
		compute_spherical_harmonics_simd4[p](p, Y, V4_NEG(sin_phi), cos_phi, cos_theta);
        }

        if (beta==0.0) {
                    one_over_rho_scale = V4_MUL(one_over_rho, inv_scale);
                    //RR[0] = one_over_rho_scale;
                    V4_SETITEM(RR, 0, one_over_rho_scale);
                    for (k=1; k<=p+1; k++) {
                        //RR[k] = V4_MUL(RR[k-1], one_over_rho_scale);
                        V4_SETITEM(RR, 4*k, V4_MUL(V4_GETITEM(RR, 4*(k-1)), one_over_rho_scale));
                    }    

		    if (!V4_IS_ZERO(q)) { 
			    core_gen_M_L_simd4(p, RR, V4_MUL(q, scale), Y, L);
		    }	
		    if (dipole) {
	                    V4_TYPE scale2 = V4_SET1(ldexp(1.0, 2*target->level));
			    mx =V4_MUL(mx, scale2); 
			    my =V4_MUL(my, scale2); 
			    mz =V4_MUL(mz, scale2); 
			    core_gen_M_L_dipole_plus_simd4(p, RR+4, mx, my, mz, Y, L); 
		    }	
        }
        else {
              SIMD_ALIGN V4_BASETYPE scale_0[4*(FMM_P_MAX+1)];

              if (dipole) {
                    V4_TYPE c_m, c_p;
                    SIMD_ALIGN V4_BASETYPE scale_m[4*(FMM_P_MAX+1)];
                    SIMD_ALIGN V4_BASETYPE scale_p[4*(FMM_P_MAX+1)];

                    bessel_k_scaled_simd4(V4_MUL(rho,V4_SET1(beta)), RR, p+2);

                    one_over_rho_scale = V4_MUL(one_over_rho, inv_scale);
                    h = V4_MUL(one_over_rho_scale, one_over_rho_scale); 

                    //scale_0[0] = V4_MUL(V4_MUL(RR[0], one_over_rho_scale), V4_SET1(FF_INV[0]));
                    V4_SETITEM(scale_0, 0, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), one_over_rho_scale), V4_SET1(FF_INV[0])));
                    //scale_0[1] = V4_MUL(V4_MUL(RR[1], h), V4_SET1(FF_INV[1]*3.0));
                    V4_SETITEM(scale_0, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 4), h), V4_SET1(FF_INV[1]*3.0)));
		    //scale_m[0] = V4_SET1(0.0);
		    V4_SETITEM(scale_m, 0, V4_SET1(0.0));
                    //scale_p[0] = V4_MUL(V4_MUL(RR[1], one_over_rho_scale), V4_SET1(FF_INV[0])); 
                    V4_SETITEM(scale_p, 0, V4_MUL(V4_MUL(V4_GETITEM(RR, 4), one_over_rho_scale), V4_SET1(FF_INV[0]))); 
		    //scale_m[1] = V4_MUL(V4_MUL(RR[0], h), V4_SET1(FF_INV[1]));
		    V4_SETITEM(scale_m, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), h), V4_SET1(FF_INV[1])));
                    //scale_p[1] = V4_MUL(V4_MUL(RR[2], h), V4_SET1(FF_INV[1]));
                    V4_SETITEM(scale_p, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 8), h), V4_SET1(FF_INV[1])));

		    for (k=2; k<=p; k++){	
                        h = V4_MUL(h, one_over_rho_scale);
                        //scale_0[k] = V4_MUL(V4_MUL(RR[k], h), V4_SET1(FF_INV[k]*((double) (2*k+1))));
                        V4_SETITEM(scale_0, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*k), h), V4_SET1(FF_INV[k]*((double) (2*k+1)))));
		        //scale_m[k] = V4_MUL(V4_MUL(RR[k-1], h), V4_SET1(FF_INV[k]));
		        V4_SETITEM(scale_m, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*(k-1)), h), V4_SET1(FF_INV[k])));
		        //scale_p[k] = V4_MUL(V4_MUL(RR[k+1], h), V4_SET1(FF_INV[k]));
		        V4_SETITEM(scale_p, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*(k+1)), h), V4_SET1(FF_INV[k])));
	            }

                    c_m = V4_MUL(V4_SET1(-beta*beta),V4_MUL(rho,scale));
                    c_p = V4_MUL(one_over_rho, scale);
		    core_gen_M_L_dipole_minus_simd4(p, scale_m, V4_MUL(c_m,mx), V4_MUL(c_m,my), V4_MUL(c_m,mz), Y, L);
		    core_gen_M_L_dipole_plus_simd4(p, scale_p, V4_MUL(c_p,mx), V4_MUL(c_p,my), V4_MUL(c_p,mz), Y, L);
		    if (!V4_IS_ZERO(q)) { 
			    core_gen_M_L_simd4(p, scale_0, V4_MUL(q, scale), Y, L);
		    }	

              }
              else if (!V4_IS_ZERO(q)) { 
                    bessel_k_scaled_simd4(V4_MUL(rho, V4_SET1(beta)), RR, p+2);

                    one_over_rho_scale = V4_MUL(one_over_rho, inv_scale);
                    h = V4_MUL(one_over_rho_scale, one_over_rho_scale); 

                    //scale_0[0] = V4_MUL(V4_MUL(RR[0], one_over_rho_scale), V4_SET1(FF_INV[0]));
                    V4_SETITEM(scale_0, 0, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), one_over_rho_scale), V4_SET1(FF_INV[0])));
                    //scale_0[1] = V4_MUL(V4_MUL(RR[1], h), V4_SET1(FF_INV[1]*3));
                    V4_SETITEM(scale_0, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 4), h), V4_SET1(FF_INV[1]*3.0)));

		    for (k=2; k<=p; k++){	
                        h = V4_MUL(h, one_over_rho_scale);
                        //scale_0[k] = V4_MUL(V4_MUL(RR[k], h), V4_SET1(FF_INV[k]*((double) (2*k+1))));
                        V4_SETITEM(scale_0, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*k), h), V4_SET1(FF_INV[k]*((double) (2*k+1)))));
	            }

		    core_gen_M_L_simd4(p, scale_0, V4_MUL(q, scale), Y, L);
              }
	}	
}




void eval_L_base_simd4(FmmvHandle *FMMV, Box *box, V4_TYPE x, V4_TYPE y, V4_TYPE z, V4_TYPE *pot, V4_TYPE *dx, V4_TYPE *dy, V4_TYPE *dz, int grad)
{
	int p = FMMV->pL;
        V4_BASETYPE beta = FMMV->beta;

        SIMD_ALIGN V4_BASETYPE Y[4*(FMM_P_MAX + 1) * (FMM_P_MAX + 2)];
        SIMD_ALIGN V4_BASETYPE RR[4*(2*FMM_P_MAX+4)];
	V4_BASETYPE *L;
	V4_TYPE rho, sin_phi, cos_phi, one_over_rho_sin_theta, cos_theta,scale;
        V4_TYPE rho_scale;
	int k;
	
	scale = V4_SET1(ldexp(1.0, box->level));

	L = box->L;

	rho = V4_SQRT(V4_FMA(x, x, V4_FMA(y, y, V4_MUL(z, z))));
        one_over_rho_sin_theta = V4_RECIP_SQRT(V4_FMA(x, x, V4_MUL(y, y)));
        sin_phi = V4_MUL(y, one_over_rho_sin_theta);
        cos_phi = V4_MUL(x, one_over_rho_sin_theta);
	cos_theta = V4_DIV(z, rho);

        if (beta==0.0) {
		    compute_spherical_harmonics_simd4[p](p, Y, sin_phi, cos_phi, cos_theta);
                    rho_scale = V4_MUL(rho, scale);
                    //RR[0] = V4_SET1(0.0);
                    V4_SETITEM(RR, 0, V4_SET1(0.0));
                    //RR[1] = V4_SET1(1.0);
                    V4_SETITEM(RR, 4, V4_SET1(1.0));
                    //RR[2] = rho_scale;
                    V4_SETITEM(RR, 8, rho_scale);
                    for (k=2; k<=p+1; k++) {
                        //RR[k+1] = V4_MUL(RR[k],rho_scale);
                        V4_SETITEM(RR, 4*(k+1), V4_MUL(V4_GETITEM(RR, 4*k), rho_scale));
                    }  

          	    *pot = core_eval_L_M_simd4(p, RR+4, L, Y);
		
		    if (grad) {  
		        core_eval_L_M_grad_minus_simd4(p, RR, L, Y, dx, dy, dz);
                        *dx = V4_MUL(*dx, scale);
                        *dy = V4_MUL(*dy, scale);
                        *dz = V4_MUL(*dz, scale);
                    }
       }
        else {
                    V4_TYPE h;
                    SIMD_ALIGN V4_BASETYPE scale_0[4*(FMM_P_MAX+1)];
                    V4_TYPE rho_beta = V4_MUL(rho, V4_SET1(beta));

                    if (grad) {
	                V4_TYPE dx_m, dy_m, dz_m;
                	V4_TYPE dx_p, dy_p, dz_p;
                        SIMD_ALIGN V4_BASETYPE scale_m[4*(FMM_P_MAX+1)];
                        SIMD_ALIGN V4_BASETYPE scale_p[4*(FMM_P_MAX+1)];
                        V4_TYPE rho_beta2 = V4_MUL (rho_beta,rho_beta);

		        //compute_spherical_harmonics[p+1](p+1, Y, sin_phi, cos_phi, cos_theta);
                        //bessel_i_scaled(rho_beta, RR, p+2, 2*p+4);
		        compute_spherical_harmonics_simd4[p](p, Y, sin_phi, cos_phi, cos_theta);
                        bessel_i_scaled_simd4(rho_beta, RR, p+1, 2*p+2);

                        rho_scale = V4_MUL(rho, scale);
                        h = rho_scale;
    
                        //scale_0[0] = V4_MUL(RR[0], V4_SET1(FF[0]));
                        V4_SETITEM(scale_0, 0, V4_MUL(V4_GETITEM(RR, 0), V4_SET1(FF[0])));
                        //scale_0[1] = V4_MUL(RR[1], V4_MUL(h, V4_SET1(FF[1])));
                        V4_SETITEM(scale_0, 4,  V4_MUL(V4_MUL(V4_GETITEM(RR, 4),h), V4_SET1(FF[1])));
		        //scale_m[0] = V4_SET1(0);
                        V4_SETITEM(scale_m, 0, V4_SET1(0));
                        //scale_p[0] = V4_MUL(RR[1], V4_SET1(FF[0])); 
                        V4_SETITEM(scale_p, 0, V4_MUL(V4_GETITEM(RR, 4), V4_SET1(FF[0]))); 
		        //scale_m[1] = V4_MUL(V4_MUL(RR[0], h),V4_SET1(FF[1]*R[3])); 
		        V4_SETITEM(scale_m, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), h),V4_SET1(FF[1]*R[3]))); 
                        //scale_p[1] = V4_MUL(V4_MUL(RR[2], h),V4_SET1(FF[1]*R[3]));
                        V4_SETITEM(scale_p, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 8), h),V4_SET1(FF[1]*R[3])));
    
		        for (k=2;k<=p; k++){	
                            h = V4_MUL(h, rho_scale);
                            //scale_0[k] = V4_MUL(V4_MUL(RR[k], h), V4_SET1(FF[k]));
                            V4_SETITEM(scale_0, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*k), h), V4_SET1(FF[k])));
		            //scale_m[k] = V4_MUL(V4_MUL(RR[k-1], h), V4_SET1(FF[k]*R[2*k+1]));
		            V4_SETITEM(scale_m, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*(k-1)), h), V4_SET1(FF[k]*R[2*k+1])));
		            //scale_p[k] = V4_MUL(V4_MUL(RR[k+1], h), V4_SET1(FF[k]*R[2*k+1]));
		            V4_SETITEM(scale_p, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*(k+1)), h), V4_SET1(FF[k]*R[2*k+1])));
	                }	

		        h = core_eval_L_M_simd4(p, scale_0, L, Y);
		        *pot = V4_MUL(rho_beta, h);
    
		        core_eval_L_M_grad_minus_simd4(p, scale_m, L, Y, &dx_m, &dy_m, &dz_m);
		        //core_eval_L_M_grad_plus_simd4(p, scale_p, L, Y, &dx_p, &dy_p, &dz_p);
		        core_eval_L_M_grad_plus_simd4(p-1, scale_p, L, Y, &dx_p, &dy_p, &dz_p);

		        *dx = V4_MUL(V4_SET1(beta), V4_FMA(rho_beta2, dx_p, dx_m));
		        *dy = V4_MUL(V4_SET1(beta), V4_FMA(rho_beta2, dy_p, dy_m));
		        *dz = V4_MUL(V4_SET1(beta), V4_FMA(rho_beta2, dz_p, dz_m));
                    }
                    else  {
		        compute_spherical_harmonics_simd4[p](p, Y, sin_phi, cos_phi, cos_theta);
                        bessel_i_scaled_simd4(rho_beta, RR, p+1, 2*p+2);

                        rho_scale = V4_MUL(rho, scale);
                        h = rho_scale;

                        //scale_0[0] = V4_MUL(RR[0], V4_SET1(FF[0]));
                        V4_SETITEM(scale_0, 0, V4_MUL(V4_GETITEM(RR, 0), V4_SET1(FF[0])));
                        //scale_0[1] = V4_MUL(V4_MUL(RR[1],h), V4_SET1(FF[1]));
                        V4_SETITEM(scale_0, 4,  V4_MUL(V4_MUL(V4_GETITEM(RR, 4),h), V4_SET1(FF[1])));

		        for (k=2;k<=p; k++){	
                            h = V4_MUL(h, rho_scale);
                            //scale_0[k] = V4_MUL(V4_MUL(RR[k], h), V4_SET1(FF[k]));
                            V4_SETITEM(scale_0, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*k), h), V4_SET1(FF[k])));
	                }	

		        h = core_eval_L_M_simd4(p, scale_0, L, Y);
		        *pot = V4_MUL(rho_beta, h);
                    }
	}	
}


void eval_M_base_simd4(FmmvHandle *FMMV, Box *source, V4_TYPE x, V4_TYPE y, V4_TYPE z, V4_TYPE *pot, V4_TYPE *dx, V4_TYPE *dy, V4_TYPE *dz, int grad)
{
	int p = FMMV->pM;
        V4_BASETYPE beta = FMMV->beta;

	V4_TYPE one_over_rho_scale;
	V4_TYPE rho, one_over_rho, sin_phi, cos_phi, one_over_rho_sin_theta, cos_theta, h, scale, inv_scale;
	SIMD_ALIGN V4_BASETYPE Y[4*(FMM_P_MAX+2)*(FMM_P_MAX+3)];
        SIMD_ALIGN V4_BASETYPE RR[4*(FMM_P_MAX+2)];
	V4_BASETYPE  *M;
	int k;

	inv_scale = V4_SET1(ldexp(1.0, -source->level)); /* inv_scale = 1/scale */
	scale = V4_SET1(ldexp(1.0, source->level)); 

	M = source->M;

        rho = V4_SQRT(V4_FMA(x, x, V4_FMA(y, y, V4_MUL(z, z))));
	one_over_rho = V4_DIV(V4_SET1(1.0), rho);
        one_over_rho_sin_theta = V4_RECIP_SQRT(V4_FMA(x, x, V4_MUL(y, y)));
        sin_phi = V4_MUL(y, one_over_rho_sin_theta);
        cos_phi = V4_MUL(x, one_over_rho_sin_theta);
	cos_theta = V4_MUL(z, one_over_rho);

        if (grad) {   
	    compute_spherical_harmonics_simd4[p+1](p+1, Y, sin_phi, cos_phi, cos_theta);
        }
        else {
	   compute_spherical_harmonics_simd4[p](p, Y, sin_phi, cos_phi, cos_theta);
        }

        if (beta==0.0) {
            one_over_rho_scale = V4_MUL(one_over_rho, inv_scale);
            //RR[0] = one_over_rho_scale;
            V4_SETITEM(RR, 0, one_over_rho_scale);
            for (k=1; k<=p+1; k++) {
                //RR[k] = V4_MUL(RR[k-1], one_over_rho_scale);
                V4_SETITEM(RR, 4*k, V4_MUL(V4_GETITEM(RR, 4*(k-1)), one_over_rho_scale));
            }    

	    h = core_eval_L_M_simd4(p, RR, M, Y);
	    *pot = V4_MUL(scale, h);

            if (grad) {
	        V4_TYPE scale2 = V4_SET1(-ldexp(1.0, 2*source->level)); 
	        core_eval_L_M_grad_plus_simd4(p, RR+4, M, Y, dx, dy, dz);
	        *dx = V4_MUL(*dx, scale2);
	        *dy = V4_MUL(*dy, scale2);
	        *dz = V4_MUL(*dz, scale2);
            }    
  
        }
        else {
            SIMD_ALIGN V4_BASETYPE scale_0[4*(FMM_P_MAX+1)];

            if (grad) {
                    V4_TYPE c_m, c_p;
                    V4_TYPE dx_m, dy_m, dz_m;
                    V4_TYPE dx_p, dy_p, dz_p;
                    SIMD_ALIGN V4_BASETYPE scale_m[4*(FMM_P_MAX+1)];
                    SIMD_ALIGN V4_BASETYPE scale_p[4*(FMM_P_MAX+1)];

                    bessel_k_scaled_simd4(V4_MUL(rho, V4_SET1(beta)), RR, p+2);

                    one_over_rho_scale = V4_MUL(one_over_rho, inv_scale);
                    h = V4_MUL(one_over_rho_scale, one_over_rho_scale); 

                    //scale_0[0] = V4_MUL(V4_MUL(RR[0], one_over_rho_scale), V4_SET1(FF_INV[0]));
                    V4_SETITEM(scale_0, 0, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), one_over_rho_scale), V4_SET1(FF_INV[0])));
                    //scale_0[1] = V4_MUL(V4_MUL(RR[1], h), V4_SET1(FF_INV[1]*3.0));
                    V4_SETITEM(scale_0, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 4), h), V4_SET1(FF_INV[1]*3.0)));
		    //scale_m[0] = V4_SET1(0.0);
		    V4_SETITEM(scale_m, 0, V4_SET1(0.0));
                    //scale_p[0] = V4_MUL(V4_MUL(RR[1], one_over_rho_scale), V4_SET1(FF_INV[0])); 
                    V4_SETITEM(scale_p, 0, V4_MUL(V4_MUL(V4_GETITEM(RR, 4), one_over_rho_scale), V4_SET1(FF_INV[0]))); 
		    //scale_m[1] = V4_MUL(V4_MUL(RR[0], h), V4_SET1(FF_INV[1]));
		    V4_SETITEM(scale_m, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), h), V4_SET1(FF_INV[1])));
                    //scale_p[1] = V4_MUL(V4_MUL(RR[2], h), V4_SET1(FF_INV[1]));
                    V4_SETITEM(scale_p, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 8), h), V4_SET1(FF_INV[1])));

		    for (k=2; k<=p; k++){	
                        h = V4_MUL(h, one_over_rho_scale);
                        //scale_0[k] = V4_MUL(V4_MUL(RR[k], h), V4_SET1(FF_INV[k]*((double) (2*k+1))));
                        V4_SETITEM(scale_0, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*k), h), V4_SET1(FF_INV[k]*((double) (2*k+1)))));
		        //scale_m[k] = V4_MUL(V4_MUL(RR[k-1], h), V4_SET1(FF_INV[k]));
		        V4_SETITEM(scale_m, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*(k-1)), h), V4_SET1(FF_INV[k])));
		        //scale_p[k] = V4_MUL(V4_MUL(RR[k+1], h), V4_SET1(FF_INV[k]));
		        V4_SETITEM(scale_p, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*(k+1)), h), V4_SET1(FF_INV[k])));
	            }                    

		    h = core_eval_L_M_simd4(p, scale_0, M, Y);
                    *pot = V4_MUL(scale, h); 

		    core_eval_L_M_grad_minus_simd4(p, scale_m, M, Y, &dx_m, &dy_m, &dz_m);
		    core_eval_L_M_grad_plus_simd4(p, scale_p, M, Y, &dx_p, &dy_p, &dz_p);
                    c_m = V4_MUL(V4_SET1(-beta*beta), V4_MUL(rho, scale));
                    c_p = V4_NEG(V4_MUL(one_over_rho, scale));
		    *dx = V4_ADD(V4_MUL(c_m, dx_m), V4_MUL(c_p, dx_p));
		    *dy = V4_ADD(V4_MUL(c_m, dy_m), V4_MUL(c_p, dy_p));
		    *dz = V4_ADD(V4_MUL(c_m, dz_m), V4_MUL(c_p, dz_p));
            }
            else {
                    bessel_k_scaled_simd4(V4_MUL(rho, V4_SET1(beta)), RR, p+2);

                    one_over_rho_scale = V4_MUL(one_over_rho, inv_scale);
                    h = V4_MUL(one_over_rho_scale, one_over_rho_scale); 

                    //scale_0[0] = V4_MUL(V4_MUL(RR[0], one_over_rho_scale), V4_SET1(FF_INV[0]));
                    V4_SETITEM(scale_0, 0, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), one_over_rho_scale), V4_SET1(FF_INV[0])));
                    //scale_0[1] = V4_MUL(V4_MUL(RR[1], h), V4_SET1(FF_INV[1]*3));
                    V4_SETITEM(scale_0, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 4), h), V4_SET1(FF_INV[1]*3.0)));

		    for (k=2; k<=p; k++){	
                        h = V4_MUL(h, one_over_rho_scale);
                        //scale_0[k] = V4_MUL(V4_MUL(RR[k], h), V4_SET1(FF_INV[k]*((double) (2*k+1))));
                        V4_SETITEM(scale_0, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*k), h), V4_SET1(FF_INV[k]*((double) (2*k+1)))));
	            }

		    h = core_eval_L_M_simd4(p, scale_0, M, Y);
                    *pot = V4_MUL(scale, h); 

            }
      }
}



void gen_L_eval_M_base_simd4(FmmvHandle *FMMV, Box *list3, 
                        V4_TYPE x, V4_TYPE y, V4_TYPE z, V4_TYPE q, V4_TYPE mx, V4_TYPE my, V4_TYPE mz,
                        V4_TYPE *pot, V4_TYPE *dx, V4_TYPE *dy, V4_TYPE *dz,
                        int dipole, int grad)

{
	int pL = FMMV->pL;
	int pM = FMMV->pM;
	int len2M = (pM+1)*(pM+2)/2;
	int p = (pL>pM?pL:pM);
        V4_BASETYPE beta = FMMV->beta;
	V4_TYPE one_over_rho_scale;
	V4_TYPE rho, one_over_rho, sin_phi, cos_phi, one_over_rho_sin_theta, cos_theta, h, scale, inv_scale;
	SIMD_ALIGN V4_BASETYPE Y[4*(FMM_P_MAX+2)*(FMM_P_MAX+3)];
        SIMD_ALIGN V4_BASETYPE RR[4*(FMM_P_MAX+2)];
	V4_BASETYPE *L;
	V4_BASETYPE *M;
	int k;
	
	L = list3->L;
	M = list3->M;	
	
	scale = V4_SET1(ldexp(1.0, list3->level));
	inv_scale = V4_SET1(ldexp(1.0, -list3->level));
        
        rho = V4_SQRT(V4_FMA(x, x, V4_FMA(y, y, V4_MUL(z, z))));
	one_over_rho = V4_DIV(V4_SET1(1.0), rho);
        one_over_rho_sin_theta = V4_RECIP_SQRT(V4_FMA(x, x, V4_MUL(y, y)));
        sin_phi = V4_MUL(y, one_over_rho_sin_theta);
        cos_phi = V4_MUL(x, one_over_rho_sin_theta);
	cos_theta = V4_MUL(z, one_over_rho);

	if (dipole||grad) {
	        compute_spherical_harmonics_simd4[p+1](p+1, Y, V4_NEG(sin_phi), cos_phi, cos_theta);
        }
        else {
	        compute_spherical_harmonics_simd4[p](p, Y, V4_NEG(sin_phi), cos_phi, cos_theta);
        } 

        if (beta==0.0) {
            one_over_rho_scale = V4_MUL(one_over_rho, inv_scale);
            //RR[0] = one_over_rho_scale;
            V4_SETITEM(RR, 0, one_over_rho_scale);
            for (k=1; k<=p+1; k++) {
                //RR[k] = V4_MUL(RR[k-1], one_over_rho_scale);
                V4_SETITEM(RR, 4*k, V4_MUL(V4_GETITEM(RR, 4*(k-1)), one_over_rho_scale));
            }    
        
	    if (!V4_IS_ZERO(q)) { 
		core_gen_M_L_simd4(pL, RR, q*scale, Y, L);
	    }	
            if (dipole) {
                V4_TYPE scale2 = V4_SET1(ldexp(1.0, 2*list3->level));
   	        mx =V4_MUL(mx, scale2); 
		my =V4_MUL(my, scale2); 
		mz =V4_MUL(mz, scale2); 
		core_gen_M_L_dipole_plus_simd4(p, RR+4, mx, my, mz, Y, L); 
	    }	

  	    VEC_conj4_simd4(len2M, (V4_BASETYPE*) Y);  // NOTE: this cast should not be necessary

		    h = core_eval_L_M_simd4(pM, RR, M, Y);
		    *pot = V4_MUL(scale, h);

                    if (grad) {
	                  V4_TYPE scale2 = V4_SET1(-ldexp(1.0, 2*list3->level)); 
	                  core_eval_L_M_grad_plus_simd4(p, RR+4, M, Y, dx, dy, dz);
          	          *dx = V4_MUL(*dx, scale2);
	                  *dy = V4_MUL(*dy, scale2);
	                  *dz = V4_MUL(*dz, scale2);
                    }
        }
        else {
              SIMD_ALIGN V4_BASETYPE scale_0[4*(FMM_P_MAX+1)];

              if (dipole||grad) {
                    V4_TYPE c_m, c_p;
                    SIMD_ALIGN V4_BASETYPE scale_m[4*(FMM_P_MAX+1)];
                    SIMD_ALIGN V4_BASETYPE scale_p[4*(FMM_P_MAX+1)];

                    bessel_k_scaled_simd4(V4_MUL(rho, V4_SET1(beta)), RR, p+2);

                    one_over_rho_scale = V4_MUL(one_over_rho, inv_scale);
                    h = V4_MUL(one_over_rho_scale, one_over_rho_scale); 

                    //scale_0[0] = V4_MUL(V4_MUL(RR[0], one_over_rho_scale), V4_SET1(FF_INV[0]));
                    V4_SETITEM(scale_0, 0, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), one_over_rho_scale), V4_SET1(FF_INV[0])));
                    //scale_0[1] = V4_MUL(V4_MUL(RR[1], h), V4_SET1(FF_INV[1]*3.0));
                    V4_SETITEM(scale_0, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 4), h), V4_SET1(FF_INV[1]*3.0)));
		    //scale_m[0] = V4_SET1(0.0);
		    V4_SETITEM(scale_m, 0, V4_SET1(0.0));
                    //scale_p[0] = V4_MUL(V4_MUL(RR[1], one_over_rho_scale), V4_SET1(FF_INV[0])); 
                    V4_SETITEM(scale_p, 0, V4_MUL(V4_MUL(V4_GETITEM(RR, 4), one_over_rho_scale), V4_SET1(FF_INV[0]))); 
		    //scale_m[1] = V4_MUL(V4_MUL(RR[0], h), V4_SET1(FF_INV[1]));
		    V4_SETITEM(scale_m, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), h), V4_SET1(FF_INV[1])));
                    //scale_p[1] = V4_MUL(V4_MUL(RR[2], h), V4_SET1(FF_INV[1]));
                    V4_SETITEM(scale_p, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 8), h), V4_SET1(FF_INV[1])));

		    for (k=2; k<=p; k++){	
                        h = V4_MUL(h, one_over_rho_scale);
                        //scale_0[k] = V4_MUL(V4_MUL(RR[k], h), V4_SET1(FF_INV[k]*((double) (2*k+1))));
                        V4_SETITEM(scale_0, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*k), h), V4_SET1(FF_INV[k]*((double) (2*k+1)))));
		        //scale_m[k] = V4_MUL(V4_MUL(RR[k-1], h), V4_SET1(FF_INV[k]));
		        V4_SETITEM(scale_m, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*(k-1)), h), V4_SET1(FF_INV[k])));
		        //scale_p[k] = V4_MUL(V4_MUL(RR[k+1], h), V4_SET1(FF_INV[k]));
		        V4_SETITEM(scale_p, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*(k+1)), h), V4_SET1(FF_INV[k])));
	            }

		    if (!V4_IS_ZERO(q)) {
			    core_gen_M_L_simd4(pL, scale_0, V4_MUL(q,scale), Y, L);
		    }	
                    if (dipole) {
                        c_m = V4_MUL(V4_SET1(-beta*beta),V4_MUL(rho,scale));
                        c_p = V4_MUL(one_over_rho, scale);
    		        core_gen_M_L_dipole_minus_simd4(p, scale_m, V4_MUL(c_m,mx), V4_MUL(c_m,my), V4_MUL(c_m,mz), Y, L);
		        core_gen_M_L_dipole_plus_simd4(p, scale_p, V4_MUL(c_p,mx), V4_MUL(c_p,my), V4_MUL(c_p,mz), Y, L);
		    }	

  	            VEC_conj4_simd4(len2M, (V4_BASETYPE*) Y);  // NOTE: this cast should not be necessary

		    h = core_eval_L_M_simd4(pM, scale_0, M, Y);
                    *pot = V4_MUL(scale, h); 

                    if (grad) {
	                V4_TYPE dx_m, dy_m, dz_m;
                	V4_TYPE dx_p, dy_p, dz_p;

		        core_eval_L_M_grad_minus_simd4(pM, scale_m, M, Y, &dx_m, &dy_m, &dz_m);
		        core_eval_L_M_grad_plus_simd4(pM, scale_p, M, Y, &dx_p, &dy_p, &dz_p);
                        c_m = V4_MUL(V4_SET1(-beta*beta),V4_MUL(rho,scale));
                        c_p = V4_NEG(V4_MUL(one_over_rho, scale));
		        *dx = c_m*dx_m + c_p*dx_p;
		        *dy = c_m*dy_m + c_p*dy_p;
		        *dz = c_m*dz_m + c_p*dz_p;
                    } 
                }
                else {
                    bessel_k_scaled_simd4(V4_MUL(rho, V4_SET1(beta)), RR, p+2);

                    one_over_rho_scale = V4_MUL(one_over_rho, inv_scale);
                    h = V4_MUL(one_over_rho_scale, one_over_rho_scale); 

                    //scale_0[0] = V4_MUL(V4_MUL(RR[0], one_over_rho_scale), V4_SET1(FF_INV[0]));
                    V4_SETITEM(scale_0, 0, V4_MUL(V4_MUL(V4_GETITEM(RR, 0), one_over_rho_scale), V4_SET1(FF_INV[0])));
                    //scale_0[1] = V4_MUL(V4_MUL(RR[1], h), V4_SET1(FF_INV[1]*3));
                    V4_SETITEM(scale_0, 4, V4_MUL(V4_MUL(V4_GETITEM(RR, 4), h), V4_SET1(FF_INV[1]*3.0)));

		    for (k=2; k<=p; k++){	
                        h = V4_MUL(h, one_over_rho_scale);
                        //scale_0[k] = V4_MUL(V4_MUL(RR[k], h), V4_SET1(FF_INV[k]*((double) (2*k+1))));
                        V4_SETITEM(scale_0, 4*k, V4_MUL(V4_MUL(V4_GETITEM(RR, 4*k), h), V4_SET1(FF_INV[k]*((double) (2*k+1)))));
	            }                    

		    core_gen_M_L_simd4(pL, scale_0, q*scale, Y, L);

  	            VEC_conj4_simd4(len2M, (V4_BASETYPE*) Y);  // NOTE: this cast should not be necessary

		    h = core_eval_L_M_simd4(pM, scale_0, M, Y);
                    *pot = V4_MUL(scale, h); 
                }
        }        
}


