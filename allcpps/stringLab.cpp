// Samhith Patibandla
// 11/14/2023
// This program is a menu-driven application that performs various operations on strings, 
// including mathematical calculations with user-inputted values, counting different elements in a given string, and manipulating C-strings and C++ string objects.

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm> // for std::sort

using namespace std;

// Initializing global Constant
const int MAX_ADDRESS_LENGTH = 10;

// Declaring Protypes
void showCopyright();
void stringMath();
bool validateInput(const char*);
void CountElements(const char*);
void cStringManip();
void scStringManip();
bool ExitProgram();

int main()
{
    int userChoice;
    bool valFlag, exitFlag;
    const char sentence[65] = "How R cStrings 4 U? They can B tricky 4 brand new C++ students!";
    
    showCopyright();
    
    do{ // Validation Loop
        valFlag = true;
        exitFlag = false;
        cout << "\nString Lab Menu";
        cout << "\n\t1 - Doing Math with Strings";
        cout << "\n\t2 - Counting Elements";
        cout << "\n\t3 - C-String Manipulation";
        cout << "\n\t4 - String Class Manipulation";
        cout << "\n\t5 - Exit Program";
        cout << "\n\nPlease enter menu choice: ";
        cin >> userChoice;

        if (userChoice < 1 || userChoice > 5) {
            cout << "ERROR - You must enter in a valid menu item. Please try again\n";
            valFlag = false;
        }

        switch(userChoice) {
            case 1:
                stringMath();
                break;
            case 2:
                CountElements(sentence);
                break;
            case 3:
                cStringManip();
                break;
            case 4:
                scStringManip();
                break;
            case 5:
                exitFlag = ExitProgram();
                break;
        }
    } while (!valFlag || !exitFlag);


    system("pause");
    return 0;
} 

void showCopyright() 
{
    cout << "Lab 8 - Strings\n";
    cout << "Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\tWelcome to the CMSY-141 C-String Manipulation Program\n";
}

bool ExitProgram() {
    char response;
    bool validResponse = false;
    cout << "Do you wish to exit the program (Y or N)? ";
    while (!validResponse) {
        cin >> response;
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
            cout << "Please enter Y or N: ";
            validResponse = false;
        }
    }
}

void stringMath() {
    bool valRepeat;
    char milesInput[10];
    char mpgInput[10];
    char costInput[10];
    char packagesInput[10];
    char repeatInput[2];

    do {
        // Get user inputs
        do{
            cout << "Please enter in the number of miles driven in a week: ";
            cin >> milesInput;
        } while(!validateInput(milesInput));

        do{
            cout << "\nPlease enter the miles per gallon your vehicle gets: ";
            cin >> mpgInput;
        } while (!validateInput(mpgInput));

        do {
            cout << "\nPlease enter the cost of a gallon of diesel: ";
            cin >> costInput;
        } while (!validateInput(costInput));

        do{
            cout << "\nPlease enter the number of packages delivered per week: ";
            cin >> packagesInput;
        } while (!validateInput(packagesInput));

        // Convert c-strings to appropriate data types
        double miles = atof(milesInput);
        double mpg = atof(mpgInput);
        double costPerGallon = atof(costInput);
        int packages = atoi(packagesInput);

        // Calculate and display total miles, gallons, and cost
        double totalGallons = miles / mpg;
        double totalCost = totalGallons * costPerGallon;

        cout << "\nThe number of miles driven in a week was: " << fixed << setprecision(2) << miles << endl;
        cout << "The amount of fuel used in a week was: " << fixed << setprecision(2) << totalGallons << endl;
        cout << "The cost of fuel for the week was: $" << fixed << setprecision(2) << totalCost << endl;

        // Calculate and display averages
        double avgPackagesPerDay = packages / 7.0;
        double avgMilesPerDay = miles / 7.0;
        double avgGallonsPerDay = totalGallons / 7.0;
        double avgCostPerDay = totalCost / 7.0;

        cout << "The average packages delivered per day: " << fixed << setprecision(2) << avgPackagesPerDay << endl;
        cout << "The average miles driven per day: " << fixed << setprecision(2) << avgMilesPerDay << endl;
        cout << "The average amount of fuel used per day: " << fixed << setprecision(2) << avgGallonsPerDay << endl;
        cout << "The average cost per day: $" << fixed << setprecision(2) << avgCostPerDay << endl;

        // Calculate and display total revenue and profit
        double totalRevenue = packages * 0.37;
        double totalProfit = totalRevenue - totalCost;

        cout << "The total revenue for the week was: $" << fixed << setprecision(2) << totalRevenue << endl;
        cout << "The company made " << fixed << setprecision(2) << totalProfit << " in deliveries this week." << endl;

        // Ask the user if they want to perform another calculation
        cout << "Do you wish to enter another value? (Y or N) ";
        do{
            valRepeat = true;
            cin >> repeatInput;
            if (toupper(repeatInput[0]) != 'Y' && toupper(repeatInput[0]) != 'N') {
                cout << "Please enter Y or N: ";
                valRepeat = false;
            }
        } while (!valRepeat);
    } while (toupper(repeatInput[0]) == 'Y');
    return;
}

bool validateInput(const char* instring) {
    bool valInput = true;
    int decimalCount = 0;  // Count the number of decimal points

    for (int i = 0; i < strlen(instring); i++) {
        if (!isdigit(instring[i])) {
            if (instring[i] == '.' && decimalCount == 0) {
                // Allow one decimal point
                decimalCount++;
            }
            else {
                valInput = false;
            }
        }
    }
    return valInput;
}

