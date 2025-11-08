#include <bits/stdc++.h>
using namespace std;

class node {
public:
    // Define node attributes here.
    int val;
    node* next;
    node(int v) : val(v), next(NULL){}
    
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }
    
    void insert_sorted(int val) {
        // Add insertion logic here.
        node* newNode = new node(val);
        
        if (head == NULL || val < head->val) {
            newNode->next = head;
            head = newNode;
            return;
        }

        node* curr = head;
        while (curr->next != NULL && curr->next->val < val) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void printLinkedList(){
        if (head==NULL){
            cout<<"EMPTY\n";
            return;
        }
        node* curr = head;
        while(curr){
            cout<<curr->val<<' ';
            curr = curr->next;
        }
        cout<<"NULL\n";
    }
};

int main() {
    LinkedList list;

    // Add your code here.
    int n ;
    cin>>n;
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        list.insert_sorted(temp);
    }
    
    list.printLinkedList();

    return 0;
}