// Samhith Patibandla
// 04/24/2024
// This program is point-of-sale program for a cellphone kiosk in the mall. 
// It uses a stack for the cell phone inventory and a queue for the customer purchases. 

#include <iostream>
#include <iomanip>
#include "Cellphone.h"
#include "Customer.h"
#include <fstream>
#include <stack>
#include <deque>

using namespace std;




// Prototypes
void progIntro();

int main()
{
    progIntro();

    stack<Cellphone> cellStack;
    deque<Customer> customerQueue;


    system("pause");
    return 0;
}

void progIntro() {
    cout << "\t\t\t\tCMSY 171 Lab 8\n";
    cout << "Copyright 2022 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\t\tWelcome to the CMSY-171 Cell Phone Purchase Program\n\n";
}