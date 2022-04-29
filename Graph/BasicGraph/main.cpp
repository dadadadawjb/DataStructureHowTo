#include "graph.h"
#include "adjMatrixGraph.h"
#include "adjListGraph.h"

int main() {
    ////////// Test AdjMatrixGraph //////////
    cout << "////////// Test Adjcent Matrix Graph //////////" << endl;
    adjMatrixGraph<char, int> myAdjMatrixGraph(10, "abcdefghij", -1);
    cout << "insert edge 'af' with weight 9:" << endl;
    myAdjMatrixGraph.insert('a', 'f', 9);
    cout << "check whether edge 'af' exists:" << endl;
    cout << myAdjMatrixGraph.exist('a', 'f') << endl;
    cout << "remove edge 'af':" << endl;
    myAdjMatrixGraph.remove('a', 'f');
    cout << "check whether edge 'af' exists:" << endl;
    cout << myAdjMatrixGraph.exist('a', 'f') << endl;
    cout << "check whether edge 'ab' exists:" << endl;
    cout << myAdjMatrixGraph.exist('a', 'b') << endl;

    ////////// Test AdjListGraph //////////
    cout << "////////// Test Adjcent List Graph //////////" << endl;
    adjListGraph<char, int> myAdjListGraph(10, "abcdefghij");
    cout << "insert edge 'af' with weight 9:" << endl;
    myAdjListGraph.insert('a', 'f', 9);
    cout << "check whether edge 'af' exists:" << endl;
    cout << myAdjListGraph.exist('a', 'f') << endl;
    cout << "remove edge 'af':" << endl;
    myAdjListGraph.remove('a', 'f');
    cout << "check whether edge 'af' exists:" << endl;
    cout << myAdjListGraph.exist('a', 'f') << endl;
    cout << "check whether edge 'ab' exists:" << endl;
    cout << myAdjListGraph.exist('a', 'b') << endl;
    cout << "insert edge 'ab', 'ac', 'bd', 'be', 'cf', 'fg', 'fh', 'fa', 'dc', 'hb', 'ih', 'ij':" << endl;
    myAdjListGraph.insert('a', 'b', 1);
    myAdjListGraph.insert('a', 'c', 2);
    myAdjListGraph.insert('b', 'd', 3);
    myAdjListGraph.insert('b', 'e', 4);
    myAdjListGraph.insert('c', 'f', 5);
    myAdjListGraph.insert('f', 'g', 6);
    myAdjListGraph.insert('f', 'h', 7);
    myAdjListGraph.insert('f', 'a', 8);
    myAdjListGraph.insert('d', 'c', 9);
    myAdjListGraph.insert('h', 'b', 10);
    myAdjListGraph.insert('i', 'h', 11);
    myAdjListGraph.insert('i', 'j', 12);
    /*     a
          / \
         b   c
        / \   \
       d   e   f   i
              / \ / \
             g   h   j
       f -> a, d -> c, h -> b */
    cout << "deepth first search:" << endl;
    myAdjListGraph.dfs();
    cout << "breadth first search:" << endl;
    myAdjListGraph.bfs();
    // cout << "euler circuit:" << endl;
    // adjListGraph<char, int> myAdjListGraph_euler(7, "abcdefg");
    // myAdjListGraph_euler.insert('a', 'g', 1);
    // myAdjListGraph_euler.insert('g', 'a', 1);
    // myAdjListGraph_euler.insert('g', 'c', 2);
    // myAdjListGraph_euler.insert('c', 'g', 2);
    // myAdjListGraph_euler.insert('c', 'b', 3);
    // myAdjListGraph_euler.insert('b', 'c', 3);
    // myAdjListGraph_euler.insert('b', 'g', 4);
    // myAdjListGraph_euler.insert('g', 'b', 4);
    // myAdjListGraph_euler.insert('g', 'e', 5);
    // myAdjListGraph_euler.insert('e', 'g', 5);
    // myAdjListGraph_euler.insert('e', 'd', 6);
    // myAdjListGraph_euler.insert('d', 'e', 6);
    // myAdjListGraph_euler.insert('d', 'f', 7);
    // myAdjListGraph_euler.insert('f', 'd', 7);
    // myAdjListGraph_euler.insert('f', 'a', 8);
    // myAdjListGraph_euler.insert('a', 'f', 8);
    // myAdjListGraph_euler.EulerCircuit('a');
    cout << "topology sort:" << endl;
    adjListGraph<char, int> myAdjListGraph_top(7, "abcdefg");
    myAdjListGraph_top.insert('a', 'b', 1);
    myAdjListGraph_top.insert('a', 'c', 2);
    myAdjListGraph_top.insert('b', 'd', 3);
    myAdjListGraph_top.insert('b', 'e', 4);
    myAdjListGraph_top.insert('b', 'f', 5);
    myAdjListGraph_top.insert('c', 'e', 6);
    myAdjListGraph_top.insert('c', 'g', 7);
    myAdjListGraph_top.insert('e', 'f', 8);
    myAdjListGraph_top.insert('e', 'g', 9);
    myAdjListGraph_top.insert('f', 'd', 10);
    /*       a
          /    \
         c      b
       /  \ /   |   \
      g <- e -> f -> d */
    myAdjListGraph_top.topSort();
    cout << "critical path:" << endl;
    adjListGraph<char, int> myAdjListGraph_critical(6, "abcdef");
    myAdjListGraph_critical.insert('a', 'b', 1);
    myAdjListGraph_critical.insert('a', 'c', 3);
    myAdjListGraph_critical.insert('a', 'd', 5);
    myAdjListGraph_critical.insert('b', 'c', 1);
    myAdjListGraph_critical.insert('c', 'd', 1);
    myAdjListGraph_critical.insert('b', 'e', 2);
    myAdjListGraph_critical.insert('c', 'f', 2);
    myAdjListGraph_critical.insert('d', 'e', 1);
    myAdjListGraph_critical.insert('d', 'f', 2);
    myAdjListGraph_critical.insert('e', 'f', 2);
    /*       a
         /   |   \
        b -> c -> d
        |    \   /
        e ->   f
        d -> e       */
    myAdjListGraph_critical.criticalPath();
    return 0;
}
