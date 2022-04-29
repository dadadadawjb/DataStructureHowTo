#ifndef INSERTSORT_BINARYINSERTSORT_H
#define INSERTSORT_BINARYINSERTSORT_H

#include <iostream>
using namespace std;
#include "../../Search/StaticSearchTable/set.h"

template <class KEY, class OTHER>
void binaryInsertSort(SET<KEY, OTHER> a[], int size) {
    int k;
    SET<KEY, OTHER> tmp;

    for (int j = 1; j < size; j++) {
        tmp = a[j];
        int low = 0;
        int high = j - 1;
        int position;           // get the first position to be moved
        bool flag = true;       // determine whether we find the same key element

        // begin searching
        while (low <= high && flag) {
            int mid = (low + high) / 2;
            if (a[mid].key == tmp.key) {
                do {
                    position = mid + 1;
                } while (a[position].key == tmp.key);
                flag = false;
            }
            if (a[mid].key < tmp.key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (flag)
            position = low;

        // begin moving
        for (k = j - 1; k >= 0 && k >= position; k--)
            a[k + 1] = a[k];
        a[k + 1] = tmp;
    }
}


#endif // INSERTSORT_BINARYINSERTSORT_H
