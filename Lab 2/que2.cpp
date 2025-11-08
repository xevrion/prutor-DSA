#include <iostream>
using namespace std;

class LinkedList
{
public:
    class Node
    {
    public:
        char data;
        Node *next;
        Node(char value)
        {
            this->data = value;
            this->next = nullptr;
        }
    };

    int size;
    Node *root;

    LinkedList()
    {
        this->size = 0;
        this->root = nullptr;
    }

    ~LinkedList()
    {
        if (root == nullptr)
            return;
        Node *current = root->next;
        while (current != root)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete root;
    }

    void enqueue(char value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            root->next = root;
        }
        else
        {
            newNode->next = root->next;
            root->next = newNode;
            root = newNode;
        }
        this->size += 1;
    }

    void dequeue()
    {
        if (root == nullptr)
            return;
        if (root->next == root)
            delete root;
        else
        {
            Node *deleted = root->next;
            root->next = deleted->next;
            delete deleted;
        }
        this->size--;
    };

    // void traverse(){
    //     Node *ptr = root;
    //     while(ptr != nullptr)
    //     {
    //         std::cout << ptr->data <<" ";
    //         ptr = ptr->next;
    //     }
    //     std::cout<<std::endl;
    // };

    void solution()
    {
        // Write your main solution code here

        if (root == nullptr)
            return; // empty linked list
        int n = size;
        int totalOperations = n - 1;
        int numbers = 1, operations = 1;
        int available = 0;

        Node *curr = root->next;
        for (int pos = 1; pos <= 2 * n - 1; ++pos)
        {
            if (pos % 2 == 1) // odd
            {

                if (curr->data == 'x')
                {
                    cout << "x" << numbers++ << " ";
                    ++available;
                }
                else
                {

                    cout << "o" << operations++ << " ";
                    --available;
                }
                curr = curr->next;
            }
            else // even
            {

                if (available >= 2 && operations <= totalOperations)
                {
                    cout << "o" << operations++ << " ";
                    --available;
                }
                else
                {

                    cout << "x" << numbers++ << " ";
                    ++available;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    LinkedList L;
    int size;
    std::cin >> size;
    int size1 = 2 * size - 1;
    // Input size and expression here
    for (int i = 0; i < size; i++)
    {
        char temp;
        cin >> temp;
        L.enqueue(temp);
    }
    L.solution();

    return 0;
}