/*
! +-----------------------------------------------+
! |        Generated by SPL Compiler 3.30         |
! +-----------------------------------------------+
! Command-line options: -l -B 32 -C -xprecision=double -xposw -xsubname=FFT_M2X_56 
! 
*/
/*
! The SPL Program: (compose (tensor (compose (..)(..))(I 8))(compose (T 56 8)(compose (..)(..))))
! node size: 56 X 56
*/


	void FFT_M2X_56(double *y, double *x) {
	int i0;
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
	double f56;
	double f57;
	double f58;
	double f59;
	double f62;
	double f63;
	double f64;
	double f65;
	double f66;
	double f67;
	double f68;
	double f69;
	double f70;
	double f71;
	double f72;
	double f73;
	double f74;
	double f75;
	double f76;
	double f77;
	double f78;
	double f79;
	double f80;
	double f81;
	double f82;
	double f83;
	double f84;
	double f85;
	double f86;
	double f87;
	double f88;
	double f89;
	double f90;
	double f91;
	double f92;
	double f93;
	double f94;
	double f95;
	double f96;
	double f97;
	double f98;
	double f99;
	double f100;
	double f101;
	double f102;
	double f103;
	double f104;
	double f105;
	double f108;
	double f109;
	double f110;
	double f111;
	double f112;
	double f113;
	double f114;
	double f115;
	double f116;
	double f117;
	double f118;
	double f119;
	double f120;
	double f121;
	double f122;
	double f123;
	double f124;
	double f125;
	double f126;
	double f127;
	double f128;
	double f129;
	double f130;
	double f131;
	double f132;
	double f133;
	double f134;
	double f135;
	double f136;
	double f137;
	double f138;
	double f139;
	double f140;
	double f141;
	double f142;
	double f143;
	double f144;
	double f145;
	double f146;
	double f147;
	double f148;
	double f149;
	double f150;
	double f151;
	double f152;
	double f153;
	double f154;
	double f155;
	double f156;
	double f157;
	double f158;
	double f159;
	double f160;
	double f161;
	double f162;
	double f163;
	double f164;
	double f165;
	double f166;
	double f167;
	double f168;
	double f169;
	  static double t38[112];
	  static double t39[112];
	  static double t40[112];
	  extern double T_56_8 [112];

	  /* deftemp t38 ( 112 ) */
	  /* deftemp t39 ( 112 ) */
	  /* deftemp t40 ( 112 ) */
	  t40[0] = x[0];
	  t40[1] = x[1];
	  t40[2] = x[14];
	  t40[3] = x[15];
	  t40[4] = x[28];
	  t40[5] = x[29];
	  t40[6] = x[42];
	  t40[7] = x[43];
	  t40[8] = x[56];
	  t40[9] = x[57];
	  t40[10] = x[70];
	  t40[11] = x[71];
	  t40[12] = x[84];
	  t40[13] = x[85];
	  t40[14] = x[98];
	  t40[15] = x[99];
	  t40[16] = x[2];
	  t40[17] = x[3];
	  t40[18] = x[16];
	  t40[19] = x[17];
	  t40[20] = x[30];
	  t40[21] = x[31];
	  t40[22] = x[44];
	  t40[23] = x[45];
	  t40[24] = x[58];
	  t40[25] = x[59];
	  t40[26] = x[72];
	  t40[27] = x[73];
	  t40[28] = x[86];
	  t40[29] = x[87];
	  t40[30] = x[100];
	  t40[31] = x[101];
	  t40[32] = x[4];
	  t40[33] = x[5];
	  t40[34] = x[18];
	  t40[35] = x[19];
	  t40[36] = x[32];
	  t40[37] = x[33];
	  t40[38] = x[46];
	  t40[39] = x[47];
	  t40[40] = x[60];
	  t40[41] = x[61];
	  t40[42] = x[74];
	  t40[43] = x[75];
	  t40[44] = x[88];
	  t40[45] = x[89];
	  t40[46] = x[102];
	  t40[47] = x[103];
	  t40[48] = x[6];
	  t40[49] = x[7];
	  t40[50] = x[20];
	  t40[51] = x[21];
	  t40[52] = x[34];
	  t40[53] = x[35];
	  t40[54] = x[48];
	  t40[55] = x[49];
	  t40[56] = x[62];
	  t40[57] = x[63];
	  t40[58] = x[76];
	  t40[59] = x[77];
	  t40[60] = x[90];
	  t40[61] = x[91];
	  t40[62] = x[104];
	  t40[63] = x[105];
	  t40[64] = x[8];
	  t40[65] = x[9];
	  t40[66] = x[22];
	  t40[67] = x[23];
	  t40[68] = x[36];
	  t40[69] = x[37];
	  t40[70] = x[50];
	  t40[71] = x[51];
	  t40[72] = x[64];
	  t40[73] = x[65];
	  t40[74] = x[78];
	  t40[75] = x[79];
	  t40[76] = x[92];
	  t40[77] = x[93];
	  t40[78] = x[106];
	  t40[79] = x[107];
	  t40[80] = x[10];
	  t40[81] = x[11];
	  t40[82] = x[24];
	  t40[83] = x[25];
	  t40[84] = x[38];
	  t40[85] = x[39];
	  t40[86] = x[52];
	  t40[87] = x[53];
	  t40[88] = x[66];
	  t40[89] = x[67];
	  t40[90] = x[80];
	  t40[91] = x[81];
	  t40[92] = x[94];
	  t40[93] = x[95];
	  t40[94] = x[108];
	  t40[95] = x[109];
	  t40[96] = x[12];
	  t40[97] = x[13];
	  t40[98] = x[26];
	  t40[99] = x[27];
	  t40[100] = x[40];
	  t40[101] = x[41];
	  t40[102] = x[54];
	  t40[103] = x[55];
	  t40[104] = x[68];
	  t40[105] = x[69];
	  t40[106] = x[82];
	  t40[107] = x[83];
	  t40[108] = x[96];
	  t40[109] = x[97];
	  t40[110] = x[110];
	  t40[111] = x[111];
	  for (i0 = 0; i0 < 7; i0++) {  
	    f0 = t40[16*i0+4] - t40[16*i0+12];
	    f1 = t40[16*i0+5] - t40[16*i0+13];
	    f2 = t40[16*i0+4] + t40[16*i0+12];
	    f3 = t40[16*i0+5] + t40[16*i0+13];
	    f4 = t40[16*i0] - t40[16*i0+8];
	    f5 = t40[16*i0+1] - t40[16*i0+9];
	    f6 = t40[16*i0] + t40[16*i0+8];
	    f7 = t40[16*i0+1] + t40[16*i0+9];
	    f8 = f6 - f2;
	    f9 = f7 - f3;
	    f10 = f6 + f2;
	    f11 = f7 + f3;
	    f12 = f4 + f1;
	    f13 = f5 - f0;
	    f14 = f4 - f1;
	    f15 = f5 + f0;
	    f16 = t40[16*i0+6] - t40[16*i0+14];
	    f17 = t40[16*i0+7] - t40[16*i0+15];
	    f18 = t40[16*i0+6] + t40[16*i0+14];
	    f19 = t40[16*i0+7] + t40[16*i0+15];
	    f20 = t40[16*i0+2] - t40[16*i0+10];
	    f21 = t40[16*i0+3] - t40[16*i0+11];
	    f22 = t40[16*i0+2] + t40[16*i0+10];
	    f23 = t40[16*i0+3] + t40[16*i0+11];
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
	    t39[16*i0+8] = f10 - f26;
	    t39[16*i0+9] = f11 - f27;
	    t39[16*i0] = f10 + f26;
	    t39[16*i0+1] = f11 + f27;
	    t39[16*i0+10] = f14 - f34;
	    t39[16*i0+11] = f15 - f35;
	    t39[16*i0+2] = f14 + f34;
	    t39[16*i0+3] = f15 + f35;
	    t39[16*i0+12] = f8 + f25;
	    t39[16*i0+13] = f9 - f24;
	    t39[16*i0+4] = f8 - f25;
	    t39[16*i0+5] = f9 + f24;
	    t39[16*i0+14] = f12 + f38;
	    t39[16*i0+15] = f13 - f39;
	    t39[16*i0+6] = f12 - f38;
	    t39[16*i0+7] = f13 + f39;
	    }
	  /* undeftemp t40 ( 112 ) */
	  for (i0 = 0; i0 < 56; i0++) {  
	    f56 = T_56_8[2*i0] * t39[2*i0];
	    f57 = T_56_8[2*i0+1] * t39[2*i0+1];
	    f58 = T_56_8[2*i0] * t39[2*i0+1];
	    f59 = T_56_8[2*i0+1] * t39[2*i0];
	    t38[2*i0] = f56 - f57;
	    t38[2*i0+1] = f58 + f59;
	    }
	  /* undeftemp t39 ( 112 ) */
	  for (i0 = 0; i0 < 8; i0++) {  
	    f62 = t38[2*i0+64] - t38[2*i0+32];
	    f63 = t38[2*i0+65] - t38[2*i0+33];
	    f64 = t38[2*i0+64] + t38[2*i0+32];
	    f65 = t38[2*i0+65] + t38[2*i0+33];
	    f66 = t38[2*i0+16] + f64;
	    f67 = t38[2*i0+17] + f65;
	    f68 = 5.0000000000000000e-01 * f64;
	    f69 = 5.0000000000000000e-01 * f65;
	    f70 = t38[2*i0+16] - f68;
	    f71 = t38[2*i0+17] - f69;
	    f72 = 8.6602540378443860e-01 * f63;
	    f73 = 8.6602540378443860e-01 * f62;
	    f74 = f70 + f72;
	    f75 = f71 - f73;
	    f76 = f70 - f72;
	    f77 = f71 + f73;
	    f78 = t38[2*i0+48] - t38[2*i0+80];
	    f79 = t38[2*i0+49] - t38[2*i0+81];
	    f80 = t38[2*i0+48] + t38[2*i0+80];
	    f81 = t38[2*i0+49] + t38[2*i0+81];
	    f82 = t38[2*i0+96] + f80;
	    f83 = t38[2*i0+97] + f81;
	    f84 = 5.0000000000000000e-01 * f80;
	    f85 = 5.0000000000000000e-01 * f81;
	    f86 = t38[2*i0+96] - f84;
	    f87 = t38[2*i0+97] - f85;
	    f88 = 8.6602540378443860e-01 * f79;
	    f89 = 8.6602540378443860e-01 * f78;
	    f90 = f86 + f88;
	    f91 = f87 - f89;
	    f92 = f86 - f88;
	    f93 = f87 + f89;
	    f94 = f66 - f82;
	    f95 = f67 - f83;
	    f96 = f66 + f82;
	    f97 = f67 + f83;
	    f98 = f76 - f92;
	    f99 = f77 - f93;
	    f100 = f76 + f92;
	    f101 = f77 + f93;
	    f102 = f74 - f90;
	    f103 = f75 - f91;
	    f104 = f74 + f90;
	    f105 = f75 + f91;
	    y[2*i0] = t38[2*i0] + f96;
	    y[2*i0+1] = t38[2*i0+1] + f97;
	    f108 = 1.6666666666666666e-01 * f96;
	    f109 = 1.6666666666666666e-01 * f97;
	    f110 = t38[2*i0] - f108;
	    f111 = t38[2*i0+1] - f109;
	    f112 = 4.0668889305758948e-01 * f98;
	    f113 = 1.7043646531196582e-01 * f99;
	    f114 = 4.0668889305758948e-01 * f99;
	    f115 = 1.7043646531196582e-01 * f98;
	    f116 = f112 + f113;
	    f117 = f115 - f114;
	    f118 = 3.9507823426270000e-01 * f104;
	    f119 = 1.9585104864746450e-01 * f105;
	    f120 = 3.9507823426270000e-01 * f105;
	    f121 = 1.9585104864746450e-01 * f104;
	    f122 = f118 + f119;
	    f123 = f120 - f121;
	    f124 = 4.4095855184409843e-01 * f95;
	    f125 = 4.4095855184409843e-01 * f94;
	    f126 = 3.9507823426270006e-01 * f100;
	    f127 = 1.9585104864746439e-01 * f101;
	    f128 = 3.9507823426270006e-01 * f101;
	    f129 = 1.9585104864746439e-01 * f100;
	    f130 = f126 - f127;
	    f131 = f128 + f129;
	    f132 = 4.0668889305758960e-01 * f102;
	    f133 = 1.7043646531196557e-01 * f103;
	    f134 = 4.0668889305758960e-01 * f103;
	    f135 = 1.7043646531196557e-01 * f102;
	    f136 = f132 - f133;
	    f137 = f134 + f135;
	    f138 = f130 - f122;
	    f139 = f131 - f123;
	    f140 = f130 + f122;
	    f141 = f131 + f123;
	    f142 = f110 + f140;
	    f143 = f111 + f141;
	    f144 = 5.0000000000000000e-01 * f140;
	    f145 = 5.0000000000000000e-01 * f141;
	    f146 = f110 - f144;
	    f147 = f111 - f145;
	    f148 = 8.6602540378443860e-01 * f139;
	    f149 = 8.6602540378443860e-01 * f138;
	    f150 = f146 + f148;
	    f151 = f147 - f149;
	    f152 = f146 - f148;
	    f153 = f147 + f149;
	    f154 = f116 + f136;
	    f155 = f117 - f137;
	    f156 = f136 - f116;
	    f157 = f117 + f137;
	    f158 = f156 - f124;
	    f159 = f125 + f157;
	    f160 = 5.0000000000000000e-01 * f156;
	    f161 = 5.0000000000000000e-01 * f157;
	    f162 = f124 + f160;
	    f163 = f125 - f161;
	    f164 = 8.6602540378443860e-01 * f155;
	    f165 = 8.6602540378443860e-01 * f154;
	    f166 = f164 - f162;
	    f167 = f163 + f165;
	    f168 = f162 + f164;
	    f169 = f163 - f165;
	    y[2*i0+96] = f142 - f158;
	    y[2*i0+97] = f143 - f159;
	    y[2*i0+16] = f142 + f158;
	    y[2*i0+17] = f143 + f159;
	    y[2*i0+48] = f152 + f168;
	    y[2*i0+49] = f153 - f169;
	    y[2*i0+64] = f152 - f168;
	    y[2*i0+65] = f153 + f169;
	    y[2*i0+80] = f150 - f166;
	    y[2*i0+81] = f151 - f167;
	    y[2*i0+32] = f150 + f166;
	    y[2*i0+33] = f151 + f167;
	    }
	  /* undeftemp t38 ( 112 ) */

	  /* undecl double t40[112]; */
	  /* undecl double t39[112]; */
	  /* undecl double t38[112]; */

	}
#include <math.h>
#ifndef NO_GLOBAL
	double T_56_8 [112];
#endif

	void init_FFT_M2X_56( void )
	{
	int i;
	int j;
	  extern double T_56_8 [112];
	  for (i=0; i<=6; i++) {
	    for (j=0; j<=7; j++) {
	      T_56_8[16*i+2*j] = (cos(6.2831853071795862e+00*i*j/56));
	      T_56_8[16*i+2*j+1] = (sin(6.2831853071795862e+00*i*j/56));
	    }
	  }

	}

