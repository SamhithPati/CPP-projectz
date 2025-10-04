// Samhith Patibandla
// 12/04/2023
// This program is a string editor that allows users to perform various operations on a string.

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Global constant initialization
const int MAX_STR_LENGTH = 80;

// Prototype Initialization
void showCopyright();
string enterString();
bool isValidString(const string& );
void replaceCharacter(string& );
void replaceAllInstances(string&);
void changeCase(string&);
void insertElement(string&);
void removeElement(string&);
void replaceWord(string&);
void reverseString(string&);
void resetString(string& , string&);
bool getExitConfirm();

int main()
{
    bool valChoice, valExit;
    int choice;
    string editString = "", orgString;  // Initializing to an empty string
    showCopyright();

    do {
        valExit = false;
        cout << "\nString Editor Menu\n";
        // Displaying the menu options
        cout << "\t1 - Input a String\n";
        cout << "\t2 - Replace Single Element in String\n";
        cout << "\t3 - Replace Multiple Elements in String\n";
        cout << "\t4 - Change Case of Elements in String\n";
        cout << "\t5 - Insert Single Element in String\n";
        cout << "\t6 - Remove Single Element in String\n";
        cout << "\t7 - Update One Word in String\n";
        cout << "\t8 - Reverse String\n";
        cout << "\t9 - Reset to Original String\n";
        cout << "\t10 - Exit Program\n";

        do {
            valChoice = true;
            // Prompt the user to enter a choice from the menu.
            cout << "\nPlease enter menu choice: ";
            cin >> choice;

            // Use a switch statement to determine the item label and cost.
            switch (choice) {
            case 1:
                editString = enterString();
                orgString = editString;
                break;

            case 2:
                if (isValidString(editString)) {
                    replaceCharacter(editString);
                }
                else {
                    cout << "ERROR - YOU MUST ENTER A STRING FIRST. PLEASE SELECT OPTION 1!!\n";
                }
                break;

            case 3:
                if (isValidString(editString)) {
                    replaceAllInstances(editString);
                }
                else {
                    cout << "ERROR - YOU MUST ENTER A STRING FIRST. PLEASE SELECT OPTION 1!!\n";
                }
                break;

            case 4:
                if (isValidString(editString)) {
                    changeCase(editString);
                }
                else {
                    cout << "ERROR - YOU MUST ENTER A STRING FIRST. PLEASE SELECT OPTION 1!!\n";
                }
                break;

            case 5:
                if (isValidString(editString)) {
                    insertElement(editString);
                }
                else {
                    cout << "ERROR - YOU MUST ENTER A STRING FIRST. PLEASE SELECT OPTION 1!!\n";
                }
                break;

            case 6:
                if (isValidString(editString)) {
                    removeElement(editString);
                }
                else {
                    cout << "ERROR - YOU MUST ENTER A STRING FIRST. PLEASE SELECT OPTION 1!!\n";
                }
                break;

            case 7:
                if (isValidString(editString)) {
                    replaceWord(editString);
                }
                else {
                    cout << "ERROR - YOU MUST ENTER A STRING FIRST. PLEASE SELECT OPTION 1!!\n";
                }
                break;

            case 8:
                if (isValidString(editString)) {
                    reverseString(editString);
                }
                else {
                    cout << "ERROR - YOU MUST ENTER A STRING FIRST. PLEASE SELECT OPTION 1!!\n";
                }
                break;

            case 9:
                if (isValidString(editString)) {
                    resetString(editString, orgString);
                }
                else {
                    cout << "ERROR - YOU MUST ENTER A STRING FIRST. PLEASE SELECT OPTION 1!!\n";
                }
                break;

            case 10:
                valExit = getExitConfirm();
                continue;

            default:
                cout << "ERROR:  You must enter in a valid menu item. Please try again";
                valChoice = false;
                break;
            }
        } while (!valChoice);
    } while (!valExit);

    system("pause");
    return 0;
}

// Function to display copyright information
void showCopyright() {
    cout << "\t\t\tCMSY 141 Extra Credit Lab";
    cout << "\nCopyright 2022 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\t\t\tWelcome to CMSY-141 Line Editor Program\n";
}

// Function to input a string from the user
string enterString() {
    string userInput;

    cout << "\nPlease enter in the string you want to edit: ";
    cin.ignore();
    getline(cin, userInput);

    // Ensure the entered string does not exceed the maximum size
    if (userInput.length() > MAX_STR_LENGTH) {
        cerr << "Error: String exceeds maximum size. Truncating to " << MAX_STR_LENGTH << " characters." << endl;
        userInput.resize(MAX_STR_LENGTH);
    }
    cout << "The current contents of this string is: " << userInput << endl;
    cout << "The length of the string is: " << userInput.length() << endl;
    return userInput;
}

// Function to check if a string is valid (not empty)
bool isValidString(const string& str) {
    return !str.empty();
}

// Function to replace a single character in the string
void replaceCharacter(string& str) {
    char newChar;
    int charPosition;

    // Input the new character
    cout << "Enter in a single character: ";
    cin >> newChar;

    // Input the character position
    cout << "Enter in the character number in the string holding the character to replace: ";
    cin >> charPosition;

    // Check for the validity of the character position
    if (charPosition < 1 || charPosition > str.length()) {
        cerr << "Error: Invalid character position. Please enter a position between 1 and " << str.length() << "." << endl;
        return;
    }

    // Replace the character
    str[charPosition - 1] = newChar;

    // Display success message along with the new string and string size
    cout << "Character successfully replaced." << endl;
    cout << "The current contents of this string is: " << str << endl;
    cout << "The length of the string is: " << str.length() << endl;
}

