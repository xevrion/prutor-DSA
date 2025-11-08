#include <iostream>
using namespace std;
struct ListNode
{
    int value;
    ListNode *next;
    ListNode(int val) : value(val), next(nullptr) {}
};

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->value;
        if (temp->next)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}


ListNode *reverseSegment(ListNode *head, int left, int right)
{
    /// code here
    //    int evenElements = 0;
    //    if(right-left %2 == 0) evenElements = 0;
    //    else evenElements = 1;

    while (left<right)
    {
        ListNode *start = head;
        ListNode *end = head;

        for(int i =0 ; i<left-1; i++){
            start = start->next;
        }

        for(int i =0 ; i<right-1; i++){
            end = end->next;
        }
        swap(start->value, end->value);
        left++;
        right--;
        



    }

    return head;
}

int main()
{

    int value;
    ListNode *head = nullptr, *tail = nullptr;
    while (cin >> value)
    {
        if (value == -1)
            break;
        ListNode *newNode = new ListNode(value);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int left, right;
    cin >> left >> right;
    cout << "Original list: ";
    printList(head);
    head = reverseSegment(head, left, right);
    cout << "Modified list: ";
    printList(head);
    ListNode *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}