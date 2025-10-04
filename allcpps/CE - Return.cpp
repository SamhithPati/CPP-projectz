// Samhith Patibandla
// 10/07/2023
// This program uses functions for a conversion calculator that allows users to convert feet to
// meters, Fahrenheit to Celsius, and pounds to kilograms and validates all user inputs.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//function for program title, copyright, and intro
void showCopyright() {
	cout << "CE - Return\n";
	cout << "Copyright 2021 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";
	cout << "\tWelcome to the Conversion Caluclator Program\n\n";
}

//Function displays menu and gets user choice, validates, and returns choice
int getUserChoice() {
    //Declaring variables
    int choice;
    bool valSubchoice;
    //Begining of do loop 
    do {
            //Outputs menu for user
            cout << "Menu of options:\n";
            cout << setw(32) << "1. - Convert feet to meters\n";
            cout << setw(40) << "2. - Convert farenheight to celcius\n";
            cout << setw(38) << "3. - Convert pounds to killograms\n";
            cout << setw(26) << "4. - Exit the program\n";

            // Prompt the user to enter a choice from the menu.
            cout << "Please make a selection: ";
            cin >> choice;
            
            if (choice > 0 && choice <= 4) {
                valSubchoice = true;
            } //End if         
            else {
                cout << "Error - Invalid choice, please reenter!! \n\n";
                valSubchoice = false;
            } //end else        
    } while (!valSubchoice); //End while loop
    return choice;
}

//Function for getting length in feet and validating
double getUserLength() {
    //Declaring variables
    double lengthFt;
    bool valInput;
    //Begining of do loop 
    do {
        //Outputs menu for user
        valInput = true;

        // Prompt the user to enter a choice from the menu.
        cout << "Please enter the length in feet: ";
        cin >> lengthFt;

        if (lengthFt < 0) {
            cout << "Error - The length cannot be below zero. Please reenter.\n\n";
            valInput = false;
        } //End if
    } while (!valInput); //End while loop
    return lengthFt;
}

//Function for converting feet to meters
double convertLength(double feet) {
    //Declaring variables
    double lengthMts;       

    lengthMts = feet / 3.281; //Formula Calc
    return lengthMts;
}

//Function for getting temperature in farenheight and validating
double getTemperature() {
    //Declaring variables
    double tempF;
    bool valInput;
    //Begining of do loop 
    do {
        //Outputs menu for user
        valInput = true;

        // Prompt the user to enter a choice from the menu.
        cout << "Please enter the temperature in farenheight: ";
        cin >> tempF;

        if (tempF < -459.67) {
            cout << "Error - The temp cannot be below absolute zero (-459.67). Please reenter.\n\n";
            valInput = false;
        } //End if
    } while (!valInput); //End while loop
    return tempF;
}

//Function for converting farenheight to celsius
double convertTemp(double farHt) {
    //Declaring variables
    double cels;

    cels = (farHt - 32) * 5/9; //Formula Calc
    return cels;
}

//Function for getting weight in pounds and validating
double getWeight() {
    //Declaring variables
    double weightLb;
    bool valInput;
    //Begining of do loop 
    do {
        //Outputs menu for user
        valInput = true;

        // Prompt the user to enter a choice from the menu.
        cout << "Please enter the weight in pounds: ";
        cin >> weightLb;

        if (weightLb < 0) {
            cout << "Error - The weight cannot be below zero. Please reenter.\n";
            valInput = false;
        } //End if
    } while (!valInput); //End while loop
    return weightLb;
}

//Function for converting pounds to killograms
double convertWeight(double lbs) {
    //Declaring variables
    double kgs;

    kgs = lbs / 2.205; //Formula Calc
    return kgs;
}

bool getExitConfirm() {
    bool confirmation, valconfirm;
    char userResp;
    do {
        valconfirm = true;
        cout << "Do you want to exit the program(y/n): ";
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
            cout << "Error - Only y or n is valid, please reenter!!\n\n";
        }
    } while (!valconfirm);
    return confirmation;
}

int main()
{
    bool confirm;

    showCopyright(); //showing copyright
    do {
        confirm = false;
        int userChoice;
        double userInput, result;
        string opLbl, ipLbl;

        userChoice = getUserChoice(); //getting user choice from menu  

        switch (userChoice) {
        case 1:
            userInput = getUserLength(); //getting length in feet
            result = convertLength(userInput); //converting feet to meters
            opLbl = "meters";
            ipLbl = "feet";
            cout << fixed << setprecision(2) << userInput << " " << ipLbl << " is equal to " << result << " " << opLbl << endl << endl;
            break;
        case 2:
            userInput = getTemperature(); //getting temperature in farenheight
            result = convertTemp(userInput); //converting farenheight to celsius
            opLbl = "degrees Celsius";
            ipLbl = "degrees Farenheight";
            cout << fixed << setprecision(2) << userInput << " " << ipLbl << " is equal to " << result << " " << opLbl << endl << endl;
            break;
        case 3:
            userInput = getWeight(); //getting weight in pounds
            result = convertWeight(userInput); //converting pounds to kgs
            opLbl = "kilograms";
            ipLbl = "pounds";
            cout << fixed << setprecision(2) << userInput << " " << ipLbl << " is equal to " << result << " " << opLbl << endl << endl;
            break;
        case 4:
            confirm = getExitConfirm();
            break;
        }
      
    } while (!confirm);

    cout << "\nThanks for using our application.\n\n";
    system("pause");
    return 0;

}



