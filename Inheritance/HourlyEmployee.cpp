#include <iostream>
#include <iomanip>
#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(int empID, std::string empNm, double hrsWorked, double payRt)
    : Employee(empID, empNm) {
    setHoursWorked(hrsWorked);
    setPayRate(payRt);
}

double HourlyEmployee::getHoursWorked() const {
    return hoursWorked;
}

double HourlyEmployee::getPayRate() const {
    return payRate;
}

void HourlyEmployee::setHoursWorked(double hrsWrkd) {
    hoursWorked = hrsWrkd;
}

void HourlyEmployee::setPayRate(double payRt) {
    payRate = payRt;
}

void HourlyEmployee::printPay() {
    std::cout << "The pay for the hourly employee " << getEmpName() << " with ID number " << getEmpID()
        << " is $" << std::fixed << std::setprecision(2) << getHoursWorked() * getPayRate();
}