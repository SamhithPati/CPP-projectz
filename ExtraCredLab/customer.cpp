#include <iostream>
#include "Customer.h"

/* constructor */
Customer::Customer(string na, int nu, Cell c[])
{
	custName = na;
	numPurchase = nu;
	totalCost = calcCost();
	for (int i = 0; i < nu; i++)
		phones[i] = c[i];
}
/* constructor */
Customer::Customer()
{
	custName = "none";
	numPurchase = 0;
	totalCost = 0;
	Cell e;
	phones[0] = e;
}

void Customer::setName(string na)
{
	custName = na;
}

void Customer::setNum(int num)
{
	numPurchase = num;
}

void Customer::addPhones(Cell c[])
{
	for (int i = 0; i < getNum(); i++)
		phones[i] = c[i];
}

string Customer::getName()
{
	return custName;
}

int Customer::getNum()
{
	return numPurchase;
}

double Customer::getCost()
{
	return totalCost;
}

Cell* Customer::getPhones()
{
	return phones;
}

double Customer::calcCost()
{
	double sub = getNum() * PRICE;
	double tax = sub * TAX;
	return (sub + tax);
}


//TO DO - Create an overloaded streaming operator for output of the Customer object.  This output should include all of the 
//data that exists in the Customer Class.  This must be done using nothing but calls to "get" methods. There should be no direct
//access to the private data elements. 
ostream& operator <<(ostream& out, Customer& cust) {
	out << "Customer Name: " << cust.getName() << endl;
	out << "Number of Purchases: " << cust.getNum() << endl;
	out << "Total Cost: $" << cust.getCost() << endl;
	return out;
}