#include <iostream>
#include <iomanip>
#include <map>
#include "Planet.h" // Including the header file where Planet class is declared
#include <cstdlib>
using namespace std;

// Function to set the planet ID based on the planet name
void Planet::setPlanetID() {
    // Create a map of strings to integers
    map<string, int> planetMap;

    // Insert some values into the map
    planetMap["Mercury"] = 1;
    planetMap["Venus"] = 2;
    planetMap["Earth"] = 3;
    planetMap["Mars"] = 4;
    planetMap["Jupiter"] = 5;
    planetMap["Saturn"] = 6;
    planetMap["Uranus"] = 7;
    planetMap["Neptune"] = 8;
    planetMap["None"] = 0;

    // Set the planet ID using the planet name
    planetID = planetMap.find(planetName)->second;
}

// Function to set the value of the radius attribute based on the planet number
void Planet::setRadius() {
    // Create a map of strings to integers
    map<int, int> radiusMap;

    // Insert some values into the map
    radiusMap[1] = 1516;
    radiusMap[2] = 3760;
    radiusMap[3] = 3959;
    radiusMap[4] = 2106;
    radiusMap[5] = 43441;
    radiusMap[6] = 36184;
    radiusMap[7] = 15759;
    radiusMap[8] = 15299;
    radiusMap[0] = 0;

    // Set the planet ID using the planet name
    radius = radiusMap.find(planetID)->second;
}

// Function to set the number of moons based on the planet ID
void Planet::setPlanetMoons() {
    // Create a map of integers to integers
    map<int, int> moonMap;

    // Insert some values into the map
    moonMap[1] = 0;
    moonMap[2] = 0;
    moonMap[3] = 1;
    moonMap[4] = 2;
    moonMap[5] = 79;
    moonMap[6] = 82;
    moonMap[7] = 27;
    moonMap[8] = 14;
    moonMap[0] = 0;

    // Set the number of moons using the planet ID
    planetMoons = moonMap.find(planetID)->second;
}

// Function to set the planet name based on the planet ID
void Planet::setPlanetName() {
    // Create a map of integers to strings
    map<int, string> planetNameMap;

    // Insert some values into the map
    planetNameMap[1] = "Mercury";
    planetNameMap[2] = "Venus";
    planetNameMap[3] = "Earth";
    planetNameMap[4] = "Mars";
    planetNameMap[5] = "Jupiter";
    planetNameMap[6] = "Saturn";
    planetNameMap[7] = "Uranus";
    planetNameMap[8] = "Neptune";
    planetNameMap[0] = "None";

    // Set the planet name using the planet ID
    planetName = planetNameMap.find(planetID)->second;
}

// Default constructor
Planet::Planet() {
    planetName = "None";
    setPlanetID();
    setPlanetMoons();
    setRadius();
}


// Constructor with a parameter for planet name
Planet::Planet(const string nm) {
    planetName = nm;
    setPlanetID();
    setPlanetMoons();
    setRadius();
}


// Constructor with a parameter for planet ID
Planet::Planet(const int inID) {
    if (inID < 1) {
        throw planetLow();
    }
    else if (inID > 8) {
        throw planetHigh();
    }
    else {
        planetID = inID;
        setPlanetName();
        setPlanetMoons();
        setRadius();
    } 
}

int Planet::getRadius() const {
    return radius;
}

// Getter for planet name
string Planet::getPlanetName() const {
    return planetName;
}

// Getter for planet ID
int Planet::getPlanetID() const {
    return planetID;
}

// Getter for number of moons
int Planet::getPlanetMoons() const {
    return planetMoons;
}

// Prefix increment operator
Planet& Planet::operator++() {
    planetID++;
    if (planetID > 8)
        planetID = 1;
    setPlanetName();
    setPlanetMoons();
    setRadius();
    return *this;
}

// Postfix increment operator
Planet Planet::operator++(int) {
    Planet temp = *this;
    ++(*this); // Call prefix operator
    return temp;
}

// Assignment operator
Planet& Planet::operator=(const Planet& other) {
    if (this != &other) {
        planetName = other.planetName;
        planetID = other.planetID;
        planetMoons = other.planetMoons;
        radius = other.radius;
    }
    return *this;
}

// Negation operator
Planet Planet::operator-() {
    return Planet("Mercury"); // Return a new object with the values of the first planet
}

// Unary plus operator
Planet Planet::operator+() {
    return Planet("Neptune"); // Return a new object with the values of the last planet
}

// Overloaded stream insertion operator
ostream& operator<<(ostream& os, const Planet& planet) {
    os << "The planet " << planet.planetName << " is planet number: " << planet.planetID 
        << "\nIt has " << planet.planetMoons << " moons and a radius of " << planet.radius << " miles.";
    return os;
}

// Overloaded stream extraction operator
istream& operator>>(istream& is, Planet& planet) {
    cout << "Enter the name of a planet: ";
    is >> planet.planetName;
    planet.setPlanetID();
    planet.setPlanetMoons();
    planet.setRadius();
    return is;
}