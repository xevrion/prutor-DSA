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

        
        newnode->next = head;
        head = newnode;
    }

    void printLinkedList()
    {
        // don't alter this printing function
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
};

void insertion_operation(LinkedList &l, node *elem)
{
    // insert the new elem at the front
    if (l.head == nullptr)
    {
        l.head = elem;
        elem->next = nullptr;
        return;
    }
    elem->next = l.head;
    l.head = elem;
}

node *deletion_operation(LinkedList &l)
{
    // delete the elem from the front
    if (l.head == nullptr)
    {
        return nullptr;
    }

    node *head = l.head;
    node *dummy = head->next;
    delete head;
    l.head = dummy;

    return dummy;
}

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

    // take input for the operations
    int num;
    cin >> num;

    int a[num], b[num];
    for (int i = 0; i < num; i++)
    {
        int tempA, tempB;
        cin >> tempA >> tempB;
        a[i] = tempA;
        b[i] = tempB;
    }

    // perform operation and after the operation print the list
    for (int i = 0; i < num; i++)
    {
        if (a[i] == 1)
        {
            node *b1 = new node(b[i]);
            insertion_operation(list, b1);
        }
        else if (a[i] == 2)
        {
            deletion_operation(list);
        }
        list.printLinkedList();
    }

    return 0;
}