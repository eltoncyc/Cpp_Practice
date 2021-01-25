// Employee.cpp
// Member-function definitions for class Employee
// Elton Chan 
// Jan 17, 2021

#include <iostream>
#include "Employee.h"

using namespace std;

// Employee constructor initializes data member 
Employee::Employee(string initFirstName, string initLastName, int initMonthlySalary)
	:firstName(initFirstName), lastName(initLastName), monthlySalary(initMonthlySalary)
{
	if (firstName.length() < MIN_NAME_LENGTH)
	{
		cerr << "\nWarning - invalid length string entered for first name in ctor: " << firstName;
		cerr << "\nThe string that was entered will be used for now." << endl;

	}

	if (lastName.length() < MIN_NAME_LENGTH)
	{
		cerr << "\nWarning - invalid length string entered for last name in ctor: " << lastName;
		cerr << "\nThe string that was entered will be used for now." << endl;

	}

	if (monthlySalary < MIN_MONTH_SALARY)
	{
		cerr << "\nInvalid salary amount specified in ctor: $ " << monthlySalary;
		cerr << "\nSalary set to $"<<MIN_MONTH_SALARY<<" instead." << endl;
		monthlySalary = MIN_MONTH_SALARY;
	}
}

// set first name 
void Employee::setFirstName(string theFirstName)
{
	if (theFirstName.length() >= MIN_NAME_LENGTH)
	{
		firstName = theFirstName;
	}
	else
	{
		cerr << "\nERROR - invalid length string entered for first name in setFirstName(): " << theFirstName;
		cerr << "\nThe first name was left unchanged: " << firstName<<endl;
	}
}

// access first name 
string Employee::getFirstName() const
{
	return firstName;
}

// set last name
void Employee::setLastName(string theLastName)
{
	if (theLastName.length() >= MIN_NAME_LENGTH)
	{
		lastName = theLastName;
	}
	else
	{
		cerr << "\nERROR - invalid length string entered for last name in setLastName(): " << theLastName;
		cerr << "\nThe last name was left unchanged: " << lastName << endl;
	}
}

// access last name
string Employee::getLastName() const
{
	return lastName;
}

// set monthly salary
void Employee::setMonthlySalary(int theMonthlySalary)
{
	if (theMonthlySalary >= MIN_MONTH_SALARY)
	{
		monthlySalary = theMonthlySalary;
	}
	else 
	{
		cerr << "\nERROR - Invalid salary amount specified: $ " << theMonthlySalary;
		cerr << "\nSalary was left unchanged at: " << monthlySalary << endl;
	}
}

// access monthly salary
int Employee::getMonthlySalary() const
{
	return monthlySalary;
}