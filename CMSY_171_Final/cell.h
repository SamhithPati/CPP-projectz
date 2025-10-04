//DO NOT MAKE ANY CHANGES TO THIS FILE
#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const double APPLE = 1199.99;
const double SAM = 699.99;
const double LG = 499.99;
const double OTHER = 299.99;
const double TAX = 0.06;

class Cell
{
private:
	string model;
	int numPhone;
	double cost;

public:
	Cell();
	Cell(string);
	void setModel(string);
	void setPhone(int);
	void addPhone();
	string getModel() ;
	int getPhone() ;
	double getCost();
	double calcCost(string, int);
	friend ostream& operator << (ostream& out,  Cell& cell);
};
#endif