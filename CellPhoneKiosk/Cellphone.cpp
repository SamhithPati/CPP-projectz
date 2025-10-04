#include "Cellphone.h"
#include <string>

using namespace std;

void Cellphone::setCellID(string cID) {
	cellId = cID;
}

void Cellphone::setCellNum(string cNum) {
	cellNum = cNum;
}

string Cellphone::getCellID() const {
	return cellId;
}

string Cellphone::getCellNum() const {
	return cellNum;
}

Cellphone::Cellphone() {
	setCellID("none");
	setCellNum("none");
}

Cellphone::Cellphone(string cID, string cNum) {
	setCellID(cID);
	setCellNum(cNum);
}