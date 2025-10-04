// Samhith Patibanda
// 10/31/2023
// This program uses vectors and range-based for loops to calculate and display the average number of beverages sold per day, 
// the total number of days, the total number of beverages sold, the revenue, the tax, the total rental cost, and the total profit. 

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Global Constants
const double REVENUE_PER_BEVERAGE = 2.97;
const double SALES_TAX_RATE = 0.06;
const double DAILY_RENTAL_FEE = 6.75;

// Function prototypes
void displayIntro();
bool endProgram();
int getMenuChoice();
int getNumBeverages();
double calculateAverage(const vector<int>&);
void calculateRevenueTaxProfit(const vector<int>&, double&, double&, double&);
int getTotalBev(const vector<int>); 
void displayOutput(const vector<int>&, double, double, double);

int main()
{
    // Variables
    vector<int> beverages;
    int menuChoice;
    bool programEnded = false;

    // Display program intro
    displayIntro();

    // Loop until user ends program
    while (!programEnded)
    {
        // Display menu and get user's choice

        menuChoice = getMenuChoice();

        // Perform action based on user's choice
        switch (menuChoice)
        {
        case 1:
            // Add new day's beverages to vector
            beverages.push_back(getNumBeverages());
            break;
        case 2:
            // Calculate and display average number of beverages sold per day
            cout << "\nThe average number of beverages sold per order is: ";
            cout << fixed << setprecision(1) << calculateAverage(beverages) << endl;
            break;
        case 3:
            // Calculate revenue, tax, and profit and display output
            double revenue, tax, profit;
            calculateRevenueTaxProfit(beverages, revenue, tax, profit);
            displayOutput(beverages, revenue, tax, profit);
            break;
        case 4:
            // End program
            programEnded = endProgram();
            break;
        default:
            // Invalid menu choice
            cout << "Error - please enter a valid menu item." << endl;
            break;
        }
    }

    system("pause");
    return 0;
}

// Function to display program title, copyright info, and intro
void displayIntro()
{
    cout << "Lab 6: Vectors and Range Based For Loops\n";
    cout << "Copyright 2022 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\tWelcome to the CMSY-141 Beverage Revenue Calculation Program\n";
}

// Function to display menu and get user's menu choice
int getMenuChoice()
{
    cout << "\nInput Menu:" << endl;
    cout << "1. Enter new value sold" << endl;
    cout << "2. Calculate the average sold" << endl;
    cout << "3. Calculate the revenue, tax and profit." << endl;
    cout << "4. End program" << endl;

    int choice;
    cout << "Enter the menu option here: ";
    cin >> choice;
    return choice;
}

// Function to get number of beverages sold for a new day
int getNumBeverages()
{
    int numBeverages;
    do
    {
        cout << "\nInput the number of beverages sold: ";
        cin >> numBeverages;
        if (numBeverages <= 0)
        {
            cout << "Error - Number of beverages must be greater than zero. Please reenter!\n\n";
        }
    } while (numBeverages <= 0);
    return numBeverages;
}

// Function to calculate average number of beverages sold per day
double calculateAverage(const vector<int>& beverages)
{
    double sum = getTotalBev(beverages);  
    return sum / beverages.size();
}

// Function to calculate revenue, tax, and profit
void calculateRevenueTaxProfit(const vector<int>& beverages, double& revenue, double& tax, double& profit)
{
    int totalBeverages = getTotalBev(beverages);
    revenue = totalBeverages * REVENUE_PER_BEVERAGE;
    tax = revenue * SALES_TAX_RATE;
    profit = revenue - tax - (DAILY_RENTAL_FEE * beverages.size());
}

int getTotalBev(const vector<int> bevs) {
    double totalBevs = 0;
    for (int numBeverages : bevs)
    {
        totalBevs += numBeverages;
    }
    return totalBevs;
}

// Function to display output
void displayOutput(const vector<int>& beverages, double revenue, double tax, double profit)
{
    int totalBeverages = getTotalBev(beverages);
    int dayNum = 1;
    double rentalCost = beverages.size() * DAILY_RENTAL_FEE;
    cout << "\nBeverage Sales: \n";
    for (int numBeverages : beverages)
    {
        cout << "\tDay #" << dayNum << ": " << numBeverages << endl;
        dayNum++;
    }
    cout << "The total number of days is: " << beverages.size() << endl;
    cout << "The total number of beverages sold is: " << totalBeverages << endl;
    cout << "The total revenue is $" << fixed << setprecision(2) << revenue << endl;
    cout << "The total tax is $" << fixed << setprecision(2) << tax << endl;
    cout << "The total rent is $" << fixed << setprecision(2) << rentalCost << endl;
    cout << "The total profit is $" << fixed << setprecision(2) << profit << endl;
}

// Function to ask user if they want to end the program
bool endProgram()
{
    char choice;
    do
    {
        cout << "\nDo you wish to exit the program (y/n)? ";
        cin >> choice;
        if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            cout << "\n\nError - Please enter in either y or n\n\n";
        }
        if (choice == 'Y' || choice == 'y') {
            cout << "\nThank you for using the beverage program. Pleae come again!\n\n";
        }
    } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
    return (choice == 'Y' || choice == 'y');
}
