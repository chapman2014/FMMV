/*
! +-----------------------------------------------+
! |        Generated by SPL Compiler 3.30         |
! +-----------------------------------------------+
! Command-line options: -l -B 32 -C -xprecision=double -xposw -xsubname=FFT_M2X_44 
! 
*/
/*
! The SPL Program: (compose (permutation (...1 x 44 ...))(compose (tensor (..)(..))(compose (..)(..))))
! node size: 44 X 44
*/


	void FFT_M2X_44(double *y, double *x) {
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
	double f40;
	double f41;
	double f42;
	double f43;
	double f44;
	double f45;
	double f46;
	double f47;
	double f48;
	double f49;
	double f50;
	double f51;
	double f52;
	double f53;
	double f54;
	double f55;
	double f56;
	double f57;
	double f58;
	double f59;
	double f60;
	double f61;
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
	double f106;
	double f107;
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
	double f170;
	double f171;
	double f172;
	double f173;
	double f174;
	double f175;
	double f176;
	double f177;
	double f178;
	double f179;
	double f180;
	double f181;
	double f182;
	double f183;
	double f184;
	double f185;
	double f186;
	double f187;
	double f188;
	double f189;
	double f190;
	double f191;
	double f192;
	double f193;
	double f194;
	double f195;
	double f196;
	double f197;
	double f198;
	double f199;
	double f200;
	double f201;
	double f202;
	double f203;
	double f204;
	double f205;
	double f206;
	double f207;
	double f208;
	double f209;
	double f210;
	double f211;
	double f212;
	double f213;
	double f214;
	double f215;
	double f216;
	double f217;
	double f218;
	double f219;
	double f220;
	double f221;
	double f222;
	double f223;
	double f224;
	double f225;
	double f226;
	double f227;
	double f228;
	double f229;
	double f230;
	double f231;
	double f232;
	double f233;
	double f234;
	double f235;
	double f236;
	double f237;
	double f238;
	double f239;
	double f240;
	double f241;
	double f242;
	double f243;
	double f244;
	double f245;
	double f246;
	double f247;
	double f248;
	double f249;
	double f250;
	double f251;
	double f252;
	double f253;
	double f254;
	double f255;
	double f256;
	double f257;
	double f258;
	double f259;
	double f260;
	double f261;
	double f262;
	double f263;
	double f264;
	double f265;
	double f266;
	double f267;
	double f268;
	double f269;
	double f270;
	double f271;
	double f272;
	double f273;
	double f274;
	double f275;
	double f276;
	double f277;
	double f278;
	double f279;
	double f280;
	double f281;
	double f282;
	double f283;
	double f304;
	double f305;
	double f306;
	double f307;
	double f308;
	double f309;
	double f310;
	double f311;
	  static double t83[88];
	  static double t84[88];
	  static double t85[88];
	  static double t86[88];
	  static double t226[88];

	  /* deftemp t83 ( 88 ) */
	  /* deftemp t84 ( 88 ) */
	  /* deftemp t85 ( 88 ) */
	  t85[0] = x[0];
	  t85[1] = x[1];
	  t85[2] = x[24];
	  t85[3] = x[25];
	  t85[4] = x[48];
	  t85[5] = x[49];
	  t85[6] = x[72];
	  t85[7] = x[73];
	  t85[8] = x[8];
	  t85[9] = x[9];
	  t85[10] = x[32];
	  t85[11] = x[33];
	  t85[12] = x[56];
	  t85[13] = x[57];
	  t85[14] = x[80];
	  t85[15] = x[81];
	  t85[16] = x[16];
	  t85[17] = x[17];
	  t85[18] = x[40];
	  t85[19] = x[41];
	  t85[20] = x[64];
	  t85[21] = x[65];
	  t85[22] = x[66];
	  t85[23] = x[67];
	  t85[24] = x[2];
	  t85[25] = x[3];
	  t85[26] = x[26];
	  t85[27] = x[27];
	  t85[28] = x[50];
	  t85[29] = x[51];
	  t85[30] = x[74];
	  t85[31] = x[75];
	  t85[32] = x[10];
	  t85[33] = x[11];
	  t85[34] = x[34];
	  t85[35] = x[35];
	  t85[36] = x[58];
	  t85[37] = x[59];
	  t85[38] = x[82];
	  t85[39] = x[83];
	  t85[40] = x[18];
	  t85[41] = x[19];
	  t85[42] = x[42];
	  t85[43] = x[43];
	  t85[44] = x[44];
	  t85[45] = x[45];
	  t85[46] = x[68];
	  t85[47] = x[69];
	  t85[48] = x[4];
	  t85[49] = x[5];
	  t85[50] = x[28];
	  t85[51] = x[29];
	  t85[52] = x[52];
	  t85[53] = x[53];
	  t85[54] = x[76];
	  t85[55] = x[77];
	  t85[56] = x[12];
	  t85[57] = x[13];
	  t85[58] = x[36];
	  t85[59] = x[37];
	  t85[60] = x[60];
	  t85[61] = x[61];
	  t85[62] = x[84];
	  t85[63] = x[85];
	  t85[64] = x[20];
	  t85[65] = x[21];
	  t85[66] = x[22];
	  t85[67] = x[23];
	  t85[68] = x[46];
	  t85[69] = x[47];
	  t85[70] = x[70];
	  t85[71] = x[71];
	  t85[72] = x[6];
	  t85[73] = x[7];
	  t85[74] = x[30];
	  t85[75] = x[31];
	  t85[76] = x[54];
	  t85[77] = x[55];
	  t85[78] = x[78];
	  t85[79] = x[79];
	  t85[80] = x[14];
	  t85[81] = x[15];
	  t85[82] = x[38];
	  t85[83] = x[39];
	  t85[84] = x[62];
	  t85[85] = x[63];
	  t85[86] = x[86];
	  t85[87] = x[87];
	  /* deftemp t86 ( 88 ) */
	  for (i0 = 0; i0 < 4; i0++) {  
	    f0 = t85[22*i0+8] - t85[22*i0+6];
	    f1 = t85[22*i0+9] - t85[22*i0+7];
	    f2 = t85[22*i0+8] + t85[22*i0+6];
	    f3 = t85[22*i0+9] + t85[22*i0+7];
	    f4 = t85[22*i0+18] - t85[22*i0+10];
	    f5 = t85[22*i0+19] - t85[22*i0+11];
	    f6 = t85[22*i0+18] + t85[22*i0+10];
	    f7 = t85[22*i0+19] + t85[22*i0+11];
	    f8 = f6 - f2;
	    f9 = f7 - f3;
	    f10 = f6 + f2;
	    f11 = f7 + f3;
	    f12 = f4 + f1;
	    f13 = f5 - f0;
	    f14 = f4 - f1;
	    f15 = f5 + f0;
	    f16 = t85[22*i0+2] + f10;
	    f17 = t85[22*i0+3] + f11;
	    f18 = 2.5000000000000000e-01 * f10;
	    f19 = 2.5000000000000000e-01 * f11;
	    f20 = t85[22*i0+2] - f18;
	    f21 = t85[22*i0+3] - f19;
	    f22 = 2.9389262614623651e-01 * f12;
	    f23 = 4.7552825814757688e-01 * f13;
	    f24 = 2.9389262614623651e-01 * f13;
	    f25 = 4.7552825814757688e-01 * f12;
	    f26 = f22 + f23;
	    f27 = f25 - f24;
	    f28 = 5.5901699437494745e-01 * f8;
	    f29 = 5.5901699437494745e-01 * f9;
	    f30 = 2.9389262614623662e-01 * f14;
	    f31 = 4.7552825814757671e-01 * f15;
	    f32 = 2.9389262614623662e-01 * f15;
	    f33 = 4.7552825814757671e-01 * f14;
	    f34 = f30 - f31;
	    f35 = f32 + f33;
	    f36 = f26 + f34;
	    f37 = f27 - f35;
	    f38 = f34 - f26;
	    f39 = f27 + f35;
	    f40 = f20 - f28;
	    f41 = f21 - f29;
	    f42 = f20 + f28;
	    f43 = f21 + f29;
	    f44 = f42 - f38;
	    f45 = f43 - f39;
	    f46 = f42 + f38;
	    f47 = f43 + f39;
	    f48 = f40 + f37;
	    f49 = f41 + f36;
	    f50 = f40 - f37;
	    f51 = f41 - f36;
	    f52 = t85[22*i0+14] - t85[22*i0+16];
	    f53 = t85[22*i0+15] - t85[22*i0+17];
	    f54 = t85[22*i0+14] + t85[22*i0+16];
	    f55 = t85[22*i0+15] + t85[22*i0+17];
	    f56 = t85[22*i0+4] - t85[22*i0+12];
	    f57 = t85[22*i0+5] - t85[22*i0+13];
	    f58 = t85[22*i0+4] + t85[22*i0+12];
	    f59 = t85[22*i0+5] + t85[22*i0+13];
	    f60 = f58 - f54;
	    f61 = f59 - f55;
	    f62 = f58 + f54;
	    f63 = f59 + f55;
	    f64 = f56 + f53;
	    f65 = f57 - f52;
	    f66 = f56 - f53;
	    f67 = f57 + f52;
	    f68 = t85[22*i0+20] + f62;
	    f69 = t85[22*i0+21] + f63;
	    f70 = 2.5000000000000000e-01 * f62;
	    f71 = 2.5000000000000000e-01 * f63;
	    f72 = t85[22*i0+20] - f70;
	    f73 = t85[22*i0+21] - f71;
	    f74 = 2.9389262614623651e-01 * f64;
	    f75 = 4.7552825814757688e-01 * f65;
	    f76 = 2.9389262614623651e-01 * f65;
	    f77 = 4.7552825814757688e-01 * f64;
	    f78 = f74 + f75;
	    f79 = f77 - f76;
	    f80 = 5.5901699437494745e-01 * f60;
	    f81 = 5.5901699437494745e-01 * f61;
	    f82 = 2.9389262614623662e-01 * f66;
	    f83 = 4.7552825814757671e-01 * f67;
	    f84 = 2.9389262614623662e-01 * f67;
	    f85 = 4.7552825814757671e-01 * f66;
	    f86 = f82 - f83;
	    f87 = f84 + f85;
	    f88 = f78 + f86;
	    f89 = f79 - f87;
	    f90 = f86 - f78;
	    f91 = f79 + f87;
	    f92 = f72 - f80;
	    f93 = f73 - f81;
	    f94 = f72 + f80;
	    f95 = f73 + f81;
	    f96 = f94 - f90;
	    f97 = f95 - f91;
	    f98 = f94 + f90;
	    f99 = f95 + f91;
	    f100 = f92 + f89;
	    f101 = f93 + f88;
	    f102 = f92 - f89;
	    f103 = f93 - f88;
	    f104 = f16 - f68;
	    f105 = f17 - f69;
	    f106 = f16 + f68;
	    f107 = f17 + f69;
	    f108 = f46 - f98;
	    f109 = f47 - f99;
	    f110 = f46 + f98;
	    f111 = f47 + f99;
	    f112 = f48 - f100;
	    f113 = f49 - f101;
	    f114 = f48 + f100;
	    f115 = f49 + f101;
	    f116 = f50 - f102;
	    f117 = f51 - f103;
	    f118 = f50 + f102;
	    f119 = f51 + f103;
	    f120 = f44 - f96;
	    f121 = f45 - f97;
	    f122 = f44 + f96;
	    f123 = f45 + f97;
	    t86[22*i0] = t85[22*i0] + f106;
	    t86[22*i0+1] = t85[22*i0+1] + f107;
	    f126 = 1.0000000000000001e-01 * f106;
	    f127 = 1.0000000000000001e-01 * f107;
	    f128 = t85[22*i0] - f126;
	    f129 = t85[22*i0+1] - f127;
	    f130 = 9.5530187798436847e-02 * f112;
	    f131 = 3.1760664857523913e-01 * f113;
	    f132 = 9.5530187798436847e-02 * f113;
	    f133 = 3.1760664857523913e-01 * f112;
	    f134 = f130 + f131;
	    f135 = f133 - f132;
	    f136 = 2.6361055643248354e-01 * f122;
	    f137 = 2.0126965627574470e-01 * f123;
	    f138 = 2.6361055643248354e-01 * f123;
	    f139 = 2.0126965627574470e-01 * f122;
	    f140 = f136 - f137;
	    f141 = f138 + f139;
	    f142 = 2.5412780247155026e-01 * f108;
	    f143 = 2.1311747936521019e-01 * f109;
	    f144 = 2.5412780247155026e-01 * f109;
	    f145 = 2.1311747936521019e-01 * f108;
	    f146 = f143 - f142;
	    f147 = f144 + f145;
	    f148 = 2.0701620998310719e-01 * f118;
	    f149 = 2.5912215035428782e-01 * f119;
	    f150 = 2.0701620998310719e-01 * f119;
	    f151 = 2.5912215035428782e-01 * f118;
	    f152 = f148 - f149;
	    f153 = f150 + f151;
	    f154 = 3.3166247903553991e-01 * f105;
	    f155 = 3.3166247903553991e-01 * f104;
	    f156 = 2.0701620998310705e-01 * f114;
	    f157 = 2.5912215035428776e-01 * f115;
	    f158 = 2.0701620998310705e-01 * f115;
	    f159 = 2.5912215035428776e-01 * f114;
	    f160 = f156 + f157;
	    f161 = f158 - f159;
	    f162 = 2.5412780247155003e-01 * f120;
	    f163 = 2.1311747936521030e-01 * f121;
	    f164 = 2.5412780247155003e-01 * f121;
	    f165 = 2.1311747936521030e-01 * f120;
	    f166 = f162 + f163;
	    f167 = f164 - f165;
	    f168 = 2.6361055643248349e-01 * f110;
	    f169 = 2.0126965627574470e-01 * f111;
	    f170 = 2.6361055643248349e-01 * f111;
	    f171 = 2.0126965627574470e-01 * f110;
	    f172 = f168 + f169;
	    f173 = f170 - f171;
	    f174 = 9.5530187798437027e-02 * f116;
	    f175 = 3.1760664857523901e-01 * f117;
	    f176 = 9.5530187798437027e-02 * f117;
	    f177 = 3.1760664857523901e-01 * f116;
	    f178 = f174 - f175;
	    f179 = f176 + f177;
	    f180 = f140 - f172;
	    f181 = f141 - f173;
	    f182 = f140 + f172;
	    f183 = f141 + f173;
	    f184 = f160 - f152;
	    f185 = f161 - f153;
	    f186 = f160 + f152;
	    f187 = f161 + f153;
	    f188 = f186 - f182;
	    f189 = f187 - f183;
	    f190 = f186 + f182;
	    f191 = f187 + f183;
	    f192 = f184 + f181;
	    f193 = f185 - f180;
	    f194 = f184 - f181;
	    f195 = f185 + f180;
	    f196 = f128 + f190;
	    f197 = f129 + f191;
	    f198 = 2.5000000000000000e-01 * f190;
	    f199 = 2.5000000000000000e-01 * f191;
	    f200 = f128 - f198;
	    f201 = f129 - f199;
	    f202 = 2.9389262614623651e-01 * f192;
	    f203 = 4.7552825814757688e-01 * f193;
	    f204 = 2.9389262614623651e-01 * f193;
	    f205 = 4.7552825814757688e-01 * f192;
	    f206 = f202 + f203;
	    f207 = f205 - f204;
	    f208 = 5.5901699437494745e-01 * f188;
	    f209 = 5.5901699437494745e-01 * f189;
	    f210 = 2.9389262614623662e-01 * f194;
	    f211 = 4.7552825814757671e-01 * f195;
	    f212 = 2.9389262614623662e-01 * f195;
	    f213 = 4.7552825814757671e-01 * f194;
	    f214 = f210 - f211;
	    f215 = f212 + f213;
	    f216 = f206 + f214;
	    f217 = f207 - f215;
	    f218 = f214 - f206;
	    f219 = f207 + f215;
	    f220 = f200 - f208;
	    f221 = f201 - f209;
	    f222 = f200 + f208;
	    f223 = f201 + f209;
	    f224 = f222 - f218;
	    f225 = f223 - f219;
	    f226 = f222 + f218;
	    f227 = f223 + f219;
	    f228 = f220 + f217;
	    f229 = f221 + f216;
	    f230 = f220 - f217;
	    f231 = f221 - f216;
	    f232 = f166 - f146;
	    f233 = f167 + f147;
	    f234 = f166 + f146;
	    f235 = f167 - f147;
	    f236 = f134 + f178;
	    f237 = f135 - f179;
	    f238 = f178 - f134;
	    f239 = f135 + f179;
	    f240 = f238 - f234;
	    f241 = f239 - f235;
	    f242 = f238 + f234;
	    f243 = f239 + f235;
	    f244 = f233 - f236;
	    f245 = f237 - f232;
	    f246 = f236 + f233;
	    f247 = f237 + f232;
	    f248 = f242 - f154;
	    f249 = f155 + f243;
	    f250 = 2.5000000000000000e-01 * f242;
	    f251 = 2.5000000000000000e-01 * f243;
	    f252 = f154 + f250;
	    f253 = f155 - f251;
	    f254 = 2.9389262614623651e-01 * f244;
	    f255 = 4.7552825814757688e-01 * f245;
	    f256 = 2.9389262614623651e-01 * f245;
	    f257 = 4.7552825814757688e-01 * f244;
	    f258 = f254 + f255;
	    f259 = f257 - f256;
	    f260 = 5.5901699437494745e-01 * f240;
	    f261 = 5.5901699437494745e-01 * f241;
	    f262 = 2.9389262614623662e-01 * f246;
	    f263 = 4.7552825814757671e-01 * f247;
	    f264 = 2.9389262614623662e-01 * f247;
	    f265 = 4.7552825814757671e-01 * f246;
	    f266 = f262 + f263;
	    f267 = f264 - f265;
	    f268 = f266 - f258;
	    f269 = f259 - f267;
	    f270 = f258 + f266;
	    f271 = f259 + f267;
	    f272 = f252 + f260;
	    f273 = f253 - f261;
	    f274 = f260 - f252;
	    f275 = f253 + f261;
	    f276 = f274 + f270;
	    f277 = f275 - f271;
	    f278 = f274 - f270;
	    f279 = f275 + f271;
	    f280 = f269 - f272;
	    f281 = f273 - f268;
	    f282 = f272 + f269;
	    f283 = f273 + f268;
	    t86[22*i0+20] = f196 - f248;
	    t86[22*i0+21] = f197 - f249;
	    t86[22*i0+2] = f196 + f248;
	    t86[22*i0+3] = f197 + f249;
	    t86[22*i0+16] = f226 - f278;
	    t86[22*i0+17] = f227 - f279;
	    t86[22*i0+6] = f226 + f278;
	    t86[22*i0+7] = f227 + f279;
	    t86[22*i0+4] = f228 - f280;
	    t86[22*i0+5] = f229 - f281;
	    t86[22*i0+18] = f228 + f280;
	    t86[22*i0+19] = f229 + f281;
	    t86[22*i0+12] = f230 + f282;
	    t86[22*i0+13] = f231 - f283;
	    t86[22*i0+10] = f230 - f282;
	    t86[22*i0+11] = f231 + f283;
	    t86[22*i0+14] = f224 - f276;
	    t86[22*i0+15] = f225 - f277;
	    t86[22*i0+8] = f224 + f276;
	    t86[22*i0+9] = f225 + f277;
	    }
	  for (i0 = 0; i0 < 11; i0++) {  
	    f304 = t86[2*i0+22] - t86[2*i0+66];
	    f305 = t86[2*i0+23] - t86[2*i0+67];
	    f306 = t86[2*i0+22] + t86[2*i0+66];
	    f307 = t86[2*i0+23] + t86[2*i0+67];
	    f308 = t86[2*i0] - t86[2*i0+44];
	    f309 = t86[2*i0+1] - t86[2*i0+45];
	    f310 = t86[2*i0] + t86[2*i0+44];
	    f311 = t86[2*i0+1] + t86[2*i0+45];
	    t84[2*i0+44] = f310 - f306;
	    t84[2*i0+45] = f311 - f307;
	    t84[2*i0] = f310 + f306;
	    t84[2*i0+1] = f311 + f307;
	    t84[2*i0+66] = f308 + f305;
	    t84[2*i0+67] = f309 - f304;
	    t84[2*i0+22] = f308 - f305;
	    t84[2*i0+23] = f309 + f304;
	    }
	  /* undeftemp t86 ( 88 ) */
	  /* undeftemp t85 ( 88 ) */
	  /* deftemp t226 ( 88 ) */
	  for (i0 = 0; i0 < 4; i0++) {  
	    t226[22*i0] = t84[22*i0];
	    t226[22*i0+1] = t84[22*i0+1];
	    t226[22*i0+2] = t84[22*i0+6];
	    t226[22*i0+3] = t84[22*i0+7];
	    t226[22*i0+4] = t84[22*i0+12];
	    t226[22*i0+5] = t84[22*i0+13];
	    t226[22*i0+6] = t84[22*i0+18];
	    t226[22*i0+7] = t84[22*i0+19];
	    t226[22*i0+8] = t84[22*i0+2];
	    t226[22*i0+9] = t84[22*i0+3];
	    t226[22*i0+10] = t84[22*i0+8];
	    t226[22*i0+11] = t84[22*i0+9];
	    t226[22*i0+12] = t84[22*i0+14];
	    t226[22*i0+13] = t84[22*i0+15];
	    t226[22*i0+14] = t84[22*i0+20];
	    t226[22*i0+15] = t84[22*i0+21];
	    t226[22*i0+16] = t84[22*i0+4];
	    t226[22*i0+17] = t84[22*i0+5];
	    t226[22*i0+18] = t84[22*i0+10];
	    t226[22*i0+19] = t84[22*i0+11];
	    t226[22*i0+20] = t84[22*i0+16];
	    t226[22*i0+21] = t84[22*i0+17];
	    }
	  for (i0 = 0; i0 < 11; i0++) {  
	    t83[2*i0] = t226[2*i0];
	    t83[2*i0+1] = t226[2*i0+1];
	    t83[2*i0+22] = t226[2*i0+66];
	    t83[2*i0+23] = t226[2*i0+67];
	    t83[2*i0+44] = t226[2*i0+44];
	    t83[2*i0+45] = t226[2*i0+45];
	    t83[2*i0+66] = t226[2*i0+22];
	    t83[2*i0+67] = t226[2*i0+23];
	    }
	  /* undeftemp t226 ( 88 ) */
	  /* undeftemp t84 ( 88 ) */
	  y[0] = t83[0];
	  y[1] = t83[1];
	  y[2] = t83[24];
	  y[3] = t83[25];
	  y[4] = t83[48];
	  y[5] = t83[49];
	  y[6] = t83[72];
	  y[7] = t83[73];
	  y[8] = t83[8];
	  y[9] = t83[9];
	  y[10] = t83[32];
	  y[11] = t83[33];
	  y[12] = t83[56];
	  y[13] = t83[57];
	  y[14] = t83[80];
	  y[15] = t83[81];
	  y[16] = t83[16];
	  y[17] = t83[17];
	  y[18] = t83[40];
	  y[19] = t83[41];
	  y[20] = t83[64];
	  y[21] = t83[65];
	  y[22] = t83[66];
	  y[23] = t83[67];
	  y[24] = t83[2];
	  y[25] = t83[3];
	  y[26] = t83[26];
	  y[27] = t83[27];
	  y[28] = t83[50];
	  y[29] = t83[51];
	  y[30] = t83[74];
	  y[31] = t83[75];
	  y[32] = t83[10];
	  y[33] = t83[11];
	  y[34] = t83[34];
	  y[35] = t83[35];
	  y[36] = t83[58];
	  y[37] = t83[59];
	  y[38] = t83[82];
	  y[39] = t83[83];
	  y[40] = t83[18];
	  y[41] = t83[19];
	  y[42] = t83[42];
	  y[43] = t83[43];
	  y[44] = t83[44];
	  y[45] = t83[45];
	  y[46] = t83[68];
	  y[47] = t83[69];
	  y[48] = t83[4];
	  y[49] = t83[5];
	  y[50] = t83[28];
	  y[51] = t83[29];
	  y[52] = t83[52];
	  y[53] = t83[53];
	  y[54] = t83[76];
	  y[55] = t83[77];
	  y[56] = t83[12];
	  y[57] = t83[13];
	  y[58] = t83[36];
	  y[59] = t83[37];
	  y[60] = t83[60];
	  y[61] = t83[61];
	  y[62] = t83[84];
	  y[63] = t83[85];
	  y[64] = t83[20];
	  y[65] = t83[21];
	  y[66] = t83[22];
	  y[67] = t83[23];
	  y[68] = t83[46];
	  y[69] = t83[47];
	  y[70] = t83[70];
	  y[71] = t83[71];
	  y[72] = t83[6];
	  y[73] = t83[7];
	  y[74] = t83[30];
	  y[75] = t83[31];
	  y[76] = t83[54];
	  y[77] = t83[55];
	  y[78] = t83[78];
	  y[79] = t83[79];
	  y[80] = t83[14];
	  y[81] = t83[15];
	  y[82] = t83[38];
	  y[83] = t83[39];
	  y[84] = t83[62];
	  y[85] = t83[63];
	  y[86] = t83[86];
	  y[87] = t83[87];
	  /* undeftemp t83 ( 88 ) */

	  /* undecl double t226[88]; */
	  /* undecl double t86[88]; */
	  /* undecl double t85[88]; */
	  /* undecl double t84[88]; */
	  /* undecl double t83[88]; */

	}
	void init_FFT_M2X_44( void )
	{
	}

