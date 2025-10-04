#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Cellphone.h"

class Customer {
private:
    std::string name;                   // Private variable to hold the customer's name
    int numPhonesPurchased;             // Private variable to hold the number of phones purchased
    double totalCost;                   // Private variable to hold the total cost of the purchase
    Cellphone phones[6];                // Array of Cellphone objects 

public:
    // Constructors
    Customer();                                             // Default constructor
    Customer(std::string n, int num, Cellphone phoneArr[]); // Constructor with parameters

    // Getter functions
    std::string getName() const;                           // Get customer's name
    int getNumPhonesPurchased() const;                      // Get number of phones purchased
    double getTotalCost() const;                           // Get total cost

    // Setter functions
    void setName(std::string n);                           // Set customer's name
    void setNumPhonesPurchased(int num);                   // Set number of phones purchased

    // Other member functions
    void calculateTotalCost();                             // Calculate total cost
    void printReceipt() const;                             // Print customer receipt
};

#endif // CUSTOMER_H
