#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
using namespace std;

void guessGame();
bool isCorrect(int, int);

int main()
{
	guessGame();
	return 0;
	getchar();
}

void guessGame()
{
	int answer;
	int guess;
	char response;

	do {
		default_random_engine engine(static_cast<unsigned int>(time(0)));
		uniform_int_distribution<unsigned int> randomInt(1, 100);
		answer = randomInt(engine);
		//answer = 1 + rand() % 100;
 
		cout << "Number between 1 and 100.\n"
			<< "Guess a number?\n"
			<< "Please type your first guess" << endl << "? ";
		cin >> guess;

		while (!isCorrect(answer, guess)) {
			cin >> guess;
		}

		cout << "\nWell, you guessed right\n"
			<< "do you like to play again (y or n)?";
		cin >> response;



	} while (response == 'y');

}

bool isCorrect(int a, int b)
{
	if (a == b) {
		return true;
	}
	else if (a > b) {
		cout << "Too low. Try again.\n?";
	}
	else {
		cout << "Too high. Try again.\n?";
	}
	return false;
}