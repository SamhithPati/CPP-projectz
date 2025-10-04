// Samhith Patibandla
// 09/13/2023
// This program prompts the user to enter and calculates the basic mathematical operations of two integers and two doubles.

// Import the necessary libraries.
#include <iostream>
#include <iomanip> 
using namespace std;

// The main function
int main()
{
	// Declare the variables
	int num1, num2;
	double a, b;

	// Print the header with suggested statements
	cout << "CE - Math\n";
	cout << "Copyright ©2021 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";

	// Takes the input from the user.
	cout << "Enter the first integer value: ";
	cin >> num1;
	cout << "Enter the second integer value: ";
	cin >> num2;
	cout << "Enter the first double value: ";
	cin >> a;
	cout << "Enter the second double value: ";
	cin >> b;
	cout << endl << endl;

	// Calculate the integer math operations.
	cout << "Integer Math\n";
	int add = num1 + num2;
	cout << "Adding " << num1 << " and " << num2 << " = " << add <<endl;
	int sub = num1 - num2;
	cout << "Subtracting " << num1 << " and " << num2 << " = " << sub <<endl;
	int mult = num1 * num2;
	cout << "Multiplying " << num1 << " and " << num2 << " = " << mult << endl;
	int div = num1 / num2;
	cout << "Dividing " << num1 << " and " << num2 << " = " << div << endl;
	int mod = num1 % num2;
	cout << "Moding " << num1 << " and " << num2 << " = " << mod << endl << endl;

	// Calculate the double math operations.
	// Set the precision of the output to 2 decimal places.
	cout << "Double Math\n";
	double adding = a + b;
	cout << "Adding " << a << " and " << b << " = " << fixed << setprecision(2) << adding << endl;
	double subtract = a - b;
	cout << "Subtracting " << a << " and " << b << " = " << fixed << setprecision(2) << subtract << endl;
	double multiply = a * b;
	cout << "Multiplying " << a << " and " << b << " = " << fixed << setprecision(2) << multiply << endl;
	double divide = a / b;
	cout << "Dividing " << a << " and " << b << " = " << fixed << setprecision(2) << divide << endl <<endl;
	
// Pause the program.
 system("pause");

 // Return 0 for success.
 return 0;

}


