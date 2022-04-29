#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

#include <iostream>
using namespace std;
#include "../../Search/StaticSearchTable/set.h"

template <class KEY, class OTHER>
void merge(SET<KEY, OTHER> a[], int low, int mid, int high) {
    SET<KEY, OTHER> *tmp = new SET<KEY, OTHER>[high - low + 1];

    int i = low, j = mid, k = 0;

    while (i < mid && j <= high) {
        if (a[i].key < a[j].key)
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while (i < mid)
        tmp[k++] = a[i++];
    while (j <= high)
        tmp[k++] = a[j++];

    for (i = 0, j = low; j <= high; i++, j++)
        a[j] = tmp[i];

    delete []tmp;
}

template <class KEY, class OTHER>
void mergeSort(SET<KEY, OTHER> a[], int low, int high) {
    if (low == high)
        return;

    int mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid + 1, high);
}

template <class KEY, class OTHER>
void mergeSort(SET<KEY, OTHER> a[], int size) {
    mergeSort(a, 0, size - 1);
}


#endif // MERGESORT_MERGESORT_H
