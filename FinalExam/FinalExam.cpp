// Samhith Patibandla
// 12/11/2023
// CMSY 141/181 – Final Exam
// This program manages family phone data, including input validation, average memory calculation, and display of information.

// Standard libraries
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Global Constant for Max string length for phone and member name
const int MAX_SIZE = 50;

// Structure to represent family phone details
struct FamilyPhoneDetails{
	char name[MAX_SIZE];
	char phoneType[MAX_SIZE];
	int totalApps, totalMemory;
	double appUsage;
};

// Prototype functions 
void inputFamilyData(FamilyPhoneDetails [], int);
double getAvgMemory(const FamilyPhoneDetails &);
void displayFamily(const FamilyPhoneDetails *, int);

// Function Main
int main()
{
	int familySize; // variable for number of family members
	bool valSize; // validation flag for family size

	do {
		valSize = true;
        // Prompt the user for the number of family members
		cout << "\nHow many family members do you have: ";
		cin >> familySize;

        // Validate the input for the number of family members
		if (familySize < 2 || familySize > 7) {
			cout << "Error - please enter in a number between 2 and 7\n";
			valSize = false;
		}
	} while (!valSize); // End of do

	// Dynamically allocate an array for FamilyPhoneDetails
	FamilyPhoneDetails* familyMembers = new FamilyPhoneDetails[familySize];

    // Calling the function to get family details
    inputFamilyData(familyMembers, familySize);

    // Callling function to display family details
    displayFamily(familyMembers, familySize);

    // Deallocate the dynamic array
    delete[] familyMembers;

    // Pause the console before exiting
    system("pause");
    return 0;
}

// Function for data entry using array notation
void inputFamilyData(FamilyPhoneDetails family[], int size) {
    bool valFlag;

    for (int i = 0; i < size; i++) {
        // Prompt the user for the name of each family member
        cout << "\nEnter name " << i + 1 << ": ";
        cin >> ws; // Work around for cin.ignore()
        //cin.ignore();
        cin.getline(family[i].name, MAX_SIZE);

        // Prompt the user for the phone model owned by each family member
        cout << "Enter the model owned by " << family[i].name << ": ";
        cin >> ws; // Work around for cin.ignore()
        //cin.ignore();
        cin.getline(family[i].phoneType, MAX_SIZE);

        do {
            valFlag = true;
            // Prompt the user for the total memory of the phone
            cout << "Enter the total memory of the phone in Gigabytes: ";
            cin >> family[i].totalMemory;

            // Validate the input for total memory
            if (family[i].totalMemory <= 0) {
                cout << "Error - please enter in a postitive number!" << endl << endl;
                valFlag = false;
            }
        } while (!valFlag); // End of do

        do {
            valFlag = true;
            // Prompt the user for the total number of applications on the phone
            cout << "Enter in the total number of applications on the phone: ";
            cin >> family[i].totalApps;

            // Validate the input for the total number of applications
            if (family[i].totalApps <= 0) {
                cout << "Error - please enter in a postitive number!" << endl << endl;
                valFlag = false;
            }
        } while (!valFlag); // End of do

        // Call the function to calculate average memory per app
        family[i].appUsage = getAvgMemory(family[i]);
    } // End of for loop
}

// Function to calculate average memory per app
double getAvgMemory(const FamilyPhoneDetails& member) {
    return member.totalMemory / double(member.totalApps); // Converting int to double in denominator for returning double value
}

// Function to display the family report
void displayFamily(const FamilyPhoneDetails* family, int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        // Display information for each family member
        cout << "Name " << i + 1 << ": " << family[i].name << endl;
        cout << "The model owned by " << family[i].name << ": " << family[i].phoneType << endl;
        cout << "The total memory of the phone is: " << family[i].totalMemory << "GB" << endl;
        cout << "The total number of applications on the phone is: " << family[i].totalApps << endl;
        cout << "The average memory used per application is: " << fixed << setprecision(2) << family[i].appUsage << "GB" << endl << endl;
    } // End of for loop
    cout << endl;
}