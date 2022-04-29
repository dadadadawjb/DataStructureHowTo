#ifndef QUEUE_SEQQUEUE_H
#define QUEUE_SEQQUEUE_H

#include "queue.h"

/* declaration */
template <class elemType>
class seqQueue: public queue<elemType> {
private:
    elemType *elem;
    int maxSize;
    int front, rear;
    void doubleSpace();

public:
    seqQueue(int initsize = 10);
    ~seqQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
};


/* implementation */
template <class elemType>
seqQueue<elemType>::seqQueue(int initSize) {
    elem = new elemType[initSize];
    maxSize = initSize;
    front = rear = 0;
}

template <class elemType>
seqQueue<elemType>::~seqQueue() {
    delete []elem;
}

template <class elemType>
bool seqQueue<elemType>::isEmpty() const {
    return front == rear;
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x) {
    if ((rear + 1) % maxSize == front)
        doubleSpace();
    rear = (rear + 1) % maxSize;
    elem[rear] = x;
}

template <class elemType>
elemType seqQueue<elemType>::deQueue() {
    if (isEmpty())
        return NULL;
    front = (front + 1) % maxSize;
    return elem[front];
}

template <class elemType>
elemType seqQueue<elemType>::getHead() const {
    if (isEmpty())
        return NULL;
    return elem[(front + 1) % maxSize];
}

template <class elemType>
void seqQueue<elemType>::doubleSpace() {
    elemType *tmp = elem;
    elem = new elemType[2*maxSize];
    for (int i = 1; i < maxSize; i++)
        elem[i] = tmp[(front + 1) % maxSize];
    front = 0;
    rear = maxSize - 1;
    maxSize *= 2;
    delete tmp;
}


#endif // QUEUE_SEQQUEUE_H
