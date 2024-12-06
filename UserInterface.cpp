#include "UserInterface.h"
#include <iostream>

void UserInterface::displayStart() {
    std::cout << "\n\t\t   ======= Phone Contacts Manager System  =======" << std::endl;
}

int UserInterface::MenuDisplayStart() {
    std::cout << "\nSelect your choice:\n\n[1]USER\n[2]EXISTING ADMIN\n[3]CREATE ADMIN\n[0]EXIT\nEnter the choice: ";
    int choice; 
    std::cin >> choice;
    return choice;
}

int UserInterface::MenuDisplayAdmin() {
    std::cout << "\n\n\t\t\t\t\tMAIN MENU\n\t\t\t\t=====================\n\t\t\t\t[1] Add a new Contact\n\t\t\t\t[2] List all Contacts\n\t\t\t\t[3] Search for contact\n\t\t\t\t[4] Edit a Contact\n\t\t\t\t[5] Delete a Contact\n\t\t\t\t[0] Exit\n\t\t\t\t\t=================\n\t\t";
    std::cout << "\t\tEnter the choice:";
    int op;
    std::cin >> op;
    return op;
}

int UserInterface::MenuDisplayUser() {
    std::cout << "\n\n\t\t\t\t\tMAIN MENU\n\t\t\t\t=====================\n\t\t\t\t[1] List all Contacts\n\t\t\t\t[2] Search for contact\n\t\t\t\t[0] Exit\n\t\t\t\t=================\n\t\t";
    std::cout << "\t\tEnter the choice:";
    int op;
    std::cin >> op;
    return op;
}
