
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <string>
#include <cstring> // for strcm
#include <iomanip> // for setw
#include <algorithm> // for sort function
using namespace std;

//Global Constants
const int ANIMAL_TYPE_SIZE = 25, ENDANGERED_COUNT = 100;
const string BINARY_DAT = "C:/test/animal.dat";
const string TEXT_DAT = "C:/test/species.txt";

// Define the structure for Animal records
struct Animal {
    char animalType[ANIMAL_TYPE_SIZE] = "none"; // Initialize animalType to "none"
    char speciesType[ANIMAL_TYPE_SIZE] = "none";
    int typeCount = 0; // Initialize typeCount to 0
    bool isEndangered = false; // Initialize isEndangered to false

    struct Animal* next = nullptr; // Pointer to the next Animal in the list
};

struct Animalread {
    char animalType[ANIMAL_TYPE_SIZE]; // No need to specify size here
    char speciesType[ANIMAL_TYPE_SIZE];
    int typeCount;
    bool isEndangered;
};

// Prototypes
bool compareAnimalType(const Animal&, const Animal&);
void readAnimal(list<Animal>&, fstream&);
//void readSingleAnimal(list<Animal>&, fstream&);
void readSpecies(vector<string>&, fstream&);
void displayAnimalRecords(const list<Animal>&);

int main()
{
    bool valFlag = true;
    char srchAnml[ANIMAL_TYPE_SIZE] = "none";

    // Dynamically creating Animals list with no max and initializing with the given data
    //vector<Animal> animals;
    list<Animal> animals;
    vector<string> species;

    fstream anmlFile, speciesFile;

    // Reading data files into vectors
    readAnimal(animals, anmlFile);
    readSpecies(species, speciesFile);

    displayAnimalRecords(animals);

    animals.clear();
    species.clear();
    system("pause");
    return 0;
}


// Custom comparison function for sorting by animalType
bool compareAnimalType(const Animal& a, const Animal& b) {
    return strcmp(a.animalType, b.animalType) < 0;
}


void readAnimal(list<Animal>& anmls, fstream& inFile) {
    inFile.open(BINARY_DAT, ios::in | ios::binary);
    if (!inFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Read data into a buffer until the end of the file
    char buffer[sizeof(Animalread)];
    while (inFile.read(buffer, sizeof(Animalread))) {
        // Create a new Animal object
        Animal* newAnimal = new Animal;

        // Copy data from the buffer to the Animal object
        memcpy(newAnimal, buffer, sizeof(Animalread));

        // Null-terminate the character arrays
        newAnimal->animalType[sizeof(newAnimal->animalType) - 1] = '\0';
        newAnimal->speciesType[sizeof(newAnimal->speciesType) - 1] = '\0';

        // Add the new animal to the front of the list
        anmls.push_front(*newAnimal);

        // Reset the file pointer to the position after the last read
        inFile.clear();
        inFile.seekg(0, ios::cur);
    }

    inFile.close();
}





void readSpecies(vector<string>& species, fstream& inFile) {
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

// Function to display all animal records
void displayAnimalRecords(const list<Animal>& anmls) {
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


