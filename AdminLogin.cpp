#include "AdminLogin.h"
#include <fstream>

AdminLogin::AdminLogin() {
    std::ifstream fin;
    fin.open("password.txt", std::ios::in);
    std::string user, pass;
    getline(fin, user);
    getline(fin, pass);
    Username = user;
    Password = pass;
}

bool AdminLogin::checkCredentials(std::string user, std::string pass) {
    if(user == Username && pass == Password)
        return true;
    else 
        return false;
}
