#include <iostream>
#include <vector>
using namespace std;

// Node class for the linked list
class Node
{
public:
    int data;
    Node *next;
};

// LinkedList class for the main linked list operations
class LinkedList
{
private:
    Node *head;
    Node *createNode(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }

public:
    LinkedList() : head(nullptr) {}

public:
    // Function to calculate the greater array
    vector<int> calculateGreater(int size)
    {
        vector<int> ans;
        for (int i = 0; i < size; i++)
        {
            Node *current = head;
            Node *current2 = head;
            int maxi = 0;
            int n = i + 1;
            int m = i;
            while (m--)
            {
                current2 = current2->next;
            }
            while (n--)
            {
                current = current->next;
            }
            for (int j = i + 1; j < size; j++)
            {
                if (current->data > current2->data)
                {

                    maxi = max(maxi, current->data);
                }
                current = current->next;
                if (maxi != 0)
                    break;
            }
            if (maxi >= current2->data)
            {
                ans.push_back(maxi);
            }
            else
                ans.push_back(0);
        }
        return ans;
    }

    // Function to print the linked list
    void printList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void append(int data)
    {
        Node *newNode = createNode(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
};

int main()
{
    int size;
    cin >> size;

    LinkedList list;

    // Input the elements of the linked list
    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        list.append(data);
    }

    // Calculate the greater array
    vector<int> greater = list.calculateGreater(size);

    // Output the greater array
    for (int i = 0; i < size; i++)
    {
        cout << greater[i] << " ";
    }
    cout << endl;

    return 0;
}