#ifndef BASICGRAPH_ADJLISTGRAPH_H
#define BASICGRAPH_ADJLISTGRAPH_H

#include "graph.h"
#include "../../Linear/Queue/linkQueue.h"

/* declaration */
template <class TypeOfVer, class TypeOfEdge>
class adjListGraph: public graph<TypeOfVer, TypeOfEdge> {
public:
    adjListGraph(int vSize, const TypeOfVer d[]);
    ~adjListGraph();
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
    void remove(TypeOfVer x, TypeOfVer y);
    bool exist(TypeOfVer x, TypeOfVer y) const;
    void dfs() const;
    void bfs() const;
    void EulerCircuit(TypeOfVer start);
    void topSort() const;
    void criticalPath() const;

private:
    struct edgeNode {
        int end;
        TypeOfEdge weight;
        edgeNode *next;

        edgeNode(int e, TypeOfEdge w, edgeNode *n = NULL) {
            end = e;
            weight = w;
            next = n;
        }
    };

    struct verNode {
        TypeOfVer ver;
        edgeNode *head;

        verNode(edgeNode *h = NULL) {
            head = h;
        }
    };

    struct EulerNode {
        int NodeNum;
        EulerNode *next;

        EulerNode(int ver) {
            NodeNum = ver;
            next = NULL;
        }
    };

    verNode *verList;

    void dfs(int start, bool visited[]) const;

    int find(TypeOfVer v) const {
        for (int i = 0; i < this->Vers; i++)
            if (verList[i].ver == v)
                return i;
        return -1;
    }

    void EulerCircuit(int start, EulerNode *&beg, EulerNode *&end);
    verNode *clone() const;
};


