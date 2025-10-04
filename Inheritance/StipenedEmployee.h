#ifndef STIPENEDEMPLOYEE_H
#define STIPENEDEMPLOYEE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h" // Include base class header

class StipenedEmployee : public Employee {
private:
    double hoursSpent;
    double totalPaid;

public:
    StipenedEmployee(int id, std::string name, double hours, double paid);

    // Accessors
    double getHoursSpent() const;
    double getTotalPaid() const;

    // Mutators
    void setHoursSpent(double hours);
    void setTotalPaid(double paid);

    // Overridden function
    void printPay() override;

    // Destructor
    virtual ~StipenedEmployee() {};
};

#endif // STIPENEDEMPLOYEE_H