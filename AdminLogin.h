#ifndef ADMIN_LOGIN_H
#define ADMIN_LOGIN_H

#include <string>

class AdminLogin {
private:
    std::string Username;
    std::string Password;
public:
    AdminLogin();
    bool checkCredentials(std::string username, std::string password);
};

#endif 