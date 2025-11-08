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
};

node *concatenate(node *head1, node *head2)
{
    // well not needed but you can get it from previous question
}

node *sortedConcatenate(node *head1, node *head2)
{
    // Implement the required logic here
    node* head = new node;
    node* dummy = head;
    while(head1!=NULL && head2!=NULL)
    if(head1->val <= head2->val){
        dummy->next = head1;
        head1 = head1->next;
        dummy = dummy->next;
    }
    else if(head1->val > head2->val){
        dummy->next = head2;
        head2 = head2->next;
        dummy = dummy->next;
    }
    while(head1!=NULL){
        dummy->next = head1;
        head1 = head1->next;
        dummy = dummy->next;
    }
    while(head2!=NULL){
        dummy->next = head2;
        head2 = head2->next;
        dummy = dummy->next;
    }
    return head->next;
}

int main()
{
    // Initialize two linked lists
    int n, m;
    cin >> n >> m;

    LinkedList List1;
    LinkedList List2;

    // take input and make the linked lists
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        List1.insert(temp);
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        List2.insert(temp);
    }

    LinkedList Ans;
    // call the sortedConcatenate function
    Ans.head = sortedConcatenate(List1.head, List2.head);

    // print the new sorted big linked list using printLinkedList
    Ans.printLinkedList();

    return 0;
}