#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <fstream>
#include "badip.h"
using namespace std;
const int FILESIZE = 100;
const int IPSIZE = 8;
const int FULLIP = 16;
const int DATESIZE = 24;

// Prototype

void intro();
fstream openFile();
void dispBad(vector<BadIP>&);
bool isBadIP(const string&);

int main()
{
	fstream ipFile;
	intro();
	char temp[FILESIZE];
	char badIP[IPSIZE];
	char badFull[FULLIP];
	char badDT[DATESIZE];
	vector<BadIP> allIP;
	int count = 0;

	ipFile = openFile();

	//TO DO - Create the vector with the suspect IP addresses
	//1. Read all of the entries in the file
	//2. Search for any entries with the suspect IP addresses
	//3. When a suspect IP address is found, split the data into the IP address and the date and time
	//4. Instantiate a BadIP object with the data found
	//5. Save the objets in the allIP vector
	while (!ipFile.eof())
	{
		string line;
		while (getline(ipFile, line)) {
			count++; // Increment totalRecords for each line read

			// Extract IP address and date/time information from the line
			string ipAddress = line.substr(0, 15);
			string dateTime = line.substr(16, 24);

			if (isBadIP(ipAddress)) {
			
				strncpy_s(badFull, ipAddress.c_str(), FULLIP - 1); 
				badFull[FULLIP - 1] = '\0'; 

				strncpy_s(badDT, dateTime.c_str(), DATESIZE - 1);
				badDT[DATESIZE - 1] = '\0'; 
				//cout << badDT << endl;

				BadIP tempBadIp(badFull, badDT);
				allIP.push_back(tempBadIp);
			}
		}

		//TO DO - Close the bad ip address file
		ipFile.close();


		cout << "\nOutput Report" << endl;
		cout << "-------------" << endl << endl;
		cout << "Total IP Addresses analyzed: " << count << endl;
		dispBad(allIP);

		cout << "\nThank you for using the program!\n\n";
		system("pause");
		return 0;
	}
}

//Display the intro
void intro()
{
	cout << setw(50) << "CMSY 171 Midterm Exam" << endl;
	cout << "Copyright 2023 - Howard Community College All rights reserved; Unauthorized duplication prohibited. \n" << endl;
	cout << setw(65) << "Welcome to CMSY-171 IP Address Evaluator Program\n" << endl;
}

fstream openFile()
{
	char fName[FILESIZE];
	bool contFlag = true;
	//TO DO - Allow the entry of the file path and name and return the file handle to main
	
	//1. Allow entry of the ip file path and name
	//2. Open the file as a text file
	//3. Test that the file was found
	//4. If not found, display appropriate error and allow reentry
	//5. If found, return the file handle to main
	fstream ipInputsFile;
		
	do{
		contFlag = true;
		cout << "\nEnter the name of the input file: ";
		cin >> fName;
		ipInputsFile.open(fName, ios::in);
		
		if (!ipInputsFile.is_open()) {
			cout << "\nError - this file does not exist. Please reenter the filename to continue: ";
			contFlag = false;
		}
		else {
			return ipInputsFile;
		}
	}while (!contFlag);
	
}


void dispBad(vector<BadIP>& f)
{
	//TO DO - Create the output of the bad IP addresses
	//1. Output the grand total number of bad IP addresses found using a vector function
	//2. Output the IP address and the date/time founf using a range based for loop and the overloaded streaming operator.

	int totalRecords = f.size();
	cout << "The Total number of suspect IP Addresses is: " << totalRecords << endl << endl;
	// Get the number of suspect IP addresses
	int numSuspectIPs = 0;
	for (BadIP& tempBadIp : f) {
		cout << tempBadIp;
	}
	return;
}

// Function to check if an IP address is suspect
bool isBadIP(const string& ipAddress) {
	// Check if the IP address starts with one of the three suspect IP ranges
	return (ipAddress.substr(0, 7) == "168.193" || ipAddress.substr(0, 7) == "224.174" || ipAddress.substr(0, 7) == "233.012");
}