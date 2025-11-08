#include <iostream>
using namespace std;

// Node structure for the linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int n) : data(n), next(nullptr) {};
};

// Class to represent a linked list
class LinkedList
{
public:
    Node *head;
    LinkedList() : head(nullptr) {}

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to add two linked lists representing numbers
    LinkedList add_two_numbers(LinkedList *temp2)
    {
        Node *curr = nullptr;
        Node *curr2 = nullptr;
        string first;
        string second;
        cin >> first;
        // cout<<first;
        cin >> second;
        // cout<<second;
        for (int i = 0; i < first.size(); i++) {
            insertAtHead(first[i] - '0');
        }

        for (int i = 0; i < second.size(); i++) {
            temp2->insertAtHead(second[i] - '0');
        }


        // if (first.size() > second.size())
        // {
        //     for (int i = second.size(); i < first.size(); i++)
        //     {
        //         Node *newNum = new Node(0);
        //         curr2 = newNum;
        //         curr2 = curr2->next;
        //     }
        // }
        // else
        // {
        //     for (int i = first.size(); i < second.size(); i++)
        //     {
        //         Node *newNum = new Node(0);
        //         curr = newNum;

        //         curr = curr->next;
        //     }
        // }

        Node* l1 = head;
        Node* l2 = temp2->head;
        LinkedList result;
        Node* dummy = new Node(0);
        Node* r = dummy;
        int carry = 0;


        // Node *newC1 = head;
        // Node *newC2 = temp2->head;

        int carr = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->data; l1 = l1->next; }
            if (l2) { sum += l2->data; l2 = l2->next; }
            carry = sum / 10;
            r->next = new Node(sum % 10);
            r = r->next;
        }
        result.head = dummy->next;
        return result;
    }


    // Function to display the linked list
    void print_list()
    {
        Node* move = head;
        while (move != nullptr) {
            cout << move->data;
            move = move->next;
        }
    }
};

int main()
{
    // int num1, num2;

    // Input for two numbers
    // cin >> num1 >> num2;

    // Creating linked lists for the input numbers
    LinkedList list1, list2;

    // Adding the linked lists
    LinkedList result = list1.add_two_numbers(&list2);

    // Displaying the result
    result.print_list();

    return 0;
}