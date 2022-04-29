#ifndef QUEUE_LINKQUEUE_H
#define QUEUE_LINKQUEUE_H

#include "queue.h"

/* declaration */
template <class elemType>
class linkQueue: public queue<elemType> {
private:
    struct node {
        elemType data;
        node *next;

        node(const elemType &x, node *n = NULL) {
            data = x;
            next = n;
        }
        node():next(NULL) {};
        ~node() {};
    };

    node *front, *rear;

public:
    linkQueue();
    ~linkQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
};


/* implementation */
template <class elemType>
linkQueue<elemType>::linkQueue() {
    front = rear = NULL;
}

template <class elemType>
linkQueue<elemType>::~linkQueue() {
    node *tmp;
    while (front != NULL) {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template <class elemType>
bool linkQueue<elemType>::isEmpty() const {
    return front == NULL;
}

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x) {
    if (rear == NULL)
        front = rear = new node(x);
    else
        rear = rear->next = new node(x);
}

template <class elemType>
elemType linkQueue<elemType>::deQueue() {
    if (isEmpty())
        return NULL;
    node *tmp = front;
    elemType x = front->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete tmp;
    return x;
}

template <class elemType>
elemType linkQueue<elemType>::getHead() const {
    if (isEmpty())
        return NULL;
    return front->data;
}


#endif // QUEUE_LINKQUEUE_H
