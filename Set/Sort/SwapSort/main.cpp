#include "bubbleSort.h"
#include "quickSort.h"

int main() {
    SET<int, char> mySet_Bubble[5];
    mySet_Bubble[0].key = 1;
    mySet_Bubble[0].other = 'a';
    mySet_Bubble[1].key = 4;
    mySet_Bubble[1].other = 'd';
    mySet_Bubble[2].key = 3;
    mySet_Bubble[2].other = 'c';
    mySet_Bubble[3].key = 2;
    mySet_Bubble[3].other = 'b';
    mySet_Bubble[4].key = 5;
    mySet_Bubble[4].other = 'e';
    SET<int, char> mySet_Quick[5];
    mySet_Quick[0].key = 1;
    mySet_Quick[0].other = 'a';
    mySet_Quick[1].key = 4;
    mySet_Quick[1].other = 'd';
    mySet_Quick[2].key = 3;
    mySet_Quick[2].other = 'c';
    mySet_Quick[3].key = 2;
    mySet_Quick[3].other = 'b';
    mySet_Quick[4].key = 5;
    mySet_Quick[4].other = 'e';

    ////////// Test BubbleSort //////////
    cout << "////////// Test Bubble Sort //////////" << endl;
    cout << "before bubble sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet_Bubble[i].other << ' ';
    cout << endl;
    cout << "bubble sort:" << endl;
    bubbleSort(mySet_Bubble, 5);
    cout << "after bubble sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet_Bubble[i].other << ' ';
    cout << endl;

    ////////// Test QuickSort //////////
    cout << "////////// Test Quick Sort //////////" << endl;
    cout << "before quick sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet_Quick[i].other << ' ';
    cout << endl;
    cout << "quick sort:" << endl;
    bubbleSort(mySet_Quick, 5);
    cout << "after quick sort:" << endl;
    for (int i = 0; i < 5; i++)
        cout << mySet_Quick[i].other << ' ';
    cout << endl;
    return 0;
}
