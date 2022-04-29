#ifndef SELECTSORT_HEAPSORT_H
#define SELECTSORT_HEAPSORT_H

#include <iostream>
using namespace std;
#include "../../Search/StaticSearchTable/set.h"

template <class KEY, class OTHER>
void percolateDown(SET<KEY, OTHER> a[], int hole, int size) {
    int child;
    SET<KEY, OTHER> tmp = a[hole];

    for (; hole * 2 + 1 < size; hole = child) {
        child = hole * 2 + 1;
        if (child != size-1 && a[child+1].key > a[child].key)
            child++;
        if (a[child].key > tmp.key)
            a[hole] = a[child];
        else
            break;
    }
    a[hole] = tmp;
}

template <class KEY, class OTHER>
void heapSort(SET<KEY, OTHER> a[], int size) {
    int i;

    for (i = size / 2 - 1; i >= 0;i--)
        percolateDown(a, i, size);

    for (i = size - 1; i > 0; i--) {
        swap(a[0], a[i]);
        percolateDown(a, 0, i);
    }
}

#endif // SELECTSORT_HEAPSORT_H
