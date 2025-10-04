#include <iostream>
#include <iomanip>
#include "Food.h"
#include <cstdlib>
using namespace std;

	// Private function to dynamically allocate an int array
	void Food::makeArray() {
		// Dynamically allocate memory for the array
		sales = new int[num];

		// Assign 0 to all elements of the array
		for (int i = 0; i < num; i++) {
			sales[i] = 0;
		}
	}

	// Private function to calculate the ending inventory
	void Food::calcEnd() {
		int totalSales = 0;
		for (int i = 0; i < num; i++) {
			totalSales += sales[i];
		}
		//setting end inventory
		setEnd(getStart() - totalSales);
	}

	// Private function to calculate the average number of items sold per day
	double Food::calcAvg() {
		int totalSales = 0;
		for (int i = 0; i < num; i++) {
			totalSales += sales[i];
		}

		// Calculate the average number of items sold per day
		double average = static_cast<double>(totalSales) / num;
		return average;
	}

		// Constructors
		Food::Food() {
			setName("none");
			setStart(24);
			num = 7;
			makeArray();
		}
		Food::Food(int n) {
			setName("none");
			setStart(24);
			if (n > 0) {
				num = n;
			}
			else {
				num = 7;
			}
			makeArray();
		}
		Food::Food(string nm, int st, int n) {
			setName(nm);
			setStart(st);
			if (n > 0) {
				num = n;
			}
			else {
				num = 3;
			}
			makeArray();
		}


		// Mutators
		void Food::setName(string nm) {
			name = nm;
		}

		void Food::setStart(int st) {
			if (st >= 24 && st <= 99) {
				invStart = st;
			}
			else {
				invStart = 24;
				cout << "Invalid.  Cannot set the starting inventory to " << st << " for " << getName() << endl;
			}
		}

		void Food::setEnd(int en) {
			if (en >= 0) {
				invEnd = en;
			}
			else {
				invEnd = 0;
				cout << "Invalid.  Cannot set the ending inventory to " << en << " for " << getName() << endl;
			}
		}

		// Function to set sales at index i
		void Food::setSales(int i, int sale) {
			if (i >= 0 && i < num && sale >= 1 && sale <= 99) {
				sales[i] = sale;
			}
			else {
				cout << "Invalid.  Cannot set the sales for day " << i << " to " << sale << " for " << getName() << endl;
			}
		}


		// Accessors 
		string Food::getName() const {
			return name;
		}

		int Food::getStart() const {
			return invStart;
		}

		int Food::getEnd() const {
			return invEnd;
		}

		// Other members
		
		// Function to show sales
		void Food::showSales() const {
			cout << endl;
			for (int i = 0; i < num; ++i) {
				cout << "Day " << i + 1 << " had a sales of " << sales[i] << " for item " << getName() << endl;
			}
		}

		// Function to display food objects
		void Food::display() {
			cout << "\nFood Name: " << getName();
			cout << "\nStarting Inventory Amount: " << getStart();
			showSales();
			calcEnd();
			cout << "Final Inventory Amount: " << getEnd() << endl;
			cout << "The average sold per day is: " << fixed << setprecision(1) << calcAvg() << endl;
		}



		