#include "calc.h"

calc::node *calc::create(char *&s) {
    node *p, *root = NULL;
    Type returnType;
    int value;

    while (*s) {
        returnType = getToken(s, value);
        switch (returnType) {
            case DATA:
            case OPAREN:
                if (returnType == DATA)
                    p = new node(DATA, value);
                else
                    p = create(s);

                if (root != NULL)
                    if(root->rchild == NULL)
                        root->rchild = p;
                    else
                        root->rchild->rchild = p;
                break;
            case CPAREN:
            case EOL:
                return root;
            case ADD:
            case SUB:
                if (root == NULL)
                    root = new node(returnType, 0, p);
                else {
                    if (root->type == MULTI || root->type == DIV)
                        root = new node(returnType, 0, root);
                    else
                        root->rchild = new node(returnType, 0, root->rchild);
                }
        }
    }

    return root;
}

calc::Type calc::getToken(char *&s, int &value) {
    char type;

    while (*s == ' ')
        s++;

    if (*s >= '0' && *s <= '9') {
        value = 0;
        while (*s >= '0' && *s <= '9') {
            value = value * 10 + *s - '0';
            s++;
        }
        return DATA;
    }

    if (*s == '\0')
        return EOL;

    type = *s;
    s++;
    switch (type) {
        case '+': return ADD;
        case '-': return SUB;
        case '*': return MULTI;
        case '/': return DIV;
        case '(': return OPAREN;
        case ')': return CPAREN;
        default: return EOL;
    }
}

int calc::result(node *t) {
    int num1, num2;

    if (t->type == DATA)
        return t->data;

    num1 = result(t->lchild);
    num2 = result(t->rchild);
    switch (t->type) {
        case ADD: t->data = num1 + num2; break;
        case SUB: t->data = num1 - num2; break;
        case MULTI: t->data = num1 * num2; break;
        case DIV: t->data = num1 / num2;
    }
    return t->data;
}