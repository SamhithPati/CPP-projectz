// Samhith Patibandla
// 09/08/2023
// Practicing the basics of C++ by working with different data types, initialization and declarations, escape sequences, and input/output."


#include <iostream>
using namespace std;

int main()
{
    int num;      // Initialize the int variable
    double var;   // Initialize the double variable
    char let;     //Initialize the character variable
    string word;  // Initialize the string variable
    bool play;    // Initialize the boolean variable

    //Prints sentences and using new line, tab, \ and " escape sequences.

    cout << "This is my first program\n\n";                                 
    cout << "This prints two lines\n" <<"Using an escape sequence\n";      
    cout << "\tThis string tests the tab sequence" <<endl;
    cout << "This prints a \\ and a \" character\n";
    cout << "This string uses the end of line manipulator" << endl <<endl;

    //declaration of variables.

    num = 12;
    var = 3.14159;
    let = 'B';
    word = "This is the display for CE-Output";
    play = false;

    //Printing variables 

    cout << "The integer variable is: " << num <<endl;
    cout << "The double variable is: " << var << endl;
    cout << "The character variable is: " << let << endl;
    cout << "The string variable is: " << word << endl;
    cout << "The boolean variable is: " << play << endl <<endl;

    //Initializing int variables 

    int num1, num2;

       

    cout << "Enter in the first integer value: ";  // Printing the statement
    cin >> num1; // Taking user input
    cout << "Enter in the second integer value: "; // Printing the statement
    cin >> num2; // Taking user input
    cout << "The addition of " << num1 << " and " << num2 << " = " << num1 + num2 <<endl <<endl;  // Adding the two variables and printing result
    

    system("pause"); 
    return 0;
}