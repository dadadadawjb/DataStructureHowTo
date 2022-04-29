#include <iostream>
using namespace std;

class Node {
public:
    int coff, ex;
    Node *next;

    Node() {
        next = NULL;
    }
    Node(int n1, int n2, Node *p = NULL):coff(n1), ex(n2), next(p) {};
};

Node *add(Node *exp1, Node *exp2) {
    Node *res, *p, *tmp;

    res = p = new Node;
    exp1 = exp1->next;
    exp2 = exp2->next;

    while (exp1 != NULL && exp2 != NULL) {
        if (exp1->ex < exp2->ex) {
            p->next = new Node(exp1->coff, exp1->ex);
            exp1 = exp1->next;
        } else {
            if (exp1->ex > exp2->ex) {
                p->next = new Node(exp2->coff, exp2->ex);
                exp2 = exp2->next;
            } else {
                if (exp1->coff + exp2->coff != 0) {
                    p->next = new Node(exp1->coff + exp2->coff, exp1->ex);
                    exp1 = exp1->next;
                    exp2 = exp2->next;
                }
            }
        }
        p = p->next;
    }

    if (exp1 == NULL)
        tmp = exp2;
    else
        tmp = exp1;
    while (tmp != NULL) {
        p->next = new Node(tmp->coff, tmp->ex);
        tmp = tmp->next;
        p = p->next;
    }

    return res;
}