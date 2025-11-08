#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
    class Node
    {
        // Build LL Node class here
    public:
        int val;
        Node *next;
        Node(int v)
        {
            val = v;
            next = nullptr;
        }
    };
    int size;
    Node *root;

    LinkedList()
    {
        // Constructor
        size = 0;
        root = nullptr;
    }

    ~LinkedList()
    {
        // Destructor
        Node *curr = root;
        while (curr)
        {
            Node *tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }

    void push(int value)
    {
        // Code to push value to stack/LL
        Node *n = new Node(value);
        if (!root)
            root = n;
        else
        {
            Node *curr = root;
            while (curr->next)
                curr = curr->next;
            curr->next = n;
        }
        size++;
    }

    int solution()
    {
        vector<int> arr;
        Node *current = root;
        while (current)
        {
            arr.push_back(current->val);
            current = current->next;
        }

        int n = arr.size();
        if (n < 3)
            return 0;

        vector<long long> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        int count = 0;

        for (int i = 0; i <= n - 3; i++)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                long long sumA = (i > 0 ? prefix[i - 1] : 0) + (prefix[n - 1] - prefix[j - 1]);
                long long sumB = prefix[j - 1] - (i > 0 ? prefix[i - 1] : 0);
                if (sumA == sumB)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    LinkedList L;
    int size;
    cin >> size;
    // Input your Linked list size and values here
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        L.push(temp);
    }
    cout << L.solution();

    return 0;
}