// Samhith Patibandla
// 02/19/2024
// This program demonstrates sorting algorithms: Bubble Sort and Selection Sort
// It initializes two arrays, performs sorting using the mentioned algorithms, and displays the sorted arrays.

#include <iostream>
#include <vector>
#include <array>
#include <iomanip>
#include <iomanip>
using namespace std;

// Global Constants
const int ARY_SIZE{ 14 };

// Prototype Functions
void projIntro(); // Function to display project introduction
void displayAry(array<int, ARY_SIZE>&); // Function to display the elements of an array
void bubbleSort(array<int, ARY_SIZE>&); // Function to perform Bubble Sort
void selectSort(array<int, ARY_SIZE>&); // Function to perform Selection Sort
void swap(int&, int&); // Function to swap two integers

int main()
{
    projIntro(); // Display project introduction

    // Initialize two arrays with unsorted values
    array<int, ARY_SIZE> numList1 = { 98, 78, 102, 67, 45, 83, 29, 184, 2, 68, -7, 56, 121, 5 };
    array<int, ARY_SIZE> numList2 = { 98, 78, 102, 67, 45, 83, 29, 184, 2, 68, -7, 56, 121, 5 };

    // Display unsorted array before Bubble Sort
    cout << "\nBefore Bubble Sort: ";
    displayAry(numList1);

    // Perform Bubble Sort and display sorted array
    bubbleSort(numList1);
    cout << "\nAfter Bubble Sort: ";
    displayAry(numList1);

    cout << endl << "----------------\n";

    // Display unsorted array before Selection Sort
    cout << "\nBefore Selection Sort: ";
    displayAry(numList2);

    // Perform Selection Sort and display sorted array
    selectSort(numList2);
    cout << "\nAfter Selection Sort: ";
    displayAry(numList2);

    cout << endl;

    system("pause");
    return 0;
}

// Function to display project introduction
void projIntro() {
    cout << "CE - Sort\n";
    cout << "Copyright 2022 - Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\tWelcome to CMSY-171 Starter Review Program\n\n";
}

// Function to display the elements of an array
void displayAry(array<int, ARY_SIZE>& arr1) {
    cout << endl;
    for (const auto& elmtArr1 : arr1) {
        cout << "\tNumber  1 = " << elmtArr1 << endl;
    }
}

// Function to perform Bubble Sort
void bubbleSort(array<int, ARY_SIZE>& arr1) {
    int minElement;
    int index;

    for (minElement = 0; minElement < ARY_SIZE; minElement++) {
        for (index = ARY_SIZE - 1; index > minElement; index--) {
            if (arr1[index] < arr1[index - 1]) {
                swap(arr1[index], arr1[index - 1]);
            }
        }
    }
}

// Function to perform Selection Sort
void selectSort(array<int, ARY_SIZE>& arr1) {
    int maxIndex, maxValue;

    for (int start = ARY_SIZE - 1; start > 0; start--) {
        maxIndex = start;
        maxValue = arr1[start];
        for (int index = start - 1; index >= 0; index--) {
            if (arr1[index] < maxValue) {
                maxValue = arr1[index];
                maxIndex = index;
            }
        }
        swap(arr1[maxIndex], arr1[start]);
    }
}

// Function to swap two integers
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}