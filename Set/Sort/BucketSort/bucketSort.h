#ifndef BUCKETSORT_BUCKETSORT_H
#define BUCKETSORT_BUCKETSORT_H

#include <iostream>
using namespace std;
#include "../../Search/StaticSearchTable/set.h"

template <class OTHER>
struct node {
    SET<int, OTHER> data;
    node *next;

    node() {
        next = NULL;
    }
    node(SET<int, OTHER> d):data(d) {
        next = NULL;
    }
};

template <class OTHER>
void bucketSort(node<OTHER> *&p) {
    node<OTHER> *bucket[10], *last[10], *tail;
    int i, j, k, base = 1, max = 0, len = 0;

    for (tail = p; tail != NULL; tail = tail->next) {
        if (tail->data.key > max)
            max = tail->data.key;
    }

    if (max == 0)
        len = 0;
    else
        while (max > 0) {
            len++;
            max /= 10;
        }

    for (i = 1; i <= len; i++) {
        for (j = 0; j <= 9; j++)
            bucket[j] = last[j] = NULL;

        while (p != NULL) {
            k = p->data.key / base % 10;
            if (bucket[k] == NULL)
                bucket[k] = last[k] = p;
            else
                last[k] = last[k]->next = p;
            p = p->next;
        }
        p = NULL;
        for (j = 0; j <= 9; j++) {
            if (bucket[j] == NULL)
                continue;
            if (p == NULL)
                p = bucket[j];
            else
                tail->next = bucket[j];
            tail = last[j];
        }
        tail->next = NULL;
        base *= 10;
    }
}


#endif // BUCKETSORT_BUCKETSORT_H
