#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    
public:
    queue<TreeNode*> temp;
    TreeNode* constructBT(vector<int> &arr){
        int itr = 0;
        TreeNode* root = new TreeNode(arr[itr]);
        temp.push(root);
        while(!temp.empty()){
            int size = temp.size();
            TreeNode* tempN;
            
            for(int j = 0; j<size; j++){
                tempN = temp.front();
                ++itr;
                TreeNode* lft = NULL;
                TreeNode* rght = NULL;
                if(itr>=0 && itr<arr.size() && arr[itr] != -1 ){
                     lft = new TreeNode(arr[itr]);
                    temp.push(lft);
                }
                ++itr;
                if(itr>=0 && itr<arr.size() && arr[itr]!=-1){ 
                     rght = new TreeNode(arr[itr]);
                    temp.push(rght);
            }
                tempN->left = lft;
                tempN->right = rght;
               temp.pop();
            }
        }
        return root;
    }
    
    int maxHeight(TreeNode* root){
        if(root==NULL)return 0;
        else{
            int left = maxHeight(root->left);
            if(left==-1) return -1;
            int right = maxHeight(root->right);
            if(right==-1) return -1;
            if(abs(left-right) > 1)return -1;
            return(1+max(left,right));
        }
    }
};
    
    
    
    


int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    BinaryTree tree;
    TreeNode* root = tree.constructBT(arr);
    bool ans = true;
    if(tree.maxHeight(root) == -1) ans = false;

    std::cout << (ans ? "true" : "false") << std::endl;

    return 0;
}