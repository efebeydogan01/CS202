/*
* Title: Heaps
* Author: Efe Beydogan
* ID: 21901548
* Section: 1
* Assignment: 3
* Description: printer simulator h file
*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "PriorityQueue.h"

using namespace std;

class simulator {
public:
    simulator();

    void findOptimum( Request*& arr, double avgWaitTime, int requests);
};
#endif // SIMULATOR_H

