#ifndef SWAPSORT_BUBBLESORT_H
#define SWAPSORT_BUBBLESORT_H

#include <iostream>
using namespace std;
#include "../../Search/StaticSearchTable/set.h"

template <class KEY, class OTHER>
void bubbleSort(SET<KEY, OTHER> a[], int size) {
    for (int i = 1; i < size; i++) {
        bool flag = false;
        for (int j = 0; j < size - i; j++) {
            if (a[j].key > a[j+1].key) {
                swap(a[j], a[j+1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}


#endif // SWAPSORT_BUBBLESORT_H
