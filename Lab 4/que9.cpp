#include <iostream>
#include <vector>
using namespace std;

// Class representing a Tree
class Tree {

public:
    int n;
    Tree(int nodes): n(nodes){

    }

    void addEdge(int u, int v){

    }
    // Method to calculate the largest number of non-redundant routes
    int calculateMaxRoutes() {
        return n-1;
    }
    
};

int main() {
    int n;
    cin >> n;

    Tree tree(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }

    cout << tree.calculateMaxRoutes() << endl;

    return 0;
}