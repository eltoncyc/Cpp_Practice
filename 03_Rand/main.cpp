// main.cpp
// Elton Chan 
// Jan 31, 2021

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function prototypes
void multiplication(); // function prototype
void correctMessage(); // function prototype
void incorrectMessage(); // function prototype

const int EXIT_KEY = -1;
const int MAX_VALUE = 9;
const int MIN_VALUE = 0;

int main()
{
	multiplication();
	cout << "That's all for now. Bye." << endl;
	getchar();
	
}

void multiplication()
{
	unsigned int randInt1;
	unsigned int randInt2;
	int answer = 0;
	int trueAns = 0;
	// randomize random number generator using current time 
	srand(static_cast<unsigned int>(time(0)));


	cout << "Enter " << EXIT_KEY << " to End." << endl;
	
	while (answer != EXIT_KEY)
	{
		randInt1 = MIN_VALUE + rand() % (MAX_VALUE + 1);
		randInt2 = MIN_VALUE + rand() % (MAX_VALUE + 1);
		trueAns = randInt1 * randInt2;

		cout << "How much is " << randInt1 << " times " << randInt2 << " (" << EXIT_KEY << " to End)? ";
		cin >> answer;
		while (cin.rdstate())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input entered - try again: "; // prompt to try again
			cin >> answer;
		}

		while (answer != trueAns && answer != EXIT_KEY)
		{
			incorrectMessage();
			cin >> answer;
			while (cin.rdstate())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Invalid input entered - try again: "; // prompt to try again
				cin >> answer;
			}
		}
		if (answer == trueAns) { // if it's not -1 but a correct answer
			correctMessage();
		}
	}
}

void correctMessage()
{
	const int TOTAL_MSGS = 4;
	unsigned int choice = rand() % TOTAL_MSGS; 
	switch (choice) {
	case 0:
		cout << "Very good!\n" << endl;
		break;
	case 1:
		cout << "Excellent!\n" << endl;
		break;
	case 2:
		cout << "Nice work!\n" << endl;
		break;
	case 3:
		cout << "Keep up the good work!\n" << endl;
		break;
	default:
		cout << "Randomizer failed\n" << endl;
		break;
	}
}

void incorrectMessage()
{
	const int TOTAL_MSGS = 4;
	unsigned int choice = rand() % TOTAL_MSGS;
	switch (choice) {
	case 0:
		cout << "No. Please try again.\n?";
		break;
	case 1:
		cout << "Wrong. Try once more.\n?";
		break;
	case 2:
		cout << "Don't give up!\n?";
		break;
	case 3:
		cout << "No. Keep trying.\n?";
		break;
	default:
		cout << "Randomizer failed\n";
		break;
	}
}