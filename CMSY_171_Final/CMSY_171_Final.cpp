// Samhith Patibandla
// 05/14/2024
// This program reads in the brand names of cellphones from a text file. 

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <list>
#include <vector>
#include "cell.h"
using namespace std;

const int FILESIZE = 100;

void intro();
fstream openFile();
void createList(list<Cell>&, fstream&);
void dispList(list<Cell>);

int main()
{
	cout << fixed << setprecision(2) << showpoint;
	fstream inFile;
	list<Cell> cellList;
	bool fileFlag = false;
	intro();

	//Call a function to open the file - use a try..catch block and a loop to catch 
	//the thrown exception for a bad file name or path
	while (!fileFlag)
	{
		//TO DO - write a try..catch block to accept the throw from the function if the file is not found
		//The loop can only end when the code is able to find and open the file.
		try {
			inFile = openFile();
			fileFlag = true; // If the file is successfully opened, exit the loop
		}
		catch (const runtime_error& e) {
			cout << e.what() << endl;
		}
	}


	//Call a function to read the file and create the List of phones
	createList(cellList, inFile);

	//Close the cellphone file

	//TO DO - close the input file 
	inFile.close();

	//Display the list
	dispList(cellList);

	cout << "Thank you for using the program" << endl << endl;
	system("pause");
	return 0;
}
//Display the intro
void intro()
{
	cout << setw(50) << "CMSY 171 Final Exam" << endl;
	cout << "Copyright 2022 - Howard Community College All rights reserved; Unauthorized duplication prohibited. \n" << endl;
	cout << setw(65) << "Welcome to CMSY-171 Cell Phone Cost Program\n" << endl;
}

fstream openFile()
{
	//Use the string just input to open the file for read only; this is a text file

	//TO DO - Declare a string or c-string called "fName", input the file path and name, open the file for input only and as text
	//Put in a properly declared variable called "inFile"
	string fName;
	cout << "Enter the file name and path: ";
	getline(cin, fName);

	fstream inFile(fName, ios::in); // Open the file for input only

	if (!inFile)
	{
		//Throw and exception if the file cannot be found
		string s = "\nError - this file does not exist, please reenter the file name to continue. ";
		throw(s);
	}
	else
	{
		//Return the file handle if the file is found
		return inFile;
	}
}

void createList(list<Cell>& cList, fstream& inFile)
{
	//Read each element in the data file one string at a time (this is the model of phone sold)
	//Determine if the model already has an object built that is in the list
	//If there is an object in the list for that model, use the .addPhone() class function to increment the number of phones by one
	//If there is not an object in the list for that model, instantiate the object and add it to the list in sorted order 
	//The sort order is alphabetical by name

	//TO DO - Read the file one line at a time.  Follow the algorithm above to create the list.  Return the list to main()
	string brand;
	while (getline(inFile, brand)) {
		// Find the brand in the list
		auto it = find_if(cList.begin(), cList.end(), [&brand](Cell& cell) {
			return cell.getModel() == brand;
			});

		if (it != cList.end()) {
			// If the brand is found, increment the number of phones
			it->addPhone();
		}
		else {
			// If the brand is not found, create a new Cell object with 1 phone and add it to the list
			Cell newCell(brand);
			// Insert the new cell in sorted order
			auto insertPos = find_if(cList.begin(), cList.end(), [&brand](Cell& cell) {
				return cell.getModel() > brand;
				});
			cList.insert(insertPos, newCell);
		}
	}

}

void dispList(list<Cell> cList)
{
	//Use a range based for loop to get each object from the list
	//Use the overloaded streaming operator to display the output as seen in the screen shot

	//TO DO - Create a loop and display the output using the overloaded output streaming operator
	for (auto& cell : cList) {
		cout << cell;
	}
}