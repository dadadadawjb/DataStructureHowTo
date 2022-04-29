#ifndef DYNAMICSEARCHTABLE_TRIETREE_H
#define DYNAMICSEARCHTABLE_TRIETREE_H

#include "dynamicSearchTable.h"

/* declaration */
class TrieTree {
private:
    struct TrieNode {
        char prefix;
        char *prefix_leaf;
        TrieNode *child;
        TrieNode *sibling;
        TrieNode *father;
        // if prefix_leaf is not NULL, then its child is NULL; if prefix_leaf is NULL, then its child is not NULL

        TrieNode():prefix_leaf(NULL), child(NULL), sibling(NULL), father(NULL) {};
        TrieNode(char p, TrieNode *f = NULL, TrieNode *c = NULL, TrieNode *s = NULL):prefix(p), prefix_leaf(NULL), father(f), child(c), sibling(s) {};
        TrieNode(const char *p, TrieNode *f = NULL, TrieNode *c = NULL, TrieNode *s = NULL):father(f), child(c), sibling(s) {
            int size;
            for (size = 0; p[size] != '\0'; size++);

            prefix_leaf = new char[size+1];
            for (int i = 0; i < size; i++)
                prefix_leaf[i] = p[i];
            prefix_leaf[size] = '\0';
        }
    };

    TrieNode *root;
    
public:
    TrieTree();
    ~TrieTree();
    bool find(const char *word) const;
    void insert(const char *word);
    void remove(const char *word);
    bool findPrefix(const char *prefix) const {
        TrieNode *pos;
        int offset;
        return findPrefix(prefix, pos, offset);
    }

private:
    void makeEmpty(TrieNode *t);
    bool findPrefix(const char *prefix, TrieNode *&pos, int &offset) const;
    void deletePos(TrieNode *pos);
};


/* implementation */
TrieTree::TrieTree() {
    root = new TrieNode();
}

TrieTree::~TrieTree() {
    makeEmpty(root);
}

void TrieTree::makeEmpty(TrieNode *t) {
    if (t == NULL)
        return;
    makeEmpty(t->child);
    makeEmpty(t->sibling);
    delete t->prefix_leaf;
    delete t;
}

bool TrieTree::findPrefix(const char *prefix, TrieNode *&pos, int &offset) const {
    int size;
    for (size = 0; prefix[size] != '\0'; size++);

    pos = root;
    for (int i = 0; i < size; i++) {
        if (pos->child != NULL) {
            pos = pos->child;
            while (true) {
                if (pos->prefix_leaf == NULL) {
                    if (pos->prefix != prefix[i]) {
                        if (pos->sibling != NULL)
                            pos = pos->sibling;
                        else {
                            // pos return the last one this level since not found this char, offset as the index of the char
                            offset = i;
                            return false;
                        }
                    } else {
                        break;              // not leaf, still have child
                    }
                } else {
                    if (pos->prefix_leaf[0] != prefix[i]) {
                        if (pos->sibling != NULL)
                            pos = pos->sibling;
                        else {
                            // pos return the last one this level since not found this char, offset as the index of the char
                            offset = i;
                            return false;
                        }
                    } else {
                        int j = 0;
                        while (pos->prefix_leaf[j] != '\0') {
                            if (i + j < size) {
                                if (pos->prefix_leaf[j] != prefix[i + j]) {
                                    // pos return this leaf since prefix is not equal to this leaf, offset as the minus index of the char
                                    offset = (-1) * (i+1);      // trick here, in order to leave 0 to the `same` case
                                    return false;
                                }
                            } else {
                                // pos return this leaf since prefix is contained in this leaf
                                offset = i + 1;                 // trick here, in order to leave 0 to the `same` case
                                return true;
                            }
                            j++;
                        }
                        if (i + j == size) {
                            // pos return this leaf since the prefix is the same as the leaf
                            offset = 0;
                            return true;
                        } else {
                            // pos return this leaf since prefix is longer, offset as the minus index of the char
                            offset = (-1) * (i+1);              // trick here, in order to leave 0 to the normal case
                            return false;
                        }
                    }
                }
            }
        } else {
            // pos return root, offset invalid
            return false;
        }
    }
    // pos return the mid node, only the `break` will reach here, offset as the minus size
    offset = (-1) * size;
    return true;
}

