// Samhith Patibandla
// 09/20/2023
// This program allows the user to purchase either sandwiches or french fries only. Fror any other item entered d.isplays error message
// The program calculates the total cost of the order based on the number of items purchased and the price per item. 
// If the Quantity is less than zero it displays error message.

//standard Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	// Print a header message.
	cout << "CE - Decision Making\n";
	cout << "Copyright ©2021 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";

	// Declaration of variables.
	string itemName;
	int quantity;
	const int invalQty = 0, invalCost = 0;
	const double sandCost = 3.50;
	const double sandDisc = 2.75;
	const double FryCost = 2.50;
	const double FryDisc = 1.75;
	double orderTotal;
	double itemCost;
	
	// Prompts the user to enter the item to purchase.
	cout << "Please enter the item to purchase (sandwich or french fries): ";
	getline(cin, itemName);

	// Validate the user input.
	if (itemName != "sandwich" && itemName != "french fries") {
		cout << "Error - this is not a valid option. Please try again.\n\n";
	}
	else {
		// Determine the labels for the item.
		string itemLabel = (itemName == "sandwich") ? "sandwiches" : itemName;
		// Determine the output labels for the item.
		string itemOutLbl1 = (itemName == "sandwich") ? itemName : "order of french fries";
		string itemOutLbl2 = (itemName == "sandwich") ? "sandwich(es)" : "order(s) of french fries";

		// Prompts the user to enter the quantity of the item.
		cout << "Please enter the number of " << itemLabel << " you wish to buy: ";
		cin >> quantity;

		// Validate the user input.
		int ordQty = quantity;
		if (quantity < 0) {
			cout << "Error - this is an invalid number of items. Please try again.\n\n";
			ordQty = invalQty;
			itemCost = invalCost;
		}
		else {
			// Calculate the price of the item based on the quantity purchased.
			if (ordQty < 4) {
				if (itemName == "sandwich") {
					itemCost = sandCost;
				}
				else {
					itemCost = FryCost;
				} 
			} 
			else {
				if (itemName == "sandwich") {
					itemCost = sandDisc;
				}
				else {
					itemCost = FryDisc;
				} 
			}  

		} 

		// Calculate the total cost of the order.
		orderTotal = ordQty * itemCost;

		// Print the cost of a single item and the total cost of the order.
		cout << "The cost of a single " << itemOutLbl1 << " is: $" << fixed << setprecision(2) << itemCost << endl;
		cout << "The cost of " << quantity << " " << itemOutLbl2 << " is: $" << orderTotal << endl << endl;
	}
	
	//Prints a Goodbye Message.
	cout << "Thanks for your moneyzz!!\n\n";

	// Pause the program.
	system("pause");
	return 0;
}


