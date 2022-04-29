#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <iostream>
using namespace std;

/* virtual function */
template <class T>
class tree {
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T root(T flag) const = 0;
    virtual T parent(T x, T flag) const = 0;
    virtual T child(T x, int i, T flag) const = 0;
    virtual void remove(T x, int i) = 0;
    virtual void traverse() const = 0;
};


#endif // TREE_TREE_H
