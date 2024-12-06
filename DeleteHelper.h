#ifndef DELETE_HELPER_H
#define DELETE_HELPER_H

#include <string>
#include <iostream>
#include <fstream>

class DeleteHelper {
private:
    std::string contactName;
public:
    DeleteHelper(std::string name);
    void deleting();
    void temporary_to_original();
    void deleteFromContactbook();
};

#endif 