#include "memory.h"

memory::memory(int capacity) {
    head = new node;
    head->next = new node(0, capacity - 1, head);
    head->next->next = tail = new node;
    tail->prev=head->next;
}

memory::~memory() {
    node *p = head;
    node *q;

    while (p != NULL) {
        q = p->next;
        delete p;
        p = q;
    }
}

int memory::malloc(int size) {
    node *p = head->next;
    int returnValue;

    while (p != tail && p->end - p->start + 1 < size)
        p = p->next;
    if (p == tail)
        return -1;
    returnValue = p->start;
    if (p->end - p->start + 1 == size) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    } else {
        p->start += size;
    }

    return returnValue;
}

void memory::free(int start, int size) {
    node *p = head->next;
    node *np;

    while (p != tail && p->start < start)
        p = p->next;

    if (p != tail && start + size == p->start) {
        p->start = start;
        np = p;
    } else {
        np = new node(start, start + size - 1, p->prev, p);
        p->prev->next = np;
        p->prev = np;
    }

    p = np->prev;
    if (p->end + 1 == np->start) {
        p->end = np->end;
        p->next = np->next;
        np->next->prev = p;
        delete np;
    }
}