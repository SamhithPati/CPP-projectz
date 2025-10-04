// Samhith Patibandla
// 10/13/2023
// This program allows the user to browse and purchase a variety of items, including printer ink cartridges, backpacks, printer paper, and folders. 
// The program also calculates the subtotal for each item purchased, as well as the grand total, sales tax, and total due.

// standand libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void showCopyright(); //prototype for program title, copyright, and intro
int getUserchoice();
int getQty(string itemLbl1); //Protype for quantity
int getSubchoice(); //Protype for printer paper subchoice
void finalOutput();
bool getExitConfirm();
void doTotal(double subtotal1, double subtotal2, double subtotal3, double subtotal4, bool discInk);

double totalDisc = 0;

int main() {

    // Declare variables to store the user's choice and quantity.
    int itemQty, subchoice = 0, userChoice;
    bool valChoice, valExit, inkDiscount = false;
    string itemLbl1, bpCoupon;
    int cartridgeQty = 0, backpackQty = 0, paperQty1 = 0, paperQty2 = 0, folderQty = 0;

    // Declare constants for the menu items and their prices.
    const double inkcost = 41.25, backPackcost = 37.50, printReamcost = 6.00, printCasecost = 34.50;
    const double packDisc = 33.75, sQty = 0.69, mQty = 0.59, lQty = 0.49;
    double cartridgeTotal = 0, backpackTotal = 0, paperTotal = 0, folderTotal = 0, bpCost = 0, folderCost, bpDisc = 0, foldDisc = 0;
    const string couponCode = "disc back"; 

    // Declare variables to store the item label, cost, and total cost.
    bool orderAgain = true, plattOrder = false, valCoup, discFlagPP = false;

    showCopyright();

    do { //Repeat until exit
        valExit = false;
        do { //User Choice validation
            userChoice = getUserchoice();
            valChoice = true;
            switch (userChoice) {
            case 1:
                itemLbl1 = " printer ink cartriges ";
                break;
            case 2:
                itemLbl1 = " backpacks ";
                break;
            case 3:
                itemLbl1 = " print papers ";
                subchoice = getSubchoice();
                switch (subchoice) {
                case 1:
                    // itemCost = printReam;
                    itemLbl1 = " reams of printer paper ";
                    break;
                case 2:
                    // itemCost = printCase;
                    itemLbl1 = " cases of printer paper ";
                    break;
                }
                break;
            case 4:
                itemLbl1 = " Folders ";
                break;
            case 5:
                valExit = getExitConfirm(); //Calling exit function
                if (!valExit) {
                    continue;
                }
                else {
                    goto endrepeat;
                }
                break;
            default:
                cout << "\nSorry, we do not sell that item.\n"; 
                cout << "Please make another seletion\n\n";
                valChoice = false;
                break;
            }
        } while (!valChoice);
        if (userChoice == 5) {
            continue;
        }

        itemQty = getQty(itemLbl1);

        switch (userChoice) {
        case 1:
            cartridgeQty = cartridgeQty + itemQty;
            cartridgeTotal = cartridgeQty * inkcost;
            itemLbl1 = "printer ink";
            // Display the subtotal for printer ink cartriges
            cout << "\tThe subtotal for " << itemLbl1 << " is: $" << fixed << setprecision(2) << cartridgeTotal << endl << endl;
            break;
        case 2:
            backpackQty = backpackQty + itemQty;
            cin.ignore(); //clear one or more characters from the input buffer
            do {
                valCoup = true;
                cout << "\tPlease enter in a coupon code or NONE ";
                getline(cin, bpCoupon);

                if (bpCoupon == couponCode) {
                    bpCost = packDisc;
                    cout << "\tValid code entered.\n";
                }
                else if (bpCoupon == "NONE") {
                    bpCost = backPackcost;
                }
                else {
                    cout << "Error - Invalid coupon code. Please enter a valid coupon code or NONE. \n";
                    valCoup = false;
                }
            } while (!valCoup);

            bpDisc = ((backPackcost - bpCost) * backpackQty);
            backpackTotal = backpackQty * bpCost;
            // Display the subtotal for backpack
            cout << "\tThe subtotal for" << itemLbl1 << "is: $" << fixed << setprecision(2) << backpackTotal << endl << endl;

            break;
        case 3:
            switch (subchoice) {
            case 1:
                paperQty1 = paperQty1 + itemQty;

                break;
            case 2:
                paperQty2 = paperQty2 + itemQty;
                break;
            }
            paperTotal = (paperQty1 * printReamcost) + (paperQty2 * printCasecost);
            itemLbl1 = "the printer paper";
            // Display the subtotal for printer paper
            cout << "\tThe subtotal for " << itemLbl1 << " is: $" << fixed << setprecision(2) << paperTotal << endl << endl;
            break;
        case 4:
            folderQty = folderQty + itemQty;
            switch (folderQty) {
            case 1: case 2: case 3: case 4: case 5:
                folderCost = sQty;
                break;
            case 6: case 7: case 8: case 9: case 10:
                folderCost = mQty;
                break;
            default:
                folderCost = lQty;
                break;
            }
            foldDisc = (sQty - folderCost) * folderQty;
            folderTotal = folderQty * folderCost;
            itemLbl1 = "the folders";
            // Display the subtotal for folders
            cout << "\tThe subtotal for " << itemLbl1 << " is: $" << fixed << setprecision(2) << folderTotal << endl << endl;
            break;     
        default:
            cout << "\nError - Not valid. Please enter valid choice\n";
            valChoice = false;
            break;
        }
   // nextiter:

    } while (!valExit);

endrepeat:
    totalDisc = bpDisc + foldDisc;
    //Subtotal Calculations
    if (cartridgeQty >= 4) {
        inkDiscount = true;
    }

    doTotal(cartridgeTotal, backpackTotal, paperTotal, folderTotal, inkDiscount);


    system("pause");
    return 0;

 }// end main function

  
