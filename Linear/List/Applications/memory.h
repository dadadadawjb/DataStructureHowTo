#ifndef LIST_MEMORY_H
#define LIST_MEMORY_H

#include <iostream>
using namespace std;

class memory {
    struct node {
        int start;
        int end;
        node *prev;
        node *next;

        node() {
            start = 0;
            end = 0;
            prev = NULL;
            next = NULL;
        }
        node(int s, int e, node *p = NULL, node *n = NULL) {
            start = s;
            end = e;
            prev = p;
            next = n;
        }
    };

    node *head;
    node *tail;

public:
    memory(int capacity);
    int malloc(int size);
    void free(int start, int size);
    ~memory();
};


#endif // LIST_MEMORY_H
