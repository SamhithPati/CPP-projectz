#ifndef CELLPHONE_H
#define CELLPHONE_H

#include <string>

class Cellphone {
private:
    std::string idNumber;       // Private variable to hold the cellphone id number
    std::string phoneNumber;    // Private variable to hold the cellphone phone number

public:
    // Constructors
    Cellphone();                                                // Default constructor
    Cellphone(std::string id, std::string phone);               // Constructor with parameters

    // Getter functions
    std::string getIdNumber() const;                            // Get id number
    std::string getPhoneNumber() const;                         // Get phone number

    // Setter functions
    void setIdNumber(std::string id);                           // Set id number
    void setPhoneNumber(std::string phone);                      // Set phone number
};

#endif // CELLPHONE_H
