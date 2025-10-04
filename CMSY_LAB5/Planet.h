// Specification file for the food class
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#ifndef PLANET_H
#define PLANET_H

class Planet
{
private:
	string planetName;
	int planetID;
	int planetMoons;
	int radius;

	// Mutator Prototypes
	void setPlanetID();
	void setPlanetMoons();
	void setPlanetName();
	void setRadius();

public:
	// Constructors 
	Planet();
	Planet(const string);
	Planet(const int);

	// Nested Classes = Empty Class declaration
	class planetLow {};
	class planetHigh {};
	
	// Accessors
	string getPlanetName() const;
	int getPlanetID() const;
	int getPlanetMoons() const;
	int getRadius() const;

	// Overloaded operators
	Planet& operator++(); // Prefix ++
	Planet operator++(int); // Postfix ++ 
	Planet& operator=(const Planet& other); // Assignment
	Planet operator-(); // Unary minus
	Planet operator+(); // Unary plus
	friend ostream& operator<<(ostream& os, const Planet& planet);
	friend istream& operator>>(istream& is, Planet& planet);

	// Destructor
	~Planet() {}
};

#endif