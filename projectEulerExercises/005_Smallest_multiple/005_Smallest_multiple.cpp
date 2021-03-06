// 005_Smallest_multiple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <time.h>    
#include <iomanip>  
#include "Timer.h"

// Completed 14/12/2015

bool IsDivisible(long long dividend, int divisor)
{
	return !(dividend % divisor);
}

void FunctionWrapper()
{
    std::cout << "Smallest positive number that is evenly divisible by all numbers from 1 to 20: " << std::endl;

    bool isFound = false;
    int i = 20;
    int smallestMultiple = 0;

    while (!isFound)
    {
        bool isEvenlyDivisible = false;

        for (size_t j = 11; j <= 20; j++)
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
            break;
        }

        i += 20;
        isFound = isEvenlyDivisible;
    }

    std::cout << smallestMultiple << std::endl;
}

int main()
{
	clock_t clockBegin, clockEnd;
	clockBegin = clock();

	std::cout << "Smallest positive number that is evenly divisible by all numbers from 1 to 20: " << std::endl;

	bool isFound = false;
	int i = 20;
	int smallestMultiple = 0;

	while (!isFound)
	{
		bool isEvenlyDivisible = false;

		for (size_t j = 11; j <= 20; j++)
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
			break;
		}

		i += 20;
		isFound = isEvenlyDivisible;
	}

	std::cout << smallestMultiple << std::endl;

	clockEnd = clock();

	
	std::cout << "total seconds elapsed: " << std::setprecision(4) << double(clockEnd - clockBegin) / CLOCKS_PER_SEC << std::endl;


    std::cout << "TimerClockLib test: " << std::endl;
    Timer::PrintFunctionRunningTime(&FunctionWrapper);

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
