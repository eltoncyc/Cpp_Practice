// Elton Chan
// March 13 2021

#include "Complex.h"
#include <iomanip>
#include <iostream>
using namespace std;


Complex::Complex(double r, double i)
	:real(r), imaginary(i){}



// setters 
void Complex::setComplexNum(const double& i)
{
	imaginary = i;
}

void Complex::setRealNum(const double& r)
{
	real = r;
}
//getters
double Complex::getComplexNum(void)const
{
	return imaginary;
}

double Complex::getRealNum(void) const
{
	return real;
}

// add two complex num
const Complex& Complex::plusEq(const Complex& c)
{
	real += c.real;
	imaginary += c.imaginary;
	return *this;
}

// subtract complex num
const Complex& Complex::minusEq(const Complex& c)
{
	real -= c.real;
	imaginary -= c.imaginary;
	return *this;
	
}

// display
void Complex::display()const
{
	cout << fixed << setprecision(4) << "( " << real << " , " << imaginary << " )";
}
