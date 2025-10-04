// Samhith Patibandla
// 02/29/2024
// This program adds onto the animal data display program integrating files. 

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring> // for strcmp
#include <iomanip> // for setw
#include <algorithm> // for sort function
using namespace std;

//Global Constants
const string MENU_ONE = "1. Add animal(s)", MENU_TWO = "2. Display animals", MENU_THREE = "3. Search for animal", MENU_FOUR = "4. Display endangered animals", MENU_FIVE = "5. QUIT";
const int CHOICE_ONE = 1, CHOICE_TWO = 2, CHOICE_THREE = 3, CHOICE_FOUR = 4, CHOICE_FIVE = 5;
const int ANIMAL_TYPE_SIZE = 25, ENDANGERED_COUNT = 100;
const string BINARY_DAT = "C:/test/animal.dat";
const string TEXT_DAT = "C:/test/species.txt";

// Define the structure for Animal records
struct Animal {
    char animalType[ANIMAL_TYPE_SIZE] = "none"; // Initialize animalType to "none"
    char speciesType[ANIMAL_TYPE_SIZE] = "none";
    int typeCount = 0; // Initialize typeCount to 0
    bool isEndangered = false; // Initialize isEndangered to false
};

// Prototypes
void progIntro();
void addAnimal(vector<Animal>&, const vector<string>&);
void displaySpeciesMenu(const vector<string>&);
void writeAnimal(const vector<Animal>&, fstream&);
void readAnimal(vector<Animal>&, fstream&);
void readSpecies(vector<string>&, fstream&);
bool isAnimalExists(const vector<Animal>&, const char*);
void displayAnimalRecords(const vector<Animal>&);
void displayAnimal(const Animal);
void displayEndangeredAnimalRecords(const vector<Animal>&);
void selectSort(vector<Animal>&);
bool compareAnimals(const Animal&, const Animal&);
void swap(Animal&, Animal&);
void searchAnimalByName(vector<Animal>&);
void updateRecord(fstream&, Animal, Animal&);
void updateRecordInFile(fstream&, const Animal&);
int getIndex(const vector<Animal>&, const Animal&);
bool getExitConfirm();


int main()
{
    bool valFlag = true, valExit = false, valChoice = true;
    int choice = 0;
    char srchAnml[ANIMAL_TYPE_SIZE] = "none";
    progIntro();

    // Dynamically creating Animals vector with no max and initializing with the given data
    vector<Animal> animals;
    vector<string> species;

    fstream anmlFile, speciesFile;

    // Reading data files into vectors
    readAnimal(animals, anmlFile);
    readSpecies(species, speciesFile);

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
                addAnimal(animals, species);
                break;

            case CHOICE_TWO:
                //selectSort(animals);
                displayAnimalRecords(animals);
                break;

            case CHOICE_THREE:
                selectSort(animals);                             
                searchAnimalByName(animals);
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
    species.clear();
    system("pause");
    return 0;
}

// Function to display the program introduction
void progIntro() {
    cout << "\t\t\t\t\tCMSY 171 Lab 3\n";
    cout << "Copyright 2022 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\t\tWelcome to CMSY-171 Animal Count Vector Program\n";
}

// Function to add animal records
void addAnimal(vector<Animal>& anmls, const vector<string>& species) {
    bool valCount = true, valNone = false, valSpecChoice = true;
    Animal newAnimal;

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

            // Display species menu
            displaySpeciesMenu(species);
            do {
                valSpecChoice = true;
                int specChoice;
                cout << "Please enter the number of the species here: ";
                cin >> specChoice;

                if (specChoice >= 1 && specChoice <= species.size()) {
                    strcpy_s(newAnimal.speciesType, species.at(specChoice - 1).c_str());
                }
                else {
                    cout << "Invalid species menu choice. Please try again." << endl;
                    valSpecChoice = false;
                }
            } while (!valSpecChoice);

            cout << "Enter the animal type's count: ";
            do {
                valCount = true;
                cin >> animCount;
                if (animCount < 0) {
                    cout << "Invalid count! Try again: ";
                    valCount = false;
                }
            } while (!valCount);

            bool isEndangered = animCount < ENDANGERED_COUNT;

            
            strcpy_s(newAnimal.animalType, inType);
            newAnimal.typeCount = animCount;
            newAnimal.isEndangered = isEndangered;

            anmls.push_back(newAnimal);

            // Sort animals vector
            sort(anmls.begin(), anmls.end(), compareAnimals);

            // Write animals to file
            fstream outFile;
            writeAnimal(anmls, outFile);
        }
    } while (!valNone);
}

void displaySpeciesMenu(const vector<string> &species) {
    cout << "\nSelect the species from the list:" << endl;
    for (int i = 0; i < species.size(); ++i) {
        cout << i + 1 << ". " << species.at(i) << endl;
    }
}

void writeAnimal(const vector<Animal> &anmls, fstream &inFile) {
    inFile.open(BINARY_DAT, ios::binary | ios::out | ios::trunc);
    if (!inFile.is_open()) {
        cerr << "Error opening animal file for writing." << endl;
        return;
    }

    for (const auto& animal : anmls) {
        inFile.write(reinterpret_cast<const char*>(&animal), sizeof(Animal));
    }

    inFile.close();
}

