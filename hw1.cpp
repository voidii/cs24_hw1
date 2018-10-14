#include<iostream>
#include<ctime>

using namespace std;

void f(double n)
{
	clock_t begin = clock();
	int sum = 0;
	for (int i = 1; i < n; i *= 2)
		for (int j = 1; j <= i; j *= 2)
			++sum;
	clock_t end = clock();
	double diff = double(end - begin);
	cout << sum << endl;
	cout << diff;
}

int main()
{
	f(10000000000.01);
	return 0;
}