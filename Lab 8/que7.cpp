// Given the root of a binary tree, determine whether the tree satisfies the heap property.
// A binary tree is considered a Max Heap if it satisfies the following two conditions:

// Completeness Property:
// The binary tree is a complete binary tree, i.e. all levels are completely filled except possibly the last, which is filled from left to right.

// Heap Order Property:
// The value of each node is greater than or equal to the values of its children.

// Return true if the given binary tree satisfies both conditions; otherwise, return false.


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = nullptr;
    }

    // TODO: Implement buildTree() to create binary tree from level order input
    Node* buildTree(const vector<int>& arr) {
        if (arr.empty()) return nullptr;
        root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while (i < (int)arr.size()) {
            Node* current = q.front();
            q.pop();
            if (i < (int)arr.size()) {
                current->left = new Node(arr[i++]);
                q.push(current->left);
            }
            if (i < (int)arr.size()) {
                current->right = new Node(arr[i++]);
                q.push(current->right);
            }
        }
        return root;
    }

    // TODO: Implement isHeap() to check if the tree satisfies heap property
    bool isHeap(Node* root) {
        if (!root) return true;
        queue<Node*> q;
        q.push(root);
        bool nullSeen = false;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node->left) {
                if (nullSeen || node->data < node->left->data)
                    return false;
                q.push(node->left);
            } else {
                nullSeen = true;
            }

            if (node->right) {
                if (nullSeen || node->data < node->right->data)
                    return false;
                q.push(node->right);
            } else {
                nullSeen = true;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    BinaryTree bt;
    Node* root = bt.buildTree(arr);

    // TODO: Call isHeap() and print "true" or "false"
    cout << (bt.isHeap(root) ? "true" : "false") << endl;

    return 0;
}
