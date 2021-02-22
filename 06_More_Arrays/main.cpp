// Elton Chan
// 2/21/2021

#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

// constants
const int SIZE_OF_ARRAY = 20;
const int LOWEST_VALUE = 10;
const int HIGHEST_VALUE = 100;
const int NUMBER_ELEMENTS_ROW = 5;

// functions prototypes 
int getInput(int index, int lowValue, int highValue);
bool isUnique(array<unsigned int, SIZE_OF_ARRAY> arr, int pos, int value);

int main()
{	
	// define the output array
	array<unsigned int, SIZE_OF_ARRAY> outputArray = {};
	// define the input value
	int input = 0;
	// define valid output count 
	int count = 0;

	// prompt for input of 20 integers
	for (int i = 0; i < outputArray.size(); i++)
	{	
		// read input
		input = getInput(i, LOWEST_VALUE, HIGHEST_VALUE);
		// check if it's unique
		if (isUnique(outputArray, i,input))
		{
			outputArray[i] = input;
			cout << "The number: " << input << " is unique" << endl;
		}
		
	}
	// print the output array
	cout << "\n\nThe unique numbers are : \n";
	for (int i = 0; i < outputArray.size(); i++)
	{	
		if (outputArray[i] > 0)
		{
			cout << setw(5) << outputArray[i];
			if (count % NUMBER_ELEMENTS_ROW == 4)
			{
				cout << '\n';
			}
			count++;
		}
		
	}
	cout << '\n' << endl;

	getchar();
	return 0;
}

//  Function continues to prompt for value until a valid value entered
int getInput(int index, int lowValue, int highValue)
{
	int value = 0;
	cout << "\nEnter # " << index + 1 << " : ";
	cin >> value;

	// accept integers between 10 and 100
	while (cin.rdstate() || value < LOWEST_VALUE || value > HIGHEST_VALUE)
	{
		if (cin.rdstate())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		cout << "The number entered is not in the valid range of " << LOWEST_VALUE << " to " << HIGHEST_VALUE << endl;
		cout << "\nEnter # " << index + 1 << " : ";
		cin >> value;
	}

	return value;
}

// function to check if a value is unique in the given array
bool isUnique(array<unsigned int, SIZE_OF_ARRAY> arr, int pos, int value)
{
	// only read the array until the given position
	for (unsigned int i = 0; i < pos; i++)
	{
		if (arr[i] == value)
		{
			return false;
		}
	}
	return true;
}