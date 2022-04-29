#ifndef PRIORITYQUEUE_SIMULATOR_H
#define PRIORITYQUEUE_SIMULATOR_H

#include <ctime>

#include "../priorityQueue.h"
#include "../../Linear/Queue/linkQueue.h"

class simulator {
    int noOfServer;
    int arrivalTimeLow;
    int arrivalTimeHigh;
    int serviceTimeLow;
    int serviceTimeHigh;
    int customNum;

    struct eventT {
        int time;
        int type;

        bool operator<(const eventT &e) const {
            return time < e.time;
        }
    };

public:
    simulator();
    int avgWaitTime();
};


#endif // PRIORITYQUEUE_SIMULATOR_H
