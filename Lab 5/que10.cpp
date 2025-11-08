#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    node *left;
    node *right;
    int id;
    node(int x)
    {
        left = nullptr;
        right = nullptr;
        id = x;
    }
} node;

node *levelOrderToBT(vector<int> &v)
{

    vector<node *> nodes(v.size(), nullptr);
    for (int i = 0; i < v.size(); i++)
        if (v[i] != -1)
            nodes[i] = new node(v[i]);

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == -1)
            continue;
        if (2 * i + 1 < v.size() and v[2 * i + 1] != -1)
            nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < v.size() and v[2 * i + 2] != -1)
            nodes[i]->right = nodes[2 * i + 2];
    }

    return nodes[0];
}
// DO NOT ALTER THE CODE ABOVE.

class Solution
{
    // Add helper functions/variables here as private members
public:
    int maxi;
    int dfs(node* r){
        if(!r) return 0;

        int left = max(0, dfs(r->left));
        int right = max(0, dfs(r->right));
        maxi = max(maxi , r->id + left+ right);
        return r->id + max(left, right);
    }

    int MaxScore(node *r)
    {
        // complete the function now.
        maxi = 0;
        dfs(r);
        return maxi;
    }
};

// DO NOT ALTER THE CODE BELOW.

int main()
{

    int h;
    cin >> h;
    vector<int> v((1 << (h + 1)) - 1, -1);
    for (int &i : v)
        cin >> i;

    node *root = levelOrderToBT(v);

    Solution sol;
    cout << sol.MaxScore(root);

    return 0;
}