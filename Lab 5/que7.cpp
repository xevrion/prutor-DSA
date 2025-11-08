#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    Node *returnHead()
    {
        return head;
    }
    // Function to append a new node to the linked list
    void append(int new_data)
    {
        Node *new_node = new Node(new_data);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        Node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = new_node;
    }
};

int countConsecutive(Node *head, const vector<int> &ids, int n)
{
    vector<int> sorted_ids = ids;
    sort(sorted_ids.begin(), sorted_ids.end());
    int count = 0;
    int len = 1;
    for (int i = 1; i < sorted_ids.size(); i++)
    {
        if (sorted_ids[i] == sorted_ids[i - 1] + 1)
        {
            len++;
        }
        else
        {
            count += (len * (len - 1)) / 2; 
            len = 1;
        }
    }
    count += (len * (len - 1)) / 2; 

    return count;
}

int main()
{
    int n, m;
    cin >> n;

    vector<int> list(n);
    for (int i = 0; i < n; i++)
        list[i] = i;

    cin >> m;

    vector<int> ids(m);
    for (int i = 0; i < m; i++)
        cin >> ids[i];

    LinkedList linkedList;

    // Append elements to the linked list
    for (int i = 0; i < n; i++)
        linkedList.append(list[i]);

    // Calculate and print the count of consecutive elements
    cout << countConsecutive(linkedList.returnHead(), ids, n) << endl;

    return 0;
}