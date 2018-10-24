#include <iostream>
using namespace std;
void sort(int arr[], int n)
{ 
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			arr[j] = key;
			j = j-1;
			for (int m = 0; m < 10; m++)
			{
				cout << arr[m] << " ";
			}
			cout << endl;
		}
	}
}

int main()
{
	int arr_1[10] = {9, 2, 3, 5, 4, 1, 8, 7, 10, 6};
	sort(arr_1, 10);
	return 0;
}