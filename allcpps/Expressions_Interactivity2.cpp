// Samhith Patibandla
//09/17/2023
// This program calculates the cost of a bicycle, including the base price, warranty cost, sales tax, total cost, 
// down payment, total due at purchase, finance amount, and monthly payment. Where disposal fee and finance term are constant.


// Include the standard libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// Print header
	cout << "Lab 1 - Expressions and Interactivity" <<endl;
	cout << "Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited." << endl <<endl;
	cout << "Welcome to the Bicycle Cost Calculator program" << endl << endl;

	// Declare variables
	string make_and_model;
	double base, warranty, salesTax, taxable;
	const double disposal = 14.67;
	bool valdata;
	
	// Prompts the user input make and model of the bicycle
	cout << "Please enter the make and model of the bicycle: ";
	getline(cin, make_and_model);
	
	// Prompts the user input base price of the bicycle
	cout << "\nEnter the base price of the bicycle: ";

	// Do-while loop to validate user input
	do {
		cin >> base;
		if (base >= 0) {
			valdata = true;
		}
		// Otherwise, set valdata to false and print an error message
		else {
			cout << "Error - the base price of the bicycle cannot be less than or equal to $0.00. Please reenter here: ";
			valdata = false;
		}
	} while (!valdata);

	cout << "\nEnter the cost of the bicycle damage warranty: ";

	// Do-while loop to validate user input
	do {
		cin >> warranty;
		if (warranty >= 0) {
			valdata = true;
		}
		// Otherwise, set valdata to false and print an error message
		else {
			cout << "Error - the price of the bicycle damage warranty cannot be less than or equal to $0.00. Please reenter here: ";
			valdata = false;
		}
	} while (!valdata);

	// Tax calculated for the sum of base price of the bicycle & warrenty	    
	taxable = base + warranty;
	salesTax = taxable * 0.06;

	//Calculations for total cost, Downpayment, Total due at the purchase of the bicycle, finance amount, monthly payment
	double totalPrice = base + warranty + disposal + salesTax;
	double downPay = taxable * 0.22;
	double totalDue = downPay + salesTax + disposal;         
	double remainingAmountDue = taxable - downPay;
	const int financeTerm = 18;
	double monthlyPay = remainingAmountDue / financeTerm;

	// Display the output report
	cout << "\nOUTPUT REPORT: \n";
	cout << "Make and Model: " << make_and_model;
	cout << endl;
	cout << "Base Price: \t\t$" << fixed << setprecision(2) << setw(9) << setfill(' ') << base << endl;
	cout << "Warranty Cost: \t\t$" << fixed << setprecision(2) << setw(9) << setfill(' ') << warranty << endl;
	cout << "Disposal Fee: \t\t$" << fixed << setprecision(2) << setw(9) << setfill(' ') << disposal << endl;
	cout << "Sales Tax: \t\t$" << fixed << setprecision(2) << setw(9) << setfill(' ') << salesTax << endl;
	cout << "Total Cost: \t\t$" << fixed << setprecision(2) << setw(9) << setfill(' ') << totalPrice << endl;
	cout << "Downpayment: \t\t$" << fixed << setprecision(2) << setw(9) << setfill(' ') << downPay << endl;
	cout << "Total Due at urchase: \t$" << fixed << setprecision(2) << setw(9) << setfill(' ') << totalDue << endl;
	cout << "Finance Amount: \t$" << fixed << setprecision(2) << setw(9) << setfill(' ') << remainingAmountDue << endl;
	cout << "Monthly Payment: \t$" << fixed << setprecision(2) << setw(9) << setfill(' ') << monthlyPay << endl << endl;

	// Pause the program
	system("pause");

	// Return from main
	return 0;

}


