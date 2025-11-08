#include <iostream>
using namespace std;

class BinaryTree
{
public:
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;
        // Implement any required node variables/methods/constructors here
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node *root = nullptr;

    void make_BT_from_array(int *arr, int size)
    {
        this->root = BT_from_level_order_array(arr, 0, size);
    }

    Node *BT_from_level_order_array(int *arr, int index, int size)
    {

        if (index < size && arr[index] != -1)
        {
            Node *newnode = new Node(arr[index]);
            newnode->left = BT_from_level_order_array(arr, 2 * index + 1, size);
            newnode->right = BT_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }

    int tempRec(int mul, Node *root, int sum, int target)
    {
        if (!root)
            return 0;

        int count = 0;
        if (sum + mul * root->data == target)
            count++;

        sum += mul * root->data;

        count += tempRec(-mul, root->left, sum, target);
        count += tempRec(-mul, root->right, sum, target);

        return count;
    }

    void alternating_path_sum(int *targets, int k)
    {
        int count[k] = {0};

        for (int i = 0; i < k; i++)
        {
            int sum = root->data;
            int total = 0;
            if (sum == targets[i])
                total++;

            total += tempRec(-1, root->left, sum, targets[i]);
            total += tempRec(-1, root->right, sum, targets[i]);

            count[i] = total;
        }

        for (int i = 0; i < k; i++)
        {
            cout << count[i] << " ";
        }
    }
};

int main()
{
    BinaryTree tree;
    int n, data, k;
    std::cin >> n >> k;
    int *arr = new int[n];
    int *targets = new int[k];

    for (int i = 0; i < n; i++)
    {
        std::cin >> data;
        arr[i] = data;
    }

    for (int i = 0; i < k; i++)
    {
        std::cin >> data;
        targets[i] = data;
    }

    tree.make_BT_from_array(arr, n);
    tree.alternating_path_sum(targets, k);
    return 0;
}