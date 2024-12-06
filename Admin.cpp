#include "Admin.h"
#include <fstream>

Administrator::Administrator() {
    std::ifstream fin;
    fin.open("password.txt", std::ios::in);
    std::string user, pass;
    getline(fin, user);
    getline(fin, pass);
    Username = user;
    Password = pass;
}

Administrator::Administrator(std::string Username_, std::string Password_)
    : Username(Username_), Password(Password_) {
    std::ofstream fout;
    fout.open("password.txt", std::ios::out);
    fout << Username << "\n";
    fout << Password;
    std::cout << "Admin Created\n";
}

void Administrator::setUser(std::string newUsername) {
    Username = newUsername;
    std::ofstream fout;
    fout.open("password.txt", std::ios::out);
    fout << Username;
    fout << Password;
}

void Administrator::changeUsername() {
    std::cout << "Enter new Username: ";
    std::string newUsername;
    std::cin >> newUsername;
    setUser(newUsername);
}

void Administrator::setPass(std::string newPassword) {
    Password = newPassword;
    std::ofstream fout;
    fout.open("password.txt", std::ios::out);
    fout << Username;
    fout << Password;
}

void Administrator::changePassword() {
    std::cout << "Enter new Password: ";
    std::string newPassword;
    std::cin >> newPassword;
    setUser(newPassword);
}

void Administrator::display_mydetails() {
    std::cout << "Username: " << Username << std::endl;
    std::cout << "Password: " << Password << std::endl;
}

