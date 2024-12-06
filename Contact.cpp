#include "Contact.h"

Contact::Contact(std::string name, std::string number, std::string address, std::string mail)
    : contactName(name), contactNumber(number), contactAddress(address), contactEmail(mail) {}

void Contact::display() {
    std::cout << "\nName: " << contactName;
    std::cout << "\nNumber: " << contactNumber;
    std::cout << "\nAddress: " << contactAddress;
    std::cout << "\nEmail: " << contactEmail;
}

void Contact::add() {
    std::ofstream fout;
    fout.open("ContactBook.txt", std::ios::app);
    fout << "\n";
    fout << contactName << "\n";
    fout << contactNumber << "\n";
    fout << contactAddress << "\n";
    fout << contactEmail << "\n";
}
