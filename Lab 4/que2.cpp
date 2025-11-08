#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new tree node
TreeNode* newNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Function to build a binary tree from an array
TreeNode* buildTreeFromArray(int arr[], int index, int size) {
    // Implement the function here
    if (index >= size || arr[index] == -1) return nullptr;
    TreeNode* root = newNode(arr[index]);
    root->left = buildTreeFromArray(arr, 2*index + 1, size);
    root->right = buildTreeFromArray(arr, 2*index + 2, size);
    return root;
}

// Function to check if two binary trees are identical
bool areIdentical(TreeNode* root1, TreeNode* root2) {
    // Implement the function here
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return (root1->data == root2->data) 
           && areIdentical(root1->left, root2->left) 
           && areIdentical(root1->right, root2->right);
}

// Function to build a binary tree from a string in the array format
TreeNode* buildTreeFromArrayString(const string& str) {
    // Implement the function here
    vector<int> arr;
    stringstream ss(str);
    string temp;
    while (ss >> temp) {
        if (temp == "null" || temp == "-1") arr.push_back(-1);
        else arr.push_back(stoi(temp));
    }
    if (arr.empty()) return nullptr;
    return buildTreeFromArray(arr.data(), 0, arr.size());

    
}

void freeMemory(TreeNode* root) {
    if (!root) return;
    freeMemory(root->left);
    freeMemory(root->right);
    free(root);
}

int main() {
    // Get the array input for the first tree from the user
    string input1;
    getline(cin, input1);

    // Create binary tree from the first input
    TreeNode* root1 = buildTreeFromArrayString(input1);

    // Get the array input for the second tree from the user
    string input2;
    getline(cin, input2);

    // Create binary tree from the second input
    TreeNode* root2 = buildTreeFromArrayString(input2);

    // Check if the trees are identical
    if (areIdentical(root1, root2)) {
        cout << "1"; // 1 for identical
    } else {
        cout << "0"; // 0 for not identical
    }

    // Free allocated memory
    // Implement freeing memory here
    freeMemory(root1);
    freeMemory(root2);

    return 0;
}