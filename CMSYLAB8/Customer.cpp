#include "Customer.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Default constructor
Customer::Customer() : name("none"), numPhonesPurchased(0), totalCost(0.0) {
    // Initialize phones array with default Cellphone objects
    for (int i = 0; i < 6; ++i) {
        phones[i] = Cellphone();
    }
}

// Constructor with parameters
Customer::Customer(std::string n, int num, Cellphone phoneArr[]) : name(n), numPhonesPurchased(num), totalCost(0.0) {
    // Copy phoneArr into phones array
    for (int i = 0; i < num; ++i) {
        phones[i] = phoneArr[i];
    }
    // Calculate total cost
    calculateTotalCost();
}

// Getter function for customer's name
std::string Customer::getName() const {
    return name;
}

// Getter function for number of phones purchased
int Customer::getNumPhonesPurchased() const {
    return numPhonesPurchased;
}

// Getter function for total cost
double Customer::getTotalCost() const {
    return totalCost;
}

// Setter function for customer's name
void Customer::setName(std::string n) {
    name = n;
}

// Setter function for number of phones purchased
void Customer::setNumPhonesPurchased(int num) {
    numPhonesPurchased = num;
}

// Function to calculate total cost
void Customer::calculateTotalCost() {
    totalCost = numPhonesPurchased * 199.99 * (1 + 0.06); // Each phone costs $199.99 and there is 6% sales tax
}

// Function to print customer receipt
void Customer::printReceipt() const {
    // Print customer information
    cout << "\nCustomer Receipt: \n";
    cout << "Customer Name    : " << name << endl;
    cout << "Number Phones    : " << numPhonesPurchased << endl;
    cout << "Total amount due : $" << fixed << setprecision(2) << totalCost << endl;
    cout << "\nPhone(s) id and number: " << endl;
    // Print information for each phone purchased
    for (int i = 0; i < numPhonesPurchased; ++i) {
        cout << "Id number: " << phones[i].getIdNumber() << "\tPhone Number: " << phones[i].getPhoneNumber() << endl;
    }
    cout << endl;
}
