// Samhith Patibandla
// 10/07/2023
// This program uses functions for 5 integer mathematical operaions and 4 double mathematical operaions.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


void showCopyright();//prototype for program title, copyright, and intro
void getUserChoice(int &);//prototype displays menu and gets user choice, validates, and returns choice

int intAddition(int, int); //Prototype function for integer addition
int intSubtraction(int, int); //Prototype function for integer subtraction
int intMultiply(int , int); //Prototype function for integer multiplication
int intDivide(int, int); //Prototype function for integer division
int intMod(int, int); //Prototype function for integer modulus

void doubleAddition(double, double, double&); //Prototype function for double addition
void doubleSubtraction(double, double, double&); //Prototype function for double subtraction
void doubleMultiply(double, double, double&); //Prototype function for double multiplication
void doubleDivide(double, double, double&); //Prototype function for double division

bool getExitConfirm(); //Prototype function for exit
    
int main()
{
        
   bool confirm;
   showCopyright(); //showing copyright
    //Do While loop
   do {
       //Declaring Variables
        confirm = false;
        int userChoice = 0, x, y;
        double userInput, result;
        string opLbl, ipLbl;
        int intRes1, intRes2, intRes3, intRes4, intRes5;

         getUserChoice(userChoice); //getting user choice from menu  
         
         switch (userChoice) {
         case 1:
             int num1, num2;
             cout << "\nPlease enter the first integer value: ";
             cin >> num1;
             cout << endl;
             cout << "\nPlease enter the second integer value: ";
             cin >> num2;
             cout << endl << endl;
             cout << "RESULTS\n";

             intRes1 = intAddition(num1, num2); //getting sum of integers
             intRes2 = intSubtraction(num1, num2); //getting sub of integers
             intRes3 = intMultiply(num1, num2); //getting mult of integers
             intRes4 = intDivide(num1, num2); //getting div of integers
             intRes5 = intMod(num1, num2); //getting mod of integers

             //Printing Results
             cout <<  "\tAddition       = " << intRes1 << endl;
             cout << "\tSubtraction    = " << intRes2 << endl;
             cout << "\tMultiplication = " << intRes3 << endl;
             cout << "\tDivision       = " << intRes4 << endl;
             cout << "\tModulus        = " << intRes5 << endl << endl;
             break;

         case 2:
             double dblnum1, dblnum2, dblRes1, dblRes2, dblRes3, dblRes4;

             cout << "\nPlease enter the first double value: ";
             cin >> dblnum1;
             cout << endl;
             cout << "\nPlease enter the second double value: ";
             cin >> dblnum2;
             cout << endl << endl;
             cout << "RESULTS\n";

              doubleAddition(dblnum1, dblnum2, dblRes1); //getting sum of double values
              doubleSubtraction(dblnum1, dblnum2, dblRes2); //getting sub of double values
              doubleMultiply(dblnum1, dblnum2, dblRes3); //getting mult of double values
              doubleDivide(dblnum1, dblnum2, dblRes4); //getting div of double values

             cout << "\tAddition       = " << fixed << setprecision(2) << dblRes1 << endl;
             cout << "\tSubtraction    = " << fixed << setprecision(2) << dblRes2 << endl;
             cout << "\tMultiplication = " << fixed << setprecision(2) << dblRes3 << endl;
             cout << "\tDivision       = " << fixed << setprecision(2) << dblRes4 << endl << endl;
             break;
             
         case 3:
             confirm = getExitConfirm(); //Getting exit
             break;
         }
       
    } while (!confirm);

    cout << "Thanks for using our application.\n\n"; //Thank you message
 
    system("pause");
    return 0;

}

//function for program title, copyright, and intro
void showCopyright() {
    cout << "CE - Pass By Reference\n";
    cout << "Copyright 2021 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n";
    cout << "\tWelcome to the CMSY-141 Caluclator Program\n\n";
    return;
}

//function to display menu and gets user choice, validates, and returns choice
void getUserChoice(int& choice) {
    //Declaring variables
    bool valSubchoice;
    //Begining of do loop 
    do {
        //Outputs menu for user
        cout << "MAIN MENU\n";
        cout << "\t1 - Integer Math\n";
        cout << "\t2 - Double Math\n";
        cout << "\t3 - Exit program\n";

        // Prompt the user to enter a choice from the menu.
        cout << "Please enter your menu choice: ";
        cin >> choice;
        cout << endl;

        if (choice > 0 && choice <= 3) {
            valSubchoice = true;
        } //End if         
        else {
            cout << "ERROR - Please enter a valid menu option \n\n";
            valSubchoice = false;
        } //end else        
    } while (!valSubchoice); //End while loop
}

//function for adding integer values
int intAddition(int x, int y) {
    //Declaring variables
    int result = x + y;
    return result;
}

//function for subtracting integer values
int intSubtraction(int x, int y) {
    //Declaring variables
   int result = x - y;
   return result;
}

//function for multiplying integer values
int intMultiply(int x, int y) {
    //Declaring variables
    int result = x * y;
    return result;
}

//function for dividing integer values
int intDivide(int x, int y) {
    //Declaring variables
    int result = x / y;
    return result;
}

//function for mod integer values
int intMod(int x, int y) {
    //Declaring variables
    int result = x % y;
    return result;
}

void doubleAddition(double x, double y, double &result) {
    result = x + y;
}

void doubleSubtraction(double x, double y, double& result) {
    result = x - y;
}

void doubleMultiply(double x, double y, double& result) {
    result = x * y;
}

void doubleDivide(double x, double y, double& result) {
    result = x / y;
}

//function to exit the program
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
            cout << "\n\nError - please enter in either y or n\n\n\n";
        }
    } while (!valconfirm);
    return confirmation;
}
v