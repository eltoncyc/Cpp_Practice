#include <iostream>
#include <array>
using namespace std;

int main()
{
	
	int i, n;
	int* arr;

	cout << "How many elements in the array? (-1 to End) ";
	cin >> n;

	while (n != -1)
	{
		arr = new (nothrow) int[n];
		if (arr == nullptr)
			cout << "Error: memory could not be allocated.";
		else
		{
			for (i = 0; i < n; i++)
			{
				cout << "Enter a number: ";
				cin >> arr[i];
			}
			cout << "The array has: ";
			for (i = 0; i < n; i++)
			{
				cout << arr[i] << ", ";
			}
			delete[] arr;
		}
		cout << "\nHow many elements in the array? (-1 to End) ";
		cin >> n;
	}


	return 0;

}
