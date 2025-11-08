#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class binary_tree
{
public:
    node *root = nullptr;

    void make_binary_tree_from_array(vector<int> &arr)
    {
        this->root = construct_binary_tree_from_level_order_array(arr, 0);
    }

    node *construct_binary_tree_from_level_order_array(vector<int> &arr, size_t index)
    {
        // Implement your code Here
        if (index < arr.size() && arr[index] != -1)
        {
            node *newnode = new node(arr[index]);
            newnode->left = construct_binary_tree_from_level_order_array(arr, 2 * index + 1);
            newnode->right = construct_binary_tree_from_level_order_array(arr, 2 * index + 2);
            return newnode;
        }
        return nullptr;
    };

    // Merge Trees Function
    node *merge_trees(node *root1, node *root2)
    {
        // Implement your code here
        if (!root1 && !root2)
            return nullptr;
        if (!root1)
        {
            return root2;
        }
        if (!root2)
        {
            return root1;
        }
        node *new1 = new node(root1->data + root2->data);
        new1->left = merge_trees(root1->left, root2->left);
        new1->right = merge_trees(root1->right, root2->right);
        return new1;
    }

    // Inorder Traversal
    void inorder(node *root)
    {
        // Implement your code here
        if (!root)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    int n, m;

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Take the level-order of Tree 1

    cin >> m;
    vector<int> brr(m);
    for (int i = 0; i < m; i++)
        cin >> brr[i]; // Take the level-order of Tree 2

    binary_tree tree1, tree2;
    tree1.make_binary_tree_from_array(arr);
    tree2.make_binary_tree_from_array(brr);

    binary_tree combined;
    node *mergedRoot = combined.merge_trees(tree1.root, tree2.root);

    combined.inorder(mergedRoot); // Print the inorder traversal of the merged tree
    cout << endl;

    return 0;
}