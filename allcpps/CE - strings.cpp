// Samhith Patibandla 
// 11/13/2023
// This program does something. 

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

// Global Constants
const int SUBSTRING_SIZE = 25;
const int FULL_STRING_SIZE = 100;

// Initiating prototype functions
void showCopyright();
void countCharacters(const char*);
bool continueOrEnd();

int main()
{
	showCopyright();
    do{
        char department[SUBSTRING_SIZE];
        char number[SUBSTRING_SIZE];
        char section[SUBSTRING_SIZE];
        char title[SUBSTRING_SIZE];
 
        std::cout << "\nPlease enter the department name: ";
        std::cin >> department;
        std::cout << "Please enter in the class number: ";
        std::cin >> number;
        std::cout << "Please enter in the section number: ";
        std::cin >> section;
        std::cout << "Please enter in the class title: ";
        std::cin.ignore(); // Ignore the newline character in the input buffer
        std::cin.getline(title, SUBSTRING_SIZE);

        char fullString[FULL_STRING_SIZE];
        strcpy_s(fullString, department);
        strcat_s(fullString, "-");
        strcat_s(fullString, number);
        strcat_s(fullString, " (");
        strcat_s(fullString, section);
        strcat_s(fullString, ") ");
        strcat_s(fullString, title);

        std::cout << "\nThe course entered is: " << fullString << std::endl;
        std::cout << "The size of the string is: " << strlen(fullString) << std::endl;

        if (strcmp(department, "CMSY") == 0) {
            std::cout << "This is a computer science class." << std::endl;
        }
        else {
            std::cout << "This is not a computer science class." << std::endl;
        }

        countCharacters(fullString);
   
    } while (!continueOrEnd());
    return 0;
}


void showCopyright() {
	cout << "CE - Strings\n";
	cout << "Copyright ©2021 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
	cout << "\n\tWelcome to the CMSY-141 C-String Practice Program\n";
}

void countCharacters(const char* inputStr) {
    int alphaCount = 0, numCount = 0, punctCount = 0, spaceCount = 0;
    for (int i = 0; i < strlen(inputStr); i++) {
        if (isalpha(inputStr[i])) {
            alphaCount++;
        }
        else if (isdigit(inputStr[i])) {
            numCount++;
        }
        else if (ispunct(inputStr[i])) {
            punctCount++;
        }
        else if (isspace(inputStr[i])) {
            spaceCount++;
        }
    }
    std::cout << "\nThe number of alphas = " << alphaCount << std::endl;
    std::cout << "The number of digits = " << numCount << std::endl;
    std::cout << "The number of spaces = " << punctCount << std::endl;
    std::cout << "The number of puncts = " << spaceCount << std::endl;
}

bool continueOrEnd() {
    char response;
    bool validResponse = false;
    std::cout << "\nDo you wish to exit the program (Y or N)? ";
    while (!validResponse) {
        std::cin >> response;
        response = toupper(response);
        if (response == 'Y') {
            validResponse = true;
            return true; // End the program
        }
        else if (response == 'N') {
            validResponse = true;
            return false; // Continue with the class entry process
        }
        else {
            std::cout << "Please enter Y or N: ";
            validResponse = false;
        }
    }
}