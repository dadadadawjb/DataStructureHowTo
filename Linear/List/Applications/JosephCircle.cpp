#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;

    node(int d, node *n = NULL) {
        data = d;
        next = n;
    }
};

int main() {
    node *head, *p, *q;
    int n;

    cout << "input n:";
    cin >> n;

    p = head = new node(0);
    for (int i = 0; i < n; i++)
        p = p->next = new node(i);
    p->next = head;

    q = head;
    while (q->next != q) {
        p = q->next;
        q = p->next;
        p->next = q->next;
        cout << q->data << '\t';
        delete q;
        q = p->next;
    }

    cout << "\nlast leave:" << q->data << endl;

    return 0;
}