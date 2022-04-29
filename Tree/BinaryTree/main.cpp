#include "bTree.h"
#include "binaryTree.h"

int main() {
    ////////// Test BinaryTree //////////
    binaryTree<char> myBinaryTree;
    cout << "////////// Test Binary tree //////////" << endl;
    cout << "create tree:" << endl;
    myBinaryTree.createTree('@');
    // test tree can be input as
    // A
    // L C
    // B E
    // @ D
    // @ @
    // @ @
    // W @
    // @ X
    // @ @
    cout << "preorder traverse:" << endl;
    myBinaryTree.preOrder();
    cout << "preorder traverse (non-recursive):" << endl;
    myBinaryTree.preOrderNR();
    cout << "midorder traverse:" << endl;
    myBinaryTree.midOrder();
    cout << "midorder traverse (non-recursive):" << endl;
    myBinaryTree.midOrderNR();
    cout << "postorder traverse:" << endl;
    myBinaryTree.postOrder();
    cout << "postorder traverse (non-recursive):" << endl;
    myBinaryTree.postOrderNR();
    cout << "levelorder traverse:" << endl;
    myBinaryTree.levelOrder();
    cout << "is empty:" << endl;
    cout << myBinaryTree.isEmpty() << endl;
    cout << "see root:" << endl;
    cout << myBinaryTree.root('@') << endl;
    cout << "see size:" << endl;
    cout << myBinaryTree.size() << endl;
    cout << "see height:" << endl;
    cout << myBinaryTree.height() << endl;
    cout << "see parent of 'L':" << endl;
    cout << myBinaryTree.parent('L', '@') << endl;
    cout << "see left child of 'L':" << endl;
    cout << myBinaryTree.lchild('L', '@') << endl;
    cout << "see right child of 'C':" << endl;
    cout << myBinaryTree.rchild('C', '@') << endl;
    cout << "see all tree:" << endl;
    printTree(myBinaryTree, '@');
    cout << "delete left of 'L' and right of 'C':" << endl;
    myBinaryTree.delLeft('L');
    myBinaryTree.delRight('C');
    cout << "see all tree:" << endl;
    printTree(myBinaryTree, '@');
    return 0;
}
