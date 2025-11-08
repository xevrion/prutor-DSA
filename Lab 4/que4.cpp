#include <iostream>
#include <algorithm>

using namespace std;

// Class for AVL Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    // Constructor to initialize a new AVL tree node
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Function to get the height of a node
int height(Node *node)
{
    // Implement this function to return the height of a node
    return node ? node->height : 0;
}

// Function to create a new AVL tree node
Node *createNode(int data)
{
    return new Node(data);
}

// Function to right rotate subtree rooted with y
Node *rightRotate(Node *y)
{
    // Implement this function to perform a right rotation
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Function to left rotate subtree rooted with x
Node *leftRotate(Node *x)
{
    // Implement this function to perform a left rotation
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    // Implement this function to calculate and return the balance factor
    return N ? height(N->left) - height(N->right) : 0;
}

// Function to insert a node in AVL tree and balance the tree
Node *insert(Node *node, int data)
{

    // Implement this function to insert a node and balance the AVL tree
    if (!node)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to check if a tree is a valid AVL tree
bool isValidAVL(Node *root)
{
    // Implement this function to check if a tree is a valid AVL tree
    if (!root) return true;
    int balance = abs(height(root->left) - height(root->right));
    if (balance > 1) return false;
    return isValidAVL(root->left) && isValidAVL(root->right);
}

// Function to perform preorder traversal of the AVL tree
void preorderTraversal(Node *root)
{
    // Implement this function to perform a preorder traversal and print nodes
    if (!root)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    int n;

    cin >> n;
    Node *root = nullptr;

    for (int i = 0; i < n; ++i)
    {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    preorderTraversal(root);
    cout << endl;

    if (isValidAVL(root))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}