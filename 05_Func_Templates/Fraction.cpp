// Member-function definitions for class Fraction.
// Author:  Elton Chan
// Date: 2/7/2021

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;

int DEFAULT_NUM = 0;
int DEFAULT_DENOM = 1;

// default ctor
Fraction::Fraction(void):numerator(DEFAULT_NUM), denominator(DEFAULT_DENOM){};

// second ctor, which
// requires at least one long long argument
Fraction::Fraction(long long num, long long denom)
	:numerator(num), denominator(denom)
{
	if (denominator == 0) {
		denominator = 1;
		numerator = num;
		cerr << "Denominator should not be 0. It has been set to 1." << endl;
	}
	else {
		numerator = num;
		denominator = denom;
		simplify();
	}
}


//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq(const Fraction & op )
{
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
	             //   will invoke gcd() function to reduce fraction
	             //   as much as possible

	return (*this); // returns the object which invoked the method
}

//Implementation of the plusEq() member function
const Fraction& Fraction::plusEq(const Fraction& op)
{
	numerator = (numerator * op.denominator) + (op.numerator * denominator);
	denominator = denominator * op.denominator;

	simplify();
	return(*this);
}

//Implementation of the minusEq() member function
const Fraction& Fraction::minusEq(const Fraction& op)
{
	numerator = (numerator * op.denominator) - (op.numerator * denominator);
	denominator = denominator * op.denominator;

	simplify();
	return(*this);
}

//Implementation of the divideEq() member function
const Fraction& Fraction::divideEq(const Fraction& op)
{
	numerator *= op.denominator;
	denominator *= op.numerator;

	simplify();
	return(*this);
}

//Implementation of the negate() function
Fraction Fraction::negate(void)const
{
	return Fraction(numerator * -1, denominator);
}

long long Fraction::getNum(void)const  // Returns numerator
{
	return numerator;
}


long long Fraction::getDenom(void) const // Returns denominator
{
	return denominator;
}

// reduces the Fraction objects as much as possible.
void Fraction::simplify()
{
	long divisor = gcd(numerator, denominator);
	numerator /= divisor;
	denominator /= divisor;

	//It also ensures that the denominator is positive.
	if (denominator < 0) {
		denominator *= -1;
		numerator *= -1; // move the negative sign from denom to num
	}

}

// display the object 
void Fraction::display(void) const
{
	cout << getNum() << "/" << getDenom();
}