void readAnimal(vector<Animal> &anmls, fstream &inFile) {
    inFile.open(BINARY_DAT, ios::in | ios::binary);
    // Checking if file opened
    if (!inFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Reading binary data & pushing into animal vector
    Animal temp;
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(Animal))) {
        cout << "\nI am here " << sizeof(Animal) << endl;
        anmls.push_back(temp);
    }

    inFile.close();
}

void readSpecies(vector<string> &species, fstream &inFile) {
    inFile.open(TEXT_DAT, ios::in);
    if (!inFile.is_open()) {
        cerr << "Error opening species file." << endl;
        return;
    }

    string temp;
    while (getline(inFile, temp)) {
        species.push_back(temp);
    }

    inFile.close();
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
            cout << "The species is: " << animal.speciesType << endl;
            cout << "There is a population of: " << animal.typeCount;
            cout << ".  This animal is " << (animal.isEndangered ? "" : "not ") << "endangered!! \n\n\n"; // single line if  
        }
    }
}

// Function to display one animal record
void displayAnimal(const Animal a) {       
            cout << "Animal: " << a.animalType << endl;
            cout << "The species is: " << a.speciesType << endl;
            cout << "There is a population of: " << a.typeCount;
            cout << ".  This animal is " << (a.isEndangered ? "" : "not ") << "endangered!! \n\n\n"; // single line if             
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

bool compareAnimals(const Animal& a, const Animal& b) {
    return strcmp(a.animalType, b.animalType) < 0;
}

// Function to swap two Animal structs
void swap(Animal& a, Animal& b) {
    Animal temp = a;
    a = b;
    b = temp;
}

void updateRecord(fstream& inFile, Animal existingAnimal, Animal &updatedAnimal) {
    bool valSpecChoice = true, valUpdChoice = true;
    char updChoice = ' ';
    //char updName[ANIMAL_TYPE_SIZE];
    inFile.open(BINARY_DAT, ios::binary | ios::in | ios::out);
    if (!inFile.is_open()) {
        cerr << "Error opening animal file for updating." << endl;
        return;
    }

    while (inFile.read(reinterpret_cast<char*>(&existingAnimal), sizeof(Animal))) {
        if (strcmp(existingAnimal.animalType, updatedAnimal.animalType) == 0) {
            cout << "Animal was found:" << endl;
            displayAnimal(existingAnimal);
            do{
                valUpdChoice = true;              
                cout << "Do you want to update the information? (Y/N): ";
                cin >> updChoice;

                if (toupper(updChoice) != 'Y' && toupper(updChoice) != 'N') {
                    cout << "Error - please enter Y or N only.  Please reenter.\n\n";
                    valUpdChoice = false;
                }
            } while (!valUpdChoice);

            if (toupper(updChoice) == 'Y') {
                cout << "Enter animal name: ";
                cin.ignore();
                cin.getline(updatedAnimal.animalType, ANIMAL_TYPE_SIZE);

                vector<string> specs;
                fstream specFile;

                // Reading data files into vectors
                readSpecies(specs, specFile);

                // Display species menu
                displaySpeciesMenu(specs);
                do {
                    valSpecChoice = true;
                    int specChoice = 0;
                    cout << "Please enter the number of the species here: ";
                    cin >> specChoice;
 
                    // Copying string value to cstring
                    /*copy(specs.at(specChoice - 1).begin(), specs.at(specChoice - 1).end(), updName);
                    updName[specs.at(specChoice - 1).length()] = '\0';*/

                    if (specChoice >= 1 && specChoice <= specs.size()) {
                        strcpy_s(updatedAnimal.speciesType, specs.at(specChoice - 1).c_str());
                    }
                    else {
                        cout << "Invalid species menu choice. Please try again." << endl;
                        valSpecChoice = false;
                    }
                } while (!valSpecChoice);
                //cin.getline(updatedAnimal.speciesType, ANIMAL_TYPE_SIZE);
                specs.clear();

                cout << "Enter the animal type's count: ";
                cin >> updatedAnimal.typeCount;

                updatedAnimal.isEndangered = updatedAnimal.typeCount < ENDANGERED_COUNT;

                // Save updated record
                inFile.seekp(-static_cast<int>(sizeof(Animal)), ios::cur);
                updateRecordInFile(inFile, updatedAnimal);
                cout << "Record updated successfully." << endl;
            }
            return;
        }
    }

    cout << "Animal not found." << endl;
    inFile.close();
}

void updateRecordInFile(fstream& inFile, const Animal& updatedAnimal) {
    inFile.write(reinterpret_cast<const char*>(&updatedAnimal), sizeof(Animal));
}

// Function to perform binary search for an animal by name
void searchAnimalByName(vector<Animal>& anmls) {
    char searchName[ANIMAL_TYPE_SIZE];
    int i = 0;
    cout << "Enter the name of the animal to search: ";
    cin.ignore();
    cin.getline(searchName, ANIMAL_TYPE_SIZE);

    fstream file;
    for (const auto& animal : anmls) {
        if (strcmp(animal.animalType, searchName) == 0) {
            Animal updatedAnimal = animal;
            for (i = 0; i < anmls.size(); ++i)
            {
                if (anmls[i].animalType == animal.animalType)
                    break;
            }
            //cout << "To be updated " << i << " " << anmls[i].animalType << endl;
            updateRecord(file, animal, updatedAnimal);
            anmls.at(i) = updatedAnimal;

            return;
        }
    }

    cout << "Animal not found." << endl;
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