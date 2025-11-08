#include<bits/stdc++.h>
using namespace std;

class BinaryTree{
    public:
    class Node {
        public:
        int data;
        Node* left;
        Node* right;
        
        Node(): data(0), left(nullptr), right(nullptr) {}
        
        Node(int val): data(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root = nullptr;
    
    void make_BT_from_array(int *arr, int size)
    {
        this->root = BT_from_level_order_array(arr, 0, size);
    }
    
    Node* BT_from_level_order_array(int *arr, int index, int size){

        if (index < size && arr[index] != -1) {
            Node* newnode = new Node(arr[index]);
            newnode->left = BT_from_level_order_array(arr, 2 * index + 1, size);
            newnode->right = BT_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }
    
    void alternatingLevelOrderTraversal() {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);
        bool reverse1 = false;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                level.push_back(front->data);

                if (front->left != nullptr) q.push(front->left);
                if (front->right != nullptr) q.push(front->right);
            }

            if (reverse1) {
                reverse(level.begin(), level.end());
            }

            for (int i = 0; i < level.size(); i++) {
                cout << level[i] << " ";
            }
            cout<<"| ";
            reverse1 = !reverse1; // to alternate .... every time
        }
        
        
        

    }
    
};

int main() {
    BinaryTree tree;
    int n, data;
    std::cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        std::cin >> data;
        arr[i] = data;
    }
    
    tree.make_BT_from_array(arr,n);
    tree.alternatingLevelOrderTraversal();
    return 0;
}