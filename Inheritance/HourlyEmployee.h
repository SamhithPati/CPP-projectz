#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h" // Include base class header

using namespace std;

class HourlyEmployee : public Employee {
private:
    double hoursWorked;
    double payRate;

public:
    // Constructor in derived class
    HourlyEmployee(int id, string name, double hours, double rate);

    // Accessors
    double getHoursWorked() const;
    double getPayRate() const;

    // Mutators
    void setHoursWorked(double hours);
    void setPayRate(double rate);

    // Overridden virtual function
    void printPay() override;

    virtual ~HourlyEmployee() {} // Virtual destructor
};

#endif // HOURLYEMPLOYEE_H