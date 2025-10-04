#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include "cell.h"
using namespace std;

const int MAX = 6;
const double PRICE = 199.99;
const double TAX = 0.06;

class Customer
{
private:
	string custName;
	int numPurchase;
	double totalCost;
	Cell phones[MAX];

public:
	Customer();
	Customer(string, int, Cell[]);

	void setName(string);
	void setNum(int);
	double calcCost();
	void addPhones(Cell[]);

	string getName();
	int getNum();
	double getCost();
	Cell* getPhones();

	friend ostream& operator << (ostream& out, Customer& cust);
};
#endif