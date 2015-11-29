/* This file is automatically generated by gen_frontend.py */
/* DO NOT EDIT! */

#include"_fmmv.h"
#include<assert.h>

void
#if (FMM_PRECISION==0)
fmmv2df
#elif (FMM_PRECISION==1)
fmmv2d
#endif
(	unsigned int NParticles, 
	_FLOAT_ particles[][2],
	_FLOAT_ charges[],
	_FLOAT_ dipoleMoments[][2],
	unsigned int NTargets, 
	_FLOAT_ targets[][2],
	_FLOAT_ potentials[],
	_FLOAT_ gradients[][2],
	struct FmmvOptions *options, /* if NULL use default options */
	struct FmmvStatistics *statistics, /* can be NULL */
	char **errorMessage)
{
	FmmvHandle *FMMV;
	char *err;
	int typeSources = 0;
	int typeTargets = 0;

	if (dipoleMoments) {
		typeSources |= DIPOLEMOMENTS;
	}
	if (charges) {
		typeSources |= CHARGES;
	}

	if (potentials) {
		typeTargets |= POTENTIALS;
	}
	if (gradients) {
		typeTargets |= GRADIENTS;
	}

#if (FMM_PRECISION==0)
	fmmv2df_initialize
#elif (FMM_PRECISION==1)
	fmmv2d_initialize
#endif
	(	(void**) &FMMV,
		NParticles, particles, typeSources,
		NTargets, targets, typeTargets,
		options, statistics, &err);
	if (err) goto _err;

#if (FMM_PRECISION==0)
	fmmv2df_evaluate
#elif (FMM_PRECISION==1)
	fmmv2d_evaluate
#endif
	(	(void*) FMMV,
		charges, dipoleMoments, 
		potentials, gradients, 
		 statistics, &err);
	if (err) goto _err;

#if (FMM_PRECISION==0)
	fmmv2df_finalize((void*) FMMV, statistics, &err);
#elif (FMM_PRECISION==1)
	fmmv2d_finalize((void*) FMMV, statistics, &err);
#endif
	if (err) goto _err;

	*errorMessage = 0;
_err:
	*errorMessage = err;
}

