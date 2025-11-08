#include <iostream>
using namespace std;

// Class definition for a Node in the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class definition for the Binary Search Tree
class BST {
private:
    Node* root;

    // Helper function to insert a node in the BST
    Node* insert(Node* node, int data) {
        // TODO: Implement the insert function
        if(node == nullptr){
            return new Node(data);
        }

        if(data < node->data){
            node->left = insert(node->left,data);
        }
        else if(data > node->data){
            node->right = insert(node->right,data);
        }

        return node;
    }

    // Helper function to find the minimum value node in a subtree
    Node* findMin(Node* node) {
        // TODO: Implement the findMin function
        Node* curr = node;
        while(curr && curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }

    // Helper function to find a node with a given value
    Node* findNode(Node* node, int data) {
        // TODO: Implement the findNode function
        if(node == nullptr || node->data == data){
            return node;
        }

        if(node->data < data){
            return findNode(node->right, data);
        } else if(node->data > data){

            return findNode(node->left, data);
        }
        else {
            return nullptr;
        }

    }

public:
    // Constructor to initialize the root of the BST
    BST() {
        root = nullptr;
    }

    // Public function to insert a node in the BST
    void insert(int data) {
        root = insert(root, data);
    }

    // Function to find the in-order successor of a given node
    int findInOrderSuccessor(int data) {
        // TODO: Implement the findInOrderSuccessor function
        Node* temp = findNode(root, data);
        // cout<<temp->data;
        if(temp->right){
            return temp->right->data;
        }
        Node* curr = nullptr;
        int count = 100;
        int temp1 = data;
        while(!curr){
            if(count==0) break;
            count--;
            temp1++;
            curr = findNode(root,temp1);
        }
        if(curr){
            return curr->data;
        }
        else return -1;
    }
};

// Main function to execute the program
int main() {
    int n, target;
    cin >> n;

    BST tree;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cin >> target;

    int successor = tree.findInOrderSuccessor(target);
    if (successor != -1) {
        cout << successor << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}