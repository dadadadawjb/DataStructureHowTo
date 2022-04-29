#ifndef QUEUE_SIMULATOR_H
#define QUEUE_SIMULATOR_H

#include <ctime>

#include "..\linkQueue.h"

class simulator {
    int arrivalTimeLow;
    int arrivalTimeHigh;
    int serviceTimeLow;
    int serviceTimeHigh;
    int customNum;

public:
    simulator();
    int avgWaitTime() const;
};


#endif // QUEUE_SIMULATOR_H
