// 004_Largest_palindrome_product.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

bool IsPalindrome(unsigned long number)
{
	bool result = false;
	std::string numberString = std::to_string(number);
	int stringLength = numberString.length();

	for (size_t i = 0; i <= stringLength/2; i++)
	{
		if (numberString[i] != numberString[stringLength - i - 1])
		{
			return false;
		}

		result = true;
	}

	return result;
}

void GetLargestPalindrome()
{
	int maxPalindrome = 0;

	for (size_t i = 999; i >= 100; i--)
	{	
		for (size_t j = 999; j >= 100; j--)
		{
			long number = i * j;

			if (IsPalindrome(number) && number > maxPalindrome)
			{
				std::cout << i << " * " << j << " = " << number << std::endl;
				maxPalindrome = number;
			}
		}
	}
}

int main()
{	
	std::cout << "Largest palindrome made from two 3-digit numbers:" << std::endl;

	GetLargestPalindrome();

    return 0;
}

