#ifndef FILEHANDLINGMODULE_H
#define FILEHANDLINGMODULE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class filehandlingmodule
{
public:
    string username1, password1;

    bool log_in(string username, string password);
    void createaccount(string username, string password);
    void ticket(string username, string firstname[], string lastname[], string sex[], int age[], int no);
};

#endif
