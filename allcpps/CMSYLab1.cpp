// Samhith Patibandla
// 02/15/2024
// This program manages animal records and provides options to add, display, and manage them.

#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
using namespace std;

//Global Constants
const string MENU_ONE = "1. Add animal(s)", MENU_TWO = "2. Display animals", MENU_THREE = "3. Display endangered animals", MENU_FOUR = "4. QUIT";
const int ANIMAL_TYPE_SIZE = 100;

// Define the structure for Animal records
struct Animal {
    char animalType[ANIMAL_TYPE_SIZE] = "none"; // Initialize animalType to "none"
    int typeCount = 0; // Initialize typeCount to 0
    bool isEndangered = false; // Initialize isEndangered to false
};

// Prototype Functions
void progIntro();
void addAnimal(vector<Animal>&);
bool isAnimalExists(const vector<Animal>&, const char*);
void displayAnimalRecords(const vector<Animal>&);
void displayEndangeredAnimalRecords(const vector<Animal>&);
bool getExitConfirm();

int main()
{
    bool valFlag = true, valExit = false, valChoice = true;
    int choice = 0;
    progIntro();

    // Dynamically creating Animals vector with no max
    vector<Animal> animals{};

    do {
        valExit = false;

        do {
            valChoice = true;

            // Displaying the menu options
            cout << endl << MENU_ONE << endl;
            cout << MENU_TWO << endl;
            cout << MENU_THREE << endl;
            cout << MENU_FOUR << endl;

            // Prompt the user to enter a choice from the menu.
            cout << "\nEnter the menu choice: ";
            cin >> choice;

            // Use a switch statement to determine the item label and cost.
            switch (choice) {
            case 1:
                addAnimal(animals);
                break;

            case 2:
                displayAnimalRecords(animals);
                break;

            case 3:
                displayEndangeredAnimalRecords(animals);
                break;

            case 4:
                valExit = getExitConfirm();
                continue;

            default:
                cout << "Invalid choice! Try again: \n";
                valChoice = false;
                break;
            }
        } while (!valChoice);

    } while (!valExit);

    animals.clear();
    system("pause");
    return 0;
}

// Function to display program introduction
void progIntro() {
    cout << "\t\t\t\t\tCMSY 171 Lab 1\n";
    cout << "Copyright 2022 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\t\tWelcome to CMSY-171 Animal Count Vector Program\n";
}

// Function to add animal records
void addAnimal(vector<Animal>& anmls) {
    bool valCount = true, valNone = false;

    do {
        char inType[ANIMAL_TYPE_SIZE] = { "" }, lowType[ANIMAL_TYPE_SIZE] = { "" };
        int animCount = 0;
        cout << "Enter animal type (or 'none' to stop): ";
        cin >> ws;
        cin.getline(inType, ANIMAL_TYPE_SIZE);

        // Convert input to lowercase and preserving original case
        for (int j = 0; j < strlen(inType); ++j) {
            lowType[j] = tolower(inType[j]);
        }

        valNone = (strcmp(lowType, "none") != 0 ? false : true);

        if (!valNone) {
            if (isAnimalExists(anmls, inType)) {
                cout << "Error: Animal already exists in the records. Please re-enter.\n";
                continue;
            }

            cout << "Enter count for " << inType << ": ";
            do {
                valCount = true;
                cin >> animCount;
                if (animCount < 0) {
                    cout << "Invalid count! Try again: ";
                    valCount = false;
                }
            } while (!valCount);

            bool isEndangered = animCount < 100;

            Animal newAnimal;
            strcpy_s(newAnimal.animalType, inType);
            newAnimal.typeCount = animCount;
            newAnimal.isEndangered = isEndangered;

            anmls.push_back(newAnimal);
        }
    } while (!valNone);
}

// Function to check if an animal already exists in the records
bool isAnimalExists(const vector<Animal>& anmls, const char* anmType) {
    for (const auto& record : anmls) {
        if (strcmp(record.animalType, anmType) == 0) {
            return true;
        }
    }
    return false;
}

// Function to display all animal records
void displayAnimalRecords(const vector<Animal>& anmls) {
    cout << "\nThere are " << anmls.size() << " animals in the database.\n\n";
    for (const auto& animal : anmls) {
        if (animal.typeCount > 0) {
            cout << "Animal: " << animal.animalType << endl;
            cout << "Has a count of: " << animal.typeCount << endl;
            cout << "This animal is " << (animal.isEndangered ? "" : "not ") << "endangered!! \n\n\n"; // single line if  
        }
    }
}

// Function to display only endangered animal records
void displayEndangeredAnimalRecords(const vector<Animal>& anmls) {
    for (const auto& animal : anmls) {
        if (animal.typeCount > 0 && animal.isEndangered) {
            cout << "Animal: " << animal.animalType << " is " << (animal.isEndangered ? "" : "not ") << "endangered!!\n"; // single line if;
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