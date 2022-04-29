#include "mergeSort.h"

int main() {
    SET<int, char> mySet[5];
    mySet[0].key = 1;
    mySet[0].other = 'a';
    mySet[1].key = 4;
    mySet[1].other = 'd';
    mySet[2].key = 3;
    mySet[2].other = 'c';
    mySet[3].key = 2;
    mySet[3].other = 'b';
    mySet[4].key = 5;
    mySet[4].other = 'e';

    ////////// Test MergeSort //////////
    cout << "////////// Test Merge Sort //////////" << endl;
    cout << "before merge sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet[i].other << ' ';
    cout << endl;
    cout << "merge sort:" << endl;
    mergeSort(mySet, 5);
    cout << "after merge sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet[i].other << ' ';
    cout << endl;
    return 0;
}
