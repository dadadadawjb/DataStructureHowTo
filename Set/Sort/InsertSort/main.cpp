#include "simpleInsertSort.h"
#include "binaryInsertSort.h"
#include "shellSort.h"

int main() {
    SET<int, char> mySet_Simple[5];
    mySet_Simple[0].key = 1;
    mySet_Simple[0].other = 'a';
    mySet_Simple[1].key = 4;
    mySet_Simple[1].other = 'd';
    mySet_Simple[2].key = 3;
    mySet_Simple[2].other = 'c';
    mySet_Simple[3].key = 2;
    mySet_Simple[3].other = 'b';
    mySet_Simple[4].key = 5;
    mySet_Simple[4].other = 'e';
    SET<int, char> mySet_Binary[5];
    mySet_Binary[0].key = 1;
    mySet_Binary[0].other = 'a';
    mySet_Binary[1].key = 4;
    mySet_Binary[1].other = 'd';
    mySet_Binary[2].key = 3;
    mySet_Binary[2].other = 'c';
    mySet_Binary[3].key = 2;
    mySet_Binary[3].other = 'b';
    mySet_Binary[4].key = 5;
    mySet_Binary[4].other = 'e';
    SET<int, char> mySet_Shell[5];
    mySet_Shell[0].key = 1;
    mySet_Shell[0].other = 'a';
    mySet_Shell[1].key = 4;
    mySet_Shell[1].other = 'd';
    mySet_Shell[2].key = 3;
    mySet_Shell[2].other = 'c';
    mySet_Shell[3].key = 2;
    mySet_Shell[3].other = 'b';
    mySet_Shell[4].key = 5;
    mySet_Shell[4].other = 'e';

    ////////// Test SimpleInsertSort //////////
    cout << "////////// Test Simple Insert Sort //////////" << endl;
    cout << "before insert sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet_Simple[i].other << ' ';
    cout << endl;
    cout << "insert sort:" << endl;
    simpleInsertSort(mySet_Simple, 5);
    cout << "after insert sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet_Simple[i].other << ' ';
    cout << endl;

    ////////// Test BinaryInsertSort //////////
    cout << "////////// Test Binary Insert Sort //////////" << endl;
    cout << "before binary insert sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet_Binary[i].other << ' ';
    cout << endl;
    cout << "binary insert sort:" << endl;
    binaryInsertSort(mySet_Binary, 5);
    cout << "after binary insert sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet_Binary[i].other << ' ';
    cout << endl;

    ////////// Test ShellSort //////////
    cout << "////////// Test Shell Sort //////////" << endl;
    cout << "before shell sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet_Shell[i].other << ' ';
    cout << endl;
    cout << "binary shell sort:" << endl;
    shellSort(mySet_Shell, 5);
    cout << "after shell sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet_Shell[i].other << ' ';
    cout << endl;
    return 0;
}