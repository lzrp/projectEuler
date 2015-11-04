// 002_Even_Fibonacci_numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

//Completed 04/11/2015

int main()
{
	auto upperLimit = 4000000;
	int a = 0, b = 1,c, sum = 0;

	cout << "Fibonacci numbers whose values do not exceed four million: " << endl;

	while (b < upperLimit )
	{
		a += b;

		c = b;
		b = a;		
		a = c;

		if (b % 2 == 0)
		{
			sum += b;
		}
	}

	cout << "The sum of even fibonacci numbers under 4M is: " << sum << endl;

    return 0;
}
