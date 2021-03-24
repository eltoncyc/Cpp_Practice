#include <string>
#include "Date.h"

#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
public:
	Employee(const std::string&, const std::string&, const Date&, const Date&);
	void print()const;
	~Employee();
private:
	std::string firstName;
	std::string lastName;
	const Date birthDate;
	const Date hireDate;

}
#endif // !EMPLOYEE_H
