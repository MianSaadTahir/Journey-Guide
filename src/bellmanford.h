#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "datamodule.h"

class bellmanfordalgorithm : public datamodule
{
public:
    int N, i, j, k;
    bellmanfordalgorithm();
    void algorithmic_implementation();
    void floydWarshall();
};

#endif // BELLMANFORD_H
