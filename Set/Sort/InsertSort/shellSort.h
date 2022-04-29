#ifndef INSERTSORT_SHELLSORT_H
#define INSERTSORT_SHELLSORT_H

#include <iostream>
using namespace std;
#include "../../Search/StaticSearchTable/set.h"

template <class KEY, class OTHER>
void shellSort(SET<KEY, OTHER> a[], int size) {
    int step;
    int k;
    SET<KEY, OTHER> tmp;
    for (step = size / 2; step > 0; step /= 2) {
        for (int j = step; j < size; j++) {
            tmp = a[j];
            for (k = j - step; k >= 0 && a[k].key > tmp.key; k -= step)
                a[k + step] = a[k];
            a[k + step] = tmp;
        }
    }
}


#endif // INSERTSORT_SHELLSORT_H
