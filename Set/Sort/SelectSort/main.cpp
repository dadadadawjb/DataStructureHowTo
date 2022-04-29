#include "simpleSelectSort.h"
#include "heapSort.h"

int main() {
    SET<int, char> mySet_Simple[10];
    mySet_Simple[0].key = 39;
    mySet_Simple[0].other = 'f';
    mySet_Simple[1].key = 36;
    mySet_Simple[1].other = 'e';
    mySet_Simple[2].key = 58;
    mySet_Simple[2].other = 'h';
    mySet_Simple[3].key = 23;
    mySet_Simple[3].other = 'b';
    mySet_Simple[4].key = 44;
    mySet_Simple[4].other = 'g';
    mySet_Simple[5].key = 97;
    mySet_Simple[5].other = 'j';
    mySet_Simple[6].key = 31;
    mySet_Simple[6].other = 'd';
    mySet_Simple[7].key = 14;
    mySet_Simple[7].other = 'a';
    mySet_Simple[8].key = 26;
    mySet_Simple[8].other = 'c';
    mySet_Simple[9].key = 77;
    mySet_Simple[9].other = 'i';
    SET<int, char> mySet_Heap[10];
    mySet_Heap[0].key = 39;
    mySet_Heap[0].other = 'f';
    mySet_Heap[1].key = 36;
    mySet_Heap[1].other = 'e';
    mySet_Heap[2].key = 58;
    mySet_Heap[2].other = 'h';
    mySet_Heap[3].key = 23;
    mySet_Heap[3].other = 'b';
    mySet_Heap[4].key = 44;
    mySet_Heap[4].other = 'g';
    mySet_Heap[5].key = 97;
    mySet_Heap[5].other = 'j';
    mySet_Heap[6].key = 31;
    mySet_Heap[6].other = 'd';
    mySet_Heap[7].key = 14;
    mySet_Heap[7].other = 'a';
    mySet_Heap[8].key = 26;
    mySet_Heap[8].other = 'c';
    mySet_Heap[9].key = 77;
    mySet_Heap[9].other = 'i';

    ////////// Test SimpleSelectSort //////////
    cout << "////////// Test Simple Select Sort //////////" << endl;
    cout << "before select sort:" << endl;
    for (int i = 0; i < 10; i++)
        cout << mySet_Simple[i].other << ' ';
    cout << endl;
    cout << "simple sort:" << endl;
    simpleSelectSort(mySet_Simple, 10);
    cout << "after simple sort:" << endl;
    for (int i = 0; i < 10; i++)
        cout << mySet_Simple[i].other << ' ';
    cout << endl;

    ////////// Test HeapSort //////////
    cout << "////////// Test Heap Sort //////////" << endl;
    cout << "before heap sort:" << endl;
    for (int i = 0; i < 10; i++)
        cout << mySet_Heap[i].other << ' ';
    cout << endl;
    cout << "heap sort:" << endl;
    simpleSelectSort(mySet_Heap, 10);
    cout << "after heap sort:" << endl;
    for (int i = 0; i < 10; i++)
        cout << mySet_Heap[i].other << ' ';
    cout << endl;
    return 0;
}
