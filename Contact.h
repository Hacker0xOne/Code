#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <fstream>

class Contact {
private:
    std::string contactName;
    std::string contactNumber;
    std::string contactAddress;
    std::string contactEmail;
public:
    Contact(std::string name, std::string number, std::string address, std::string mail);
    void display();
    void add();
};

#endif 