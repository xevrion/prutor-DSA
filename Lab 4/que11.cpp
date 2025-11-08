#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{

private:
    Node *root;

    // Helper function to insert a node in the BST
    Node *insert(Node *node, int data)
    {
        // TODO: Implement the insert function
        if (node == nullptr)
        {
            return new Node(data);
        }

        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data);
        }

        return node;
    }

    // Helper function to find the minimum value node in a subtree
    Node *findMin(Node *node)
    {
        // TODO: Implement the findMin function
        Node *curr = node;
        while (curr && curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr;
    }

    // Helper function to find a node with a given value
    Node *findNode(Node *node, int data)
    {
        // TODO: Implement the findNode function
        if (node == nullptr || node->data == data)
        {
            return node;
        }

        if (node->data < data)
        {
            return findNode(node->right, data);
        }
        else if (node->data > data)
        {

            return findNode(node->left, data);
        }
        else
        {
            return nullptr;
        }
    }

public:
    // Constructor to initialize the root of the BST
    BST()
    {
        root = nullptr;
    }

    // Public function to insert a node in the BST
    void insert(int data)
    {
        root = insert(root, data);
    }

    void printOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        printOrder(root->left);

        cout << root->data << " ";

        printOrder(root->right);
    }

    void inOrderTraversal()
    {
        printOrder(root);
    }
};

int main()
{
    int n;
    cin >> n;
    // vector<int> temp;
    int c;
    BST bst;
    while (n--)
    {
        cin >> c;
        bst.insert(c);
    }
    
    bst.inOrderTraversal();

    return 0;
}