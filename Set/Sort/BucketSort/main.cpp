#include "bucketSort.h"

int main() {
    ////////// Test BucketSort //////////
    cout << "////////// Test Bucket Sort //////////" << endl;
    SET<int, char> mySetItem[15] = {{5, 'b'}, {10, 'd'}, {18, 'h'}, {30, 'l'}, {21, 'i'}, 
                                    {0, 'a'}, {11, 'e'}, {9, 'c'}, {35, 'n'}, {29, 'k'}, 
                                    {12, 'f'}, {22, 'j'}, {33, 'm'}, {14, 'g'}, {55, 'o'}};
    node<char> *mySetLinkList = NULL;
    node<char> *mySetLinkP = mySetLinkList;
    node<char> *mySetLinkP_prev = NULL;
    for (int i = 0; i < 15; i++) {
        if (mySetLinkP_prev != NULL) {
            mySetLinkP_prev->next = new node<char>(mySetItem[i]);
            mySetLinkP = mySetLinkP_prev->next;
        } else {
            mySetLinkP = new node<char>(mySetItem[i]);
            mySetLinkList = mySetLinkP;
        }
        mySetLinkP_prev = mySetLinkP;
    }
    cout << "before bucket sort:" << endl;
    mySetLinkP = mySetLinkList;
    for (int i = 0; i < 15; i++) {
        cout << mySetLinkP->data.other << ' ';
        mySetLinkP = mySetLinkP->next;
    }
    cout << endl;
    cout << "bucket sort:" << endl;
    bucketSort(mySetLinkList);
    cout << "after bucket sort:" << endl;
    mySetLinkP = mySetLinkList;
    for (int i = 0; i < 15; i++) {
        cout << mySetLinkP->data.other << ' ';
        mySetLinkP = mySetLinkP->next;
    }
    cout << endl;
    return 0;
}