bool TrieTree::find(const char *word) const {
    TrieNode *pos;
    int offset;
    bool flag = findPrefix(word, pos, offset);

    if (flag == false)
        return false;
    else {
        if (pos->prefix_leaf != NULL) {
            // check this leaf whether is actually contained but not the same
            if (offset == 0)
                return true;
            else
                return false;
        } else {
            // check child
            pos = pos->child;
            while (pos != NULL) {
                if (pos->prefix_leaf == NULL) {
                    pos = pos->sibling;
                } else {
                    if (pos->prefix_leaf[0] == '$')
                        return true;
                    else
                        pos = pos->sibling;
                }
            }
            return false;
        }
    }
}

void TrieTree::insert(const char *word) {
    TrieNode *pos;
    int offset;
    bool flag = findPrefix(word, pos, offset);

    if (flag == false) {
        if (pos == root) {
            // insert at root, special case
            pos->child = new TrieNode(word, pos);
            return;
        }
        if (offset < 0) {
            // word is longer or not equal
            offset = (-1) * offset - 1;
            pos->prefix = word[offset];
            int j = 1;
            TrieNode *p = pos;
            while (word[offset+j] == pos->prefix_leaf[j]) {
                p->child = new TrieNode(word[offset+j], p);
                p = p->child;
                j++;
            }
            if (pos->prefix_leaf[j] == '\0') {
                // word is longer
                p->child = new TrieNode("$", p);
                p->child->sibling = new TrieNode(&word[offset+j], p);
            } else {
                // word is not equal
                p->child = new TrieNode(&word[offset+j], p);
                int size;
                for (size = 0; pos->prefix_leaf[j+size] != '\0'; size++);
                char *leftWord = new char[size+1];
                for (int k = 0; k < size; k++) {
                    leftWord[k] = pos->prefix_leaf[j+k];
                }
                leftWord[size] = '\0';
                p->child->sibling = new TrieNode(leftWord, p);
            }
            delete pos->prefix_leaf;
            pos->prefix_leaf = NULL;
        } else {
            // insert as sibling
            pos->sibling = new TrieNode(&word[offset], pos->father);
        }
    } else {
        if (offset == 0) {
            // the same, no need to insert
            return;
        } else if (offset > 0) {
            // word is contain in some leaf
            offset -= 1;
            pos->prefix = word[offset];
            int j = 1;
            TrieNode *p = pos;
            while (word[offset+j] == pos->prefix_leaf[j]) {
                p->child = new TrieNode(word[offset+j], p);
                p = p->child;
                j++;
            }
            if (word[offset+j] == '\0') {
                p->child = new TrieNode("$", p);
                int size;
                for (size = 0; pos->prefix_leaf[j+size] != '\0'; size++);
                char *leftWord = new char[size+1];
                for (int k = 0; k < size; k++) {
                    leftWord[k] = pos->prefix_leaf[j+k];
                }
                leftWord[size] = '\0';
                p->child->sibling = new TrieNode(leftWord, p);
            }
            delete pos->prefix_leaf;
            pos->prefix_leaf = NULL;
        } else {
            // insert in the mid
            offset = (-1) * offset;
            if (pos->child == NULL) {
                pos->child = new TrieNode("$", pos);
            } else {
                TrieNode *p = pos->child;
                while (p->sibling != NULL) {
                    p = p->sibling;
                }
                p->sibling = new TrieNode("$", p->father);
            }
        }
    }
}

void TrieTree::remove(const char *word) {
    TrieNode *pos;
    int offset;
    bool flag = findPrefix(word, pos, offset);

    if (flag == false) {
        // no such word
        return;
    } else {
        if (offset == 0) {
            // find it
            deletePos(pos);
        } else if (offset > 0 ){
            // no such word
            return;
        } else {
            // there exists `$` and we also need to remove it
            TrieNode *tmp = pos->child;
            while (tmp != NULL) {
                if (tmp->prefix_leaf[0] == '$')
                    pos = tmp;
                tmp = tmp->sibling;
            }
            deletePos(pos);
        }
    }
}

