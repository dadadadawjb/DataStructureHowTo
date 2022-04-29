#ifndef SELECTSORT_SIMPLESELECTSORT_H
#define SELECTSORT_SIMPLESELECTSORT_H

#include <iostream>
using namespace std;
#include "../../Search/StaticSearchTable/set.h"

template <class KEY, class OTHER>
void simpleSelectSort(SET<KEY, OTHER> a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j].key < a[min].key)
                min = j;
        }
        swap(a[min], a[i]);
    }
}


#endif // SELECTSORT_SIMPLESELECTSORT_H
