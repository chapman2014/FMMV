/*
! +-----------------------------------------------+
! |        Generated by SPL Compiler 3.30         |
! +-----------------------------------------------+
! Command-line options: -l -B 32 -C -xprecision=double -xposw -xsubname=FFT_M2X_8 
! 
*/
/*
! The SPL Program: (compose (tensor (F 2)(I 4))(compose (T 8 4)(compose (..)(..))))
! node size: 8 X 8
*/


	void FFT_M2X_8(double *y, double *x) {
	double f0;
	double f1;
	double f2;
	double f3;
	double f4;
	double f5;
	double f6;
	double f7;
	double f8;
	double f9;
	double f10;
	double f11;
	double f12;
	double f13;
	double f14;
	double f15;
	double f16;
	double f17;
	double f18;
	double f19;
	double f20;
	double f21;
	double f22;
	double f23;
	double f24;
	double f25;
	double f26;
	double f27;
	double f28;
	double f29;
	double f30;
	double f31;
	double f32;
	double f33;
	double f34;
	double f35;
	double f36;
	double f37;
	double f38;
	double f39;

	  f0 = x[4] - x[12];
	  f1 = x[5] - x[13];
	  f2 = x[4] + x[12];
	  f3 = x[5] + x[13];
	  f4 = x[0] - x[8];
	  f5 = x[1] - x[9];
	  f6 = x[0] + x[8];
	  f7 = x[1] + x[9];
	  f8 = f6 - f2;
	  f9 = f7 - f3;
	  f10 = f6 + f2;
	  f11 = f7 + f3;
	  f12 = f4 + f1;
	  f13 = f5 - f0;
	  f14 = f4 - f1;
	  f15 = f5 + f0;
	  f16 = x[6] - x[14];
	  f17 = x[7] - x[15];
	  f18 = x[6] + x[14];
	  f19 = x[7] + x[15];
	  f20 = x[2] - x[10];
	  f21 = x[3] - x[11];
	  f22 = x[2] + x[10];
	  f23 = x[3] + x[11];
	  f24 = f22 - f18;
	  f25 = f23 - f19;
	  f26 = f22 + f18;
	  f27 = f23 + f19;
	  f28 = f20 + f17;
	  f29 = f21 - f16;
	  f30 = f20 - f17;
	  f31 = f21 + f16;
	  f32 = 7.0710678118654757e-01 * f30;
	  f33 = 7.0710678118654757e-01 * f31;
	  f34 = f32 - f33;
	  f35 = f33 + f32;
	  f36 = 7.0710678118654757e-01 * f28;
	  f37 = 7.0710678118654757e-01 * f29;
	  f38 = f36 + f37;
	  f39 = f36 - f37;
	  y[8] = f10 - f26;
	  y[9] = f11 - f27;
	  y[0] = f10 + f26;
	  y[1] = f11 + f27;
	  y[10] = f14 - f34;
	  y[11] = f15 - f35;
	  y[2] = f14 + f34;
	  y[3] = f15 + f35;
	  y[12] = f8 + f25;
	  y[13] = f9 - f24;
	  y[4] = f8 - f25;
	  y[5] = f9 + f24;
	  y[14] = f12 + f38;
	  y[15] = f13 - f39;
	  y[6] = f12 - f38;
	  y[7] = f13 + f39;


	}
	void init_FFT_M2X_8( void )
	{
	}
