#include <iostream>
#include <cstdlib>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
};

// Function to delete duplicate elements from a sorted singly-linked list
ListNode *deleteDuplicates(ListNode *head)
{
    // Implement this function to remove duplicate elements from the linked list.

    ListNode dummy;
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *curr = head;

    while (curr) {
        bool isDuplicate = false;
        while (curr->next && curr->val == curr->next->val) {
            isDuplicate = true;
            ListNode *dup = curr->next;
            curr->next = dup->next;
            delete dup;
        }
        if (isDuplicate) {
            ListNode *dup = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete dup;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy.next;
    // Return the head of the modified list.
}

// Function to sort a singly-linked list in ascending order
ListNode *sortList(ListNode *head)
{
    // Implement this function to sort the linked list in ascending order.
    if (!head || !head->next)
        return head;

    bool swapped;
    do {
        swapped = false;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr && curr->next) {
            if (curr->val > curr->next->val) {
                int temp = curr->val;
                curr->val = curr->next->val;
                curr->next->val = temp;
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);

    return head;
    // Return the head of the sorted list.
}

// Function to print the elements of a singly-linked list
void printList(ListNode *head)
{
    // Implement this function to print the elements of the linked list.
    ListNode *current = head;
    while (current != nullptr)
    {
        
            std::cout << current->val<<" ";
        
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to create a singly-linked list from an array of digits
ListNode *createList(const char *digits)
{
    ListNode *head = nullptr;
    ListNode *current = nullptr;

    for (int i = 0; digits[i] != '\0'; ++i)
    {
        ListNode *newNode = new ListNode;
        newNode->val = digits[i] - '0';
        newNode->next = nullptr;

        if (current == nullptr)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

// Function to free the memory allocated for a singly-linked list
void freeList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
}

int main()
{

    char digits[100];

    std::cin >> digits;

    ListNode *head = createList(digits);

    printList(head);

    ListNode *result = deleteDuplicates(head);
    ListNode *sortedResult = sortList(result);

    printList(sortedResult);

    freeList(sortedResult);

    return 0;
}