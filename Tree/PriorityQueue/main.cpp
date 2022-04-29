#include "priorityQueue.h"

int main() {
    ////////// Test PriorityQueue //////////
    cout << "////////// Test Priority Queue //////////" << endl;
    priorityQueue<int> myPriorityQueue(10);
    cout << "enqueue 3:" << endl;
    myPriorityQueue.enQueue(3);
    cout << "get head:" << endl;
    cout << myPriorityQueue.getHead() << endl;
    cout << "enqueue 2:" << endl;
    myPriorityQueue.enQueue(2);
    cout << "get head:" << endl;
    cout << myPriorityQueue.getHead() << endl;
    cout << "enqueue 5:" << endl;
    myPriorityQueue.enQueue(5);
    cout << "get head:" << endl;
    cout << myPriorityQueue.getHead() << endl;
    cout << "enqueue 1:" << endl;
    myPriorityQueue.enQueue(1);
    cout << "get head:" << endl;
    cout << myPriorityQueue.getHead() << endl;
    cout << "enqueue 4:" << endl;
    myPriorityQueue.enQueue(4);
    cout << "get head:" << endl;
    cout << myPriorityQueue.getHead() << endl;
    cout << "dequeue:" << endl;
    cout << myPriorityQueue.deQueue() << endl;
    cout << "get head:" << endl;
    cout << myPriorityQueue.getHead() << endl;
    cout << "is empty:" << endl;
    cout << myPriorityQueue.isEmpty() << endl;
    return 0;
}
