#include <iostream>
#include <cstring>
#include "badip.h"

/* constructor */
BadIP::BadIP(char* ip, char* dt)
{
	//TO DO - create the constructor to update the attributes with the parameter values
	setBadIP(ip);
	setDateTime(dt);
}
/* constructor */
BadIP::BadIP()
{
	//TO DO - create the constructor to update the attributes with the default values of "none'
	char tempIp[SIZE] = "none";
	char tempDate[SIZE] = "none";
	setBadIP(tempIp);
	setDateTime(tempDate);

}

void BadIP::setBadIP(char* ip)
{
	strcpy_s(IPAddr, ip);
}

char* BadIP::getBadIP()
{
	return IPAddr;
}

void BadIP::setDateTime(char* dt)
{
	strcpy_s(dateTime, dt);
}

char* BadIP::getDateTime()
{
	return dateTime;
}

ostream& operator << (ostream& out, BadIP& bip)
{
	//TO DO - create the overriden output streaming operator to display the suspect IP addresses as shown by the screen shot
	out << "The suspect IP address " << bip.getBadIP() << " occured at: " << bip.getDateTime() << endl;
	return out;
}

