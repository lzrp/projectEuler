// 006_Sum_square_difference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <iomanip>

// Completed 15/12/2015

void BruteForceMethod(int limit)
{
	clock_t clockBegin, clockEnd;
	clockBegin = clock();

	unsigned long long sumOfSquares = 0, squareOfSum = 0;

	for (size_t i = 1; i <= limit; i++)
	{
		sumOfSquares += i*i;
		squareOfSum += i;
	}

	squareOfSum *= squareOfSum;

	std::cout << "Brute force method output:" << std::endl;
	std::cout << "The sum of squares is:" << sumOfSquares << ". Square of the sum is: " << squareOfSum << std::endl;
	std::cout << "The difference is: " << squareOfSum - sumOfSquares << std::endl;

	clockEnd = clock();

	std::cout << "total seconds elapsed: " << std::setprecision(4) << double(clockEnd - clockBegin) / CLOCKS_PER_SEC << std::endl;
}

void OptimalMethod(long limit)
{
	clock_t clockBegin, clockEnd;
	clockBegin = clock();
	
	unsigned long long sum = limit * (limit + 1) / 2;
	unsigned long long sum_sq = (limit * (limit + 1) * (2 * limit + 1)) / 6;

	std::cout << "Mathematical algorithm method output:" << std::endl;
	std::cout << "The sum of squares is:" << sum_sq << ". Square of the sum is: " << sum*sum << std::endl;
	std::cout << "The difference is: " << sum*sum - sum_sq << std::endl;

	clockEnd = clock();

	std::cout << "total seconds elapsed: " << std::setprecision(4) << double(clockEnd - clockBegin) / CLOCKS_PER_SEC << std::endl;
}

int main()
{
	int limit = 1000; // not working properly when limit > 1000

	BruteForceMethod(limit);
	std::cout << std::endl;
	OptimalMethod(limit);

    return 0;
}

