#include "ContactBook.h"
#include <iostream>

ContactBook::ContactBook() {
    details[0] = "Name";
    details[1] = "Phone(Mobile)";
    details[2] = "Address";
    details[3] = "Email";
    details[4] = "";
}

void ContactBook::adding() {
    std::string vals[4];
    for(int i = 0; i < 4; i++) {
        std::cout << details[i] << ": ";
        getline(std::cin >> std::ws, vals[i]);    
    }
    Contact contact(vals[0], vals[1], vals[2], vals[3]);
    contact.add(); 
}

void ContactBook::listing() {
    std::ifstream fin;
    fin.open("ContactBook.txt", std::ios::in);
    char inpt[30];
    int i = 0;
    while(fin) {
        fin.getline(inpt, 30);
        if(i != 4)
            std::cout << details[i] << " : " << inpt << std::endl;
        else
            std::cout << details[i] << inpt << std::endl;
        i++;
        if(i == 5)
            i = 0;
    }        
}

void ContactBook::searching() {
    std::string name;
    std::cout << "Enter name whose contact is to be searched: ";
    getline(std::cin >> std::ws, name);
    std::ifstream fin;
    fin.open("ContactBook.txt", std::ios::in);
    std::string inpt;
    int c = 0;
    while(fin) {
        getline(fin >> std::ws, inpt);
        if(inpt == name) {
            c++;
            for(int i = 0; i < 4; i++) {
                std::cout << details[i] << ": " << inpt << std::endl;
                getline(fin >> std::ws, inpt);
            }
        }
        if(c > 0)
            break;
    }
}

void ContactBook::editing() {
    std::string name;
    std::cout << "Enter name whose contact is to be Edited: ";
    getline(std::cin >> std::ws, name);
    std::ifstream fin;
    std::ofstream fout;
    fin.open("ContactBook.txt", std::ios::in);
    fout.open("ContactBookTemporary.txt", std::ios::out|std::ios::trunc);
    std::string inpt;
    int b = 0;
    int c = 0;
    while(!fin.eof()) {
        getline(fin >> std::ws, inpt);
        b++;
        if(inpt == name) {
            c++;
            std::cout << "Enter new details: \n";
            for(int i = 0; i < 4; i++) {
                std::string newdetail;
                std::cout << "New " << details[i] << ": ";
                getline(std::cin >> std::ws, newdetail);
                b++;
                fout << newdetail << "\n";
            }
            for(int i = 0; i <= 3; i++, b++)
                getline(fin >> std::ws, inpt);
            fout << "\n" << inpt << "\n";
        } 
        else {
            if(fin.eof() != 1)
                fout << inpt << "\n";
            else
                fout << inpt;
            if(b%4 == 0 && fin.eof() != 1)
                fout << "\n";
        }
    }
}

void ContactBook::deleting() {
    std::string name;
    std::cout << "Enter name whose contact is to be Deleted: ";
    getline(std::cin >> std::ws, name);
    DeleteHelper deletehelperObject(name);
    deletehelperObject.deleteFromContactbook();
}
