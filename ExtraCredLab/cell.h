#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cell
{
private:
	string idNumber;
	string phoneNumber;
public:
	Cell();
	Cell(string, string);
	void setId(string);
	void setPhone(string);
	string getId();
	string getPhone();
};
#endif