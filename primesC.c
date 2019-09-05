#ifndef __cplusplus
typedef unsigned char bool;
static const bool False = 0;
static const bool True = 1;
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long getNumberOfPrimes(long n, bool* could_be_primes)
{
	long numberOfPrimes = 0, i = 0;
	for (long i = 2; i < n; i++)
		could_be_primes[i] = 1;
	could_be_primes[0] = 0;
	could_be_primes[1] = 0;

	for (long i=2; i<(long)sqrt((double)n); i++)
    {
        if (could_be_primes[i]!=0)
        {
			numberOfPrimes++;
            for (long j=i*i; j<n; j=j+i)
            {
                could_be_primes[j]=0;
            }
        }
    }

	for (; i < n; i++)
		if (could_be_primes[i])
			numberOfPrimes++;
	return numberOfPrimes;
}

int main()
{
	long n = 100000000, numberOfPrimes = 0, br = 0;
	bool* allNumbersToN = malloc(sizeof(bool) * n);
	numberOfPrimes = getNumberOfPrimes(n, allNumbersToN);
	long* primes = malloc(sizeof(long) * numberOfPrimes);

	for (int i = 2; i < n; i++)
		if (allNumbersToN[i])
		{
			primes[br] = i;
			br++;
		}
	/*
	do something;
	*/
	free(allNumbersToN);
	free(primes);
	return 0;
}

	
/*for (long i = 0; i < n; i++)
		if (primes[i])
			printf("\n%ld", i);*/