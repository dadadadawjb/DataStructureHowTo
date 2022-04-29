#ifndef DYNAMICSEARCHTABLE_KETREE_H
#define DYNAMICSEARCHTABLE_KETREE_H

#include "dynamicSearchTable.h"

/* declaration */
template <class KEY, class OTHER>
class KDTree: public dynamicSearchTable<KEY, OTHER> {
private:
    int dimension;

    struct KDNode {
        SET<KEY, OTHER> item;
        KDNode *left, *right;

        KDNode():left(NULL), right(NULL) {};
        KDNode(const SET<KEY, OTHER> &_item, int _dimension):left(NULL), right(NULL) {
            for (int i = 0; i < _dimension; i++)
                item.key[i] = _item.key[i];
            item.other = _item.other;
        }
    };

    KDNode *Root;

public:
    KDTree(int dim = 2);
    ~KDTree();
    SET<KEY, OTHER> *find(const KEY &x) const;
    void insert(const SET<KEY, OTHER> &x);
    void remove(const KEY &x);
    int rangeSearch(const KEY *searchRange, KEY *treeRange) const;
    OTHER findMin(int dimCmp) const;
    OTHER findMax(int dimCmp) const;
    int dimensionValue() const {
        return dimension;
    }

private:
    SET<KEY, OTHER> *find(KDNode *root, const KEY &key, int dim) const;
    void insert(KDNode *&root, const SET<KEY, OTHER> &x, int dim);
    void remove(KDNode *&root, const KEY &key, int dim, KDNode *parent);
    int rangeSearch(KDNode *root, int dim, const KEY *searchRange, KEY *treeRange) const;
    KDNode *findMin(KDNode *root, int dimCmp, int dim) const;
    KDNode *findMax(KDNode *root, int dimCmp, int dim) const;
    bool keySame(const KEY &key1, const KEY &key2) const;
    void makeEmpty(KDNode *t);
};


/* implementation */
template <class KEY, class OTHER>
KDTree<KEY, OTHER>::KDTree(int dim) {
    dimension = dim;
    Root = NULL;
}

template <class KEY, class OTHER>
KDTree<KEY, OTHER>::~KDTree() {
    makeEmpty(Root);
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *KDTree<KEY, OTHER>::find(KDNode *root, const KEY &key, int dim) const {
    if (root == NULL)
        return NULL;
    if (keySame(key, root->item.key))
        return (SET<KEY, OTHER> *)root;
    else if (key[dim] < root->item.key[dim])
        return find(root->left, key, (dim+1) % 2);
    else
        return find(root->right, key, (dim+1) % 2);
}
template <class KEY, class OTHER>
SET<KEY, OTHER> *KDTree<KEY, OTHER>::find(const KEY &key) const {
    return find(Root, key, 0);
}

template <class KEY, class OTHER>
void KDTree<KEY, OTHER>::insert(KDNode *&root, const SET<KEY, OTHER> &x, int dim) {
    if (root == NULL) {
        root = new KDNode(x, dimension);
        return;
    }
    if (keySame(x.key, root->item.key))
        return;
    if (x.key[dim] < root->item.key[dim])
        insert(root->left, x, (dim+1) % 2);
    else
        insert(root->right, x, (dim+1) % 2);
}
template <class KEY, class OTHER>
void KDTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x) {
    insert(Root, x, 0);
}

template <class KEY, class OTHER>
void KDTree<KEY, OTHER>::remove(KDNode *&root, const KEY &key, int dim, KDNode *parent) {
    if (root == NULL)
        return;
    if (keySame(key, root->item.key)) {
        if (root->left == NULL && root->right == NULL) {
            if (parent == NULL) {
                delete root;
                return;
            }
            if (parent->left == root)
                parent->left = NULL;
            else if (parent->right == root)
                parent->right = NULL;
            delete root;
        } else {
            KDNode *replace = (root->right != NULL) ? findMin(root->right, dim, (dim+1) % 2) : findMax(root->left, dim, (dim+1) % 2);
            root->item.key[0] = replace->item.key[0];
            root->item.key[1] = replace->item.key[1];
            root->item.other = replace->item.other;
            remove((root->right != NULL) ? root->right : root->left, replace->item.key, (dim+1) % 2, root);
        }
    } else if (key[dim] < root->item.key[dim])
        remove(root->left, key, (dim+1) % 2, root);
    else
        remove(root->right, key, (dim+1) % 2, root);
}
template <class KEY, class OTHER>
void KDTree<KEY, OTHER>::remove(const KEY &key) {
    remove(Root, key, 0, NULL);
}

