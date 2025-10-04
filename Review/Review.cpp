// Samhith Patibandla
// 01/31/2024
// This program allows users to input information about their cars, including make, model, model year, and mileage.

#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

// Structure to hold car information
struct CAR {
    string carMake = "none";
    string carModel = "none";
    int modelYear = 0;
    double miles = 0.00;
};

// Prototypes 
void progIntro();
void carInput(CAR*, int);
void displayCarReport(const CAR*, int);

int main()
{
    int numCars;
    bool valFlag;
    progIntro();

    // Validate the number of cars input
    do {
        valFlag = true;
        // Ask the user for the number of cars
        cout << "\nPlease enter in the number of cars you own: ";
        cin >> numCars;

        if (numCars < 0) {
            cout << "Error - please enter a positive number!";
            valFlag = false;
        }
    } while (!valFlag);

    // Dynamically allocate an array of Car structures
    CAR* cars = new CAR[numCars];

    carInput(cars, numCars);
    displayCarReport(cars, numCars);

    // Deallocate the memory allocated for the array
    delete[] cars;

    system("pause");
    return 0;
}

// Function to display program introduction
void progIntro() {
    cout << "CE - 141 Review\n";
    cout << "Copyright ©2023 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\tWelcome to CMSY-171 Starter Review Program\n";
}

// Function to input car information
void carInput(CAR* cars, int size) {
    bool valYear, valmiles;   
    for (int i = 0; i < size; i++) {
        cout << endl;
        cout << "Enter in the car make and model: ";
        string makeAndModel;
        cin >> ws; // Work around for cin.ignore()
        // cin.ignore(); - not working

        getline(cin, makeAndModel);

        // Use stringstream to split the make and model
        stringstream ss(makeAndModel);
        ss >> cars[i].carMake >> cars[i].carModel;

        do{
            valYear = true;
            cout << "Please enter in the model year of the " << cars[i].carMake << " " << cars[i].carModel << " : ";
            cin >> cars[i].modelYear;
            if (cars[i].modelYear < 1903 || cars[i].modelYear > 2024) {
                cout << "Error - please enter a value between 1903 and 2024!\n";
                valYear = false;
            }
        } while (!valYear);

        do {
            valmiles = true;
            cout << "Please enter in the number of miles on the odometer of the " << cars[i].carMake << " " << cars[i].carModel << " : ";
            cin >> cars[i].miles;
            if (cars[i].miles <= 0) {
                cout << "Error - please enter valid number of miles greater than 0\n";
                valmiles = false;
            }
        } while (!valmiles);
    }
}

// Function to display the car output report
void displayCarReport(const CAR* carArray, int numCars) {
    cout << "\n\nOutput Report:\n";
    int i = 0;
    double totalMiles = 0;
    while (i < numCars) {
        cout << "The make of the car is: " << carArray[i].carMake << endl; 
        cout << "The model of the car is: " << carArray[i].carModel << endl;
        cout << "The model year is: " << carArray[i].modelYear << endl;
        cout << "The number of miles driven is: " << fixed << setprecision(1) << carArray[i].miles << endl;
        cout << endl;
        totalMiles += carArray[i].miles;
        ++i;
    }
    cout << "\nThe total miles driven for all cars is: " << fixed << setprecision(1) << totalMiles << endl << endl;
    cout << "Thank you for using the review program.\n\n";
}