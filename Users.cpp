#include "Users.h"

Users::Users(std::string name_) : name(name_) {
}

void Users::checkIn() {
    std::ofstream fout;
    fout.open("Users.txt", std::ios::app);
    fout << name << "\n" << __TIMESTAMP__ << "\n";
}
