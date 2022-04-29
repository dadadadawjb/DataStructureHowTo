#ifndef BASICGRAPH_GRAPH_H
#define BASICGRAPH_GRAPH_H

#include <iostream>
using namespace std;

/* virtual function */
template <class TypeOfVer, class TypeOfEdge>
class graph {
public:
    virtual void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) = 0;
    virtual void remove(TypeOfVer x, TypeOfVer y) = 0;
    virtual bool exist(TypeOfVer x, TypeOfVer y) const = 0;
    int numOfVer() const {
        return Vers;
    }
    int numOfEdge() const {
        return Edges;
    }

protected:
    int Vers;
    int Edges;
};


#endif // BASICGRAPH_GRAPH_H