// Function to display copyright, intro & Welcome Meesg
void showCopyright() {

    cout << "Lab 3 - Function - Returns\n";
    cout << "Copyright - 2022 Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";
    cout << "\tWelcome to CMSY-141 Books and Supplies.\n";
    cout << "\t\tSamhith Patibandla, Owner\n\n";

} // end showCopyright function

// Function for displaaying menu and getting user choice
int getUserchoice() {
    int choice;

    //Display menu options
    cout << "\nOur inventory: \n";
    cout << setw(19) << "1. Printer Ink\n";
    cout << setw(17) << "2. Backpacks\n";
    cout << setw(21) << "3. Printer Paper\n";
    cout << setw(15) << "4. Folders\n";
    cout << setw(16) << "5. Checkout\n";

    // Prompt the user to enter a choice from the menu.
    cout << "Please make a selection: ";
    cin >> choice;

    return choice;
}//end getUserchoice function

// Function for getting Quantity from user and validating it
int getQty(string itemLbl1) {
    bool valQty;
    int quantity;
    // Validate the quantity entered by the user.
    do {
        // Prompt the user to enter the quantity of the item.
        cout << "\n\tHow many" << itemLbl1 << "would you like to buy? ";
        cin >> quantity;
        valQty = true;
        if (quantity <= 0) {
            cout << "Error - invalid number of" << itemLbl1 << "entered. Please enter a number greater than zero!\n\n";
            valQty = false;
        }//end if
    } while (!valQty);
    return quantity;
}//end getQty function

//Function to get Subchoice for Printer paper and Validate it
int getSubchoice() {
    bool valSubchoice;
    int subchoice;
    do {
        valSubchoice = true;
        cout << "\nHow would you like to buy your printer paper?\n";
        cout << setw(12) << "1. Ream\n";
        cout << setw(12) << "2. Case\n";
        cout << "Please enter your choice: ";
        cin >> subchoice;

        if (subchoice <= 0 || subchoice > 2) {
            cout << "\nError - Not valid.Please enter valid choice\n";
            valSubchoice = false;
        }//end if
    } while (!valSubchoice);
    return subchoice;
}//end getSubcoice function

void doTotal(double subtotal1, double subtotal2, double subtotal3, double subtotal4, bool diskInk) {
    double grandTotal;
    const double salesTax = 0.06;
    if (diskInk) {
        subtotal3 = 0.5 * subtotal3;
        totalDisc = totalDisc + subtotal3;
    }
    if (totalDisc > 0) {
        cout << "\nThe total discount is: $" << totalDisc << endl << endl;
    }
    grandTotal = subtotal1 + subtotal2 + subtotal3 + subtotal4;
    cout << "\nThe grand total is: $" << fixed << setprecision(2) << grandTotal << endl;
    double taxAmount = salesTax * grandTotal;
    cout << "The sales tax is: $" << fixed << setprecision(2) << taxAmount << endl;
    grandTotal = grandTotal + taxAmount;
    cout << "The total dude is: $" << fixed << setprecision(2) << grandTotal << endl << endl;
    cout << "Thank you for ordering from CSMY-141 Book and Supplies. Please come again.\n\n";

}

//function to exit the program
bool getExitConfirm() {
    bool confirmation, valconfirm;
    char userResp;
    do {
        valconfirm = true;
        cout << "Do you want to exit the program(y/n): ";
        cin >> userResp;
        userResp = tolower(userResp);

        if (userResp == 'y') {
            confirmation = true;
        }
        else if (userResp == 'n') {
            confirmation = false;
        }
        else {
            valconfirm = false;
            cout << "\n\nError - please enter in either y or n\n\n\n";
        }
    } while (!valconfirm);
    return confirmation;
}

