#pragma once

// Employee.h
// Definition for class Employee
// Elton Chan 
// Jan 17, 2021

#include <string>

class Employee
{
public:
	explicit Employee(std::string firstName, std::string lastName, int monthlySalary); //constructor
	void setFirstName(std::string); // set first name 
	std::string getFirstName() const; // return the first name
	void setLastName(std::string); // set last name 
	std::string getLastName() const; // return the last name
	void setMonthlySalary(int); // set monthly salary
	int getMonthlySalary() const; // return the monthly salary

private:
	std::string firstName; // data memeber that stores the first name
	std::string lastName; // stores the last name
	int monthlySalary; // stores the monthly salary

	const static int MIN_NAME_LENGTH = 2; // name should be at least 2 in length
	const static int MIN_MONTH_SALARY = 0; // salary should be at least $0

};