#include <iostream>
using namespace std;

// Definition for a doubly linked list node.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to insert a node at the end of the doubly linked list.
void insert(Node*& head, int data) {
    // Complete this function.
    if(head == NULL){
        head = new Node(data);
    }
    else{
        Node* curr = head;
        while(curr->next != NULL){
            curr = curr -> next;
        }
        curr -> next = new Node(data);
        curr->next->prev = curr;
    }
}

// Function to delete all occurrences of a key if it appears at least twice in the doubly linked list.
void deleteIfOccursTwice(Node*& head, int key) {
    // Complete this function.
    int count = 0;
    Node* curr = head;

    while(curr){
        if(curr->data == key) count++;
        curr = curr->next;
        // cout<<"uh "<<count<<" ";
    }
                                                                  
    if(count < 2) return; // cuz there's nothing to delete..
    // -----------------------------------------------------
    // if(count >= 2){
    //     while(head){
    //         cout<<"boomii ";
    //         if(head->data == key){
    //             // here we have to jump one element.. like go to the next element and take the element out from the linkedlist...
    //             cout<<"boom ";
    //             // head->prev->next = head->next;
    //             Node* previous = head->prev;
    //             Node* next1 = head->next;
    //             previous->next = next1;
    //             continue;
    //         }
    //         head = head->next;
    //     }
    // }
    // -----------------------------------------------------

    curr = head;
    while(curr){
        Node* nextNode = curr -> next;

        if(curr -> data == key){
            if(curr->prev) curr->prev->next = curr->next;
            else head = curr->next; // this line is because if the first element is bout to be removed.. then we might run into an error if we do the normal deletion.. so we need to assign head to current's next node..

            if(curr->next) curr->next->prev = curr->prev;


            delete curr;
        }

        curr = nextNode; // this moves one element forward..
    }
}

// Function to print the doubly linked list.
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n; cin >> n;
    Node* head = nullptr;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        insert(head, t);
    }

    int key; cin >> key;
    deleteIfOccursTwice(head, key);

    printList(head);

    return 0;
}