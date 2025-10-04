// Specification file for the food class
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#ifndef FOOD_H
#define FOOD_H

class Food
{
private:
	string name;
	int invStart;
	int invEnd;
	int* sales;
	int num = 7;

	// Private Prototypes
	void makeArray();	
	void calcEnd();	
	double calcAvg();

public:
	// Constructors Prototypes
	Food();
	Food(int);
	Food(string, int, int);

	// Mutators Prototypes
	void setName(string);
	void setStart(int);
	void setEnd(int);
	void setSales(int, int);

	// Accessors Prototypes
	string getName() const;
	int getStart() const;
	int getEnd() const;

	// Other members Prototypes
	void showSales() const;
	void display();

	// Destructor to free dynamically allocated memory
	~Food() {
		delete[] sales;
	}
};

#endif