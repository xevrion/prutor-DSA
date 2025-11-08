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
        if (head == NULL)
        {
            head = new node(val);
        }
        else
        {
            node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = new node(val);
        }
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
};

node *concatenate(node *head1, node *head2)
{
    // Implement the required logic
    node *curr = head1;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = head2;
    return head1;
}

int main()
{
    // make instances for the two linked lists
    LinkedList *first = new LinkedList();
    LinkedList *second = new LinkedList();

    // take input for the two linked lists
    int n1, n2;
    cin >> n1 >> n2;
    int k = n1;
    while (n1--)
    {
        
        int temp;
        cin >> temp;
        first->insert(temp);
        
    }
    while (n2--)
    {
        int temp;
        cin >> temp;
        second->insert(temp);
    }
    if(k == 0){
        second->printLinkedList();
        return 0;
    }

    // call the concatenate function
    concatenate(first->head, second->head);

    // print the linked list using printLinkedList function
    first->printLinkedList();
    // second->printLinkedList();

    return 0;
}