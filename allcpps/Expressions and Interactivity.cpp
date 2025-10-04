// Samhith Patibandla 
// 09/15/2023
// This program calculates and prints the average number of wins for 3 seasons. 
// Prompts user to enter 3 seansons numbers,check the validity and prints the error message if number is less than zero

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	// Print header
	cout << "CE-Expressions and Interactivity\n";
	cout << "Copyright ©2021 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";

	// Declare Variables
	int num1, num2, num3;
	bool valdata;
	const int numOfSeason = 3;
	cout << "Input Data: \n";

	// Prompts the user input for season 1
	cout << "\tEnter the number of wins in season 1: ";

	// Do-while loop to validate user input
	do {
		cin >> num1;
		cout << endl;
		if (num1 >= 0) {
			valdata = true;
		}
		// Otherwise, set valdata to false and print an error message
		else {
			cout << "\nError - You cannot enter in a value less than 0. Please reenter here: ";
			cout << endl;
			valdata = false;
		}
	} while (!valdata);

	// No extra new line after season 1 input

	// Prompts the user input for season 2
	cout << "\tEnter the number of wins in season 2: ";

	// Do-while loop to validate user input
	do {
		cin >> num2;
		cout << endl;
		if (num2 >= 0) {
			valdata = true;
		}
		// Otherwise, set valdata to false and print an error message
		else {
			cout << "\nError - You cannot enter in a value less than 0. Please reenter here: \n";
			valdata = false;
		}
	} while (!valdata);

	// No extra new line after season 2 input

	// Prompts the user input for season 3
	cout << "\tEnter the number of wins in season 3: ";

	// Do-while loop to validate user input
	do {
		cin >> num3;
		cout << endl;
		if (num3 >= 0) {
			valdata = true;
		}
		// Otherwise, set valdata to false and print an error message
		else {
			cout << "\nError - You cannot enter in a value less than 0. Please reenter here: ";
			valdata = false;
		}
	} while (!valdata);


	// Calculate and print the average number of wins
	double avg;
	avg = static_cast<double> (num1 + num2 + num3) / numOfSeason;

	cout << endl;
	cout << endl << "The average number of wins per year is: " << fixed << setprecision(2) << avg << endl << endl;


	system("pause");
	return 0;
}