#include <stdio.h>
#include <stdlib.h>

// -------- AVL Node Definition --------
struct Node
{
    int key;
    int height;
    int size;
    struct Node *left, *right;
};

// -------- Utility Functions (already implemented) --------
int height(struct Node *n) { return n ? n->height : 0; }
int size(struct Node *n) { return n ? n->size : 0; }

void update(struct Node *n)
{
    if (n)
    {
        int hl = height(n->left);
        int hr = height(n->right);
        n->height = (hl > hr ? hl : hr) + 1;
        n->size = size(n->left) + size(n->right) + 1;
    }
}

int getBalance(struct Node *n)
{
    return n ? height(n->left) - height(n->right) : 0;
}

struct Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    temp->size = 1;
    return temp;
}

// --------- TODO: Rotations (to be implemented by students) ---------
struct Node *rotateRight(struct Node *y)
{
    // TODO: Implement right rotation
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    update(y);
    update(x);

    return x;
}

struct Node *rotateLeft(struct Node *x)
{
    // TODO: Implement left rotation
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    update(x);
    update(y);

    return y;
}

// --------- TODO: Balance function ---------
struct Node *balance(struct Node *n)
{
    // TODO: Update node, calculate balance factor
    // Perform necessary rotations
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

// --------- TODO: Insertion ---------
struct Node *insert(struct Node *root, int key)
{
    // TODO: Implement AVL insertion using recursion + balance()
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

// --------- TODO: Deletion ---------
struct Node *erase(struct Node *root, int key)
{
    // TODO: Implement AVL deletion (use minValueNode for successor)
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
            Node *temp = root->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            return temp;
            root->key = temp->key;
            root->right = erase(root->right, temp->key);
        }
    }
    update(root);
    return balance(root);
}

// --------- Order Statistic (already implemented) ---------
int getKth(struct Node *root, int k)
{
    if (!root || k <= 0 || k > size(root))
        return -1;
    int leftSize = size(root->left);
    if (k == leftSize + 1)
        return root->key;
    else if (k <= leftSize)
        return getKth(root->left, k);
    else
        return getKth(root->right, k - leftSize - 1);
}

// -------- Driver Code (given) --------
int main()
{
    int Q;
    scanf("%d", &Q);
    struct Node *root = NULL;

    while (Q--)
    {
        int type, x;
        scanf("%d", &type);
        if (type == 1)
        { // insert
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (type == 2)
        { // delete
            scanf("%d", &x);
            root = erase(root, x);
        }
        else if (type == 3)
        { // median
            if (size(root) == 0)
            {
                printf("-1\n");
            }
            else
            {
                int n = size(root);
                int median;
                if (n % 2 == 1)
                {
                    median = getKth(root, (n + 1) / 2); // odd → middle
                }
                else
                {
                    median = getKth(root, n / 2 + 1); // even → upper middle
                }
                printf("%d\n", median);
            }
        }
    }
    return 0;
}