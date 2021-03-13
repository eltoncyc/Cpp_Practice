// Elton Chan
// March 13 2021
#pragma once

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{

public:
	//default ctor
	Complex(double = 1.0, double = 0.0);
	// setters 
	void setComplexNum(const double& i);
	void setRealNum(const double& r);
	//getters
	double getComplexNum(void) const;
	double getRealNum(void) const;
	// add two complex num
	const Complex& plusEq(const Complex&);
	// subtract complex num
	const Complex& minusEq(const Complex&);
	// display
	void display() const;


private:
	double real;
	double imaginary;

};
#endif // !COMPLEX_H


