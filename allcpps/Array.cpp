// Samhith Patibandla
// 10/25/2023
// This C++ program calculates and displays the total revenue, average revenue, 
// total tax, average tax, total profit, and average profit for a food kiosk over a week. 

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Declaring global constants 
const int DAYSINWEEK = 7;
const double SALESTAX = 0.06;

// Prototype functions
void showCopyright();
bool validate(double);
void displayReport(double []);
double sumRev(double[]);
double avgRevenue(double[]);

// Beginning of Main Function
int main()
{
	bool valInput;
	showCopyright();

	double revinue[DAYSINWEEK];
	double totalRev, avgRev, totalTaxAmt, avgTaxAmt, totalProfit, avgProfit;

	// Input gross revenue for each day of the week
	cout << "\nPlease enter the gross revinue for \n";

	for (int i = 0; i < DAYSINWEEK; i++) {
		do {
			cout <<"\t Day " << i + 1 << " : $";
			cin >> revinue[i];
			valInput = validate(revinue[i]);
		} while (!valInput);
	}

	// Display sales report
	displayReport(revinue);

	// Calculate total and average revenue, total and average tax, total and average profit
	totalRev = sumRev(revinue);
	avgRev = avgRevenue(revinue);
	totalTaxAmt = totalRev * SALESTAX;
	avgTaxAmt = avgRev * SALESTAX;
	totalProfit = totalRev - totalTaxAmt;
	avgProfit = avgRev - avgTaxAmt;

	// Display the calculated values
	cout << "\n\nTotal Revenue for the week: $" << totalRev << endl;
	cout << "Average Revenue per day: $" << avgRev << endl << endl;
	cout << "Total Tax for the week: $" << totalTaxAmt << endl;
	cout << "Average Tax per day: $" << avgTaxAmt << endl << endl;
	cout << "Total Profit for the week: $" << totalProfit << endl;
	cout << "Average Profit per day: $" << avgProfit << endl << endl;

	cout << "Thank you for using the Food Kiosk Calculator! Goodbye!\n\n";

	system("pause");
	return 0;
}

// Function to display copyright and welcome message
void showCopyright() {
	cout << "CE - Array\n";
	cout << "Copyright ©2021 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";
	cout << "\tWelcome to the CMSY-141 Food Kiosk Profit Calculator\n";
}

// Function to validate input number (must be non-negative)
bool validate(double inputNum) {
	bool valInput = true;
	if (inputNum < 0) {
		cout << "Invalid Entry. Please enter valid value\n";
		valInput = false;
	}
	return valInput;
} 

// Function to display the sales report
void displayReport(double inputAry[]) {
	cout << "\n\nFood Kiosk Profit Calculator\n";
	cout << "\tSales Report\n";

	for (int i = 0; i < DAYSINWEEK; i++) {
		cout << "\n\tDay " << i + 1 << " : $" << fixed << setprecision(2) << inputAry[i];
	}
	return;
}

// Function to calculate the total revenue
double sumRev(double inputAry[]) {
	double sumInput = 0;
	for (int i = 0; i < DAYSINWEEK; i++) {
		sumInput += inputAry[i];
	}
	return sumInput;
}

// Function to calculate the average revenue
double avgRevenue(double inputAry[]) {
	double total = sumRev(inputAry);
	double average = total / DAYSINWEEK;
	return average;
}

