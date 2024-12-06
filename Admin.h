#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>

class Administrator {
private:
    std::string Username;
    std::string Password;
public:
    Administrator();
    Administrator(std::string uname, std::string pass);
    void setUser(std::string newUsername);
    void changeUsername();
    void setPass(std::string newPassword);
    void changePassword();
    void display_mydetails();
};

#endif 