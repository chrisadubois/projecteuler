// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int SumOfMultiplesOf3Or5(int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 3 == 0)
		{
			sum += i;
		}
		else if (i % 5 == 0)
		{
			sum += i;
		}
		else
		{
			continue;
		}
	}
	return sum;
}

long SumOfFibonacciSequenceEvenNumbers()
{
	int n1 = 1; int n2 = 0; int ret = 0;
	int max = 4000000;
	do
	{
		n2 = n1 + n2;//calculate the fibonacci number in the sequence
		n1 = n2 - n1;//update the last one
		if (n2 % 2 == 0)//if it's even
		{
			ret += n2;
		}
	} while (n2 <= max);//do all this while the fib number is less than a particular number
	return ret;
}

long long int findLargestPrimeFactor(long long int n)//does not work for perfect squares
{
	long long int i = 2;
	while (i * i <= n)
	{
		while (n % i == 0)
		{
			n = n / i;
		}
		i++;
	}
	return n;
}

void findAllPrimeFactors(long long int n, long long int i, vector<long long int>& a)
{
	if (n < 2)
	{
		return;
	}
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			a.push_back(i);
			n = n / i;
		}
	}
	//recursive solution below
	/*if (n % i == 0)
	{
		a.push_back(i);
		findAllPrimeFactors(n / i, i, a);
	}
	if (n % i != 0)
	{
		i++;
		findAllPrimeFactors(n, i, a);
	}*/
}

vector<bool> SieveOfErasthothenes(int n)
{
	vector<bool> PrimeArr = vector<bool>(n + 1, true);
	int j = 0;
	for (int i = 2; i <= n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (j % i == 0)
			{
				PrimeArr[j] = false;
			}
		}
	}
	//if PrimeArr[i] == true, then i is the VALUE which is prime.
	return PrimeArr;
}

bool isPrime(long long int n)
{
	if (n < 2)
	{
		return false;
	}
	if (n % 2 == 0)
	{
		return false;
	}
	if (n == 2)
	{
		return true;
	}
	if (n == 3)
	{
		return true;
	}
	if (n % 3 == 0)
	{
		return false;
	}
	if (n == 5)
	{
		return true;
	}
	if (n % 5 == 0)
	{
		return false;
	}
	if (n == 7)
	{
		return true;
	}
	if (n % 7 == 0)
	{
		return false;
	}
	for (long long int i = 11; i <= sqrt(n) + 1; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

long long int sumPrimes(long long int n)
{
	long long int sum = 2;
	for (int i = 3; i < n; i++)
	{
		if (isPrime(i)) sum = sum + i;
	}
	return sum;
}

int tenthousandfirstprime()
{
	int primeN = 10001;
	int counter = 1;
	int primecheck = 0;
	while (counter < primeN)
	{
		primecheck++;
		if (isPrime(primecheck))
		{
			counter++;
		}
	}
	return primecheck;
}

int diffSquareStuff(int n)
{
	int sumofsquares = 0;
	int squareofsum = 0;
	for (int i = 1; i <= n; i++)
	{
		sumofsquares += i * i;
		squareofsum += i;
	}
	squareofsum = squareofsum * squareofsum;
	if (sumofsquares - squareofsum < 1)
	{
		return -(sumofsquares - squareofsum);
	}
	else
	{
		return (sumofsquares - squareofsum);
	}
}

int smallestMultiple(int range)
{
	return 0;
}

int specialPythagoreanTriplet()
{
	int a = 1;
	int b = 1;
	int c = 1;
	bool done = false;
	while (!done)
	{
		while (a + b + c != 1000)
		{

		}
	}
	int rV = a*b*c;
	return rV;
}

bool isPali(string pali)
{
	if (pali.length() == 1 || pali.length() == 0)
	{
		return true;
	}
	return pali.at(pali.length() - 1) == pali.at(0)
		&& isPali(pali.substr(pali.length() - 1));
}

bool areAnagrams(string& one, string& two)
{
	vector<int> storingOne(255);
	vector<int> storingTwo(255);
	for (int k = 0; k < one.length(); k++)
	{
		char ascii = one.at(k);
		storingOne.at((int)ascii) += 1;
	}
	for (int m = 0; m < two.length(); m++)
	{
		char ascii = two.at(m);
		storingTwo.at((int)ascii) += 1;
	}
	bool anagram = false;
	for (int i = 0; i < 255; i++)
	{
		if (storingOne.at(i) != storingTwo.at(i))
		{
			anagram = false;
			break;
		}
		else
		{
			anagram = true;
			continue;
		}
	}
	return anagram;
}

int mod(int toMod, int modBy)
{
	int temp = toMod / modBy;//113 / 11 = 10.797 floor = 10;
	temp = temp * modBy;// temp = 10 * 11 = 110;
	return toMod - temp;//113 - 110 = 3 which is 113 % 11;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int c;
	cout << SumOfMultiplesOf3Or5(1000) << endl;
	cout << SumOfFibonacciSequenceEvenNumbers() << endl;
	long long int pass = 600851475143;
	cout << findLargestPrimeFactor(pass) << endl;
	vector<bool> si = SieveOfErasthothenes(30);
	for (int i = 2; i < si.size(); i++)
	{
		if (si.at(i) == true)
		{
			cout << i << ",";
		}
	}
	cout << endl;
	vector<long long int> d;
	findAllPrimeFactors(pass, 2, d);
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << ",";
	}
	cout << endl;
	cout << sumPrimes(2000000) << endl;
	cout << tenthousandfirstprime() << endl;
	cout << diffSquareStuff(100) << endl;
	cout << endl;
	string one = "iceman";
	string two = "cinema";
	cout << areAnagrams(one, two) << " should print 1\n";
	string three = "person";
	string four = "notaperson";
	cout << areAnagrams(three, four) << " should print 0\n";
	cout << endl;
	cout << mod(113, 11);
	cout << endl;
	for (int i = 0; i < 1000; i++)
	{
		if (isPrime(i)) cout << i << ",";
	}
	cin >> c;
	return 0;
}

