// Samhith Patibandla
// 02/06/2024
// This program implements an animal count management system.

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// Global constants
const int MIN_RECORDS = 2, MAX_RECORDS = 5, ANIMAL_TYPE_SIZE = 100;

struct Animal {
    const char* animalType;
    int typeCount;
    bool isEndangered;

    // Constructor with default values
    Animal() : animalType("none"), typeCount(0), isEndangered(false) {}
};

// Prototype Functions
void progIntro();
void addAnimal(Animal[], int);
void displayAnimals(const Animal[], const int);
bool getExitConfirm();

int main()
{
    bool valFlag = true, valExit = false, valChoice = true;
    int numAnimals = 0, choice = 0;
    progIntro();

    
    // Ask the user for the number of cars
    cout << "\nHow many animal records would you like to store (5 max): ";
    // Validate the number of cars input
    do {
        valFlag = true;     
        cin >> numAnimals;

        if (numAnimals < MIN_RECORDS || numAnimals > MAX_RECORDS) {
            cout << "Invalid entry! Try again: ";
            valFlag = false;
        }
    } while (!valFlag);

    // Dynamically allocate an array of Car structures
    Animal* animals = new Animal[numAnimals];

    do {
        valExit = false;       
        
        do {
            valChoice = true;

            // Displaying the menu options
            cout << "\n1. Add animal(s)\n";
            cout << "2. Display animals\n";
            cout << "3. Quit\n";

            // Prompt the user to enter a choice from the menu.
            cout << "\nEnter the menu choice: ";
            cin >> choice;

            // Use a switch statement to determine the item label and cost.
            switch (choice) {
            case 1:
                addAnimal(animals, numAnimals);
                break;

            case 2:
                displayAnimals(animals, numAnimals);
                break;

            case 3:
                valExit = getExitConfirm();
                continue;

            default:
                cout << "Invalid choice! Try again: \n";
                valChoice = false;
                break;
            }
        } while (!valChoice);

    } while (!valExit);

    // Deallocate the memory allocated for the array
    delete[] animals;

    system("pause");
    return 0;
}

void progIntro() {
    cout << "\t\t\t\t\tCMSY 171 Lab 0\n";
    cout << "Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\t\t\tWelcome to the CMSY-171 Animal Count Program\n";
}

void addAnimal(Animal inAnimals[], int size) {
    // Static variable to track the number of records stored
    static int recEntered = 0; 
    bool valNone = false, valCount = true;

    // Loop to input animal records
    for (int i = recEntered; i < size; ++i) {
        cout << "Please enter an animal type (none to stop): ";
        char inType[ANIMAL_TYPE_SIZE], lowType[ANIMAL_TYPE_SIZE] = {""};
        cin >> ws;
        cin.getline(inType, ANIMAL_TYPE_SIZE);

        // Convert input to lowercase and preserving original case
        for (int j = 0; j < strlen(inType); ++j) {
            lowType[j] = tolower(inType[j]);
        }

        // Check if the input is "none"
        if (strcmp(lowType, "none") == 0) {
            break;
        }
        // Set the animal type
        inAnimals[i].animalType = _strdup(inType); // Allocate memory for the animal type

        // Input the animal count
        cout << "Enter the animal type's count: ";
        do{
            valCount = true;    
            cin >> inAnimals[i].typeCount;
            cin.ignore(); // Ignore the newline character left in the input buffer
            if (inAnimals[i].typeCount < 0) {
                cout << "Invalid count! Try again: ";
                valCount = false;
            }
        } while (!valCount);

        // Check if the animal is endangered
        if (inAnimals[i].typeCount < 100) {
            inAnimals[i].isEndangered = true;
        }

        recEntered++;
    }
}

void displayAnimals(const Animal inAnimals[], const int size) {
    // Loop to display animal records
    for (int i = 0; i < size; ++i) {
        // Check if the animal record is not empty
        if (inAnimals[i].animalType != "none") {
            cout << "\nAnimal: " << inAnimals[i].animalType << endl;
            cout << "Has a count of: " << inAnimals[i].typeCount << endl;
            cout << "This animal is " << (inAnimals[i].isEndangered ? "" : "not ") << "endangered!! \n\n\n"; // single line if       
        }
    }
}

// Function to get confirmation for exiting the program
bool getExitConfirm() {
    bool confirmation, valconfirm;
    char userResp;
    cout << "Do you wish to exit the program (Y or N): ";
    do {
        valconfirm = true;
        cin >> userResp;
        userResp = tolower(userResp);

        if (userResp == 'y') {
            confirmation = true;
        }
        else if (userResp == 'n') {
            confirmation = false;
        }
        else {
            valconfirm = false;
            cout << "Please enter Y or N: ";
        }
    } while (!valconfirm);
    return confirmation;
}