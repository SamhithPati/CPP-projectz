// Samhith Patibandla
// 03/06/2024
// This program calculates the inventory of a food kiosk using classes and objects.

#include <iostream>
#include "Food.h"
using namespace std;

// Prototype
void progIntro();

int main()
{
    progIntro();

    // Create Food objects

    /*
    Food Food1();
    Food Food1(7);
    Food Food3("Tossed Salad", 75, 7); // Calls constructor with 3 parameters
    */

    Food Food1("Sandwiches", 90, 7); // Calls constructor with 3 parameters
    Food1.setSales(0, 7);
    Food1.setSales(1, 8);
    Food1.setSales(2, 9);
    Food1.setSales(3, 10);
    Food1.setSales(4, 10);
    Food1.setSales(5, 5);
    Food1.setSales(6, 12);

    Food Food2("Beverages", 80, 7); // Calls constructor with 3 parameters
    Food2.setSales(0, 10);
    Food2.setSales(1, 10);
    Food2.setSales(2, 12);
    Food2.setSales(3, 10);
    Food2.setSales(4, 12);
    Food2.setSales(5, 11);
    Food2.setSales(6, 12);

    Food Food3("Tossed Salad", 75, 7); // Calls constructor with 3 parameters 
    Food3.setSales(0, 4);
    Food3.setSales(1, 6);
    Food3.setSales(2, 2);
    Food3.setSales(3, 3);
    Food3.setSales(4, 4);
    Food3.setSales(5, 7);
    Food3.setSales(6, 3);

    /*
    cout << "\n\nCalling the set functions and displaying errors\n";
    Food Food4("Sandwiches", 200, 7);
    Food3.setSales(5, 105);
    Food3.setSales(-4, -105);
    cout << endl;
    */

    cout << "\nCalling the display function after initial call to constructors\n";

    Food1.display();
    Food2.display();
    Food3.display();

    cout << "\n\nThank you for using this program!\n";

    system("pause");
    return 0;
  }

void progIntro() {
    cout << "\t\t\t\tCMSY 171 Lab 4" << endl;
    cout << "Copyright 2022 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\t\tWelcome to CMSY-171 Food Kiosk Inventory Program\n\n\n";
}

