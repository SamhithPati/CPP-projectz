#include "Employee.h"

// Constructor for base class
Employee::Employee(int id, std::string name) : employeeID(id), employeeName(name) {}

// Accessors
int Employee::getEmpID() const {
	return employeeID;
}

std::string Employee::getEmpName() const {
	return employeeName;
}

// Mutators
void Employee::setEmpID(int id) {
	employeeID = id;
}

void Employee::setEmpName(std::string name) {
	employeeName = name;
}