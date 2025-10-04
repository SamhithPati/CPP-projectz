#include "Cellphone.h"

// Default constructor
Cellphone::Cellphone() : idNumber("none"), phoneNumber("none") {}

// Constructor with parameters
Cellphone::Cellphone(std::string id, std::string phone) : idNumber(id), phoneNumber(phone) {}

// Getter function for id number
std::string Cellphone::getIdNumber() const {
    return idNumber;
}

// Getter function for phone number
std::string Cellphone::getPhoneNumber() const {
    return phoneNumber;
}

// Setter function for id number
void Cellphone::setIdNumber(std::string id) {
    idNumber = id;
}

// Setter function for phone number
void Cellphone::setPhoneNumber(std::string phone) {
    phoneNumber = phone;
}
