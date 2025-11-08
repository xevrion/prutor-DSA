#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

    // Destructor to clean up dynamically allocated nodes
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

// Function to create a new node
TreeNode *createNode(int value)
{
    if (value == -1)
        return nullptr; // -1 is used to denote null nodes
    return new TreeNode(value);
}

// Function to insert nodes in level order
TreeNode *insertLevelOrder(vector<int> &arr, TreeNode *root, int i, int n)
{
    // Given an array representation of a tree, construct the binary tree
    // TODO: Implement the function
    if (i>=n || arr[i] == -1) return nullptr;
    root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr, root->left,2*i+1,n);
    root->right = insertLevelOrder(arr, root->right,2*i+2,n);
    return root;
}

// Function to invert the binary tree
TreeNode *invertTree(TreeNode *root)
{
    // Swap the left and right children of every node in the tree
    // TODO: Implement the function
    if(!root) return nullptr;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;

}

// Function to print the tree in pre-order
void printPreorder(TreeNode *node)
{
    // Print the nodes of a binary tree in preorder
    // TODO: Implement the function
    if(node == nullptr) return;
    cout<<node->value<<" ";

    printPreorder(node->left);
    printPreorder(node->right);
}

int main()
{
    // DO NOT MODIFY THIS
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    TreeNode *root = nullptr;
    root = insertLevelOrder(arr, root, 0, n);

    // Print the original tree in pre-order
    printPreorder(root);
    cout << endl;

    // Invert the tree and print again
    root = invertTree(root);
    printPreorder(root);
    cout << endl;

    // Clean up memory
    delete root;

    return 0;
}