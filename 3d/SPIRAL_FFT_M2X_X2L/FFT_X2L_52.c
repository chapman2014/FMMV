/*
! +-----------------------------------------------+
! |        Generated by SPL Compiler 3.30         |
! +-----------------------------------------------+
! Command-line options: -l -B 32 -C -xprecision=double -xposw -xsubname=FFT_X2L_52 
! 
*/
/*
! The SPL Program: (compose (permutation (...1 x 52 ...))(compose (tensor (..)(..))(compose (..)(..))))
! node size: 52 X 52
*/


	void FFT_X2L_52(double *y, double *x) {
	int i0;
	double f0;
	double f1;
	double f2;
	double f3;
	double f4;
	double f5;
	double f6;
	double f7;
	double f16;
	double f17;
	double f18;
	double f19;
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
	double f256;
	double f257;
	double f258;
	double f259;
	double f260;
	double f261;
	double f266;
	double f267;
	double f268;
	double f269;
	double f272;
	double f273;
	double f274;
	double f275;
	double f276;
	double f277;
	double f282;
	double f283;
	double f284;
	double f285;
	double f288;
	double f289;
	double f290;
	double f291;
	double f292;
	double f293;
	double f298;
	double f299;
	double f300;
	double f301;
	double f304;
	double f305;
	double f306;
	double f307;
	double f308;
	double f309;
	  static double t57[104];
	  static double t58[104];
	  static double t59[104];
	  static double t60[104];
	  extern double T_52_4 [104];

	  /* deftemp t57 ( 104 ) */
	  /* deftemp t58 ( 104 ) */
	  /* deftemp t59 ( 104 ) */
	  /* deftemp t60 ( 104 ) */
	  t60[0] = x[0];
	  t60[1] = x[1];
	  t60[2] = x[26];
	  t60[3] = x[27];
	  t60[4] = x[52];
	  t60[5] = x[53];
	  t60[6] = x[78];
	  t60[7] = x[79];
	  t60[8] = x[2];
	  t60[9] = x[3];
	  t60[10] = x[28];
	  t60[11] = x[29];
	  t60[12] = x[54];
	  t60[13] = x[55];
	  t60[14] = x[80];
	  t60[15] = x[81];
	  t60[16] = x[4];
	  t60[17] = x[5];
	  t60[18] = x[30];
	  t60[19] = x[31];
	  t60[20] = x[56];
	  t60[21] = x[57];
	  t60[22] = x[82];
	  t60[23] = x[83];
	  t60[24] = x[6];
	  t60[25] = x[7];
	  t60[26] = x[32];
	  t60[27] = x[33];
	  t60[28] = x[58];
	  t60[29] = x[59];
	  t60[30] = x[84];
	  t60[31] = x[85];
	  t60[32] = x[8];
	  t60[33] = x[9];
	  t60[34] = x[34];
	  t60[35] = x[35];
	  t60[36] = x[60];
	  t60[37] = x[61];
	  t60[38] = x[86];
	  t60[39] = x[87];
	  t60[40] = x[10];
	  t60[41] = x[11];
	  t60[42] = x[36];
	  t60[43] = x[37];
	  t60[44] = x[62];
	  t60[45] = x[63];
	  t60[46] = x[88];
	  t60[47] = x[89];
	  t60[48] = x[12];
	  t60[49] = x[13];
	  t60[50] = x[38];
	  t60[51] = x[39];
	  t60[52] = x[64];
	  t60[53] = x[65];
	  t60[54] = x[90];
	  t60[55] = x[91];
	  t60[56] = x[14];
	  t60[57] = x[15];
	  t60[58] = x[40];
	  t60[59] = x[41];
	  t60[60] = x[66];
	  t60[61] = x[67];
	  t60[62] = x[92];
	  t60[63] = x[93];
	  t60[64] = x[16];
	  t60[65] = x[17];
	  t60[66] = x[42];
	  t60[67] = x[43];
	  t60[68] = x[68];
	  t60[69] = x[69];
	  t60[70] = x[94];
	  t60[71] = x[95];
	  t60[72] = x[18];
	  t60[73] = x[19];
	  t60[74] = x[44];
	  t60[75] = x[45];
	  t60[76] = x[70];
	  t60[77] = x[71];
	  t60[78] = x[96];
	  t60[79] = x[97];
	  t60[80] = x[20];
	  t60[81] = x[21];
	  t60[82] = x[46];
	  t60[83] = x[47];
	  t60[84] = x[72];
	  t60[85] = x[73];
	  t60[86] = x[98];
	  t60[87] = x[99];
	  t60[88] = x[22];
	  t60[89] = x[23];
	  t60[90] = x[48];
	  t60[91] = x[49];
	  t60[92] = x[74];
	  t60[93] = x[75];
	  t60[94] = x[100];
	  t60[95] = x[101];
	  t60[96] = x[24];
	  t60[97] = x[25];
	  t60[98] = x[50];
	  t60[99] = x[51];
	  t60[100] = x[76];
	  t60[101] = x[77];
	  t60[102] = x[102];
	  t60[103] = x[103];
	  for (i0 = 0; i0 < 13; i0++) {  
	    f0 = t60[8*i0+2] - t60[8*i0+6];
	    f1 = t60[8*i0+3] - t60[8*i0+7];
	    f2 = t60[8*i0+2] + t60[8*i0+6];
	    f3 = t60[8*i0+3] + t60[8*i0+7];
	    f4 = t60[8*i0] - t60[8*i0+4];
	    f5 = t60[8*i0+1] - t60[8*i0+5];
	    f6 = t60[8*i0] + t60[8*i0+4];
	    f7 = t60[8*i0+1] + t60[8*i0+5];
	    t59[8*i0+4] = f6 - f2;
	    t59[8*i0+5] = f7 - f3;
	    t59[8*i0] = f6 + f2;
	    t59[8*i0+1] = f7 + f3;
	    t59[8*i0+6] = f4 + f1;
	    t59[8*i0+7] = f5 - f0;
	    t59[8*i0+2] = f4 - f1;
	    t59[8*i0+3] = f5 + f0;
	    }
	  /* undeftemp t60 ( 104 ) */
	  for (i0 = 0; i0 < 52; i0++) {  
	    f16 = T_52_4[2*i0] * t59[2*i0];
	    f17 = T_52_4[2*i0+1] * t59[2*i0+1];
	    f18 = T_52_4[2*i0] * t59[2*i0+1];
	    f19 = T_52_4[2*i0+1] * t59[2*i0];
	    t58[2*i0] = f16 - f17;
	    t58[2*i0+1] = f18 + f19;
	    }
	  /* undeftemp t59 ( 104 ) */
	  for (i0 = 0; i0 < 4; i0++) {  
	    f22 = t58[2*i0+40] - t58[2*i0+64];
	    f23 = t58[2*i0+41] - t58[2*i0+65];
	    f24 = t58[2*i0+40] + t58[2*i0+64];
	    f25 = t58[2*i0+41] + t58[2*i0+65];
	    f26 = t58[2*i0+8] - t58[2*i0+96];
	    f27 = t58[2*i0+9] - t58[2*i0+97];
	    f28 = t58[2*i0+8] + t58[2*i0+96];
	    f29 = t58[2*i0+9] + t58[2*i0+97];
	    f30 = f28 - f24;
	    f31 = f29 - f25;
	    f32 = f28 + f24;
	    f33 = f29 + f25;
	    f34 = f26 + f23;
	    f35 = f27 - f22;
	    f36 = f26 - f23;
	    f37 = f27 + f22;
	    f38 = t58[2*i0+16] - t58[2*i0+88];
	    f39 = t58[2*i0+17] - t58[2*i0+89];
	    f40 = t58[2*i0+16] + t58[2*i0+88];
	    f41 = t58[2*i0+17] + t58[2*i0+89];
	    f42 = t58[2*i0+24] - t58[2*i0+80];
	    f43 = t58[2*i0+25] - t58[2*i0+81];
	    f44 = t58[2*i0+24] + t58[2*i0+80];
	    f45 = t58[2*i0+25] + t58[2*i0+81];
	    f46 = f44 - f40;
	    f47 = f45 - f41;
	    f48 = f44 + f40;
	    f49 = f45 + f41;
	    f50 = f42 + f39;
	    f51 = f43 - f38;
	    f52 = f42 - f39;
	    f53 = f43 + f38;
	    f54 = t58[2*i0+48] - t58[2*i0+56];
	    f55 = t58[2*i0+49] - t58[2*i0+57];
	    f56 = t58[2*i0+48] + t58[2*i0+56];
	    f57 = t58[2*i0+49] + t58[2*i0+57];
	    f58 = t58[2*i0+72] - t58[2*i0+32];
	    f59 = t58[2*i0+73] - t58[2*i0+33];
	    f60 = t58[2*i0+72] + t58[2*i0+32];
	    f61 = t58[2*i0+73] + t58[2*i0+33];
	    f62 = f60 - f56;
	    f63 = f61 - f57;
	    f64 = f60 + f56;
	    f65 = f61 + f57;
	    f66 = f58 + f55;
	    f67 = f59 - f54;
	    f68 = f58 - f55;
	    f69 = f59 + f54;
	    f70 = f48 - f64;
	    f71 = f49 - f65;
	    f72 = f48 + f64;
	    f73 = f49 + f65;
	    f74 = f32 + f72;
	    f75 = f33 + f73;
	    f76 = 5.0000000000000000e-01 * f72;
	    f77 = 5.0000000000000000e-01 * f73;
	    f78 = f32 - f76;
	    f79 = f33 - f77;
	    f80 = 8.6602540378443860e-01 * f71;
	    f81 = 8.6602540378443860e-01 * f70;
	    f82 = f78 + f80;
	    f83 = f79 - f81;
	    f84 = f78 - f80;
	    f85 = f79 + f81;
	    f86 = f52 - f68;
	    f87 = f53 - f69;
	    f88 = f52 + f68;
	    f89 = f53 + f69;
	    f90 = f36 + f88;
	    f91 = f37 + f89;
	    f92 = 5.0000000000000000e-01 * f88;
	    f93 = 5.0000000000000000e-01 * f89;
	    f94 = f36 - f92;
	    f95 = f37 - f93;
	    f96 = 8.6602540378443860e-01 * f87;
	    f97 = 8.6602540378443860e-01 * f86;
	    f98 = f94 + f96;
	    f99 = f95 - f97;
	    f100 = f94 - f96;
	    f101 = f95 + f97;
	    f102 = f46 - f62;
	    f103 = f47 - f63;
	    f104 = f46 + f62;
	    f105 = f47 + f63;
	    f106 = f30 + f104;
	    f107 = f31 + f105;
	    f108 = 5.0000000000000000e-01 * f104;
	    f109 = 5.0000000000000000e-01 * f105;
	    f110 = f30 - f108;
	    f111 = f31 - f109;
	    f112 = 8.6602540378443860e-01 * f103;
	    f113 = 8.6602540378443860e-01 * f102;
	    f114 = f110 + f112;
	    f115 = f111 - f113;
	    f116 = f110 - f112;
	    f117 = f111 + f113;
	    f118 = f50 - f66;
	    f119 = f51 - f67;
	    f120 = f50 + f66;
	    f121 = f51 + f67;
	    f122 = f34 + f120;
	    f123 = f35 + f121;
	    f124 = 5.0000000000000000e-01 * f120;
	    f125 = 5.0000000000000000e-01 * f121;
	    f126 = f34 - f124;
	    f127 = f35 - f125;
	    f128 = 8.6602540378443860e-01 * f119;
	    f129 = 8.6602540378443860e-01 * f118;
	    f130 = f126 + f128;
	    f131 = f127 - f129;
	    f132 = f126 - f128;
	    f133 = f127 + f129;
	    t57[2*i0] = t58[2*i0] + f74;
	    t57[2*i0+1] = t58[2*i0+1] + f75;
	    f136 = 8.3333333333333329e-02 * f74;
	    f137 = 8.3333333333333329e-02 * f75;
	    f138 = t58[2*i0] - f136;
	    f139 = t58[2*i0+1] - f137;
	    f140 = 2.5624767158293649e-01 * f98;
	    f141 = 1.5689139105158467e-01 * f99;
	    f142 = 2.5624767158293649e-01 * f99;
	    f143 = 1.5689139105158467e-01 * f98;
	    f144 = f140 + f141;
	    f145 = f143 - f142;
	    f146 = 2.5826039031174497e-01 * f116;
	    f147 = 1.5355568557954136e-01 * f117;
	    f148 = 2.5826039031174497e-01 * f117;
	    f149 = 1.5355568557954136e-01 * f116;
	    f150 = f146 - f147;
	    f151 = f148 + f149;
	    f152 = 2.8757036473700154e-01 * f122;
	    f153 = 8.7069300576068015e-02 * f123;
	    f154 = 2.8757036473700154e-01 * f123;
	    f155 = 8.7069300576068015e-02 * f122;
	    f156 = f152 + f153;
	    f157 = f155 - f154;
	    f158 = 7.5902986037193920e-02 * f82;
	    f159 = 2.9071724147084105e-01 * f83;
	    f160 = 7.5902986037193920e-02 * f83;
	    f161 = 2.9071724147084105e-01 * f82;
	    f162 = f158 - f159;
	    f163 = f160 + f161;
	    f164 = 3.0023863596633255e-01 * f100;
	    f165 = 1.1599105605768394e-02 * f101;
	    f166 = 3.0023863596633255e-01 * f101;
	    f167 = 1.1599105605768394e-02 * f100;
	    f168 = f164 + f165;
	    f169 = f166 - f167;
	    f170 = 3.0046260628866583e-01 * f106;
	    f171 = 3.0046260628866583e-01 * f107;
	    f172 = 3.0023863596633255e-01 * f130;
	    f173 = 1.1599105605768285e-02 * f131;
	    f174 = 3.0023863596633255e-01 * f131;
	    f175 = 1.1599105605768285e-02 * f130;
	    f176 = f173 - f172;
	    f177 = f174 + f175;
	    f178 = 7.5902986037193768e-02 * f84;
	    f179 = 2.9071724147084099e-01 * f85;
	    f180 = 7.5902986037193768e-02 * f85;
	    f181 = 2.9071724147084099e-01 * f84;
	    f182 = f178 + f179;
	    f183 = f180 - f181;
	    f184 = 2.8757036473700143e-01 * f90;
	    f185 = 8.7069300576067835e-02 * f91;
	    f186 = 2.8757036473700143e-01 * f91;
	    f187 = 8.7069300576067835e-02 * f90;
	    f188 = f184 - f185;
	    f189 = f186 + f187;
	    f190 = 2.5826039031174480e-01 * f114;
	    f191 = 1.5355568557954136e-01 * f115;
	    f192 = 2.5826039031174480e-01 * f115;
	    f193 = 1.5355568557954136e-01 * f114;
	    f194 = f190 + f191;
	    f195 = f192 - f193;
	    f196 = 2.5624767158293660e-01 * f132;
	    f197 = 1.5689139105158451e-01 * f133;
	    f198 = 2.5624767158293660e-01 * f133;
	    f199 = 1.5689139105158451e-01 * f132;
	    f200 = f196 - f197;
	    f201 = f198 + f199;
	    f202 = f188 + f156;
	    f203 = f189 - f157;
	    f204 = f188 - f156;
	    f205 = f189 + f157;
	    f206 = f138 - f170;
	    f207 = f139 - f171;
	    f208 = f138 + f170;
	    f209 = f139 + f171;
	    f210 = f208 - f204;
	    f211 = f209 - f205;
	    f212 = f208 + f204;
	    f213 = f209 + f205;
	    f214 = f206 + f203;
	    f215 = f207 - f202;
	    f216 = f206 - f203;
	    f217 = f207 + f202;
	    f218 = f144 + f176;
	    f219 = f145 + f177;
	    f220 = f176 - f144;
	    f221 = f145 - f177;
	    f222 = f162 - f194;
	    f223 = f163 - f195;
	    f224 = f162 + f194;
	    f225 = f163 + f195;
	    f226 = f224 - f220;
	    f227 = f225 - f221;
	    f228 = f224 + f220;
	    f229 = f225 + f221;
	    f230 = f222 + f219;
	    f231 = f223 + f218;
	    f232 = f222 - f219;
	    f233 = f223 - f218;
	    f234 = f168 - f200;
	    f235 = f169 - f201;
	    f236 = f168 + f200;
	    f237 = f169 + f201;
	    f238 = f182 - f150;
	    f239 = f183 - f151;
	    f240 = f182 + f150;
	    f241 = f183 + f151;
	    f242 = f240 - f236;
	    f243 = f241 - f237;
	    f244 = f240 + f236;
	    f245 = f241 + f237;
	    f246 = f238 + f235;
	    f247 = f239 - f234;
	    f248 = f238 - f235;
	    f249 = f239 + f234;
	    f250 = f228 - f244;
	    f251 = f229 - f245;
	    f252 = f228 + f244;
	    f253 = f229 + f245;
	    t57[2*i0+8] = f212 + f252;
	    t57[2*i0+9] = f213 + f253;
	    f256 = 5.0000000000000000e-01 * f252;
	    f257 = 5.0000000000000000e-01 * f253;
	    f258 = f212 - f256;
	    f259 = f213 - f257;
	    f260 = 8.6602540378443860e-01 * f251;
	    f261 = 8.6602540378443860e-01 * f250;
	    t57[2*i0+24] = f258 + f260;
	    t57[2*i0+25] = f259 - f261;
	    t57[2*i0+72] = f258 - f260;
	    t57[2*i0+73] = f259 + f261;
	    f266 = f232 - f248;
	    f267 = f233 - f249;
	    f268 = f232 + f248;
	    f269 = f233 + f249;
	    t57[2*i0+40] = f216 + f268;
	    t57[2*i0+41] = f217 + f269;
	    f272 = 5.0000000000000000e-01 * f268;
	    f273 = 5.0000000000000000e-01 * f269;
	    f274 = f216 - f272;
	    f275 = f217 - f273;
	    f276 = 8.6602540378443860e-01 * f267;
	    f277 = 8.6602540378443860e-01 * f266;
	    t57[2*i0+16] = f274 + f276;
	    t57[2*i0+17] = f275 - f277;
	    t57[2*i0+48] = f274 - f276;
	    t57[2*i0+49] = f275 + f277;
	    f282 = f226 - f242;
	    f283 = f227 - f243;
	    f284 = f226 + f242;
	    f285 = f227 + f243;
	    t57[2*i0+96] = f210 + f284;
	    t57[2*i0+97] = f211 + f285;
	    f288 = 5.0000000000000000e-01 * f284;
	    f289 = 5.0000000000000000e-01 * f285;
	    f290 = f210 - f288;
	    f291 = f211 - f289;
	    f292 = 8.6602540378443860e-01 * f283;
	    f293 = 8.6602540378443860e-01 * f282;
	    t57[2*i0+80] = f290 + f292;
	    t57[2*i0+81] = f291 - f293;
	    t57[2*i0+32] = f290 - f292;
	    t57[2*i0+33] = f291 + f293;
	    f298 = f230 - f246;
	    f299 = f231 - f247;
	    f300 = f230 + f246;
	    f301 = f231 + f247;
	    t57[2*i0+64] = f214 + f300;
	    t57[2*i0+65] = f215 + f301;
	    f304 = 5.0000000000000000e-01 * f300;
	    f305 = 5.0000000000000000e-01 * f301;
	    f306 = f214 - f304;
	    f307 = f215 - f305;
	    f308 = 8.6602540378443860e-01 * f299;
	    f309 = 8.6602540378443860e-01 * f298;
	    t57[2*i0+88] = f306 + f308;
	    t57[2*i0+89] = f307 - f309;
	    t57[2*i0+56] = f306 - f308;
	    t57[2*i0+57] = f307 + f309;
	    }
	  /* undeftemp t58 ( 104 ) */
	  y[0] = t57[0];
	  y[1] = t57[1];
	  y[2] = t57[102];
	  y[3] = t57[103];
	  y[4] = t57[100];
	  y[5] = t57[101];
	  y[6] = t57[98];
	  y[7] = t57[99];
	  y[8] = t57[96];
	  y[9] = t57[97];
	  y[10] = t57[94];
	  y[11] = t57[95];
	  y[12] = t57[92];
	  y[13] = t57[93];
	  y[14] = t57[90];
	  y[15] = t57[91];
	  y[16] = t57[88];
	  y[17] = t57[89];
	  y[18] = t57[86];
	  y[19] = t57[87];
	  y[20] = t57[84];
	  y[21] = t57[85];
	  y[22] = t57[82];
	  y[23] = t57[83];
	  y[24] = t57[80];
	  y[25] = t57[81];
	  y[26] = t57[78];
	  y[27] = t57[79];
	  y[28] = t57[76];
	  y[29] = t57[77];
	  y[30] = t57[74];
	  y[31] = t57[75];
	  y[32] = t57[72];
	  y[33] = t57[73];
	  y[34] = t57[70];
	  y[35] = t57[71];
	  y[36] = t57[68];
	  y[37] = t57[69];
	  y[38] = t57[66];
	  y[39] = t57[67];
	  y[40] = t57[64];
	  y[41] = t57[65];
	  y[42] = t57[62];
	  y[43] = t57[63];
	  y[44] = t57[60];
	  y[45] = t57[61];
	  y[46] = t57[58];
	  y[47] = t57[59];
	  y[48] = t57[56];
	  y[49] = t57[57];
	  y[50] = t57[54];
	  y[51] = t57[55];
	  y[52] = t57[52];
	  y[53] = t57[53];
	  y[54] = t57[50];
	  y[55] = t57[51];
	  y[56] = t57[48];
	  y[57] = t57[49];
	  y[58] = t57[46];
	  y[59] = t57[47];
	  y[60] = t57[44];
	  y[61] = t57[45];
	  y[62] = t57[42];
	  y[63] = t57[43];
	  y[64] = t57[40];
	  y[65] = t57[41];
	  y[66] = t57[38];
	  y[67] = t57[39];
	  y[68] = t57[36];
	  y[69] = t57[37];
	  y[70] = t57[34];
	  y[71] = t57[35];
	  y[72] = t57[32];
	  y[73] = t57[33];
	  y[74] = t57[30];
	  y[75] = t57[31];
	  y[76] = t57[28];
	  y[77] = t57[29];
	  y[78] = t57[26];
	  y[79] = t57[27];
	  y[80] = t57[24];
	  y[81] = t57[25];
	  y[82] = t57[22];
	  y[83] = t57[23];
	  y[84] = t57[20];
	  y[85] = t57[21];
	  y[86] = t57[18];
	  y[87] = t57[19];
	  y[88] = t57[16];
	  y[89] = t57[17];
	  y[90] = t57[14];
	  y[91] = t57[15];
	  y[92] = t57[12];
	  y[93] = t57[13];
	  y[94] = t57[10];
	  y[95] = t57[11];
	  y[96] = t57[8];
	  y[97] = t57[9];
	  y[98] = t57[6];
	  y[99] = t57[7];
	  y[100] = t57[4];
	  y[101] = t57[5];
	  y[102] = t57[2];
	  y[103] = t57[3];
	  /* undeftemp t57 ( 104 ) */

	  /* undecl double t60[104]; */
	  /* undecl double t59[104]; */
	  /* undecl double t58[104]; */
	  /* undecl double t57[104]; */

	}
#include <math.h>
#ifndef NO_GLOBAL
	double T_52_4 [104];
#endif

	void init_FFT_X2L_52( void )
	{
	int i;
	int j;
	  extern double T_52_4 [104];
	  for (i=0; i<=12; i++) {
	    for (j=0; j<=3; j++) {
	      T_52_4[8*i+2*j] = (cos(6.2831853071795862e+00*i*j/52));
	      T_52_4[8*i+2*j+1] = (sin(6.2831853071795862e+00*i*j/52));
	    }
	  }

	}
