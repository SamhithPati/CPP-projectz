// Samhith Patibandla
// 11/08/2023
// This C++ program calculates and displays sales, tax, and profit information for a food kiosk using pointers.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Declaring global constant for sales tax rate
const double SALESTAX = 0.06;

// Prototype functions
void showCopyright();
bool validate(double&);
bool validIntInput(int);
void displayReport(double*, int);
double sumRev(double*, int);
double avgRevenue(double*, int);

// Beginning of Main Function
int main()
{
    int numOfDays;
    bool valInput;
    showCopyright();

    double totalRev, avgRev, totalTaxAmt, avgTaxAmt, totalProfit, avgProfit;
    double* revenue;

    // Get the number of days of data collection from the user
    do {
        cout << "\nPlease enter the number of days of data collection: ";
        cin >> numOfDays;
        valInput = validIntInput(numOfDays);
    } while (!valInput);

    // Dynamically allocate an array to hold revenue for each day
    revenue = new double[numOfDays];

    // Input gross revenue for each day of the week
    cout << "\nPlease enter the gross revenue for \n";
    for (int i = 0; i < numOfDays; i++)
    {
        do
        {
            cout << "\t Day " << i + 1 << " : $";
            cin >> revenue[i];
            valInput = validate(revenue[i]);
        } while (!valInput);
    }

    // Display sales report
    displayReport(revenue, numOfDays);

    // Calculate total and average revenue, total and average tax, total and average profit
    totalRev = sumRev(revenue, numOfDays);
    avgRev = avgRevenue(revenue, numOfDays);

    totalTaxAmt = totalRev * SALESTAX;
    avgTaxAmt = avgRev * SALESTAX;
    totalProfit = totalRev - totalTaxAmt;
    avgProfit = avgRev - avgTaxAmt;

    // Display the calculated values
    cout << "\n\nTotal Revenue for the week: $" << totalRev << endl;
    cout << "Average Revenue per day: $" << avgRev << endl
        << endl;
    cout << "Total Tax for the week: $" << totalTaxAmt << endl;
    cout << "Average Tax per day: $" << avgTaxAmt << endl
        << endl;
    cout << "Total Profit for the week: $" << totalProfit << endl;
    cout << "Average Profit per day: $" << avgProfit << endl
        << endl;

    // Deallocate memory used by revenue array
    delete[] revenue;
    revenue = nullptr;

    cout << "Thank you for using the Food Kiosk Calculator! Goodbye!\n\n";

    // Pause the program to view the output
    system("pause");
    return 0;
}

// Function to display copyright and welcome message
void showCopyright()
{
    cout << "CE - Pointer\n";
    cout << "Copyright �2023 � Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";
    cout << "\tWelcome to the CMSY-141 Food Kiosk Profit Calculator\n";
}

// Function to validate input number (must be non-negative)
bool validate(double& inputNum)
{
    bool valInput = true;
    if (inputNum < 0)
    {
        cout << "Invalid Entry. Please enter a valid value\n";
        valInput = false;
    }
    return valInput;
}

// Function to validate input number (must be positive)
bool validIntInput(int inputNum)
{
    bool valInput = true;
    if (inputNum <= 0)
    {
        cout << "Error - the number of days must be greater than 0. Please reenter!\n";
        valInput = false;
    }
    return valInput;
}

// Function to display the sales report
void displayReport(double* inputAry, int numDays)
{
    cout << "\n\nFood Kiosk Profit Calculator\n";
    cout << "\tSales Report\n";

    for (int i = 0; i < numDays; i++)
    {
        cout << "\n\tDay " << i + 1 << " : $" << fixed << setprecision(2) << inputAry[i];
    }
    return;
}

// Function to calculate the total revenue
double sumRev(double* inputAry, int numDays)
{
    double sumInput = 0;
    for (int i = 0; i < numDays; i++)
    {
        sumInput += inputAry[i];
    }
    return sumInput;
}

// Function to calculate the average revenue
double avgRevenue(double* inputAry, int numDays)
{
    double total = sumRev(inputAry, numDays);
    double average = total / numDays;
    return average;
}