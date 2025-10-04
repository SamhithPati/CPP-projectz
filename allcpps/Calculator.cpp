// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//10/01/2023

#include <iostream>
using namespace std;

double valNum(string lbl) {
    double num;
    bool valNum;

    do {
        cout << "Please enter " << lbl << " : ";
        cin >> num;
        valNum = true;
        if (num < 0) {
            cout << "Error, invalid input. Please try again.\n";
            valNum = false;
        }
    } while (!valNum);

    return num;
}

int main()
{
    int choice;
    double num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
    bool valchoice = true, calc = true;
    string let;

    do {
        cout << "Welcome to Calculator.\n";
        cout << "1. Addition\n";
        cout << "3. Multiply\n";
        cout << "5. Quit\n";

        choice = valNum("choice");

        if (choice == 5) {
            cout << "Bruh!\n\n";
            goto exdec;
        }

        num1 = valNum("num1");
        num2 = valNum("num2");
        num3 = valNum("num3");
        num4 = valNum("num4");
        num5 = valNum("num5");


            /*do {
                cout << "Please enter the second number: ";
                cin >> num2;
                valQty = true;
                if (num2 < 0) {
                    cout << "Error, invalid quantity. Please try again.\n";
                    valQty = false;
                }
            } while (!valQty);*/


            double answer = 0;

            switch (choice) {
            case 1:
                answer = num1 + num2 + num3 + num4 + num5;
                let = " + ";
                break;
            case 2:
                answer = num1 * num2 * num3 * num4 * num5;
                let = " * ";
                break;          
            default:
                cout << "Invalid choice." << endl;
                calc = false;
                break;
            }
            cout << "\nThe answer of " << num1 << let << num2 << let << num3 << let << num4 << let << num5 << " = " << answer << endl << endl;
        } while (calc);

    exdec:
        cout << "Thank you!\n";
        cout << "It works!\n\n";

        system("pause");
        return 0;
    }

