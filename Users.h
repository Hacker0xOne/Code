#ifndef USERS_H
#define USERS_H

#include <string>
#include <fstream>

class Users {
private:
    std::string name;
public:
    Users(std::string name_);
    void checkIn();
};

#endif 