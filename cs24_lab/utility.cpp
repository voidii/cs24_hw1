#include"math.h"

// utility.cpp

// IN THIS FILE, define any of your OWN functions you may need to 
// solve the problems.    

// For example, if you need an isPrime function, you can put the function
// definition in this file.  Similarly, isOdd or isEven might be useful.

// You will need to include the function prototype in "utility.h" and
// then be sure to  #include "utility.h" in the file where you use
// these functions

bool isOdd(int x) { 
 	if (x%2 == 0)
       		return false;
      	else 
		return true;	// REPLACE THIS STUB WITH REAL CODE
}
bool isEven(int x) { 
	if (x%2 != 0)
 		return false; 
	else 
		return true;	// REPLACE THIS STUB WITH REAL CODE
}
bool isPrime(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i <= (int) sqrt((double) x); i++)
		if (x % i == 0)
			return false;

  return true;  // REPLACE THIS STUB WITH REAL CODE
}