void
#if (FMM_PRECISION==0)
fmmv2df_initialize
#elif (FMM_PRECISION==1)
fmmv2d_initialize
#endif
(	void** fh,
	unsigned int NParticles,
	_FLOAT_ particles[][2],
	int typeSources,
	unsigned int NTargets, 
	_FLOAT_ targets[][2],
	int typeTargets,
	struct FmmvOptions *options, /* if NULL use default options */
	struct FmmvStatistics *statistics, /* can be NULL */
	char **errorMessage)
{
	FmmvHandle *FMMV;
	char *err;


	FMMV = (FmmvHandle*) malloc(sizeof(FmmvHandle));
	FMMV->magicNumber = 1079252849; /* TODO: fmmv kind specific... */
	FMMV->NParticles = NParticles;
	FMMV->particles = particles;
	FMMV->targets = targets;
	if (targets) {	
		FMMV->NTargets = NTargets;
	}
	else {
		FMMV->NTargets = NParticles;
	}	
	

	if (FMMV->targets) {
		if( (typeSources&CHARGES) && (typeSources&DIPOLEMOMENTS) && (typeTargets&POTENTIALS) && (typeTargets&GRADIENTS) && 1) {
			FMMV->dataKind = FMM_ST_DIPOLE_GRAD;
		}
		else if( (typeSources&CHARGES) && (typeTargets&POTENTIALS) && (typeTargets&GRADIENTS) && 1) {
			FMMV->dataKind = FMM_ST_GRAD;
		}
		else if( (typeSources&CHARGES) && (typeSources&DIPOLEMOMENTS) && (typeTargets&POTENTIALS) && 1) {
			FMMV->dataKind = FMM_ST_DIPOLE;
		}
		else if( (typeSources&CHARGES) && (typeTargets&POTENTIALS) && 1) {
			FMMV->dataKind = FMM_ST_STANDARD;
		}
		else {
			assert(0);
		}
	}
	else{
		if( (typeSources&CHARGES) && (typeSources&DIPOLEMOMENTS) && (typeTargets&POTENTIALS) && (typeTargets&GRADIENTS) && 1) {
			FMMV->dataKind = FMM_DIPOLE_GRAD;
		}
		else if( (typeSources&CHARGES) && (typeTargets&POTENTIALS) && (typeTargets&GRADIENTS) && 1) {
			FMMV->dataKind = FMM_GRAD;
		}
		else if( (typeSources&CHARGES) && (typeSources&DIPOLEMOMENTS) && (typeTargets&POTENTIALS) && 1) {
			FMMV->dataKind = FMM_DIPOLE;
		}
		else if( (typeSources&CHARGES) && (typeTargets&POTENTIALS) && 1) {
			FMMV->dataKind = FMM_STANDARD;
		}
		else {
			assert(0);
		}
	}

	FMMV->beta = options->beta; 
	err = fmmv_initialize(&FMMV, options, statistics);
	if (err) goto _err;

	switch(FMMV->dataKind) {
	case FMM_STANDARD:
		FMMV->gen_M = gen_M_standard;
		FMMV->eval_L = eval_L_standard;
		FMMV->eval_M = 0;
		FMMV->gen_L = 0;
		FMMV->gen_L_eval_M = gen_L_eval_M_standard;
		FMMV->extrinsic_correction = extrinsic_correction_standard;
		switch(FMMV->directEvalAccuracy) {
		case 0:
			FMMV->eval_direct = eval_direct_standard_acc0;
			FMMV->eval_direct_periodic = eval_direct_periodic_standard_acc0;
			break;
		case 1:
			FMMV->eval_direct = eval_direct_standard_acc1;
			FMMV->eval_direct_periodic = eval_direct_periodic_standard_acc1;
			break;
		case 2:
			FMMV->eval_direct = eval_direct_standard_acc2;
			FMMV->eval_direct_periodic = eval_direct_periodic_standard_acc2;
			break;
		}
		break;
	case FMM_DIPOLE:
		FMMV->gen_M = gen_M_dipole;
		FMMV->eval_L = eval_L_dipole;
		FMMV->eval_M = 0;
		FMMV->gen_L = 0;
		FMMV->gen_L_eval_M = gen_L_eval_M_dipole;
		FMMV->extrinsic_correction = extrinsic_correction_dipole;
		switch(FMMV->directEvalAccuracy) {
		case 0:
			FMMV->eval_direct = eval_direct_dipole_acc0;
			FMMV->eval_direct_periodic = eval_direct_periodic_dipole_acc0;
			break;
		case 1:
			FMMV->eval_direct = eval_direct_dipole_acc1;
			FMMV->eval_direct_periodic = eval_direct_periodic_dipole_acc1;
			break;
		case 2:
			FMMV->eval_direct = eval_direct_dipole_acc2;
			FMMV->eval_direct_periodic = eval_direct_periodic_dipole_acc2;
			break;
		}
		break;
	case FMM_GRAD:
		FMMV->gen_M = gen_M_grad;
		FMMV->eval_L = eval_L_grad;
		FMMV->eval_M = 0;
		FMMV->gen_L = 0;
		FMMV->gen_L_eval_M = gen_L_eval_M_grad;
		FMMV->extrinsic_correction = extrinsic_correction_grad;
		switch(FMMV->directEvalAccuracy) {
		case 0:
			FMMV->eval_direct = eval_direct_grad_acc0;
			FMMV->eval_direct_periodic = eval_direct_periodic_grad_acc0;
			break;
		case 1:
			FMMV->eval_direct = eval_direct_grad_acc1;
			FMMV->eval_direct_periodic = eval_direct_periodic_grad_acc1;
			break;
		case 2:
			FMMV->eval_direct = eval_direct_grad_acc2;
			FMMV->eval_direct_periodic = eval_direct_periodic_grad_acc2;
			break;
		}
		break;
	case FMM_DIPOLE_GRAD:
		FMMV->gen_M = gen_M_dipole_grad;
		FMMV->eval_L = eval_L_dipole_grad;
		FMMV->eval_M = 0;
		FMMV->gen_L = 0;
		FMMV->gen_L_eval_M = gen_L_eval_M_dipole_grad;
		FMMV->extrinsic_correction = extrinsic_correction_dipole_grad;
		switch(FMMV->directEvalAccuracy) {
		case 0:
			FMMV->eval_direct = eval_direct_dipole_grad_acc0;
			FMMV->eval_direct_periodic = eval_direct_periodic_dipole_grad_acc0;
			break;
		case 1:
			FMMV->eval_direct = eval_direct_dipole_grad_acc1;
			FMMV->eval_direct_periodic = eval_direct_periodic_dipole_grad_acc1;
			break;
		case 2:
			FMMV->eval_direct = eval_direct_dipole_grad_acc2;
			FMMV->eval_direct_periodic = eval_direct_periodic_dipole_grad_acc2;
			break;
		}
		break;
	case FMM_ST_STANDARD:
		FMMV->gen_M = gen_M_ST_standard;
		FMMV->eval_L = eval_L_ST_standard;
		FMMV->eval_M = eval_M_ST_standard;
		FMMV->gen_L = gen_L_ST_standard;
		FMMV->gen_L_eval_M = 0;
		FMMV->extrinsic_correction = extrinsic_correction_ST_standard;
		switch(FMMV->directEvalAccuracy) {
		case 0:
			FMMV->eval_direct = eval_direct_ST_standard_acc0;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_standard_acc0;
			break;
		case 1:
			FMMV->eval_direct = eval_direct_ST_standard_acc1;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_standard_acc1;
			break;
		case 2:
			FMMV->eval_direct = eval_direct_ST_standard_acc2;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_standard_acc2;
			break;
		}
		break;
	case FMM_ST_DIPOLE:
		FMMV->gen_M = gen_M_ST_dipole;
		FMMV->eval_L = eval_L_ST_dipole;
		FMMV->eval_M = eval_M_ST_dipole;
		FMMV->gen_L = gen_L_ST_dipole;
		FMMV->gen_L_eval_M = 0;
		FMMV->extrinsic_correction = extrinsic_correction_ST_dipole;
		switch(FMMV->directEvalAccuracy) {
		case 0:
			FMMV->eval_direct = eval_direct_ST_dipole_acc0;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_dipole_acc0;
			break;
		case 1:
			FMMV->eval_direct = eval_direct_ST_dipole_acc1;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_dipole_acc1;
			break;
		case 2:
			FMMV->eval_direct = eval_direct_ST_dipole_acc2;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_dipole_acc2;
			break;
		}
		break;
	case FMM_ST_GRAD:
		FMMV->gen_M = gen_M_ST_grad;
		FMMV->eval_L = eval_L_ST_grad;
		FMMV->eval_M = eval_M_ST_grad;
		FMMV->gen_L = gen_L_ST_grad;
		FMMV->gen_L_eval_M = 0;
		FMMV->extrinsic_correction = extrinsic_correction_ST_grad;
		switch(FMMV->directEvalAccuracy) {
		case 0:
			FMMV->eval_direct = eval_direct_ST_grad_acc0;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_grad_acc0;
			break;
		case 1:
			FMMV->eval_direct = eval_direct_ST_grad_acc1;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_grad_acc1;
			break;
		case 2:
			FMMV->eval_direct = eval_direct_ST_grad_acc2;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_grad_acc2;
			break;
		}
		break;
	case FMM_ST_DIPOLE_GRAD:
		FMMV->gen_M = gen_M_ST_dipole_grad;
		FMMV->eval_L = eval_L_ST_dipole_grad;
		FMMV->eval_M = eval_M_ST_dipole_grad;
		FMMV->gen_L = gen_L_ST_dipole_grad;
		FMMV->gen_L_eval_M = 0;
		FMMV->extrinsic_correction = extrinsic_correction_ST_dipole_grad;
		switch(FMMV->directEvalAccuracy) {
		case 0:
			FMMV->eval_direct = eval_direct_ST_dipole_grad_acc0;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_dipole_grad_acc0;
			break;
		case 1:
			FMMV->eval_direct = eval_direct_ST_dipole_grad_acc1;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_dipole_grad_acc1;
			break;
		case 2:
			FMMV->eval_direct = eval_direct_ST_dipole_grad_acc2;
			FMMV->eval_direct_periodic = eval_direct_periodic_ST_dipole_grad_acc2;
			break;
		}
		break;
	}

	*fh = (void*) FMMV;
	*errorMessage = 0;
_err:
	*errorMessage = err;
}

