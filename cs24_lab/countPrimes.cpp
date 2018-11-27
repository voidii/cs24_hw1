#include "arrayFuncs.h"
#include <cstdlib>
#include <iostream>

#include "utility.h"

int countPrimes(int a[], int size) {
	int primeNum;
	for (int i = 0; i < size; i++)
	{
		if (isPrime(a[i]) == true)	
       		{
			primeNum++;
		}
	}
	return primeNum; // STUB!  Replace with correct code.
}
