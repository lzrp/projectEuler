// 003_Largest_prime_factor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

//Completed 13/12/2015

list<int> GetPrimeNumbers(int upperLimit)
{
	int a = 2;
	list<int> primeNumbers;

	for (int i = a; i <= upperLimit; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			if (!(i%j) && (i != j)) 
			{
				break;
			}

			if (j == i) 
			{
				primeNumbers.insert(primeNumbers.end(), i);
			}
		}
	}

	return primeNumbers;
}

list<int> GetPrimeFactors(long long number)
{
	list<int> primeFactors;
	list<int> primeNumbers = GetPrimeNumbers(2000);

	for (list<int>::iterator iterator = primeNumbers.begin(); iterator != primeNumbers.end(); ++iterator)
	{
		while (number % *iterator == 0 && number >= *iterator)
		{
			number = number / *iterator;
			primeFactors.push_back(*iterator);
		}
	}

	primeFactors.push_back(number);

	return primeFactors;
}

int main()
{
	cout << "Type a number for which you want to find its prime factors." << endl;

	long long number;
	std::cin >> number;

	list<int> primeFactorsList = GetPrimeFactors(number);

	std::cout << "The prime factors for the number: " << number << " are:" << endl;
	for (list<int>::const_iterator i = primeFactorsList.begin(); i != primeFactorsList.end(); ++i)
	{
		cout << *i << " ";
	}

	cout << endl;

    return 0;
}



