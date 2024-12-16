#include "bellmanford.h"
#include "datamodule.h"

#include <iostream>

bellmanfordalgorithm::bellmanfordalgorithm()
{
    N = 15;
}

void bellmanfordalgorithm::algorithmic_implementation()
{
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < N; k++)
            {
                if (journey[i].cost[j] > journey[i].cost[k] + journey[k].cost[j])
                {
                    journey[i].cost[j] = journey[i].cost[k] + journey[k].cost[j];
                    journey[i].array[j] = k;
                }
            }
        }
    }
}

void bellmanfordalgorithm::floydWarshall()
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (journey[i].cost[k] + journey[k].cost[j] < journey[i].cost[j])
                {
                    journey[i].cost[j] = journey[i].cost[k] + journey[k].cost[j];
                    journey[i].array[j] = k;
                }
            }
        }
    }
}
