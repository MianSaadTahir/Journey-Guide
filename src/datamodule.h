#ifndef DATAMODULE_H
#define DATAMODULE_H

#include <string>
using namespace std;

extern struct CityData journey[15];
extern struct InitialCosts ini[15];
struct CityData
{
    long long int cost[20];
    int array[20];
};

struct InitialCosts
{
    long long int cost[20];
};

class datamodule
{
public:
    string city[15];
    datamodule();

    void costdeclaration();
};

#endif
