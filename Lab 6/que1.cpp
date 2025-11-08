#include <bits/stdc++.h>
using namespace std;

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
        // Return true if key k exists in the subtree
        int i = 0;
        while (i < keys.size() && k > keys[i]) i++;
        if (i < keys.size() && keys[i] == k) return true;
        if (leaf) return false;
        return children[i]->search(k);
    }

    // TODO: Insert a key into a non-full node
    void insertNonFull(int k) {
        // Insert key k into this node
        int i = keys.size() - 1;
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
            if (children[i]->keys.size() == 2 * t - 1) {
                splitChild(i, children[i]);
                if (keys[i] < k) i++;
            }
            children[i]->insertNonFull(k);
        }
    }

    // TODO: Split a full child node
    void splitChild(int i, BTreeNode* y) {
        // Split child y at index i
        BTreeNode* z = new BTreeNode(y->t, y->leaf);
        for (int j = 0; j < t - 1; j++) z->keys.push_back(y->keys[j + t]);
        if (!y->leaf) {
            for (int j = 0; j < t; j++) z->children.push_back(y->children[j + t]);
        }
        y->keys.resize(t - 1);
        if (!y->leaf) y->children.resize(t);
        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, y->keys[t - 1]);
    }
    
    int getPredecessor(int idx) {
        BTreeNode* cur = children[idx];
        while (!cur->leaf) cur = cur->children.back();
        return cur->keys.back();
    }

    int getSuccessor(int idx) {
        BTreeNode* cur = children[idx + 1];
        while (!cur->leaf) cur = cur->children[0];
        return cur->keys[0];
    }

    void borrowFromPrev(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx - 1];
        child->keys.insert(child->keys.begin(), keys[idx - 1]);
        if (!child->leaf) child->children.insert(child->children.begin(), sibling->children.back()), sibling->children.pop_back();
        keys[idx - 1] = sibling->keys.back();
        sibling->keys.pop_back();
    }

    void borrowFromNext(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];
        child->keys.push_back(keys[idx]);
        if (!child->leaf) child->children.push_back(sibling->children[0]), sibling->children.erase(sibling->children.begin());
        keys[idx] = sibling->keys[0];
        sibling->keys.erase(sibling->keys.begin());
    }

    void merge(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];
        child->keys.push_back(keys[idx]);
        for (int i = 0; i < sibling->keys.size(); i++) child->keys.push_back(sibling->keys[i]);
        if (!sibling->leaf) {
            for (int i = 0; i < sibling->children.size(); i++) child->children.push_back(sibling->children[i]);
        }
        keys.erase(keys.begin() + idx);
        children.erase(children.begin() + idx + 1);
        delete sibling;
    }

    void fill(int idx) {
        if (idx != 0 && children[idx - 1]->keys.size() >= t) borrowFromPrev(idx);
        else if (idx != keys.size() && children[idx + 1]->keys.size() >= t) borrowFromNext(idx);
        else {
            if (idx != keys.size()) merge(idx);
            else merge(idx - 1);
        }
    }

    // TODO: Delete a key from the subtree rooted at this node
    void remove(int k) {
        // Handle deletion from leaf and internal nodes
        // Handle merging or borrowing if necessary
        int idx = lower_bound(keys.begin(), keys.end(), k) - keys.begin();
        if (idx < keys.size() && keys[idx] == k) {
            if (leaf) {
                keys.erase(keys.begin() + idx);
            } else {
                if (children[idx]->keys.size() >= t) {
                    int pred = getPredecessor(idx);
                    keys[idx] = pred;
                    children[idx]->remove(pred);
                } else if (children[idx + 1]->keys.size() >= t) {
                    int succ = getSuccessor(idx);
                    keys[idx] = succ;
                    children[idx + 1]->remove(succ);
                } else {
                    merge(idx);
                    children[idx]->remove(k);
                }
            }
        } else {
            if (leaf) return;
            bool flag = (idx == keys.size());
            if (children[idx]->keys.size() < t) fill(idx);
            if (flag && idx > keys.size()) children[idx - 1]->remove(k);
            else children[idx]->remove(k);
        }
    }

    // Optional helper functions for deletion:
    // - getPredecessor
    // - getSuccessor
    // - fill
    // - borrowFromPrev
    // - borrowFromNext
    // - merge
};

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
        if (!root) {
            root = new BTreeNode(t, true);
            root->keys.push_back(k);
        } else {
            if (root->keys.size() == 2 * t - 1) {
                BTreeNode* s = new BTreeNode(t, false);
                s->children.push_back(root);
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0] < k) i++;
                s->children[i]->insertNonFull(k);
                root = s;
            } else root->insertNonFull(k);
        }
    }

    void remove(int k) {
        // Delete key k from the B-Tree
        if (!root) return;
        root->remove(k);
        if (root->keys.size() == 0) {
            BTreeNode* tmp = root;
            if (root->leaf) root = nullptr;
            else root = root->children[0];
            delete tmp;
        }
    }

    bool search(int k) {
        // Search key k starting from root
        if (!root) return false;
        return root->search(k);
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

    int k_del, k_search;
    cin >> k_del >> k_search;

    tree.remove(k_del); // Delete the key
    cout << (tree.search(k_search) ? 1 : 0) << endl;
    return 0;
}