void
#if (FMM_PRECISION==0)
fmmv2df_evaluate
#elif (FMM_PRECISION==1)
fmmv2d_evaluate
#endif
(	void* fh,
	_FLOAT_ charges[],
	_FLOAT_ dipoleMoments[][2],
	_FLOAT_ potentials[],
	_FLOAT_ gradients[][2],
	struct FmmvStatistics *statistics, /* can be NULL */
	char **errorMessage)
{
	char *err;
	FmmvHandle* FMMV = (FmmvHandle*) fh;

	FMMV->dipoleMoments = dipoleMoments;
	FMMV->charges = charges;
	FMMV->potentials = potentials;
	FMMV->gradients = gradients;

	err = fmmv_evaluate(FMMV, statistics);
	if (err) goto _err;

	*errorMessage = 0;
_err:
	*errorMessage = err;
}

void
#if (FMM_PRECISION==0)
fmmv2df_finalize
#elif (FMM_PRECISION==1)
fmmv2d_finalize
#endif
(	void* fh,
	struct FmmvStatistics *statistics, /* can be NULL */
	char **errorMessage)
{
	FmmvHandle* FMMV = (FmmvHandle*) fh;
	char *err;

	err = fmmv_finalize(FMMV, statistics);
	if (err) goto _err;

	*errorMessage = 0;
_err:
	*errorMessage = err;
}

