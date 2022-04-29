#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H

#include "../../Linear/Queue/queue.h"
#include <iostream>
using namespace std;

/* declaration */
template <class Type>
class priorityQueue: public queue<Type> {
public:
    priorityQueue(int capacity = 100);
    priorityQueue(const Type data[], int size);
    ~priorityQueue();
    bool isEmpty() const;
    Type getHead() const;
    void enQueue(const Type &x);
    Type deQueue();

private:
    Type *array;
    int currentSize;
    int maxSize;

    void percolateDown(int hole);
    void buildHeap();
    void doubleSpace();
};


/* implementation */
template <class Type>
priorityQueue<Type>::priorityQueue(int capacity) {
    array = new Type[capacity];
    maxSize = capacity;
    currentSize = 0;
}

template <class Type>
priorityQueue<Type>::priorityQueue(const Type data[], int size):maxSize(size+10), currentSize(size) {
    array = new Type[maxSize];
    for (int i = 0; i < size; i++)
        array[i + 1] = data[i];
    buildHeap();
}

template <class Type>
priorityQueue<Type>::~priorityQueue() {
    delete []array;
}

template <class Type>
bool priorityQueue<Type>::isEmpty() const {
    return currentSize == 0;
}

template <class Type>
Type priorityQueue<Type>::getHead() const {
    return array[1];
}

template <class Type>
void priorityQueue<Type>::enQueue(const Type &x) {
    if (currentSize + 1 == maxSize)
        doubleSpace();

    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole / 2]; hole /= 2) {
        array[hole] = array[hole / 2];
    }
    array[hole] = x;
}

template <class Type>
Type priorityQueue<Type>::deQueue() {
    Type minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return minItem;
}

template <class Type>
void priorityQueue<Type>::percolateDown(int hole) {
    int child;
    Type tmp = array[hole];
    for(; hole * 2 <= currentSize; hole = child) {
        child = hole * 2;
        if (child != currentSize && array[child+1] < array[child])
            child++;
        if (array[child] < tmp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = tmp;
}

template <class Type>
void priorityQueue<Type>::buildHeap() {
    for (int i = currentSize / 2; i > 0; i--)
        percolateDown(i);
}

template <class Type>
void priorityQueue<Type>::doubleSpace() {
    Type *tmp = array;
    maxSize *= 2;
    array = new Type[maxSize];
    for (int i = 0; i < currentSize; i++)
        array[i] = tmp[i];
    delete []tmp;
}

#endif // PRIORITYQUEUE_PRIORITYQUEUE_H
