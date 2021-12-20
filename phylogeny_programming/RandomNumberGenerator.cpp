#include "RandomNumberGenerator.h"
#include <ctime>     //needed for time()

/*
learn from https://hoehnalab.github.io/courses_baby_bayes/chapter4/
*/

RandomNumberGenerator::RandomNumberGenerator(void)
{
	seed = (int)(time(0));
}

RandomNumberGenerator::RandomNumberGenerator(int x)
{
	seed = x;
}


double  RandomNumberGenerator::uniform01(void)
{
	int hi = seed / 127773;
	int lo = seed % 12773;
	int test = 16807 * lo - 2836 * hi;

	if (test > 0)
		seed = test;
	else
		seed = test + 2147483647;

		return (double)(seed) / (double)2147483647;
}
