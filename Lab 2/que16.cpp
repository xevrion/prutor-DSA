#include <iostream>
#include <vector>
using namespace std;


class Node{
    public:
        int val;
        Node* next;


        Node(int data): val(data), next(nullptr){}
    };

Node* mergeTwo(Node* head1,Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node dummy(-1);
    Node* it = &dummy;

    while(t1!=nullptr && t2!= nullptr){
        if(t1->val < t2->val){
            it->next = t1;
            it=t1;
            t1=t1->next;
        }

        else{
            it->next = t2;
            it=t2;
            t2=t2->next;
        }

    }

    if(t1) it->next = t1;
    else if(t2) it->next = t2;

    return dummy.next;

}

Node* mergeKLists(vector<Node*> scrolls){

    if(scrolls.empty()) return nullptr;

    

    while(scrolls.size()>1){
        
        vector<Node*> merged;

        for(int i=0; i<scrolls.size(); i+=2){
            if(i<scrolls.size()-1){                     // Not last left out list
                merged.push_back(mergeTwo(scrolls[i], scrolls[i+1]));
            }

            else{
                merged.push_back(scrolls[i]);
            }

            
        }
        scrolls = move(merged);   
    }

    return scrolls[0];

}

Node* ListInput(int n){
    if(n==0) return nullptr;

    int val;        // first node value
    cin>> val;
    Node* head = new Node(val);
    Node* tail = head;

    for(int i=1; i<n; i++){
        int val;
        cin>>val;
        tail->next = new Node(val);
        tail=tail->next;
    }

    return head;
}


int main() {
    int k;
    cin >> k; 
    vector<Node*> scrolls;

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n; 
        scrolls.push_back(ListInput(n));
    }

    Node* mergedHead = mergeKLists(scrolls);

    // Print merged linked list
    Node* temp = mergedHead;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";

    return 0;
}