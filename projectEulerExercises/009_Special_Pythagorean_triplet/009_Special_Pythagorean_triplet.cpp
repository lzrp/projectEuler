// 009_Special_Pythagorean_triplet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include <iostream>

using namespace std;

// completed 19/12/2015

void PrintSpecialPythTriplet()
{
	int a = 0, b = 0, c = 0;
	int sum = (a + b + c);


	for (size_t i = 2; sum != 1000; ++i)
	{
		for (size_t j = 1; j < i; ++j)
		{
			a = (i*i) - (j*j);
			b = 2 * i * j;
			c = (i*i) + (j*j);
			sum = (a + b + c);

			if (sum == 1000)
			{
				cout << "Triplet found: a = " << a << " b = " << b << " c = " << c << " with sum: (a+b+c) = " << (a + b + c) << endl;
				cout << "Its product is: a*b*c = " << a*b*c << endl;
				break;
			}
		}
	}
}


int main()
{
	PrintSpecialPythTriplet();

    return 0;
}

