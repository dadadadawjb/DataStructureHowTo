#ifndef DYNAMICSEARCHTABLE_DYNAMICSEARCHTABLE_H
#define DYNAMICSEARCHTABLE_DYNAMICSEARCHTABLE_H

#include <iostream>
#include "../StaticSearchTable/set.h"
using namespace std;

/* virtual function */
template <class KEY, class OTHER>
class dynamicSearchTable {
public:
    virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
    virtual void insert(const SET<KEY, OTHER> &x) = 0;
    virtual void remove(const KEY &x) = 0;
    virtual ~dynamicSearchTable() {};
};


#endif // DYNAMICSEARCHTABLE_DYNAMICSEARCHTABLE_H
