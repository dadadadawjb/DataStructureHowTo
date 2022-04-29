#include <iostream>
#include "set.h"
using namespace std;

template <class KEY, class OTHER>
int seqSearchNS(SET<KEY, OTHER> data[], int size, const KEY &x) {
    data[0].key = x;
    int i;
    for (i = size; x != data[i].key; i--);
    return i;
}

template <class KEY, class OTHER>
int seqSearch(SET<KEY, OTHER> data[], int size, const KEY &x) {
    data[0].key = x;
    int i;
    for (i = size; x < data[i].key; i--);
    if (x < data[i].key || i == 0)
        return 0;
    else
        return i;
}

template <class KEY, class OTHER>
int binarySearch(SET<KEY, OTHER> data[], int size, const KEY &x) {
    int low = 1, high = size;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x == data[mid].key)
            return mid;
        if (x < data[mid].key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main() {
    SET<int, char> mySet_NS[5];
    mySet_NS[0].key = 1;
    mySet_NS[0].other = 'a';
    mySet_NS[1].key = 4;
    mySet_NS[1].other = 'd';
    mySet_NS[2].key = 3;
    mySet_NS[2].other = 'c';
    mySet_NS[3].key = 2;
    mySet_NS[3].other = 'b';
    mySet_NS[4].key = 5;
    mySet_NS[4].other = 'e';
    SET<int, char> mySet_S[5];
    mySet_S[0].key = 1;
    mySet_S[0].other = 'a';
    mySet_S[1].key = 2;
    mySet_S[1].other = 'b';
    mySet_S[2].key = 3;
    mySet_S[2].other = 'c';
    mySet_S[3].key = 4;
    mySet_S[3].other = 'd';
    mySet_S[4].key = 5;
    mySet_S[4].other = 'e';

    ////////// Test SeqSearchNS //////////
    cout << "////////// Test Sequence Search (non-sequence) //////////" << endl;
    cout << "sequence search 3 (non-sequence):" << endl;
    cout << seqSearchNS(mySet_NS, 5, 3) << endl;

    ////////// Test SeqSearch //////////
    cout << "////////// Test Sequence Search //////////" << endl;
    cout << "sequence search 3:" << endl;
    cout << seqSearch(mySet_S, 5, 3) << endl;

    ////////// Test BinarySearch //////////
    cout << "////////// Test Binary Search //////////" << endl;
    cout << "binary search 3:" << endl;
    cout << binarySearch(mySet_S, 5, 3) << endl;
    return 0;
}
