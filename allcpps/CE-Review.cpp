// Samhith Patibandla
// 10/15/2023
// This program captures and displays student information, including name, major, and current semester. 
// It then calculates the average test score and corresponding letter grade for the student, allowing users to input data for multiple students until they choose to exit.
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_TESTS = 5;
const int MIN_SCORE = 0;
const int MAX_SCORE = 100;

// Function prototypes
void copyRight();
void enterStudentInfo(string& name, string& major, string& semester);
int getSumScore(string);
void calculateAverage(int sum, double& average);
char getGradeLet(double average);
void displayStudentReport(string name, string major, string semester, double average, char letterGrade);
bool getExitConfirm();
void thankYou();

int main() {
    string name, major, semester;
    int sum;
    double average;
    char letterGrade;

    // Display the copyright and welcome message
    copyRight();

    // Main program loop
    do {
        // Function to enter student information
        enterStudentInfo(name, major, semester);

        // Function to get the sum of test scores
        sum = getSumScore(name);

        // Function to calculate the average test score
        calculateAverage(sum, average);

        // Function to determine the letter grade
        letterGrade = getGradeLet(average);

        // Function to display student report
        displayStudentReport(name, major, semester, average, letterGrade);

    } while (!getExitConfirm()); // Continue loop if user wants to enter another student's information

    // Goodbye message
    thankYou();

    system("pause");
    return 0;
}

// Function definitions

// Function to display copyright and welcome message
void copyRight() {
    cout << "CE - Review\n";
    cout << "Copyright ©2021 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\tWelcome to the CSMY-141 First Half Review Program\n";
}

// Function to enter student information
void enterStudentInfo(string& name, string& major, string& semester) {
    cout << "\nEnter in the name of the student: ";
    getline(cin, name);

    cout << "Enter in the major for " << name << ": ";
    getline(cin, major);

    cout << "Enter in the current semester and year: ";
    getline(cin, semester);
    cout << endl;
}

// Function to get the sum of test scores
int getSumScore(string name) {
    int sumSc = 0;
    for (int i = 0; i < NUM_TESTS; ++i) {
        int score;
        do {
            cout << "Enter test score " << i + 1 << " for " << name << ": ";
            cin >> score;
            if (score < MIN_SCORE || score > MAX_SCORE) {
                cout << "Error - Invalid entry. Score must be between " << MIN_SCORE << " and " << MAX_SCORE << ". Please reenter." << endl << endl;
            }
        } while (score < MIN_SCORE || score > MAX_SCORE);
        sumSc += score;
    }
    return sumSc;
}

// Function to calculate the average of test scores
void calculateAverage(int sum, double& average) {
    average = static_cast<double>(sum) / NUM_TESTS;
}

// Function to determine the letter grade based on the average
char getGradeLet(double average) {
    if (average >= 90) {
        return 'A';
    }
    else if (average >= 80) {
        return 'B';
    }
    else if (average >= 70) {
        return 'C';
    }
    else if (average >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}

// Function to display the student report
void displayStudentReport(string name, string major, string semester, double average, char letterGrade) {
    cout << fixed << setprecision(1);
    cout << "\nStudent Report:\n";
    cout << "Student Name    : " << name << endl;
    cout << "Major           : " << major << endl;
    cout << "Semester        : " << semester << endl;
    cout << "Test Average    : " << average << endl;
    cout << "Course Grade    : " << letterGrade << endl;
}
// Function to ask the user if they want to exit
bool getExitConfirm() {
    char choice;
    bool valExit;
    do {
        valExit = true;
        cout << "\nDo you want to exit the program? (y/n): ";
        cin >> choice;

        // Validate user input
        if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
            cout << "Error - Only y or n is valid, please reenter!!\n";
            valExit = false;
        }
    } while (!valExit);
    cin.ignore(); // clear input buffer
        return (choice == 'Y' || choice == 'y');
}

void thankYou() {
    cout << "\nThank you for trying this program. Stay Healthy!\n\n";
}