void
#if (FMM_PRECISION==0)
fmmv2df_direct
#elif (FMM_PRECISION==1)
fmmv2d_direct
#endif
(	unsigned int NParticles, 
	_FLOAT_ particles[][2],
	_FLOAT_ charges[],
	_FLOAT_ dipoleMoments[][2],
	unsigned int NTargets, 
	_FLOAT_ targets[][2],
	_FLOAT_ potentials[],
	_FLOAT_ gradients[][2],
	int accuracy,
	double beta,
	double *time,
	char **errorMessage)
{

	FmmvHandle _FMMV;
	FmmvHandle *FMMV = &_FMMV;
	Box _box;
	Box *box = &_box;
	int i;
	int err;
	int typeSources = 0;
	int typeTargets = 0;
        
	if (accuracy<0) {
		direct_method_xp(NParticles, particles,
		charges,
		dipoleMoments,
		NTargets, targets,
		potentials,
		gradients,
		beta,
		time, errorMessage);
		return;
	}

        FMMV->NParticles = NParticles;
        FMMV->particles = particles;
	FMMV->targets = targets;
	if (targets||((!targets)&&(NTargets>0)&&(NTargets<=NParticles))) {	
		FMMV->NTargets = NTargets;
	}
	else {
		FMMV->NTargets = NParticles;
	}	
	FMMV->directEvalAccuracy = accuracy;
	
	FMMV->dipoleMoments = dipoleMoments;
	FMMV->charges = charges;
	FMMV->potentials = potentials;
	FMMV->gradients = gradients;

	if (dipoleMoments) {
		typeSources |= DIPOLEMOMENTS;
	}
	if (charges) {
		typeSources |= CHARGES;
	}

	if (potentials) {
		typeTargets |= POTENTIALS;
	}
	if (gradients) {
		typeTargets |= GRADIENTS;
	}

	if (FMMV->targets) {
		if( (typeSources&CHARGES) && (typeSources&DIPOLEMOMENTS) && (typeTargets&POTENTIALS) && (typeTargets&GRADIENTS) && 1) {
			FMMV->dataKind = FMM_ST_DIPOLE_GRAD;
		}
		else if( (typeSources&CHARGES) && (typeTargets&POTENTIALS) && (typeTargets&GRADIENTS) && 1) {
			FMMV->dataKind = FMM_ST_GRAD;
		}
		else if( (typeSources&CHARGES) && (typeSources&DIPOLEMOMENTS) && (typeTargets&POTENTIALS) && 1) {
			FMMV->dataKind = FMM_ST_DIPOLE;
		}
		else if( (typeSources&CHARGES) && (typeTargets&POTENTIALS) && 1) {
			FMMV->dataKind = FMM_ST_STANDARD;
		}
		else {
			assert(0);
		}
	}
	else{
		if( (typeSources&CHARGES) && (typeSources&DIPOLEMOMENTS) && (typeTargets&POTENTIALS) && (typeTargets&GRADIENTS) && 1) {
			FMMV->dataKind = FMM_DIPOLE_GRAD;
		}
		else if( (typeSources&CHARGES) && (typeTargets&POTENTIALS) && (typeTargets&GRADIENTS) && 1) {
			FMMV->dataKind = FMM_GRAD;
		}
		else if( (typeSources&CHARGES) && (typeSources&DIPOLEMOMENTS) && (typeTargets&POTENTIALS) && 1) {
			FMMV->dataKind = FMM_DIPOLE;
		}
		else if( (typeSources&CHARGES) && (typeTargets&POTENTIALS) && 1) {
			FMMV->dataKind = FMM_STANDARD;
		}
		else {
			assert(0);
		}
	}


	FMMV->perm = (int *) malloc(NParticles*sizeof(int));
	if (FMMV->perm==0) goto _err;
	
	for (i=0; i<FMMV->NParticles; i++) {
       		FMMV->perm[i] = i;
	}
	if (targets) {
                FMMV->permTargets = (int *) malloc(NTargets*sizeof(int));
                if (FMMV->permTargets==0) goto _err;
		for (i=0; i<FMMV->NTargets; i++) {
        		FMMV->permTargets[i] = i;
		}
	}
	else  {
              	FMMV->permTargets = FMMV->perm;
	}

        err = ida_allocate(FMMV);
        if (err) goto _err;

        copy_particles(FMMV);
        copy_charges(FMMV);
        zero_pot(FMMV);
	
	box->firstParticle = 0;
	box->noOfParticles = FMMV->NParticles;
	box->firstTarget = 0;
	box->noOfTargets = FMMV->NTargets;
	
	FMMV->beta = beta;
	switch(FMMV->dataKind) {
	case FMM_STANDARD:
		switch(FMMV->directEvalAccuracy) {
		case 0:
			eval_direct_standard_acc0(FMMV, box, box);
			break;
		case 1:
			eval_direct_standard_acc1(FMMV, box, box);
			break;
		case 2:
			eval_direct_standard_acc2(FMMV, box, box);
			break;
		}
		break;
	case FMM_DIPOLE:
		switch(FMMV->directEvalAccuracy) {
		case 0:
			eval_direct_dipole_acc0(FMMV, box, box);
			break;
		case 1:
			eval_direct_dipole_acc1(FMMV, box, box);
			break;
		case 2:
			eval_direct_dipole_acc2(FMMV, box, box);
			break;
		}
		break;
	case FMM_GRAD:
		switch(FMMV->directEvalAccuracy) {
		case 0:
			eval_direct_grad_acc0(FMMV, box, box);
			break;
		case 1:
			eval_direct_grad_acc1(FMMV, box, box);
			break;
		case 2:
			eval_direct_grad_acc2(FMMV, box, box);
			break;
		}
		break;
	case FMM_DIPOLE_GRAD:
		switch(FMMV->directEvalAccuracy) {
		case 0:
			eval_direct_dipole_grad_acc0(FMMV, box, box);
			break;
		case 1:
			eval_direct_dipole_grad_acc1(FMMV, box, box);
			break;
		case 2:
			eval_direct_dipole_grad_acc2(FMMV, box, box);
			break;
		}
		break;
	case FMM_ST_STANDARD:
		switch(FMMV->directEvalAccuracy) {
		case 0:
			eval_direct_ST_standard_acc0(FMMV, box, box);
			break;
		case 1:
			eval_direct_ST_standard_acc1(FMMV, box, box);
			break;
		case 2:
			eval_direct_ST_standard_acc2(FMMV, box, box);
			break;
		}
		break;
	case FMM_ST_DIPOLE:
		switch(FMMV->directEvalAccuracy) {
		case 0:
			eval_direct_ST_dipole_acc0(FMMV, box, box);
			break;
		case 1:
			eval_direct_ST_dipole_acc1(FMMV, box, box);
			break;
		case 2:
			eval_direct_ST_dipole_acc2(FMMV, box, box);
			break;
		}
		break;
	case FMM_ST_GRAD:
		switch(FMMV->directEvalAccuracy) {
		case 0:
			eval_direct_ST_grad_acc0(FMMV, box, box);
			break;
		case 1:
			eval_direct_ST_grad_acc1(FMMV, box, box);
			break;
		case 2:
			eval_direct_ST_grad_acc2(FMMV, box, box);
			break;
		}
		break;
	case FMM_ST_DIPOLE_GRAD:
		switch(FMMV->directEvalAccuracy) {
		case 0:
			eval_direct_ST_dipole_grad_acc0(FMMV, box, box);
			break;
		case 1:
			eval_direct_ST_dipole_grad_acc1(FMMV, box, box);
			break;
		case 2:
			eval_direct_ST_dipole_grad_acc2(FMMV, box, box);
			break;
		}
		break;
	}

	backcopy_pot(FMMV);
	ida_free(FMMV);

	*errorMessage = 0;
_err:
	*errorMessage = err;
}
