// Samhith Patibandla
// 10/02/2023
// This program demonstrates the Do While loop for books and supplies store. The user can select items from the menu, enter the
// quantity, and the program will calculate the total cost. 

// standand libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Declare variables to store the user's choice and quantity.
    int choice, quantity = 0, subchoice;

    // Declare constants for the menu items and their prices.
    const double printInk = 41.25, backPack = 37.50, printReam = 6.00, printCase = 34.50;
    const double packDisc = 33.75 , salesTax = 0.06, sQty = 0.69, mQty = 0.59, lQty = 0.49;
    const string item1 = " printer ink cartriges ", item2 = " backpacks ";
    const string item3 = " printer paper ", item4 = " folders ", couponCode = "disc back";


    // Declare variables to store the item label, cost, and total cost.
    string itemLbl, itemLbl1, itemLbl2, itemLbl3, bpCoupon;
    double itemCost = 0, totalCost = 3, grandTotal = 0.00, taxAmount, totalDue, discountAmount = 0;
    bool valQty, valChoice, orderAgain = true, plattOrder = false, valCoup, discFlagPP = false, valSubchoice;

    // Displays header.
    cout << "Lab 2 - Decision Making and Loops\n";
    cout << "Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";
    cout << "Welcome to CMSY-141 Books and Supplies.\n";
    cout << "\tSamhith Patibandla, Owner\n\n";


    do {
        
        cout << "Our inventory: \n";
        valChoice = true;
        cout << setw(19) << "1. Printer Ink\n";
        cout << setw(17) << "2. Backpacks\n";
        cout << setw(21) << "3. Printer Paper\n";
        cout << setw(15) << "4. Folders\n";
        cout << setw(16) << "5. Checkout\n";

        // Prompt the user to enter a choice from the menu.
        cout << "Please make a selection: ";
        cin >> choice;

        // Use a switch statement to determine the item label and cost.
        switch (choice) {
        case 1:
            itemLbl = item1;
            itemLbl1 = " printer ink cartriges ";
            itemLbl2 = " printer ink ";
            break;

        case 2:
            itemLbl = item2;
            itemLbl1 = " backpacks ";
            itemLbl2 = " backpack ";
            break;

        case 3:
            itemLbl = item3;

            do {
                valSubchoice = true;
                cout << "\nHow would you like to buy your printer paper?\n";
                cout << setw(12) << "1. Ream\n";
                cout << setw(12) << "2. Case\n";
                cout << "Please enter your choice: ";
                cin >> subchoice;

                switch (subchoice) {
                case 1:
                    itemCost = printReam;
                    itemLbl1 = " reams of printer paper ";
                    break;
                case 2:
                    itemCost = printCase;
                    itemLbl1 = " cases of printer paper ";
                    break;
                default:
                    cout << "\nError - Not valid. Please enter valid choice. \n";
                    valSubchoice = false;
                    break;
                }
            } while (!valSubchoice);

            itemLbl2 = " the printer paper ";
            break;

        case 4:
            itemLbl = item4;
            itemLbl1 = " Folders ";
            itemLbl2 = " Folders ";
            break;

        case 5:
            orderAgain = false;
            goto checkout;

        default:
            cout << "\n\nSorry, we do not sell that item.\n";
            cout << "Please make another selection.\n\n";
            continue;
            //valChoice = false;
        }


        // Validate the quantity entered by the user.
        do {
            // Prompt the user to enter the quantity of the item.
            cout << "\n\tHow many" << itemLbl1 << "would you like to buy? ";
            cin >> quantity;
            valQty = true;
            if (quantity <= 0) {
                cout << "Error - invalid number of" << itemLbl1 << "entered. Please enter a number greater than zero!\n\n";
                valQty = false;
            }
        } while (!valQty);

        switch (choice) {
        case 1:
            itemCost = printInk;

            if (quantity >= 4) {
                discFlagPP = true;
            }
            break;

        case 2:           
            itemCost = backPack;

            do {
                valCoup = true;
                cout << "Please enter the coupon code. ";
                getline (cin, bpCoupon);
                cout << bpCoupon;

                if (bpCoupon == couponCode) {
                    itemCost = packDisc;
                    cout << "Valid code entered.\n";
                }
                else if (bpCoupon == "NONE") {
                    itemCost = backPack;
                }
                else {
                    cout << "Error - Invalid coupon code. Please enter a valid coupon code or NONE. \n";
                    valCoup = false;
                }
            } while (!valCoup);
            break;

        case 3:
            if (discFlagPP) {
                itemCost = itemCost * 0.50;
                discountAmount = itemCost;
            }
            break;

        case 4:
            switch (quantity) {
            case 1: case 2: case 3: case 4: case 5:
                itemCost = sQty;
                break;
            case 6: case 7: case 8: case 9: case 10:
                itemCost = mQty;
                break;

            default:
                itemCost = lQty;
                break;
            }
            break;
        }

        
        // Calculate the total cost of the order.
        totalCost = abs(quantity * itemCost);
        discountAmount = abs(quantity * discountAmount);
        

        // Display the cost of a single item and the total cost of the order.
        cout << "The subtotal for " << itemLbl2 << " is: $" << fixed << setprecision(2) << totalCost << endl << endl;

        grandTotal = grandTotal + totalCost;
    } while (orderAgain);


checkout:
    taxAmount = salesTax * grandTotal;
    totalDue = grandTotal + taxAmount;
    if (discountAmount > 0) {
        cout << "\n\n Your discount amount is $" << fixed << setprecision(2) << discountAmount << endl;
    }
    cout << "\nThe grand total is: $" << fixed << setprecision(2) << grandTotal << endl;
    cout << "The sales tax is: $" << fixed << setprecision(2) << taxAmount << endl;
    cout << "The total due is: $" << fixed << setprecision(2) << totalDue << endl;
    //cout << "The grand total is 11 $" << fixed << setprecision(2) << totalCost << endl;
    cout << "\nThank you for odering from CMSY-141 Books and Supplies. Please come again.\n\n";


    // Pause the program before exiting.
    system("pause");
    return 0;
}

