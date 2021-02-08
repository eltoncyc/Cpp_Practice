#pragma once
// Member-function definitions for class Fraction.
// Author:  Elton Chan
// Date: 2/7/2021

#include <iostream>

template<typename T>
T gcd(T value1, T value2)
{
	T output = 1; 
	// absolute values should be used 
	if (value1 < 0) {
		value1 *= -1;
	}
	if (value2 < 0) {
		value2 *= -1;
	}


	// for-loop approach
	for (T i = output; i <= ((value1 < value2) ? value1 : value2); i++)
	{
		if (i > output && value1 % i == 0 && value2 % i == 0) {
			output = i;
		}
	}
	return output;

	// recursive approach 
	// final output will be the recursion step being run until reaching the base case.
	
	//if (value2 == 0) // base case 
	//{
	//	return value1;
	//}
	//
	//return gcd(value2, value1 % value2); // recursion step

	// Compared both methods, same test output generated. 

}