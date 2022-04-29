#ifndef INSERTSORT_SIMPLEINSERTSORT_H
#define INSERTSORT_SIMPLEINSERTSORT_H

#include <iostream>
using namespace std;
#include "../../Search/StaticSearchTable/set.h"

template <class KEY, class OTHER>
void simpleInsertSort(SET<KEY, OTHER> a[], int size) {
    int k;
    SET<KEY, OTHER> tmp;

    for (int j = 1; j < size; j++) {
        tmp = a[j];
        for (k = j - 1; k >= 0&& tmp.key < a[k].key; k--) {
            // the search process is combined in the condition statement
            a[k + 1] = a[k];
        }
        a[k + 1] = tmp;
    }
}

#endif // INSERTSORT_SIMPLEINSERTSORT_H
