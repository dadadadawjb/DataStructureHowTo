#include "simulator.h"

simulator::simulator() {
    cout << "input the num of servers: ";
    cin >> noOfServer;
    cout << "input the arrival time:" << endl;
    cout << "arrivalTimeLow: ";
    cin >> arrivalTimeLow;
    cout << "arrivalTimeHigh: ";
    cin >> arrivalTimeHigh;

    cout << "\ninput the service time:" << endl;
    cout << "serviceTimeLow: ";
    cin >> serviceTimeLow;
    cout << "serviceTimeHigh: ";
    cin >> serviceTimeHigh;

    cout << "\ninput the custom num: ";
    cin >> customNum;

    srand(time(NULL));
}

int simulator::avgWaitTime() {
    int serverBusy = 0;
    int currentTime;
    int totalWaitTime = 0;
    priorityQueue<eventT> eventQueue;
    linkQueue<eventT> waitQueue;
    eventT currentEvent;

    currentEvent.time = 0;
    currentEvent.type = 0;
    for (int i = 0; i < customNum; i++) {
        currentEvent.time += arrivalTimeLow + (arrivalTimeHigh-arrivalTimeLow+1)*rand()/(RAND_MAX+1);
        eventQueue.enQueue(currentEvent);
    }

    while (!eventQueue.isEmpty()) {
        currentEvent = eventQueue.deQueue();
        currentTime = currentEvent.time;
        switch (currentEvent.type) {
            case 0:
                if (serverBusy != noOfServer) {
                    serverBusy++;
                    currentEvent.time += serviceTimeLow + (serviceTimeHigh-serviceTimeLow+1)*rand()/(RAND_MAX+1);
                    currentEvent.type = 1;
                    eventQueue.enQueue(currentEvent);
                } else {
                    waitQueue.enQueue(currentEvent);
                }
                break;
            case 1:
                if (!waitQueue.isEmpty()) {
                    currentEvent = waitQueue.deQueue();
                    totalWaitTime += currentTime - currentEvent.time;
                    currentEvent.time = currentTime + serviceTimeLow + (serviceTimeHigh-serviceTimeLow+1)*rand()/(RAND_MAX+1);
                    currentEvent.type = 1;
                    eventQueue.enQueue(currentEvent);
                } else {
                    serverBusy--;
                }
        }
    }

    return totalWaitTime / customNum;
}