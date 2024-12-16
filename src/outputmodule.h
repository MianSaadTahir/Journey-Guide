#ifndef OUTPUTMODULE_H
#define OUTPUTMODULE_H

#include <iostream>
#include <string>
#include <fstream>
#include "datamodule.h"
#include "inputmodule.h"
#include "filehandlingmodule.h"

using namespace std;

class outputmodule
{
public:
    string source, destination;

    void ticketHistory(string username);
    void initial();
    void list_cities(int N);
    void ticket(int total_price, int no, string source, string destination, string username);
    void passengerdetailedticket(int no, string firstname[], string lastname[], string sex[], int age[]);
    int display_price(string source, string destination, int N, string username);
};

#endif // OUTPUTMODULE_H
