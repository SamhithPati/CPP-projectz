#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Cellphone.h"
#include <string>
using namespace std;

class Cellphone
{
private:
	string cellId;
	string cellNum;

public:
	// Mutators
	void setCellID(string);
	void setCellNum(string);
	
	// Accessors
	string getCellID() const;
	string getCellNum() const;

	// Constructors
	Cellphone();
	Cellphone(string, string);
};

#endif