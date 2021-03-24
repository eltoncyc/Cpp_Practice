#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h"
using namespace std;

Date::Date(int mn, int dy, int yr)
{
	if (mn > 0 && mn <= monthsPerYear) {
		month = mn;
	}
	else {
		throw invalid_argument("month must be 1-12");
	}
	
	if (year >= minYear) {
		year = yr;
	}
	else {
		throw invalid_argument("year must be greater than 1900");
	}

	day = checkDay(dy);
	print();
	cout << endl;
}

void Date::print() const
{
	cout << month << '/' << day << '/' << year;

}

Date::~Date()
{
	cout << "Date obj destructor for date ";
	print();
	cout << endl;
}

unsigned int Date::checkDay(int day) const
{
	static const array<int, monthsPerYear + 1> daysPerMonth =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (day > 0 && day <= daysPerMonth[month]) {
		return day;
	}

	if (month == 2 && day == 29 && year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return day;
	}
	throw invalid_argument("invalid day for the given month and yaer");
}


