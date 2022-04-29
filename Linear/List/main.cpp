#include "list.h"
#include "seqList.h"
#include "sLinkList.h"
#include "dLinkList.h"

int main() {
    ////////// Test SeqList //////////
    seqList<int> mySeqList(10);
    cout << "////////// Test sequence list //////////" << endl;
    cout << "insert 0 to 0:" << endl;
    mySeqList.insert(0, 0);
    mySeqList.traverse();
    cout << "insert 1 to 1 and 2 to 2:" << endl;
    mySeqList.insert(1, 1);
    mySeqList.insert(2, 2);
    mySeqList.traverse();
    cout << "remove from 2:" << endl;
    mySeqList.remove(2);
    mySeqList.traverse();
    cout << "length: " << endl;
    cout << mySeqList.length() << endl;
    cout << "search 1:" << endl;
    cout << mySeqList.search(1) << endl;
    cout << "visit 0:" << endl;
    cout << mySeqList.visit(0) << endl;
    cout << "traverse:" << endl;
    mySeqList.traverse();
    cout << "sum, max, min:" << endl;
    int sum_value = mySeqList.sum(0);
    int max_value, min_value;
    int max_index, min_index;
    max_value = mySeqList.max(max_index);
    min_value = mySeqList.min(min_index);
    cout << sum_value << " " << max_value << " " << min_value << endl;

    ////////// Test SLinkList //////////
    sLinkList<int> mySLinkList;
    cout << "////////// Test static link list //////////" << endl;
    cout << "insert 0 to 0:" << endl;
    mySLinkList.insert(0, 0);
    mySLinkList.traverse();
    cout << "insert 1 to 1 and 2 to 2:" << endl;
    mySLinkList.insert(1, 1);
    mySLinkList.insert(2, 2);
    mySLinkList.traverse();
    cout << "remove from 2:" << endl;
    mySLinkList.remove(2);
    mySLinkList.traverse();
    cout << "length: " << endl;
    cout << mySLinkList.length() << endl;
    cout << "search 1:" << endl;
    cout << mySLinkList.search(1) << endl;
    cout << "visit 0:" << endl;
    cout << mySLinkList.visit(0) << endl;
    cout << "traverse:" << endl;
    mySLinkList.traverse();

    ////////// Test DLinkList //////////
    dLinkList<int> myDLinkList;
    cout << "////////// Test dynamic link list //////////" << endl;
    cout << "insert 0 to 0:" << endl;
    myDLinkList.insert(0, 0);
    myDLinkList.traverse();
    cout << "insert 1 to 1 and 2 to 2:" << endl;
    myDLinkList.insert(1, 1);
    myDLinkList.insert(2, 2);
    myDLinkList.traverse();
    cout << "remove from 2:" << endl;
    myDLinkList.remove(2);
    myDLinkList.traverse();
    cout << "length: " << endl;
    cout << myDLinkList.length() << endl;
    cout << "search 1:" << endl;
    cout << myDLinkList.search(1) << endl;
    cout << "visit 0:" << endl;
    cout << myDLinkList.visit(0) << endl;
    cout << "traverse:" << endl;
    myDLinkList.traverse();
    return 0;
}
