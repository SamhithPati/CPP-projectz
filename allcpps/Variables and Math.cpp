// Samhith Patibandla
// 09/11/2023
// This program displays quadratic equation, calculates discriminant, and calculates/prints the roots and its values

#include <iostream>	
#include <iomanip>	// File that includes for setprecision
using namespace std;

int main()
{
	// printing the suggested statements in the assignment
	cout << "CMSY - 141 Lab 0\n";
	cout << "Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
	cout << "Welcome to Quadratic Problem Solver \n\n";
	
	double a, b, c; //Declaration of variables which are coefficients and the constant in a quadratic equation

	//Prompts user to enter value of a,b,c
	cout << "Please enter the value of a: ";
	cin >> a;

	cout << "Please enter the value of b: ";
	cin >> b;

	cout << "Please enter the value of c: ";
	cin >> c;
	cout << endl;
	
	//Prints the equation in quadratic form
	// Used setprecesion to display the 2 digits after decimal point 
	cout << fixed << setprecision(2);
	cout << "The equation is: " << a << "x^2 + " << b << "x + " << c << endl << endl;

	//Calculates the discriminant and stores in a variable
	double discriminant = (b * b) - (4 * a * c);

	//Prints the discriminant
	cout << "The discriminant is: " << discriminant << endl <<endl;

	//Checks the value of the discriminant and prints the roots
	if (discriminant > 0) {
		double root1 = (-b + sqrt(discriminant)) / (2 * a), root2 = (-b - sqrt(discriminant)) / (2 * a);  //There are two roots
		cout << "There are two roots and the values are " << root1 << " and " << root2 <<endl <<endl;
	}
	else if (discriminant == 0) {
		double root = -b / (2 * a);    //There is one root
		cout << "There is one root and the value is: " << root << endl << endl;
	}
	else {
		cout << "There are no roots for this equation." << endl << endl;
	}

	cout << "Thank you for using the quadratic problem solver.\n\n"; //Prints thank you statement at end 

	system("pause");
	return 0;
}
