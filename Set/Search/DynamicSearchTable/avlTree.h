#ifndef DYNAMICSEARCHTABLE_AVLTREE_H
#define DYNAMICSEARCHTABLE_AVLTREE_H

#include "dynamicSearchTable.h"

/* declaration */
template <class KEY, class OTHER>
class AvlTree: public dynamicSearchTable<KEY, OTHER> {
private:
    struct AvlNode {
        SET<KEY, OTHER> data;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode(const SET<KEY, OTHER> &theData, AvlNode *lt, AvlNode *rt, int h = 1):data(theData), left(lt), right(rt), height(h) {};
    };

    AvlNode *root;

public:
    AvlTree();
    ~AvlTree();
    SET<KEY, OTHER> *find(const KEY &x) const;
    void insert(const SET<KEY, OTHER> &x);
    void remove(const KEY &x);

private:
    int height(AvlNode *t) const {
        return t==NULL ? 0 : t->height;
    }
    void insert(const SET<KEY, OTHER> &x, AvlNode *&t);
    bool remove(const KEY &x, AvlNode *&t);
    void LL(AvlNode *&t);
    void RR(AvlNode *&t);
    void LR(AvlNode *&t);
    void RL(AvlNode *&t);
    bool adjust(AvlNode *&t, int subTree);
    void makeEmpty(AvlNode *t);
    int max(int a, int b) {
        return (a>b) ? a : b;
    }
};


/* implementation */
template <class KEY, class OTHER>
AvlTree<KEY,OTHER>::AvlTree() {
    root = NULL;
}

template <class KEY, class OTHER>
AvlTree<KEY, OTHER>::~AvlTree() {
    makeEmpty(root);
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *AvlTree<KEY, OTHER>::find(const KEY &x) const {
    AvlNode *t = root;

    while (t != NULL && t->data.key != x) {
        if (x < t->data.key)
            t = t->left;
        else
            t = t->right;
    }

    if (t == NULL)
        return NULL;
    else
        return (SET<KEY, OTHER> *)t;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x, AvlNode *&t) {
    if (t == NULL)
        t = new AvlNode(x, NULL, NULL);
    else {
        if (x.key < t->data.key) {
            insert(x, t->left);
            if (height(t->left) - height(t->right) == 2) {
                if (x.key < t->left->data.key)
                    LL(t);
                else
                    LR(t);
            }
        } else {
            if (x.key > t->data.key) {
                insert(x, t->right);
                if (height(t->right) - height(t->left) == 2) {
                    if (x.key > t->right->data.key)
                        RR(t);
                    else
                        RL(t);
                }
            }
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}
template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x) {
    insert(x, root);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LL(AvlNode *&t) {
    AvlNode *newNode = t->left;
    t->left = newNode->right;
    newNode->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    newNode->height = max(height(newNode->left), height(t)) + 1;
    t = newNode;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RR(AvlNode *&t) {
    AvlNode *newNode = t->right;
    t->right = newNode->left;
    newNode->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    newNode->height = max(height(newNode->right), height(t)) + 1;
    t = newNode;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LR(AvlNode *&t) {
    RR(t->left);
    LL(t);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RL(AvlNode *&t) {
    LL(t->right);
    RR(t);
}

template <class KEY, class OTHER>
bool AvlTree<KEY, OTHER>::remove(const KEY &x, AvlNode *&t) {
    if (t == NULL)
        return true;
    if (x == t->data.key) {
        if (t->left == NULL || t->right == NULL) {
            AvlNode *oldNode = t;
            t = (t->left != NULL) ? t->left : t->right;
            delete oldNode;
            return false;
        } else {
            AvlNode *tmp = t->right;
            while (tmp->left != NULL)
                tmp = tmp->left;
            t->data = tmp->data;
            if (remove(tmp->data.key, t->right))
                return true;
            return adjust(t, 1);
        }
    } else {
        if (x < t->data.key) {
            if (remove(x, t->left))
                return true;
            return adjust(t, 0);
        } else {
            if (remove(x, t->right))
                return true;
            return adjust(t, 1);
        }
    }
}
template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::remove(const KEY &x) {
    remove(x, root);
}

template <class KEY, class OTHER>
bool AvlTree<KEY, OTHER>::adjust(AvlNode *&t, int subTree) {
    if (subTree) {
        if (height(t->left) - height(t->right) == 1)
            return true;
        if (height(t->right) == height(t->left)) {
            t->height--;
            return false;
        }
        if (height(t->left->right) > height(t->left->left)) {
            LR(t);
            return false;
        }
        LL(t);
        if (height(t->right) == height(t->left))
            return false;
        else
            return true;
    } else {
        if (height(t->right) - height(t->left) == 1)
            return true;
        if (height(t->left) == height(t->right)) {
            t->height--;
            return false;
        }
        if (height(t->right->left) > height(t->right->right)) {
            RL(t);
            return false;
        }
        RR(t);
        if (height(t->left) == height(t->right))
            return false;
        else
            return true;
    }
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::makeEmpty(AvlNode *t) {
    if (t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}


#endif // DYNAMICSEARCHTABLE_AVLTREE_H
