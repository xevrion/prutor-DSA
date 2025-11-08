#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int v = 0, Node *p = nullptr, Node *n = nullptr)
    {
        data = v;
        prev = p;
        next = n;
    }
};

class DoubleLinkedList
{
public:
    Node *head;
    DoubleLinkedList(Node *h = nullptr)
    {
        head = h;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    void printLinkedList()
    {
        if (head == nullptr)
        {
            cout << "\n";
            return;
        }

        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << "\n";
    }

    void bubbleSort()
    {
        if (!head)
            return;
        bool swapped;
        Node *ptr;
        Node *last = NULL;

        do
        {
            swapped = false;
            ptr = head;

            while (ptr->next != last)
            {
                if (ptr->data > ptr->next->data)
                {
                    swap(ptr->data, ptr->next->data);
                    swapped = true;
                }
                ptr = ptr->next;
            }
            last = ptr;
        } while (swapped);
    }
};

DoubleLinkedList concatenate(DoubleLinkedList &old, DoubleLinkedList &other)
{
    Node *curr = old.head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = other.head;
    if(other.head) other.head->prev=curr;
    return old;
}

DoubleLinkedList sortedConcatenate(DoubleLinkedList &l1, DoubleLinkedList &l2)
{
    l1.bubbleSort();
    l2.bubbleSort();

    Node *curr = l1.head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = l2.head;
    if(l2.head) l2.head->prev=curr;
    l1.bubbleSort();
    return l1;
}

DoubleLinkedList insertSorted(DoubleLinkedList &l, int val)
{
    Node *nNode = new Node(val);

    // what if l is empty
    if (!l.head)
    {
        l.head = nNode;
        return l;
    }

    // inserting at the beginning.. as val as smaller than the first element.. in the linked list..
    if (val <= l.head->data)
    {
        nNode->next = l.head;
        l.head->prev = nNode;
        l.head = nNode;
        return l;
    }

    // if none of them are correct... means insertion will be done in the middle or the end.. so yeah...
    Node *curr = l.head;
    while (curr->next && curr->next->data < val)
    {
        curr = curr->next;
    }

    nNode->next = curr->next;
    nNode->prev = curr;

    if (curr->next)
    {
        curr->next->prev = nNode;
    }
    curr->next = nNode;

    return l;
}

int secondHighest(DoubleLinkedList &l)
{
    if (!l.head || !l.head->next)
        return -1;

    Node* curr = l.head;
    int first = curr->data;
    int second = curr->next->data;

    if (second > first)
        std::swap(first, second);

    curr = curr->next->next;

    while (curr)
    {
        if (curr->data > first)
        {
            second = first;
            first = curr->data;
        }
        else if (curr->data > second && curr->data < first)
        {
            second = curr->data;
        }
        curr = curr->next;
    }

    return (first == second) ? -1 : second; // -1 if all elements equal
}

void pairSumGreaterThanX(DoubleLinkedList &l, int x)
{
    int count = 0;
    // int sum = 0;
    Node *curr = l.head;

    while (curr != NULL)
    {
        Node *curr1 = curr->next;

        while (curr1 != NULL)
        {
            if (curr1->data + curr->data > x)
            {
                count++;
            }
            curr1 = curr1->next;
        }
        curr = curr->next;
    }
    if(count == 0){
        cout<<-1;
    }else
    cout << count;
}

int main()
{

    int queryType;
    cin >> queryType;
    if (queryType == 1)
    {
        int n, m, temp;
        cin >> n >> m;
        temp = n;
        DoubleLinkedList list1;
        DoubleLinkedList list2;
        int x;
        while (n--)
        {
            cin >> x;
            list1.insert(x);
        }
        while (m--)
        {
            cin >> x;
            list2.insert(x);
        }

        if(temp==0){
            list2.printLinkedList();
            return 0;
        }
        
        concatenate(list1, list2).printLinkedList();
        
    }
    
    else if (queryType == 2)
    {
        int n, m,temp;
        cin >> n >> m;
        temp = n;
        DoubleLinkedList list1;
        DoubleLinkedList list2;
        int x;
        while (n--)
        {
            cin >> x;
            list1.insert(x);
        }
        while (m--)
        {
            cin >> x;
            list2.insert(x);
        }
        if(temp==0){
            list2.printLinkedList();
            return 0;
        }
        sortedConcatenate(list1, list2).printLinkedList();
    }
    else if (queryType == 3)
    {
        int n;
        cin >> n;
        int x;
        DoubleLinkedList list1;
        while (n--)
        {
            cin >> x;
            list1.insert(x);
        }
        int k;
        cin >> k;
        insertSorted(list1, k).printLinkedList();
    }

    else if (queryType == 4)
    {
        int n,temp;
        cin >> n;
        temp = n;
        DoubleLinkedList list1;
        int x;
        while (n--)
        {
            cin >> x;
            list1.insert(x);
        }

        if(temp == 1){
            cout<<x;
            return 0;
        }

        cout << secondHighest(list1) << endl;
    }
    else if (queryType == 5)
    {
        int n, k;
        cin >> n >> k;
        DoubleLinkedList list1;
        int x;
        while (n--)
        {
            cin >> x;
            list1.insert(x);
        }
        pairSumGreaterThanX(list1, k);
    }

    return 0;
}