// Function to replace all instances of a character in the string
void replaceAllInstances(string& str) {
    int instancesReplaced = 0;
    char oldChar, newChar;

    // Input the new character
    cout << "Enter in a character from the current string: ";
    cin >> oldChar;

    // Input the new character
    cout << "Enter in the replacement character: ";
    cin >> newChar;

    // Iterate through the string and replace all instances of oldChar with newChar
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
            instancesReplaced++;
        }
    }

    // Display success message along with the new string and string size
    cout << instancesReplaced << " characters succesfully replaced in the string.\n";
    cout << "The current contents of this string is: " << str << endl;
    cout << "The length of the string is: " << str.length() << endl;
}

// Function to change the case of all letters in the string
void changeCase(string& str) {
    char userChoice;
    bool valChoice;

    // Confirm with the user if they want to make letters uppercase or lowercase
    cout << "Do you want to change all the letters to uppper or lower case? (U or L) ";
    do {
        valChoice = true;
        cin >> userChoice;
        userChoice = toupper(userChoice);

        // Check the validity of the user's choice
        if (userChoice != 'U' && userChoice != 'L') {
            cerr << "Please enter U or L: ";
            valChoice = false;
        }
    } while (!valChoice);

    // Change the case of all alpha characters based on the user's choice
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            if (userChoice == 'U') {
                str[i] = toupper(str[i]);
            }
            else {
                str[i] = tolower(str[i]);
            }
        }
    }

    // Display success message along with the new string and string size
    cout << "All letters set to " << (userChoice == 'U' ? "upper" : "lower") << " case successful!\n";
    cout << "The current contents of this string is: " << str << endl;
    cout << "The length of the string is: " << str.length() << endl;
}

// Function to insert a single element into the string
void insertElement(string& str) {
    char newChar;
    int charPosition;
    bool valPos;

    // Check if the current string is at the maximum size
    if (str.length() >= MAX_STR_LENGTH) {
        cerr << "Error: The string is already at the maximum size. Insertion is not allowed." << endl;
        return;
    }

    // Input the new character
    cout << "Enter in a single character: ";
    cin >> newChar;
    
    // Input the character position
    cout << "Enter the character number and the new character will be inserted after: ";

    do{
        valPos = true;
        cin >> charPosition;

        // Check for the validity of the character position
        if (charPosition < 1 || charPosition > str.length() + 1) {
            cerr << "Error: Invalid character position. Please enter a position between 1 and " << str.length() + 1 << "." << endl;
            valPos = false;
        }
    } while (!valPos);

    // Insert the new character at the appropriate spot
    str.insert(charPosition, 1, newChar);

    // Display success message along with the new string and string size
    cout << "Character successfully inserted\n";
    cout << "The current contents of this string is: " << str << endl;
    cout << "The length of the string is: " << str.length() << endl;
}

// Function to remove a single element from the string
void removeElement(string& str) {
    int charPosition;
    bool valPos;
    // Check if the current string has only one character
    if (str.length() <= 1) {
        cerr << "Error: The string has only one character. Removal is not allowed." << endl;
        return;
    }

    // Input the character position
    cout << "Enter the character number to be removed: ";

    do {
        valPos = true;
        cin >> charPosition;

        // Check for the validity of the character position
        if (charPosition < 1 || charPosition > str.length()) {
            cerr << "\nError, character number past end of line; Please reenter: ";
            valPos = false;
        }
    } while (!valPos);
    // Remove the character from the appropriate spot
    str.erase(charPosition - 1, 1);

    // Display success message along with the new string and string size
    cout << "Character successfully removed.\n";
    cout << "The current contents of this string is: " << str << endl;
    cout << "The length of the string is: " << str.length() << endl;
}

// Function to replace a single word in the string with another word
void replaceWord(string& str) {
    string oldWord, newWord;

    // Input the word to be replaced
    cout << "Please enter in the word you want to change: ";
    cin >> oldWord;

    // Check if the old word is present in the string
    int pos = str.find(oldWord);
    if (pos == string::npos) {
        cerr << "Error:  This word is not in the current string!" << endl;
        goto printString;
    }

    // Input the replacement word
    cout << "Please enter in the new word: ";
    cin >> newWord;

    // Replace the old word with the new word
    str.replace(pos, oldWord.length(), newWord);

printString:
    cout << "The current contents of this string is: " << str << endl;
    cout << "The length of the string is: " << str.length() << endl;
}

// Function to reverse the string
void reverseString(string& str) {
    // Use the reverse algorithm to reverse the string
    reverse(str.begin(), str.end());

    // Display success message along with the new string and string size
    cout << "String reversal successfull.\n";
    cout << "The current contents of this string is: " << str << endl;
    cout << "The length of the string is: " << str.length() << endl;
}

// Function to reset the string back to the original string value
void resetString(string& str, string& orig) {
    char userChoice;
    bool valReset;
    
    // Confirm with the user if they really want to reset
    cout << "Are you sure you want to reset the string? (Y or N): ";
    do {
        valReset = true;
        cin >> userChoice;
        userChoice = toupper(userChoice);

        if (userChoice == 'Y') {
            // Reset the string to the original value
            str = orig;

            // Display success message along with the new string and string size
            cout << "Reset Successful!\n";
            cout << "The current contents of this string is: " << str << endl;
            cout << "The length of the string is: " << str.length() << endl;
        }
        else if (userChoice == 'N') {
            cout << "Reset canceled. Current string remains unchanged." << endl;
        }
        else {
            cerr << "Please enter Y or N: ";
            valReset = false;
        }
    } while (!valReset);
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