#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

// -------- AVL Node Definition --------
struct Node
{
    int key;
    int height;
    int size;
    struct Node *left, *right;
};

// -------- Utility Functions --------
int height(struct Node *n)
{ /* TODO */
    return n ? n->height : 0;
}
int size(struct Node *n)
{ /* TODO */
    return n ? n->size : 0;
}
void update(struct Node *n)
{ /* TODO */
    if (!n)
        return;
    n->height = 1 + max(height(n->left), height(n->right));
    n->size = 1 + size(n->left) + size(n->right);
}
int getBalance(struct Node *n)
{ /* TODO */
    return n ? height(n->left) - height(n->right) : 0;
}
struct Node *newNode(int key)
{ /* TODO */
    Node *temp = new Node;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    temp->size = 1;
    return temp;
}

// -------- Rotations --------
struct Node *rotateRight(struct Node *y)
{ /* TODO */
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    update(y);
    update(x);

    return x;
}
struct Node *rotateLeft(struct Node *x)
{ /* TODO */
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    update(x);
    update(y);

    return y;
}

// -------- Balancing --------
struct Node *balance(struct Node *n)
{ /* TODO */
    int balance = getBalance(n);

    if (balance > 1 && getBalance(n->left) >= 0)
        return rotateRight(n);

    if (balance < -1 && getBalance(n->left) < 0)
    {
        n->left = rotateLeft(n->left);
        return rotateLeft(n);
    }
    if (balance > 1 && getBalance(n->right) <= 0)
    {
        return rotateRight(n);
    }

    if (balance < -1 && getBalance(n->right) > 0)
    {
        n->right = rotateRight(n->right);
        return rotateLeft(n);
    }

    return n;
}

// -------- Insert --------
struct Node *insert(struct Node *root, int key)
{ /* TODO */
    if (!root)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;
    update(root);
    return balance(root);
}

// -------- Delete --------
struct Node *minValueNode(struct Node *n)
{ /* TODO */
    Node *curr = n;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;
}
struct Node *erase(struct Node *root, int key)
{ /* TODO */
    if (!root)
        return root;

    if (key < root->key)
        root->left = erase(root->left, key);
    else if (key > root->key)
        root->right = erase(root->right, key);
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
            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = erase(root->right, temp->key);
        }
    }
    update(root);
    return balance(root);
}



// -------- Queries --------
int getRank(struct Node *root, int key)
{ /* TODO */
    if(!root) return -1;
    if(key < root->key) return getRank(root->left, key);
    else if ( key > root->key){
        int r = getRank(root->right , key);
        if(r == -1) return -1;
        return size(root->left)+1+r;
    } else {
        return size(root->left) + 1;
    }
    
}
int getKth(struct Node *root, int k)
{ /* TODO */
    if(!root|| k<=0|| k>size(root)) return -1;

    int lSize = size(root->left);

    if(k == lSize + 1) return root->key;
    else if (k<= lSize) return getKth(root->left, k);
    else return getKth(root->right, k-lSize-1);
}

// -------- Driver Code --------
int main()
{
    int Q;
    scanf("%d", &Q);
    struct Node *root = NULL;

    while (Q--)
    {
        char op;
        int x;
        scanf(" %c %d", &op, &x);
        if (op == 'I')
            root = insert(root, x);
        else if (op == 'D')
            root = erase(root, x);
        else if (op == 'R')
            printf("%d\n", getRank(root, x));
        else if (op == 'K')
            printf("%d\n", getKth(root, x));
    }
    return 0;
}