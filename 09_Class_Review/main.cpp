#include <iostream>
using namespace std;

#include "DateTime.h"

int main()
{
	const int MAXTICKS = 30;
	DateTime d(3, 10, 2021, 21, 46, 50);

	for (int i = 1; i <= MAXTICKS; i++) {
		cout << "Universal time: ";
		d.printUniversal(); 
		cout << "Standard  time: ";
		d.printStandard(); 
		d.tick(); 
	}

	cout << endl;
	return 0;
	getchar();
}