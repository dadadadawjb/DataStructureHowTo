#include "dynamicSearchTable.h"
#include "binarySearchTree.h"
#include "avlTree.h"
#include "trieTree.h"
#include "kdTree.h"
#include "closeHashTable.h"
#include "openHashTable.h"

int main() {
    SET<int, char> mySet[] = {{10, 'a'}, {8, 'b'}, {21, 'c'}, {87, 'd'},
                          {56, 'e'}, {4, 'f'}, {11, 'g'}, {3, 'h'},
                          {22, 'i'}, {7, 'j'}};
    SET<int, char> x;
    SET<int, char> *p;

    ////////// Test BinarySearchTree //////////
    cout << "////////// Test Binary Search Tree //////////" << endl;
    BinarySearchTree<int, char> myBinarySearchTree;
    cout << "insert mySet into myBinarySearchTree:" << endl;
    for (int i = 0; i < 10; i++)
        myBinarySearchTree.insert(mySet[i]);
    cout << "find 56:" << endl;
    p = myBinarySearchTree.find(56);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    cout << "remove 56:" << endl;
    myBinarySearchTree.remove(56);
    cout << "find 56:" << endl;
    p = myBinarySearchTree.find(56);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    cout << "insert 30:" << endl;
    x.key = 30;
    x.other = 'x';
    myBinarySearchTree.insert(x);
    cout << "find 30:" << endl;
    p = myBinarySearchTree.find(30);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    
    ////////// Test AvlTree //////////
    cout << "////////// Test Avl Tree //////////" << endl;
    AvlTree<int, char> myAvlTree;
    cout << "insert mySet into myAvlTree:" << endl;
    for (int i = 0; i < 10; i++)
        myAvlTree.insert(mySet[i]);
    cout << "find 56:" << endl;
    p = myAvlTree.find(56);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    cout << "remove 56:" << endl;
    myAvlTree.remove(56);
    cout << "find 56:" << endl;
    p = myAvlTree.find(56);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    cout << "insert 30:" << endl;
    x.key = 30;
    x.other = 'x';
    myAvlTree.insert(x);
    cout << "find 30:" << endl;
    p = myAvlTree.find(30);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    
    ////////// Test TrieTree //////////
    cout << "////////// Test Trie Tree //////////" << endl;
    TrieTree myTrieTree;
    cout << "insert 'abcde':" << endl;
    myTrieTree.insert("abcde");
    cout << "insert 'abcdef':" << endl;
    myTrieTree.insert("abcdef");
    cout << "find prefix 'abcde':" << endl;
    cout << myTrieTree.findPrefix("abcde") << endl;
    cout << "find prefix 'ac':" << endl;
    cout << myTrieTree.findPrefix("ac") << endl;
    cout << "insert 'acde':" << endl;
    myTrieTree.insert("acde");
    cout << "find prefix 'ac':" << endl;
    cout << myTrieTree.findPrefix("ac") << endl;
    cout << "remove 'abcde':" << endl;
    myTrieTree.remove("abcde");
    cout << "find 'abcde':" << endl;
    cout << myTrieTree.find("abcde") << endl;
    cout << "find prefix 'abcde':" << endl;
    cout << myTrieTree.findPrefix("abcde") << endl;

    ////////// Test KDTree //////////
    cout << "////////// Test KD Tree //////////" << endl;
    SET<int [3], char> mySet_KD[5] = {{{1, 1, 1}, 'a'}, {{3, 4, 2}, 'b'}, {{6, 5, 4}, 'c'}, {{2, 3, 5}, 'd'}, {{4, 5, 1}, 'e'}};
    KDTree<int [3], char> myKDTree(3);
    cout << "insert mySet_KD:" << endl;
    for (int i = 0; i < 5; i++)
        myKDTree.insert(mySet_KD[i]);
    cout << "find min in dimension 1:" << endl;
    cout << myKDTree.findMin(1) << endl;
    cout << "find max in dimension 0:" << endl;
    cout << myKDTree.findMax(0) << endl;
    cout << "find key as (3, 4, 2):" << endl;
    int findKey[3] = {3, 4, 2};
    if (myKDTree.find(findKey))
        cout << myKDTree.find(findKey)->other << endl;
    else
        cout << "not find" << endl;
    cout << "search range (2, 8, 0, 6, 1, 5):" << endl;
    int tmp1[2][3] = {{2, 0, 1}, {8, 6, 5}};
    int (*searchRange)[3] = tmp1;
    int tmp2[2][3] = {{-9999, -9999, -9999}, {-9999, -9999, -9999}};
    int (*treeRange)[3] = tmp2;
    cout << myKDTree.rangeSearch(searchRange, treeRange) << endl;
    cout << "remove (3, 4, 2):" << endl;
    myKDTree.remove(findKey);
    cout << "search range (2, 8, 0, 6, 1, 5):" << endl;
    cout << myKDTree.rangeSearch(searchRange, treeRange) << endl;
    cout << "find key as (3, 4, 2):" << endl;
    if (myKDTree.find(findKey))
        cout << myKDTree.find(findKey)->other << endl;
    else
        cout << "not find" << endl;
    cout << "dimension value:" << endl;
    cout << myKDTree.dimensionValue() << endl;
    
    ////////// Test CloseHashTable //////////
    cout << "////////// Test Close Hash Table //////////" << endl;
    closeHashTable<int, char> myCloseHashTable(11);
    cout << "insert mySet into myCloseHashTable:" << endl;
    for (int i = 0; i < 10; i++)
        myCloseHashTable.insert(mySet[i]);
    cout << "find 56:" << endl;
    p = myCloseHashTable.find(56);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    cout << "remove 56:" << endl;
    myCloseHashTable.remove(56);
    cout << "find 56:" << endl;
    p = myCloseHashTable.find(56);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    cout << "insert 30:" << endl;
    x.key = 30;
    x.other = 'x';
    myCloseHashTable.insert(x);
    cout << "find 30:" << endl;
    p = myCloseHashTable.find(30);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    cout << "print table:" << endl;
    myCloseHashTable.printTable();
    cout << "rehash:" << endl;
    myCloseHashTable.rehash();
    cout << "print table:" << endl;
    myCloseHashTable.printTable();

    ////////// Test OpenHashTable //////////
    cout << "////////// Test Open Hash Table //////////" << endl;
    openHashTable<int, char> myOpenHashTable(11);
    cout << "insert mySet into myOpenHashTable:" << endl;
    for (int i = 0; i < 10; i++)
        myOpenHashTable.insert(mySet[i]);
    cout << "find 56:" << endl;
    p = myOpenHashTable.find(56);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    cout << "remove 56:" << endl;
    myOpenHashTable.remove(56);
    cout << "find 56:" << endl;
    p = myOpenHashTable.find(56);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    cout << "insert 30:" << endl;
    x.key = 30;
    x.other = 'x';
    myOpenHashTable.insert(x);
    cout << "find 30:" << endl;
    p = myOpenHashTable.find(30);
    if (p)
        cout << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;
    cout << "print table:" << endl;
    myOpenHashTable.printTable();

    return 0;
}
