#include "stack.h"
#include "seqStack.h"
#include "linkStack.h"

int main() {
    ////////// Test SeqStack //////////
    seqStack<int> mySeqStack(10);
    cout << "////////// Test sequence stack //////////" << endl;
    cout << "is empty:" << endl;
    cout << mySeqStack.isEmpty() << endl;
    cout << "push 0:" << endl;
    mySeqStack.push(0);
    cout << mySeqStack.top() << endl;
    cout << "push 1 and 2:" << endl;
    mySeqStack.push(1);
    mySeqStack.push(2);
    cout << "top element:" << endl;
    cout << mySeqStack.top() << endl;
    cout << "pop:" << endl;
    cout << mySeqStack.pop() << endl;

    ////////// Test LinkStack //////////
    linkStack<int> myLinkStack;
    cout << "////////// Test link stack //////////" << endl;
    cout << "is empty:" << endl;
    cout << myLinkStack.isEmpty() << endl;
    cout << "push 0:" << endl;
    myLinkStack.push(0);
    cout << myLinkStack.top() << endl;
    cout << "push 1 and 2:" << endl;
    myLinkStack.push(1);
    myLinkStack.push(2);
    cout << "top element:" << endl;
    cout << myLinkStack.top() << endl;
    cout << "pop:" << endl;
    cout << myLinkStack.pop() << endl;
    return 0;
}
