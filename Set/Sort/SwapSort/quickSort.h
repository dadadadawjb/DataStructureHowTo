#ifndef SWAPSORT_QUICKSORT_H
#define SWAPSORT_QUICKSORT_H

#include <iostream>
using namespace std;
#include "../../Search/StaticSearchTable/set.h"

template <class KEY, class OTHER>
int divide(SET<KEY, OTHER> a[], int low, int high) {
    SET<KEY, OTHER> bench = a[low];
    do {
        for (; a[high].key >= bench.key && low < high; high--);
        if (low < high) {
            a[low] = a[high];
            low++;
        }
        for (; a[low].key < bench.key && low < high; low++);
        if (low < high) {
            a[high] = a[low];
            high--;
        }
    } while (low != high);
    a[low] = bench;
    return low;
}

template <class KEY, class OTHER>
void quickSort(SET<KEY, OTHER> a[], int low, int high) {
    if (low >= high)
        return;

    int mid = divide(a, low, high);
    quickSort(a, low, mid - 1);
    quickSort(a, mid + 1, high);
}

template <class KEY, class OTHER>
void quickSort(SET<KEY, OTHER> a[], int size) {
    quickSort(a, 0, size - 1);
}


#endif // SWAPSORT_QUICKSORT_H
