#ifndef LIST_SLINKLIST_H
#define LIST_SLINKLIST_H

#include "list.h"

/* declaration */
template <class elemType>
class sLinkList: public list<elemType> {
private:
    struct node {
        elemType data;
        node *next;

        node(const elemType &x, node *n = NULL) {
            data = x;
            next = n;
        }
        node():next(NULL) {};
        ~node() {};
    };

    node *head;
    int currentLength;

    node *move(int i) const;

public:
    sLinkList();
    ~sLinkList() {
        clear();
        delete head;
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
typename sLinkList<elemType>::node *sLinkList<elemType>::move(int i) const {
    node *p = head;
    while (i-- >= 0) {
        p = p->next;
    }
    return p;
}

template <class elemType>
sLinkList<elemType>::sLinkList() {
    head = new node;
    currentLength = 0;
}

template <class elemType>
void sLinkList<elemType>::clear() {
    node *p = head->next;
    node *q;
    head->next = NULL;
    while (p != NULL) {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}

template <class elemType>
void sLinkList<elemType>::insert(int i, const elemType &x) {
    node *pos;
    pos = move(i-1);
    pos->next = new node(x, pos->next);
    currentLength++;
}

template <class elemType>
void sLinkList<elemType>::remove(int i) {
    node *pos, *delp;
    pos = move(i - 1);
    delp = pos->next;
    pos->next = delp->next;
    delete delp;
    currentLength--;
}

template <class elemType>
int sLinkList<elemType>::search(const elemType &x) const {
    node *p = head->next;
    int i = 0;
    while (p != NULL && p->data != x) {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return -1;
    else
        return i;
}

template <class elemType>
elemType sLinkList<elemType>::visit(int i) const {
    return move(i)->data;
}

template <class elemType>
void sLinkList<elemType>::traverse() const {
    node *p = head->next;
    while (p != NULL) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}


#endif // LIST_SLINKLIST_H
