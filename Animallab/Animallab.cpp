// Samhith Patibandla
// 02/22/2024
// This program demonstrates a simple animal database management system.

#include <iostream>
#include <vector>
#include <cstring> // for strcmp
#include <iomanip> // for setw
using namespace std;

//Global Constants
const string MENU_ONE = "1. Add animal(s)", MENU_TWO = "2. Display animals", MENU_THREE = "3. Search for animal", MENU_FOUR = "4. Display endangered animals", MENU_FIVE = "5. QUIT";
const int CHOICE_ONE = 1, CHOICE_TWO = 2, CHOICE_THREE = 3, CHOICE_FOUR = 4, CHOICE_FIVE = 5;
const int ANIMAL_TYPE_SIZE = 100, ENDANGERED_COUNT = 100;

// Define the structure for Animal records
struct Animal {
    char animalType[ANIMAL_TYPE_SIZE] = "none"; // Initialize animalType to "none"
    int typeCount = 0; // Initialize typeCount to 0
    bool isEndangered = false; // Initialize isEndangered to false
};

// Prototypes
void progIntro();
void addAnimal(vector<Animal>&);
bool isAnimalExists(const vector<Animal>&, const char*);
void displayAnimalRecords(const vector<Animal>&);
void displayEndangeredAnimalRecords(const vector<Animal>&);
void selectSort(vector<Animal>&);
void swap(Animal&, Animal&);
void searchAnimal(const vector<Animal>&, const char*);
bool getExitConfirm();


int main()
{
    bool valFlag = true, valExit = false, valChoice = true;
    int choice = 0;
    char srchAnml[ANIMAL_TYPE_SIZE] = "none";
    progIntro();

    // Dynamically creating Animals vector with no max and initializing with the given data
    vector<Animal> animals{
        {"California Puma", 2005, false},
        {"Bengal Tiger", 97, true},
        {"White Rhino", 45, true},
        {"California Condor", 275, false},
        {"Grey Wolf", 77, true},
        {"Three Toed Sloth", 1725, false}
    };


    do {
        valExit = false;

        do {
            valChoice = true;

            // Displaying the CHOICE options
            cout << endl << MENU_ONE << endl;
            cout << MENU_TWO << endl;
            cout << MENU_THREE << endl;
            cout << MENU_FOUR << endl;
            cout << MENU_FIVE << endl;

            // Prompt the user to enter a choice from the menu.
            cout << "\nEnter the menu choice: ";
            cin >> choice;

            // Use a switch statement to determine the item label and cost.
            switch (choice) {
            case CHOICE_ONE:
                addAnimal(animals);
                break;

            case CHOICE_TWO:
                selectSort(animals);
                displayAnimalRecords(animals);
                break;

            case CHOICE_THREE:
                selectSort(animals);
                cout << "Please enter the name of the animal you are looking for: ";
                cin.ignore();
                cin.getline(srchAnml, ANIMAL_TYPE_SIZE);
                searchAnimal(animals, srchAnml);
                break;

            case CHOICE_FOUR:
                selectSort(animals);
                displayEndangeredAnimalRecords(animals);
                break;

            case CHOICE_FIVE:
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

// Function to display the program introduction
void progIntro() {
    cout << "\t\t\t\t\tCMSY 171 Lab 2\n";
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
        cin >> ws; // Work around for cin.ignore()
        //cin.ignore(); - not working because the first letter in a c string goes missing
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

            bool isEndangered = animCount < ENDANGERED_COUNT;

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
    if (anmls.size() > 0) {
        for (const auto& animal : anmls) {
            if (animal.typeCount > 0 && animal.isEndangered) {
                cout << "Animal: " << animal.animalType << " is " << (animal.isEndangered ? "" : "not ") << "endangered!!\n"; // single line if;
            }
        }
    }
    else {
        cout << "\nThere are " << anmls.size() << " animals in the database.\n\n";
    }
}

// Function to perform Selection Sort
void selectSort(vector<Animal>& anmls) {
    int minIndex = 0;

    for (int start = 0; start < anmls.size() - 1; start++) {
        minIndex = start;
        for (int index = start + 1; index < anmls.size(); index++) {
            if (strcmp(anmls.at(index).animalType, anmls.at(minIndex).animalType) < 0) {
                minIndex = index;
            }
        }
        if (minIndex != start) {
            swap(anmls.at(minIndex), anmls.at(start));
        }
    }
}

// Function to swap two Animal structs
void swap(Animal& a, Animal& b) {
    Animal temp = a;
    a = b;
    b = temp;
}

// Function to perform binary search for an animal by name
void searchAnimal(const vector<Animal>& anmls, const char* name) {
    int left = 0;
    int right = anmls.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(anmls.at(mid).animalType, name);
        if (cmp == 0) {
            // Animal found, display information
            cout << "Animal was found:\n";
            cout << "Animal: " << anmls.at(mid).animalType << endl;
            cout << "Has a count of: " << anmls.at(mid).typeCount << endl;
            cout << "This animal is " << (anmls.at(mid).isEndangered ? "" : "not ") << "endangered!! \n\n\n";
            return;
        }
        else if (cmp < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    // Animal not found, display error message
    cout << "We could not find your animal in the database at this time. Please add the animal into the database." << endl << endl;
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