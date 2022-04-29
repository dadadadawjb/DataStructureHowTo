#include "simulator.h"

simulator::simulator() {
    cout << "input the arrival time:" << endl;
    cout << "arrivalTimeLow: ";
    cin >> arrivalTimeLow;
    cout << "arrivalTimeHigh: ";
    cin >> arrivalTimeHigh;

    cout << "\ninput the service time:" <<endl;
    cout << "serviceTimeLow: ";
    cin >> serviceTimeLow;
    cout << "serviceTimeHigh: ";
    cin >> serviceTimeHigh;

    cout << "\ninput the custom num: ";
    cin >> customNum;

    srand(time(NULL));
}

int simulator::avgWaitTime() const {
    int currentTime = 0;
    int totalWaitTime = 0;
    int eventTime;
    linkQueue<int> customerQueue;

    for (int i = 0; i < customNum; i++) {
        currentTime += arrivalTimeLow + (arrivalTimeHigh-arrivalTimeLow+1)*rand()/(RAND_MAX+1);
        customerQueue.enQueue(currentTime);
    }

    currentTime = 0;
    while (!customerQueue.isEmpty()) {
        eventTime = customerQueue.deQueue();
        if (eventTime < currentTime)
            totalWaitTime += currentTime - eventTime;
        else
            currentTime = eventTime;
        currentTime += serviceTimeLow + (serviceTimeHigh-serviceTimeLow+1)*rand()/(RAND_MAX+1);
    }

    return totalWaitTime / customNum;
}