void TrieTree::deletePos(TrieNode *pos) {
    TrieNode *myFather;
    TrieNode *p;
    TrieNode *pos_left;
    int childNum;
    bool first_stop = false;
    bool second_stop = false;
    do {
        myFather = pos->father;
        p = myFather->child;
        pos_left = NULL;
        childNum = 0;
        while (p != NULL) {
            childNum++;
            if (p->sibling == pos)
                pos_left = p;
            p = p->sibling;
        }

        if (childNum-1 > 1) {
            // no longer 1
            if (second_stop == true)
                break;
            // directly delete it
            if (pos_left != NULL) {
                pos_left->sibling = pos->sibling;
                delete pos->prefix_leaf;
                pos->prefix_leaf = NULL;
            } else {
                myFather->child = pos->sibling;
                delete pos->prefix_leaf;
                pos->prefix_leaf = NULL;
            }
            first_stop = true;
        } else if (childNum == 2) {
            // no longer 1
            if (second_stop == true)
                break;
            // recursive
            if (pos_left != NULL) {
                if (pos_left->prefix_leaf == NULL) {
                    // the left is not a leaf
                    delete pos->prefix_leaf;
                    pos->prefix_leaf = NULL;
                    pos_left->sibling = NULL;
                    first_stop = true;
                } else {
                    // the left is also a leaf
                    if (pos_left->prefix_leaf[0] == '$') {
                        delete pos->prefix_leaf;
                        pos->prefix_leaf = NULL;
                        myFather->prefix_leaf = new char[2];
                        myFather->prefix_leaf[0] = myFather->prefix;
                        myFather->prefix_leaf[1] = '\0';
                        delete pos_left->prefix_leaf;
                        pos_left->prefix_leaf = NULL;
                        myFather->child = NULL;
                        pos = myFather;
                    } else {
                        int size;
                        for (size = 0; pos_left->prefix_leaf[size] != '\0'; size++);
                        myFather->prefix_leaf = new char[size+2];
                        myFather->prefix_leaf[0] = myFather->prefix;
                        for (int i = 1; i < size+1; i++)
                            myFather->prefix_leaf[i] = pos_left->prefix_leaf[i-1];
                        myFather->prefix_leaf[size+1] = '\0';
                        delete pos->prefix_leaf;
                        pos->prefix_leaf = NULL;
                        delete pos_left->prefix_leaf;
                        pos_left->prefix_leaf = NULL;
                        myFather->child = NULL;
                        pos = myFather;
                    }
                }
            } else {
                if (pos->sibling->prefix_leaf == NULL) {
                    // the right is not a leaf
                    delete pos->prefix_leaf;
                    pos->prefix_leaf = NULL;
                    myFather->child = pos->sibling;
                    first_stop = true;
                } else {
                    // the right is also a leaf
                    if (pos->sibling->prefix_leaf[0] == '$') {
                        delete pos->prefix_leaf;
                        pos->prefix_leaf = NULL;
                        myFather->prefix_leaf = new char[2];
                        myFather->prefix_leaf[0] = myFather->prefix;
                        myFather->prefix_leaf[1] = '\0';
                        delete pos->sibling->prefix_leaf;
                        pos->sibling->prefix_leaf = NULL;
                        myFather->child = NULL;
                        pos = myFather;
                    } else {
                        int size;
                        for (size = 0; pos->sibling->prefix_leaf[size] != '\0'; size++);
                        myFather->prefix_leaf = new char[size+2];
                        myFather->prefix_leaf[0] = myFather->prefix;
                        for (int i = 1; i < size+1; i++)
                            myFather->prefix_leaf[i] = pos->sibling->prefix_leaf[i-1];
                        myFather->prefix_leaf[size+1] = '\0';
                        delete pos->sibling->prefix_leaf;
                        pos->sibling->prefix_leaf = NULL;
                        delete pos->prefix_leaf;
                        pos->prefix_leaf = NULL;
                        myFather->child = NULL;
                        pos = myFather;
                    }
                }
            }
        } else if (childNum == 1) {
            // keep remove up
            if (myFather == root) {
                delete pos->prefix_leaf;
                pos->prefix_leaf = NULL;
                myFather->child = NULL;
                first_stop = true;
            } else {
                int size;
                for (size = 0; pos->prefix_leaf[size] != '\0'; size++);
                myFather->prefix_leaf = new char[size+2];
                myFather->prefix_leaf[0] = myFather->prefix;
                for (int i = 1; i < size+1; i++)
                    myFather->prefix_leaf[i] = pos->prefix_leaf[i-1];
                myFather->prefix_leaf[size+1] = '\0';
                delete pos->prefix_leaf;
                pos->prefix_leaf = NULL;
                pos = myFather;
            }
            second_stop = true;
        }
    } while (first_stop == false);
}


#endif // DYNAMICSEARCHTABLE_TRIETREE_H