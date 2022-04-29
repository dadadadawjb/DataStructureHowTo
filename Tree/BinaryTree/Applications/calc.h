#ifndef BTREE_CALC_H
#define BTREE_CALC_H

#include <iostream>
using namespace std;

class calc {
    enum Type{DATA, ADD, SUB, MULTI, DIV, OPAREN, CPAREN, EOL};
    struct node {
        Type type;
        int data;
        node *lchild;
        node *rchild;

        node(Type t, int d = 0, node *lc = NULL, node *rc = NULL) {
            type = t;
            data = d;
            lchild = lc;
            rchild = rc;
        }
    };

    node *root;

    node *create(char *&s);
    Type getToken(char *&s, int &value);
    int result(node *t);

public:
    calc(char *s) {
        root = create(s);
    }
    int result() {
        if (root == NULL)
            return 0;
        return result(root);
    }
};


#endif // BTREE_CALC_H
