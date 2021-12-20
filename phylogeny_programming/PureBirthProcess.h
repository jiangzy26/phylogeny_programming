#ifndef PureBirthProcess_h
#define PureBirthProcess_h

#include "RandomNumberGenerator.h"

#include <stdio.h>
#include <vector>

class Tree;

class PureBirthProcess{
public:
	PureBirthProcess(const double *b);
	virtual     ~PureBirthProcess();

	double                          lnProbability(void) const;
	Tree *                           rv(RandomNumberGenerator * rng, double age);
	void                              setValue(const Tree *x);

protected:
	const double *               birth_rate;
	const Tree *                   value;

};




#endif

