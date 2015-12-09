from fmmv_setup import float_types, simd_vector_length, eval_direct_number_of_accuracies, dim, drivers
from fmmv_setup import charge_pot_combs as charge_pot_combs0

print "# This file is automatically generated by gen_Makefile2.py */"
print "# DO NOT EDIT! */"
print

data = [
("gen_eval_expansions",      False),
("eval_direct",          True),
("extrinsic_correction", False), 
]

simd_suffix = {1:"",2:"_simd2", 4:"_simd4", 8:"_simd8"} 

simds = [simd_suffix[i] for i in list(set(simd_vector_length.values()))]

for float_type in float_types:
    print "SUFFIX_SIMD_%s = %s_%s" % (float_type.upper(), simd_suffix[simd_vector_length[float_type]], float_type)
print    

print "NAMES_ACCESS = \\"
for (driver_suf, subset) in drivers:
    charge_pot_combs =  {x: charge_pot_combs0[x] for x in subset}
    for (name0, acc) in data:
        name = name0+driver_suf
	for i in charge_pot_combs:
	    for st in ["", "_st"]:
		if  acc:
			for j in range(eval_direct_number_of_accuracies["generic"]):	
				print "\t"+name+st+i+("_acc%i" % j)+"\\"
				print "\t"+name+"_periodic"+st+i+("_acc%i" % j)+"\\"
		else:		
			print "\t"+name+st+i+"\\"
print			
print
for (driver_suf, subset) in drivers:
    charge_pot_combs =  {x: charge_pot_combs0[x] for x in subset}
    float_type_nr = 0
    for float_type in float_types:
	for (name0, acc) in data:
             name = name0+driver_suf
	     for simd in simds:
		for i in charge_pot_combs:
		    for st in ["", "_st"]:
			if  acc:
				for j in range(eval_direct_number_of_accuracies["generic"]):	
					dep = name+simd+".c"
					target = "$(ODIR)/"+name+st+i+("_acc%i" % j)+simd+"_"+float_type+".o"
					print "%s: %s" % (target, dep)
					print "\t$(LIBTOOL_COMPILE) -c -D%s -DACCURACY=%i -DFMM_PRECISION=%i $(CFLAGS) -I.. %s -o %s" % (
						(st+i)[1:].upper(), j, float_type_nr, dep, target)
					print	
					target = "$(ODIR)/"+name+"_periodic"+st+i+("_acc%i" % j)+simd+"_"+float_type+".o"
					print "%s: %s" % (target, dep)
					print "\t$(LIBTOOL_COMPILE) -c -DPERIODIC -D%s -DACCURACY=%i -DFMM_PRECISION=%i $(CFLAGS) -I.. %s -o %s" % (
						(st+i)[1:].upper(), j, float_type_nr, dep, target)
					print	
			else:
				target = "$(ODIR)/"+name+st+i+simd+"_"+float_type+".o"
				dep = name+simd+".c"
				print "%s: %s" % (target, dep)
				print "\t$(LIBTOOL_COMPILE) -c -D%s -DFMM_PRECISION=%i $(CFLAGS) -I.. %s -o %s" % (
					(st+i)[1:].upper(), float_type_nr, dep, target)
				print	
	float_type_nr += 1					

