#include "queue.h"
#include "seqQueue.h"
#include "linkQueue.h"

int main() {
    ////////// Test SeqQueue //////////
    seqQueue<int> mySeqQueue(10);
    cout << "////////// Test sequence queue //////////" << endl;
    cout << "is empty:" << endl;
    cout << mySeqQueue.isEmpty() << endl;
    cout << "enqueue 0:" << endl;
    mySeqQueue.enQueue(0);
    cout << mySeqQueue.getHead() << endl;
    cout << "enqueue 1 and 2:" << endl;
    mySeqQueue.enQueue(1);
    mySeqQueue.enQueue(2);
    cout << "head element:" << endl;
    cout << mySeqQueue.getHead() << endl;
    cout << "dequeue:" << endl;
    cout << mySeqQueue.deQueue() << endl;

    ////////// Test LinkQueue //////////
    linkQueue<int> myLinkQueue;
    cout << "////////// Test link queue //////////" << endl;
    cout << "is empty:" << endl;
    cout << myLinkQueue.isEmpty() << endl;
    cout << "enqueue 0:" << endl;
    myLinkQueue.enQueue(0);
    cout << myLinkQueue.getHead() << endl;
    cout << "enqueue 1 and 2:" << endl;
    myLinkQueue.enQueue(1);
    myLinkQueue.enQueue(2);
    cout << "head element:" << endl;
    cout << myLinkQueue.getHead() << endl;
    cout << "dequeue:" << endl;
    cout << myLinkQueue.deQueue() << endl;
    return 0;
}
