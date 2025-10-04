#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <array>
#include "Cellphone.h"

using namespace std;

// Global Constants
const double CELL_COST = 199.99;
const double SALES_TAX = 0.06;
const int MAX_PHONES = 6, MIN_PHONES = 1;

class Customer
{
private:
	string custName;
	int phonesPurchased;
	double totalCost;

	// Array of cellphones
	Cellphone phones[MAX_PHONES];

public:
	// Exception Classes
	class phonesLow {};
	class phonesHigh {};

	// Constructor
	Customer();
	Customer(string, int, Cellphone*);

	// Accessors
	string getCustName() const;
	int getPhonesPurchased() const;
	double getTotalCost() const;
	Cellphone* getPhones() const;

	// Mutators
	void setCustName(string);
	void setPhonesPurchased(int);
	void setPhones(Cellphone*);
	void calcTotalCost();

};

#endif // !CUSTOMER_H
