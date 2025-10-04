// Samhith Patibandla
// 10/16/2023
// This program calculates estimates for deck construction based on user input.

// Standard libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constant variable declaration for prices and tax rate
const double PI = 3.14, WOODPRICE = 24.75, TREXPRICE = 29.85, SALESTAX = 0.06, MATCOSTRT = 0.69;

// Function prototypes
void welcome();
void getInfo(string&, string&, string&);
int selectPackageShape();
void getDimensions(double&, double&); 
double calcSquareFeet(double, double);
void getDimensions(double&); 
double calcSquareFeet(double);
void getDimensions(double&, double&, double&); 
double calcSquareFeet(double, double, double);
int selectMaterial();
double calcTotalPrice(int, double);
void displayEstimate(string, string, string, double, int, double);
void goodBye();
bool smart(double, string);

int main()
{
	string getname, getnumber, getemail;
	bool confirmation = true;

	welcome();// Display welcome message

	getInfo(getname, getnumber, getemail);// Get customer information


	do {
		double area;
		bool valArea;
		int shapeChoice = selectPackageShape();// Get deck shape choice from user
		do {
			valArea = true;

			switch (shapeChoice) {
				case 1: // Rectangular deck
					double length, width;
					getDimensions(length, width);
					area = calcSquareFeet(length, width);
					break;
				case 2: // Circular deck
					double diameter;
					getDimensions(diameter);
					area = calcSquareFeet(diameter);
					break;
				case 3: // Trapezoidal deck
					double sl, ll, h;
					getDimensions(sl, ll, h);
					area = calcSquareFeet(sl, ll, h);
					break;
			}  //end switch 

			if (area > 408) {
				cout << "ERROR - The maximum area is 408.00 feet.  Please reenter dimensions!\n\n";
				valArea = false;
			}
		} while (!valArea);

		int material = selectMaterial(); // Get material choice from user
		double calcTotal = calcTotalPrice(material, area); // Calculate total cost
		displayEstimate(getname, getnumber, getemail, area, material, calcTotal); // Display estimate details

		bool valconfirm;
		char userResp;
		do {
			valconfirm = false;
			cout << "\n\n\tWould you like another estimate? [Y or N]: ";
			cin >> userResp;
			userResp = tolower(userResp);
			if (userResp == 'n') {
				valconfirm = true;
				confirmation = false;
			}
			else if (userResp == 'y') {
				valconfirm = true;
				confirmation = true;
			}

		} while (!valconfirm);

	} while (confirmation);   // Keep generating estimates until the user says they are done.


	goodBye(); // Display goodbye message

	system("pause");
	return 0;
}

// Function definitions

// Function to display Welcome message
void welcome() {
	cout << "Lab 4 - Functions - Pass By Reference\n";
	cout << "Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
	cout << "\n\tWelcome to CMSY-141 Deck Builders\n";
	cout << "\t\tSamhith P, Owner\n\n";
} // End of welcome() function

// Function to get Customer Information
void getInfo(string &name, string &number, string &email) {
	cout << "Please enter your full name: ";
	getline(cin, name);
	cout << "Please enter your cellphone number: (ex: (555) 555-5555) ";
	getline(cin, number);
	cout << "Please enter your email address: (ex: name@domain.net) ";
	getline(cin, email);
} // End of getInfo function

// Function to get deck shape choice from user
int selectPackageShape() {
	int choice;
	bool valChoice;
	cout << "\n\t\tEstimate\n\n";
	do{ 
	valChoice = true;
	cout << "To describe the shape of the deck, please select 1, 2, 3:\n";
	cout << setw(19) << "1. Rectangular\n";
	cout << setw(16) << "2. Circular\n";
	cout << setw(20) << "3. Trapezoidal\n\n";
	cout << "Enter your selection here: ";
	cin >> choice;

	if (choice < 1 || choice > 3) {
		cout << "Error: This is not a valid selection. Please try again.\n\n";
		valChoice = false;
	}
	} while (!valChoice);

	return choice;

} // End of selectPackageShape function

// Function to get length and width of deck
void getDimensions(double &length, double &width) {
	bool valDimensions;
	do {
		cout << "\nPlease input the length of the deck (in feet): ";
		cin >> length;
		valDimensions = smart(length, "length");
	} while (!valDimensions);

	do {
		cout << "\nPlease input the width of the deck (in feet): ";
		cin >> width;	
		valDimensions = smart(width, "width");
	} while (!valDimensions);
} // End of getDimensions Function

