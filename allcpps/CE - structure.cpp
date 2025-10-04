// Samhith Patibandla
// 11/18/2023
// This program calculates and displays the inventory and reorder information for a beverage kiosk.

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// Constants for sales tax rate, wholesale price, beverage name size, and minimum inventory amount
const double SALES_TAX_RATE = 0.06;
const double WHOLESALE_PRICE = 0.73;
const int BEVERAGE_NAME_SIZE = 50;
const int MIN_INVENTORY_AMOUNT = 24;

// Structure to represent a beverage
struct Beverage {
    char name[BEVERAGE_NAME_SIZE];
    int numInInventory;
    double inventoryValue;
    bool mustReorder;
};

// Prototype functions
void showCopyright();
void collectBeverageData(Beverage* beverages, int numBeverages);
void displayInventoryReport(Beverage* beverages, int numBeverages);
double calculateReorderCost(int numToOrder);

int main() {
    // Display copyright and program introduction
    showCopyright();

    // Ask the user for the number of beverages
    int numBeverages;
    cout << "\nPlease enter the number of beverages: ";
    cin >> numBeverages;

    // Dynamically allocate an array for beverages
    Beverage* beverages = new Beverage[numBeverages];

    // Collect beverage data from the user
    collectBeverageData(beverages, numBeverages);

    // Display the inventory report
    displayInventoryReport(beverages, numBeverages);

    // Deallocate the dynamic array
    delete[] beverages;

    cout << "\nThank you for using the CMSY-141 Beverage Inventory Calculator program. Goodbye!\n\n";

    // Pause the system before closing the console window
    system("pause");
    return 0;
}

// Function to display copyright information and program introduction
void showCopyright() {
    cout << "CE - Structures\n";
    cout << "Copyright ©2021 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\tWelcome to the CMSY-141 Beverage Inventory Calculator\n";
}

// Function to collect beverage data from the user
void collectBeverageData(Beverage* beverages, int numBeverages) {
    for (int i = 0; i < numBeverages; ++i) {
        // Ask for the name of the beverage
        cout << "\nPlease enter the beverage name: ";
        cin.ignore(); // Ignore the newline character in the input buffer
        cin.getline(beverages[i].name, BEVERAGE_NAME_SIZE);

        // Ask for the number of bottles in inventory
        do {
            cout << "Please enter the number of bottles in inventory for " << beverages[i].name << ": ";
            cin >> beverages[i].numInInventory;

            // Validate input for a non-negative value
            if (beverages[i].numInInventory < 0) {
                cout << "Invalid value. Please enter a valid non-negative value.\n";
            }
        } while (beverages[i].numInInventory < 0);

        // Calculate the cost of inventory and determine if reorder is necessary
        beverages[i].inventoryValue = beverages[i].numInInventory * WHOLESALE_PRICE;
        beverages[i].mustReorder = (beverages[i].numInInventory < MIN_INVENTORY_AMOUNT);
    }
}

// Function to display the inventory report
void displayInventoryReport(Beverage* beverages, int numBeverages) {
    cout << "\nBeverage Inventory Calculator";
    cout << "\n\tInventory Report\n";
    for (int i = 0; i < numBeverages; ++i) {
        cout << "\n\tBeverage Name: " << beverages[i].name << endl;
        cout << "\tNumber in Inventory: " << beverages[i].numInInventory << endl;
        cout << "\tValue of Inventory: $" << beverages[i].inventoryValue << endl;

        // Check if reorder is necessary
        if (!beverages[i].mustReorder) {
            cout << "\tInventory is greater than a case. No need to order additional " << beverages[i].name;
        }
        else {
            cout << "\tWarning: Inventory is below one case.\n";
            int shortAmount = MIN_INVENTORY_AMOUNT - beverages[i].numInInventory;
            double reorderCost = calculateReorderCost(shortAmount);
            cout << "\tYou must order " << shortAmount << " more " << beverages[i].name << endl;
            cout << "\tThe cost with tax will be: $" << fixed << setprecision(2) << reorderCost << endl;
        }

        cout << endl;
    }
}

// Function to calculate the reorder cost including sales tax
double calculateReorderCost(int numToOrder) {
    // Calculate the cost before tax
    double costBeforeTax = numToOrder * WHOLESALE_PRICE;
    // Calculate sales tax
    double salesTax = costBeforeTax * SALES_TAX_RATE;
    // Calculate total cost including sales tax
    double totalCost = costBeforeTax + salesTax;
    return totalCost;
}