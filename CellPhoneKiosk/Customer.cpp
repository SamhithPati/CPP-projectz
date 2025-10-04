#include "Customer.h"
#include "Cellphone.h"
#include <string>
#include <array>

using namespace std;

string Customer::getCustName() const {
	return custName;
}

int Customer::getPhonesPurchased() const {
	return phonesPurchased;
}

double Customer::getTotalCost() const {
	return totalCost;
}

Cellphone* getPhones() const {
	return phones;
}

void Customer::setCustName(string cuName) {
	custName = cuName;
}

void Customer::setPhonesPurchased(int numPhones) {
	if (numPhones < MIN_PHONES) {
		throw phonesLow();
	}
	else if (numPhones > MAX_PHONES) {
		throw phonesHigh();
	}
	else {
		phonesPurchased = numPhones;
	}
}

void setPhones(Cellphone* cPhones) {
	phones = cPhones;
}

void Customer::calcTotalCost() {
	double cost = phonesPurchased * CELL_COST;
	totalCost = cost + (cost * SALES_TAX); 
}

Customer::Customer() {
	setCustName("none");
	setPhonesPurchased(0);
	totalCost = 0.0;
}

Customer::Customer(string cuName, int numPhones, Cellphone* cPhones) {
	setCustName(cuName);
	setPhonesPurchased(numPhones);
	setPhones(cPhones);
	calcTotalCost();
}