/* implementation */
template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vSize, const TypeOfVer d[]) {
    this->Vers = vSize;
    this->Edges = 0;

    verList = new verNode[vSize];
    for (int i = 0; i < vSize; i++)
        verList[i].ver = d[i];
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph() {
    edgeNode *p;

    for (int i = 0; i < this->Vers; i++) {
        while ((p = verList[i].head) != NULL) {
            verList[i].head = p->next;
            delete p;
        }
    }
    delete []verList;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) {
    int u = find(x);
    int v = find(y);
    verList[u].head = new edgeNode(v, w, verList[u].head);
    this->Edges++;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::remove(TypeOfVer x, TypeOfVer y) {
    int u = find(x);
    int v = find(y);
    edgeNode *p = verList[u].head;

    if (p == NULL)
        return;

    if (p->end == v) {
        verList[u].head = p->next;
        delete p;
        this->Edges--;
        return;
    }

    while (p->next != NULL && p->next->end != v)
        p = p->next;
    if (p->next != NULL) {
        edgeNode *q = p->next;
        p->next = q->next;
        delete q;
        this->Edges--;
    }
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x, TypeOfVer y) const {
    int u = find(x);
    int v = find(y);
    edgeNode *p = verList[u].head;

    while (p != NULL && p->end != v)
        p = p->next;
    if (p == NULL)
        return false;
    else
        return true;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const {
    bool *visited = new bool[this->Vers];

    for (int i = 0; i < this->Vers; i++)
        visited[i] = false;

    // cout << "the dfs sequence is:" << endl;

    for (int i = 0; i < this->Vers; i++) {
        if (visited[i] == true)
            continue;
        dfs(i, visited);
        cout << endl;
    }
}
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool *visited) const {
    edgeNode *p = verList[start].head;

    cout << verList[start].ver << '\t';
    visited[start] = true;

    while (p != NULL) {
        if (visited[p->end] == false)
            dfs(p->end, visited);
        p = p->next;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs() const {
    bool *visited = new bool[this->Vers];
    linkQueue<int> q;

    for (int i = 0; i < this->Vers; i++)
        visited[i] = false;

    // cout << "the bfs sequence is:" << endl;

    for (int i = 0; i < this->Vers; i++) {
        if (visited[i] == true)
            continue;

        q.enQueue(i);
        while (!q.isEmpty()) {
            int currentNode = q.deQueue();
            if (visited[currentNode] == true)
                continue;
            cout << verList[currentNode].ver << '\t';
            visited[currentNode] = true;

            edgeNode *p = verList[currentNode].head;
            while (p != NULL) {
                if (visited[p->end] == false)
                    q.enQueue(p->end);
                p = p->next;
            }
        }
        cout << endl;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::EulerCircuit(TypeOfVer start) {
    // only support undirected graph now
    // now bug exists
    if (this->Edges == 0) {
        cout << "no such Euler Circuit" << endl;
        return;
    }
    for(int i = 0; i < this->Vers; i++) {
        int NumOfDegree = 0;
        edgeNode *r = verList[i].head;
        while (r != NULL) {
            NumOfDegree++;
            r = r->next;
        }
        if (NumOfDegree % 2) {
            cout << "no such Euler Circuit" << endl;
            return;
        }
    }

    int i = find(start);
    EulerNode *beg, *end;
    EulerNode *p, *q;
    EulerNode *tb, *te;
    verNode *tmp = clone();

    EulerCircuit(i, beg, end);
    while (true) {
        p = beg;
        while (p->next != NULL) {
            if (verList[p->next->NodeNum].head != NULL)
                break;
            else
                p = p->next;
        }
        if (p->next == NULL)
            break;
        q = p->next;
        EulerCircuit(q->NodeNum, tb, te);
        te->next = q->next;
        p->next = tb;
        delete q;
    }

    delete []verList;
    verList = tmp;

    // cout << "the Euler Circuit is:" << endl;
    while (beg != NULL) {
        cout << verList[beg->NodeNum].ver << '\t';
        p = beg;
        beg = beg->next;
        delete p;
    }
    cout << endl;
}
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::EulerCircuit(int start, EulerNode *&beg, EulerNode *&end) {
    int nextNode;

    beg = end = new EulerNode(start);
    while (verList[start].head != NULL) {
        nextNode = verList[start].head->end;
        remove(start, nextNode);
        remove(nextNode, start);
        start = nextNode;
        end->next = new EulerNode(start);
        end = end->next;
    }
}

template <class TypeOfVer, class TypeOfEdge>
typename adjListGraph<TypeOfVer, TypeOfEdge>::verNode *adjListGraph<TypeOfVer, TypeOfEdge>::clone() const {
    verNode *tmp = new verNode[this->Vers];
    edgeNode *p;

    for (int i = 0; i < this->Vers; i++) {
        tmp[i].ver = verList[i].ver;
        p = verList[i].head;
        while (p != NULL) {
            tmp[i].head = new edgeNode(p->end, p->weight, tmp[i].head);
            p = p->next;
        }
    }

    return tmp;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::topSort() const {
    linkQueue<int> q;
    edgeNode *p;
    int current;
    int *inDegree = new int[this->Vers];

    for (int i = 0; i < this->Vers; i++)
        inDegree[i] = 0;
    for (int i = 0; i < this->Vers; i++) {
        for (p = verList[i].head; p != NULL; p = p->next)
            inDegree[p->end]++;
    }

    for (int i = 0; i < this->Vers; i++) {
        if (inDegree[i] == 0)
            q.enQueue(i);
    }

    // cout << "topological sort is:" << endl;
    while (!q.isEmpty()) {
        current = q.deQueue();
        cout << verList[current].ver << '\t';
        for (p = verList[current].head; p != NULL; p = p->next) {
            if (--inDegree[p->end] == 0)
                q.enQueue(p->end);
        }
    }
    cout << endl;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::criticalPath() const {
    TypeOfEdge *ee = new TypeOfEdge[this->Vers];
    TypeOfEdge *le = new TypeOfEdge[this->Vers];
    int *top = new int[this->Vers];
    int *inDegree = new int[this->Vers];
    linkQueue<int> q;
    edgeNode *p;

    for (int i = 0; i < this->Vers; i++)
        inDegree[i] = 0;
    for (int i = 0; i < this->Vers; i++) {
        for (p = verList[i].head; p != NULL; p = p->next)
            inDegree[p->end]++;
    }

    for (int i = 0; i < this->Vers; i++) {
        if (inDegree[i] == 0)
            q.enQueue(i);
    }

    int i = 0;
    while (!q.isEmpty()) {
        top[i] = q.deQueue();
        for (p = verList[top[i]].head; p != NULL; p = p->next) {
            if (--inDegree[p->end] == 0)
                q.enQueue(p->end);
        }
        i++;
    }

    for (int j = 0; j < this->Vers; j++)
        ee[j] = 0;
    for (int j = 0; j < this->Vers; j++) {
        for (p = verList[top[j]].head; p != NULL; p = p->next) {
            if (ee[p->end] < ee[top[j]] + p->weight)
                ee[p->end] = ee[top[j]] + p->weight;
        }
    }

    for (int j = 0; j < this->Vers; j++)
        le[j] = ee[top[this->Vers - 1]];
    for (int j = this->Vers - 1; j >= 0; j--) {
        for (p = verList[top[j]].head; p != NULL; p = p->next) {
            if (le[p->end] - p->weight < le[top[j]])
                le[top[j]] = le[p->end] - p->weight;
        }
    }

    // cout << "the critical path is:" << endl;
    for (int j = 0; j < this->Vers; j++) {
        if (le[top[j]] == ee[top[j]])
            cout << "(" << verList[top[j]].ver << ", " << ee[top[j]] << ")";
    }
    cout << endl;
}


#endif // BASICGRAPH_ADJLISTGRAPH_H
