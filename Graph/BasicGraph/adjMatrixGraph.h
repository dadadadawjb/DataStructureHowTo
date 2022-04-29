#ifndef BASICGRAPH_ADJMATRIXGRAPH_H
#define BASICGRAPH_ADJMATRIXGRAPH_H

#include "graph.h"

/* declaration */
template <class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph: public graph<TypeOfVer, TypeOfEdge> {
public:
    adjMatrixGraph(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag);
    ~adjMatrixGraph();
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
    void remove(TypeOfVer x, TypeOfVer y);
    bool exist(TypeOfVer x, TypeOfVer y) const;

private:
    TypeOfVer *ver;
    TypeOfEdge **edge;
    TypeOfEdge noEdge;
    int find(TypeOfVer v) const {
        for (int i = 0; i < this->Vers; i++)
            if (ver[i] == v)
                return i;
        return -1;
    }
};


/* implementation */
template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::adjMatrixGraph(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag) {
    this->Vers = vSize;
    this->Edges = 0;
    noEdge = noEdgeFlag;

    ver = new TypeOfVer[vSize];
    for (int i = 0; i < vSize; i++)
        ver[i] = d[i];

    edge = new TypeOfEdge *[vSize];
    for (int i = 0; i < vSize; i++) {
        edge[i] = new TypeOfEdge[vSize];
        for (int j = 0; j < vSize; j++)
            edge[i][j] = noEdge;
        edge[i][i] = 0;
    }
}

template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::~adjMatrixGraph() {
    delete []ver;
    for (int i = 0; i < this->Vers; i++)
        delete []edge[i];
    delete []edge;
}

template <class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) {
    int u = find(x);
    int v = find(y);
    edge[u][v] = w;
    this->Edges++;
}

template <class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::remove(TypeOfVer x, TypeOfVer y) {
    int u = find(x);
    int v = find(y);
    edge[u][v] = noEdge;
    this->Edges--;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjMatrixGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x, TypeOfVer y) const {
    int u = find(x);
    int v = find(y);
    return (edge[u][v] != noEdge);
}


#endif // BASICGRAPH_ADJMATRIXGRAPH_H
