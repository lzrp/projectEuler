// 012_Highly_divisible_triangular_number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "Timer.h"
#include "vector"

using std::cout;
using std::endl;


std::vector<unsigned long long> GetTriangleNumbers(int limit)
{ 
    unsigned long long triangleNumber = 1;
    std::vector<unsigned long long> triangleNumbersVector;

    for (size_t i = 2; i < limit+2; i++)
    {
        triangleNumbersVector.push_back(triangleNumber);
        triangleNumber += i;
    }

    return triangleNumbersVector;
}

int GetNumberOfDivisors(unsigned long long number)
{
    int numberOfDivisors = 0;

    for (auto i = number/2 ; i > 1; i--)
    {
        if (number % i == 0)
        {
            numberOfDivisors++;
        }
    }

    return ++numberOfDivisors;
}

void PrintNumberOfDivisorsOfTriangleNumberList(std::vector<unsigned long long> triangleNumbersVector)
{
    for (auto number : triangleNumbersVector)
    {
        cout << "Numbers " << number << " number of divisors is: " << GetNumberOfDivisors(number) << endl;
    }
}


unsigned long long GetTriangleNumberByNumberOfDivisors(std::vector<unsigned long long> triangleNumbersVector, int requiredMinimumNumberOfDivisors)
{
    
    for(auto number : triangleNumbersVector)
    {
        int product = 0;
        int expA = 0, expB = 0, expC = 0, expD = 0;

        while (number != 1)
        {
            if (number % 2 == 0)
            {
                number /= 2;
                expA++;
                continue;
            }

            if (number % 3 == 0)
            {
                number /= 3;
                expB++;
                continue;
            }

            if (number % 5 == 0)
            {
                number /= 5;
                expC++;
                continue;
            }

            else
            {
                for (size_t i = 7; i < number; i+=2)
                {
                    if (number % i == 0)
                    {
                        number /= i;
                        expD++;
                    }
                }
            }
        }

        product = ((expA + 1) * (expB + 1) * (expC + 1) * (expD + 1));

        if (product > requiredMinimumNumberOfDivisors)
        {
            cout << "Number " << number << " has " << product << " divisors." << endl;
            return number;
        }
    }

    cout << "nothing found using this limit: " << requiredMinimumNumberOfDivisors << endl;
    return 0;
}

void FunctionWrapper()
{
    GetTriangleNumberByNumberOfDivisors(GetTriangleNumbers(100000) ,500);
}

int main()
{
    Timer::PrintFunctionRunningTime(&FunctionWrapper);

    return 0;
}

