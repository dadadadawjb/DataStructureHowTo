#ifndef BINARY_BINARYTREE_H
#define BINARY_BINARYTREE_H

#include "bTree.h"
#include "../../Linear/Queue/linkQueue.h"
#include "../../Linear/Stack/linkStack.h"

/* declaration */
template <class T>
class binaryTree: public bTree<T> {
    template <class U>
    friend void printTree(const binaryTree<U> &t, U flag);

private:
    struct Node {
        Node *left, *right;
        T data;

        Node():left(NULL), right(NULL) {};
        Node(T item, Node *L = NULL, Node *R = NULL):data(item), left(L), right(R) {};
        ~Node() {};
    };

    Node *Root;

    struct StNode {
        Node *node;
        int TimesPop;

        StNode(Node *N = NULL):node(N), TimesPop(0) {};
    };

public:
    binaryTree():Root(NULL) {};
    binaryTree(T x) {
        Root = new Node(x);
    }
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T root(T flag) const;
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;
    void preOrderNR() const;
    void midOrder() const;
    void midOrderNR() const;
    void postOrder() const;
    void postOrderNR() const;
    void levelOrder() const;
    void createTree(T flag);
    T parent(T x, T flag) const {
        return flag;
    }
    int size() const;
    int height() const;

private:
    Node *find(T x, Node *t) const;
    void clear(Node *&t);
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;
    int size(Node *t) const;
    int height(Node *t) const;
};


/* implementation */
template <class T>
binaryTree<T>::~binaryTree() {
    clear(Root);
}

template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t) {
    if (t == NULL)
        return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}
template <class T>
void binaryTree<T>::clear() {
    clear(Root);
}

template <class T>
bool binaryTree<T>::isEmpty() const {
    return Root == NULL;
}

template <class T>
T binaryTree<T>::root(T flag) const {
    if (Root == NULL)
        return flag;
    else
        return Root->data;
}

template <class T>
void binaryTree<T>::preOrder(Node *t) const {
    if (t == NULL)
        return;
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}
template <class T>
void binaryTree<T>::preOrder() const {
    preOrder(Root);
    cout << endl;
}

template <class T>
void binaryTree<T>::midOrder(Node *t) const {
    if (t == NULL)
        return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}
template <class T>
void binaryTree<T>::midOrder() const {
    midOrder(Root);
    cout << endl;
}

template <class T>
void binaryTree<T>::postOrder(Node *t) const {
    if (t == NULL)
        return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
}
template <class T>
void binaryTree<T>::postOrder() const {
    postOrder(Root);
    cout << endl;
}

template <class T>
void binaryTree<T>::levelOrder() const {
    linkQueue<Node *> que;
    Node *tmp;
    que.enQueue(Root);
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        cout << tmp->data << ' ';
        if (tmp->left)
            que.enQueue(tmp->left);
        if (tmp->right)
            que.enQueue(tmp->right);
    }
    cout << endl;
}

template <class T>
typename binaryTree<T>::Node* binaryTree<T>::find(T x, Node *t) const {
    Node *tmp;
    if (t == NULL)
        return NULL;
    if (t->data == x)
        return t;
    if ((tmp = find(x, t->left)))
        return tmp;
    else
        return find(x, t->right);
}

template <class T>
T binaryTree<T>::lchild(T x, T flag) const {
    Node *tmp = find(x, Root);
    if (tmp == NULL || tmp->left == NULL)
        return flag;
    return tmp->left->data;
}

template <class T>
T binaryTree<T>::rchild(T x, T flag) const {
    Node *tmp = find(x, Root);
    if (tmp == NULL || tmp->right == NULL)
        return flag;
    return tmp->right->data;
}

template <class T>
void binaryTree<T>::delLeft(T x) {
    Node *tmp = find(x, Root);
    if (tmp == NULL)
        return;
    clear(tmp->left);
}

template <class T>
void binaryTree<T>::delRight(T x) {
    Node *tmp = find(x, Root);
    if (tmp == NULL)
        return;
    clear(tmp->right);
}

template <class T>
void binaryTree<T>::createTree(T flag) {
    linkQueue<Node *> que;
    Node *tmp;
    T x, ldata, rdata;

    cout << "input root: ";
    cin >> x;
    Root = new Node(x);
    que.enQueue(Root);

    while (!que.isEmpty()) {
        tmp = que.deQueue();
        cout << "input " << tmp->data << "'s two children(" << flag << " means none):";
        cin >> ldata >> rdata;
        if (ldata != flag)
            que.enQueue(tmp->left = new Node(ldata));
        if (rdata != flag)
            que.enQueue(tmp->right = new Node(rdata));
    }

    cout << "create completed!" << endl;
}


template <class T>
void printTree(const binaryTree<T> &t, T flag) {
    linkQueue<T> que;
    que.enQueue(t.Root->data);
    while(!que.isEmpty()) {
        T p, l, r;
        p = que.deQueue();
        l = t.lchild(p, flag);
        r = t.rchild(p, flag);
        cout << p << " " << l << " " << r << endl;
        if (l != flag)
            que.enQueue(l);
        if (r != flag)
            que.enQueue(r);
    }
}

template <class T>
int binaryTree<T>::size(Node *t) const {
    if (t == NULL)
        return 0;
    return 1 + size(t->left) + size(t->right);
}
template <class T>
int binaryTree<T>::size() const {
    return size(Root);
}

template <class T>
int binaryTree<T>::height(Node *t) const {
    if (t == NULL)
        return 0;
    else {
        int lh = height(t->left);
        int rh = height(t->right);
        return 1 + (lh>rh ? lh : rh);
    }
}
template <class T>
int binaryTree<T>::height() const {
    return height(Root);
}

template <class T>
void binaryTree<T>::preOrderNR() const {
    linkStack<Node *> s;
    Node *current;

    s.push(Root);
    while (!s.isEmpty()) {
        current = s.pop();
        cout << current->data << ' ';
        if (current->right != NULL)
            s.push(current->right);
        if (current->left != NULL)
            s.push(current->left);
    }
    cout << endl;
}

template <class T>
void binaryTree<T>::midOrderNR() const {
    linkStack<StNode> s;
    StNode current(Root);

    s.push(current);
    while (!s.isEmpty()) {
        current = s.pop();
        if (++current.TimesPop == 2) {
            cout << current.node->data << ' ';
            if (current.node->right != NULL)
                s.push(StNode(current.node->right));
        } else {
            s.push(current);
            if (current.node->left != NULL)
                s.push(StNode(current.node->left));
        }
    }
    cout << endl;
}

template <class T>
void binaryTree<T>::postOrderNR() const {
    linkStack<binaryTree<char>::StNode> s;
    StNode current(Root);

    s.push(current);
    while (!s.isEmpty()) {
        current = s.pop();
        if (++current.TimesPop == 3) {
            cout << current.node->data << ' ';
            continue;
        }
        s.push(current);
        if (current.TimesPop == 1) {
            if (current.node->left != NULL)
                s.push(StNode(current.node->left));
        } else {
            if(current.node->right != NULL)
                s.push(StNode(current.node->right));
        }
    }
    cout << endl;
}


#endif // BINARY_BINARYTREE_H
