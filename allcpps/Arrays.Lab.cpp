// Samhith Patibandla
// 10/29/2023
// This program calculates and displays sales data for inventory items over a week.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Initialize global constants
const int NUMOFITEMS = 3;
const int NUMOFDAYS = 7;

// Prototype functions
void showCopyright();
int validate(int, string);
void aryInput(string[], int[][NUMOFDAYS]);
void displayAry(const string[], const int[][NUMOFDAYS]);
void displayAvg(const string[], const int[][NUMOFDAYS]);
void displayLowest(const string[], const int[][NUMOFDAYS]);
void displayHighest(const string[], const int[][NUMOFDAYS]);
void displayDayHighest(const string[], const int[][NUMOFDAYS]);

int main() {
	// Display copyright information and program introduction
	showCopyright();

	// Arrays to store inventory item names and corresponding sales data
	string invItem[NUMOFITEMS] = { "none","none","none" };
	int itemSold[NUMOFITEMS][NUMOFDAYS] = { {0, 0, 0, 0, 0, 0, 0},
											{0, 0, 0, 0, 0, 0, 0},
											{0, 0, 0, 0, 0, 0, 0} };

	// Input sales data for each inventory item
	aryInput(invItem, itemSold);

	// Display sales data, average sales, lowest and highest sales, and days with highest sales
	displayAry(invItem, itemSold);
	displayAvg(invItem, itemSold);
	displayLowest(invItem, itemSold);
	displayHighest(invItem, itemSold);
	displayDayHighest(invItem, itemSold);

	system("pause");
	return 0;
}

// Function to display copyright information and program introduction
void showCopyright() {
	cout << "Lab 5 - Arrays\n";
	cout << "Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
	cout << "\n\tWelcome to the CMSY-141 Food Kiosk Inventory Program\n";
	return;
}

// Function to validate input number (must be non-negative)
int validate(int inputNum, string itemLbl) {
	bool valInput;
	do {
		valInput = true;
		if (inputNum <= 0) {
			cout << "Error - The number of " << itemLbl << " must be greater than 0. Please reenter: ";
			cin >> inputNum;
			valInput = false;
		}
	} while (!valInput);
	return inputNum;
}

// Function to input inventory item names and sales data
void aryInput(string itemType[], int numSold[][NUMOFDAYS]) {

	for (int i = 0; i < NUMOFITEMS; i++) {
		cout << "\nEnter name of the inventory item: ";
		getline(cin, itemType[i]);

		for (int j = 0; j < NUMOFDAYS; j++) {
			cout << "Enter the number of " << itemType[i] << " sold on day " << j + 1 << ": ";
			cin >> numSold[i][j];
			numSold[i][j] = validate(numSold[i][j], itemType[i]);
		}
		cin.ignore();
	}
	return;
}

// Function to display the sales data in a tabular format
void displayAry(const string itemType[], const int numSold[][NUMOFDAYS]) {
	cout << "\nItem\t\t\tDay 1\tDay 2\tDay 3\tDay 4\tDay 5\tDay 6\tDay 7";
	cout << "\n____\t\t\t____\t____\t____\t____\t____\t____\t____\n";

	for (int i = 0; i < NUMOFITEMS; i++) {
		cout << endl << itemType[i] << "\t\t";
		for (int j = 0; j < NUMOFDAYS; j++) {
			cout << numSold[i][j] << "\t";
		}
	}
	cout << endl;
	return;
}

// Function to calculate and display average sales for each item
void displayAvg(const string itemType[], const int numSold[][NUMOFDAYS]) {
	double calcAvg;
	cout << "\nItem\t\t\tAverage";
	cout << "\n____\t\t\t_______\n";
	for (int i = 0; i < NUMOFITEMS; i++) {
		int calcSum = 0;
		for (int j = 0; j < NUMOFDAYS; j++) {
			calcSum += numSold[i][j];
		}
		calcAvg = calcSum / 7.00;
		cout << endl << itemType[i] << "\t\t" << fixed << setprecision(1) << calcAvg;
	}
	return;
}

// Function to display the item that sold the lowest amount and on which day
void displayLowest(const string itemType[], const int numSold[][NUMOFDAYS]) {
	int lowestAmt = numSold[0][0];
	string lowItemName = itemType[0];
	int lowestDay = 1;
	for (int i = 0; i < NUMOFITEMS; i++) {
		for (int j = 0; j < NUMOFDAYS; j++) {
			if (lowestAmt > numSold[i][j]) {
				lowestAmt = numSold[i][j];
				lowItemName = itemType[i];
				lowestDay = j + 1;
			}
		}
	}
	cout << "\n\nItem " << lowItemName << " sold the lowest amount, " << lowestAmt << ", " << "on day " << lowestDay << endl;
	return;
}

// Function to display the item that sold the highest amount and on which day
void displayHighest(const string itemType[], const int numSold[][NUMOFDAYS]) {
	int highestAmt = 0;
	string highItemName;
	int highestDay;
	for (int i = 0; i < NUMOFITEMS; i++) {
		for (int j = 0; j < NUMOFDAYS; j++) {
			if (highestAmt < numSold[i][j]) {
				highestAmt = numSold[i][j];
				highItemName = itemType[i];
				highestDay = j + 1;
			}
		}
	}
	cout << "\nItem " << highItemName << " sold the highest amount, " << highestAmt << ", " << "on day " << highestDay << endl;
	return;
}

// Function to display the item with the most days of highest sales
void displayDayHighest(const string itemType[], const int numSold[][NUMOFDAYS]) {
	int itemCount[NUMOFITEMS] = { 0, 0, 0 };
	int mostHighestCount = 0, mostHighItem;

	// Count the number of days each item had the highest sales
	for (int j = 0; j < NUMOFDAYS; j++) {
		int dayHighest = 0, itemHigh;
		for (int i = 0; i < NUMOFITEMS; i++) {
			if (dayHighest < numSold[i][j]) {
				dayHighest = numSold[i][j];
				itemHigh = i;
			}
		}
		itemCount[itemHigh]++;
	}
	
	for (int i = 0; i < NUMOFITEMS; i++) {
		if (mostHighestCount < itemCount[i]) {
			mostHighestCount = itemCount[i];
			mostHighItem = i;
		}
	}
	cout << "\nItem " << itemType[mostHighItem] << " had the most days with the highest sales, " << mostHighestCount << " days!\n\n";
	return;
}