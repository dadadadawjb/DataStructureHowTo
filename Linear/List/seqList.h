#ifndef LIST_SEQLIST_H
#define LIST_SEQLIST_H

#include "list.h"

/* declaration */
template <class elemType>
class seqList: public list<elemType>{
private:
    elemType *data;
    int currentLength;
    int maxSize;

    void doubleSpace();

public:
    seqList(int initSize = 10);
    ~seqList();
    void clear();
    int length() const;
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
    elemType sum(const elemType zero) const;    // added function
    elemType max(int &maxPos) const;            // added function
    elemType min(int &minPos) const;            // added function
};


/* implementation */
template <class elemType>
void seqList<elemType>::clear() {
    currentLength = 0;
}

template <class elemType>
int seqList<elemType>::length() const {
    return currentLength;
}

template <class elemType>
seqList<elemType>::seqList(int initSize) {
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}

template <class elemType>
seqList<elemType>::~seqList() {
    delete []data;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x) {
    if (currentLength == maxSize)
        doubleSpace();
    for (int j = currentLength; j < i; j--) {
        data[j] = data[j - 1];
    }
    data[i] = x;
    currentLength++;
}

template <class elemType>
void seqList<elemType>::remove(int i) {
    for (int j = i; j < currentLength - 1; j++)
        data[j] = data[j + 1];
    currentLength--;
}

template <class elemType>
int seqList<elemType>::search(const elemType &x) const {
    int i;
    for (i = 0; i < currentLength && data[i] != x; i++);
    if (i == currentLength)
        return -1;
    else
        return i;
}

template <class elemType>
elemType seqList<elemType>::visit(int i) const {
    return data[i];
}

template <class elemType>
void seqList<elemType>::traverse() const {
    for (int i = 0; i < currentLength; i++)
        cout << data[i] << ' ';
    cout << endl;
}

template <class elemType>
void seqList<elemType>::doubleSpace() {
    elemType *tmp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for (int i = 0; i < currentLength; i++)
        data[i] = tmp[i];
    delete []tmp;
}

template <class elemType>
elemType seqList<elemType>::sum(const elemType zero) const {
    if (currentLength == 0)
        return zero;

    elemType s = data[0];
    for (int i = 1; i < currentLength; i++)
        s += data[i];
    return s;
}

template <class elemType>
elemType seqList<elemType>::max(int &maxPos) const {
    if (currentLength == 0) {
        maxPos = NULL;
        return NULL;
    }

    elemType m = data[0];
    for (int i = 1; i < currentLength; i++) {
        if (data[i] > m) {
            m = data[i];
            maxPos = i;
        }
    }
    return m;
}

template <class elemType>
elemType seqList<elemType>::min(int &minPos) const {
    if (currentLength == 0) {
        minPos = NULL;
        return NULL;
    }

    elemType m = data[0];
    for (int i = 1; i < currentLength; i++) {
        if (data[i] < m) {
            m = data[i];
            minPos = i;
        }
    }
    return m;
}


#endif // LIST_SEQLIST_H
