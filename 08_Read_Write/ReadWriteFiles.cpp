// Elton Chan
// 3/7/2021

#include <iostream>
#include <conio.h>  // Required for _getch() function
#include <fstream>  // Required for file input/output
#include <iomanip>
#include <string>
using namespace std;

//global constants
const int MAX_REGULAR_HOURS = 40;
const int MAX_WEEKLY_HOURS = 54;
const double OVERTIME_PAYRATE_MULTIPLE = 1.5;
// for taxable 
const double TAX_CONSTANT1 = 14.00;
const double TAX_CONSTANT2 = 11.00;
// for federal tax calculation
const double FEDERAL_COEF1 = 0.14;
const double FEDERAL_COEF2 = 0.00023;
// for provincial tax calculation
const double PROVINCIAL_COEF = 0.35;
// for pension calculation
const double PENSION_AMT = 16.50;
const double PENSION_PCT = 0.077;
// for input validation
const int SIN_MAX_LENGTH = 9;
const int MIN_EXEMPTION = 0;
const int MAX_EXEMPTION = 19;
const int MIN_HOURS_WORKED = 0;
const int MAX_HOURS_WORKED = 54;
const double MIN_WEEKLY_WAGE = 0.00;
const double MAX_WEEKLY_WAGE = 99.99;

// function prototypes
// Input
bool isValidSIN(long socialInsuranceNum);
bool isValidPayRate(double payRate);
bool isValidExemptions(int numberOfExemptions);
bool isValidHoursWorked(double hoursWorked);

// Output functions
double calculateGrossPay(double payRate, double hoursWorked);
double calculateNetPay(double grossPay, double deductions, double pension);
double calculatePension(double grossPay);
double calculateDeductions(double grossPay, int numberOfExemptions);

// One way to specify a file name:
const char * IN_FILE = "EmployeePayInput.txt";

// A second way to specify a file name:
#define OUT_FILE "EmployeePayOutput.txt"

int main()
{
	//Declare variables
	long socialInsuranceNum;  // Will store social security number of employee
	int numberOfExemptions;  // Will store number of excemptions for employee

	double payRate = 0,			// Will store the pay rate for the employee
		hoursWorked = 0,		// Will store hours worked for the employee
		grossPay = 0,
		deductions = 0,
		netPay = 0,
		pension = 0,
		totalGrossPay = 0,
		totalNetPay = 0,
		totalPension = 0,
		totalDeductions = 0;

	//Define ifstream object and open file
	ifstream ins;
	ins.open(IN_FILE);

	//Check that file opened without any issues
	if (ins.fail())
	{
		cerr << "ERROR--> Unable to open input file : " << IN_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -1; //error return code
	}

	//Define ofstream object and open file
	ofstream outs;
	outs.open(OUT_FILE);

	//Check that file opened without any issues
	if (outs.fail())
	{
		cerr << "ERROR--> Unable to open output file : " << OUT_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -2; //error return code
	}

	// Output  header
	outs << "XYZ Company\n";
	outs << "---------------------------------\n\n";

	outs << left << setw(20) << "Social insurance no." <<
		right << setw(12) << "gross pay" <<
		right << setw(11) << "net pay" <<
		right << setw(11) << "pension" <<
		right << setw(15) << "deductions\n";
	outs << "--------------------------------------------------------------------\n";
	// Read in first social security number
	ins >> socialInsuranceNum;
	int employeeCount = 0;
	// Process data until end of file is reached
	while (!ins.eof()){

		// Read in other data for the employee
		ins >> payRate >> numberOfExemptions >> hoursWorked;

		// input validation
		bool validSIN = isValidSIN(socialInsuranceNum);
		bool validPay = isValidPayRate(payRate);
		bool validExemptions = isValidExemptions(numberOfExemptions);
		bool validHours = isValidHoursWorked(hoursWorked);


		// The following line of code is used to confirm that reading and writing from/to files is working correctly.
		//  This line of code (and these 2 comment lines) will need to be removed in your final solution.
		//outs << socialInsuranceNum << "  " << payRate << "  " << numberOfExemptions << "  " << hoursWorked << '\n';

		if (validSIN && validPay && validExemptions && validHours) {
			employeeCount++;
			
			grossPay = calculateGrossPay(payRate, hoursWorked);
			totalGrossPay += grossPay;

			pension = calculatePension(grossPay);
			totalPension += pension;

			deductions = calculateDeductions(grossPay, numberOfExemptions) + pension; 
			totalDeductions += deductions;

			netPay = calculateNetPay(grossPay, deductions, pension);
			totalNetPay += netPay;

			outs << left << setw(20) << socialInsuranceNum <<
				right << setw(12) << fixed << setprecision(2) << grossPay <<
				right << setw(11) << fixed << setprecision(2) << netPay <<
				right << setw(11) << fixed << setprecision(2) << pension <<
				right << setw(14) << fixed << setprecision(2) << deductions<<"\n";
		}
		else {
			cerr << fixed << setprecision(2);
			if (!validSIN) {
				cerr << setw(10) << right << socialInsuranceNum << setw(20) << left << "	INPUT DATA ERRROR:	" << "Invalid social security #" << endl;
			}
			if (!validPay) {
				cerr << setw(10) << right << socialInsuranceNum << setw(20) << left << "	INPUT DATA ERRROR:	" << "Invalid pay rate: " << payRate << endl;
			}
			if (!validExemptions) {
				cerr << setw(10) << right << socialInsuranceNum << setw(20) << left << "	INPUT DATA ERRROR:	" << "Invalid number of exemptions: " << numberOfExemptions << endl;
			}
			if (!validHours) {
				cerr << setw(10) << right << socialInsuranceNum << setw(20) << left << "	INPUT DATA ERRROR:	" << "Invalid hours worked: " << hoursWorked << endl;
			}
		}


		// Read in next social security number
		ins >> socialInsuranceNum;
	}

	// print summary
	outs << "\n\n\nSummary\n-------\n\n";
	outs << left << setw(42) << "Number of employees processed:" << right << setw(14) << employeeCount << "\n";
	outs << left << setw(42) << "Total gross pay for all employees:" << right << setw(14) << totalGrossPay << "\n";
	outs << left << setw(42) << "Total net pay for all employees:" << right << setw(14) << totalNetPay << "\n";
	outs << left << setw(42) << "Total pension withheld for all employees:" << right << setw(14) << totalPension << "\n";
	outs << left << setw(42) << "Total deductions for all employees:" << right << setw(14) << totalDeductions << "\n";

	// Close files
	ins.close();
	outs.close();

	//cout << '\n' << endl;

	// Remove following line of code (and this comment) from your solution
	//cout << "Type any key to continue ... \n\n";

	_getch(); // causes execution to pause until char is entered

}

