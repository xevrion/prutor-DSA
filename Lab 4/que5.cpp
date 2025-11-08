#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    struct Node *left, *right;
    int height;
};

// Utility function to get maximum of two integers
// int max(int a, int b)
// {
//     // TODO: Implement max function
//     if (a > b)
//     {
//         return a;
//     }
//     else
//         return b;
// }

// Function to get height of the tree
int height(Node *N)
{
    // TODO: Implement height function
    return N ? N->height : 0;
}

// Helper function to create a new node with the given key
Node *newNode(int key)
{
    // TODO: Allocate memory for a new node and initialize it
    Node *temp = new Node;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

// Function to right rotate subtree rooted with y
Node *rightRotate(Node *y)
{
    // TODO: Implement rightRotate function
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
    // TODO: Implement leftRotate function
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
    // TODO: Implement getBalance function
    return N ? height(N->left) - height(N->right) : 0;
}

// Recursive function to insert a key into the subtree rooted with node
// and returns the new root of the subtree.
Node *insert(Node *node, int key)
{
    // TODO: Implement AVL tree insertion logic
    // Remember to update the height of the node and balance the tree
    if (!node)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Recursive function to delete a node with given key from subtree with given root
// It returns root of the modified subtree.
Node *deleteNode(Node *root, int key)
{
    // TODO: Implement AVL tree deletion logic
    // Remember to update the height of the node and balance the tree
    if (!root)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left || !root->right)
        {
            Node *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                delete root;
                return NULL;
            }
            else
            {
                *root = *temp;
                delete temp;
            }
        }
        else
        {
            Node *temp = root->right;
            while (temp->left != nullptr)
                temp = temp->left;

            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance < -1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return leftRotate(root);
    }
    if (balance > 1 && getBalance(root->right) <= 0)
    {
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// A utility function to do preorder traversal of the tree
void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        root = insert(root, key);
    }

    cin >> key;
    root = deleteNode(root, key);

    preOrder(root);

    return 0;
}