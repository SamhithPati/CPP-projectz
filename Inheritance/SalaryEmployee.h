#ifndef SALARYEMPLOYEE_H
#define SALARYEMPLOYEE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h" // Include base class header

class SalaryEmployee : public Employee {
private:
    double yearSal;

public:
    // Constructor
    SalaryEmployee(int id, std::string name, double salary);

    // Accessors
    double getYearSal() const;

    // Mutators
    void setYearSal(double salary);

    // Overridden function
    void printPay() override;

    virtual ~SalaryEmployee() {} // Virtual destructor
};

#endif // SALARYEMPLOYEE_H