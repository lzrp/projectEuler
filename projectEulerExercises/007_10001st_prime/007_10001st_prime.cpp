// 007_10001st_prime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>

// Completed 15/12/2015

bool IsPrime(unsigned long number)
{
	if (number == 1)
	{
		return false;
	}
	if (number < 4)
	{
		return true;
	}
	if (number % 2 == 0)
	{
		return false;
	}			
	if (number < 9)
	{
		return true;
	}
	if (number % 3 == 0)
	{
		return false;
	}
					
	int roundedNumber = floor(sqrt(number));
	int factor = 5;

	while (factor <= roundedNumber)
	{
		if (number % factor == 0)
		{
			return false;
		}

		if (number % (factor + 2) == 0)
		{
			return false;
		}

		factor += 6;
	}
	return true;
}

long GeneratePrimeNumberMySolution()
{
	int i = 2, k = 0;

	while (true)
	{
		for (size_t j = 2; j <= i; j++)
		{
			if (!(i%j) && (i != j))
			{
				break;
			}

			if (j == i)
			{
				k++;

				if (k == 10001)
				{
					return j;
				}				
			}
		}

		++i;
	}
}
long GeneratePrimeNumberPEulerSolution()
{
	int limit = 10001;
	int primesCount = 1;
	unsigned long primeCandidate = 1;

	while (primesCount != limit)
	{
		primeCandidate += 2;
		if (IsPrime(primeCandidate))
		{
			primesCount++;
		}
	}

	return primeCandidate;
}

int main()
{

	clock_t clockBegin, clockEnd;
	clockBegin = clock();

	long prime = GeneratePrimeNumberMySolution();

	std::cout << "My function output: " << std::endl;
	std::cout << "The 10001st prime is: " << prime << std::endl;

	clockEnd = clock();

	std::cout << "total seconds elapsed: " << std::setprecision(4) << double(clockEnd - clockBegin) / CLOCKS_PER_SEC << std::endl;

	std::cout << std::endl;
	
	clockBegin = clock();

	prime = GeneratePrimeNumberPEulerSolution();

	std::cout << "Project Euler function output: " << std::endl;
	std::cout << "The 10001st prime is: " << prime << std::endl;

	clockEnd = clock();

	std::cout << "total seconds elapsed: " << std::setprecision(4) << double(clockEnd - clockBegin) / CLOCKS_PER_SEC << std::endl;

    return 0;
}