template <class KEY, class OTHER>
int KDTree<KEY, OTHER>::rangeSearch(KDNode *root, int dim, const KEY *searchRange, KEY *treeRange) const {
    if (root == NULL)
        return 0;
    int count = 1;
    for (int i = 0; i < dimension; i++) {
        if (root->item.key[i] < searchRange[0][i])
            count = 0;
        if (root->item.key[i] > searchRange[1][i])
            count = 0;
        
        if (root->item.key[i] < treeRange[0][i])
            treeRange[0][i] = root->item.key[i];
        if (root->item.key[i] > treeRange[i][1])
            treeRange[1][i] = root->item.key[i];
    }
    return count + rangeSearch(root->left, (dim+1) % 2, searchRange, treeRange) + rangeSearch(root->right, (dim+1) % 2, searchRange, treeRange);
}
template <class KEY, class OTHER>
int KDTree<KEY, OTHER>::rangeSearch(const KEY *searchRange, KEY *treeRange) const {
    return rangeSearch(Root, 0, searchRange, treeRange);
}

template <class KEY, class OTHER>
typename KDTree<KEY, OTHER>::KDNode *KDTree<KEY, OTHER>::findMin(KDNode *root, int dimCmp, int dim) const {
    if (root == NULL)
        return NULL;
    KDNode *minNode = findMin(root->left, dimCmp, (dim+1) % 2);                   // actually the left min node
    if (dimCmp != dim) {
        KDNode *rightMinNode = findMin(root->right, dimCmp, (dim+1) % 2);
        if (minNode == NULL && rightMinNode != NULL)
            minNode = rightMinNode;
        else if (rightMinNode == NULL && minNode != NULL)
            minNode = minNode;
        else if (minNode == NULL && rightMinNode == NULL)
            minNode = NULL;
        else
            minNode = (minNode->item.key[dimCmp] < rightMinNode->item.key[dimCmp]) ? minNode : rightMinNode;
    }
    if (minNode == NULL)
        return root;
    else
        return (minNode->item.key[dimCmp] < root->item.key[dimCmp]) ? minNode : root;
}
template <class KEY, class OTHER>
OTHER KDTree<KEY, OTHER>::findMin(int dimCmp) const {
    KDNode *result = findMin(Root, dimCmp, 0);
    if (result == NULL)
        return NULL;
    else
        return result->item.other;
}

template <class KEY, class OTHER>
typename KDTree<KEY, OTHER>::KDNode *KDTree<KEY, OTHER>::findMax(KDNode *root, int dimCmp, int dim) const {
    if (root == NULL)
        return NULL;
    KDNode *maxNode = findMax(root->right, dimCmp, (dim+1) % 2);                  // actually the right max node
    if (dimCmp != dim) {
        KDNode *leftMaxNode = findMax(root->left, dimCmp, (dim+1) % 2);
        if (maxNode == NULL && leftMaxNode != NULL)
            maxNode = leftMaxNode;
        else if (leftMaxNode == NULL && maxNode != NULL)
            maxNode = maxNode;
        else if (maxNode == NULL && leftMaxNode == NULL)
            maxNode = NULL;
        else
            maxNode = (maxNode->item.key[dimCmp] > leftMaxNode->item.key[dimCmp]) ? maxNode : leftMaxNode;
    }
    if (maxNode == NULL)
        return root;
    else
        return (maxNode->item.key[dimCmp] > root->item.key[dimCmp]) ? maxNode : root;
}
template <class KEY, class OTHER>
OTHER KDTree<KEY, OTHER>::findMax(int dimCmp) const {
    KDNode *result = findMax(Root, dimCmp, 0);
    if (result == NULL)
        return NULL;
    else
        return result->item.other;
}

template <class KEY, class OTHER>
bool KDTree<KEY, OTHER>::keySame(const KEY &key1, const KEY &key2) const {
    for (int i = 0; i < dimension; i++)
        if (key1[i] != key2[i])
            return false;
    return true;
}

template <class KEY, class OTHER>
void KDTree<KEY, OTHER>::makeEmpty(KDNode *t) {
    if (t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}


#endif // DYNAMICSEARCHTABLE_KETREE_H