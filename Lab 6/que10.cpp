#include <bits/stdc++.h>
using namespace std;

// B-Tree node
class BTreeNode {
public:
    vector<int> keys;            // keys in the node
    vector<BTreeNode*> children; // child pointers
    int t;                       // minimum degree
    bool leaf;                   // true if leaf

    BTreeNode(int t, bool leaf) {
        this->t = t;
        this->leaf = leaf;
    }

    // TODO: Implement search function
    bool search(int k) {
        // Return true if key k exists in the subtree, else false
        int i = 0;
        while (i < (int)keys.size() && k > keys[i]) i++;

        if (i < (int)keys.size() && keys[i] == k)
            return true;

        if (leaf)
            return false;

        return children[i]->search(k);
    }

    // TODO: Insert a key into a non-full node
    void insertNonFull(int k) {
        // Insert key k into this node
        // Handle leaf and non-leaf cases
        int i = (int)keys.size() - 1;

        if (leaf) {
            keys.push_back(0);
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
        } else {
            while (i >= 0 && keys[i] > k) i--;
            i++;
            if ((int)children[i]->keys.size() == 2 * t - 1) {
                splitChild(i, children[i]);
                if (k > keys[i]) i++;
            }
            children[i]->insertNonFull(k);
        }
    }

    // TODO: Split a full child node
    void splitChild(int i, BTreeNode* y) {
        // Split child y at index i
        // Update keys and children accordingly
        BTreeNode* z = new BTreeNode(y->t, y->leaf);

        // move t-1 keys
        for (int j = 0; j < t - 1; j++)
            z->keys.push_back(y->keys[j + t]);

        // move children if not leaf
        if (!y->leaf) {
            for (int j = 0; j < t; j++)
                z->children.push_back(y->children[j + t]);
        }

        y->keys.resize(t - 1);
        if (!y->leaf) y->children.resize(t);

        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, y->keys[t - 1]);
    }
};

// B-Tree wrapper
class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int t) {
        this->t = t;
        root = nullptr;
    }

    void insert(int k) {
        // Insert key k into the B-Tree
        // Handle root splits if necessary
        if (!root) {
            root = new BTreeNode(t, true);
            root->keys.push_back(k);
            return;
        }

        if ((int)root->keys.size() == 2 * t - 1) {
            BTreeNode* s = new BTreeNode(t, false);
            s->children.push_back(root);
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k) i++;
            s->children[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }

    bool search(int k) {
        // Search key k starting from root
        return root ? root->search(k) : false;
        
    }
};

int main() {
    int n, t;
    cin >> n >> t;
    BTree tree(t);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.insert(x);
    }
    int key;
    cin >> key;
    cout << (tree.search(key) ? 1 : 0) << endl;
    return 0;
}