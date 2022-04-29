#ifndef DYNAMICSEARCHTABLE_BINARYSEARCHTREE_H
#define DYNAMICSEARCHTABLE_BINARYSEARCHTREE_H

#include "dynamicSearchTable.h"
#include "../../../Linear/Stack/linkStack.h"

/* declaration */
template <class KEY, class OTHER>
class BinarySearchTree: public dynamicSearchTable<KEY, OTHER> {
private:
    struct BinaryNode {
        SET<KEY, OTHER> data;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const SET<KEY, OTHER> &theData, BinaryNode *lt = NULL, BinaryNode *rt = NULL):data(theData), left(lt), right(rt) {};
    };

    BinaryNode *root;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    SET<KEY, OTHER> *find(const KEY &x) const;
    void insert(const SET<KEY, OTHER> &x);
    void remove(const KEY &x);
    SET<KEY, OTHER> *findNR(const KEY &x) const;    // no-reference added
    void insertNR(const SET<KEY, OTHER> &x);        // no-reference added and not finish
    void removeNR(const KEY &x);                    // no-reference added and not finish

private:
    SET<KEY, OTHER> *find(const KEY &x, BinaryNode *t) const;
    void insert(const SET<KEY, OTHER> &x, BinaryNode *&t);
    void remove(const KEY &x, BinaryNode *&t);
    void makeEmpty(BinaryNode *t);
};


/* implementation */
template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::BinarySearchTree() {
    root = NULL;
}

template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::~BinarySearchTree() {
    makeEmpty(root);
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::find(const KEY &x, BinaryNode *t) const {
    if (t == NULL)
        return (SET<KEY, OTHER> *)t;
    if (t->data.key == x)
        return (SET<KEY, OTHER> *)t;
    if (t->data.key < x)
        return find(x, t->right);
    else
        return find(x, t->left);
}
template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::find(const KEY &x) const {
    return find(x, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x, BinaryNode *&t) {
    if (t == NULL)
        t = new BinaryNode(x, NULL, NULL);
    else if (x.key < t->data.key)
        insert(x, t->left);
    else if (x.key > t->data.key)
        insert(x, t->right);
}
template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x) {
    insert(x, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY &x, BinaryNode *&t) {
    if (t == NULL)
        return;
    if (x < t->data.key)
        remove(x, t->left);
    else
        if (x > t->data.key)
            remove(x, t->right);
        else {
            if (t->left != NULL && t->right != NULL) {
                BinaryNode *tmp = t->right;
                while (tmp->left != NULL)
                    tmp = tmp->left;
                t->data = tmp->data;
                remove(t->data.key, t->right);
            } else {
                if (t->left == NULL && t->right == NULL)
                    delete t;
                else {
                    BinaryNode *oldNode = t;
                    t = (t->left != NULL) ? t->left : t->right;
                    delete oldNode;
                }
            }
        }
}
template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY &x) {
    remove(x, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::makeEmpty(BinaryNode *t) {
    if (t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::findNR(const KEY &x) const {
    linkStack<BinaryNode> binaryStack;
    BinaryNode *tmp;

    binaryStack.push(root);
    while (!binaryStack.isEmpty()) {
        tmp = binaryStack.pop();
        if (tmp == NULL) {
            return NULL;
        } else {
            if (x == tmp->data.key)
                return tmp;
            else {
                if (x < tmp->data.key)
                    binaryStack.push(tmp->left);
                else
                    binaryStack.push(tmp->right);
            }
        }
    }
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insertNR(const SET<KEY, OTHER> &x) {
    // not finish
    linkStack<BinaryNode> binaryStack;
    BinaryNode *tmp;

    binaryStack.push(root);
    while (!binaryStack.isEmpty()) {
        tmp = binaryStack.pop();
        if (tmp == NULL) {

        }
    }
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::removeNR(const KEY &x) {
    // not finish

}


#endif // DYNAMICSEARCHTABLE_BINARYSEARCHTREE_H
