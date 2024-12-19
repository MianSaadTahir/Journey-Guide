#include "datamodule.h"
#include <iostream>

#define INF 999999999
using namespace std;

struct CityData journey[15];
struct InitialCosts ini[15];
datamodule::datamodule() : city{"London", "Paris", "New York", "Tokyo", "Sydney", "Rome", "Berlin", "Los Angeles", "Dubai", "Toronto", "Barcelona", "Moscow", "Madrid", "Seoul", "Cape Town"} {}

void datamodule::costdeclaration()
{
    int N, i, j;
    N = 15;
    long long int arr[15][15] = {{0, 3500, 2000, INF, 1000, INF, INF, INF, INF, 7000, 4000, 1500, INF, 6500, INF},
                                 {3500, 0, INF, 1520, INF, INF, INF, 2500, INF, INF, INF, INF, INF, INF, 5000},
                                 {2000, INF, 0, 1500, INF, 3000, INF, INF, INF, INF, 2000, 1000, INF, INF, 1500},
                                 {INF, 1520, 1500, 0, INF, 1200, 4500, INF, 6000, INF, INF, INF, INF, INF, 1000},
                                 {1000, INF, INF, INF, 0, 1500, INF, INF, INF, INF, INF, INF, INF, INF, INF},
                                 {INF, INF, 3000, 1200, 1500, 0, 1950, INF, INF, INF, INF, INF, INF, INF, INF},
                                 {INF, INF, INF, 4500, INF, 1950, 0, INF, INF, 2050, INF, INF, INF, INF, INF},
                                 {INF, 2500, INF, INF, INF, INF, INF, 0, 5000, INF, INF, INF, INF, INF, INF},
                                 {INF, INF, INF, 6000, INF, INF, INF, 5000, 0, 7000, INF, INF, INF, INF, INF},
                                 {7000, INF, INF, INF, INF, INF, 2050, INF, 7000, 0, INF, INF, INF, INF, INF},
                                 {4000, INF, 2000, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF},
                                 {1500, INF, 1000, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF},
                                 {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF},
                                 {6500, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF},
                                 {INF, 5000, 1500, 1000, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0}};
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            journey[i].cost[j] = arr[i][j];
            journey[i].array[j] = j;
            ini[i].cost[j] = arr[i][j];
        }
    }
}
