#include <iostream>
#include "Cell.h"

/* constructor */
Cell::Cell(string i, string p)
{
	idNumber = i;
	phoneNumber = p;
}
/* constructor */
Cell::Cell()
{
	idNumber = "none";
	phoneNumber = "none";
}

void Cell::setId(string i)
{
	idNumber = i;
}

void Cell::setPhone(string p)
{
	phoneNumber = p;
}

string Cell::getId()
{
	return idNumber;
}

string Cell::getPhone()
{
	return phoneNumber;
}
