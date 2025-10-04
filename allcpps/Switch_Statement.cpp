// Samhith Patibandla
// 09/22/2023
// This program demonstrates the use of a switch statement to calculate the cost of an order at a food kiosk.

// standand libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Declare variables to store the user's choice and quantity.
    int choice, quantity;

    // Declare constants for the menu items and their prices.
    const double sandCost = 3.50, fryCost = 2.50, plattCost = 5.00;
    const double sandDisc = 2.75, fryDisc = 1.75, plattDisc = 4.25, inval = 0.00;
    const string menu1 = "sandwiches", menu2 = "french fries", menu3 = "platters";

    // Declare variables to store the item label, cost, and total cost.
    string itemLbl, itemLbl1, itemLbl2;
    double itemCost, totalCost;


    // Displays header with Welcome message and display the menu.
    cout << "CE - Switch Statment\n";
    cout << "Copyright ©2021 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";
    cout << "Welcome to the Mall Food Kiosk. Here is our menu.\n";

    cout << setw(16) << "1. Sandwich\n";
    cout << setw(20) << "2. French Fries\n";
    cout << setw(15) << "3. Platter\n";
    cout << setw(16) << "4. Checkout\n";

    // Prompt the user to enter a choice from the menu.
    cout << "Please enter the item to purchace from the menu above: ";
    cin >> choice;

    // Use a switch statement to determine the item label and cost.
    switch (choice) {
    case 1:
        itemLbl = menu1;
        itemLbl1 = "sandwich";
        itemLbl2 = "sandwich(es)";
        break;

    case 2:
        itemLbl = menu2;
        itemLbl1 = "order of french fries";
        itemLbl2 = "order(s) of french fries";
        break;

    case 3:
        itemLbl = menu3;
        itemLbl1 = menu3;
        itemLbl2 = "platter(s)";
        break;

    case 4:
        cout << "Thank you for the your business. Please come again.\n\n";
        goto endexec;

    default:
        cout << "Error - this is an invalid entry. Please try again.\n\n";
        goto endexec;
    }

    // Prompt the user to enter the quantity of the item.
    cout << "Please enter the number of " << itemLbl << " you wish to buy: ";
    cin >> quantity;

    // Validate the quantity entered by the user.
    if (quantity < 0) {
        cout << "Error - this is an invalid number of items.  Please try again.\n\n";
        itemCost = inval;
        goto calc;
    }

    
    switch (choice) {
    case 1:
        itemCost = (quantity < 4) ? sandCost : sandDisc;
        break;

    case 2:
        itemCost = (quantity < 4) ? fryCost : fryDisc;
        break;

    case 3:
        itemCost = (quantity < 4) ? plattCost : plattDisc;
        break;

    }

calc:
    // Calculate the total cost of the order.
    totalCost = abs (quantity * itemCost);

    // Display the cost of a single item and the total cost of the order.
    cout << "The cost of a single " << itemLbl1 << " is: $" << fixed << setprecision(2) << itemCost << endl;
    cout << "The cost of " << quantity << " " << itemLbl2 << " is: $" << totalCost << endl << endl;

   
endexec:
    // Pause the program before exiting.
    system("pause");
    return 0;
}

        