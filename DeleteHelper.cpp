#include "DeleteHelper.h"

DeleteHelper::DeleteHelper(std::string name) : contactName(name) {}

void DeleteHelper::deleting() {
    std::string name = contactName;
    std::ifstream fin;
    std::ofstream fout;
    fin.open("ContactBook.txt", std::ios::in);
    fout.open("ContactBookTemporary.txt", std::ios::out|std::ios::trunc);
    std::string inpt;
    int b = 0;
    int c = 0;
    while(!fin.eof())
    {
        getline(fin >> std::ws, inpt);
        b++;
        if(inpt == name)
            c++;
        else
        {
            if(c >= 1 && c <= 3)
                c++;
            else
            {
                if(fin.eof() != 1)
                    fout << inpt << "\n";
                else
                    fout << inpt;
                if(b%4 == 0 && fin.eof() != 1)
                    fout << "\n";
            }
        }
    }
}

void DeleteHelper::temporary_to_original() {
    std::ofstream fout1;
    std::ifstream fin1;
    fout1.open("ContactBook.txt", std::ios::out|std::ios::trunc);
    fin1.open("ContactBookTemporary.txt", std::ios::in);
    char reading[30];
    while(!fin1.eof())
    {
        fin1.getline(reading, 30);
        if(fin1.eof() == 0)
            fout1 << reading << "\n";
        else
            fout1 << reading;
    }
}

void DeleteHelper::deleteFromContactbook() {
    deleting();
    temporary_to_original();
    std::cout << "\nSuccessfully Deleted.\n";
}
