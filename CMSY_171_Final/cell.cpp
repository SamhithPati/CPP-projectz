#include <iostream>
#include <iomanip>
#include "Cell.h"

/* constructor */
Cell::Cell(string s)
{
	model = s;
	numPhone = 1;
}
/* constructor */
Cell::Cell()
{
	model = "none";
	numPhone = 0;
}

void Cell::setModel(string i)
{
	model = i;
}

void Cell::setPhone(int i)
{
	numPhone = i;
}

string Cell::getModel() 
{
	return model;
}

int Cell::getPhone() 
{
	return numPhone;
}

void Cell::addPhone()
{
	numPhone++;
}

double Cell::getCost() 
{
	return (calcCost(model, numPhone));
}

double Cell::calcCost(string s, int i)
{
	//Calculate the code based on the model, the appropriate constants and the number of phones
	double total, tax;

	//TO DO - write the code to calculate the total cost of the cellphones (with tax) for each individual model
	double basePrice;

	// Determine the base price based on the model
	if (model == "Apple") {
		basePrice = APPLE;
	}
	else if (model == "Samsung") {
		basePrice = SAM;
	}
	else if (model == "LG") {
		basePrice = LG;
	}
	else {
		basePrice = OTHER;
	}

	// Calculate the total cost before tax
	double totalCostBeforeTax = basePrice * i;

	// Calculate the tax amount
	tax = totalCostBeforeTax * TAX;

	// Calculate the total cost including tax
	total = totalCostBeforeTax + tax;

	return total;
}

ostream& operator << (ostream& out, Cell& cell)
{
	//Create the output stream that matches the screen shot. The code MUST use iomanipulation functions.  Do NOT use \t or blank spaces.

	//TO DO - write the out statement to display the output to the as seen in the screen shot
	out << left << setw(6) << "Model" << setw(16) << cell.getModel() << setw(5) << "sold" << setw(3) << cell.getPhone() << setw(23) << "unit(s) for a cost of $" << fixed << setprecision(2) << cell.getCost() << endl;
	return out;
}