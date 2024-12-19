#ifndef INPUTMODULE_H
#define INPUTMODULE_H

#include <iostream>
#include <string>
#include "filehandlingmodule.h"
using namespace std;

class inputmodule
{
public:
    string source, destination;
    string username, password;

    void user_input(string userchoice[]);
    string login();
    int noofpassenger();
};

#endif
