// Samhith Patibandla
// 04/10/2024
// This program uses exception handling for planet program.

#include <iostream>
#include <iomanip>
#include "Planet.h" // Assuming Planet class is defined in "Planet.h"
#include <string>
using namespace std;

// Global Constant
const int EARTH_RADIUS = 3959; // Miles

// Prototypes
void projIntro();
template<typename T>
void processPlanet(const Planet&, bool, T&);

int main()
{
	projIntro(); // Display project introduction

	// Create planets
	//Planet Planet1("Jupiter");
	Planet Planet1(5);
	Planet Planet2, Planet3, Planet4, Planet5, Planet6;

	// Display planet information using standard streaming operator
	cout << "\nUsing cout and the standard streaming operator: " << endl;
	cout << "The planet name is: " << Planet1.getPlanetName() << endl;
	cout << "The planet number is: " << Planet1.getPlanetID() << endl;
	cout << "The planet has " << Planet1.getPlanetMoons() << " moons." << endl;
	cout << "The radius of the planet is: " << Planet1.getRadius() << " miles." << endl;

	// Display planet information using overloaded streaming operator
	cout << "\nUsing cout and the overloaded streaming operator: " << endl;
	cout << Planet1 << endl;

	// Using prefix operator to increment planet numbers
	cout << "\nUsing the prefix operator for planet 1 and planet 2: " << endl;
	Planet2 = ++Planet1;
	cout << Planet1 << endl;
	cout << Planet2 << endl;

	// Using prefix operator for planet 1 and planet 3
	cout << "\nUsing the prefix operator for planet 1 and planet 3: " << endl;
	Planet3 = Planet1++;
	cout << Planet1 << endl;
	cout << Planet3 << endl;

	// Using overloaded streaming operator to input planet information
	cout << "\nUsing the overloaded streaming operator for planet 4: " << endl;
	cin >> Planet4;
	cout << Planet4 << endl;

	// Using overloaded '-' operator to create a new planet with values associated with the first planet
	cout << "\nUsing the overloaded '-' operator for planet 5: " << endl;
	Planet5 = -Planet1;
	cout << Planet5 << endl;

	// Using overloaded '+' operator to create a new planet with values associated with the last planet
	cout << "\nUsing the overloaded '+' operator for planet 6: " << endl;
	Planet6 = +Planet1;
	cout << Planet6 << endl;

	bool valinID = true;
	do {
		int inPlanetID;
		valinID = true;
		cout << "\nUsing the try-catch to input number of planet 7: " << endl;
		cout << "Enter the number of a planet (1 - 8): ";
		cin >> inPlanetID;

		try {
			Planet Planet7(inPlanetID);
			cout << Planet7 << endl;
		}
		catch (Planet::planetLow) {
			cout << "Error - the value entered is too small.  Please try again!\n";
			valinID = false;
		}
		catch (Planet::planetHigh) {
			cout << "Error - the value entered is too large.  Please try again!\n";
			valinID = false;
		}
	} while (!valinID);

	// Instantiate an eighth planet object using the constructor that takes an integer
	Planet Planet8(6);
	double result;

	// Display planet information using standard streaming operator
	cout << "\nUsing cout and the standard streaming operator and the template: " << endl;
	cout << "The planet name is: " << Planet8.getPlanetName() << endl;
	cout << "The planet number is: " << Planet8.getPlanetID() << endl;
	cout << "The planet has " << Planet8.getPlanetMoons() << " moons." << endl;
	cout << "The radius of the planet is: " << Planet8.getRadius() << " miles." << endl;

	processPlanet(Planet8, false, result);
	cout << "The size is equal to " << fixed << setprecision(2) << result << " times the radius of Earth!" << endl;

	cout << "\n\nThank you for using the program!\n\n";

	system("pause"); // Pause the program before exiting
	return 0;
}

// Function to display project introduction
void projIntro() {
	cout << "\t\t\t\tCMSY 171 CE-Exception and Template\n";
	cout << "Copyright 2022 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
	cout << "\n\t\tWelcome to CMSY-171 Planet Operations Program\n";
}

template<typename T>
void processPlanet(const Planet& planetT, bool isTrue, T& radResult) {
	if (isTrue) {
		radResult = planetT.getRadius(); // Set result to the planet's radius
	}
	else {
		// Calculate "Earth Equivalents" and assign it to result
		radResult = static_cast<T>(planetT.getRadius()) / static_cast<T>(EARTH_RADIUS); 
	}
}