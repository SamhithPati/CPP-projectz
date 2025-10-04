// Samhith Patibandla
// 03/20/2024
// This program allows the user to manage a list of employees and their pay.

#include <iostream>
#include "Employee.h"
#include "SalaryEmployee.h"
#include "HourlyEmployee.h"
#include "StipenedEmployee.h"
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
void progIntro();
void getInput(vector<Employee*>& Ve);
void printList(const vector<Employee*>& Ve);
bool getExitConfirm();
bool validateEmpID(int);
bool validateDblNum(double);

int main()
{
    progIntro(); // Display program introduction

    vector<Employee*> Ve; // Vector to store employee objects
    getInput(Ve); // Get user input for employee data
    printList(Ve); // Print employee information

    // Clean up allocated memory
    for (auto empPtr : Ve) {
        delete empPtr;
    }

    system("pause");
    return 0;
}

// Function to display program introduction
void progIntro() {
    cout << "\t\t\t\tCMSY 171 Lab 6\n";
    cout << "Copyright 2022 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\t\tWelcome to CMSY-171 Employee Weekly Pay Program\n\n";
}

// Function to get input from the user
void getInput(vector<Employee*>& Ve) {
    int choice;
    string empName;
    int empID;
    bool valChoice, valExit = false;
    bool valID = true;
    bool valDouble = true;
    bool valRate = true;
    double hours, rate;
    do {
        valExit = false;
        do {
            valChoice = true;
            cout << "\n1. Hourly Employee\n";
            cout << "2. Salaried Employee\n";
            cout << "3. Stipend Employee\n";
            cout << "4. End Program\n";
            cout << "Enter menu choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "\nEnter the employee name: ";
                cin.ignore();
                getline(cin, empName);

                cout << "Enter the employee id: ";
                do {
                    cin >> empID;
                    valID = validateEmpID(empID);
                } while (!valID);

                cout << "Enter hours worked: ";

                do {
                    cin >> hours;
                    valDouble = validateDblNum(hours);
                } while (!valDouble);

                cout << "Enter hourly rate : $";

                do {
                    cin >> rate;
                    valDouble = validateDblNum(rate);
                } while (!valDouble);

                Ve.push_back(new HourlyEmployee(empID, empName, hours, rate));
                break;
            case 2:
                double ySal;
                cout << "\nEnter the employee name: ";
                cin.ignore();
                getline(cin, empName);

                cout << "Enter the employee id: ";
                do {
                    cin >> empID;
                    valID = validateEmpID(empID);
                } while (!valID);

                cout << "Enter salary : $";
                do {
                    cin >> ySal;
                    valDouble = validateDblNum(ySal);
                } while (!valDouble);

                Ve.push_back(new SalaryEmployee(empID, empName, ySal));
                break;
            case 3:
                double tPaid, tHours;
                cout << "\nEnter the employee name: ";
                cin.ignore();
                getline(cin, empName);

                cout << "Enter the employee id: ";
                do {
                    cin >> empID;
                    valID = validateEmpID(empID);
                } while (!valID);

                cout << "Enter stipend amount: $";
                do {
                    cin >> tPaid;
                    valDouble = validateDblNum(tPaid);
                } while (!valDouble);

                cout << "Enter total hours: ";
                do {
                    cin >> tHours;
                    valDouble = validateDblNum(tHours);
                } while (!valDouble);

                Ve.push_back(new StipenedEmployee(empID, empName, tPaid, tHours));
                break;
            case 4:
                valExit = getExitConfirm();
                continue;
            default:
                cout << "Error - invalid entry. Please reenter the menu choice\n\n";
                valChoice = false;
                break;
            }
        } while (!valChoice);
    } while (!valExit);
}

// Function to print employee information
void printList(const vector<Employee*>& Ve) {
    cout << "\nOutput Report:\n";
    for (const auto& empPtr : Ve) {
        empPtr->printPay();
        cout << endl;
    }
}

// Function to get confirmation for exiting the program
bool getExitConfirm() {
    bool confirmation, valconfirm;
    char userResp;
    cout << "Do you wish to exit the program (Y or N): ";
    do {
        valconfirm = true;
        cin >> userResp;
        userResp = tolower(userResp);

        if (userResp == 'y') {
            confirmation = true;
        }
        else if (userResp == 'n') {
            confirmation = false;
        }
        else {
            valconfirm = false;
            cout << "Please enter Y or N: ";
        }
    } while (!valconfirm);
    return confirmation;
}

// Function to validate employee ID
bool validateEmpID(int empID) {
    if (empID >= 100000 && empID <= 999999) {
        return true;
    }
    else {
        cout << "A value between 100000 and 999999 is required. Please re-enter: ";
        return false;
    }
}

// Function to validate double number
bool validateDblNum(double dblNuml) {
    if (dblNuml > 0) {
        return true;
    }
    else {
        cout << "\nA value > 0 is required. Please re-enter: ";
        return false;
    }
}