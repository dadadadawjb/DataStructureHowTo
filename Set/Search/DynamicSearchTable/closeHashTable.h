#ifndef DYNAMICSEARCHTABLE_CLOSEHASHTABLE_H
#define DYNAMICSEARCHTABLE_CLOSEHASHTABLE_H

#include "dynamicSearchTable.h"

/* declaration */
template <class KEY, class OTHER>
class closeHashTable: public dynamicSearchTable<KEY, OTHER> {
private:
    struct node {
        SET<KEY, OTHER> data;
        int state;

        node() {
            state = 0;
        }
    };

    node *array;
    int size;

    int (*key)(const KEY &x);
    static int defaultKey(const int &x) {
        return x;
    }

public:
    closeHashTable(int length = 101, int (*f)(const KEY &x) = defaultKey);
    ~closeHashTable();
    void insert(const SET<KEY, OTHER> &x);
    void remove(const KEY &x);
    SET<KEY, OTHER> *find(const KEY &x) const;
    void rehash();
    void printTable();
};


/* implementation */
template <class KEY, class OTHER>
closeHashTable<KEY, OTHER>::closeHashTable(int length, int (*f)(const KEY &x)) {
    size = length;
    array = new node[size];
    key = f;
}

template <class KEY, class OTHER>
closeHashTable<KEY, OTHER>::~closeHashTable() {
    delete []array;
}

template <class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::insert(const SET<KEY, OTHER> &x) {
    int initPos, pos;

    initPos = pos = key(x.key) % size;
    do {
        if (array[pos].state != 1) {
            array[pos].data = x;
            array[pos].state = 1;
            return;
        }
        pos = (pos + 1) % size;
    } while (pos != initPos);
}

template <class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::remove(const KEY &x) {
    int initPos, pos;

    initPos = pos = key(x) % size;
    do {
        if (array[pos].state == 0)
            return;
        if (array[pos].state == 1 && array[pos].data.key == x) {
            array[pos].state = 2;
            return;
        }
        pos = (pos + 1) % size;
    } while (pos != initPos);
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *closeHashTable<KEY, OTHER>::find(const KEY &x) const {
    int initPos, pos;

    initPos = pos = key(x) % size;
    do {
        if (array[pos].state == 0)
            return NULL;
        if (array[pos].state == 1 && array[pos].data.key == x)
            return (SET<KEY, OTHER> *)&array[pos];
        pos = (pos + 1) % size;
    } while (pos != initPos);
}

template <class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::rehash() {
    node *tmp = array;
    array = new node[size];
    for (int i = 0; i < size; i++) {
        if (tmp[i].state == 1)
            insert(tmp[i].data);
    }
    delete []tmp;
}

template <class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::printTable() {
    for (int i = 0; i < size; i++)
        if (array[i].state == 0)
            cout << "(NULL) ";
        else if (array[i].state == 1)
            cout << "(" << array[i].data.key << "," << array[i].data.other << "," << array[i].state << ") ";
        else if (array[i].state == 2)
            cout << "(" << array[i].data.key << "," << array[i].data.other << ",deleted) ";
    cout << endl;
}


#endif // DYNAMICSEARCHTABLE_CLOSEHASHTABLE_H
