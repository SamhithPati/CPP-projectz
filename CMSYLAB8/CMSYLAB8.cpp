// Samhith Patibandla
// 04/22/2024
// This program is point-of-sale program for a cellphone kiosk which and 
// uses a stack for the cell phone inventory and a queue for the customer purchases.

#include <iostream>
#include <fstream>
#include <stack>
#include <deque>
#include "Cellphone.h"
#include "Customer.h"

using namespace std;

// Constants
const string FILE_PATH = "C:\\test\\cellphone.txt";
const double SALES_TAX = 0.06;
const int MAX_PHONES_PER_CUSTOMER = 6;
const int MIN_PHONES = 1;
const string MENU_ONE = "1. Buy Phone", MENU_TWO = "2. Checkout Customer", MENU_THREE = "3. Quit";
const int CHOICE_ONE = 1, CHOICE_TWO = 2, CHOICE_THREE = 3;

// Prototypes
void progIntro();
void createStack(stack<Cellphone>&);
void buyPhone(stack<Cellphone>&, deque<Customer>&);
void checkoutCustomer(deque<Customer>&);

int main() {
    // Introduction
    progIntro();

    // Data structures
    stack<Cellphone> phoneStack;
    deque<Customer> customerQueue;

    // Read cellphone data from file
    createStack(phoneStack);

    // Menu loop
    int choice;
    while (true) {
        cout << endl << MENU_ONE << endl;
        cout << MENU_TWO << endl;
        cout << MENU_THREE << endl;
        cout << "\nEnter the menu choice: ";
        cin >> choice;

        switch (choice) {
        case CHOICE_ONE:
            buyPhone(phoneStack, customerQueue);
            break;
        case CHOICE_TWO:
            checkoutCustomer(customerQueue);
            break;
        case CHOICE_THREE:
            if (!customerQueue.empty()) {
                cout << "Error - there are still customers in the checkout queue!" << endl;
                cout << "Please return to main menu and checkout all of the customers!\n\n";
            }
            else {
                cout << "Thank you for using the cellphone kiosk program. Goodbye!" << endl;
                system("pause");
                return 0;
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            
        }
       
    }
    return 0;
}

// Function to display program introduction
void progIntro() {
    cout << "\t\t\t\tCMSY 171 Lab 8\n";
    cout << "Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\t\tWelcome to CMSY-171 Cell Phone Purchase Program\n\n";
}

// Function to read cellphone data from file and populate stack
void createStack(stack<Cellphone>& phoneStack) {
    ifstream file(FILE_PATH);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string id, number;
    while (file >> id >> number) {
        phoneStack.push(Cellphone(id, number));
    }

    file.close();
}

// Function to handle buying phones
void buyPhone(stack<Cellphone>& phoneStack, deque<Customer>& customerQueue) {
    if (phoneStack.empty()) {
        cout << "No phones available for purchase." << endl;
        return;
    }

    // Input customer name
    string name;
    int numPhones;
    bool valFlag = true;
    cin.ignore();
    cout << "Please enter in the customer name: ";
    getline(cin, name);

    // Validate and input number of phones to purchase
    do {
        valFlag = true;
        cout << "Please enter in the number of phones to purchase (" << MIN_PHONES << " - " << min(MAX_PHONES_PER_CUSTOMER, (int)phoneStack.size()) << "): ";
        cin >> numPhones;

        if (numPhones < MIN_PHONES || numPhones > min(MAX_PHONES_PER_CUSTOMER, (int)phoneStack.size())) {
            cout << "Error - you can only purchase " << MIN_PHONES << " - " << min(MAX_PHONES_PER_CUSTOMER, (int)phoneStack.size()) << " phones. Please reenter!" << endl << endl;
            valFlag = false;
        }
    } while (!valFlag);

    // Populating the array of purchased phones and creating a customer object
    Cellphone phoneArr[MAX_PHONES_PER_CUSTOMER];
    for (int i = 0; i < numPhones; ++i) {
        phoneArr[i] = phoneStack.top();
        phoneStack.pop();
    }

    Customer customer(name, numPhones, phoneArr);
    customerQueue.push_back(customer);
    
}

// Function to handle customer checkout
void checkoutCustomer(deque<Customer>& customerQueue) {
    if (customerQueue.empty()) {
        cout << "There are no customers left to checkout!" << endl << endl;
        return;
    }

    Customer customer = customerQueue.front();
    customer.printReceipt();
    customerQueue.pop_front();
}