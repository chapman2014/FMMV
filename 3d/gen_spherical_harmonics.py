# FMMV - the Fastest Multipole Method of Vienna
# Copyright (c) 2006-2015 Harald Hofstaetter
# http://www.harald-hofstaetter.at
#
# This file is part of FMMV.
#
# FMMV is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# FMMV is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with FMMV; if not, write to the Free Software  Foundation, Inc.,
# 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#

import math 

def J(n,m):
	return (n*(n+1))/2 + m

def gen_spherical_harmonics(funname, p):
	Fact = [0.0 for i in range(2*p+1)]
	Fact[0] = 1.0;
	for n in range(1,len(Fact)):
		Fact[n]=n*Fact[n-1]

	B = [0.0 for i in range((p*(p+1))/2+p+1) ]

	for n in range(p+1):
		for m in range(n+1):
			B[J(n,m)] = math.sqrt(Fact[n-abs(m)]/Fact[n+abs(m)])

	R = [0.0] + [1.0/i for i in range(1,p+1) ]
	
	type = Op.templates["type"] 	
	basetype = Op.templates["basetype"] 	

	begin_block('void %s_p%i(int p, %s *Y, %s sin_phi, %s cos_phi, %s cos_theta)\n' % (funname, p, basetype, type, type, type))
	Y = parameter("Y", array=True)
	sin_phi = parameter("sin_phi")
	cos_phi = parameter("cos_phi")
	cos_theta = parameter("cos_theta")

	pmm = var("pmm")
	pm1 = var("pm1")
	pm2 = var("pm2")
	pml = var("pml")
	c = var("c")
	s = var("s")
	h = var("h")
	alpha = var("alpha")
	beta = var("beta")
	sqrt_1_minus_cos_theta_2 = var("sqrt_1_minus_cos_theta_2", sqrt(1.0 - cos_theta*cos_theta))
	print

	pmm ^= 1.0
	
	## m==0: #############################
	Y[0] ^= B[0] * pmm
	Y[1] ^= 0.0
	pm2 ^= pmm
	pml ^= pmm*cos_theta
	Y[2] ^= pml
	Y[3] ^= 0.0 
	k = 1
	for l in range(2, p+1):
		pm1 ^= pml
		pml ^= R[l] * ((2*l-1)*cos_theta*pm1 - (l-1)*pm2)
		pm2 ^= pm1
		k += l
		Y[2*k] ^= pml
		Y[2*k+1] ^= 0.0

	## m==1: #############################
	m = 1
	pmm *= -sqrt_1_minus_cos_theta_2
	s ^= sin_phi
	c ^= cos_phi
	alpha ^= 1-c
	beta ^= s
	h ^= B[2] * pmm
	Y[4] ^= c*h
	Y[5] ^= s*h
	pm2 ^= pmm
	pml ^= 3*pmm*cos_theta
	h ^= B[4] * pml
	Y[8] ^= c*h
	Y[9] ^= s*h
	#k = (m+1)*(m+2)/2 + m
	k=4
	for l in range(3, p+1):
		pm1 ^= pml
		pml ^= R[l-1] * ((2*l-1)*cos_theta*pm1 - l*pm2)
		pm2 ^= pm1
		k += l
		h ^= B[k] * pml
		Y[2*k] ^= c*h
		Y[2*k+1] ^= s*h

	## 2 <= m <= p-1: #############################
	kk = 1
	for m in range(2, p):		
		pmm *= (1-2*m)*sqrt_1_minus_cos_theta_2
		h ^= (alpha*c + beta*s)
		s ^= s - alpha*s + beta*c   # to simplify transformation to fma, fms, fnms
		c -= h
		kk += m
		k = kk + m
		h ^= B[k] * pmm
		Y[2*k] ^= c*h
		Y[2*k+1] ^= s*h
		pm2 ^= pmm
		pml ^= (2*m+1)*pmm*cos_theta
		k += m+1
		h ^= B[k] * pml
		Y[2*k] ^= c*h
		Y[2*k+1] ^= s*h
		for l in range(m+2, p+1):
			pm1 ^= pml
			pml ^= R[l-m] * ((2*l-1)*cos_theta*pm1 - (l+m-1)*pm2)
			pm2 ^= pm1
			k += l
			h ^= B[k] * pml
			Y[2*k] ^= c*h
			Y[2*k+1] ^= s*h
	## m==p: #############################
	m = p
        pmm *= (1-2*m)*sqrt_1_minus_cos_theta_2
        h ^= (alpha*c + beta*s)
        s ^= s - alpha*s + beta*c   # to simplify transformation to fma, fms, fnms
        c -= h
	kk += m
	k = kk + m
        h ^= B[k] * pmm
        Y[2*k] ^= c*h
        Y[2*k+1] ^= s*h

	end_block()

from gen_straightline_code import Op, sqrt, var, parameter, templates, begin_block, end_block

p_max_single = 20
p_max_double = 30
preferred_p_list = [8, 16, 23]

import sys

print '''
/* This file is automatically generated by gen_spherical_harmonics.py */
/* DO NOT EDIT! */
#include"_fmmv.h"
'''
if len(sys.argv) > 1:
	par = sys.argv[1]
	print '#include "simd.h"'
	print "#if (FMM_PRECISION==0)"
        print '   #include"%ss.h"' % par
        print "#else"
        print '   #include"%sd.h"' % par
        print "#endif"
	Op.templates = templates[par]
	suf = "_"+par
else:  
	Op.templates = templates["generic"]
	suf = ""

for p in range(p_max_single+2):
	if p in preferred_p_list:
	        gen_spherical_harmonics('compute_spherical_harmonics'+suf, p)
		print
print "#if (FMM_PRECISION>=1)"
for p in range(p_max_single+2, p_max_double+2):
	if p in preferred_p_list:
	        gen_spherical_harmonics('compute_spherical_harmonics'+suf, p)
		print
print "#endif /* FMM_PRECISION>=1 */"

type = Op.templates["type"]
basetype = Op.templates["basetype"]
print
print "void compute_spherical_harmonics_generic%s(int p, %s *Y, %s sin_phi, %s cos_phi, %s cos_theta);" % (suf, basetype, type, type, type)
print

print "void (*compute_spherical_harmonics%s[])(int p, %s *Y, %s sin_phi, %s cos_phi, %s cos_theta) = {" % (suf, basetype, type, type, type)
for p in  range(p_max_single+2):
	if p in preferred_p_list:
		print "compute_spherical_harmonics%s_p%i," % (suf, p)
	else:
		print "compute_spherical_harmonics_generic%s," % suf
print "#if (FMM_PRECISION>=1)"
for p in  range(p_max_single+2, p_max_double+2):
	if p in preferred_p_list:
		print "compute_spherical_harmonics%s_p%i," % (suf, p)
	else:
		print "compute_spherical_harmonics_generic%s," % suf
print "#endif /* FMM_PRECISION>=1 */"
print "};"



