#include <iostream>
#include <iomanip>
#include "SalaryEmployee.h"

SalaryEmployee::SalaryEmployee(int empID, std::string empNm, double yrSal)
    : Employee(empID, empNm) {
    setYearSal(yrSal);
}

double SalaryEmployee::getYearSal() const {
    return yearSal;
}

void SalaryEmployee::setYearSal(double yrSal) {
    yearSal = yrSal;
}

void SalaryEmployee::printPay() {
    std::cout << "The pay for the salaried employee " << getEmpName() << " with ID number " << getEmpID()
        << " is $" << std::fixed << std::setprecision(2) << getYearSal() / 52;
}