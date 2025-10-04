// Samhith Patibandla
// 05/04/2024
// This program is point-of-sale program for a cellphone kiosk which and 
// uses a stack for the cell phone inventory and a queue for the customer purchases.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include "cell.h"
#include "customer.h"
using namespace std;

const int BUY = 1;
const int CO = 2;
const int QUIT = 3;
const int MAX_PHONE = 6;
const int MIN_PHONES = 1;
const int FILESIZE = 100;

void intro();
fstream openFile();
void createList(list<Cell>&, fstream&);
void dispMenu();
void buyPhone(list<Cell>&, deque<Customer>&);
void checkOut(deque<Customer>&);

int main()
{
	//stack <Cell, vector<Cell>> cellStack;
	list <Cell> cellList;
	deque <Customer> custQueue;
	int choice = 0;
	bool endFlag = false;
	fstream cellFile;
	cout << fixed << setprecision(2) << showpoint;
	intro();
	cellFile = openFile();
	createList(cellList, cellFile);

	do
	{
		endFlag = false;
		//Display menu, get menu choice
		do
		{
			dispMenu();
			cin >> choice;
			if (choice < BUY || choice > QUIT)
			{
				cout << "Invalid choice! Try again\n";
			}
		} while (choice < BUY || choice > QUIT);


		//Process menu selection
		switch (choice)
		{
		case BUY:
			if (!cellList.empty())
			{
				buyPhone(cellList, custQueue);
			}
			else
			{
				cout << "There are no phone left in inventory. Please check out customers and end the program! " << endl << endl;
			}
			break;
		case CO:
			if (!custQueue.empty())
			{
				checkOut(custQueue);
			}
			else
			{
				cout << "There are no customer left to checkout! " << endl << endl;
			}
			break;
		case QUIT:
			if (!custQueue.empty())
			{
				cout << "Error - there are still customers in the checkout queue! " << endl;
				cout << "Please return to main menu and check out all of the customers! " << endl << endl;
			}
			else
			{
				cout << "\nThank you for using our program today. " << endl;
				endFlag = true;
			}
			break;
		default:
			cout << "Invalid choice! Try again: \n";
			break;
		}
	} while (!endFlag);

	system("pause");
	return 0;
}
//Display the intro
void intro()
{
	cout << setw(50) << "CMSY 171 Extra Credit Lab" << endl;
	cout << "Copyright 2023 - Howard Community College All rights reserved; Unauthorized duplication prohibited. \n" << endl;
	cout << setw(65) << "Welcome to CMSY-171 Updated Cell Phone Purchase Program\n" << endl;
}

//TODO - Create a function to allow the user to input a file name and path.  Once entered, the code tests that the filename
//and path exists and can be open for read.  If it cannot be opened, the code displays the appropriate error and allows 
//for the reentry of the file path and name.  Once it is valid, the code returns the input file handle to the calling function.
//This file is a read only TEXT file. It is not binary. 
fstream openFile()
{
	char fName[FILESIZE];
	bool contFlag = true;

	fstream ipInputsFile;

	do {
		contFlag = true;
		cout << "\nEnter the name of the input file: ";
		//cin >> fName;
		cin.getline(fName, FILESIZE);
		ipInputsFile.open(fName, ios::in); // Opening file path

		if (!ipInputsFile.is_open()) { // Validating path whether it exists or not
			cout << "\nError - this file does not exist. Please reenter the filename to continue: ";
			contFlag = false;
		}
		else {
			return ipInputsFile;
		}
	} while (!contFlag);

}

//TODO - Create a function that creates a sorted linked list (ascending by phone number).  The code reads the input file for all
//elements and creates the linked list in a sorted manner (do NOT use .sort()).  The code should close the file once the code has
//read all of the elements and created the list.

// Function to create a sorted linked list of Cell objects
void createList(list<Cell>& newList, fstream& cFile) {
	string id, num;
	while (cFile >> id >> num) {
		// Create a new Cell object
		Cell newCell;
		newCell.setId(id);
		newCell.setPhone(num);

		// Find the correct position to insert the new Cell in the sorted list
		bool valInsert = false;
		for (auto it = newList.begin(); it != newList.end(); ++it) {
			if (num < it->getPhone()) {
				newList.insert(it, newCell);
				valInsert = true;
				break;
			}
		}

		// If the newCell has the largest phoneNumber, insert at the end
		if (!valInsert) {
			newList.push_back(newCell);
		}
	}

	// Close the cfile
	cFile.close();
}

//Function to display the main menu
void dispMenu()
{
	cout << "\n" << BUY << ". Buy Phone\n"
		<< CO << ". Customer Checkout\n"
		<< QUIT << ". Quit\n\n"
		<< "Enter the menu choice: ";
}

//TODO Create a function to allow the user to buy at least one cellphone. The code will use the linked list to get the cellphone
//objects.  The code uses the cell phone objects at the front of the list to fill the array.  The code then removes the objects from 
//the list when they have been bought by the customer. 
//The function MUST keep track of the number of phones and MUST always display the approproate amount left.  If I start with 22 and have
//3 customers buy three phones each, when the 4th customer buys a phone, the code must state that the number available is 1 - 4 (not 1-6). 

void buyPhone(list<Cell>& cList, deque<Customer>& cQueue) {
	if (cList.empty()) {
		cout << "No phones available for purchase." << endl;
		return;
	}

	// Input customer name
	string name;
	int numPhones;
	bool valFlag = true;
	cin.ignore();
	cout << "Please enter the customer's name: ";
	getline(cin, name);

	// Validate and input number of phones to purchase
	do {
		valFlag = true;
		cout << "Please enter the number of phones to purchase (1 - " << min(MAX_PHONE, (int)cList.size()) << "): ";
		cin >> numPhones;

		if (numPhones < 1 || numPhones > min(MAX_PHONE, (int)cList.size())) {
			cout << "Error - you can only purchase between 1 and " << min(MAX_PHONE, (int)cList.size()) << " phones. Please reenter!" << endl << endl;
			valFlag = false;
		}
	} while (!valFlag);

	// Populating the array of purchased phones and creating a customer object
	Cell p[MAX_PHONE];
	auto it = cList.begin();
	for (int i = 0; i < numPhones; ++i) {
		p[i] = *it;
		++it;
	}
	cList.erase(cList.begin(), next(cList.begin(), numPhones));

	Customer customer(name, numPhones, p);
	cQueue.push_back(customer);

	// Display the phones bought
	cout << "Phones bought by " << name << ":" << endl;
	for (int i = 0; i < numPhones; ++i) {
		cout << "ID: " << p[i].getId() << ", Phone Number: " << p[i].getPhone() << endl;
	}

	// Display the remaining number of phones
	cout << "Phones available: " << cList.size() << " - " << cQueue.size() << endl;
}



//TODO - Create a function to checkout each customer one customer at a time. This must be one customer at a time and it must use
//the overloaded streaming operator in the customer class.  The code must remove the customer from the queue once the output for 
//that customer is displayed.
void checkOut(deque<Customer>& cQueue) {
	if (cQueue.empty()) {
		cout << "There are no customers left to checkout!" << endl << endl;
		return;
	}

	// Display information for the first customer in the queue
	cout << "Checking out customer:" << endl;
	cout << cQueue.front() << endl;


	// Remove the customer from the queue
	cQueue.pop_front();
}
