// e001_Multiples_of_3_and_5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;


// Completed 04/11/2015

int main()
{
	auto sum = 0, maxValue = 1000;

	for (auto i = 0; i < maxValue; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	cout << "The sum of all natural numbers that are multiples of 3 and 5 below " << maxValue << " is:" << sum << endl;

    return 0;
}

