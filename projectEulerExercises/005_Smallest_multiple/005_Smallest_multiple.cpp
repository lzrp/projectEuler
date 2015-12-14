// 005_Smallest_multiple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>

// Completed 14/12/2015

bool IsDivisible(long long dividend, int divisor)
{
	return !(dividend % divisor);
}

int main()
{
	std::cout << "Smallest positive number that is evenly divisible by all numbers from 1 to 20: " << std::endl;

	bool isFound = false;
	int i = 10;
	int smallestMultiple = 0;

	while (!isFound)
	{
		bool isEvenlyDivisible = false;

		for (size_t j = 1; j <= 20; j++)
		{
			if (!IsDivisible(i, j))
			{
				isEvenlyDivisible = false;
				break;
			}

			isEvenlyDivisible = true;
		}

		if (isEvenlyDivisible)
		{
			smallestMultiple = i;
		}

		i += 10;
		isFound = isEvenlyDivisible;
	}

	std::cout << smallestMultiple << std::endl;

    return 0;
}

// TODO implement original p.euler algorithm
//k = 20
//N = 1
//i = 1
//check = true
//limit = sqrt(k)
//while p[i] <= k
//a[i] = 1
//if check then
//if p[i] <= limit then
//a[i] = floor(log(k) / log(p[i]))
//else
//check = false
//end if
//end if
//N = N * p[i] ^ a[i]
//i = i + 1
//end while
//output N