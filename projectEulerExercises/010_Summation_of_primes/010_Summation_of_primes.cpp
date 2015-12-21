// 010_Summation_of_primes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <string>
#include <iostream>
#include <bitset>

using namespace std;

// completed 20/12/2015

bitset<2000000> GetPrimeNumbersSieveEratosthenes()
{
	unsigned long const upperLimit = 2000000;
	bitset<2000000> numbersBitSet = bitset<2000000>().set();
	numbersBitSet.set(0, false);
	numbersBitSet.set(1, false);
	numbersBitSet.set(2, true);

	for (size_t i = 2; i * i < upperLimit; i++)
	{
		if (numbersBitSet[i])
		{
			for (size_t j = i * i; j < upperLimit; j += i)
			{
				numbersBitSet.reset(j);
			}
		}
	}

	return numbersBitSet;
}

int main()
{
	const bitset<2000000> primeNumbers = GetPrimeNumbersSieveEratosthenes();

	unsigned long long sum = 0;

	for (size_t i = 0; i < primeNumbers.size(); ++i)
	{
		if (primeNumbers.test(i))
		{
			sum += i;
		}
	}

	cout << "The sum of all primes below two million is: " << sum << endl;

    return 0;
}