void CountElements(const char* inputStr) {
    int alphaCount = 0, numCount = 0, ucCount = 0, lcCount = 0, punctCount = 0, spaceCount = 0;
    for (int i = 0; i < strlen(inputStr); i++) {
        if (isalpha(inputStr[i])) {
            alphaCount++;
            if (isupper(inputStr[i])) {
                ucCount++;
            }
            else if (islower(inputStr[i])) {
                lcCount++;
            }
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
    cout << "\nThe test string is: " << inputStr << endl;
    cout << "\nThe number of alphas = " << alphaCount << endl;
    cout << "The number of digits = " << numCount << endl;
    cout << "The number of uppers = " << ucCount << endl;
    cout << "The number of lowers = " << lcCount << endl;
    cout << "The number of spaces = " << spaceCount << endl;
    cout << "The number of puncts = " << punctCount << endl;
    
}

void cStringManip() {
    char testString[100]; // Increase the size to accommodate input
    char firstName[15];
    char lastName[15];
    char completeName[50];
    char characterArray[50];
    int index;
    char newChar;
    char city[50];
    char completeAddress[MAX_ADDRESS_LENGTH + 30]; // Adjusted size

    // Display testString and its length
    cin.ignore();
    cout << "Enter in a string for test string: ";
    cin.getline(testString, sizeof(testString));
    cout << "The length of " << testString << " is: " << strlen(testString) << endl;

    cout << "\n\nEnter in a first name: ";
    cin.getline(firstName, sizeof(firstName));
    cout << "Enter in a last name: ";
    cin.getline(lastName, sizeof(lastName));

    // Copy first name to completeName
    strcpy_s(completeName, sizeof(completeName), firstName);
    cout << "After strcpy, string completeName is " << completeName << " and the length is " << strlen(completeName) << endl;

    // Concatenate last name to completeName with a space
    strcat_s(completeName, sizeof(completeName), " ");
    strcat_s(completeName, sizeof(completeName), lastName);
    cout << "\nAfter strcat, string completeName is " << completeName << " and the length is " << strlen(completeName) << endl;

    // Enter character and integer, then replace character at specified index
    cout << "\nEnter in a single character: ";
    cin >> newChar;
    cout << "Enter in the character number in the string holding the full name to replace: ";
    cin >> index;
    completeName[index - 1] = newChar;
    cout << "After replacement, string completeName is " << completeName << endl;

    // Enter city and copy to completeAddress using strncpy
    cin.ignore(); // Clear newline character
    cout << "\n\nEnter in a city: ";
    cin.getline(city, sizeof(city));
    
    // Enter state and zip, add to completeAddress using strncat_s
    //cin.ignore(); // Clear newline character
    char state[MAX_ADDRESS_LENGTH];
    char zip[MAX_ADDRESS_LENGTH];
    cout << "Enter a state: ";
    cin.getline(state, sizeof(state));
    //cin.ignore(); // Clear newline character
    cout << "Enter a zip code: ";
    cin.getline(zip, sizeof(zip));

    strncpy_s(completeAddress, sizeof(completeAddress), city, MAX_ADDRESS_LENGTH);
    completeAddress[MAX_ADDRESS_LENGTH] = '\0'; // Ensure null-termination
    cout << "When doing a strncpy of city into completeAddress, max 10, you get: " << completeAddress << endl;
    
    // Compare city and completeAddress using strcmp
    if (strcmp(city, completeAddress) == 0) {
        cout << "\nWhen first copied, city and completeAddress do equal each other." << endl;
    }
    else {
        cout << "\nWhen first copied, city and completeAddress do not equal each other." << endl;
    }

    strncat_s(completeAddress, sizeof(completeAddress), ", ", 2);
    strncat_s(completeAddress, sizeof(completeAddress), state, MAX_ADDRESS_LENGTH);
    strncat_s(completeAddress, sizeof(completeAddress), " ", 1);
    strncat_s(completeAddress, sizeof(completeAddress), zip, MAX_ADDRESS_LENGTH);
    cout << "\nThe complete address is: " << completeAddress << endl;
    cout << "The length of the address is: " << strlen(completeAddress) << " characters.";

    // Search for state in completeAddress using strstr
    char* statePtr = strstr(completeAddress, state);
    if (statePtr != nullptr) {
        cout << "\n\nWhen looking for the string " << "\"" << state << "\"" << " in the name strstr you get: " << statePtr << endl;
    }
    else {
        cout << "State not found in Complete Address." << endl;
    }
}

void scStringManip() {
    // Enter two strings representing part numbers for a laptop
    string partNumber1, partNumber2;
    cin.ignore();
    cout << "\nPlease enter part number 1: ";
    getline(cin, partNumber1);

    cout << "Please enter part number 2: ";
    getline(cin, partNumber2);

    // Enter two strings representing a laptop make and model
    string make, model;
    cout << "\nEnter in the laptop make: ";
    getline(cin, make);
    cout << "Enter in the laptop model: ";
    getline(cin, model);

    // Enter two strings representing a laptop dealer and a city
    string dealer, city;
    cout << "\nEnter in the store where the laptop was purchased: ";
    getline(cin, dealer);
    cout << "Enter the city: ";
    getline(cin, city);

    // Compare and sort the part numbers
    if (partNumber1 == partNumber2) {
        cout << "The part numbers are the same." << endl;
    }
    else {
        // Alphabetically order the part numbers
        string sortedPartNumbers[2] = { partNumber1, partNumber2 };
        sort(sortedPartNumbers, sortedPartNumbers + 2);

        cout << "\nThe part numbers are:  ";
        cout << sortedPartNumbers[0] << " and " << sortedPartNumbers[1] << endl;
    } 

    // Append the model to the make using +=
    make += " " + model;
    cout << "\n\nThe laptop make and model is: " << make << endl;

    // Concatenate the city to the dealer using +
    string completeAddress = dealer + " " + city;
    cout << "\n\nThe laptop was purchased at: " << completeAddress << endl;
}