#include <iostream>
#include <iomanip>
#include "StipenedEmployee.h"

StipenedEmployee::StipenedEmployee(int empID, std::string empNm, double totPaid, double totHours)
    : Employee(empID, empNm) {
    setHoursSpent(totHours);
    setTotalPaid(totPaid);
}

double StipenedEmployee::getHoursSpent() const {
    return hoursSpent;
}

double StipenedEmployee::getTotalPaid() const {
    return totalPaid;
}

void StipenedEmployee::setHoursSpent(double hrsSpent) {
    hoursSpent = hrsSpent;
}

void StipenedEmployee::setTotalPaid(double totPaid) {
    totalPaid = totPaid;
}

void StipenedEmployee::printPay() {
    std::cout << "The pay for the stipend employee " << getEmpName() << " with ID number " << getEmpID()
        << " is $" << std::fixed << std::setprecision(2) << getTotalPaid() / (getHoursSpent() / 40);
}