// Input validation functions 
// check if the SIN is a 9 digit number
bool isValidSIN(long socialInsuranceNum)
{
	string strSIN = to_string(socialInsuranceNum);
	if (strSIN.length() == SIN_MAX_LENGTH && strSIN.at(0) != 0) {
		return true;
	}
	return false;
}

// check if payrate input is valid
bool isValidPayRate(double payRate)
{
	if (payRate >= MIN_WEEKLY_WAGE && payRate <= MAX_WEEKLY_WAGE) {
		return true;
	}
	return false;
}

// check if exemptions is valid
bool isValidExemptions(int numberOfExemptions)
{
	if (numberOfExemptions >= MIN_EXEMPTION && numberOfExemptions <= MAX_EXEMPTION) {
		return true;
	}
	return false;
}

// check if hours worked is valid
bool isValidHoursWorked(double hoursWorked)
{
	if (hoursWorked >= MIN_HOURS_WORKED && hoursWorked <= MAX_HOURS_WORKED) {
		return true;
	}
	return false;
}

// Output functions
// calculate the gross pay
// Regular pay for the first 40 hours and time-and-a-half 
// beyond that up to a limit of 54 hours in any given week. 
double calculateGrossPay(double payRate, double hoursWorked)
{
	double grossPay = 0;
	double extraPayRate = 0;
	if (hoursWorked <= MAX_REGULAR_HOURS) {
		grossPay = payRate * hoursWorked;
	}
	else {
		// calculate for overtime
		if (hoursWorked <= MAX_WEEKLY_HOURS) {
			grossPay = payRate * MAX_REGULAR_HOURS;
			extraPayRate = (payRate * OVERTIME_PAYRATE_MULTIPLE);
			grossPay += (extraPayRate * (hoursWorked - MAX_REGULAR_HOURS));
		}
	}
	return grossPay;
}

// calculate net pay
// Gross pay less all deductions
double calculateNetPay(double grossPay, double deductions, double pension)
{
	double netPay = 0;
	// check if gross pay is greater than deductions less pension
	if (grossPay >= (deductions - pension)) {
		netPay = grossPay - deductions;
	}
	return netPay;
}

// calculate pension
// $16.50 or 7.7% of gross, whichever is less. 
double calculatePension(double grossPay)
{
	double pension = 0;
	pension = grossPay * PENSION_PCT;
	if (pension > PENSION_AMT) {
		return PENSION_AMT;
	}
	return pension;
}

// calculate deductions
// federal + provincial
double calculateDeductions(double grossPay, int numberOfExemptions)
{
	double taxable = 0;
	double federal = 0;
	double provincial = 0;
	double deductions = 0;

	taxable = grossPay - (TAX_CONSTANT1 * numberOfExemptions) - TAX_CONSTANT2;
	if (taxable >= 0) {
		federal = taxable * (FEDERAL_COEF1 + (FEDERAL_COEF2 * taxable));
		provincial = federal * PROVINCIAL_COEF;
		deductions = federal + provincial;
	}
	return deductions;

}