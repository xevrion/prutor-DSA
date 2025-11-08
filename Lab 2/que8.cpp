#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node(int v = 0, node *nxt = NULL)
    {
        val = v;
        next = nxt;
    }
};

class LinkedList
{
public:
    node *head;
    LinkedList(node *h = NULL)
    {
        head = h;
    }

    void insert(int val)
    {
        // complete this insert function
        node *newnode = new node(val);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }

        node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newnode;
    }

    void printLinkedList()
    {
        if (head == NULL)
        {
            cout << "EMPTY\n";
            return;
        }
        node *curr = head;
        while (curr)
        {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << "NULL\n";
    }

    node *second_highest()
    {
        // Add the logic to obtain second highest element here.

        if (!head || !head->next)
            return NULL;
        bool flag = true;

        node *curr = head;
        node *first = curr;
        node *second = curr->next;

        if (second->val > first->val)
            std::swap(first->val, second->val);
        if (first->val != second->val)
            flag = false;
        curr = curr->next->next;
        if (flag && second->val != curr->val)
            flag = false;
        while (curr)
        {
            if (curr->next != NULL)
            {
                if (curr->val != curr->next->val && flag)
                {
                    flag = false;
                }
            }

            if (curr->val > first->val)
            {
                second->val = first->val;
                first->val = curr->val;
            }
            else if (curr->val > second->val && curr->val < first->val)
            {
                second->val = curr->val;
            }
            curr = curr->next;
        }

        if (flag)
        {
            return NULL;
        }

        return second;
    }
};

int main()
{
    // initialize the linked list
    int n;
    cin >> n;
    LinkedList list;

    // take input for linked list
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        list.insert(temp);
    }

    if (n < 2)
    {
        cout << "NULL";
        return 0;
    }

    node *result = list.second_highest();

    if (result)
    {
        cout << result->val << endl;
    }
    else
    {
        cout << "NULL" << endl;
    }

    return 0;
}