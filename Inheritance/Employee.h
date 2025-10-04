#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
	int employeeID;
	string employeeName;

public:
	// Constructor for base class
	Employee(int id, string name);

	// Accessors
	int getEmpID() const;
	string getEmpName() const;

	// Mutators
	void setEmpID(int id);
	void setEmpName(string name);

	// Pure Virtual Function
	virtual void printPay() = 0;
	virtual ~Employee() {} // Virtual destructor
};

#endif // EMPLOYEE_H