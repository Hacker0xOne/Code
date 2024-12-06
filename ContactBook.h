#ifndef CONTACT_BOOK_H
#define CONTACT_BOOK_H

#include <string>
#include <fstream>
#include "Contact.h"
#include "DeleteHelper.h"

class ContactBook {
private:
    std::string details[5];
public:
    ContactBook();
    void adding();
    void listing();
    void searching();
    void editing();
    void deleting();
};

#endif 