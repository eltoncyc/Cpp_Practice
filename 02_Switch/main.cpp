
// Elton Chan 
// 1/24/2021

#include <iostream>
#include<cctype>
using namespace std;

const int NUMBER_OF_TESTS = 10;
const int MAX_VALUE = 1001; // used to be compared with M
const int M_VALUE = 1000;
const int D_VALUE = 500;
const int C_VALUE = 100;
const int L_VALUE = 50;
const int X_VALUE = 10;
const int V_VALUE = 5;
const int I_VALUE = 1;

int main()
{
	int sum; // output
	char input; //a single input char
	int lastValue; //the last processed value
	bool inputError;

	cout << "10 Roman numeral values will be input and converted into" <<
		"\ntheir equivalent Hindu-Arabic numeric values." << endl;

	for (int i = 1; i <= NUMBER_OF_TESTS; i++)
	{
		lastValue = MAX_VALUE;
		sum = 0;
		inputError = false;
		cout << "Input Roman numeral # " << i << ": ";
		
		while ((input = cin.get()) != EOF && input != '\n' && !inputError)
		{
			input = toupper(input);
			cout << input;
			switch (input)
			{
			case 'M':
				sum += M_VALUE;
				if (lastValue < M_VALUE)
				{
					sum -= 2 * lastValue;
				}
				lastValue = M_VALUE;
				break;

			case 'D':
				sum += D_VALUE;
				if (lastValue < D_VALUE)
				{
					sum -= 2 * lastValue;
				}
				lastValue = D_VALUE;
				break;

			case 'C':
				sum += C_VALUE;
				if (lastValue < C_VALUE)
				{
					sum -= 2 * lastValue;
				}
				lastValue = C_VALUE;
				break;

			case 'L':
				sum += L_VALUE;
				if (lastValue < L_VALUE)
				{
					sum -= 2 * lastValue;
				}
				lastValue = L_VALUE;
				break;

			case 'X':
				sum += X_VALUE;
				if (lastValue < X_VALUE)
				{
					sum -= 2 * lastValue;
				}
				lastValue = X_VALUE;
				break;

			case 'V':
				sum += V_VALUE;
				if (lastValue < V_VALUE)
				{
					sum -= 2 * lastValue;
				}
				lastValue = V_VALUE;
				break;

			case 'I':
				sum += I_VALUE;
				if (lastValue < I_VALUE)
				{
					sum -= 2 * lastValue;
				}
				lastValue = I_VALUE;
				break;

			// ignore \n \t and space.
			case '\n':
			case '\t':
			case ' ':
				break;

			default:
				inputError = true;
				cerr << " Error - last character was not valid!!!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}

		if(!inputError)
		{
			// only print the result for valid input.
			cout << " = " << sum << "\n" << endl;
		}
		
	}
	cout << "THAT'S ALL FOLKS :)" << endl;
	getchar();
}