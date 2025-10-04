// Samhith Patibandla
// 10/21/2023
// Exam 1 - Fall 2023 Midterm
// This program converts the NLeastian units to Earth metric units and confirms whether a rocket is safe to launch 

//Standard Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//global constant declaration
const int chartIncrement = 5, allowedWindsp = 324, secPerHr = 3600;
const double allowedPhillies = 24.8;

//Prototype Functions
double convertMetToCel(double);
double convertPhiltoKg(double);
void convertNatstoMts(double, double &);
void convertMarlinstoHrs(double, double&);
bool launchSpeed(double &);

int main()
{
	// Variable Declaration
	double met1, met2, mtsPerSec;
	bool valMet, safeLaunch;
	
	// Displaying met to celcius chart and Input validation for the first number (met1)
	do {
		valMet = true;
		cout << "Please enter the first number: ";
		cin >> met1;
		if (met1 < -10 || met1 > 150) {
			cout << "Error - the low temp must be between -10 and 150. Please reenter.\n";
			valMet = false;
		}
	} while (!valMet);

	// Displaying met to celcius chart and Input validation for the second number (met2)
	do {
		valMet = true;
		cout << "Please enter the second number: ";
		cin >> met2;
		if ((met2 < -10 || met2 > 150) && (met2 < met1)) {
			cout << "Error - the high temp must be between -10 and 150. Please reenter.\n";
			valMet = false;
		}
	} while (!valMet);

	
	// Converting and displaying temperature chart
	double tempMet = met1;
	double tempCelc;
	cout << "\n\tDegree Met" << "\tDegree Celcius\n";
	while (tempMet <= met2) { 
		tempCelc = convertMetToCel(tempMet);
		cout << fixed << setprecision(3) << setw(18) << tempMet << setw(20) << tempCelc << endl;
		tempMet = tempMet + chartIncrement; // Incrementing mets
	}
	
	// Converting and displaying the mass of Phillies to kilograms
	double allowedKgs = convertPhiltoKg(allowedPhillies);
	cout << "\nA mass of " << fixed << setprecision(3) << allowedPhillies << " Phillies " << "is equal to " << allowedKgs << " killograms\n";

	// Checking if it's safe to launch based on wind speed
	safeLaunch = launchSpeed(mtsPerSec);
	cout << "\nThe wind speed is: " << fixed << setprecision(3) << mtsPerSec << " meters/sec.";

	if (safeLaunch) {
		cout << " The ship CAN launch!!\n\n";
	}
	else {
		cout << " The ship CANNOT launch!!\n\n";
	}

	system("pause");
	return 0;
}

// Function to convet from met to celcius
double convertMetToCel(double inputMet) {
	double outCelc;
	outCelc = ((inputMet * inputMet) / 7.23) + 26.5;
	return outCelc;
}

// Function to convet from phillies to Killograms
double convertPhiltoKg(double phillies) {
	double kgs = 0.07 * (phillies * phillies * phillies);
	return kgs;
}

// Function to convet from nats to meters
void convertNatstoMts(double inNats, double &outMts) {
	outMts = 0.625 * inNats;
	return;
}

// Function to convet from Marlins to Hours
void convertMarlinstoHrs(double inMarlins, double &outHours) {
	outHours = sqrt(6.2 * inMarlins);
	return;
}

// Function to check if the rocket can launch based on wind speed
bool launchSpeed(double &metersPerSec) {
	bool valInput, goodforLaunch;
	double natsperMarlin, meters, hours;
	do {
		valInput = true;
		cout << "\nPlease enter in the wind speed in Nats/Marlin: ";
		cin >> natsperMarlin;
		if (natsperMarlin < 0) {
			cout << "Error - the wind speed must be greater than 0. Please reenter.\n";
			valInput = false;
		}
	} while (!valInput);

	// Converting Nats to meters
	 convertNatstoMts(natsperMarlin, meters);

	 // Converting 1 marlin to hours
	 convertMarlinstoHrs(1, hours);

	 // Converting hours to seconds
	 double seconds = hours * secPerHr;
	  
	 // Converted windspeed in meters per second
	  metersPerSec = meters / seconds;

	 // Checking if rocket is good for launch
	 if (metersPerSec <= allowedWindsp) {
		 goodforLaunch = true;
	 }
	 else {
		 goodforLaunch = false;
	 }
	 return goodforLaunch;
}
