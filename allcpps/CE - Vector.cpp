// Samhith Patibandla
// 10/27/2023
// This program manages a list of beverages and performs various operations on it.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Prototype Functions
void showCopyright();
bool validate(double);
void vecDisplayBev(vector<string>);
bool valDuplicate(vector<string>, string);

int main()
{
	// Vector to store beverage names
	vector<string> beverageList;
	int numofBev;
	bool valSize, valDupItem;
	string tempBev;

	// Display copyright information
	showCopyright();

	// Validate and input the number of beverages in the inventory
	do {
		cout << "\nEnter the number of beverages you have in inventory: ";
		cin >> numofBev;
		valSize = validate(numofBev);
	} while (!valSize);

	cin.ignore();
	cout << endl;
	// Input beverage names and check for duplicates
	for (int i = 1; i <= numofBev; i++) {
		cout << "Enter the name of beverage " << i << ": ";
		getline(cin, tempBev);
		valDupItem = valDuplicate(beverageList, tempBev);
		if (valDupItem == true) {
			cout << "Error - this beverage already exists. Please enter a different beverage: ";
			getline(cin, tempBev);
		}
		beverageList.push_back(tempBev);
	}

	// Display the list of beverages
	vecDisplayBev(beverageList);

	// Add a new beverage and display the updated list
	cout << "\n\nPlease enter in the new beverage: ";
	getline(cin, tempBev);
	beverageList.push_back(tempBev);
	vecDisplayBev(beverageList);

	// Remove the last two beverages and display the updated list
	beverageList.pop_back();
	beverageList.pop_back();
	cout << endl;
	vecDisplayBev(beverageList);

	// Clear the beverage list and display an empty list
	beverageList.clear();
	cout << endl;
	vecDisplayBev(beverageList);

	// End of the program
	cout << "\nThanks for your business. Please come again.\n\n";

	system("pause");
	return 0;
}

// Function to display copyright information
void showCopyright() {
	cout << "CE - Vector\n";
	cout << "Copyright ©2021 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";
	cout << "\tWelcome to the CMSY-141 Food Kiosk Beverage Inventory List.\n";
}

// Function to validate input number (must be non-negative)
bool validate(double inputNum) {
	bool valInput = true;
	if (inputNum <= 0) {
		cout << "Error - Please enter a number greater than 0.\n";
		valInput = false;
	}
	return valInput;
}

// Function to display beverage list
void vecDisplayBev(vector<string> bevs) {
	cout << "\nBeverage List:\n";
	for (string tempBev : bevs) {
		cout << "\t" << tempBev << endl;
	}
	cout << "The total number of beverages is: " << bevs.size() << endl;
}

// Function to check for duplicates in the beverage list
bool valDuplicate(vector<string> bevs, string item) {
	bool valDup = find(bevs.begin(), bevs.end(), item) != bevs.end();
	return valDup;
}