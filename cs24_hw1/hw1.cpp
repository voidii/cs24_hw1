// cs24_hw1.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<ctime>

using namespace std;

void f(double n)
{
	double diff;
	double x = 0;
	int sum = 0;
	while (x < 1)
	{
		clock_t begin = clock();
		for (double i = 1; i < n; i *= 2)
			for (double j = 1; j <= i; j *= 2)
				++sum;
		clock_t end = clock();
		double diff = double(end - begin);
		x = x + diff;
	}
	//cout << sum << endl;
	cout << sum << endl;
	cout << x << endl;
}

int main()
{
	f(10000000000.0);
	return 0;
}