// Function to calculate area for rectangular deck
double calcSquareFeet(double len, double wid) {
	double area = len * wid;
	return area;
} // End of calcSquareFeet Function

// Function to get diameter of circular deck
void getDimensions(double &diameter) {
	bool valDimensions;
	do {
	cout << "\nPlease input the diameter of your deck (in feet): ";
	cin >> diameter;
	valDimensions = smart(diameter, "diameter");
	} while (!valDimensions);
} // End of getDimensions Function

// Function to calculate area for circular deck
double calcSquareFeet(double diam) {
	double radius = diam/2;
	double area = PI * radius * radius;
	return area;
} // End of calcSquareFeet Function

// Function to get dimensions for trapezoidal deck
void getDimensions(double &shortLength, double &longLength, double &height) {
	bool valDimensions;
	do{
		cout << "\nPlease enter the shortest length of the deck (in feet): ";
		cin >> shortLength;
		valDimensions = smart(shortLength, "short length");
	} while (!valDimensions);
	do {
		cout << "\nPlease enter the longest length of the deck (in feet): ";
		cin >> longLength;
		valDimensions = smart(longLength, "long length");
	} while (!valDimensions);
	do {
		cout << "\nPlease input the height of the deck (in feet): ";
		cin >> height;
		valDimensions = smart(height, "height");
	} while (!valDimensions);
} // End of getDimensions Function

// Function to calculate area for trapezoidal deck
double calcSquareFeet(double shortLen, double longLen, double height) {
	double area = (shortLen + longLen) / 2 * height;
	return area;
} // End of calcSquareFeet Function

// Function to select deck material
int selectMaterial() {
	int materialChoice;
	bool valMat;
	do {
		valMat = true;
		cout << "\nThere are two types of deck material that are available\n";
		cout << "All prices are based on square footage and include construction costs.\n\n";
		cout << setw(16) << "1. Wood   $" << WOODPRICE << " per square foot\n";
		cout << setw(16) << "2. Trex   $" << TREXPRICE << " per square foot\n\n";
		cout << "Enter your selection here: ";
		cin >> materialChoice;
		if (materialChoice < 1 || materialChoice > 2) {
			cout << "Error - this is not a valid selection. Please try again.\n\n\n";
			valMat = false;
		}
	} while (!valMat);
	return materialChoice;
} // End of selectMaterial Function

// Function to calculate total price based on material and area
double calcTotalPrice(int materialChoice, double area) {
	double totalPrice;
	if (materialChoice == 1) {
		totalPrice = WOODPRICE * area;
	}
	else if (materialChoice == 2) {
		totalPrice = TREXPRICE * area;
	}
	return totalPrice;
} // End of calcTotalPrice Function

// Function to display estimate details
void displayEstimate(string name, string number, string email, double area, int matChoice, double total) {
	double matCost = total * MATCOSTRT;
	double taxAmount = matCost * SALESTAX;
	cout << "\n\tEstimate:";
	cout << "\nCustomer Name:            " << name;
	cout << "\nCellphone Number:         " << number;
	cout << "\nEmail Address:            " << email;
	cout << "\n\nArea of the deck: " << fixed << setprecision(2) << area << " square feet";
	string mat = (matChoice == 1) ? "wood" : "trex";
	cout << "\n\nMaterial Type selected: " << mat;
	double matUnitPrice = (matChoice == 1) ? WOODPRICE : TREXPRICE;
	cout << "\nPrice per square foot $" << matUnitPrice;
	cout << "\n\nTotal Cost:    $" << setw(7) << fixed << setprecision(2) << total;
	cout << "\nTaxes:         $" << setw(7) << fixed << setprecision(2) << taxAmount;
	cout << "\nFinal Cost:    $" << setw(7) << fixed << setprecision(2) << (taxAmount + total);
	cout << "\n\nDate: October 17, 2023";
	cout << "\nThis estimate is valid for 60 days from the above date.\n";
} // End of displayEstimate Function

// Function to validate input dimensions
bool smart(double inputNum, string dimName) {
	bool valInput = true;
	if (inputNum < 0) {
		cout << "Error: Invalid Entry. The " << dimName << " must be greater than zero.\n\n";
		valInput = false;
	}
	return valInput;
} // End of smart Function

// Function to display goodbye message
void goodBye() {
	cout << "\nThank you for your business. Please come again!\n";
	cout << "Please contact our experts if you have any issues.\n\n";
} // End of goodBye Function