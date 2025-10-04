// Samhith Patibandla
// 11/09/2023
// This C++ program calculates daily laundry statistics, including total loads washed, average loads per day, 
// total dried loads, revenue, and identifies profitable days for a laundromat.

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// Global Constant Variable
const int WASHTODRY = 3;

// Prototype Functions
void displayTitle();
bool validIntInput(int);
bool validate(int &);
int totalWashed(int*, int);
double average(int*, int);
int howManyDryerLoads(int*, int);
double calcRevenue(int*, int);
bool profit(int);
void displayHighest(int*, int);

int main() 
{
	int numOfDays;
	bool valInput;
	int* loads, dryerLoads;
	displayTitle();

	// Get the number of days of data collection from the user
	cout << "\nPlease enter the number of days: ";
	do {
		cin >> numOfDays;
		valInput = validIntInput(numOfDays);
	} while (!valInput);

	// Dynamically allocate an array to hold revenue for each day
	loads = new int[numOfDays];

	// Input gross revenue for each day of the week
	for (int i = 0; i < numOfDays; i++)
	{
		cout << "Enter the number of loads washed for day " << i + 1 << ": ";
		do
		{
			cin >> *(loads + i);
			valInput = validate(*(loads + i));
		} while (!valInput);
	}

	cout << "\nThe total number of loads washed is " << totalWashed(loads, numOfDays) << endl;
	cout << "The average number of loads washed per day is " << fixed << setprecision(1) << average(loads, numOfDays) << endl;
	dryerLoads = howManyDryerLoads(loads, numOfDays);
	cout << "\nThe total number of loads dried is " << dryerLoads << endl;
	cout << "The average number of loads dried per day is " << fixed << setprecision(1) << dryerLoads / double(numOfDays) << endl;
	cout << "\nThe total revenue generated is $" << fixed << setprecision(2) << calcRevenue(loads, numOfDays) << endl;

	// Determine the total number of days that the Laundromat made a profit
	int profitDays = 0;
	for (int i = 0; i < numOfDays; i++) {
		if (profit(*(loads + i))) {
			profitDays++;
		}
	}
	cout << "\nThere were " << profitDays << " days in which the laundromat made a profit!" << endl;

	// Calling function to display highest loads and day
	displayHighest(loads, numOfDays);

	// Release the dynamically allocated memory at the end of the program
	delete[] loads;

	system("pause");
	return 0;
}

// Function to display title of Program
void displayTitle() 
{
	cout << "Lab 7 - Pointers\n";
	cout << "Copyright © 2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
	cout << "\n\tWelcome to the CMSY-141 Laundromat Profit Calculator\n";
}

// Function to validate input number (must be positive)
bool validIntInput(int inputNum)
{
	bool valInput = true;
	if (inputNum <= 0)
	{
		cout << "The number of days must be greater than 0; please reenter: ";
		valInput = false;
	}
	return valInput;
}

// Function to validate input number (must be non-negative)
bool validate(int& inputNum)
{
	bool valInput = true;
	if (inputNum < 0)
	{
		cout << "Negatives are not allowed. Please re-enter: ";
		valInput = false;
	}
	else if (inputNum > 35) 
	{
		cout << "The maximum loads per day is 35.  Please reenter: ";
		valInput = false;
	}
	return valInput;
}

// Function to calculate the total revenue
int totalWashed(int* loads, int days)
{
	int sumInput = 0;
	for (int i = 0; i < days; i++)
	{
		sumInput += *(loads + i);
	}
	return sumInput;
}

// Function to calculate the average revenue
double average(int* loads, int days) 
{
	int total = totalWashed(loads, days);
	double average = total / double(days); // Cast total to double for floating-point division
	return average;
}

int howManyDryerLoads(int* loads, int days) {
	int sumLoads = 0, dryLoads;
	for (int i = 0; i < days; i++)
	{
		dryLoads = (*(loads + i) % WASHTODRY) > 0 ? (*(loads + i) / WASHTODRY) + 1 : *(loads + i) / WASHTODRY;
		sumLoads += dryLoads;
	}
	return sumLoads; 
}

// Function to calculate the amount of revenue earned for the number of days entered
double calcRevenue(int* loads, int days) {
	double revenue = 0;
	for (int i = 0; i < days; i++) {
		revenue += *(loads + i) * 3.56 + howManyDryerLoads(loads + i, 1) * 2.99;
	}
	return revenue;
}

// Function to determine if the Laundromat made a profit for the day
bool profit(int loads) {
	double revenue = loads * 3.56 + howManyDryerLoads(&loads, 1) * 2.99;
	return revenue >= 97.00;
}

void displayHighest(int* loads, int days) {
	int highestLoad = *(loads), highestDay = 0;

	for (int i = 0; i < days; i++) {
		if (highestLoad < *(loads + i)) {
			highestLoad = *(loads + i);
			highestDay = i + 1;
		}
	}
	cout << "\nThe day with the highest washer load was day " << highestDay << " with " << highestLoad << " loads.\n\n";
	return;
}