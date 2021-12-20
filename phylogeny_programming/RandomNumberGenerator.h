#ifndef RandomNumberGererator_h
#define RandomNumberGererator_h

#include <stdio.h>

class RandomNumberGenerator
{
	public:
		RandomNumberGenerator(void);
		RandomNumberGenerator(int x);

		double                                           uniform01(void);
	private:
		int                                                  seed;
};

#endif
