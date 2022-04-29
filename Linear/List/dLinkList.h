#ifndef LIST_DLINKLIST_H
#define LIST_DLINKLIST_H

#include "list.h"

/* declaration */
template <class elemType>
class dLinkList: public list<elemType> {
private:
    struct node {
        elemType data;
        node *prev, *next;

        node(const elemType &x, node *p = NULL, node *n = NULL) {
            data = x;
            next = n;
            prev = p;
        }
        node():next(NULL),prev(NULL) {};
        ~node() {};
    };

    node *head, *tail;
    int currentLength;

    node *move(int i) const;

public:
    dLinkList();
    ~dLinkList() {
        clear();
        delete head;
        delete tail;
    }
    void clear();
    int length() const {
        return currentLength;
    }
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
};


/* implementation */
template <class elemType>
typename dLinkList<elemType>::node *dLinkList<elemType>::move(int i) const {
    node *p = head;
    while (i-- >= 0)
        p = p->next;
    return p;
}

template <class elemType>
dLinkList<elemType>::dLinkList() {
    head = new node;
    head->next = tail = new node;
    tail->prev = head;
    currentLength = 0;
}

template <class elemType>
void dLinkList<elemType>::clear() {
    node *p = head->next;
    node *q;
    head->next = tail;
    tail->prev = head;
    while (p != tail) {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}

template <class elemType>
void dLinkList<elemType>::insert(int i, const elemType &x) {
    node *pos, *tmp;
    pos = move(i);
    tmp = new node(x, pos->prev, pos);
    pos->prev->next = tmp;
    pos->prev = tmp;
    currentLength++;
}

template <class elemType>
void dLinkList<elemType>::remove(int i) {
    node *pos;
    pos = move(i);
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    currentLength--;
}

template <class elemType>
int dLinkList<elemType>::search(const elemType &x) const {
    node *p = head->next;
    int i;
    for (i = 0; p != tail && p->data != x; i++)
        p = p->next;
    if (p == tail)
        return -1;
    else
        return i;
}

template <class elemType>
elemType dLinkList<elemType>::visit(int i) const {
    return move(i)->data;
}

template <class elemType>
void dLinkList<elemType>::traverse() const {
    node *p = head->next;
    while (p != tail) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}


#endif // LIST_DLINKLIST_H
