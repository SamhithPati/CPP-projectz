// Samhith Patibandla
// 09/29/2023
// This program demonstrates the Do While loop for a mall food kiosk. The user can select items from the menu, enter the
// quantity, and the program will calculate the total cost. 

// standand libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Declare variables to store the user's choice and quantity.
    int choice, quantity = 0;

    // Declare constants for the menu items and their prices.
    const double sandCost = 3.50, fryCost = 2.50, plattCost = 5.00, bevCost = 1.50;
    const double sandDisc = 2.75, fryDisc = 1.75, plattDisc = 4.25, inval = 0.00, bevDisc = 1.00;
    const string menu1 = "sandwiches", menu2 = "french fries", menu3 = "platters", menu4 = "beverages";

    // Declare variables to store the item label, cost, and total cost.
    string itemLbl, itemLbl1, itemLbl2, itemLbl3;
    double itemCost = 0, totalCost = 3, grandTotal = 0.00;
    bool valQty, valChoice, orderAgain = true, plattOrder = false;

    // Displays header.
    cout << "CE - Loops\n";
    cout << "Copyright ©2021 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";


    do {
        cout << "Welcome to the Mall Food Kiosk. Here is our menu.\n";
        valChoice = true;
        cout << setw(16) << "1. Sandwich\n";
        cout << setw(20) << "2. French Fries\n";
        cout << setw(15) << "3. Platter\n";
        cout << setw(16) << "4. Beverage\n";
        cout << setw(16) << "5. Checkout\n";

        // Prompt the user to enter a choice from the menu.
        cout << "Please enter the item to purchace from the menu above: ";
        cin >> choice;

        // Use a switch statement to determine the item label and cost.
        switch (choice) {
        case 1:
            itemLbl = menu1;
            itemLbl1 = "sandwich";
            itemLbl2 = "sandwich(es)";
            itemLbl3 = "sandwiches";
            break;

        case 2:
            itemLbl = menu2;
            itemLbl1 = "order of french fries";
            itemLbl2 = "order(s) of french fries";
            itemLbl3 = "orders of french fries";
            break;

        case 3:
            itemLbl = menu3;
            itemLbl1 = menu3;
            itemLbl2 = "platter(s)";
            itemLbl3 = "platters";
            plattOrder = true;
            break;

        case 4:
            itemLbl = menu4;
            itemLbl1 = menu4;
            itemLbl2 = "beverage(s)";
            itemLbl3 = "beverages";
            break;

        case 5:
            orderAgain = false;
            goto endexec;

        default:
            cout << "Error - this is not a valid option. Please try again.\n\n";
            valChoice = false;
            continue;
        }


        // Validate the quantity entered by the user.
        do {
            // Prompt the user to enter the quantity of the item.
            cout << "Please enter the number of " << itemLbl << " you wish to buy: ";
            cin >> quantity;
            valQty = true;
            if (quantity <= 0) {
                cout << "Error - the number of " << itemLbl3 << " must be greater than 0. Please reenter.\n\n";
                valQty = false;
            }
        } while (!valQty);

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

        case 4:
            itemCost = bevCost;
            itemCost = (plattOrder) ? bevDisc : bevCost;
            break;
        }

        // Calculate the total cost of the order.
        totalCost = abs(quantity * itemCost);

        // Display the cost of a single item and the total cost of the order.
        cout << "The cost of a single " << itemLbl1 << " is: $" << fixed << setprecision(2) << itemCost << endl;
        cout << "The cost of " << quantity << " " << itemLbl2 << " is: $" << totalCost << endl << endl;

        grandTotal = grandTotal + totalCost;


    } while (orderAgain);

endexec:
    cout << "The grand total is $" << fixed << setprecision(2) << grandTotal << endl;
    cout << "Thank you for your business. Please come again.\n\n";


    // Pause the program before exiting.
    system("pause");
    return 0;
}

