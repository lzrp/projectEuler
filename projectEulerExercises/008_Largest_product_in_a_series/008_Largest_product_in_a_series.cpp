// 008_Largest_product_in_a_series.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vector"
#include "iostream"
#include <string>

using namespace std;

// completed 19/12/2015

vector<string> ReturnSubStringsWithoutZero(string inputString)
{
	vector<string> subStringsVector;
	string subString = "";

	int i = 0;

	for (char & character : inputString)
	{
		if (character != '0')
		{
			subString += character;
		}

		else
		{
			subStringsVector.push_back(subString);
			subString = "";
			i++;
		}
	}

	return subStringsVector;
}

string GetSampleInput()
{
	string sampleInput = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	return sampleInput;
}

unsigned long long ComputeGreatestProduct(string inputString)
{
	unsigned long long product = 1;

	for(char & character : inputString)
	{
		product *= character - '0';
	}

	return product;
}

void PrintAdjacentNumbersGreatestProduct(vector<string> inputStringsVector, int adjacentNumbersLimit)
{
	unsigned long long maxProduct = 0;

	for (string & subString : inputStringsVector)
	{
		for (size_t i = 0; i + adjacentNumbersLimit <= subString.length(); ++i)
		{
			string adjacentNumbersString = subString.substr(i, adjacentNumbersLimit);

			unsigned long long product = ComputeGreatestProduct(adjacentNumbersString);

			if (product > maxProduct)
			{
				maxProduct = product;

				cout << "The new greatest product belongs to the adjacent numbers: " << adjacentNumbersString << " and its value is: " << maxProduct << endl;
			}
		}
	}	
}

vector<string> GetSubStringByAdjacentNumbersLimit(vector<string> inputStringsVector, int adjacentNumbersLimit)
{
	vector<string> adjacentNumbersStringVector;

	for (string & subString : inputStringsVector)
	{
		if (subString.length() >= adjacentNumbersLimit)
		{
			adjacentNumbersStringVector.push_back(subString);
		}
	}

	return adjacentNumbersStringVector;
}

int main()
{ 
	string sampleInput = GetSampleInput();

	vector<string> subStringsWithoutZero = ReturnSubStringsWithoutZero(sampleInput);

	vector<string> adjacentNumbersStringVector = GetSubStringByAdjacentNumbersLimit(subStringsWithoutZero, 13);

	int i = 1;

	for(string & subString : adjacentNumbersStringVector)
	{
		cout << i << ". substr is: " << subString << endl;
		++i;
	}

	PrintAdjacentNumbersGreatestProduct(adjacentNumbersStringVector, 13);

    return 0;
}

