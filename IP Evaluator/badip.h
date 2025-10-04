//DO NOT CHANGE ANYTHING IN THIS FILE
#ifndef BADIP_H
#define BADIP_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int SIZE = 30;

class BadIP
{
private:
	char IPAddr[SIZE];
	char dateTime[SIZE];

public:
	BadIP();
	BadIP(char*, char*);
	void setBadIP(char*);
	char* getBadIP();
	void setDateTime(char*);
	char* getDateTime();
	friend ostream& operator << (ostream& out, BadIP& bip);
};
#endif